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

#include "Enums.h"
#include "FakeClr.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	class CNetCoreImpl;
	class CReceivedMessage;
	class IRmiHost;
	class BeforeRmiSummary;
	class AfterRmiSummary;

	/** 
	\~korean
	PIDL �����Ϸ��� ������ Stub Ŭ������ ���̽� Ŭ����

	���� ����
	- �� Ŭ������ ������ ���� �������� �� ��. PIDL �����Ϸ����� ������ ���� ������ �ؾ� �Ѵ�.

	\~english
	Base class of Stub class created by PIDL compiler

	Note
	- User must not create this class. Must be realized by PIDL compiler.

	\~chinese
	PIDL??��������Stub?������?��

	�������
	- ��?�������??�?���PIDL??�������??��?ड�

	\~japanese
	PIDL����ѫ���?����������Stub���髹�Ϋ�?�����髹

	���������
	- ���Ϋ��髹���?��?������?�ު��ʪ����ȡ�PIDL����ѫ���?��?�ު�����Ϊ��Ū��誦�˪��ʪ���Ъʪ�ު���
	\~
	*/
	class IRmiStub
	{
	public:
		IRmiHost *m_core;
		bool m_internalUse; // true�̸� ProudNet ����. ����ڴ� �ǵ��� ����

		/** 
		\~korean
		true�� �����ϸ� NotifyCallFromStub �� ȣ����� �� �ִ�.
		�׷���, �� �񰡷� ���� �ӵ��� ������ ��������. ������� �� ���� �Ѵ�
		���� �����Ѵ�.

		\~english
		If set as true then calls NotifyCallFromStub.
		But in return, process speed will be lowered significantly. It is recommended to use this when debugging.

		\~chinese
		?��?true��?ʦ���УNotifyCallFromStub��
		ӣ?������?٥?��˽����?���??��?����?��

		\~japanese
		true�����Ҫ����NotifyCallFromStub�������󪷪ƪ�骦���Ȫ��Ǫ��ު���
		������������??��?���������ʪ���ժ���ު����ǫЫë��󫰪򪹪����ΪߪĪ��몳�Ȫ�?�᪷�ު���
		\~
		*/
		bool m_enableNotifyCallFromStub;

		/** 
		\~korean
		true�� �����ϸ� BeforeRmiInvocation,AfterRmiInvocation �� �ݹ��Ѵ�.
		�׷��� �� �񰡷� ���� �ӵ��� �ణ ��������. ���� ����ȭ�� ���� RMI �Լ� ������ ����
		�ð��� üũ�� ���� �Ѵ� ���� �����Ѵ�.

		\~english
		If set as true then BeforeRmiInvocation and AfterRmiInvocation are called back.
		But in return, process speed will be lowered a little. It is recommended to use this when checking running time of RMI function of each type.

		\~chinese
		?��?true��?��?BeforeRmiInvocation,AfterRmiInvocation��
		ӣ?������?٥?��˽��?��������?������?���??RMI��????��??��?����?��

		\~japanese
		true�����Ҫ���ȡ�BeforeRmiInvocation,AfterRmiInvocation��?��Ыë����ު���
		������������??��?��������ᴪ�ժ���ު����������������Ϊ����RMI??����׾ܬ?�����������ë��������ΪߪĪ��몳�Ȫ�?�᪷�ު���
		\~
		*/
		bool m_enableStubProfiling;

		/** 
		\~korean
		�� �Լ��� �������� �� ��. PIDL �����Ϸ��� ������� override�Ѵ�.

		\~english
		DO NOT realize this function. The outcome of PIDL compiler will override.

		\~chinese
		���??���?��PIDL ??����?ڪ?override��

		\~japanese
		����??��?�ު��ʪ����ȡ�PIDL����ѫ���?��̿��ڪ����?��?�髤�ɪ���ު���
		\~
		*/
		virtual RmiID* GetRmiIDList() = 0;
		/** 
		\~korean
		�� �Լ��� �������� �� ��. PIDL �����Ϸ��� ������� override�Ѵ�.

		\~english
		DO NOT realize this function. The outcome of PIDL compiler will override.

		\~chinese
		���??���?��PIDL ??����?ڪ?override��

		\~japanese
		����??��?�ު��ʪ����ȡ�PIDL����ѫ���?��̿��ڪ����?��?�髤�ɪ���ު���
		\~
		*/
		virtual int GetRmiIDListCount() = 0;
		/** 
		\~korean
		�� �Լ��� �������� �� ��. PIDL �����Ϸ��� ������� override�Ѵ�.

		\~english
		DO NOT realize this function. The outcome of PIDL compiler will override.

		\~chinese
		���??���?��PIDL ??����?ڪ?override��

		\~japanese
		����??��?�ު��ʪ����ȡ�PIDL����ѫ���?��̿��ڪ����?��?�髤�ɪ���ު���
		\~
		*/
		virtual bool ProcessReceivedMessage(CReceivedMessage& pa, void* hostTag) = 0;
		/** 
		\~korean
		RMI�� ����� ���� ȣ��ȴ�.
		AfterRmiInvocation.m_rmiName�� USE_RMI_NAME_STRING�� define�ؾ� ���ڿ��� �����մϴ�.

		\~english
		Called right after RMI is run
		In AfterRmiInvocation.m_rmiName's case, a character string appears after you define USE_RMI_NAME_STRING.

		\~chinese
		RMI?����ء?����У��
		AfterRmiSummary.m_rmiName���USE_RMI_NAME_STRING��?����?�ݬ��.

		\~japanese
		RMI��?�����쪿���������󪵪�ު���
		AfterRmiInvocation.m_rmiName��USE_RMI_NAME_STRING��define�����������Ǫު���

		\~
		*/
		virtual void AfterRmiInvocation(const AfterRmiSummary& summary);
		/** 
		\~korean
		RMI�� ����Ǳ� ������ ȣ��ȴ�.
		BeforeRmiSummary.m_rmiName�� USE_RMI_NAME_STRING�� define�ؾ� ���ڿ��� �����մϴ�.

		\~english
		Called right after RMI is run
		In BeforeRmiSummary.m_rmiName's case, a character string appears after you define USE_RMI_NAME_STRING.

		\~chinese
		RMI?����������У��
		BeforeRmiSummary.m_rmiName���USE_RMI_NAME_STRING��?����?�ݬ��.

		\~japanese
		RMI��?���������������󪵪�ު���
		BeforeRmiSummary.m_rmiName��USE_RMI_NAME_STRING��define�����������Ǫު���

		\~
		*/
		virtual void BeforeRmiInvocation(const BeforeRmiSummary& summary);

		/** 
		\~korean
		������ �� �Լ��� override�ϸ�, RMI�� ����Ǹ鼭 ���� �Ķ���͸� ���ڿ��� ��� ǥ���� �� �ְ� ���ش�.
		��, ������ �ſ� �������� �ǹǷ� �����ؼ� ������ ����.

		\~english
		If user override this function then it lets parameter received from RMI be displayed as text string.
		But in return, process speed will be lowered significantly so be careful when you use this.

		\~chinese
		��?override���?��?��ʦ���RMI?����?����������???��?�ݬ����
		ӣ��������?��˽��������?����

		\~japanese
		��?��?������??��?��?�髤�ɪ���С�RMI��?������ʪ����������ѫ��?��?�����֪��������ƪǪ���誦�˪��ު���
		ӣ����������ު�Ȫ�ժ����誦�˪ʪ�Ϊ���򪷪��Ūêƪ���������
		\~
		*/
		virtual void NotifyCallFromStub(HostID remote, RmiID RMIId, String methodName, String parameters);

		PROUD_API void ShowUnknownHostIDWarning(HostID remoteHostID);

		PROUD_API IRmiStub();
		PROUD_API virtual ~IRmiStub();
	};

	extern const PNTCHAR* DecryptFailedError;

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
