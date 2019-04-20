/**
* @file can_range_based_for.hpp
* @brief �͈̓x�[�Xfor���ɗ��p�ł���^���ǂ������肷�郁�^�֐�
* @author �ΎR �I
* @date 2019/01/12
*/
#ifndef SAKI_TYPE_TRAITS_CAN_RANGE_BASED_FOR_HPP
#define SAKI_TYPE_TRAITS_CAN_RANGE_BASED_FOR_HPP
#include <type_traits>
#include <utility>
#include <saki/type_traits/can_begin_method.hpp>
#include <saki/type_traits/can_end_method.hpp>
#include <saki/type_traits/enable_if_nullptr.hpp>

namespace saki
{
/**
	* @brief �͈̓x�[�Xfor���ɗ��p�ł���^���ǂ������肷��
	* @details std::begin��std::end�𗘗p�ł����true�Ƃ�������ɂȂ�
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
	* @brief can_range_based_for���ȒP�ɌĂяo����ϐ�
	*/
template <typename T>
static constexpr auto can_range_based_for_v = can_range_based_for<T>::value;
} // namespace saki
#endif //SAKI_TYPE_TRAITS_CAN_RANGE_BASED_FOR_HPP