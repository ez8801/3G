#pragma once

namespace C2S {


	//Message ID that replies to each RMI method. 
               
    static const ::Proud::RmiID Rmi_Chat = (::Proud::RmiID)(3000+1);
               
    static const ::Proud::RmiID Rmi_Login = (::Proud::RmiID)(3000+2);
               
    static const ::Proud::RmiID Rmi_RequestMakeRaidRoom = (::Proud::RmiID)(3000+3);

	// List that has RMI ID.
	extern ::Proud::RmiID g_RmiIDList[];
	// RmiID List Count
	extern int g_RmiIDListCount;

}


 
