// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from gazebo_msgs:msg/WheelSlip.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "gazebo_msgs/msg/detail/wheel_slip__rosidl_typesupport_introspection_c.h"
#include "gazebo_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "gazebo_msgs/msg/detail/wheel_slip__functions.h"
#include "gazebo_msgs/msg/detail/wheel_slip__struct.h"


// Include directives for member types
// Member `name`
#include "rosidl_runtime_c/string_functions.h"
// Member `lateral_slip`
// Member `longitudinal_slip`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void WheelSlip__rosidl_typesupport_introspection_c__WheelSlip_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gazebo_msgs__msg__WheelSlip__init(message_memory);
}

void WheelSlip__rosidl_typesupport_introspection_c__WheelSlip_fini_function(void * message_memory)
{
  gazebo_msgs__msg__WheelSlip__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember WheelSlip__rosidl_typesupport_introspection_c__WheelSlip_message_member_array[3] = {
  {
    "name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gazebo_msgs__msg__WheelSlip, name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lateral_slip",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gazebo_msgs__msg__WheelSlip, lateral_slip),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "longitudinal_slip",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gazebo_msgs__msg__WheelSlip, longitudinal_slip),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers WheelSlip__rosidl_typesupport_introspection_c__WheelSlip_message_members = {
  "gazebo_msgs__msg",  // message namespace
  "WheelSlip",  // message name
  3,  // number of fields
  sizeof(gazebo_msgs__msg__WheelSlip),
  WheelSlip__rosidl_typesupport_introspection_c__WheelSlip_message_member_array,  // message members
  WheelSlip__rosidl_typesupport_introspection_c__WheelSlip_init_function,  // function to initialize message memory (memory has to be allocated)
  WheelSlip__rosidl_typesupport_introspection_c__WheelSlip_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t WheelSlip__rosidl_typesupport_introspection_c__WheelSlip_message_type_support_handle = {
  0,
  &WheelSlip__rosidl_typesupport_introspection_c__WheelSlip_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gazebo_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gazebo_msgs, msg, WheelSlip)() {
  if (!WheelSlip__rosidl_typesupport_introspection_c__WheelSlip_message_type_support_handle.typesupport_identifier) {
    WheelSlip__rosidl_typesupport_introspection_c__WheelSlip_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &WheelSlip__rosidl_typesupport_introspection_c__WheelSlip_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
