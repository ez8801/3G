#pragma once
#ifndef __PACKET_H_
#define __PACKET_H_

#include "Common.h"
#include "mymarshaler.h"
#include "../TeamGGCommon/C2S_stub.h"
#include "../TeamGGCommon/S2C_proxy.h"

class C2SStub : public C2S::Stub
{
public:
	DECRMI_C2S_Chat;
	DECRMI_C2S_Login;
};


class ServerManager
{
private:
	static ServerManager *S2CInstance;
	C2SStub m_C2SStub;
	S2C::Proxy *m_S2CProxy;
	HostID m_groupHostID;
	HostID m_lastClientID ;
	ServerManager();
public:
	////////GET FUNC/////////
	S2C::Proxy& getS2CProxy();
	C2SStub getC2SStub();
	HostID getGroupHostID();
	HostID getLastClientID();


	///////SET FUNC//////////
	void setGroupHostID(Proud::HostID setHostID);
	void setLastClientHostID(Proud::HostID setLastClientID);

	void setS2CProxyValue(S2C::Proxy m_proxy);

	static ServerManager *getInstance();

};


#endif // !__PACKET_H_