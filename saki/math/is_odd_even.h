/**
* @file is_odd_even.h
* @brief 奇数がどうか、偶数かどうか判定する関数
* @author 石山 悠
* @date 2019/01/07
*/
#pragma once
#ifndef SAKI_IS_ODD_EVEN_2019_01_07
#define SAKI_IS_ODD_EVEN_2019_01_07
#include <limits>
#include <saki/math/fmod.h>
#include <saki/math/isinf.h>

namespace saki
{
	/**
	* @brief 奇数がどうか判定する関数
	*/
	template<typename T>
	constexpr bool is_odd(T x)
	{
		return saki::isinf(x) ||
			saki::fmod(((x > 0) ? x : -x), 2) == static_cast<T>(1);
	}
	/**
	* @brief 偶数がどうか判定する関数
	*/
	template<typename T>
	constexpr bool is_even(T x)
	{
		return x == saki::isinf(x) ||
			saki::fmod(((x > 0) ? x : -x), 2) == static_cast<T>(0);
	}
}
#endif //SAKI_IS_ODD_EVEN_2019_01_07