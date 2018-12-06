/**
* @file clock.h
* @brief ���Ԃ𑪂�N���X
* @author �ΎR �I
* @date 2018/12/04
*/
#pragma once
#ifndef SAKI_CLOCK_2018_12_04
#define SAKI_CLOCK_2018_12_04
#include <saki/singleton/singleton.h>
#include <iostream>
#include <ctime>
namespace saki
{
	/**
	* @brief ���Ԃ𑪂�N���X
	*/
	class saki_clock :public saki::singleton<saki_clock>
	{
		clock_t start_time;//�J�n����
	public:
		/**
		* @brief �R���X�g���N�^
		*/
		saki_clock() :start_time(0) {}
		/**
		* @brief �J�n���Ԃ̃Z�b�g
		*/
		void start()
		{
			start_time = clock();
		}
		/**
		* @brief �J�n���Ԃ��Z�b�g���Ă���̎��Ԃ�Ԃ�
		* @param ms true�Ȃ�~���b,false�Ȃ�b�ŕԂ�
		* return ����
		*/
		template<typename T = double>
		T end(bool ms = true)
		{
			clock_t end_time = clock();
			return static_cast<T>(static_cast<double>(end_time - start_time) / ((ms) ? 1 : (CLOCKS_PER_SEC)));
		}
		/**
		* @brief �J�n���Ԃ��Z�b�g���Ă���̎��Ԃ�Ԃ��A��������܂����Ԃ��X�^�[�g����
		* @param ms true�Ȃ�~���b,false�Ȃ�b�ŕԂ�
		* return ����
		*/
		template<typename T = double>
		T end_and_start(bool ms = true)
		{
			auto end_time = end<T>(ms);
			start();
			return end_time;
		}
	};
}
#endif //SAKI_CLOCK_2018_12_04