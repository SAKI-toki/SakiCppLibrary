/**
* @file atan2.h
* @brief コンパイル時atan2
* @author 石山 悠
* @date 2019/01/06
*/
#pragma once
#ifndef SAKI_ATAN2_2019_01_06
#define SAKI_ATAN2_2019_01_06
#include <limits>
#include <type_traits>
#include <saki/math/isnan.h>
#include <saki/math/signbit.h>
#include <saki/math/copysign.h>
#include <saki/math/atan.h>
#include <saki/math/pi.h>

namespace saki
{
	/**
	* @brief コンパイル時atan2
	* @param y,x 辺の長さ
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
		constexpr T atan2(T y, T x)
	{
		if (saki::isnan(x))
		{
			if (saki::isnan(y))
			{
				return saki::signbit(x) && saki::signbit(y) ?
					-std::numeric_limits<T>::quiet_NaN() :
					std::numeric_limits<T>::quiet_NaN();
			}
		}
		if (saki::isnan(y))return static_cast<T>(y);
		if (y == 0)
		{
			return (x < 0) ? saki::PI<T> : 0;
		}
		if (x == 0)
		{
			return saki::copysign(saki::PI_HALF<T>, y);
		}
		if (y == std::numeric_limits<T>::infinity() ||
			y == -std::numeric_limits<T>::infinity())
		{
			return (x == std::numeric_limits<T>::infinity()) ?
				saki::copysign(saki::PI_QUARTER<T>, y) :
				(x == -std::numeric_limits<T>::infinity()) ?
				saki::copysign(saki::PI_QUARTER<T> * 3, y) :
				saki::copysign(saki::PI_HALF<T>, y);
		}
		if (x == std::numeric_limits<T>::infinity())
		{
			return saki::copysign<T>(0, y);
		}
		if (x == -std::numeric_limits<T>::infinity())
		{
			return saki::copysign(saki::PI<T>, y);
		}

		//0<x
		if (0 < x)
		{
			return saki::atan(y / x);
		}
		//x<0,0<y
		else if (0 < y)
		{
			return saki::atan(y / x) + saki::PI<T>;
		}
		//x<0,y<0
		else
		{
			return saki::atan(y / x) - saki::PI<T>;
		}
	}
	/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	*/
	template<typename T,
		typename std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
		constexpr double atan2(T y, T x)
	{
		return saki::atan2(static_cast<double>(y), static_cast<double>(x));
	}
	/**
	* @brief 型をそろえる
	*/
	template<typename T1, typename T2,
		typename std::enable_if_t<std::is_arithmetic_v<T1>, std::nullptr_t> = nullptr,
		typename std::enable_if_t<std::is_arithmetic_v<T2>, std::nullptr_t> = nullptr>
		constexpr auto atan2(T1 y, T2 x)
	{
		using type = decltype(std::declval<T1>()*std::declval<T2>());
		return atan2(static_cast<type>(y), static_cast<type>(x));
	}
	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr float atan2f(float y, float x)
	{
		return saki::atan2(y, x);
	}
	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr long double atan2l(long double y, long double x)
	{
		return saki::atan2(y, x);
	}
}
#endif //SAKI_ATAN2_2019_01_06