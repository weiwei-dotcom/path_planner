// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from interface:srv/FlagPoints.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "interface/srv/detail/flag_points__rosidl_typesupport_introspection_c.h"
#include "interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "interface/srv/detail/flag_points__functions.h"
#include "interface/srv/detail/flag_points__struct.h"


// Include directives for member types
// Member `points`
#include "geometry_msgs/msg/point.h"
// Member `points`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void FlagPoints_Request__rosidl_typesupport_introspection_c__FlagPoints_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  interface__srv__FlagPoints_Request__init(message_memory);
}

void FlagPoints_Request__rosidl_typesupport_introspection_c__FlagPoints_Request_fini_function(void * message_memory)
{
  interface__srv__FlagPoints_Request__fini(message_memory);
}

size_t FlagPoints_Request__rosidl_typesupport_introspection_c__size_function__Point__points(
  const void * untyped_member)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return member->size;
}

const void * FlagPoints_Request__rosidl_typesupport_introspection_c__get_const_function__Point__points(
  const void * untyped_member, size_t index)
{
  const geometry_msgs__msg__Point__Sequence * member =
    (const geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

void * FlagPoints_Request__rosidl_typesupport_introspection_c__get_function__Point__points(
  void * untyped_member, size_t index)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  return &member->data[index];
}

bool FlagPoints_Request__rosidl_typesupport_introspection_c__resize_function__Point__points(
  void * untyped_member, size_t size)
{
  geometry_msgs__msg__Point__Sequence * member =
    (geometry_msgs__msg__Point__Sequence *)(untyped_member);
  geometry_msgs__msg__Point__Sequence__fini(member);
  return geometry_msgs__msg__Point__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember FlagPoints_Request__rosidl_typesupport_introspection_c__FlagPoints_Request_message_member_array[1] = {
  {
    "points",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__srv__FlagPoints_Request, points),  // bytes offset in struct
    NULL,  // default value
    FlagPoints_Request__rosidl_typesupport_introspection_c__size_function__Point__points,  // size() function pointer
    FlagPoints_Request__rosidl_typesupport_introspection_c__get_const_function__Point__points,  // get_const(index) function pointer
    FlagPoints_Request__rosidl_typesupport_introspection_c__get_function__Point__points,  // get(index) function pointer
    FlagPoints_Request__rosidl_typesupport_introspection_c__resize_function__Point__points  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers FlagPoints_Request__rosidl_typesupport_introspection_c__FlagPoints_Request_message_members = {
  "interface__srv",  // message namespace
  "FlagPoints_Request",  // message name
  1,  // number of fields
  sizeof(interface__srv__FlagPoints_Request),
  FlagPoints_Request__rosidl_typesupport_introspection_c__FlagPoints_Request_message_member_array,  // message members
  FlagPoints_Request__rosidl_typesupport_introspection_c__FlagPoints_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  FlagPoints_Request__rosidl_typesupport_introspection_c__FlagPoints_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t FlagPoints_Request__rosidl_typesupport_introspection_c__FlagPoints_Request_message_type_support_handle = {
  0,
  &FlagPoints_Request__rosidl_typesupport_introspection_c__FlagPoints_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, FlagPoints_Request)() {
  FlagPoints_Request__rosidl_typesupport_introspection_c__FlagPoints_Request_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!FlagPoints_Request__rosidl_typesupport_introspection_c__FlagPoints_Request_message_type_support_handle.typesupport_identifier) {
    FlagPoints_Request__rosidl_typesupport_introspection_c__FlagPoints_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &FlagPoints_Request__rosidl_typesupport_introspection_c__FlagPoints_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "interface/srv/detail/flag_points__rosidl_typesupport_introspection_c.h"
// already included above
// #include "interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "interface/srv/detail/flag_points__functions.h"
// already included above
// #include "interface/srv/detail/flag_points__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void FlagPoints_Response__rosidl_typesupport_introspection_c__FlagPoints_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  interface__srv__FlagPoints_Response__init(message_memory);
}

void FlagPoints_Response__rosidl_typesupport_introspection_c__FlagPoints_Response_fini_function(void * message_memory)
{
  interface__srv__FlagPoints_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember FlagPoints_Response__rosidl_typesupport_introspection_c__FlagPoints_Response_message_member_array[1] = {
  {
    "flag",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__srv__FlagPoints_Response, flag),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers FlagPoints_Response__rosidl_typesupport_introspection_c__FlagPoints_Response_message_members = {
  "interface__srv",  // message namespace
  "FlagPoints_Response",  // message name
  1,  // number of fields
  sizeof(interface__srv__FlagPoints_Response),
  FlagPoints_Response__rosidl_typesupport_introspection_c__FlagPoints_Response_message_member_array,  // message members
  FlagPoints_Response__rosidl_typesupport_introspection_c__FlagPoints_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  FlagPoints_Response__rosidl_typesupport_introspection_c__FlagPoints_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t FlagPoints_Response__rosidl_typesupport_introspection_c__FlagPoints_Response_message_type_support_handle = {
  0,
  &FlagPoints_Response__rosidl_typesupport_introspection_c__FlagPoints_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, FlagPoints_Response)() {
  if (!FlagPoints_Response__rosidl_typesupport_introspection_c__FlagPoints_Response_message_type_support_handle.typesupport_identifier) {
    FlagPoints_Response__rosidl_typesupport_introspection_c__FlagPoints_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &FlagPoints_Response__rosidl_typesupport_introspection_c__FlagPoints_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "interface/srv/detail/flag_points__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers interface__srv__detail__flag_points__rosidl_typesupport_introspection_c__FlagPoints_service_members = {
  "interface__srv",  // service namespace
  "FlagPoints",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // interface__srv__detail__flag_points__rosidl_typesupport_introspection_c__FlagPoints_Request_message_type_support_handle,
  NULL  // response message
  // interface__srv__detail__flag_points__rosidl_typesupport_introspection_c__FlagPoints_Response_message_type_support_handle
};

static rosidl_service_type_support_t interface__srv__detail__flag_points__rosidl_typesupport_introspection_c__FlagPoints_service_type_support_handle = {
  0,
  &interface__srv__detail__flag_points__rosidl_typesupport_introspection_c__FlagPoints_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, FlagPoints_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, FlagPoints_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, FlagPoints)() {
  if (!interface__srv__detail__flag_points__rosidl_typesupport_introspection_c__FlagPoints_service_type_support_handle.typesupport_identifier) {
    interface__srv__detail__flag_points__rosidl_typesupport_introspection_c__FlagPoints_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)interface__srv__detail__flag_points__rosidl_typesupport_introspection_c__FlagPoints_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, FlagPoints_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, FlagPoints_Response)()->data;
  }

  return &interface__srv__detail__flag_points__rosidl_typesupport_introspection_c__FlagPoints_service_type_support_handle;
}
