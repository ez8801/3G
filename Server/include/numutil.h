/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


�� ���α׷��� ���۱��� ���ټǿ��� �ֽ��ϴ�.
�� ���α׷��� ����, ���, ������ ���õ� ������ �� ���α׷��� �������ڿ��� ����� ������,
����� �ؼ����� �ʴ� ��� ��Ģ������ ���� ����� �����մϴ�.
���� ��뿡 ���� å���� �� ���α׷��� �������ڿ��� ��༭�� ��õǾ� �ֽ��ϴ�.

** ���� : ���۹��� ���� ���� ��ø� �������� ���ʽÿ�.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


���������??Nettention�������
?����������ǡ����ġ�?����?����?���������������?���??��
������???��?�������������ġ�
���������?��٥���?��������?�������?�졣

** ��������?�����ڪ��߾��٥�ơ�


���Ϋ׫���������?��Nettention�˪���ު���
���Ϋ׫��������ᡢ���ġ����֪�?������������׫��������?�Ȫ���峪�?����
��峪��������ʪ����ꡢ����ܪ���?���Ī��ת��ު���
��?���Ī˪���������׫��������?�Ȫ��������٥�ƪ���ƪ��ު���

** �������ڪ��?����߾����٥�ƪ���۪��ʪ��Ǫ���������

*/

#pragma once

#include "BasicTypes.h"
#include "quicksort.h"
#include "pnstdint.h" 

#if defined(_WIN32)
    #include <algorithm>
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	�� �� v1,v2�� v1->v2���� ���а� ratio�� ���Ѵ�.
	ratio�� 0�� �������� v1�� ������. 

	\~english
	Obtains a interior division ratio of two values of v1,v2, v1->v2.
	As ratio gets closer to 0, it gets closer to v1.

	\~chinese
	ϴ��???v1��v2��v1->v2��??ratio��
	Ration ������0��?������v1.

	\~japanese
	?��v1��v2��v1->v2�ت�?����ratio��ϴ��ު���
	ratio��0���ΪŪ��۪�v1���Ϊ��Ǫ���
	\~
	*/
	template<typename T>
	inline T Lerp(T v1, T v2, T ratio)
	{
		return v1 + (v2 - v1)*ratio;
	}


	/**
	\~korean
 	Lerp�� ������ ����. ratio�� ���ڴ� ratio1,�и�� ratio2

	\~english TODO:translate needed.
	Integer version of Lerp. Numerator of the ratio is ratio 1. Denominator is ratio 2. 

	\~chinese
	Lerp ����?�����⡣Ratio �������ratio1����ٽ��ratio2.

	\~japanese
	Lerp����?����?�����Ratio������ratio1����ٽ��ratio2
	\~
	*/
	template<typename T>
	inline T LerpInt(T v1, T v2,T ratio1, T ratio2)
	{
		return (v1 + ((v2 - v1)*ratio1)/ratio2);
	}

	/** 
	\~korean
	Round robin ���� ���� ������.

	\~english
	Round robin slot number generator 

	\~chinese
	Round robin ?�ˣ�slot��?�������

	\~japanese
	Round robin ����ë�?������
	\~
	*/
	class CRoundRobinNumberGenerator
	{
		int m_number;
	public:
		PROUD_API CRoundRobinNumberGenerator();

		PROUD_API int Next(int maxNumber);
	};
	/**  @} */

	// ��ó: http://www.java2s.com/Tutorial/Cpp/0260__template/Genericquicksort.htm

// 	template<typename T>
// 	inline void swap(T& v1,T& v2)
// 	{
// 		T temp=v2;
// 		v2=v1;
// 		v1=temp;
// 	}

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
