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

#include "ErrorInfo.h"
#include "ByteArray.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class CByteArray;
	class CMessage;

	class CCryptoFastKey
	{
		friend class CCryptoFast;

	private:
		// ��ĪŰ
		ByteArray m_key;

	public:
		CCryptoFastKey();
		~CCryptoFastKey();

		/**
		\~korean
		Fast Ű ���̸� ���ɴϴ�. (byte)
		\return Fast Ű ����

		\~english
		Gets length of Fast key. (byte)
		\return Fast key length

		\~chinese
		?��Fast key?������byte��
		\return Fast key?��

		\~japanese
		Fast ��?����������ƪ��ު���(byte)
		\return Fast ��?������
		\~
		*/
		int GetKeyLength() const;


		/**
		\~korean
		Ű�� �̹� �����Ǿ������� Ȯ���մϴ�.

		\~english
		Check key is already existed or not.

		\~chinese
		??key�����?��������

		\~japanese
		��?��?����������ƪ��몫�����㪷�ު���
		\~
		*/
		bool KeyExists() const;

		void Clear();
	};

	// �ſ� �ܼ��� ������ ��ȣȭ �˰���
	// ���� ��Ʈ��ŷ �޽����� ��� ��ȣȭ�� ū ���ϸ� ���� ������ŭ ������ �۵������� ���� ��ŷ���Ѵٴ� ������ �ִ�.
	// �ʺ����� ��Ŀ ������ �ɷ����� �뵵 ���� ���� �÷����� ��� �޽����� ��ȣȭ�ϴµ� ���̸� �ȴ�.
	class CCryptoFast
	{
	public:
		/**
		\~korean
		��ȣȭ�� ���Ǵ� Ű ��ü�� �����ϴ� �Լ��Դϴ�.
		\param outKey ������ ��ȣȭ Ű ��ü�� ����˴ϴ�.
		\param inputKey
		\param keyLength 16 or 24 or 32 bytes �Դϴ�.

		\~english
		\param outKey
		\param inputKey
		\param keyLength 16 or 24 or 32 bytes

		\~chinese
		\param outKey
		\param inputKey
		\param keyLength 16 or 24 or 32 bytes��
		

		\~japanese
		��?�����Ū��뫭?���֫������Ȫ���������??�Ǫ���
		\param outKey �������쪿��?����?���֫������Ȫ�������ު���
		\param inputKey
		\param keyLength 16 or 24 or 32 bytes �Ǫ���
		\~
		*/
		static bool ExpandFrom(CCryptoFastKey& outKey, const uint8_t* inputKey, int keyLength);

		/**
		\~korean
		\param key ��ĪŰ�Դϴ�.
		\param inputLength ��ȣȭ�� �������� ����
		\return ��ȣȭ�� �������� ����

		\~english
		\param key Symmetric key
		\param inputLength Size of plain text
		\return Size of Encrypted result

		\~chinese
		\param key ??key
		\param inputLength �ʥ����?��?��
		\return ʥ����?��?��

		\~japanese
		\param key ??��?�Ǫ���
		\param inputLength ��?�������?��������
		\return ��?�����쪿��?��������
		\~
		*/
		static int GetEncryptSize(int inputLength);

		/**
		\~korean
		�����͸� ��ȣȭ �մϴ�.
		\param key ��ĪŰ�Դϴ�.
		\param input �� �޽����Դϴ�.
		\param inputLength ���� �������Դϴ�.
		\param output ��ȣȭ�� ������Դϴ�.
		\param outputLength ��ȣȭ�� ����� �������Դϴ�.

		\~english
		Encrypt data
		\param key Symmetric key
		\param input Plain text message
		\param inputLength Size of plain text
		\param output Encrypted result value
		\param outputLength Size of Encrypted result

		\~chinese
		ʥ��?�ߡ�
		\param key ??key��
		\param input ٥�����ӡ�
		\param inputLength ٥�������
		\param output ʥ����?��?��
		\param outputLength ʥ����?����᳡�

		\~japanese
		��?������?�����ު���
		\param key ??��?�Ǫ���
		\param input ������ë�?���Ǫ���
		\param inputLength �����Ϋ������Ǫ���
		\param output ��?�����쪿̿�����Ǫ���
		\param outputLength ��?�����쪿̿���Ϋ������Ǫ���
		\~
		*/
		static bool Encrypt(
			const CCryptoFastKey& key,
			const uint8_t* input,
			int inputLength,
			uint8_t *output,
			int& outputLength,
			ErrorInfoPtr& errorInfo
			);

		/**
		\~korean
		�����͸� ��ȣȭ �մϴ�.
		\param key ��ĪŰ �Դϴ�.
		\param input ��ȣȭ�� �޽����Դϴ�.
		\param inputLength ��ȣȭ�� �޽����� �������Դϴ�.
		\param output ��ȣȭ�� ����� �Դϴ�.
		\param outputLength ��ȣȭ�� ������� �������Դϴ�.

		\~english
		Decrypt data
		\param key Symmetric key
		\param input Encrypted message
		\param inputLength Size of Encrypted message
		\param output Decrypted result value
		\param outputLength Size of Decrypted text

		\~chinese
		��??�ߡ�
		\param key ??key��
		\param input ʥ�������ӡ�
		\param inputLength ʥ�����������
		\param output ??��?��?��
		\param outputLength ??��?����᳡�

		\~japanese
		��?������?�����ު���
		\param key ??��?�Ǫ���
		\param input ��?�����쪿��ë�?���Ǫ���
		\param inputLength ��?�����쪿��ë�?���Ϋ������Ǫ���
		\param output ��?�����쪿̿�����Ǫ���
		\param outputLength ��?�����쪿̿�����Ϋ������Ǫ���
		\~
		*/
		static bool Decrypt(
			const CCryptoFastKey& key,
			const uint8_t* input,
			int inputLength,
			uint8_t *output,
			int& outputLength,
			ErrorInfoPtr& errorInfo
			);

		/**
		\~korean
		ByteArray�� ��ȣȭ �մϴ�.
		\param key ��ĪŰ�Դϴ�.
		\param input �� �޽����Դϴ�.
		\param output ��ȣȭ�� ������Դϴ�.

		\~english
		Encrypt ByteArray
		\param key Symmetric key
		\param input Plain text message
		\param output Encrypted result value

		\~chinese
		ʥ�� ByteArray��
		\param key ??key��
		\param input ٥�����ӡ�
		\param output ʥ����?��?��

		\~japanese
		ByteArray����?�����ު���
		\param key ??��?�Ǫ���
		\param input ������ë�?���Ǫ���
		\param output ��?�����쪿̿�����Ǫ���
		
		\~
		*/
		static bool EncryptByteArray(
			const CCryptoFastKey& key,
			const ByteArray& input,
			ByteArray& output,
			ErrorInfoPtr& errorInfo
			);

		/**
		\~korean
		ByteArray�� ��ȣȭ �մϴ�.
		\param key ��ĪŰ �Դϴ�.
		\param input ��ȣȭ�� �޽����Դϴ�.
		\param output ��ȣȭ�� ����� �Դϴ�.

		\~english
		Decrypt ByteArray
		\param key Symmetric key
		\param input Encrypted message
		\param output Decrypted result value

		\~chinese
		��? ByteArray��
		\param key ??key��
		\param input ʥ�������ӡ�
		\param output ��?��?��?��

		\~japanese
		ByteArray����?�����ު���
		\param key ??��?�Ǫ���
		\param input ��?�����쪿��ë�?���Ǫ���
		\param output ��?�����쪿̿�����Ǫ���
		\~
		*/
		static bool DecryptByteArray(
			const CCryptoFastKey& key,
			const ByteArray& input, 
			ByteArray& output,
			ErrorInfoPtr& errorInfo
			);

		/**
		\~korean
		Message�� ��ȣȭ �մϴ�.
		\param key ��ĪŰ�Դϴ�.
		\param input �� �޽����Դϴ�.
		\param output ��ȣȭ�� ������Դϴ�.
		\param offset �� �޽������� ��ȣȭ�� ������ ��ġ

		\~english
		Encrypt Message
		\param key Symmetric key
		\param input Plain text message
		\param output Encrypted result value
		\param offset Encrypt start position at plain text message

		\~chinese
		ʥ��Message��
		\param key ??key��
		\param input ٥�����ӡ�
		\param output ʥ����?��?��
		\param offset �٥������?�ʥ�������ǡ�

		\~japanese
		Message����?�����ު���
		\param key ??��?�Ǫ���
		\param input ������ë�?���Ǫ���
		\param output ��?�����쪿̿�����Ǫ���
		\param offset ������ë�?������?������㷪�������
		\~
		*/
		static bool EncryptMessage(
			const CCryptoFastKey& key,
			const CMessage& input,
			CMessage& output,
			int offset,
			ErrorInfoPtr& errorInfo
			);

		/**
		\~korean
		Message�� ��ȣȭ �մϴ�.
		\param key ��ĪŰ �Դϴ�.
		\param input ��ȣȭ�� �޽����Դϴ�.
		\param output ��ȣȭ�� ����� �Դϴ�.
		\param offset ��ȣȭ�� �޽������� ��ȣȭ�� ������ ��ġ

		\~english
		Decrypt Message
		\param key Symmetric key
		\param input Encrypted message
		\param output Decrypted result value
		\param offset Decrypt start position at encrypted message

		\~chinese
		��?Message��
		\param key ??key��
		\param input ʥ�������ӡ�
		\param output ��?��?��?��
		\param offset �ʥ������?���?�����ǡ�

		\~japanese
		Message����?�����ު���
		\param key ??��?�Ǫ���
		\param input ��?�����쪿��ë�?���Ǫ���
		\param output ��?�����쪿̿�����Ǫ���
		\param offset ��?�����쪿��ë�?������?������㷪�������
		\~
		*/
		static bool DecryptMessage(
			const CCryptoFastKey& key,
			const CMessage& input,
			CMessage& output,
			int offset,
			ErrorInfoPtr& errorInfo
			);
	};
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif