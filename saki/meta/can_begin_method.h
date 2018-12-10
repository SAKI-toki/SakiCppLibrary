/**
* @file can_begin_method.h
* @brief 指定した型がstd::beginできるかどうか判定するメタ関数
* @author 石山 悠
* @date 2018/12/09
*/
#pragma once
#ifndef SAKI_CAN_BEGIN_METHOD_2018_12_09
#define SAKI_CAN_BEGIN_METHOD_2018_12_09
#include <type_traits>
#include <xutility>

namespace saki
{
	struct CanBegin
	{
		template<typename T>
		static constexpr auto value = decltype(begin_check(std::declval<T>()))::value;
	private:
		template<typename T>
		static constexpr auto begin_check(T t)
			->decltype(std::begin(t), std::true_type());
		static constexpr std::false_type begin_check(...);
	};
}
#endif //SAKI_CAN_BEGIN_METHOD_2018_12_09