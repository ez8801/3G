#pragma once

#ifndef __SERVERMAIN_H_
#define __SERVERMAIN_H_
#include "Common.h"
#include "Packet.h"
#include "User.h"
class ServerMain
{
public:
	ServerMain();

	void Team3GServerMain();
private:
	ServerManager * m_InMain;
	S2C::Proxy m_S2CProxy;
	
};


#endif // !__SERVERMAIN_H_
