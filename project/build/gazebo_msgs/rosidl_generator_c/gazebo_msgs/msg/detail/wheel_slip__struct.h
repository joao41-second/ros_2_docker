// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gazebo_msgs:msg/WheelSlip.idl
// generated code does not contain a copyright notice

#ifndef GAZEBO_MSGS__MSG__DETAIL__WHEEL_SLIP__STRUCT_H_
#define GAZEBO_MSGS__MSG__DETAIL__WHEEL_SLIP__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'name'
#include "rosidl_runtime_c/string.h"
// Member 'lateral_slip'
// Member 'longitudinal_slip'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/WheelSlip in the package gazebo_msgs.
typedef struct gazebo_msgs__msg__WheelSlip
{
  rosidl_runtime_c__String__Sequence name;
  rosidl_runtime_c__double__Sequence lateral_slip;
  rosidl_runtime_c__double__Sequence longitudinal_slip;
} gazebo_msgs__msg__WheelSlip;

// Struct for a sequence of gazebo_msgs__msg__WheelSlip.
typedef struct gazebo_msgs__msg__WheelSlip__Sequence
{
  gazebo_msgs__msg__WheelSlip * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gazebo_msgs__msg__WheelSlip__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GAZEBO_MSGS__MSG__DETAIL__WHEEL_SLIP__STRUCT_H_
