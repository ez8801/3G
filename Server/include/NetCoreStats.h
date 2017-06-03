/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once

#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \~korean »óÈ² Åë°è Á¤º¸ÀÔ´Ï´Ù. 
	\~english Status information.
	\~chinese ????ãáãÓ¡£
	\~japanese ?üÏªÎ÷ÖÍªï×ÜÃªÇª¹¡£
	\~
	*/
	class CNetCoreStats
	{
	public:
		uint64_t m_totalTcpReceiveCount;

		/**
		\~korean
		ÃÑ ¼ö½ÅµÈ TCP ¸Ş½ÃÁöÀÇ ¾ç(byte). RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Amount(byte) of all TCP messages received. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?â¥ãáîÜTCPãáãÓÕá£¨byte£©¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áôãáªµªìª¿TCP«á«Ã«»?«¸ªÎ?Õá(byte)¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		uint64_t m_totalTcpReceiveBytes;

		uint64_t m_totalTcpSendCount;

		/**
		\~korean
		ÃÑ ¼Û½ÅµÈ TCP ¸Ş½ÃÁöÀÇ ¾ç(byte). RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Amount(byte) of all TCP messages sent. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		??áêîÜTCPãáãÓÕá£¨byte£©¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áêãáªµªìª¿TCP«á«Ã«»?«¸ªÎ?Õá(byte)¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		uint64_t m_totalTcpSendBytes;
		
		/**
		\~korean
		ÃÑ ¼ö½ÅµÈ UDP ¸Ş½ÃÁöÀÇ °¹¼ö. RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Number of all UDP messages received. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?â¥ãáîÜUDPãáãÓ??¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áôãáªµªìª¿UDP«á«Ã«»?«¸ªÎ??¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		uint64_t m_totalUdpReceiveCount;
		/**
		\~korean
		ÃÑ ¼ö½ÅµÈ UDP ¸Ş½ÃÁöÀÇ ¾ç(byte). RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Amount(byte) of all UDP messages received. This includes RMI and the headers of all packets in ProudNet

		\~chinese
		?â¥ãáîÜUDPãáãÓÕá£¨byte£©¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áôãáªµªìª¿UDP«á«Ã«»?«¸ªÎ?Õá£¨byte£©¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		uint64_t m_totalUdpReceiveBytes;

		/**
		\~korean
		ÃÑ ¼Û½ÅµÈ UDP ¸Ş½ÃÁöÀÇ ¾ç(byte). RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Amount(byte) of all UDP messages sent. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		??áêîÜUDPãáãÓÕá£¨byte£©¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áêãáªµªìª¿UDP«á«Ã«»?«¸ªÎ?Õá£¨byte£©¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		uint64_t m_totalUdpSendBytes;

		/**
		\~korean
		ÃÑ ¼Û½ÅµÈ UDP ¸Ş½ÃÁöÀÇ °¹¼ö. RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Number of all UDP messages sent. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		??áêîÜUDPãáãÓ??¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áêãáªµªìª¿UDP«á«Ã«»?«¸ªÎ??¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		uint64_t m_totalUdpSendCount;

		inline uint64_t GetTotalReceiveBytes()
		{
			return m_totalTcpReceiveBytes + m_totalUdpReceiveBytes;
		}

		/**
		\~korean
		ÃÑ ¼ö½ÅµÈ ¸Ş½ÃÁöÀÇ ¾ç(byte). RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Amount(byte) of all messages sent. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?â¥ãáîÜãáãÓÕá£¨byte£©¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áôãáªµªìª¿«á«Ã«»?«¸ªÎ?Õá£¨byte£©¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
#if defined(_MSC_VER)
		__declspec(property(get = GetTotalReceiveBytes)) uint64_t m_totalReceiveBytes;
#endif


		inline uint64_t GetTotalSendCount()
		{
			return m_totalTcpSendCount + m_totalUdpSendCount;
		}
		inline uint64_t GetTotalReceiveCount()
		{
			return m_totalTcpReceiveCount + m_totalUdpReceiveCount;
		}
		inline uint64_t GetTotalSendBytes()
		{
			return m_totalTcpSendBytes + m_totalUdpSendBytes;
		}
		/**
		\~korean
		ÃÑ ¼Û½ÅµÈ ¸Ş½ÃÁöÀÇ °¹¼ö. RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Number of all messages sent. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?â¥ãáîÜãáãÓ??¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áêãáªµªìª¿«á«Ã«»?«¸ªÎ??¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
#if defined (_MSC_VER)
		__declspec(property(get = GetTotalSendCount)) uint64_t m_totalSendCount;

		/**
		\~korean
		ÃÑ ¼ö½ÅµÈ ¸Ş½ÃÁöÀÇ °¹¼ö. RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Number of all received messages. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?â¥ãáîÜãáãÓ??¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áôãáªµªìª¿«á«Ã«»?«¸ªÎ??¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		__declspec(property(get = GetTotalReceiveCount)) uint64_t m_totalReceiveCount;

		/**
		\~korean
		ÃÑ ¼Û½ÅµÈ ¸Ş½ÃÁöÀÇ ¾ç(byte). RMI »Ó¸¸ ¾Æ´Ï¶ó ProudNet ³»ºÎÀÇ ¸ğµç ÆĞÅ¶ÀÇ Çì´õ±îÁö Æ÷ÇÔÇÑ´Ù.

		\~english
		Amount(byte) of all sent messages. This includes RMI and the headers of all packets in ProudNet.

		\~chinese
		?â¥ãáîÜãáãÓîÜÕá£¨byte£©¡£ğ¶ÖõRMI£¬å¥øĞÎÀProudNet?İ»îÜá¶êó?ËßøĞheader¡£

		\~japanese
		áêãáªµªìª¿«á«Ã«»?«¸ªÎ?Õá£¨byte£©¡£RMIªÀª±ªÇªÏªÊª¯¡¢ProudNet?İ»ªÎîïªÆªÎ«Ñ«±«Ã«ÈªÎ«Ø«Ã«À?ªŞªÇùßªáªŞª¹¡£
		\~
		*/
		__declspec(property(get = GetTotalSendBytes)) uint64_t m_totalSendBytes;
		
#endif

		CNetCoreStats();

		/**
		\~korean
		ÀÌ °´Ã¼ÀÇ ³»¿ë¹°À» Ç¥ÇöÇÏ´Â ¹®ÀÚ¿­À» ¸®ÅÏÇÕ´Ï´Ù.

		\~english
		Returns a string that represents this object.

		\~chinese
		Ú÷üŞøúãÆ??ßÚîÜí®İ¬Íú¡£

		\~japanese
		ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎ?é»ªòøúª¹«¹«È«ê«ó«°ªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		virtual String ToString() const = 0;
	};
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif