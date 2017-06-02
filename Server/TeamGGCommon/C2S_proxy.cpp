﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.


#include "C2S_proxy.h"

namespace C2S {


        
	bool Proxy::Chat ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & a, const int & b, const float & c)	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_Chat;
__msg.Write(__msgid); 
	
__msg << a;
__msg << b;
__msg << c;
		
		return RmiSend(&remote,1,rmiContext,__msg,
			RmiName_Chat, (::Proud::RmiID)Rmi_Chat);
	}

	bool Proxy::Chat ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & a, const int & b, const float & c)  	{
		::Proud::CMessage __msg;
__msg.UseInternalBuffer();
__msg.SetSimplePacketMode(m_core->IsSimplePacketMode());

::Proud::RmiID __msgid=(::Proud::RmiID)Rmi_Chat;
__msg.Write(__msgid); 
	
__msg << a;
__msg << b;
__msg << c;
		
		return RmiSend(remotes,remoteCount,rmiContext,__msg,
			RmiName_Chat, (::Proud::RmiID)Rmi_Chat);
	}
#ifdef USE_RMI_NAME_STRING
const PNTCHAR* Proxy::RmiName_Chat =_PNT("Chat");
#else
const PNTCHAR* Proxy::RmiName_Chat =_PNT("");
#endif
const PNTCHAR* Proxy::RmiName_First = RmiName_Chat;

}



