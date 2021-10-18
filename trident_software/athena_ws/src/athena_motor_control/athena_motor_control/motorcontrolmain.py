import rclpy
from baseclasses.motorcontrolbase import MotorControlBase

class MotorControlNode(MotorControlBase):
    """The main node for the motor control module. 
    """
    def __init__(self, node_name) -> None:
        super().__init__(node_name)
        self.get_logger().info("Created motor control node.")


def main(args=None):
    rclpy.init(args=args)
    motor_control_node = MotorControlNode("motor_control")
    # while(rclpy.ok()):
    rclpy.spin(motor_control_node)
    rclpy.shutdown()


if __name__=="__main__":
    main()


