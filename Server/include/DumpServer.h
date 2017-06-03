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

#include "PnTime.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup minidump_group
	*  @{
	*/

	/** 
	\~korean
	´ýÇÁ ¼­¹ö°¡ ¿ä±¸ÇÏ´Â delegate

	\~english
	delegate that is requested by dump server

	\~chinese
	??Ü×?ÐïâÍé©îÜdelegate¡£

	\~japanese
	«À«ó«×«µ?«Ð?ª¬é©Ï´ª¹ªëdelegate
	\~
	*/
	class IDumpServerDelegate
	{
	public:
		virtual ~IDumpServerDelegate() {}

		/** 
		\~korean
		¼­¹ö ½ÇÇà ÆÄ¶ó¸ÞÅÍ¸¦ ¼³Á¤ÇÏ´Â ¸Þ¼­µå.
		¼­¹ö°¡ ½ÃÀÛµÇ´Â ¼ø°£ ÄÝ¹éµÈ´Ù. »ç¿ëÀÚ´Â ÀÌ ¸Þ¼­µå¸¦ ÅëÇØ ¼­¹ö¿¡°Ô ¼­¹ö ½ÇÇà ¿É¼ÇÀ» ¼³Á¤ÇØ¾ß ÇÑ´Ù.

		\param refParam ¼­¹ö ½ÇÇà ¿É¼Ç. ÀÌ ÇÔ¼ö¿¡¼­ »ç¿ëÀÚ´Â Proud.CStartServerParameter.m_tcpPort´Â ¹Ýµå½Ã ¼³Á¤ÇØ¾ß ÇÑ´Ù.
		Proud.CStartServerParameter.m_localNicAddr,Proud.CStartServerParameter.m_serverAddrAtClient´Â ÇÊ¿ä½Ã ¼³Á¤ÇÏµµ·Ï ÇÑ´Ù.
		³ª¸ÓÁö ÆÄ¶ó¸ÞÅÍ´Â ¼³Á¤ÇÏÁö ¾Ê¾Æµµ µÈ´Ù.
		ÁÖÀÇ! DumpServer´Â UDP »ç¿ëÀ» ÇÏÁö ¾Ê±â¶§¹®¿¡ m_udpPorts, m_udpAssignMode¸¦ ¼³Á¤ÇØµµ UDP Åë½ÅÀÌ µÇÁö ¾Ê´Â´Ù.

		\~english
		Method that sets server execution parameter
		Called back at the moment server is started. User must set server execution option through this method.

		\param refParam server execution option. Within this function, user must set Proud.CStartServerParameter.m_tcpPort at least.
		Proud.CStartServerParameter.m_localNicAddr and Proud.CStartServerParameter.m_serverAddrAtClient can be set as needed.
		Other parameter, they do not have to be set.
		**Note** Since DumpServer does not use UDP, UDP communication will be not available even if m_udpPorts and/or m_udpAssignMode are set.

		\~chinese
		?öÇÜ×?Ðï?ú¼??îÜÛ°Ûö¡£
		Ü×?Ðï??îÜâë?üÞ?¡£éÄ?é©÷×?ó®Û°ÛöèÙÜ×?Ðï?öÇÜ×?Ðï?ú¼??¡£

		\param refParam Ü×?Ðï?ú¼??¡£î¤ó®ùÞ?éÄ?ù±??öÇ Proud.CStartServerParameter.m_tcpPort%¡£
		êóù±é©îÜ?ý¦?öÇ Proud.CStartServerParameter.m_localNicAddr, Proud.CStartServerParameter.m_serverAddrAtClient%¡£
		í¥ù»îÜ??ÜôéÄ?öÇ¡£
		ñ¼ëò£¡DumpServer ãÀÜôÞÅéÄUDPîÜ£¬ á¶ì¤?ÞÅ?öÇm_udpPorts, m_udpAssignMode å¥Üô??ú¼UDP÷×ãá¡£

		\~japanese
		«µ?«Ð??ú¼«Ñ«é«á?«¿?ªòàâïÒª¹ªë«á«½«Ã«É
		«µ?«Ð?ª¬ËÒã·ªµªìªëâëÊà«³?«ë«Ð«Ã«¯ªµªìªÞª¹¡£«æ?«¶?ªÏª³ªÎ«á«½«Ã«Éªò÷×ª¸«µ?«Ð?ªË«µ?«Ð??ú¼«ª«×«·«ç«óªòàâïÒª·ªÊª±ªìªÐªÊªêªÞª»ªó¡£
		\param refParam «µ?«Ð??ú¼«ª«×«·«ç«ó¡£ª³ªÎ??ªÇ«æ?«¶?ªÏ¡¢Proud.CStartServerParameter.m_tcpPortªòù±ªºàâïÒª·ªÊª±ªìªÐªÊªêªÞª»ªó¡£
		Proud.CStartServerParameter.m_localNicAddr,Proud.CStartServerParameter.m_serverAddrAtClientªÏù±é©ªËªèªÃªÆàâïÒª¹ªëªèª¦ªËª·ªÞª¹¡£
		?ªêªÎ«Ñ«é«á?«¿?ªÏàâïÒª·ªÊª¯ªÆªâÕÞª¤ªÇª¹¡£
		ª´ñ¼ëò£¡DumpServerªÏUDPÞÅéÄªòª·ªÊª¤ª¿ªá¡¢m_udpPorts¡¢m_udpAssignModeªòàâïÒª·ªÆªâUDP÷×ãáª¬ú¼ªïªìªÞª»ªó¡£
		\~
		*/
		virtual void OnStartServer(CStartServerParameter &refParam) = 0;

		/** 
		\~korean
		¼­¹ö°¡ Á¾·áÇØ¾ß ÇÏ´Â »óÈ²(À¯ÀúÀÇ ¿äÃ» µî)ÀÌ¸é ÀÌ ÇÔ¼ö°¡ true¸¦ ¸®ÅÏÇÏ¸é µÈ´Ù.

		\~english
		In case when server must be terminated(i.e. upon user request), it can be done if this function returns true.

		\~chinese
		Ü×?Ðïé©?ò­îÜï×?£¨éÄ?îÜé­?Ôõ£©îÜ?£¬ó®ùÞ?Ú÷üÞtrue?Ê¦¡£

		\~japanese
		«µ?«Ð?ª¬ðûÖõª¹ªë?üÏ£¨«æ?«¶?ªÎé©ôëªÊªÉ£©ªÇª¢ªìªÐª³ªÎ??ª¬trueªò«ê«¿?«óª¹ªìªÐÕÞª¤ªÇª¹¡£
		\~
		 */
		virtual bool MustStopNow() = 0;
		
		/** 
		\~korean
		Critical section °´Ã¼¸¦ ¸®ÅÏÇÑ´Ù. °³¹ßÀÚ´Â ÀÌ ÇÔ¼ö¸¦ ÅëÇØ ÀÌ¹Ì ¼­¹ö°¡ »ç¿ëÁßÀÎ critical sectionÀÌ³ª
		º°µµ·Î ÁØºñÇÑ critical section °´Ã¼¸¦ °ø±ÞÇØ¾ß ÇÑ´Ù.

		\~english
		Returns critical section object. Developer must provide either the critical section that is already used by server through this function or oterwise prepared critical section object.

		\~chinese
		Ú÷üÞCritical section?ßÚ¡£??íº÷×?ó®ùÞ?é©ð«ÍêÜ×?Ðïì«?î¤ÞÅéÄñéîÜcritical sectionûäíº?èâñ×?îÜcritical section?ßÚ¡£

		\~japanese
		Critical section «ª«Ö«¸«§«¯«Èªò«ê«¿?«óª·ªÞª¹¡£ËÒ?íºªÏª³ªÎ??ªò÷×ª¸?ªË«µ?«Ð?ª¬ÞÅéÄª·ªÆª¤ªëcritical sectionªÈª«Ü¬ªËñÞÝáª·ª¿critical section«ª«Ö«¸«§«¯«ÈªòÍêÐåª·ªÊª±ªìªÐªÊªêªÞª»ªó¡£
		\~
		 */
		virtual CriticalSection* GetCriticalSection() = 0;
		
		/** 
		\~korean
		¼­¹ö ½ÃÀÛÀÌ ¿Ï·áµÆÀ½À» ¾Ë¸®´Â ÀÌº¥Æ®
		\param err ¼­¹ö ½ÃÀÛÀÌ ¼º°øÇßÀ¸¸é NULLÀÌ, ±×·¸Áö ¾ÊÀ¸¸é ErrorInfo °´Ã¼°¡ µé¾îÀÖ´Ù.

		\~english
		Evnet notifies that server start is completed
		\param err NULL if server start is successful, if not then it contains ErrorInfo object.

		\~chinese
		Í±ò±Ü×?Ðï??èÇà÷îÜevent¡£
		\param err Ü×?Ðï??à÷ÍíîÜ?NULL£¬é©ÜôæÔêóErrorInfo?ßÚ¡£

		\~japanese
		«µ?«Ð?ËÒã·ª¬èÇÖõªµªìª¿ª³ªÈªòò±ªéª»ªë«¤«Ù«ó«È
		\~
		 */
		virtual void OnServerStartComplete(Proud::ErrorInfo *err) = 0;
		
		/** 
		\~korean
		±â·ÏÇÒ ´ýÇÁ ÆÄÀÏÀÇ ÀÌ¸§À» °³¹ßÀÚ°¡ ÀÌ ÇÔ¼ö¸¦ ÅëÇØ °ø±ÞÇØ¾ß ÇÕ´Ï´Ù. ÀÔ·Â ÆÄ¶ó¸ÞÅÍ¸¦ ±Ù°Å·Î ¸¸µé¾îÁÖ¸é ÁÁ½À´Ï´Ù.
		\param clientHostID ´ýÇÁ Å¬¶óÀÌ¾ðÆ®ÀÇ HostID.
		\param clientAddr Å¬¶óÀÌ¾ðÆ®ÀÇ ¿ÜºÎ ÀÎÅÍ³Ý ÁÖ¼Ò 
		\param dumpTime ´ýÇÁ°¡ ³²´Â ½Ã°£

		\~english
		Developer must provide the name of dump file to be recorded through this function. It is ideal if it is based on input parameter.
		\param clientHostID HostID of dump client
		\param clientAddr external internet address of client 
		\param dumpTime time that dump stays

		\~chinese
		??íº÷×?ó®ùÞ?ð«Íêé©??îÜ??ÙþËìîÜÙ£?¡£õÌû¿ì¤?ìý???ëîËß?Ëï¡£
		\param clientHostID ??èÌÊ«îÜHost ID¡£
		\param clientAddr èÌÊ«îÜèâÝ»û»??ò¢ò£¡£
		\param dumpTime ??í¥ù»îÜ??¡£

		\~japanese
		ÑÀ?ª¹ªë«À«ó«×«Õ«¡«¤«ëªÎÙ£îñªòËÒ?íºª¬ª³ªÎ??ªò÷×ª¸ÍêÐåª·ªÊª±ªìªÐªÊªêªÞª»ªó¡£ìýÕô«Ñ«é«á?«¿?ªòÐÆ?ªËª·ªÆíÂªìªÐÕÞª¤ªÇª¹¡£
		\param clientHostID «À«ó«×«¯«é«¤«¢«ó«ÈªÎHostID.
		\param clientAddr «¯«é«¤«¢«ó«ÈªÎèâÝ»«¤«ó«¿?«Í«Ã«È«¢«É«ì«¹
		\param dumpTime «À«ó«×ª¬?ªëãÁÊà
		\~
		*/
		virtual String GetDumpFilePath(Proud::HostID clientHostID, const Proud::AddrPort& clientAddr, const ::timespec& tp) = 0;

		/** 
		\~korean
		ÀÏÁ¤ ½Ã°£¸¶´Ù È£ÃâµÈ´Ù.

		\~english
		Periodically called

		\~chinese
		ØßìéïÒ??Ô´?û¼Ð£¡£

		\~japanese
		á¶ïÒãÁÊàª´ªÈªËû¼ªÓõóªµªìªÞª¹¡£
		\~
		 */
		virtual void OnFrameMove() {}
	};

	/** 
	\~korean
	´ýÇÁ ¼­¹ö

	ÀÏ¹ÝÀû ¿ëµµ
	- »ý¼ºÀº Create()·Î ÇÑ´Ù.
	- RunMainLoop()¸¦ ½ÇÇàÇÏ¸é ´ýÇÁ ¼­¹ö°¡ Á¾·áÇÒ ¶§±îÁö ¿ªÇÒÀ» ¼öÇàÇÑ´Ù.

	\~english
	dump server

	General usage
	- To create, use Create().
	- If run RunMainLoop() then it runs until dump server is terminated.

	\~chinese
	??Ü×?Ðï¡£

	ìéÚõéÄÔ²
	- ßæà÷÷×?Create()¡£
	- ?ú¼RunMainLoop()îÜ?£¬?ú¼ÐìíÂéÄòÁÓð??Ü×?Ðï?ò­¡£

	\~japanese
	«À«ó«×«µ?«Ð?

	ìéÚõîÜªÊéÄÔ²
	- ßæà÷ªÏCreate()ªÇú¼ª¤ªÞª¹¡£
	- RunMainLoop()ªò?ú¼ª¹ªëªÈ«À«ó«×«µ?«Ð?ª¬ðûÖõª¹ªëãÁªÞªÇæµùÜªòâÄú¼ª·ªÞª¹¡£
	\~
	 */
	class CDumpServer
	{
	public:
		virtual ~CDumpServer(void) {}
		/** 
		\~korean
		ÀÌ ¸Þ¼­µå¸¦ ½ÇÇàÇÏ¸é ´ýÇÁ ¼­¹ö°¡ È°¼ºÈ­µÈ´Ù. ÀÌ ¸Þ¼­µå´Â ¼­¹ö°¡ ÀÛµ¿À» ÁßÁöÇÏ¶ó´Â ¿äÃ»ÀÌ IDumpServerDelegate¿¡
		ÀÇÇØ ¿À±â Àü±îÁö ¸®ÅÏÇÏÁö ¾Ê´Â´Ù.

		\~english
		Once this method is run, dump server is activated. This method does not return until it receives server down request from IDumpServerDelegate

		\~chinese
		?ú¼ó®Û°ÛöîÜ??Ì­üÀ??Ü×?Ðï¡£?ò­Ü×?Ðï??îÜé­??êóù¬IDumpServerDelegate??ñýîñ£¬ó®Û°ÛöÜô?Ú÷üÞ¡£

		\~japanese
		ª³ªÎ«á«½«Ã«Éªò?ú¼ª¹ªëªÈ«À«ó«×«µ?«Ð?ª¬üÀàõûùªµªìªÞª¹¡£ª³ªÎ«á«½«Ã«ÉªÏ«µ?«Ð?ª¬íÂÔÑªòñéò­ª·ªíªÈª¤ª¤ª¦é©ôëª¬IDumpServerDelegateªËªèªÃªÆ?ªëîñªÞªÇ«ê«¿?«óª·ªÞª»ªó¡£
		\~
		 */
		virtual void RunMainLoop() = 0;

		/** 
		\~korean
		CDumpServer °´Ã¼¸¦ »ý¼ºÇÑ´Ù.
		\param dg IDumpServerDelegate¸¦ »ó¼Ó¹ÞÀº ÀÌº¥Æ® CallbackÀ» ¹ÞÀ» class Æ÷ÀÎÅÍ
		\return »ý¼ºµÈ CDumpServer °´Ã¼ Æ÷ÀÎÅÍ

		\~english TODO:translate needed.
		Generates a CDumpServer object. 
		\param dg The class pointer to receive the event callback that inherited IDumpServerDelegate
		\return Generated CDumpServer object pointer

		\~chinese
		ßæà÷ CDumpServer%?ßÚ¡£
		\param dg ïÈâ¥?ã¯IDumpServerDelegateîÜCallbackeventîÜclass pointer¡£
		\return ßæà÷îÜ CDumpServer%?ßÚpointer¡£

		\~japanese
		CDumpServer«ª«Ö«¸«§«¯«Èªòßæà÷ª·ªÞª¹¡£
		\param dg IDumpServerDelegateªòßÓ?ª·ªÆªâªéªÃª¿«¤«Ù«ó«È«³?«ë«Ð«Ã«¯ªòáôª±ªë«¯«é«¹«Ý«¤«ó«¿?
		\return ßæà÷ªµªìª¿CDumpServer«ª«Ö«¸«§«¯«È«Ý«¤«ó«¿?
		\~
		 */
		PROUDSRV_API static CDumpServer* Create(IDumpServerDelegate* dg);
	};
	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif