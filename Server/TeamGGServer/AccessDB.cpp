#include "Common.h"

String g_DbmsConnectionString = L"Driver={MySQL ODBC 5.1 Driver};Server=121.131.147.109;UID=soongsae;PWD=soongsae9016!;DB=ProudDB2-Test;Port=3306";
String g_DbmsConnectionString2 = L"Driver={MySQL ODBC 5.1 Driver};server = 121.131.147.109; port = 3306; Database = ProudDB2-Test;User ID = soongsae; Password = soongsae9016!";
String g_DbAuthKey = L"This is the test.";


DBConnector::DBConnector()
{

}

void DBConnector::ConnectDB()
{
	Proud::CAdoConnection conn;
	conn.Open(L"Driver={MySQL ODBC 5.1 Driver};server = 121.131.147.109; port = 3306; Database = ProudDB2-Test;User ID = soongsae; Password = soongsae9016!");
	//just_conn.Open(g_DbmsConnectionString2,MySql);
	conn.BeginTrans();  // Ʈ����� ����  ����!!Provider �� ����� ��� Ʈ����� �������� ����.
	int Val = 3;
	
	conn.CommitTrans();  // Ʈ����� Commit
}
void DBConnector::executeQuery()
{
	Proud::CAdoConnection conn;
	Proud::CAdoRecordset rs;
	rs.Open(conn,OpenForReadWrite,L"select * from friend ");
    
    while(rs.IsEOF() == false)
    {
        String a = rs.FieldValues[L"UUID"];
		cout << a.c_str() << endl;
        rs.MoveNext();
    }

}
//void TGDB_Delegate::prepareDBCacheServer()
//{
//	m_db2Server.Attach(CDbCacheServer2::New());
//	puts("prepare DB Cache Server Success \n");
//}
//bool TGDB_Delegate::TrialStartDbServer(String dbmsConnectionString, String &outErrMsg)
//{
//	CDbCacheServer2StartParameter p1;
//	p1.m_authenticationKey = g_DbAuthKey;
//	p1.m_DbmsConnectionString = g_DbmsConnectionString;
//	p1.m_delegate = this;
//	p1.m_serverIP = L"localhost";
//	//p1.m_tcpPort = g_DbServerPort;
//	p1.m_allowNonExclusiveAccess = true;
//
//	m_gamerTable.m_rootTableName = L"Gamer";
//	m_gamerTable.m_childTableNames.Add(L"Hero");
//	m_gamerTable.m_childTableNames.Add(L"Item");
//	m_gamerTable.m_childTableNames.Add(L"Friend");
//
//	// ���� ���۽� �θ���ڽ� ���̺��� �̸��� �߰��մϴ�.
//	// ����~!! �̰� �ؾ� stored procedure �� DBMS�� �����ϱ⶧���� �� �ؾ��մϴ�.
//	// �̸��� DBMS�� �ִ� ���̺� �̸��� Ʋ���ٸ� exception�� �߻��մϴ�. �� Start�� try catch�� ��ƾ��մϴ�.
//
//	// When you start server, adds name of parents and child table.
//	// Warning~!! It only creates stored procedure to DBMS when you do it.
//	// If name is different than table name in DBMS, it occurs exception. Start has to catch with try catch.
//	p1.m_tableNames.Add(m_gamerTable);
//
//	try
//	{
//		m_db2Server->Start(p1);
//	}
//	catch (std::exception &e)
//	{
//		outErrMsg = StringA2W(e.what());
//		return false;
//	}
//	return true;
//}
//
//void TGDB_Delegate::OnException(const Exception& e)
//{
//	String txt;
//	txt.Format(L"%s occured at %s", StringA2W(e.what()).GetString(), __FUNCTIONW__);
//	
//}
//
//void TGDB_Delegate::OnError(ErrorInfo *errorInfo)
//{
//	String txt;
//	txt.Format(L"%s occured at %s", errorInfo->ToString().GetString(), __FUNCTIONW__);
//	
//}
//
//void TGDB_Delegate::OnWarning(ErrorInfo *errorInfo)
//{
//	String txt;
//	txt.Format(L"%s occured at %s", errorInfo->ToString().GetString(), __FUNCTIONW__);
//	
//}
