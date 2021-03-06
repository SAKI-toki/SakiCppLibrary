/**
* @file can_range_based_for.hpp
* @brief 範囲ベースfor文に利用できる型がどうか判定するメタ関数
* @author 石山 悠
* @date 2019/01/12
*/
#ifndef SAKI_TYPE_TRAITS_CAN_RANGE_BASED_FOR_HPP
#define SAKI_TYPE_TRAITS_CAN_RANGE_BASED_FOR_HPP
#include <type_traits>
#include <utility>
#include <saki/type_traits/can_begin_method.hpp>
#include <saki/type_traits/can_end_method.hpp>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief 範囲ベースfor文に利用できる型かどうか判定する
* @details std::beginとstd::endを利用できればtrueという判定になる
*/
template <typename T>
class can_range_based_for
{
	template <typename U,
			  typename saki::enable_if_nullptr_t<saki::can_begin_v<U> && saki::can_end_v<U>> = nullptr>
	static constexpr std::true_type check_range_based_for(std::nullptr_t *u);
	template <typename U>
	static constexpr std::false_type check_range_based_for(...);

public:
	static constexpr auto value = decltype(check_range_based_for<T>(nullptr))::value;
};
/**
* @brief can_range_based_forを簡単に呼び出せる変数
*/
template <typename T>
inline constexpr auto can_range_based_for_v = can_range_based_for<T>::value;
SAKI_NAMESPACE_END
#endif //SAKI_TYPE_TRAITS_CAN_RANGE_BASED_FOR_HPP