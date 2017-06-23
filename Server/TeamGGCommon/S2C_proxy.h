﻿



  
// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

#pragma once


#include "S2C_common.h"

namespace S2C {


	class Proxy : public ::Proud::IRmiProxy
	{
	public:
	virtual bool ShowChat ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & a, const int & b, const float & c) PN_SEALED; 
	virtual bool ShowChat ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & a, const int & b, const float & c)   PN_SEALED;  
	virtual bool SystemChat ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & txt) PN_SEALED; 
	virtual bool SystemChat ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & txt)   PN_SEALED;  
	virtual bool sendUserInfo ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::String & userName, const int & att, const int & def) PN_SEALED; 
	virtual bool sendUserInfo ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::String & userName, const int & att, const int & def)   PN_SEALED;  
	virtual bool sendInventoryData ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::CFastArray<items> & ivData) PN_SEALED; 
	virtual bool sendInventoryData ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::CFastArray<items> & ivData)   PN_SEALED;  
static const PNTCHAR* RmiName_ShowChat;
static const PNTCHAR* RmiName_SystemChat;
static const PNTCHAR* RmiName_sendUserInfo;
static const PNTCHAR* RmiName_sendInventoryData;
static const PNTCHAR* RmiName_First;
		Proxy()
		{
			if(m_signature != 1)
				::Proud::ShowUserMisuseError(::Proud::ProxyBadSignatureErrorText);
		}

		virtual ::Proud::RmiID* GetRmiIDList() PN_OVERRIDE { return g_RmiIDList; } 
		virtual int GetRmiIDListCount() PN_OVERRIDE { return g_RmiIDListCount; }
	};

}



