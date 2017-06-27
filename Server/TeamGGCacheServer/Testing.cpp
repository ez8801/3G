#include <iostream>
//#include "../include/ProudNetServer.h"
#include "../include/ProudDB.h"
using namespace std;
using namespace Proud;
String g_DbAuthKey = L"This is the test.";
String g_DbmsConnectionString = L"Driver={MySQL ODBC 5.1 Driver};Server=127.0.0.1;UID=soongsae;PWD=soongsae9016!;DB=ProudDB2-Test;Port=3306";


class cacheDbClass : public IDbCacheServerDelegate2
{
public:
	cacheDbClass();
protected:
	CAutoPtr<CDbCacheServer2> m_db2Server;

	CCachedTableName m_gamerTable;
	virtual void OnException(const Exception& e) PN_OVERRIDE;
	virtual void OnError(ErrorInfo *errorInfo) PN_OVERRIDE;
	virtual void OnWarning(ErrorInfo *errorInfo) PN_OVERRIDE;
	bool TrialStartDbServer(String dbmsConnectionString, String &outErrMsg);
};
cacheDbClass::cacheDbClass()
{
	CoInitialize(NULL);
	m_db2Server.Attach(CDbCacheServer2::New());
	String errMsg;
	if (!TrialStartDbServer(g_DbmsConnectionString, errMsg))
	{
		exit(0);
	}
	else
	{
		exit(0);
	}
}
void cacheDbClass::OnException(const Exception& e)
{
	String txt;
	txt.Format(L"%s occured at %s", StringA2W(e.what()).GetString(), __FUNCTIONW__);
	//LogEvent(txt.GetString());
}

void cacheDbClass::OnError(ErrorInfo *errorInfo)
{
	String txt;
	txt.Format(L"%s occured at %s", errorInfo->ToString().GetString(), __FUNCTIONW__);
	//LogEvent(txt.GetString());
}

void cacheDbClass::OnWarning(ErrorInfo *errorInfo)
{
	String txt;
	txt.Format(L"%s occured at %s", errorInfo->ToString().GetString(), __FUNCTIONW__);
	//LogEvent(txt.GetString());
}

bool cacheDbClass::TrialStartDbServer(String dbmsConnectionString, String &outErrMsg)
{
	CDbCacheServer2StartParameter p1;
	p1.m_authenticationKey = g_DbAuthKey;
	p1.m_DbmsConnectionString = g_DbmsConnectionString;
	p1.m_delegate = this;
	p1.m_serverIP = L"localhost";
	p1.m_tcpPort = 33940;
	p1.m_allowNonExclusiveAccess = true;

	m_gamerTable.m_rootTableName = L"Gamer";
	m_gamerTable.m_childTableNames.Add(L"Hero");
	m_gamerTable.m_childTableNames.Add(L"Item");
	m_gamerTable.m_childTableNames.Add(L"Friend");

	// 서버 시작시 부모와자식 테이블의 이름을 추가합니다.
	// 주의~!! 이걸 해야 stored procedure 를 DBMS에 생성하기때문에 꼭 해야합니다.
	// 이름이 DBMS에 있는 테이블 이름과 틀리다면 exception이 발생합니다. 단 Start를 try catch로 잡아야합니다.

	// When you start server, adds name of parents and child table.
	// Warning~!! It only creates stored procedure to DBMS when you do it.
	// If name is different than table name in DBMS, it occurs exception. Start has to catch with try catch.
	p1.m_tableNames.Add(m_gamerTable);

	try
	{
		m_db2Server->Start(p1);
	}
	catch (std::exception &e)
	{
		outErrMsg = StringA2W(e.what());
		return false;
	}
	return true;
}

int main(void)
{
	cacheDbClass abd;
	return 0;
}