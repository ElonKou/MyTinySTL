#ifndef MYTINYSTL_TYPE_TRAITS_H_
#define MYTINYSTL_TYPE_TRAITS_H_

// 这个头文件用于提取类型信息

// use standard header for type_traits
#include <type_traits>

namespace mystl
{

// helper struct

// 封装基础的数值类型
template <class T, T v>
struct m_integral_constant
{
  static constexpr T value = v;
};

// 特化一个布尔类型
template <bool b>
using m_bool_constant = m_integral_constant<bool, b>;

// 特化布尔类型
typedef m_bool_constant<true>  m_true_type;
typedef m_bool_constant<false> m_false_type;

/*****************************************************************************************/
// type traits

// is_pair

// --- forward declaration begin
template <class T1, class T2>
struct pair;
// --- forward declaration end

template <class T>
struct is_pair : mystl::m_false_type {};

template <class T1, class T2>
struct is_pair<mystl::pair<T1, T2>> : mystl::m_true_type {};
// 实现pair的判断，如果两个参数，自然为true，如果是一个参数，就是false

} // namespace mystl

#endif // !MYTINYSTL_TYPE_TRAITS_H_

