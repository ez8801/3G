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

#include "./CriticalSect.h"
#include "./Event.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

#if defined(_WIN32)    
	class CReaderLock_NORECURSE;
	class CWriterLock_NORECURSE;

	// ���������θ� ���� Ŭ������, ������ ���� ���뼺�� ����Ѵ�
	// ���� ��� ��� ����
	// *����* ��� ���ٽ� �������� �ʰ� ��������� �̾�����!
	class CReaderWriterMonitor_NORECURSE
	{
		friend CReaderLock_NORECURSE;
		friend CWriterLock_NORECURSE;
		CriticalSection m_cs; // ���Ŀ��� lock free �˰������� �����ؾ� �ϰڴ�. �ϴ��� �̷��� �����.

		int m_readerLockCount;
		int m_writerLockCount;
		uint32_t m_owningThread;
		Event m_noReaderLocked;
		Event m_noWriterLocked;

		int ReaderLock();
		void ReaderUnlock();
		void WriterLock();
		void WriterUnlock();

	public:
		CReaderWriterMonitor_NORECURSE(void);
		~CReaderWriterMonitor_NORECURSE(void);

	};

	class CReaderLock_NORECURSE
	{
		CReaderWriterMonitor_NORECURSE* m_cs;
		bool m_locked;
		int m_multipleReaderCount;
	public:
		/** 
		\~korean
		reader lock ��ü�� �����ڿ��� �ٷ� lock�� �� �ִ�.
		\param cs ������ reader lock ��ü
		\param initialLock true�̸� �����ڿ��� �ٷ� lock�Ѵ�. 

		\~english
		Reader lock object can be directly locked at constructor.
		\param cs reader lock object to be applied
		\param initialLock if true then constructor locks directly

		\~chinese
		����reader lock?������������lock��
		\param cs �������reader lock?�ڡ�
		\param initialLock true��??���������?��lock��

		\~japanese
		reader lock ���֫������Ȫ�������ꪹ����ë��Ǫ��ު���
		\param cs ���Ī���reader lock���֫�������
		\param initialLock true�Ǫ����������ꪹ����ë����ު��� 
		\~
		*/
		inline CReaderLock_NORECURSE(CReaderWriterMonitor_NORECURSE& cs, bool initialLock)
		{
			m_multipleReaderCount = 0;
			m_cs = &cs;
			m_locked = false;
			if (initialLock == true)
			{
				m_multipleReaderCount = m_cs->ReaderLock();
				m_locked = true;
			}
		}

		/** 
		\~korean
		�ı��� 
		- �̹� �� ��ü�� �����ϰ� �ִ� CriticalSection �� ���� ��� ���� ������ �ڵ����� �Ѵ�. 

		\~english
		Destructor 
		- If there is CriticalSection that is occupied by this object already then disoccupation will be performed automatically.

		\~chinese
		��?�
		- ����?���?�����CriticalSection��?�����?������

		\~japanese
		��?�
		- ?�˪��Ϋ��֫������Ȫ���󪷪ƪ���CriticalSection���������ꡢ���������Ѫ˪��ު��� 
		\~
		*/
		inline ~CReaderLock_NORECURSE()
		{
			if (m_locked)
				Unlock();
		}

		/** 
		\~korean
		reader lock�� �����Ѵ�.
		\return ��װ� ���� ���� multiple reader�� ���� 

		\~english
		Occupies reader lock
		\return number of multiple reader required after locking

		\~chinese
		���reader lock��
		\return ?�����?����multiple reader??��

		\~japanese
		reader lock����󪷪ު���
		\return ��ë����ƪ�����multiple reader��?
		\~
		*/
		inline void Lock()
		{
			m_locked = true;
			m_multipleReaderCount = m_cs->ReaderLock();
		}

		inline int GetMultipleReaderCount()
		{
			return m_multipleReaderCount;
		}

		/** 
		\~korean
		reader lock�� ���� �����Ѵ�. 

		\~english
		Withdraws reader lock

		\~chinese
		������reader lock��

		\~japanese
		reader lock�������𶪷�ު��� 
		\~
		*/
		inline void Unlock()
		{
			m_cs->ReaderUnlock();
			m_locked = false;
		}
	};

	class CWriterLock_NORECURSE
	{
		CReaderWriterMonitor_NORECURSE* m_cs;
		bool m_locked;
	public:
		/** 
		\~korean
		Writer lock ��ü�� �����ڿ��� �ٷ� lock�� �� �ִ�.
		\param ������ Writer lock ��ü
		\param initialLock true�̸� �����ڿ��� �ٷ� lock�Ѵ�. 

		\~english
		Writer lock object can be directly locked at constructor.
		\param to_be_applied Writer lock object
		\param initialLock if true then constructor locks directly

		\~chinese
		Writer lock ʦ���?��?���������lock��
		\param ������Writer lock?�ڡ�
		\param initialLock true��??���������?��lock��

		\~japanese
		Writer lock ���֫������Ȫ�������ꪹ����ë��Ǫ��ު���
		\param ���Ī��� Writer lock���֫�������
		\param initialLock true�Ǫ����������ꪹ����ë����ު��� 
		\~
		*/
		inline CWriterLock_NORECURSE(CReaderWriterMonitor_NORECURSE& cs, bool initialLock)
		{
			m_cs = &cs;
			m_locked = false;
			if (initialLock == true)
			{
				m_cs->WriterLock();
				m_locked = true;
			}
		}

		/** 
		\~korean
		�ı��� 
		- �̹� �� ��ü�� �����ϰ� �ִ� CriticalSection �� ���� ��� ���� ������ �ڵ����� �Ѵ�. 

		\~english
		Destructor
		- If there is CriticalSection that is occupied by this object already then disoccupation will be performed automatically.

		\~chinese
		��?�
		- ����?���?�����CriticalSection��?�����?������

		\~japanese
		��?�
		- ?�˪��Ϋ��֫������Ȫ���󪷪ƪ���CriticalSection���������ꡢ���������Ѫ˪��ު��� 
		\~
		*/
		inline ~CWriterLock_NORECURSE()
		{
			if (m_locked)
				Unlock();
		}

		/** 
		\~korean
		Writer lock�� �����Ѵ�. 

		\~english
		Occupies writer lock

		\~chinese
		���Writer lock��

		\~japanese
		Writer lock����󪷪ު���
		\~
		*/
		inline void Lock()
		{
			m_locked = true;
			m_cs->WriterLock();
		}

		/** 
		\~korean
		Writer lock�� ���� �����Ѵ�.

		\~english
		Withdraws writer lock

		\~chinese
		���Writer lock���

		\~japanese
		Writer lock�������𶪷�ު���
		\~
		*/
		inline void Unlock()
		{
			m_cs->WriterUnlock();
			m_locked = false;
		}
	};

	enum eAccessMode
	{
		eAccessMode_None = 0,
		eAccessMode_Read = 1,
		eAccessMode_Write = 2
	};


	class CReaderWriterAccessChecker
	{
#ifdef _DEBUG
		PROUDNET_VOLATILE_ALIGN uint32_t	m_AccessThreadID;
		PROUDNET_VOLATILE_ALIGN eAccessMode m_AccessMode;
#endif // _DEBUG
	public:
		CReaderWriterAccessChecker();
		void AssertThreadID(eAccessMode eMode) const;
		void ClearThreadID() const;
	};
#endif // __GNUC__

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
