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
#include "FakeClr.h"
#include "ThreadPool.h"
#include "IRmiHost.h"
#include "P2PGroup.h"

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
CNetServer.Start ¿¡ ÀÇÇØ ¼­¹ö°¡ ½ÃÀÛÇÒ ¶§ ¼­¹öÀÇ ÃÊ±â ¼³Á¤°ªÀÔ´Ï´Ù.
¼­¹ö ÃÊ±â ¼³Á¤°ªÀº ¼­¹ö ¼º´É¿¡ ¿µÇâÀ» Áİ´Ï´Ù. ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#performance_tips" >ProudNet ¼º´ÉÀ» À§ÇÑ ÆÁ</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.

\~english
This is an initial setup value when the server initializes.
The initial values of the server directly affect server functions. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#performance_tips" >ProudNet Tips for performance enhancement</a> for more details.

\~chinese
Ü×?Ğïë¦ CNetServer.Start%?ã·îÜ?ı¦îÜôøã·?ïÒ?¡£
Ü×?ĞïîÜôøã·?ïÒ??Ü×?ĞïàõÒö?ßæç¯?¡£????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#performance_tips" >ProudNet àõÒö</a>%¡£

\~japanese
CNetServer.StartªËªèªÃªÆ«µ?«Ğ?ª¬ËÒã·ª¹ªëãÁ¡¢«µ?«Ğ?ªÎôøÑ¢àâïÒö·ªÇª¹¡£
«µ?«Ğ?ôøÑ¢àâïÒö·ªÏ«µ?«Ğ?àõÒöªËç¯úÂªò?ª¨ªŞª¹¡£ßÙª·ª¯ªÏ¡¢\ref performance_tipsªòª´?ğÎª¯ªÀªµª¤¡£

\~
*/
	class CStartServerParameterBase
	{
	public:
		/**
		\~korean
		¼­¹öÀÇ ÁÖ¼ÒÀÔ´Ï´Ù.
		- ÃÊ±â°ªÀº ºó ¹®ÀÚ¿­ÀÔ´Ï´Ù.
		- Åë»óÀûÀ¸·Î ºó ¹®ÀÚ¿­À» ÁöÁ¤ÇÏÁö¸¸, L4 ½ºÀ§Ä¡³ª ÀÎÅÍ³İ °øÀ¯±â(NAT) µÚ¿¡¼­ ¼­¹ö°¡ ÀÛµ¿ÇÒ °æ¿ì
		Å¬¶óÀÌ¾ğÆ®°¡ ÀÎ½ÄÇÒ ¼­¹öÀÇ È£½ºÆ® ÀÌ¸§ÀÌ³ª IP addressÀ» ³Ö¾îÁà¾ß ÇÕ´Ï´Ù.
		- IP ÁÖ¼Ò(111.111.111.111 µî) È¤Àº ÀÎ½Ä °¡´ÉÇÑ ÀÌ¸§(aaa.mydomain.com)À» ³ÖÀ» ¼ö ÀÖ½À´Ï´Ù. ÇÏÁö¸¸ Æ÷Æ® ¹øÈ£´Â ³ÖÁö ¸øÇÕ´Ï´Ù.

		\~english
		This is a server address.
		- The initial vlaue is an empty string.
		- It is usual to designate an empty value for this but it is necessary to input either the host name of the server or IP address
		when the server is working behind an L4 switch or an Internet router(NAT) for the clients to recognize.
		- An IP address (e.g. 111.111.111.111) or a recognizable name (www.mydomain.com) can be used, but not the port number

		\~chinese
		Ü×?Ğïò¢ò£¡£
		- ôøã·?ãÀÍöí®İ¬Íú¡£
		- ìéÚõÜôò¦ïÒÍöí®İ¬Íú£¬Ó£ãÀÜ×?Ğïî¤L4 switchûäíº??ÖØë¦Ğï£¨NAT£©ı¨Øü??îÜ?ı¦é©?ìıclientÒö??îÜÜ×?Ğïñ«ÏõÙ£ûäíºIP address¡£
		- Ê¦ì¤?ìıIPò¢ò£(111.111.111.111Ôõ)ûäíºÊ¦ì¤??îÜÙ£í®(aaa.mydomain.com)¡£Ó£ãÀÜôÒö?ìıÓ®Ï¢??¡£

		\~japanese
		«µ?«Ğ?ªÎ«¢«É«ì«¹ªÇª¹¡£
		- ôøÑ¢ö·ªÏÍöªÎÙşí®ÖªªÇª¹¡£
		- ÷×ßÈ¡¢ÍöªÎÙşí®Öªªòò¦ïÒª·ªŞª¹ª¬¡¢L4«¹«¤«Ã«ÁªÈª««¤«ó«¿?«Í«Ã«È«ë?«¿?(NAT)ªÎı­ªíªÇ«µ?«Ğ?ª¬íÂÔÑª¹ªëíŞùê¡¢«¯«é«¤«¢«ó«Èª¬ìããÛª¹ªë«µ?«Ğ?ªÎ«Û«¹«ÈÙ£ªÈª«IP«¢«É«ì«¹ªòìıªìªëù±é©ª¬ª¢ªêªŞª¹¡£
		- IP«¢«É«ì«¹(111.111.111.111ªÊªÉ)ªŞª¿ªÏìããÛÊ¦ÒöªÊÙ£îñ(aaa.mydomain.com)ªòìıªìªëª³ªÈª¬ªÇª­ªŞª¹¡£ª·ª«ª·¡¢«İ?«ÈÛã?ªÏìıªìªëª³ªÈª¬ªÇª­ªŞª»ªó¡£

		\~
		*/
		String m_serverAddrAtClient;

		/**
		\~korean
		¼­¹öÀÇ ¸®½º´× ¼ÒÄÏÀÌ ¹ÙÀÎµùµÉ ÁÖ¼ÒÀÔ´Ï´Ù.
		- ÃÊ±â°ªÀº ºó ¹®ÀÚ¿­ÀÔ´Ï´Ù.
		- Åë»óÀûÀ¸·Î ºó ¹®ÀÚ¿­À» ÁöÁ¤ÇÏÁö¸¸ ¼­¹ö°¡ ³×Æ®¿öÅ© ÀÎÅÍÆäÀÌ½º(NIC)¸¦ 2°³ ÀÌ»ó °¡Áö´Â °æ¿ì,
		±×¸®°í ±×°Íµé Áß ÇÏ³ª¸¸ÀÌ CNetClient ¿¡¼­ ¿À´Â Á¢¼Ó ¿äÃ»À» ¹ŞÀ» ¼ö ÀÖ´Â °æ¿ì ¿©±â¿¡ ÇØ´çµË´Ï´Ù.
		NIC¿¡ ÁöÁ¤µÈ IP ¶Ç´Â È£½ºÆ® ÀÌ¸§À» ÁöÁ¤ÇØ¾ß ÇÕ´Ï´Ù. È£½ºÆ®¿¡ ÀÖ´Â NIC ÁÖ¼Ò ¸®½ºÆ®¸¦ ¾òÀ¸·Á¸é Proud.GetLocalIPAddresses ¸¦ ¾µ ¼ö ÀÖ½À´Ï´Ù.
		- È£½ºÆ® ÀÌ¸§À» ÁöÁ¤ÇÒ °æ¿ì Å¬¶óÀÌ¾ğÆ®´Â ¼­¹ö·Î Á¢¼ÓÇÏ±â À§ÇÑ ÁÖ¼Ò·Î localhost¸¦ ÀÔ·ÂÇÒ °æ¿ì ¿¬°á ½ÇÆĞ¸¦ ÇÒ ¼ö ÀÖ½À´Ï´Ù. ÀÌ·¯ÇÑ °æ¿ì
		Å¬¶óÀÌ¾ğÆ®´Â ¼­¹ö·Î Á¢¼ÓÇÏ±â À§ÇØ ¼­¹ö È£½ºÆ®ÀÇ ÁÖ¼Ò¸¦ ¸í½ÃÀûÀ¸·Î ÀÔ·ÂÇØ¾ß ÇÕ´Ï´Ù.
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#multiple_nic_at_server" >¼­¹ö°¡ ¿©·¯°³ÀÇ LANÄ«µå(NIC)¸¦ ÀåÂøÇÑ °æ¿ìÀÇ ¼³Á¤</a>

		\~english
		This is the address that the listening socket of the server to be bound.
		- The initial value is an empty value.
		- It is usual to designate an empty value for this but it is used in the case that the server has more than
		2 Network Interfces (NIC) and when only one of them is able to receive a connection request from CNetClient.
		Either an IP address or a host name that is registered by the NIC must be designated.
		It is possible to use Proud.GetLocalIPAddresses to acquire the NIC address list in the host.
		- When a hostname is designated, itis possible to cause a connection failure when a localhost is used for the address to connect at the client.
		It is necessary to input correct address of the server host in order to connect to client server.
		- <a target="_blank" href="http://guide.nettention.com/cpp_en#multiple_nic_at_server" >Setup when there are several LAN cards (NIC) are attached.</a>

		\~chinese
		Ü×?ĞïîÜlisting socketé©ù¬boundîÜò¢ò£¡£
		- ôøã·?ãÀÍöí®İ¬Íú¡£
		- ìéÚõò¦ïÒ?Íöí®İ¬Íú£¬Ó£ãÀÜ×?Ğï?êó2?ì¤ß¾??Í£Øü£¨NIC£©îÜ?ı¦£¬ûäíºãÀñşêóĞìñéñıìéÊ¦ì¤ïÈâ¥? CNetClient%??îÜ?ïÈé­?îÜ?ı¦?éÍ?×ì¡£
		é©ò¦ïÒî¤NICò¦ïÒîÜIPûäíºñ«ÏõÙ£?¡£ßÌ?Ôğî¤ñ«ÏõîÜNICò¢ò£listîÜ?Ê¦ì¤ŞÅéÄ Proud.GetLocalIPAddresses%¡£
		- ò¦ïÒñ«ÏõÙ£îÜ?ı¦£¬client ?Öõ?ïÈÜ×?Ğïì»?ìıîÜò¢ò£ãÀlocalhostîÜ?Ê¦Òö??ïÈã÷?¡£??ı¦client?Öõ?ïÈÜ×?Ğï£¬é©Ù¥ãÆò¢?ìıÜ×?Ğïñ«ÏõîÜò¢ò£¡£
		- <a target="_blank" href="http://guide.nettention.com/cpp_zh#multiple_nic_at_server" >î¤Ü×?ĞïäÌ?êóÒı?LAN?(NIC)?îÜ?öÇ</a>

		\~japanese
		«µ?«Ğ?ªÎ«ê«¹«Ë«ó«°«½«±«Ã«Èª¬«Ğ«¤«ó«Ç«£«ó«°ªµªìªë«¢«É«ì«¹ªÇª¹¡£
		- ôøÑ¢ö·ªÏÍöªÎÙşí®ÖªªÇª¹¡£
		- ÷×ßÈ¡¢ÍöªÎÙşí®Öªªòò¦ïÒª·ªŞª¹ª¬¡¢«µ?«Ğ?ª¬«Í«Ã«È«ï?«¯«¤«ó«¿?«Õ«§?«¹(NIC)ªò2ËÁì¤ß¾ò¥ªÃªÆª¤ªëíŞùê¡¢ª½ª·ªÆª½ªìªéªÎª¦ªÁìéªÄªÎªßª¬CNetClientª«ªé?ªëïÈ?é©ôëªòáôª±ªéªìªëíŞùê¡¢ª³ªìªËú±?ª·ªŞª¹¡£
		NICªËò¦ïÒªµªìª¿IPªŞª¿ªÏ«Û«¹«ÈÙ£ªòò¦ïÒª¹ªëù±é©ª¬ª¢ªêªŞª¹¡£«Û«¹«ÈªËª¢ªëNIC«¢«É«ì«¹«ê«¹«ÈªòÔğªëª¿ªáªËªÏ¡¢Proud.GetLocalIPAddressesªòŞÅª¦ª³ªÈª¬ªÇª­ªŞª¹¡£ 
		- «Û«¹«ÈÙ£ªòò¦ïÒª¹ªëíŞùê¡¢«¯«é«¤«¢«ó«ÈªÏ«µ?«Ğ?ªËïÈ?ª¹ªëª¿ªáªÎ«¢«É«ì«¹ªÇ¡¢localhostªòìıÕôª¹ªëíŞùê¡¢Ö§Ì¿ã÷ø¨ªÎÊ¦Òöàõª¬ª¢ªêªŞª¹¡£ª³ªÎªèª¦ªÊíŞùê¡¢«¯«é«¤«¢«ó«ÈªÏ«µ?«Ğ?ªËïÈ?ª¹ªëª¿ªáªË¡¢«µ?«Ğ?«Û«¹«ÈªÎ«¢«É«ì«¹ªòÙ¥ãÆîÜªËìıÕôª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
		- \ref multiple_nic_at_server

		\~
		*/
		String m_localNicAddr;
		/**
		\~korean
		¼­¹ö¿Í Å¬¶óÀÌ¾ğÆ®°£ ¸ÂÃß´Â ÇÁ·ÎÅäÄİ ¹öÀüÀÔ´Ï´Ù.
		- ¸¸¾à ÇÁ·ÎÅäÄİ ¹öÀüÀÌ ¼­·Î ´Ù¸£°Ô ÁöÁ¤µÈ Å¬¶óÀÌ¾ğÆ®°¡
		¼­¹ö¿¡ ¿¬°á(CNetClient.Connect)ÇÏ·Á°í ½ÃµµÇÏ¸é
		Å¬¶óÀÌ¾ğÆ®¿¡¼­ ErrorType_ProtocolVersionMismatch °¡ Æ®¸®°ÅµË´Ï´Ù.

		\~english
		This is a protocaol version that syncs the servers and the clients.
		- When a client with different protocol version to ther server attempt to connect(CNetClient.Connect), the client will trigger ErrorType_ProtocolVersionMismatch.

		\~chinese
		Ü×?Ğïûúclient?ïÈîÜ??÷úÜâ¡£
		- åıÍı??÷úÜâò¦ïÒßÓû»ÜôÔÒîÜclient???ïÈ£¨CNetClient.Connect£©Ü×?ĞïîÜ?£¬client?ìÚÑÃErrorType_ProtocolVersionMismatch¡£

		\~japanese
		«µ?«Ğ?ªÈ«¯«é«¤«¢«ó«ÈÊàªËùêªïª»ªë«×«í«È«³?«ë«Ğ?«¸«ç«óªÇª¹¡£
		- ªâª·¡¢«×«í«È«³?«ë«Ğ?«¸«ç«óª¬ªªû»ª¤êŞªÃªÆò¦ïÒªµªìª¿«¯«é«¤«¢«ó«Èª¬«µ?«Ğ?ªËïÈ?(CNetClient.Connect)ª·ªèª¦ªÈª·ª¿ªé¡¢«¯«é«¤«¢«ó«ÈªÇErrorType_ProtocolVersionMismatchª¬«È«ê«¬?ªµªìªŞª¹¡£

		\~
		*/
		Guid m_protocolVersion;

		/**
		\~korean
		»ç¿ëÀÚ Á¤ÀÇ ·çÆ¾ÀÌ ½ÇÇàµÇ´Â ½º·¹µå°¡ ÀÌ ¸ğµâÀÇ ³»Àå ½º·¹µå Ç®¿¡¼­ ½ÇÇàµÉ °æ¿ì, ±× ½º·¹µå Ç®ÀÇ ½º·¹µå °¹¼öÀÔ´Ï´Ù.
		- ±âº»°ªÀº 0ÀÔ´Ï´Ù. 0À» ÁöÁ¤ÇÏ¸é CPU °¹¼ö·Î ÁöÁ¤µË´Ï´Ù.
		- m_externalUserWorkerThreadPoolÀÌ ¼³Á¤ µÇ¾úÀ» °æ¿ì ÀÌ °ªÀº ¹«½ÃµË´Ï´Ù.

		\~english
		The number of treads in thread pool. It must be at least bigger than 1.
		- The initial value is 0. If 0 is designated, then it is to be disignated as the number of CPUs.
		- When you set m_externalUserWorkerThreadPool then this value is ignored.

		\~chinese
		éÄ?ïÒ?routine?ú¼îÜ?ïïî¤ó®Ù¼?îÜ?öÇ?ïïğË×ì?ú¼?ı¦£¬Ñá??ïïğËîÜ?ïï??¡£
		- Ùù??ãÀ0¡£ò¦ïÒ0îÜ?øµ?ò¦ïÒ?CPU??¡£
		- m_externalUserWorkerThreadPoolù¬?öÇîÜ?ı¦ó®??ù¬ûì?¡£

		\~japanese
		«æ?«¶?ïÒëù«ë?«Á«óª¬?ú¼ªµªìªë«¹«ì«Ã«Éª¬ª³ªÎ«â«¸«å?«ëªÎ??«¹«ì«Ã«É«×?«ëªÇ?ú¼ªµªìªëíŞùê¡¢ª½ªÎ«¹«ì«Ã«É«×?«ëªÎ«¹«ì«Ã«É?ªÇª¹¡£
		- ĞñÜâö·ªÏ0ªÇª¹¡£0ªòò¦ïÒª¹ªëªÈ¡¢CPU?ªÇò¦ïÒªµªìªŞª¹¡£
		- m_externalUserWorkerThreadPoolª¬àâïÒªµªìª¿íŞùê¡¢ª³ªÎö·ªÏÙíãÊªµªìªŞª¹¡£

		\~
		*/
		int m_threadCount;

		/**
		\~korean
		ProudNetÀº ³»ºÎÀûÀ¸·Î I/O Ã³¸®¸¦ ´ã´çÇÏ´Â ½º·¹µå°¡ ÀÖ½À´Ï´Ù. ÀÌ°ÍÀÇ °¹¼ö¸¦ ÁöÁ¤ÇÕ´Ï´Ù.
		- ±âº»°ªÀº 0ÀÔ´Ï´Ù. 0À» ÁöÁ¤ÇÏ¸é CPU °¹¼ö·Î ÁöÁ¤µË´Ï´Ù.
		- ¸¸¾à ProudNetÀÌ ÀÛµ¿ÇÒ ¼­¹ö°¡ 1°³ÀÇ ¸Ó½Å¿¡¼­ CPU ÄÚ¾î °¹¼ö¸¸Å­ ÀÛµ¿ÇÏ´Â °æ¿ì »ç½Ç»ó ¼­¹ö´Â ´ÜÀÏ ½º·¹µå ±â¹İÀÌ³ª ´Ù¸§¾ø½À´Ï´Ù. ÀÌ·¯ÇÑ °æ¿ì¿¡´Â ÀÌ °ªÀ» 1·Î ¼³Á¤ÇØ¼­ 1°³ÀÇ CPU ¸¸ »ç¿ëÇÏµµ·Ï ¼³Á¤ÇØÁÖ¸é ProudNetÀÇ Ã³¸® ¼º´ÉÀÌ Çâ»óµË´Ï´Ù. ±× ¿Ü¿¡´Â º» °ªÀº ±×³É µÎ´Â °ÍÀÌ ÁÁ½À´Ï´Ù.
		- m_externalNetWorkerThreadPoolÀÌ ¼³Á¤ µÇ¾úÀ» °æ¿ì ÀÌ °ªÀº ¹«½ÃµË´Ï´Ù.

		\~english
		ProudNet has a thread that deals with internal I/O. This value designates how many for this.
		- If it is 0 then it is regarded as the number of CPU cores.
		- In case when the server where Proudnet to be working works as many as the number of CPU cores within a machine, it is reasonable to say that the server is one thread base.
		If this is the case, it is ideal to set this value as 1 to use 1 CPU in order to increase the CPU's overall efficiency.
		- If this is not the case, then it is ideal to leave the value as it is.

		\~chinese
		ProudNet ?öÇó·?ìòI/O?×âîÜ?ïï¡£ò¦ïÒó®??¡£
		- Ùù??ãÀ0¡£ò¦ïÒ0îÜ?øµ?ò¦ïÒ?CPU??¡£
		- åıÍı??ProudNetîÜÜ×?Ğïî¤ìé?ÏõĞï??ßÓ?éÍCPU core?ÕáîÜ?ı¦£¬??ß¾Ü×?Ğï??ìé?ïïĞñ??êóÜôÔÒ¡£??ï×?é©÷êó®??öÇ?1£¬?öÇà÷ñşŞÅéÄìé?CPUîÜ?£¬?ğ«ÍÔProudNetîÜ?×âàõÒö¡£ó®èâÜô?ó®?îÜ?û¿¡£
		- m_externalNetWorkerThreadPoolù¬?öÇîÜ?ı¦ó®??ù¬ûì?¡£

		\~japanese
		ProudNetªÏ?İ»îÜªËI/O?×âªò??ª¹ªë«¹«ì«Ã«Éª¬ª¢ªêªŞª¹¡£ª³ªìªéªÎ?ªòò¦ïÒª·ªŞª¹¡£
		- ĞñÜâö·ªÏ0ªÇª¹¡£0ªòò¦ïÒª¹ªìªĞCPU?ªÇò¦ïÒªµªìªŞª¹¡£
		- ªâª·¡¢ProudNetª¬íÂÔÑª¹ªë«µ?«Ğ?ª¬1÷»ªÎ«Ş«·«óªÇCPU«³«¢?ªÀª±íÂÔÑª¹ªëíŞùê¡¢ŞÀ?ß¾«µ?«Ğ?ªÏ?ìé«¹«ì«Ã«ÉĞñÚïªÈÊàêŞª¤ª¢ªêªŞª»ªó¡£ª³ªÎªèª¦ªÊíŞùêªËªÏ¡¢ª³ªÎö·ªò1ªËò±ªÃªÆª¤ª·ªÆ1ËÁªÎCPUªÎªßŞÅéÄª¹ªëªèª¦ªËàâïÒª¹ªìªĞProudNetªÎ?×âàõÒöª¬ú¾ß¾ªµªìªŞª¹¡£ª½ªÎöâªËªÏª³ªÎö·ªÏª½ªÎªŞªŞöÇª¤ª¿Û°ª¬ÕŞª¤ªÇª¹¡£
		- m_externalNetWorkerThreadPoolª¬àâïÒªµªìªÆª¤ªëíŞùê¡¢ª³ªÎö·ªÏÙíãÊªµªìªŞª¹¡£

		\~
		*/
		int m_netWorkerThreadCount;
		/**
		\~korean
		ProudNet¿¡¼­ ¾ÏÈ£È­µÈ ¸Ş½ÃÂ¡À» ÁÖ°í ¹ŞÀ» ¶§ÀÇ ¾ÏÈ£Å°ÀÇ ±æÀÌÀÔ´Ï´Ù. (Âü°í: <a target="_blank" href="http://guide.nettention.com/cpp_ko#key_length" >¾ÏÈ£È­ Å° ±æÀÌ: ¾ÏÈ£È­ ¼öÁØ°ú ¼º´É »çÀÌ¿¡¼­ Á¶À²ÇÏ±â</a>)
		- AES±â¹İÀÇ ÇÁ¶ó¿ìµå³İÀÇ ÀÚÃ¼ ¾ÏÈ£È­µÈ Å°¸¦ »ı¼ºÇÕ´Ï´Ù.
		- Proud::EncryptLevel °ªÀ» ÂüÁ¶ÇÏ¿© ¼¼ÆÃÇÏ¿©¾ß ÇÏ¸ç ÃÊ±â°ªÀº EncryptLevel_Low ÀÔ´Ï´Ù.

		\~english
		This is the length of the coded key when ProudNet communicates with encrypted messeges. (Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#key_length" >The length of encryption: mediate between the level of encryption and performance.</a>)
		- It generates encrypted key that based on AES.
		- You need to set it up with refer to Proud::EncryptLevel value and defualt value is EncryptLevel_Low.

		\~chinese
		î¤ProudNet×ì?ïÈÊ¥ÚËîÜmessagingîÜ?ı¦îÜÚË??Óø¡££¨?ÍÅ£º<a target="_blank" href="http://guide.nettention.com/cpp_zh#key_length" >Ê¥ÚËkey?Óø: î¤Ê¥ÚËâ©ñ×?àõÒöñı??ú¼??</a>£©
		- ßæà÷AESĞñ?îÜProudNetÜâãóÊ¥ÚËîÜkey¡£
		- é©?ğÎ Proud::EncryptLevel%?ì»?öÇ£¬ôøã·?ãÀEncryptLevel_Low¡£

		\~japanese
		ProudNetªÇäŞ?ûùªµªìª¿«á«Ã«»?«¸«ó«°ªòªäªêö¢ªêª¹ªëãÁªÎäŞ?«­?ªÎíşªµªÇª¹¡£(?ÍÅ£º\ref key_length)
		- AESĞñ÷ùªÎ«×«é«¦«É«Í«Ã«ÈªÎí»?äŞ?ûù«­?ªòßæà÷ª·ªŞª¹¡£
		- Proud::EncryptLevel ö·ªò?ğÎª·ªÆàâïÒª·ªÊª±ªìªĞªÊªêªŞª»ªóª·¡¢ôøÑ¢ö·ªÏEncryptLevel_LowªÇª¹¡£

		\~
		*/
		EncryptLevel m_encryptedMessageKeyLength;

		/**
		\~korean
		ProudNet¿¡¼­ ¾ÏÈ£È­µÈ ¸Ş½ÃÂ¡À» ÁÖ°í ¹ŞÀ» ¶§ÀÇ ¾ÏÈ£Å°ÀÇ ±æÀÌÀÔ´Ï´Ù. (Âü°í: <a target="_blank" href="http://guide.nettention.com/cpp_ko#key_length" >¾ÏÈ£È­ Å° ±æÀÌ: ¾ÏÈ£È­ ¼öÁØ°ú ¼º´É »çÀÌ¿¡¼­ Á¶À²ÇÏ±â</a>)
		- Fast±â¹İÀÇ ÇÁ¶ó¿ìµå³İÀÇ ÀÚÃ¼ ¾ÏÈ£È­µÈ Å°¸¦ »ı¼ºÇÕ´Ï´Ù.
		- ½ºÆ®¸®¹Ö ¾ÏÈ£È­ ¹æ½ÄÀÌ±â ¶§¹®¿¡ Å°°ªÀÌ ±æ¾îµµ ¾Ïº¹È£È­ÀÇ ¼Óµµ¿¡´Â ¿µÇâÀ» ÁÖÁö ¾Ê½À´Ï´Ù.
		- Proud::FastEncryptLevel °ªÀ» ÂüÁ¶ÇÏ¿© ¼¼ÆÃÇÏ¿©¾ß ÇÏ¸ç ÃÊ±â°ªÀº FastEncryptLevel_Low ÀÔ´Ï´Ù.

		\~english
		This is the length of the coded key when ProudNet communicates with encrypted messeges. (Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#key_length" >The length of encryption: mediate between the level of encryption and performance.</a>)
		- It generates encrypted key that based on Fast
		- It does not affect speed of encryption even key value is long because it use streaming encryption type.
		- You need to set it up with refer to Proud::FastEncryptLevel value and defualt value is FastEncryptLevel_Low.

		\~chinese
		î¤ProudNet×ì?ïÈÊ¥ÚËîÜmessagingîÜ?ı¦îÜÚË??Óø¡££¨?ÍÅ£º<a target="_blank" href="http://guide.nettention.com/cpp_zh#key_length" >Ê¥ÚËkey?Óø: î¤Ê¥ÚËâ©ñ×?àõÒöñı??ú¼??</a>£©
		- ßæà÷FastĞñ?îÜProudNetÜâãóÊ¥ÚËîÜkey¡£
		- ì×?ãÀÍú×µÊ¥ÚËÛ°ãÒ£¬key ??å¥Üô??Ê¥ÚË¡¢ú°ÚËáÜÓø?ßæç¯?¡£
		- é©?ğÎ Proud::FastEncryptLevel%?ì»?öÇ£¬ôøã·?ãÀFastEncryptLevel_Low¡£

		\~japanese
		ProudNetªÇäŞ?ûùªµªìª¿«á«Ã«»?«¸«ó«°ªòªäªêö¢ªêª¹ªëãÁªÎäŞ?«­?ªÎíşªµªÇª¹¡£(?ÍÅ£º\ref key_length)
		- FastĞñ÷ùªÎ«×«é«¦«É«Í«Ã«ÈªÎí»?äŞ?ûù«­?ªòßæà÷ª·ªŞª¹¡£
		- «¹«È«ê?«ß«ó«°äŞ?ûùÛ°ãÒªÊªÎªÇ¡¢«­?ö·ª¬íşª¯ªÆªâäŞ?ÜÖ?ûùªÎáÜÓøªËªÏç¯úÂªò?ª¨ªŞª»ªó¡£
		- Proud::FastEncryptLevel ö·ªò?ğÎª·ªÆàâïÒª·ªÊª±ªìªĞªÊªêªŞª»ªóª·¡¢ôøÑ¢ö·ªÏFastEncryptLevel_LowªÇª¹¡£

		\~
		*/
		FastEncryptLevel m_fastEncryptedMessageKeyLength;

		/**
		\~korean
		P2P RMI ¸Ş¼¼ÁöÀÇ encrypt ¸¦ ÄÑ°Å³ª ²ô´Â±â´ÉÀÔ´Ï´Ù. ±âº»°ªÀº falseÀÔ´Ï´Ù.
		- ¸¸¾à, »ç¿ëÀÚ°¡ false·Î ¼³Á¤ÇÏ¸é P2P ¾ÏÈ£È­µÈ RMI´Â ºÒ°¡´ÉÇÕ´Ï´Ù. ´ë½Å¿¡ ¼­¹ö¼º´ÉÀº Çâ»óµË´Ï´Ù.
		- »ç¿ëÀÚ°¡ falseÀÎ »óÅÂ¿¡¼­ encrypt ¸Ş¼¼Â¡À» ÇÒ°æ¿ì¿¡´Â OnError°¡ Äİ¹éµË´Ï´Ù.

		\~english
		This is used to turn on/off the encryption function of P2P RMI message. The default value is false.
		- If the user sets this as false then it is impossible to use encrypted P2P RMI. Instead, the server performance is improved.
		- If the user uses encrypted messaging with its value being false, then OnError will be called back.

		\~chinese
		??ûä??P2P RMIãáãÓîÜencryptîÜÍíÒö¡£Ùù??ãÀfalse¡£
		- åıÍıéÄ??öÇ?falseîÜ?P2PÊ¥ÚËîÜRMIãÀÜôÊ¦ÒöîÜ¡£Ó£ãÀÜ×?ĞïàõÒö?ğ«ÍÔ¡£
		- éÄ?î¤falseîÜ??ù»?ú¼encrypt messagingîÜ?ı¦?üŞ? OnError¡£

		\~japanese
		P2P RMI«á«Ã«»?«¸ªÎencryptªò«ª«ó?«ª«Õª¹ªëÑ¦ÒöªÇª¹¡£ĞñÜâö·ªÏfalseªÇª¹¡£
		- ªâª·¡¢«æ?«¶?ª¬falseªËàâïÒª¹ªëªÈP2PäŞ?ûùªµªìª¿RMIªÏÜôÊ¦ÒöªÇª¹¡£ª½ªÎÓÛªïªêªË«µ?«Ğ?àõÒöªÏú¾ß¾ªµªìªŞª¹¡£
		- «æ?«¶?ª¬falseªÎ?÷¾ªÇencrypt«á«Ã«»?«¸«ó«°ªòª¹ªëíŞùêªËªÏ¡¢OnErrorª¬«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£

		\~
		*/
		bool m_enableP2PEncryptedMessaging;

		/**
		\~korean
		¼­¹ö¸¦ <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> ÀÇ ¸â¹ö·Î Æ÷ÇÔ½ÃÅ³ ¼ö ÀÖ´ÂÁö¸¦ °áÁ¤ÇÏ´Â ¼³Á¤°ªÀÔ´Ï´Ù.
		- ±âº»°ªÀº falseÀÔ´Ï´Ù.
		- ÀÚ¼¼ÇÑ ³»¿ëÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_as_p2pgroup_member" >P2P ±×·ì ¸â¹ö·Î¼­ ¼­¹ö¸¦ Æ÷ÇÔ½ÃÅ°±â</a>¸¦ Âü°íÇÏ½Ê½Ã¿À.

		\~english
		This is a value to decide whether the server can be included as the member of <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> or not.
		- The default value is false.
		- Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#server_as_p2pgroup_member" >How to include a server as a peer-to- peer group member</a> for more details.

		\~chinese
		?ïÒãÀÜúÒö÷êÜ×?ĞïøĞùß?<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%îÜà÷?îÜ?ïÒ?¡£
		- Ùù??ãÀfalse¡£
		- ???é»??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_as_p2pgroup_member" >ì¤P2PîÜ?à÷?ùŞÎÀÜ×?Ğï</a>%¡£

		\~japanese
		«µ?«Ğ?ªò\ref p2p_groupªÎ«á«ó«Ğ?ªËùßªŞª»ªëª³ªÈª¬ªÇª­ªëª«ªòÌ½ïÒª¹ªëàâïÒö·ªÇª¹¡£ 
		- ĞñÜâö·ªÏfalseªÇª¹¡£
		- ßÙª·ª¯ªÏ¡¢\ref server_as_p2pgroup_memberªòª´?ğÎª¯ªÀªµª¤¡£

		\~
		*/
		bool m_allowServerAsP2PGroupMember;


		/**
		\~korean
		Timer callback ÁÖ±â ÀÔ´Ï´Ù. <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_timer_callback" >¼­¹ö¿¡¼­ Å¸ÀÌ¸Ó ·çÇÁ RMI ÀÌº¥Æ® Ã³¸®ÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù.
		ÀÌ°ÍÀ» ¼¼ÆÃÇÏ¸é milisec´ÜÀ§·Î ÇÑ¹ø¾¿ INetServerEvent.OnTick °¡ È£ÃâµË´Ï´Ù.
		- 0ÀÌ¸é Äİ¹éÇÏÁö ¾Ê½À´Ï´Ù.
		- ±âº»°ªÀº 0ÀÔ´Ï´Ù.

		\~english
		This sets the period of timer callback. A function described in <a target="_blank" href="http://guide.nettention.com/cpp_en#server_timer_callback" >Managing Timer loop RMI Event from server</a>.
		When this is activated, INetServerEvent.OnTimerCallback will be called at every period set by millisecond unit.
		- Ther is no callback when this is set as 0.
		- The default value is 0

		\~chinese
		Timer callbackñ²Ñ¢¡£<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_timer_callback" >î¤Ü×?Ğï?×âTimer Loop£¬RMI£¬Event</a>ÍíÒö¡£
		?öÇ??îÜ?£¬ INetServerEvent.OnTick%?ì¤milisec?êÈû¼Ğ£ìéó­¡£
		- 0îÜîÜ?Üô?üŞ?¡£
		- Ùù??ãÀ0¡£

		\~japanese
		Timer callback ñ²Ñ¢ªÇª¹¡£\ref server_timer_callback Ñ¦ÒöªÇª¹¡£ª³ªìªòàâïÒª¹ªëªÈ¡¢milisec?êÈªÇìéÓøªºªÄINetServerEvent.OnTickª¬û¼ªÓõóªµªìªŞª¹¡£
		- 0ªÇª¢ªìªĞ«³?«ë«Ğ«Ã«¯ª·ªŞª»ªó¡£
		- ĞñÜâö·ªÏ0ªÇª¹¡£

		\~
		*/
		uint32_t m_timerCallbackIntervalMs;

		/**
		\~korean
		Timer callbackÀÌ µ¿½Ã ¸î °³ÀÇ user worker thread¿¡¼­ È£ÃâµÉ ¼ö ÀÖ´ÂÁö¸¦ Á¤ÇÕ´Ï´Ù.
		±âº»°ªÀº 1ÀÔ´Ï´Ù. ¸ğµç user worker thread¸¦ »ç¿ëÇÏ°í ½Í´Ù¸é INT_MAX¸¦ ÀÔ·ÂÇØµµ µË´Ï´Ù.

		\~english 
		It determines whether timer callback can be called in how many user worker threads simultaneously.
		The default value is 1. If you want to use all user worker threads, you may enter INT_MAX. 

		\~chinese
		?ïÒTimer callbackÔÒ?Òöî¤??user worker threadù¬û¼Ğ£¡£
		Ùù??ãÀ1¡£ßÌŞÅéÄá¶êóuser worker threadîÜ?å¥Ê¦ì¤?ìıINT_MAX¡£

		\~japanese
		Timer callbackª¬ÔÒãÁù¼ËÁªÎuser worker threadªÇû¼ªÓõóªµªìªëª«ªòÌ½ªáªŞª¹¡£
		ĞñÜâö·ªÏ1ªÇª¹¡£îïªÆªÎuser worker threadªòŞÅª¤ª¿ª¤íŞùêªÏ¡¢INT_MAXªòìıÕôª·ªÆªâÕŞª¤ªÇª¹¡£

		\~
		*/
		int32_t m_timerCallbackParallelMaxCount;

		/**
		\~korean
		¼­¹ö¿¡¼­ ÀÏÁ¤ÁÖ±â¿¡ ÇÑ¹ø¾¿ Äİ¹éÀ» ÇÒ½Ã¿¡ ÀÎÀÚ·Î »ç¿ëµÇ´Â À¯Àú µ¥ÀÌÅÍÀÔ´Ï´Ù.
		Proud.INetServerEvent.OnTick °¡ È£ÃâµÉ½Ã¿¡ ÀÎÀÚ°ªÀ¸·Î µé¾î°©´Ï´Ù. <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_timer_callback" >¼­¹ö¿¡¼­ Å¸ÀÌ¸Ó ·çÇÁ RMI ÀÌº¥Æ® Ã³¸®ÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù.
		- ±âº»°ªÀº NULLÀÔ´Ï´Ù.

		\~english
		This is a user data used as an index when the server calls back each time in every period.
		This value is to be input as an index when Proud.INetServerEvent.OnTimerCallback is called. A function described in <a target="_blank" href="http://guide.nettention.com/cpp_en#server_timer_callback" >Managing Timer loop RMI Event from server</a>.
		- The default value is NULL.

		\~chinese
		î¤Ü×?ĞïØßìéïÒñ²Ñ¢üŞ?ìéó­îÜ?ı¦éÄéÍì×áÈîÜéÄ??Ëß¡£
		Proud.INetServerEvent.OnTick%ù¬û¼Ğ£îÜ?ı¦?ìıà÷ì×áÈ?¡£ãÀ<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_timer_callback" >î¤Ü×?Ğï?×âTimer Loop£¬RMI£¬Event</a>%ÍíÒö¡£
		- Ùù??ãÀNULL¡£

		\~japanese
		«µ?«Ğ?ªÇá¶ïÒñ²Ñ¢ªË1ÓøªºªÄ«³?«ë«Ğ«Ã«¯ª¹ªëãÁªËì×í­ªÈª·ªÆŞÅªïªìªë«æ?«¶?«Ç?«¿ªÇª¹¡£
		Proud.INetServerEvent.OnTickª¬û¼ªÓõóªµªìªëãÁªËì×í­ö·ªÈª·ªÆìıªêªŞª¹¡£\ref server_timer_callback Ñ¦ÒöªÇª¹¡£
		- ĞñÜâö·ªÏNULLªÇª¹¡£

		\~
		*/
		void* m_timerCallbackContext;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#delayed_send" >TCP Áö¿¬ ¼Û½Å ±â´É°ú Nagle ¾Ë°í¸®Áò</a> ±â´ÉÀ» ÄÑ°Å³ª ²ü´Ï´Ù. TCP¸¦ ÁÖ·Î »ç¿ëÇÏ¸é¼­ ·¹ÀÌÅÏ½Ã¿¡ ¹Î°¨ÇÏ¸ç, Åë½Å·®ÀÌ ÀûÀº ¾ÛÀº ÀÌ °ªÀ» false·Î ÁöÁ¤ÇÏ±âµµ ÇÕ´Ï´Ù.
		- ±âº»°ªÀº trueÀÔ´Ï´Ù.
		- trueÀÎ °æ¿ì TCP Nagle ¾Ë°í¸®ÁòÀÌ ÄÑÁö¸ç ProudNet ÀÚÃ¼ÀÇ Áö¿¬ ¼Û½Å ±â´ÉÀ» ²ü´Ï´Ù.
		- falseÀÎ °æ¿ì TCP Nagle ¾Ë°í¸®ÁòÀÌ ²¨Áö¸ç ProudNet ÀÚÃ¼ÀÇ Áö¿¬ ¼Û½Å ±â´ÉÀ» ÄÕ´Ï´Ù.
		- TCP Nagle ¾Ë°í¸®ÁòÀº ¿î¿µÃ¼Á¦¿¡ µû¶ó ´Ù¸¨´Ï´Ù. Windows°£ È£½ºÆ®¿¡¼­ WAN¿¡¼­´Â ÃÖÀå 0.7ÃÊ°¡ º¸°íµÇ¾ú½À´Ï´Ù.
		- ProudNet ÀÚÃ¼ÀÇ Áö¿¬ ¼Û½Å ±â´ÉÀº ÃÖÀå 0.01ÃÊÀÔ´Ï´Ù.

		\~english
		Turn on or off <a target="_blank" href="http://guide.nettention.com/cpp_en#delayed_send" >TCP delayed transmitting function and Nagle algorism</a> function. It normally use TCP and sensitive with latency. If application does not require high traffic, sometimes set this value to false.
		- Default value is true
		- If it is true, it will trun on TCP Nagle algorism and turn off delayed sending function.
		- If it is false, it will turn off TCP Nagle algorism and turn on delayed sending function.
		- TCP Nagle algorism is different depends on OS. Longest time that reported is 0.7 second in WAN, Host between Windows.
		- ProudNet's delayed sending function is 0.01 second for longest.

		\~chinese
		?ûäíº?<a target="_blank" href="http://guide.nettention.com/cpp_zh#delayed_send" >TCP æÅ?áêãáÍíÒöûúNagleß©Ûö</a>%ÍíÒö¡£ñ«é©ŞÅéÄTCP£¬?latency??ÚÂÊï£¬÷×ãáÕáá´îÜ?éÄå¥÷êó®?ò¦ïÒ?false¡£
		- Ùù??ãÀtrue¡£
		- trueîÜ???TCP Nagleß©Ûö£¬??ProudNetÜâãóîÜæÅ??áêÍíÒö¡£
		- falseîÜ???TCP Nagleß©Ûö£¬??ProudNetÜâãóîÜæÅ??áêÍíÒö¡£
		- TCP Nagleß©ÛöĞÆËß???Í§ì»ÜôÔÒ¡£Windows ?îÜñ«Ïõñé£¬î¤WAN?Í±õÌ??0.7õ©¡£
		- ProudNetÜâãóîÜæÅ??áêÍíÒöîÜõÌ?ãÀ0.01õ©¡£

		\~japanese
		\ref delayed_send Ñ¦Òöªò«ª«ó?«ª«Õª·ªŞª¹¡£TCPªòñ«ªËŞÅª¤ªÊª¬ªé«ì?«Æ«ó«·?ªËÚÂÊïªÇ¡¢÷×ãáÖùªÎá´ªÊª¤«¢«×«êªÏª³ªÎö·ªòflaseªÇò¦ïÒª·ª¿ªêª·ªŞª¹¡£
		- ĞñÜâö·ªÏtrueªÇª¹¡£
		- trueªÎíŞùê¡¢TCP Nagle«¢«ë«´«ê«º«àª¬«ª«óªËªÊªÃªÆProudNetí»?ªÎ?æÅáêãáÑ¦Òöª¬«ª«ÕªËªÊªêªŞª¹¡£
		- falseªÎíŞùê¡¢TCP Nagle«¢«ë«´«ê«º«àª¬«ª«ÕªËªÊªÃªÆProudNetí»?ªÎ?æÅáêãáÑ¦Òöª¬«ª«óªËªÊªêªŞª¹¡£
		- TCP Nagle «¢«ë«´«ê«º«àªÏOSªËªèªÃªÆêŞª¤ªŞª¹¡£WindowsÊàªÎ«Û«¹«ÈªÇWANªÇªÏõÌíş0.7õ©ª¬ÜÃÍ±ªµªìªÆª¤ªŞª¹¡£
		- ProudNet í»?ªÎ?æÅáêãáÑ¦ÒöªÏõÌíş0.01õ©ªÇª¹¡£

		\~
		*/
		bool m_enableNagleAlgorithm;

		/**
		\~korean
		P2P Group »ı¼º¿¡ »ç¿ëÇÒ ¿¹¾àµÈ ¹üÀ§ÀÇ HostIDÀÇ ½ÃÀÛ°ªÀÔ´Ï´Ù. ¹üÀ§ÀÇ Å©±â´Â m_reservedHostIDCount·Î ¼³Á¤ÇÏ½Ê½Ã¿À.
		- Å¬¶óÀÌ¾ğÆ®µéÀÇ HostID´Â ÀÌ ¿¹¾à ¹üÀ§¸¦ ÇÇÇØ¼­ »ı¼ºµË´Ï´Ù.
		- CreateP2PGroup()¿¡ ÀÌ ¿¹¾à ¹üÀ§¿¡ ÀÖ´Â °ªÀ» ³Ö¾î¼­ »ç¿ëÀÚ°¡ ¿øÇÏ´Â HostID°ªÀ» °¡Áø P2P groupÀ» »ı¼ºÇÒ ¼ö ÀÖ½À´Ï´Ù.

		\~english 
		This is the starting value of HostID within the reserved range to be used in generation of a P2P group. The size of the range should be set with m_reservedHostIDCount. 
		- The HostID of the clients is generated by avoiding the reserved range. 
		- By inserting the value within this reserved range in CreateP2PGroup(), you can create a P2P group with the HostID value wanted by the user. 

		\~chinese
		î¤ßæà÷P2P Group ?é©ŞÅéÄîÜ?ïÒÛõ??îÜ HostID ôøã·?¡£??Ûõ?ÓŞá³?öÇ? m_reservedHostIDCount¡£
		- á¶é©?ïÈîÜËÔ?Ó® HostID?ù­????ïÒÛõ?ßæà÷¡£
		- î¤CreateP2PGroup()ñé?ìıó®?ïÒÛõ??îÜ?Ê¦ì¤ßæà÷?êóéÄ?á¶ıñØĞ HostID?îÜ P2P group¡£

		\~japanese
		P2P Group ßæà÷ªËŞÅéÄª¹ªëåøå³ªµªìª¿Ûô?ªÎHostIDªÎ«¹«¿?«Èö·ªÇª¹¡£Ûô?ªÎÓŞª­ªµªÏ m_reservedHostIDCountªËàâïÒª·ªÆª¯ªÀªµª¤¡£
		- ïÈ?ªµªìª¿«¯«é«¤«¢«ó«Èª¿ªÁªÎHostIDªÏª³ªÎåøå³Ûô?ªòù­ª±ªÆßæà÷ªµªìªŞª¹¡£
		- CreateP2PGroup()ªËª³ªÎåøå³Ûô?ªËª¢ªëö·ªòìıªìªÆ«æ?«¶ª¬ØĞªàHostIDö·ªòªâªÃª¿P2P groupªòßæà÷ªÇª­ªŞª¹¡£
		\~
		*/
		HostID m_reservedHostIDFirstValue;

		/**
		\~korean
		P2P Group »ı¼º¿¡ »ç¿ëÇÒ ¿¹¾àµÈ ¹üÀ§ÀÇ HostIDÀÇ °¹¼öÀÔ´Ï´Ù. ½ÃÀÛ°ªÀº m_reservedHostIDFirstValue·Î ¼³Á¤ÇÏ½Ê½Ã¿À.

		\~english
		It is the number of HostID in the reserved range that are going to be used for P2P group creation. Start value must be set as m_reservedHostIDFirstValue.

		\~chinese
		î¤ßæà÷P2P Group ?é©ŞÅéÄîÜ?ïÒÛõ??îÜ HostID ??¡£??ôøã·??öÇ?m_reservedHostIDFirstValue¡£

		\~japanese
		P2P Groupßæà÷ªËŞÅéÄª¹ªëåøå³ªµªìª¿Ûô?ªÎHostIDªÎ?ªÇª¹¡£«¹«¿?«Èö·ªÏm_reservedHostIDFirstValueªËàâïÒª·ªÆª¯ªÀªµª¤¡£

		\~
		*/
		int m_reservedHostIDCount;

		/**
		\~korean
		»ç¿ëÀÚ Á¤ÀÇ ¸Ş¼­µå¸¦ »ç¿ëÀÚ°¡ ¼öµ¿À¸·Î »ı¼ºÇÑ thread pool¿¡¼­ ½ÇÇàÇÏ°Ô ÇÕ´Ï´Ù. ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#thread_pool_sharing" >¼­¹ö¿¡¼­ ¿©·¯ È£½ºÆ® ¸ğµâÀÌ °°Àº Thread Pool¸¦ °øÀ¯ÇÏ±â</a> À» Âü°íÇÏ½Ê½Ã¿À.
		- ±âº»°ªÀº nullÀÔ´Ï´Ù.
		- ÀÌ °ªÀ» ¼³Á¤ÇßÀ» °æ¿ì m_threadCount´Â ¹«½ÃµË´Ï´Ù.

		\~english
		Running user defined method in thread pool that created manually by user. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#thread_pool_sharing" >Share Thread Pool that has same host module in a server.</a> for more detail.
		- Default value is null
		- When you set this value, m_threadCount is ignored.

		\~chinese
		î¤éÄ?â¢?ßæà÷îÜthread pool×ì?ú¼éÄ?ïÒ?Û°Ûö¡£????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#thread_pool_sharing" >î¤Ü×?ĞïñéÍìú½??ñ«ÏõÙ¼?ßÓÔÒîÜThread Pool</a>%¡£
		- Ùù??ãÀnull¡£
		- ?ïÒó®?îÜ??ûì?m_threadCount¡£

		\~japanese
		«æ?«¶?ïÒëù«á«½«Ã«Éªò«æ?«¶?ª¬ñ«ÓôªÇßæà÷ª·ª¿thread poolªÇ?ú¼ª¹ªëªèª¦ªËª·ªŞª¹¡£ßÙª·ª¯ªÏ¡¢\ref thread_pool_sharingªòª´?ğÎª¯ªÀªµª¤¡£
		- ĞñÜâö·ªÏnullªÇª¹¡£
		- ª³ªÎö·ªòàâïÒª·ª¿íŞùê¡¢m_threadCountªÏÙíãÊªµªìªŞª¹¡£

		\~
		*/
		CThreadPool* m_externalUserWorkerThreadPool;

		/**
		\~korean
		network I/O °ü·Ã ·çÆ¾À» »ç¿ëÀÚ°¡ ¼öµ¿À¸·Î »ı¼ºÇÑ thread pool¿¡¼­ ½ÇÇàÇÏ°Ô ÇÕ´Ï´Ù. ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#thread_pool_sharing" >¼­¹ö¿¡¼­ ¿©·¯ È£½ºÆ® ¸ğµâÀÌ °°Àº Thread Pool¸¦ °øÀ¯ÇÏ±â</a> À» Âü°íÇÏ½Ê½Ã¿À.
		- ±âº»°ªÀº nullÀÔ´Ï´Ù.
		- ÀÌ °ªÀ» ¼³Á¤ÇßÀ» °æ¿ì m_networkerThreadCount´Â ¹«½ÃµË´Ï´Ù. m_externalNetWorkerThreadPool°¡ »ç¿ëÀÚ°¡ ¼öµ¿À¸·Î »ı¼ºÇÑ thread poolÀÎ

		\~english
		Running network I/O related routine in thread pool that created manually by user. Please refer to  <a target="_blank" href="http://guide.nettention.com/cpp_en#thread_pool_sharing" >Share Thread Pool that has same host module in a server.</a> for more detail.
		- Default value is null
		- When you set this value, m_networkerThreadCount is ignored.

		\~chinese
		î¤éÄ?â¢?ßæà÷îÜthread pool×ì?ú¼network I/OßÓ?routine¡£????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#thread_pool_sharing" >î¤Ü×?ĞïñéÍìú½??ñ«ÏõÙ¼?ßÓÔÒîÜThread Pool</a>%¡£
		- Ùù??ãÀnull¡£
		- ?ïÒó®?îÜ??ûì?m_networkerThreadCount¡£

		\~japanese
		network I/O ?Ö§«ë?«Á«óªò«æ?«¶?ª¬â¢ÔÑªÇßæà÷ª·ª¿thread poolªÇ?ú¼ª¹ªëªèª¦ªËª·ªŞª¹¡£ßÙª·ª¯ªÏ¡¢\ref thread_pool_sharingªòª´?ğÎª¯ªÀªµª¤¡£
		- ĞñÜâö·ªÏnullªÇª¹¡£
		- ª³ªÎö·ªòàâïÒª·ª¿íŞùê¡¢m_networkerThreadCountªÏÙíãÊªµªìªŞª¹¡£m_externalNetWorkerThreadPoolª¬«æ?«¶?ª¬â¢ÔÑªÇßæà÷ª·ª¿thread poolªÇª¢ªë

		\~
		*/
		CThreadPool* m_externalNetWorkerThreadPool;

		/**
		\~korean
		- OnException Äİ¹é ±â´ÉÀ» »ç¿ëÇÒ Áö ¿©ºÎ¸¦ ¼±ÅÃÇÕ´Ï´Ù.
		- ±âº»°ªÀº trueÀÔ´Ï´Ù.
		- ¸¸¾à false¸¦ ÁöÁ¤ÇÏ¸é À¯Àú Äİ¹é¿¡¼­ ¿¹»óÄ¡ ¸øÇÑ Exception ¹ß»ı ½Ã OnExceptionÀÌ È£ÃâµÇÁö ¾Ê°í Å©·¡½Ã°¡ ¹ß»ıÇÕ´Ï´Ù.

		\~english
		- Decide whether it uses OnException callback function or not.
		- Default value is true.
		- If setting it as false, when exception occurs during  user callback, crash will occur as OnException is not called.

		\~chinese
		- ??ãÀÜúŞÅéÄ OnException CallbackÍíÒö¡£
		- ĞñÜâ?? true¡£
		- åıÍıò¦ïÒfalse£¬éÄ?î¤Callback?ïïñé?ßæëòßÌÜôÓğîÜ Exception ?£¬OnException?Üôù¬û¼õó£¬ó¦?ßæCrash¡£

		\~japanese
		- OnException CallbackÑ¦ÒöªòŞÅéÄª¹ªëª«ªÉª¦ª«ªòàÔ?ª·ªŞª¹¡£
		- «Ç«Õ«©«ë«Èö·ªÏtrueªÇª¹¡£
		- ªâª·falseªòò¦ïÒª¹ªëªÈ«æ?«¶?Callbackª«ªéåøßÌªÇª­ªÊª¤Exceptionª¬?ßæª·ª¿ãÁ¡¢OnExceptionª¬û¼ªÓõóªµªìªºªË«¯«é«Ã«·«åª¬?ßæª·ªŞª¹¡£
		\~
		*/
		bool m_allowExceptionEvent;

		/**
		\~korean
		- ¾ÏÈ£È­ ±â´ÉÀ» ÄÑ°Å³ª ²ü´Ï´Ù.
		- ÀÏ¹İÀûÀ¸·Î´Â ¾ÏÈ£È­ ±â´ÉÀ» ÄÑ´Â °ÍÀÌ ÁÁ½À´Ï´Ù. ÇÏÁö¸¸ Å¬¶óÀÌ¾ğÆ®°¡ ¼­¹ö¿¡ Á¢¼ÓÇÒ ¶§ º¸¾È key ±³È¯À» À§ÇØ ¼­¹öÀÇ ¿¬»ê ½Ã°£À» ´õ ¸¹ÀÌ ¼Ò¿äÇÏ°Ô µË´Ï´Ù.
		- ¾ÏÈ£È­ ±â´ÉÀÌ ÀüÇô ÇÊ¿ä ¾ø´Â °ÔÀÓ ¼­¹ö¶ó¸é º» ±â´ÉÀ» ²ô½Ã´Â °ÍÀÌ ÁÁ½À´Ï´Ù.
		- ±âº»°ªÀº trueÀÔ´Ï´Ù.

		\~english
		- Turn on or off the encryption feature. 
		- Generally it¡¯s better to turn on the encryption feature. However, when the client connects to the server, the calculation time of the server is spent more to exchange encryption keys. 
		- If this is a game server without any need for an encryption feature, it¡¯s better to turn off this feature. 
		- The default value is true. 

		\~chinese
		- ??ûä??Ê¥ÚËÍíÒö
		- Ëï???Ê¥ÚËÍíÒö¡£Ó£î¤ËÔ?Ó®?ïÈÜ×?ĞïÎß?äÌîïÚË??ïï?á¼ÙÄìéŞÁÜ×?ĞïæÑß©??¡£
		- åıÍıêı?Ü×?ĞïÜôâÍé©ìòù¼Ê¥ÚËÊ¦ì¤??ÜâÍíÒö¡£
		- Ùù???¡°true¡±¡£

		\~japanese
		- äŞ?ûùÑ¦Òöªò«ª«ó?«ª«Õª·ªŞª¹¡£
		- ìéÚõîÜªËªÏäŞ?ûùÑ¦ÒöªòÜõª±ª¿Û°ª¬ÕŞª¤ªÇª¹¡£ª·ª«ª·¡¢«¯«é«¤«¢«ó«Èª¬«µ?«Ğ?ªËïÈ?ª¹ªëãÁ¡¢«»«­«å«ê«Æ«£«­?ÎßüµªÎª¿ªáªË«µ?«Ğ?ªÎæÑß©ãÁÊàªòªâªÃªÈÒıª¯ù±é©ªÈª·ªŞª¹¡£
		- äŞ?ûùÑ¦Òöª¬îïª¯é©ªéªÊª¤«²?«à«µ?«Ğ?ªÊªéÜâÑ¦Òöªòá¼ª·ª¿Û°ª¬ÕŞª¤ªÇª¹¡£
		- ĞñÜâö·ªÏtrueªÇª¹¡£

		\~
		*/
		bool m_enableEncryptedMessaging;
	protected:
		CStartServerParameterBase();

	};

	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
