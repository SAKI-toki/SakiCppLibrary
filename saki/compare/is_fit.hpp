/**
* @file is_fit.hpp
* @brief 範囲内かどうかの判定を行う
* @author 石山 悠
* @date 2019/01/21
*/
#ifndef SAKI_COMPARE_IS_FIT_HPP
#define SAKI_COMPARE_IS_FIT_HPP
#include <type_traits>
#include <saki/type_traits/can_compare/can_less_or_equal.hpp>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief 範囲内かどうかの判定を行う
* @details if(a <= x && x <= b)をis_fit(x,a,b)と書ける
*/
template <typename T,
		  saki::enable_if_nullptr_t<
			  saki::can_less_or_equal_v<T> //<=演算子が有効かどうか
			  > = nullptr>
constexpr bool is_fit(const T &x, const T &min_n, const T &max_n)
{
	return (min_n <= x && x <= max_n);
}
/**
* @brief 型をそろえる
*/
template <typename First, typename MinType, typename MaxType,
		  saki::enable_if_nullptr_t<
			  std::is_convertible_v<MinType, First> && //MinTypeからFirstに変換可能か
			  std::is_convertible_v<MaxType, First> && //MaxTypeからFirstに変換可能か
			  saki::can_less_or_equal_v<First>		   //<=演算子が有効かどうか
			  > = nullptr>
constexpr bool is_fit(First x, MinType min_n, MaxType max_n)
{
	return is_fit(x, static_cast<First>(min_n), static_cast<First>(max_n));
}
SAKI_NAMESPACE_END
#endif //SAKI_COMPARE_IS_FIT_HPP