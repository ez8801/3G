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

#include <winsvc.h>
#include "BasicTypes.h"
#include "PNString.h"

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

	class INTServiceEvent;

	/**
	\~korean
	���񽺸� ����� ��, CreateService �Լ��� ���Ǵ� �������Դϴ�.

	\~english
	It is a setting value that is used for CreateService function when registering a service.

	\~chinese
	�?��??�� ������CreateService��?��?��?��

	\~japanese
	��?�ӫ�����?��������CreateService??�����Ī�����������Ǫ���
	*/
	class CServiceParameter
	{
	public:
		/**
		\~korean
		���񽺿� ���� �׼����� �����մϴ�. �⺻ ���� SERVICE_ALL_ACCESS�Դϴ�.

		\~english
		Appoint the access of the service. Default value is SERVICE_ALL_ACCESS.

		\~chinese
		���?����?��??������??SERVICE_ALL_ACCESS��

		\~japanese
		��?�ӫ���?���뫢����������Ҫ��ު����ǫի��������SERVICE_ALL_ACCESS�Ǫ���
		*/
		DWORD m_desiredAccess;

		/**
		\~korean
		������ Ÿ���� �����մϴ�. �⺻ ���� SERVICE_WIN32_OWN_PROCESS�Դϴ�.

		\~english
		Appoint the service type. Default value is SERVICE_WIN32_OWN_PROCESS.

		\~chinese
		�����??��������??SERVICE_WIN32_OWN_PROCESS��

		\~japanese
		��?�ӫ��Ϋ����ת���Ҫ��ު����ǫի��������SERVICE_WIN32_OWN_PROCESS�Ǫ���
		*/
		DWORD m_serviceType;

		/**
		\~korean
		������ ���� �ɼ��� �����մϴ�. �⺻ ���� SERVICE_DEMAND_START�Դϴ�.

		\~english
		Set the start option of the service. Default value is SERVICE_DEMAND_START.

		\~chinese
		?����???��??������??SERVICE_DEMAND_START��

		\~japanese
		��?�ӫ��Ϋ���?�ȫ��׫��������Ҫ��ު����ǫի�������SERVICE_DEMAND_START�Ǫ���
		*/
		DWORD m_startType;

		/**
		\~korean
		���� ������ ������ ��� ������ ������ �����մϴ�. �⺻ ���� SERVICE_ERROR_NORMAL�Դϴ�.

		\~english
		Appoint the level of an error in case service start fails. Default value is SERVICE_ERROR_NORMAL.

		\~chinese
		�����???��??��??����?������??SERVICE_ERROR_NORMAL��

		\~japanese
		��?�ӫ�����?�Ȫ������������ꡢ����?�Ϋ�٫����Ҫ��ު����ǫի��������SERVICE_ERROR_NORMAL�Ǫ���
		*/
		DWORD m_errorControl;

		/**
		\~korean
		���񽺰� �����ؾ��� ������ �̸��� �����մϴ�.

		\~english
		Appoint the name of an account that the service executes.

		\~chinese
		���?����??��??٣��

		\~japanese
		��?�ӫ���?�����뫢������Ȫ�٣����Ҫ��ު���
		*/
		String m_serviceStartName;

		/**
		\~korean
		m_serviceStartName �Ű� ������ ���� ������ ���� �̸��� ���� ��ȣ�� �����մϴ�.

		\~english
		Appoint the password of the account name that has been appointed by m_serviceStartName parameter. 

		\~chinese
		?����m_serviceStartName??����������??٣�������?��

		\~japanese
		m_serviceStartName??�˪����Ҫ��쪿��������Ȫ�٣��?������?����Ҫ��ު���
		*/
		String m_password;

		/**
		\~korean
		������ �޼����Դϴ�.

		\~english
		It is a constructor method. 

		\~chinese
		�����۰����

		\~japanese
		�����ޫë��ɪǪ���
		*/
		PROUD_API CServiceParameter()
		{
			m_desiredAccess	= SERVICE_ALL_ACCESS;
			m_serviceType	= SERVICE_WIN32_OWN_PROCESS;
			m_startType		= SERVICE_DEMAND_START;
			m_errorControl	= SERVICE_ERROR_NORMAL;
		}
	};


	/**
	\~korean
	CNTService.WinMain �� ���� NTService�� ������ ���� �ʱ� �������Դϴ�.

	\~english
	It is an initial setting value when creating NTService by CNTService.WinMain.

	\~chinese
	��CNTService.WinMain�����NTService?�����?��?��

	\~japanese
	CNTService.WinMain�˪��NTService����������������Ѣ�������Ǫ���
	*/
	class CNTServiceStartParameter
	{
	public:
		/**
		\~korean
		NT ���� �̸��Դϴ�. �ִ� ���ڿ� ���̴� 256���̸�, '/'�� '\'�� ����� �Ұ����մϴ�.

		\~english
		It is the name of NT service. Maximum length of character string is 256 and special characters (such as '/' and '\') are not available. 

		\~chinese
		NT��?��٣?���ݬ?����?��?256?�ݬ�����ʦ���� '/' �� '\'��

		\~japanese
		NT��?�ӫ���٣�Ǫ������֪������256�Ǫ��ꡢ'/'��'\'�����ĪǪ��ު���
		*/
		String m_serviceName;

		/**
		\~korean
		CNTService�� �ʿ�� �ϴ� Event Sink ��ü�Դϴ�.

		\~english
		It is an Even Sink object that CNTService needs. 
		
		\~chinese
		CNTService ����� Event Sink ?�ڡ�

		\~japanese
		CNTService����驪Ȫ���Event Sink���֫������ȪǪ���
		*/
		INTServiceEvent* m_serviceEvent;

		/**
		\~korean
		���񽺸� ����� ��, CreateService �Լ��� ���Ǵ� �������Դϴ�.

		\~english
		It is a setting value that is used for CreateService function when registering a service.  

		\~chinese
		�?��??�� CreateService ��?�������?��?��

		\~japanese
		CNTService����驪Ȫ���Event Sink���֫������ȪǪ���
		*/
		CServiceParameter m_serviceParam;
	};


	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
