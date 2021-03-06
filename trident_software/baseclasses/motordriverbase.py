
"""Module containing the base class definition for the motor driver nodes.

Author: Johannes Deivard 2021-10
"""
from abc import ABCMeta, abstractmethod
import rclpy
from rclpy.node import Node
from rclpy.action import ActionClient, ActionServer
from std_srvs.srv import Trigger
import json
import numpy as np
# from geometry_msgs.msg import Pose, Point, Quaternion
# from trident_msgs.action import GotoPose, HoldPose
from trident_msgs.msg import MotorOutputs, MotorOutput
from trident_msgs.srv import GetState
from cola2_msgs.msg import Setpoints
from baseclasses.tridentstates import MotorDriverState


class MotorDriverBase(Node, metaclass=ABCMeta):
    """A base class for the motor driver nodes used in Athena and NAIAD designed with
    generalization in mind.
    """

    def __init__(self, node_name):
        super().__init__(node_name)
        self._motor_driver_state = MotorDriverState.IDLE

        # Declare parameters
        self.declare_parameters(
            namespace='',
            parameters=[
                ('motor_output_silence_period',  0.3), # Seconds
                ('motor_interface',  ""),
                ('motor_output_scale', 0.1),
                ('simulation', False) # Specifies if the motor driver should send motor ouputs to the simulation
            ])                        # environment or the real motors. Defaults to False, and is set to True in the simulation
                                      # launch file.
        # Load parameters
        self._motor_output_silence_period = self.get_parameter('motor_output_silence_period').get_parameter_value().double_value # Seconds
        self._motor_output_scale = self.get_parameter('motor_output_scale').get_parameter_value().double_value # Percentage
        self._motor_interface = json.loads(self.get_parameter('motor_interface').get_parameter_value().string_value)
        self._simulation_env = self.get_parameter('simulation').get_parameter_value().bool_value
        # Check if we are supposed to run in the simulation environment
        if self._simulation_env:
            self._send_motor_outputs_fn = self._send_to_simulation
        else:
            self._send_motor_outputs_fn = self._send_motor_outputs

        # Set default motor state to active
        self.motors_killed = False

        # Watchdog timer for the motor output silence (we want the agent to stop if no command is received within a defined timer period)
        self._motor_output_silence_watchdog_timer = self.create_timer(self._motor_output_silence_period, self._motor_output_silence_watchdog_timer_callback)
        # Timestamp that tracks when the last motor output was actively sent to the motors
        self._last_motor_output_timestamp = -np.inf

        # Subscriptions
        # -------------
        self._motor_output_subscription = self.create_subscription(
            MotorOutputs,
            'motor_control/motor_output',
            self._motor_output_sub_callback,
            1 # TODO: Use deadlines?
        )

        # Publishers
        # -------------
        if self._simulation_env:
            # Publisher for the motors in stonefish simulator
            self._sim_motor_publisher = self.create_publisher(
                Setpoints,
                'simulation/thruster_setpoints',
                10
            )

        # Services
        # --------
        self._kill_motors_service = self.create_service(
            Trigger,
            'motor_driver/motors/kill',
            self._kill_motors_service_callback
        )
        self._kill_motors_service = self.create_service(
            Trigger,
            'motor_driver/motors/activate',
            self._activate_motors_service_callback
        )
        # Service to retrieve the state of the node
        self._get_state_server = self.create_service(
            GetState,
            'motor_driver/state/get',
            self._get_state_callback
        )

    @abstractmethod
    def _send_motor_outputs(self, motor_values):
        pass
    
    def _send_to_simulation(self, motor_outputs):
        """Converts motor_outputs to Setpoints and sends the values
        to the simulation topic.
        """
        # Motor values are sent to the motors set the last output timestamp.
        self._last_motor_output_timestamp = self.get_clock().now().nanoseconds/1000000000
        # Create the thruster Setpoints message
        msg = Setpoints()
        outputs = []
        for motor_output in motor_outputs:
            # Scale the output according to the motor_output_scale parameter
            outputs.append(float(motor_output.value * self._motor_output_scale))

        msg.setpoints = outputs
        self.get_logger().info(f"Publishing motor outputs to simulation. Outputs: {msg}")
        self._sim_motor_publisher.publish(msg)

    def __send_motor_outputs(self, motor_outputs):
        """Private wrapper for the _send_motor_value abstract method.
        This wrapper ensures that the killed state of the motors is respected.
        The wrapper calls the method that is assigned to the send_motor_outputs_fn,
        which is a method that sends to the simulator, or a method that sends to the real motors.
        """
        if self.motors_killed:
            self.get_logger().info('Motors are killed. Not sending motor values.')
            return

        self._send_motor_outputs_fn(motor_outputs)

    def set_zero_motor_output(self):
        """Simply sets all motors output to zero.
        """
        # motor_outputs = MotorOutputs()
        outputs = []
        for motor in self._motor_interface:
            output = MotorOutput()
            output.id, output.value = motor["id"], 0.0
            outputs.append(output)
        # motor_outputs.motor_outputs = outputs
        self._send_motor_outputs_fn(outputs)

    #                   Callbacks
    # -----------------------------------------        
    def _get_state_callback(self, _, response):
        """Simple getter for the node's state.
        """
        response.success = True
        response.state = str(self._motor_driver_state)
        response.int_state = self._motor_driver_state

        return response

    def _kill_motors_service_callback(self, _, response):
        """Callback function for the kill_motors service.
        The motors are killed by setting the motor output to 0 and the motors_killed boolean to True,
        which will hinder any motor values from getting to the motors.
        """
        try:
            self.set_zero_motor_output()
            self._motor_driver_state = MotorDriverState.KILLED
            self.motors_killed = True
            response.success = True
            response.message = "Successfully killed the motors."
        except Exception as e:
            response.success = False
            response.message = f"Failed to kill the motors. Error: {e}"

        return response

    def _activate_motors_service_callback(self, _, response):
        """Callback function for the activate_motors service.
        """
        try:
            self._motor_driver_state = MotorDriverState.ACTIVE
            self.motors_killed = False
            response.success = True
            response.message = "Successfully activated the motors."
        except Exception as e:
            response.success = False
            response.message = f"Failed to activate the motors. Error: {e}"
        
        return response
    

    def _motor_output_silence_watchdog_timer_callback(self):
        """Callback for the motor output silence watchdog timer that simply sets all motor values to 0
        to avoid the agent from escaping form us in case the motor control node stops functioning. 
        """

        self.get_logger().debug('Watchdog timer for motor output silence triggered.')
        timestamp = self.get_clock().now().nanoseonds/1000000000
        time_delta = timestamp - self._last_motor_output_timestamp
        if time_delta > self._motor_output_silence_period:
            self.set_zero_motor_output()
            self.get_logger().info('Watchdog timer noticed that no motor output has been sent to to motors within accepted interval. Setting motors to zero.')
            self._motor_driver_state = MotorDriverState.MOTOR_OUTPUT_SILENCE

        # # Cancel the timer so it behaves like a oneshot timer.
        # # self._motor_output_silence_watchdog_timer.cancel()
        # # Send the output 3 times to increase the chances of the message not being timed out when added to serial write queue.
        # # TODO: Change the motor output message contain a timestamp and let the serial check if the message is too old, and if it 
        # # is, send zero values instead.
        # for _ in range(1):
        #     # self.set_zero_motor_output()
        #     # self.get_logger().info('Watchdog timer for motor output silence triggered.')
        #     self._motor_driver_state = MotorDriverState.MOTOR_OUTPUT_SILENCE

    def _motor_output_sub_callback(self, msg):
        """Callback for messages received on the motor_control/motor_output topic.
        Sends the received motor values to the motors via the MiniMaestro.
        Also starts a watchdog timer that sets the motor values to 0 on all motors
        if no motor output message is received within a 100 ms period.
        """
        # Stop the timer so that it doesn't trigger while we are processing the message
        # self._motor_output_silence_watchdog_timer.cancel()

        # eck if the motors are supposed to be killed
        if not self.motors_killed:
            motor_outputs = msg.motor_outputs
            # self.get_logger().info(f'Publishing motor output values to the motors. Motor values: {motor_outputs}')
            self._motor_driver_state = MotorDriverState.ACTIVE
            # for motor_num, value in motor_outputs:
            self.__send_motor_outputs(motor_outputs)
            # Motor values are sent to the motors set the last output timestamp.
            self._last_motor_output_timestamp = self.get_clock().now().nanoseconds/1000000000
            # self._motor_output_silence_watchdog_timer.reset()
        else:
            self.get_logger().info('Motors are currently killed. No motor output sent to the motors.\n' \
                                   'Activate the motors again by calling the motor_driver/motors/activate service.')



