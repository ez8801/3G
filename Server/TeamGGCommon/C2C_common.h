#pragma once

namespace C2C {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_P2PChat = (::Proud::RmiID)(2000+1);
               
    static const ::Proud::RmiID Rmi_ReadyPacket = (::Proud::RmiID)(2000+2);
               
    static const ::Proud::RmiID Rmi_SettingEnemyInfo = (::Proud::RmiID)(2000+3);
               
    static const ::Proud::RmiID Rmi_StartPacket = (::Proud::RmiID)(2000+4);
               
    static const ::Proud::RmiID Rmi_LeaveRoom = (::Proud::RmiID)(2000+5);
               
    static const ::Proud::RmiID Rmi_SyncPacket = (::Proud::RmiID)(2000+6);
               
    static const ::Proud::RmiID Rmi_DamagedFromEnemy = (::Proud::RmiID)(2000+7);
               
    static const ::Proud::RmiID Rmi_UseSkill = (::Proud::RmiID)(2000+8);
               
    static const ::Proud::RmiID Rmi_MatchEnd = (::Proud::RmiID)(2000+9);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
