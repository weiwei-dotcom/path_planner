// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from interface:msg/GetPathpoints.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "interface/msg/detail/get_pathpoints__rosidl_typesupport_introspection_c.h"
#include "interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "interface/msg/detail/get_pathpoints__functions.h"
#include "interface/msg/detail/get_pathpoints__struct.h"


// Include directives for member types
// Member `path_points`
#include "geometry_msgs/msg/point.h"
// Member `path_points`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void GetPathpoints__rosidl_typesupport_introspection_c__GetPathpoints_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  interface__msg__GetPathpoints__init(message_memory);
}

void GetPathpoints__rosidl_typesupport_introspection_c__GetPathpoints_fini_function(void * message_memory)
{
  interface__msg__GetPathpoints__fini(message_memory);
}

size_t GetPathpoints__rosidl_typesupport_introspection_c__size_function__Point__path_points(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * GetPathpoints__rosidl_typesupport_introspection_c__get_const_function__Point__path_points(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * GetPathpoints__rosidl_typesupport_introspection_c__get_function__Point__path_points(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

bool GetPathpoints__rosidl_typesupport_introspection_c__resize_function__Point__path_points(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember GetPathpoints__rosidl_typesupport_introspection_c__GetPathpoints_message_member_array[1] = {
  {
    "path_points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__msg__GetPathpoints, path_points),  // bytes offset in struct
    NULL,  // default value
    GetPathpoints__rosidl_typesupport_introspection_c__size_function__Point__path_points,  // size() function pointer
    GetPathpoints__rosidl_typesupport_introspection_c__get_const_function__Point__path_points,  // get_const(index) function pointer
    GetPathpoints__rosidl_typesupport_introspection_c__get_function__Point__path_points,  // get(index) function pointer
    GetPathpoints__rosidl_typesupport_introspection_c__resize_function__Point__path_points  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers GetPathpoints__rosidl_typesupport_introspection_c__GetPathpoints_message_members = {
  "interface__msg",  // message namespace
  "GetPathpoints",  // message name
  1,  // number of fields
  sizeof(interface__msg__GetPathpoints),
  GetPathpoints__rosidl_typesupport_introspection_c__GetPathpoints_message_member_array,  // message members
  GetPathpoints__rosidl_typesupport_introspection_c__GetPathpoints_init_function,  // function to initialize message memory (memory has to be allocated)
  GetPathpoints__rosidl_typesupport_introspection_c__GetPathpoints_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t GetPathpoints__rosidl_typesupport_introspection_c__GetPathpoints_message_type_support_handle = {
  0,
  &GetPathpoints__rosidl_typesupport_introspection_c__GetPathpoints_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, msg, GetPathpoints)() {
  GetPathpoints__rosidl_typesupport_introspection_c__GetPathpoints_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!GetPathpoints__rosidl_typesupport_introspection_c__GetPathpoints_message_type_support_handle.typesupport_identifier) {
    GetPathpoints__rosidl_typesupport_introspection_c__GetPathpoints_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &GetPathpoints__rosidl_typesupport_introspection_c__GetPathpoints_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
