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
	/** \addtogroup db_group
	*  @{
	*/

	/** 
	\~korean
	CoInitialize, CoUninitialize ȣ�� ���� �����.
	- �Ϲ������� CoInitialize�� CoUninitialize�� ȣ�� Ƚ���� ������ ����� �ϸ�, �� ������ ���� ȣ���ؾ� �ϴ� �޼����̴�.
	�ڼ��� ���� �� API�� ������ ������ ��.
	- ���� CoInitialize(), CoUninitialize()�� ȣ���ϴ� �ͺ��� �� Ŭ������ ���� ������ �����ϴ� ���� �� �������̴�.
	�� Ŭ������ �ڵ����� CoUninitialize()�� �ʿ��� �� ȣ���ϱ� �����̴�.
	
	\~english
	This method works in a set of CoInitialize and CoUninitialize call.
	- It needs to be called per each threads and normally the number of calls for CoInitialize and CoUninitialize should be balanced.
	Refer to API document for more detailed information.
	- It's safer to declare this class as a local variable rather than directly calling for CoInitialize() and CoUninitialize(),
	since it automatically calls for CoUninitialize() when needed.
	
	\~chinese
	CoInitialize, CoUninitialize��У??��
	- ����??CoInitialize��CoUninitialize����У�?�?�����������?����У��۰�ҡ�
	??��??����API���졣
	- ����������УCoInitialize()��CoUninitialize()۰�������?�ͱ?���??��?�ҡ�
	��?�?���CoUninitialize()��?��?�?��У��
	
	\~japanese
	CoInitialize, CoUninitialize �����󪷫ګ�����請�ު���
	- �����ܪˡ�CoInitialize��CoUninitialize����������?�˫Ы�󫹪�������驪����êơ�������ë�ܬ�������󪵪ʪ���Ъʪ�ʪ��᫽�ëɪǪ���
	�٪�������API��������?�Ϊ���������
	- ����CoInitialize(), CoUninitialize()�������󪹪��Ȫ��ϡ����Ϋ��髹���?����??����몷��۰����ê������ܪǪ���
	���Ϋ��髹����Ѫ�CoUninitialize()����驪Ȫ������������󪹪���Ǫ���
	\~
	*/
	class CCoInitializer
	{
	private:
		bool m_success;

	public:
		PROUD_API CCoInitializer();
		PROUD_API ~CCoInitializer();
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif