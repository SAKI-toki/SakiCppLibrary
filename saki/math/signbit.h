/**
* @file signbit.h
* @brief 負数かどうか判定する関数
* @author 石山 悠
* @date 2019/01/03
*/
#pragma once
#ifndef SAKI_SIGNBIT_2019_01_03
#define SAKI_SIGNBIT_2019_01_03
#include <saki/math/copysign.h>
#include <saki/math/isnan.h>

namespace saki
{
	/**
	* @brief 負数かどうか判定する
	* @param x 判定する値
	* @return 負数かどうか
	*/
	template<typename T>
	bool signbit(T x)
	{
		return x < static_cast<T>(0);
	}
}
#endif //SAKI_SIGNBIT_2019_01_03