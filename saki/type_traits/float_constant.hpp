/**
* @file float_constant.hpp
* @brief 浮動小数点型の定数を表す型
* @author 石山 悠
* @date 2019/01/15
*/
#ifndef SAKI_TYPE_TRAITS_FLOAT_CONSTANT_HPP
#define SAKI_TYPE_TRAITS_FLOAT_CONSTANT_HPP
#include <cstddef>
#include <saki/math/digit_count.hpp>
#include <saki/math/details/pow_n.hpp>
#include <saki/math/copysign.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
namespace details
{
/**
* @brief 浮動小数点型の定数を表すベースクラス
*/
template <typename T, int Integer, size_t Dec, size_t ZeroNum = 0>
struct float_constant_base
{
	static constexpr T value = Integer +
							   saki::copysign(static_cast<T>(Dec) /
												  saki::details::pow_n(static_cast<T>(10),
																	   ZeroNum + saki::digit_count(Dec)),
											  Integer);
	constexpr operator T() const
	{
		return value;
	}
	constexpr T operator()() const
	{
		return value;
	}
};
} // namespace details
/**
* @brief 浮動小数点型の定数を表す
*/
template <int Integer, size_t Dec, size_t ZeroNum = 0>
struct float_constant : public saki::details::float_constant_base<float, Integer, Dec, ZeroNum>
{
};
/**
* @brief float_constantを簡単に呼び出せる変数
*/
template <int Integer, size_t Dec, size_t ZeroNum = 0>
inline constexpr float float_constant_v = saki::float_constant<Integer, Dec, ZeroNum>::value;

/**
* @brief 倍精度浮動小数点型の定数を表す
*/
template <int Integer, size_t Dec, size_t ZeroNum = 0>
struct double_constant : public saki::details::float_constant_base<double, Integer, Dec, ZeroNum>
{
};
/**
* @brief double_constantを簡単に呼び出せる変数
*/
template <int Integer, size_t Dec, size_t ZeroNum = 0>
inline constexpr double double_constant_v = saki::double_constant<Integer, Dec, ZeroNum>::value;
SAKI_NAMESPACE_END
#endif //SAKI_TYPE_TRAITS_FLOAT_CONSTANT_HPP