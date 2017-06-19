#include "Packet.h"
#include "../TeamGGCommon/C2S_stub.cpp"
#include "../TeamGGCommon/S2C_proxy.cpp"
#include "../TeamGGCommon/C2S_common.cpp"
#include "../TeamGGCommon/S2C_common.cpp"
DEFRMI_C2S_Chat(C2SStub)
{
	cout << "[Server] chat message received :";
	cout << " a=" << string(a);
	cout << " b=" << b;
	cout << " c=" << c;
	cout << endl;

	// Echo chatting message which received from server to client.
	ServerManager *manager;
	manager = ServerManager::getInstance();
	manager->getS2CProxy().ShowChat(remote, RmiContext::ReliableSend, a, b + 1, c + 1);
	return true;
}

DEFRMI_C2S_Login(C2SStub)
{
	cout << "[Login Request] id : << " << string(id) << " password : " << string(password) << endl;

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

S2C::Proxy ServerManager::getS2CProxy()
{
	return this->m_S2CProxy;
}
C2SStub ServerManager::getC2SStub()
{
	return this->m_C2SStub;
}

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