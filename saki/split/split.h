/**
* @file split.h
* @brief 文字列の分割
* @author 石山 悠
* @date 2018/12/23
*/
#pragma once
#ifndef SAKI_SPLIT_2018_12_23
#define SAKI_SPLIT_2018_12_23
#include <string>
#include <vector>
#include <type_traits>
#include <saki/split/details/multiple_separation.h>
#include <saki/meta/has_check_method.h>

namespace saki
{
	/**
	* @brief string型を指定された文字で区切ったものをvectorで返す
	* @param str 区切る対象の文字列
	* @param split_separation 区切りを複数選択できるクラス
	* @return 区切った文字列を格納するvectorクラス
	* @details bool check(char)の関数を持っているクラスならなんでも受け取れ、falseの間文字を格納し続けます
	*/
	template<typename T, typename std::enable_if_t<has_check_v<T>, std::nullptr_t> = nullptr>
	std::vector<std::string> split(std::string str, T&& split_separation)
	{
		//区切った文字列を追加
		std::vector<std::string> str_list;

		size_t index = 0;
		while (index < str.size())
		{
			std::string buffer = "";
			while (index < str.size() && !split_separation.check(str[index]))
			{
				buffer += str[index++];
			}
			str_list.push_back(buffer);
			++index;
		}

		return str_list;
	}

	/**
	* @brief string型を指定された文字で区切ったものをvectorで返す
	* @param str 区切る対象の文字列
	* @param first_separation 1つ目の区切り文字
	* @param t 2つ目以降の区切り文字
	* @return 区切った文字列を格納するvectorクラス
	*/
	template<typename First,typename ...T>
	std::vector<std::string> split(std::string str, First first_separation, T ...t)
	{
		//区切った文字列を追加
		std::vector<std::string> str_list;
		//複数区切り文字の生成
		MultipleSeparation separation(first_separation, t...);
		size_t index = 0;
		while (index < str.size())
		{
			std::string buffer = "";
			while (index < str.size() && !separation.check(str[index]))
			{
				buffer += str[index++];
			}
			str_list.push_back(buffer);
			++index;
		}

		return str_list;
	}
}
#endif //SAKI_SPLIT_2018_12_23