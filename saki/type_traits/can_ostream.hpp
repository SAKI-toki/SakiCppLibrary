/**
* @file can_ostream.hpp
* @brief 指定した型がostream演算子をオーバーロードしているかどうか判定する(正確にはcout)
* @author 石山 悠
* @date 2019/01/22
*/
#ifndef SAKI_TYPE_TRAITS_CAN_OSTREAM_HPP
#define SAKI_TYPE_TRAITS_CAN_OSTREAM_HPP
#include <type_traits>
#include <utility>
#include <iostream>
#include <saki/type_traits/remove_reference_const.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief ostream演算子をオーバーロードしているかどうか判定する構造体(cout)
*/
template <typename T>
struct can_ostream
{
private:
	template <typename U>
	static constexpr std::true_type ostream_check(
		saki::remove_reference_const_t<decltype(std::cout << (std::declval<U>()))> *u);
	template <typename U>
	static constexpr std::false_type ostream_check(...);

public:
	static constexpr auto value = decltype(ostream_check<T>(nullptr))::value;
};
/**
* @brief can_ostreamを簡単に呼び出せる変数
*/
template <typename T>
inline constexpr auto can_ostream_v = saki::can_ostream<T>::value;
SAKI_NAMESPACE_END
#endif //SAKI_TYPE_TRAITS_CAN_OSTREAM_HPP