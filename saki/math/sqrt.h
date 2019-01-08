/**
* @file sqrt.h
* @brief コンパイル時平方根
* @author 石山 悠
* @date 2018/11/21
*/
#pragma once
#ifndef SAKI_SQRT_2018_11_21
#define SAKI_SQRT_2018_11_21
#include <limits>
#include <type_traits>
#include <saki/math/isnan.h>
#include <saki/math/isinf.h>

namespace saki
{
	/**
	* @brief コンパイル時平方根
	* @param x 平方根を求める値
	* @details アルゴリズムはバビロニアの平方根を利用
	*/
	template<typename T,
		typename std::enable_if_t<std::is_floating_point_v<T>, std::nullptr_t> = nullptr>
	constexpr T sqrt(T x)
	{
		if (saki::isnan(x) ||
			x == std::numeric_limits<T>::infinity() ||
			x == 0)return x;
		if (x < 0)return -std::numeric_limits<T>::quiet_NaN();

		T prev = static_cast<T>(x / 2.0);
		T next = static_cast<T>((prev + x / prev) * 0.5);
		while (prev != next)
		{
			prev = next;
			next = static_cast<T>((prev + x / prev) * 0.5);
		}
		return prev;
	}
	/**
	* @brief 引数がint型の場合に、戻り値をdouble型にするためのもの
	* @param x int型のラジアン角
	*/
	template<typename T,
		typename std::enable_if_t<std::is_integral_v<T>, std::nullptr_t> = nullptr>
		constexpr double sqrt(T x)
	{
		return saki::sqrt(static_cast<double>(x));
	}

	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr float sqrtf(float x)
	{
		return saki::sqrt(x);
	}
	/**
	* @brief 標準に寄せるため実装
	*/
	constexpr long double sqrtl(long double x)
	{
		return saki::sqrt(x);
	}

	namespace details
	{
		template<int N,typename T>
		static constexpr T sqrt_v = saki::sqrt<T>(N);
	}
}
#endif //SAKI_SQRT_2018_11_21