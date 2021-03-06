/**
* @file iterator.hpp
* @brief コンパイル時iterator
* @author 石山 悠
* @date 2019/01/09
*/
#ifndef SAKI_ITERATOR_ITERATOR_HPP
#define SAKI_ITERATOR_ITERATOR_HPP
#include <saki/macro/type_macro.hpp>
#include <saki/iterator/details/iterator_base.hpp>
#include <saki/macro/namespace_macro.hpp>

SAKI_NAMESPACE_BEGIN
/**
* @brief ノーマルなイテレーター
*/
template <typename T>
class iterator : public saki::details::iterator_base<T>
{
public:
	explicit constexpr iterator(T *pointer) : saki::details::iterator_base<T>(pointer) {}
};
/**
* @brief constなイテレーター
*/
template <typename T>
class const_iterator : public saki::details::iterator_base<const T>
{
public:
	explicit constexpr const_iterator(const T *pointer) : saki::details::iterator_base<const T>(pointer) {}
};
SAKI_NAMESPACE_END
#endif //SAKI_ITERATOR_ITERATOR_HPP