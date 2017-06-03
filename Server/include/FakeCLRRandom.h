/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


�� ���α׷��� ���۱��� ���ټǿ��� �ֽ��ϴ�.
�� ���α׷��� ����, ���, ������ ���õ� ������ �� ���α׷��� �������ڿ��� ����� ������,
����� �ؼ����� �ʴ� ��� ��Ģ������ ���� ����� �����մϴ�.
���� ��뿡 ���� å���� �� ���α׷��� �������ڿ��� ��༭�� ���õǾ� �ֽ��ϴ�.

** ���� : ���۹��� ���� ���� ���ø� �������� ���ʽÿ�.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


���������??Nettention�������
?����������ǡ����ġ�?����?����?���������������?����??��
������???��?��������������ġ�
����������?��٥���?��������?��������?�졣

** ��������?�����ڪ��߾��٥�ơ�


���Ϋ׫�����������?��Nettention�˪���ު���
���Ϋ׫����������ᡢ���ġ����֪�?������������׫����������?���Ȫ���峪�?����
��峪��������ʪ����ꡢ����ܪ���?���Ī��ת��ު���
��?���Ī˪���������׫����������?���Ȫ��������٥�ƪ���ƪ��ު���

** �������ڪ��?����߾����٥�ƪ���۪��ʪ��Ǫ���������

*/

#pragma once

#include "BasicTypes.h"
#include "Random.h"
#include "FakeClr.h"
#include "pnguid.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/
	class Random
	{
		CRandom m_rand;
	public:
		Random()
		{
			m_rand.InitializeSeed();
		}

		/** 
		\~korean
		0~1 ���� ���� �ε��Ҽ��� ���� �����մϴ�.

		\~english
		Create random floating point value between 0 to 1

		\~chinese
		����0~1��??��ݩ�ã�floating point��?��

		\~japanese
		0~1�����??�����?�������������ު���
		\~
		*/
		PROUD_API double NextDouble();

		/** 
		\~korean
		�������� �����մϴ�.
		������ �������� 0���� maxVal���� �� �ϳ��Դϴ�.

		\~english
		Create random number.
		Created random number will be one of between 0 to maxVal.

		\~chinese
		����?��?��
		������?��?��0��maxVal��?����?��

		\~japanese
		??�����������ު���
		�������쪿??����0����maxVal�ުǪ������ĪǪ���
		\~
		*/
		PROUD_API int Next(int maxVal);

		/** 
		\~korean
		GUID �������� �����մϴ�.

		\~english
		Create GUID random number.

		\~chinese
		����GUID?��?��

		\~japanese
		GUID??�����������ު���
		\~
		*/
		PROUD_API Guid NextGuid();
	};
	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif