#include "Packet.h"
#include "../TeamGGCommon/C2S_stub.cpp"
#include "../TeamGGCommon/S2C_proxy.cpp"
#include "../TeamGGCommon/C2S_common.cpp"
#include "../TeamGGCommon/S2C_common.cpp"
//글로벌로 선언된 g_S2CProxy변수
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
	g_S2CProxy.sendInventoryData(remote, RmiContext::ReliableSend, cfasttest);
	return true;
}
ServerManager* ServerManager::S2CInstance = nullptr;
ServerManager::ServerManager()
{
	m_groupHostID = HostID_None;
	m_lastClientID = HostID_None;
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

