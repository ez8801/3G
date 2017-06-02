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

#include "OdbcEnum.h"
#include "OdbcException.h"
#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class COdbcHandle;
	class COdbcRecordset;
	class COdbcConnectionImpl;

	/**
	 \~korean
	 Connection ������ Transaction ����, DirectExecute�� ������ �� �ִ� Ŭ���� �Դϴ�.
	 ODBC �Ŵ����� ���� ����Ͻô� �����ͺ��̽��� ����̹��� ����Ͽ� �ش� DSN(Data Source Name)�� ���� �����Ͻø� �˴ϴ�.

	 \~english
	 It is a class that can manage Connection, control Transaction and execute DirectExecute.
	 Register a driver of database that you are using by the ODBC manager and access through DSN(Data Source Name).

	 \~chinese
	 ʦ?��Connection η�⣬ Transaction ���, DirectExecute ��class��
	 ��? ODBCη�⣬�?������?��?driver����??DSN(Data Source Name)???ʦ��

	 \~japanese
	 Connection η��� Transaction ����ȫ�?�롢DirectExecute��?���Ǫ��뫯�髹�Ǫ���
	 ODBC�ޫ�?����?���ת������Ī����?����?���Ϋɫ髤��?����?������?DSN(Data Source Name)���ת������Ϊ��ƪ���������

	 \~
	 */
	class COdbcConnection
	{
	public:
		COdbcConnection();
		~COdbcConnection();

		/**
		 \~korean
		 �����ͺ��̽��� ������ �� ����մϴ�.

		 \~english
		 It is used when connecting to the database. 

		 \~chinese
		 ?��?��??���ġ�

		 \~japanese
		 ��?����?����֧̿����Ȫ������Ī��ު���

		 \~
		 */
		void Open(const String& dsn, const String& id, const String& passwd, COdbcWarnings* odbcWarnings = NULL);

		/**
		 \~korean
		 �����ͺ��̽��� ������ �� ����մϴ�.
		 ex> conn.Open("DSN=MsSqlDsn;UID=root;PWD=1234")

		 \~english
		 It is used when connecting to the database. 
		 ex> conn.Open("DSN=MsSqlDsn;UID=root;PWD=1234")

		 \~chinese
		 ?��?��??���ġ�
		 ex> conn.Open("DSN=MsSqlDsn;UID=root;PWD=1234").

		 \~japanese
		 ��?����?����֧̿����Ȫ������Ī��ު���
		 ex> conn.Open("DSN=MsSqlDsn;UID=root;PWD=1234")

		 \~
		 */
		void Open(const String& connectionString, COdbcWarnings* odbcWarnings = NULL);

		/**
		 \~korean
		 ������ ������ �� ����մϴ�.
		 �� Ŀ�ؼ��� ���� ������ ��� COdbcCommand, COdbcRecordset ��ü���� ������ ��Ĩ�ϴ�.

		 \~english
		 It is used when disconnection.
		 It has an effect on all COdbcCommand objects and COdbcRecordset objects that have been created by this connection. 

		 \~chinese
		 ?��?��?���ġ�
		 ?�?�������?�?�������� COdbcCommand, COdbcRecordset ?�ڡ�

		 \~japanese
		 ֧̿����������Ȫ������Ī��ު���
		 ���Ϋ��ͫ��������ת����������쪿��ƪ�COdbcCommand, COdbcRecordset���֫������Ȫ���ª�?���ު���

		 \~
		 */
		void Close();

		/**
		 \~korean
		 Ʈ������� ������ �� ����մϴ�.
		 RollbackTrans() �̳� CommitTrans()�� �����Ͽ� Ʈ������� �����ϸ� �ٽ� ȣ���ؾ� ���� �˴ϴ�.

		 \~english
		 It is used when starting transaction. 
		 In case transaction ends by executing RollbackTrans() or CommitTrans(), it is applied only when re-calling. 

		 \~chinese
		 Transaction?�?���ġ�
		 ��??�� RollbackTrans() �� CommitTrans()?��Transaction?��������������������ġ�

		 \~japanese
		 �ȫ�󫶫�������㷪ު��������Ī��ު���
		 RollbackTrans() �� CommitTrans()��?�������ȫ�󫶫������������������ꡢ���ĪΪ���˪Ϫ⪦������������驪�����ު���

		 \~
		 */
		void BeginTrans();

		/**
		 \~korean
		 Ʈ������� Rollback�� �� ����մϴ�.

		 \~english
		 It is used when transaction rollback. 

		 \~chinese
		 Rollback Transaction?���ġ�

		 \~japanese
		 �ȫ�󫶫�������Rollback�����������Ī��ު���

		 \~
		 */
		void RollbackTrans();

		/**
		 \~korean
		 Ʈ������� Commit�� �� ����մϴ�.

		 \~english
		 It is used when committing transaction. 

		 \~chinese
		 Transaction Commit ?���ġ�

		 \~japanese
		 �ȫ�󫶫�������Commit�����������Ī��ު���

		 \~
		 */
		void CommitTrans();

		/**
		 \~korean
		 �����ͺ��̽��� ���� ���������� Ȯ���� �� ����մϴ�.

		 \~english
		 It is used when checking if connection to the database is normal. 

		 \~chinese
		 ???�����??��??��?���ġ�

		 \~japanese
		 ���?����?����֧̿��Ǫ��몫���㪹��Ȫ������Ī��ު���

		 \~
		 */
		bool IsOpened();

		/**
		 \~korean
		 ���̷�Ʈ ������ �����մϴ�.
		 ���� �������� ������ ���� Row ������ ��ȯ�մϴ�.
		 \param query ������

		 \~english
		 It executed a direct query.
		 \param query It is a query.

		 \~chinese
		 ?�� direct query��
		 \param query query���졣

		 \~japanese
		 �����쫯�ȫ�����?��?�����ު���
		 \param query ������?��

		 \~
		 */
		int Execute(const String& query, COdbcWarnings* odbcWarnings = NULL);

		/**
		 \~korean
		 ���̷�Ʈ ������ �����մϴ�.
		 ���� �������� ������ ���� Row ������ ��ȯ�մϴ�.
		 \param recordset SELECT ���� ���� �� �޾����� Recordset ��ü
		 \param query ������

		 \~english
		 It executed a direct query.
		 \param recordset It is a Recordset object that is received when executing SELECT query.
		 \param query It is a query.

		 \~chinese
		 ?�� direct query ��
		 \param recordset SELECT query ?��?������� Recordset ?�ڡ�
		 \param query query����

		 \~japanese
		 �����쫯�ȫ�����?��?�����ު���
		 \param recordset SELECT ������??������?�ɪ����Recordset���֫�������
		 \param query ������?��

		 \~
		 */
		int Execute(COdbcRecordset &recordset, const String& query, COdbcWarnings* odbcWarnings = NULL);

		// WARNING::���ο��� ���Ǵ� �Լ��Դϴ�. ������� ���ñ� �ٶ��ϴ�.
		// WARNING::Internal use only. Don't use this function.
		void AllocStmtHandle(COdbcHandle* hstmt, OdbcPrepareType typem, COdbcWarnings* odbcWarnings = NULL);

	private:
		COdbcConnectionImpl* m_pImpl;

		COdbcConnection(const COdbcConnection& other);
		COdbcConnection& operator=(const COdbcConnection& other);
	};

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif