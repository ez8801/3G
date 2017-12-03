#pragma once

namespace C2S {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_Chat = (::Proud::RmiID)(3000+1);
               
    static const ::Proud::RmiID Rmi_Login = (::Proud::RmiID)(3000+2);
               
    static const ::Proud::RmiID Rmi_RequestMakeRaidRoom = (::Proud::RmiID)(3000+3);
               
    static const ::Proud::RmiID Rmi_RequestGetRaidRoomInfo = (::Proud::RmiID)(3000+4);
               
    static const ::Proud::RmiID Rmi_RequestJoinRaidRoom = (::Proud::RmiID)(3000+5);
               
    static const ::Proud::RmiID Rmi_RequestMakePVPRoom = (::Proud::RmiID)(3000+6);
               
    static const ::Proud::RmiID Rmi_RequestGetPVPRoomInfo = (::Proud::RmiID)(3000+7);
               
    static const ::Proud::RmiID Rmi_RequestJoinPVPRoom = (::Proud::RmiID)(3000+8);
               
    static const ::Proud::RmiID Rmi_RequestLeavePVPRoom = (::Proud::RmiID)(3000+9);
               
    static const ::Proud::RmiID Rmi_RequestMakeAccount = (::Proud::RmiID)(3000+10);
               
    static const ::Proud::RmiID Rmi_RequestLoginAccount = (::Proud::RmiID)(3000+11);
               
    static const ::Proud::RmiID Rmi_RequestInventoryData = (::Proud::RmiID)(3000+12);
               
    static const ::Proud::RmiID Rmi_RequestSkillData = (::Proud::RmiID)(3000+13);
               
    static const ::Proud::RmiID Rmi_RequestEquipData = (::Proud::RmiID)(3000+14);
               
    static const ::Proud::RmiID Rmi_RequestChangeEquipWeapon = (::Proud::RmiID)(3000+15);
               
    static const ::Proud::RmiID Rmi_RequestBattleInfo = (::Proud::RmiID)(3000+16);
               
    static const ::Proud::RmiID Rmi_RequestBattleEnd = (::Proud::RmiID)(3000+17);
               
    static const ::Proud::RmiID Rmi_AddItemToInventory = (::Proud::RmiID)(3000+18);
               
    static const ::Proud::RmiID Rmi_AddGold = (::Proud::RmiID)(3000+19);
               
    static const ::Proud::RmiID Rmi_UseItemFromInventory = (::Proud::RmiID)(3000+20);
               
    static const ::Proud::RmiID Rmi_UseGold = (::Proud::RmiID)(3000+21);
               
    static const ::Proud::RmiID Rmi_SellAllItem = (::Proud::RmiID)(3000+22);
               
    static const ::Proud::RmiID Rmi_SendEquipInfo = (::Proud::RmiID)(3000+23);
               
    static const ::Proud::RmiID Rmi_SendPassiveEquipInfo = (::Proud::RmiID)(3000+24);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
