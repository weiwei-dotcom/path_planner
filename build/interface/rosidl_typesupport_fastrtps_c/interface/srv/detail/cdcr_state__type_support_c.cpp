// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from interface:srv/CdcrState.idl
// generated code does not contain a copyright notice
#include "interface/srv/detail/cdcr_state__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "interface/srv/detail/cdcr_state__struct.h"
#include "interface/srv/detail/cdcr_state__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "geometry_msgs/msg/detail/pose__functions.h"  // base_pose_now
#include "rosidl_runtime_c/primitives_sequence.h"  // alpha_now, theta_now
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // alpha_now, theta_now

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_interface
size_t get_serialized_size_geometry_msgs__msg__Pose(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_interface
size_t max_serialized_size_geometry_msgs__msg__Pose(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose)();


using _CdcrState_Request__ros_msg_type = interface__srv__CdcrState_Request;

static bool _CdcrState_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CdcrState_Request__ros_msg_type * ros_message = static_cast<const _CdcrState_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: alpha_now
  {
    size_t size = ros_message->alpha_now.size;
    auto array_ptr = ros_message->alpha_now.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: theta_now
  {
    size_t size = ros_message->theta_now.size;
    auto array_ptr = ros_message->theta_now.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: base_pose_now
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->base_pose_now, cdr))
    {
      return false;
    }
  }

  return true;
}

static bool _CdcrState_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CdcrState_Request__ros_msg_type * ros_message = static_cast<_CdcrState_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: alpha_now
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->alpha_now.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->alpha_now);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->alpha_now, size)) {
      return "failed to create array for field 'alpha_now'";
    }
    auto array_ptr = ros_message->alpha_now.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: theta_now
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->theta_now.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->theta_now);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->theta_now, size)) {
      return "failed to create array for field 'theta_now'";
    }
    auto array_ptr = ros_message->theta_now.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: base_pose_now
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->base_pose_now))
    {
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interface
size_t get_serialized_size_interface__srv__CdcrState_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CdcrState_Request__ros_msg_type * ros_message = static_cast<const _CdcrState_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name alpha_now
  {
    size_t array_size = ros_message->alpha_now.size;
    auto array_ptr = ros_message->alpha_now.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name theta_now
  {
    size_t array_size = ros_message->theta_now.size;
    auto array_ptr = ros_message->theta_now.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name base_pose_now

  current_alignment += get_serialized_size_geometry_msgs__msg__Pose(
    &(ros_message->base_pose_now), current_alignment);

  return current_alignment - initial_alignment;
}

static uint32_t _CdcrState_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_interface__srv__CdcrState_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interface
size_t max_serialized_size_interface__srv__CdcrState_Request(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: alpha_now
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: theta_now
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: base_pose_now
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Pose(
        full_bounded, current_alignment);
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _CdcrState_Request__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_interface__srv__CdcrState_Request(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_CdcrState_Request = {
  "interface::srv",
  "CdcrState_Request",
  _CdcrState_Request__cdr_serialize,
  _CdcrState_Request__cdr_deserialize,
  _CdcrState_Request__get_serialized_size,
  _CdcrState_Request__max_serialized_size
};

static rosidl_message_type_support_t _CdcrState_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CdcrState_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interface, srv, CdcrState_Request)() {
  return &_CdcrState_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "interface/srv/detail/cdcr_state__struct.h"
// already included above
// #include "interface/srv/detail/cdcr_state__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

// already included above
// #include "geometry_msgs/msg/detail/pose__functions.h"  // base_pose_tar
// already included above
// #include "rosidl_runtime_c/primitives_sequence.h"  // alpha_tar, theta_tar
// already included above
// #include "rosidl_runtime_c/primitives_sequence_functions.h"  // alpha_tar, theta_tar

// forward declare type support functions
ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_interface
size_t get_serialized_size_geometry_msgs__msg__Pose(
  const void * untyped_ros_message,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_interface
size_t max_serialized_size_geometry_msgs__msg__Pose(
  bool & full_bounded,
  size_t current_alignment);

ROSIDL_TYPESUPPORT_FASTRTPS_C_IMPORT_interface
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose)();


using _CdcrState_Response__ros_msg_type = interface__srv__CdcrState_Response;

static bool _CdcrState_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _CdcrState_Response__ros_msg_type * ros_message = static_cast<const _CdcrState_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: alpha_tar
  {
    size_t size = ros_message->alpha_tar.size;
    auto array_ptr = ros_message->alpha_tar.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: theta_tar
  {
    size_t size = ros_message->theta_tar.size;
    auto array_ptr = ros_message->theta_tar.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: base_pose_tar
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_serialize(
        &ros_message->base_pose_tar, cdr))
    {
      return false;
    }
  }

  // Field name: success
  {
    cdr << (ros_message->success ? true : false);
  }

  return true;
}

static bool _CdcrState_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _CdcrState_Response__ros_msg_type * ros_message = static_cast<_CdcrState_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: alpha_tar
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->alpha_tar.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->alpha_tar);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->alpha_tar, size)) {
      return "failed to create array for field 'alpha_tar'";
    }
    auto array_ptr = ros_message->alpha_tar.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: theta_tar
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->theta_tar.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->theta_tar);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->theta_tar, size)) {
      return "failed to create array for field 'theta_tar'";
    }
    auto array_ptr = ros_message->theta_tar.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: base_pose_tar
  {
    const message_type_support_callbacks_t * callbacks =
      static_cast<const message_type_support_callbacks_t *>(
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(
        rosidl_typesupport_fastrtps_c, geometry_msgs, msg, Pose
      )()->data);
    if (!callbacks->cdr_deserialize(
        cdr, &ros_message->base_pose_tar))
    {
      return false;
    }
  }

  // Field name: success
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->success = tmp ? true : false;
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interface
size_t get_serialized_size_interface__srv__CdcrState_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _CdcrState_Response__ros_msg_type * ros_message = static_cast<const _CdcrState_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name alpha_tar
  {
    size_t array_size = ros_message->alpha_tar.size;
    auto array_ptr = ros_message->alpha_tar.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name theta_tar
  {
    size_t array_size = ros_message->theta_tar.size;
    auto array_ptr = ros_message->theta_tar.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name base_pose_tar

  current_alignment += get_serialized_size_geometry_msgs__msg__Pose(
    &(ros_message->base_pose_tar), current_alignment);
  // field.name success
  {
    size_t item_size = sizeof(ros_message->success);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _CdcrState_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_interface__srv__CdcrState_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_interface
size_t max_serialized_size_interface__srv__CdcrState_Response(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: alpha_tar
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: theta_tar
  {
    size_t array_size = 0;
    full_bounded = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: base_pose_tar
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        max_serialized_size_geometry_msgs__msg__Pose(
        full_bounded, current_alignment);
    }
  }
  // member: success
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static size_t _CdcrState_Response__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_interface__srv__CdcrState_Response(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_CdcrState_Response = {
  "interface::srv",
  "CdcrState_Response",
  _CdcrState_Response__cdr_serialize,
  _CdcrState_Response__cdr_deserialize,
  _CdcrState_Response__get_serialized_size,
  _CdcrState_Response__max_serialized_size
};

static rosidl_message_type_support_t _CdcrState_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_CdcrState_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interface, srv, CdcrState_Response)() {
  return &_CdcrState_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "interface/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "interface/srv/cdcr_state.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t CdcrState__callbacks = {
  "interface::srv",
  "CdcrState",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interface, srv, CdcrState_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interface, srv, CdcrState_Response)(),
};

static rosidl_service_type_support_t CdcrState__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &CdcrState__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, interface, srv, CdcrState)() {
  return &CdcrState__handle;
}

#if defined(__cplusplus)
}
#endif
