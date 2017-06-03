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

#include <sqltypes.h>

#include "Exception.h"
#include "FastArray.h"
#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/**
	 \~korean
	 ODBC�� �ͼ��� ó���� ���� Ŭ�����Դϴ�.
	 what() �Լ��� �̿��Ͽ� �� ������ Ȯ���� �� �ֽ��ϴ�.

	 \~english
	 It is a class that deals with ODBC exception. 
	 You can check the detailed information by what() function. 

	 \~chinese
	 ?��ODBC?����class��
	 ��?what()��?ʦ�?????黡�

	 \~japanese
	 ODBC��exception?��Ϊ���Ϋ��髹�Ǫ���
	 what() ??�����Ī������?黪�����Ǫ��ު���

	 \~
	 */
	class COdbcException: public Exception
	{
	protected:
		SQLRETURN m_ret;

	public:
		COdbcException();
		COdbcException(const SQLRETURN ret, const StringA& errorString);

		/**
		 \~korean
		 sql.h�� sqlext.h�� ���ǵ� return value�� ��ȯ �մϴ�.

		 \~english
		 It returns the return value that has been defined in sql.h or sqlext.h.

		 \~chinese
		 ��?�sql.h�� sqlext.h��?��return value��

		 \~japanese
		 sql.h��sqlext.h���������쪿return value���������ު���

		 \~
		 */
		int GetSqlErrorCode();

		COdbcException(const COdbcException& other);
		COdbcException& operator=(const COdbcException& other);
	};

	/**
	 \~korean
	 SqlErrorCode�� SQL_SUCCESS_WITH_INFO�� ��� Warning Exception�� �߻��մϴ�.
	 �ش� �ͼ����� �⺻������ �����ص� ��������� �߿��� ������ ����ִ� ��쵵 �����Ƿ� �����ؾ� �մϴ�.
	 ex> Warning �߻� ��
	 1. MSSQL�� ��� ����ϴ� �����ͺ��̽�(��Ű��)�� ����Ǵ� ��쿡 ����Ǿ��ٴ� �˸��� ���� �߻�
	 2. Insert�� Primary Key�� �ߺ��� �������� ��� �߻�(Primary Key Duplicate Error)

	 \~english
	 In case SqlErrorCode is SQL_SUCCESS_WITH_INFO, Warning Exception will occur. 
	 It does not matter if you ignore this exception, but it contains important information, so you should take extra caution. 
	 ex> Example of Warning Occurrence
	 1. In case of MSSQL, when the database (schema) is changed, warning will occur.
	 2. In case primary keys are duplicated when inserting, warning will occur. (Primary Key Duplicate Error)

	 \~chinese
	 SqlErrorCode�� SQL_SUCCESS_WITH_INFO����?��?�� Warning Exception��
	 ������?����???���?������??��ӣ��������������?���������
	 ex> Warning ?�� ��
	 1. . MSSQL����?��������?��??��?��?���?���?�档
	 2. Insert�� Primary Key?��??��??��(Primary Key Duplicate Error)

	 \~japanese
	 SqlErrorCode��SQL_SUCCESS_WITH_INFO������Warning Exception��?�檷�ު���
	 ��?exception�������ܪ����ʪ��ƪ�ϰ���ު��󪬡���驪����ê��ߪ�ƪ�������⪢�몿�᪴��򪯪�������
	 ex> Warning ?�����
	 1. MSSQL�����ꡢ���Ī��ƪ����?����?��������?�ޣ���?�ڪ���������?�ڪΪ��骻�Ϊ���?��
	 2. Insert��Primary Key�����ܪ��쪿��?��������?��(Primary Key Duplicate Error)

	 \~
	 */
	class COdbcWarning: public COdbcException
	{
	public:
		COdbcWarning();
		COdbcWarning(const SQLRETURN ret, const StringA& errorString);

		COdbcWarning(const COdbcWarning& other);
		COdbcWarning& operator=(const COdbcWarning& other);
	};

	typedef CFastArray<COdbcWarning> COdbcWarnings;
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif