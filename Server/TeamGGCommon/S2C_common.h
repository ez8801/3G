#pragma once

namespace S2C {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_ShowChat = (::Proud::RmiID)(4000+1);
               
    static const ::Proud::RmiID Rmi_SystemChat = (::Proud::RmiID)(4000+2);
               
    static const ::Proud::RmiID Rmi_sendUserInfo = (::Proud::RmiID)(4000+3);
               
    static const ::Proud::RmiID Rmi_sendInventoryData = (::Proud::RmiID)(4000+4);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
