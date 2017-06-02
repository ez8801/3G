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
#include "StartServerParameterBase.h"
#include "ServerUdpAssignMode.h"

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
Parameters for NetServer startup.
*/
	class CStartServerParameter : public CStartServerParameterBase
	{
	public:
		/**
		\~korean
		TCP ¸®½º´× Æ÷Æ® ¸ñ·Ï.
		- Æ÷Æ®¸¦ ¿©·¯°³ ¸¸µé¾î¼­ ¿©·¯°³ÀÇ Listening socketÀ» »ı¼ºÇÒ¼ö ÀÖ½À´Ï´Ù.
		- ¸ñ·ÏÀ» Ã¤¿ìÁö ¾ÊÀ¸¸é 0ÀÌ µé¾î°©´Ï´Ù. 0À» ÁöÁ¤ÇÏ¸é TCP ¸®½º´× Æ÷Æ® ÇÑ°³°¡ ÀÚµ¿ ÇÒ´çµË´Ï´Ù. ÀÚµ¿ ÇÒ´çÀÌ À¯¿ëÇÑ °æ¿ì´Â,
		Å¬¶óÀÌ¾ğÆ®°¡ ¼­¹ö¿¡ Á¢¼ÓÇÏ±â Àü¿¡ ÀÚµ¿ ÇÒ´çµÈ Æ÷Æ® ¹øÈ£¸¦ ¹ŞÀº °æ¿ì,
		¿¹¸¦ µé¾î ½ºÆ®·¹½º Å×½ºÆ®¸¦ À§ÇØ ºÒÆ¯Á¤ ´Ù¼öÀÇ ¼­¹ö¸¦ ¶ç¿ö¾ß ÇÏ´Â °æ¿ìÀÔ´Ï´Ù.
		ÀÌ¶§ Å¬¶óÀÌ¾ğÆ®¿¡°Ô ÀÚµ¿ÇÒ´çµÈ Æ÷Æ® ÁÖ¼Ò¸¦ ¾Ë·ÁÁà¾ß ÇÕ´Ï´Ù.
		ÀÚµ¿ ÇÒ´çµÈ Æ÷Æ® ¹øÈ£´Â GetServerAddrPort()·Î ¾òÀ» ¼ö ÀÖ½À´Ï´Ù.

		\~english
		TCP listening port
		- The initial value is 0. The TCP listening port is to be allocated automatically when 0 is designated.
		It is useful to use the automatic allocation when a client received an automatically allocated port number before connected to the server,
		for exmple, when you need to launch multiple anonymous servers for a stress test.
		If this is the case, then the server must let the clients know the automatically allocated port addresses.
		The automatically allocated port numbers can be acquired using GetServerAddrPort().

		\~chinese
		TCP listingÓ®Ï¢ÙÍ?
		- ?Ëï??Ó®Ï¢ì¤ı¨Ê¦ì¤ßæà÷??Listening socket¡£
		- Üô?õöÙÍ?îÜ???ìı0¡£ò¦ïÒ0îÜ?TCP listingìé?port?í»?İÂÛÕ¡£í»?İÂÛÕêóéÄîÜï×?ãÀ£¬clientî¤?ïÈÜ×?ĞïñıîñïÈâ¥í»?İÂÛÕîÜport??îÜ?ı¦£¬ÖÇåı?Öõ?ïï??£¬é©öè?Üô÷åïÒîÜÒı?Ü×?ĞïîÜ?ı¦¡£
		??ı¦é©Í±?clientí»?İÂÛÕîÜportò¢ò£¡£
		í»?İÂÛÕîÜport??Ê¦ì¤ë¦GetServerAddrPort()?Ôğ¡£

		\~japanese
		TCP«ê«¹«Ë«ó«°«İ?«È«ê«¹«È
		- «İ?«ÈªòÜÜ?íÂªÃªÆÜÜ?ªÎListening socketªòßæà÷ª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
		- «ê«¹«Èªò?ª¿ªµªÊª±ªìªĞ0ª¬ìıªêªŞª¹¡£0ªòò¦ïÒª¹ªëªÈTCP«ê«¹«Ë«ó«°«İ?«È1ËÁª¬í»ÔÑùÜªê?ªÆªéªìªŞª¹¡£
		í»ÔÑùÜ?ª¬êóéÄªÊíŞùêªÏ¡¢
		«¯«é«¤«¢«ó«Èª¬«µ?«Ğ?ªËïÈ?ª¹ªëîñªËí»ÔÑùÜªê?ªÆªéªìª¿«İ?«ÈÛã?ªòáôª±ª¿íŞùê¡¢
		ÖÇª¨ªĞ¡¢«¹«È«ì«¹«Æ«¹«ÈªÎª¿ªáªËÜô÷åïÒÒı?ªÎ«µ?«Ğ?ªòÑÃÔÑª·ªÊª±ªìªĞªÊªéªÊª¤íŞùêªÇª¹¡£
		ª³ªÎãÁ¡¢«¯«é«¤«¢«ó«ÈªËí»ÔÑùÜªê?ªÆªéªìª¿«İ?«È«¢«É«ì«¹ªòò±ªéª»ªÊª±ªìªĞªÊªêªŞª»ªó¡£
		í»ÔÑùÜªê?ªÆªéªìª¿«İ?«ÈÛã?ªÏ GetServerAddrPort()ªÇÔğªéªìªŞª¹¡£
		\~
		*/
		CFastArray<int> m_tcpPorts;

		/**
		\~korean
		UDP È£½ºÆ® Æ÷Æ® ¸ñ·ÏÀÔ´Ï´Ù.
		m_udpAssignMode°¡ Proud.ServerUdpAssignMode_PerClient ÀÎ °æ¿ì º» ¸ñ·ÏÀº ¹«½ÃµË´Ï´Ù.

		m_udpAssignMode°¡ Proud.ServerUdpAssignMode_Static ÀÎ °æ¿ì º» ¸ñ·ÏÀº ´ÙÀ½°ú °°ÀÌ ÀÛµ¿ÇÕ´Ï´Ù.
		- 0ÀÌ µé¾îÀÖ´Â ¹è¿­ÀÎ °æ¿ì: 0ÀÌ µé¾îÀÖ´Â °¹¼ö¸¸Å­ ÀÓÀÇ Æ÷Æ® ¹øÈ£¸¦ °¡Áö´Â UDP ¼ÒÄÏµéÀÌ ¹Ì¸® ÁØºñµË´Ï´Ù.
		ÀÌ¶§ ½ÇÁ¦ ¹èÁ¤µÈ Æ÷Æ® ¹øÈ£¸¦ ¾òÀ¸·Á¸é CNetServer.GetServerUdpAddrPort()¸¦ »ç¿ëÇÏ¸é µË´Ï´Ù.
		- 0 ÀÌ¿ÜÀÇ °ªµéÀÌ µé¾îÀÖ´Â ¹è¿­ÀÎ °æ¿ì: ¹è¿­¿¡ µé¾îÀÖ´Â °ªÀ» °¡Áø UDP ¼ÒÄÏµéÀÌ ¹Ì¸® ÁØºñµË´Ï´Ù.

		- UDP È£½ºÆ® Æ÷Æ® ¸ñ·ÏÀº ¼­¹ö¿ë ¹æÈ­º® ¼³Á¤¿¡ ¿µÇâÀ» Áİ´Ï´Ù. <a target="_blank" href="http://guide.nettention.com/cpp_ko#firewall_setting" >¼­¹ö¿¡¼­ÀÇ ¹æÈ­º® ¼³Á¤</a> À» Âü°íÇÏ½Ê½Ã¿À.
		- Æ÷Æ® °¹¼öÀÇ ÀûÁ¤¼±¿¡ ´ëÇØ¼­´Â <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_udp_assign" >¼­¹öÀÇ UDP Æ÷Æ® »ç¿ë ¹æ½Ä</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.
		- °³¿ä¿¡ ´ëÇØ¼­´Â <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_listen" >¼­¹ö¿¡¼­ Å¬¶óÀÌ¾ğÆ® ¿¬°á ¹Ş±â¸¦ ½ÃÀÛÇÏ±â</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.

		\~english
		This is a list of UDP host port
		When m_udpAssignMode is same as Proud.ServerUdpAssignMode_PerClient, this list will be ignored;

		When m_udpAssignMode is same as Proud.ServerUdpAssignMode_Static, this list will work as followings;
		- in the case the allocation containing 0 value: The UDP sockets, as many as of the number of 0s containing, with random port numbers will be prepared.
		CNetServer.GetServerUdpAddrPort() is used to get the port numbers that are actually allocated.
		- in the case the allocation containing other values other than 0: The UDP sockets with the values contained within the allocation will be prepared.

		- The list of UDP host port affects a firewall settings for servers. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#firewall_setting" >Setting firewall from server</a> for more details.
		- About reasonable number of port, please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#server_udp_assign" >Method of using Server UDP Port</a>.
		- For the summary, please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#server_listen" >How to start receiving client connection</a>.

		\~chinese
		ãÀUDPñ«ÏõÓ®Ï¢ÙÍ?¡£
		m_udpAssignModeãÀ Proud.ServerUdpAssignMode_PerClient%îÜ?ı¦ó®Ùé?ÙÍ?¡£

		m_udpAssignModeãÀ Proud.ServerUdpAssignMode_Static%îÜ?ı¦ó®ÙÍ??åıù»??¡£
		- êó0îÜ??îÜ?ı¦£º??à»ñ×??êóßÓ?éÍêó0?ÕáîÜìòëòport??îÜUDP socket¡£
		ó®?ßÌ?Ôğ??İÂÛÕîÜport??îÜ?£¬Ê¦ì¤ŞÅéÄ CNetServer.GetServerUdpAddrPort()¡£
		- êó0ì¤èâ?îÜ??îÜ?ı¦£º?à»ñ×??êó??×ìîÜ?îÜUDP socket¡£

		- UDPñ«Ïõport??Ü×?ĞïéÄÛÁûı??öÇ?ßæç¯?¡£??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#firewall_setting" >?öÇÜ×?ĞïÛÁûı?</a>%¡£
		- ?port??îÜùê×â???ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_udp_assign" >Ü×?ĞïUDPÓ®Ï¢ŞÅéÄÛ°Ûö</a>%¡£
		- ??é©??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_listen" >î¤Ü×?Ğï?ñé?ã·ïÈâ¥ËÔ?Ó®?ïÈ</a>%¡£

		\~japanese
		UDP«Û«¹«È«İ?«È«ê«¹«ÈªÇª¹¡£
		m_udpAssignModeª¬Proud.ServerUdpAssignMode_PerClientªÇª¢ªëíŞùê¡¢Üâ«ê«¹«ÈªÏÙíãÊªµªìªŞª¹¡£
		
		m_udpAssignModeª¬Proud.ServerUdpAssignMode_StaticªÇª¢ªëíŞùê¡¢Üâ«ê«¹«ÈªÏó­ªÎªèª¦ªËíÂÔÑª·ªŞª¹¡£
		- 0ª¬ìıªÃªÆª¤ªëÛÕÖªªÎíŞùê£º0ª¬ìıªÃªÆª¤ªë?ªÀª±ªÎìòëò«İ?«ÈÛã?ªòò¥ªÄUDP«½«±«Ã«Èª¬îñªâªÃªÆñŞİáªµªìªŞª¹¡£
		ª³ªÎãÁ¡¢?ğ·ùÜªê?ªÆªéªìª¿«İ?«ÈÛã?ªòÔğªëª¿ªáªËªÏ¡¢CNetServer.GetServerUdpAddrPort()ªòŞÅª¨ªĞÕŞª¤ªÇª¹¡£
		- 0ì¤èâªÎö·ª¬ìıªÃªÆª¤ªëÛÕÖªªÎíŞùê£ºÛÕÖªªËìıªÃªÆª¤ªëö·ªòò¥ªÄUDP«½«±«Ã«ÈªòîñªâªÃªÆñŞİáª·ªŞª¹¡£
		- UDP «Û«¹«È«İ?«È«ê«¹«ÈªÏ«µ?«Ğ?éÄ«Õ«¡«¤«¢«¦«©?«ëàâïÒªËç¯úÂªò?ª¨ªŞª¹¡£\ref firewall_settingªòª´?ğÎª¯ªÀªµª¤¡£
		- «İ?«È?ªÎîêïáàÊªË?ª·ªÆªÏ¡¢\ref server_udp_assignªòª´?ğÎª¯ªÀªµª¤¡£
		- ?é©ªË?ª·ªÆªÏ¡¢\ref server_listenªòª´?ğÎª¯ªÀªµª¤¡£
		\~
		*/
		CFastArray<int> m_udpPorts;

		/**
		\~korean
		UDP È£½ºÆ® Æ÷Æ® »ç¿ë Á¤Ã¥ÀÔ´Ï´Ù.
		- UDP È£½ºÆ® Æ÷Æ® ¸ñ·ÏÀº ¼­¹ö¿ë ¹æÈ­º® ¼³Á¤¿¡ ¿µÇâÀ» Áİ´Ï´Ù. <a target="_blank" href="http://guide.nettention.com/cpp_ko#firewall_setting" >¼­¹ö¿¡¼­ÀÇ ¹æÈ­º® ¼³Á¤</a> À» Âü°íÇÏ½Ê½Ã¿À.
		- º» ¼³Á¤Àº ¼­¹öÀÇ ¼º´É¿¡ ¿µÇâÀ» Áİ´Ï´Ù. (ÀÚ¼¼ÇÑ ³»¿ë: <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_udp_assign" >¼­¹öÀÇ UDP Æ÷Æ® »ç¿ë ¹æ½Ä</a>)
		- °³¿ä¿¡ ´ëÇØ¼­´Â <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_listen" >¼­¹ö¿¡¼­ Å¬¶óÀÌ¾ğÆ® ¿¬°á ¹Ş±â¸¦ ½ÃÀÛÇÏ±â</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.

		\~english
		This is the policy of using UDP port.
		- The UDP host port list affects the firewall settings for the servers. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#firewall_setting" >Setting firewall from server</a>.
		- This setting affects server functions. (for more details, please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#server_udp_assign" >Method of using Server UDP Port</a>.)
		- For the smmary, please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#server_listen" >How to start receiving client connection</a>.

		\~chinese
		UDPñ«ÏõÓ®Ï¢ŞÅéÄïÙóş¡£
		- UDPñ«ÏõportÙÍ??Ü×?ĞïÛÁûı??öÇ?ßæç¯?¡£??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#firewall_setting" >?öÇÜ×?ĞïÛÁûı?</a>%¡£
		- ó®?öÇ?Ü×?ĞïîÜàõÒö?ßæç¯?¡££¨???é»£º<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_udp_assign" >Ü×?ĞïUDPÓ®Ï¢ŞÅéÄÛ°Ûö</a>£©
		- ??é©??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_listen" >î¤Ü×?Ğï?ñé?ã·ïÈâ¥ËÔ?Ó®?ïÈ</a>%¡£

		\~japanese
		UDP«Û«¹«È«İ?«ÈŞÅéÄ«İ«ê«·?ªÇª¹¡£
		- UDP «Û«¹«È«İ?«È«ê«¹«ÈªÏ«µ?«Ğ?éÄ«Õ«¡«¤«¢«¦«©?«ëàâïÒªËç¯úÂªò?ª¨ªŞª¹¡£\ref firewall_setting ªòª´?ğÎª¯ªÀªµª¤¡£
		- ª³ªÎàâïÒªÏ«µ?«Ğ?ªÎàõÒöªËç¯úÂªò?ª¨ªŞª¹¡£(ßÙª·ª¯ªÏ¡¢\ref server_udp_assign)
		- ?é©ªË?ª·ªÆªÏ¡¢\ref server_listenªòª´?ğÎª¯ªÀªµª¤¡£
		\~
		*/
		ServerUdpAssignMode m_udpAssignMode;

		/**
		\~korean

		\~english

		\~chinese

		\~japanese
		\~
		FOR TEST USE! DO NOT MODIFY THIS
		*/
		bool m_enableIocp;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®¿¡¼­ ÇÊ¿ä½Ã universal plug and play(UPNP) ±â´ÉÀ» ½ÃµµÇÒ °ÍÀÎÁö¿¡ ´ëÇÑ ¿©ºÎÀÔ´Ï´Ù.
		- ±âº»°ªÀº trueÀÔ´Ï´Ù.
		- ¼­¹ö°£ Åë½Å¿¡¼­ CNetClient ¸¦ ¾²´Â °æ¿ì ºÒÇÊ¿äÇÒ ¼ö ÀÖ´Âµ¥ ÀÌ¶§ ÀÌ °ªÀ» false·Î ¼³Á¤ÇØÁÖ¸é µË´Ï´Ù.

		\~english
		This is used to decide wheter to use universal plug and play function for the clients when required.
		- The default vlaue is true.
		- It may not be necessary when CNetClient is used between server communications then set tis value as false.

		\~chinese
		ClientâÍé©?ãÀÜúé©??universal plug and play(UPNP)ÍíÒöîÜ?Üú¡£
		- Ùù??ãÀtrue¡£
		- Ü×?Ğïñı?÷×ãáñéŞÅéÄ CNetClient%îÜ?ı¦Ê¦Òö?ÜôâÍé©£¬??ı¦÷êó®??öÇ?false?Ê¦¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªÇù±é©ãÁªËuniversal plug and play(UPNP)Ñ¦ÒöªòãËª¹ª«ªÉª¦ª«ªË?ª¹ªëÊ¦ÜúªÇª¹¡£
		- ĞñÜâö·ªÏtrueªÇª¹¡£
		- «µ?«Ğ?ÊàªÎ÷×ãáªÇCNetClientªòŞÅª¦íŞùê¡¢Üôé©ªÊíŞùêª¬ª¢ªêªŞª¹ª¬¡¢ª³ªÎãÁ¡¢ª³ªÎö·ªòfalseªÇàâïÒª¹ªìªĞÕŞª¤ªÇª¹¡£
		\~
		*/
		bool m_upnpDetectNatDevice;

		/**
		\~korean
		trueÀÌ¸é Å¬¶óÀÌ¾ğÆ®¿¡¼­ ÇÊ¿ä½Ã universal plug and play(UPNP) ±â´ÉÀ» ÀÌ¿ëÇÏ¿© TCP È¦ÆİÄª ¿¬°áÀ» °­Á¦ Æ÷Æ® ¸ÅÇÎ
		½ÃÅµ´Ï´Ù.
		- ÀÌ ±â´ÉÀÌ ÄÑÁ® ÀÖÀ¸¸é TCP¿ÍÀÇ ¿¬°áÀ» ¾ÈÁ¤È­ ÇÏ±â À§ÇØ TCP È¦ÆİÄª ¿¬°á¿¡ ´ëÇÑ upnp Æ÷Æ®¸ÅÇÎ ¿¬°áÀ» Á¦¾îÇÕ´Ï´Ù.
		- ÀÏ¹İÀûÀ¸·Î TCP ¿¬°áÀÌ ¿­·Á ÀÖÀ¸¸é ÀÌ ±â´ÉÀÌ ±»ÀÌ ÇÊ¿äÇÏÁö´Â ¾Ê½À´Ï´Ù. µû¶ó¼­ ±âº»°ªÀº falseÀÔ´Ï´Ù.

		\~english TODO:translate needed.
		If true, the TCP hole punching connection is forced to be port mapped using the universal plug and play (UPNP) feature if needed in the client. 
		- If this feature is turned on, it controls the upnp port mapping connection to the TCP hole punching connection to stabilize the connection to TCP. 
		- If the TCP connection is open in general, this feature is not really necessary. Therefore, the basic value is false. 

		\~chinese
		TrueîÜ?clientâÍé©?××éÄuniversal plug and play(UPNP)ÍíÒö÷êTCPöèÔ×?ïÈ?ú¼Ë­ğ¤port mapping¡£
		- ó®ÍíÒö??îÜ?£¬?Öõ?ïÒ?TCPîÜ?ïÈ£¬ğ¤??TCPöèÔ×?ïÈîÜupnp port mapping?ïÈ¡£
		- ìéÚõï×?ù»TCP?ïÈ?ó·îÜ?ÜôâÍé©ó®ÍíÒö¡£Ùù??ãÀfasle¡£

		\~japanese
		TrueªÇª¢ªìªĞ«¯«é«¤«¢«ó«ÈªÇù±é©ãÁªËuniversal plug and play(UPNP)Ñ¦ÒöªòŞÅªÃªÆTCP«Û?«ë«Ñ«ó«Á«ó«°ïÈ?ªò?ğ¤«İ?«È«Ş«Ã«Ô«ó«°ªµª»ªŞª¹¡£
		- ª³ªÎÑ¦Òöª¬«ª«óªËªÊªÃªÆª¤ªëªÈTCPªÈªÎïÈ?ªòäÌïÒûùª¹ªëª¿ªáªË¡¢TCP«Û?«ë«Ñ«ó«Á«ó«°ïÈ?ªË?ª¹ªëupne«İ?«È«Ş«Ã«Ô«ó«°ïÈ?ªòğ¤åÙª·ªŞª¹¡£
		- ìéÚõîÜªËTCPïÈ?ª¬ËÒª¤ªÆª¤ªìªĞ¡¢ª³ªÎÑ¦ÒöªÏù±é©ªÇªÏª¢ªêªŞª»ªó¡£ªèªÃªÆ¡¢ĞñÜâö·ªÏfalseªÇª¹¡£
		\~
		*/
		bool m_upnpTcpAddPortMapping;


		/**
		\~korean
		¼­¹öÃø ¹æÈ­º®¿¡¼­ ICMP ÆĞÅ¶ÀÌ ¿À´Â È£½ºÆ®°¡ ÀÖÀ»½Ã ±× È£½ºÆ®·ÎºÎÅÍÀÇ ¸ğµç Á¾·ùÀÇ Åë½ÅÀ»
		´Ù Â÷´ÜÇØ¹ö¸®´Â '°úÀ×Áø¾ĞÇü' Á¤Ã¥ÀÌ ÀÖ´Â °æ¿ì º» °ªÀ» true·Î ¼³Á¤ÇØ ÁÖ¾î¾ß ÇÕ´Ï´Ù. ´Ü, Per client
		UDP assign mode¸¦ »ç¿ëÇÏ´Â °æ¿ì º» °ªÀ» true·Î ¼³Á¤ÇÏÁö ¾Ê¾Æµµ Àß ÀÛµ¿ÇÒ ¼ö ÀÖ´Âµ¥, ÀÌ·¯ÇÑ °æ¿ì
		false¸¦ ¾²´Â °ÍÀ» ±ÇÀåÇÕ´Ï´Ù.
		- »ó±â °úÀ×Áø¾ĞÇü Á¤Ã¥Àº º°·Î ±ÇÀåµÇÁö ¾Ê½À´Ï´Ù. ¿Ö³ÄÇÏ¸é TTLÀ» Á¦ÇÑÇÑ ÆĞÅ¶ ±³È¯ÀÌ ºÒ°¡´ÉÇÏ±â
		¶§¹®¿¡, ÀÏºÎ °øÀå¿¡¼­ ³ª¿À´Â ÀÎÅÍ³İ °øÀ¯±â(¶ó¿ìÅÍ)°¡ ¼­¹ö¸¦ ¸Ö¿ş¾î·Î °¨ÁöÇØ¹ö¸®´Â »çÅÂ°¡
		ÀÖÀ» ¼ö ÀÖ±â ¶§¹®ÀÔ´Ï´Ù.
		- ±âº»°ªÀº falseÀÔ´Ï´Ù.

		\~english
		If there exists a strong policy that totally eliminates all types of communications from the host with ICMP packet from server firewalls, then this value must be set as true.
		However, there could be some cases when Per client UDP asigne mode is used and working well while this value is not set as true, but it is recommended to set this value as false.
		- The policy mentioned above is not recommended to stick with since it makes the exchange of the packets that restricted TTL impossible, causing some routers detect the servers as mullware.
		- The default value is false.

		\~chinese
		ğíî¤?Ü×?ĞïÛÁûı???îÜICMP?ËßøĞîÜñ«ÏõîÜ?ı¦£¬êóï·?îïİ»ó®ñ«ÏõîÜá¶êó??÷×ãáîÜ¡®?í¥??úş¡¯ïÙóşîÜ?£¬÷êó®??öÇ?true¡£Ó£ãÀŞÅéÄPer client UDP assign modeîÜ?ı¦£¬?ŞÅÜô÷êó®??öÇ?trueå¥???£¬??ı¦Ëï?éÄfasle¡£
		- Üô÷¼Ëï?ß¾âû?í¥??úşïÙóş¡£ì×?ùÚğ¤TTLîÜ?ËßøĞÜôÊ¦ÒöÎß?£¬Ê¦Òö??ßæ?ìéİ»İÂÍï?õó?îÜ??ÖØë¦Ğï?÷êÜ×?ĞïÊïò±?mullwareîÜï×?¡£
		- Ùù??ãÀfalse¡£

		\~japanese
		«µ?«Ğ?ö°ªÎ«Õ«¡«¤«¢«¦«©?«ëªÇICMP«Ñ«±«Ã«Èª¬ìıªÃªÆª¯ªë«Û«¹«Èª¬ª¢ªëãÁ¡¢ª½ªÎ«Û«¹«Èª«ªéªÎîïªÆªÎğú×¾ªÎ÷×ãáªòó´?ª·ªÆª·ªŞª¦¡¸Î¦???úş¡¹«İ«ê«·?ª¬ª¢ªëíŞùê¡¢ª³ªÎö·ªòtureªËàâïÒª·ªŞª¹¡£Ó£ª·¡¢Per client UDP assign modeªòŞÅª¦íŞùê¡¢ª³ªÎö·ªòtureªËàâïÒª·ªÊª¯ªÆªâªèª¯íÂÔÑª¹ªëª³ªÈª¬ª¢ªêªŞª¹ª¬¡¢ª³ªÎªèª¦ªÊíŞùêªÏ¡¢falseªòŞÅª¦ª³ªÈªòªª?ªáª·ªŞª¹¡£
		- ß¾ÑÀªÎÎ¦???úş«İ«ê«·?ªÏÜ¬ªË??ª·ªŞª»ªó¡£ªÊª¼ªÊªé¡¢TTLªòğ¤ùÚª·ª¿«Ñ«±«Ã«ÈÎßüµª¬ÜôÊ¦ÒöªÇª¢ªëª¿ªá¡¢ìéİ»ªÎÍïíŞªÇõóªÆ?ªë«¤«ó«¿?«Í«Ã«È«ë?«¿?ª¬«µ?«Ğ?ªò«Ş«ë«¦«§«¢ªÇÊïò±ª·ªÆª·ªŞª¦ª³ªÈª¬ª¢ªêÔğªëª«ªéªÇª¹¡£
		- ĞñÜâö·ªÏfalseªÇª¹¡£
		\~
		*/
		bool m_usingOverBlockIcmpEnvironment;

		/**
		\~korean
		¼­¹ö°¡ HostID¸¦ ¹ß±ŞÇÏ´Â ¹æ½ÄÀ» ÁöÁ¤ÇÕ´Ï´Ù.
		- default´Â HostIDGenerationPolicy_NoRecycle ÀÔ´Ï´Ù.

		\~english
		Server will select method of issuing HostID
		- Default is HostIDGenerationPolicy_NoRecycle.

		\~chinese
		Ü×?Ğïò¦ïÒ?Û¯Host IDîÜÛ°ãÒ¡£
		- defaultãÀHostIDGenerationPolicy_NoRecycle¡£

		\~japanese
		«µ?«Ğ?ª¬HostIDªò?ú¼ª¹ªëÛ°ãÒªòò¦ïÒª·ªŞª¹¡£
		- defaultªÏHostIDGenerationPolicy_NoRecycleªÇª¹¡£
		\~
		*/
		//HostIDGenerationPolicy m_HostIDGenerationPolicy;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®°¡ ³²°Ü¾ß ÇÒ ºñ»ó ·Î±× ¶óÀÎ¼öÀÔ´Ï´Ù.
		- default´Â 0ÀÔ´Ï´Ù.
		- ÀÌ°ªÀ» ÁöÁ¤ÇÏ¸é, NetClient ¿¡¼­ SendEmergencyLog ¸¦ È£ÃâÇÏ´Â °æ¿ì
		EmergencyLogServer ·Î±×ÆÄÀÏ¿¡ ÇØ´ç ¶óÀÎ¼ö ¸¸Å­ ºñ»ó·Î±×°¡ ÀúÀåµË´Ï´Ù.

		\~english
		This is number of emergency log line for client
		- Default is 0
		- Once you set this value, client create LogFile when NetClient call DumpEmergencyLog.

		\~chinese
		Clienté©×ºù»îÜ?Ğálog line?¡£
		- defaultãÀ0¡£
		- ò¦ïÒó®?îÜ?£¬î¤NetClientû¼Ğ£SendEmergencyLogîÜ?ı¦£¬èÙEmergencyLogServer logÙşËì?ğíßÓ?éÍßÓ?line?îÜ?Ğálog¡£

		\~japanese
		«¯«é«¤«¢«ó«Èª¬?ª¹ªÙª­ŞªßÈ«í«°«é«¤«ó?ªÇª¹¡£
		- ĞñÜâö·ªÏ0ªÇª¹¡£
		- ª³ªÎö·ªòò¦ïÒª¹ªëªÈ¡¢NetClientªÇSendEmergencyLogªòû¼ªÓõóª¹íŞùê
		EmergencyLogServer «í«°«Õ«¡«¤«ëªËú±?«é«¤«ó?ªÀª±ªÎŞªßÈ«í«°ª¬ÜÁğíªµªìªŞª¹¡£
		\~
		*/
		uint32_t	m_clientEmergencyLogMaxLineCount;

		/*
		\~korean
		¸ğµç ÇÇ¾î°£ÀÇ ÇÎÀ» ¼öÁıÇÏ´Â ±â´ÉÀÔ´Ï´Ù.
		- ÃÊ±â°ªÀº false ÀÔ´Ï´Ù.
		- true·Î ÇÏ¸é Peer·Î ºÎÅÍ ¿¬°áµÇ¾î ÀÖ´Â ¸ğµç ÇÇ¾î°£ÀÇ ÇÎ°ªÀ» ¸ğµÎ ¾ò¾î ¿É´Ï´Ù.
		- ÀÌ ±â´ÉÀÌ ÄÑÁ®ÀÖÁö ¾Ê´Ù¸é Superpeer ¼±Á¤¿¡ ÀÖ¾î Peer°£ ÇÎÀ» ¹ŞÀ» ¼ö ¾øÀ½À¸·Î, m_peerLagWeight°ªÀ» °è»êÇÏÁö ¾Ê½À´Ï´Ù.

		\~english TODO:translate needed.
		This is the feature to collect the ping between every peer. 
		- The initial value is false. 
		- If set true, the ping value among all peers connected from the peer is obtained entirely. 
		- If this feature is not turned on, you cannot get the ping among peers when selecting the superpeer, so it does not calculate m_peerLagWeight value. 

		\~chinese
		â¥ó¢á¶êópeerñı?îÜpingÍíÒö¡£
		- ôøã·?ãÀfalse¡£
		- ??trueîÜ?£¬?îïİ»?ö¢?peer?ã·?ïÈîÜá¶êópeerñı?ping?¡£
		- ó®ÍíÒö?êó??îÜ?£¬î¤Superpeer?ïÒß¾ÜôÒöïÈâ¥peerñı?îÜping£¬ÜôÒö?ß©m_peerLagWeight?¡£

		\~japanese
		îïªÆªÎPeerÊàªÎpingªò?ó¢ª¹ªëÑ¦ÒöªÇª¹¡£
		- ôøÑ¢ö·ªÏfalseªÇª¹¡£
		- tureªËª¹ªëªÈPeerª«ªéïÈ?ªµªìªÆª¤ªëîïªÆªÎPeerÊàªÎpingö·ªòîïªÆÔğªÆª­ªŞª¹¡£
		- ª³ªÎÑ¦Òöª¬«ª«ÕªËªÊªÃªÆª¤ªëªÈ¡¢SuperpeeràÔïÒªËªªª¤ªÆ¡¢PeerÊàªÎpingªòáôª±ªëª³ªÈª¬ªÇª­ªÊª¤ª¿ªá¡¢m_peerLagWeightö·ªòÍªß©ª·ªŞª»ªó¡£
		\~
		*/
		bool m_enablePingTest;


		/**
		\~korean
		ÀÌ°ªÀ» true·Î ÇßÀ»°æ¿ì m_udpports¿¡ ÀÌ¹Ì »ç¿ëÁßÀÎ port°¡ ÀÖÀ»°æ¿ì ½ÇÆĞÇÏÁö¾Ê°í ´ÙÀ½Æ÷Æ®¸¦ bindÇÏ°Ô µË´Ï´Ù.
		- ÃÊ±â°ªÀº falseÀÔ´Ï´Ù.
		- ½ÇÆĞÇÑ port ¸ñ·ÏÀº m_failedBindPorts ¾È¿¡ µé¾î°©´Ï´Ù.

		\~english
		When you set this value to true, it bind next port if it has port that already using in m_udpports.
		- Default is false
		- Failed port list will go through to m_failedBindPorts

		\~chinese
		÷êó®???trueîÜ?£¬î¤m_udpportsì«?êóŞÅéÄñéîÜportîÜ?ı¦Üô?ã÷?£¬ì»ãÀ?bindù»ìé?Ó®Ï¢¡£
		- ôøã·?ãÀfalse¡£
		- ã÷?îÜportÙÍ??ìım_failedBindPorts¡£

		\~japanese
		ª³ªÎö·ªòtrueªËª·ª¿íŞùê¡¢m_udpportsªË?ªËŞÅéÄª·ªÆª¤ªëportª¬ª¢ªëíŞùê¡¢ã÷ø¨ª·ªÊª¯ó­ªÎ«İ?«Èªò«Ö«é«¤«ó«Éª·ªŞª¹¡£
		- ôøÑ¢ö·ªÏfalseªÇª¹¡£
		- ã÷ø¨ª·ª¿port«ê«¹«ÈªÏ m_failedBindPorts?ªËìıªêªŞª¹¡£
		\~
		*/
		bool m_ignoreFailedBindPort;

		/**
		\~korean
		m_ignoreFailedBindPort¸¦ true·Î ÇßÀ»°æ¿ì, ÀÌ¾È¿¡ bind ½ÇÆĞÇÑ port¸ñ·ÏÀÌ µé¾î°¡°Ô µË´Ï´Ù.
		- m_ignoreFailedBindPort°¡ fasleÀÏ¶§´Â °ªÀÌ Ã¤¿öÁöÁö ¾Ê½À´Ï´Ù.

		\~english
		When you set m_ignoreFailedBindPort to true, port list of failed bind will be there.
		- When m_ignoreFailedBindPort is false, value does not fill in.

		\~chinese
		÷êm_ignoreFailedBindPort??trueîÜ?£¬èÙ?×ì?ìıbindã÷?îÜportÙÍ?¡£
		- m_ignoreFailedBindPort?fasleîÜ?ı¦Üô??õöó®?¡£

		\~japanese
		m_ignoreFailedBindPortªòtrueªËª·ª¿íŞùê¡¢ª³ªÎñéªËbindªËã÷ø¨ª·ª¿port«ê«¹«Èª¬ìıªëªèª¦ªËªÊªêªŞª¹¡£
		- m_ignoreFailedBindPortª¬fasleªÇª¢ªëãÁªÏö·ª¬?ª¿ªµªìªŞª»ªó¡£
		\~
		*/
		CFastArray<int> m_failedBindPorts;

		// coalesce interval. Å×½ºÆ®¿ëÀÌ¹Ç·Î Æò¼Ò¿¡´Â ¼Õ´ëÁö ¸» °Í. 0ÀÌ¸é ±âº»°ª ÀÎÅÍ¹ú °ªÀ¸·Î ´ëÃ¼µÊÀ» ÀÇ¹ÌÇÏ¸ç, ÀÌ °ª ÀÚÃ¼ÀÇ ±âº»°ªÀº 0ÀÌ´Ù.
		int m_tunedNetworkerSendIntervalMs_TEST;

		/**
		\~korean
		\brief Simple network protocol mode.

		±âº»°ªÀº false ÀÔ´Ï´Ù.
		ÆĞÅ¶ Ä¸ÃÄ ¹× º¹Á¦ ¹æ½ÄÀ¸·Î ´õ¹Ì Å¬¶óÀÌ¾ğÆ® Å×½ºÆ®¸¦ °¡´ÉÇÏ°Ô ÇÏ±â À§ÇØ¼­ ÀÌ °ªÀ» true·Î ¼³Á¤ÇÏ½Ê½Ã¿À.
		´Ü, ¼­ºñ½º°¡ ÇØÄ¿ÀÇ °ø°İ¿¡ Ãë¾àÇØ Áö¸ç UDP networking°ú direct P2P Åë½ÅÀ» »ç¿ëÇÒ ¼ö ¾ø½À´Ï´Ù. (´ë½Å relay ·Î Àü¼ÛÇÕ´Ï´Ù.)
		¶óÀÌºê ¼­ºñ½º¸¦ À§ÇØ¼­´Â false·Î ¼³Á¤ÇÏ½Ê½Ã¿À.

		ÆĞÅ¶ Ä¸ÃÄ¿Í ¸®ÇÃ·¹ÀÌ Å×½ºÆ®°ü·Ã ³»¿ë:
		°¢°¢ÀÇ ´õ¹Ì Å¬¶óÀÌ¾ğÆ®´Â ÀÚ½ÅÀÇ HostID¸¦ È®ÀÎÇÒ ¼ö ¾ø½À´Ï´Ù.
		CreateP2PGroup() °ú °°ÀÌ P2P ±×·ì °ü·Ã ÇÔ¼ö¸¦ È£ÃâÇÒ °æ¿ì ¿¹»óÄ¡ ¸øÇÑ »óÈ²ÀÌ ¹ß»ıÇÒ ¼ö ÀÖ½À´Ï´Ù.

		\~english
		\brief Simple network protocol mode.

		Default is false.
		Setting this to true allows dummy client test via packet capture and replication method.
		However, it will make service vulnerable to hackers, and does not allow UDP networking
		and direct P2P communication (will be relayed instead.)
		You should set this to false for live service.

		Notice for packet capture and replay test:
		- Each dummy client cannot identify self HostID.
		Unexpected behavior may occur if you call P2P group functions such as CreateP2PGroup().

		\~chinese
		\brief Simple network protocol mode.

		ĞñÜâ??false¡£
		ãÀ?ËßøĞï¸ö¢Ğà?ğ¤îÜÛ°ãÒ£¬?Òö??ú¼ËÔ?Ó®????ó®??öÇ?true¡£
		Ó£??Ê¦Òö?é»æ¶áôÓğıÙËÔÍô?ó¦ÙéÛöŞÅéÄUDP networkingûúDirect P2P÷×ãá¡££¨Ó£???éÄrelay?áê£©¡£
		?Òö?ğ«Íê??Ü×???ó®??öÇ?false¡£

		?ËßøĞï¸ö¢?Replay??îÜßÓ??é»£º
		ÊÀ??ËÔ?Ó®ÙéÛö??í»ĞùîÜHostID¡£
		åıCreateP2PGroup()£¬û¼Ğ£P2P?ßÓ?ùŞ??Ê¦Òö??ßæ?êó??ÓğîÜ??¡£

		\~japanese
		\brief Simple network protocol mode.

		«Ç«Õ«©«ë«Èö·ªÏ false ªÇª¹¡£
		Packet captureĞàªÓÜÜğ²Û°ãÒªÇdummy client «Æ«¹«ÈªòÊ¦ÒöªËª¹ªëª¿ªáªËª³ªÎö·ªò trueªËàâïÒª·ªÆª¯ªÀªµª¤¡£
		ª¿ªÀª·¡¢«µ?«Ó«¹ª¬HackerªÎÍô?ªËöªå°ªËªÊªê¡¢ UDP networkingªÈ direct P2P÷×ãáªòŞÅª¦ª³ªÈª¬ªÇª­ªŞª»ªó¡£ (ÓÛªïªêªË relayªÇ?áêª·ªŞª¹¡£)
		Live«µ?«Ó«¹ªÎª¿ªáªËªÏ falseªËàâïÒª·ªÆª¯ªÀªµª¤¡£

		Packet captureªÈ«ê«×«ì?«Æ«¹«È?Ö§?é»
		ÊÀ?ªÎ dummy client ªÏí»İÂªÎ HostIDªÎü¬ìãª¬ªÇª­ªŞª»ªó¡£
		CreateP2PGroup() ªÎªèª¦ªË P2P«°«ë?«×?Ö§??ªòû¼ªÓõóª¹íŞùê¡¢åøßÌèâªÎ?üÏª¬?ßæª¹ªëÍğªìª¬ª¢ªêªŞª¹¡£

		\~
		*/
		bool m_simplePacketMode;

		/**
		\~korean
		HostID Àç»ç¿ë ±â´É ¿É¼ÇÀÔ´Ï´Ù.
		- HostIDGenerationPolicy_Recycle·Î ¼³Á¤µÇ¾î ÀÖÀ»°æ¿ì CNetConfigÀÇ HostIDRecycleAllowTimeMs°ª¿¡ µû¶ó HostID°¡ Àç»ç¿ëµÇ¾î Áı´Ï´Ù.
		- HostIDGenerationPolicy_NoRecycle·Î ¼³Á¤µÇ¾î ÀÖÀ»°æ¿ì INT_MAX±îÁö UniqueÇÑ HostID°ªÀ» º¸ÀåÇÕ´Ï´Ù.

		±âº»°ªÀº HostIDGenerationPolicy_RecycleÀÔ´Ï´Ù.

		\~english
		It is an option for HostID reuse function.
		- If HostIDGenerationPolicy_Recycle is set, HostID will be reused according to HostIDRecycleAllowTimeMs of CNetConfig.
		- If HostIDGenerationPolicy_NoRecycle is set, unique HostID (until INT_MAX) will be guaranteed.

		Default value is HostIDGenerationPolicy_Recycle.

		\~chinese
		HostIDãÀî¢ŞÅéÄĞüÒö??¡£
		- ì«?ïÒ? HostIDGenerationPolicy_Recycle ?£¬?ó· CNetConfigîÜ HostIDRecycleAllowTimeMs ?£¬ HostIDù¬î¢ŞÅéÄ¡£
		- ì«?ïÒ? HostIDGenerationPolicy_NoRecycle ? £¬ÜÁî¡ Unique Óğ INT_MAX îÜ HostID?¡£

		ĞñÜâ?? HostIDGenerationPolicy_Recycle¡£

		\~japanese
		HostID î¢ŞÅéÄÑ¦Òö«ª«×«·«ç«óªÇª¹¡£
		- HostIDGenerationPolicy_RecycleªÈàâïÒªµªìªÆª¤ªëíŞùê¡¢ CNetConfigªÎHostIDRecycleAllowTimeMsö·ªËªèªêHostIDª¬î¢ŞÅéÄªµªìªŞª¹¡£
		- HostIDGenerationPolicy_NoRecycleªÈàâïÒªµªìªÆª¤ªëíŞùê¡¢INT_MAXªŞªÇUniqueªÊHostIDö·ªòÜÁî¡ª·ªŞª¹¡£

		«Ç«Õ«©«ë«Èö·ªÏHostIDGenerationPolicy_RecycleªÇª¹¡£

		\~
		*/
		HostIDGenerationPolicy m_hostIDGenerationPolicy;

		/**
		\~korean
		ÇØ´ç °ªÀÌ ¼³Á¤µÇ¸é NetServer º´¸ñ ¹ß»ı½Ã °æ°í¿Í ´ıÇÁ ÆÄÀÏÀÌ »ı¼ºµË´Ï´Ù.
		Æ¯º°ÇÑ °æ¿ì°¡ ¾Æ´Ï¶ó¸é ÇÔºÎ·Î ÀÌ °ªÀ» ¼³Á¤ÇÏÁö ¸¶½Ê½Ã¿À.

		\~english
		When the value is set, a warning and a dump file are generated when NetServer bottleneck occurs. 
		Unless it is a special situation, do not carelessly set this value. 

		\~chinese
		ìéÓ©?öÇ??£¬î¤NetServer?ßæ????ßæà÷ÌíÍ±ûúdumpÙşËì¡£
		ğ¶Şª÷åâ¨ï×?£¬Üôé©?öÇó®?¡£

		\~japanese
		ú±?ö·ª¬àâïÒªµªìªìªĞNetServer«Ü«Ã«È«ë«Í«Ã«¯ª¬?ßæãÁªËÌíÍ±ªÈ«À«ó«×«Õ«¡«¤«ëª¬ßæà÷ªµªìªŞª¹¡£
		÷åÜ¬ªÊíŞùêªÇªÏªÊª±ªìªĞã­â¢ªËª³ªÎö·ªòàâïÒª·ªÊª¤ªÇª¯ªÀªµª¤¡£


		\~
		*/
		CriticalSectionSettings m_bottleneckWarningSettings;

		/**
		\~korean
		»ı¼ºÀÚ ¸Ş¼­µåÀÔ´Ï´Ù.

		\~english
		Constructor method

		\~chinese
		ßæà÷íºÛ°Ûö¡£

		\~japanese
		ßæà÷í­«á«½«Ã«ÉªÇª¹¡£
		\~
		*/
		PROUD_API CStartServerParameter();
	};


	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
