// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interface:srv/PathPlan.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__PATH_PLAN__STRUCT_H_
#define INTERFACE__SRV__DETAIL__PATH_PLAN__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'start_position'
// Member 'end_position'
#include "geometry_msgs/msg/detail/point__struct.h"
// Member 'start_velocity'
// Member 'end_velocity'
#include "geometry_msgs/msg/detail/vector3__struct.h"

// Struct defined in srv/PathPlan in the package interface.
typedef struct interface__srv__PathPlan_Request
{
  geometry_msgs__msg__Point start_position;
  geometry_msgs__msg__Vector3 start_velocity;
  geometry_msgs__msg__Point end_position;
  geometry_msgs__msg__Vector3 end_velocity;
} interface__srv__PathPlan_Request;

// Struct for a sequence of interface__srv__PathPlan_Request.
typedef struct interface__srv__PathPlan_Request__Sequence
{
  interface__srv__PathPlan_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__srv__PathPlan_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'control_points'
// already included above
// #include "geometry_msgs/msg/detail/point__struct.h"

// Struct defined in srv/PathPlan in the package interface.
typedef struct interface__srv__PathPlan_Response
{
  geometry_msgs__msg__Point__Sequence control_points;
  int16_t degree;
  double knot_interval;
  bool success;
} interface__srv__PathPlan_Response;

// Struct for a sequence of interface__srv__PathPlan_Response.
typedef struct interface__srv__PathPlan_Response__Sequence
{
  interface__srv__PathPlan_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__srv__PathPlan_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACE__SRV__DETAIL__PATH_PLAN__STRUCT_H_
