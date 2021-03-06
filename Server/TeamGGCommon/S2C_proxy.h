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
	virtual bool sendRaidRoomInfo ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::CFastArray<raidrooms> & roomData) PN_SEALED; 
	virtual bool sendRaidRoomInfo ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::CFastArray<raidrooms> & roomData)   PN_SEALED;  
	virtual bool sendMakePVPRoomResult ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & p2pGroupId, const Proud::String & RoomName, const int & RoomIdx, const int & Result) PN_SEALED; 
	virtual bool sendMakePVPRoomResult ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const int & p2pGroupId, const Proud::String & RoomName, const int & RoomIdx, const int & Result)   PN_SEALED;  
	virtual bool sendPVPRoomInfo ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::CFastArray<pvprooms> & roomData) PN_SEALED; 
	virtual bool sendPVPRoomInfo ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::CFastArray<pvprooms> & roomData)   PN_SEALED;  
	virtual bool sendRoomHostId ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & HostId) PN_SEALED; 
	virtual bool sendRoomHostId ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const int & HostId)   PN_SEALED;  
	virtual bool sendPVPRoomJoinResult ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & p2pGroupId, const Proud::String & RoomName, const int & RoomIdx, const int & HostId, const int & Result) PN_SEALED; 
	virtual bool sendPVPRoomJoinResult ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const int & p2pGroupId, const Proud::String & RoomName, const int & RoomIdx, const int & HostId, const int & Result)   PN_SEALED;  
	virtual bool sendMakeAccountResult ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & Result) PN_SEALED; 
	virtual bool sendMakeAccountResult ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const int & Result)   PN_SEALED;  
	virtual bool sendLoginResult ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & Result, const Proud::String & CName, const int & gold) PN_SEALED; 
	virtual bool sendLoginResult ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const int & Result, const Proud::String & CName, const int & gold)   PN_SEALED;  
	virtual bool sendSkillData ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::CFastArray<passiveskillinfo> & skData) PN_SEALED; 
	virtual bool sendSkillData ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::CFastArray<passiveskillinfo> & skData)   PN_SEALED;  
	virtual bool sendEquipmentData ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const Proud::CFastArray<equipinfo> & eqData) PN_SEALED; 
	virtual bool sendEquipmentData ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const Proud::CFastArray<equipinfo> & eqData)   PN_SEALED;  
	virtual bool sendChangeEquipWeaponResult ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & ResultCode, const Proud::CFastArray<equipinfo> & eqData) PN_SEALED; 
	virtual bool sendChangeEquipWeaponResult ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const int & ResultCode, const Proud::CFastArray<equipinfo> & eqData)   PN_SEALED;  
	virtual bool sendBattleInfoResult ( ::Proud::HostID remote, ::Proud::RmiContext& rmiContext , const int & ResultCode, const Proud::CFastArray<battleinfo> & biData) PN_SEALED; 
	virtual bool sendBattleInfoResult ( ::Proud::HostID *remotes, int remoteCount, ::Proud::RmiContext &rmiContext, const int & ResultCode, const Proud::CFastArray<battleinfo> & biData)   PN_SEALED;  
static const PNTCHAR* RmiName_ShowChat;
static const PNTCHAR* RmiName_SystemChat;
static const PNTCHAR* RmiName_sendUserInfo;
static const PNTCHAR* RmiName_sendInventoryData;
static const PNTCHAR* RmiName_sendRaidRoomInfo;
static const PNTCHAR* RmiName_sendMakePVPRoomResult;
static const PNTCHAR* RmiName_sendPVPRoomInfo;
static const PNTCHAR* RmiName_sendRoomHostId;
static const PNTCHAR* RmiName_sendPVPRoomJoinResult;
static const PNTCHAR* RmiName_sendMakeAccountResult;
static const PNTCHAR* RmiName_sendLoginResult;
static const PNTCHAR* RmiName_sendSkillData;
static const PNTCHAR* RmiName_sendEquipmentData;
static const PNTCHAR* RmiName_sendChangeEquipWeaponResult;
static const PNTCHAR* RmiName_sendBattleInfoResult;
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



