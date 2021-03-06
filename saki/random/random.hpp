/**
* @file random.hpp
* @brief 決められた範囲でランダムな値を取得する
* @author 石山 悠
* @date 2018/11/26
*/
#ifndef SAKI_RANDOM_RANDOM_HPP
#define SAKI_RANDOM_RANDOM_HPP
#include <random>
#include <cassert> //for assert
#include <type_traits>
#include <saki/type_traits/enable_if_nullptr.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief 最小値と最大値を引数にとり、その間からランダムな値を返す
* @param random_min 最小値
* @param random_max 最大値
* @details 最大値を含むランダムな値を返す
*/
template <typename T,
		  saki::enable_if_nullptr_t<std::is_arithmetic_v<T>> = nullptr>
T random(const T random_min, const T random_max)
{
	assert(random_min <= random_max);
	std::random_device rd;
	std::mt19937 mt(rd());
	if constexpr (std::is_integral_v<T>)
	{
		std::uniform_int_distribution<T> rnd(random_min, random_max);
		return rnd(mt);
	}
	else
	{
		std::uniform_real_distribution<T> rnd(random_min, random_max);
		return rnd(mt);
	}
}
template <typename T1, typename T2,
		  saki::enable_if_nullptr_t<
			  std::is_arithmetic_v<T1> &&
			  std::is_arithmetic_v<T2>> = nullptr>
auto random(const T1 random_min, const T2 random_max)
{
	using type = std::common_type_t<T1, T2>;
	return random(static_cast<type>(random_min), static_cast<type>(random_max));
}
SAKI_NAMESPACE_END
#endif //SAKI_RANDOM_RANDOM_HPP