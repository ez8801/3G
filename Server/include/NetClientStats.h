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
	Å¬¶óÀÌ¾ğÆ®ÀÇ »óÈ² Åë°è Á¤º¸ÀÔ´Ï´Ù.
	¼º´É ÃøÁ¤ µî¿¡¼­ »ç¿ëµË´Ï´Ù.
	
	\~english
	Client status information.
	Used for performance check.
	
	\~chinese
	ËÔ?Ó®????ãáãÓ¡£
	éÄéÍàõÒö??¡£
	
	\~japanese
	«¯«é«¤«¢«ó«ÈªÎ?üÏªÎ÷ÖÍªï×ÜÃªÇª¹¡£
	«Ñ«Õ«©?«Ş«ó«¹ªÎö´ïÒÔõªÇŞÅªïªìªÆª¤ªŞª¹¡£
	*/
	class CNetClientStats :public CNetCoreStats
	{
	public:

		/**
		\~korean
		ÇöÀç ¿¬°áµÇ¾îÀÖ´Â remote peerÀÇ °¹¼ö

		\~english
		Number of remote peer that in currently connected

		\~chinese
		?î¤ì«?ïÈîÜremote peerîÜ??¡£

		\~japanese
		úŞî¤ªÄªÊª¬ªÃªÆª¤ªëremote peerªÎ?
		\~
		*/
		uint32_t m_remotePeerCount;

		/**
		\~korean
		trueÀÌ¸é ¼­¹ö¿ÍÀÇ UDP Åë½ÅÀÌ Á¤»óÀÓÀ» ÀÇ¹ÌÇÑ´Ù.
		falseÀÌ¸é UDP¸¦ ¾²Áö ¸øÇÏ¸ç, ¼­¹ö¿ÍÀÇ unreliable ¸Ş½ÃÂ¡µµ TCP·Î ÁÖ°í¹Ş¾ÆÁö°í ÀÖÀ½À» ÀÇ¹ÌÇÑ´Ù.

		\~english
		true means the UDP communication with server is ok
		Cannot use UDP when false and also means the unreliable messaging with server is done via TCP.

		\~chinese
		TrueîÜ?ëòÚ«ó·?Ü×?ĞïîÜUDP÷×ãáïáßÈ¡£
		FalseîÜ?ÜôÒöŞÅéÄUDP£¬ëòÚ«ó·?unreliable messagingå¥ÜôÒöéÄTCP?ïÈ¡£

		\~japanese
		TrueªÇª¢ªìªĞ«µ?«Ğ?ªÈªÎUDP÷×ãáª¬ïáßÈªÇª¢ªëª³ªÈªòëòÚ«ª·ªŞª¹¡£
		FalseªÇª¢ªìªĞUDPªòŞÅª¨ªº¡¢«µ?«Ğ?ªÈªÎunreliable«á«Ã«»?«¸«ó«°ªâTCPªÇªäªêö¢ªêª¹ªëª³ªÈªòëòÚ«ª·ªŞª¹¡£
		\~
		*/
		bool m_serverUdpEnabled;

		/**
		\~korean
		Direct P2P°¡ µÇ¾îÀÖ´Â remote peerÀÇ °¹¼ö

		\~english
		Number of remote peer that consisted Direct P2P

		\~chinese
		Direct P2PîÜremote peer??¡£

		\~japanese
		Direct P2PªËªÊªÃªÆª¤ªëremote peerªÎ?
		\~
		*/
		uint32_t m_directP2PEnabledPeerCount;


		/**
		\~korean
		TCP, UDP Send Queue¿¡ ³²¾ÆÀÖ´Â ÃÑ Å©±â, Send Queue ÃÑ Å©±â

		\~english
		Total size left in TCP and UDP Send Queue. Total size of the Send Queue


		\~chinese
		TCP, UDP Send Queueñéí¥åùîÜ?îÜÓŞá³, Send QueueîÜ?ÓŞá³

		\~japanese
		TCP, UDP Send QueueªË?ªÃªÆª¤ªë«µ«¤«ºùêÍª¡¢Send QueueªÎ«µ«¤«ºùêÍª
		\~
		*/
		uint32_t m_sendQueueTotalBytes;
		uint32_t m_sendQueueTcpTotalBytes;
		uint32_t m_sendQueueUdpTotalBytes;


		CNetClientStats();

		virtual String ToString() const;
	};
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif