#!/usr/bin/env python3
import rclpy
import os
from trident_msgs.msg import PidParam
from rcl_interfaces.srv import GetParameters
import json
from tabulate import tabulate

import sys, select, termios, tty



SETTINGS = termios.tcgetattr(sys.stdin)

def getKey():
    tty.setraw(sys.stdin.fileno())
    select.select([sys.stdin], [], [], 0)
    key = sys.stdin.read(1)
    termios.tcsetattr(sys.stdin, termios.TCSADRAIN, SETTINGS)
    return key

def print_increments(pid_increments):
    print(f"Current increments:\tp={pid_increments['p']},\ti={pid_increments['i']},\td={pid_increments['d']}")

def print_affected_pid(affected_pid):
    print(f"Currently affecting PID: {affected_pid}")

def print_feedback(params, active_pid_element, active_key):
    data = [
        ["Kp", params["p"]["x"], params["p"]["y"], params["p"]["z"], params["p"]["roll"], params["p"]["pitch"], params["p"]["yaw"]],
        ["Ki", params["i"]["x"], params["i"]["y"], params["i"]["z"], params["i"]["roll"], params["i"]["pitch"], params["i"]["yaw"]],
        ["Kd", params["d"]["x"], params["d"]["y"], params["d"]["z"], params["d"]["roll"], params["d"]["pitch"], params["d"]["yaw"]]
    ]
    headers = ["K", "x", "y", "z", "roll", "pitch", "yaw"]
    # Make the active key bold
    active_key_column = headers.index(active_key)
    headers[active_key_column] = f"\033[1m{active_key}\033[0m"
    # Make the active element and constant bold
    active_row = ["p", "i", "d"].index(active_pid_element)
    data[active_row][0] = f"\033[1m{data[active_row][0]}\033[0m"
    data[active_row][active_key_column] = f"\033[1m{data[active_row][active_key_column]}\033[0m"

    print(tabulate(data, headers=headers))

def print_increments(current_increments):
    print("Current increment values:")
    print(tabulate([[str(current_increments["p"]), str(current_increments["i"]), str(current_increments["d"])]], headers=["p","i","d"]))
    print("")

def print_welcome_msg(agent_name):
    welcome_msg = f"""
 _______________________________________
|
|  Welcome to the PID tuner.
|  Currently tuning: \033[1m{agent_name}\033[0m
|
|  Bindings for changing affected PID:
|      key | u | i | o | j     | k   | l 
|      PID | x | y | z | pitch | yaw | roll
|
|  Bindings for updating P/I/D values:
|           |          key          |
|   element | increment | decrement |
|      Kp   | q         | z
|      Ki   | w         | x
|      Kd   | e         | c
|
|  Increasing/decreasing the increment values by 0.01 (hold shift key):
|             |          key          |
|   increment | increase  | decrease  |
|      Kp     | Q         | Z
|      Ki     | W         | X
|      Kd     | E         | C
|
|  CTRL-C to quit
|
 ---------------------------------------
"""
    print(welcome_msg)


def clear_screen():
    os.system('cls' if os.name == 'nt' else "printf '\033c'")

def main(args=None):
    if args is None:
        args = sys.argv
    print(args)

    # Bindings for changing the currently affected PID
    change_affected_pid_bindings = {
        'u': 'x',
        'i': 'y',
        'o': 'z',
        'j': 'roll',
        'k': 'pitch',
        'l': 'yaw',

    }
    # Bindings for incrementing pid values
    pid_bindings={
            'q':("p", 1.0), # p+
            'z':("p",-1.0), # p-
            'w':("i", 1.0), # i+
            'x':("i",-1.0), # i-
            'e':("d", 1.0), # d+
            'c':("d",-1.0)  # d-
            }

    # Bindings for increaseing/decreasing the pid increment
    change_pid_increment_bindings = {
            'Q':("p", 0.01),
            'Z':("p",-0.01),
            'W':("i", 0.01),
            'X':("i",-0.01),
            'E':("d", 0.01),
            'C':("d",-0.01)

    }
    # Default pid increment/decrement values
    pid_increments = {
        'p': 0.05,
        'i': 0.05,
        'd': 0.05
    }

    rclpy.init()
    node = rclpy.create_node('pid_tuner')
    	
    param_publisher = node.create_publisher(PidParam, f'{args[1]}/motor_control/param/pid/set', 10)
    current_params_client = node.create_client(GetParameters, f"{args[1]}/motor_control/get_parameters")
    current_pid_key = "x"
    last_affected_element = "p"
    current_params = None

    try:
        while not current_params_client.wait_for_service(timeout_sec=1.0):
            node.get_logger().info('service not available, waiting again...')
        print("Retrieving current parameters from server...")
        current_params_request = GetParameters.Request()
        current_params_request.names = ['pid_config']
        future = current_params_client.call_async(current_params_request)
        rclpy.spin_until_future_complete(node, future)
        current_params = json.loads(future.result().values[0].string_value)
        clear_screen()
        print_welcome_msg(args[1])
        print_increments(pid_increments)
        print_feedback(current_params, last_affected_element, current_pid_key)
        param_msg = PidParam()
        while(1):
            key = getKey()

            # If the pressed key is a key that increment/decrement a pid value
            if key in pid_bindings.keys():
                last_affected_element = pid_bindings[key][0]
                param_msg.pid_element = pid_bindings[key][0]
                param_msg.key = current_pid_key
                param_msg.value = pid_bindings[key][1] * pid_increments[pid_bindings[key][0]]
                param_publisher.publish(param_msg)
                # Get the current param values to give user feedback of the new values
                current_params_request = GetParameters.Request()
                current_params_request.names = ['pid_config']
                future = current_params_client.call_async(current_params_request)
                rclpy.spin_until_future_complete(node, future)
                current_params = json.loads(future.result().values[0].string_value)

                # print(f"New value for PID {current_pid_key}: {param_msg.pid_element}={round(current_params[param_msg.pid_element][current_pid_key], 2)}")

            # If the pressed key is a key that increases/decreases the pid increment value
            elif key in change_pid_increment_bindings.keys():
                pid_increments[change_pid_increment_bindings[key][0]] = round(pid_increments[change_pid_increment_bindings[key][0]] + change_pid_increment_bindings[key][1], 2)
                print_increments(pid_increments)
            # If the presser key is a key that changes the affected PID
            elif key in change_affected_pid_bindings.keys():
                current_pid_key = change_affected_pid_bindings[key]
                print_affected_pid(current_pid_key)
            elif key == '\x03':
                break
                
            clear_screen()
            print_welcome_msg(args[1])
            print_increments(pid_increments)
            print_feedback(current_params, last_affected_element, current_pid_key)

    except Exception as e:
        print(e)

    finally:
        termios.tcsetattr(sys.stdin, termios.TCSADRAIN, SETTINGS)

if __name__=='__main__':
    main()