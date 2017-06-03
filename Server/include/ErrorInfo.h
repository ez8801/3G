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
#include "FakeClr.h"
#include "Enums.h"
#include "AddrPort.h"
//#include "NetPtr.h"
#include "Ptr.h"
#include "ProcHeap.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	class ErrorInfo;

	/** 
	\~korean
	���� ������ ��� ��ü�� ����Ʈ ������
	- ErrorInfoPtr �� ���� ����� ��ü�� �ƴϹǷ� fast alloc�� �Ⱦ���.

	\~english
	Smart pointer of the object that contains error info
	- ErrorInfoPtr does not use fast alloc since it does not exist often

	\~chinese
	??��?���������pointer��
	- ��?ErrorInfoPtr����?��������?�ڣ�����fast alloc��

	\~japanese
	����?���ê�����뫪�֫������ȪΫ���?�ȫݫ���?
	- ErrorInfoPtr�Ϫ誯?�檹�뫪�֫������ȪǪ�ʪ��Ϊǡ�fast alloc���Ū��ު���
	\~
	*/
	typedef RefCount<ErrorInfo> ErrorInfoPtr;

	/** 
	\~korean
	����(�Ǵ� ����) ������ ���� ��ü�Դϴ�.

	\~english
	Object contains error(or success) info

	\~chinese
	??��?���������������?�ڡ�

	\~japanese
	����?���ު����������ê����쪿���֫������ȪǪ���
	\~
	*/
	class ErrorInfo
	{
	public:
		/** 
		\~korean
		������ �����Դϴ�. ������ ������ ErrorType_Ok �Դϴ�.

		\~english
		Error type. If there is no error then ErrorType_Ok.

		\~chinese
		??��??��?��??��?ErrorType_Ok��

		\~japanese
		����?����׾�Ǫ�������?���ʪ����ErrorType_Ok�Ǫ���
		\~
		*/
		ErrorType m_errorType;
		/** 
		\~korean
		m_errorType �� ���� ���Դϴ�. 
		
		INetClientEvent.OnLeaveServer �� INetServerEvent.OnClientLeave ����
		m_detailType �� ���� ������ �� �ڼ��� ������ ��Ÿ���ϴ�.
		���� ��� Ŭ���̾�Ʈ ���α׷��� �����ϸ鼭 ������ �����Ǹ� ErrorType_TCPConnectFailure ��, 
		Ŭ���̾�Ʈ�� �����̳� ȸ���� �������� ������ ���� ErrorType_ConnectServerTimeout �� ���ϴ�.

		\~english
		Value for m_errorType 
		
		m_detailType indicates how disconnection occurs with more details at INetClientEvent.OnLeaveServer and INetServerEvent.OnClientLeave
		For an example, it enters ErrorType_TCPConnectFailure when disconnection occurs as client program terminates
 		or enters ErrorType_ConnectServerTimeout when disconnection occurs due to power failure and/or physical cable disconnection.

		\~chinese
		m_errorType ��???��

		� INetClientEvent.OnLeaveServer%�� INetServerEvent.OnClientLeave%��m_detailType?�����?������???黡�
		������ʫ������?�????����?������ ErrorType_TCPConnectFailure%�������?��ʫ��?����?��??�����ܣ�??��ErrorType_ConnectServerTimeout��

		\~japanese
		m_errorType ���ݻ���Ǫ���

		INetClientEvent.OnLeaveServer��INetServerEvent.OnClientLeave��m_detailType�ϡ�֧̿���Ϊ�ê��٪���?�ժ������ު���
		�Ǫ��С����髤����ȫ׫���બ�������ʪ�����?����𶪵�쪿��ErrorType_TCPConnectFailure �򡢫��髤����Ȫ��깪����ʪ�﷪����𶪵�쪿����ʪ�ErrorType_ConnectServerTimeout������ު���
		
		\~
		*/
		ErrorType m_detailType;

		/**
		\~korean
		������ ���� ������ ��� ���� ���� �ڵ�

		\~english
		Error code for socket error 

		\~chinese
		??��socket???��socket??��?��

		\~japanese
		����?�������ëȫ���?�Ǫ������ꡢ�����ëȫ���?��?��
		\~
		*/
		SocketErrorCode m_socketError;

		/**
		\~korean
		������ �߻� ȣ��Ʈ

		\~english
		Host that occur error

		\~chinese
		?��??�����

		\~japanese
		����?��?��۫���
		\~
		*/
		HostID m_remote;

		/**
		\~korean
		�߰� ���ڿ� ���� 

		\~english
		Information of additional string

		\~chinese
		��ʥ�ݬ�����ӡ�

		\~japanese
		��ʥ���֪����
		\~
		*/
		String m_comment;

		// ���� ���� �õ��� ���� ��� ��ȿ�� ������, ���� �ּ�
		AddrPort m_remoteAddr;

		/**
		\~korean
		ErrorType_InvalidPacketFormat �� ��� �߸��� ������ �޼����� �����Ѵ�.

		\~english
		Save wrong last message when case of ErrorType_InvalidPacketFormat

		\~chinese
		ErrorType_InvalidPacketFormat ��?��?��??���������ӡ�

		\~japanese
		ErrorType_InvalidPacketFormat �����ꡢ���ުê������Ϋ�ë�?���������ު���
		\~
		*/
		ByteArray m_lastReceivedMessage;

#if defined(_WIN32)    

		/**
		\~korean
		DB���� ���� HRESULT���Դϴ�.

		\~english
		HRESULT value using for DB

		\~chinese
		�DB�������HRESULT?��

		\~japanese
		DB���Ū���HRESULT���Ǫ���
		\~
		*/
		HRESULT m_hResult;
#endif
        
		/**
		\~korean
		DB���� ���� �ҽ��Դϴ�.

		\~english
		Source using for DB

		\~chinese
		�DB�������깣�source����

		\~japanese
		DB���Ū��뫽?���Ǫ���
		\~
		*/
		String m_source;

#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// �� Ŭ������ ProudNet DLL ��츦 ���� Ŀ���� �Ҵ��ڸ� ���� fast heap�� ���� �ʴ´�.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif 


		PROUD_API ErrorInfo();

		/**
		\~korean
		ErrorInfo::FromSocketError() �� ���Ͽ� �� �� �����ϰ� ErrorInfo �� ����ϴ�. 
		\param code ErrorType
		\param se ���� ���� type
		\return ������ ErrorInfoPtr

		\~english TODO:translate needed.
		Through ErrorInfo::FromSocketError(), you can make ErrorInfo more conveniently. 
		\param code ErrorType
		\param se Socket error type
		\return generated ErrorInfoPtr

		\~chinese
		��? ErrorInfo::FromSocketError()%����۰�������ErrorInfo��
		\param code ErrorType
		\param se socket??type��
		\return ������ErrorInfoPtr��

		\~japanese
		ErrorInfo::FromSocketError()���ת���ê���?��ErrorInfo���ª�ު��� 
		\param code ErrorType
		\param se �����ëȫ���? type
		\return �������쪿 ErrorInfoPtr
		
		\~
		*/
		PROUD_API static ErrorInfoPtr FromSocketError(ErrorType code, SocketErrorCode se);

		/**
		\~korean
		ErrorInfo::From() �� ���Ͽ� �� �� �����ϰ� ErrorInfo �� ����ϴ�.
		\param errorType ErrorType �Դϴ�.
		\param remote ������� HostID
		\param comment Error�� ������ ÷�� String
		\param lastReceivedMessage ������ ���� Message
		\return ������ ErrorInfoPtr

		\~english TODO:translate needed.
		Through ErrorInfo::From(), you can make ErrorInfo more more conveniently.
		\param errorType This is ErrorType
		\param remote HostID of the remote correspondent
		\param comment String Attached string related to the error
		\param lastReceivedMessage Message Last received message
		\return Generated ErrorInfoPtr

		\~chinese
		��? ErrorInfo::From()%����۰�������ErrorInfo��
		\param errorType ��ErrorType��
		\param remote ?۰��HostID��
		\param comment ?��Error��ݾʥString��
		\param lastReceivedMessage ���������Message��
		\return ������ErrorInfoPtr��

		\~japanese
		ErrorInfo::From() ���ת���ê���?�� ErrorInfo���ª�ު���
		\param errorType ErrorType �Ǫ���
		\param remote ������� HostID
		\param comment Error��?֧��������String
		\param lastReceivedMessage ������������Message
		\return �������쪿ErrorInfoPtr
		\~
		*/
		PROUD_API static ErrorInfoPtr From(ErrorType errorType, HostID remote = HostID_None, const String &comment = String(), const ByteArray &lastReceivedMessage = ByteArray() );

		/** 
		\~korean 
		ErrorInfo �� ����� ��� ������ String ���� �������ݴϴ�.

		\~english 
		Change error contents to string 

		\~chinese
		�����?����ErrorInfo�����������String��

		\~japanese
		ErrorInfo�������쪿��ƪ����ê�String�˫꫿?�󪷪ު���
		\~
		*/
		PROUD_API String ToString() const;

		/** 
		\~korean 
		��ü �ڽ��� �� ��ü�� �纻�� ��ϴ�. 

		\~english TODO:translate needed.
		The object itself is copied in a new object. 

		\~chinese
		��?������?�������?���졣

		\~japanese
		���֫��������?���檷�����֫������Ȫ˫���?���ު���
		\~
		*/
		ErrorInfo* Clone();

		/** 
		\~korean 
		���� ������ ���ڿ��� ��ȯ�Ѵ�.

		\~english 
		Change error contents to string

		\~chinese
		��??����??���ݬ����

		\~japanese
		����??黪����֪��?�����ު���
		\~
		*/
		PROUD_API static const PNTCHAR* TypeToString(ErrorType e);
		PROUD_API static const PNTCHAR* TypeToStringByLangID(ErrorType e, int languageID);

		/** 
		\~korean 
		ErrorType ���� ���ڿ��� ��ȯ�Ѵ�. (�ѱ���)

		\~english 
		Change ErrorType value to string (Korean)

		\~chinese
		��ErrorType???���ݬ������?����

		\~japanese
		ErrorType�������֪��?�����ު�������?�ޣ�
		\~
		*/
		PROUD_API static const PNTCHAR* TypeToString_Kor(ErrorType e);

		/** 
		\~korean 
		ErrorType ���� ���ڿ��� ��ȯ�Ѵ�. (����)

		\~english 
		Change ErrorType value to string (English)

		\~chinese
		��ErrorType???���ݬ������������

		\~japanese
		ErrorType�������֪��?�����ު��������ޣ�
		\~
		*/
		PROUD_API static const PNTCHAR* TypeToString_Eng(ErrorType e);

		/** 
		\~korean 
		ErrorType ���� ���ڿ��� ��ȯ�Ѵ�. (��ü �߱���)

		\~english 
		Change ErrorType value to string (Simplified Chinese)

		\~chinese
		��ErrorType???���ݬ������??������

		\~japanese
		ErrorType�������֪��?�����ު�������?��?�ޣ�
		\~
		*/
		PROUD_API static const PNTCHAR* TypeToString_Chn(ErrorType e);
	};

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
