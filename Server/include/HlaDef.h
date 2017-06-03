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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** 
	\~korean

	\~english
	HLA message identifier

	\~chinese

	\~japanese
	\~
	HLA message identifier
	*/
	enum HlaMessageType
	{
		HlaMessageType_Appear = 10,		// S2C
		HlaMessageType_Disappear,		// S2C
		HlaMessageType_RequestChange,	// C2S or C2C
		HlaMessageType_NotifyChange,		// S2C
	};

	typedef uint16_t HlaClassID;
	typedef uint8_t HlaFieldGroupID;
	typedef uint64_t HlaEntityID;

	const HlaFieldGroupID HlaFieldGroupID_None = 0;

	const HlaEntityID HlaEntityID_None = 0;

	enum Protocol
	{
		Protocol_Undefined,
		Protocol_UnreliableSend,
		Protocol_ReliableSend,
	};

	/** 
	\~korean

	\~english
	return values from synch class invocation.
	\todo you may change this type to what you want
	
	\~chinese

	\~japanese
	\~
	return values from synch class invocation.
	\todo you may change this type to what you want
	*/
	typedef unsigned int HlaResult;

	/** 
	\~korean

	\~english
	means, "synch class call successful" 
	
	\~chinese

	\~japanese
	\~
	means, "synch class call successful" 
	*/
	static const HlaResult HlaResult_Ok = 0;

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
