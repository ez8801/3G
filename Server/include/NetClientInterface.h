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

//#define TEST_DISCONNECT_CLEANUP Å×½ºÆ® ¿ëµµ

#include "IRmiHost.h"
#include "HlaHost_C.h"
#include "BasicTypes.h"
#include "ConnectParam.h"
#include "HostIDArray.h"
#include "AddrPort.h"
#include "Enums.h"
#include "ErrorInfo.h"
#include "EncryptEnum.h"
#include "RMIContext.h"
#include "ErrorInfo.h"
#include "NetClientStats.h"
#include "LambdaEventHandler.h"
#include "acr.h"

#define PN_DEPRECATED /*__declspec(deprecated) */

#ifdef _MSC_VER // pragma warningÀº VC++Àü¿ë
#pragma warning(push)
#pragma warning(disable:4324)
#endif

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

	class MessageSummary;
	class CTestStats2;
	class CMessage;
	class CNetConnectionParam;
	class CNetPeerInfo;
	class CP2PGroup;

	class CSendFragRefs;
	class ErrorInfo;
	class INetClientEvent;
	class IRmiProxy;
	class IRmiStub;
	class ReliableUdpHostStats;
	class CUserWorkerThreadCallbackContext;

	struct SendOpt;



	/**
	\~korean
	\brief Å¬¶óÀÌ¾ğÆ® FrameMove Ã³¸® °á°ú
	- FrameMove¿¡¼­ ¸Ş½ÃÁö¿Í ÀÌº¥Æ®°¡ ¾ó¸¶³ª Ã³¸® µÇ¾ú´ÂÁö ÀÇ °á°ú ÀÔ´Ï´Ù.

	\~english
	\brief client FrameMove process result
	- The result that shows how much of messages and events were processed by FrameMove

	\~chinese
	\brief clientFrameMove?×â?Íı¡£
	- î¤FrameMoveñéãáãÓ?event?×âÒıá´îÜ?Íı¡£

	\~japanese
	\brief «¯«é«¤«¢«ó«ÈFrameMoveªÎ?×âÌ¿Íı
	- FrameMoveªÇ«á«Ã«»?«¸ªÈ«¤«Ù«ó«Èª¬ªÉªìªÀª±?×âªµªìª¿ªÎª«ªÎÌ¿ÍıªÇª¹¡£ 

	\~
	*/
	class CFrameMoveResult
	{
	public:

		/**
		\~korean
		FrameMove È£Ãâ ÀÌÈÄ RMI È£Ãâ È½¼öÀÔ´Ï´Ù.

		\~english
		Number of RMI caling after calling FrameMove

		\~chinese
		FrameMoveû¼Ğ£ì¤ı¨RMIû¼Ğ£ó­?¡£

		\~japanese
		FrameMove û¼ªÓõóª·ì¤Ë½ªËRMIû¼ªÓõóª·üŞ?ªÇª¹¡£
		\~
		*/
		uint32_t	m_processedMessageCount;

		/**
		\~korean
		FrameMove È£Ãâ ÀÌÈÄ INetClientEvent Äİ¹é È½¼öÀÔ´Ï´Ù.

		\~english
		Number of INetClientEvent callback after calling FrameMove

		\~chinese
		FrameMoveû¼Ğ£ì¤ı¨INetClientEventüŞ?ó­?¡£

		\~japanese
		FrameMove û¼ªÓõóª·ì¤Ë½ªËINetClientEvent «³?«ë«Ğ«Ã«¯üŞ?ªÇª¹¡£
		\~
		*/
		uint32_t	m_processedEventCount;

		CFrameMoveResult():
			m_processedMessageCount(0),
			m_processedEventCount(0)
		{

		}
	};

	/**
	\~korean
	\brief ¼­¹ö¿ÍÀÇ ¿¬°á »óÅÂ¸¦ ¾òÀº °á°ú

	\~english
	\brief Acquired result of the connection status to server

	\~chinese
	\brief ?Ôğ?Ü×?ĞïîÜ?ïÈ??îÜ?Íı¡£

	\~japanese
	\brief «µ?«Ğ?ªÈªÎïÈ??÷¾ªòÔğª¿Ì¿Íı 
	\~
	*/
	class CServerConnectionState
	{
	public:
		/**
		\~korean
		¼­¹ö¿ÍÀÇ UDP ¿¬°áÀÌ Àß µÇ¾î ÀÖ´Â »óÅÂÀÌ¸é trueÀÌ´Ù.
		ÀÌ°Ô falseÀÎ °æ¿ì, unreliable ¸Ş½ÃÂ¡Àº TCP¸¦ ÅëÇØ ½ÃÇàµÈ´Ù.

		\~english
		True if UDP connection to server is well
		If false then unreliable messaging is done via TCP

		\~chinese
		?Ü×?ĞïîÜUDP?ïÈ??ÕŞû¿îÜ?true¡£
		?ãÀfalseîÜ?£¬unreliable messaging÷×?TCP?ú¼¡£

		\~japanese
		«µ?«Ğ?ªÈªÎUDPïÈ?ª¬ªèª¯ªÇª­ªÆª¤ªë?÷¾ªÊªétrueªÇª¹¡£
		ª³ªìª¬falseªÇª¢ªëíŞùê¡¢unreiable«á«Ã«»?«¸«ó«°ªÏTCPªò÷×ª¸ã¿ú¼ªµªìªŞª¹¡£

		\~
		*/
		bool m_realUdpEnabled;

		CServerConnectionState()
		{
			m_realUdpEnabled = false;
		}
	};

	/**
	\~korean
	\brief ProudNet ³»ºÎ¿¡¼­ Direct P2P Åë½ÅÀ» À§ÇØ º¸À¯ÇÏ°í ÀÖ´Â ÁÖ¼Ò µîÀÇ Á¤º¸ÀÔ´Ï´Ù.
	CNetClient.GetDirectP2PInfo µî¿¡¼­ »ç¿ëµË´Ï´Ù.

	\~english
	\brief Information that contains addresses and others for internal P2P communication in ProudNet.
	Used at CNetClient.GetDirectP2PInfo and so on.

	\~chinese
	\brief î¤ProudNet?İ»?ÖõDirect P2P÷×ãáì»ÜÁ×ºîÜò¢ò£ÔõãáãÓ¡£î¤ CNetClient.GetDirectP2PInfo%ÔõŞÅéÄ¡£

	\~japanese
	\brief ProudNet ?İ»ªÇDirect P2P÷×ãáªÎª¿ªáªËÜÁêóª·ªÆª¤ªë«¢«É«ì«¹ªÊªÉªÎï×ÜÃªÇª¹¡£ 
	CNetClient.GetDirectP2PInfo ªÊªÉªÇŞÅªïªìªŞª¹¡£

	\~
	*/
	class CDirectP2PInfo
	{
	public:
		/**
		\~korean
		CNetClient°¡ »ó´ë ÇÇ¾î¿ÍÀÇ Direct P2P Åë½ÅÀ» À§ÇØ °®°í ÀÖ´Â UDP ¼ÒÄÏÀÇ ·ÎÄÃ ÁÖ¼Ò
		- CNetClient.GetLocalUdpSocketAddr¿Í °°Àº °ªÀÌ´Ù.

		\~english
		Local address of UDP socket possessed by CNetClient for it to use direct P2P communication with opponent peer
		- Has same value as CNetClient.GetLocalUdpSocketAddr

		\~chinese
		CNetClient ??Û°peerîÜDirect P2P÷×ãáá¶?êóîÜUDP socketÜâò¢ò¢ò£¡£
		- ? CNetClient.GetLocalUdpSocketAddr%ìé?îÜ?¡£

		\~japanese
		CNetClientª¬ßÓâ¢peerªÈªÎDirect P2P÷×ãáªÎª¿ªáªËò¥ªÃªÆª¤ªëUDP«½«±«Ã«ÈªÎ«í?«««ë«¢«É«ì«¹ 	
		- CNetClient.GetLocalUdpSocketAddrªÈÔÒª¸ö·ªÇª¹¡£ 

		\~
		*/
		AddrPort m_localUdpSocketAddr;

		/**
		\~korean
		»ó´ë ÇÇ¾î¿¡°Ô Direct P2P·Î ÆĞÅ¶À» ¼Û½Å½Ã »ó´ë ÇÇ¾îÀÇ Âø½Å ÁÖ¼ÒÀÌ´Ù.
		socket API sendto()¿¡ ¾²ÀÌ±âµµ ÇÑ´Ù.

		\~english
		Reception address of opponent peer when packets sent through Direct P2P
		Can be used at socket API sendto()

		\~chinese
		??Û°peeréÄDirect P2P?áê?ËßøĞ??Û°peerîÜâ¥ãáò¢ò£¡£
		å¥î¤socket API sendto()×ìŞÅéÄ¡£

		\~japanese
		ßÓâ¢PeerªËDirect P2PªÇ«Ñ«±«Ã«ÈªòáêãáãÁªËßÓâ¢peerªÎó·ãá«¢«É«ì«¹ªÇª¹¡£
		socket API sendto()ªËŞÅªïªìª¿ªêª·ªŞª¹¡£ 

		\~
		*/
		AddrPort m_localToRemoteAddr;

		/**
		\~korean
		»ó´ë ÇÇ¾î·ÎºÎÅÍ Direct P2P ·Î ÆĞÅ¶À» ¼ö½Å½Ã »ó´ë ÇÇ¾îÀÇ ¼Û½Å ÁÖ¼ÒÀÌ´Ù.
		socket API recvfrom()¿¡ ¾²ÀÌ±âµµ ÇÑ´Ù.

		\~english
		Transmission address of opponent peer when packets received through Direct P2P
		Can be used at socket API recvfrom()

		\~chinese
		??Û°peeréÄDirect P2PïÈâ¥?ËßøĞ??Û°peerîÜ?áêò¢ò£¡£
		å¥î¤socket API recvfrom()×ìŞÅéÄ¡£

		\~japanese
		ßÓâ¢peerª«ªéDirect P2PªÇ«Ñ«±«Ã«ÈªòáôãáãÁªËßÓâ¢peerªÎáêãá«¢«É«ì«¹ªÇª¹¡£
		socket API recvfrom()ªËŞÅªïªìª¿ªêª·ªŞª¹¡£ 

		\~
		*/
		AddrPort m_remoteToLocalAddr;

		inline CDirectP2PInfo()
		{
			m_localToRemoteAddr = AddrPort::Unassigned;
			m_remoteToLocalAddr = AddrPort::Unassigned;
			m_localUdpSocketAddr = AddrPort::Unassigned;
		}

		/**
		\~korean
		P2P È¦ÆİÄªÀÌ ¼º»çµÇ¾î¼­ È®º¸µÈ Á¤º¸ÀÎ°¡?

		\~english
		Is this acquired after P2P hole-punching is completed?

		\~chinese
		ãÀP2PöèÔ×à÷Ííı¨?ÜÁîÜãáãÓ?£¿

		\~japanese
		P2P «Û?«ë«Ñ«ó«Á«ó«°ªËà÷Ííª·ªÆü¬ÜÁªµªìª¿ï×ÜÃªÊªÎª«£¿ 
		\~
		*/
		inline bool HasBeenHolepunched()
		{
			return m_localUdpSocketAddr.IsUnicastEndpoint() && m_localToRemoteAddr.IsUnicastEndpoint() && m_remoteToLocalAddr.IsUnicastEndpoint();
		}
	};

	/**
	\~korean
	\brief ³×Æ®¿öÅ© Å¬¶óÀÌ¾ğÆ®

	°ÔÀÓ Å¬¶óÀÌ¾ğÆ®¿Í °ÔÀÓ ¼­¹öÀÇ ³×Æ®¿öÅ·°ú ³×Æ®¿öÅ© Å¬¶óÀÌ¾ğÆ®°£ÀÇ P2P Åë½ÅÀ» À§ÇÑ Å¬¶óÀÌ¾ğÆ®ÀÔ´Ï´Ù.

	ÀÚ¼¼ÇÑ ³»¿ëÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#client_overview" >³×Æ®¿öÅ© Å¬¶óÀÌ¾ğÆ®</a> ¿¡ ÀÖ½À´Ï´Ù.

	\~english
	\brief Network Client

	A network client class for client-to-server networking and client-to-client (P2P) networking.

	<a target="_blank" href="http://guide.nettention.com/cpp_en#client_overview" >Network Client</a> explains the details.

	\~chinese
	\brief ??client¡£

	?Öõêı?clientûúêı?Ü×?ĞïîÜ??ûú??clientñı?P2P÷×ãáîÜclient¡£

	???é»î¤<a target="_blank" href="http://guide.nettention.com/cpp_zh#client_overview" >??ËÔ?Ó®</a>%×ì¡£

	\~japanese
	\brief «Í«Ã«È«ï?«¯«¯«é«¤«¢«ó«È
	«²?«à«¯«é«¤«¢«ó«ÈªÈ«²?«à«µ?«Ğ?ªÎ«Í«Ã«È«ï?«­«ó«°ªÈ«Í«Ã«È«ï?«¯«¯«é«¤«¢«ó«ÈÊàªÎP2P÷×ãáªÎª¿ªáªÎ«¯«é«¤«¢«ó«ÈªÇª¹¡£
	ßÙª·ª¯ªÏ¡¢\ref client_overviewªËª¢ªêªŞª¹¡£

	\~
	*/
	class CNetClient : public IRmiHost, public IHlaHost_C, public HasCoreEventFunctionObjects
	{
	public:
		virtual ~CNetClient() {}

	private:
		static CNetClient* Create_Internal();
	public:

		/**
		\~korean
		»õ ÀÎ½ºÅÏ½º¸¦ »ı¼ºÇÕ´Ï´Ù.

		\~english
		Creates new instance.

		\~chinese
		ßæà÷ãæ?ÖÇ¡£

		\~japanese
		ãæª·ª¤«¤«ó«¹«¿«ó«¹ªòßæà÷ª·ªŞª¹¡£
		\~
		*/
		inline static CNetClient* Create()
		{
			// ¿©±â¼­ PROUDNET_H_LIB_SIGNATURE¸¦ °Çµå¸°´Ù. ÀÌ·¸°Ô ÇÔÀ¸·Î ÀÌ Àü¿ª º¯¼ö°¡ ÄÄÆÄÀÏ·¯¿¡ ÀÇÇØ »ç¶óÁöÁö ¾Ê°Ô ÇÑ´Ù.
			PROUDNET_H_LIB_SIGNATURE++;
			return Create_Internal();
		}
		/*
		\~korean
		°¡»óÀ¸·Î ·¢ À¯¹ßÀ» ½ÃÅ²´Ù. ¼Û½Å, ¼ö½Å½Ã¿¡ ¸ğµÎ Àû¿ëµÈ´Ù.
		Åë»óÀûÀ¸·Î 300,100ÀÌ ¾à°£ ½ÉÇÑ ·¢ È¯°æÀ» Èä³»³½´Ù.

		\~english
		Virtually causes laggy situation. Applies to both transmission and reception.	Usually, 300,100 causes an average laggy situation.

		\~chinese
		????lag¡£?áêûúïÈâ¥ãáãÓ?Ô´ÒöÎÁéÄ¡£
		ìéÚõ300,100Ù¼???ñìîÜlag?ÌÑ¡£

		\~japanese
		?ßÌªÇ«é«Ã«¯ªòë¯?ªµª»ªŞª¹¡£áêáôãáãÁªËîïªÆîêéÄªµªìªŞª¹¡£
		÷×ßÈîÜªË300,100ª¬á´ª·ªÒªÉª¤«é«Ã«¯ü»ÌÑªò?ŞÄªŞª¹¡£

		\~
		*/
#ifdef DEPRECATE_SIMLAG
		virtual void SimulateBadTraffic(uint32_t minExtraPing, uint32_t extraPingVariance) = 0;
#endif // DEPRECATE_SIMLAG

		/**
		\~korean
		¼­¹ö ¿¬°á °úÁ¤À» ½ÃÀÛÇÕ´Ï´Ù.
		- ÀÌ ÇÔ¼ö´Â Áï½Ã ¸®ÅÏÇÕ´Ï´Ù. µû¶ó¼­, ÀÌ ÇÔ¼ö°¡ ¸®ÅÏÇß´Ù°í ÇØ¼­ ¼­¹ö¿ÍÀÇ ¿¬°áÀÌ ¸ğµÎ ³¡³­ °ÍÀº ¾Æ´Õ´Ï´Ù.
		- ÀÌ ÇÔ¼ö È£Ãâ ÈÄ INetClientEvent.OnJoinServerComplete() ÀÌº¥Æ®°¡ µµÂøÇÑ ÈÄ¿¡¾ß ¼­¹ö ¿¬°áÀÇ ¼º»ç ¿©ºÎ¸¦ ÆÄ¾ÇÇÒ ¼ö ÀÖ½À´Ï´Ù.

		\param param ¿¬°áÇÒ ¼­¹ö Á¤º¸ÀÔ´Ï´Ù.
		\return ÀÌ¹Ì ´Ù¸¥ ¼­¹ö¿¡ ¿¬°áµÈ »óÅÂÀÌ¸é false¸¦ ¸®ÅÏÇÑ´Ù. ¼º°øÀûÀ¸·Î ¿¬°á ¿äÃ»À» ½ÃÀÛÇßÀ¸¸é true°¡ ¸®ÅÏµË´Ï´Ù.

		\~english

		Initialtes server connection request.

		- This function returns immediately. Being this function returned does not mean that the connection to server is completed.
		- It is possible to verify if connection to server is completed only after INetClientEvent.OnJoinServerComplete event arrives after calling this function.

		\param connectionInfo specifies server information to connect to.
		\return Returns false is already connected to other server. Returns true if successfully connected.

		\~chinese
		?ã·?Ü×?ĞïîÜ?ïÈ?ïï¡£
		- ó®ùŞ?Ø¡?Ú÷üŞ¡£ó®ùŞ?Ú÷üŞÜôÓÛøú?Ü×?ĞïîÜ?ïÈîïİ»?áÖ¡£
		- ó®ùŞ?û¼Ğ£ı¨ INetClientEvent.OnJoinServerComplete() eventÓğ?ı¨î¦Ê¦ì¤ò±Ô³Ü×?Ğï?ïÈîÜà÷Íí?Üú¡£

		\param param é©?ïÈîÜÜ×?ĞïãáãÓ¡£
		\return ì«?ãÀ?ĞìöâÜ×?Ğï?ïÈîÜ??îÜ?Ú÷üŞfalse¡£à÷Íí?ã·Öõ?ïÈé­?îÜ?Ú÷üŞtrue¡£

		\~japanese
		«µ?«Ğ?ïÈ?Î¦ïïªòËÒã·ª·ªŞª¹¡£
		ª³ªÎ??ªÏòÁªÁªË«ê«¿?«óª·ªŞª¹¡£ªèªÃªÆ¡¢ª³ªÎ??ª¬«ê«¿?«óª·ª¿ªÈª·ªÆ«µ?«Ğ?ªÈªÎïÈ?ª¬îïªÆğûªïªÃª¿ªÎªÇªÏª¢ªêªŞª»ªó¡£
		- ª³ªÎ??ªòû¼ªÓõóª·ª¿ı­¡¢INetClientEvent.OnJoinServerComplete() «¤«Ù«ó«Èª¬Óğó·ª·ª¿ı­ªËªÊªÃªÆ«µ?«Ğ?ïÈ?ªÎà÷ÍíÊ¦Üúªò÷êäÄª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\param param ïÈ?ª¹ªë«µ?«Ğ?ï×ÜÃªÇª¹¡£
		\return ?ªËöâªÎ«µ?«Ğ?ªËïÈ?ªµªìª¿?÷¾ªÇª¢ªìªĞfalseªò«ê«¿?«óª·ªŞª¹¡£ïÈ?é©ôëªòËÒã·ª·ª¿ªétrueª¬«ê«¿?«óªµªìªŞª¹¡£

		\~
		*/
		virtual bool Connect(const CNetConnectionParam &connectionInfo) = 0;
		virtual bool Connect(const CNetConnectionParam &connectionInfo, ErrorInfoPtr &outError) = 0;

		/**
		\~korean
		¼­¹ö¿ÍÀÇ ¿¬°áÀ» ÇØÁ¦ÇÑ´Ù. ¾Æ¿ï·¯ ¸ğµç P2P ±×·ì¿¡¼­µµ Å»ÅğÇÑ´Ù.
		- ÀÚ¼¼ÇÑ °ÍÀº µ¿¸í ¸Ş¼­µå ÂüÁ¶

		\~english
		Terminates the connection to server and withdraws from all P2P group.
		- Please refer to same name method for more detail.

		\~chinese
		ú°ğ¶?Ü×?ĞïîÜ?ïÈ¡£ñıı¨÷Üõóá¶êóP2P?¡£
		- ????ÍÅÔÒÙ£Û°Ûö¡£

		\~japanese
		«µ?«Ğ?ªÈªÎïÈ?ªòú°ğ¶ª·ªŞª¹¡£ªÁªÊªßªË¡¢ª¹ªÙªÆªÎP2P«°«ë?«×ª«ªéªâ?÷Üª·ªŞª¹¡£
		- ßÙª·ª¯ªÏ¡¢ÔÒÙ£«á«½«Ã«Éªòª´?ğÎª¯ªÀªµª¤¡£

		\~
		*/
		virtual void Disconnect() = 0;

		/**
		\~korean
		¼­¹ö¿ÍÀÇ ¿¬°áÀ» ÇØÁ¦ÇÑ´Ù. ¾Æ¿ï·¯ ¸ğµç P2P ±×·ì¿¡¼­µµ Å»ÅğÇÑ´Ù.
		\param gracefulDisconnectTimeout ¼­¹ö¿ÍÀÇ ¿¬°áÀ» ÇØÁ¦ÇÏ´Â °úÁ¤À» Ã³¸®ÇÏ±â À§ÇØ Å¬¶óÀÌ¾ğÆ®´Â ÀÏÁ¤ ½Ã°£ÀÇ
		½Ã°£À» ¿ä±¸ÇÑ´Ù. ÀÌ °ªÀº ¼­¹ö¿ÍÀÇ ¿¬°áÀ» ÇØÁ¦ÇÏ´Â µ¥±îÁö Çã¶ôÇÏ´Â ÃÖ´ë ½Ã°£(ÃÊ)ÀÌ´Ù.
		ÀÌ °ªÀº Åë»óÀûÀ¸·Î 1 ÀÌ³»°¡ Àû´çÇÏÁö¸¸, ³Ê¹« Áö³ªÄ¡°Ô ÀÛÀº °ªÀ» Àâ´Â °æ¿ì, Å¬¶óÀÌ¾ğÆ®´Â ¼­¹ö¿ÍÀÇ
		¿¬°áÀ» Á¾·áÇßÁö¸¸ ¼­¹öÃø¿¡¼­ Å¬¶óÀÌ¾ğÆ®ÀÇ ¿¬°á ÇØÁ¦¸¦ Áï½Ã °¨ÁöÇÏÁö ¸øÇÏ´Â °æ¿ì°¡ ÀÖÀ» ¼ö ÀÖ´Ù.
		\param comment ¿©±â¿¡ Ã¤¿öÁø µ¥ÀÌÅÍ´Â INetServerEvent.OnClientLeave¿¡¼­ ¹Ş¾ÆÁø´Ù.
		Áï Å¬¶óÀÌ¾ğÆ®°¡ ¼­¹ö¿ÍÀÇ ¿¬°áÀ» ÇØÁ¦ÇÏµÇ ¼­¹ö¿¡°Ô ¸¶Áö¸·À¸·Î µ¥ÀÌÅÍ¸¦ º¸³»°íÀÚ ÇÒ ¶§(¿¹: Á¢¼ÓÀ» ²÷´Â ÀÌÀ¯¸¦ º¸³»±â) À¯¿ëÇÏ´Ù.
		gracefulDisconnectTimeout°¡ ³Ê¹« ÂªÀ¸¸é ¸ø °¥¼ö ÀÖ´Ù.

		\~english
		Terminates the connection to server and withdraws from all P2P group.
		\param gracefulDisconnectTimeout Client requires a certain amount of time in order to process the steps to terminate the connection to server. This value is the maximum time(in second) that allowed to complete the termination.
		Usually 1 is reasonable for the value but if it is too small then there can be some cases that server cannot detect clinet's diconnection immediately after client terminated the connection.
		\param comment The data filled in here will be received at INetServerEvent.OnClientLeave.
		In other words, it is useful when client need to send its last data to server before terminating its connection to server.(e.g. sending why terminating the connection)
		If gracefulDisconnectTimeout is too short then there is a chance the sending fails.

		\~chinese
		ú°ğ¶?Ü×?ĞïîÜ?ïÈ¡£ñıı¨÷Üõóá¶êóP2P?¡£
		\param gracefulDisconnectTimeout ?Öõ?×â?Ü×?Ğï?ïÈîÜú°ğ¶?ïï£¬client é©Ï´ìéïÒ??îÜ??¡£ó®?ãÀú°ğ¶?Ü×?ĞïîÜ?ïÈîÜëÃ?îÜõÌÓŞ??£¨õ©£©¡£
		ó®?ìéÚõ1ì¤??ÎÁ?£¬éÄ?á³îÜ?îÜ?Ê¦Òö??ßæclient?Ü×?ĞïîÜ?ïÈ?ì«?ò­£¬Ü×?ĞïÛ°ÜôÒöØ¡?Êïò±clientîÜ?ïÈú°ğ¶îÜï×?¡£
		\param comment èÙ?×ì?õöîÜ?Ëßî¤ INetServerEvent.OnClientLeave%ïÈâ¥¡£?clientú°ğ¶?Ü×?ĞïîÜ?ïÈ£¬ßÌõÌı¨?Ü×?Ğï?áê?ËßîÜ?ı¦êóéÄ£¨ÖÇ£º?áê???ïÈîÜ×âë¦£©¡£
		gracefulDisconnectTimeout ÷¼Ó­îÜ?Ê¦ÒöÜôÒöÓğ?¡£

		\~japanese
		«µ?«Ğ?ªÈªÎïÈ?ªòú°ğ¶ª·ªŞª¹¡£ªÁªÊªßªË¡¢ª¹ªÙªÆªÎP2P«°«ë?«×ª«ªéªâ?÷Üª·ªŞª¹¡£
		\param gracefulDisconnectTimeout «µ?«Ğ?ªÈªÎïÈ?ªòú°ğ¶ª¹ªëÎ¦ïïªò?×âª¹ªëª¿ªáªË¡¢«¯«é«¤«¢«ó«ÈªÏá¶ïÒãÁÊàªÎãÁÊàªòÏ´ªáªŞª¹¡£ª³ªÎö·ªÏ«µ?«Ğ?ªÈªÎïÈ?ú°ğ¶ªŞªÇªËúÉÊ¦ª¹ªëõÌÓŞãÁÊà(õ©)ªÇª¹¡£
		ª³ªÎö·ªÏ÷×ßÈîÜªË1ì¤?ª¬îê?ªÇª¹ª¬¡¢ª¢ªŞªêªËªâá³ªµª¤ö·ªòö¢ªëíŞùê¡¢«¯«é«¤«¢«ó«ÈªÏ«µ?«Ğ?ªÈªÎïÈ?ªòğûÖõª·ªŞª·ª¿ª¬¡¢«µ?«Ğ?ö°ªÇ«¯«é«¤«¢«ó«ÈªÎïÈ?ú°ğ¶ªòòÁªÁªËÊïò±ªÇª­ªÊª¤íŞùêª¬ª¢ªêÔğªŞª¹¡£
		\param comment ª³ª³ªËìıªìª¿«Ç?«¿ªÏ¡¢INetServerEvent.OnClientLeaveªèªêáôª±ö¢ªéªìªŞª¹¡£
		?ªÁ¡¢«¯«é«¤«¢«ó«Èª¬«µ?«Ğ?ªÈªÎïÈ?ªòú°ğ¶ª·ªŞª¹ª¬¡¢«µ?«Ğ?ªËõÌı­ªË«Ç?«¿ªòáêªêª¿ª¤ãÁ(ÖÇ£ºïÈ?ªòï·ªë×âë¦ªòáêªë)êóéÄªÇª¹¡£
		gracefulDisconnectTimeoutª¬ª¢ªŞªêªËªâÓ­ª¤ªÈ?ª«ªÊª¤íŞùêª¬ª¢ªêªŞª¹¡£ 

		\~
		*/
		virtual void Disconnect(const CDisconnectArgs &args) = 0;

		/**
		\~korean
		¼­¹ö¿ÍÀÇ ¿¬°áÀ» ÇØÁ¦ÇÑ´Ù. ¾Æ¿ï·¯ ¸ğµç P2P ±×·ì¿¡¼­µµ Å»ÅğÇÑ´Ù.
		UE4/PS4 ¿Í °°ÀÌ »ç¿ëÀÚ ´Ü¿¡¼­ try/catch ¸¦ »ç¿ë ÇÒ ¼ö ¾ø´Â È¯°æ¿¡¼­, ¿¡·¯ ¸Ş¼¼Áö¸¦ Åëº¸ ¹ŞÀ» ¶§ »ç¿ë ÇÏµµ·Ï ÇÑ´Ù.
		- ÀÚ¼¼ÇÑ °ÍÀº µ¿¸í ¸Ş¼­µå ÂüÁ¶

		\~english
		It disconnects the connection to the server. Additionally, it withdraws from all P2P groups. 
		In an environment where try/catch cannot be used from the user side such as UE4/PS4, it shall be used when an error message is notified. 
		- For details, refer to the method with the same name. 

		\~chinese
		ú°ğ¶?Ü×?ĞïîÜ?ïÈ¡£ÔÒ??á¶êóP2P?÷Üõó¡£
		ßÀUE4/PS4??ÜôÒöî¤ËÔ?Ó®ŞÅéÄtry/catchîÜ?ÌÑñé£¬?Ôğ??á¼ãÓ?ŞÅéÄ¡£
		- ??îÜ?é»??ğÎÔÒÙ£Û°Ûö

		\~japanese
		«µ?«Ğ?ªÈªÎïÈ?ªòú°ğ¶ª·ªŞª¹¡£ªÁªÊªßªË¡¢ª¹ªÙªÆªÎP2P«°«ë?«×ª«ªéªâ?÷Üª·ªŞª¹¡£
		UE4/PS4ªÎªèª¦ªË¡¢«æ?«¶?ö°ªÇtry/catchªòŞÅéÄªÇª­ªÊª¤ü»ÌÑªÇ¡¢«¨«é?«á«Ã«»?«¸ªò÷×ÜÃª·ªÆªâªéª¦ãÁªËŞÅª¦ªèª¦ªËª·ªŞª¹¡£
		- ßÙª·ª¤ª³ªÈªÏÔÒÙ£ªÎ«á«½«Ã«Éªò?ğÎª·ªÆª¯ªÀªµª¤¡£

		\~
		*/
		virtual void Disconnect(ErrorInfoPtr& outError) = 0;

		/**
		\~korean
		¼­¹ö¿ÍÀÇ ¿¬°áÀ» ÇØÁ¦ÇÑ´Ù. ¾Æ¿ï·¯ ¸ğµç P2P ±×·ì¿¡¼­µµ Å»ÅğÇÑ´Ù.
		UE4/PS4 ¿Í °°ÀÌ »ç¿ëÀÚ ´Ü¿¡¼­ try/catch ¸¦ »ç¿ë ÇÒ ¼ö ¾ø´Â È¯°æ¿¡¼­, ¿¡·¯ ¸Ş¼¼Áö¸¦ Åëº¸ ¹ŞÀ» ¶§ »ç¿ë ÇÏµµ·Ï ÇÑ´Ù.
		- ÀÚ¼¼ÇÑ °ÍÀº µ¿¸í ¸Ş¼­µå ÂüÁ¶

		\~english
		It disconnects the connection to the server. Additionally, it withdraws from all P2P groups. 
		In an environment where try/catch cannot be used from the user side such as UE4/PS4, it shall be used when an error message is notified. 
		- For details, refer to the method with the same name. 

		\~chinese
		ú°ğ¶?Ü×?ĞïîÜ?ïÈ¡£ÔÒ??á¶êóP2P?÷Üõó¡£
		ßÀUE4/PS4??ÜôÒöî¤ËÔ?Ó®ŞÅéÄtry/catchîÜ?ÌÑñé£¬?Ôğ??á¼ãÓ?ŞÅéÄ¡£
		- ??îÜ?é»??ğÎÔÒÙ£Û°Ûö

		\~japanese
		«µ?«Ğ?ªÈªÎïÈ?ªòú°ğ¶ª·ªŞª¹¡£ªÁªÊªßªË¡¢ª¹ªÙªÆªÎP2P«°«ë?«×ª«ªéªâ?÷Üª·ªŞª¹¡£
		UE4/PS4ªÎªèª¦ªË«æ?«¶?ö°ªÇtry/catchªòŞÅéÄªÇª­ªÊª¤ü»ÌÑªÇ¡¢«¨«é?«á«Ã«»?«¸ªò÷×ÜÃª·ªÆªâªéªÃª¿ãÁªËŞÅª¦ªèª¦ªËª·ªŞª¹¡£
		- ßÙª·ª¯ªÏÔÒÙ£«á«½«Ã«Éªòª´?ğÎª¯ªÀªµª¤¡£

		\~
		*/
		virtual void Disconnect(const CDisconnectArgs &args, ErrorInfoPtr& outError) = 0;

		// Added for emergency use if Disconnect() never returns though it has automatic non-wait functionality.
		virtual void DisconnectAsync(const CDisconnectArgs &args) = 0;

		/**
		\~korean
		[µğ¹ö±ë¿ë] ÀüÃ¼ P2P ±×·ìÀÇ »óÅÂ¸¦ ´ıÇÁ·Î ³²±ä´Ù.

		\~english
		[Debugging] Leaves the status of entire P2P group as a dump

		\~chinese
		[??éÄ] ÷êîïİ»P2P?îÜ??×º???¡£

		\~japanese
		[«Ç«Ğ«Ã«®«ó«°éÄ]îï?P2P«°«ë?«×ªÎ?÷¾ªò«À«ó«×ªÇ?ª·ªŞª¹¡£
		\~
		*/
		//virtual String DumpStatus() = 0;

		/**
		\~korean
		¼ö½ÅµÈ RMI³ª ÀÌº¥Æ®¸¦ Ã³¸®ÇÕ´Ï´Ù.
		°¡Àå ¸¶Áö¸·¿¡ FrameMoveÀ» È£ÃâÇÑ ÀÌÈÄºÎÅÍ Áö±İ±îÁö ¼­¹ö·ÎºÎÅÍ ¼ö½ÅµÈ RMI³ª INetClientEventÀÇ Äİ¹é ÀÌº¥Æ®´Â Å¬¶óÀÌ¾ğÆ® ¸Ş¸ğ¸®¿¡ ´©ÀûµÇ¾î ÀÖ½À´Ï´Ù.
		±×¸®°í ±×°ÍµéÀ» ÀÌ ¸Ş¼­µå¿¡ ÀÇÇØ ÀÏÁ¦È÷ Äİ¹éÀÌ ¹ß»ıÇÏ°Ô ÇÕ´Ï´Ù.
		- »ç¿ëÀÚ´Â ÀÏÁ¤ ½Ã°£¸¶´Ù ÀÌ¸¦ È£ÃâÇØ¼­ RMI ¼ö½Å Ã³¸® ¹× ¹ß»ı ÀÌº¥Æ®¸¦ Ã³¸®ÇÏµµ·Ï ÇØ¾ß ÇÕ´Ï´Ù. ÀÏ¹İÀûÀÎ °æ¿ì »ç¿ëÀÚ´Â ÀÌ ¸Ş¼­µå¸¦ ¸Å ·»´õ ÇÁ·¹ÀÓ¸¶´Ù È£ÃâÇÕ´Ï´Ù.
		- ÀÌ ¸Ş¼­µå¸¦ Àå½Ã°£ È£Ãâ ¾ÈÇÑ´Ù°í ÇØ¼­ Å¸ È£½ºÆ®³ª ¼­¹ö¿ÍÀÇ ¿¬°áÀÌ ²÷¾îÁö´Â ÀÏÀº ¾ø½À´Ï´Ù.

		\param maxWaitTimeMs Ã³¸®ÇÒ ÀÌº¥Æ®³ª ¼ö½Å ¸Ş½ÃÁö°¡ ÀÖÀ» ¶§±îÁö, ¾ó¸¶³ª ¿À·¡ ±â´Ù¸± °ÍÀÎÁö¿¡ ´ëÇÑ °ªÀÔ´Ï´Ù. 0ÀÌ¸é ±â´Ù¸®Áö ¾Ê°í Áï½Ã ¸®ÅÏÇÕ´Ï´Ù.
		°ÔÀÓ µî ·»´õ¸µ ·çÇÁ ¾È¿¡¼­´Â 0ÀÌ ÀÏ¹İÀûÀÌ¸ç, ·»´õ¸µ ·çÇÁ°¡ ¾ø´Â ÀÏ¹İ ¾Û¿¡¼­´Â Àû´çÇÑ °ª (°¡·É 200ms)¸¦ ³Ö½À´Ï´Ù.
		\param outResult FrameMove È£Ãâ½Ã Ã³¸® °á°ú º¸°í¸¦ ¾ò½À´Ï´Ù. »ı·« °¡´ÉÇÑ ÆÄ¶ó¸ŞÅÍÀÔ´Ï´Ù.

		\~english
		Handles received RMI or event
		All of RMI from server or callbcak event of INetClientEvent occurred since the last FrameMove call are stacked within memory.
		And those let callbacks happen by this method.
		- User is to call this periodically in order to handle RMI reception process and event occurred. Usually, user calls this method at every render frame.
		- By not calling this method for a long time does not cause the connection between server or other hosts terminated.

		\param maxWaitTimeMs  It is the value of how long it will wait until there is a processed event or in-coming message,  If it is 0, do not wait and return immediately.
		0 is general in the rendering loop including game, and etc.  Put the appropriate value (for example, 200ms) in the general app without the rendering loop.
		\param outResult Gets the report to process result when FrameMove is called. Ignorable parameter.

		\~chinese
		?×ââ¥ãáîÜRMIûäíºevent¡£
		?õÌı¨û¼Ğ£FrameMove?ã·Óğ?î¤?Ü×?Ğïâ¥ãáîÜRMIûäíºINetClientEventîÜüŞ?event×«?î¤client?ğí×ì¡£
		æÔı¨××éÄó®Û°Ûöìé??ßæüŞ?¡£
		- éÄ?é©î¤ØßìéÓ«??û¼Ğ£??ú¼RMIâ¥ãá?×âĞàevent?ßæ?×â¡£ìéÚõîÜï×?ù»éÄ?÷êó®Û°Ûöî¤Øß?render frameû¼Ğ£¡£
		- Üô??ßæì×?êó???û¼Ğ£ó®Û°Ûöì»?Ğìöâñ«ÏõûäíºÜ×?ĞïîÜ?ïÈ??îÜŞÀï×¡£

		\param maxWaitTimeMs  ãÀ?é©?×âîÜüÀ?ûäíºÓğêóâ¥ãáãáãÓîÜ?ı¦?ò­,ì¤ĞàâÍé©ÔõÒı???îÜËÀÌ«¡£åıÍıãÀ 0 îÜ?,?Ø¡?Ú÷üŞ,Üô?ÔõÓâ¡£
		î¤êı?Ôõ?ğ¤Ïê×ì,0ãÀìéÚõàõîÜ, î¤?êó?ğ¤ÏêîÜ?éÄ?Ëì×ì,Û¯ìıÎÁ?îÜËÀÌ«(ÖÇåı200ms)¡£
		\param outResult FrameMoveû¼Ğ£??Ôğ?×â?Íı?Í±¡£Ê¦ì¤àıÕÔîÜ??¡£

		\~japanese
		áôãáªµªìª¿RMIªÈª««¤«Ù«ó«Èªò?×âª·ªŞª¹¡£
		ìéÛãõÌı­ªËFrameMoveªòû¼ªÓõóª·ª¿ı­ª«ªé¡¢ª³ªìªŞªÇ«µ?«Ğ?ªèªêáôãáª·ª¿RMIªÈª«INetClientEventªÎ«³?«ë«Ğ«Ã«¯«¤«Ù«ó«ÈªÏ«¯«é«¤«¢«ó«È«á«â«ê?ªË×«îİªµªìªÆª¤ªŞª¹¡£
		ª½ª·ªÆ¡¢ª½ªìªéªòª³ªÎ«á«½«Ã«ÉªËªèªÃªÆìé?ªË«³?«ë«Ğ«Ã«¯ª¬?ßæª¹ªëªèª¦ªËª·ªŞª¹¡£
		- «æ?«¶?ªÏá¶ïÒãÁÊàª´ªÈªËª³ªìªòû¼ªÓõóª·ªÆRMIáôãá?×âĞàªÓ?ßæ«¤«Ù«ó«Èªò?×âª¹ªëªèª¦ªËª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£ìéÚõîÜªÊíŞùê¡¢«æ?«¶?ªÏª³ªÎ«á«½«Ã«Éªò?üŞ«ì«ó«À?«ê«ó«°«Õ«ì?«àª´ªÈªËû¼ªÓõóª·ªŞª¹¡£
		- ª³ªÎ«á«½«Ã«ÉªòíşãÁÊàû¼ªÓõóªµªÊª¤ªÈª·ªÆöâªÎ«Û«¹«Èªä«µ?«Ğ?ªÈªÎïÈ?ª¬ï·ªìªëª³ªÈªÏª¢ªêªŞª»ªó¡£
		\param maxWaitTimeMs ?×âª¹ªë«¤«Ù«ó«Èªäáôãá«á«Ã«»?«¸ª¬ª¢ªëãÁªŞªÇ¡¢ªÉªìªÀª±íşª¯ÓâªÄª«ªË?ª¹ªëö·ªÇª¹¡£0ªÇª¢ªìªĞÓâª¿ªºªËòÁªÁªË«ê«¿?«óª·ªŞª¹¡£
		«²?«àªÊªÉ«ì«ó«À?«ê«ó«°«ë?«×?ªÇªÏ0ª¬ìéÚõîÜªÇ¡¢«ì«ó«À?«ê«ó«°«ë?«×ª¬ªÊª¤ìéÚõ«¢«×«êªÇªÏîê?ªÊö·(?ªË200ms)ªòìıªìªŞª¹¡£
		\param outResult FrameMove û¼ªÓõóª·ãÁªË?×âÌ¿ÍıªÎÜÃÍ±ªòÔğªŞª¹¡£àıÕÔÊ¦ÒöªÊ«Ñ«é«á?«¿?ªÇª¹¡£ 


		\param maxWaitTimeMs  ?×âª¹ªë«¤«Ù«ó«Èªäáôãá«á«Ã«»?«¸ª¬ª¢ªëªŞªÇ¡¢ªÉªìªÛªÉíşª¯ÓâªÄªÎª«ªËªÄª¤ª¿ö·ªÇª¹¡£0ªËªÏÓâª¿ªºªËòÁªÁªË«ê«¿?«óª·ªŞª¹¡£
		«²?«àªÊªÉ«ì«ó«À«ê«ó«°«ë?«×ªÎñéªÇªÏ0ª¬ìéÚõîÜªÇª¢ªê¡¢«ì«ó«À«ê«ó«°«ë?«×ª¬ªÊª¤ìéÚõ«¢«×«êªÇªÏîê?ªÊö·(ÖÇª¨ªĞ¡¢200ms)ªòìıªìªŞª¹¡£

		\~
		*/
		virtual void FrameMove(int maxWaitTime = 0, CFrameMoveResult* outResult = NULL) = 0;
		/** No-throw function. Exception is stored to outError. Used for UE4, etc. */
		virtual void FrameMove(int maxWaitTime, CFrameMoveResult* outResult, ErrorInfoPtr& outError) = 0;

		/**
		\~korean
		ÀÌ client°¡ Âü¿©ÇÏ°í ÀÖ´Â P2P group Áß ÇÏ³ªÀÎ groupHostID¿¡ Âü¿©ÇÏ°í ÀÖ´Â
		´Ù¸¥ peerµéÀÇ HostID list¸¦ ¾ò´Â´Ù.

		\~english
		Gets the HostID list of other peers participating groupHostID that is one of P2P groups that this client is participating

		\~chinese
		?Ôğ??ó®client??îÜP2P groupñéñıìégroupHost IDîÜĞìöâpeer HostID list¡£

		\~japanese
		ª³ªÎ«¯«é«¤«¢«ó«Èª¬?Ê¥ª·ªÆª¤ªëP2P«°«ë?«×ªÎìéªÄªÇª¢ªëgroupHostIDªË?Ê¥ª·ªÆª¤ªëöâªÎPeerªÎHostID listªòÔğªŞª¹¡£
		\~
		*/
		virtual void GetGroupMembers(HostID groupHostID, HostIDArray &output) = 0;

		/**
		\~korean
		´Ù¸¥ peer¿¡¼­ °¡Áö°í ÀÖÀ» ¼­¹ö ½Ã°£À» ±¸ÇÑ´Ù.

		\~english
		Gets the server time that other peer has

		\~chinese
		Ï´Ğìöâpeer??êóîÜÜ×?Ğï??¡£

		\~japanese
		öâªÎPeerª¬ò¥ªÃªÆª¤ªë«µ?«Ğ?ãÁÊàªòÏ´ªáªŞª¹¡£
		\~
		*/
		virtual int64_t GetIndirectServerTimeMs(HostID peerHostID) = 0;

		/**
		\~korean
		ÀÌ È£½ºÆ®ÀÇ local HostID¸¦ ±¸ÇÑ´Ù. HostID_NoneÀÌ¸é ¼­¹ö¿¡ ¿¬°á ¾ÈµÆ´Ù´Â ¶æ.

		\~english
		Gets local HostID of this host. If HostID_None then means not connected to server

		\~chinese
		Ï´ó®ñ«ÏõîÜlocal Host ID¡£HostID_None îÜ?øúãÆ?êó?Ü×?Ğï?ïÈ¡£

		\~japanese
		ª³ªÎ«Û«¹«ÈªÎlocal HostIDªòÏ´ªáªŞª¹¡£HostID_NoneªÇª¢ªìªĞ«µ?«Ğ?ªËïÈ?ªµªìªÊª«ªÃª¿ªÈª¤ª¦ëòÚ«¡£
		\~
		*/
		virtual HostID GetLocalHostID() = 0;

		/**
		\~korean
		ÀÌ Å¬¶óÀÌ¾ğÆ®°¡ ¼ÓÇÑ ³×Æ®¿öÅ©¿¡ ÀÛµ¿ÁßÀÎ ÀÎÅÍ³İ °øÀ¯±â ÀåÄ¡(NAT device)ÀÇ
		ÀÌ¸§À» ¾ò´Â´Ù.

		\~english
		Gets the name of Internet router device(NAT device) that is active at the network that this client is participating.

		\~chinese
		?ó®clientá¶?îÜ???Ôğ??ñéîÜû»??ÖØë¦Ğï?öÇ£¨NAT device£©îÜÙ£í®¡£

		\~japanese
		ª³ªÎ«¯«é«¤«¢«ó«Èª¬?ª·ª¿«Í«Ã«È«ï?«¯ªËíÂÔÑñéªÎ«¤«ó«¿?«Í«Ã«È«ë?«¿?(NAT device)ªÎÙ£îñªòÔğªŞª¹¡£
		\~
		*/
		virtual String GetNatDeviceName() = 0;

		/**
		\~korean
		ÀÌ È£½ºÆ®°¡ °¡ÀÔÇÑ ¸ğµç P2P ±×·ì ¸®½ºÆ®¸¦ ¾ò´Â´Ù.

		\~english
		Gets the entire P2P group list that this host is participating

		\~chinese
		?Ôğó®ñ«ÏõÊ¥ìıîÜá¶êóP2P?Öªøú¡£

		\~japanese
		ª³ªÎ«Û«¹«Èª¬Ê¥ìıª·ª¿îïªÆªÎP2P«°«ë?«×«ê«¹«ÈªòÔğªŞª¹¡£
		\~
		*/
		virtual void GetLocalJoinedP2PGroups(HostIDArray &output) = 0;

		/**
		\~korean
		½ÃÀÛ ÀÌ·¡ ¼öÁıµÈ Ã³¸®·® Åë°è¸¦ ¾ò´Â´Ù.

		\~english
		Gets the statistics of process collected since beginning

		\~chinese
		?Ôğ?ã·ëî?â¥ó¢îÜ?×âÕá??¡£

		\~japanese
		ËÒã·ì¤?ªË?ó¢ªµªìª¿?×âÕáªÎ÷ÖÍªªòÔğªŞª¹¡£
		\~
		*/
		virtual void GetStats(CNetClientStats &outVal) = 0;

		/**
		\~korean
		P2P groupÀÇ ¼­¹ö ½Ã°£À» ¾ò´Â´Ù.
		ÀÌ´Â groupHostID°¡ °¡¸®Å°´Â P2P groupÀÇ ¸ğµç GetIndirectServerTime()°ªÀÇ Æò±ÕÀÌ´Ù.

		\~english
		Gets server time of P2P group
		This is an average value of all GetIndirectServerTime() values within the P2P group that groupHostID points.

		\~chinese
		?ÔğP2P groupîÜÜ×?Ğï??¡£
		?ãÀgroupHostIDá¶ò¦îÜP2P groupîÜá¶êóGetIndirectServerTime()?îÜøÁĞ³¡£

		\~japanese
		P2P«°«ë?«×ªÎ«µ?«Ğ?ãÁÊàªòÔğªŞª¹¡£
		ª³ªìªÏgroupHostIDª¬ò¦ª¹P2P«°«ë?«×ªÎîïªÆªÎGetIndirectServerTime()ö·ªÎøÁĞ³ªÇª¹¡£

		\~
		*/
		virtual int64_t GetP2PServerTimeMs(HostID groupHostID) = 0;

		/**
		\~korean
		ÀÌ È£½ºÆ®°¡ Å¸ Peer¿ÍÀÇ Åë½ÅÀ» À§ÇØ ³»ºÎÀûÀ¸·Î °®°í ÀÖ´Â UDP socketÀÇ ·ÎÄÃ ÁÖ¼Ò¸¦ ¾ò´Â´Ù.
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#use_alternative_p2p" >ProudNetÀ» ¾²Áö ¾Ê°í ProudNetÀÇ È¦ÆİÄª Á¤º¸¸¦ Åä´ë·Î º°µµ UDP ¼ÒÄÏÀ¸·Î Åë½ÅÇÏ±â</a>  ¿¡¼­ »ç¿ëµÇ±âµµ ÇÑ´Ù.

		\param remotePeerID ÀÌ È£½ºÆ®¿Í P2P Åë½ÅÀ» ÇÏ°í ÀÖ´Â Å¸ PeerÀÇ HostID.
		\return CNetClient ³»ºÎ¿¡¼­ º¸À¯ÇÏ°í ÀÖ´Â UDP socketÀÇ Æ÷Æ®¹øÈ£ ¶Ç´Â (ÁÖ¼Ò,Æ÷Æ®¹øÈ£). »ç¿ëÀÚ´Â ¿©±â¼­ Æ÷Æ® ¹øÈ£¸¦ °¡Á®´Ù ¾²¸é µÈ´Ù.
		- P2P ±×·ì¿¡ »ó´ëÃø peer°¡ µé¾î¿ÂÁö ¾ó¸¶ ¾ÈµÈ °æ¿ì ÀÌ °ªÀº AddrPort.UnassignedÀÏ ¼ö ÀÖ´Ù. ¿Ö³ÄÇÏ¸é ProudNetÀº ¼º´É Çâ»óÀ» À§ÇØ
		UDP socketÀ» Áï½Ã ¸¸µéÁö ¾Ê±â ¶§¹®ÀÌ´Ù. µû¶ó¼­ ÀÌ·¯ÇÑ °æ¿ì Àá½Ã µÚ¿¡ ´Ù½Ã ÀÌ ¸Ş¼­µå¸¦ È£ÃâÇØ¼­ ¾òÀ» ¼ö ÀÖ´Ù.

		\~english
		Gets the local address of UDP socket that this host has internally for communicating with other peer
		- Also used in <a target="_blank" href="http://guide.nettention.com/cpp_en#use_alternative_p2p" >Communicating with a separated UDP socket based on ProudNet hole-punched information without using ProudNet.</a>

		\param remotePeerID HostID of other peer that P2P communicates with this host
		\return CNetClient Port number or (address, port number) of UDP socket that is possessed internally. User can use this as port number.
		- This value can be AddrPort.Unassigned when the opponent peer entered P2P group recently.
		This is because ProudNet does not create UDP socket immediately for performance reason. So, if this happens then you must call this method again some moments later.

		\~chinese
		?Ôğó®ñ«Ïõ?Öõ?ĞìöâpeerîÜ÷×ãá£¬?İ»UDP socketîÜÜâò¢ò¢ò£¡£
		-  å¥î¤<a target="_blank" href="http://guide.nettention.com/cpp_zh#use_alternative_p2p" >ÜôŞÅéÄProudNet£¬ñşĞñéÍProudNetîÜöèÔ×ï×?éÄ?èâîÜUDPSocket?ú¼÷×ãá</a>%ŞÅéÄ¡£

		\param remotePeerID ó®ñ«ÏõûúP2P?ú¼÷×ãáîÜĞìöâpeerîÜHost ID¡£
		\return CNetClient%?İ»ÜÁ×ºîÜUDP socketîÜÓ®Ï¢??ûäíº£¨ò¢ò£Ó®Ï¢??£©éÄ???×ìÑÚÓ®Ï¢???Ê¦¡£
		- èÙP2P??Û°peer?ìı?êóÒıá´??îÜ?ı¦ó®?Ê¦ÒöãÀ AddrPort.Unassigned%¡£ì×?ProudNet?ÖõàõÒöğ«ÍÔÜô?Ø¡??ËïUDP socket¡£á¶ì¤??îÜï×?ù»Ê¦ì¤õªı¨î¢û¼Ğ£ó®Û°Ûö?Ôğ¡£

		\~japanese
		ª³ªÎ«Û«¹«Èª¬öâªÎPeerªÈªÎ÷×ãáªÎª¿ªáªË?İ»îÜªËò¥ªÃªÆª¤ªëUDP«½«±«Ã«ÈªÎ«í?«««ë«¢«É«ì«¹ªòÔğªŞª¹¡£
		- \ref use_alternative_p2pªÇŞÅªïªìªëª³ªÈªâª¢ªêªŞª¹¡£ 
		\param remotePeerID ª³ªÎ«Û«¹«ÈªÈP2P÷×ãáªòª·ªÆª¤ªëöâªÎPeerªÎHostID.
		\return CNetClient ?İ»ªÇÜÁêóª·ªÆª¤ªëUDP«½«±«Ã«ÈªÎ«İ?«ÈÛã?ªŞª¿ªÏ(«¢«É«ì«¹¡¢«İ?«ÈÛã?)¡£«æ?«¶?ªÏª³ª³ªÇ«İ?«ÈÛã?ªòö¢ªê?ªóªÇŞÅª¨ªĞÕŞª¤ªÇª¹¡£
		- P2P«°«ë?«×ªËßÓâ¢ö°ªÎPeerª¬ìıªÃªÆÊàªâªÊª¤íŞùê¡¢ª³ªÎö·ªÏAddrPort.UnassignedªÇª¢ªëª³ªÈªâª¢ªêªŞª¹¡£ªÊª¼ªÊªé¡¢ProudNetªÏàõÒöú¾ß¾ªÎª¿ªáªËUDP«½«±«Ã«ÈªòòÁªÁªËíÂªéªÊª¤ª«ªéªÇª¹¡£ªèªÃªÆ¡¢ª³ªÎªèª¦ªÊíŞùê¡¢ª·ªĞªéª¯ı­ªÇî¢ªÓª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª·ªÆÔğªëª³ªÈª¬ªÇª­ªŞª¹¡£

		\~
		*/
		virtual AddrPort GetLocalUdpSocketAddr(HostID remotePeerID) = 0;

		/**
		\~korean
		ÀÌ È£½ºÆ®°¡ remotePeerID°¡ °¡¸®Å°´Â Å¸ Peer¿ÍÀÇ Åë½ÅÀ» À§ÇØ È¦ÆİÄªµÈ Á¤º¸¸¦ ¾ò´Â´Ù.
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#use_alternative_p2p" >ProudNetÀ» ¾²Áö ¾Ê°í ProudNetÀÇ È¦ÆİÄª Á¤º¸¸¦ Åä´ë·Î º°µµ UDP ¼ÒÄÏÀ¸·Î Åë½ÅÇÏ±â</a>  ¿¡¼­ »ç¿ëµÇ±âµµ ÇÑ´Ù.

		\param remotePeerID Å¸ ÇÇ¾îÀÇ ID
		\param outInfo Å¸ ÇÇ¾î¿ÍÀÇ Åë½ÅÀ» À§ÇÑ È¦ÆİÄª Á¤º¸°¡ Ã¤¿öÁú °÷
		\return È¦ÆİÄªµÈ PeerÀÎ °æ¿ì true, ±× ¿ÜÀÇ °æ¿ì false¸¦ ¸®ÅÏÇÑ´Ù. ¸¸¾à false¸¦ ¸®ÅÏÇÑ °æ¿ì ¾ÆÁ÷ È¦ÆİÄªµÇÁö ¾ÊÀº peerÀÎ °æ¿ì¿¡´Â 0.3~1ÃÊ °£°İÀ¸·Î
		ÀÌ ¸Ş¼­µå¸¦ Áö¼ÓÀûÀ¸·Î È£ÃâÇÏ´Ù º¸¸é true¸¦ ¸®ÅÏÇÒ ¶§°¡ ÀÖ´Ù. ¿Ö³ÄÇÏ¸é È¦ÆİÄªÀÌ ¼º»çµÇ´Â ½Ã°£ÀÌ Ç×»ó ´Ù¸£±â ¶§¹®ÀÌ´Ù.

		\~english
		Gets the hole-punched information for this host to communicate with other peer that remotePeerID points
		- Also used in <a target="_blank" href="http://guide.nettention.com/cpp_en#use_alternative_p2p" >Communicating with a separated UDP socket based on ProudNet hole-punched information without using ProudNet.</a>

		\param remotePeerID ID of other peer
		\param outInfo where the hole-punching information for communicating with other peer to be filled
		\return True if hole-punched peer, otherwise returns false.
		For the peer that is not hole-punched yet, there are some occasions that it returns true when calling this method in every 0.3 ~ 1 seconds.
		This happens since the moment when hole-punching is completed differs all the time.
		\~chinese
		ó®ñ«Ïõ?Öõ?remotePeerIDá¶ò¦îÜĞìöâpeerîÜ÷×ãá?ÔğöèÔ×ãáãÓ¡£
		- å¥î¤<a target="_blank" href="http://guide.nettention.com/cpp_zh#use_alternative_p2p" >ÜôŞÅéÄProudNet£¬ñşĞñéÍProudNetîÜöèÔ×ï×?éÄ?èâîÜUDPSocket?ú¼÷×ãá</a>%ŞÅéÄ¡£

		\param remotePeerID ĞìöâpeerîÜID¡£
		\param outInfo ?Öõ?ĞìöâpeerîÜ÷×ãáîÜöèÔ×ãáãÓé©ù¬?õöîÜò¢Û°¡£
		\return öèÔ×îÜpeerîÜ?true£¬ñıèâîÜï×?Ú÷üŞfalse¡£åıÍıÚ÷üŞfalseîÜ?£¬??êóöèÔ×îÜpeerîÜï×?ãÀì¤0.3~1?Ì°£¬ò¥?û¼Ğ£ó®Û°ÛöîÜ?êóÚ÷üŞtrueîÜ?ı¦¡£ì×?öèÔ×à÷ÍíîÜ???ãÀÜôÔÒ¡£

		\~japanese
		ª³ªÎ«Û«¹«Èª¬remotePeerIDª¬ò¦ª¹öâªÎPeerªÈªÎ÷×ãáªÎª¿ªáªË«Û?«ë«Ñ«ó«Á«ó«°ªµªìª¿ï×ÜÃªòÔğªŞª¹¡£
		- \ref use_alternative_p2pªÇŞÅªïªìªëª³ªÈªâª¢ªêªŞª¹¡£ 		
		\param remotePeerID öâªÎPeerªÎID
		\param outInfo öâªÎPeerªÈªÎ÷×ãáªÎª¿ªáªÎ«Û?«ë«Ñ«ó«Á«ó«°ï×ÜÃª¬?ª¿ªµªìªëá¶
		\return «Û?«ë«Ñ«ó«Á«ó«°ªµªìª¿PeerªÎíŞùêªÏtrue¡¢ª½ªÎöâªÎíŞùêªÏfalseªò«ê«¿?«óª·ªŞª¹¡£ªâª·¡¢falseªò«ê«¿?«óª·ª¿íŞùê¡¢ªŞªÀ«Û?«ë«Ñ«ó«Á«ó«°ªµªìªÆªÊª¤peerªÎíŞùêªÏ0.3~1õ©ªÎÊàÌ°ªÇª³ªÎ«á«½«Ã«Éªòò¥?îÜªËû¼ªÓõóª·ªÊª¬ªéÌ¸ªëªÈ¡¢trueªò«ê«¿?«óª¹ªëãÁª¬ª¢ªêªŞª¹¡£ªÊª¼ªÊªé¡¢«Û?«ë«Ñ«ó«Á«ó«°ªËà÷Ííª¹ªëãÁÊàªÏª¤ªÄªâêŞª¦ª«ªéªÇª¹¡£ 

		\~
		*/
		virtual bool GetDirectP2PInfo(HostID remotePeerID, CDirectP2PInfo &outInfo) = 0;

		/**
		\~korean
		¿¬°áµÈ ¼­¹öÀÇ ÁÖ¼Ò¸¦ ±¸ÇÑ´Ù.

		\~english
		Gets the address of connected server

		\~chinese
		Ï´?ïÈîÜÜ×?Ğïò¢ò£¡£

		\~japanese
		ïÈ?ªµªìª¿«µ?«Ğ?ªÎ«¢«É«ì«¹ªòÏ´ªáªŞª¹¡£
		\~
		*/
		virtual AddrPort GetServerAddrPort() = 0;

		/**
		\~korean
		ÀÌ °´Ã¼¿¡ ¿¬°áµÈ peer 1°³ÀÇ Á¤º¸¸¦ ¾ò´Â´Ù.
		\param peerHostID Ã£À¸·Á´Â peerÀÇ HostID
		\param output Ã£Àº peerÀÇ Á¤º¸. ¸ø Ã£À¸¸é ¾Æ¹«°Íµµ Ã¤¿öÁöÁö ¾Ê´Â´Ù.
		\return trueÀÌ¸é Ã£¾Ò´Ù´Â ¶æ

		\~english
		Gets the information of 1 peer connected to this object
		\param peerHostID HostID of peer to find
		\param output the information of peer found. Nothing will be filled when found nothing.
		\return True means found

		\~chinese
		?Ôğ?ïÈó®?ßÚîÜìé?peerãáãÓ¡£
		\param peerHostID é©?îÜpeerîÜHostID¡£
		\param output ?ÓğîÜpeerîÜãáãÓ¡£?êó?ÓğîÜ?Üô?õöìòù¼?à¤¡£
		\return trueîÜ?ãÀ?ÓğîÜëòŞÖ¡£

		\~japanese
		ª³ªÎ«ª«Ö«¸«§«¯«ÈªËªÄªÊª¬ªÃª¿Peer 1ËÁªÎï×ÜÃªòÔğªŞª¹¡£
		\param peerHostID ÷®ª·ª¿ª¤peerªÎHostID
		\param output ÷®ª·ª¿peerªÎï×ÜÃ¡£÷®ª¹ª³ªÈª¬ªÇª­ªÊª«ªÃª¿ªéù¼ªâ?ª¿ªµªìªŞª»ªó¡£
		\return trueªÇª¢ªìªĞ÷®ª·ª¿ªÈª¤ª¦ëòÚ«

		\~
		*/
		virtual bool GetPeerInfo(HostID peerHostID, CNetPeerInfo& output) = 0;

		/**
		\~korean
		ÀÌ È£½ºÆ®¿¡ ¿¬°áµÈ ´Ù¸¥ È£½ºÆ®(¼­¹öÀÇ °æ¿ì Å¬¶óÀÌ¾ğÆ®µé, Å¬¶óÀÌ¾ğÆ®ÀÇ °æ¿ì ÇÇ¾îµé)µé °¢°¢¿¡ÀÇ tag¸¦ ÁöÁ¤ÇÕ´Ï´Ù. <a target="_blank" href="http://guide.nettention.com/cpp_ko#host_tag" >°¢ È£½ºÆ®¿¡ ´ëÇÑ »ç¿ëÀÚ Á¤ÀÇ µ¥ÀÌÅÍ(Tag)</a> ±â´ÉÀÔ´Ï´Ù.
		- ÀÚ±â ÀÚ½Å(¼­¹ö È¤Àº Å¬¶óÀÌ¾ğÆ®)¿¡ ´ëÇÑ tagµµ ÁöÁ¤ÇÒ ¼ö ÀÖ½À´Ï´Ù.

		\~english
		Desigantes tag to each of other hosts(client for server, peer for client) aht are connected to this host. A <a target="_blank" href="http://guide.nettention.com/cpp_en#host_tag" >User-defined data(Tag) for each host</a> function.
		- Can designate tag to itself (server or client)

		\~chinese
		??ïÈó®ñ«ÏõîÜĞìöâñ«Ïõ£¨Ü×?ĞïîÜ?client£¬client îÜ?peer£©ò¦ïÒtag¡£<a target="_blank" href="http://guide.nettention.com/cpp_zh#host_tag" >?ÊÀ?ñ«ÏõîÜéÄ?ïÒ??Ëß£¨Tag£©</a> %ÍíÒö¡£
		- å¥Ê¦ì¤?í»ĞùÜâãó£¨Ü×?Ğïûäíºclient£©ò¦ïÒtag¡£

		\~japanese
		ª³ªÎ«Û«¹«ÈªËªÄªÊª¬ªÃª¿öâªÎ«Û«¹«È(«µ?«Ğ?ªÎíŞùêªÏ«¯«é«¤«¢«ó«È¡¢«¯«é«¤«¢«ó«ÈªÎíŞùêªÏ«Ô?«¢)ªÎª½ªìª¾ªìªËtagªòò¦ïÒª·ªŞª¹¡£\ref host_tag Ñ¦ÒöªÇª¹¡£
		- í»Ğùí»ãó(«µ?«Ğ?ªŞª¿ªÏ«¯«é«¤«¢«ó«È)ªË?ª¹ªëtagªâò¦ïÒª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£ 

		\~
		*/
		virtual bool SetHostTag(HostID hostID, void* hostTag) = 0;

		/**
		\~korean
		¼­¹öÀÇ ÇöÀç ½Ã°£À» ±¸ÇÑ´Ù. (ÃÊ ´ÜÀ§)
		ÀÌ °ªÀº ÀÏÁ¤ ½Ã°£¸¶´Ù ·¹ÀÌÅÏ½Ãµµ °í·ÁµÇ¾î °è»êµÇ´Â ¼­¹öÀÇ ½Ã°£ÀÌ´Ù.

		\~english
		Gets current time of server (in second)
		This value is the server time that considered periodic latency

		\~chinese
		Ï´Ü×?ĞïîÜ?î¤??£¨õ©?êÈ£©¡£
		ó®?ãÀØßÌ°ìéÓ«??ÍÅ?latencyì»?ß©îÜÜ×?Ğï??¡£

		\~japanese
		«µ?«Ğ?ªÎúŞî¤ãÁÊàªòÏ´ªáªŞª¹¡£(õ©?êÈ)
		ª³ªÎö·ªÏá¶ïÒãÁÊàª´ªÈªË«ì?«Æ«ó«·?ªâÍÅÕçªµªìªÆÍªß©ªµªìªë«µ?«Ğ?ªÎãÁÊàªÇª¹¡£

		\~
		*/
		virtual int64_t GetServerTimeMs() = 0;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®¿Í ¼­¹ö¿ÍÀÇ ½Ã°£ Â÷¸¦ ±¸ÇÑ´Ù.

		\~english
		Gets the time difference between client and server

		\~chinese
		Ï´client?Ü×?ĞïîÜ??ó¬¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªÈ«µ?«Ğ?ªÈªÎãÁÊàó¬ªòÏ´ªáªŞª¹¡£
		\~
		*/
		virtual int64_t GetServerTimeDiffMs() = 0;

		/**
		\~korean
		¼­¹ö¿ÍÀÇ ¼ÒÄÏ ¿¬°á »óÅÂ¸¦ ¸®ÅÏÇÕ´Ï´Ù.
		- ¼ÒÄÏÀÇ ¿¬°á »óÅÂ¸¸ ¸®ÅÏÇÕ´Ï´Ù. ¿ÏÀüÈ÷ ¿¬°áµÇ¾ú´ÂÁö´Â OnJoinServerComplete·Î Äİ¹éµË´Ï´Ù.
		\param output ¼­¹ö¿ÍÀÇ ¿¬°á »óÅÂ°¡ Ã¤¿öÁö´Â °ø°£
		\return ¼­¹ö¿ÍÀÇ ¿¬°á »óÅÂ

		\~english
		Returns connection status to server
		\param output where the status is filled
		\return connection status to server

		\~chinese
		Ú÷üŞÜ×?Ğïûúsocket?ïÈ??¡£
		- ?Ú÷üŞsocket?ïÈ??¡£ãÀÜúèÇîï?ïÈéÄOnJoinServerCompleteüŞ?¡£
		\param output ?õö?Ü×?ĞïîÜ?ïÈ??îÜÍö?¡£
		\return ?Ü×?ĞïîÜ?ïÈ??¡£

		\~japanese
		«µ?«Ğ?ªÈªÎ«½«±«Ã«ÈïÈ??÷¾ªò«ê«¿?«óª·ªŞª¹¡£
		- «½«±«Ã«ÈªÎïÈ??÷¾ªÎªßªò«ê«¿?«óª·ªŞª¹¡£èÇîïªËªÄªÊª¬ªÃªÆª¤ªëª«ªÏOnJoinServerCompleteªË«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		\param output «µ?«Ğ?ªÈªÎïÈ??÷¾ª¬?ª¿ªµªìªëÍöÊà
		\return «µ?«Ğ?ªÈªÎïÈ??÷¾ 

		\~
		*/
		virtual ConnectionState GetServerConnectionState(CServerConnectionState &output) = 0;


		virtual void GetWorkerState(CClientWorkerInfo &output) = 0;

		/**
		\~korean
		¼­¹ö¿ÍÀÇ ¼ÒÄÏ ¿¬°á ¿©ºÎ¸¦ ¸®ÅÏÇÕ´Ï´Ù.
		- ¼­¹ö¿Í ¼ÒÄÏÀÌ ¿¬°á µÇ¾ú´ÂÁöÀÇ ¿©ºÎ¸¸ ¸®ÅÏÇÕ´Ï´Ù.

		\~english
		Return connect socket to server or not.
		- Only return connected socket to server or not.

		\~chinese
		Ú÷üŞ?Ü×?ĞïîÜsocket?ïÈ?Üú¡£
		- ñşÚ÷üŞÜ×?Ğïûúsocket?ïÈ?Üú¡£

		\~japanese
		«µ?«Ğ?ªÈªÎ«½«±«Ã«ÈïÈ?Ê¦Üúªò«ê«¿?«óª·ªŞª¹¡£
		- «µ?«Ğ?ªÈ«½«±«Ã«Èª¬ïÈ?ªµªìªÆª¤ªëª«ªÉª¦ª«ªÎªßªò«ê«¿?«óª·ªŞª¹¡£

		\~
		*/
		inline bool HasServerConnection()
		{
			CServerConnectionState stat;
			return GetServerConnectionState(stat)==ConnectionState_Connected;
		}

		/**
		\~korean
		ÀÌº¥Æ®¸¦ ¹ŞÀ» ¼ö ÀÖ´Â °´Ã¼¸¦ ¼³Á¤ÇÑ´Ù.
		- ÇÏ³ª¸¸ ¼³Á¤ °¡´ÉÇÏ´Ù.
		- ÀÌ ¸Ş¼­µå´Â Å¬¶óÀÌ¾ğÆ®°¡ ¼­¹ö¿¡ ¿¬°áÀ» ½ÃµµÇÏ±â Àü¿¡¸¸ È£ÃâÇÒ ¼ö ÀÖ´Ù. ¾È±×·¯¸é exceptionÀÌ throwµÈ´Ù.

		\~english
		Sets the object can receive event
		- Only 1 object can be set.
		- This method can only be called before client attempts to connect to server. Otherwise, an execption will be 'throw'.

		\~chinese
		?öÇÊ¦ì¤ïÈâ¥eventîÜ?ßÚ¡£
		- ñşÒö?öÇìé?¡£
		- ó®Û°ÛöñşÒöî¤client???ïÈÜ×?Ğïñıîñû¼Ğ£¡£Üú??exception ÀÌ throw¡£

		\~japanese
		«¤«Ù«ó«Èªòáôª±ªéªìªë«ª«Ö«¸«§«¯«ÈªòàâïÒª·ªŞª¹¡£
		- ìéªÄªÎªßàâïÒÊ¦ÒöªÇª¹¡£
		- ª³ªÎ«á«½«Ã«ÉªÏ«¯«é«¤«¢«ó«Èª¬«µ?«Ğ?ªËïÈ?ªòãËª¹îñªÎªßû¼ªÓõóª¹ª³ªÈª¬ªÇª­ªŞª¹¡£ª½ªìªÈªâ¡¢exceptionª¬throwªµªìªŞª¹¡£ 

		\~
		*/
		virtual void SetEventSink(INetClientEvent* eventSink) = 0;

		// rarely used for diagnostics.
		virtual INetClientEvent* GetEventSink() = 0;

	public:


		// ÁÖÀÇ: ½ÇÁ¸ °´Ã¼ÀÌ¹Ç·Î SUPPORTS_LAMBDA_EXPRESSION·Î °¨½ÎÁö ¸» °Í.

		/// See Proud.INetClientEvent.OnJoinServerComplete for details.
		LambdaBaseHolder_Param2<void, ErrorInfo*, const ByteArray&> OnJoinServerComplete;
		/// See Proud.INetClientEvent.OnLeaveServer for details.
		LambdaBaseHolder_Param1<void, ErrorInfo*> OnLeaveServer;
		/// See Proud.INetClientEvent.OnP2PMemberJoin for details.
		LambdaBaseHolder_Param4<void, HostID, HostID, int, const ByteArray &> OnP2PMemberJoin;
		/// See Proud.INetClientEvent.OnP2PMemberLeave for details.
		LambdaBaseHolder_Param3<void, HostID, HostID, int> OnP2PMemberLeave;
		/// See Proud.INetClientEvent.OnChangeP2PRelayState for details.
		LambdaBaseHolder_Param2<void, HostID, ErrorType > OnChangeP2PRelayState;
		/// See Proud.INetClientEvent.OnChangeServerUdpState for details.
		LambdaBaseHolder_Param1<void, ErrorType> OnChangeServerUdpState;
		/// See Proud.INetClientEvent.OnP2PMemberOffline for details.
		LambdaBaseHolder_Param1<void, CRemoteOfflineEventArgs &> OnP2PMemberOffline;
		/// See Proud.INetClientEvent.OnP2PMemberOnline for details.
		LambdaBaseHolder_Param1<void, CRemoteOnlineEventArgs &> OnP2PMemberOnline;
		/// See Proud.INetClientEvent.OnServerOffline for details.
		LambdaBaseHolder_Param1<void, CRemoteOfflineEventArgs &> OnServerOffline;
		/// See Proud.INetClientEvent.OnServerOnline for details.
		LambdaBaseHolder_Param1<void, CRemoteOnlineEventArgs &> OnServerOnline;
		/// See Proud.INetClientEvent.OnSynchronizeServerTime for details.
		LambdaBaseHolder_Param0<void> OnSynchronizeServerTime;


	public:
		/**
		\~korean
		Remote peerÀÇ ¸¶Áö¸· ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param remoteHostID Ã£À¸·Á´Â remote peerÀÇ HostID. HostID_Server¸¦ ÁöÁ¤ÇÏ¸é ¼­¹ö¿ÍÀÇ ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param error ¿¡·¯ ¿©ºÎ¸¦ ¸®ÅÏÇÑ´Ù. Á¤»óÀûÀÎ °æ¿ì ErrorType_Ok, PingÀ» ¾òÁö ¸øÇÑ °æ¿ì ErrorType_ValueNotExist°¡ ÀúÀåµÈ´Ù.
		\return ping timeÀ» ÃÊ´ÜÀ§·Î ¸®ÅÏÇÑ´Ù. ´Ü ¾øÀ¸¸é -1À» ¸®ÅÏÇÑ´Ù.

		\~english
		Gets the last latency of Remote peer
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in second). Returns -1 if there is none.

		\~chinese
		?Ôğremote peerîÜõÌı¨latency¡£
		\param remoteHostID é©?îÜremote peerîÜHostID¡£ò¦ïÒHostID_ServerîÜ??Ôğ?Ü×?ĞïîÜlatency¡£
		\param error Ú÷üŞ???Üú¡£åıÍıïáßÈ??ErrorType_Ok£¬åıÍı?êó?ÔğPing???ğíErrorType_ValueNotExist¡£
		\return ping÷êtimeì¤õ©?êÈÚ÷üŞ¡£?êóîÜ?Ú÷üŞ-1¡£

		\~japanese
		Remote peerªÎõÌı­ªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£
		\param remoteHostID ÷®ª½ª¦ªÈª¹ªëremote peerªÎHostID. HostID_Serverªòò¦ïÒª¹ªëªÈ«µ?«ĞªÈªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£
		\param error «¨«é?ª¬ª¢ªëª«ªÊª¤ª«ªò«ê«¿?«óª¹ªë¡£ïáßÈîÜªÊíŞùêªÏErrorType_Ok, PingªòÔğªÊª«ªÃª¿íŞùêªËªÏErrorType_ValueNotExistª¬ÜÁğíªµªìªë¡£
		\return ping timeªòõ©?êÈªÇ«ê«¿?«óª¹ªë¡£ª¿ªÀª·¡¢ ping timeª¬ö´ïÒªµªìªÆª¤ªÊª±ªìªĞ-1ªò«ê«¿?«óª¹ªë¡£

		\~
		*/
		inline double GetLastUnreliablePingSec(HostID remoteHostID, ErrorType* error = NULL)
		{
			int ret=GetLastUnreliablePingMs(remoteHostID, error);
			if(ret<0)
				return (double)ret;
			else
				return (double)(ret/1000);
		}
		/**
		\~korean
		Remote peerÀÇ ¸¶Áö¸· ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param remoteHostID Ã£À¸·Á´Â remote peerÀÇ HostID. HostID_Server¸¦ ÁöÁ¤ÇÏ¸é ¼­¹ö¿ÍÀÇ ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param error ¿¡·¯ ¿©ºÎ¸¦ ¸®ÅÏÇÑ´Ù. Á¤»óÀûÀÎ °æ¿ì ErrorType_Ok, PingÀ» ¾òÁö ¸øÇÑ °æ¿ì ErrorType_ValueNotExist°¡ ÀúÀåµÈ´Ù.
		\return ping timeÀ» ¹Ğ¸®ÃÊ´ÜÀ§·Î ¸®ÅÏÇÑ´Ù. ´Ü ¾øÀ¸¸é -1À» ¸®ÅÏÇÑ´Ù.

		\~english
		Gets the last latency of Remote peer
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in millisecond). Returns -1 if there is none.

		\~chinese
		?ÔğRemote peerîÜõÌı¨latency¡£
		\param remoteHostID é©?îÜremote peerîÜHostID¡£ò¦ïÒHostID_ServerîÜ??Ôğ?Ü×?ĞïîÜlatency¡£
		\param error Ú÷üŞ???Üú¡£åıÍıïáßÈ??ErrorType_Ok£¬åıÍı?êó?ÔğPing???ğíErrorType_ValueNotExist¡£
		\return ping÷êtimeì¤ûÆõ©?êÈÚ÷üŞ¡£?êóîÜ?Ú÷üŞ-1¡£

		\~japanese
		Remote peerªÎõÌı­ªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£
		\param remoteHostID ÷®ª½ª¦ªÈª¹ªëremote peerªÎHostID. HostID_Serverªòò¦ïÒª¹ªëªÈ«µ?«ĞªÈªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£
		\param error «¨«é?ª¬ª¢ªëª«ªÊª¤ª«ªò«ê«¿?«óª¹ªë¡£ïáßÈîÜªÊíŞùêªÏErrorType_Ok, PingªòÔğªÊª«ªÃª¿íŞùêªËªÏErrorType_ValueNotExistª¬ÜÁğíªµªìªë¡£
		\return ping timeªò«ß«êõ©?êÈªÇ«ê«¿?«óª¹ªë¡£ª¿ªÀª·¡¢ ping timeª¬ö´ïÒªµªìªÆª¤ªÊª±ªìªĞ-1ªò«ê«¿?«óª¹ªë¡£

		\~
		*/
		virtual int GetLastUnreliablePingMs(HostID remoteHostID, ErrorType* error = NULL) = 0;

		/**
		\~korean
		Remote peerÀÇ ¸¶Áö¸· ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù. GetLastUnreliablePing°ªÀº Unreliable·Î ÇÎ°ªÀ» ±¸ÇÏ´Â ¹İ¸é ÇØ´çÇÔ¼ö´Â ReliableUdp·Î ÃøÁ¤ÇÑ´Ù.
		\param remoteHostID Ã£À¸·Á´Â remote peerÀÇ HostID. HostID_Server¸¦ ÁöÁ¤ÇÏ¸é ¼­¹ö¿ÍÀÇ ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param error ¿¡·¯ ¿©ºÎ¸¦ ¸®ÅÏÇÑ´Ù. Á¤»óÀûÀÎ °æ¿ì ErrorType_Ok, PingÀ» ¾òÁö ¸øÇÑ °æ¿ì ErrorType_ValueNotExist°¡ ÀúÀåµÈ´Ù.
		\return ping timeÀ» ¹Ğ¸®ÃÊ´ÜÀ§·Î ¸®ÅÏÇÑ´Ù. ´Ü ¾øÀ¸¸é -1À» ¸®ÅÏÇÑ´Ù.

		\~english
		Gets the last latency of Remote peer. GetLastUnreliablePing value is found by Unreliable but the relevant function is measured by ReliableUdp.
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in millisecond). Returns -1 if there is none.

		\~chinese
		?ÔğRemote peerîÜõÌı¨Latency¡£GetLastUnreliablePing ?éÄUnreliableÏ´ping?£¬Ó£ßÓ?ùŞ?éÄReliableUdp?ïÒ¡£
		\param remoteHostID é©?îÜremote peerîÜHostID¡£ò¦ïÒHostID_ServerîÜ??Ôğ?Ü×?ĞïîÜlatency¡£
		\param error Ú÷üŞ???Üú¡£åıÍıïáßÈ??ErrorType_Ok£¬åıÍı?êó?ÔğPing???ğíErrorType_ValueNotExist¡£
		\return ping÷êtimeì¤ûÆõ©?êÈÚ÷üŞ¡£?êóîÜ?Ú÷üŞ-1¡£

		\~japanese
		Remote peerªÎõÌı­ªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£ GetLastUnreliablePingö·ªÏUnreliableªÇPINGö·ªòÏ´ªáªëÚãØü¡¢ú±???ªÏ ReliableUdpªÇö´ïÒª¹ªë¡£
		\param remoteHostID ÷®ª½ª¦ªÈª¹ªëremote peerªÎHostID. HostID_Serverªòò¦ïÒª¹ªëªÈ«µ?«ĞªÈªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£
		\param error «¨«é?ª¬ª¢ªëª«ªÊª¤ª«ªò«ê«¿?«óª¹ªë¡£ïáßÈîÜªÊíŞùêªÏErrorType_Ok, PingªòÔğªÊª«ªÃª¿íŞùêªËªÏErrorType_ValueNotExistª¬ÜÁğíªµªìªë¡£
		\return ping timeªò«ß«êõ©?êÈªÇ«ê«¿?«óª¹ªë¡£ª¿ªÀª·¡¢ ping timeª¬ö´ïÒªµªìªÆª¤ªÊª±ªìªĞ-1ªò«ê«¿?«óª¹ªë¡£

		\~
		*/
		virtual int GetLastReliablePingMs(HostID remoteHostID, ErrorType* error = NULL) = 0;

		/**
		\~korean
		Remote peerÀÇ ¸¶Áö¸· ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù. GetLastUnreliablePing°ªÀº Unreliable·Î ÇÎ°ªÀ» ±¸ÇÏ´Â ¹İ¸é ÇØ´çÇÔ¼ö´Â ReliableUdp·Î ÃøÁ¤ÇÑ´Ù.
		\param remoteHostID Ã£À¸·Á´Â remote peerÀÇ HostID. HostID_Server¸¦ ÁöÁ¤ÇÏ¸é ¼­¹ö¿ÍÀÇ ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param error ¿¡·¯ ¿©ºÎ¸¦ ¸®ÅÏÇÑ´Ù. Á¤»óÀûÀÎ °æ¿ì ErrorType_Ok, PingÀ» ¾òÁö ¸øÇÑ °æ¿ì ErrorType_ValueNotExist°¡ ÀúÀåµÈ´Ù.
		\return ping timeÀ» ÃÊ´ÜÀ§·Î ¸®ÅÏÇÑ´Ù. ´Ü ¾øÀ¸¸é -1À» ¸®ÅÏÇÑ´Ù.

		\~english
		Gets the last latency of Remote peer. GetLastUnreliablePing value is found by Unreliable but the relevant function is measured by ReliableUdp.
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in second). Returns -1 if there is none.

		\~chinese
		?ÔğRemote peerîÜõÌı¨Latency¡£GetLastUnreliablePing ?éÄUnreliableÏ´Ping?£¬Ó£ßÓ?ùŞ?éÄReliableUDP?ïÒ¡£
		\param remoteHostID é©?îÜremote peerîÜHostID¡£ò¦ïÒHostID_ServerîÜ??Ôğ?Ü×?ĞïîÜlatency¡£?ìı<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%îÜHost IDîÜ??ÔğP2P??îÜá¶êóà÷?îÜøÁĞ³latency¡£
		\param error Ú÷üŞ???Üú¡£åıÍıïáßÈ??ErrorType_Ok£¬åıÍı?êó?ÔğPing???ğíErrorType_ValueNotExist¡£
		\return ping÷êtimeì¤õ©?êÈÚ÷üŞ¡£?êóîÜ?Ú÷üŞ-1¡£

		\~japanese
		Remote peerªÎõÌı­ªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£ GetLastUnreliablePingö·ªÏUnreliableªÇPINGö·ªòÏ´ªáªëÚãØü¡¢ú±???ªÏ ReliableUdpªÇö´ïÒª¹ªë¡£
		\param remoteHostID ÷®ª½ª¦ªÈª¹ªëremote peerªÎHostID. HostID_Serverªòò¦ïÒª¹ªëªÈ«µ?«ĞªÈªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£
		\param error «¨«é?ª¬ª¢ªëª«ªÊª¤ª«ªò«ê«¿?«óª¹ªë¡£ïáßÈîÜªÊíŞùêªÏErrorType_Ok, PingªòÔğªÊª«ªÃª¿íŞùêªËªÏErrorType_ValueNotExistª¬ÜÁğíªµªìªë¡£
		\return ping timeªòõ©?êÈªÇ«ê«¿?«óª¹ªë¡£ª¿ªÀª·¡¢ ping timeª¬ö´ïÒªµªìªÆª¤ªÊª±ªìªĞ-1ªò«ê«¿?«óª¹ªë¡£

		\~
		*/
		inline double GetLastReliablePingSec(HostID remoteHostID, ErrorType* error = NULL)
		{
			int ret=GetLastReliablePingMs(remoteHostID, error);
			if(ret<0)
				return (double)ret;
			else
				return double(ret)/1000;
		}

		/**
		\~korean
		Remote peerÀÇ ÃÖ±Ù ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param remoteHostID Ã£À¸·Á´Â remote peerÀÇ HostID. HostID_Server¸¦ ÁöÁ¤ÇÏ¸é ¼­¹ö¿ÍÀÇ ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù. <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> ÀÇ HostID¸¦ ³ÖÀ¸¸é P2P ±×·ì ³»
		¸ğµç ¸â¹öµéÀÇ Æò±Õ ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param error ¿¡·¯ ¿©ºÎ¸¦ ¸®ÅÏÇÑ´Ù. Á¤»óÀûÀÎ °æ¿ì ErrorType_Ok, PingÀ» ¾òÁö ¸øÇÑ °æ¿ì ErrorType_ValueNotExist°¡ ÀúÀåµÈ´Ù.
		\return ping timeÀ» ÃÊ´ÜÀ§·Î ¸®ÅÏÇÑ´Ù. ´Ü ¾øÀ¸¸é -1À» ¸®ÅÏÇÑ´Ù.

		\~english
		Gets the recent latency of Remote peer
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server. Gets the average latency of all members of P2P group when set HostID of <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in second). Returns -1 if there is none.

		\~chinese
		?ÔğRemote peerîÜõÌĞÎlatency¡£
		\param remoteHostID é©?îÜremote peerîÜHostID¡£ò¦ïÒHostID_ServerîÜ??Ôğ?Ü×?ĞïîÜlatency¡£?ìı<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%îÜHost IDîÜ??ÔğP2P??îÜá¶êóà÷?îÜøÁĞ³latency¡£
		\param error Ú÷üŞ???Üú¡£åıÍıïáßÈ??ErrorType_Ok£¬åıÍı?êó?ÔğPing???ğíErrorType_ValueNotExist¡£
		\return ping÷êtimeì¤õ©?êÈÚ÷üŞ¡£?êóîÜ?Ú÷üŞ-1¡£

		\~japanese
		Remote peerªÎõÌĞÎªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£
		\param remoteHostID ÷®ª½ª¦ªÈª¹ªëremote peerªÎHostID. HostID_Serverªòò¦ïÒª¹ªëªÈ«µ?«ĞªÈªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£ <a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a> ªÎHostIDªòìıÕôª¹ªëªÈ P2P«°«ë?«×?ªÎîïªÆªÎ«á«ó«Ğ?ªÎøÁĞ³«ì«¤«Æ«ó«·ªòÔğªë¡£
		\param error «¨«é?ª¬ª¢ªëª«ªÊª¤ª«ªò«ê«¿?«óª¹ªë¡£ïáßÈîÜªÊíŞùêªÏErrorType_Ok, PingªòÔğªÊª«ªÃª¿íŞùêªËªÏErrorType_ValueNotExistª¬ÜÁğíªµªìªë¡£
		\return ping timeªòõ©?êÈªÇ«ê«¿?«óª¹ªë¡£ª¿ªÀª·¡¢ ping timeª¬ö´ïÒªµªìªÆª¤ªÊª±ªìªĞ-1ªò«ê«¿?«óª¹ªë¡£

		\~
		*/
		inline double GetRecentUnreliablePingSec(HostID remoteHostID, ErrorType* error = NULL)
		{
			int ret = GetRecentUnreliablePingMs(remoteHostID, error);
			if(ret<0)
				return (double)ret;
			else
				return (double)(ret/1000);
		}

		/**
		\~korean
		Remote peerÀÇ ÃÖ±Ù ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param remoteHostID Ã£À¸·Á´Â remote peerÀÇ HostID. HostID_Server¸¦ ÁöÁ¤ÇÏ¸é ¼­¹ö¿ÍÀÇ ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param error ¿¡·¯ ¿©ºÎ¸¦ ¸®ÅÏÇÑ´Ù. Á¤»óÀûÀÎ °æ¿ì ErrorType_Ok, PingÀ» ¾òÁö ¸øÇÑ °æ¿ì ErrorType_ValueNotExist°¡ ÀúÀåµÈ´Ù.
		\return ping timeÀ» ¹Ğ¸®ÃÊ´ÜÀ§·Î ¸®ÅÏÇÑ´Ù. ´Ü ¾øÀ¸¸é -1À» ¸®ÅÏÇÑ´Ù.

		\~english
		Gets the recent latency of Remote peer
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in millisecond). Returns -1 if there is none.

		\~chinese
		?ÔğRemote peerîÜõÌĞÎlatency¡£
		\param remoteHostID é©?îÜremote peerîÜHostID¡£ò¦ïÒHostID_ServerîÜ??Ôğ?Ü×?ĞïîÜlatency¡£
		\param error Ú÷üŞ???Üú¡£åıÍıïáßÈ??ErrorType_Ok£¬åıÍı?êó?ÔğPing???ğíErrorType_ValueNotExist¡£
		\return ping÷êtimeì¤ûÆõ©?êÈÚ÷üŞ¡£?êóîÜ?Ú÷üŞ-1¡£

		\~japanese
		Remote peerªÎõÌĞÎªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£
		\param remoteHostID ÷®ª½ª¦ªÈª¹ªëremote peerªÎHostID. HostID_Serverªòò¦ïÒª¹ªëªÈ«µ?«ĞªÈªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£
		\param error «¨«é?ª¬ª¢ªëª«ªÊª¤ª«ªò«ê«¿?«óª¹ªë¡£ïáßÈîÜªÊíŞùêªÏErrorType_Ok, PingªòÔğªÊª«ªÃª¿íŞùêªËªÏErrorType_ValueNotExistª¬ÜÁğíªµªìªë¡£
		\return ping timeªò«ß«êõ©?êÈªÇ«ê«¿?«óª¹ªë¡£ª¿ªÀª·¡¢ ping timeª¬ö´ïÒªµªìªÆª¤ªÊª±ªìªĞ-1ªò«ê«¿?«óª¹ªë¡£

		\~
		*/
		virtual int GetRecentUnreliablePingMs(HostID remoteHostID, ErrorType* error = NULL) = 0;

		/**
		\~korean
		Remote peer ÀÇ ÃÖ±Ù ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù. GetRecentUnreliablePing °ªÀº Unreliable·Î ÇÎ°ªÀ» ±¸ÇÏ´Â ¹İ¸é ÇØ´çÇÔ¼ö´Â ReliableUdp ·Î ÃøÁ¤ÇÑ´Ù.
		\param remoteHostID Ã£À¸·Á´Â remote peerÀÇ HostID. HostID_Server¸¦ ÁöÁ¤ÇÏ¸é ¼­¹ö¿ÍÀÇ ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param error ¿¡·¯ ¿©ºÎ¸¦ ¸®ÅÏÇÑ´Ù. Á¤»óÀûÀÎ °æ¿ì ErrorType_Ok, PingÀ» ¾òÁö ¸øÇÑ °æ¿ì ErrorType_ValueNotExist°¡ ÀúÀåµÈ´Ù.
		\return ping timeÀ» ¹Ğ¸®ÃÊ´ÜÀ§·Î ¸®ÅÏÇÑ´Ù. ´Ü ¾øÀ¸¸é -1À» ¸®ÅÏÇÑ´Ù.

		\~english
		Gets the recent latency of Remote peer. GetRecentUnreliablePing value is found by Unreliable but the relevant function is measured by ReliableUdp.
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in millisecond). Returns -1 if there is none.

		\~chinese
		?ÔğRemote peerîÜõÌĞÎLatency¡£GetRecentUnreliablePing ?éÄUnreliableÏ´Ping?£¬Ó£ßÓ?ùŞ??éÄReliableUDP?ïÒ¡£
		\param remoteHostID é©?îÜremote peerîÜHostID¡£ò¦ïÒHostID_ServerîÜ??Ôğ?Ü×?ĞïîÜlatency¡£
		\param error Ú÷üŞ???Üú¡£åıÍıïáßÈ??ErrorType_Ok£¬åıÍı?êó?ÔğPing???ğíErrorType_ValueNotExist¡£
		\return ping÷êtimeì¤ûÆõ©?êÈÚ÷üŞ¡£?êóîÜ?Ú÷üŞ-1¡£

		\~japanese
		Remote peerªÎõÌĞÎªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£ GetRecentUnreliablePingö·ªÏUnreliableªÇPINGö·ªòÏ´ªáªëÚãØü¡¢ú±???ªÏ ReliableUdpªÇö´ïÒª¹ªë¡£
		\param remoteHostID ÷®ª½ª¦ªÈª¹ªëremote peerªÎHostID. HostID_Serverªòò¦ïÒª¹ªëªÈ«µ?«ĞªÈªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£
		\param error «¨«é?ª¬ª¢ªëª«ªÊª¤ª«ªò«ê«¿?«óª¹ªë¡£ïáßÈîÜªÊíŞùêªÏErrorType_Ok, PingªòÔğªÊª«ªÃª¿íŞùêªËªÏErrorType_ValueNotExistª¬ÜÁğíªµªìªë¡£
		\return ping timeªò«ß«êõ©?êÈªÇ«ê«¿?«óª¹ªë¡£ª¿ªÀª·¡¢ ping timeª¬ö´ïÒªµªìªÆª¤ªÊª±ªìªĞ-1ªò«ê«¿?«óª¹ªë¡£

		\~
		*/
		virtual int GetRecentReliablePingMs(HostID remoteHostID, ErrorType* error = NULL) = 0;

		/**
		\~korean
		Remote peer ÀÇ ÃÖ±Ù ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù. GetRecentUnreliablePing °ªÀº Unreliable·Î ÇÎ°ªÀ» ±¸ÇÏ´Â ¹İ¸é ÇØ´çÇÔ¼ö´Â ReliableUdp ·Î ÃøÁ¤ÇÑ´Ù.
		\param remoteHostID Ã£À¸·Á´Â remote peerÀÇ HostID. HostID_Server¸¦ ÁöÁ¤ÇÏ¸é ¼­¹ö¿ÍÀÇ ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param error ¿¡·¯ ¿©ºÎ¸¦ ¸®ÅÏÇÑ´Ù. Á¤»óÀûÀÎ °æ¿ì ErrorType_Ok, PingÀ» ¾òÁö ¸øÇÑ °æ¿ì ErrorType_ValueNotExist°¡ ÀúÀåµÈ´Ù.
		\return ping timeÀ» ÃÊ´ÜÀ§·Î ¸®ÅÏÇÑ´Ù. ´Ü ¾øÀ¸¸é -1À» ¸®ÅÏÇÑ´Ù.

		\~english
		Gets the recent latency of Remote peer. GetRecentUnreliablePing value is found by Unreliable but the relevant function is measured by ReliableUdp.
		\param remoteHostID HostID of remote peer to find. Gets the latency with server when set HostID_Server.
		\param error It returns whether an error occurs or not. In case of normal case, ErrorType_Ok will be saved, however, ErrorType_ValueNotExist will be saved in case Ping is not received.
		\return returns ping time(in second). Returns -1 if there is none.

		\~chinese
		?ÔğRemote peerîÜõÌĞÎLatency¡£GetRecentUnreliablePing ?éÄUnreliableÏ´Ping?£¬Ó£ßÓ?ùŞ??éÄReliableUDP?ïÒ¡£
		\param remoteHostID é©?îÜremote peerîÜHostID¡£ò¦ïÒHostID_ServerîÜ??Ôğ?Ü×?ĞïîÜlatency¡£
		\param error Ú÷üŞ???Üú¡£åıÍıïáßÈ??ErrorType_Ok£¬åıÍı?êó?ÔğPing???ğíErrorType_ValueNotExist¡£
		\return ping÷êtimeì¤õ©?êÈÚ÷üŞ¡£?êóîÜ?Ú÷üŞ-1¡£

		\~japanese
		Remote peerªÎõÌĞÎªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£ GetRecentUnreliablePingö·ªÏUnreliableªÇPINGö·ªòÏ´ªáªëÚãØü¡¢ú±???ªÏ ReliableUdpªÇö´ïÒª¹ªë¡£
		\param remoteHostID ÷®ª½ª¦ªÈª¹ªëremote peerªÎHostID. HostID_Serverªòò¦ïÒª¹ªëªÈ«µ?«ĞªÈªÎ«ì«¤«Æ«ó«·ªòÔğªë¡£
		\param error «¨«é?ª¬ª¢ªëª«ªÊª¤ª«ªò«ê«¿?«óª¹ªë¡£ïáßÈîÜªÊíŞùêªÏErrorType_Ok, PingªòÔğªÊª«ªÃª¿íŞùêªËªÏErrorType_ValueNotExistª¬ÜÁğíªµªìªë¡£
		\return ping timeªòõ©?êÈªÇ«ê«¿?«óª¹ªë¡£ª¿ªÀª·¡¢ ping timeª¬ö´ïÒªµªìªÆª¤ªÊª±ªìªĞ-1ªò«ê«¿?«óª¹ªë¡£

		\~

		*/
		inline double GetRecentReliablePingSec(HostID remoteHostID, ErrorType* error = NULL)
		{
			int ret = GetRecentReliablePingMs(remoteHostID, error);
			if(ret<0)
				return (double)ret;
			else
				return double(ret)/1000;
		}

		/**
		\~korean
		³»ºÎÀûÀ¸·Î °®°í ÀÖ´Â UDP ¼ÒÄÏÀ» ´İ¾Æ¹ö¸®°í ¼­¹ö ¹× P2P Åë½ÅÀ» bypass »óÅÂ·Î °­Á¦ ÀüÈ¯ÇÑ´Ù.
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#use_alternative_p2p" >ProudNetÀ» ¾²Áö ¾Ê°í ProudNetÀÇ È¦ÆİÄª Á¤º¸¸¦ Åä´ë·Î º°µµ UDP ¼ÒÄÏÀ¸·Î Åë½ÅÇÏ±â</a>  ¿¡¼­ »ç¿ëµÈ´Ù.
		- CNetClient´Â P2P Åë½ÅÀ» ÇÏ°í ÀÖ´Â PeerÀÇ °¹¼ö¸¸Å­ÀÇ UDP ¼ÒÄÏÀ» °®°í ÀÖÀ¸¸ç °¢°¢ÀÇ UDP ¼ÒÄÏÀº ¼­·Î ´Ù¸¥ Peer¿ÍÀÇ Åë½ÅÀ»
		Àü´ãÇÏ°í ÀÖ´Ù. ÀÌ ¸Ş¼­µå´Â 1°³ Peer¿ÍÀÇ Åë½Å¸¸À» bypass »óÅÂ·Î °­Á¦ ÀüÈ¯ÇÑ´Ù.
		- ÀÌ ¸Ş¼­µå È£Ãâ ÈÄ »ó´ë¹æµµ direct P2P¸¦ ¾µ ¼ö ¾ø°Ô µÇ¹Ç·Î »ó´ë¹æµµ º» ¸Ş¼­µå¸¦ È£ÃâÇØ¾ß ÇÒ ¼öµµ ÀÖ´Ù.
		- direct P2P°¡ ÀÌ¹Ì ¾Æ´Ñ °æ¿ì¿¡µµ ÀÌ ¸Ş¼­µå´Â °ú°Å È¦ÆİÄªµÇ¾ú´ø Á¤º¸¸¦ Ã¤¿öÁØ´Ù.

		\param peerID °­Á¦ bypassÇÒ »ó´ëÃø peerÀÇ HostID
		\param outDirectP2PInfo °­Á¦ bypassµÈ peer¿Í ÀÌ CNetClient°¡ P2P Åë½ÅÀ» ÇÏ±â À§ÇØ CNetClient°¡ ³»ºÎÀûÀ¸·Î °®°í ÀÖ´ø È¦ÆİÄª Á¤º¸°¡ Ã¤¿öÁú °÷.
		\return »ó´ë ÇÇ¾î°¡ Á¸ÀçÇÏ¸ç »ó´ë ÇÇ¾î¿ÍÀÇ È¦ÆİÄªÀÌ µÈ ÀûÀÌ ÀÖ¾ú°Å³ª direct P2P¸¦ À¯ÁöÇÏ°í ÀÖ¾ú´Ù¸é true¸¦ ¸®ÅÏÇÑ´Ù.

		\~english
		Shuts UDP socket that is possessed internally then forcefully converts server and P2P communication to bypass state
		- Used in <a target="_blank" href="http://guide.nettention.com/cpp_en#use_alternative_p2p" >Communicating with a separated UDP socket based on ProudNet hole-punched information without using ProudNet.</a>
		- CNetClient has the same number of UDP sockets as the number of peers that are P2P communiating with and each of UDP sockets manages the communication with each peer.
		This methos forcefully converts 1 communication with peer to bypass state.
		- Since the opponent cannot use direct P2P after calling this method, the opponent may call this method as well.
		- Also fills previously hole-punched info when not direct P2P

		\param peerID HostId of opponent peer that to be forcefully bypassed
		\param outDirectP2PInfo where the hole-punching information that was possessed by CNetClient in order to perform P2P communication between this CNetClient and forcefully bypassed peer.
		\return Returns true either if hole-punched with opponent peer while opponent peer exists OR sustained direct P2P.

		\~chinese
		???İ»îÜUDP socket£¬Ë­ğ¤??Ü×?ĞïĞàP2P÷×ãáì¤bypass??¡£
		- î¤<a target="_blank" href="http://guide.nettention.com/cpp_zh#use_alternative_p2p" >ÜôŞÅéÄProudNet£¬ñşĞñéÍProudNetîÜöèÔ×ï×?éÄ?èâîÜUDPSocket?ú¼÷×ãá</a>%ŞÅéÄ¡£
		- CNetClient%?êóó·ßÓ?éÍ?ú¼P2P÷×ãápeer??îÜUDP socket£¬Øß?UDP socket???ĞìöâpeerîÜ÷×ãá¡£ó®Û°Ûöì¤bypass??ñşË­ğ¤???ìé?peerîÜ÷×ãá¡£
		- û¼Ğ£ó®Û°Ûöı¨?Û°å¥ÜôÒöŞÅéÄdirect P2P£¬á¶ì¤?Û°å¥Ê¦Òöé©û¼Ğ£ó®Û°Ûö¡£
		- ÜôãÀdirect P2PîÜï×?£¬ó®Û°Ûöå¥?õö?ËÛù¬öèÔ×îÜãáãÓ¡£

		\param peerID é©Ë­ğ¤bypassîÜ?Û°peerîÜHost ID¡£
		\param outDirectP2PInfo Ë­ğ¤bypassîÜpeerûúó® CNetClient%?ÖõP2P÷×ãá£¬ CNetClient%î¤?İ»?êóîÜöèÔ×ãáãÓù¬?õöîÜò¢Û°¡£
		\return ğíî¤?Û°peerì»ó¦êó???Û°peerîÜöèÔ×ûäíº?ò¥direct P2PîÜ?Ú÷üŞtrue¡£

		\~japanese
		?İ»îÜªËò¥ªÃªÆª¤ªëUDP«½«±«Ã«ÈªòøÍª¸ªÆ¡¢«µ?«Ğ?ªªªèªÓP2P÷×ãáªò«Ğ«¤«Ñ«¹?÷¾ªË?ğ¤ï·ªêôğª¨ªŞª¹¡£
		- \ref use_alternative_p2p ªÇŞÅªïªìªŞª¹¡£
		- CNetClientªÏP2P÷×ãáªòª·ªÆª¤ªëPeerªÎ?ªÀª±ªÎUDP«½«±«Ã«Èªòò¥ªÃªÆª¤ªÆ¡¢ÊÀ?ªÎUDP«½«±«Ã«ÈªÏªªû»ª¤êŞª¦PeerªÈªÎ÷×ãáªò??ª·ªÆª¤ªŞª¹¡£ª³ªÎ«á«½«Ã«ÉªÏ1ËÁªÎPeerªÈªÎ÷×ãáªÎªßªò«Ğ«¤«Ñ«¹?÷¾ªË?ğ¤ï·ªêôğª¨ªŞª¹¡£
		- ª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª·ª¿ı­¡¢ßÓâ¢ªâdirect P2PªòŞÅª¨ªÊª¯ªÊªêªŞª¹ªÎªÇ¡¢ßÓâ¢ªâª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª¹ª³ªÈªâªÇª­ªŞª¹¡£
		- direct P2PªÇªÏªÊª¤íŞùêªËªâª³ªÎ«á«½«Ã«ÉªÏÎ¦ËÛªË«Û?«ë«Ñ«ó«Á«ó«°ªµªìª¿ï×ÜÃªò?ª¿ª·ªÆª¯ªìªŞª¹¡£
		
		\param peerID ?ğ¤ªË«Ğ«¤«Ñ«¹ª¹ªëßÓâ¢ªÎPeerªÎHostID		
		\param outDirectP2PInfo ?ğ¤ªË«Ğ«¤«Ñ«¹ªµªìª¿peerªÈª³ªÎCNetClientª¬P2P÷×ãáªòú¼ª¦ª¿ªá¡¢CNetClientª¬?İ»îÜªËò¥ªÃªÆª¤ª¿«Û?«ë«Ñ«ó«Á«ó«°ï×ÜÃª¬?ª¿ªµªìªëá¶¡£\return ßÓâ¢Peerª¬ğíî¤ª·ªÆßÓâ¢PeerªÈªÎ«Û?«ë«Ñ«ó«Á«ó«°ª¬ªµªìª¿ª³ªÈª¬ª¢ªÃª¿ªÈª«¡¢direct P2Pªòë«ò¥ª·ªÆª¤ª¿ªétrueªò«ê«¿?«óª·ªŞª¹¡£ 

		\~
		*/
		virtual bool InvalidateUdpSocket(HostID peerID, CDirectP2PInfo &outDirectP2PInfo ) = 0;

		/**
		\~korean
		InvalidateUdpSocketÀ¸·Î Á¦°ÅµÈ UDP socketÀ» ´Ù½Ã ¸¸µç´Ù.
		±×¸®°í ÇØ´ç »ó´ëÃø peer¿ÍÀÇ UDP È¦ÆİÄªÀ» Àç°³ÇÑ´Ù.
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#use_alternative_p2p" >ProudNetÀ» ¾²Áö ¾Ê°í ProudNetÀÇ È¦ÆİÄª Á¤º¸¸¦ Åä´ë·Î º°µµ UDP ¼ÒÄÏÀ¸·Î Åë½ÅÇÏ±â</a>  ¿¡¼­ »ç¿ëµÈ´Ù.
		- ÀÌ ¸Ş¼­µå¸¦ È£ÃâÇÑ´Ù°í ÇØ¼­ Áï½Ã UDP socketÀÌ ¸¸µé¾îÁöÁö´Â ¾Ê´Â´Ù. »õ·Î ¸¸µé¾îÁø UDP ¼ÒÄÏÀÇ ÁÖ¼Ò¸¦ ¾òÀ¸·Á¸é
		Àá½Ã ÈÄ¿¡ GetLocalUdpSocketAddrÀ» È£ÃâÇØ¼­ ¾ò¾î¿Í¾ß ÇÑ´Ù.
		- ÀÌ ¸Ş¼­µå È£Ãâ ÈÄ »ó´ë¹æµµ direct P2P¸¦ ¾µ ¼ö ÀÖ¾î¾ß ÇÏ¹Ç·Î »ó´ë¹æµµ º» ¸Ş¼­µå¸¦ È£ÃâÇØ¾ß ÇÒ ¼öµµ ÀÖ´Ù.

		\param peerID ÀÏÀü¿¡ InvalidateUdpSocketÀÌ ½ÃÇàµÇ¾ú´ø ÇÇ¾îÀÇ ID.
		\return ¼º°øÀûÀ¸·Î ¿Ï·á½Ã true. ÇØ´ç »ó´ëÃø peer°¡ ¾øÀ¸¸é false.

		\~english
		Re-creates UDP socket removed by InvalidateUdpSocket
		And re-starts UDP hole-punching with opponent peer
		- Used at <a target="_blank" href="http://guide.nettention.com/cpp_en#use_alternative_p2p" >Communicating with a separated UDP socket based on ProudNet hole-punched information without using ProudNet.</a>
		- Calling this method does not mean immediate UDP socket creation. To get the address of newly created UDP socket, must call GetLocalUdpSocketAddr and get the address after a while.
		- Since the opponent cannot use direct P2P after calling this method, the opponent may call this method as well.

		\param peerID ID of peer that InvalidateUdpSocket was executed previously.
		\return true if successfully completed. False if there is no opponent peer.

		\~chinese
		ñìãæ?ËïéÄInvalidateUdpSocket?ğ¶îÜUDP socket¡£
		æÔı¨ñìãæ?ã·?ßÓ??Û°peerîÜUDPöèÔ×¡£
		- î¤<a target="_blank" href="http://guide.nettention.com/cpp_zh#use_alternative_p2p" >ÜôŞÅéÄProudNet£¬ñşĞñéÍProudNetîÜöèÔ×ï×?éÄ?èâîÜUDPSocket?ú¼÷×ãá</a>%ŞÅéÄ¡£
		- ?ŞÅû¼Ğ£ó®Û°Ûö£¬å¥Üô?Ø¡??ËïUDP socket¡£ßÌ?Ôğñìãæ?ËïîÜUDP socketîÜò¢ò£îÜ?£¬õªı¨û¼Ğ£GetLocalUdpSocketAddrı¨?ö¢
		- ó®Û°Ûöû¼Ğ£ı¨?Û°å¥é©ŞÅéÄdirect P2P£¬á¶ì¤?Û°å¥êóÊ¦Òö?û¼Ğ£ó®Û°Ûö¡£

		\param peerID ñıîñInvalidateUdpSocketù¬?ú¼îÜpeerîÜID¡£
		\return ïáãÒèÇà÷îÜ?true¡£?êóßÓ??Û°peerîÜ?false¡£

		\~japanese
		InvalidateUdpSocketªÇğ¶ËÛªµªìª¿UDP socketªòî¢ªÓíÂªêªŞª¹¡£ 
		ª½ª·ªÆú±?ßÓâ¢ªÎPeerªÈªÎUDP«Û?«ë«Ñ«ó«Á«ó«°ªòî¢ËÒª·ªŞª¹¡£
		- \ref use_alternative_p2p ªÇŞÅªïªìªŞª¹¡£
		- ª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª¹ªÈª¤ªÃªÆòÁªÁªËUDP socketª¬íÂªéªìªëª³ªÈªÏª¢ªêªŞª»ªó¡£ãæª¿ªËíÂªéªìª¿UDP«½«±«Ã«ÈªÎ«¢«É«ì«¹ªòÔğªëª¿ªáªËªÏ¡¢ª·ªĞªéª¯ı­ªÇGetLocalUdpSocketAddrªòû¼ªÓõóª·ªÆÔğªÆª¯ªëù±é©ª¬ª¢ªêªŞª¹¡£
		- ª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª·ª¿ı­¡¢ßÓâ¢ªâdirect P2PªòŞÅª¦ª³ªÈª¬ªÇª­ªÊª±ªìªĞªÊªéªÊª¤ªÎªÇ¡¢ßÓâ¢ªâª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª¹ª³ªÈªâª¢ªêªŞª¹¡£
		\param peerID ª³ªÎîñªËInvalidateUdpSocketª¬ã¿ú¼ªµªìª¿PeerªÎID
		\return à÷ÍíîÜªËèÇÖõãÁªËtrue¡£ú±?ßÓâ¢ö°ªÎPeerª¬ªÊª±ªìªĞfalse¡£

		\~
		*/
		virtual bool RestoreUdpSocket(HostID peerID) = 0;

		// »ç¿ëÀÚ´Â ÀÌ°É ¾²Áö ¸»°Í
		virtual void TEST_FallbackUdpToTcp(FallbackMethod mode) = 0;

		virtual void TEST_EnableVirtualSpeedHack(int64_t multipliedSpeed)=0;

		virtual void TEST_SetPacketTruncatePercent(Proud::HostType hostType, int percent) = 0;

		/**
		\~korean
		P2P°£ÀÇ Reliable ¸Ş½ÃÂ¡ ½Ã½ºÅÛÀÇ ÀÛµ¿ Åë°è¸¦ ¾ò´Â´Ù.
		- ¼º´É ÃøÁ¤ÀÌ³ª µğ¹ö±ë µîÀ» À§ÇØ »ç¿ëµÈ´Ù.

		\~english
		Gets operation statistics of reliable messaging system among P2P
		- Used for performance test or debugging

		\~chinese
		?ÔğP2Pñı?îÜReliable messagingÍ§?îÜ????¡£
		- ?àõÒö?ïÒûäíº??Ôõì»ŞÅéÄ¡£

		\~japanese
		P2PÊàªÎReliable«á«Ã«»?«¸«ó«°«·«¹«Æ«àªÎíÂÔÑ÷ÖÍªªòÔğªŞª¹¡£
		- àõÒöö´ïÒªä«Ç«Ğ«Ã«®«ó«°ªÊªÉªÎª¿ªáªËŞÅéÄªµªìªŞª¹¡£ 

		\~
		*/
		virtual bool GetPeerReliableUdpStats(HostID peerID,ReliableUdpHostStats &output) = 0;

		/**
		\~korean
		ÀÌ Å¬¶óÀÌ¾ğÆ®°¡ °øÀ¯±â µÚ¿¡ ÀÖ´Â Å¬¶óÀÌ¾ğÆ®ÀÎ°¡?
		\return ÆÇ´ÜÇÒ ¼ö ¾øÀ¸¸é false ¸®ÅÏ. ÀÌ¶§ outputÀº ¾ÈÃ¤¿öÁø´Ù.
		\param output °øÀ¯±â µÚ¿¡ ÀÖ´Â Å¬¶óÀÌ¾ğÆ®ÀÌ¸é true°¡ Ã¤¿öÁø´Ù.

		\~english
		Is this client behind a router?
		\return returns false if cannot be verified. The output will not be filled at this time.
		\param output Fills true if the client is behind a router

		\~chinese
		ó®clientãÀÖØë¦Ğïı¨ØüîÜclient?£¿
		\return ÜôÒö÷÷?îÜ?Ú÷üŞfalse¡£??ı¦Üô?õöoutput¡£
		\param output ÖØë¦Ğïı¨ØüîÜclientîÜ??õötrue¡£

		\~japanese
		ª³ªÎ«¯«é«¤«¢«ó«Èª¬«ë?«¿?ªÎı­ªíªËª¢ªë«¯«é«¤«¢«ó«ÈªÊªÎª«£¿
		\return ÷÷?ªÇª­ªÊª±ªìªĞfalseªò«ê«¿?«ó¡£ª³ªÎãÁ¡¢outputªÏ?ª¿ªµªìªŞª»ªó¡£ 
		\param output «ë?«¿?ªÎı­ªíªËª¢ªë«¯«é«¤«¢«ó«ÈªÇª¢ªìªĞtrueª¬?ª¿ªµªìªŞª¹¡£ 

		\~
		*/
		virtual bool IsLocalHostBehindNat(bool &output) = 0;

		/**
		\~korean
		¿£Áø ÇÁ·ÎÅäÄİ ¹öÀüÀ» ¾ò´Â´Ù. ÀÌ °ªÀÌ Å¬¶óÀÌ¾ğÆ®¿¡¼­ ¾ò´Â ¿£Áø ÇÁ·ÎÅäÄİ ¹öÀü°ú ´Ù¸£¸é Á¢¼ÓÀÌ ºÒÇãµÈ´Ù.

		\~english
		Gets the version of engine protocol. If this value differes to engine protocol version from client then the connection will not be accepted.

		\~chinese
		?ÔğìÚÌÖ??÷úÜâ¡£ó®???client?ÔğîÜìÚÌÖ??÷úÜâÜôÔÒîÜ?ÜôëÃ??ïÈ¡£

		\~japanese
		«¨«ó«¸«ó«×«í«È«³«ë«Ğ?«¸«ç«óªòÔğªŞª¹¡£ª³ªÎö·ª¬«¯«é«¤«¢«ó«ÈªèªêÔğªë«¨«ó«¸«ó«×«í«È«³«ë«Ğ?«¸«ç«óªÈêŞªÃªÆïÈ?ª¬ÜôúÉªµªìªŞª¹¡£
		\~
		*/
		virtual int GetInternalVersion() = 0;

		/**
		\~korean
		ÁÖ°í¹ŞÀ» ¼ö ÀÖ´Â RMI È¤Àº »ç¿ëÀÚ Á¤ÀÇ ¸Ş½ÃÁöÀÇ ÃÖ´ë Å©±â´Ù.

		\~english
		The maximum size of RMI or user defined message

		\~chinese
		Òö?ïÈîÜRMIûäíºéÄ?ïÒ?îÜãáãÓîÜõÌÓŞÓŞá³¡£

		\~japanese
		ªäªêö¢ªêªÇª­ªëRMIªŞª¿ªÏ«æ?«¶?ïÒëù«á«Ã«»?«¸ªÎõÌÓŞ«µ«¤«ºªÇª¹¡£
		\~
		*/
		virtual int GetMessageMaxLength() = 0;

		/**
		\~korean
		¼­¹ö¿¡¼­ ÀÎ½ÄµÈ, ÀÌ Å¬¶óÀÌ¾ğÆ®ÀÇ ³×Æ®¿öÅ© ÁÖ¼Ò¸¦ ¾ò´Â´Ù. Áï, Áï °øÀÎ ÀÎÅÍ³İ ÁÖ¼Ò(external addr)ÀÌ´Ù.
		- ¼­¹ö¿Í ¿¬°áµÇ¾î ÀÖÀ»¶§¸¸ À¯È¿ÇÑ °ªÀ» ¸®ÅÏÇÑ´Ù.

		\~english
		Gets the network address of this client that is recognized by server. In other words, this is a public Internet address(external address).
		- Returns effective values only when connected to server

		\~chinese
		?Ôğ?Ü×?Ğï??îÜ£¬ó®clientîÜ??ò¢ò£¡£?Íë?û»??ò¢ò££¨external addr£©¡£
		- ñş?Ü×?Ğï?ïÈîÜ?ı¦Ú÷üŞêóüù?¡£

		\~japanese
		«µ?«Ğ?ªèªêìããÛªµªìª¿ª³ªÎ«¯«é«¤«¢«ó«ÈªÎ«Í«Ã«È«ï?«¯«¢«É«ì«¹ªòÔğªŞª¹¡£?ªÁ¡¢«Ñ«Ö«ê«Ã«¯«¤«ó«¿?«Í«Ã«È«¢«É«ì«¹(external addr)ªÇª¹¡£
		- «µ?«Ğ?ªÈïÈ?ªµªìªÆª¤ªëãÁªÎªßêó?ªÊö·ªò«ê«¿?«óª·ªŞª¹¡£

		\~
		*/
		virtual AddrPort GetPublicAddress() = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#thread_pool" >½º·¹µå Ç®(Thread pool)</a> ÀÇ °¢ ½º·¹µåÀÇ Á¤º¸¸¦ ¾ò½À´Ï´Ù.
		\param output ¿©±â¿¡ Á¤º¸°¡ Ã¤¿öÁı´Ï´Ù.

		\~english
		Gets the information of each thread of <a target="_blank" href="http://guide.nettention.com/cpp_en#thread_pool" >Thread pool</a>
		\param output this is where the information has filled in.

		\~chinese
		?Ôğ<a target="_blank" href="http://guide.nettention.com/cpp_zh#thread_pool" >?ïïò®(Thread pool)</a>%îÜÊÀ?ïïãáãÓ¡£
		\param output èÙ?×ì?õöãáãÓ¡£

		\~japanese
		\ref thread_poolªÎÊÀ«¹«ì«Ã«ÉªÎï×ÜÃªòÔğªŞª¹¡£
		\param output ª³ª³ªËï×ÜÃª¬?ª¿ªµªìªŞª¹¡£

		\~
		*/
		virtual void GetUserWorkerThreadInfo(CFastArray<CThreadInfo> &output) = 0;

		/**
		\~korean
		³×Æ®¿öÅ· ½º·¹µåÀÇ Á¤º¸¸¦ ¾ò½À´Ï´Ù.
		ProudNetÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#thread_pool" >½º·¹µå Ç®(Thread pool)</a> °ú º°°³·Î ³×Æ®¿öÅ© I/OÃ³¸®¸¦ ´ã´çÇÏ´Â ½º·¹µå°¡ ³»ÀåµÇ¾î ÀÖ½À´Ï´Ù. ÀÌ°ÍÀÇ Á¤º¸¸¦ ¾ò½À´Ï´Ù.
		\param output ¿©±â¿¡ Á¤º¸°¡ Ã¤¿öÁı´Ï´Ù.

		\~english
		Gets the information of networking thread
		ProudNet has a thread that manages network I/O that is independent to <a target="_blank" href="http://guide.nettention.com/cpp_en#thread_pool" >Thread pool</a>. This gets the information of the thread.
		\param output This is where the information is filled.

		\~chinese
		?ö¢???ïïãáãÓ¡£
		ProudNetãÀ?<a target="_blank" href="http://guide.nettention.com/cpp_zh#thread_pool" >?ïïò®(Thread pool)</a>ÜôÔÒ£¬?öÇ?ìò??I/O?×âîÜ?ïï¡£?Ôğ?îÜãáãÓ¡£
		\param output èÙ?×ì?õöãáãÓ¡£

		\~japanese
		«Í«Ã«È«ï?«­«ó«°«¹«ì«Ã«ÉªÎï×ÜÃªòÔğªŞª¹¡£
		ProudNetªÏ\ref thread_poolªÈªÏÜ¬ªË«Í«Ã«È«ï?«¯I/O?×âªò??ª¹ªë«¹«ì«Ã«Éª¬??ªµªìªÆª¤ªŞª¹¡£ª³ªìªÎï×ÜÃªòÔğªŞª¹¡£
		\param output ª³ª³ªËï×ÜÃª¬?ª¿ªµªìªŞª¹¡£ 

		\~
		*/
		virtual void GetNetWorkerThreadInfo(CFastArray<CThreadInfo> &output) = 0;

		/**
		\~korean
		ProudNet¿¡ ÀÇÇØ ¸¸µé¾îÁø socket handle µéÀ» ¾ò½À´Ï´Ù. ÀÌ ±â´ÉÀº Å¬¶óÀÌ¾ğÆ® º¸¾È ¼ÒÇÁÆ®¿ş¾î(°¡·É nProtect³ª Ahnlab Hack Shield µî)¿¡¼­ ÇÊ¿ä·Î ÇÒ °æ¿ì À¯¿ëÇÕ´Ï´Ù.
		ÀÌ ¸Ş¼­µå¸¦ ÅëÇØ ¾òÀº socket handleÀº Á¤º¸ È¹µæ ¿ëµµ·Î¸¸ »ç¿ëÇÏ½Ã°í, I/O Ã³¸®¸¦ ¼öÇàÇÏ´Â °ÍÀº ±İÁöÇÕ´Ï´Ù. ºÎÀÛ¿ëÀÌ ÀÖÀ» ¼ö ÀÖ±â ¶§¹®ÀÔ´Ï´Ù.

		\param remoteHostID ¼ÒÄÏ Á¤º¸¸¦ ¾òÀ» peerÀÇ HostIDÀÔ´Ï´Ù. HostID_ServerÀÏ °æ¿ì ¼­¹ö¿Í ¿¬°áµÈ ¼ÒÄÏ Á¤º¸¸¦ ¾ò½À´Ï´Ù.
		\param output ¿©±â¿¡ Á¤º¸°¡ Ã¤¿öÁı´Ï´Ù.
		\return remoteHostID °ªÀÌ À¯È¿ÇÑ °æ¿ì trueÀÔ´Ï´Ù.

		\~english
		Gets socket handles that made by ProudNet. This function is useful when it need at security software(e.g. nProtect or Ahnlab Hack Shield)
		Please use socket handle from this method for getting information. Do not excute I/O process. Because it may occur bed reaction.

		\param remoteHostID HostID of peer that getting socket information. If it is HostID_Server then it gets socket information from connected server.
		\param output Information fill in here
		\return remoteHostID It is true, if value is available.

		\~chinese
		?Ôğù¬ProudNet?ËïîÜsocket handle¡£ó®ÍíÒöî¤clientäÌîï?Ëì£¨ÖÇåınProtectûäíºAhnlab HackÔõ£©âÍé©îÜ?ı¦êóéÄ¡£
		÷×?ó®Û°Ûö?ÔğîÜsocket handleñşÎÁéÄéÍ?ÔğãáãÓéÄÔ²£¬Ğ×ò­?ú¼I/O ?×â¡£ì×?Ê¦ÒöêóÜùíÂéÄ¡£

		\param remoteHostID ?ÔğsocketîÜpeerîÜHost ID¡£åıÍıãÀHostID_ServerîÜ??Ôğ?Ü×?Ğï?ïÈîÜsocketãáãÓ¡£
		\param output èÙ?×ì?õöãáãÓ¡£
		\return remoteHostID?êóüùîÜ?true¡£

		\~japanese
		ProudNetªËªèªÃªÆíÂªéªìª¿socket handleªòÔğªŞª¹¡£ª³ªÎÑ¦ÒöªÏ«¯«é«¤«¢«ó«È«»«­«å«ê«Æ«£«½«Õ«È«¦«§«¢(?ªË¡¢nProtectªÈª«Ahnlab Hack ShieldªÊªÉ)ªÇù±é©ªÈª¹ªëíŞùêªËêóéÄªÇª¹¡£
		ª³ªÎ«á«½«Ã«Éªò÷×ª¸Ôğª¿socket handleªÏï×ÜÃüòÔğéÄÔ²ªÇªÎªßŞÅªÃªÆ¡¢I/O?×âªòâÄú¼ª¹ªëª³ªÈªÏĞ×ò­ªÇª¹¡£ÜùíÂéÄª¬ª¢ªêÔğªëª«ªéªÇª¹¡£
		\param remoteHostID «½«±«Ã«Èï×ÜÃªòÔğªëPeerªÎHostIDªÇª¹¡£HostID_ServerªÎíŞùê¡¢«µ?«Ğ?ªËïÈ?ªµªìª¿«½«±«Ã«Èï×ÜÃªòÔğªŞª¹¡£
		\param output ª³ª³ªËï×ÜÃª¬?ª¿ªµªìªŞª¹¡£
		\return remoteHostID ö·ª¬êó?ªÊíŞùê¡¢trueªÇª¹¡£ 

		\~
		*/
		virtual bool GetSocketInfo(HostID remoteHostID,CSocketInfo& output) = 0;

		/**
		\~korean
		CNetClientÀ» »ç¿ëÇÏ´Â ÀÀ¿ëÇÁ·Î±×·¥ »óÅÂ¸¦ CNetClient¿¡°Ô Àü´ŞÇÕ´Ï´Ù.
		CNetClient¸¦ ·»´õ¸µ ·çÇÁ¿Í ´Ù¸¥ ½º·¹µå¿¡¼­ ½ÇÇà½ÃÅ°´Â °ÔÀÓÀÇ °æ¿ì ÇÁ·¹ÀÓ ·¹ÀÌÆ®¸¦ CNetClient°¡ Á÷Á¢ »êÃâÇÒ ¼ö ¾ø¾î¼­ »ç¿ëÀÚ°¡ ±»ÀÌ ÃøÁ¤ÇØ¾ß ÇÕ´Ï´Ù.
		- ¾Æ¹«¶§³ª È£ÃâÇØµµ ¼º´É¿¡ ¿µÇâÀ» °ÅÀÇ ¾ÈÁİ´Ï´Ù.
		- ÀÌ ¸Ş¼­µå´Â ´Ù¾çÇÑ ±â´É, °¡·É <a target="_blank" href="http://guide.nettention.com/cpp_ko#super_peer" >Super Peer(¼öÆÛÇÇ¾î È¤Àº È£½ºÆ®) Áß½ÉÀÇ P2P ³×Æ®¿öÅ·</a> ±â´É µî¿¡¼­ »ç¿ëÇÕ´Ï´Ù.

		\~english
		Passes the status of application program that uses CNetClient to CNetClient
		User must measure the frame rate of the game that runs CNetClient in diffrent thread to rendering loop since it cannot be acquired directly by CNetClient.

		- Does not affect performance even called at any time
		- Various functions of this method can be used, e.g. <a target="_blank" href="http://guide.nettention.com/cpp_en#super_peer" >P2P Networking for Super Peer (Super Peer or host)</a> function.

		\~chinese
		? CNetClient%??ŞÅéÄ CNetClient%îÜ?éÄïïßí??¡£
		î¤àÂæøloopûúĞìöâ?ïï?ú¼îÜêı?îÜ?ı¦£¬ CNetClient%ÜôÒöòÁïÈß©õó?áã£¬ì×ó®éÄ?ìéïÒé©?ú¼?ïÒ¡£
		- Ùé?ä§??ı¦û¼Ğ££¬?éÍàõÒö?ûºÜô?ßæç¯?¡£
		- ó®Û°ÛöãÀî¤ÊÀ?ÍíÒö£¬ÖÇåıî¤<a target="_blank" href="http://guide.nettention.com/cpp_zh#super_peer" >Super Peer(ûäñ«Ïõ) ñéãıîÜP2P÷×ãá</a>%ÍíÒöÔõ×ìŞÅéÄ¡£
		\~
		\~japanese
		CNetClientªòŞÅéÄª¹ªë«¢«×«ê«±?«·«ç«óªÎ?÷¾ªòCNetClientªË?Ó¹ª·ªŞª¹¡£
		CNetClientªò«ì«ó«À?«ê«ó«°«ë?«×ªÈöâªÎ«¹«ì«Ã«ÉªÇ?ú¼ªµª»ªë«²?«àªÎíŞùê¡¢«Õ«ì?«à«ì?«ÈªòCNetClientª¬òÁïÈß©õóªÇª­ªº¡¢«æ?«¶?ª¬ª¢ª¨ªÆö´ïÒª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£ 
		- ª¤ªÄû¼ªÓõóª·ªÆªâàõÒöªËªÛªÜç¯úÂªò?ª¨ªŞª»ªó¡£
		- ª³ªÎ«á«½«Ã«ÉªÏÒı?ªÊÑ¦Òö¡¢?ªË\ref super_peer Ñ¦ÒöªÊªÉªÇŞÅéÄª·ªŞª¹¡£ 
\~
		*/
		virtual void SetApplicationHint(const CApplicationHint &hint) = 0;

		/**
		\~korean
		»ç¿ëÀÚ Á¤ÀÇ ¸Ş½ÃÁö¸¦ Àü¼ÛÇÕ´Ï´Ù. ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#send_user_message" >RMI¸¦ ÀüÇô ¾È¾²°í »ç¿ëÀÚ Á¤ÀÇ ¸Ş½ÃÁö¸¦ ÁÖ°í ¹Ş±â</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.
		\param remotes ¼ö½ÅÀÚ ¹è¿­ÀÔ´Ï´Ù. RMI¿Í ¸¶Âù°¡Áö·Î, Å¬¶óÀÌ¾ğÆ®, ¼­¹ö(HostID_Server), <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> µîÀ» ³ÖÀ» ¼ö ÀÖ½À´Ï´Ù.
		\param remoteCount ¼ö½ÅÀÚ ¹è¿­ Å©±â
		\param rmiContext ¼Û½Å ºÎ°¡Á¤º¸. ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#protocol_overview" >ProudNetÀÇ ÇÁ·ÎÅäÄİ Á¾·ù</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.
		\param payload º¸³¾ ¸Ş½ÃÁö µ¥ÀÌÅÍ
		\param payloadLength º¸³¾ ¸Ş½ÃÁö µ¥ÀÌÅÍÀÇ ±æÀÌ. ¹ÙÀÌÆ® ´ÜÀ§ÀÔ´Ï´Ù.

		\~english
		Send user defined message. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#send_user_message" >Exchanging user-defined message without using RMI at all</a> for more detail
		\param remotes Receiver array. You can put client, server(HostID_Server), <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>, etc like RMI.
		\param remoteCount Size of receiver array
		\param rmiContext Additional information of sending. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#protocol_overview" >Protocol type of ProudNet</a>
		\param payload Message data for sending.
		\param payloadLength Length of sending message data. It is byte.

		\~chinese
		?áêéÄ?ïÒ?ãáãÓ¡£????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#send_user_message" >èÇîïÜôŞÅéÄRMIÎß?éÄ?ïÒ?ãáãÓ</a>%¡£
		\param remotes â¥ãáíº??¡£?RMIìé?£¬Ê¦ì¤?ìıclient£¬Ü×?Ğï£¨HostID_Server£©£¬<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%Ôõ¡£
		\param remoteCount â¥ãáíº??ÓŞá³¡£
		\param rmiContext ?áêãáãÓİ¾Ê¥ãáãÓ¡£????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#protocol_overview" >ProudNet îÜ??????</a>%¡£
		\param payload é©?áêîÜãáãÓ?Ëß¡£
		\param payloadLength é©?áêîÜãáãÓ?Ëß?Óø¡£Byte ?êÈ¡£
		\~
		\~japanese
		«æ?«¶?ïÒëù«á«Ã«»?«¸ªò?áêª·ªŞª¹¡£ßÙª·ª¯ªÏ¡¢\ref send_user_messageªòª´?ğÎª¯ªÀªµª¤¡£
		\param remotes áôãáíºÛÕÖªªÇª¹¡£RMIªÈÔÒ?ªË¡¢«¯«é«¤«¢«ó«È¡¢«µ?«Ğ?(HostID_Server)¡¢\ref p2p_groupªÊªÉªòìıªìªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\param remoteCount áôãáíºÛÕÖª«µ«¤«º
		\param rmiContext áêãáÜõÊ¥ï×ÜÃ¡£ßÙª·ª¯ªÏ¡¢\ref protocol_overviewªòª´?ğÎª¯ªÀªµª¤¡£
		\param payload áêªë«á«Ã«»?«¸«Ç?«¿
		\param payloadLength áêªë«á«Ã«»?«¸«Ç?«¿ªÎíşªµ¡£«Ğ«¤«È?êÈªÇª¹¡£
\~
		*/
		virtual bool SendUserMessage(const HostID* remotes, int remoteCount, const RmiContext &rmiContext, uint8_t* payload, int payloadLength) = 0;

		/**
		\~korean
		»ç¿ëÀÚ Á¤ÀÇ ¸Ş½ÃÁö¸¦ Àü¼ÛÇÕ´Ï´Ù. ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#send_user_message" >RMI¸¦ ÀüÇô ¾È¾²°í »ç¿ëÀÚ Á¤ÀÇ ¸Ş½ÃÁö¸¦ ÁÖ°í ¹Ş±â</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.
		\param remote ¼ö½ÅÀÚ
		\param rmiContext ¼Û½Å ºÎ°¡Á¤º¸. ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#protocol_overview" >ProudNetÀÇ ÇÁ·ÎÅäÄİ Á¾·ù</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.
		\param payload º¸³¾ ¸Ş½ÃÁö µ¥ÀÌÅÍ
		\param payloadLength º¸³¾ ¸Ş½ÃÁö µ¥ÀÌÅÍÀÇ ±æÀÌ. ¹ÙÀÌÆ® ´ÜÀ§ÀÔ´Ï´Ù.

		\~english
		Sending user defined message. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#send_user_message" >Exchanging user-defined message without using RMI at all</a> for more detail.
		\param remote receiver
		\param rmiContext Additional information of sending. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#protocol_overview" >Protocol type of ProudNet</a>.
		\param payload Message data for sending.
		\param payloadLength Length of sending message data. It is byte.

		\~chinese
		?áêéÄ?ïÒ?ãáãÓ¡£????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#send_user_message" >èÇîïÜôŞÅéÄRMIÎß?éÄ?ïÒ?ãáãÓ</a>%¡£
		\param remote â¥ãáíº
		\param rmiContext ?áêãáãÓİ¾Ê¥ãáãÓ¡£????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#protocol_overview" >ProudNet îÜ??????</a>%¡£
		\param payload é©?áêîÜãáãÓ?Ëß¡£
		\param payloadLength é©?áêîÜãáãÓ?Ëß?Óø¡£Byte ?êÈ¡£

		\~japanese
		«æ?«¶?ïÒëù«á«Ã«»?«¸ªò?áêª·ªŞª¹¡£ßÙª·ª¯ªÏ¡¢\ref send_user_messageªòª´?ğÎª¯ªÀªµª¤¡£
		\param remote áôãáíº
		\param rmiContext áêãáÜõÊ¥ï×ÜÃ¡£ßÙª·ª¯ªÏ¡¢\ref protocol_overviewªòª´?ğÎª¯ªÀªµª¤¡£
		\param payload áêªë«á«Ã«»?«¸«Ç?«¿
		\param payloadLength áêªë«á«Ã«»?«¸«Ç?«¿ªÎíşªµ¡£«Ğ«¤«È?êÈªÇª¹¡£

		\~
		*/
		inline bool SendUserMessage(HostID remote, const RmiContext &rmiContext, uint8_t* payload, int payloadLength)
		{
			return SendUserMessage(&remote,1,rmiContext,payload,payloadLength);
		}

		/** \~korean Coalesce intervalÀ» ¼öµ¿À¸·Î ¼³Á¤ÇÕ´Ï´Ù.
		ProudNet ÀÚÃ¼¿¡¼­ ¼³Á¤µÇ´Â ³×Æ®¿öÅ© Ç°Áú ±â¹İ µ¥ÀÌÅÍ ¹¶ÃÄ º¸³»´Â ±â´ÉÀÌ ¿øÇÏÁö ¾Ê´Â Ç°ÁúÀÌ ³ª¿Ã¶§ »ç¿ëÇÏ½Ê½Ã¿À.
		ÀûÀıÇÏÁö ¾ÊÀº °ªÀ» ÀÔ·ÂÇÒ °æ¿ì ÀÇµµÇÏÁö ¾ÊÀº °á°ú°¡ ÃÊ·¡µÉ ¼ö ÀÖÀ¸´Ï ÁÖÀÇÇÏ½Ê½Ã¿À.
		\~english Manually set coalesce interval.
		Use this function if you do not satisfy to the quality of coalesce feature of ProudNet.
		Inapprpriate use of this function may cause unexpected behavior, so care must be taken.

		\~japanese
		Coalesce intervalªòâ¢ÔÑªÇàâïÒª·ªŞª¹¡£
		ProudNet í»?ªÇàâïÒªµªìªë«Í«Ã«È«ï?«¯ù¡òõĞñ÷ùªÎ«Ç?«¿ªòáêªëÑ¦Òöª¬ØĞªŞªÊª¤ù¡òõªËªÊªëãÁªËŞÅªÃªÆª¯ªÀªµª¤¡£
		îêï·ªÇªÏªÊª¤ö·ªòìıÕôª¹ªëíŞùê¡¢ëò?ª·ªÊª¤Ì¿Íıª¬?ßæª¹ªëª³ªÈª¬ª¢ªêªŞª¹ªÎªÇª´ñ¼ëòª¯ªÀªµª¤¡£

		\~
		*/
		virtual ErrorType SetCoalesceIntervalMs(HostID remote, int intervalMs) = 0;

		/** \~korean Coalesce intervalÀ» ÀÚµ¿À¸·Î ¼³Á¤ÇÕ´Ï´Ù. ÀÌ ¼³Á¤Àº µğÆúÆ®ÀÔ´Ï´Ù.
		\~english Coalesce interval set to automatic. This is default.

		\~japanese
		Coalesce intervalªòí»ÔÑàâïÒª·ªŞª¹¡£ª³ªÎàâïÒªÏ«Ç«Õ«©«ë«ÈªÇª¹¡£
		\~
		*/
		virtual ErrorType SetCoalesceIntervalToAuto(HostID remote) = 0;

/**
		\~korean
		±ä±Ş ·Î±×¸¦ ±ä±Ş ·Î±× ¼öÁı ¼­¹ö(CEmergencyLogServer)·Î Àü¼ÛÇÕ´Ï´Ù. CEmergencyLogServer¸¦ ¸ÕÀú ½ÇÇàÇÏ¼Å¾ß ÇØ´ç±â´ÉÀ» ¾µ¼ö ÀÖ½À´Ï´Ù.
		- CStartServerParameter.m_clientEmergencyLogMaxLineCountÀÇ °¹¼ö¸¦ ÁöÁ¤ÇÏ¼Å¾ß ÇÕ´Ï´Ù.
		- ÀÇµµµÇÁö ¾Ê°Ô ¼­¹ö¿ÍÀÇ ¿¬°áÀÌ ²÷±ä °æ¿ì, ÇØ´çÇÔ¼ö¸¦ È£ÃâÇÏ¸é Å¬¶óÀÇ ÃÖ±Ù »óÈ²°ú ÇöÀç »óÅÂ·Î±×¸¦ CEmergencyLogServer·Î Àü¼ÛÇÕ´Ï´Ù.
		- logClient´Â ³»ºÎ¿¡¼­ »õ·Î¿î thread¸¦ »ı¼ºÇÏ¿© ·Î±× Å¬¶óÀÌ¾ğÆ®¸¦ ¸¸µé°í ¹Ù·Î ¼­¹ö·Î ·Î±×°¡ Àü¼ÛµË´Ï´Ù. µû¶ó¼­ ÀÌ ¸Ş¼­µå call ÈÄ ¹Ù·Î ¸ŞÀÎ ½º·¹µå¸¦ Á¾·áÇÏÁö ¸»¾Æ¾ß ÇÕ´Ï´Ù.
		\param serverAddr ·Î±×¼­¹ö ÁÖ¼ÒÀÔ´Ï´Ù.
		\param serverPort ·Î±×¼­¹öÀÇ Æ÷Æ®¹øÈ£ÀÔ´Ï´Ù.
		\return ¼º°ø, ½ÇÆĞ ¿©ºÎÀÔ´Ï´Ù. m_clientEmergencyLogMaxLineCount °ªÀÌ 0ÀÎ °æ¿ì°¡ ÀÌ¿¡ÇØ´çµË´Ï´Ù.

		\~english TODO:translate needed.
		The emergency log is transmitted to the emergency log collection server (CEmergencyLogServer). You have to run CEmergencyLogServer first in order to use its feature. 	
		- You have to designate the number of CStartServerParameter.m_clientEmergencyLogMaxLineCount. 
		- When the connection to the server is lost unintentionally, the current status log as well as the latest status of the client is transmitted to CEmergencyLogServer. 
		- logClient generates a new thread inside and create a log client and the log is directly transmitted to the server. Therefore, you must not end the main thread after calling this method. 
		\param serverAddr This is the address of the log server. 
		\param serverPort This is the port number of the log server. 
		\return This is either success or failure. The case when the value of m_clientEmergencyLogMaxLineCount is 0 falls under this case. 


		\~chinese
		÷ê?Ğálog?áêÓğ?Ğálogâ¥ó¢Ü×?Ğï£¨CEmergencyLogServer£©¡£é©à»?ú¼ CEmergencyLogServer%î¦ÒöŞÅéÄó®ÍíÒö¡£
		- é©ò¦ïÒ CStartServerParameter.m_clientEmergencyLogMaxLineCount%îÜ??¡£
		- Şªëò?îÜ???ïÈîÜ?ı¦£¬û¼Ğ£ßÓ?ùŞ?îÜ?£¬èÙ CEmergencyLogServer%?áêclientîÜõÌĞÎ??ûú?î¤??log¡£
		- logClientî¤?İ»ßæà÷ãæthread??Ëïlog client£¬Ø¡?èÙÜ×?Ğï?áêlog¡£ì×ó®î¤û¼Ğ£ó®Û°Ûöı¨£¬?Üôé©Ø¡??ò­ñ«?ïï¡£
		\param serverAddr logÜ×?Ğïò¢ò£¡£
		\param serverPort logÜ×?ĞïÓ®Ï¢??¡£
		\return à÷Íí?Üú¡£ m_clientEmergencyLogMaxLineCount ãÀ0îÜï×??éÍó®¡£

		\~japanese
		ÑÌĞá«í«°ªòÑÌĞá«í«°?ó¢«µ?«Ğ?(CEmergencyLogServer)ªË?áêª·ªŞª¹¡£CEmergencyLogServerªòà»ªË?ú¼ª·ªÆª«ªéú±?Ñ¦ÒöªòŞÅª¦ª³ªÈª¬ªÇª­ªŞª¹¡£		
		- CStartServerParameter.m_clientEmergencyLogMaxLineCountªÎ?ªòò¦ïÒª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
		- ëò?ª»ªºªË«µ?«Ğ?ªÈªÎïÈ?ª¬ï·ªìª¿íŞùê¡¢ú±???ªòû¼ªÓõóª¹ªÈ«¯«é«¤«¢«ó«ÈªÎõÌĞÎ?üÏªÈúŞî¤?÷¾«í«°ªòCEmergencyLogServerªË?áêª·ªŞª¹¡£
		- logClientªÏ?İ»ªÇãæª·ª¤«¹«ì«Ã«Éªòßæà÷ª·ªÆ«í«°«¯«é«¤«¢«ó«ÈªòíÂªÃªÆª¹ª°«µ?«Ğ?ªË«í«°ª¬?áêªµªìªŞª¹¡£ªèªÃªÆ¡¢ª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª·ª¿ı­¡¢ª¹ª°«á«¤«ó«¹«ì«Ã«ÉªòğûÖõª·ªÆªÏª¤ª±ªŞª»ªó¡£
		\param serverAddr «í«°«µ?«Ğ?«¢«É«ì«¹ªÇª¹¡£
		\param serverPort «í«°«µ?«Ğ?ªÎ«İ?«ÈÛã?ªÇª¹¡£
		\return à÷Íí¡¢ã÷ø¨Ê¦ÜúªÇª¹¡£m_clientEmergencyLogMaxLineCount ö·ª¬0ªÇª¢ªëíŞùêª¬ª³ªìªËú±?ª·ªŞª¹¡£

		\~
		*/
		#if defined(_WIN32)
		virtual bool SendEmergencyLogData(String serverAddr, uint16_t serverPort) = 0;
		#endif

		virtual AddrPort GetTcpLocalAddr() = 0;
		virtual AddrPort GetUdpLocalAddr() = 0;

		virtual String TEST_GetDebugText() = 0;
		virtual void TEST_GetTestStats(CTestStats2 &output) = 0;

		// ACR test¿ë
		virtual void TEST_FakeTurnOffSendAndReceive() = 0;
		virtual void TEST_SetAutoConnectionRecoverySimulatedDelay(int timeMs) = 0;

#ifdef TEST_DISCONNECT_CLEANUP
		virtual bool IsAllCleanup() = 0;
#endif
		/**
		\~korean
		»ç¿ëÀÚ°¡ ÁöÁ¤ÇÑ ´Ù¸¥ P2P peer¿ÍÀÇ Åë½ÅÀ» °­Á¦·Î relay·Î µÇ°Ô ÇÒÁö¸¦ ÁöÁ¤ÇÏ´Â ÇÔ¼öÀÔ´Ï´Ù.

		ÀÌ ±â´ÉÀÌ ¿ä±äÇÏ°Ô ¾²ÀÌ´Â °æ¿ì´Â ´ÙÀ½°ú °°½À´Ï´Ù.
		- Å¬¶óÀÌ¾ğÆ®ÃøÀÇ P2P Åë½Å·®ÀÌ °ú´ÙÇØ¼­, ¸î¸î P2P peer¿ÍÀÇ Åë½ÅÀº relay·Î ÀüÈ¯ÇÏ°íÀÚ ÇÒ °æ¿ì
		\param remotePeerID Relay ÀüÈ¯½ÃÅ³ Peer ÀÇ HostID°ªÀÔ´Ï´Ù.
		\param enable trueÀÌ¸é °­Á¦ relay ¸¦ ÄÕ´Ï´Ù.

		\~english TODO:translate needed.
		This is the function to designate whether the communication with other P2P peers designated by the user should be forced to relay. The following are the cases where this feature comes handy. 
		- When the P2P traffic from the client side is excessive so you want to convert some communication with some P2P peers to relay;
		\param remotePeerID The HostID value of the peer to be converted to relay
		\param enable If true is enabled, forced relay is turned on. 

		\~chinese
		ãÀò¦ïÒãÀÜú?éÄ?ò¦ïÒîÜ?ĞìöâP2P Peer?îÜ÷×ãáË­ğ¤?ú¼relayîÜùŞ?¡£
		Òö?êóüùŞÅéÄĞìÍíÒöîÜ??åıù»¡£
		ËÔ?Ó®îÜP2P÷×ãáÕá?Òı?£¬ßÌ???P2P Peer?îÜ÷×ãá??à÷relayîÜ?ı¦¡£
		\param remotePeerID Relayé©??îÜPeerîÜHostID?¡£
		\param enable åıÍıãÀtrue???Ë­ğ¤relay¡£

		\~japanese
		«æ?«¶?ª¬ò¦ïÒª·ª¿öâªÎP2P PeerªÈªÎ÷×ãáªò?ğ¤ªËrelayª¹ªëª«ªòò¦ïÒª¹ªë??ªÇª¹¡£ª³ªÎÑ¦Òöª¬êó?ªËŞÅªïªìªëíŞùêªÏó­ªÎ÷×ªêªÇª¹¡£
		- «¯«é«¤«¢«ó«Èö°ªÎP2P÷×ãáÖùª¬ÒıÎ¦ª®ªÆ¡¢ª¤ª¯ªÄª«ªÎP2P PeerªÈªÎ÷×ãáªÏrelayªËï·ªêôğª¨ª¿ª¤íŞùê¡¢
		\param remotePeerID Relay ï·ªêôğª¨ªëPeerªÎHostIDö·ªÇª¹¡£
		\param enable trueªÇª¢ªìªĞ?ğ¤relayªòªÄª±ªŞª¹¡£

		\~
		*/
		virtual ErrorType ForceP2PRelay(HostID remotePeerID, bool enable) = 0;

		/**
		\~korean
		ÀÏ¹İÀûÀÎ ¿Â¶óÀÎ °ÔÀÓ¿¡¼­´Â unreliable ¸Ş½ÃÂ¡ÀÌ ÀüÃ¼ Æ®·¡ÇÈÀÇ ´ëºÎºĞÀ» Â÷ÀÌÁöÇÔ¿¡ µû¶ó ±âÁ¸ unreliable ¸Ş½ÃÂ¡ ±â´É¿¡ Æ®·¡ÇÈ ·Î½ºÀ²À» ¾ò´Â ±â´ÉÀ» Ãß°¡ÇÕ´Ï´Ù.
		ÆĞÅ¶ ·Î½ºÀ² ÃøÁ¤±â
		\param remoteHostID ¾î´À remote ¿ÍÀÇ Åë½Å¿¡ ´ëÇÑ ·Î½ºÀ²À» ¾òÀ» °ÈÀÎÁö. ÀÚ±â ÀÚ½Å peer, server ¹¹µçÁö ÀÔ·Â °¡´ÉÇÕ´Ï´Ù. ÀÚ±â ÀÚ½ÅÀÌ¸é 0% ÀÔ´Ï´Ù
		\param outputPercent ÆĞÅ¶ ·Î½ºÀ²À» %´ÜÀ§·Î Ã¤¿öÁü(Áï 0~100)

		\~english TODO:translate needed.
		As unreliable messaging takes most of the entire traffic in common on-line games, we add the feature to get the traffic loss rate in the existing unreliable messaging feature. 
		Packet loss rate measuring device
		\param remoteHostID Which loss rate with communication with which remote would be obtained. You can input anything, including your own peer, server, etc. If it is itself, it is 0%
		\param outputPercent The packet loss rate is filled up in % unit (i.e., 0 to 100) 

		\~chinese
		î¤ìéÚõî¤?êı?ñé?UnreliableãáãÓîÜ??÷×ãáÕáï¿Ëß?ÓŞİ»İÂ?£¬î¤ê«êóUnreliableãáãÓÍíÒöß¾ôÕÊ¥?Ôğ÷×ãáÕáLossáãîÜÍíÒö¡£
		?ËßøĞLossáã?ïÒ?¡£
		\param remoteHostID é©?Ôğ??ìé?remote?îÜ÷×ãáLossáã£¬Ê¦ì¤?ìıåıí»ãóPeer£¬server Ôõ¡£åıÍıãÀí»ĞùîÜ???0%¡£
		\param outputPercent  ?ËßøĞîÜLossáã?ì¤%?êÈ?õö£¬£¨?0~100£©
		
		\~japanese
		ìéÚõîÜªË«ª«ó«é«¤«ó«²?«àªÇªÏunreliable«á«Ã«»?«¸«ó«°ª¬îï?«È«é«Õ«£«Ã«¯ªÎªÛªÈªóªÉªòï¿ªáªŞª¹ªÎªÇ¡¢?ğíªÎunrelable«á«Ã«»?«¸«ó«°Ñ¦ÒöªË«È«é«Õ«£«Ã«¯«í«¹áãªòÔğªëÑ¦ÒöªòõÚÊ¥ª·ªŞª¹¡£
		«Ñ«±«Ã«È«í«¹áãö´ïÒÑ¦
		\param remoteHostID ªÉªÎremoteªÈªÎ÷×ãáªË?ª¹ªë«í«¹áãªòÔğªëª«¡£í»Ğùí»ãóªÎpeer¡¢serverù¼ªÇªâìıÕôÊ¦ÒöªÇª¹¡£í»Ğùí»ãóªÇª¢ªìªĞ0%ªÇª¹¡£
		\param outputPercent «Ñ«±«Ã«È«í«¹áãª¬%?êÈªÇ?ª¿ªµªìªŞª¹(?ªÁ¡¢0~100)

		\~
		*/
		virtual ErrorType GetUnreliableMessagingLossRatioPercent(HostID remotePeerID, int *outputPercent) = 0;

		virtual void HolsterMoreCallbackUntilNextFrameMove() = 0;
	};

	PROUD_API const PNTCHAR* ToString(ConnectionState cs);

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

	/**  @} */

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif
