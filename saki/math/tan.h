/**
* @file tan.h
* @brief コンパイル時tan
* @author 石山 悠
* @date 2019/01/05
*/
#pragma once
#ifndef SAKI_TAN_2019_01_05
#define SAKI_TAN_2019_01_05
#include <type_traits>
#include <limits>
#include <saki/math/isnan.h>
#include <saki/math/sin.h>
#include <saki/math/cos.h>

namespace saki
{
	/**
	* @brief コンパイル時tan
	* @param x ラジアン角
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
		constexpr T tan(T x)
	{
		//NaN
		if (saki::isnan(x))return x;
		//inf
		if (x == std::numeric_limits<T>::infinity() ||
			x == -std::numeric_limits<T>::infinity())
		{
			return -std::numeric_limits<T>::quiet_NaN();
		}
		return saki::sin(x) / saki::cos(x);
	}

	/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	* @param x int型のラジアン角
	*/
	template<typename T,
		typename std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
		constexpr double tan(T x)
	{
		return saki::tan(static_cast<double>(x));
	}

	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr float tanf(float x)
	{
		return saki::tan(x);
	}
	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr long double tanl(long double x)
	{
		return saki::tan(x);
	}
}
#endif //SAKI_TAN_2019_01_05