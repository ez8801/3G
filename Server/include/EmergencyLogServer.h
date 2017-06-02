/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


ÀÌ ÇÁ·Î±×·¥ÀÇ ÀúÀÛ±ÇÀº ³ÝÅÙ¼Ç¿¡°Ô ÀÖ½À´Ï´Ù.
ÀÌ ÇÁ·Î±×·¥ÀÇ ¼öÁ¤, »ç¿ë, ¹èÆ÷¿¡ °ü·ÃµÈ »çÇ×Àº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾àÀ» µû¸£¸ç,
°è¾àÀ» ÁØ¼öÇÏÁö ¾Ê´Â °æ¿ì ¿øÄ¢ÀûÀ¸·Î ¹«´Ü »ç¿ëÀ» ±ÝÁöÇÕ´Ï´Ù.
¹«´Ü »ç¿ë¿¡ ÀÇÇÑ Ã¥ÀÓÀº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾à¼­¿¡ ¸í½ÃµÇ¾î ÀÖ½À´Ï´Ù.

** ÁÖÀÇ : ÀúÀÛ¹°¿¡ °üÇÑ À§ÀÇ ¸í½Ã¸¦ Á¦°ÅÇÏÁö ¸¶½Ê½Ã¿À.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


ó®ïïßíîÜ÷ú??NettentionÍëÞÉá¶êó¡£
?ó®ïïßíîÜáóËÇ¡¢ÞÅéÄ¡¢?øÖßÓ?îÜÞÀ?é©ñåáúó®ïïßíîÜá¶êó?íºîÜ??¡£
Üôñåáú???é©ê«?àõîÜÐ×ò­ôºí»ÞÅéÄ¡£
ôºí»ÞÅéÄîÜ?ìòÙ¥ãÆî¤?ó®ïïßíá¶êó?íºîÜùêÔÒ?×ì¡£

** ñ¼ëò£ºÜôé©ì¹ð¶?éÍð¤íÂÚªîÜß¾âûÙ¥ãÆ¡£


ª³ªÎ«×«í«°«é«àªÎîÊíÂ?ªÏNettentionªËª¢ªêªÞª¹¡£
ª³ªÎ«×«í«°«é«àªÎáóïá¡¢ÞÅéÄ¡¢ÛÕøÖªË?ª¹ªëÞÀú£ªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ªË?ª¤¡¢
Ìøå³ªòñåáúª·ªÊª¤íÞùê¡¢ê«öÎîÜªËÙí?ÞÅéÄªòÐ×ª¸ªÞª¹¡£
Ùí?ÞÅéÄªËªèªëô¡ìòªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ßöªËÙ¥ãÆªµªìªÆª¤ªÞª¹¡£

** ñ¼ëò£ºîÊíÂÚªªË?ª¹ªëß¾ÑÀªÎÙ¥ãÆªòð¶ËÛª·ªÊª¤ªÇª¯ªÀªµª¤¡£

*/

#pragma once

#include "ProudNetServer.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	/** 
	\~korean
	EmergencyLog ¼­¹ö°¡ ¿ä±¸ÇÏ´Â delegate

	\~english TODO:translate needed.
	The delegate requested by EmergencyLog server

	\~chinese
	EmergencyLog Ü×?ÐïâÍé©îÜdelegate¡£

	\~japanese
	EmergencyLog «µ?«Ð?ª¬é©Ï´ª¹ªë delegate
	\~
	*/
	class IEmergencyLogServerDelegate
	{
	public:
		virtual ~IEmergencyLogServerDelegate() {}

		/**
		\~korean
		¼­¹ö ½ÇÇà ÆÄ¶ó¸ÞÅÍ¸¦ ¼³Á¤ÇÏ´Â ¸Þ¼­µå.
		¼­¹ö°¡ ½ÃÀÛµÇ´Â ¼ø°£ ÄÝ¹éµÈ´Ù. »ç¿ëÀÚ´Â ÀÌ ¸Þ¼­µå¸¦ ÅëÇØ ¼­¹ö¿¡°Ô ¼­¹ö ½ÇÇà ¿É¼ÇÀ» ¼³Á¤ÇØ¾ß ÇÑ´Ù.

		\param refParam ¼­¹ö ½ÇÇà ¿É¼Ç. ÀÌ ÇÔ¼ö¿¡¼­ »ç¿ëÀÚ´Â Proud.CStartServerParameter.m_tcpPort ´Â ¹Ýµå½Ã ¼³Á¤ÇØ¾ß ÇÑ´Ù.
		Proud.CStartServerParameter.m_localNicAddr,Proud.CStartServerParameter.m_serverAddrAtClient ´Â ÇÊ¿ä½Ã ¼³Á¤ÇÏµµ·Ï ÇÑ´Ù.
		³ª¸ÓÁö ÆÄ¶ó¸ÞÅÍ´Â ¼³Á¤ÇÏÁö ¾Ê¾Æµµ µÈ´Ù.
		ÁÖÀÇ! CEmergencyLogServer ´Â UDP »ç¿ëÀ» ÇÏÁö ¾Ê±â¶§¹®¿¡ m_udpPorts, m_udpAssignMode ¸¦ ¼³Á¤ÇØµµ UDP Åë½ÅÀÌ µÇÁö ¾Ê´Â´Ù.

		\~english TODO:translate needed.
		The method to set server run parameters. 
		This is called back when the server starts. Users must set the server running option through this method. 
		\param refParam Server running option. In this function, the user must configure Proud.CStartServerParameter.m_tcpPort. 
		Proud.CStartServerParameter.m_localNicAddr,Proud.CStartServerParameter.m_serverAddrAtClient shall be configured when necessary. 
		Other parameters need not be configured. 
		Caution! As CEmergencyLogServer does not use UDP, UDP communication is not possible even if m_udpPorts and m_udpAssignMode are selected. 

		\~chinese
		?öÇÜ×?ÐïîÜ?ú¼??Û°Ûö¡£
		Ü×?Ðï??âë??üÞ?¡£éÄ?é©××éÄó®Û°Ûö?Ü×?Ðï?öÇÜ×?Ðï?ú¼??¡£

		\param refParam Ü×?Ðï?ú¼??¡£ó®ùÞ?îÜéÄ?ù±??öÇ Proud.CStartServerParameter.m_tcpPort%¡£

		ù±é©??öÇ Proud.CStartServerParameter.m_localNicAddr, Proud.CStartServerParameter.m_serverAddrAtClient%¡£
		í¥ù»îÜ??ÜôéÄ?öÇ¡£
		ñ¼ëò£¡ì×? CEmergencyLogServer%ÜôÞÅéÄUDP£¬?ÞÅ?öÇÖõm_udpPorts, m_udpAssignMode å¥Üô??ú¼UDP÷×ãá¡£

		\~japanese
		«µ?«Ð??ú¼«Ñ«é«á?«¿?ªòàâïÒª¹ªë«á«½«Ã«É
		«µ?«Ð?ª¬ËÒã·ªµªìªëâëÊà«³?«ë«Ð«Ã«¯ªµªìªÞª¹¡£«æ?«¶?ªÏª³ªÎ«á«½«Ã«Éªò÷×ª¸«µ?«Ð?ªË«µ?«Ð??ú¼«ª«×«·«ç«óªòàâïÒª·ªÊª±ªìªÐªÊªêªÞª»ªó¡£
		\param refParam «µ?«Ð??ú¼«ª«×«·«ç«ó¡£ª³ªÎ??ªÇ«æ?«¶?ªÏProud.CStartServerParameter.m_tcpPort ªòù±ªºàâïÒª·ªÊª±ªìªÐªÊªêªÞª»ªó¡£
		Proud.CStartServerParameter.m_localNicAddr,Proud.CStartServerParameter.m_serverAddrAtClientªÏù±é©ªËªèªÃªÆàâïÒª·ªÆª¯ªÀªµª¤¡£
		?ªêªÎ«Ñ«é«á?«¿?ªÏàâïÒª·ªÊª¯ªÆªâÕÞª¤ªÇª¹¡£
		ª´ñ¼ëò! CEmergencyLogServerªÏUDPÞÅéÄªòª·ªÊª¤ª¿ªá¡¢m_udpPorts, m_udpAssignMode ªòàâïÒª·ªÆªâUDP÷×ãáª¬ªÇª­ªÞª»ªó¡£
		\~
		*/
		virtual void OnStartServer(CStartServerParameter &refParam) = 0;

		/** 
		\~korean
		¼­¹ö°¡ Á¾·áÇØ¾ß ÇÏ´Â »óÈ²(À¯ÀúÀÇ ¿äÃ» µî)ÀÌ¸é ÀÌ ÇÔ¼ö°¡ true¸¦ ¸®ÅÏÇÏ¸é µÈ´Ù. 

		\~english TODO:translate needed.
		If this is a situation where the server must be terminated (user request, etc), then this function shall return true. 

		\~chinese
		åýâÍ?ò­Ü×?Ðï£¨ì×éÄ?é­?Ôõê«ì×£©£¬ó®ùÞ?Ú÷üÞtrue?Ê¦¡£

		\~japanese
		«µ?«Ð?ª¬ðûÖõª·ªÊª±ªìªÐªÊªéªÊª¤?üÏ£¨«æ?«¶?ªÎé©ôëªÊªÉ£©ªÇª¢ªìªÐª³ªÎ??ª¬trueªò«ê«¿?«óª¹ªìªÐª¤ª¤ªÇª¹¡£
		\~
		*/
		virtual bool MustStopNow() = 0;
		
		/** 
		\~korean
		Critical section °´Ã¼¸¦ ¸®ÅÏÇÑ´Ù. °³¹ßÀÚ´Â ÀÌ ÇÔ¼ö¸¦ ÅëÇØ ÀÌ¹Ì ¼­¹ö°¡ »ç¿ëÁßÀÎ critical sectionÀÌ³ª
		º°µµ·Î ÁØºñÇÑ critical section °´Ã¼¸¦ °ø±ÞÇØ¾ß ÇÑ´Ù.  

		\~english TODO:translate needed.
		A critical section object is returned. Developers must supply either a critical section where the server is already being used or a critical section object additionally prepared.  

		\~chinese
		Ú÷üÞCritical section?ßÚ¡£??íºé©÷×?ó®ùÞ?ð«ÍêÜ×?Ðïïáî¤ÞÅéÄîÜcritical section£¬ûä?èâñ×?îÜcritical section¡£

		\~japanese
		Critical section «ª«Ö«¸«§«¯«Èªò«ê«¿?«óª·ªÞª¹¡£ËÒ?íºªÏª³ªÎ??ªò÷×ª¸?ªË«µ?«Ð?ª¬ÞÅéÄª·ªÆª¤ªëcritical sectionªÈª«Ü¬ªËñÞÝáª·ª¿critical section«ª«Ö«¸«§«¯«ÈªòÍêÐåª·ªÊª±ªìªÐªÊªêªÞª»ªó¡£ 
		  
		\~
		*/
		virtual CriticalSection* GetCriticalSection() = 0;
		
		/** 
		\~korean
		¼­¹ö ½ÃÀÛÀÌ ¿Ï·áµÆÀ½À» ¾Ë¸®´Â ÀÌº¥Æ®
		\param err ¼­¹ö ½ÃÀÛÀÌ ¼º°øÇßÀ¸¸é NULLÀÌ, ±×·¸Áö ¾ÊÀ¸¸é ErrorInfo °´Ã¼°¡ µé¾îÀÖ´Ù. 

		\~english TODO:translate needed.
		The event that informs the server start is complete. 
		If the server start is successful, NULL, otherwise the ErrorInfo object is in there. 
		

		\~chinese
		Í±ò±Ü×?Ðï??èÇ?îÜîÜÞÀËì¡£
		\param err Ü×?Ðï??à÷ÍíîÜ?êóNULL£¬Üú??êóErrorInfo?ßÚ¡£

		\~japanese
		«µ?«Ð?ËÒã·ª¬èÇÖõªµªìª¿ª³ªÈªòò±ªéª»ªë«¤«Ù«ó«È
		\param err «µ?«Ð?ËÒã·ªËà÷Ííª·ª¿ªéNULLª¬¡¢ã÷ø¨ª·ª¿ªéErrorInfo«ª«Ö«¸«§«¯«Èª¬ìýªÃªÆª¤ªÞª¹¡£ 
		
		\~
		*/
		virtual void OnServerStartComplete(Proud::ErrorInfo *err) = 0;

		/** 
		\~korean
		ÀÏÁ¤ ½Ã°£¸¶´Ù È£ÃâµÈ´Ù. 

		\~english TODO:translate needed.
		It is called a fixed interval. 
		 
		\~chinese
		ØßÌ°ìéÓ«???ú¼?û¼¡£

		\~japanese
		á¶ïÒãÁÊàª´ªÈªËû¼ªÓõóªµªìªÞª¹¡£
		\~
		*/
		virtual void OnFrameMove() {}
	};

	/** 
	\~korean
	EmergencyLog ¼­¹ö
	ÀÏ¹ÝÀû ¿ëµµ
	- Å¬¶óÀÌ¾ðÆ®´Â µû·Î ½ÇÇàÇÒ ÇÊ¿ä¾øÀ½ CNetClient.SendEmergencyLog ¸¦ È£ÃâÇÏ¸é ¾Ë¾Æ¼­ ·Î±×¼­¹ö·Î º¸³¿
	- »ý¼ºÀº Create()·Î ÇÑ´Ù.
	- RunMainLoop()¸¦ ½ÇÇàÇÏ¸é ·Î±× ¼­¹ö°¡ Á¾·áÇÒ ¶§±îÁö ¿ªÇÒÀ» ¼öÇàÇÑ´Ù.

	\~english TODO:translate needed.
	EmergencyLog server
	General use
	- The client needs not be executed additionally. If you call CNetClient.SendEmergencyLog, it sends to the log server on its own. 
	- Creation is done with Create()
	- If you run RunMainLoop(), it performs its role until the log server ends. 

	\~chinese
	EmergencyLog Ü×?Ðï¡£
	ìéÚõéÄÔ²
	- clientÜôâÍ?èâ?ú¼¡£?û¼ CNetClient.SendEmergencyLog%??í»??áêò¸logÜ×?Ðï¡£
	- ßæà÷éÄCreate()¡£
	- ?ú¼RunMainLoop()îÜ????íÂéÄò¸logÜ×?Ðï?áÖ¡£

	\~japanese
	EmergencyLog «µ?«Ð?
	ìéÚõîÜªÊéÄÔ²
	- «¯«é«¤«¢«ó«ÈªÏÜ¬ªË?ú¼ª¹ªëù±é©ª¬ª¢ªêªÞª»ªó¡£CNetClient.SendEmergencyLogªòû¼ªÓõóª·ªÊª¬ªé«í«°«µ?«Ð?ªËáêªêªÞª¹¡£
	- ßæà÷ªÏCreate()ªÈª·ªÞª¹¡£
	- RunMainLoop()ªò?ú¼ª¹ªëªÈ«í«°«µ?«Ð?ª¬ðûÖõª¹ªëãÁªÞªÇæµùÜªòâÄú¼ª·ªÞª¹¡£
	\~
	*/
	class CEmergencyLogServer
	{
	public:
		virtual ~CEmergencyLogServer(void) {}

		/** 
		\~korean
		ÀÌ ¸Þ¼­µå¸¦ ½ÇÇàÇÏ¸é ·Î±× ¼­¹ö°¡ È°¼ºÈ­µÈ´Ù. ÀÌ ¸Þ¼­µå´Â ¼­¹ö°¡ ÀÛµ¿À» ÁßÁöÇÏ¶ó´Â ¿äÃ»ÀÌ IEmergencyLogServerDelegate ¿¡
		ÀÇÇØ ¿À±â Àü±îÁö ¸®ÅÏÇÏÁö ¾Ê´Â´Ù. 

		\~english TODO:translate needed.
		- If you run this method, the log server is activated. This method does not return until the request to stop running the server is relayed by IEmergencyLogServerDelegate. 

		\~chinese
		?ú¼ó®Û°ÛöîÜ??Ì­üÀlogÜ×?Ðï¡£î¤ïÈÓð÷×?IEmergencyLogServerDelegateÜ×?Ðï?õóîÜ?ò­?ú¼é­?ñýîñ£¬ó®Û°ÛöÜô?Ú÷üÞ¡£

		\~japanese
		ª³ªÎ«á«½«Ã«Éªò?ú¼ª¹ªëªÈ«í«°«µ?«Ð?ª¬üÀàõûùªµªìªÞª¹¡£ª³ªÎ«á«½«Ã«ÉªÏ«µ?«Ð?ª¬íÂÔÑªòñéò­ª·ªíªÈª¤ª¦é©ôëª¬IEmergencyLogServerDelegateªËªèªÃªÆ?ªëîñªÞªÇ«ê«¿?«óª·ªÞª»ªó¡£ 
		\~
		*/
		virtual void RunMainLoop() = 0;

		/** 
		\~korean
		CEmergencyLogServer °´Ã¼¸¦ »ý¼ºÇÑ´Ù. 

		\~english TODO:translate needed.
		Generate CEmergencyLogServer object. 

		\~chinese
		ßæà÷ CEmergencyLogServer%?ßÚ¡£

		\~japanese
		CEmergencyLogServer «ª«Ö«¸«§«¯«Èªòßæà÷ª·ªÞª¹¡£
		\~
		*/
		PROUDSRV_API static CEmergencyLogServer* Create(IEmergencyLogServerDelegate* dg);
	};

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
