/**
* @file atan.hpp
* @brief コンパイル時atan
* @author 石山 悠
* @date 2019/01/06
*/
#ifndef SAKI_MATH_ATAN_HPP
#define SAKI_MATH_ATAN_HPP
#include <limits>
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/abs.hpp>
#include <saki/math/sqrt.hpp>
#include <saki/math/pow.hpp>
#include <saki/math/pi.hpp>
#include <saki/math/isnan.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief コンパイル時atan
* @param x 辺の比
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T atan(T x)
{
	if (saki::isnan(x) || x == 0)
		return x;
	if (x == std::numeric_limits<T>::infinity())
		return saki::PI_HALF<T>;
	if (x == -std::numeric_limits<T>::infinity())
		return -saki::PI_HALF<T>;

	//|x|≦√2-1
	if (saki::abs(x) <= (saki::sqrt<T>(2) - 1))
	{
		T sum = 0;
		T _sum = -1;
		int n = 0;
		while (!saki::isnan(sum) && sum != _sum)
		{
			_sum = sum;
			sum += static_cast<T>(((n % 2 == 0) ? 1 : -1) *
								  saki::pow(x, 2 * n + 1) /
								  (2 * n + 1));
			++n;
		}
		return sum;
	}
	//√2+1<|x|
	else if (saki::abs(x) > (saki::sqrt<T>(2) + 1))
	{
		return (x > 0) ? (saki::PI_HALF<T> - saki::atan(1 / x)) : -(saki::PI_HALF<T> - saki::atan(1 / -x));
	}
	//√2-1<|x|≦√2+1
	else
	{
		return (x > 0) ? (saki::PI_QUARTER<T> + saki::atan((x - 1) / (x + 1))) : -(saki::PI_QUARTER<T> + saki::atan((-x - 1) / (-x + 1)));
	}
}
/**
* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
* @param x int型の比
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double atan(T x)
{
	return saki::atan(static_cast<double>(x));
}
SAKI_NAMESPACE_END
#endif //SAKI_MATH_ATAN_HPP