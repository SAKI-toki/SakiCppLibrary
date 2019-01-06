/**
* @file acos.h
* @brief コンパイル時acos
* @author 石山 悠
* @date 2019/01/06
*/
#pragma once
#ifndef SAKI_ACOS_2019_01_06
#define SAKI_ACOS_2019_01_06
#include <limits>
#include <type_traits>
#include <saki/math/abs.h>
#include <saki/math/isnan.h>
#include <saki/math/pi.h>
#include <saki/math/asin.h>

namespace saki
{
	/**
	* @brief コンパイル時acos
	* @param x 辺の比
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
		constexpr T acos(T x)
	{
		if (saki::isnan(x))return x;
		if (saki::abs(x) > 1)return std::numeric_limits<T>::quiet_NaN();

		return saki::PI_HALF<T> -saki::asin(x);
	}
	/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	* @param x int型の比
	*/
	template<typename T,
		typename std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
		constexpr double acos(T x)
	{
		return saki::acos(static_cast<double>(x));
	}
	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr float acosf(float x)
	{
		return saki::acos(x);
	}
	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr long double acosl(long double x)
	{
		return saki::acos(x);
	}
}
#endif //SAKI_ACOS_2019_01_06