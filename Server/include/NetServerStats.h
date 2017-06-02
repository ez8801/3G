/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once 

#include "NetCoreStats.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/**
	\~korean
	\brief ¼­¹ö »óÈ² Åë°è Á¤º¸
	- ¼º´É ÃøÁ¤¸¦ À§ÇÑ ¿ëµµÀÌ´Ù.

	\~english
	\brief server status statistics information
	- To check performance

	\~chinese
	\brief Ü×?Ğï????ãáãÓ¡£
	- ?ÖõàõÒö?ïÒîÜéÄÔ²¡£

	\~japanese
	\brief «µ?«Ğ??üÏ÷ÖÍªï×ÜÃ
	- àõÒöö´ïÒªÎª¿ªáªÎéÄÔ²ªÇª¹¡£
	\~
	*/
	class CNetServerStats:public CNetCoreStats
	{
	public:
		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®°£ÀÇ Á÷°£Á¢ P2P ¿¬°áÀÇ ÃÑ °¹¼ö
		- ´Ü, ¾ÆÁ÷ P2P Åë½ÅÀ» ÇÑ Àûµµ ¾ø´ÂÁö¶ó P2P ¿¬°á ÀÚÃ¼¸¦ ½ÃµµÁ¶Â÷ ¾ÈÇÑ P2P ¿¬°áÀº Áı°è¿¡¼­ Á¦¿ÜµÈ´Ù.

		\~english
		Number of all direct/indirect P2P connection among clients
		- However, this does not include the P2P connections that are not even attempted yet since there has been no P2P communication attempted.

		\~chinese
		Clientñı?òÁ?ïÈP2P?ïÈîÜ???¡£
		- Ó£?Ú±?ú¼?P2P÷×ãá£¬ì×ó®åıÍıãÀ?P2P?ïÈÜâãóå¥Ô´?êó??îÜP2P?ïÈğ¶èâ¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈÊàªÎòÁ?ÊàïÈP2PïÈ?ªÎ??
		- Ó£ª·¡¢ªŞªÀP2P÷×ãáªòú¼ªÃª¿ª³ªÈªâªÊª¤ªÎªÇ¡¢P2PïÈ?í»?ªòãËª·ªµª¨ª·ªÊª«ªÃª¿P2PïÈ?ªÏ¡¢ó¢Íªªèªêğ¶èâªµªìªŞª¹¡£
		\~
		*/
		uint32_t m_p2pConnectionPairCount;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®°£ÀÇ Á÷Á¢ P2P ¿¬°áÀÇ ÃÑ °¹¼ö
		- ´Ü, ¾ÆÁ÷ P2P Åë½ÅÀ» ÇÑ Àûµµ ¾ø´ÂÁö¶ó P2P ¿¬°á ÀÚÃ¼¸¦ ½ÃµµÁ¶Â÷ ¾ÈÇÑ P2P ¿¬°áÀº Áı°è¿¡¼­ Á¦¿ÜµÈ´Ù.

		\~english
		Number of all direct P2P connection among clients
		- However, this does not include the P2P connections that are not even attempted yet since there has been no P2P communication attempted.

		\~chinese
		Clientñı?òÁ?ïÈP2P?ïÈîÜ???¡£
		- Ó£?Ú±?ú¼?P2P÷×ãá£¬ì×ó®åıÍıãÀ?P2P?ïÈÜâãóå¥Ô´?êó??îÜP2P?ïÈğ¶èâ¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈÊàªÎòÁ?ÊàïÈP2PïÈ?ªÎ??
		- Ó£ª·¡¢ªŞªÀP2P÷×ãáªòú¼ªÃª¿ª³ªÈªâªÊª¤ªÎªÇ¡¢P2PïÈ?í»?ªòãËª·ªµª¨ª·ªÊª«ªÃª¿P2PïÈ?ªÏ¡¢ó¢Íªªèªêğ¶èâªµªìªŞª¹¡£
		\~
		*/
		uint32_t m_p2pDirectConnectionPairCount;

		/**
		\~korean
		ÃÑ Å¬¶óÀÌ¾ğÆ® °¹¼ö

		\~english
		Number of all clients

		\~chinese
		?client??¡£

		\~japanese
		«¯«é«¤«¢«ó«È??
		\~
		*/
		uint32_t m_clientCount;

		/**
		\~korean
		UDP Åë½ÅÀ» À¯ÁöÇÏ°í ÀÖ´Â (TCP fallbackÀ» ¾ÈÇÏ°í ÀÖ´Â) Å¬¶óÀÌ¾ğÆ® °¹¼ö

		\~english
		Number of clients that sustain UDP communications(not doing TCP fallback)

		\~chinese
		?ò¥UDP÷×ãáîÜ£¨?êó?ú¼TCP fallback£©client??¡£

		\~japanese
		UDP÷×ãáªòë«ò¥ª·ªÆª¤ªë(TCP fallbackªòª·ªÆª¤ªÊª¤)«¯«é«¤«¢«ó«È?
		\~
		*/
		uint32_t m_realUdpEnabledClientCount;

		/**
		\~korean
		»ç¿ëÁßÀÎ UDP Æ÷Æ®ÀÇ °¹¼öÀÔ´Ï´Ù.
		- ServerUdpAssignMode_StaticÀ» »ç¿ëÁßÀÌ¸é ÀÌ °ªÀº ¹«ÀÇ¹ÌÇÕ´Ï´Ù.
		- ServerUdpAssignMode_PerClient¸¦ »ç¿ëÁßÀÌ¸é ÀÌ °ªÀº ÇöÀç »ç¿ëÁßÀÎ Æ÷Æ®ÀÇ °¹¼ö¸¦ ¸®ÅÏÇÕ´Ï´Ù.
		ÀÏ¹İÀûÀ¸·Î, ¼­¹ö¿¡ ¿¬°áµÈ Å¬¶óÀÌ¾ğÆ®ÀÇ °¹¼ö¿Í °ÅÀÇ µ¿ÀÏÇÕ´Ï´Ù¸¸ Áø´Ü ¸ñÀûÀ¸·Î ÀÌ¸¦
		»ç¿ëÇÏ¼Åµµ µË´Ï´Ù.

		\~english
		Number of UDP ports that are in use
		- This value is meaningless if ServerUdpAssignMode_Static is in use.
		- If ServerUdpAssignMode_PerClient is in use then this value returns the number of ports that are currently in use.
		In general, this is same as the numer of clients connnected to server but you can use this as diagnosis.

		\~chinese
		ŞÅéÄñéîÜUDPÓ®Ï¢??¡£
		- ŞÅéÄServerUdpAssignMode_StaticñéîÜ?ó®?ö¦Ùéëò?Öõ¡£
		- ŞÅéÄServerUdpAssignMode_PerClientñéîÜ?ó®?Ú÷üŞ?î¤ŞÅéÄñéîÜÓ®Ï¢??¡£
		ìéÚõ?î¤Ü×?Ğï?ïÈîÜclient???ûºßÓÔÒ£¬Ê¦ì¤ì¤??ÙÍîÜŞÅéÄ¡£

		\~japanese
		ŞÅéÄª·ªÆª¤ªëUDP«İ?«ÈªÎ?ªÇª¹¡£
		- ServerUdpAssignMode_StaticªòŞÅéÄª·ªÆª¤ªëªÈ¡¢ª³ªÎö·ªÏÙíëòÚ«ªÇª¹¡£
		- ServerUdpAssignMode_PerClientªòŞÅéÄª·ªÆª¤ªëªÈ¡¢ª³ªÎö·ªÏúŞî¤ŞÅéÄª·ªÆª¤ªë«İ?«ÈªÎ?ªò«ê«¿?«óª·ªŞª¹¡£
		ìéÚõîÜªË¡¢«µ?«Ğ?ªËªÄªÊª¬ªÃª¿«¯«é«¤«¢«ó«ÈªÎ?ªÈªÛªÜÔÒª¸ªÇª¹ª¬¡¢òà?ÙÍîÜªÇª³ªìªòŞÅéÄª·ªÆªâÕŞª¤ªÇª¹¡£
		\~
		*/
		int m_occupiedUdpPortCount;

		CNetServerStats();
		virtual String ToString() const;
	};
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif