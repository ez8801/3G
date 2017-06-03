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

#include "FakeClrBase.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud 
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
#ifdef _WIN32

	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	���� �ð����� Ư�� ��ƾ�� ����ǰ� �ϰ��� �Ѵٸ� CTimerThread �� CTimerQueue �� ����ϴ� ����� �ֽ��ϴ�. 
	- CTimerThread �� ���� �ð����� Ÿ�̸� �ݹ� �Լ��� ����˴ϴ�. ������ �� �Ѱ��� �����忡������ �ݹ��� �Ͼ�ϴ�. 
	- CTimerQueue �� ���� Ÿ�̸� �ݹ��� �������� ���� ���¿��� Ÿ�̸� �ð��� �Ǿ��� ������ �� �ٸ� �����忡�� �ݹ��� �Ͼ�ϴ�.

	\~english
	 If you want to have a specific routine to run at a specific time, use  CTimerThread or CTimerQueue.
	- CTimerThread runs a timer callback function at specific times. But callback only happens in a single thread. 
	- CTimerQueue allows callback to start in a different thread at specific times even thoud the previous timer callback hasn't been returned.

	\~chinese
	�������������???������routine��?�������� CTimerThread%��� CTimerQueue%��۰����
	- CtimerThread�������???��timer��?��?��ӣ����?����??������?��
	- CtimerQueue�?��timer��??��������??������timer��??����������?��?����?��

	\~japanese
	������઴�Ȫ����ҫ�?����?�������誦�˪���������ϡ�CTimerThread�ު���CTimerQueue���Ū�۰��������ު���
	- CTimerThread��������઴�Ȫ˫�����?��?��Ыë�??��?������ު��������������ê�1���Ϋ���ëɪǪΪ߫�?��Ыë���?�檷�ު���
	- CTimerQueue��Φ�۪Ϋ�����?��?��Ыë����꫿?�󪷪ƪ��ʪ�?���ǫ�����?����˪ʪê����ϡ��ު��ު�����ëɪǫ�?��Ыë���?�檷�ު���
	\~
	*/
	class CTimerThread
	{
		Event m_tickEvent;
		Timer m_timer;
		Thread m_thread;
		Thread::ThreadProc m_proc;
		void* m_procCtx;
		volatile bool m_stopThread;
		CriticalSection m_startStopMethodLock;

		static void OuterThreadProc(void* ctx);

	public:
		// true�̸� CoInitialize�� ������ ���۽� ȣ��ȴ�.
		bool m_useComModel; 

		/** 
		\~korean
		������. Ÿ�̸� �����尡 ���������� �ʽ��ϴ�. 
		\param threadProc ���� �ð����� ȣ��Ǵ� �Լ��Դϴ�. ����ڰ� �����ؾ� �մϴ�.
		\param interval Ÿ�̸� �ֱ�. �и����Դϴ�.
		\param ctx threadProc�� ����� �� �������� �����Դϴ�. ����ڰ� �����ؾ� �մϴ�. 

		\~english
		Creator and timer thead do not start here. 
		\param threadProc a function that gets called at an user-defined specific time.
		\param interval Timer cycle in millisecond.
		\param ctx A factor tht gets passed on when threadProc is running. This needs to be defined by user. 

		\~chinese
		������Timer ?��?��??㷡�
		\param threadProc ������??��У����?�����?��?��
		\param interval timer�Ѣ��������
		\param ctx threadProc?����?�����������?��ҡ�

		\~japanese
		������������?����ëɪ���㷪���몳�ȪϪ���ު���
		\param threadProc ������઴�Ȫ������󪵪��??�Ǫ�����?��?���������ʪ���Ъʪ�ު���
		\param interval ������?�Ѣ���߫����Ǫ���
		\param ctx threadProc ��?������������Ū������Ǫ�����?��?����Ҫ�����驪�����ު���
		\~
		*/
		CTimerThread(Thread::ThreadProc threadProc, uint32_t interval, void *ctx);
		
		/** 
		\~korean
		�ı���. �ı��Ǳ� ���� Ÿ�̸� �����带 �����ŵ�ϴ�. 

		\~english
		Shuts down timer thread before destruction.

		\~chinese
		��?�����?����?�timer?�

		\~japanese
		��?����?�������˫�����?����ëɪ����������ު���
		\~
		*/
		~CTimerThread();

		/** 
		\~korean
		Ÿ�̸� �������� �۵��� �����մϴ�.

		\~english
		Starts the operation of timer thread.

		\~chinese
		?�timer?����??��

		\~japanese
		������?����ëɪ����Ѫ���㷪��ު���
		\~
		*/
		void Start();

		/** 
		\~korean
		Ÿ�̸� �������� �۵��� �����ϰ�, ������ �ı��� �Ϸ�� ������ ��ٸ��ϴ�. 

		\~english
		Stops the operation of timer thread and wait until a thread gets destructed.

		\~chinese
		?�timer?����??������?����??�֡�

		\~japanese
		������?����ëɪ����Ѫ���򭪷�ơ�����ë���?�������������ު�����ު���
		\~
		*/
		void Stop();
	};

	/**  @} */
#endif
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
