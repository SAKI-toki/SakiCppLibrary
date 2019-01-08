/**
* @file acosh.h
* @brief コンパイル時acosh
* @author 石山 悠
* @date 2019/01/08
*/
#pragma once
#ifndef SAKI_ACOSH_2019_01_08
#define SAKI_ACOSH_2019_01_08
#include <type_traits>
#include <limits>
#include <saki/math/isnan.h>
#include <saki/math/isinf.h>
#include <saki/math/log.h>
#include <saki/math/sqrt.h>

namespace saki
{
	/**
	* @brief コンパイル時sinh
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
		constexpr T acosh(T x)
	{
		if (saki::isnan(x) || x == std::numeric_limits<T>::infinity())return x;
		if (x < 1)return std::numeric_limits<T>::quiet_NaN();
		if (x == 1)return 0;

		return saki::log(x + saki::sqrt(x * x - 1));
	}
	/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	*/
	template<typename T,
		typename std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
		constexpr double acosh(T x)
	{
		return saki::acosh(static_cast<double>(x));
	}

	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr float acoshf(float x)
	{
		return saki::acosh(x);
	}
	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr long double acoshl(long double x)
	{
		return saki::acosh(x);
	}
}
#endif //SAKI_ACOSH_2019_01_08