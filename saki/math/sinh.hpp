/**
* @file sinh.hpp
* @brief �R���p�C����sinh
* @author �ΎR �I
* @date 2019/01/08
*/
#ifndef SAKI_MATH_SINH_HPP
#define SAKI_MATH_SINH_HPP
#include <cstddef>
#include <type_traits>
#include <limits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/math/factorial.hpp>
#include <saki/math/pow.hpp>
#include <saki/math/isnan.hpp>
#include <saki/math/isinf.hpp>

namespace saki
{
/**
	* @brief �R���p�C����sinh
	*/
template <typename T,
		  typename saki::enable_if_nullptr_t<std::is_floating_point_v<T>> = nullptr>
constexpr T sinh(T x)
{
	if (saki::isnan(x) || saki::isinf(x) || x == 0)
		return x;

	T sum = 0;
	size_t n = 0;
	while (2 * n + 1 <= saki::factorial_limits<T>::limit)
	{
		sum += static_cast<T>(saki::pow(x, 2 * n + 1) / saki::factorial<T>(2 * n + 1));
		++n;
	}
	return sum;
}
/**
	* @brief ������int�^�̏ꍇ�ɁA�߂�l��double�^�ɂ��邽�߂̂���
	*/
template <typename T,
		  typename saki::enable_if_nullptr_t<std::is_integral_v<T>> = nullptr>
constexpr double sinh(T x)
{
	return saki::sinh(static_cast<double>(x));
}
} // namespace saki
#endif //SAKI_MATH_SINH_HPP