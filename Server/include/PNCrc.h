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

#define UPDC16(cp,crc)      (Proud::CCrc::Crc16Table[((crc^cp) & 0xff)] ^ (crc >> 8))
#define UPDCCCITT(cp,crc)   (Proud::CCrc::CrcCcittTable[((crc >> 8) & 0xff)] ^ (crc << 8) ^ cp)
#define UPDC32(octet,crc)   (Proud::CCrc::Crc32Table[((crc) ^ (octet)) & 0xff] ^ ((crc) >> 8))

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	CRC üũ�� Ŭ�����Դϴ�.
	
	\~english
	CRC checksum class
	
	\~chinese
	CRC��??��?��
	
	\~japanese
	CRC�����ë����૯�髹�Ǫ���
	\~
	*/
	class CCrc
	{
	public:
		/** 
		\~korean
		Crc-16 
		\param data �������� ������
		\param length �������� ����
		\return üũ�� �����

		\~english TODO:translate needed.
		Crc-16 
		\param data Data pointer
		\param length Data length
		\return Check sum result value

		\~chinese
		Crc-16
		\param data ?�����?
		\param length ?����?��
		\return ��??��?��?

		\~japanese
		Crc-16 
		\param data ��?���Ϋݫ���?
		\param length ��?��������
		\return �����ë�����̿����
		\~
		*/
		PROUD_API static unsigned short Crc16(const uint8_t* data, unsigned int length);

		/** 
		\~korean
		Crc-ccitt 
		\param data �������� ������
		\param length �������� ����
		\return üũ�� �����
		
		\~english TODO:translate needed.
		Crc-ccitt 
		\param data Data pointer
		\param length Data length
		\return Check sum result value

		
		\~chinese
		Crc-ccitt
		\param data ?�����?
		\param length ?����?��
		\return ��??��?��?
		
		\~japanese
		Crc-ccitt 
		\param data ��?���Ϋݫ���?
		\param length ��?��������
		\return �����ë�����̿����
		\~
		*/
		PROUD_API static unsigned short CrcCcitt(const uint8_t* data, unsigned int length);

		/**  
		\~korean
		Crc-32
		\param data �������� ������
		\param length �������� ����
		\return üũ�� �����
		
		\~english TODO:translate needed.
		Crc-32
		\param data Data pointer
		\param length Data length
		\return Check sum result value

		
		\~chinese
		Crc-32
		\param data ?�����?
		\param length ?����?��
		\return ��??��?��?
		
		\~japanese
		Crc-32
		\param data ��?���Ϋݫ���?
		\param length ��?��������
		\return �����ë�����̿����
		\~
		*/
		PROUD_API static unsigned int  Crc32(const uint8_t* data, unsigned int length);

	private:
		static const unsigned short Crc16Table[256];
		static const unsigned short CrcCcittTable[256];
		static const unsigned int  Crc32Table[256];
	};

	typedef unsigned int Crc32;

	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif