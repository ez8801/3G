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
	conn.BeginTrans();  // 트랜잭션 시작  주의!!Provider 를 사용할 경우 트랜잭션 지원하지 않음.
	int Val = 3;
	
	conn.CommitTrans();  // 트랜잭션 Commit
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
//	// 서버 시작시 부모와자식 테이블의 이름을 추가합니다.
//	// 주의~!! 이걸 해야 stored procedure 를 DBMS에 생성하기때문에 꼭 해야합니다.
//	// 이름이 DBMS에 있는 테이블 이름과 틀리다면 exception이 발생합니다. 단 Start를 try catch로 잡아야합니다.
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
