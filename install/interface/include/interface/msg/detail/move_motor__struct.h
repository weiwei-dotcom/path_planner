// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from interface:msg/MoveMotor.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__MSG__DETAIL__MOVE_MOTOR__STRUCT_H_
#define INTERFACE__MSG__DETAIL__MOVE_MOTOR__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/MoveMotor in the package interface.
typedef struct interface__msg__MoveMotor
{
  int64_t motor_id;
  int64_t pos;
  int64_t vel;
  int64_t tor;
  int64_t kp;
  int64_t kd;
} interface__msg__MoveMotor;

// Struct for a sequence of interface__msg__MoveMotor.
typedef struct interface__msg__MoveMotor__Sequence
{
  interface__msg__MoveMotor * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} interface__msg__MoveMotor__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // INTERFACE__MSG__DETAIL__MOVE_MOTOR__STRUCT_H_
