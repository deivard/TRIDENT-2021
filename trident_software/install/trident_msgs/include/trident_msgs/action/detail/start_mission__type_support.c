// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from trident_msgs:action/StartMission.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "trident_msgs/action/detail/start_mission__rosidl_typesupport_introspection_c.h"
#include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "trident_msgs/action/detail/start_mission__functions.h"
#include "trident_msgs/action/detail/start_mission__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void StartMission_Goal__rosidl_typesupport_introspection_c__StartMission_Goal_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__StartMission_Goal__init(message_memory);
}

void StartMission_Goal__rosidl_typesupport_introspection_c__StartMission_Goal_fini_function(void * message_memory)
{
  trident_msgs__action__StartMission_Goal__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember StartMission_Goal__rosidl_typesupport_introspection_c__StartMission_Goal_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__StartMission_Goal, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers StartMission_Goal__rosidl_typesupport_introspection_c__StartMission_Goal_message_members = {
  "trident_msgs__action",  // message namespace
  "StartMission_Goal",  // message name
  1,  // number of fields
  sizeof(trident_msgs__action__StartMission_Goal),
  StartMission_Goal__rosidl_typesupport_introspection_c__StartMission_Goal_message_member_array,  // message members
  StartMission_Goal__rosidl_typesupport_introspection_c__StartMission_Goal_init_function,  // function to initialize message memory (memory has to be allocated)
  StartMission_Goal__rosidl_typesupport_introspection_c__StartMission_Goal_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t StartMission_Goal__rosidl_typesupport_introspection_c__StartMission_Goal_message_type_support_handle = {
  0,
  &StartMission_Goal__rosidl_typesupport_introspection_c__StartMission_Goal_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_Goal)() {
  if (!StartMission_Goal__rosidl_typesupport_introspection_c__StartMission_Goal_message_type_support_handle.typesupport_identifier) {
    StartMission_Goal__rosidl_typesupport_introspection_c__StartMission_Goal_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &StartMission_Goal__rosidl_typesupport_introspection_c__StartMission_Goal_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/start_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__functions.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__struct.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void StartMission_Result__rosidl_typesupport_introspection_c__StartMission_Result_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__StartMission_Result__init(message_memory);
}

void StartMission_Result__rosidl_typesupport_introspection_c__StartMission_Result_fini_function(void * message_memory)
{
  trident_msgs__action__StartMission_Result__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember StartMission_Result__rosidl_typesupport_introspection_c__StartMission_Result_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__StartMission_Result, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__StartMission_Result, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers StartMission_Result__rosidl_typesupport_introspection_c__StartMission_Result_message_members = {
  "trident_msgs__action",  // message namespace
  "StartMission_Result",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__StartMission_Result),
  StartMission_Result__rosidl_typesupport_introspection_c__StartMission_Result_message_member_array,  // message members
  StartMission_Result__rosidl_typesupport_introspection_c__StartMission_Result_init_function,  // function to initialize message memory (memory has to be allocated)
  StartMission_Result__rosidl_typesupport_introspection_c__StartMission_Result_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t StartMission_Result__rosidl_typesupport_introspection_c__StartMission_Result_message_type_support_handle = {
  0,
  &StartMission_Result__rosidl_typesupport_introspection_c__StartMission_Result_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_Result)() {
  if (!StartMission_Result__rosidl_typesupport_introspection_c__StartMission_Result_message_type_support_handle.typesupport_identifier) {
    StartMission_Result__rosidl_typesupport_introspection_c__StartMission_Result_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &StartMission_Result__rosidl_typesupport_introspection_c__StartMission_Result_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/start_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__functions.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__struct.h"


// Include directives for member types
// Member `message`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void StartMission_Feedback__rosidl_typesupport_introspection_c__StartMission_Feedback_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__StartMission_Feedback__init(message_memory);
}

void StartMission_Feedback__rosidl_typesupport_introspection_c__StartMission_Feedback_fini_function(void * message_memory)
{
  trident_msgs__action__StartMission_Feedback__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember StartMission_Feedback__rosidl_typesupport_introspection_c__StartMission_Feedback_message_member_array[3] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__StartMission_Feedback, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "message",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__StartMission_Feedback, message),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "waypoints_completed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT16,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__StartMission_Feedback, waypoints_completed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers StartMission_Feedback__rosidl_typesupport_introspection_c__StartMission_Feedback_message_members = {
  "trident_msgs__action",  // message namespace
  "StartMission_Feedback",  // message name
  3,  // number of fields
  sizeof(trident_msgs__action__StartMission_Feedback),
  StartMission_Feedback__rosidl_typesupport_introspection_c__StartMission_Feedback_message_member_array,  // message members
  StartMission_Feedback__rosidl_typesupport_introspection_c__StartMission_Feedback_init_function,  // function to initialize message memory (memory has to be allocated)
  StartMission_Feedback__rosidl_typesupport_introspection_c__StartMission_Feedback_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t StartMission_Feedback__rosidl_typesupport_introspection_c__StartMission_Feedback_message_type_support_handle = {
  0,
  &StartMission_Feedback__rosidl_typesupport_introspection_c__StartMission_Feedback_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_Feedback)() {
  if (!StartMission_Feedback__rosidl_typesupport_introspection_c__StartMission_Feedback_message_type_support_handle.typesupport_identifier) {
    StartMission_Feedback__rosidl_typesupport_introspection_c__StartMission_Feedback_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &StartMission_Feedback__rosidl_typesupport_introspection_c__StartMission_Feedback_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/start_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__functions.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__struct.h"


// Include directives for member types
// Member `goal_id`
#include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
#include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `goal`
#include "trident_msgs/action/start_mission.h"
// Member `goal`
// already included above
// #include "trident_msgs/action/detail/start_mission__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void StartMission_SendGoal_Request__rosidl_typesupport_introspection_c__StartMission_SendGoal_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__StartMission_SendGoal_Request__init(message_memory);
}

void StartMission_SendGoal_Request__rosidl_typesupport_introspection_c__StartMission_SendGoal_Request_fini_function(void * message_memory)
{
  trident_msgs__action__StartMission_SendGoal_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember StartMission_SendGoal_Request__rosidl_typesupport_introspection_c__StartMission_SendGoal_Request_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__StartMission_SendGoal_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "goal",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__StartMission_SendGoal_Request, goal),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers StartMission_SendGoal_Request__rosidl_typesupport_introspection_c__StartMission_SendGoal_Request_message_members = {
  "trident_msgs__action",  // message namespace
  "StartMission_SendGoal_Request",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__StartMission_SendGoal_Request),
  StartMission_SendGoal_Request__rosidl_typesupport_introspection_c__StartMission_SendGoal_Request_message_member_array,  // message members
  StartMission_SendGoal_Request__rosidl_typesupport_introspection_c__StartMission_SendGoal_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  StartMission_SendGoal_Request__rosidl_typesupport_introspection_c__StartMission_SendGoal_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t StartMission_SendGoal_Request__rosidl_typesupport_introspection_c__StartMission_SendGoal_Request_message_type_support_handle = {
  0,
  &StartMission_SendGoal_Request__rosidl_typesupport_introspection_c__StartMission_SendGoal_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_SendGoal_Request)() {
  StartMission_SendGoal_Request__rosidl_typesupport_introspection_c__StartMission_SendGoal_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  StartMission_SendGoal_Request__rosidl_typesupport_introspection_c__StartMission_SendGoal_Request_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_Goal)();
  if (!StartMission_SendGoal_Request__rosidl_typesupport_introspection_c__StartMission_SendGoal_Request_message_type_support_handle.typesupport_identifier) {
    StartMission_SendGoal_Request__rosidl_typesupport_introspection_c__StartMission_SendGoal_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &StartMission_SendGoal_Request__rosidl_typesupport_introspection_c__StartMission_SendGoal_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/start_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__functions.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__struct.h"


// Include directives for member types
// Member `stamp`
#include "builtin_interfaces/msg/time.h"
// Member `stamp`
#include "builtin_interfaces/msg/detail/time__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void StartMission_SendGoal_Response__rosidl_typesupport_introspection_c__StartMission_SendGoal_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__StartMission_SendGoal_Response__init(message_memory);
}

void StartMission_SendGoal_Response__rosidl_typesupport_introspection_c__StartMission_SendGoal_Response_fini_function(void * message_memory)
{
  trident_msgs__action__StartMission_SendGoal_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember StartMission_SendGoal_Response__rosidl_typesupport_introspection_c__StartMission_SendGoal_Response_message_member_array[2] = {
  {
    "accepted",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__StartMission_SendGoal_Response, accepted),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "stamp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__StartMission_SendGoal_Response, stamp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers StartMission_SendGoal_Response__rosidl_typesupport_introspection_c__StartMission_SendGoal_Response_message_members = {
  "trident_msgs__action",  // message namespace
  "StartMission_SendGoal_Response",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__StartMission_SendGoal_Response),
  StartMission_SendGoal_Response__rosidl_typesupport_introspection_c__StartMission_SendGoal_Response_message_member_array,  // message members
  StartMission_SendGoal_Response__rosidl_typesupport_introspection_c__StartMission_SendGoal_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  StartMission_SendGoal_Response__rosidl_typesupport_introspection_c__StartMission_SendGoal_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t StartMission_SendGoal_Response__rosidl_typesupport_introspection_c__StartMission_SendGoal_Response_message_type_support_handle = {
  0,
  &StartMission_SendGoal_Response__rosidl_typesupport_introspection_c__StartMission_SendGoal_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_SendGoal_Response)() {
  StartMission_SendGoal_Response__rosidl_typesupport_introspection_c__StartMission_SendGoal_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, builtin_interfaces, msg, Time)();
  if (!StartMission_SendGoal_Response__rosidl_typesupport_introspection_c__StartMission_SendGoal_Response_message_type_support_handle.typesupport_identifier) {
    StartMission_SendGoal_Response__rosidl_typesupport_introspection_c__StartMission_SendGoal_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &StartMission_SendGoal_Response__rosidl_typesupport_introspection_c__StartMission_SendGoal_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_SendGoal_service_members = {
  "trident_msgs__action",  // service namespace
  "StartMission_SendGoal",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_SendGoal_Request_message_type_support_handle,
  NULL  // response message
  // trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_SendGoal_Response_message_type_support_handle
};

static rosidl_service_type_support_t trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_SendGoal_service_type_support_handle = {
  0,
  &trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_SendGoal_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_SendGoal_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_SendGoal_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_SendGoal)() {
  if (!trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_SendGoal_service_type_support_handle.typesupport_identifier) {
    trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_SendGoal_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_SendGoal_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_SendGoal_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_SendGoal_Response)()->data;
  }

  return &trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_SendGoal_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/start_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__functions.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void StartMission_GetResult_Request__rosidl_typesupport_introspection_c__StartMission_GetResult_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__StartMission_GetResult_Request__init(message_memory);
}

void StartMission_GetResult_Request__rosidl_typesupport_introspection_c__StartMission_GetResult_Request_fini_function(void * message_memory)
{
  trident_msgs__action__StartMission_GetResult_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember StartMission_GetResult_Request__rosidl_typesupport_introspection_c__StartMission_GetResult_Request_message_member_array[1] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__StartMission_GetResult_Request, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers StartMission_GetResult_Request__rosidl_typesupport_introspection_c__StartMission_GetResult_Request_message_members = {
  "trident_msgs__action",  // message namespace
  "StartMission_GetResult_Request",  // message name
  1,  // number of fields
  sizeof(trident_msgs__action__StartMission_GetResult_Request),
  StartMission_GetResult_Request__rosidl_typesupport_introspection_c__StartMission_GetResult_Request_message_member_array,  // message members
  StartMission_GetResult_Request__rosidl_typesupport_introspection_c__StartMission_GetResult_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  StartMission_GetResult_Request__rosidl_typesupport_introspection_c__StartMission_GetResult_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t StartMission_GetResult_Request__rosidl_typesupport_introspection_c__StartMission_GetResult_Request_message_type_support_handle = {
  0,
  &StartMission_GetResult_Request__rosidl_typesupport_introspection_c__StartMission_GetResult_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_GetResult_Request)() {
  StartMission_GetResult_Request__rosidl_typesupport_introspection_c__StartMission_GetResult_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  if (!StartMission_GetResult_Request__rosidl_typesupport_introspection_c__StartMission_GetResult_Request_message_type_support_handle.typesupport_identifier) {
    StartMission_GetResult_Request__rosidl_typesupport_introspection_c__StartMission_GetResult_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &StartMission_GetResult_Request__rosidl_typesupport_introspection_c__StartMission_GetResult_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/start_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__functions.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__struct.h"


// Include directives for member types
// Member `result`
// already included above
// #include "trident_msgs/action/start_mission.h"
// Member `result`
// already included above
// #include "trident_msgs/action/detail/start_mission__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void StartMission_GetResult_Response__rosidl_typesupport_introspection_c__StartMission_GetResult_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__StartMission_GetResult_Response__init(message_memory);
}

void StartMission_GetResult_Response__rosidl_typesupport_introspection_c__StartMission_GetResult_Response_fini_function(void * message_memory)
{
  trident_msgs__action__StartMission_GetResult_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember StartMission_GetResult_Response__rosidl_typesupport_introspection_c__StartMission_GetResult_Response_message_member_array[2] = {
  {
    "status",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__StartMission_GetResult_Response, status),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "result",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__StartMission_GetResult_Response, result),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers StartMission_GetResult_Response__rosidl_typesupport_introspection_c__StartMission_GetResult_Response_message_members = {
  "trident_msgs__action",  // message namespace
  "StartMission_GetResult_Response",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__StartMission_GetResult_Response),
  StartMission_GetResult_Response__rosidl_typesupport_introspection_c__StartMission_GetResult_Response_message_member_array,  // message members
  StartMission_GetResult_Response__rosidl_typesupport_introspection_c__StartMission_GetResult_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  StartMission_GetResult_Response__rosidl_typesupport_introspection_c__StartMission_GetResult_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t StartMission_GetResult_Response__rosidl_typesupport_introspection_c__StartMission_GetResult_Response_message_type_support_handle = {
  0,
  &StartMission_GetResult_Response__rosidl_typesupport_introspection_c__StartMission_GetResult_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_GetResult_Response)() {
  StartMission_GetResult_Response__rosidl_typesupport_introspection_c__StartMission_GetResult_Response_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_Result)();
  if (!StartMission_GetResult_Response__rosidl_typesupport_introspection_c__StartMission_GetResult_Response_message_type_support_handle.typesupport_identifier) {
    StartMission_GetResult_Response__rosidl_typesupport_introspection_c__StartMission_GetResult_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &StartMission_GetResult_Response__rosidl_typesupport_introspection_c__StartMission_GetResult_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_GetResult_service_members = {
  "trident_msgs__action",  // service namespace
  "StartMission_GetResult",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_GetResult_Request_message_type_support_handle,
  NULL  // response message
  // trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_GetResult_Response_message_type_support_handle
};

static rosidl_service_type_support_t trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_GetResult_service_type_support_handle = {
  0,
  &trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_GetResult_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_GetResult_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_GetResult_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_GetResult)() {
  if (!trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_GetResult_service_type_support_handle.typesupport_identifier) {
    trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_GetResult_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_GetResult_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_GetResult_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_GetResult_Response)()->data;
  }

  return &trident_msgs__action__detail__start_mission__rosidl_typesupport_introspection_c__StartMission_GetResult_service_type_support_handle;
}

// already included above
// #include <stddef.h>
// already included above
// #include "trident_msgs/action/detail/start_mission__rosidl_typesupport_introspection_c.h"
// already included above
// #include "trident_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__functions.h"
// already included above
// #include "trident_msgs/action/detail/start_mission__struct.h"


// Include directives for member types
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/uuid.h"
// Member `goal_id`
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__rosidl_typesupport_introspection_c.h"
// Member `feedback`
// already included above
// #include "trident_msgs/action/start_mission.h"
// Member `feedback`
// already included above
// #include "trident_msgs/action/detail/start_mission__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void StartMission_FeedbackMessage__rosidl_typesupport_introspection_c__StartMission_FeedbackMessage_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  trident_msgs__action__StartMission_FeedbackMessage__init(message_memory);
}

void StartMission_FeedbackMessage__rosidl_typesupport_introspection_c__StartMission_FeedbackMessage_fini_function(void * message_memory)
{
  trident_msgs__action__StartMission_FeedbackMessage__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember StartMission_FeedbackMessage__rosidl_typesupport_introspection_c__StartMission_FeedbackMessage_message_member_array[2] = {
  {
    "goal_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__StartMission_FeedbackMessage, goal_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "feedback",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(trident_msgs__action__StartMission_FeedbackMessage, feedback),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers StartMission_FeedbackMessage__rosidl_typesupport_introspection_c__StartMission_FeedbackMessage_message_members = {
  "trident_msgs__action",  // message namespace
  "StartMission_FeedbackMessage",  // message name
  2,  // number of fields
  sizeof(trident_msgs__action__StartMission_FeedbackMessage),
  StartMission_FeedbackMessage__rosidl_typesupport_introspection_c__StartMission_FeedbackMessage_message_member_array,  // message members
  StartMission_FeedbackMessage__rosidl_typesupport_introspection_c__StartMission_FeedbackMessage_init_function,  // function to initialize message memory (memory has to be allocated)
  StartMission_FeedbackMessage__rosidl_typesupport_introspection_c__StartMission_FeedbackMessage_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t StartMission_FeedbackMessage__rosidl_typesupport_introspection_c__StartMission_FeedbackMessage_message_type_support_handle = {
  0,
  &StartMission_FeedbackMessage__rosidl_typesupport_introspection_c__StartMission_FeedbackMessage_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_trident_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_FeedbackMessage)() {
  StartMission_FeedbackMessage__rosidl_typesupport_introspection_c__StartMission_FeedbackMessage_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, unique_identifier_msgs, msg, UUID)();
  StartMission_FeedbackMessage__rosidl_typesupport_introspection_c__StartMission_FeedbackMessage_message_member_array[1].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, trident_msgs, action, StartMission_Feedback)();
  if (!StartMission_FeedbackMessage__rosidl_typesupport_introspection_c__StartMission_FeedbackMessage_message_type_support_handle.typesupport_identifier) {
    StartMission_FeedbackMessage__rosidl_typesupport_introspection_c__StartMission_FeedbackMessage_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &StartMission_FeedbackMessage__rosidl_typesupport_introspection_c__StartMission_FeedbackMessage_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
