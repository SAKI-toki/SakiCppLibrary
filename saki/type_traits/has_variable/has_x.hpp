/**
* @file has_x.hpp
* @brief �w�肵���^���ϐ�x�������Ă��邩�ǂ������肷�郁�^�֐�
* @author �ΎR �I
* @date 2018/12/29
*/
#ifndef SAKI_TYPE_TRAITS_HAS_VARIABLE_HAS_X_HPP
#define SAKI_TYPE_TRAITS_HAS_VARIABLE_HAS_X_HPP
#include <type_traits>
#include <utility>
#include <saki/type_traits/remove_reference_const.hpp>

namespace saki
{
/**
	* @brief �ϐ�x�������Ă��邩�ǂ����𔻒肷��\����
	*/
template <typename T>
struct has_x
{
  private:
	template <typename U>
	static constexpr std::true_type x_check(saki::remove_reference_const_t<decltype(std::declval<U>().x)> *);
	template <typename U>
	static constexpr std::false_type x_check(...);

  public:
	static constexpr auto value = decltype(x_check<T>(nullptr))::value;
};
/**
	* @brief has_x���ȒP�ɌĂяo����ϐ�
	*/
template <typename T>
static constexpr auto has_x_v = saki::has_x<T>::value;
} // namespace saki
#endif //SAKI_TYPE_TRAITS_HAS_VARIABLE_HAS_X_HPP