/**
* @file can_equal_equal.hpp
* @brief �w�肵���^��(==)���Z�q���g�p�ł��邩�ǂ������肷�郁�^�֐�
* @author �ΎR �I
* @date 2019/01/22
*/
#ifndef SAKI_TYPE_TRAITS_CAN_COMPARE_CAN_EQUAL_EQUAL_HPP
#define SAKI_TYPE_TRAITS_CAN_COMPARE_CAN_EQUAL_EQUAL_HPP
#include <type_traits>
#include <utility>
#include <saki/type_traits/remove_reference_const.hpp>

namespace saki
{
/**
	* @brief �C�R�[���C�R�[����r�ł��邩�ǂ����𔻒肷��\����(==)
	*/
template <typename T>
struct can_equal_equal
{
  private:
	template <typename U>
	static constexpr std::true_type equal_equal_check(
		saki::remove_reference_const_t<decltype(std::declval<U>() == std::declval<U>())> *);
	template <typename U>
	static constexpr std::false_type equal_equal_check(...);

  public:
	static constexpr auto value = decltype(equal_equal_check<T>(nullptr))::value;
};
/**
	* @brief can_equal_equal���ȒP�ɌĂяo����ϐ�
	*/
template <typename T>
static constexpr auto can_equal_equal_v = saki::can_equal_equal<T>::value;
} // namespace saki
#endif //SAKI_TYPE_TRAITS_CAN_COMPARE_CAN_EQUAL_EQUAL_HPP