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

#include "Marshaler.h"

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
	DB cache server���� ������ ������ Table �� ������ ����� ����� ����

	\~english
	Sort of event that actually writting to user defined table in DB cache server

	\~chinese
	�DB cache server߾��?��?��Table??�??��������??��

	\~japanese
	DB cache server�ǫ�?��?����������Table��?����?�����������׾
	\~
	*/
	enum DbmsWritePropNodePendType
	{
		/**
		\~korean
		���� 
		
		\~english
		None 
		
		\~chinese
		��

		\~japanese
		�ʪ�
		\~
		*/
		DWPNPT_None,

		/**
		\~korean
		\ref PropNode  �߰� 

		\~english
		Add \ref PropNode 

		\~chinese
		��ʥ\ref PropNode%��

		\~japanese
		\ref PropNode  ��ʥ
		\~
		*/
		DWPNPT_AddPropNode,

		/** 
		\~korean
		\ref PropNode  ���� 

		\~english
		Delete \ref PropNode 
		
		\~chinese
		?�\ref PropNode%��

		\~japanese
		\ref PropNode  ���
		\~
		*/
		DWPNPT_RemovePropNode,

		/**
		\~korean
		Request �� ���� \ref PropNode ������Ʈ 
		
		\~english TODO:Translate needed.
		Update \ref PropNode.

		\~chinese TODO:Translate needed.
		�?\ref PropNode%��

		\~japanese
		Request ��?���� \ref PropNode ���ë׫�?��
		\~
		*/
		DWPNPT_RequestUpdatePropNode,

		/**
		\~
		\ref PropNode  SetValueIf
		*/
		DWPNPT_SetValueIf,

		/**
		\~
		\ref PropNode  ModifyValueIf
		*/
		DWPNPT_ModifyValue,

		/** 
		\~korean 
		Request �� ���� \ref PropNode ������Ʈ 
		
		\~english TODO:Translate needed.
		Update \ref PropNod.
		
		\~chinese TODO:Translate needed.
		�?\ref PropNode%��

		\~japanese
		Request �� ���� \ref PropNode ������Ʈ 
		\~
		*/
		DWPNPT_RequestUpdatePropNodeList,

		/** 
		\~korean
		\ref PropNode   �̵� 

		\~english 
		Update \ref PropNod 
		
		\~chinese
		\ref PropNode%�?��
		\~japanese
		\ref PropNode   ���
		\~
		*/
		DWPNPT_MovePropNode,

		/**
		\~korean
		\~english
		\~chinese
		\~japanese
		\~
		Unilateral Update \ref PropNod.
		*/
		DWPNPT_UnilateralUpdatePropNode,

		/**
		\~korean
		\~english
		\~chinese
		\~japanese
		\~
		Unilateral Update \ref PropNod.
		*/
		DWPNPT_UnilateralUpdatePropNodeList,

		/**
		\~korean
		\ref PropNode ������Ʈ

		\~english
		Update \ref PropNode

		\~chinese
		�?\ref PropNode%��

		\~japanese
		\ref PropNode ���ë׫�?��
		\~
		*/
		DWPNPT_UpdatePropNode,
	};

	PROUDSRV_API const PNTCHAR* TypeToString(DbmsWritePropNodePendType t);

	/**  @}  */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

PROUDNET_SERIALIZE_ENUM(DbmsWritePropNodePendType);

#ifdef _MSC_VER
#pragma pack(pop)
#endif