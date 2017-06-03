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

#include "Message.h"
#include "AddrPort.h"
#include "ProcHeap.h"
#include "CompressEnum.h"
#include "ClassBehavior.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/* 
	\~korean
	���ŵ� �޽���. ���� �뵵��. 

	\~english
	Received messge. Internal purpose.

	\~chinese
	�����������?ݻ�ġ�

	\~japanese
	���᪷����ë�?����?ݻ��Բ�Ǫ���
	\~
	*/
	class CReceivedMessage
	{
		// ���� ����� ũ��. CFinalUserWorkItem�� ������ �ؼ� ���� �ȵǰ� �Ѵ�.
		NO_COPYABLE(CReceivedMessage)

	public:
		// ���� �������� fast heap�� �ܺ� �����ϱ� ������ ��ü �ı��� main ��ü�� ��װ� �� ���� fast heap access�� �ؾ� ������
		// ������ �׷� ����� ������� ���� obj-pool ����� ���� ������ unsafe�� �ƴ�.
		// ����: Final user work item�� ��� �̰��� RMI ID���� �����ϴ� �����̴�. �� MessageType_XXX�� ���ŵ� ���´�.
		CMessage m_unsafeMessage;

		// �۽���
		HostID m_remoteHostID;

		// UDP ������ ��쿡 ��ȿ�� ��� ����
		AddrPort m_remoteAddr_onlyUdp;

		// �����̷� �Դ�?
		bool m_relayed;

		// ACR
		int m_messageID; // m_hasMessgeID=true�϶��� ��ȿ 
		bool m_hasMessageID;

		//double m_actionTime;

		EncryptMode m_encryptMode;
		CompressMode m_compressMode;

		// ���� ��� ȣ�� Ƚ���� �ſ� ���� �޼��������� inline���� �д�.
		inline CReceivedMessage()
		{
			Clear();
		}

		inline CMessage &GetWriteOnlyMessage()
		{
			return m_unsafeMessage;
		}
		inline CMessage &GetReadOnlyMessage()
		{
			return m_unsafeMessage;
		}
		inline AddrPort GetRemoteAddr()
		{
			return m_remoteAddr_onlyUdp;
		}
		inline HostID GetRemoteHostID()
		{
			return m_remoteHostID;
		}
		inline bool IsRelayed()
		{
			return m_relayed;
		}

		// PIDL compiler output���� ȣ���ϹǷ�, getter method�� �ǵ��� ��.
		inline EncryptMode GetEncryptMode()
		{
			return m_encryptMode;
		}

		// PIDL compiler output���� ȣ���ϹǷ�, getter method�� �ǵ��� ��.
		inline CompressMode GetCompressMode()
		{
			return m_compressMode;
		}

		// called by BiasManagedPointer.
		inline void Clear()
		{
			m_relayed = false;
			m_remoteHostID = HostID_None;
			m_remoteAddr_onlyUdp = AddrPort::Unassigned;

			m_messageID = 0;
			m_hasMessageID = false;

			m_encryptMode = EM_None;
			m_compressMode = CM_None;

			m_unsafeMessage.Clear();
		}

	};


#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
