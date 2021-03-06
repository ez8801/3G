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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	/** \addtogroup net_group
	*  @{
	*/

	enum SocketType
	{
		SocketType_Tcp, SocketType_Udp, SocketType_Raw,
	};

#if defined(_WIN32)
	class OverlappedResult
	{
	public:
		/// rievedFlags
		uint32_t m_retrievedFlags;

		/** 
		\~korean 
		���� ���� �߻��� ���´�. SocketErrorCode_Ok �̸� ���� 
		
		\~english TODO:translate needed.
		It is received when a socket error occurs. Normal if it is SocketErrorCode_Ok

		\~chinese
		Socket ?��????����SocketErrorCode_Ok ��?���ȡ�

		\~japanese
		�����ëȫ���??���������êƪ��ު��� SocketErrorCode_Ok�Ǫ�������ȪǪ���
		\~
		*/
		SocketErrorCode m_errorCode;

		/**
		\~korean
		
		\~english
		
		\~chinese

		\~japanese
		\~
		for recvfrom(UDP) only
		*/
		AddrPort m_receivedFrom;
	
		/** 
		\~korean 
		�Ϸ�� Data����

		\~english TODO:translate needed.
		Completed data length

		\~chinese
		?����data?����

		\~japanese
		�������쪿��?��������
		\~
		*/
		int m_completedDataLength;

		inline OverlappedResult()
		{
			m_completedDataLength = 0;
			m_retrievedFlags = 0;
			m_errorCode = SocketErrorCode_Ok;
			m_receivedFrom = AddrPort::Unassigned;
		}
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