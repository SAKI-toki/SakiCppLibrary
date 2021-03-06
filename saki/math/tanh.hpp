/**
* @file tanh.hpp
* @brief コンパイル時tanh
* @author 石山 悠
* @date 2019/01/08
*/
#ifndef SAKI_MATH_TANH_HPP
#define SAKI_MATH_TANH_HPP
#include <type_traits>
#include <limits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/copysign.hpp>
#include <saki/math/sinh.hpp>
#include <saki/math/cosh.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief コンパイル時tanh
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T tanh(T x)
{
	if (saki::isnan(x) || x == 0)
		return x;
	if (saki::isinf(x))
		return static_cast<T>(saki::copysign(1, x));

	return saki::sinh(x) / saki::cosh(x);
}
/**
* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double tanh(T x)
{
	return saki::tanh(static_cast<double>(x));
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_TANH_HPP