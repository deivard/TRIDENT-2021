// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from turtlesim:srv/Spawn.idl
// generated code does not contain a copyright notice

#ifndef TURTLESIM__SRV__DETAIL__SPAWN__TRAITS_HPP_
#define TURTLESIM__SRV__DETAIL__SPAWN__TRAITS_HPP_

#include "turtlesim/srv/detail/spawn__struct.hpp"
#include <stdint.h>
#include <rosidl_runtime_cpp/traits.hpp>
#include <sstream>
#include <string>
#include <type_traits>

namespace turtlesim
{

namespace srv
{

inline void to_flow_style_yaml(
  const Spawn_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: x
  {
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << ", ";
  }

  // member: y
  {
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << ", ";
  }

  // member: theta
  {
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << ", ";
  }

  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Spawn_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "x: ";
    rosidl_generator_traits::value_to_yaml(msg.x, out);
    out << "\n";
  }

  // member: y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "y: ";
    rosidl_generator_traits::value_to_yaml(msg.y, out);
    out << "\n";
  }

  // member: theta
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "theta: ";
    rosidl_generator_traits::value_to_yaml(msg.theta, out);
    out << "\n";
  }

  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Spawn_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace turtlesim

namespace rosidl_generator_traits
{

[[deprecated("use turtlesim::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtlesim::srv::Spawn_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtlesim::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtlesim::srv::to_yaml() instead")]]
inline std::string to_yaml(const turtlesim::srv::Spawn_Request & msg)
{
  return turtlesim::srv::to_yaml(msg);
}

template<>
inline const char * data_type<turtlesim::srv::Spawn_Request>()
{
  return "turtlesim::srv::Spawn_Request";
}

template<>
inline const char * name<turtlesim::srv::Spawn_Request>()
{
  return "turtlesim/srv/Spawn_Request";
}

template<>
struct has_fixed_size<turtlesim::srv::Spawn_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<turtlesim::srv::Spawn_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<turtlesim::srv::Spawn_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace turtlesim
{

namespace srv
{

inline void to_flow_style_yaml(
  const Spawn_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: name
  {
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Spawn_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "name: ";
    rosidl_generator_traits::value_to_yaml(msg.name, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Spawn_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace turtlesim

namespace rosidl_generator_traits
{

[[deprecated("use turtlesim::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const turtlesim::srv::Spawn_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  turtlesim::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use turtlesim::srv::to_yaml() instead")]]
inline std::string to_yaml(const turtlesim::srv::Spawn_Response & msg)
{
  return turtlesim::srv::to_yaml(msg);
}

template<>
inline const char * data_type<turtlesim::srv::Spawn_Response>()
{
  return "turtlesim::srv::Spawn_Response";
}

template<>
inline const char * name<turtlesim::srv::Spawn_Response>()
{
  return "turtlesim/srv/Spawn_Response";
}

template<>
struct has_fixed_size<turtlesim::srv::Spawn_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<turtlesim::srv::Spawn_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<turtlesim::srv::Spawn_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<turtlesim::srv::Spawn>()
{
  return "turtlesim::srv::Spawn";
}

template<>
inline const char * name<turtlesim::srv::Spawn>()
{
  return "turtlesim/srv/Spawn";
}

template<>
struct has_fixed_size<turtlesim::srv::Spawn>
  : std::integral_constant<
    bool,
    has_fixed_size<turtlesim::srv::Spawn_Request>::value &&
    has_fixed_size<turtlesim::srv::Spawn_Response>::value
  >
{
};

template<>
struct has_bounded_size<turtlesim::srv::Spawn>
  : std::integral_constant<
    bool,
    has_bounded_size<turtlesim::srv::Spawn_Request>::value &&
    has_bounded_size<turtlesim::srv::Spawn_Response>::value
  >
{
};

template<>
struct is_service<turtlesim::srv::Spawn>
  : std::true_type
{
};

template<>
struct is_service_request<turtlesim::srv::Spawn_Request>
  : std::true_type
{
};

template<>
struct is_service_response<turtlesim::srv::Spawn_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // TURTLESIM__SRV__DETAIL__SPAWN__TRAITS_HPP_
