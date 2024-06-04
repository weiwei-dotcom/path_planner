// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from interface:srv/CdcrState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "interface/srv/detail/cdcr_state__rosidl_typesupport_introspection_c.h"
#include "interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "interface/srv/detail/cdcr_state__functions.h"
#include "interface/srv/detail/cdcr_state__struct.h"


// Include directives for member types
// Member `alpha_now`
// Member `theta_now`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `base_pose_now`
#include "geometry_msgs/msg/pose.h"
// Member `base_pose_now`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void CdcrState_Request__rosidl_typesupport_introspection_c__CdcrState_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  interface__srv__CdcrState_Request__init(message_memory);
}

void CdcrState_Request__rosidl_typesupport_introspection_c__CdcrState_Request_fini_function(void * message_memory)
{
  interface__srv__CdcrState_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember CdcrState_Request__rosidl_typesupport_introspection_c__CdcrState_Request_message_member_array[3] = {
  {
    "alpha_now",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__srv__CdcrState_Request, alpha_now),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "theta_now",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__srv__CdcrState_Request, theta_now),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "base_pose_now",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__srv__CdcrState_Request, base_pose_now),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers CdcrState_Request__rosidl_typesupport_introspection_c__CdcrState_Request_message_members = {
  "interface__srv",  // message namespace
  "CdcrState_Request",  // message name
  3,  // number of fields
  sizeof(interface__srv__CdcrState_Request),
  CdcrState_Request__rosidl_typesupport_introspection_c__CdcrState_Request_message_member_array,  // message members
  CdcrState_Request__rosidl_typesupport_introspection_c__CdcrState_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  CdcrState_Request__rosidl_typesupport_introspection_c__CdcrState_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t CdcrState_Request__rosidl_typesupport_introspection_c__CdcrState_Request_message_type_support_handle = {
  0,
  &CdcrState_Request__rosidl_typesupport_introspection_c__CdcrState_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, CdcrState_Request)() {
  CdcrState_Request__rosidl_typesupport_introspection_c__CdcrState_Request_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!CdcrState_Request__rosidl_typesupport_introspection_c__CdcrState_Request_message_type_support_handle.typesupport_identifier) {
    CdcrState_Request__rosidl_typesupport_introspection_c__CdcrState_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &CdcrState_Request__rosidl_typesupport_introspection_c__CdcrState_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "interface/srv/detail/cdcr_state__rosidl_typesupport_introspection_c.h"
// already included above
// #include "interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "interface/srv/detail/cdcr_state__functions.h"
// already included above
// #include "interface/srv/detail/cdcr_state__struct.h"


// Include directives for member types
// Member `alpha_tar`
// Member `theta_tar`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `base_pose_tar`
// already included above
// #include "geometry_msgs/msg/pose.h"
// Member `base_pose_tar`
// already included above
// #include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void CdcrState_Response__rosidl_typesupport_introspection_c__CdcrState_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  interface__srv__CdcrState_Response__init(message_memory);
}

void CdcrState_Response__rosidl_typesupport_introspection_c__CdcrState_Response_fini_function(void * message_memory)
{
  interface__srv__CdcrState_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember CdcrState_Response__rosidl_typesupport_introspection_c__CdcrState_Response_message_member_array[4] = {
  {
    "alpha_tar",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__srv__CdcrState_Response, alpha_tar),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "theta_tar",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__srv__CdcrState_Response, theta_tar),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "base_pose_tar",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__srv__CdcrState_Response, base_pose_tar),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__srv__CdcrState_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers CdcrState_Response__rosidl_typesupport_introspection_c__CdcrState_Response_message_members = {
  "interface__srv",  // message namespace
  "CdcrState_Response",  // message name
  4,  // number of fields
  sizeof(interface__srv__CdcrState_Response),
  CdcrState_Response__rosidl_typesupport_introspection_c__CdcrState_Response_message_member_array,  // message members
  CdcrState_Response__rosidl_typesupport_introspection_c__CdcrState_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  CdcrState_Response__rosidl_typesupport_introspection_c__CdcrState_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t CdcrState_Response__rosidl_typesupport_introspection_c__CdcrState_Response_message_type_support_handle = {
  0,
  &CdcrState_Response__rosidl_typesupport_introspection_c__CdcrState_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, CdcrState_Response)() {
  CdcrState_Response__rosidl_typesupport_introspection_c__CdcrState_Response_message_member_array[2].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  if (!CdcrState_Response__rosidl_typesupport_introspection_c__CdcrState_Response_message_type_support_handle.typesupport_identifier) {
    CdcrState_Response__rosidl_typesupport_introspection_c__CdcrState_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &CdcrState_Response__rosidl_typesupport_introspection_c__CdcrState_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "interface/srv/detail/cdcr_state__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers interface__srv__detail__cdcr_state__rosidl_typesupport_introspection_c__CdcrState_service_members = {
  "interface__srv",  // service namespace
  "CdcrState",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // interface__srv__detail__cdcr_state__rosidl_typesupport_introspection_c__CdcrState_Request_message_type_support_handle,
  NULL  // response message
  // interface__srv__detail__cdcr_state__rosidl_typesupport_introspection_c__CdcrState_Response_message_type_support_handle
};

static rosidl_service_type_support_t interface__srv__detail__cdcr_state__rosidl_typesupport_introspection_c__CdcrState_service_type_support_handle = {
  0,
  &interface__srv__detail__cdcr_state__rosidl_typesupport_introspection_c__CdcrState_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, CdcrState_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, CdcrState_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, CdcrState)() {
  if (!interface__srv__detail__cdcr_state__rosidl_typesupport_introspection_c__CdcrState_service_type_support_handle.typesupport_identifier) {
    interface__srv__detail__cdcr_state__rosidl_typesupport_introspection_c__CdcrState_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)interface__srv__detail__cdcr_state__rosidl_typesupport_introspection_c__CdcrState_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, CdcrState_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, CdcrState_Response)()->data;
  }

  return &interface__srv__detail__cdcr_state__rosidl_typesupport_introspection_c__CdcrState_service_type_support_handle;
}
