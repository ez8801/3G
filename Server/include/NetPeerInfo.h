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

#include "BasicTypes.h"
#include "AddrPort.h"
#include "Enums.h"
#include "HostIDArray.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup net_group
	*  @{
	*/


	/**
	\~korean
	»ó´ë È£½ºÆ®ÀÇ Á¤º¸ ±¸Á¶Ã¼

	\~english
	Information construct of opponent host

	\~chinese
	?Û°ñ«ÏõîÜãáãÓ?ğã?¡£

	\~japanese
	ßÓâ¢«Û«¹«ÈªÎï×ÜÃÏ°ğã?
	\~
	*/
	class CNetPeerInfo
	{
	public:
		/**
		\~korean
		¼­¹ö¿¡¼­ ¹Ù¶óº» Å¬¶óÀÌ¾ğÆ®ÀÇ UDP socketÀÇ ÁÖ¼Ò. Áï, Å¬¶óÀÌ¾ğÆ®°¡ ¼­¹ö¿ÍÀÇ È¦ÆİÄªÀÌ ¿Ï·áµÈ ÈÄÀÇ ÀÎ½ÄµÈ ÁÖ¼Ò
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#get_holepunched_info" >Å¬¶óÀÌ¾ğÆ®ÀÇ È¦ÆİÄªµÈ ÁÖ¼Ò¸¦ ¾ò±â</a>  ¹× <a target="_blank" href="http://guide.nettention.com/cpp_ko#use_alternative_p2p" >ProudNetÀ» ¾²Áö ¾Ê°í ProudNetÀÇ È¦ÆİÄª Á¤º¸¸¦ Åä´ë·Î º°µµ UDP ¼ÒÄÏÀ¸·Î Åë½ÅÇÏ±â</a>  ¼±°á ÀÌÇØ¸¦ ±ÇÀåÇÕ´Ï´Ù.
		- ¼­¹ö¿Í ¿¬°áÀÌ °« ³¡³­ Å¬¶óÀÌ¾ğÆ®´Â AddrPort.Unassigned ÀÌ´Ù°¡ ¼ö ÃÊ ÀÌ³»¿¡ È¦ÆİÄªµÈ °ªÀ¸·Î ¹Ù²ò´Ï´Ù.
		µû¶ó¼­ °øÀ¯±âÀÇ Á¾·ù ¶Ç´Â °øÀ¯±â ¼³Á¤¿¡ µû¶ó È¦ÆİÄªÀÌ ¿µ±¸ÀûÀ¸·Î ¼º°øÇÏÁö ¸øÇÒ ¼öµµ ÀÖ½À´Ï´Ù. ÀÌ·¯ÇÑ °æ¿ì ÀÌ °ªÀº
		°è¼ÓÇØ¼­ AddrPort.Unassigned ÀÏ ¼öµµ ÀÖ½À´Ï´Ù.
		- ¹İµå½Ã ÀÌ °ªÀÌ P2P È¦ÆİÄªµÈ Å¬¶óÀÌ¾ğÆ®ÀÇ ÁÖ¼Ò¸¦ ÀÇ¹ÌÇÏÁö´Â ¾Ê½À´Ï´Ù. ±× °ªÀº ¿£Áø ³»ºÎ¿¡¼­ °ü¸®µË´Ï´Ù.

		\~english
		Address of TCP socket of peer from server perspective. In other words, recognized address after finished t hole-punching from client to server.
		- We recommend to understand <a target="_blank" href="http://guide.nettention.com/cpp_en#get_holepunched_info" >Earning hole-punched address of client</a> and <a target="_blank" href="http://guide.nettention.com/cpp_en#use_alternative_p2p" >Communicating with a separated UDP socket based on ProudNet hole-punched information without using ProudNet.</a> first.
		- The client jsut completed connecting to server has AddrPort.Unassigned value and changed to have hole-punched value within seconds.
		  That means depending ontype and/or settings of router, the hole-punching can never be successful. If this happens, the value can remain as the value of AddrPort.Unassigned.
		- This value does not necessarily mean the address of P2P hole-punched client address. The value is managed internally by engine.

		\~chinese
		î¤Ü×?Ğï×ìá¶Ê×ÓğîÜclientîÜUDP socketò¢ò£¡£?£¬client ?Ü×?ĞïîÜöèÔ×èÇà÷ı¨îÜ??ò¢ò£¡£
		- Ëï?<a target="_blank" href="http://guide.nettention.com/cpp_zh#get_holepunched_info" >?ö¢ËÔ?Ó®ì«?ú¼öèÔ×îÜò¢ò£</a>%Ğà<a target="_blank" href="http://guide.nettention.com/cpp_zh#use_alternative_p2p" >ÜôŞÅéÄProudNet£¬ñşĞñéÍProudNetîÜöèÔ×ï×?éÄ?èâîÜUDPSocket?ú¼÷×ãá</a>%îÜ?à»×âú°¡£
		- ?Ü×?ĞïîÜ?ïÈ??áÖîÜèÌÊ«à»ãÀ AddrPort.Unassigned £¬?õ©ì¤ı¨ËÇà÷ì«ù¬öèÔ×îÜ?¡£
		ì×ó®£¬?ó·ÖØë¦ĞïîÜ??ûäíºÖØë¦ĞïîÜ?öÇ£¬öèÔ×Ê¦ÒöÜô?çµÎùàõîÜà÷Íí¡£??ı¦ó®?Ê¦ÒöìéòÁ?ãÀ AddrPort.Unassigned%¡£
		- ???ÜôãÀù±?ëòÚ«ó·P2Pù¬öèÔ×îÜclientò¢ò£¡£Ñá??î¤ìÚÌÖ?İ»Î·×â¡£


		\~japanese
		«µ?«Ğ?ª«ªéÌ¸ª¿«¯«é«¤«¢«ó«ÈªÎUDP socketªÎ«¢«É«ì«¹¡£?ªÁ¡¢«¯«é«¤«¢«ó«Èª¬«µ?«Ğ?ªÈªÎ«Û?«ë«Ñ«ó«Á«ó«°ª¬èÇÖõªµªìª¿ı­ªÎìããÛ«¢«É«ì«¹
		- \ref get_holepunched_info ĞàªÓ \ref use_alternative_p2p ªòà»ªË×âú°ª¹ªëª³ªÈªòªª?ªáª·ªŞª¹¡£
		- «µ?«Ğ?ªÈªÎïÈ?ª¬ğûªïªÃª¿ªŞªŞªÎ«¯«é«¤«¢«ó«ÈªÏAddrPort.UnassignedªÇª¹ª¬¡¢?õ©ì¤?ªË«Û?«ë«Ñ«ó«Á«ó«°ªµªìª¿ö·ªË?ªïªêªŞª¹¡£ªèªÃªÆ¡¢«ë?«¿?ªÎğú×¾ªŞª¿ªÏ«ë?«¿?àâïÒªËªèªÃªÆ«Û?«ë«Ñ«ó«Á«ó«°ª¬çµÎùîÜªËà÷ÍíªÇª­ªÊª¤ª³ªÈªâª¢ªêªŞª¹¡£ª³ªÎªèª¦ªÊíŞùê¡¢ª³ªÎö·ªÏ?ª±ªÆAddrPort.UnassignedªËªÊªëª³ªÈªâª¢ªêªŞª¹¡£
		- ù±ªº¡¢ª³ªÎö·ª¬P2P«Û?«ë«Ñ«ó«Á«ó«°ªµªìª¿«¯«é«¤«¢«ó«ÈªÎ«¢«É«ì«¹ªòëòÚ«ª¹ªëª³ªÈªÏª¢ªêªŞª»ªó¡£ª½ªÎö·ªÏ«¨«ó«¸«ó?İ»ªÇÎ·×âªµªìªŞª¹¡£
		\~
		*/
		AddrPort m_UdpAddrFromServer;

		/**
		\~korean
		peer ³»ºÎ¿¡¼­ÀÇ UDP socketÀÇ ÁÖ¼Ò
		- ¼­¹ö¿ÍÀÇ UDP È¦ÆİÄªÀÌ ¾ÆÁ÷ ¾È³¡³­ Å¬¶óÀÌ¾ğÆ®, Áï TCP·Î¸¸ Åë½ÅÁßÀÎ Å¬¶óÀÌ¾ğÆ®´Â ÀÌ °ªÀÌ UnassignedÀÏ ¼ö ÀÖ½À´Ï´Ù. ±×·¯³ª ºñÁ¤»ó »óÈ²Àº ¾Æ´Õ´Ï´Ù.

		\~english
		Address of UDP socket inside of peer
		- The client that has not comp[leted UDP hole-punching with server, in other words the client communicating only through TCP can have this value as unassigned. But this is not abnormal situation.

		\~chinese
		î¤peer?İ»îÜUDP socketò¢ò£¡£
		- ?Ü×?ĞïîÜUDPöèÔ×??êó?áÖîÜclient¡£??éÍñşéÄTCP÷×ãáîÜclient£¬ó®?Ê¦Òö?unassigned¡£Ó£ÜôãÀŞªïáßÈï×?¡£

		\~japanese
		peer ?İ»ªÇªÎUDP socketªÎ«¢«É«ì«¹
		- «µ?«Ğ?ªÈªÎUDP«Û?«ë«Ñ«ó«Á«ó«°ª¬ªŞªÀğûªïªÃªÆªÊª¤«¯«é«¤«¢«ó«È¡¢?ªÁ¡¢TCPªØªÎªß÷×ãáª·ªÆª¤ªë«¯«é«¤«¢«ó«ÈªÏ¡¢ª³ªÎö·ª¬UnassignedªÎíŞùêªâª¢ªêªŞª¹¡£ª·ª«ª·¡¢ì¶ßÈ?üÏªÇªÏª¢ªêªŞª»ªó¡£ 
		\~
		*/
		AddrPort m_UdpAddrInternal;

		/**
		\~korean
		CNetServer ¿¡¼­ ÇÒ´çÇØÁØ peer ÀÇ int.

		\~english
		Int of peer that allocated by CNetServer.

		\~chinese
		î¤ CNetServer%İÂÛÕîÜpeerîÜint¡£

		\~japanese
		CNetServerªèªêùÜªê?ªÆªéªìª¿peerªÎint.
		\~
		*/
		HostID m_HostID;

		/**
		\~korean
		trueÀÌ¸é ÀÌ Å¬¶óÀÌ¾ğÆ® peer·ÎÀÇ RMI´Â ¼­¹ö¸¦ °æÀ¯ÇÏ´Â P2P relay¸¦
		ÇÔÀ» ÀÇ¹ÌÇÕ´Ï´Ù.
		- CNetClient ¿¡¼­¸¸ À¯È¿ÇÑ °ª.

		\~english
		If true then RMI towards to peer of tis client P2P relayes.
		- Only valid in CNetClient

		\~chinese
		TrueîÜ?ëòÚ«ó·ó®client peerîÜRMI?ú¼?ë¦Ü×?ĞïîÜP2P relay¡£
		- ñşêóî¤ CNetClient%ãÀêóüù?¡£

		\~japanese
		TrueªÇª¢ªìªĞª³ªÎ«¯«é«¤«¢«ó«ÈªÎpeerªØªÎRMIªÏ«µ?«Ğ?ªò?ë¦ª¹ªëP2P relayªòëòÚ«ª·ªŞª¹¡£
		- CNetClientªÇªÎªßêó?ªÊö· 
		\~
		*/
		bool m_RelayedP2P;

		/**
		\~korean
		ÀÌ client°¡ Âü¿©ÇÏ°í ÀÖ´Â P2P ±×·ìÀÇ ¸®½ºÆ®
		- CNetServer, CNetClient ¸ğµÎ¿¡¼­ À¯È¿ÇÕ´Ï´Ù.

		\~english
		P2P group list that this client is participating
		- Valid in both CNetServer and CNetClient

		\~chinese
		ó®client??îÜP2P?îÜÖªøú¡£
		- î¤ CNetServer, CNetClient%îïİ»êóüù¡£

		\~japanese
		ª³ªÎ«¯«é«¤«¢«ó«Èª¬?Ê¥ª·ªÆª¤ªëP2P«°«ë?«×ªÎ«ê«¹«È
		- CNetServer, CNetClient ªÎ?Û°ªÇêó?ªÇª¹¡£ 
		\~
		*/
		HostIDArray m_joinedP2PGroups;

		/**
		\~korean
		trueÀÎ °æ¿ì ÀÌ Å¬¶óÀÌ¾ğÆ®´Â NAT ÀåÄ¡ µÚ¿¡ ÀÖÀ½À» ÀÇ¹ÌÇÕ´Ï´Ù.
		- CNetServer, CNetClient ¸ğµÎ¿¡¼­ À¯È¿ÇÕ´Ï´Ù.

		\~english
		If true then this client is behind NAT device
		- Valid in both CNetServer and CNetClient

		\~chinese
		True îÜ?ëòÚ«ó·ó®clientî¤NAT?öÇı¨Øü¡£
		- î¤ CNetServer, CNetClient%îïİ»êóüù¡£

		\~japanese
		trueªÎíŞùê¡¢ª³ªÎ«¯«é«¤«¢«ó«ÈªÏNAT?öÇªÎı­ªËª¢ªëª³ªÈªòëòÚ«ª·ªŞª¹¡£
		- CNetServer, CNetClient ªÎ?Û°ªÇêó?ªÇª¹¡£ 
		\~
		*/
		bool m_isBehindNat;

		/**
		\~korean
		ÃÖ±Ù¿¡ ÃøÁ¤µÈ pingÀÇ Æò±Õ ½Ã°£ (¹Ğ¸®ÃÊ´ÜÀ§)
		- CNetClient.GetPeerInfo ¿¡¼­ ¾òÀº °æ¿ì: ÇØ´ç P2P peerÀÇ pingÀÔ´Ï´Ù.
		- CNetServer.GetClientInfo ¿¡¼­ ¾òÀº °æ¿ì: ¼­¹ö-Å¬¶ó°£ÀÇ pingÀÔ´Ï´Ù.

		\~english
		Recently measured the average time of ping (in Millisecond)
		- If from CNetClient.GetPeerInfo: ping of the P2P peer
		- If from CNetServer.GetClientInfo: ping between server and client

		\~chinese
		õÌĞÎ??îÜpingîÜøÁĞ³??£¨ûÆõ©?êÈ£©¡£
		- î¤ CNetClient.GetPeerInfo%?ÔğîÜï×?£ºßÓ?P2P peerîÜping¡£
		- î¤ CNetServer.GetClientInfo%?ÔğîÜï×?£ºÜ×?Ğï-client ñı?îÜping¡£

		\~japanese
		õÌĞÎªËö´ïÒªµªìª¿pingªÎøÁĞ³ãÁÊà£¨«ß«êõ©?êÈ£©
		- CNetClient.GetPeerInfo ªèªêÔğª¿íŞùê£ºú±?P2P peerªÎpingªÇª¹¡£ 
		- CNetServer.GetClientInfoªèªêÔğª¿íŞùê£º«µ?«Ğ?«¯«é«¤«¢«ó«ÈÊàªÎpingªÇª¹¡£ 
		\~
		*/
		int m_recentPingMs;

		/**
		\~korean
		ÀÌ peer·ÎÀÇ ¼Û½Å ´ë±âÁßÀÎ ¸Ş½ÃÁöÀÇ ÃÑ·®(¹ÙÀÌÆ® ´ÜÀ§) ÀÔ´Ï´Ù.
		- ¼­¹ö¿¡¼­ peer ¿¡ ´ëÇØ ¾ò´Â °æ¿ì ¼­¹ö=>Å¬¶óÀÌ¾ğÆ® ¼Û½Å¿¡ ´ëÇÑ ÃÑ·®ÀÔ´Ï´Ù.
		- Å¬¶óÀÌ¾ğÆ®¿¡¼­ peer ¿¡ ´ëÇØ ¾ò´Â °æ¿ì Å¬¶óÀÌ¾ğÆ®=>Å¬¶óÀÌ¾ğÆ® ¼Û½Å¿¡ ´ëÇÑ ÃÑ·®(´Ü, relayµÇ´Â ¸Ş½ÃÁö¿¡ ´ëÇØ¼­´Â Á¦¿Ü)

		\~english
		Total amount(in byte) of waiting messages to be sent to this peer
		- If getting from peer by server: Total amount of transmission by client
		- If getting from peer by client: Total amount of transmission by client (but excluding relayed messages)

		\~chinese
		éÄó®peerîÜÔõÓâ?áêîÜãáãÓ?Õá£¨byte ?êÈ£©¡£
		- î¤Ü×?Ğï?peer?ÔğîÜï×?£ºÜ×?Ğï=>client ?áêãáãÓîÜ?Õá¡£
		- î¤client?peer?ÔğîÜï×?£ºclient=>client ?áêãáãÓîÜ?Õá£¨Ó££¬?relayîÜãáãÓÖÇèâ£©¡£

		\~japanese
		ª³ªÎpeerªØªÎáêãáªòÓâªÃªÆª¤ªë«á«Ã«»?«¸ªÎ?Õá£¨«Ğ«¤«È?êÈ£©ªÇª¹¡£
		- «µ?«Ğ?ªèªêpeerªË?ª·ªÆÔğªëíŞùê¡¢«µ?«Ğ?=>«¯«é«¤«¢«ó«ÈáêãáªË?ª¹ªë?ÕáªÇª¹¡£
		- «¯«é«¤«¢«ó«ÈªèªêpeerªË?ª·ªÆÔğªëíŞùê¡¢«¯«é«¤«¢«ó«È=>«¯«é«¤«¢«ó«ÈáêãáªË?ª¹ªë?Õá£¨Ó£ª·¡¢relayªµªìªÊª¤«á«Ã«»?«¸ªË?ª·ªÆªÏğ¶èâ£©
		\~
		*/
		int m_sendQueuedAmountInBytes;

		/**
		\~korean
		»ç¿ëÀÚ°¡ ÁöÁ¤ÇÑ tagÀÇ Æ÷ÀÎÅÍÀÔ´Ï´Ù.
		- CNetServer.SetHostTag, CNetClient.SetHostTag À» ÅëÇØ ÁöÁ¤ÇÑ °ªÀÔ´Ï´Ù.
		- ÁÖÀÇ! : tag´Â ³×Æ®¿÷ µ¿±âÈ­°¡ µÇÁö ¾Ê´Â °ªÀÔ´Ï´Ù.

		\~english
		Pointer of user defined tag
		- A value set by CNetServer.SetHostTag and CNetClient.SetHostTag
		- Attention!: tag is a value that cannot be network synchronized.

		\~chinese
		éÄ?ò¦ïÒîÜtagò¦?¡£
		- ÷×? CNetServer.SetHostTag,  CNetClient.SetHostTag%ò¦ïÒîÜ?¡£
		- ñ¼ëò£¡£ºtag ãÀ?êó??ÔÒÜÆîÜ?¡£

		\~japanese
		«æ?«¶?ª¬ò¦ïÒª·ª¿tagªÎ«İ«¤«ó«¿?ªÇª¹¡£
		- CNetServer.SetHostTag, CNetClient.SetHostTagªò÷×ª¸ò¦ïÒª·ª¿ö·ªÇª¹¡£ 
		- ª´ñ¼ëò!£ºtagªÏ«Í«Ã«È«ï?«¯ÔÒÑ¢ûùª¬ö¢ªìªÊª¤ö·ªÇª¹¡£ 
		\~
		*/
		void* m_hostTag;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®ÀÇ Frame Rate ÀÔ´Ï´Ù.
		- CNetClient.SetApplicationHint ¿¡ »ç¿ëÀÚ°¡ ÀÔ·ÂÇÑ °ªÀÔ´Ï´Ù.
		- P2P ±×·ìÀ» ¸ÎÀº °¢ ÇÇ¾îµéÀÇ Frame Rate ¸¦ È®ÀÎÇÏ°íÀÚ ÇÒ ¶§ »ç¿ëÇÕ´Ï´Ù.
		- ÇÎ°ú ÇÔ²² ¼öÆÛÇÇ¾î ¼±Á¤¿¡ »ç¿ëÇÒ ¼ö ÀÖ½À´Ï´Ù.
		- Frame rate´Â Åë½Å·® Àı°¨À» À§ÇÏ¿© Àü¼Û½Ã float°ªÀ¸·Î º¯È¯µÇ¾î ¼Û¼ö½Å µË´Ï´Ù.

		\~english
		Frame Rate of client
		- User input value at CNetClient.SetApplicationHint
		- It uses to check Frame Rate that each peers in P2P group
		- You can use to select super peer with ping
		- To reduce traffic, it sends/receives with float value

		\~chinese
		Client îÜFrame Rate¡£
		- éÄ?î¤ CNetClient.SetApplicationHint%?ìıîÜ?¡£
		- é©?ïÒ?ïÈP2P?îÜÊÀpeerîÜFrame RateîÜ?ı¦ŞÅéÄ¡£
		- ?pingìéÑÃÊ¦ì¤ŞÅéÄéÍsuper peer?ïÒ¡£
		- Frame rate ?Öõ?á´÷×ãáÕá£¬?áê????float?ı¨?áêãáãÓ¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªÎFrame RateªÇª¹¡£
		- CNetClient.SetApplicationHintªË«æ?«¶?ª¬ìıÕôª·ª¿ö·ªÇª¹¡£
		- P2P«°«ë?«×ªòÌ¿ªóªÀÊÀ«Ô?«¢ªÎFrame Rateªòü¬ìãª·ª¿ª¤ãÁªËŞÅª¤ªŞª¹¡£
		- pingªÈªÈªâªËsuper peerªÎàâïÒªËŞÅª¦ª³ªÈª¬ªÇª­ªŞª¹¡£
		- Frame rateªÏ÷×ãáÖùªÎï½ÊõªÎª¿ªáªË¡¢?áêãÁªËfloatö·ªË?üµª·ªÆáêáôãáªµªìªŞª¹¡£ 
		\~
		*/
		double m_directP2PPeerFrameRate;

		/**
		\~korean
		ÀÚ½Å(CNetClient)ÀÌ ÇØ´ç Å¬¶ó¿¡°Ô Udp packetÀ» Àü¼Û ½ÃµµÇÑ ÃÑ °¹¼ö

		\~english
		Total attempted number of sending Udp packet from CNetClient to other client

		\~chinese
		í»ãó£¨CNetClient£©???ßÓ?client?áêUDP packetîÜ???¡£

		\~japanese
		í»İÂ(CNetClient)ª¬ú±?«¯«é«¤«¢«ó«ÈªËUDP packetªÎáêãáªò?ú¼ª·ª¿??
		\~
		*/
		uint32_t m_toRemotePeerSendUdpMessageTrialCount;

		/**
		\~korean
		ÀÚ½Å(CNetClient)ÀÌ ÇØ´ç Å¬¶ó¿¡°Ô Udp packetÀ» Àü¼ÛÇØ¼­ ¼º°øÇÑ ÃÑ °¹¼ö

		\~english
		Total succeed number of sending Udp packet from CNetClient to other client

		\~chinese
		í»ãó£¨CNetClient£©?ßÓ?clientà÷Íí?áêUDP packetîÜ???¡£

		\~japanese
		í»İÂ(CNetClient)ª¬ú±?«¯«é«¤«¢«ó«ÈªËUDP packetªÎáêãáªòà÷Ííª·ª¿??
		\~
		*/
        uint32_t m_toRemotePeerSendUdpMessageSuccessCount;

		int64_t m_unreliableMessageReceiveSpeed;

		PROUD_API CNetPeerInfo();

		String ToString(bool atServer);

		/**
		\~korean
		UDP Data Àü¼ÛµÇ´Â ÀüÃ¼ Byte ¼ö

		\~english
		The number of total bytes that transmits the UDP data

		\~chinese
		UDP Û°ãÒ??îÜá¶êóí®??


		\~japanese
		UDP Data áêãáªµªìªëîï?«Ğ«¤«È?
		\~
		*/
		int64_t m_udpSendDataTotalBytes;



#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// ÀÌ Å¬·¡½º´Â ProudNet DLL °æ¿ì¸¦ À§ÇØ Ä¿½ºÅÒ ÇÒ´çÀÚ¸¦ ¾²µÇ fast heapÀ» ¾²Áö ¾Ê½À´Ï´Ù.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif
	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
