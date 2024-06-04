// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from interface:srv/ConnectFlag.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "interface/srv/detail/connect_flag__rosidl_typesupport_introspection_c.h"
#include "interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "interface/srv/detail/connect_flag__functions.h"
#include "interface/srv/detail/connect_flag__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ConnectFlag_Request__rosidl_typesupport_introspection_c__ConnectFlag_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  interface__srv__ConnectFlag_Request__init(message_memory);
}

void ConnectFlag_Request__rosidl_typesupport_introspection_c__ConnectFlag_Request_fini_function(void * message_memory)
{
  interface__srv__ConnectFlag_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ConnectFlag_Request__rosidl_typesupport_introspection_c__ConnectFlag_Request_message_member_array[1] = {
  {
    "structure_needs_at_least_one_member",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__srv__ConnectFlag_Request, structure_needs_at_least_one_member),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ConnectFlag_Request__rosidl_typesupport_introspection_c__ConnectFlag_Request_message_members = {
  "interface__srv",  // message namespace
  "ConnectFlag_Request",  // message name
  1,  // number of fields
  sizeof(interface__srv__ConnectFlag_Request),
  ConnectFlag_Request__rosidl_typesupport_introspection_c__ConnectFlag_Request_message_member_array,  // message members
  ConnectFlag_Request__rosidl_typesupport_introspection_c__ConnectFlag_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ConnectFlag_Request__rosidl_typesupport_introspection_c__ConnectFlag_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ConnectFlag_Request__rosidl_typesupport_introspection_c__ConnectFlag_Request_message_type_support_handle = {
  0,
  &ConnectFlag_Request__rosidl_typesupport_introspection_c__ConnectFlag_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, ConnectFlag_Request)() {
  if (!ConnectFlag_Request__rosidl_typesupport_introspection_c__ConnectFlag_Request_message_type_support_handle.typesupport_identifier) {
    ConnectFlag_Request__rosidl_typesupport_introspection_c__ConnectFlag_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ConnectFlag_Request__rosidl_typesupport_introspection_c__ConnectFlag_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "interface/srv/detail/connect_flag__rosidl_typesupport_introspection_c.h"
// already included above
// #include "interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "interface/srv/detail/connect_flag__functions.h"
// already included above
// #include "interface/srv/detail/connect_flag__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ConnectFlag_Response__rosidl_typesupport_introspection_c__ConnectFlag_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  interface__srv__ConnectFlag_Response__init(message_memory);
}

void ConnectFlag_Response__rosidl_typesupport_introspection_c__ConnectFlag_Response_fini_function(void * message_memory)
{
  interface__srv__ConnectFlag_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ConnectFlag_Response__rosidl_typesupport_introspection_c__ConnectFlag_Response_message_member_array[1] = {
  {
    "flag_connected",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__srv__ConnectFlag_Response, flag_connected),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ConnectFlag_Response__rosidl_typesupport_introspection_c__ConnectFlag_Response_message_members = {
  "interface__srv",  // message namespace
  "ConnectFlag_Response",  // message name
  1,  // number of fields
  sizeof(interface__srv__ConnectFlag_Response),
  ConnectFlag_Response__rosidl_typesupport_introspection_c__ConnectFlag_Response_message_member_array,  // message members
  ConnectFlag_Response__rosidl_typesupport_introspection_c__ConnectFlag_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ConnectFlag_Response__rosidl_typesupport_introspection_c__ConnectFlag_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ConnectFlag_Response__rosidl_typesupport_introspection_c__ConnectFlag_Response_message_type_support_handle = {
  0,
  &ConnectFlag_Response__rosidl_typesupport_introspection_c__ConnectFlag_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, ConnectFlag_Response)() {
  if (!ConnectFlag_Response__rosidl_typesupport_introspection_c__ConnectFlag_Response_message_type_support_handle.typesupport_identifier) {
    ConnectFlag_Response__rosidl_typesupport_introspection_c__ConnectFlag_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ConnectFlag_Response__rosidl_typesupport_introspection_c__ConnectFlag_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "interface/srv/detail/connect_flag__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers interface__srv__detail__connect_flag__rosidl_typesupport_introspection_c__ConnectFlag_service_members = {
  "interface__srv",  // service namespace
  "ConnectFlag",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // interface__srv__detail__connect_flag__rosidl_typesupport_introspection_c__ConnectFlag_Request_message_type_support_handle,
  NULL  // response message
  // interface__srv__detail__connect_flag__rosidl_typesupport_introspection_c__ConnectFlag_Response_message_type_support_handle
};

static rosidl_service_type_support_t interface__srv__detail__connect_flag__rosidl_typesupport_introspection_c__ConnectFlag_service_type_support_handle = {
  0,
  &interface__srv__detail__connect_flag__rosidl_typesupport_introspection_c__ConnectFlag_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, ConnectFlag_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, ConnectFlag_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interface
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, ConnectFlag)() {
  if (!interface__srv__detail__connect_flag__rosidl_typesupport_introspection_c__ConnectFlag_service_type_support_handle.typesupport_identifier) {
    interface__srv__detail__connect_flag__rosidl_typesupport_introspection_c__ConnectFlag_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)interface__srv__detail__connect_flag__rosidl_typesupport_introspection_c__ConnectFlag_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, ConnectFlag_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, srv, ConnectFlag_Response)()->data;
  }

  return &interface__srv__detail__connect_flag__rosidl_typesupport_introspection_c__ConnectFlag_service_type_support_handle;
}
