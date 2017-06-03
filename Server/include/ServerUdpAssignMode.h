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
¼­¹ö°¡, ¼­¹ö¿¡ Á¢¼ÓÇÏ´Â Å¬¶óÀÌ¾ğÆ®¿Í Åë½ÅÇÒ ¶§ »ç¿ëÇÒ UDP ¼ÒÄÏÀ» ¹èÁ¤ÇÏ´Â Á¤Ã¥ÀÔ´Ï´Ù.
ÀÚ¼¼ÇÑ »çÇ×Àº <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_udp_assign" >¼­¹öÀÇ UDP Æ÷Æ® »ç¿ë ¹æ½Ä</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.

\~english
This is a policy allocating UDP sockets to be used by the serverwhen communicating with the clients.
Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#server_udp_assign" >Method of using Server UDP Port</a> for more details.

\~chinese
İÂÛÕÜ×?Ğï??ïÈÜ×?ĞïîÜclient÷×ãáîÜ?ı¦ŞÅéÄîÜUDP socketîÜïÙóş¡£
????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_udp_assign" >Ü×?ĞïUDPÓ®Ï¢ŞÅéÄÛ°Ûö</a>%¡£

\~japanese
«µ?«Ğ?ª¬¡¢«µ?«Ğ?ªËïÈ?ª¹ªë«¯«é«¤«¢«ó«ÈªÈ÷×ãáª¹ªëãÁªËŞÅª¦UDP«½«±«Ã«ÈªòùÜªê?ªÆªë«İ«ê«·?ªÇª¹¡£
ßÙª·ª¯ªÏ¡¢\ref server_udp_assign ªòª´?ğÎª¯ªÀªµª¤¡£
\~
*/
	enum ServerUdpAssignMode
	{
		/**
		\~korean
		ÁöÁ¤¾ÈµÊ. »ç¿ëÀÚ´Â ÀÌ °ªÀ» ¾²Áö ¸¶½Ê½Ã¿À.

		\~english
		Not designated. Users are not to use this value.

		\~chinese
		?ù¬ò¦ïÒ¡£éÄ?Üôé©ŞÅéÄó®?¡£

		\~japanese
		Ú±ò¦ïÒ¡£«æ?«¶?ªÏª³ªÎö·ªòŞÅªÃªÆªÏª¤ª±ªŞª»ªó¡£
		\~
		*/
		ServerUdpAssignMode_None,

		/**
		\~korean
		Á¢¼ÓÀÌ µé¾î¿À´Â °¢ Å¬¶óÀÌ¾ğÆ®¿¡ ´ëÇØ¼­ ¼­·Î ´Ù¸¥ UDP Æ÷Æ®¸¦ »ç¿ëÇÕ´Ï´Ù.
		- º» °ªÀº ±âº»°ªÀÌ¸ç, ±ÇÀåµÇ´Â °ªÀÔ´Ï´Ù.
		- ÀÌ °ªÀº Proud.CStartServerParameter.m_udpPorts ¿¡µµ ¿µÇâÀ» ¹ÌÄ¨´Ï´Ù.

		\~english
		For each clients that coonects, it is to use different UDP port for each of them.
		- This value is a default and recommended value.
		- This value affects Proud.CStartServerParameter.m_udpPorts also.

		\~chinese
		??ïÈîÜclientŞÅéÄÜôÔÒîÜUDPÓ®Ï¢¡£
		- ó®?ãÀÙù??£¬ì»ó¦ãÀù¬Ëï?îÜ?¡£
		- ó®?å¥? Proud.CStartServerParameter.m_udpPorts%?ßæç¯?¡£

		\~japanese
		ïÈ?ª¬ìıªÃªÆª¯ªëÊÀ«¯«é«¤«¢«ó«ÈªË?ª·ªÆßÓû»êŞª¦UDP«İ?«ÈªòŞÅéÄª·ªŞª¹¡£
		- ª³ªÎö·ªÏĞñÜâö·ªÇ¡¢??ö·ªÇª¹¡£
		- ª³ªÎö·ªÏ¡¢Proud.CStartServerParameter.m_udpPortsªËªâç¯úÂªòĞàªÜª·ªŞª¹¡£
		\~
		*/
		ServerUdpAssignMode_PerClient,

		/**
		\~korean
		Á¢¼ÓÀÌ µé¾î¿À´Â ¸ğµç Å¬¶óÀÌ¾ğÆ®´Â ¹Ì¸® ÁØºñµÇ¾î ÀÖ´Â °íÁ¤µÈ °¹¼öÀÇ UDP Æ÷Æ®¸¦ Àç»ç¿ëÇÕ´Ï´Ù.
		ÀÌ ¼³Á¤À» »ç¿ëÇÒ °æ¿ì UDPÀÇ Æ¯¼º»ó ¼­¹ö¿Í Åë½ÅÀ» ÇÏ±â ¾î·Á¿î Å¬¶óÀÌ¾ğÆ®µéÀÌ »ı±æ ¼ö ÀÖ½À´Ï´Ù.
		- º» ¿É¼ÇÀº ProudNetÀÇ ÇÏÀ§ È£È¯¼º ¶§¹®¿¡ ÁØºñµÈ ±â´ÉÀÌ¸ç, ±ÇÀåÇÏÁö ¾Ê´Â ±â´ÉÀÔ´Ï´Ù.
		- º» ¿É¼Ç »ç¿ë½Ã ¹æÈ­º® ¼³Á¤ÀÌ ÇÊ¿äÇÕ´Ï´Ù. ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#block_icmp" >ICMP °ü·Ã ¹æÈ­º® ¼³Á¤</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.
		ÀÌ °ªÀº Proud.CStartServerParameter.m_udpPorts ¿¡µµ ¿µÇâÀ» ¹ÌÄ¨´Ï´Ù.

		\~english
		All the clients that connect reuse the UDP ports that are already prepared.
		When using this option, it is possible to cause some clients hard to communicate with the server due to UDP characteristics.
		- This is option is prepared for the lower compatibility of Proudnet and it is not recommended to use.
		- It is necessary to use a firewall setup to use this feature. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#block_icmp" >Firewall setup for ICMP related
</a> for more details.
		This value affects Proud.CStartServerParameter.m_udpPorts also.

		\~chinese
		?ïÈîÜclientî¢ó­ŞÅéÄì«?ñ×?û¿îÜÍ³ïÒ??îÜUDPÓ®Ï¢¡£
		ŞÅéÄó®?öÇîÜ?ı¦£¬ì×UDPîÜ÷åàõ£¬Ê¦Òö??ßæ?Ü×?Ğï?ì¤÷×ãáîÜclient¡£
		- ó®??ì×?ãÀ?ProudNetîÜù»êÈÌÂé»àõì»ñ×?îÜÍíÒö£¬ãÀÜôõÏ?îÜÍíÒö¡£
		- ŞÅéÄó®???âÍé©ÛÁûı??öÇ¡£????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#block_icmp" >ICMP ßÓ?îÜÛÁûı??öÇ</a>%¡£
		ó®?å¥? Proud.CStartServerParameter.m_udpPorts%?ßæç¯?¡£

		\~japanese
		ïÈ?ª¬ìıªÃªÆª¯ªëîïªÆªÎ«¯«é«¤«¢«ó«ÈªÏîñªâªÃªÆñŞİáªµªìªÆª¤ªëÍ³ïÒ?ªÎUDP«İ?«Èªòî¢ŞÅéÄª·ªŞª¹¡£
		ª³ªÎàâïÒªòŞÅéÄª¹ªëíŞùê¡¢UDPªÎ÷åàõª«ªé«µ?«Ğ?ªÈªÎ÷×ãáª¬Ññª·ª¤«¯«é«¤«¢«ó«Èª¬?ßæª¹ªëª³ªÈª¬ª¢ªêªŞª¹¡£
		- ª³ªÎ«ª«×«·«ç«óªÏProudNetªÎù»êÈû»üµàõªÎª¿ªáñŞİáªµªìª¿Ñ¦ÒöªÇ¡¢??ª·ªÊª¤Ñ¦ÒöªÇª¹¡£
		- ª³ªÎ«ª«×«·«ç«óªòŞÅª¦ãÁªÏ«Õ«¡«¤«¢«¦«©?«ëàâïÒª¬ù±é©ªÇª¹¡£ßÙª·ª¯ªÏ¡¢\ref block_icmpªòª´?ğÎª¯ªÀªµª¤¡£
		ª³ªÎö·ªÏ¡¢Proud.CStartServerParameter.m_udpPortsªËªâç¯úÂªòĞàªÜª·ªŞª¹¡£
		\~
		*/
		ServerUdpAssignMode_Static,
	};

	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
