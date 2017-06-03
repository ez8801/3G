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
	Information structure of other host

	\~chinese
	?Û°ñ«ÏõîÜãáãÓ?ğã?¡£

	\~japanese
	ßÓâ¢«Û«¹«ÈªÎï×ÜÃÏ°ğã?
	\~
	*/
	class CNetClientInfo
	{
	public:
		/**
		\~korean
		¼­¹ö¿¡¼­ ¹Ù¶óº» peerÀÇ TCP socketÀÇ ÁÖ¼Ò. Áï °øÀÎ ÀÎÅÍ³İ ÁÖ¼Ò(external addr)ÀÔ´Ï´Ù.
		- ¼­¹ö¿Í ¿¬°áµÆÁö¸¸ ¾ÆÁ÷ È¦ÆİÄªÀÌ ¼º»çµÇÁö ¾ÊÀº Å¬¶óÀÌ¾ğÆ®µµ ¾îÂ·°Å³ª ÁÖ¼Ò´Â ¾òÀ» ¼ö ÀÖ¾î¾ß ÇÏ¹Ç·Î ÀÌ ÇÊµå°¡ Á¸ÀçÇÕ´Ï´Ù.
		- º¸¾ÈÀ» À§ÇØ, Å¬¶óÀÌ¾ğÆ®¿¡¼­´Â Å¸ remote peer¿¡ ´ëÇÑ ÀÌ °ªÀ» ¾òÁö ¸øÇÕ´Ï´Ù.

		\~english
		TCP socket address of peer from server side. It is official internet address (external addr).
		- Client is connected to server but it does not success hole-punching yet. Anyway it need to get address so that is why this field exists.
		- Other remote peer can not get this value as security reason.

		\~chinese
		î¤Ü×?Ğï×ìá¶Ê×ÓğîÜpeerîÜTCP socketò¢ò£¡£?Íë?û»??ò¢ò££¨external addr£©¡£
		- ?æÔì«??Ü×?Ğï?ïÈ£¬Ó£ì×??êóöèÔ×îÜèÌÊ«å¥é©?Ôğò¢ò££¬á¶ì¤âÍé©???æ´¡£
		- ?ÖõäÌîï£¬èÌÊ«ÜôÒö?ÔğĞìöâremote peerîÜ?¡£

		\~japanese
		«µ?«Ğ?ª«ªéÌ¸ª¿PeerªÎTCP socketªÎ«¢«É«ì«¹¡£?ªÁ¡¢«Ñ«Ö«ê«Ã«¯«¤«ó«¿?«Í«Ã«È«¢«É«ì«¹(external addr)ªÇª¹¡£
		- «µ?«Ğ?ªËªÄªÊª¬ªêªŞª·ª¿ª¬¡¢ªŞªÀ«Û?«ë«Ñ«ó«Á«ó«°ªËà÷Ííª·ªÆª¤ªÊª¤«¯«é«¤«¢«ó«ÈªâªÉª¦ª·ªÆªâ«¢«É«ì«¹ªÏÔğªëù±é©ª¬ª¢ªêªŞª¹ªÎªÇ¡¢ª³ªÎ«Õ«£?«ë«Éª¬ğíî¤ª·ªŞª¹¡£
		- «»«­«å«ê«Æ«£ªÎª¿ªáªË¡¢«¯«é«¤«¢«ó«ÈªÇªÏöâªÎremote peerªË?ª¹ªëª³ªÎö·ªòÔğªéªìªŞª»ªó¡£
		\~
		*/
		AddrPort m_TcpAddrFromServer;

		/**
		\~korean
		¼­¹ö¿¡¼­ ¹Ù¶óº» Å¬¶óÀÌ¾ğÆ®ÀÇ UDP socketÀÇ ÁÖ¼Ò. Áï, Å¬¶óÀÌ¾ğÆ®°¡ ¼­¹ö¿ÍÀÇ È¦ÆİÄªÀÌ ¿Ï·áµÈ ÈÄÀÇ ÀÎ½ÄµÈ ÁÖ¼Ò
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#get_holepunched_info" >Å¬¶óÀÌ¾ğÆ®ÀÇ È¦ÆİÄªµÈ ÁÖ¼Ò¸¦ ¾ò±â</a>  ¹× <a target="_blank" href="http://guide.nettention.com/cpp_ko#use_alternative_p2p" >ProudNetÀ» ¾²Áö ¾Ê°í ProudNetÀÇ È¦ÆİÄª Á¤º¸¸¦ Åä´ë·Î º°µµ UDP ¼ÒÄÏÀ¸·Î Åë½ÅÇÏ±â</a>  ¼±°á ÀÌÇØ¸¦ ±ÇÀåÇÕ´Ï´Ù.
		- ¼­¹ö¿Í ¿¬°áÀÌ °« ³¡³­ Å¬¶óÀÌ¾ğÆ®´Â AddrPort.Unassigned ÀÌ´Ù°¡ ¼ö ÃÊ ÀÌ³»¿¡ È¦ÆİÄªµÈ °ªÀ¸·Î ¹Ù²ò´Ï´Ù.
		µû¶ó¼­ °øÀ¯±âÀÇ Á¾·ù ¶Ç´Â °øÀ¯±â ¼³Á¤¿¡ µû¶ó È¦ÆİÄªÀÌ ¿µ±¸ÀûÀ¸·Î ¼º°øÇÏÁö ¸øÇÒ ¼öµµ ÀÖ½À´Ï´Ù. ÀÌ·¯ÇÑ °æ¿ì ÀÌ °ªÀº
		°è¼ÓÇØ¼­ AddrPort.Unassigned ÀÏ ¼öµµ ÀÖ½À´Ï´Ù.
		- ¹İµå½Ã ÀÌ °ªÀÌ P2P È¦ÆİÄªµÈ Å¬¶óÀÌ¾ğÆ®ÀÇ ÁÖ¼Ò¸¦ ÀÇ¹ÌÇÏÁö´Â ¾Ê½À´Ï´Ù. ±× °ªÀº ¿£Áø ³»ºÎ¿¡¼­ °ü¸®µË´Ï´Ù.

		\~english
		Client's UDP socket address from server side. It is recognized address once client finished hole-punching with server.
		- We recommend to understand <a target="_blank" href="http://guide.nettention.com/cpp_en#get_holepunched_info" >Earning hole-punched address of client</a> and <a target="_blank" href="http://guide.nettention.com/cpp_en#use_alternative_p2p" >Communicating with a separated UDP socket based on ProudNet hole-punched information without using ProudNet.</a> first.
		- Client that just finished connecting to server is AddrPort.Unassigned then it changes to hole-punched value within second. So hole-punching never success depends on type or setting of router.
		This case, value can be AddrPort.Unassigned.
		- Sometimes, this value does not mean address of P2P hole-punched client. This value will manange from internal of engine.

		\~chinese
		î¤Ü×?Ğïá¶?îÜclient UDP socketò¢ò£¡£?client?Ü×?ĞïîÜöèÔ×à÷Ííı¨ù¬??îÜò¢ò£¡£
		- Ëï??à»×âú°<a target="_blank" href="http://guide.nettention.com/cpp_zh#get_holepunched_info" >?ö¢ËÔ?Ó®ì«?ú¼öèÔ×îÜò¢ò£</a>%Ğà<a target="_blank" href="http://guide.nettention.com/cpp_zh#use_alternative_p2p" >ÜôŞÅéÄProudNet£¬ñşĞñéÍProudNetîÜöèÔ×ï×?éÄ?èâîÜUDPSocket?ú¼÷×ãá</a>%¡£
		- ?Ü×?ĞïîÜ?ïÈ??áÖîÜèÌÊ«à»ãÀ AddrPort.Unassigned%£¬î¤?õ©ì¤??ËÇà÷ì«ù¬öèÔ×îÜ?¡£
		ì×ó®£¬?ó·ÖØë¦ĞïîÜ??ûäíºÖØë¦ĞïîÜ?öÇ£¬öèÔ×Ê¦ÒöÜô?çµÎùàõîÜà÷Íí¡£??ı¦ó®?Ê¦ÒöìéòÁ?ãÀ AddrPort.Unassigned%¡£
		- ???ÜôãÀù±?ëòÚ«ó·P2Pù¬öèÔ×îÜclientò¢ò£¡£Ñá??î¤ìÚÌÖ?İ»Î·×â¡£

		\~japanese
		«µ?«Ğ?ª«ªéÌ¸ª¿«¯«é«¤«¢«ó«ÈªÎUDP socketªÎ«¢«É«ì«¹¡£?ªÁ¡¢«¯«é«¤«¢«ó«Èª¬«µ?«Ğ?ªÈªÎ«Û?«ë«Ñ«ó«Á«ó«°ª¬èÇÖõª·ª¿ı­ªÎìããÛ«¢«É«ì«¹
		- \ref get_holepunched_info ĞàªÓ\ref use_alternative_p2pªòà»ªË×âú°ª¹ªëª³ªÈªòªª?ªáª·ªŞª¹¡£
		- «µ?«Ğ?ªÈªÎïÈ?ª¬ğûªïªÃª¿ªŞªŞªÎ«¯«é«¤«¢«ó«ÈªÏ¡¢AddrPort.UnassignedªÇª¢ªëª¬¡¢?õ©ì¤?ªË«Û?«ë«Ñ«ó«Á«ó«°ªµªìª¿ö·ªË?ªïªêªŞª¹¡£
		ªèªÃªÆ¡¢«ë?«¿?ªÎğú×¾ªŞª¿ªÏ«ë?«¿?àâïÒªËªèªÃªÆ«Û?«ë«Ñ«ó«Á«ó«°ª¬çµÎùîÜªËà÷ÍíªÇª­ªÊª¤ª«ªâò±ªìªŞª»ªó¡£ª³ªÎªèª¦ªÊíŞùê¡¢ª³ªÎö·ªÏ?ª±ªÆ AddrPort.UnassignedªËªÊªëª³ªÈªâª¢ªêªŞª¹¡£
		- ù±ªºª³ªÎö·ª¬P2P«Û?«ë«Ñ«ó«Á«ó«°ªµªìª¿«¯«é«¤«¢«ó«ÈªÎ«¢«É«ì«¹ªòëòÚ«ª¹ªëª³ªÈªÏª¢ªêªŞª»ªó¡£ª½ªÎö·ªÏ«¨«ó«¸«ó?İ»ªÇÎ·×âªµªìªŞª¹¡£
		\~
		*/
		AddrPort m_UdpAddrFromServer;

		/**
		\~korean
		peer ³»ºÎ¿¡¼­ÀÇ UDP socketÀÇ ÁÖ¼Ò
		- ¼­¹ö¿ÍÀÇ UDP È¦ÆİÄªÀÌ ¾ÆÁ÷ ¾È³¡³­ Å¬¶óÀÌ¾ğÆ®, Áï TCP·Î¸¸ Åë½ÅÁßÀÎ Å¬¶óÀÌ¾ğÆ®´Â ÀÌ °ªÀÌ UnassignedÀÏ ¼ö ÀÖ½À´Ï´Ù. ±×·¯³ª ºñÁ¤»ó »óÈ²Àº ¾Æ´Õ´Ï´Ù.

		\~english
		UDP socket address of inside of peer
		- Client that has not finished UDP hole-punching with server. If client communicate wiht only TCP, it can be Unassigned. However it is not wrong situation.

		\~chinese
		î¤peer?İ»îÜUDP socketò¢ò£¡£
		- ?Ü×?ĞïîÜUDPöèÔ×??êó?áÖîÜclient¡£??éÍñşéÄTCP÷×ãáîÜclient£¬ó®?Ê¦Òö?unassigned¡£Ó£ÜôãÀŞªïáßÈï×?¡£

		\~japanese
		peer?İ»ªÇªÎUDP socketªÎ«¢«É«ì«¹¡£
		- «µ?«Ğ?ªÈªÎUDP«Û?«ë«Ñ«ó«Á«ó«°ª¬ªŞªÀğûªïªÃªÆª¤ªÊª¤«¯«é«¤«¢«ó«È¡¢?ªÁ¡¢TCPªØªÎªß÷×ãáª·ªÆª¤ªë«¯«é«¤«¢«ó«ÈªÏª³ªÎö·ª¬UnassignedªËªÊªëª³ªÈª¬ª¢ªêªŞª¹¡£ª·ª«ª·¡¢ì¶ßÈ?üÏªÇªÏª¢ªêªŞª»ªó¡£

		\~
		*/
		AddrPort m_UdpAddrInternal;

		/**
		\~korean
		CNetServer ¿¡¼­ ÇÒ´çÇØÁØ peer ÀÇ int.

		\~english
		int of peer that assigned from CNetServer

		\~chinese
		î¤ CNetServer%İÂÛÕîÜpeerîÜint¡£

		\~japanese
		CNetServerªÇùÜªê?ªÆª¿peerªÎint.  
		\~
		*/
		HostID m_HostID;

		/**
		\~korean
		trueÀÌ¸é ÀÌ Å¬¶óÀÌ¾ğÆ® peer·ÎÀÇ RMI´Â ¼­¹ö¸¦ °æÀ¯ÇÏ´Â P2P relay¸¦
		ÇÔÀ» ÀÇ¹ÌÇÕ´Ï´Ù.
		- CNetClient ¿¡¼­¸¸ À¯È¿ÇÑ °ª.

		\~english
		If it is ture, it means this client peer is doing P2P relay with RMI through a server.
		- Available value on CNetClient

		\~chinese
		TrueîÜ?ëòÚ«ó·ó®client peerîÜRMI?ú¼?ë¦Ü×?ĞïîÜP2P relay¡£
		- ñşêóî¤ CNetClient%ãÀêóüù?¡£

		\~japanese
		TrueªÇª¢ªìªĞ¡¢ª³ªÎ«¯«é«¤«¢«ó«ÈpeerªØªÎRMIªÏ«µ?«Ğ?ªò?ë¦ª¹ªëP2P relayªòú¼ª¦ª³ªÈªòëòÚ«ª·ªŞª¹¡£
		- CNetClientªÇªÎªßêó?ªÊö· 
		\~
		*/
		bool m_RelayedP2P;

		/**
		\~korean
		ÀÌ client°¡ Âü¿©ÇÏ°í ÀÖ´Â P2P ±×·ìÀÇ ¸®½ºÆ®
		- CNetServer, CNetClient ¸ğµÎ¿¡¼­ À¯È¿ÇÕ´Ï´Ù.

		\~english
		P2P group list that this client joined with
		- It is available at CNetServer, CNetClient.

		\~chinese
		ó®client??îÜP2P?îÜÖªøú¡£
		- î¤ CNetServer, CNetClient%îïİ»êóüù¡£

		\~japanese
		ª³ªÎ«¯«é«¤«¢«ó«Èª¬?Ê¥ª·ªÆª¤ªëP2P«°«ë?«×ªÎ«ê«¹«È
		- CNetServer, CNetClientªÎ?Û°ªÇêó?ªÇª¹¡£ 
		\~
		*/
		HostIDSet m_joinedP2PGroups;

		/**
		\~korean
		trueÀÎ °æ¿ì ÀÌ Å¬¶óÀÌ¾ğÆ®´Â NAT ÀåÄ¡ µÚ¿¡ ÀÖÀ½À» ÀÇ¹ÌÇÕ´Ï´Ù.
		- CNetServer, CNetClient ¸ğµÎ¿¡¼­ À¯È¿ÇÕ´Ï´Ù.

		\~english
		If it is true, it means this client locates behind of NAT device.
		- It is available at CNetServer, CNetClient.

		\~chinese
		TrueîÜ?ëòÚ«ó·ó®clientî¤NAT?öÇı¨Øü¡£
		- î¤ CNetServer, CNetClient%îïİ»êóüù¡£

		\~japanese
		TrueªÎíŞùê¡¢ª³ªÎ«¯«é«¤«¢«ó«ÈªÏNAT?öÇªÎ×êªËª¢ªëª³ªÈªòëòÚ«ª·ªŞª¹¡£
		- CNetServer, CNetClientªÎ?Û°ªÇêó?ªÇª¹¡£ 
		\~
		*/
		bool m_isBehindNat;

		/**
		\~korean
		trueÀÎ °æ¿ì ÀÌ Å¬¶óÀÌ¾ğÆ®´Â ¼­¹ö¿ÍÀÇ UDP Åë½ÅÀÌ À¯ÁöµÇ°í ÀÖÀ½À» ÀÇ¹ÌÇÕ´Ï´Ù.
		falseÀÎ °æ¿ì UDP Åë½ÅÀÌ ºÒ°¡´ÉÇÏ±â ¶§¹®¿¡ TCP°¡ UDP ´ë½Å »ç¿ëµÇ°í ÀÖÀ½À» ÀÇ¹ÌÇÕ´Ï´Ù.

		\~english
		If it is ture, it means UDP communication between this client and server is still up and running.
		If it is false, it means TCP is being used because UDP communication is impossible.

		\~chinese
		TrueîÜ?ëòÚ«ó·ó®client?ò¥ó·?Ü×?ĞïîÜUDP÷×ãá¡£
		False îÜ?ëòÚ«ó·ì×?ÙéÛö?ú¼UDP÷×ãá£¬TCP ÓÛôğUDPá¶ŞÅéÄ¡£

		\~japanese
		TureªÎíŞùê¡¢ª³ªÎ«¯«é«¤«¢«ó«ÈªÏ«µ?«Ğ?ªÈªÎUDP÷×ãáª¬ë«ò¥ªµªìªÆª¤ªëª³ªÈªòëòÚ«ª·ªŞª¹¡£
		FalseªÎíŞùê¡¢UDP÷×ãáª¬ªÇª­ªÊª¤ªÎªÇ¡¢TCPª¬UDPªÎÓÛªïªêªËŞÅªÃªÆª¤ªëª³ªÈªòëòÚ«ª·ªŞª¹¡£
		\~
		*/
		bool m_realUdpEnabled;

		/**
		\~korean
		ÀÌ Å¬¶óÀÌ¾ğÆ®°¡ ÀÛµ¿ÁßÀÎ NAT ÀåÄ¡ÀÇ ÀÌ¸§
		- CNetServer ¿¡¼­¸¸ ¾òÀ» ¼ö ÀÖ½À´Ï´Ù.
		- ½ÇÁ¦·Î NAT device µÚ¿¡ ÀÖ´Â Å¬¶óÀÌ¾ğÆ®¶ó ÇÏ´õ¶óµµ, ÀÌ¸§À» ¾ò´Âµ¥´Â ¾î´À Á¤µµÀÇ ½Ã°£ÀÌ ÇÊ¿äÇÕ´Ï´Ù. µû¶ó¼­
		¹Ù·Î Á¢¼ÓÀÌ µé¾î¿Â Å¬¶óÀÌ¾ğÆ®ÀÇ Á¤º¸¸¦ ¾òÀ» °æ¿ì ÀÌ °ªÀÌ ¾ÆÁ÷ Ã¤¿öÁöÁö ¾ÊÀ» ¼ö ÀÖ½À´Ï´Ù. ÀÌ·¯ÇÑ °æ¿ì Àá½Ã µÚ¿¡
		´Ù½Ã Å¬¶óÀÌ¾ğÆ®ÀÇ Á¤º¸¸¦ ¾ò¾î¿À¸é NAT ÀåÄ¡ÀÇ ÀÌ¸§À» ¾òÀ» ¼ö ÀÖ½À´Ï´Ù.

		\~english
		Name of NAT device which operated by this client
		- You can get it from CNetServer only.
		- If client actually locate behind of NAT device, it will take some time to get a name. So if you get client information that just loged on, it may empty.  This case you can get name of NAT device by reloading client information in a few minutes.

		\~chinese
		ó®client??ñéîÜNAT?öÇÙ£?¡£
		- ñşÒöî¤ CNetServer%ñé?Ôğ¡£
		- ?ŞÅãÀî¤??NAT deviceı¨ØüîÜclient£¬?ÔğÙ£í®âÍé©ìéïÒîÜ??¡£ì×ó®£¬?ö¢???ïÈîÜclientãáãÓîÜ?ı¦£¬ó®?Ê¦Òö?êóù¬?õö¡£??ı¦£¬õªı¨ñìãæ?ÔğclientãáãÓîÜ?£¬Ê¦ì¤?ÔğNAT?öÇîÜÙ£í®¡£

		\~japanese
		ª³ªÎ«¯«é«¤«¢«ó«Èª¬íÂÔÑª·ªÆª¤ªëNAT?öÇÙ£
		- CNetServerªÇªÎªßÔğªéªìªŞª¹¡£
		- ?ğ·ªËNAT deviceªÎ×êªËª¢ªë«¯«é«¤«¢«ó«ÈªÈª·ªÆªâ¡¢Ù£îñªòÔğªëª³ªÈªËª¢ªëïïÓøªÎãÁÊàª¬ù±é©ªÇª¹¡£ªèªÃªÆ¡¢ª¹ª°ïÈ?ª¬ìıªÃªÆª­ª¿«¯«é«¤«¢«ó«ÈªÎï×ÜÃªòÔğªëíŞùê¡¢ª³ªÎö·ª¬ªŞªÀ?ª¿ªµªìªÊª¤ª³ªÈª¬ª¢ªêªŞª¹¡£ª³ªÎªèª¦ªÊíŞùê¡¢ª·ªĞªéª¯ı­ªÇî¢ªÓ«¯«é«¤«¢«ó«ÈªÎï×ÜÃªòÔğªëªÈNAT?öÇªÎÙ£îñªòÔğªëª³ªÈª¬ªÇª­ªŞª¹¡£

		\~
		*/
		String m_natDeviceName;

		/**
		\~korean
		ÃÖ±Ù¿¡ ÃøÁ¤µÈ pingÀÇ Æò±Õ ½Ã°£ (ÃÊ´ÜÀ§)
		- CNetClient.GetPeerInfo ¿¡¼­ ¾òÀº °æ¿ì: ÇØ´ç P2P peer ÀÇ pingÀÔ´Ï´Ù.
		- CNetServer.GetClientInfo ¿¡¼­ ¾òÀº °æ¿ì: ¼­¹ö-Å¬¶ó°£ÀÇ pingÀÔ´Ï´Ù.

		\~english
		Average ping time that measure recently (Second)
		- When it get from CNetClient.GetPeerInfo: Ping of P2P peer
		- When it get from CNetServer.GetClientInfo: Ping between server-client

		\~chinese
		õÌĞÎ??îÜpingîÜøÁĞ³??£¨õ©?êÈ£©¡£
		- î¤ CNetClient.GetPeerInfo%?ÔğîÜï×?£ºßÓ?P2P peerîÜping¡£
		- î¤ CNetServer.GetClientInfo%?ÔğîÜï×?£ºÜ×?Ğï-client ñı?îÜping¡£

		\~japanese
		õÌĞÎªËö´ïÒª·ª¿pingªÎøÁĞ³ãÁÊà(õ©?êÈ)
		- CNetClient.GetPeerInfoª«ªéÔğª¿íŞùê£ºú±?P2P peerªÎpingªÇª¹¡£ 
		- CNetServer.GetClientInfoª«ªéÔğª¿íŞùê£º«µ?«Ğ?«¯«é«¤«¢«ó«ÈÊàªÎpingªÇª¹¡£ 
		\~
		*/
		int m_recentPingMs;

		/**
		\~korean
		ÀÌ peer·ÎÀÇ ¼Û½Å ´ë±âÁßÀÎ ¸Ş½ÃÁöÀÇ ÃÑ·®(¹ÙÀÌÆ® ´ÜÀ§) ÀÔ´Ï´Ù.
		- ¼­¹ö¿¡¼­ peer¿¡ ´ëÇØ ¾ò´Â °æ¿ì ¼­¹ö=>Å¬¶óÀÌ¾ğÆ® ¼Û½Å¿¡ ´ëÇÑ ÃÑ·®ÀÔ´Ï´Ù.
		- Å¬¶óÀÌ¾ğÆ®¿¡¼­ peer¿¡ ´ëÇØ ¾ò´Â °æ¿ì Å¬¶óÀÌ¾ğÆ®=>Å¬¶óÀÌ¾ğÆ® ¼Û½Å¿¡ ´ëÇÑ ÃÑ·®(´Ü, relayµÇ´Â ¸Ş½ÃÁö¿¡ ´ëÇØ¼­´Â Á¦¿Ü)

		\~english
		Total amount(byte) of waiting message to this peer.
		- When it get about peer from server, it is total sending amount of server to client
		- When it get about peer from client, it is total sending amount of client to client (except message that relayed)

		\~chinese
		éÄó®peerîÜÔõÓâ?áêîÜãáãÓ?Õá£¨byte ?êÈ£©¡£
		- î¤Ü×?Ğï?peer?ÔğîÜï×?£ºÜ×?Ğï=>client ?áêãáãÓîÜ?Õá¡£
		- î¤client?peer?ÔğîÜï×?£ºclient=>client ?áêãáãÓîÜ?Õá£¨Ó££¬?relayîÜãáãÓÖÇèâ£©¡£

		\~japanese
		ª³ªÎpeerªØªÎáêãáªòÓâªÃªÆª¤ªë«á«Ã«»?«¸ªÎ?Õá(«Ğ«¤«È?êÈ)ªÇª¹¡£
		- «µ?«Ğ?ªÇpeerªË?ª·ªÆÔğªëíŞùê¡¢«µ?«Ğ?=>«¯«é«¤«¢«ó«ÈáêãáªË?ª¹ªë?ÕáªÇª¹¡£
		- «¯«é«¤«¢«ó«ÈªÇpeerªË?ª·ªÆÔğªëíŞùê¡¢«¯«é«¤«¢«ó«È=>«¯«é«¤«¢«ó«ÈáêãáªË?ª¹ªë?Õá(Ó£ª·¡¢relayªµªìªë«á«Ã«»?«¸ªË?ª·ªÆªÏğ¶èâ)
		\~
		*/
		int m_sendQueuedAmountInBytes;

		/**
		\~korean
		»ç¿ëÀÚ°¡ ÁöÁ¤ÇÑ tagÀÇ Æ÷ÀÎÅÍÀÔ´Ï´Ù.
		- CNetServer.SetHostTag, CNetClient.SetHostTag À» ÅëÇØ ÁöÁ¤ÇÑ °ªÀÔ´Ï´Ù.
		- ÁÖÀÇ! : tag´Â ³×Æ®¿÷ µ¿±âÈ­°¡ µÇÁö ¾Ê´Â °ªÀÔ´Ï´Ù.

		\~english
		Pointer of user defined tag.
		- It designates through CNetServer.SetHostTag and CNetClient.SetHostTag
		- Warning!! : tag value does not synchronize with network.

		\~chinese
		éÄ?ò¦ïÒîÜtagò¦?¡£
		- ÷×? CNetServer.SetHostTag, CNetClient.SetHostTag%ò¦ïÒîÜ?¡£
		- ñ¼ëò£¡£ºtag ãÀ?êó??ÔÒÜÆîÜ?¡£

		\~japanese
		«æ?«¶?ª¬ò¦ïÒª·ª¿tagªÎ«İ«¤«ó«¿?ªÇª¹¡£
		- CNetServer.SetHostTag, CNetClient.SetHostTag ªò÷×ª¸ò¦ïÒª·ª¿ö·ªÇª¹¡£ 
		- ª´ñ¼ëò!£ºtagªÏ«Í«Ã«È«ï?«¯ÔÒÑ¢ûùª¬ªµªìªÊª¤ö·ªÇª¹¡£
		\~
		*/
		void* m_hostTag;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®ÀÇ Frame Rate ÀÔ´Ï´Ù.
	    - CNetClient.SetApplicationHint ¿¡¼­ »ç¿ëÀÚ°¡ ÀÔ·ÂÇÑ °ªÀÔ´Ï´Ù.
		- °¢ ÇÇ¾î¿¡´Â Àü´ŞµÇÁö ¾ÊÀ¸¸ç, ¼­¹ö¿¡¼­ °¢ Å¬¶óÀÌ¾ğÆ®ÀÇ Frame Rate ¸¦ È®ÀÎ ÇÏ°íÀÚ ÇÒ ¶§ »ç¿ëÇÕ´Ï´Ù.
		- Frame rate´Â Åë½Å·® Àı°¨À» À§ÇÏ¿© Àü¼Û½Ã float°ªÀ¸·Î º¯È¯µÇ¾î ¼Û¼ö½Å µË´Ï´Ù.

		\~english
		Frame Rate of client.
		- User enter this value on CNetClient.SetApplicationHint.
		- It does not send to each peer, it only use to check Frame Rate of client at server.
		- To reduce traffic, frame rate will send/receive as float value.

		\~chinese
		Client îÜFrame Rate¡£
		- î¤ CNetClient.SetApplicationHint%éÄ??ìıîÜ?¡£
		- ÜôèÙÊÀpeer??£¬î¤Ü×?ĞïßÌ??ÊÀclientîÜFrame RateîÜ?ı¦ŞÅéÄ¡£
		- Frame rate ?Öõ?àı÷×ãáÕá£¬?áêîÜ?ı¦???float?ı¨?â¥ãáãÓ¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªÎFrame RateªÇª¹¡£
		- CNetClient.SetApplicationHintªÇ«æ?«¶?ª¬ìıÕôª·ª¿ö·ªÇª¹¡£
		- ÊÀpeerªËªÏ?Ó¹ªµªìªÊª¯¡¢«µ?«Ğ?ªÇÊÀ«¯«é«¤«¢«ó«ÈªÎFrame Rateªòü¬ìãª·ª¿ª¤ãÁªËŞÅéÄª·ªŞª¹¡£
		- Frame rateªÏ÷×ãáÖùï½ÊõªÎª¿ªáªË?áêãÁªËFloatö·ªË?üµªµªìªÆáêáôãáªµªìªŞª¹¡£
		\~
		*/
		double m_recentFrameRate;

		/**
		\~korean
		ÇØ´ç Å¬¶óÀÌ¾ğÆ®°¡ ¼­¹ö¿¡°Ô Udp packet Àü¼ÛÀ» ½ÃµµÇÑ ÃÑ È½¼ö

		\~english
		Total number of attempt to send Udp packet to server from client

		\~chinese
		ßÓ?client?Ü×?Ğï??UDP packet?áêîÜ?ó­?¡£

		\~japanese
		ú±?«¯«é«¤«¢«ó«Èª¬«µ?«Ğ?ªËUDP packet?áêªòú¼ªÃª¿??
		\~
		*/
		uint32_t m_toServerSendUdpMessageTrialCount;

		/**
		\~korean
		ÇØ´ç Å¬¶óÀÌ¾ğÆ®°¡ ¼­¹ö¿¡°Ô Udp packet Àü¼ÛÀ» ¼º°øÇÑ ÃÑ È½¼ö

		\~english
		Total number of attempt to success sending Udp packet to server from client

		\~chinese
		ßÓ?client?Ü×?Ğïà÷Íí?áêUDP packetîÜ?ó­?¡£

		\~japanese
		ú±?«¯«é«¤«¢«ó«Èª¬«µ?«Ğ?ªËUDP packet?áêªËà÷Ííª·ª¿??
		\~
		*/
		uint32_t m_toServerSendUdpMessageSuccessCount;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®°¡ ÇöÀç »ç¿ëÇÏ°í ÀÖ´Â HostID ÀÇ Àç»ç¿ë È½¼öÀÔ´Ï´Ù.
		- StartParameter.m_HostIDGenerationPolicy ·Î Àç»ç¿ëÀ» ÇÒÁö¸¦ °áÁ¤ÇÒ¼ö ÀÖ½À´Ï´Ù.
		- Àç»ç¿ëÇÏÁö ¾Ê´Â ¿É¼ÇÀÌ¸é ¹«Á¶°Ç 0ÀÌ ³ª¿É´Ï´Ù.

		\~english
		Total reused count of HostID that client is using currently.
		- You can decide reusing with StartParameter.m_HostIDGenerationPolicy.
		- If you select non-recyle option, value will be 0

		\~chinese
		Client ?î¤ŞÅéÄîÜHost IDîÜî¢ŞÅéÄó­?¡£
		- Ê¦ì¤?ïÒãÀÜúì¤ StartParameter.m_HostIDGenerationPolicy%î¢ó­ŞÅéÄ¡£
		- ÜôãÀî¢ó­ŞÅéÄîÜ??îÜ?ù±?0¡£

		\~japanese
		«¯«é«¤«¢«ó«Èª¬úŞî¤ŞÅªÃªÆª¤ªëHostIDªÎî¢ŞÅéÄüŞ?ªÇª¹¡£
		- StartParameter.m_HostIDGenerationPolicyªÇî¢ŞÅéÄªòª¹ªëª«ªÉª¦ª«ªòÌ½ªáªëª³ªÈª¬ªÇª­ªŞª¹¡£
		- î¢ŞÅéÄª·ªÊª¤«ª«×«·«ç«óªÇª¢ªìªĞÙí?Ëì0ª¬õóªŞª¹¡£
		\~
		*/
		uint32_t m_hostIDRecycleCount;

		int64_t m_unreliableMessageRecentReceiveSpeed;

		PROUD_API CNetClientInfo();

		String ToString(bool atServer);


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
