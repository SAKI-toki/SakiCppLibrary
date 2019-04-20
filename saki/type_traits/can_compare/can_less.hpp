/**
* @file can_less.hpp
* @brief �w�肵���^��(<)���Z�q���g�p�ł��邩�ǂ������肷�郁�^�֐�
* @author �ΎR �I
* @date 2019/01/22
*/
#ifndef SAKI_TYPE_TRAITS_CAN_COMPARE_CAN_LESS_HPP
#define SAKI_TYPE_TRAITS_CAN_COMPARE_CAN_LESS_HPP
#include <type_traits>
#include <utility>
#include <saki/type_traits/remove_reference_const.hpp>

namespace saki
{
/**
	* @brief ��菬������r�ł��邩�ǂ����𔻒肷��\����(<)
	*/
template <typename T>
struct can_less
{
  private:
	template <typename U>
	static constexpr std::true_type less_check(
		saki::remove_reference_const_t<decltype(std::declval<U>() < std::declval<U>())> *);
	template <typename U>
	static constexpr std::false_type less_check(...);

  public:
	static constexpr auto value = decltype(less_check<T>(nullptr))::value;
};
/**
	* @brief can_less���ȒP�ɌĂяo����ϐ�
	*/
template <typename T>
static constexpr auto can_less_v = saki::can_less<T>::value;
} // namespace saki
#endif //SAKI_TYPE_TRAITS_CAN_COMPARE_CAN_LESS_HPP