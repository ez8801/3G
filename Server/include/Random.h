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
#include "FastArray.h"
#include "FastArrayPtr.h"
#include "CriticalSect.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	������ ������

	Ư¡
	- seed�� ������ ���������� �����ϴ�.

	�Ϲ��� �뵵
	- CRandom ��ü�� ������ �� InitializeSeed()�� SetSeed() ���� 1ȸ �� GetInt(), GetInt64, GetFloat ���� ���� �ȴ�.
	- ����� ���� ������ �䱸���� ������ �׳� StaticGet*()�� ����϶�.
	- ����� ���� ������ �ʿ�� �ϸ� �� ��ü�� ���� InitializeSeed()�� ���� �ѹ��� ȣ���� ��
	Get*()�� ����϶�. 

	\~english
	Random value generator

	Characteristics
	- If seeds are same then the randome values are same.

	General usage
	- After creating CRandom object,use GetInt(), GetInt64, GetFloat and so on after calling InitializeSeed() or SetSeed() once for the first time.
	- If explicit random distribution is not required then just use StaticGet*().
	- If explicit random distribution is required then create this object, call InitializeSeed() once for the first time then use Get*().

	\~chinese
	?��?������

	����
	- seed������??��?���ҡ�

	��������Բ
	- ���� CRandom%?�����InitializeSeed()���SetSeed()����1���������GetInt(), GetInt64, GetFloat��?ʦ��
	- ���ϴ??��?��������?������StaticGet*()?��
	- ���??��?��������??���?�����������У���InitializeSeed()�����Get*()?��

	\~japanese
	���������������?��?

	��?
	- seed���Ҫ��Ǫ���Ы����������Ҫ��Ǫ���

	�����ܪ���Բ
	- CRandom ���֫������Ȫ�������������InitializeSeed()�Ȫ�SetSeed()������1������GetInt(), GetInt64, GetFloat �ʪɪ��Ūêƪ���������
	- ٥���ܫ��������֪��ϴ���ʪ���Ъ��� StaticGet*()���Ūêƪ���������
	- ٥���ܫ��������֪���驪Ȫ���Ъ��Ϋ��֫������Ȫ��ªê�InitializeSeed()������1�ުΪ������󪷪�����Get*()���Ūêƪ��������� 
	\~
	*/
	class CRandom
	{
	private:
		uint32_t m_dwState[625];
		uint32_t *m_pdwNext;
		int m_lLeft;
	
		uint32_t LoadMersenneTwister();
		double GetFloat_INTERNAL();
		static double StaticGetFloat_INTERNAL();

		CriticalSection m_cs;
	public:
		PROUD_API CRandom();
		PROUD_API virtual ~CRandom();

		/** 
		\~korean
		�������� seed ���� �����մϴ�. 

		\~english
		Set random number creating seed value

		\~chinese
		?��??����seed?��

		\~japanese
		??����seed�������Ҫ��ު���
		\~
		*/
		PROUD_API void InitializeSeed();

		/** 
		\~korean
		�������� seed ���� Ư�� ������ �����մϴ�. 
		\param dwSeed �õ尪

		\~english TODO:translate needed.
		Set random number creating seed value to specific value.

		\~chinese
		?��??����seed??����?��
		\param dwSeed seed?

		\~japanese
		??����seed���������������Ҫ��ު���
		\param dwSeed ��?����
		\~
		*/
		PROUD_API void SetSeed(uint32_t dwSeed);

		/** 
		\~korean
		�������� �����. INT_MIN~INT_MAX �� �ϳ��̴�. 

		\~english
		Creates random value. One value between INT_MIN~INT_MAX

		\~chinese
		����?��?��INT_MIN~INT_MAX �����顣

		\~japanese
		�����������ª�ު���INT_MIN~INT_MAX����ĪǪ��� 
		\~
		*/
		PROUD_API int GetInt();

		/** 
		\~korean
		�������� �����. INT64_MIN~INT64_MAX �� �ϳ��̴�.

		\~english
		Creates random value. One value between INT64_MIN~INT64_MAX

		\~chinese
		����?��?��INT64_MIN~INT64_MAX �����顣

		\~japanese
		�����������ª�ު���INT64_MIN~INT64_MAX����ĪǪ���
		\~
		*/
		PROUD_API int64_t GetInt64();

		/** 
		\~korean
		���� ��ü�� ������� CRandom ���κ��� ���� ���Ѵ�. thread safe�ϴ�.

		\~english
		Gets value from CRandom that created with global object. It does thread safe.

		\~chinese
		����?�������� CRandom%��ϴ?����thread safe�ܡ�

		\~japanese
		��洫��֫������Ȫ��ª�쪿CRandom�������ϴ��ު���thread safe�Ǫ���
		\~
		*/
		PROUD_API static int StaticGetInt();

		/** 
		\~korean
		���� ��ü�� ������� CRandom ���κ��� ���� ���Ѵ�. thread safe�ϴ�. 

		\~english
		Gets value from CRandom that created with global object. It does thread safe.

		\~chinese
		����?�������� CRandom%��ϴ?����thread safe�ܡ�

		\~japanese
		��洫��֫������Ȫ��ª�쪿CRandom�������ϴ��ު���thread safe�Ǫ���
		\~
		*/
		PROUD_API static int64_t StaticGetInt64();

		/** 
		\~korean
		���� ��ü�� ������� CRandom ���κ��� ���� ���Ѵ�. 0~1 ������ �ε��Ҽ��� ���̴�. thread safe�ϴ�. 

		\~english
		Gets value from CRandom that created with global object. It is floating point value between 0 to 1. It does thread safe.

		\~chinese
		����?�������� CRandom%��ϴ?��0~1��?��ݩ��?����thread safe�ܡ�

		\~japanese
		��洫��֫������Ȫ��ª�쪿CRandom�������ϴ��ު���0~1����������?�����Ǫ���thread safe�Ǫ���
		\~
		*/
		PROUD_API double GetFloat();
		
		/** 
		\~korean
		���� ��ü�� ������� CRandom ���κ��� ���� ���Ѵ�. 0~1 ������ �ε��Ҽ��� ���̴�. thread safe�ϴ�. 

		\~english
		Gets value from CRandom that created with global object. It is floating point value between 0 to 1. It does thread safe.

		\~chinese
		����?�������� CRandom%��ϴ?��0~1��?��ݩ��?����thread safe�ܡ�

		\~japanese
		��洫��֫������Ȫ��ª�쪿CRandom�������ϴ��ު���0~1����������?�����Ǫ���thread safe�Ǫ���
		\~
		*/
		PROUD_API static double StaticGetFloat();
	};


	template<typename T>
	T GetRandomElement(const CFastArray<T>& arr)
	{
		if (arr.GetSize() == 0)
			return 0;
		else
			return arr[CRandom::StaticGetInt()%arr.GetSize()];
	}

#if defined(_WIN32)    
	template<typename T>
	T GetRandomElement(const std::vector<T>& arr)
	{
		if (arr.size() == 0)
			return 0;
		else
			return arr[CRandom::StaticGetInt()%arr.size()];
	}
#endif
    
	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
