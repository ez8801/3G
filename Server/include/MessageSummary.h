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

#include "EncryptEnum.h"
#include "CompressEnum.h"
#include "Enums.h"
#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class CMessage;

	/** \addtogroup net_group
	*  @{
	*/

	/** 
	\~korean
	���۵Ǵ� �޽����� ��� �����Դϴ�. ���� ��� RMI �α׸� ������ ��, ���� �޽����� � �������� ���� ����Ͽ� ����ڿ��� �����մϴ�. 

	\~english
	This is a quick summary of messages being sent. For instance, when tracking RMI log, this shows a summary of the sent messages to user such as which type they are in.

	\~chinese
	??����������驡�������RMI���log��?����?��?�����������?���������?��?��

	\~japanese
	?�ꪵ����ë�?���������êǪ����Ǫ��С�RMI�������檹��������ê���ë�?�����ɪΪ誦�����ҪʪΪ��ʪɪ��峪��ƫ�?��?����ꪷ�ު���
	\~
	*/
	class MessageSummary
	{
	public:
		/** 
		\~korean
		�޽����� ũ���Դϴ�. ProudNet�� �޽��� ���� ������ ������ �������� �ʽ��ϴ�. 

		\~english
		Size of message. This doesn't include other classes than the ProudNet message class.

		\~chinese
		��������᳡�������ProudNet������??�����??��

		\~japanese
		��ë�?���Ϋ������Ǫ���ProudNet�Ϋ�ë�?��ͭ�������ͭ�����ߪ�ު���
		\~
		*/
		int m_payloadLength;

		/** 
		\~korean
		����� �޽����� ũ���Դϴ�.������ ���� �ʾ�����,0�� ���ϴ�. ProudNet�� �޽��� ���� ������ ������ �������� �ʽ��ϴ�. 

		\~english
		Size of compressed message. This doesn't include other classes than the ProudNet message class.

		\~chinese
		??��������᳡�����?��??��?��0��������ProudNet������??�����??��

		\~japanese
		?�ꪵ�쪿��ë�?���Ϋ������Ǫ���?�ꪬ����ʪ����0������ު���ProudNet�Ϋ�ë�?��ͭ�������ͭ�����ߪ�ު���
		\~
		*/
		int m_compressedPayloadLength;

		/** 
		\~korean
		�� �޽����� RMI �޽����� ��� RMI�� ID���Դϴ�. 

		\~english
		RMI ID if a message is RMI.

		\~chinese
		�����������RMI������?��RMI��ID?��

		\~japanese
		���Ϋ�ë�?����RMI��ë�?���Ǫ������ꡢRMI��ID���Ǫ���
		\~
		*/
		RmiID m_rmiID;
		/** 
		\~korean
		�� �޽����� RMI �޽����� ��� RMI�� �Լ����Դϴ�. 

		\~english
		RMI function name if a message is RMI.

		\~chinese
		�����������RMI������?��RMI����?٣��

		\~japanese
		���Ϋ�ë�?����RMI��ë�?���Ǫ������ꡢRMI��??٣�Ǫ���
		\~
		*/
		const PNTCHAR* m_rmiName;
		/** 
		\~korean
		�� �޽����� ������ ��ȣȭ ����Դϴ�. 

		\~english
		The encrypted method of a message.

		\~chinese
		��??����??��ʥ����?��

		\~japanese
		���Ϋ�ë�?������ꬪ��쪿��?�������Ǫ���
		\~
		*/
		EncryptMode m_encryptMode;
		/** 
		\~korean
		�� �޽����� ������ �������Դϴ�.

		\~english
		The compressed method of a message.

		\~chinese
		��??����??��??۰�ҡ�

		\~japanese
		���Ϋ�ë�?������ꬪ��쪿?��۰�ҪǪ���
		\~
		*/
		CompressMode m_compressMode;
	};

	/**  @} */

	/** 
	\~korean
	IRmiStub::BeforeRmiInvocation ���� ���� �޽����� ��� �����Դϴ�. ���� ��� RMI �α׸� ������ ��, ���� �޽����� � �������� ���� ����Ͽ� ����ڿ��� �����մϴ�. 

	\~english
	Summary of received message at IRmiStub::BeforeRmiInvocation. For exmaple, it provide summary to user such as type of message when you tracking RMI log.

	\~chinese
	�IRmiStub::BeforeRmiInvocation �����������驡�������RMI���log��?����?��?������������?���������?��?��

	\~japanese
	IRmiStub::BeforeRmiInvocation �������ë�?���������êǪ����Ǫ��С�RMI�������檹��������ê���ë�?�����ɪ�����ҪʪΪ��ʪɪ��峪��ƫ�?��?����ꪷ�ު���
	\~
	*/
	class BeforeRmiSummary
	{
	public:
		/** 
		\~korean
		�� �޽����� RMI �޽����� ��� RMI�� ID���Դϴ�. 

		\~english
		RMI ID if a message is RMI.

		\~chinese
		�����������RMI������?��RMI��ID?��

		\~japanese
		���Ϋ�ë�?����RMI��ë�?���Ǫ������ꡢRMI��ID���Ǫ���
		\~
		*/
		RmiID m_rmiID;
		/** 
		\~korean
		�� �޽����� RMI �޽����� ��� RMI�� �Լ����Դϴ�. 
		USE_RMI_NAME_STRING�� define�ؾ� �� �Լ��� �Ķ���Ϳ��� ���ڿ��� �����մϴ�.

		\~english
		RMI function name if a message is RMI.
		A character string will appear in the parameter of this function only when you've defined USE_RMI_NAME_STRING.

		\~chinese
		�����������RMI������?��RMI����?٣��
		USE_RMI_NAME_STRING ����?�����?��??����?�ݬ��.

		\~japanese
		���Ϋ�ë�?����RMI��ë�?���Ǫ������ꡢRMI��??٣�Ǫ���
		USE_RMI_NAME_STRING��define�����������Ǫު���
		\~
		*/
		const PNTCHAR* m_rmiName;
		/** 
		\~korean
		���� Host�� HostID �Դϴ�. 

		\~english
		HostID of Host who sent

		\~chinese
		?����Host��Host ID��

		\~japanese
		��ê�Host��HostID�Ǫ���
		\~
		*/
		HostID m_hostID;
		/** 
		\~korean
		����ڰ� ������ hostTag�� �������Դϴ�. 

		\~english
		Pointer of user defined hostTag.

		\~chinese
		��?�����hostTag���?��

		\~japanese
		��?��?����Ҫ���hostTag�Ϋݫ���?�Ǫ���
		\~
		*/
		void* m_hostTag;
	};

	/**  @} */

	/** \addtogroup net_group
	*  @{
	*/

	/** 
	\~korean
	IRmiStub::AfterRmiInvocation ���� ���� �޽����� ��� �����Դϴ�. ���� ��� RMI �α׸� ������ ��, ���� �޽����� � �������� ���� ����Ͽ� ����ڿ��� �����մϴ�. 

	\~english
	Summary of received message at IRmiStub::AfterRmiInvocation. For exmaple, it provide summary to user such as type of message when you tracking RMI log.

	\~chinese
	�IRmiStub::AfterRmiInvocation �����������驡�������RMI���log��?����?��?������������?���������?��?��

	\~japanese
	IRmiStub::AfterRmiInvocation �������ë�?���������êǪ����Ǫ��С�RMI�������檹��������ê���ë�?�����ɪ�����ҪʪΪ��ʪɪ��峪��ƫ�?��?����ꪷ�ު���
	\~
	*/
	class AfterRmiSummary
	{
	public:
		/** 
		\~korean
		�� �޽����� RMI �޽����� ��� RMI�� ID���Դϴ�. 

		\~english
		RMI ID if a message is RMI.

		\~chinese
		�����������RMI��������?��RMI��ID?��

		\~japanese
		���Ϋ�ë�?����RMI��ë�?���Ǫ������ꡢRMI��ID���Ǫ���
		\~
		*/
		RmiID m_rmiID;
		/** 
		\~korean
		�� �޽����� RMI �޽����� ��� RMI�� �Լ����Դϴ�.
		USE_RMI_NAME_STRING�� define�ؾ� �� �Լ��� �Ķ���Ϳ��� ���ڿ��� �����մϴ�.

		\~english
		RMI function name if a message is RMI.
		A character string will appear in the parameter of this function only when you've defined USE_RMI_NAME_STRING.

		\~chinese
		�����������RMI��������?��RMI����?٣��
		USE_RMI_NAME_STRING ����?�����?��??����?�ݬ��.

		\~japanese
		���Ϋ�ë�?����RMI��ë�?���Ǫ������ꡢRMI��??٣�Ǫ���
		USE_RMI_NAME_STRING��define�����������Ǫު���
		\~
		*/
		const PNTCHAR* m_rmiName;
		/** 
		\~korean
		���� Host�� HostID �Դϴ�. 

		\~english
		HostID of Host who sent

		\~chinese
		?����Host��Host ID��

		\~japanese
		��ê�Host��HostID�Ǫ���
		\~
		*/
		HostID m_hostID;
		/** 
		\~korean
		����ڰ� ������ hostTag�� �������Դϴ�. 

		\~english
		Pointer of user defined hostTag.

		\~chinese
		��?�����hostTag���?��

		\~japanese
		��?��?����Ҫ���hostTag�Ϋݫ���?�Ǫ���
		\~
		*/
		void* m_hostTag;
		/** 
		\~korean
		���� RMI�Լ��� ó���Ǵµ� �ɸ��� �ð� 

		\~english
		Time to process received RMI function.

		\~chinese
		���RMI��?��?��?������??��

		\~japanese
		����RMI??��?�⪵���˪���������
		\~
		*/
		uint32_t m_elapsedTime;
	};

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif