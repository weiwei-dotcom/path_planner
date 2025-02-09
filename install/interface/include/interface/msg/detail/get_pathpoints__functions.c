// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interface:msg/GetPathpoints.idl
// generated code does not contain a copyright notice
#include "interface/msg/detail/get_pathpoints__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `path_points`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
interface__msg__GetPathpoints__init(interface__msg__GetPathpoints * msg)
{
  if (!msg) {
    return false;
  }
  // path_points
  if (!geometry_msgs__msg__Point__Sequence__init(&msg->path_points, 0)) {
    interface__msg__GetPathpoints__fini(msg);
    return false;
  }
  return true;
}

void
interface__msg__GetPathpoints__fini(interface__msg__GetPathpoints * msg)
{
  if (!msg) {
    return;
  }
  // path_points
  geometry_msgs__msg__Point__Sequence__fini(&msg->path_points);
}

bool
interface__msg__GetPathpoints__are_equal(const interface__msg__GetPathpoints * lhs, const interface__msg__GetPathpoints * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // path_points
  if (!geometry_msgs__msg__Point__Sequence__are_equal(
      &(lhs->path_points), &(rhs->path_points)))
  {
    return false;
  }
  return true;
}

bool
interface__msg__GetPathpoints__copy(
  const interface__msg__GetPathpoints * input,
  interface__msg__GetPathpoints * output)
{
  if (!input || !output) {
    return false;
  }
  // path_points
  if (!geometry_msgs__msg__Point__Sequence__copy(
      &(input->path_points), &(output->path_points)))
  {
    return false;
  }
  return true;
}

interface__msg__GetPathpoints *
interface__msg__GetPathpoints__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__msg__GetPathpoints * msg = (interface__msg__GetPathpoints *)allocator.allocate(sizeof(interface__msg__GetPathpoints), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interface__msg__GetPathpoints));
  bool success = interface__msg__GetPathpoints__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interface__msg__GetPathpoints__destroy(interface__msg__GetPathpoints * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interface__msg__GetPathpoints__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interface__msg__GetPathpoints__Sequence__init(interface__msg__GetPathpoints__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__msg__GetPathpoints * data = NULL;

  if (size) {
    data = (interface__msg__GetPathpoints *)allocator.zero_allocate(size, sizeof(interface__msg__GetPathpoints), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interface__msg__GetPathpoints__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interface__msg__GetPathpoints__fini(&data[i - 1]);
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
interface__msg__GetPathpoints__Sequence__fini(interface__msg__GetPathpoints__Sequence * array)
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
      interface__msg__GetPathpoints__fini(&array->data[i]);
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

interface__msg__GetPathpoints__Sequence *
interface__msg__GetPathpoints__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__msg__GetPathpoints__Sequence * array = (interface__msg__GetPathpoints__Sequence *)allocator.allocate(sizeof(interface__msg__GetPathpoints__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interface__msg__GetPathpoints__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interface__msg__GetPathpoints__Sequence__destroy(interface__msg__GetPathpoints__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interface__msg__GetPathpoints__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interface__msg__GetPathpoints__Sequence__are_equal(const interface__msg__GetPathpoints__Sequence * lhs, const interface__msg__GetPathpoints__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interface__msg__GetPathpoints__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interface__msg__GetPathpoints__Sequence__copy(
  const interface__msg__GetPathpoints__Sequence * input,
  interface__msg__GetPathpoints__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interface__msg__GetPathpoints);
    interface__msg__GetPathpoints * data =
      (interface__msg__GetPathpoints *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interface__msg__GetPathpoints__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interface__msg__GetPathpoints__fini(&data[i]);
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
    if (!interface__msg__GetPathpoints__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
