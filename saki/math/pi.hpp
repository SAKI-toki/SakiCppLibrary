/**
* @file pi.hpp
* @brief 円周率のテンプレート変数
* @author 石山 悠
* @date 2018/10/15
*/
#ifndef SAKI_MATH_PI_HPP
#define SAKI_MATH_PI_HPP
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
	* @brief 円周率のテンプレート変数
	*/
template <typename T = double,
		  saki::enable_if_nullptr_t<std::is_arithmetic_v<T>> = nullptr>
inline constexpr auto PI =
	static_cast<T>(3.14159265358979323846);
/**
	* @brief 円周率の1/2のテンプレート変数
	*/
template <typename T = double,
		  saki::enable_if_nullptr_t<std::is_arithmetic_v<T>> = nullptr>
inline constexpr auto PI_HALF = static_cast<T>(PI<double> / 2);
/**
	* @brief 円周率の1/4のテンプレート変数
	*/
template <typename T = double,
		  saki::enable_if_nullptr_t<std::is_arithmetic_v<T>> = nullptr>
inline constexpr auto PI_QUARTER = static_cast<T>(PI<double> / 4);
SAKI_NAMESPACE_END
#endif //SAKI_MATH_PI_HPP