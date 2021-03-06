/**
* @file reverse_iterator_operator.hpp
* @brief reverse_iteratorNXΜZq
* @author ΞR I
* @date 2019/01/09
*/
#ifndef SAKI_ITERATOR_REVERSE_DETAILS_REVERSE_ITERATOR_OPERATOR_HPP
#define SAKI_ITERATOR_REVERSE_DETAILS_REVERSE_ITERATOR_OPERATOR_HPP
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
namespace details
{
//vg^CvιΎ
template <typename T>
class reverse_iterator_base;
/**
* @brief ==Zq
*/
template <typename T>
constexpr bool operator==(const reverse_iterator_base<T> &itr1, const reverse_iterator_base<T> &itr2)
{
	return itr1.itr == itr2.itr;
}
/**
* @brief !=Zq
*/
template <typename T>
constexpr bool operator!=(const reverse_iterator_base<T> &itr1, const reverse_iterator_base<T> &itr2)
{
	return !(itr1 == itr2);
}
} // namespace details
SAKI_NAMESPACE_END
#endif //SAKI_ITERATOR_REVERSE_DETAILS_REVERSE_ITERATOR_OPERATOR_HPP