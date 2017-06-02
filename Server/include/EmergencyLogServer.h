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

#include "ProudNetServer.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	/** 
	\~korean
	EmergencyLog ������ �䱸�ϴ� delegate

	\~english TODO:translate needed.
	The delegate requested by EmergencyLog server

	\~chinese
	EmergencyLog ��?�������delegate��

	\~japanese
	EmergencyLog ��?��?���ϴ���� delegate
	\~
	*/
	class IEmergencyLogServerDelegate
	{
	public:
		virtual ~IEmergencyLogServerDelegate() {}

		/**
		\~korean
		���� ���� �Ķ���͸� �����ϴ� �޼���.
		������ ���۵Ǵ� ���� �ݹ�ȴ�. ����ڴ� �� �޼��带 ���� �������� ���� ���� �ɼ��� �����ؾ� �Ѵ�.

		\param refParam ���� ���� �ɼ�. �� �Լ����� ����ڴ� Proud.CStartServerParameter.m_tcpPort �� �ݵ�� �����ؾ� �Ѵ�.
		Proud.CStartServerParameter.m_localNicAddr,Proud.CStartServerParameter.m_serverAddrAtClient �� �ʿ�� �����ϵ��� �Ѵ�.
		������ �Ķ���ʹ� �������� �ʾƵ� �ȴ�.
		����! CEmergencyLogServer �� UDP ����� ���� �ʱ⶧���� m_udpPorts, m_udpAssignMode �� �����ص� UDP ����� ���� �ʴ´�.

		\~english TODO:translate needed.
		The method to set server run parameters. 
		This is called back when the server starts. Users must set the server running option through this method. 
		\param refParam Server running option. In this function, the user must configure Proud.CStartServerParameter.m_tcpPort. 
		Proud.CStartServerParameter.m_localNicAddr,Proud.CStartServerParameter.m_serverAddrAtClient shall be configured when necessary. 
		Other parameters need not be configured. 
		Caution! As CEmergencyLogServer does not use UDP, UDP communication is not possible even if m_udpPorts and m_udpAssignMode are selected. 

		\~chinese
		?����?����?��??۰����
		��?��??��??��?����?������۰��?��?��?����?��?��??��

		\param refParam ��?��?��??�����?����?��??�� Proud.CStartServerParameter.m_tcpPort%��

		���??�� Proud.CStartServerParameter.m_localNicAddr, Proud.CStartServerParameter.m_serverAddrAtClient%��
		�����??����?�ǡ�
		�����? CEmergencyLogServer%������UDP��?��?����m_udpPorts, m_udpAssignMode ���??��UDP���ᡣ

		\~japanese
		��?��??���ѫ��?��?�����Ҫ���᫽�ë�
		��?��?����㷪�������૳?��Ыë�����ު�����?��?�Ϫ��Ϋ᫽�ëɪ��ת���?��?�˫�?��??�����׫��������Ҫ��ʪ���Ъʪ�ު���
		\param refParam ��?��??�����׫���󡣪���??�ǫ�?��?��Proud.CStartServerParameter.m_tcpPort ���������Ҫ��ʪ���Ъʪ�ު���
		Proud.CStartServerParameter.m_localNicAddr,Proud.CStartServerParameter.m_serverAddrAtClient����驪˪�ê����Ҫ��ƪ���������
		?��Ϋѫ��?��?�����Ҫ��ʪ��ƪ��ު��Ǫ���
		�����! CEmergencyLogServer��UDP���Ī򪷪ʪ����ᡢm_udpPorts, m_udpAssignMode �����Ҫ��ƪ�UDP���᪬�Ǫ��ު���
		\~
		*/
		virtual void OnStartServer(CStartServerParameter &refParam) = 0;

		/** 
		\~korean
		������ �����ؾ� �ϴ� ��Ȳ(������ ��û ��)�̸� �� �Լ��� true�� �����ϸ� �ȴ�. 

		\~english TODO:translate needed.
		If this is a situation where the server must be terminated (user request, etc), then this function shall return true. 

		\~chinese
		����?���?�����?�?����ף������?����true?ʦ��

		\~japanese
		��?��?���������ʪ���Ъʪ�ʪ�?�ϣ���?��?�����ʪɣ��Ǫ���Ъ���??��true��꫿?�󪹪�Ъ����Ǫ���
		\~
		*/
		virtual bool MustStopNow() = 0;
		
		/** 
		\~korean
		Critical section ��ü�� �����Ѵ�. �����ڴ� �� �Լ��� ���� �̹� ������ ������� critical section�̳�
		������ �غ��� critical section ��ü�� �����ؾ� �Ѵ�.  

		\~english TODO:translate needed.
		A critical section object is returned. Developers must supply either a critical section where the server is already being used or a critical section object additionally prepared.  

		\~chinese
		����Critical section?�ڡ�??����?���?�����?�����������critical section����?����?��critical section��

		\~japanese
		Critical section ���֫������Ȫ�꫿?�󪷪ު�����?�Ϫ���??���ת�?�˫�?��?�����Ī��ƪ���critical section�Ȫ�ܬ�����᪷��critical section���֫������Ȫ����媷�ʪ���Ъʪ�ު��� 
		  
		\~
		*/
		virtual CriticalSection* GetCriticalSection() = 0;
		
		/** 
		\~korean
		���� ������ �Ϸ������ �˸��� �̺�Ʈ
		\param err ���� ������ ���������� NULL��, �׷��� ������ ErrorInfo ��ü�� ����ִ�. 

		\~english TODO:translate needed.
		The event that informs the server start is complete. 
		If the server start is successful, NULL, otherwise the ErrorInfo object is in there. 
		

		\~chinese
		ͱ���?��??��?�������졣
		\param err ��?��??������?��NULL����??��ErrorInfo?�ڡ�

		\~japanese
		��?��?��㷪��������쪿���Ȫ��骻�뫤�٫��
		\param err ��?��?��㷪���������NULL��������������ErrorInfo���֫������Ȫ����êƪ��ު��� 
		
		\~
		*/
		virtual void OnServerStartComplete(Proud::ErrorInfo *err) = 0;

		/** 
		\~korean
		���� �ð����� ȣ��ȴ�. 

		\~english TODO:translate needed.
		It is called a fixed interval. 
		 
		\~chinese
		��̰��ӫ???��?����

		\~japanese
		������઴�Ȫ������󪵪�ު���
		\~
		*/
		virtual void OnFrameMove() {}
	};

	/** 
	\~korean
	EmergencyLog ����
	�Ϲ��� �뵵
	- Ŭ���̾�Ʈ�� ���� ������ �ʿ���� CNetClient.SendEmergencyLog �� ȣ���ϸ� �˾Ƽ� �α׼����� ����
	- ������ Create()�� �Ѵ�.
	- RunMainLoop()�� �����ϸ� �α� ������ ������ ������ ������ �����Ѵ�.

	\~english TODO:translate needed.
	EmergencyLog server
	General use
	- The client needs not be executed additionally. If you call CNetClient.SendEmergencyLog, it sends to the log server on its own. 
	- Creation is done with Create()
	- If you run RunMainLoop(), it performs its role until the log server ends. 

	\~chinese
	EmergencyLog ��?�
	������Բ
	- client����?��?����?�� CNetClient.SendEmergencyLog%??�??���log��?�
	- ������Create()��
	- ?��RunMainLoop()��????�����log��?��?�֡�

	\~japanese
	EmergencyLog ��?��?
	�����ܪ���Բ
	- ���髤����Ȫ�ܬ��?��������驪�����ު���CNetClient.SendEmergencyLog�������󪷪ʪ������?��?�����ު���
	- ������Create()�Ȫ��ު���
	- RunMainLoop()��?������ȫ���?��?�������������ު���ܪ��������ު���
	\~
	*/
	class CEmergencyLogServer
	{
	public:
		virtual ~CEmergencyLogServer(void) {}

		/** 
		\~korean
		�� �޼��带 �����ϸ� �α� ������ Ȱ��ȭ�ȴ�. �� �޼���� ������ �۵��� �����϶�� ��û�� IEmergencyLogServerDelegate ��
		���� ���� ������ �������� �ʴ´�. 

		\~english TODO:translate needed.
		- If you run this method, the log server is activated. This method does not return until the request to stop running the server is relayed by IEmergencyLogServerDelegate. 

		\~chinese
		?���۰����??̭��log��?��������?IEmergencyLogServerDelegate��?��?����?�?���?�����۰����?���ޡ�

		\~japanese
		���Ϋ᫽�ëɪ�?������ȫ���?��?������������ު������Ϋ᫽�ëɪϫ�?��?�����Ѫ���򭪷��Ȫ�����몬IEmergencyLogServerDelegate�˪�ê�?����ުǫ꫿?�󪷪ު��� 
		\~
		*/
		virtual void RunMainLoop() = 0;

		/** 
		\~korean
		CEmergencyLogServer ��ü�� �����Ѵ�. 

		\~english TODO:translate needed.
		Generate CEmergencyLogServer object. 

		\~chinese
		���� CEmergencyLogServer%?�ڡ�

		\~japanese
		CEmergencyLogServer ���֫������Ȫ��������ު���
		\~
		*/
		PROUDSRV_API static CEmergencyLogServer* Create(IEmergencyLogServerDelegate* dg);
	};

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
