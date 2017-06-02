/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


ÀÌ ÇÁ·Î±×·¥ÀÇ ÀúÀÛ±ÇÀº ³İÅÙ¼Ç¿¡°Ô ÀÖ½À´Ï´Ù.
ÀÌ ÇÁ·Î±×·¥ÀÇ ¼öÁ¤, »ç¿ë, ¹èÆ÷¿¡ °ü·ÃµÈ »çÇ×Àº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾àÀ» µû¸£¸ç,
°è¾àÀ» ÁØ¼öÇÏÁö ¾Ê´Â °æ¿ì ¿øÄ¢ÀûÀ¸·Î ¹«´Ü »ç¿ëÀ» ±İÁöÇÕ´Ï´Ù.
¹«´Ü »ç¿ë¿¡ ÀÇÇÑ Ã¥ÀÓÀº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾à¼­¿¡ ¸í½ÃµÇ¾î ÀÖ½À´Ï´Ù.

** ÁÖÀÇ : ÀúÀÛ¹°¿¡ °üÇÑ À§ÀÇ ¸í½Ã¸¦ Á¦°ÅÇÏÁö ¸¶½Ê½Ã¿À.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


ó®ïïßíîÜ÷ú??NettentionÍëŞÉá¶êó¡£
?ó®ïïßíîÜáóËÇ¡¢ŞÅéÄ¡¢?øÖßÓ?îÜŞÀ?é©ñåáúó®ïïßíîÜá¶êó?íºîÜ??¡£
Üôñåáú???é©ê«?àõîÜĞ×ò­ôºí»ŞÅéÄ¡£
ôºí»ŞÅéÄîÜ?ìòÙ¥ãÆî¤?ó®ïïßíá¶êó?íºîÜùêÔÒ?×ì¡£

** ñ¼ëò£ºÜôé©ì¹ğ¶?éÍğ¤íÂÚªîÜß¾âûÙ¥ãÆ¡£


ª³ªÎ«×«í«°«é«àªÎîÊíÂ?ªÏNettentionªËª¢ªêªŞª¹¡£
ª³ªÎ«×«í«°«é«àªÎáóïá¡¢ŞÅéÄ¡¢ÛÕøÖªË?ª¹ªëŞÀú£ªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ªË?ª¤¡¢
Ìøå³ªòñåáúª·ªÊª¤íŞùê¡¢ê«öÎîÜªËÙí?ŞÅéÄªòĞ×ª¸ªŞª¹¡£
Ùí?ŞÅéÄªËªèªëô¡ìòªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ßöªËÙ¥ãÆªµªìªÆª¤ªŞª¹¡£

** ñ¼ëò£ºîÊíÂÚªªË?ª¹ªëß¾ÑÀªÎÙ¥ãÆªòğ¶ËÛª·ªÊª¤ªÇª¯ªÀªµª¤¡£

*/

#pragma once

#include "Enums.h"
#include "EncryptEnum.h"
#include "BasicTypes.h"
#include "CompressEnum.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	class CReceivedMessage;
	class CMessage;

	/**
	\~korean
	RMI È£Ãâ¿¡ °ü·ÃµÈ ³×Æ®¿öÅ· ¼Ó¼º µî

	\~english
	Networkign nature related to RMI calling and others

	\~chinese
	?éÍRMIû¼õóîÜ???àõÔõ¡£

	\~japanese
	RMIû¼ªÓõóª·ªË?ª¹ªë«Í«Ã«È«ï?«­«ó«°?àõªÊªÉ
	\~
	*/
	// ÁÖÀÇ: ¼öÁ¤½Ã ProudClrÀÇ µ¿¸í ½Éº¼µµ ¼öÁ¤ÇØ¾ß ÇÑ´Ù.
	class RmiContext
	{
	public:
		/**
		\~korean
		relayµÈ ¸Ş½ÃÁöÀÎ°¡?
		- RMI stub¿¡¼­ Ã¤¿öÁö´Â °ªÀÔ´Ï´Ù.
		- ¸¸¾à Å¬¶óÀÌ¾ğÆ®°¡ º¸³½ RMI°¡ ¼­¹ö¸¦ ÅëÇØ ¸±·¹ÀÌ(¹ÙÀÌÆĞ½º)µÇ¾ú°Å³ª( <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_comm_overview" >Å¬¶óÀÌ¾ğÆ®°£ P2P Åë½ÅÀÇ °³¿ä</a> Âü°í),
		¼­¹ö°¡ º¸³½ RMI°¡ ´Ù¸¥ Å¬¶óÀÌ¾ğÆ®¸¦ ÅëÇØ routeµÇ¾úÀ¸¸é ( <a target="_blank" href="http://guide.nettention.com/cpp_ko#s2c_routed_multicast" >¼­¹ö¿¡¼­ ´Ù¼öÀÇ Å¬¶óÀÌ¾ğÆ®¿¡°Ô routed multicast¸¦ ÇÏ±â</a> Âü°í)
		ÀÌ °ªÀº true°¡ µÈ Ã¤ RMI ÇÔ¼ö°¡ Äİ¹éµË´Ï´Ù.

		\~english
		Is this a relaysed message?
		- The value filled at RMI stub
		- If RMI from client is relayed via server(Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_comm_overview" >Overview of peer-to-peer communication between clients</a>) or RMI sent by server is routed by other client(Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#s2c_routed_multicast" >Routed multicasting several clients from server</a>),
  		then RMI function wil be called back while this value keeps to be true.

		\~chinese
		Relay îÜãáãÓ?£¿
		- î¤RMI stub?õöîÜ?¡£
		- åıÍıclient?áêîÜRMI÷×?Ü×?Ğïrelay£¨bypass£©Öõ£¨?ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_comm_overview" >ËÔ?Ó®ñı?îÜP2P÷×ãá?é©</a>%£©ûäíºÜ×?Ğï?áêîÜRMI÷×?Ğìöâclientù¬routeîÜ?£¨?ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#s2c_routed_multicast" >î¤Ü×?Ğïñé?Òı?ËÔ?Ó®?ú¼routed multicast</a>%£©£¬ó®??î¤true??ù»üŞ?RMIùŞ?¡£

		\~japanese
		Relayªµªìª¿«á«Ã«»?«¸ªÊªÎª«£¿
		- RMI stubªÇ?ª¿ªµªìªëö·ªÇª¹¡£
		- ªâª·¡¢«¯«é«¤«¢«ó«Èª¬áêªÃª¿RMIª¬«µ?«Ğ?ªò÷×ª¸«ê«ì?(«Ğ«¤«Ñ«¹)ªµªìªÆª¤ªëª«(\ref p2p_comm_overview ?ÍÅ)¡¢«µ?«Ğ?ª¬áêªÃª¿RMIª¬öâªÎ«¯«é«¤«¢«ó«Èªò÷×ª¸routeªµªìª¿ªé(\ref s2c_routed_multicast ?ÍÅ)ª³ªÎö·ªÏtrueªËªÊªÃª¿ªŞªŞRMI??ª¬«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£ 

		\~
		*/
		bool m_relayed;

		/**
		\~korean
		RMI¸¦ ¼Û½ÅÇÑ peerÀÇ HostID ÀÌ´Ù.
		- RMI stub¿¡¼­ Ã¤¿öÁö´Â °ªÀÌ´Ù.

		\~english
		HostID of peer that transmitted RMI
		- The value filled at RMI stub

		\~chinese
		?áêRMIîÜpeerîÜHost ID¡£
		- î¤RMI stub?õöîÜ?¡£

		\~japanese
		RMIªòáêãáª·ª¿PeerªÎHostIDªÇª¹¡£
		- RMI stubªÇ?ª¿ªµªìªëö·ªÇª¹¡£

		\~
		*/
		HostID m_sentFrom;

		/**
		\~korean
		unreliable sendÀÎ °æ¿ì,
		routed multicast¸¦ ÇÒ ¼ö ÀÖ´Ù. ÀÌ¶§ ¸î°³±îÁö Çã¿ëÇÏ´ÂÁö¸¦ ¿©±â¼­ ÁöÁ¤ÇÑ´Ù.
		- »ç¿ëÀÚ°¡ ÁöÁ¤ÇØ¾ß ÇÑ´Ù.

		\~english
		If unreliable send, can perform routed multicast. This is where to decide how many of them are allowed.
		- User must define.

		\~chinese
		unreliable send îÜï×?ù»Ê¦ì¤?ú¼routed multicast¡£??î¤?×ìò¦ïÒÒöëÃ?ò¸??¡£
		- é©éÄ?ò¦ïÒ¡£

		\~japanese
		Unreliable sendªÎíŞùê¡¢routed multicastª¬ªÇª­ªŞª¹¡£ª³ªÎãÁ¡¢ù¼ËÁªŞªÇúÉé»ª¹ªëª«ªòª³ª³ªÇò¦ïÒª·ªŞª¹¡£
		- «æ?«¶?ª¬ò¦ïÒª·ªŞª¹¡£

		\~
		*/
		int m_unreliableS2CRoutedMulticastMaxCount;

		/**
		\~korean
		unreliable ¸Ş½ÃÂ¡ÀÎ °æ¿ì¿¡,
		routed multicast¸¦ ÇÒ ¼ö ÀÖ´Ù. ÀÌ¶§ ¾ó¸¶ ÀÌ»óÀÇ ·¢ ÀÌÇÏÀÇ ÇÇ¾î°£ Åë½Å¿¡¼­¸¸ Çã¿ëÇÏ´ÂÁö¸¦ ¿©±â¼­ ÁöÁ¤ÇÑ´Ù.
		- »ç¿ëÀÚ°¡ ÁöÁ¤ÇØ¾ß ÇÑ´Ù.

		\~english
		If unreliable messaging, can perform routed multicast. This is where to decide which rate of laggy P2P communications are allowed.
		- User must define.

		\~chinese
		åıÍıãÀUnreliable messagingîÜï×?£¬Ê¦ì¤?ú¼routed multicast¡£??î¤?×ìò¦ïÒñşëÃ?Òıá´ì¤ß¾îÜlagì¤ù»îÜpeerñı?÷×ãá¡£
		- é©éÄ?ò¦ïÒ¡£

		\~japanese
		Unreliable «á«Ã«»?«¸«ó«°ªÎíŞùê¡¢routed multicastª¬ªÇª­ªŞª¹¡£ª³ªÎãÁ¡¢ª¤ª¯ªéì¤ß¾ªÎ«é«Ã«¯ì¤ù»ªÎPeerÊàªÎ÷×ãáªÇªÎªßúÉé»ª¹ªëª«ªòª³ª³ªÇò¦ïÒª·ªŞª¹¡£
		- «æ?«¶?ª¬ò¦ïÒª·ªŞª¹¡£

		\~
		*/
		int m_unreliableS2CRoutedMulticastMaxPingMs;

		/**
		\~korean
		Á÷Á¢ ¸ÖÆ¼Ä³½ºÆ®¸¦ ÇÒ ¼ö ÀÖ´Â ÃÖ´ë °¹¼ö
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#throttling" >¼Û½Å·® ÀÚµ¿ Á¶Àı ±â´É (Throttling)</a> ±â¹ı Áß ÇÏ³ªÀÌ´Ù.
		- P2P ±×·ìÀ» ´ë»óÀ¸·Î RMI ¼Û½ÅÀ» ÇÒ °æ¿ì, ÀÌ °ªÀÌ NÀ¸·Î ÁöÁ¤µÈ °æ¿ì, P2P ±×·ì ¸â¹öÁß N°³ ¸¸Å­ÀÇ Å¸ peer¿¡°Ô´Â
		P2P·Î Á÷Á¢ Àü¼ÛÇÑ´Ù. (¹°·Ğ Å¸ peer°¡ Á÷Á¢ P2P Åë½ÅÀ» ÇÏ°í ÀÖ´Â °æ¿ì¿¡) ÇÏÁö¸¸ ³ª¸ÓÁö peerµé¿¡°Ô´Â
		Relayed P2P·Î Àü¼ÛÇÑ´Ù. ¼³·É Á÷Á¢ P2P Åë½ÅÀ» ÇÏ°í ÀÖ´õ¶óµµ ¸»ÀÌ´Ù. 0À» ÁöÁ¤ÇÏ¸é direct P2P ¼Û½Å ÀÚÃ¼¸¦ ¾ÈÇÔÀ» ÀÇ¹ÌÇÑ´Ù.
		- ÀÌ ±â´ÉÀº Å¬¶óÀÌ¾ğÆ®°¡ ´ë·®ÀÇ ¸ÖÆ¼Ä³½ºÆ®¸¦ ÇÏ´Â °æ¿ì, ±×¸®°í Å¬¶óÀÌ¾ğÆ®ÀÇ ¾÷·Îµå ¼ÓµµÀÇ ÇÑ°è°¡ Å« °æ¿ì(¿¹¸¦ µé¾î
		¾÷·Îµå ¼Óµµ°¡ ´À¸° ADSL È¸¼±) À¯¿ëÇÏ´Ù. ¿Ö³ÄÇÏ¸é ProudNet¿¡¼­´Â relayed P2PÀÇ ºê·ÎµåÄ³½ºÆ® °úÁ¤¿¡¼­ Å¬¶óÀÌ¾ğÆ®´Â
		1°³ÀÇ relayµÉ ¸Ş½ÃÁö¸¸À» ¼­¹ö¿¡°Ô º¸³»°í, ¼­¹ö´Â ±×°ÍÀ» ¿©·¯ Å¬¶óÀÌ¾ğÆ®µé¿¡°Ô º¸³»ÁÖ´Â ¿ªÇÒÀ» ÇÏ±â ¶§¹®ÀÌ´Ù.
		- ±âº»°ª: ¹«Á¦ÇÑ.
		- Å¬¶óÀÌ¾ğÆ®¿¡¼­ È£ÃâÇÏ´Â RMIÀÇ ÆÄ¶ó¸ŞÅÍ¿¡ Àü¿¡ ÀÌ °ªÀ» »ç¿ëÀÚ°¡ ÁöÁ¤ÇÒ ¼ö ÀÖ´Ù. ¼­¹ö¿¡¼­´Â ÀÌ °ªÀÌ ¾²ÀÌÁö ¾Ê´Â´Ù.

		\~english
		The maximum number of direct multicast can be performed
		- One of <a target="_blank" href="http://guide.nettention.com/cpp_en#throttling" >Traffic auto-control function (Throttling)</a>
		- When RMI transmitting to P2P group and the value is set as N, for N many of other peers of P2P group members, it will be trasmitted as direct P2P. (Of course when other peers communicate with direct P2P)
		  However, it will be transmitted to the other peers as relayed P2P even if they are performing direct P2P communications. If 0 is set then it means there is no P2P transmission at all.
		- This function is useful when client performs a large amount of multicasts and the speed limit of client upload (e.g. ADSL line with slower upload speed).
                  During broadcasting relayed P2P in Proudnet, client sends only 1 of message to be relayed then server performs the role that sends it to many other clients.
		- Default: infinite
		- User can designate this value to RMI parameter before it is called by client. At server, this value is not used.

		\~chinese
		ÒöòÁïÈ?ú¼multi castîÜõÌÓŞ??¡£
		- <a target="_blank" href="http://guide.nettention.com/cpp_zh#throttling" >í»???ãáãÓ?áêÕá(Throttling)</a>%ĞüÛöñéñıìé¡£
		- ì¤P2P???ßÚ?áêRMIîÜ?ı¦£¬÷êó®?ò¦ïÒ?N?£¬?P2P?à÷?ñéßÓ?éÍN?îÜĞìöâpeeréÄP2PòÁïÈ?áê£¨?æÔ£¬ãÀî¤ĞìöâpeeròÁïÈ?ú¼P2P÷×ãáîÜï×?ù»£©¡£Ó£ãÀ?í¥ù»îÜpeer£¬éÄrelayed P2P?áê¡£?ŞÅòÁïÈ?ú¼P2P÷×ãáå¥ãÀ¡£ò¦ïÒ0îÜ?ëòÚ«ó·Üô?ú¼direct P2PÜâãó¡£
		- ó®ÍíÒöî¤client?ú¼ÓŞÕámulti castîÜ?ı¦£¬?êóclientîÜß¾?áÜÓøîÜß¾ùÚÓŞîÜ?ı¦£¨ÖÇåıß¾?áÜÓøØ·îÜADSLüŞÖØ£©?êóüùÍı¡£ì×?î¤ProudNet?ú¼relayed P2PîÜbroadcast?ïïñéclientñş÷êìé?relayîÜãáãÓ?áê?Ü×?Ğï£¬Ü×?Ğï?÷êó®?é»?áê??ÒıclientîÜíÂéÄ¡£
		- Ùù??£ºÙéùÚğ¤¡£
		- î¤clientû¼Ğ£îÜRMI??ñıîñéÄ?Ê¦ì¤ò¦ïÒó®?¡£î¤Ü×?ĞïÜôéÄó®?¡£

		\~japanese
		òÁïÈ«Ş«ë«Á«­«ã«¹«Èª¬ªÇª­ªëõÌÓŞ?
		- \ref throttling ĞüÛöªÎª¦ªÁìéªÄªÇª¹¡£
		- P2P«°«ë?«×ªò?ßÚªËRMIáêãáªòª¹ªëíŞùê¡¢ª³ªÎö·ª¬NªÇò¦ïÒªµªìª¿íŞùê¡¢P2P«°«ë?«×«á«ó«Ğ?ñéªËNËÁªÀª±ªÎöâªÎpeerªËªÏP2PªÇòÁïÈ?áêª·ªŞª¹¡£(ªâªÁªíªó¡¢öâªÎpeerª¬òÁïÈP2P÷×ãáªóªòª·ªÆª¤ªëíŞùê)ª·ª«ª·¡¢?ªêªÎpeerª¿ªÁªËªÏRelayed P2PªÇ?áêª·ªŞª¹¡£ª¿ªÈª¨¡¢òÁïÈP2P÷×ãáªòª·ªÆª¤ªëªÈª·ªÆªâªÇª¹¡£0ªòò¦ïÒª¹ªìªĞdirect P2Páêãáí»?ªòª·ªÊª¤ª³ªÈªòëòÚ«ª·ªŞª¹¡£
		- ª³ªÎÑ¦ÒöªÏ«¯«é«¤«¢«ó«Èª¬ÓŞÕáªÎ«Ş«ë«Á«­«ã«¹«Èªòª¹ªëíŞùê¡¢ª½ª·ªÆ¡¢«¯«é«¤«¢«ó«ÈªÎ«¢«Ã«×«í?«ÉáÜÓøªÎùÚÍ£ª¬ÓŞª­ª¤íŞùê(ÖÇª¨ªĞ¡¢«¢«Ã«×«í?«ÉáÜÓøª¬?ª¤ADSLüŞàÊ)ë¯ÓôªÇª¹¡£ªÊª¼ªÊªé¡¢ProudNetªÇªÏrelayed P2PªÎ«Ö«í?«É«­«ã«¹«ÈÎ¦ïïªÇ«¯«é«¤«¢«ó«ÈªÏ1ËÁªÎrelayªµªìªë«á«Ã«»?«¸ªÎªßªò«µ?«Ğ?ªËáêªÃªÆ¡¢«µ?«Ğ?ªÏª½ªìªòÜÜ?ªÎ«¯«é«¤«¢«ó«ÈªËáêªëæµùÜªòª¹ªëª«ªéªÇª¹¡£ 
		- ĞñÜâö·£ºÙíğ¤ùÚ
		- «¯«é«¤«¢«ó«ÈªÇû¼ªÓõóª¹RMIªÎ«Ñ«é«á?«¿?ªÎîñªËª³ªÎö·ªò«æ?«¶?ª¬ò¦ïÒª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£«µ?«Ğ?ªÇªÏª³ªÎö·ªÏŞÅªïªìªŞª»ªó¡£

		\~
		*/
		int m_maxDirectP2PMulticastCount; // NOTE: ¼­¹ö°£ Åë½ÅÀÇ °æ¿ì µî ¶§¹®¿¡ »ç¿ëÀÚ°¡ ÀÓÀÇ ÁöÁ¤ÇÏÁö ¾Ê´ÂÇÑ ¹«Á¦ÇÑÀÌ´Ù.

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#message_unique_id" >ÃÖÁ¾ ¸Ş½ÃÁö¸¸ ¼ÛÃâÇÏ±â</a> ±â´ÉÀ» À§ÇÑ °íÀ¯°ªÀÔ´Ï´Ù.
		- ±âº»°ªÀº 0ÀÔ´Ï´Ù. 0ÀÎ °æ¿ì ´ÜÀÏÈ­µÇÁö ¾Ê½À´Ï´Ù.
		- ¼Û½ÅÇÒ ¸Ş½ÃÁö¸¦ ¼Û½Å Å¥¿¡¼­ ´ÜÀÏÈ­ÇÏ°íÀÚ ÇÑ´Ù¸é ÀÌ °ªÀ» 0 ÀÌ¿ÜÀÇ °ªÀ» ÁöÁ¤ÇÏ½Ê½Ã¿À.

		\~english
		Unique ID for <a target="_blank" href="http://guide.nettention.com/cpp_en#message_unique_id" >Transmitting the latest message only</a>.
		- Default is 0 and does not unify if 0.
		- If the mesage to be sent is to be unified at transmission queue then this value must not designate 0 but other value.

		\~chinese
		ãÀ?Öõ<a target="_blank" href="http://guide.nettention.com/cpp_zh#message_unique_id" >ñş?áêõÌ?ãáãÓ</a> ĞüÒöîÜÍ³êó?¡£
		- ĞñÜâ??0.ĞñÜâ??0?,Üôù¬?ìéûù¡£
		- åıÍıßÌ÷êáêãáãáãÓî¤áêãáqueueñé?ìéûù£¬??ĞñÜâ??öÇ?0ì¤èâîÜ?í®¡£

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#message_unique_id" >Transmitting the latest message only</a>Ñ¦ÒöªÎª¿ªáªÎÍ³êóö·ªÇª¹¡£
		- «Ç«Õ«©«ë«ÈªÏ£°ªÇª¹¡££°ªÎíŞùê¡¢?ìéûùªµªìªŞª»ªó¡£
		- áêãáª¹ªë«á«Ã«»?«¸ªòáêãá«­«å?ªÇ?ìéûùª¹ªëğ·ªËªÏ¡¢ª³ªÎö·ªò£°ì¤èâªÎö·ªÇò¦ïÒª·ªÆª¯ªÀªµª¤¡£
		\~
		*/
		int64_t m_uniqueID;

		/**
		\~korean
		¸Ş½ÃÁö ¼Û½Å ¿ì¼±¼øÀ§
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#message_priority" >¸Ş½ÃÁö ¼Û½Å ¿ì¼±¼øÀ§ ±â´É</a> Âü°í.
		- »ç¿ëÀÚ°¡ ÁöÁ¤ÇØ¾ß ÇÑ´Ù.
		- m_reliability°¡ reliable·Î ÁöÁ¤µÈ °æ¿ì ÀÌ °ªÀº ¹«½ÃµÈ´Ù.

		\~english
		Message trnasmission priority
		- Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#message_priority" >Prioritizing message transmission</a>.
		- User must define.
		- If m_reliability = reliable then this value is ignored.

		\~chinese
		ãáãÓ?áêîÜ?à»?ßí¡£
		- ?ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#message_priority" >ãáãÓ?áêîÜ?à»?ßíÍíÒö¡£</a>%¡£
		- é©éÄ?ò¦ïÒ¡£
		- m_reliability ù¬ò¦ïÒ?reliableîÜ?£¬ó®??ûì?¡£

		\~japanese
		«á«Ã«»?«¸áêãá«×«é«¤«ª«ê«Æ«£
		- \ref message_priority ?ÍÅ
		- «æ?«¶?ª¬ò¦ïÒª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
		- m_reliabilityª¬reliableªÇò¦ïÒªµªìªÆª¤ªëíŞùê¡¢ª³ªÎö·ªÏÙíãÊªµªìªŞª¹¡£ 

		\~
		*/
		mutable MessagePriority m_priority;

		/**
		\~korean
		¸Ş½ÃÁö ¼Û½Å ¸Ş¼­µå
		- »ç¿ëÀÚ°¡ ÁöÁ¤ÇØ¾ß ÇÑ´Ù.

		\~english
		Message trnasmission method
		- User must define.

		\~chinese
		ãáãÓ?áêÛ°Ûö¡£
		- é©éÄ?ò¦ïÒ¡£

		\~japanese
		«á«Ã«»?«¸áêãá«á«½«Ã«É
		- «æ?«¶?ª¬ò¦ïÒª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£

		\~
		*/
		MessageReliability m_reliability;

		/**
		\~korean
		ÀÌ °ªÀÌ falseÀÌ¸é RMI ¼ö½ÅÀÚ°¡ P2P ±×·ì µî º¹¼ö°³ÀÎ °æ¿ì ÀÚ±â ÀÚ½Å¿¡°Ô º¸³»´Â ¸Ş½ÃÂ¡(loopback)À» Á¦¿Ü½ÃÅµ´Ï´Ù.
		±âº»°ªÀº trueÀÔ´Ï´Ù.

		\~english
		While this value is false if there are 2 or more RMI receivers then excludes the messaging to itself(loopback).
		Default is true.

		\~chinese
		ó®?ãÀfalseîÜ?RMIâ¥ãáíºP2P?Ôõ???îÜ?ı¦÷ê??í»ĞùîÜmessaging£¨loopback£©ğ¶èâ¡£
		Ùù??ãÀtrue¡£

		\~japanese
		ª³ªÎö·ª¬falseªÇª¢ªìªĞ¡¢RMIáôãáíºª¬P2P«°«ë?«×ªÊªÉÜÜ?ªÇª¢ªëíŞùê¡¢í»Ğùí»ãóªËáêªë«á«Ã«»?«¸«ó«°(loopbakc)ªòğ¶èâªµª»ªŞª¹¡£
		ĞñÜâö·ªÏtrueªÇª¹¡£

		\~
		*/
		bool m_enableLoopback;

		/**
		\~korean
		»ç¿ëÀÚ°¡ ÁöÁ¤ÇÑ tag °ªÀÔ´Ï´Ù. <a target="_blank" href="http://guide.nettention.com/cpp_ko#host_tag" >°¢ È£½ºÆ®¿¡ ´ëÇÑ »ç¿ëÀÚ Á¤ÀÇ µ¥ÀÌÅÍ(Tag)</a> ±â´ÉÀÔ´Ï´Ù.
		- ÁÖÀÇ! : tag´Â ³×Æ®¿÷ µ¿±âÈ­°¡ µÇÁö ¾Ê´Â °ªÀÔ´Ï´Ù.

		\~english
		User defined tag value. A <a target="_blank" href="http://guide.nettention.com/cpp_en#host_tag" >User-defined data(Tag) for each host</a> function.
		- Caution!: tag is a value that cannot be network synchronized.

		\~chinese
		éÄ?ò¦ïÒîÜtag?¡£ãÀ<a target="_blank" href="http://guide.nettention.com/cpp_zh#host_tag" >?ÊÀ?ñ«ÏõîÜéÄ?ïÒ??Ëß£¨Tag£©</a>ÍíÒö ¡£
		- ñ¼ëò£¡£ºtag ãÀÙéÛö?ú¼??ÔÒÜÆîÜ?¡£

		\~japanese
		«æ?«¶?ª¬ò¦ïÒª·ª¿£ô£á£çö·ªÇª¹¡£\ref host_tagÑ¦ÒöªÇª¹¡£
		- ª´ñ¼ëò!£ºtagªÏ«Í«Ã«È«ï?«¯ÔÒÑ¢ûùª¬ªµªìªÊª¤ö·ªÇª¹¡£

		\~
		*/
		void* m_hostTag;

		// ³»ºÎ ¿ëµµ
		// trueÀÎ °æ¿ì ÀÌ RMI¼Û½ÅÀº JIT P2P È¦ÆİÄªÀ» Æ®¸®°ÅÇÑ´Ù. Non-PN RMI¿¡¼­¸¸ falseÀÌ´Ù.
		bool m_enableP2PJitTrigger;

		/**
		\~korean
		ÀÌ °ªÀÌ falseÀÌ¸é Unreliable·Î º¸³»·Á ÇÒ¶§, »ó´ë°¡ relay modeÀÌ¸é, º¸³»Áö ¾Ê½À´Ï´Ù.
		- ±âº»°ªÀº trueÀÔ´Ï´Ù.

		\~english
		While this value is false if opponent is relay mode then do not send it.
		- Default is true.

		\~chinese
		ó®?ãÀfalseîÜ?èÙUnreliable?áêîÜ?ı¦£¬?Û°ãÀrelay modeîÜ?Üô??áê¡£
		- Ùù??ãÀtrue¡£

		\~japanese
		ª³ªÎö·ª¬falseªÇª¢ªìªĞUnrelaibleªÇáêªíª¦ªÈª¹ªëãÁ¡¢ßÓâ¢ª¬Relay modeªÇª¢ªìªĞáêªêªŞª»ªó¡£
		- ĞñÜâö·ªÏtureªÇª¹¡£

		\~
		*/
		bool m_allowRelaySend;

        /**
		\~korean
		°­Á¦ ¸±·¹ÀÌ ÀÓ°èºñÀ² °ªÀÔ´Ï´Ù.
		ÀÌ °ªÀ» Á¶ÀıÇÏ¸é, P2P°£ Åë½Å ¼Óµµº¸´Ù ¸±·¹ÀÌ°¡ ´õ Åë½Å ¼Óµµ°¡ ºü¸¥ °æ¿ì ¸±·¹ÀÌ¸¦ ¼±ÅÃÇÒ ¼ö ÀÖ½À´Ï´Ù.

		- ¿¹¸¦ µé¾î ÇÇ¾î°£ ÆĞÅ¶ Àü¼Û ½Ã°£ÀÌ ¼­¹ö¸¦ ÅëÇØ ¸±·¹ÀÌÇÏ´Â ½Ã°£º¸´Ù 3¹è ´À¸° °æ¿ì¿¡´Â Á÷Á¢ ÇÇ¾î¿¡°Ô Àü¼ÛÇÒ
		¼ö ÀÖ´Ù ÇÏ´õ¶óµµ ¼­¹ö¸¦ ÅëÇØ ¸±·¹ÀÌÇÏ°í ½ÍÀ» ¼ö ÀÖ½À´Ï´Ù. ±×·¯ÇÑ °æ¿ì ÀÌ °ªÀ» 1/3À¸·Î ÁöÁ¤ÇÏ¸é µË´Ï´Ù.
		5¹è ´À¸° °æ¿ì¿¡ ÇÑÇØ °­Á¦ ¸±·¹ÀÌ¸¦ ¿øÇÒ °æ¿ì 1/5¸¦ ÁöÁ¤ÇÏ¸é µË´Ï´Ù. 0À» ÁöÁ¤ÇÏ¸é °­Á¦ ¸±·¹ÀÌ¸¦ ÇÏÁö ¾Ê½À´Ï´Ù.
		Áï, "Relay p2p ping / Direct p2p ping"ÀÌ ÀÌ °ªº¸´Ù ÀÛÀº °æ¿ì¿¡´Â °­Á¦·Î ¸±·¹ÀÌ·Î Àü¼ÛÇÕ´Ï´Ù.
		- Áß±¹¿¡¼­´Â P2P°£ Åë½Å ¼Óµµº¸´Ù ¼­¹ö¿Í Åë½ÅÇÏ´Â ¼Óµµ°¡ ÈÎ¾À ¿øÈ°ÇÑ È¯°æÀÌ ÀÖ´Ù°í ¾Ë·ÁÁ® ÀÖ½À´Ï´Ù.
		- ±âº»°ªÀº 0ÀÔ´Ï´Ù.

		\~english
		Forced relay critical rate value.
		If you change this value, it can select relay instead of P2P communication when relay is faster than P2p communication.

		-For example, If packet sending time is 3 times slower than relay through a server, you may relay it through server even it can send to peer directly. This case set this value to 1/3.
		Also if it is 5 times slower then set 1/5. If you set 0, it does not do forced relay.
		Therefore it does forced relay when "Relay p2p ping / Direct p2p ping" is smaller than this value.
		- In China, server-client is faster than P2P.
		- Default is 0

		\~chinese
		Ë­ğ¤relay?Í£İïáã?¡£
		?ïÚó®?îÜ?£¬?relay÷×ãááÜÓøİïP2P÷×ãááÜÓøÌÚ?îÜ?ı¦Ê¦ì¤??relay¡£

		- ÖÇåı£¬peer ñı??ËßøĞ?áê??İï÷×?Ü×?ĞïrelayîÜ??Ø·3ÛÃîÜ?ı¦£¬?ŞÅÒö?òÁïÈèÙpeer?áê£¬å¥Ê¦ÒößÌ÷×?Ü×?Ğïrelay¡£??÷êó®?ò¦ïÒ?1/3?Ê¦¡£ùÚ?Ø·5ÛÃîÜï×?£¬é©Ë­ğ¤relayîÜ?ı¦ò¦ïÒ1/5?Ê¦¡£ò¦ïÒà÷0îÜ?Üô?Ë­ğ¤relay¡£?£¬"Relay p2p ping / Direct p2p ping"İïó®?á³îÜ?£¬?áê?Ë­ğ¤relay¡£
		- Ëß?î¤ñé??Ü×?Ğï÷×ãáîÜáÜÓøİïP2Pñı?÷×ãááÜÓø?îÜÒı¡£
		- Ùù??ãÀ0¡£

		\~japanese
		?ğ¤«ê«ì?×üÍ£İïáãö·ªÇª¹¡£
		ª³ªÎö·ªòğàï½ª¹ªëªÈ¡¢P2PÊàªÎ÷×ãááÜÓøªèªê«ê«ì?ª¬ªâªÃªÈáÜª¤íŞùê¡¢«ê«ì?ªòàÔ?ª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
		- ÖÇª¨ªĞ¡¢PeerÊàªÎ«Ñ«±«Ã«È?áêãÁÊàª¬«µ?«Ğ?ªò÷×ª¸«ê«ì?ª¹ªëãÁÊàªèªê3ÛÃ?ª¤íŞùêªËªÏ¡¢òÁïÈPeerªË?áêª¹ªëª³ªÈª¬ªÇª­ªëªÈª·ªÆªâ«µ?«Ğ?ªò÷×ª¸«ê«ì?ª·ª¿ª¤íŞùêª¬ª¢ªêªŞª¹¡£ª½ªÎªèª¦ªÊíŞùê¡¢ª³ªÎö·ªò1/3ªËò¦ïÒª¹ªìªĞÕŞª¤ªÇª¹¡£
		5ÛÃ?ª¤íŞùêªËùÚªÃªÆ?ğ¤«ê«ì?ªòıñØĞª¹ªëíŞùê¡¢1/5ªòò¦ïÒª¹ªìªĞÕŞª¤ªÇª¹¡£0ªòò¦ïÒª¹ªìªĞ?ğ¤«ê«ì?ª¬ªÇª­ªŞª»ªó¡£
		?ªÁ¡¢"Relay p2p ping / Direct p2p ping"ª¬ª³ªÎö·ªèªêá³ªµª¤íŞùêªËªÏ¡¢?ğ¤«ê«ì?ªÇ?áêª·ªŞª¹¡£
		- ñé?ªÇªÏP2PÊàªÎ÷×ãááÜÓøªèªê«µ?«Ğ?ªÈ÷×ãáª¹ªëáÜÓøª¬ªÏªëª«ªËå÷üÁªÊü»ÌÑª¬ª¢ªëªÈò±ªéªìªÆª¤ªŞª¹¡£
		- ĞñÜâö·ªÏ0ªÇª¹¡£

		\~
		*/
        double m_forceRelayThresholdRatio;

        /**
		\~korean
		ProudNet Àü¿ë ¸Ş½ÃÁöÀÎÁö¿¡ ´ëÇÑ ½Äº°°ªÀÔ´Ï´Ù.
        - ±âº» falseÀÔ´Ï´Ù. falseÀÌ¸é udp ¸Ş½ÃÁö °¹¼ö¸¦ ÃøÁ¤ÇÕ´Ï´Ù.
        - Æ¯º°ÇÑ »óÈ²ÀÌ ¾Æ´Ï¸é ÀÌ°ªÀ» true·Î ¹Ù²ÙÁö ¸¶½Ê½Ã¿À.

		\~english
		Identifying value that message for only ProudNet or not
		- Default is false. If it is false then check number of udp messages.
		- Do not change it to true except special case.

		\~chinese
		?ProudNet?éÄãáãÓîÜ???¡£
		- Ùù??ãÀfalse¡£False îÜ??ïÒudpãáãÓ??¡£
		- ÜôãÀ÷åâ¨ï×?£¬Üôé©÷êó®?áóËÇà÷true¡£

		\~japanese
		ProudNet?éÄ«á«Ã«»?«¸ªÊªÎª«ªË?ª¹ªëãÛÜ¬ö·ªÇª¹¡£
		- ĞñÜâö·ªÏfalseªÇª¹¡£FalseªÇª¢ªìªĞUDP«á«Ã«»?«¸?ªòö´ïÒª·ªŞª¹¡£
		- ÷åÜ¬ªÊ?üÏªÇªÏªÊª±ªìªĞª³ªÎö·ªòtureªË?ª¨ªÊª¤ªÇª¯ªÀªµª¤¡£

		\~
		*/
        bool m_INTERNAL_USE_isProudNetSpecificRmi;

		/** \~korean trueÀÌ¸é, unreliable ¼Û½Å¿¡ ¾²ÀÌ´Â ¸Ş½ÃÁö¸¦ MTU Å©±â·Î ºĞÇÒÇØ¼­ º¸³À´Ï´Ù.
		UDP Ã³¸®·Î ÀÎÇØ ¼­¹ö°¡ CPU »ç¿ë·®ÀÌ ³ôÀ¸¸é ÀÌ°ÍÀ» ²¨ º¸¼¼¿ä.
		±âº»°ªÀº true ÀÔ´Ï´Ù.

		\~english Sends messages after fragmentation.
		If true, the message used in unreliable transmission is divided and sent into MTU size. 
		Turn this off if the server has high CPU use due to UDP processing. 
		The default value is true. 

		\~chinese NOTE: Machanical translation.
		åıÍıãÀtrue£¬ö¦÷êéÄéÍunreliable??îÜá¼ãÓİÂùÜà÷MTUîÜÓŞá³ñıı¨?áê¡£
		åıÍıì×UDP?×âì»ğ«ÍÔCPUîÜŞÅéÄáã£¬ö¦????¡£
		Ùù???true¡£

		\~japanese NOTE: Machanical translation.
		TrueªÇª¢ªìªĞ¡¢unreliableáêãáªËŞÅªïªìªë«á«Ã«»?«¸ªòMTU«µ«¤«ºªËİÂùÜª·ªÆáêªêªŞª¹¡£
		UDP?×âªËªèªÃªÆ«µ?«Ğ?ªÎCPUŞÅéÄÖùª¬ÍÔª±ªìªĞ¡¢ª³ªìªò«ª«Õª·ªÆª¯ªÀªµª¤¡£
		ĞñÜâö·ªÏtrueªÇª¹¡£

		\~
		*/
		bool m_fragmentOnNeed;


        /**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#encryption_usage" >Åë½Å ¸Ş½ÃÁö ¾ÏÈ£È­ÇÏ±â</a> ¿¡¼­ »ç¿ëµÇ´Â ¾ÏÈ£È­ ¾Ë°í¸®Áò ¼±ÅÃÀÔ´Ï´Ù.
		- ±âº»°ªÀº EM_None ÀÔ´Ï´Ù.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#encryption_usage" >Åë½Å ¸Ş½ÃÁö ¾ÏÈ£È­ÇÏ±â</a> ¿¡¼­ »ç¿ëµÇ´Â ¾ÏÈ£È­ ¾Ë°í¸®Áò ¼±ÅÃÀÔ´Ï´Ù.
		- Default EM_None .

		\~chinese
		??î¤<a target="_blank" href="http://guide.nettention.com/cpp_zh#encryption_usage" >Ê¥ÚË÷×ãáãáãÓ</a>%ŞÅéÄîÜÊ¥ÚËß¤?¡£
		- Ùù??ãÀEM_None¡£

		\~japanese
		\ref encryption_usageªÇŞÅªïªìªëäŞ?ûù«¢«ë«´«ê«º«ààÔ?ªÇª¹¡£ 
		- ĞñÜâö·ªÏEM_NoneªÇª¹¡£

		\~
		*/
        EncryptMode m_encryptMode;

		/**
		\~korean
        ¸Ş½ÃÁö ¾ĞÃà ±â´É ÀÔ´Ï´Ù. ÀÌ °ªÀ» CM_None ÀÌ¿Ü¸¦ ¼±ÅÃÇÒ °æ¿ì ¾ĞÃàÀ» ÇÏ¿© ¸Ş½ÃÁö¸¦ Àü¼ÛÇÕ´Ï´Ù.
        - ±âº»°ªÀº CM_None ÀÔ´Ï´Ù.
        - º¸³¾ ¸Ş½ÃÁöÀÇ Å©±â°¡ ³Ê¹« ÀÛ°Å³ª(¾à 50¹ÙÀÌÆ®) ¾ĞÃàÀ» ÇØµµ Å©±â°¡ ÀÛ¾ÆÁöÁö ¾ÊÀ¸¸é ¾ĞÃàÇÏÁö ¾Ê°í Àü¼ÛÇÕ´Ï´Ù.

		\~english TODO:translate needed.
		This is the message compression feature. When things other than CM_None is selected for this value, you can compress to send the message. 
		- The default value is CM_None
		- If the message to be sent is too small (approx. 50 bytes) or does not get smaller even if it¡¯s compressed, then send it uncompressed. 

		\~chinese
		ãáãÓ??ÍíÒö¡£÷êó®????CM_Noneì¤èâîÜ?ı¦£¬??ì¤ı¨?áêãáãÓ¡£
		- Ùù??ãÀCM_None¡£
		- é©?áêãáãÓîÜ÷¼á³£¨?50byte£¬ö¦Üô??òÁïÈ?áê¡£

		\~japanese
		«á«Ã«»?«¸?õêÑ¦ÒöªÇª¹¡£ª³ªÎö·ªòCM_Noneì¤èâªòàÔ?ª¹ªëíŞùê¡¢?õêª·ªÆ«á«Ã«»?«¸ªò?áêª·ªŞª¹¡£
		- ĞñÜâö·ªÏCM_NoneªÇª¹¡£
		- áêªë«á«Ã«»?«¸ªÎ«µ«¤«ºª¬ªÈªÆªâá³ªµª¤ª«(å³50«Ğ«¤«È)¡¢?õêª·ªÆªâ«µ«¤«ºª¬á³ªµª¯ªÊªéªÊª±ªìªĞ?õêª·ªÊª¯ªÆ?áêª·ªŞª¹¡£

		\~
		*/
        CompressMode m_compressMode;

		// ÁÖÀÇ: ¼öÁ¤½Ã ProudClrÀÇ µ¿¸í ½Éº¼µµ ¼öÁ¤ÇØ¾ß ÇÑ´Ù.
		PROUD_API RmiContext();

		// ÁÖÀÇ: ¼öÁ¤½Ã ProudClrÀÇ µ¿¸í ½Éº¼µµ ¼öÁ¤ÇØ¾ß ÇÑ´Ù.
		PROUD_API RmiContext( MessagePriority priority, MessageReliability reliability, int unreliableS2CRoutedMulticastMaxCount, EncryptMode encryptMode = EM_None);

		/**
		\~korean
		Reliable message·Î RMI È£Ãâ½Ã ÀÌ°ÍÀ» ÆÄ¶ó¸ŞÅÍ·Î ³ÖÀ¸¸é µÈ´Ù.
		- À¯Àú°¡ ¿øÇÏ¸é º°µµ·Î RmiContext °´Ã¼¸¦ µÖµµ ÁÁÁö¸¸ Åë»óÀûÀÎ °æ¿ì RMI È£Ãâ½Ã ÀÌ°ÍÀ» ±×³É ½áµµ µÈ´Ù.

		\~english
		This is to be entered as parameter when calling RMI as reliable message.
		- It is ok to use separate RmiContext object if needed but usually if the case is usual then it is ok to use this calling RMI.

		\~chinese
		éÄReliable messageû¼Ğ£RMI?£¬÷ê???ìı????Ê¦¡£
		- éÄ?ıñØĞîÜ?£¬?×º RmiContext%?ßÚå¥û¿£¬ìéÚõï×?ù»û¼Ğ£RMI?å¥Ê¦ì¤òÁïÈŞÅéÄ??¡£

		\~japanese
		Reliable messageªÇRMIªòû¼ªÓõóª¹ãÁ¡¢ª³ªìªò«Ñ«é«á?«¿?ªÇìıªìªìªĞª¤ª¤ªÇª¹¡£
		- «æ?«¶?ª¬ıñØĞª¹ªìªĞ¡¢Ü¬Ô²ªÇRmiContext«ª«Ö«¸«§«¯«ÈªòöÇª¤ªÆªâÕŞª¤ªÇª¹ª¬¡¢÷×ßÈªÎíŞùê¡¢RMIªòû¼ªÓõóª¹ªÈª³ªìªòª½ªÎªŞªŞŞÅªÃªÆªâÕŞª¤ªÇª¹¡£

		\~
		*/
		PROUD_API static RmiContext ReliableSend;

		/**
		\~korean
		EM_Fast ¸ğµå·Î ¾ÏÈ£È­ ÇÏ¿© Reliable message ·Î RMI È£Ãâ½Ã ÀÌ°ÍÀ» ÆÄ¶ó¸ŞÅÍ·Î ³ÖÀ¸¸é µÈ´Ù.
		- ±âÅ¸ »çÇ×Àº ReliableSend ¿Í °°½À´Ï´Ù.

		\~english
		Encrypt with EM_Fast mode then put this as parameter when you call RMI with Reliable message.
		- All other details are same as ReliableSend.

		\~chinese
		ì¤EM_FastÙ¼ãÒÊ¥ÚËì¤ı¨éÄReliable messageû¼Ğ£RMI?£¬÷ê???ìı????Ê¦¡£
		- Ğìöâ??ReliableSendßÓÔÒ¡£

		\~japanese
		EM_Fast «â?«ÉªÇäŞ?ûùª·ªÆ¡¢Reliable messageªÇRMIªòû¼ªÓõóª¹ãÁ¡¢ª³ªìªò«Ñ«é«á?«¿?ªÇìıªìªìªĞÕŞª¤ªÇª¹¡£
		- ª½ªÎöâŞÀú£ªÏReliableSendªÈÔÒª¸ªÇª¹¡£

		\~
		*/
		PROUD_API static RmiContext FastEncryptedReliableSend;

		/**
		\~korean
		EM_Secure ¸ğµå·Î ¾ÏÈ£È­ ÇÏ¿© Reliable message·Î RMI È£Ãâ½Ã ÀÌ°ÍÀ» ÆÄ¶ó¸ŞÅÍ·Î ³ÖÀ¸¸é µÈ´Ù.
		- ±âÅ¸ »çÇ×Àº ReliableSend ¿Í °°½À´Ï´Ù.

		\~english
		Encrypt with EM_Secure mode then put this as parameter when you call RMI with Reliable message.
		- All other details are same as ReliableSend.

		\~chinese
		ì¤EM_SecureÙ¼ãÒÊ¥ÚËì¤ı¨éÄReliable messageû¼Ğ£RMI?£¬÷ê???ìı????Ê¦¡£
		- Ğìöâ??ReliableSendßÓÔÒ¡£

		\~japanese
		EM_Secure«â?«ÉªÇäŞ?ûùª·ªÆReliable messageªÇRMIªòû¼ªÓõóª¹ãÁ¡¢ª³ªìªò«Ñ«é«á?«¿?ªÇìıªìªìªĞÕŞª¤ªÇª¹¡£
		- ª½ªÎöâŞÀú£ªÏReliableSendªÈÔÒª¸ªÇª¹¡£

		\~
		*/
		PROUD_API static RmiContext SecureReliableSend;





		/**
		\~korean
		Unreliable message·Î RMI È£Ãâ½Ã ÀÌ°ÍÀ» ÆÄ¶ó¸ŞÅÍ·Î ³ÖÀ¸¸é µÈ´Ù.
		- À¯Àú°¡ ¿øÇÏ¸é º°µµ·Î RmiContext °´Ã¼¸¦ µÖµµ ÁÁÁö¸¸ Åë»óÀûÀÎ °æ¿ì RMI È£Ãâ½Ã ÀÌ°ÍÀ» ±×³É ½áµµ µÈ´Ù.
		- HIGH priority·Î ÁöÁ¤µÇ¾î ÀÖ´Ù.

		Âü°í »çÇ×
		- ÀÏ¹İÀûÀÎ ¿Â¶óÀÎ °ÔÀÓ¿¡¼­ ÀüÃ¼ Åë½Å·®ÀÇ ´ëºÎºĞÀº Ä³¸¯ÅÍ ÀÌµ¿, ¿¬»ç °ø°İ°ú °°Àº ¸î Á¾·ùÀÇ ¸Ş½ÃÁö¸¸ÀÌ Â÷ÁöÇÏ¸ç
		±× ¿ÜÀÇ ¼ö¸¹Àº ¸Ş½ÃÁöµéÀº ³·Àº ºñÁßÀ» Â÷ÁöÇÑ´Ù. ±×¸®°í ÃæºĞÈ÷ °ËÅäÇÏÁö ¾Ê°í unreliable send¸¦ ¾µ °æ¿ì Á¾Á¾
		Àå½Ã°£ÀÇ ¹®Á¦ ÇØ°á ½Ã°£À¸·Î ÀÌ¾îÁö°ï ÇÑ´Ù. ÀÌ·¯ÇÑ °æÇèÀ» °í·ÁÇßÀ»¶§ ¿Â¶óÀÎ °ÔÀÓ °³¹ß ÃÊ±â °úÁ¤¿¡¼­´Â À¢¸¸ÇÑ ¸Ş½ÃÁö´Â
		¸ğµÎ reliable send¸¦ ¾²°Ô ¸¸µé´Ù°¡ ³×Æ®¿÷ Åë½Å·® ÇÁ·ÎÇÊ¸µ µîÀ» ÅëÇØ ´ëºÎºĞÀÇ Åë½Å·®À» Â÷ÁöÇÏÁö¸¸ ´©½ÇÀÌ °¨´çµÇ´Â ¸Ş½ÃÁöµé¸¸
		Ã£¾Æ¼­ unreliable send·Î ¹Ù²ãÁÖ´Â °Íµµ ÁÁÀº °³¹ß ¹æ¹ıÀÌ¶ó ¸»ÇÒ ¼ö ÀÖ´Ù.

		\~english
		This is to be entered as parameter when calling RMI as reliable message.
		- It is ok to use separate RmiContext object if needed but usually if the case is usual then it is ok to use this calling RMI.
		- Set as HIGH priority.

		Reference
		- Generally in most of online games, most of overall communications consist of a few different types of mesages such as character movement, attacking actions and so on while others have significantly low proportion.
		And there have been many cases where unreliable send was used without enough considerations then caused to spend hours of debugging time.
		Considering those experiences, it is believed to say that making everything use reliable send at the beginning then replace only those that can handle losses to unreliable can be a good way to develop an online game.

		\~chinese
		éÄUnreliable messageû¼Ğ£RMI?£¬÷ê???ìı????Ê¦¡£
		- éÄ?ıñØĞîÜ?£¬?×º RmiContext%?ßÚå¥û¿£¬ìéÚõï×?ù»û¼Ğ£RMI?å¥Ê¦ì¤òÁïÈŞÅéÄ??¡£
		- ù¬ò¦ïÒ?HIGH priority¡£

		?ÍÅŞÀßÚ
		- î¤ìéÚõîÜ??êı?ñé£¬îïİ»÷×ãáÕáîÜÓŞİ»İÂãÀë¦ÊÇßäì¹?£¬?ŞÒÍô?Ôõ??ãáãÓá¶ï¿êó£¬ñıèâîÜ?ÒıãáãÓï¿Ëßİïñì?î¸¡£ì»ó¦Üô?ú¼õöİÂîÜ??ı¨ŞÅéÄunreliable sendîÜ?ı¦£¬?êó??âÍé©???ú°?îÜ??îÜ?ßæ¡£ÍÅ?Óğ????£¬î¤??êı???ôøÑ¢?ìéÚõîÜãáãÓ?öÇà÷éÄreliable send£¬?æÔ???÷×???÷×ãáÕáprofilingÔõï¿ËßÓŞİ»İÂ÷×ãáÕá£¬Ó£ãÀÊ¦ì¤??Òö??×µã÷îÜãáãÓ£¬??ĞìáóËÇà÷unreliable sendå¥Ê¦ì¤?ãÀ?û¿îÜ??Û°Ûö¡£

		\~japanese
		Unreliable messageªÇRMIªòû¼ªÓõóª¹ãÁ¡¢ª³ªìªò«Ñ«é«á?«¿?ªÇìıªìªìªĞÕŞª¤ªÇª¹¡£
		- «æ?«¶?ª¬ıñØĞª¹ªìªĞ¡¢Ü¬Ô²ªÇRmiContext«ª«Ö«¸«§«¯«ÈªòöÇª¤ªÆªâÕŞª¤ªÇª¹ª¬¡¢÷×ßÈªÎíŞùê¡¢RMIªòû¼ªÓõóª¹ªÈª³ªìªòª½ªÎªŞªŞŞÅªÃªÆªâÕŞª¤ªÇª¹¡£
		- HIGH priorityªÇò¦ïÒªµªìªÆª¤ªŞª¹¡£
		?ÍÅŞÀú£
		- ìéÚõîÜªÊ«ª«ó«é«¤«ó«²?«àªÇîï?÷×ãáÕáªÎªÛªÈªóªÉªÏ«­«ã«é«¯«¿?ì¹ÔÑ¡¢Ö§ŞÒÍô?ªÎªèª¦ªÊ?ğú×¾ªÎ«á«Ã«»?«¸ªÎªßª¬ï¿ªáªÆ¡¢ª½ªÎèâªÎ?Òıª¤«á«Ã«»?«¸ªÏî¸ª¤İïñìªòï¿ªáªŞª¹¡£ª½ª·ªÆ¡¢ä¨İÂ?÷Ğª»ªºªËunreliable sendªòŞÅª¦íŞùê¡¢éÏªËíşãÁÊàªÎÙığ¹ú°Ì½ãÁÊàªËªÄªÊª¬ªëª³ªÈª¬ª¢ªêªŞª¹¡£ª³ªÎªèª¦ªÊ??ªòÍÅÕçª·ª¿ãÁ¡¢«ª«ó«é«¤«ó«²?«àËÒ?ªÎôøÑ¢Î¦ïïªÇªÏ¡¢ªÛªÈªóªÉªÎ«á«Ã«»?«¸ªÏreliable sendªòŞÅª¦ªèª¦ªËª·ªÆ¡¢«Í«Ã«È«ï?«¯÷×ãáÖùªÎ«×«í«Õ«£?«ê«ó«°ªÊªÉªò÷×ª¸ªÛªÈªóªÉªÎ÷×ãáÖùªòï¿ªáªŞª¹ª¬¡¢×©ª¨ª¤ª¬â¢ªËİ¶ª¨ªÊª¤«á«Ã«»?«¸ªÎªßªò÷®ª·ªÆunreliable sendªË?ª¨ªÆª¯ªìªëª³ªÈªâÕŞª¤ËÒ?Û°ÛöªÈåëª¨ªŞª¹¡£

		\~
		*/
		PROUD_API static RmiContext UnreliableSend;

		/**
		\~korean
		EM_Fast ¸ğµå·Î ¾ÏÈ£È­ ÇÏ¿© Unreliable message·Î RMI È£Ãâ½Ã ÀÌ°ÍÀ» ÆÄ¶ó¸ŞÅÍ·Î ³ÖÀ¸¸é µÈ´Ù.
		- ±âÅ¸ »çÇ×Àº UnreliableSend ¿Í °°½À´Ï´Ù.

		\~english
		Encrypt with EM_Fast mode then put this as parameter when you call RMI with Reliable message.
		- All other details are same as ReliableSend.

		\~chinese
		ì¤EM_FastÙ¼ãÒÊ¥ÚËì¤ı¨éÄUnreliable messageû¼Ğ£RMI?£¬÷ê???ìı????Ê¦¡£
		- Ğìöâ??UnreliableSendßÓÔÒ¡£

		\~japanese
		EM_Fast«â?«ÉªÇäŞ?ûùª·ªÆUnreliable messageªÇRMIªòû¼ªÓõóª¹ãÁ¡¢ª³ªìªò«Ñ«é«á?«¿?ªÇìıªìªìªĞÕŞª¤ªÇª¹¡£
		- ª½ªÎöâŞÀú£ªÏUnrelaibleSendªÈÔÒª¸ªÇª¹¡£

		\~
		*/
		PROUD_API static RmiContext FastEncryptedUnreliableSend;


		/**
		\~korean
		EM_Secure ¸ğµå·Î ¾ÏÈ£È­ ÇÏ¿© Unreliable message·Î RMI È£Ãâ½Ã ÀÌ°ÍÀ» ÆÄ¶ó¸ŞÅÍ·Î ³ÖÀ¸¸é µÈ´Ù.
		- ±âÅ¸ »çÇ×Àº UnreliableSend¿Í °°½À´Ï´Ù.

		\~english
		Encrypt with EM_Secure mode then put this as parameter when you call RMI with Reliable message.
		- All other details are same as ReliableSend.

		\~chinese
		ì¤EM_SecureÙ¼ãÒÊ¥ÚËì¤ı¨éÄUnreliable messageû¼Ğ£RMI?£¬÷ê???ìı????Ê¦¡£
		- Ğìöâ??UnreliableSendßÓÔÒ¡£

		\~japanese
		EM_Secure«â?«ÉªÇäŞ?ûùª·ªÆUnreliable messageªÇRMIªòû¼ªÓõóª¹ãÁ¡¢ª³ªìªò«Ñ«é«á?«¿?ªÇìıªìªìªĞÕŞª¤ªÇª¹¡£
		- ª½ªÎöâŞÀú£ªÏUnrelaibleSendªÈÔÒª¸ªÇª¹¡£

		\~
		*/
		PROUD_API static RmiContext SecureUnreliableSend;





		/**
		\~korean
		Unreliable server to client multicast message·Î RMI È£Ãâ½Ã ÀÌ°ÍÀ» ÆÄ¶ó¸ŞÅÍ·Î ³ÖÀ¸¸é µÈ´Ù.
		- À¯Àú°¡ ¿øÇÏ¸é º°µµ·Î RmiContext °´Ã¼¸¦ µÖµµ ÁÁÁö¸¸ Åë»óÀûÀÎ °æ¿ì RMI È£Ãâ½Ã ÀÌ°ÍÀ» ±×³É ½áµµ µÈ´Ù.
		- Medium priority·Î ÁöÁ¤µÇ¾î ÀÖ´Ù.
		- ÀÌ ±â´ÉÀº, ¼­¹ö¿¡¼­ ¿©·¯°³ÀÇ Å¬¶óÀÌ¾ğÆ®·Î unreliable RMI ºê·ÎµåÄ³½ºÆ® È£ÃâÀ» ÇÒ ¶§ ¼ö½ÅÀÚ Áß P2P Á÷Á¢ ¿¬°áÀÌ µÇ¾î ÀÖ´Â °Íµé³¢¸®´Â
		P2P¸¦ ÅëÇÑ routed send¸¦ ÇÏ°Ô ÇÑ´Ù. ÀÌ ±â´ÉÀº ¼­¹ö¿¡¼­ÀÇ CPU »ç¿ë·®À» ¾à°£ Áõ°¡½ÃÅ°´Â ´ñ°¡·Î ¼­¹ö¿¡¼­ Å¬¶óÀÌ¾ğÆ®·ÎÀÇ ¼Û½Å
		Åë½Å·®À» Àı°¨ÇÑ´Ù. (´ëºÎºĞÀÇ °ÔÀÓ¿¡¼­ À¯¿ëÇÏ°Ô ¾²ÀÏ ¼ö ÀÖ´Ù.)

		\~english
		This is unreliable server to client multicast message and this is to be entered as parameter when calling RMI.
		- It is ok to use separate RmiContext object if needed but usually if the case is usual then it is ok to use this calling RMI.
		- Set as HIGH priority.
		- This function performs routed send via P2P for those direct P2P connected among receivers when server calls unreliable RMI broadcast to multiple clients.
		This function saves the amount of transmission from server to client in exchange of increase of CPU use in server. (Can be very useful in most of games.)

		\~chinese
		éÄUnreliable server to client multicast messageû¼Ğ£RMI?£¬÷ê???ìı????Ê¦¡£
		- éÄ?ıñØĞîÜ?£¬?×º RmiContext%?ßÚå¥Ê¦ì¤£¬ìéÚõï×?ù»û¼Ğ£RMI?å¥Ê¦ì¤òÁïÈŞÅéÄ??¡£
		- ò¦ïÒ?Medium priority¡£
		- ó®ÍíÒöãÀ£¬î¤Ü×?ĞïéÄ??client?ú¼unreliable RMI broadcastû¼Ğ£îÜ?ı¦£¬P2P òÁïÈ?ïÈîÜâ¥ãáíºñı???ú¼÷×?P2PîÜrouted send¡£ó®ÍíÒöãÀì¤õªÚ°ñòÊ¥CPUŞÅéÄÕá?ÓÛËÀ£¬?á´?Ü×?ĞïèÙclientîÜ?áê÷×ãáÕá¡£

		\~japanese
		Unreliable server to client multicast messageªÇRMIªòû¼ªÓõóª¹ãÁ¡¢ª³ªìªò«Ñ«é«á?«¿?ªÇìıªìªìªĞÕŞª¤ªÇª¹¡£
		- «æ?«¶?ª¬ıñØĞª¹ªìªĞ¡¢Ü¬Ô²ªÇRMI Context«ª«Ö«¸«§«¯«ÈªòöÇª¤ªÆªâÕŞª¤ªÇª¹ª¬¡¢÷×ßÈªÎíŞùêªÏ¡¢RMIªòû¼ªÓõóª¹ãÁ¡¢ª³ªìªòª½ªÎªŞªŞŞÅªÃªÆªâÕŞª¤ªÇª¹¡£
		- Medium priorityªÇò¦ïÒªµªìªÆª¤ªŞª¹¡£
		- ª³ªÎÑ¦ÒöªÏ¡¢«µ?«Ğ?ªÇÜÜ?ªÎ«¯«é«¤«¢«ó«ÈªËunreliable RMI«Ö«í?«É«­«ã«¹«Èû¼ªÓõóª·ªòª¹ªëãÁ¡¢áôãáíºªÎñéªÇP2PòÁïÈïÈ?ª¬ªÇª­ªÆª¤ªëªâªÎÔÒŞÍªÇªÏP2Pªò÷×ª¸ªërouted sendª¬ªÇª­ªëªèª¦ªËª·ªŞª¹¡£ª³ªÎÑ¦ÒöªÏ«µ?«Ğ?ªÇªÎCPUŞÅéÄÕáªòá´ª·?Ê¥ªµª»ªë??ªÈª·ªÆ¡¢«µ?«Ğ?ªèªê«¯«é«¤«¢«ó«ÈªØªÎáêãá÷×ãáÖùªòï½Êõª·ªŞª¹¡£(ªÛªÈªóªÉªÎ«²?«àªÇêóéÄªËŞÅªïªìªëª³ªÈª¬ª¢ªêªŞª¹¡£)


		\~
		*/
		PROUD_API static RmiContext UnreliableS2CRoutedMulticast;

		PROUD_API void AssureValidation() const;
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#include "RmiContext.inl"
