// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interface:srv/FlagPoints.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__FLAG_POINTS__STRUCT_H_
#define INTERFACE__SRV__DETAIL__FLAG_POINTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'points'
#include "geometry_msgs/msg/detail/point__struct.h"

// Struct defined in srv/FlagPoints in the package interface.
typedef struct interface__srv__FlagPoints_Request
{
  geometry_msgs__msg__Point__Sequence points;
} interface__srv__FlagPoints_Request;

// Struct for a sequence of interface__srv__FlagPoints_Request.
typedef struct interface__srv__FlagPoints_Request__Sequence
{
  interface__srv__FlagPoints_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__srv__FlagPoints_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/FlagPoints in the package interface.
typedef struct interface__srv__FlagPoints_Response
{
  bool flag;
} interface__srv__FlagPoints_Response;

// Struct for a sequence of interface__srv__FlagPoints_Response.
typedef struct interface__srv__FlagPoints_Response__Sequence
{
  interface__srv__FlagPoints_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__srv__FlagPoints_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACE__SRV__DETAIL__FLAG_POINTS__STRUCT_H_
