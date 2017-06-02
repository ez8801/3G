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
#ifndef _WIN32
    #include "CriticalSect.h"
    #include <pthread.h>
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
	��Ƽ������ ���α׷��ֿ��� semaphore ��ü�̴�.
	- .Net Framework�� System.Threading.Semaphore�� ���� ������ �Ѵ�.

	\~english
	Semaphore object of multi-thread programming.
	- This works same as System.Threading.Semaphore of .Net Framework.

	\~chinese
	��?��?������semaphore?�ڡ�
	- ���?.Net Framework ��System.Threading.Semaphore%���������ġ�

	\~japanese
	�ޫ������ëɫ׫���߫󫰪�semaphore���֫������ȪǪ���
	- .Net Framework��System.Threading.Semaphore�Ϊ誦����ܪ򪷪ު���
	\~
	*/
	class Semaphore
	{
#ifdef _WIN32
		HANDLE m_sema;
#else
		// m_cs�� ���� ��ȣ��. �� ���� 0�� �ɶ����� �����带 awake�Ѵ�.
		int32_t m_count, m_maxCount; 

		// semaphore ��� condition variable�� ����Ѵ�. ios������ ������ named object�� �䱸�� ������
		pthread_cond_t m_cond;

		// m_cond�� �ʿ�� ��
		CriticalSection m_cs;
#endif 

	public:

		/** 
		\~korean
		������
		\param initialCount semaphore ��ü�� ���� �ʱ� ���� ��
		\param maxCount semaphore ��ü�� ���� �� �ִ� �ִ밪

		\~english
		Creator
		\param initialCount the initial value that semaphore object will have.
		\param maxCount the maximum value that semaphore object can have.

		\~chinese
		�����
		\param initialCount semaphore?��???�������?ݻ?��
		\param maxCount semaphoreʦ�?��������?��

		\~japanese
		�����
		\param initialCount semaphore ���֫������Ȫ�����Ѣ?ݻ��
		\param maxCount semaphore ���֫������Ȫ��ƪ�������
		\~
		*/
		Semaphore(int initialCount, int maxCount);

		/** 
		\~korean
		�ı��� 

		\~english
		Destructor

		\~chinese
		��?�

		\~japanese
		��?�
		\~
		*/
		~Semaphore();

		/** 
		\~korean
		���� ī��Ʈ�� 1 �̻��� �� ������ ������ ��ٸ���. 
		���� ī��Ʈ�� 1 �̻��� ��� ī��Ʈ�� 1 ���ҽ�Ű�鼭 �����Ѵ�.

		\~english
		It waits endlessly untill the internal counte becomes higher than 1. 
		If the count becomes higher than 1, it reduces the count by 1 and returns.

		\~chinese
		��������?ݻcount?1�߾��
		?ݻcount?1�߾��?������count?�1?���ޡ�

		\~japanese
		?ݻ������Ȫ�1�߾�˪ʪ����ު��ڪ�ʪ�����ު���
		?ݻ������Ȫ�1�߾�Ǫ������ꡢ������Ȫ�1��ᴪ����ʪ���꫿?�󪷪ު���
		\~
		*/
		bool WaitOne()
		{
			return WaitOne(PN_INFINITE);
		}
		/** 
		\~korean
		���� ī��Ʈ�� 1 �̻��� �� ������ ���� �ð� ��ٸ���. 
		���� ī��Ʈ�� 1 �̻��� ��� ī��Ʈ�� 1 ���ҽ�Ű�鼭 �����Ѵ�. 
		\param timeOut (�и���) �ñ׳� ��� �ִ� �ð�. INFINITE�� ������ ������ ��ٸ���.

		\~english
		It waits for a specific time until the internal count becomes higher than 1. 
		If the count becomes higher than 1, it reduces the count by 1 and returns. 
		\param timeOut (millisecond) The maximum waiting time for signal standby. Input INFINITE if you want it to wait endlessly.

		\~chinese
		��������??�?ݻcount?��1�߾��
		?ݻcount?1�߾��?������count?�1?���ޡ�
                \param timeOut ��������������?������??��?��INFINITE��?������Ѣ���⡣

		\~japanese
		?ݻ������Ȫ�1�߾�˪ʪ����ު�������������ު���
		?ݻ������Ȫ�1�߾�Ǫ������ꡢ������Ȫ�1��ᴪ����ʪ���꫿?�󪷪ު���
		\param timeOut���߫����������ʫ�����������ࡣINFINITE���������ڪ�ʪ�����ު���
		\~
		*/
		bool WaitOne(uint32_t timeOut);

		/** 
		\~korean
		���� ī��Ʈ�� Ư�� ����ŭ ������Ų��.
		\param releaseCount ������ų �� 
		\return ������Ű�� ���� semaphore�� ���� ��

		\~english TODO:translate needed.
		Increase the internal count with a certain value. 
		\param releaseCount Value to be increased
		\return Internal value of semaphore before the increase. 

		\~chinese
		��ʥ?ݻcount��?������?��
		\param releaseCount ���ʥ��?��
		\return ��ʥ������semaphore?ݻ?��

		\~japanese
		?ݻ������Ȫ�����������?ʥ�����ު���
		\param releaseCount ?ʥ��������
		\return ?ʥ��������� semaphore��?ݻ��
		\~
		*/
		void Release(int releaseCount = 1);
	};

	/** @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
