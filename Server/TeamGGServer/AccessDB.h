#pragma once



//class TGDB_Delegate : public IDbCacheServerDelegate2
//{
//public:
//	void prepareDBCacheServer();
//
//	void GetTestData(CCallbackArgs& args);
//protected:
//	CAutoPtr<CDbCacheServer2> m_db2Server;
//
//	virtual void OnException(const Exception& e) PN_OVERRIDE;
//	virtual void OnError(ErrorInfo *errorInfo) PN_OVERRIDE;
//	virtual void OnWarning(ErrorInfo *errorInfo) PN_OVERRIDE;
//
//	CCachedTableName m_gamerTable;
//	bool TrialStartDbServer(String dbmsConnectionString, String &outErrMsg);
//private:
//
//};
//

class DBConnector
{
public:
	DBConnector();
	void ConnectDB();
	void executeQuery();
protected:
	CCoInitializer coi;
	Proud::CAdoConnection just_conn;

};