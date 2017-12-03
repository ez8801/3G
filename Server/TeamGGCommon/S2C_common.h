#pragma once

namespace S2C {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_ShowChat = (::Proud::RmiID)(4000+1);
               
    static const ::Proud::RmiID Rmi_SystemChat = (::Proud::RmiID)(4000+2);
               
    static const ::Proud::RmiID Rmi_sendUserInfo = (::Proud::RmiID)(4000+3);
               
    static const ::Proud::RmiID Rmi_sendInventoryData = (::Proud::RmiID)(4000+4);
               
    static const ::Proud::RmiID Rmi_sendRaidRoomInfo = (::Proud::RmiID)(4000+5);
               
    static const ::Proud::RmiID Rmi_sendMakePVPRoomResult = (::Proud::RmiID)(4000+6);
               
    static const ::Proud::RmiID Rmi_sendPVPRoomInfo = (::Proud::RmiID)(4000+7);
               
    static const ::Proud::RmiID Rmi_sendRoomHostId = (::Proud::RmiID)(4000+8);
               
    static const ::Proud::RmiID Rmi_sendPVPRoomJoinResult = (::Proud::RmiID)(4000+9);
               
    static const ::Proud::RmiID Rmi_sendMakeAccountResult = (::Proud::RmiID)(4000+10);
               
    static const ::Proud::RmiID Rmi_sendLoginResult = (::Proud::RmiID)(4000+11);
               
    static const ::Proud::RmiID Rmi_sendSkillData = (::Proud::RmiID)(4000+12);
               
    static const ::Proud::RmiID Rmi_sendEquipmentData = (::Proud::RmiID)(4000+13);
               
    static const ::Proud::RmiID Rmi_sendChangeEquipWeaponResult = (::Proud::RmiID)(4000+14);
               
    static const ::Proud::RmiID Rmi_sendBattleInfoResult = (::Proud::RmiID)(4000+15);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
