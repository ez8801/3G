﻿  






// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.
   
#pragma once


#include "C2S_common.h"

     
namespace C2S {


	class Stub : public ::Proud::IRmiStub
	{
	public:
               
		virtual bool Chat ( ::Proud::HostID, ::Proud::RmiContext& ,  const Proud::String & ,  const int & ,  const float & )		{ 
			return false;
		} 

#define DECRMI_C2S_Chat bool Chat ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ,  const Proud::String & a,  const int & b,  const float & c) PN_OVERRIDE

#define DEFRMI_C2S_Chat(DerivedClass) bool DerivedClass::Chat ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ,  const Proud::String & a,  const int & b,  const float & c)
#define CALL_C2S_Chat Chat ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ,  const Proud::String & a,  const int & b,  const float & c)
#define PARAM_C2S_Chat ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ,  const Proud::String & a,  const int & b,  const float & c)
               
		virtual bool Login ( ::Proud::HostID, ::Proud::RmiContext& ,  const Proud::String & ,  const Proud::String & )		{ 
			return false;
		} 

#define DECRMI_C2S_Login bool Login ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ,  const Proud::String & id,  const Proud::String & password) PN_OVERRIDE

#define DEFRMI_C2S_Login(DerivedClass) bool DerivedClass::Login ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ,  const Proud::String & id,  const Proud::String & password)
#define CALL_C2S_Login Login ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ,  const Proud::String & id,  const Proud::String & password)
#define PARAM_C2S_Login ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ,  const Proud::String & id,  const Proud::String & password)
               
		virtual bool RequestMakeRaidRoom ( ::Proud::HostID, ::Proud::RmiContext& ,  const Proud::HostID & )		{ 
			return false;
		} 

#define DECRMI_C2S_RequestMakeRaidRoom bool RequestMakeRaidRoom ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ,  const Proud::HostID & HostId) PN_OVERRIDE

#define DEFRMI_C2S_RequestMakeRaidRoom(DerivedClass) bool DerivedClass::RequestMakeRaidRoom ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ,  const Proud::HostID & HostId)
#define CALL_C2S_RequestMakeRaidRoom RequestMakeRaidRoom ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ,  const Proud::HostID & HostId)
#define PARAM_C2S_RequestMakeRaidRoom ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ,  const Proud::HostID & HostId)
 
		virtual bool ProcessReceivedMessage(::Proud::CReceivedMessage &pa, void* hostTag) PN_OVERRIDE;
		static const PNTCHAR* RmiName_Chat;
		static const PNTCHAR* RmiName_Login;
		static const PNTCHAR* RmiName_RequestMakeRaidRoom;
		static const PNTCHAR* RmiName_First;
		virtual ::Proud::RmiID* GetRmiIDList() PN_OVERRIDE { return g_RmiIDList; }
		virtual int GetRmiIDListCount() PN_OVERRIDE { return g_RmiIDListCount; }
	};

#ifdef SUPPORTS_CPP11 
	
	class StubFunctional : public Stub 
	{
	public:
               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& ,  const Proud::String & ,  const int & ,  const float & ) > Chat_Function;
		virtual bool Chat ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ,  const Proud::String & a,  const int & b,  const float & c) 
		{ 
			if (Chat_Function==nullptr) 
				return true; 
			return Chat_Function(remote,rmiContext, a, b, c); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& ,  const Proud::String & ,  const Proud::String & ) > Login_Function;
		virtual bool Login ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ,  const Proud::String & id,  const Proud::String & password) 
		{ 
			if (Login_Function==nullptr) 
				return true; 
			return Login_Function(remote,rmiContext, id, password); 
		}

               
		std::function< bool ( ::Proud::HostID, ::Proud::RmiContext& ,  const Proud::HostID & ) > RequestMakeRaidRoom_Function;
		virtual bool RequestMakeRaidRoom ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext ,  const Proud::HostID & HostId) 
		{ 
			if (RequestMakeRaidRoom_Function==nullptr) 
				return true; 
			return RequestMakeRaidRoom_Function(remote,rmiContext, HostId); 
		}

	};
#endif

}


