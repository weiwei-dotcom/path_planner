// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from interface:srv/CdcrState.idl
// generated code does not contain a copyright notice
#include "interface/srv/detail/cdcr_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `alpha_now`
// Member `theta_now`
#include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `base_pose_now`
#include "geometry_msgs/msg/detail/pose__functions.h"

bool
interface__srv__CdcrState_Request__init(interface__srv__CdcrState_Request * msg)
{
  if (!msg) {
    return false;
  }
  // alpha_now
  if (!rosidl_runtime_c__double__Sequence__init(&msg->alpha_now, 0)) {
    interface__srv__CdcrState_Request__fini(msg);
    return false;
  }
  // theta_now
  if (!rosidl_runtime_c__double__Sequence__init(&msg->theta_now, 0)) {
    interface__srv__CdcrState_Request__fini(msg);
    return false;
  }
  // base_pose_now
  if (!geometry_msgs__msg__Pose__init(&msg->base_pose_now)) {
    interface__srv__CdcrState_Request__fini(msg);
    return false;
  }
  return true;
}

void
interface__srv__CdcrState_Request__fini(interface__srv__CdcrState_Request * msg)
{
  if (!msg) {
    return;
  }
  // alpha_now
  rosidl_runtime_c__double__Sequence__fini(&msg->alpha_now);
  // theta_now
  rosidl_runtime_c__double__Sequence__fini(&msg->theta_now);
  // base_pose_now
  geometry_msgs__msg__Pose__fini(&msg->base_pose_now);
}

bool
interface__srv__CdcrState_Request__are_equal(const interface__srv__CdcrState_Request * lhs, const interface__srv__CdcrState_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // alpha_now
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->alpha_now), &(rhs->alpha_now)))
  {
    return false;
  }
  // theta_now
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->theta_now), &(rhs->theta_now)))
  {
    return false;
  }
  // base_pose_now
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->base_pose_now), &(rhs->base_pose_now)))
  {
    return false;
  }
  return true;
}

bool
interface__srv__CdcrState_Request__copy(
  const interface__srv__CdcrState_Request * input,
  interface__srv__CdcrState_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // alpha_now
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->alpha_now), &(output->alpha_now)))
  {
    return false;
  }
  // theta_now
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->theta_now), &(output->theta_now)))
  {
    return false;
  }
  // base_pose_now
  if (!geometry_msgs__msg__Pose__copy(
      &(input->base_pose_now), &(output->base_pose_now)))
  {
    return false;
  }
  return true;
}

interface__srv__CdcrState_Request *
interface__srv__CdcrState_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__srv__CdcrState_Request * msg = (interface__srv__CdcrState_Request *)allocator.allocate(sizeof(interface__srv__CdcrState_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interface__srv__CdcrState_Request));
  bool success = interface__srv__CdcrState_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interface__srv__CdcrState_Request__destroy(interface__srv__CdcrState_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interface__srv__CdcrState_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interface__srv__CdcrState_Request__Sequence__init(interface__srv__CdcrState_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__srv__CdcrState_Request * data = NULL;

  if (size) {
    data = (interface__srv__CdcrState_Request *)allocator.zero_allocate(size, sizeof(interface__srv__CdcrState_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interface__srv__CdcrState_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interface__srv__CdcrState_Request__fini(&data[i - 1]);
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
interface__srv__CdcrState_Request__Sequence__fini(interface__srv__CdcrState_Request__Sequence * array)
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
      interface__srv__CdcrState_Request__fini(&array->data[i]);
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

interface__srv__CdcrState_Request__Sequence *
interface__srv__CdcrState_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__srv__CdcrState_Request__Sequence * array = (interface__srv__CdcrState_Request__Sequence *)allocator.allocate(sizeof(interface__srv__CdcrState_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interface__srv__CdcrState_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interface__srv__CdcrState_Request__Sequence__destroy(interface__srv__CdcrState_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interface__srv__CdcrState_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interface__srv__CdcrState_Request__Sequence__are_equal(const interface__srv__CdcrState_Request__Sequence * lhs, const interface__srv__CdcrState_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interface__srv__CdcrState_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interface__srv__CdcrState_Request__Sequence__copy(
  const interface__srv__CdcrState_Request__Sequence * input,
  interface__srv__CdcrState_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interface__srv__CdcrState_Request);
    interface__srv__CdcrState_Request * data =
      (interface__srv__CdcrState_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interface__srv__CdcrState_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interface__srv__CdcrState_Request__fini(&data[i]);
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
    if (!interface__srv__CdcrState_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `alpha_tar`
// Member `theta_tar`
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"
// Member `base_pose_tar`
// already included above
// #include "geometry_msgs/msg/detail/pose__functions.h"

bool
interface__srv__CdcrState_Response__init(interface__srv__CdcrState_Response * msg)
{
  if (!msg) {
    return false;
  }
  // alpha_tar
  if (!rosidl_runtime_c__double__Sequence__init(&msg->alpha_tar, 0)) {
    interface__srv__CdcrState_Response__fini(msg);
    return false;
  }
  // theta_tar
  if (!rosidl_runtime_c__double__Sequence__init(&msg->theta_tar, 0)) {
    interface__srv__CdcrState_Response__fini(msg);
    return false;
  }
  // base_pose_tar
  if (!geometry_msgs__msg__Pose__init(&msg->base_pose_tar)) {
    interface__srv__CdcrState_Response__fini(msg);
    return false;
  }
  // success
  return true;
}

void
interface__srv__CdcrState_Response__fini(interface__srv__CdcrState_Response * msg)
{
  if (!msg) {
    return;
  }
  // alpha_tar
  rosidl_runtime_c__double__Sequence__fini(&msg->alpha_tar);
  // theta_tar
  rosidl_runtime_c__double__Sequence__fini(&msg->theta_tar);
  // base_pose_tar
  geometry_msgs__msg__Pose__fini(&msg->base_pose_tar);
  // success
}

bool
interface__srv__CdcrState_Response__are_equal(const interface__srv__CdcrState_Response * lhs, const interface__srv__CdcrState_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // alpha_tar
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->alpha_tar), &(rhs->alpha_tar)))
  {
    return false;
  }
  // theta_tar
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->theta_tar), &(rhs->theta_tar)))
  {
    return false;
  }
  // base_pose_tar
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->base_pose_tar), &(rhs->base_pose_tar)))
  {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  return true;
}

bool
interface__srv__CdcrState_Response__copy(
  const interface__srv__CdcrState_Response * input,
  interface__srv__CdcrState_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // alpha_tar
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->alpha_tar), &(output->alpha_tar)))
  {
    return false;
  }
  // theta_tar
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->theta_tar), &(output->theta_tar)))
  {
    return false;
  }
  // base_pose_tar
  if (!geometry_msgs__msg__Pose__copy(
      &(input->base_pose_tar), &(output->base_pose_tar)))
  {
    return false;
  }
  // success
  output->success = input->success;
  return true;
}

interface__srv__CdcrState_Response *
interface__srv__CdcrState_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__srv__CdcrState_Response * msg = (interface__srv__CdcrState_Response *)allocator.allocate(sizeof(interface__srv__CdcrState_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(interface__srv__CdcrState_Response));
  bool success = interface__srv__CdcrState_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
interface__srv__CdcrState_Response__destroy(interface__srv__CdcrState_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    interface__srv__CdcrState_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
interface__srv__CdcrState_Response__Sequence__init(interface__srv__CdcrState_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__srv__CdcrState_Response * data = NULL;

  if (size) {
    data = (interface__srv__CdcrState_Response *)allocator.zero_allocate(size, sizeof(interface__srv__CdcrState_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = interface__srv__CdcrState_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        interface__srv__CdcrState_Response__fini(&data[i - 1]);
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
interface__srv__CdcrState_Response__Sequence__fini(interface__srv__CdcrState_Response__Sequence * array)
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
      interface__srv__CdcrState_Response__fini(&array->data[i]);
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

interface__srv__CdcrState_Response__Sequence *
interface__srv__CdcrState_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  interface__srv__CdcrState_Response__Sequence * array = (interface__srv__CdcrState_Response__Sequence *)allocator.allocate(sizeof(interface__srv__CdcrState_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = interface__srv__CdcrState_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
interface__srv__CdcrState_Response__Sequence__destroy(interface__srv__CdcrState_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    interface__srv__CdcrState_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
interface__srv__CdcrState_Response__Sequence__are_equal(const interface__srv__CdcrState_Response__Sequence * lhs, const interface__srv__CdcrState_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!interface__srv__CdcrState_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
interface__srv__CdcrState_Response__Sequence__copy(
  const interface__srv__CdcrState_Response__Sequence * input,
  interface__srv__CdcrState_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(interface__srv__CdcrState_Response);
    interface__srv__CdcrState_Response * data =
      (interface__srv__CdcrState_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!interface__srv__CdcrState_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          interface__srv__CdcrState_Response__fini(&data[i]);
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
    if (!interface__srv__CdcrState_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
