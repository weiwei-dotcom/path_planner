// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from interface:msg/MoveMotor.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "interface/msg/detail/move_motor__rosidl_typesupport_introspection_c.h"
#include "interface/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "interface/msg/detail/move_motor__functions.h"
#include "interface/msg/detail/move_motor__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void MoveMotor__rosidl_typesupport_introspection_c__MoveMotor_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  interface__msg__MoveMotor__init(message_memory);
}

void MoveMotor__rosidl_typesupport_introspection_c__MoveMotor_fini_function(void * message_memory)
{
  interface__msg__MoveMotor__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember MoveMotor__rosidl_typesupport_introspection_c__MoveMotor_message_member_array[6] = {
  {
    "motor_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__msg__MoveMotor, motor_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pos",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__msg__MoveMotor, pos),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "vel",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__msg__MoveMotor, vel),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "tor",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__msg__MoveMotor, tor),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kp",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__msg__MoveMotor, kp),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "kd",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(interface__msg__MoveMotor, kd),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers MoveMotor__rosidl_typesupport_introspection_c__MoveMotor_message_members = {
  "interface__msg",  // message namespace
  "MoveMotor",  // message name
  6,  // number of fields
  sizeof(interface__msg__MoveMotor),
  MoveMotor__rosidl_typesupport_introspection_c__MoveMotor_message_member_array,  // message members
  MoveMotor__rosidl_typesupport_introspection_c__MoveMotor_init_function,  // function to initialize message memory (memory has to be allocated)
  MoveMotor__rosidl_typesupport_introspection_c__MoveMotor_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t MoveMotor__rosidl_typesupport_introspection_c__MoveMotor_message_type_support_handle = {
  0,
  &MoveMotor__rosidl_typesupport_introspection_c__MoveMotor_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_interface
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, interface, msg, MoveMotor)() {
  if (!MoveMotor__rosidl_typesupport_introspection_c__MoveMotor_message_type_support_handle.typesupport_identifier) {
    MoveMotor__rosidl_typesupport_introspection_c__MoveMotor_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &MoveMotor__rosidl_typesupport_introspection_c__MoveMotor_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
