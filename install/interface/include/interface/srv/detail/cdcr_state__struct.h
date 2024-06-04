// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interface:srv/CdcrState.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__CDCR_STATE__STRUCT_H_
#define INTERFACE__SRV__DETAIL__CDCR_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'alpha_now'
// Member 'theta_now'
#include "rosidl_runtime_c/primitives_sequence.h"
// Member 'base_pose_now'
#include "geometry_msgs/msg/detail/pose__struct.h"

// Struct defined in srv/CdcrState in the package interface.
typedef struct interface__srv__CdcrState_Request
{
  rosidl_runtime_c__double__Sequence alpha_now;
  rosidl_runtime_c__double__Sequence theta_now;
  geometry_msgs__msg__Pose base_pose_now;
} interface__srv__CdcrState_Request;

// Struct for a sequence of interface__srv__CdcrState_Request.
typedef struct interface__srv__CdcrState_Request__Sequence
{
  interface__srv__CdcrState_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__srv__CdcrState_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'alpha_tar'
// Member 'theta_tar'
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"
// Member 'base_pose_tar'
// already included above
// #include "geometry_msgs/msg/detail/pose__struct.h"

// Struct defined in srv/CdcrState in the package interface.
typedef struct interface__srv__CdcrState_Response
{
  rosidl_runtime_c__double__Sequence alpha_tar;
  rosidl_runtime_c__double__Sequence theta_tar;
  geometry_msgs__msg__Pose base_pose_tar;
  bool success;
} interface__srv__CdcrState_Response;

// Struct for a sequence of interface__srv__CdcrState_Response.
typedef struct interface__srv__CdcrState_Response__Sequence
{
  interface__srv__CdcrState_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__srv__CdcrState_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACE__SRV__DETAIL__CDCR_STATE__STRUCT_H_
