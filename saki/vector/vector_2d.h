/**
* @file vector_2d.h
* @brief 2次元でのベクトル
* @author 石山 悠
* @date 2018/12/06
*/
#pragma once
#ifndef SAKI_VECTOR_2D_2018_12_06
#define SAKI_VECTOR_2D_2018_12_06
#include <type_traits> //for meta method
#include <limits> //for numeric_limits
#include <saki/constexpr/constexpr_sqrt.h> //for constexpr_sqrt

namespace saki
{
	/**
	* @brief 2次元でのベクトル
	*/
	template<typename T>
	class Vector2
	{
	public:
		T x, y;
		/**
		* @brief 引数なしコンストラクタ
		* @details 全て0で初期化
		*/
		constexpr Vector2() :
			x(static_cast<T>(0)), y(static_cast<T>(0))
		{}
		/**
		* @brief 引数ありコンストラクタ
		* @param _x xの初期値
		* @param _y yの初期値
		*/
		constexpr Vector2(const T& _x, const T& _y) :
			x(_x), y(_y)
		{}
		/**
		* @brief 生配列からの初期化
		* @param pointer 配列のポインタ
		*/
		constexpr Vector2(const T* const pointer) :
			x(*pointer), y(*(pointer + 1))
		{}
		//デフォルトを使用
		//デフォルトではメンバ変数のコピー、ムーブを行う
		Vector2(const Vector2<T>&) = default;
		Vector2<T>& operator=(const Vector2<T>&) = default;
		Vector2(Vector2<T>&&)noexcept = default;
		Vector2& operator=(Vector2<T>&&)noexcept = default;
		/**
		* @brief +=演算子
		*/
		template<typename U = T>
		auto operator+=(const Vector2<U>& other)
		{
			*this = *this + other;
			return *this;
		}
		/**
		* @brief -=演算子
		*/
		template<typename U = T>
		auto operator-=(const Vector2<U>& other)
		{
			*this = *this - other;
			return *this;
		}
		/**
		* @brief *=演算子(スカラ)
		*/
		template<typename U = T>
		auto operator*=(const U& scalar)
		{
			*this = *this * scalar;
			return *this;
		}
		/**
		* @brief *=演算子(ベクトル)
		*/
		template<typename U = T>
		auto operator*=(const Vector2<U>& other)
		{
			*this = *this * other;
			return *this;
		}
		/**
		* @brief /=演算子(スカラ)
		*/
		template<typename U = T>
		auto operator/=(const U& scalar)
		{
			*this = *this / scalar;
			return *this;
		}
		/**
		* @brief /=演算子(ベクトル)
		*/
		template<typename U = T>
		auto operator/=(const Vector2<U>& other)
		{
			*this = *this / other;
			return *this;
		}
		/**
		* @brief 単項+演算子
		*/
		constexpr Vector2<T> operator+()const
		{
			return *this;
		}
		/**
		* @brief 単項-演算子
		*/
		constexpr Vector2<T> operator-()const
		{
			return Vector2<T>(this->x * (-1), this->y * (-1));
		}
		/**
		* @brief []演算子
		*/
		T& operator[](const unsigned int index)
		{
			return (index == 0) ? this->x : this->y;
		}
		/**
		* @brief []演算子(constexpr)
		*/
		constexpr T operator[](const unsigned int index)const
		{
			return (index == 0) ? this->x : this->y;
		}
		/**
		* @brief ++演算子(前置)
		*/
		Vector2<T>& operator++()
		{
			this->x += 1; this->y += 1;
			return *this;
		}
		/**
		* @brief ++演算子(後置)
		*/
		Vector2<T> operator++(int)
		{
			Vector2<T> temp = *this;
			this->x += 1; this->y += 1;
			return temp;
		}
		/**
		* @brief --演算子(前置)
		*/
		Vector2<T>& operator--()
		{
			this->x -= 1; this->y -= 1;
			return *this;
		}
		/**
		* @brief --演算子(後置)
		*/
		Vector2<T> operator--(int)
		{
			Vector2<T> temp = *this;
			this->x -= 1; this->y -= 1;
			return temp;
		}
		/**
		* @brief 正規化
		* @details int型の場合、すべての要素が0で帰ります
		*/
		void normalize()
		{
			//分母
			auto den = saki::sqrt(this->x * this->x + this->y * this->y);
			if (den == 0)
			{
				this->x = 0;
				this->y = 0;
			}
			else
			{
				this->x /= den;
				this->y /= den;
			}
		}
		/**
		* @brief 正規化
		* @return 正規化したもの
		* @details thisは正規化しない、int型の場合、すべての要素が0で返ります
		*/
		template<typename U = double>
		constexpr Vector2<U> return_normalize()const
		{
			//分母
			auto den = saki::sqrt(this->x * this->x + this->y * this->y);
			if (den == 0)
			{
				return Vector2<U>
					(static_cast<U>(0),//x
						static_cast<U>(0));//y
			}
			else
			{
				return Vector2<U>
					(static_cast<U>(this->x / den),//x
						static_cast<U>(this->y / den));//y
			}
		}
	};

	/**
	* @brief Vector2のオールゼロ
	*/
	template<typename T>
	static constexpr Vector2<T> vector2_zero{ static_cast<T>(0), static_cast<T>(0) };
	/**
	* @brief Vector2のオールワン
	*/
	template<typename T>
	static constexpr Vector2<T> vector2_one{ static_cast<T>(1), static_cast<T>(1) };
	/**
	* @brief Vector2の最小値
	*/
	template<typename T>
	static constexpr Vector2<T> vector2_min{ std::numeric_limits<T>::min(), std::numeric_limits<T>::min() };
	/**
	* @brief Vector2の最大値
	*/
	template<typename T>
	static constexpr Vector2<T> vector2_max{ std::numeric_limits<T>::max(), std::numeric_limits<T>::max() };

	/**
	* @brief 内積
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr U dot(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return static_cast<U>(v1.x*v2.x + v1.y*v2.y);
	}
	/**
	* @brief 外積
	*/
	template<typename U = double, typename T1, typename T2>
	constexpr U cross(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return static_cast<U>(v1.x * v2.y - v1.y * v2.x);
	}

	/**
	* @brief 線形補間
	*/
	template<typename U = double, typename T1, typename T2, typename T = double>
	constexpr Vector2<U> lerp(const Vector2<T1>& v1, const Vector2<T2>& v2, const T& t, const T& base = 1)
	{
		return Vector2<U>(
			v1.x + (v2.x - v1.x) * t / base,
			v1.y + (v2.y - v1.y) * t / base);
	}

	/**
	* @brief +演算子
	*/
	template<typename T1, typename T2>
	constexpr auto operator+(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return Vector2<decltype(std::declval<T1>() + std::declval<T2>())>
		{ v1.x + v2.x, v1.y + v2.y };
	}
	/**
	* @brief -演算子
	*/
	template<typename T1, typename T2>
	constexpr auto operator-(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return Vector2<decltype(std::declval<T1>() - std::declval<T2>())>
		{ v1.x - v2.x, v1.y - v2.y };
	}
	/**
	* @brief *演算子(スカラ)
	*/
	template<typename T1, typename T2>
	constexpr auto operator*(const Vector2<T1>& v, const T2& scalar)
	{
		return Vector2<decltype(std::declval<T1>() * std::declval<T2>())>
		{ v.x * scalar, v.y * scalar };
	}
	/**
	* @brief *演算子(ベクトル)
	*/
	template<typename T1, typename T2>
	constexpr auto operator*(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return Vector2<decltype(std::declval<T1>() * std::declval<T2>())>
		{ v1.x * v2.x, v1.y * v2.y};
	}
	/**
	* @brief /演算子(スカラ)
	*/
	template<typename T1, typename T2>
	constexpr auto operator/(const Vector2<T1>& v, const T2& scalar)
	{
		return Vector2<decltype(std::declval<T1>() * std::declval<T2>())>
		{ v.x / scalar, v.y / scalar };
	}
	/**
	* @brief /演算子(ベクトル)
	*/
	template<typename T1, typename T2>
	constexpr auto operator/(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return Vector2<decltype(std::declval<T1>() * std::declval<T2>())>
		{ v1.x / v2.x, v1.y / v2.y};
	}
	/**
	* @brief ==演算子
	*/
	template<typename T>
	constexpr bool operator==(const Vector2<T>& v1, const Vector2<T>& v2)
	{
		return v1.x == v2.x && v1.y == v2.y;
	}
	/**
	* @brief !=演算子
	*/
	template<typename T>
	constexpr bool operator!=(const Vector2<T>& v1, const Vector2<T>& v2)
	{
		return !(v1 == v2);
	}
	/**
	* @brief ==演算子(型不一致)
	* @details この関数の使用は推奨しない
	*/
	template<typename T1, typename T2>[[deprecated("type_mismatch")]]
		constexpr bool operator==(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return v1.x == v2.x && v1.y == v2.y;
	}
	/**
	* @brief !=演算子(型不一致)
	* @details この関数の使用は推奨しない
	*/
	template<typename T1, typename T2>[[deprecated("type_mismatch")]]
		constexpr bool operator!=(const Vector2<T1>& v1, const Vector2<T2>& v2)
	{
		return !(v1 == v2);
	}
}
#endif //SAKI_VECTOR_2D_2018_12_06