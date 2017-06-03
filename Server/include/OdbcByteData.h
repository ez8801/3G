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

// Linux���� ODBC�� ���� ������ ODBC for unix�� ��Ÿ�� ��ġ�Ͻʽÿ�.
// ��: sudo apt-get install unixodbc-dev
#include <sqltypes.h>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/**
	 \~korean
	 ODBC API�� ���� �����͸� ������Ҷ� ���˴ϴ�.
	 ���� �����Ͱ� ��ġ�� �ſ� ū ���, ������ ����� �������� ���ʿ��� ���� ������ �����ϱ� ���� �� Ŭ������ ���˴ϴ�.
	 ����ڰ� ���� �����͸� ���� �����ؾ� �ϰ�, �� Ŭ������ �� �����͸� �����ϴ� ������ �մϴ�.

	 \~english
	 It is used for input & output of binary data at ODBC API.
	 If the size of binary data is too big, this class will be used to omit unnecessary copy process in the process of data input & output. 
	 A user must possess binary data and this class refers to the data. 

	 \~chinese
	 �ODBC API?�����?�?��?���ġ�
	 �?�?����ު����?��?���?����?����?���������������?�?�����?class��
	 ��??��������?�?�ߣ��?class����?��??�������ġ�

	 \~japanese
	 ODBC API�˫ѫ��ʫ��?��������������������Ū��ު���
	 �ѫ��ʫ��?���Ϋ���������?�ު������ꡢ��?��������Φ�������驪ʫ���?Φ������Ԫ��몿��˪��Ϋ��髹�����Ī���ު���
	 ��?��?���ѫ��ʫ��?����������󪹪���驪����ꡢ���Ϋ��髹�Ϫ��Ϋ�?����?�Ϊ�����ܪ򪷪ު���

	 \~
	 */
	class COdbcByteData
	{
	private:
		// ����ڰ� ������� ���� �� �� ���� ���� �Դϴ�.
		// dataPtr�� ������ ����� ������ ���� ���δ� ������� ������ �� ������ �� ��ü ��ü(�����Ͱ�)�� ����Ǹ� �ȵ˴ϴ�.
		// ��ü�� ������� ���ϱ� ������ maxLen�� �ѹ� �����ϸ� �ٲ��� ���մϴ�.
		SQLCHAR* m_dataPtr;

		SQLLEN m_dataLength;
		SQLULEN m_maxLength;

	public:
		/**
		 \~korean
		 ������ �Լ�. ���⼭ ����ڰ� ���� �ִ� ���� �������� �ּҿ� ũ�⸦ �Է��Ͻʽÿ�.
		 \param pData ���� �������� �ּ�
		 \param dataLength ���� �������� ��ȿ�� ���� ũ���Դϴ�
		 \param maxLength ���� �����Ͱ� ����Ǵ� �ִ� ũ��

		 \~english
		 Constructor function. Please input the size & address of binary data that a user has. 
		 \param pData Address of binary data.
		 \param dataLength Current valid size of binary data. 
		 \param maxLength Maximum size of binary data saving.

		 \~chinese
		 ����� ��?����?����?���?�?����������᳡�
		 \param pData �?�?������
		 \param dataLength �?�?����?��������᳡�
		 \param maxLength �?�?��ʦ����������������

		 \~japanese
		 �����??�������ǫ�?��?���êƪ���ѫ��ʫ��?���Ϋ��ɫ쫹�ȫ��������������ƪ���������
		 \param pData �ѫ��ʫ��?���Ϋ��ɫ쫹
		 \param dataLength �ѫ��ʫ��?������?����������Ǫ���
		 \param maxLength �ѫ��ʫ��?������?�֪�������ޫ�����

		 \~
		 */
		COdbcByteData(SQLCHAR* pData, SQLLEN dataLength, SQLULEN maxLength);

		/**
		 \~korean
		 ������ �������� �ּҸ� ���� �ɴϴ�.

		 \~english
		 Get the data address that has been set. 

		 \~chinese
		 ?���?����?���򣡣

		 \~japanese
		 ���Ҫ��쪿��?���Ϋ��ɫ쫹���?�ɪ��ު���

		 \~
		 */
		SQLCHAR* GetDataPtr();

		/**
		 \~korean
		 ������ �������� ũ�⸦ ���� �ɴϴ�.

		 \~english
		 Get the data size that has been set. 

		 \~chinese
		 ?���?����?����᳡�

		 \~japanese
		 ���Ҫ��쪿��?���Ϋ��������?�ɪ��ު���.

		 \~
		 */
		SQLLEN GetDataLength();

		/**
		 \~korean
		 �������� ũ�⸦ �������մϴ�.
		 �����ڿ��� ������ ����� ������ ���۸� �����Ͽ��� �� �װ��� ���̰� �ٲ�� �� �Լ��� ȣ���Ͽ� ũ�⸦ �����ؾ� �մϴ�.

		 \~english
		 Readjust the size of data.
		 If the length of data buffer changes when modifying data buffer that has been set by a constructor, you will be required to change the size by calling this function. 

		 \~chinese
		 ����?��?����᳡�
		 ����������������??��buffer?������??�������?�����������??�����?�ڡ�

		 \~japanese
		 ��?���Ϋ�����������ڪ��ު���
		 ��������Ҫ�����?��?��?���Ыëի�?�����᪷���Ȫ��������������?���Ȫ���??�������󪷡���������?�ڪ�����驪�����ު���

		 \~
		 */
		void SetDataLength(SQLLEN dataLength);

		/**
		 \~korean
		 ������ �������� �ִ� ũ�⸦ ����ϴ�.

		 \~english
		 Obtain the maximum size of data. 

		 \~chinese
		 ?���?��?��������?��

		 \~japanese
		 ���Ҫ��쪿��?�������ޫ����������𪷪ު���

		 \~
		 */
		SQLULEN GetMaxLength();

	private:
		// ���� ����
		COdbcByteData(const COdbcByteData& other);
		COdbcByteData& operator=(const COdbcByteData& other);
	};
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif