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
#include "HlaDef.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	template<typename type>
	class CStaticBehaviorMember
	{
		type m_value_INTERNAL;
	public:
		inline void Set(type value)
		{
			m_value_INTERNAL = value;
		}
		inline type Get()
		{
			return m_value_INTERNAL;
		}

		// does nothing, but it is needed because it is called by SWD compiler output.
		// \return always false
		inline bool GatherTheChangeToMessage(HlaFieldGroupID memberID, CMessage &outputMessage, Protocol &outProtocol)
		{
			outProtocol = Protocol_Undefined;
			return false;
		}

		inline void ClearTheChange()
		{
		}

		inline bool IsChanged()
		{
			return false;
		}

		// does nothing, but it is needed because it is called by SWD compiler output.
		inline void GatherAllToMessage(HlaFieldGroupID memberID, CMessage &outputMessage)
		{
		}
	};

	/** 
	\~korean
	Conditional behavior member�� ���� �ӽ� Class
	
	\~english
	a template class for conditional behavior member
	
	\~chinese
	?��Conditional behavior member��??Class��
	
	\~japanese
	Conditional behavior member�Ϊ�����������髹
	\~
	*/
	template<typename type>
	class CConditionalBehaviorMember
	{
		type m_value_INTERNAL;
		bool m_valueChanged_INTERNAL;
	public:
		inline CConditionalBehaviorMember()
		{
			m_valueChanged_INTERNAL = false;
		}
		inline void Set(type value)
		{
			if (value != m_value_INTERNAL)
			{
				// A variable whose 'changed'
				// is true will be multicasted soon.
				m_valueChanged_INTERNAL = true;
				m_value_INTERNAL = value;
			}
		}
		inline type Get()
		{
			return m_value_INTERNAL;
		}

		// append the value to the message if it has been changed.
		// \return true if the value is written to the message.
		inline bool GatherTheChangeToMessage(HlaFieldGroupID memberID, CMessage &outputMessage, Protocol &outProtocol)
		{
			outProtocol = Protocol_Undefined;
			if (m_valueChanged_INTERNAL)
			{
				outputMessage.Write(memberID);
				outputMessage<<m_value_INTERNAL;
				outProtocol = Protocol_ReliableSend;

				return true;
			}

			return false;
		}

		inline void ClearTheChange()
		{
			m_valueChanged_INTERNAL = false;
		}

		inline bool IsChanged()
		{
			return m_valueChanged_INTERNAL;
		};

		// does nothing, but it is needed because it is called by SWD compiler output.
		inline void GatherAllToMessage(HlaFieldGroupID memberID, CMessage &outputMessage)
		{
			outputMessage.Write(memberID);
			outputMessage<<m_value_INTERNAL;
		}
	};

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif