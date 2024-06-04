// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from interface:srv/ConnectFlag.idl
// generated code does not contain a copyright notice

#ifndef INTERFACE__SRV__DETAIL__CONNECT_FLAG__STRUCT_HPP_
#define INTERFACE__SRV__DETAIL__CONNECT_FLAG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__interface__srv__ConnectFlag_Request __attribute__((deprecated))
#else
# define DEPRECATED__interface__srv__ConnectFlag_Request __declspec(deprecated)
#endif

namespace interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ConnectFlag_Request_
{
  using Type = ConnectFlag_Request_<ContainerAllocator>;

  explicit ConnectFlag_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit ConnectFlag_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    interface::srv::ConnectFlag_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::srv::ConnectFlag_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::srv::ConnectFlag_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::srv::ConnectFlag_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::srv::ConnectFlag_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::srv::ConnectFlag_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::srv::ConnectFlag_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::srv::ConnectFlag_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::srv::ConnectFlag_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::srv::ConnectFlag_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__srv__ConnectFlag_Request
    std::shared_ptr<interface::srv::ConnectFlag_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__srv__ConnectFlag_Request
    std::shared_ptr<interface::srv::ConnectFlag_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConnectFlag_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConnectFlag_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConnectFlag_Request_

// alias to use template instance with default allocator
using ConnectFlag_Request =
  interface::srv::ConnectFlag_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interface


#ifndef _WIN32
# define DEPRECATED__interface__srv__ConnectFlag_Response __attribute__((deprecated))
#else
# define DEPRECATED__interface__srv__ConnectFlag_Response __declspec(deprecated)
#endif

namespace interface
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ConnectFlag_Response_
{
  using Type = ConnectFlag_Response_<ContainerAllocator>;

  explicit ConnectFlag_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flag_connected = false;
    }
  }

  explicit ConnectFlag_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->flag_connected = false;
    }
  }

  // field types and members
  using _flag_connected_type =
    bool;
  _flag_connected_type flag_connected;

  // setters for named parameter idiom
  Type & set__flag_connected(
    const bool & _arg)
  {
    this->flag_connected = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    interface::srv::ConnectFlag_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const interface::srv::ConnectFlag_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<interface::srv::ConnectFlag_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<interface::srv::ConnectFlag_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      interface::srv::ConnectFlag_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<interface::srv::ConnectFlag_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      interface::srv::ConnectFlag_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<interface::srv::ConnectFlag_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<interface::srv::ConnectFlag_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<interface::srv::ConnectFlag_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__interface__srv__ConnectFlag_Response
    std::shared_ptr<interface::srv::ConnectFlag_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__interface__srv__ConnectFlag_Response
    std::shared_ptr<interface::srv::ConnectFlag_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConnectFlag_Response_ & other) const
  {
    if (this->flag_connected != other.flag_connected) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConnectFlag_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConnectFlag_Response_

// alias to use template instance with default allocator
using ConnectFlag_Response =
  interface::srv::ConnectFlag_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace interface

namespace interface
{

namespace srv
{

struct ConnectFlag
{
  using Request = interface::srv::ConnectFlag_Request;
  using Response = interface::srv::ConnectFlag_Response;
};

}  // namespace srv

}  // namespace interface

#endif  // INTERFACE__SRV__DETAIL__CONNECT_FLAG__STRUCT_HPP_
