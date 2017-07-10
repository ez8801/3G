#include "Packet.h"
#include "../TeamGGCommon/C2S_stub.cpp"
#include "../TeamGGCommon/S2C_proxy.cpp"
#include "../TeamGGCommon/C2S_common.cpp"
#include "../TeamGGCommon/S2C_common.cpp"
//�۷ι��� ����� g_S2CProxy����
S2C::Proxy g_S2CProxy;
DEFRMI_C2S_Chat(C2SStub)
{
	cout << "[Server] chat message received :";
	cout << " a=" << string(a);
	cout << " b=" << b;
	cout << " c=" << c;
	cout << endl;

	// Echo chatting message which received from server to client.
	//ServerManager *manager;
	//manager = ServerManager::getInstance();
	g_S2CProxy.ShowChat(remote, RmiContext::ReliableSend, a, b + 1, c + 1);
	return true;
}
DEFRMI_C2S_RequestMakeRaidRoom(C2SStub)
{
	cout << HostId << endl;
	ServerManager *manager;
	manager = ServerManager::getInstance();

	HostIDArray arr;
	arr.Add(HostId);

	manager->srv->CreateP2PGroup(arr.GetData(), arr.Count, ByteArray());
	return true;
}

DEFRMI_C2S_Login(C2SStub)
{
	cout << "[Login Request] id : << " << string(id) << " password : " << string(password) << endl;
	items test[10];
	Proud::CFastArray<items> cfasttest;

	for (int i = 0; i < 10; i++)
	{
		test[i].itemIdx = i;
		test[i].itemInherentIdx = i;
		test[i].itemType = i;
		cfasttest.Add(test[i]);
	}
	//ServerManager *manager;
	//manager = ServerManager::getInstance();
	//manager->getS2CProxy()
	CAdoConnection conn;
	CAdoRecordset rec;
	try
	{
		conn.Open(L"Driver={MySQL ODBC 5.1 Driver};Server=127.0.0.1;UID=soongsae;PWD=soongsae9016!;DB=team3g-db;Port=3306", DbmsType::MySql);

		//conn.Open(L"Driver={MySQL ODBC 5.1 Driver};server = 127.0.0.1; port = 3306; Database = friend;User ID = soongsae; Password = soongsae9016!; ");

		wprintf(L"DB Connect Succeed!!\n");
		if (!rec.IsOpened())
		{
			// ���Ϲ���  recordset ��ü�� ���� ����� ���ٰ���
			// Has to open recordset object to access it
			rec.Open(conn, OpenForRead, String::NewFormat(L"select * from UserAccount where id = '%s' and password= '%s'", id, password));
			if (rec.IsEOF() == true)
			{
				//���̵� ����� ����.
				wprintf(L"don't have record set \n");
			}
			else
			{
				//�α��� ���� �����͸� �ҷ��´�.
				wprintf(L"login success\n");
			}
		}


	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	
	g_S2CProxy.sendInventoryData(remote, RmiContext::ReliableSend, cfasttest);
	return true;
}
ServerManager* ServerManager::S2CInstance = nullptr;
ServerManager::ServerManager()
{
	m_groupHostID = HostID_None;
	m_lastClientID = HostID_None;
	srv = CNetServer::Create();
};
ServerManager* ServerManager::getInstance()
{
	if (S2CInstance == NULL)
		S2CInstance = new ServerManager();
	return S2CInstance;
};

HostID ServerManager::getGroupHostID()
{
	return  this->m_groupHostID;
}
HostID ServerManager::getLastClientID()
{
	return this->m_lastClientID;
}

void ServerManager::setGroupHostID(HostID setHostID)
{
	this->m_groupHostID = setHostID;
}
void ServerManager::setLastClientHostID(HostID setLastClientID)
{
	this->m_lastClientID = setLastClientID;
}

///////////////////////////
// ADODB ��� ��      /////
/*
CAdoConnection conn;
CAdoRecordset rec;
try
{
	conn.Open(L"Driver={MySQL ODBC 5.1 Driver};Server=127.0.0.1;UID=soongsae;PWD=soongsae9016!;DB=ProudDB2-Test;Port=3306", DbmsType::MySql);

	//conn.Open(L"Driver={MySQL ODBC 5.1 Driver};server = 127.0.0.1; port = 3306; Database = friend;User ID = soongsae; Password = soongsae9016!; ");

	wprintf(L"DB Connect Succeed!!\n");

}
catch (AdoException &e)
{
	wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
}

try
{
	
}
catch (AdoException &e)
{
	wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
}
String strID, strPassword, strCountry;
while (rec.IsEOF() == false)
{
	strID = rec.FieldValues[L"UserID"];
	strPassword = rec.FieldValues[L"Password"];
	strCountry = rec.FieldValues[L"Country"];

	wprintf(L"UserID : %s, Password : %s, Country : %s\n", strID.GetString(), strPassword.GetString(), strCountry.GetString());

	// Ŀ���� ���������� �̵���Ų��.
	// Move a cursor to the next line.
	rec.MoveNext();
}
*/