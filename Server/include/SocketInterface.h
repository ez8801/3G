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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class CSocket;

#ifdef _WIN32

	/** \addtogroup net_group
	*  @{
	*/

	/** 
	\~korean
	SocketSelectContext class
	- ���� ������ Sample�� SimpleHttpConnect�� �����Ͻø� �˴ϴ�.
	- socket�� select() non-block model �� ���� �뵵
	- ����: Wait ȣ�� �Ŀ��� FD_SET�� ������ �ٲ��. ���� �� ��ü�� 1ȸ������ ������ �Ѵ�. 
	- Win32������ �����ϴ� ����Դϴ�. iOS, linux������ �̰� ��� ::poll()�� ����Ͻʽÿ�.

	\~english TODO:translate needed.
	SocketSelectContext class
	- For instruction examples, please refer to SimpleHttpConnect within the samples.
	- Usage for select() non-black model of the socket.
	- Warning: after calling wait, the content of FD_SET is changed. Therefore, this object must be used on one-time basis.
	- This feature is supportedin Win32 only. In iOS and Linux, use ::poll() instead.

	\~chinese
	SocketSelectContext class
	- ����۰�����?��sample��SimpleHttpConnect?ʦ��
	- ?��socket��select() non-block model����Բ��
	- ���Wait��У���?��?FD_SET��?黡����?��������������
	- ���Win32ʦ��򥡣�iOS, linux����::poll()?����??��

	\~japanese
	SocketSelectContext class
	- ���������ϡ�����׫�Ϊ���SimpleHttpConnect��?�Ū˪���Ъ����Ǫ���
	- socket��select() non-block model�Ϊ������Բ
	- �����Wait���������˪�FD_SET��?黪�?���ު�����êơ����Ϋ��֫������Ȫ�??�����Ū��ʪ���Ъʪ�ު���
	- Win32�ǪΪ߫���?�Ȫ���Ѧ���Ǫ���iOS��linux�ǪϪ����۪���::poll()���Ūêƪ���������
	\~
	*/
	class SocketSelectContext
	{
	public:
		SocketSelectContext() {}

		virtual void AddWriteWaiter(CSocket& socket) = 0;
		virtual void AddExceptionWaiter( CSocket& socket ) = 0;
		virtual void Wait(uint32_t miliSec) = 0;
		virtual bool GetConnectResult(CSocket& socket, SocketErrorCode& outCode) = 0;

		PROUD_API static SocketSelectContext *New();
	};
#endif // _WIN32

	/**
	\~korean
	Socket Delegate Interface
	- Socket�� ���õ� ������ OnSocketWarning �Լ����� ������ �ִ�.

	\~english
	Socket Delegate Interface
	- You can receive Socket related error from OnSocketWarning function.

	\~chinese
	Socket Delegate Interface
	- Socket��?��??ʦ��OnSocketWarning��?����⥡�

	\~japanese
	Socket Delegate Interface
	- Socket��?֧����?��OnSocketWarning ??����������ު���
	\~
	*/
	class ISocketDelegate
	{
	public:
		virtual ~ISocketDelegate() {}
		virtual void OnSocketWarning(CSocket* soket, String msg) = 0;
	};

	/**
	\~korean
	CSocket class
	- Proud�� NetClient �� ���� �ʰ� �ܺ��� Server�� http�� �����Ҷ� ���� �����ϴ�.
	- ���������� Proud::FastSocket �� ����Ѵ�.

	\~english
	CSocket class
	- It is useful when you access external Server or http without NetClient of ProudNet.
	- Use Proud::FastSocket internally

	\~chinese
	CSocket class
	- ������Proud��NetClient��??��ݻ��Server���http��?��������?���ġ�
	- ����?ݻ Proud::FastSocket%��

	\~japanese
	CSocket class
	- Proud��NetClient���Ū�ʪ���ݻ�Ϋ�?��?��http�򫢫��������������Ū������ĪǪ���
	- ?ݻ�ܪ�Proud::FastSocket�����Ī��ު���
	\~
	*/
	class CSocket
	{
	public:
		virtual ~CSocket(){}

	public:
		virtual bool Bind() = 0;
		virtual bool Bind(int port) = 0;
		virtual bool Bind( const PNTCHAR* addr, int port ) = 0;

		/**
		\~kore?an
		Connect �Ѵ�.
		\param hostAddr host �� �ּ�
		\param hostPort host �� port

		\~english
		Connect.
		\param hostAddr Address of host
		\param hostPort Port of host


		\~chinese
		?��connect��
		\param hostAddr host���򣡣
		\param hostPort host��port��

		\~japanese
		��?���ު���
		\param hostAddr host �Ϋ��ɫ쫹
		\param hostAddr host �Ϋ�?��
		\~
		*/
		virtual SocketErrorCode Connect(String hostAddr, int hostPort) = 0;

#if defined(_WIN32)
		/**
		\~korean
		UDP socket
		- Recv�� Issue�Ѵ�.
		\param length ������ ũ��
		\return ���� Error�� �������ݴϴ�. SocketErrorCode_Ok �̸� ����

		\~english
		UDP socket
		- Issue Recv
		\param length Size of length buffer
		\return Return the socket error. If SocketErrorCode_Ok, it is normal.


		\~chinese
		UDP socket
		- ��Recv?��issue��
		\param length buffer����᳡�
		\return ����socket��Error��SocketErrorCode_Ok ��?���ȡ�

		\~japanese
		UDP socket
		- Recv��Issue���ު���
		\param length �Ыëի�?�Ϋ�����
		\return �����ëȫ���?��꫿?�󪷪ު���SocketErrorCode_Ok�Ǫ�������ȪǪ���
		\~
		*/
		virtual SocketErrorCode IssueRecvFrom(int length) = 0;
		
		/**
		\~korean
		UDP socket
		- Send�� Issue�Ѵ�.
		\param data ���� data�� �迭
		\param count �迭�� ũ��
		\param sendTo ���� �ּ�
		\return ���� Error�� �������ݴϴ�. SocketErrorCode_Ok �̸� ����

		\~english
		UDP socket
		- Does asynchronous send call.

		\~chinese
		UDP socket
		- ��Send?��Issue��
		\param data �?����data��??��
		\param count ??����᳡�
		\param sendTo �?�����򣡣
		\return ����socket��Error��SocketErrorCode_Ok ��?���ȡ�

		\~japanese
		UDP socket
		- Send��Issue���ު���
		\param data ����?������֪
		\param count ��֪�Ϋ�����
		\param sendTo ��뫢�ɫ쫹
		\return �����ëȫ���?��꫿?�󪷪ު���SocketErrorCode_Ok�Ǫ�������ȪǪ���
		\~
		*/
		virtual SocketErrorCode IssueSendTo( uint8_t* data, int count, AddrPort sendTo ) = 0;
		
		/**
		\~korean
		TCP socket
		- Recv�� Issue�Ѵ�.
		\param length ������ ũ��
		\return ���� Error�� �������ݴϴ�. SocketErrorCode_Ok �̸� ����

		\~english TODO:translate needed.
		TCP socket
		- Issue Recv
		\param length Size of length buffer
		\return Return the socket error. If SocketErrorCode_Ok, it is normal.


		\~chinese
		UDP socket
		- ��Recv?��issue��
		\param length buffer����᳡�
		\return ����socket��Error��SocketErrorCode_Ok ��?���ȡ�

		\~japanese
		TCP socket
		- Recv��Issue���ު���
		\param length �Ыëի�?�Ϋ�����
		\return �����ëȫ���?��꫿?�󪷪ު���SocketErrorCode_Ok�Ǫ�������ȪǪ���
		\~
		*/
		virtual SocketErrorCode IssueRecv(int length) = 0;

		/**
		\~korean
		TCP socket
		- Send �� Issue �Ѵ�.
		\param data ���� data �� �迭
		\param count �迭�� ũ��
		\return ���� Error �� �������ݴϴ�. SocketErrorCode_Ok�̸� ����

		\~english TODO:translate needed.
		TCP socket
		- Issue Send.
		\param data Array of the data to be sent.
		\param count Size of the array
		\return Return the socket error. If SocketErrorCode_Ok, it is normal.


		\~chinese
		UDP socket
		- ��Send?��Issue��
		\param data �?����data��??��
		\param count ??����᳡�
		\return ����socket��Error��SocketErrorCode_Ok ��?���ȡ�

		\~japanese
		TCP socket
		- Send��Issue���ު���
		\param data ����?������֪
		\param count ��֪�Ϋ�����
		\return �����ëȫ���?��꫿?�󪷪ު���SocketErrorCode_Ok�Ǫ�������ȪǪ���
		\~
		*/
		virtual SocketErrorCode IssueSend( uint8_t* data, int count) = 0;

		/**
		\~korean
		async issue�� ����� ��ٸ���.
		- ���� �ƹ��͵� �Ϸ���� �ʾ����� null�� �����Ѵ�.
		- ���� �Ϸ� ���� �Ǵ� ���� ���� ���� ���а� ����� ��ü�� �����ϵ� m_errorCode�� ä���� �ִ�.
		\param waitUntilComplete �Ϸ�ɶ����� ��ٸ� ������ �����Ѵ�.
		\param ret ��� \ref OverlappedResult ����
		\return �����̸� true, �����̸� false����

		\~english TODO:translate needed.
		Wait for the result of async issue.
		- If nothing has been completed, return null.
		- If completion success or failures as socket errors, etc. occur, return the object but it is filled with m_errorCode.
		\param waitUntilComplete Determine whether to wait until complete.
		\param Refer to the result \ref OverlappedResult
		\return Return true if successful or false if failed.


		\~chinese
		����async issue��?����
		- �?Դ?��?����?����null��
		- ��������?�����?��socket??����?����?������?��ӣ��??��m_errorCode��
		\param waitUntilComplete ?�����������?�֡�
		\param ret ?��?��\ref OverlappedResult%��
		\return ������?true����?��?����false��

		\~japanese
		async issue��̿��������ު���
		- �ު�������������ʪ��ê���null��꫿?�󪷪ު���
		- �⪷����������ު��ϫ����ëȫ���?�ʪɪ��������檸���髪�֫������Ȫ�꫿?�󪷪ު�����m_errorCode��?������ƪ��ު���
		\param waitUntilComplete �����������ު���Ī��ɪ�����̽�Ҫ��ު���
		\param ret ̿�� \ref OverlappedResult ?��
		\return ����Ǫ����true�������Ǫ����false��꫿?�󪷪ު���
		\~
		*/
		virtual bool GetRecvOverlappedResult(bool waitUntilComplete, OverlappedResult &ret) = 0;
		
		/**
		\~korean
		async issue�� ����� ��ٸ���.
		- ���� �ƹ��͵� �Ϸ���� �ʾ����� null�� �����Ѵ�.
		- ���� �Ϸ� ���� �Ǵ� ���� ���� ���� ���а� ����� ��ü�� �����ϵ� m_errorCode�� ä���� �ִ�.
		\param waitUntilComplete �Ϸ�ɶ����� ��ٸ� ������ �����Ѵ�.
		\param ret ��� \ref OverlappedResult ����
		\return �����̸� true, �����̸� false����

		\~english TODO:translate needed.
		Wait for the result of async issue.
		- If nothing has been completed, return null.
		- If completion success or failures as socket errors, etc. occur, return the object but it is filled with m_errorCode.
		\param waitUntilComplete Determine whether to wait until complete.
		\param ret Refer to the result \ref OverlappedResult
		\return Return true if successful or false if failed.


		\~chinese
		��async issue��?����
		- �?Դ?��?����?����null��
		- ��������?�����?��socket??����?����?������?��ӣ��??��m_errorCode��
		\param waitUntilComplete ?�����������?�֡�
		\param ret ?��?��\ref OverlappedResult%��
		\return ������?true����?��?����false��

		\~japanese
		async issue��̿��������ު���
		- �ު�������������ʪ��ê��顢null��꫿?�󪷪ު���
		- �⪷����������ު��ϫ����ëȫ���?�ʪɪ��������檸���髪�֫������Ȫ�꫿?�󪹪몬��m_errorCode��?������ƪ��ު���
		\param waitUntilComplete �����������ު���Ī��ɪ�����̽�Ҫ��ު���
		\param ret ̿�� \ref OverlappedResult ?��
		\return ����Ǫ����true�������Ǫ����false��꫿?�󪷪ު���
		\~
		*/
		virtual bool GetSendOverlappedResult(bool waitUntilComplete, OverlappedResult &ret) = 0;
#endif
        
		/**
		\~korean
		������ �ּҸ� �����´�.

		\~english TODO:translate needed.
		Get the address of the socket

		\~chinese
		��?socket���򣡣

		\~japanese
		�����ëȪΫ��ɫ쫹������?�ߪު���
		\~
		*/
		virtual AddrPort GetSockName() = 0;

		/**
		\~korean
		peer �� ���� ������ �ּҸ� �����´�.

		\~english TODO:translate needed.
		Get the socket address to the peer.

		\~chinese
		��??peer��socket�򣡣

		\~japanese
		Peer��?���뫽���ëȫ��ɫ쫹������?�ߪު���
		\~
		*/
		virtual AddrPort GetPeerName() = 0;

		/**
		\~korean
		��ſ� ���Ͽ� ��ŷ ��带 ����� ������ �����Ѵ�.

		\~english TODO:translate needed.
		Select whether to use the blocking mode for the communication.

		\~chinese
		???������������blockingټ�ҡ�

		\~japanese
		�����?���ƫ֫�ë��󫰫�?�ɪ��Ū����ɪ�������?���ު���
		\~
		*/
		virtual void SetBlockingMode(bool isBlockingMode) = 0;

		/**
		\~korean
		recv ������ �����͸� ���´�.

		\~english TODO:translate needed.
		Get the pointer of the recv buffer.

		\~chinese
		?��recv buffer���?��

		\~japanese
		recv�Ыëի�?�Ϋݫ���?����ު���
		\~
		*/
		virtual uint8_t* GetRecvBufferPtr() = 0;
		
		/**
		\~korean
		recv host�� ip Address�� ���´�.

		\~english TODO:translate needed.


		\~chinese
		?��recv host��ip Address��

		\~japanese
		recv host��ip Address����ު���
		\~
		*/
		PROUD_API static String GetIPAddress(String hostName);

		/**
		\~korean
		CSocket ��ü�� �����Ѵ�.
		\param type ������ Type�� ���Ѵ�.
		\param dg ������ �̺�Ʈ�� ���� ��ü. \ref ISocketDelegate �� ����

		\~english TODO:translate needed.
		Generate CSocket object
		\param type Determine the type of the socket.
		\param dg Object to receive the socket event. Refer to \ref ISocketDelegate.


		\~chinese
		���� CSocket%?�ڡ�
		\param type ���socket��Type��
		\param dg ���socket��event��?�ڡ�?��\ref ISocketDelegate%��

		\~japanese
		CSocket���֫������Ȫ��������ު���
		\param type �����ëȪ�Type��̽��ު���
		\param dg �����ëȪΫ��٫�Ȫ������뫪�֫������ȡ�\ref ISocketDelegate ��?�Ϊ���������
		\~
		*/
		PROUD_API static CSocket *New(SocketType type, ISocketDelegate *dg);
	};
	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
