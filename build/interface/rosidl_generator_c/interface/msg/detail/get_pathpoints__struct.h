// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interface:msg/GetPathpoints.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__GET_PATHPOINTS__STRUCT_H_
#define INTERFACE__MSG__DETAIL__GET_PATHPOINTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'path_points'
#include "geometry_msgs/msg/detail/point__struct.h"

// Struct defined in msg/GetPathpoints in the package interface.
typedef struct interface__msg__GetPathpoints
{
  geometry_msgs__msg__Point__Sequence path_points;
} interface__msg__GetPathpoints;

// Struct for a sequence of interface__msg__GetPathpoints.
typedef struct interface__msg__GetPathpoints__Sequence
{
  interface__msg__GetPathpoints * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__msg__GetPathpoints__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACE__MSG__DETAIL__GET_PATHPOINTS__STRUCT_H_
