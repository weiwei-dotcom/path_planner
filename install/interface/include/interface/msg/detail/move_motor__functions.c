// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interface:msg/MoveMotor.idl
// generated code does not contain a copyright notice
#include "interface/msg/detail/move_motor__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
interface__msg__MoveMotor__init(interface__msg__MoveMotor * msg)
{
  if (!msg) {
    return false;
  }
  // motor_id
  // pos
  // vel
  // tor
  // kp
  // kd
  return true;
}

void
interface__msg__MoveMotor__fini(interface__msg__MoveMotor * msg)
{
  if (!msg) {
    return;
  }
  // motor_id
  // pos
  // vel
  // tor
  // kp
  // kd
}

bool
interface__msg__MoveMotor__are_equal(const interface__msg__MoveMotor * lhs, const interface__msg__MoveMotor * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // motor_id
  if (lhs->motor_id != rhs->motor_id) {
    return false;
  }
  // pos
  if (lhs->pos != rhs->pos) {
    return false;
  }
  // vel
  if (lhs->vel != rhs->vel) {
    return false;
  }
  // tor
  if (lhs->tor != rhs->tor) {
    return false;
  }
  // kp
  if (lhs->kp != rhs->kp) {
    return false;
  }
  // kd
  if (lhs->kd != rhs->kd) {
    return false;
  }
  return true;
}

bool
interface__msg__MoveMotor__copy(
  const interface__msg__MoveMotor * input,
  interface__msg__MoveMotor * output)
{
  if (!input || !output) {
    return false;
  }
  // motor_id
  output->motor_id = input->motor_id;
  // pos
  output->pos = input->pos;
  // vel
  output->vel = input->vel;
  // tor
  output->tor = input->tor;
  // kp
  output->kp = input->kp;
  // kd
  output->kd = input->kd;
  return true;
}

interface__msg__MoveMotor *
interface__msg__MoveMotor__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__msg__MoveMotor * msg = (interface__msg__MoveMotor *)allocator.allocate(sizeof(interface__msg__MoveMotor), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interface__msg__MoveMotor));
  bool success = interface__msg__MoveMotor__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interface__msg__MoveMotor__destroy(interface__msg__MoveMotor * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interface__msg__MoveMotor__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interface__msg__MoveMotor__Sequence__init(interface__msg__MoveMotor__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__msg__MoveMotor * data = NULL;

  if (size) {
    data = (interface__msg__MoveMotor *)allocator.zero_allocate(size, sizeof(interface__msg__MoveMotor), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interface__msg__MoveMotor__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interface__msg__MoveMotor__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
interface__msg__MoveMotor__Sequence__fini(interface__msg__MoveMotor__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      interface__msg__MoveMotor__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

interface__msg__MoveMotor__Sequence *
interface__msg__MoveMotor__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__msg__MoveMotor__Sequence * array = (interface__msg__MoveMotor__Sequence *)allocator.allocate(sizeof(interface__msg__MoveMotor__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interface__msg__MoveMotor__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interface__msg__MoveMotor__Sequence__destroy(interface__msg__MoveMotor__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interface__msg__MoveMotor__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interface__msg__MoveMotor__Sequence__are_equal(const interface__msg__MoveMotor__Sequence * lhs, const interface__msg__MoveMotor__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interface__msg__MoveMotor__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interface__msg__MoveMotor__Sequence__copy(
  const interface__msg__MoveMotor__Sequence * input,
  interface__msg__MoveMotor__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interface__msg__MoveMotor);
    interface__msg__MoveMotor * data =
      (interface__msg__MoveMotor *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interface__msg__MoveMotor__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interface__msg__MoveMotor__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!interface__msg__MoveMotor__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
