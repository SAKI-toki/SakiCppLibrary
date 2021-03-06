/**
* @file logb.hpp
* @brief コンパイル時logb
* @author 石山 悠
* @date 2019/01/15
*/
#ifndef SAKI_MATH_LOGB_HPP
#define SAKI_MATH_LOGB_HPP
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>
#include <saki/math/log2.hpp>
#include <saki/math/abs.hpp>
#include <saki/math/floor.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief コンパイル時logb
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T logb(T x)
{
	return saki::floor(saki::log2(saki::abs(x)));
}
/**
* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double logb(T x)
{
	return saki::logb(static_cast<double>(x));
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_LOGB_HPP