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

#if defined(__unix__)
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#elif defined(_WIN32)
#include <winsock2.h>
#include <ws2ipdef.h>
#pragma comment(lib,"Ws2_32.lib")
#else
#include <arpa/inet.h>
#include <errno.h>
#endif

#if defined(__ORBIS__)
#include "OrbisIPv6.h"
#endif

#ifdef PF_MAX
#undef PF_MAX
#endif

#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/
	class CFastSocket;

	struct ExtendSockAddr;
	struct NamedAddrPort;

	/**

	\~korean
	¼ÒÄÏ ¿¡·¯ ÄÚµå

	\~english
	Socket Error Code

	\~chinese
	Socket ??ÓÛ?

	\~japanese
	«½«±«Ã«È«¨«é?«³?«É
	\~
	*/
	enum SocketErrorCode
	{
		SocketErrorCode_Ok = 0,
		// EINTR¿Í WSAEINTRÀº ¼­·Î ´Ù¸¥ °ªÀÌ´Ù. µû¶ó¼­ Win32¿¡¼­´Â EINTRÀ» ¾²¸é ¾ÈµÈ´Ù.
		// µû¶ó¼­, ¾îÂ¿ ¼ö ¾øÀÌ ¾Æ·¡¿Í °°ÀÌ ¼­·Î ´Ù¸£°Ô ±¸º°µÉ ¼ö¹Û¿¡ ¾ø´Ù.
#if !defined(_WIN32)
		SocketErrorCode_Error = -1,
		SocketErrorCode_Timeout = ETIMEDOUT,
		SocketErrorCode_ConnectionRefused = ECONNREFUSED,
		SocketErrorCode_ConnectResetByRemote = ECONNRESET,
		SocketErrorCode_AddressNotAvailable = EADDRNOTAVAIL,
		SocketErrorCode_NotSocket = ENOTSOCK,
		SocketErrorCode_WouldBlock = EWOULDBLOCK,
		SocketErrorCode_AccessError = EACCES,
		SocketErrorCode_InvalidArgument = EINVAL,
		SocketErrorCode_Intr = EINTR, // EINTR in linux
		SocketErrorCode_InProgress = EINPROGRESS, // operationÀÌ ÀÌ¹Ì ÁøÇàÁßÀÌ´Ù.
		SocketErrorCode_Again = EAGAIN, // win32¿¡¼­´Â would-blockÀÌ ´ëÃ¼.
		SocketErrorCode_AlreadyIsConnected = EISCONN,
		SocketErrorCode_AlreadyAttempting = EALREADY, // The socket is nonblocking and a previous connection attempt has not yet been completed.
		SocketErrorCode_NetUnreachable = ENETUNREACH,
#else
		SocketErrorCode_Error = SOCKET_ERROR,
		SocketErrorCode_Timeout = WSAETIMEDOUT,
		SocketErrorCode_ConnectionRefused = WSAECONNREFUSED,
		SocketErrorCode_ConnectResetByRemote = WSAECONNRESET,
		SocketErrorCode_AddressNotAvailable = WSAEADDRNOTAVAIL,
		SocketErrorCode_NotSocket = WSAENOTSOCK,
		SocketErrorCode_ShutdownByRemote = WSAEDISCON,	// FD_CLOSE or FD_SEND¿¡¼­ÀÇ ÀÌº¥Æ®
		SocketErrorCode_WouldBlock = WSAEWOULDBLOCK,
		SocketErrorCode_IoPending = WSA_IO_PENDING,
		SocketErrorCode_AccessError = WSAEACCES,
		SocketErrorCode_OperationAborted = ERROR_OPERATION_ABORTED,
		SocketErrorCode_InvalidArgument = WSAEINVAL,
		SocketErrorCode_Intr = WSAEINTR, // EINTR in linux
		SocketErrorCode_InProgress = WSAEINPROGRESS, // operationÀÌ ÀÌ¹Ì ÁøÇàÁßÀÌ´Ù.
		SocketErrorCode_AlreadyIsConnected = WSAEISCONN,
		SocketErrorCode_AlreadyAttempting = WSAEALREADY,
		SocketErrorCode_Cancelled = WSAECANCELLED,
		SocketErrorCode_NetUnreachable = WSAENETUNREACH,
#endif
	};

	enum ShutdownFlag
	{
#if !defined(_WIN32)
		ShutdownFlag_Send = SHUT_WR,
		ShutdownFlag_Receive = SHUT_RD,
		ShutdownFlag_Both = SHUT_RDWR,
#else
		ShutdownFlag_Send = SD_SEND,
		ShutdownFlag_Receive = SD_RECEIVE,
		ShutdownFlag_Both = SD_BOTH,
#endif
	};

	static const int PN_IPV6_ADDR_LENGTH = 16;

	// ¹«È¿ÇÑ ¼ÒÄÏ ÇÚµé°ª.
#ifdef _WIN32
	// À©µµ¿¡¼­´Â invalid fd = INVALID_SOCKET = 0ÀÌ´Ù.
	const int InvalidSocket = 0; // INVALID_SOCKET
#else 
	// unix¿¡¼­´Â À½¼ö°¡ ¹«È¿ ¼ÒÄÏ fd °ªÀÌ´Ù.
	const int InvalidSocket = -1;
#endif

	/**
	\~korean
	IP, Port ½Äº°ÀÚ

	\~english
	IP, Port Identifier

	\~chinese
	IP, Port??íº

	\~japanese
	IP¡¢«İ?«ÈãÛÜ¬í­
	\~
	*/
	struct PROUD_API AddrPort
	{

		/* PN_ALIGN(1) Áï,  __declspec(align) À» 1¹ÙÀÌÆ®·Î »ç¿ë ÇßÀ» ¶§ VC++¿¡¼­´Â "4 ¹Ì¸¸Àº ¹«½ÃÇÑ´Ù"´Â warningÀÌ ¶á´Ù.
		µû¶ó¼­ align 4¸¦ ÇÏµÇ, ¼±¾ğµÇ´Â º¯¼öµéÀÌ 4¹è¼ö Å©±â·Î ÁöÁ¤ÇÏµµ·Ï ÇÑ´Ù.
		¾î¶² ÄÄÆÄÀÏ·¯´Â ±âº» align 8ÀÌ¹Ç·Î align 4¸¦ ÇØÁÖ¾î¾ß ÇÑ´Ù.
		*/
		union PN_ALIGN(4) ExtendAddr
		{
			// Àı´ë ÀÌ °ø¿ëÃ¼ ³»ÀÇ º¯¼ö¸¦ ÇÔºÎ·Î Ãß°¡ ÇÏÁö ¸¶½Ê½Ã¿À.
			struct PN_ALIGN(4)
			{
				uint8_t  __dummy[PN_IPV6_ADDR_LENGTH - sizeof(uint32_t)]; // 12¹ÙÀÌÆ® => 4¹è¼ö ¸¸Á·
				uint32_t v4; // 4¹ÙÀÌÆ® => 4¹è¼ö ¸¸Á·
			};

			uint16_t v6Short[PN_IPV6_ADDR_LENGTH / 2]; // 16¹ÙÀÌÆ® => 4¹è¼ö ¸¸Á·
			uint8_t  v6Byte[PN_IPV6_ADDR_LENGTH]; // 16¹ÙÀÌÆ® => 4¹è¼ö ¸¸Á·
		} m_addr;

		/**
		\~korean
		Æ÷Æ® ¹øÈ£
		- native endianÀÌ°í, network endian°¡ ¾Æ´Ï´Ù. Áï socket ÇÔ¼ö htons³ª ntohs¸¦ ÅëÇØ º¯È¯ÇÒ ÇÊ¿ä°¡ ¾øÀÌ ±×´ë·Î »ç¿ëÇØµµ µÈ´Ù.

		\~english
		Port Number
		- It's native endian, not network endian. So it can be used as-is without converting it through htons or ntohs.

		\~chinese
		Ó®Ï¢??
		- ãÀnative endian£¬ì»ÜôãÀnetwork endian¡£å¥ö¦ãÀ?£¬?êóù±é©÷×?socketùŞ?htonsûäntohs??£¬å¥Ê¦ì¤òÁïÈŞÅéÄ¡£

		\~japanese
		«İ?«ÈÛã?
		? native endianªÇ¡¢network endianªÇªÏª¢ªêªŞª»ªó¡£?ªÁ¡¢socket??ªÎhtonsªäntohsªò÷×ª¸?üµª¹ªëù±é©ª¬ªÊª¯ª½ªÎªŞªŞŞÅªÃªÆªâÕŞª¤ªÇª¹¡£		

		\~
		*/
		uint16_t m_port;

	private:
		bool IsFFFFAddress() const;
		bool Is0000Address() const;
		bool IsLocalhostAddress() const;
		
	public:

		// #TODO ¾Æ·¡ ÁÖ¼®µéÀº code review ÈÄ doxygen ÇüÅÂ·Î Á¤¸® ÇØ¾ß µÈ´Ù.

		/**
		IPv4 ÁÖ¼Ò°¡ µé¾îÀÖÀ¸¸é, true¸¦ ¸®ÅÏÇÕ´Ï´Ù.
		RFC 4291 ¿¡¼­ Á¤ÀÇ ÇÏ°í ÀÖ´Â, Ç¥ÁØ IPv4 Ç¥Çö ¹æ½ÄÀ» ÀÏÄÂ½À´Ï´Ù.
		¿¹: 11.22.33.44´Â ::ffff:11.22.33.44 Çü½ÄÀ¸·Î ÀúÀåµÇ¸ç, ÀÌ¶§ ÀÌ ÇÔ¼ö´Â true¸¦ ¸®ÅÏÇÕ´Ï´Ù.
		*/
		bool IsIPv4MappedIPv6Addr() const;

		/*
		RFC 4291 ¿¡¼­ Á¤ÀÇ ÇÏ°í ÀÖ´Â Ç¥ÁØ IPv4 Ç¥Çö ¹æ½ÄÀ¸·Î ¼¼ÆÃ ÇÕ´Ï´Ù.
		(::1.2.3.4 ¿Í ::FFFF:1.2.3.4 µÎ°³°¡ ÀÖÁö¸¸, ÇÁ¶ó¿ìµå³İ¿¡¼­´Â µÚÀÇ ¹æ½ÄÀ¸·Î »ç¿ë ÇÕ´Ï´Ù.)
		*/
		void SetIPv4MappedIPv6Address(uint32_t ipv4Address);

		/*
		IPv6 ÁÖ¼Ò·Î ¼¼ÆÃ ÇÕ´Ï´Ù.
		addr ÀÎÀÚ°¡ v4 mapped v6 ÁÖ¼Ò·Î ÀúÀå µÇ¾î ÀÖ¾îµµ µË´Ï´Ù.
		*/
		void SetIPv6Address(const in6_addr& addr);

		void SetIPv6Address(const uint8_t* src, const size_t length);

		// ³»ºÎ Àü¿ë ÇÔ¼ö. µµ¿ò¸» ºÒÇÊ¿ä.
		void Synthesize(const uint8_t* pref, const size_t prefLength, const uint32_t v4BinaryAddress);

		/* IPv4 ÁÖ¼Ò¸¦ 32ºñÆ® ¹ÙÀÌ³Ê¸®·Î¼­ ¾ò´Â´Ù.
		AddrPort ´Â RFC 6052, RFC 4291 ¿¡¼­ Á¤ÀÇ ÇÏ°í ÀÖ´Â v4 Ç¥Çö ¹æ½ÄÀ» µû¸£°í ÀÖ¾î¾ß ÇÕ´Ï´Ù.

		¿¹: 11.22.33.44 => ::ffff:11.22.33.44

		¸¸¾à NAT64 ÁÖ¼ÒÀÌ°Å³ª, IPv6 È£½ºÆ®¸¦ °¡¸®Å°´Â ÁÖ¼ÒÀÎ °æ¿ì, ÀÌ ÇÔ¼ö´Â ½ÇÆĞÇÕ´Ï´Ù.

		\param outIPv4Address ¾ò¾î³½ IPv4 ÁÖ¼Ò°ª.
		\return ¼º°øÀûÀ¸·Î ¾ò¾î³»¸é true.
		*/
		bool GetIPv4Address(uint32_t* outIPv4Address) const;

		inline bool IsAddressEqualTo(const AddrPort &a) const
		{
			return memcmp(m_addr.v6Byte, a.m_addr.v6Byte, PN_IPV6_ADDR_LENGTH) == 0 ? true : false;
		}

		/**
		\~korean
		»ı¼ºÀÚ

		\~english
		Generator

		\~chinese
		ßæà÷íº

		\~japanese
		ßæà÷í­
		\~
		*/
		AddrPort();

		bool ToNativeV4(ExtendSockAddr& output, ErrorInfo& outErrorInfo) const;
		void ToNativeV6(ExtendSockAddr& out) const;


		/**
		\~korean
		Socket API ÆÄ¶ó¸ŞÅÍ sockaddr_in ±¸Á¶Ã¼¿¡°Ô °ªÀ» ÁØ´Ù.

		\~english
		This method passes a value to Socket API Parameter, sockaddr_in structure.

		\~chinese
		?åøSocket API??sockaddr_in?ğã???¡£

		\~japanese
		Socket API«Ñ«é«á?«¿?ªÎsockaddr_inÏ°ğã?ªËö·ªò?ª¨ªŞª¹¡£

		\~
		*/
		void FromNativeV4(const sockaddr_in& in);

		void FromNativeV6(const sockaddr_in6& in);

		void FromNative(const ExtendSockAddr& in);

		/**
		\~korean
		xxx.xxx.xxx.xxx:xxxx ¹®ÀÚ¿­ ÃßÃâ

		\~english
		Extract xxx.xxx.xxx.xxx:XXXX string

		\~chinese
		õÎõóí®İ¬Íú xxx.xxx.xxx.xxx:XXXX

		\~japanese
		xxx.xxx.xxx.xxx:xxxx Ùşí®Öª«¨«¯«¹«İ?«È
		\~
		*/
		virtual String ToString() const;

		/**
		\~korean
		xxx.xxx.xxx.xxx ¹®ÀÚ¿­ ÃßÃâ

		\~english
		Extract xxx.xxx.xxx.xxx string

		\~chinese
		õÎõóí®İ¬Íú xxx.xxx.xxx.xxx

		\~japanese
		xxx.xxx.xxx.xxx Ùşí®Öª«¨«¯«¹«İ?«È
		\~
		*/
		virtual String IPToString() const;

		/**
		\~korean
		IP address ¹®ÀÚ¿­°ú port¸¦ ÀÔ·Â¹Ş¾Æ, AddrPort °´Ã¼¸¦ ¸®ÅÏÇÕ´Ï´Ù.
		host nameÀº Ã³¸®ÇÒ ¼ö ¾ø½À´Ï´Ù. ´ë½Å FromHostNamePort()¸¦ »ç¿ëÇÏ¼¼¿ä.
		\param ipAddress IP ÁÖ¼Ò °ªÀÔ´Ï´Ù. ¿¹¸¦ µé¾î "11.22.33.44"ÀÔ´Ï´Ù.
		\param port Æ÷Æ® °ªÀÔ´Ï´Ù.

		\~english
		Input an IP address string and a port to get the return value from AddrPort object.
		Host name can¡¯t be processed. Use FromHostNamePort() instead.
		\param ipAddress IP is the address value. Ex. ¡°11.22.33.44¡±
		\param port is the port value.

		\~chinese
		÷×??ìıIPò¢ò£í®İ¬ÍúûúÓ®Ï¢Ú÷üŞAddrPort?ßÚ¡£
		host nameÙéÛö?×â£¬?ŞÅéÄFromHostNamePort()¡£
		\param ipAddress IPò¢ò£?¡£ÖÇåı"11.22.33.44"¡£
		\param port Ó®Ï¢?¡£

		\~japanese
		\param ipAddress IP«¢«É«ì«¹ö·ªÇª¹¡£ÖÇª¨ªĞ¡¢"11.22.33.44"ªÇª¹¡£
		\param port «İ?«Èö·ªÇª¹¡£

		\~
		*/
		static AddrPort FromIPPortV4(const String& ipAddress, uint16_t port);

		static AddrPort FromIPPortV6(const String& ipAddress, uint16_t port);

		static AddrPort FromIPPort(const int32_t& af, const String& ipAddress, uint16_t port);

		/** Set to Any:port. */
		static AddrPort FromAnyIPPort(const int32_t& af, uint16_t port);

		static bool FromHostNamePort(AddrPort* outAddrPort, SocketErrorCode& errorCode, const String& hostName, uint16_t port);

		/**
		\~korean
		NamedAddrPort °´Ã¼·ÎºÎÅÍ °ªÀ» °¡Á®¿Â´Ù.
		- NamedAddrPortÀÇ host nameÀÌ "my.somename.net" ÇüÅÂÀÎ °æ¿ì ÀÌ¸¦ IP address·Î º¯È¯ÇØ¼­ °¡Á®¿Â´Ù.

		\~english
		This method gets a value from NamedAddrPort object.
		- If host name of NamedAddrPort is in "my.somename.net" format, then this method converts the host name to IP address and returns it.

		\~chinese
		?NamedAddrPort?ßÚö¢?¡£
		- ?NamedAddrPortîÜhost nameãÀ"my.somename.net"û¡?îÜ?£¬÷ê???à÷IP addressı¨ö¢üŞ¡£

		\~japanese
		NamedAddrPort «ª«Ö«¸«§«¯«Èª«ªéö·ªòö¢ªê?ªßªŞª¹¡£
		- NamedAddrPortªÎhost nameª¬"my.somename.net"û¡÷¾ªÇª¢ªëíŞùê¡¢ª³ªìªòIP addressªË?üµª·ªÆö¢ªê?ªßªŞª¹¡£
		\~
		*/
		static AddrPort From(const NamedAddrPort& src);

		/**
		\~korean
		¹ÌÁöÁ¤ IP °´Ã¼. µğÆúÆ® °ªÀÌ´Ù.

		\~english
		Undesignated IP object. It is default value.

		\~chinese
		Ú±ò¦ïÒîÜIP?ßÚ£¬ãÀÙù??¡£

		\~japanese
		Ú±ò¦ïÒIP«ª«Ö«¸«§«¯«È¡£«Ç«Õ«©«ë«Èö·ªÇª¹¡£
		\~
		*/
		static AddrPort Unassigned;

		/**
		\~korean
		ºê·ÎµåÄ³½ºÆ® ÁÖ¼Òµµ ¾Æ´Ï°í, null ÁÖ¼Òµµ ¾Æ´Ñ, 1°³ È£½ºÆ®ÀÇ 1°³ Æ÷Æ®¸¦ °¡¸®Å°´Â Á¤»óÀûÀÎ ÁÖ¼ÒÀÎ°¡?

		\~english
		Is it correct address that point 1 port of 1 host instead of broadcast address, null address?

		\~chinese
		ÜôãÀbroadcastò¢ò££¬å¥ÜôãÀnullò¢ò££¬ãÀÜúãÀò¦ìé?ñ«Ïõß¾ìé?Ó®Ï¢îÜïáßÈò¢ò££¿

		\~japanese
		«Ö«í?«É«­«ã«¹«È«¢«É«ì«¹ªÇªâªÊª¯¡¢null«¢«É«ì«¹ªÇªâªÊª¤¡¢1«Û«¹«ÈªÎ1«İ?«Èªòò¦ª¹ïáßÈªÊ«¢«É«ì«¹ªÇª¹ª«£¿
		\~
		*/
		bool IsUnicastEndpoint() const;

		bool IsAnyOrUnicastEndpoint() const;

		static bool IsEqualAddress(const AddrPort& a, const AddrPort& b)
		{
			return a.IsAddressEqualTo(b);
		}

		inline uint32_t Hash() const
		{
			assert(PN_IPV6_ADDR_LENGTH == 16); // º» ÇÔ¼ö´Â IPv6 or IPv4 mapped IPv6 ÁÖ¼Ò¸¸ Ã³¸®ÇÒ ¼ö ÀÖ´Ù.

			uint32_t* p = (uint32_t*)&m_addr;
			uint32_t v = 0;
			for (int i = 0; i < 4; i++)
			{
				v ^= *p;
				p++;
			}
			v ^= m_port;

			return v;
		}

		inline bool operator!=(const AddrPort &rhs) const
		{
			assert(PN_IPV6_ADDR_LENGTH == 16); // º» ÇÔ¼ö´Â IPv6 or IPv4 mapped IPv6 ÁÖ¼Ò¸¸ Ã³¸®ÇÒ ¼ö ÀÖ´Ù.

			if (CompareInt32Array<4>(m_addr.v6Byte, rhs.m_addr.v6Byte) != 0 ||
				m_port != rhs.m_port)
			{
				return true;
			}

			return false;
		}
		inline bool operator==(const AddrPort &b) const
		{
			assert(PN_IPV6_ADDR_LENGTH == 16); // º» ÇÔ¼ö´Â IPv6 or IPv4 mapped IPv6 ÁÖ¼Ò¸¸ Ã³¸®ÇÒ ¼ö ÀÖ´Ù.

			if (CompareInt32Array<4>(m_addr.v6Byte, b.m_addr.v6Byte) == 0 &&
				m_port == b.m_port)
			{
				return true;
			}

			return false;
		}

		inline bool operator<(const AddrPort& b) const
		{
			int compareResult = CompareInt32Array<4>(m_addr.v6Byte, b.m_addr.v6Byte);
			if (compareResult < 0)
				return true;
			if (compareResult > 0)
				return false;
			return m_port - b.m_port < 0;
		}
	};

	/**
	\~korean
	AddrPort¿Í ºñ½ÁÇÏÁö¸¸ m_addr¿¡ ¹®ÀÚ¿­ÀÌ µé¾î°£´Ù.
	- ¹®ÀÚ¿­¿¡´Â 111.222.111.222 ÇüÅÂ ¶Ç´Â game.aaa.com Çü½ÄÀÇ ÀÌ¸§ÀÌ µé¾î°¥ ¼ö ÀÖ´Ù.
	- AddrPortÀº 111.222.111.222 ÇüÅÂ¸¸ÀÌ ÀúÀåµÉ ¼ö ÀÖ´Â ÇÑ°è ¶§¹®¿¡ ÀÌ ±¸Á¶Ã¼°¡ ÇÊ¿äÇÑ°Å´Ù.

	\~english
	It's similar to AddrPort but string can be inserted in m_addr.
	- At string, either 111.222.111.222 format or game.aaa.com format can be added.
	- This structure is needed since AddrPort can only store 111.222.111.222 format.

	\~chinese
	?AddrPorttßÓŞÄ£¬Ó£ãÀm_addr×ìêóí®İ¬Íú¡£
	- í®İ¬Íú×ì?êó111.222.111.222Ì«ãÒ£¬ûäíºgame.aaa.comÌ«ãÒîÜÙ£?¡£
	- ì×?AddrPortñşÒöğí?111.222.111.222Ì«ãÒ£¬á¶ì¤âÍé©ó®?ğã¡£

	\~japanese
	AddrPortªÈ×¾ŞÄª·ªÆª¤ªŞª¹ª¬¡¢m_addrªËÙşí®Öªª¬ìıªêªŞª¹¡£
	- Ùşí®ÖªªËªÏ111.222.111.222û¡÷¾ªŞª¿ªÏgame.aaa.comû¡ãÒªÎÙ£îñª¬ìıªëª³ªÈª¬ªÇª­ªŞª¹¡£
	- AddrPortªÏ111.222.111.222û¡÷¾ªÎªßÜÁğíªÇª­ªëªÈª¤ª¦ùÚÍ£ªÎª¿ªá¡¢ª³ªÎÏ°ğã?ª¬ù±é©ªÇª¹¡£
	\~
	*/
	struct NamedAddrPort
	{
		/**
		\~korean
		È£½ºÆ® ÀÌ¸§
		- ¹®ÀÚ¿­¿¡´Â 111.222.111.222 ÇüÅÂ ¶Ç´Â game.aaa.com Çü½ÄÀÇ ÀÌ¸§ÀÌ µé¾î°¥ ¼ö ÀÖ´Ù.

		\~english
		Host name
		- At string, either 111.222.111.222 format or game.aaa.com format can be added.

		\~chinese
		ñ«ÏõÙ£
		- í®İ¬Íú×ìÊ¦ì¤ôÕÊ¥111.222.111.222ûäíºgame.aaa.comÌ«ãÒîÜÙ£?¡£

		\~japanese
		«Û«¹«ÈÙ£
		- Ùşí®ÖªªËªÏ111.222.111.222û¡÷¾ªŞª¿ªÏgame.aaa.comû¡ãÒªÎÙ£îñª¬ìıªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\~
		*/
		String m_addr;

		/**
		\~korean
		Æ÷Æ® °ª

		\~english
		Port Value

		\~chinese
		Ó®Ï¢?

		\~japanese
		«İ?«Èö·
		\~
		*/
		uint16_t m_port;

		/**
		\~korean
		ºó ÁÖ¼Ò

		\~english
		Empty Address

		\~chinese
		Íöò¢ò£

		\~japanese
		Íö«¢«É«ì«¹
		\~
		*/
		static NamedAddrPort PROUD_API Unassigned;

		/**
		\~korean
		Æ¯Á¤ hostname, Æ÷Æ® ¹øÈ£·ÎºÎÅÍ ÀÌ °´Ã¼¸¦ »ı¼ºÇÑ´Ù.

		\~english
		Generate this object from a specific hostname and port number.

		\~chinese
		÷åïÒîÜhostname£¬?Ó®Ï¢??ßæà÷ó®?ßÚ¡£

		\~japanese
		÷åïÒhostname¡¢«İ?«ÈÛã?ª«ªéª³ªÎ«ª«Ö«¸«§«¯«Èªòßæà÷ª·ªŞª¹¡£
		\~
		*/
		static NamedAddrPort PROUD_API FromAddrPort(String addr, uint16_t port);

		/**
		\~korean
		AddrPort °´Ã¼·ÎºÎÅÍ ÀÌ °´Ã¼¸¦ »ı¼ºÇÑ´Ù

		\~english
		Generate this object from AddrPort object

		\~chinese
		?AddrPort?ßÚßæà÷???ßÚ¡£

		\~japanese
		AddrPort«ª«Ö«¸«§«¯«Èª«ªéª³ªÎ«ª«Ö«¸«§«¯«Èªòßæà÷ª·ªŞª¹¡£
		\~
		*/
		static NamedAddrPort PROUD_API From(const AddrPort &src);

		/**
		\~korean
		hostnameÀÌ µé¾îÀÖ´Â ¹®ÀÚ¿­ÀÎ °æ¿ì µé¾îÀÖ´Â ¹®ÀÚ¿­·Î »õ È£½ºÆ® ÀÌ¸§À» ÁöÁ¤ÇÑ´Ù.

		\~english
		Appoint a new host name with the string inside of hostname.

		\~chinese
		êóhostnameí®İ¬ÍúîÜï×?£¬ŞÅéÄ?î¤í®İ¬Íúò¦ïÒãæîÜñ«ÏõÙ£¡£

		\~japanese
		hostnameª¬ìıªëÙşí®ÖªªÎíŞùê¡¢ìıªÃªÆª¤ªëÙşí®ÖªªËãæª·ª¤«Û«¹«ÈÙ£ªòò¦ïÒª·ªŞª¹¡£
		\~
		*/
		PROUD_API void OverwriteHostNameIfExists(const String &hostName);

		/**
		\~korean
		ºñ±³ ¿¬»êÀÚ

		\~english
		Comparison Operator

		\~chinese
		İï??ß©İ¬

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		inline bool operator==( const NamedAddrPort &rhs ) const
		{
			return m_addr == rhs.m_addr && m_port == rhs.m_port;
		}

		/**
		\~korean
		ºñ±³ ¿¬»êÀÚ

		\~english
		Comparison Operator

		\~chinese
		İï??ß©İ¬

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		inline bool operator!=( const NamedAddrPort &rhs ) const
		{
			return !( m_addr == rhs.m_addr && m_port == rhs.m_port );
		}

		/**
		\~korean
		³»¿ë¹°À» ¹®ÀÚ¿­·Î ¸¸µç´Ù.

		\~english
		This method makes the contents into string.

		\~chinese
		÷ê?é»ËÇà÷í®İ¬Íú¡£

		\~japanese
		?é»ÚªªòÙşí®ÖªªËª·ªŞª¹¡£
		\~
		*/
		String PROUD_API ToString() const;

		/**
		\~korean
		ºê·ÎµåÄ³½ºÆ® ÁÖ¼Òµµ ¾Æ´Ï°í, null ÁÖ¼Òµµ ¾Æ´Ñ, 1°³ È£½ºÆ®ÀÇ 1°³ Æ÷Æ®¸¦ °¡¸®Å°´Â Á¤»óÀûÀÎ ÁÖ¼ÒÀÎ°¡?

		\~english
		Is it correct address that point 1 port of 1 host instead of broadcast address, null address?

		\~chinese
		ÜôãÀbroadcastò¢ò££¬å¥ÜôãÀnullò¢ò££¬ãÀÜúãÀò¦ïÒìé?ñ«Ïõß¾ìé?Ó®Ï¢îÜïáßÈò¢ò££¿

		\~japanese
		«Ö«í?«É«­«ã«¹«È«¢«É«ì«¹ªÇªâªÊª¯¡¢null«¢«É«ì«¹ªÇªâªÊª¤¡¢1«Û«¹«ÈªÎ1«İ?«Èªòò¦ª¹ïáßÈªÊ«¢«É«ì«¹ªÇª¹ª«£¿
		\~
		*/
		bool IsUnicastEndpoint();
	};

	inline void AppendTextOut(String& a, AddrPort &b)
	{
		a += b.ToString();
	}

	inline void AppendTextOut(String& a, NamedAddrPort &b)
	{
		a += b.ToString();
	}

	/**
	\~korean
	³×Æ®¿öÅ© ÇÁ·Î±×·¡¹Ö °ü·Ã À¯Æ¿¸®Æ¼ Å¬·¡½º

	\~english
	Network programming related utility class

	\~chinese
	???ïïßÓ?îÜ?éÄïïßí?

	\~japanese
	«Í«Ã«È«ï?«¯«×«í«°«é«ß«ó«°?Ö§«æ?«Æ«£«ê«Æ«£?«¯«é«¹
	\~
	*/
	class CNetUtil
	{
	public:
//#if !defined __MARMALADE__ && !defined __FreeBSD__
		/**
		\~korean
		È£½ºÆ®°¡ °®°í ÀÖ´Â ·ÎÄÃ IP ÁÖ¼Ò¸¦ ¸ğµÎ ¾ò¾î³À´Ï´Ù.

		\~english
		Gets every local IP addresses that host has.

		\~chinese
		ö¢Ôğñ«Ïõ?êóîÜá¶êóÜâò¢IPò¢ò£¡£

		\~japanese
		«Û«¹«Èª¬ò¥ªÃªÆª¤ªë«í?«««ëIP«¢«É«ì«¹ªòîïªÆö¢ªêò¥ªÁªŞª¹¡£
		\~
		*/
		PROUD_API static void GetLocalIPAddresses(CFastArray<String> &output);
//#endif // !defined(__MARMALADE__)

		PROUD_API static int GetIPVersionFromString(const String& rhs);

		/** Returns true if address is filled with 255 or 0xffff. */
		static bool IsAddressAny(const String& address);

		/** Returns true if address is filled with 0. */
		static bool IsAddressUnspecified(const String& address);

		/** Returns true if address is not Any, Unspecified nor Loopback. */
		static bool IsAddressPhysical(const String& address);

		/** Returns true if addres is Loopback. For example, "127.0.0.1", "::1" or "localhost". */
		static bool IsAddressLoopback(const String& address);

#if defined(_WIN32)

		/**
		\~korean
		ÀÏºÎ ¿Âº¸µå Àú°¡Çü ³×Æ®¿öÅ© ¾Æ´äÅ¸ÀÇ °æ¿ì ÇÏµå¿ş¾î¿¡¼­ Áö¿øÇÏ´Â TCP offload ±â´É¿¡ ¹®Á¦°¡ ÀÖÀ» ¼ö ÀÖ½À´Ï´Ù.
		ÀÌ ¸Ş¼­µå´Â À©µµ¿ì ·¹Áö½ºÆ®¸®¿¡¼­ ÇØ´ç ±â´ÉÀ» Á¦¾îÇÏ¸ç ÀçºÎÆÃÀ» ÇÊ¿ä·Î ÇÕ´Ï´Ù.
		\return ErrorType_Ok ÀÌ¸é ¼º°øÀûÀ¸·Î Àû¿ëÇßÀ¸¸ç, ÀçºÎÆÃÀ» ¿äÇÕ´Ï´Ù. Windows Vista ÀÌ»óÀÇ OS ¿¡¼­ °ü¸®ÀÚ ±ÇÇÑÀ» È¹µæÇÏÁö ¾ÊÀ¸¸é ErrorType_PermissionDenied ¿¡·¯°¡ ¹ß»ıÇÒ ¼ö ÀÖ½À´Ï´Ù. ±âÅ¸ ¿À·ùÀÇ °æ¿ì ErrorType_Unexpected °¡ ¸®ÅÏµË´Ï´Ù.

		\~english
		TCP offload function will occur problem with some cheap network adapter that intergrated on the mother board.
		This method is controlled by Windows registry and it require restart a machine.
		It successfully applied, if \return ErroType_Ok is true. and it require restart. ErrorType_PermissionDenied will occur, if you do not get aminitrator permission on Windows Vista or above version. ErrorType_Unexpected will return with other errors

		\~chinese
		ìéŞÁÖ¯ËÀîÜ??ÎÁÛÕĞïó¢à÷£¬Ê¦Òö?î¤ÌãËìò¨ò¥îÜTCP offloadĞüÒö?ßæ??¡£??Û°Ûö?î¤Windowsñ¼?øúß¾Íóğ¤êó?ĞüÒö£¬?âÍé©ñìãæ??¡£¡¢
		\return ErrorType_OkîÜ?øúãÆ?éÄà÷Íí£¬âÍñìãæ??¡£î¤Windows Vistaì¤ß¾îÜOS×ìÜô?ÔğÎ·×â?ùÚ£¬??ßæErrorType_PermissionDenied??¡£Ğìöâ??îÜ?ı¦?Ú÷üŞErrorType_Unexpected¡£

		\~japanese
		ìéİ»«ª«ó«Ü?«Éî¸ù»úş«Í«Ã«È«ï?«¯«¢«À«×«¿?ªÎíŞùê¡¢«Ï?«É«¦«§«¢ªÇ«µ«İ?«Èª¹ªëTCP offloadÑ¦ÒöªËÙığ¹ª¬ª¢ªëíŞùêª¬ª¢ªêªŞª¹¡£
		ª³ªÎ«á«½«Ã«ÉªÏ«¦«£«ó«É«¦«ì«¸«¹«È«ê?ªÇú±?Ñ¦Òöªòğ¤åÙª·ªÆî¢ÑÃÔÑªòù±é©ªÈª·ªŞª¹¡£
		\return ErrorType_OkªÇª¢ªìªĞîêéÄ?ªßªÇª¹ªÎªÇî¢ÑÃÔÑª·ªÆª¯ªÀªµª¤¡£Windows Vistaì¤ß¾ªÎOSªÇÎ·×âíºªÎ?ùÚªòüòÔğª·ªÊª±ªìªĞErrorType_PermissionDenied«¨«é?ª¬?ßæª¹ªëÊ¦Òöàõª¬ª¢ªêªŞª¹¡£ª½ªÎöâ«¨«é?ªÎíŞùê¡¢ErrorType_Unexpectedª¬ö¢ªê?ªµªìªŞª¹¡£
		\~
		*/
		PROUD_API static ErrorType EnableTcpOffload(bool enable);
#endif
	};

	/**  @}  */
}

template<>
class CPNElementTraits < Proud::AddrPort >
{
public:
	typedef const Proud::AddrPort& INARGTYPE;
	typedef Proud::AddrPort& OUTARGTYPE;

	inline static uint32_t Hash(INARGTYPE a)
	{
		uint32_t sumVal = 0;
		for (int32_t i = 0; i < Proud::PN_IPV6_ADDR_LENGTH; i++)
		{
			sumVal += a.m_addr.v6Byte[i];
		}

		return sumVal ^ a.m_port;
	}

	inline static bool CompareElements(INARGTYPE element1, INARGTYPE element2)
	{
		return element1 == element2;
	}

	inline static int CompareElementsOrdered(INARGTYPE element1, INARGTYPE element2)
	{
 		if (element1 < element2)
 			return -1;
 		if (element1 == element2)
 			return 0;
		return 1;
	}
};

// template<>
// class CPNElementTraits<Proud::AddrPort>
// {
// public:
// 	typedef const Proud::AddrPort& INARGTYPE;
// 	typedef Proud::AddrPort& OUTARGTYPE;
//
// 	inline static ULONG Hash( INARGTYPE element )
// 	{
// 		assert(sizeof(element.m_binaryAddress) == 4);
// 		return element.m_binaryAddress ^ element.m_port;
//
// 		return ret;
// 	}
//
// 	inline static bool CompareElements( INARGTYPE element1, INARGTYPE element2 ) throw()
// 	{
// 		return ( element1 == element2 ) ? true:false;
// 	}
//
// 	inline static int CompareElementsOrdered( INARGTYPE element1, INARGTYPE element2 ) throw()
// 	{
// 		if(element1.m_binaryAddress < element2.m_binaryAddress)
// 			return -1;
// 		else if(element1.m_binaryAddress < element2.m_binaryAddress)
// 			return 1;
// 		if(element1.m_port < element2.m_port)
// 			return -1;
// 		else if(element1.m_port > element2.m_port)
// 			return 1;
// 		return 0;
// 	}
// };

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

