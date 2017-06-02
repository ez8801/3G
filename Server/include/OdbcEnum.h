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

#include <sql.h>
#include <sqlext.h>
#include <sqlucode.h>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	// C++ ���� �νĵǴ� ������ Ÿ��.
	// SQL C Type ��ü.
	enum OdbcDataType
	{
		OdbcDataType_NULL 			= 0,	/* = Basic OdbcSqlDataType 		*/
		OdbcDataType_BOOL 			= 1,	/* = OdbcSqlDataType_BIT 		*/
		OdbcDataType_TCHAR 			= 2,	/* = OdbcSqlDataType_CHAR(Linux) or OdbcSqlDataType_WCHAR(Windows) 		*/
		OdbcDataType_SINT8 			= 3,	/* = OdbcSqlDataType_TINYINT 	*/
		OdbcDataType_UINT8 			= 4,	/* = OdbcSqlDataType_TINYINT 	*/
		OdbcDataType_SINT16 		= 5,	/* = OdbcSqlDataType_SMALLINT 	*/
		OdbcDataType_UINT16 		= 6,	/* = OdbcSqlDataType_SMALLINT 	*/
		OdbcDataType_SINT32 		= 7,	/* = OdbcSqlDataType_INTEGER 	*/
		OdbcDataType_UINT32 		= 8,	/* = OdbcSqlDataType_INTEGER 	*/
		OdbcDataType_SINT64 		= 9,	/* = OdbcSqlDataType_BIGINT 	*/
		OdbcDataType_UINT64 		= 10,	/* = OdbcSqlDataType_BIGINT 	*/
		OdbcDataType_FLOAT 			= 11,	/* = OdbcSqlDataType_FLOAT 		*/
		OdbcDataType_DOUBLE 		= 12,	/* = OdbcSqlDataType_DOUBLE 	*/
		OdbcDataType_STRING 		= 13,	/* = OdbcSqlDataType_VARCHAR(Linux) or OdbcSqlDataType_WVARCHAR(Windows)	*/
		OdbcDataType_BYTE 			= 14,	/* = OdbcSqlDataType_VARBINARY 	*/
		OdbcDataType_TIMESTAMP 		= 15	/* = OdbcSqlDataType_TIMESTAMP 	*/
	};

	// DB �ȿ��� �νĵǴ� ������ Ÿ��.
	// SQLTYPE ��ü.
	enum OdbcSqlDataType
	{
		// ����: �Ʒ� ������ ODBC �Լ��� ���� ���ȴ�. ���� assign�� ���� ���Ƿ� �ٲ��� �� ��.
		OdbcSqlDataType_UNKNOWN 		= SQL_UNKNOWN_TYPE,
		OdbcSqlDataType_CHAR 			= SQL_CHAR,				/* = SQL_C_CHAR */
		OdbcSqlDataType_VARCHAR 		= SQL_VARCHAR,			/* = SQL_C_CHAR */
		OdbcSqlDataType_LONGVARCHAR 	= SQL_LONGVARCHAR,		/* = SQL_C_CHAR */
		OdbcSqlDataType_WCHAR			= SQL_WCHAR,			/* = SQL_C_WCHAR */
		OdbcSqlDataType_WVARCHAR 		= SQL_WVARCHAR,			/* = SQL_C_WCHAR */
		OdbcSqlDataType_WLONGVARCHAR 	= SQL_WLONGVARCHAR,		/* = SQL_C_WCHAR */
		OdbcSqlDataType_BIT 			= SQL_BIT,				/* = SQL_C_BIT */
		OdbcSqlDataType_TINYINT 		= SQL_TINYINT,			/* = SQL_C_TINYINT */
		OdbcSqlDataType_SMALLINT 		= SQL_SMALLINT,			/* = SQL_C_SHORT */
		OdbcSqlDataType_INTEGER 		= SQL_INTEGER,			/* = SQL_C_LONG */
		OdbcSqlDataType_BIGINT 			= SQL_BIGINT,			/* = SQL_C_SBIGINT */
		OdbcSqlDataType_REAL 			= SQL_REAL,				/* = SQL_C_FLOAT */
		OdbcSqlDataType_FLOAT 			= SQL_FLOAT,			/* = SQL_C_DOUBLE */
		OdbcSqlDataType_DOUBLE 			= SQL_DOUBLE,			/* = SQL_C_DOUBLE */
		OdbcSqlDataType_NUMERIC			= SQL_NUMERIC,			/* = SQL_C_DOUBLE */
		OdbcSqlDataType_DECIMAL			= SQL_DECIMAL,			/* = SQL_C_DOUBLE */
		OdbcSqlDataType_BINARY 			= SQL_BINARY,			/* = SQL_C_BINARY */
		OdbcSqlDataType_VARBINARY 		= SQL_VARBINARY,		/* = SQL_C_BINARY */
		OdbcSqlDataType_LONGVARBINARY 	= SQL_LONGVARBINARY,	/* = SQL_C_BINARY */
		OdbcSqlDataType_DATE 			= SQL_DATE,				/* = SQL_C_TIMESTAMP */
		OdbcSqlDataType_TIME 			= SQL_TIME,				/* = SQL_C_TIMESTAMP */
		OdbcSqlDataType_TIMESTAMP 		= SQL_TIMESTAMP			/* = SQL_C_TIMESTAMP */
	};

	enum OdbcPrepareType
	{
		OdbcPrepareType_QUERY 	= 0,
		OdbcPrepareType_PROC 	= 1
	};
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif