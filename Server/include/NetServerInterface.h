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

#include "BasicTypes.h"
#include "HostIDArray.h"
#include "AddrPort.h"
#include "Enums.h"
#include "EncryptEnum.h"
#include "RMIContext.h"
#include "ErrorInfo.h"
#include "ServerParam.h"
#include "NetServerStats.h"
#include "NetClientInterface.h"
#include "LambdaEventHandler.h"
#include "acr.h"

#define PN_DEPRECATED /*__declspec(deprecated) */

#ifdef _MSC_VER
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
	class CNetClientInfo;
	class CP2PGroup;
	class CP2PGroups;
	class CSendFragRefs;
	class ErrorInfo;
	class INetClientEvent;
	class INetServerEvent;
	class IRmiProxy;
	class IRmiStub;
	class ReliableUdpHostStats;
	struct SendOpt;





	/**
	\~korean
	\brief GetSuitableSuperPeerRankListInGroup¿¡¼­ Ã¤¿öÁö´Â ¹è¿­ÀÇ °¢ ¿ø¼ÒÀÔ´Ï´Ù.

	\~english
	\brief Each element of array filled at GetSuitableSuperPeerRankListInGroup

	\~chinese
	\brief î¤GetSuitableSuperPeerRankListInGroup?õöîÜ?ËßÊÀêªáÈ¡£

	\~japanese
	\brief GetSuitableSuperPeerRankListInGroupªÇ?ª¿ªµªìªëÛÕÖªªÎÊÀêªáÈªÇª¹¡£
	\~
	*/
	struct SuperPeerRating
	{
		/**
		\~korean
		P2P ±×·ì ³»ÀÇ ÇÇ¾î ID ÀÔ´Ï´Ù.

		\~english
		Peer ID in P2P group

		\~chinese
		P2P??îÜpeerID¡£

		\~japanese
		P2P«°«ë?«×?ªÎPeer IDªÇª¹¡£
		\~
		*/
		HostID m_hostID;

		/**
		\~korean
		ÀÌ ÇÇ¾î ID°¡ ¼öÆÛÇÇ¾î Àû°İ °Ë»ç¿¡¼­ ¾òÀº Á¡¼öÀÔ´Ï´Ù.
		ÀÌ Ç×¸ñÀÌ Æ÷ÇÔµÈ ¹è¿­ÀÇ ´Ù¸¥ ¿ø¼Ò¿Í ºñ±³ÇßÀ»¶§ °ªÀÌ Å¬¼ö·Ï ¼öÆÛÇÇ¾î·Î¼­ÀÇ Àû°İ ¼öÁØÀÌ ³ôÀ½À» ÀÇ¹ÌÇÕ´Ï´Ù.

		\~english
		Result from superpeer qualified testing by this peer ID.
		If value is bigger than others, it means, it is close to qualification of superpeer

		\~chinese
		ó®peer IDî¤superpeerîÜùêÌ«??ñé?ÔğîÜİÂ?¡£
		?øĞùßó®?ÙÍîÜ??îÜĞìöâêªáÈßÓİï?îÜ?£¬ó®?êÆÓŞëòÚ«ó·ì¤superpeerîÜ?Ì«â©ñ×êÆÍÔ¡£

		\~japanese
		ª³ªÎPeer IDª¬Super PeerîêÌ«?ŞÛª«ªéÔğª¿ïÃ?ªÇª¹¡£
		ª³ªÎú£ÙÍª¬ùßªŞªìª¿ÛÕÖªªÎöâªÎêªáÈªÈİïÎòª·ª¿ãÁ¡¢ö·ª¬ÓŞª­ª¤ªÛªÉSuper PeerªÈª·ªÆªÎîêÌ««ì«Ù«ëª¬ÍÔª¤ª³ªÈªòëòÚ«ª·ªŞª¹¡£

		\~
		*/
		double m_rating;

		/**
		\~korean
		¼­¹ö¿ÍÀÇ UDP Åë½ÅÀÌ ¼º»çµÇ°í ÀÖÀ¸¸é trueÀÔ´Ï´Ù. ¼­¹ö¿ÍÀÇ UDP°¡ µÇ¾î¾ß ¿øÈ°ÇÑ P2P Åë½ÅÀ» ±â´ëÇÒ ¼ö ÀÖ½À´Ï´Ù.

		\~english
		If it communicates to server with UDP, it is true. You can expect reliable P2P if it communicates with UDP

		\~chinese
		?Ü×?ĞïîÜUDP÷×ãáà÷ÍíîÜ?true¡£?Ü×?ĞïîÜUDPà÷Ííî¦ÒöÑ¢Óâ?××îÜP2P÷×ãá¡£

		\~japanese
		«µ?«Ğ?ªÈªÎUDP÷×ãáªËà÷Ííª·ª¿ªétrueªÇª¹¡£«µ?«Ğ?ªÈªÎUDPª¬ªÇª­ªÆª³ª½å÷üÁªÊP2P÷×ãáªòÑ¢Óâª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\~
		*/
		bool m_realUdpEnabled;

		/**
		\~korean
		°øÀ¯±â µÚ¿¡ ÀÖ´Â È£½ºÆ®ÀÌ¸é trueÀÔ´Ï´Ù. °øÀ¯±â°¡ ¾ø´Â È£½ºÆ®ÀÎ °æ¿ì ¿øÈ°ÇÑ ¼öÆÛÇÇ¾î ¿ªÇÒÀ» ±â´ëÇÒ ¼ö ÀÖ½À´Ï´Ù.

		\~english
		If it locates behind of router then it is true. You can expect relialbe superpeer when host does not use router

		\~chinese
		ÖØë¦Ğïı¨ØüîÜñ«ÏõîÜ?ãÀtrue¡£?êóÖØë¦ĞïîÜñ«ÏõîÜ?ÜôÒöÑ¢ÓâsuperpeerîÜíÂéÄ¡£

		\~japanese
		«ë?«¿?ªÎı­ªíªËª¢ªë«Û«¹«ÈªÊªétrueªÇª¹¡£«ë?«¿?ªÎªÊª¤«Û«¹«ÈªÎíŞùê¡¢å÷üÁªÊSuper PeeræµùÜªòÑ¢Óâª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\~
		*/
		bool m_isBehindNat;

		/**
		\~korean
		ÃÖ±Ù Å¬¶óÀÌ¾ğÆ®-¼­¹ö°£ ·¹ÀÌÅÏ½ÃÀÔ´Ï´Ù. ¹Ğ¸®ÃÊ ´ÜÀ§ÀÔ´Ï´Ù. Å¬¼ö·Ï ¼öÆÛÇÇ¾î·Î¼­ÀÇ ¿ªÇÒÀ» ±â´ëÇÏ±â ¾î·Æ½À´Ï´Ù.

		\~english
		Latency between client to server. It is a second unit. If it is high, do not except working as superpeer

		\~chinese
		õÌĞÎclient-Ü×?Ğïñı?latency¡£ûÆõ©?êÈ¡£êÆÓŞêÆ?Ñ¢ÓâíÂ?superpeerîÜíÂéÄ¡£

		\~japanese
		õÌĞÎ¡¢«¯«é«¤«¢«ó«È«µ?«Ğ?ÊàªÎ«ì?«Æ«ó«·?ªÇª¹¡£«ß«êõ©?êÈªÇª¹¡£ÓŞª­ª¤ªÛªÉSuper PeerªÈª·ªÆªÎæµùÜªòÑ¢Óâª·ªËª¯ª¤ªÇª¹¡£
		\~
		*/
		int m_recentPingMs;

		/**
		\~korean
		Å¸ ÇÇ¾î¿ÍÀÇ Æò±Õ ·¹ÀÌÅÏ½ÃÀÔ´Ï´Ù. ¹Ğ¸®ÃÊ ´ÜÀ§ÀÔ´Ï´Ù. Å¬¼ö·Ï ¼öÆÛÇÇ¾î·Î¼­ÀÇ ¿ªÇÒÀ» ±â´ëÇÏ±â ¾î·Æ½À´Ï´Ù.

		\~english
		Average latency with other peers. It is a second unit. If it is high, do not except working as superpeer

		\~chinese
		?ĞìöâpeerîÜøÁĞ³latency¡£ûÆõ©?êÈ¡£êÆÓŞêÆ?Ñ¢ÓâíÂ?superpeerîÜíÂéÄ¡£

		\~japanese
		öâªÎPeerªÈªÎøÁĞ³«ì?«Æ«ó«·?ªÇª¹¡£«ß«êõ©?êÈªÇª¹¡£ÓŞª­ª¤ªÛªÉSuper PeerªÈª·ªÆªÎæµùÜªÏÑ¢Óâª·Ññª¤ªÇª¹¡£
		\~
		*/
		int64_t m_P2PGroupTotalRecentPingMs;

		/**
		\~korean
		¼Û½Å ÃÖ´ë °¡´É ¼ÓµµÀÔ´Ï´Ù.
		ºÎµ¿¼Ò¼öÁ¡ Å¸ÀÔÀÌÁö¸¸, ¹ÙÀÌÆ® ´ÜÀ§ÀÔ´Ï´Ù. (1 ¹Ì¸¸ÀÇ Åë½Å·®µµ Ã¼Å©ÇÏ±â À§ÇØ¼­) Å¬¼ö·Ï ¼öÆÛÇÇ¾î·Î¼­ÀÇ ¿ªÇÒÀ» ±â´ëÇÒ ¼ö ÀÖ½À´Ï´Ù.

		\~english
		Maximum sending speed.
		It is a floating-point type but byte. (to check traffic that under 1) If it is high, you can except working as superpeer

		\~chinese
		?áêãáãÓõÌÓŞÊ¦ÒöáÜÓø¡£
		İ©ïÃá³?ïÃ?úş£¬byte?êÈ¡££¨?Öõå¥é©??Ú±?1îÜ÷×ãáÕá£©êÆÓŞÊ¦ì¤Ñ¢ÓâíÂ?superpeerîÜíÂéÄ¡£

		\~japanese
		áêãáõÌÓŞÊ¦ÒöáÜÓøªÇª¹¡£
		ÜôÔÑá³?ïÃ«¿«¤«×ªÇª¹ª¬¡¢«Ğ«¤«È?êÈªÇª¹¡£(1Ú±?ªÎ÷×ãáÕáªâ«Á«§«Ã«¯ª¹ªëª¿ªáªË)ÓŞª­ª¤ªÛªÉSuper PeerªÈª·ªÆªÎæµùÜªòÑ¢Óâª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£

		\~
		*/
		double m_sendSpeed;

		/**
		\~korean
		P2P ±×·ì¿¡ µé¾î¿Â ÈÄ Áö³­ ½Ã°£ÀÔ´Ï´Ù.
		ÀÌ¹Ì ´Ù¸¥ ÇÇ¾î°¡ ¼öÆÛÇÇ¾îÀÏ¶§ ÀÌ ÇÇ¾î°¡ ¼öÆÛÇÇ¾î·Î ÀüÈ¯µÇ´Â°Ç ¼º±ŞÇÒ ¼ö ÀÖ½À´Ï´Ù.

		\~english
		Past time that after joined P2P group.
		If other peer is already superpeer it may hasty to change superpeer

		\~chinese
		?ìıP2P?ı¨??îÜ??¡£
		ì«?ãÀĞìöâpeer?superpeerîÜ?ı¦£¬ó®peer???superpeerÊ¦Òö?êóïÃàõĞá¡£

		\~japanese
		P2P«°«ë?«×ªËìıªÃªÆª«ªéÎ¦ª®ª¿ãÁÊàªÇª¹¡£
		?ªËöâªÎPeerª¬Super PeerªÇª¢ªëãÁ¡¢ª³ªÎPeerª¬Super PeerªËï·ªêôğªïªëª³ªÈªÏªÁªçªÃªÈáÜª¤ª«ªâò±ªìªŞª»ªó¡£

		\~
		*/
		int64_t m_JoinedTime;

		/**
		\~korean
		»ç¿ëÀÚ¿¡ ÀÇÇØ ÀÔ·ÂµÈ ÃÊ´ç ÇÁ·¹ÀÓ °¹¼ö(frame rate)ÀÔ´Ï´Ù. Proud.CNetClient.SetApplicationHint ¿¡¼­ ÀÔ·ÂµË´Ï´Ù.

		\~english
		Frame rate (second) that entered by user. It enters at Proud.CNetClient.SetApplicationHint

		\~chinese
		ù¬éÄ??ìıîÜØßõ©?îÜ??£¨frame rate£©¡£î¤ Proud.CNetClient.SetApplicationHint%×ì?ìı¡£

		\~japanese
		«æ?«¶?ªËªèªÃªÆìıÕôªµªìª¿õ©?ª¿ªê«Õ«ì?«à?(frame rate)ªÇª¹¡£Proud.CNetClient.SetApplicationHintªÇìıÕôªµªìªŞª¹¡£
		\~
		*/
		double m_frameRate;
	};

	/**
	\~korean
	\brief ¼öÆÛ ÇÇ¾î ¼±Á¤ Á¤Ã¥

	\~english
	\brief super peer selection policy

	\~chinese
	\brief superpeer?ïÒïÙóş¡£

	\~japanese
	\brief Super PeeràÔïÒ«İ«ê«·?
	\~
	*/
	class CSuperPeerSelectionPolicy
	{
	public:

		/**
		\~korean
		¼­¹ö¿ÍÀÇ UDP Åë½ÅÀÌ ÄÑÁ®ÀÖÀ» ¶§ °¡»êÁ¡µÇ´Â °¡ÁßÄ¡. ¾ĞµµÀûÀ¸·Î °¡ÁßÄ¡°¡ ¸Å¿ì Ä¿¾ß ÇÑ´Ù.

		\~english
		The weight added when UDP communication to server is on. This weight must be overwhelming.

		\~chinese
		?Ü×?ĞïîÜUDP÷×ãá??îÜ?ı¦Ê¥İÂîÜÊ¥ñì?¡£Ê¥ñì?é©?ÓîàõîÜÓŞ¡£

		\~japanese
		«µ?«Ğ?ªÈªÎUDP÷×ãáª¬ÓŞª­ª¯ªÊªÃªÆª¤ªëãÁ¡¢Ê¥ß©ïÃªËªÊªëÊ¥ñìö·¡£?ÓîîÜªËÊ¥ñìö·ª¬ÓŞª­ª¯ªÊª±ªìªĞªÊªêªŞª»ªó¡£
		\~
		*/
		double m_realUdpWeight;
		/**
		\~korean
		ÀÎÅÍ³İ °øÀ¯±â ¾ø´Â, Áï °øÀÎ IP¸¦ Á÷Á¢ »ç¿ëÇÏ´Â Å¬¶óÀÌ¾ğÆ®¿¡ °¡»êÁ¡µÇ´Â °¡ÁßÄ¡. È¦ÆİÄª À¯ÁöÀ²ÀÌ ³ôÀ¸¹Ç·Î °¡ÁßÄ¡¸¦ ³ô°Ô Àâ´Â ÆíÀÌ ÁÁ´Ù.

		\~english
		The weight added to client that directly uses public IP - which means using no internet router. It is recommended to set this as relatively high since hole-punching rate is kept high.

		\~chinese
		?êóÖØë¦ĞïîÜ£¬??òÁïÈŞÅéÄÍë?IPîÜclientà÷?Ê¥İÂîÜÊ¥ñì?¡£öèÔ×?ò¥áãÍÔ£¬á¶ì¤?öÇÊ¥ñì?ÍÔìéïÃ?û¿¡£

		\~japanese
		«¤«ó«¿?«Í«Ã«È«ë?«¿?ªÎªÊª¤¡¢?ªÁ«Ñ«Ö«ê«Ã«¯IPªòòÁïÈŞÅª¦«¯«é«¤«¢«ó«ÈªËÊ¥ß©ïÃªËªÊªëÊ¥ñìö·¡£«Û?«ë«Ñ«ó«Á«ó«°ªÎë«ò¥áãª¬ÍÔª¤ªÎªÇÊ¥ñìö·ªòÍÔª¯ö¢ªÃª¿Û°ª¬ÕŞª¤ªÇª¹¡£
		\~
		*/
		double m_noNatDeviceWeight;
		/**
		\~korean
		¼­¹ö¿ÍÀÇ ·¹ÀÌÅÏ½Ã 1ÃÊ ºĞ·®¿¡ ´ëÇØ °¨Á¡µÇ´Â °¡ÁßÄ¡. ¼öÆÛÇÇ¾î°¡ ¼­¹ö¿ÍÀÇ Åë½ÅÀ» ÀÚÁÖ ÇÏ´Â °æ¿ì °¡ÁßÄ¡¸¦ Å©°Ô Àâ´Â °ÍÀÌ ÁÁ´Ù.

		\~english
		The weight added for each second of time of latency to server. If a super peer is communicating with server often then this must be set high.

		\~chinese
		?Ü×?ĞïîÜlatencyìéõ©İÂÕá?İÂîÜÊ¥ñì?¡£åıÍısuperpeer?ßÈ?Ü×?Ğï÷×ãáîÜ??öÇÊ¥ñì?ÍÔìéïÃ?û¿¡£

		\~japanese
		«µ?«Ğ?ªÈªÎ«ì?«Æ«ó«·?1õ©İÂÕáªË?ª·ªÆÊõïÃªËªÊªëÊ¥ñìö·¡£Super Peerª¬«µ?«Ğ?ªÈªÎ÷×ãáªòªèª¯ªäªëíŞùê¡¢Ê¥ñìö·ªòÓŞª­ª¯ö¢ªÃª¿Û°ª¬ÕŞª¤ªÇª¹¡£
		\~
		*/
		double m_serverLagWeight;
		/**
		\~korean
		Å¸ ÇÇ¾î 1°³¿ÍÀÇ ·¹ÀÌÅÏ½Ã 1ÃÊ ºĞ·®¿¡ ´ëÇØ °¨Á¡µÇ´Â °¡ÁßÄ¡. m_serverLagWeight º¸´Ù ÀÛ°Ô Àâ´õ¶óµµ ÇÇ¾îÀÇ °¹¼ö°¡ Áõ°¡ÇÒ¼ö·Ï ´ë ¼­¹ö °¡ÁßÄ¡º¸´Ù Áõ°¡ÇÑ´Ù.
		ÀÌ °ªÀº CStartServerParameter.m_enablePingTest °ªÀ» true·Î ¼³Á¤ÇÏÁö ¾ÊÀ¸¸é, °è»êµÇÁö ¾Ê½À´Ï´Ù.

		\~english
		The weight to be deducted for each second of time of latency to other peer. This increases as the number of peers increase even if set smaller than m_serverLagWeight.
		It is not calculated, if you do not set CStartServerParameter.m_enablePingTest as true.

		\~chinese
		?Ğìöâpeerìé?îÜlatencyìéõ©İÂÕá?İÂîÜÊ¥ñì?¡£?ŞÅİïm_serverLagWeight?öÇîÜá³£¬peer îÜ??êÆñòÊ¥å¥?İïÓŞÜ×?ĞïÊ¥ñì?ñòÊ¥¡£
		Üô÷ê CStartServerParameter.m_enablePingTest%??öÇà÷trueîÜ?£¬ó®?Üô?ù¬?ß©¡£

		\~japanese
		öâªÎPeer 1ËÁªÈªÎ«ì?«Æ«ó«·?1õ©İÂÕáªË?ª·ªÆÊõïÃªµªìªëÊ¥ñìö·¡£ m_serverLagWeightªèªêá³ªµª¯ö¢ªÃªÆªâPeerªÎ?ª¬?Ê¥ª¹ªëªÛªÉ?«µ?«Ğ?Ê¥ñìö·ªèªê?Ê¥ª·ªŞª¹¡£
		CStartServerParameter.m_enablePingTest ö·ªòtrueªËàâïÒª·ªÊª±ªìªĞÍªß©ªµªìªŞª»ªó¡£

		\~
		*/
		double m_peerLagWeight;
		/**
		\~korean
		¼Û½Å ¼Óµµ 10Mbps¿¡ ´ëÇØ °¡»êÁ¡µÇ´Â °¡ÁßÄ¡. °¡Á¤¿ë ÀÎÅÍ³İ¿¡¼­´Â ¾÷·Îµå ¼Óµµ°¡ ´À¸° ÆíÀÌ±â ¶§¹®¿¡ ÀÌ °¡ÁßÄ¡°¡ ÇÊ¿äÇÒ ¼öµµ ÀÖ´Ù.

		\~english
		The weight added to transmission speed of 10Mbps. This weight may be needed as home internet connection has relatively low spees for uploading.

		\~chinese
		??áêáÜÓø10MbpsÊ¥İÂîÜÊ¥ñì?¡£ì×?Ê«ïÔéÄû»??ß¾?áÜÓøø¶Ø·£¬Ê¦Òö?âÍé©ó®Ê¥ñì?¡£

		\~japanese
		áêãááÜÓø10MbpsªË?ª·ªÆÊ¥ß©ïÃªËªÊªëÊ¥ñìö·¡£Ê«ïÔéÄ«¤«ó«¿?«Í«Ã«ÈªÇªÏ«¢«Ã«×«í?«ÉáÜÓøª¬?ª¤ªÎªÇ¡¢ª³ªÎÊ¥ñìö·ª¬ù±é©ªËªÊªëª«ªâò±ªìªŞª»ªó¡£
		\~
		*/
		double m_sendSpeedWeight;
		/**
		\~korean
		»ç¿ëÀÚ°¡ ÃøÁ¤ÇÑ ÇÁ·¹ÀÓ·¹ÀÌÆ®¿ÍÀÇ °¡ÁßÄ¡ÀÔ´Ï´Ù.
		- ÇÁ·¹ÀÓ ·¹ÀÌÆ® °ª 1¿¡ ºñ·ÊÇØ¼­ ÀÌ °ªÀÌ Áõ°¡ÇÕ´Ï´Ù. ¿¹¸¦ µé¾î 60ÇÁ·¹ÀÓÀ» Àß À¯ÁöÇÏ¸é ¼öÆÛÇÇ¾î·Î¼­ Àû°İÀÌ°í 20ÇÁ·¹ÀÓ ÀÌÇÏÀÌ¸é
		¼öÆÛÇÇ¾î·Î¼­ ºÎÀûÇÕÇÏ°Ô Æò°¡ÇÏ°íÀÚ ÇÑ´Ù¸é, 4¸¦ ³ÖÀ» °æ¿ì 20ÇÁ·¹ÀÓ * 4 = 80, 60ÇÁ·¹ÀÓ*4 = 240, Áï 160ÀÇ Á¡¼öÂ÷°¡ ³ª°Ô µË´Ï´Ù.
		- ÃøÁ¤µÈ ÇÁ·¹ÀÓ ·¹ÀÌÆ®´Â Proud.CNetClient.SetApplicationHint ¸¦ ÅëÇØ ÀÔ·ÂÇÏ½Ê½Ã¿À.

		\~english
		The weight to the frame rate measured by user
		- This value increases proportional to frame rate value 1. For an example, if assumed that sustaining 60 fps is regarded as an ideal super peer and lower than 20 fps as to be avoided,
		then entering 4 gives 20 fps * 4 = 80, 60 fps * 4 = 240 resulting 160 points in difference.
		- Measured frame rate is to be entered via Proud.CNetClient.SetApplicationHint.

		\~chinese
		éÄ??ïÒîÜ??áãîÜÊ¥ñì?¡£
		- ??áã?1ßÓİï£¬ó®??ñòÊ¥¡£ÖÇåıßÌ?ËÀ??û¿îÜ?ò¥60?îÜ?£¬íÂ?superpeerãÀùêÌ«îÜ£¬20?ìéù»îÜ?ãÀÜôùêÌ«îÜ?£¬?ìı4îÜ?20?*4=80£¬60?*4=240£¬??ßÓó¬160İÂ¡£
		- ?ïÒîÜ?áã?÷×? Proud.CNetClient.SetApplicationHint%?ìı¡£

		\~japanese
		«æ?«¶?ª¬ö´ïÒª·ª¿«Õ«ì?«à«ì?«ÈªÈªÎÊ¥ñìö·ªÇª¹¡£
		- «Õ«ì?«à«ì?«Èö·1ªËİïÖÇª·ªÆª³ªÎö·ª¬?Ê¥ª·ªŞª¹¡£ÖÇª¨ªĞ¡¢60«Õ«ì?«àªòªèª¯ë«ò¥ª¹ªìªĞSuper PeerªÈª·ªÆîêÌ«ªÇ¡¢20«Õ«ì?«àì¤ù»ªÇª¢ªìªĞSuper PeerªÈª·ªÆÜôîêùêªËøÄ?ª¹ªëªÈª·ª¿ªé¡¢4ªòìıªìªëíŞùê¡¢20«Õ«ì?«à*4=80¡¢60«Õ«ì?«à*4=240¡¢?ªÁ¡¢160ªÎïÃ?ó¬ª¬õóªëªèª¦ªËªÊªêªŞª¹¡£
		- ö´ïÒªµªìª¿«Õ«ì?«à«ì?«ÈªÏ¡¢Proud.CNetClient.SetApplicationHintªò÷×ª¸ìıÕôª·ªÆª¯ªÀªµª¤¡£

		\~
		*/
		double m_frameRateWeight;

		/**
		\~korean
		P2P ±×·ì¿¡ Âü°¡µÈ Å¬¶óÀÌ¾ğÆ®°¡ Âü°¡ÇÑ ÈÄ Áö³­ ½Ã°£ÀÌ ¿©±â¼­ ÁöÁ¤ÇÑ ½Ã°£ ÀÌÇÏÀÌ¸é ¼öÆÛÇÇ¾î ¼±Á¤¿¡¼­ °ÅÀÇ ¹èÁ¦ÇÑ´Ù. ¹Ğ¸®ÃÊ ´ÜÀ§´Ù.
		- 0À¸·Î ÁöÁ¤ÇÏ¸é ÀÌ·¯ÇÑ ¹èÁ¦¸¦ ÇÏÁö ¾Ê´Â´Ù.
		- Åë»óÀûÀ¸·Î ÀæÀº ¼öÆÛÇÇ¾î º¯°æÀ» ¸·±â À§ÇØ °ªÀ» ÁöÁ¤ÇÑ´Ù.

		\~english
		To be disregarded as super peer when the time from the moment that the client participated to the P2P group to now is less than the time designated here. This is in millisecond.
		- Set as 0 then the disregard will not occur.
		- Usually set to prevent super peer eing changed too often.

		\~chinese
		??P2P?îÜclient?Ê¥ı¨??îÜ??ãÀî¤?×ìò¦ïÒ??ì¤ù»îÜ?£¬?superpeer?ïÒ×ìÛÉğ¶¡£ûÆõ©?êÈ¡£
		- ò¦ïÒ?0îÜ?Üô?ñ®??ÛÉğ¶¡£
		- ìéÚõ?Öõù­Øó?ÛåîÜsuperpeerËÇ?ì»ò¦ïÒó®?¡£

		\~japanese
		P2P«°«ë?«×ªË?Ê¥ª·ª¿«¯«é«¤«¢«ó«Èª¬?Ê¥ª·ı­ªÎ?Î¦ãÁÊàª¬ª³ª³ªÇò¦ïÒª·ª¿ãÁÊàì¤ù»ªÇª¢ªìªĞSuper PeeràÔïÒªÇªÛªÜÛÉğ¶ª·ªŞª¹¡£«ß«êõ©?êÈªÇª¹¡£
		- 0ªËò¦ïÒª¹ªìªĞª³ªÎªèª¦ªÊÛÉğ¶ªòª·ªŞª»ªó¡£
		- ÷×ßÈ¡¢ŞºÛåªÊSuper PeerªÎ?ÌÚªòÛÁª°ª¿ªáªËö·ªòò¦ïÒª·ªŞª¹¡£

		\~
		*/
		int64_t m_excludeNewJoineeDurationTimeMs;

		CSuperPeerSelectionPolicy();

		inline bool operator==(const CSuperPeerSelectionPolicy& rhs) const
		{
			return m_realUdpWeight == rhs.m_realUdpWeight &&
				m_noNatDeviceWeight == rhs.m_noNatDeviceWeight &&
				m_serverLagWeight == rhs.m_serverLagWeight &&
				m_peerLagWeight == rhs.m_peerLagWeight &&
				m_sendSpeedWeight == rhs.m_sendSpeedWeight &&
				m_frameRateWeight == rhs.m_frameRateWeight;
		}

		/**
		\~korean
		ÀÏ¹İÀûÀ¸·Î ¾²ÀÌ´Â À¯ÇüÀ¸·Î °ªÀ» ¹Ì¸® ¼³Á¤ÇØ¼­ ¸®ÅÏÇÑ´Ù.

		\~english
		Previously prepared type are set and then returned.

		\~chinese
		ĞÆËßìéÚõŞÅéÄîÜ?úş£¬ŞÀà»?öÇ?ı¨Ú÷üŞ¡£

		\~japanese
		ìéÚõîÜªËŞÅªïªìªë×¾úşªÇö·ªòîñªâªÃªÆàâïÒª·ªÆ«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		static CSuperPeerSelectionPolicy GetOrdinary();

		/**
		\~korean
		¾²Áö ¸»°Í

		\~english
		DO NOT USE THIS.

		\~chinese
		Üôé©ŞÅéÄ¡£

		\~japanese
		ŞÅªïªÊª¤ª³ªÈ¡£
		\~
		*/
		static CSuperPeerSelectionPolicy GetNull();
	};

	/**
	\~korean
	\brief P2P ¿¬°á¿¡ ´ëÇÑ Åë°èÀÔ´Ï´Ù.

	\~english
	\brief Statistics to P2P connection

	\~chinese
	\brief ?P2P?ïÈîÜ??¡£

	\~japanese
	\brief P2PïÈ?ªË?ª¹ªë÷ÖÍªªÇª¹¡£
	\~
	*/
	class CP2PConnectionStats
	{
	public:
		/**
		\~korean
		ÀüÃ¼ ¿¬°á P2P½ÖÀÇ °¹¼öÀÔ´Ï´Ù.

		\~english
		Number of all connected P2P pairs

		\~chinese
		îïİ»P2P?ïÈîÜìé???¡£

		\~japanese
		îï?ïÈ?P2P«Ú«¢ªÎ?ªÇª¹¡£
		\~
		*/
		uint32_t m_TotalP2PCount;

		/**
		\~korean
		Á÷Á¢ ¿¬°á P2P½ÖÀÇ °¹¼öÀÔ´Ï´Ù.

		\~english
		Number of directly connected P2P pairs

		\~chinese
		òÁïÈP2P?ïÈîÜìé???

		\~japanese
		òÁïÈïÈ?P2P«Ú«¢ªÎ?ªÇª¹¡£
		\~
		*/
		uint32_t m_directP2PCount;

		/**
		\~korean
		ÇØ´ç Å¬¶óÀÌ¾ğÆ®°¡ ´Ù¸¥ Å¬¶óÀÌ¾ğÆ®¿¡°Ô Udp packet Àü¼ÛÀ» ½ÃµµÇÑ ÃÑ È½¼ö
		- CNetServer ¿¡¼­¸¸ °ªÀÌ Ã¤¿öÁı´Ï´Ù. ( CLanServer ¿¡¼­´Â udp¸¦ »ç¿ë¾ÈÇÏ¹Ç·Î. )
		- groupÀÇ CP2PConnectionStats ¶ó¸é ¸ğµç ±×·ì¿øÀÇ È½¼ö°¡ ÇÕ»êµË´Ï´Ù.

		\~english
		Total attempted number of Udp packet sending from client to other client.
		- Value will fill at only CNetServer (Because CLanServer does not use udp.)
		- All group members attempt will be added, if it is CP2PConnectionStats of group.

		\~chinese
		?ßÓ?clientèÙĞìöâclient???áêUDP packetîÜ?ó­?¡£
		- ñşî¤ CNetServer%?ù¬?õö¡££¨ì×?î¤ CLanServer%ÜôŞÅéÄUDP£©
		- groupîÜ CP2PConnectionStats%îÜ?á¶êó??îÜó­?Ô´?ù¬ùêß©¡£

		\~japanese
		ú±?«¯«é«¤«¢«ó«Èª¬öâªÎ«¯«é«¤«¢«ó«ÈªËUDP«Ñ«±«Ã«ÈªÎ?áêªòãËª·ª¿?üŞ?
		- CNetServer ªÇªÎªßö·ª¬?ª¿ªµªìªŞª¹¡£ (CLanServerªÇªÏUDPªòŞÅéÄª·ªŞª»ªóªÎªÇ)
		- groupªÎCP2PConnectionStatsªÊªéîïªÆªÎ«°«ë?«×«á«ó«Ğ?ªÎüŞ?ª¬ùêß©ªµªìªŞª¹¡£

		\~
		*/
		uint32_t m_toRemotePeerSendUdpMessageTrialCount;

		/**
		\~korean
		ÇØ´ç Å¬¶óÀÌ¾ğÆ®°¡ ´Ù¸¥ Å¬¶óÀÌ¾ğÆ®¿¡°Ô Udp packet Àü¼ÛÀ» ¼º°øÇÑ ÃÑ È½¼ö
		- CNetServer ¿¡¼­¸¸ °ªÀÌ Ã¤¿öÁı´Ï´Ù. ( CLanServer ¿¡¼­´Â udp¸¦ »ç¿ë¾ÈÇÏ¹Ç·Î. )
		- groupÀÇ CP2PConnectionStats ¶ó¸é ¸ğµç ±×·ì¿øÀÇ È½¼ö°¡ ÇÕ»êµË´Ï´Ù.

		\~english
		Total successful number of Udp packet sending from client to other client
		- Value will fill at only CNetServer (Because CLanServer does not use udp.)
		- All group members attempt will be added, if it is CP2PConnectionStats of group.

		\~chinese
		?ßÓ?clientèÙĞìöâclientà÷Íí?áêUDP packetîÜ?ó­?¡£
		- ñşî¤ CNetServer%?ù¬?õö¡££¨ì×?î¤ CLanServer%ÜôŞÅéÄUDP£©
		- groupîÜ CP2PConnectionStats%îÜ?á¶êó??îÜó­?Ô´?ù¬ùêß©¡£

		\~japanese
		ú±?«¯«é«¤«¢«ó«Èª¬öâªÎ«¯«é«¤«¢«ó«ÈªËUDP«Ñ«±«Ã«ÈªÎ?áêªËà÷Ííª·ª¿?üŞ?
		- CNetServer ªÇªÎªßö·ª¬?ª¿ªµªìªŞª¹¡£(CLanServerªÇªÏUDPªòŞÅéÄª·ªŞª»ªóªÎªÇ)
		- groupªÎCP2PConnectionStatsªÇª¢ªìªĞîïªÆªÎ«°«ë?«×«á«ó«Ğ?ªÎüŞ?ª¬ùêß©ªµªìªŞª¹¡£

		\~
		*/
		uint32_t m_toRemotePeerSendUdpMessageSuccessCount;
	};

	/**
	\~korean
	\brief RemoteA ¿Í RemoteB »çÀÌÀÇ Udp ¸Ş½ÃÂ¡ ½Ãµµ¿Í ¼º°ø°¹¼öÀÔ´Ï´Ù.

	\~english
	\brief Number of attempt and success Udp messaging between RemoteA and Remote B.

	\~chinese
	\brief RemoteAûúRemoteBñı?UDP messaging??ûúà÷Íí??¡£

	\~japanese
	\brief RemoteAªÈRemoteBÊàªÎUDP«á«Ã«»?«¸«ó«°ªÎãËª·ªÈà÷Íí?ªÇª¹¡£
	\~
	*/
	class CP2PPairConnectionStats
	{
	public:
		/**
		\~korean
		A°¡ B¿¡°Ô ½ÃµµÇÑ Udp °¹¼ö

		\~english
		Number of attempted Udp from A to B

		\~chinese
		A?B??îÜUDP??¡£

		\~japanese
		Aª¬BªËãËª·ª¿UDP?
		\~
		*/
		uint32_t m_toRemoteBSendUdpMessageTrialCount;

		/**
		\~korean
		A°¡ B¿¡°Ô ¼º°øÇÑ Udp °¹¼ö

		\~english
		Number of succeed Udp  from A to B

		\~chinese
		A?Bà÷ÍíîÜUDP??¡£

		\~japanese
		Aª¬BªËà÷Ííª·ª¿UDP?
		\~
		*/
		uint32_t m_toRemoteBSendUdpMessageSuccessCount;

		/**
		\~korean
		B°¡ A¿¡°Ô ½ÃµµÇÑ Udp °¹¼ö

		\~english
		Number of attempted Udp from B to A

		\~chinese
		B?A??îÜUDP??¡£

		\~japanese
		Bª¬AªËãËª·ª¿UDP?
		\~
		*/
		uint32_t m_toRemoteASendUdpMessageTrialCount;

		/**
		\~korean
		A°¡ B¿¡°Ô ½ÃµµÇÑ Udp °¹¼ö

		\~english
		Number of attempted Udp from A to B

		\~chinese
		A?B??îÜUDP??¡£

		\~japanese
		Aª¬BªËãËª·ª¿UDP?
		\~
		*/
		uint32_t m_toRemoteASendUdpMessageSuccessCount;

		/**
		\~korean
		¸±·¹ÀÌ Åë½ÅÀ» ÇÏ°í ÀÖÀ¸¸é trueÀÔ´Ï´Ù.

		\~english
		true if relayed mode.

		\~chinese
		åıÍıì«ãÀ?ú¼Relay÷×ãáîÜ????true¡£

		\~japanese
		«ê«ì?÷×ãáªòª·ªÆª¤ªìªĞtrueªÇª¹¡£
		\~
		*/
		bool m_isRelayed;
	};

	/**
	\~korean
	\brief °ÔÀÓ¿ë ³×Æ®¿öÅ© ¼­¹ö

	°ÔÀÓ¿ë ³×Æ®¿öÅ© ¼­¹öÀÔ´Ï´Ù. ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_overview" >ProudNet ¼­¹ö</a> ¿¡ ÀÖ½À´Ï´Ù.
	- MMO °ÔÀÓ¿¡µµ ¾µ ¼ö ÀÖ´Ù.
	- CNetClient ÀÇ ¿¬°áÀ» ¹Ş´Â´Ù.
	- Å¬¶óÀÌ¾ğÆ®¿¡°Ô HostID ¸¦ ¹èÁ¤ÇØÁÖ´Â ¿ªÇÒÀ» ÇÑ´Ù.
	- HostID ¸¦ ¸Å°³Ã¼·Î ÇÏ´Â RMI¸¦ °¡´ÉÇÏ°Ô ÇÑ´Ù.
	- ÀÏ¹İÀûÀÎ °ÔÀÓ ¼­¹ö¿¡ ÇÊ¿äÇÑ ±âº»Àû ¿É¼ÇÀÌ ¼³Á¤µÇ¾î ÀÖ´Ù.
	- Å¬¶óÀÌ¾ğÆ®°£ P2P ¿¬°áÀ» Áö¿øÇÑ´Ù. ÀÌ ¼­¹ö °´Ã¼´Â Å¬¶óÀÌ¾ğÆ®°£ P2P ¿¬°áÀÌ ½ÇÆĞÇÒ °æ¿ì
	¸±·¹ÀÌ ¼­¹ö ¿ªÇÒµµ Áö¿øÇÑ´Ù.

	ÀÏ¹İÀû ¿ë¹ı
	- ÀÌ °´Ã¼¸¦ »ı¼ºÇÑ´Ù. Proud.CNetServer.Create() »ç¿ë.
	- Start()·Î ¼­¹ö¸¦ ½ÃÀÛÇÑ´Ù.
	- INetServerEvent ¸¦ ±¸ÇöÇÑ´Ù. °¡·É INetServerEvent.OnClientJoin() µîÀ» ±¸ÇöÇÑ´Ù.
	ÀÌ°ÍµéÀº Å¬¶óÀÌ¾ğÆ® Á¢¼Ó µî¿¡ ´ëÇÑ ÀÌº¥Æ® ÇÚµé·¯ÀÌ´Ù.
	- ½ÃÀÛ½Ã SetEventSink()·Î ÀÌº¥Æ® ÇÚµé·¯¸¦ ¿«¾îÁÖ°í,
	AttachProxy(), AttachStub()¸¦ ½á¼­ 1°³ ÀÌ»óÀÇ ¼Û½Å ¶Ç´Â
	¼ö½Å¿ë RMI ÀÎÅÍÆäÀÌ½º¸¦ ¿¬°èÇÑ´Ù.

	P2P ¿¬°á ±×·ì ¸¸µé±â
	- CNetServer ¿¡ ¿¬°áµÈ Å¬¶óÀÌ¾ğÆ®´Â 1°³ ÀÌ»óÀÇ P2P ±×·ìÀ» ¸¸µé ¼ö ÀÖ´Ù.
	P2P ±×·ìÀ¸·Î ¹­¿©ÀÖ´Â Å¬¶óÀÌ¾ğÆ®³¢¸®´Â HostID ¸¦ ÀÎÀÚ·Î RMI ¸¦ Á÷Á¢ ÁÖ°í ¹ŞÀ» ¼ö ÀÖ´Ù.
	- »õ P2P groupÀ» »ı¼º/Á¦°ÅÇÏ±â: ¼­¹ö¸¸ÀÌ ±ÇÇÑÀÌ ÀÖ´Ù.
	CreateP2PGroup(),DestroyP2PGroup() ¸¦ ÅëÇØ¼­. Å¬¶óÀÌ¾ğÆ®¿¡¼­´Â OnP2PMemberJoin µîÀÌ È£ÃâµÈ´Ù.
	- peer ¸¦ ±â Á¸Àç P2P group¿¡ Ãß°¡/Á¦°ÅÇÏ±â:
	JoinP2PGroup(), LeaveP2PGroup(). Å¬¶óÀÌ¾ğÆ®¿¡¼­´Â OnP2PMemberJoin µîÀÌ È£ÃâµÈ´Ù.

	Relay server·Î¼­ÀÇ ¿ªÇÒ
	- HostID ¸¦ ¾²´ÂÇÑ P2P ¿¬°áÀº °¡»óÀ¸·Îµµ ÀÌ·ç¾îÁø´Ù. ¿¹ÄÁ´ë P2P ¿¬°áÀÌ ½ÇÁ¦·Î
	¾ÆÁ÷ ¼º°øÇÏÁö ¸øÇÑ peer°£ÀÌ¶óµµ »ó´ë°¡ P2P group¿¡ ¼ÓÇØÀÖÀ¸¸é »ó´ëÀÇ HostID
	·Î º¸³»´Â RMI´Â ¼º°øÀûÀ¸·Î »ó´ë¿¡°Ô °£´Ù. relay server°¡ Áßµµ ¿ªÇÒÀ» ´ã´çÇÑ´Ù.
	°°Àº RMI ¼ö½Å ¸Ş½ÃÁö¶óµµ ±×°ÍÀÌ relay server¸¦ °æÀ¯Çß´ÂÁö ¿©ºÎ¸¦ ¾òÀ¸·Á¸é RMI ¼ö½ÅºÎ¿¡¼­
	RmiContext.m_relayed ¸¦ ÀĞÀ¸¸é µÈ´Ù.

	½º·¹µå Ç®¸µ
	- ±âº»ÀûÀ¸·Î ½º·¹µå Ç®À» »ç¿ëÇÑ´Ù. µû¶ó¼­ ¼­¹ö ½ÃÀÛ½Ã ½º·¹µå ¼ö¸¦ ÃÖ¼Ò 1°³¸¦ ÁöÁ¤ÇØ¾ß ÇÑ´Ù.
	- ½º·¹µå Ç®¸µ ±â´ÉÀ» ²ô´Â°Ô À¯¸®ÇÑ °æ¿ì: 1°³ CPUÀÌ¸é¼­ CPU time Ã³¸®°¡ ÀüºÎÀÎ ¼­¹ö(¿¹ÄÁ´ë ¸±·¹ÀÌ ¼­¹ö)
	- ½º·¹µå Ç®¸µ ±â´ÉÀ» ÄÑ´Â°Ô À¯¸®ÇÑ °æ¿ì: ¸ÖÆ¼ CPU ¶Ç´Â device time Ã³¸®°¡ ÀæÀº ¼­¹ö(¿¹ÄÁ´ë MMO °ÔÀÓ ¼­¹ö)
	- ½º·¹µå Ç® ÇÔ¼ö´Â CoInitialize()°¡ ÁØºñµÈ »óÅÂ¿¡¼­ È£ÃâµÇ¹Ç·Î ¶Ç CoInitialize()³ª CoUninitialize() È£Ãâ ºÒÇÊ¿ä.

	UDP È£½ºÆ® Æ÷Æ® °¹¼ö °ü·Ã ¼­¹ö ¼º´É
	- CNetServer.Start ÀÇ ¼­¹ö Æ÷Æ® ÆÄ¶ó¸ŞÅÍ·Î UDP È£½ºÆ® Æ÷Æ® °¹¼ö¸¦ ÁöÁ¤ÇÒ ¼ö ÀÖ´Ù.
	Å¬¶óÀÌ¾ğÆ®´Â ¼­¹ö·Î ¿¬°áÇÒ ¶§ ÆÄ¶ó¸ŞÅÍ¿¡ ÀÖ´Â Æ÷Æ® Áß ÇÏ³ª·Î ¼­¹ö¿¡ ¿¬°áµÈ´Ù.

	P2P Á÷Á¢ Åë½Å ¼º°ø °¡´É¼º ³ëÆ®
	- P2P°£ ÇÑÂÊÀÌ real IP, Full-cone NATÀÎ °æ¿ì direct P2P Åë½ÅÀÌ ¼º°øÇÑ´Ù.
	- °ÔÀÓ ¼­¹ö°¡ NAT µÚ¿¡¼­ ÀÛµ¿ÇÒ °æ¿ì, Start()¿¡ ¼­¹ö ÁÖ¼Ò¸¦ ³Ö¾î¾ß ÇÑ´Ù. (ÀÚ¼¼ÇÑ °ÍÀº Start()ÀÇ ¼³¸í ÂüÁ¶)
	´Ü, ÀÌ·¸°Ô ÇÑ´Ù ÇÏ´õ¶óµµ °ÔÀÓ ¼­¹ö ¾ÕÀÇ NAT µÚ¿¡ ÀÖ´Â ¶Ç ´Ù¸¥ È£½ºÆ®¿¡¼­ ½ÇÇàµÇ´Â Å¬¶óÀÌ¾ğÆ®¿Í ¿ÜºÎ ÀÎÅÍ³İ
	ÀÇ Å¬¶óÀÌ¾ğÆ®°£ Á÷Á¢ P2P Åë½ÅÀº ½ÇÇöµÇÁö ¸øÇÑ´Ù. ¼­¹ö¿¡ ÀÖ´Â NAT ÀåÄ¡¿¡ ÀÇÇØ ¿ÜºÎ ÀÎÅÍ³İ ÁÖ¼Ò ´ë½Å NATÀÇ ³»ºÎ
	IP°¡ ÀÎ½ÄµÇ±â ¶§¹®ÀÌ´Ù.

	\~english
	\brief Gaming network server

	A network server for gaming. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#server_overview" >ProudNet Server</a>.
	- Can be used for a MMO title
	- Receives CNetClient connection
	- Allocates HostID to client
	- Allows RMI requires HostID
	- Basic options are set in order to support what a general game server needs
	- Supports P2P connection between clients. This server object supports to be a rela server when P2P connection fails between clients.

	General usage
	- Creates this object. Use Proud.CNetServer.Create().
	- Use Start() to start server.
	- Realize INetServerEvent, such as realizing INetServerEvent.OnClientJoin() and so on.
	Those are event handlers for client connections and so on.
	- Intertwines SetEventSink() to event andlers when started and links 1 or more of transmission or reception RMI interface using AttachProxy(), AttachStub().

	Creating P2P connection group
	- The client connected to CNetServer can create 1 or more P2P group.
	Among the clients linked as P2P group can transmit/receive RMI as HostID being index.
	- Creating/removing a new P2P group: Only server has rights.
	OnP2PMemberJoin and so on will be called at client via CreateP2PGroup(),DestroyP2PGroup().
	- Adding/removig peer to/from  existing P2P group: JoinP2PGroup(), LeaveP2PGroup(). OnP2PMemberJoin and so on will be called at client.

	Roles as relay server
	- As long as using HostID, P2P connection occurs virtually as well.
	For an example, even if the opponent is a member of P2P group, between clients that P2P connection was not successful in real then RMI is successfully sent to opponent's HostID.
	Relay server manages the carrying.
	Tough for same RMI reception message, it is to read RmiContext.m_relayed at RMI read part to get whether went through relay server.

	Thread pooling
	- Basically uses thread pool. So there must be at least 1 or more thread when server starts.
	- When turning thread pooling off is better: server with 1 CPU and all it does is CPU time process (e.g. relay server)
	- When turning thread pooling on is better: server with multip CPU or server that has often device time process (e.g. MMO game server)
	- Since thread pool function is called when CoInitialize()is ready there is no need to call CoInitialize() or CoUninitialize().

	Server performance related to number of UDP host port
	- Can designate number of UDP host port as server port parameter of CNetServer.Start
	Client will be connected to one of the ports among parameter when connected to server.

	Success rate of P2P direct communication note
	- Direct P2P communication will be successful when an end of P2P is real IP, Full-cone NAT.
	- When game server operatedbehind NAT it is necessary to enter server address to Start(). (Please refer Start() manual.)
	However, there will be no direct P2P communication between the client run by other host that is in front of game server and behind of NAT and the client of outer internet.
	This is because the internal IP of NAT will be recognized other than outer internet address by NAT device in server.

	\~chinese
	\brief êı?éÄ??Ü×?Ğï¡£

	êı?éÄ??Ü×?Ğï¡£??îÜî¤<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_overview" >ProudNet Ü×?Ğï</a>%×ì¡£
	- å¥Ê¦ì¤î¤MMOêı?ŞÅéÄ¡£
	- ïÈâ¥ CNetClient%îÜ?ïÈ¡£
	- ÑÃó·?clientİÂÛÕHost IDîÜíÂéÄ¡£
	- ?RMIÊ¦ì¤ì¤Host ID?ØÚ?¡£
	- ?öÇó·ìéÚõêı?Ü×?ĞïâÍé©îÜĞñÜâ??¡£
	- ò¨ò¥clientñı?P2P?ïÈ¡£ó®Ü×?Ğï?ßÚî¤clientñı?P2P?ïÈã÷?îÜ?ı¦?ò¨ò¥relayÜ×?ĞïîÜíÂéÄ¡£

	ìéÚõŞÅéÄÛ°Ûö
	- ßæà÷ó®?ßÚ¡£ŞÅéÄ Proud.CNetServer.Create()¡£
	- éÄStart()?ã·Ü×?Ğï¡£
	- ??INetServerEvent¡£ÖÇåı?? INetServerEvent.OnClientJoin()Ôõ¡£
	?ŞÁãÀ?client?ïÈÔõîÜevent handler¡£
	- ?ã·?éÄSetEventSink()?event handler£¬ŞÅéÄAttachProxy(), AttachStub()?ïÈìé?ì¤ß¾îÜ?áêûäíºâ¥ãáéÄRMIÍ£Øü¡£

	?ËïP2P?ïÈ?¡£
	- ?ïÈ CNetServer%îÜclientÊ¦ì¤?Ëïìé?ì¤ß¾îÜP2P?¡£
	?à÷P2P?îÜclientñı?Ê¦ì¤ì¤Host ID?ì×í­òÁïÈÎß?RMI¡£
	- ßæà÷/?ğ¶ãæP2P group£ºñşêóÜ×?Ğïêó?Õô¡£
	÷×?CreateP2PGroup(),DestroyP2PGroup()£¬î¤clientû¼Ğ£OnP2PmemberJoinÔõ¡£
	- ÷êpeerèÙì«ğíî¤P2P groupôÕÊ¥/?ğ¶£º
	JoinP2PGroup(), LeaveP2PGroup()¡£î¤clientû¼Ğ£OnP2PMemberJoinÔõ¡£

	Relay serverîÜíÂéÄ
	- ?æÔŞÅéÄHost ID£¬P2P?ïÈ?????¡£ÖÇåı?ŞÅãÀP2P?ïÈ??ß¾??êóà÷ÍíîÜPeerñı?£¬?Û°?éÍP2P groupîÜ??áêÓğ?Û°Host IDîÜRMI?à÷ÍíÓğ?áê??Û°¡£Relay serverî¤ñé??ìòíÂéÄ¡£?ŞÅãÀßÓÔÒîÜïÈâ¥ãáãÓ£¬ßÌò±Ô³?ãÀÜú?ë¦relay serverîÜ?î¤RMIâ¥ãáİ»? RmiContext.m_relayed%?Ê¦¡£

	?ïïpooling
	- ìéÚõÔ´ŞÅéÄ?ïïpool¡£á¶ì¤Ü×?Ğï?ã·?ò¸á´é©ò¦ïÒìé??ïï?¡£
	- ???ïïpoolÍíÒö?êó××îÜï×?£ºãÀìé?CPUì»ó¦CPU time?×âãÀîïİ»îÜÜ×?Ğï£¨ÖÇåırelayÜ×?Ğï£©¡£
	- ???ïïpoolÍíÒö?êó××îÜï×?£ºÒıCPUûäíºdevice time?×â?ÛåîÜÜ×?Ğï£¨ÖÇåıMMOêı?Ü×?Ğï£©¡£
	- ?ïïpoolùŞ?î¤CoInitialize()ñ×?îÜ??ù»û¼Ğ££¬á¶ì¤ÜôâÍé©CoInitialize()ûäíºCoUninitialize()

	UDPñ«ÏõÓ®Ï¢??ßÓ?Ü×?ĞïàõÒö¡£
	- éÄ CNetServer.Start%îÜÜ×?ĞïÓ®Ï¢??Ê¦ì¤ò¦ïÒUDPñ«ÏõÓ®Ï¢??¡£
	Client?Ü×?Ğï?ïÈîÜ?ı¦éÄ??×ìğíî¤îÜÓ®Ï¢ñıìé?Ü×?Ğï?ú¼?ïÈ¡£

	P2PòÁïÈ÷×ãáà÷ÍíÊ¦Òöàõ??¡£
	- P2Pñı?ìéÛ°real IP, Full-cone NAT îÜ?ı¦direct P2P÷×ãáà÷Íí¡£
	- êı?Ü×?Ğïî¤NATı¨Øü??îÜ?ı¦é©èÙStart()?ìıÜ×?Ğïò¢ò£¡££¨????ÍÅStart()?Ù¥£©
	Ó£?ŞÅ??£¬êı?Ü×?ĞïîñØüîÜNATî¤Ğìı¨ØüîÜĞìöâñ«Ïõñé?ú¼îÜclientûúèâİ»û»??clientñı?îÜòÁïÈ÷×ãáÊ¿Üô???¡£ ì×?ĞÆËßÜ×?ĞïîÜNAT?öÇ£¬ù¬??îÜÜôãÀèâİ»û»??ò¢ß¾£¬ì»ãÀ?İ»IP¡£

	\~japanese
	\brief «²?«àéÄ«Í«Ã«È«ï?«¯«µ?«Ğ?
	«²?«àéÄ«Í«Ã«È«ï?«¯«µ?«Ğ?ªÇª¹¡£ßÙª·ª¯ªÏ¡¢\ref server_overviewªËª¢ªêªŞª¹¡£
	- MMO «²?«àªËªâŞÅª¨ªŞª¹¡£
	- CNetClient ª«ªéªÎïÈ?ªòáôª±ªŞª¹¡£
	- «¯«é«¤«¢«ó«ÈªËHostIDªòùÜªê?ªÆªëæµùÜªòª·ªŞª¹¡£
	- HostIDªòØÚË¿?ªÈª¹ªëRMIªòÊ¦ÒöªËª·ªŞª¹¡£
	- ìéÚõîÜªÊ«²?«à«µ?«Ğ?ªËù±é©ªÊĞñÜâîÜªÊ«ª«×«·«ç«óª¬àâïÒªµªìªÆª¤ªŞª¹¡£
	- «¯«é«¤«¢«ó«ÈÊàªÎP2PïÈ?ªò«µ«İ?«Èª·ªŞª¹¡£ª³ªÎ«µ?«Ğ?«ª«Ö«¸«§«¯«ÈªÏ«¯«é«¤«¢«ó«ÈÊàªÎP2PïÈ?ªËã÷ø¨ª·ª¿íŞùê¡¢«ê«ì?«µ?«Ğ?æµùÜªò«µ«İ?«Èª·ªŞª¹¡£

	ìéÚõîÜªÊéÄÛö
	- ª³ªÎ«ª«Ö«¸«§«¯«Èªòßæà÷ª·ªŞª¹¡£Proud.CNetServer.Create() ŞÅéÄ
	- Start()ªÇ«µ?«Ğ?ªòËÒã·ª·ªŞª¹¡£
	- INetServerEventªò?úŞª·ªŞª¹¡£?ªËINetServerEvent.OnClientJoin()ªÊªÉªò?úŞª·ªŞª¹¡£
	ª³ªìªéªÏ«¯«é«¤«¢«ó«ÈïÈ?ªÊªÉªË?ª¹ªë«¤«Ù«ó«È«Ï«ó«É«é?ªÇª¹¡£
	- ËÒã·ãÁªËSetEventSink()ªÇ«¤«Ù«ó«È«Ï«ó«É«é?ªòğÚªóªÇ¡¢AttachProxy()¡¢AttachStub()ªòŞÅªÃªÆ1ËÁì¤ß¾ªÎáêãáªŞª¿ªÏáôãáéÄRMI«¤«ó«¿?«Õ«§?«¹ªòÖ§ıÍª·ªŞª¹¡£

	P2PïÈ?«°«ë?«×ßæà÷
	- CNetServer ªËïÈ?ªµªìª¿«¯«é«¤«¢«ó«ÈªÏ1ËÁì¤ß¾ªÎP2P«°«ë?«×ªòíÂªëª³ªÈª¬ªÇª­ªŞª¹¡£
	P2P«°«ë?«×ªÇÚÚªéªìªÆª¤ªë«¯«é«¤«¢«ó«ÈÊàªÇªÏHostIDªòì×í­ªËRMIªòªäªêö¢ªêªÇª­ªŞª¹¡£
	- ãæª·ª¤P2P groupªòßæà÷/ğ¶ËÛª¹ªë£º«µ?«Ğ?ªÎªßª¬?ùÚª¬ª¢ªêªŞª¹¡£
	CreateP2PGroup(),DestroyP2PGroup()ªò÷×ª¸¡¢«¯«é«¤«¢«ó«ÈªÇªÏOnP2PMemberJoinªÊªÉª¬û¼ªÓõóªµªìªŞª¹¡£
	- peerªò?ªËğíî¤ª¹ªëP2P groupªËõÚÊ¥?ğ¶ËÛª¹ªë£º
	JoinP2PGroup(), LeaveP2PGroup(). «¯«é«¤«¢«ó«ÈªÇªÏOnP2PMemberJoinªÊªÉª¬û¼ªÓõóªµªìªŞª¹¡£

	Relay serverªÈª·ªÆªÎæµùÜ
	- HostIDªòŞÅª¦ùÚªê¡¢P2PïÈ?ªÏ?ßÌªÇªâú¼ªïªìªŞª¹¡£ÖÇª¨ªĞ¡¢P2PïÈ?ª¬?ğ·ªËªŞªÀà÷Ííª·ªÊª«ªÃª¿PeerÊàªÇªâßÓâ¢ª¬P2P groupªË?ª·ªÆª¤ªìªĞßÓâ¢ªÎHostIDªËáêªëRMIªÏà÷ÍíîÜªËßÓâ¢ªËú¼ª­ªŞª¹¡£relay serverª¬ñéÔ²æµùÜªò??ª·ªŞª¹¡£
	ÔÒª¸RMIáôãá«á«Ã«»?«¸ªÇªâª½ªìª¬relay serverªòÌØàªª·ª¿ªÎª«ªÉª¦ª«ªòÔğªëª¿ªáªËªÏ¡¢RMIáôãáİ»ªÇRmiContext.m_relayedªò?ªáªĞª¤ª¤ªÇª¹¡£

	«¹«ì«Ã«É«×?«ê«ó«°
	- ĞñÜâîÜªË«¹«ì«Ã«É«×?«ëªòŞÅéÄª·ªŞª¹¡£ªèªÃªÆ¡¢«µ?«Ğ?ËÒã·ãÁªË«¹«ì«Ã«É?ªòõÌá³£±ËÁªòò¦ïÒª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
	- «¹«ì«Ã«É«×?«ê«ó«°Ñ¦Òöªò«ª«Õª¹ªëªÎª¬êó××ªÊíŞùê£º1ËÁªÎCPUªÇª¢ªêªÊª¬ªéCPU time?×âª¬îïİ»ªÇª¢ªë«µ?«Ğ?(ÖÇª¨ªĞ¡¢«ê«ì?«µ?«Ğ?)
	- «¹«ì«Ã«É«×?«ê«ó«°Ñ¦Òöªò«ª«óª¹ªëªÎª¬êó××ªÊíŞùê£º«Ş«ë«ÁCPUªŞª¿ªÏdevice time?×âª¬ŞºÛåªÊ«µ?«Ğ?(ÖÇª¨ªĞ¡¢MMO«²?«à«µ?«Ğ?)
	- «¹«ì«Ã«É«×?«ë??ªÏ¡¢CoInitialize()ª¬ñŞİáªµªìª¿?÷¾ªÇû¼ªÓõóªµªìªŞª¹ªÎªÇ¡¢ªŞª¿¡¢CoInitialize()ªÈª«CoUninitialize()ªÎû¼ªÓõóª·ª¬Üôé©¡£

	UDP«Û«¹«È«İ?«È?ªË?Ö§ª¹ªë«µ?«Ğ?àõÒö
	- CNetServer.StartªÎ«µ?«Ğ?«İ?«È«Ñ«é«á?«¿?ªÇUDP«Û«¹«È«İ?«È?ªòò¦ïÒª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
	«¯«é«¤«¢«ó«ÈªÏ«µ?«Ğ?ªËïÈ?ª¹ªëãÁªË«Ñ«é«á?«¿?ªËª¢ªë«İ?«ÈªÎª¦ªÁìéªÄªÇ«µ?«Ğ?ªËïÈ?ª·ªŞª¹¡£

	P2PòÁïÈ÷×ãáà÷ÍíÊ¦Òöàõ«Î?«É
	- P2PªÎø¸ö°ª¬real IP, Full-cone NATªÇª¢ªëíŞùê¡¢direct P2P÷×ãáª¬à÷Ííª·ªŞª¹¡£
	- «²?«à«µ?«Ğ?ª¬NATªÎı­ªíªÇíÂÔÑª¹ªëíŞùê¡¢Start()ªË«µ?«Ğ?«¢«É«ì«¹ªòìıªìªëù±é©ª¬ª¢ªêªŞª¹¡£(ßÙª·ª¯ªÏStart()ªÎ?Ù¥ªòª´?ğÎª¯ªÀªµª¤¡£)
	Ó£ª·¡¢ª³ªÎªèª¦ªËª¹ªëªÈª·ªÆªâ¡¢«²?«à«µ?«Ğ?ªÎîñªÎNATªÎı­ªíªËª¢ªëöâªÎ«Û«¹«ÈªÇ?ú¼ªµªìªë«¯«é«¤«¢«ó«ÈªÈèâİ»«¤«ó«¿?«Í«Ã«ÈªÎ«¯«é«¤«¢«ó«ÈÊàªÎòÁïÈP2P÷×ãáªÏ?úŞªµªìªŞª»ªó¡£«µ?«Ğ?ªËª¢ªëNAT?öÇªËªèªÃªÆèâİ»«¤«ó«¿?«Í«Ã«È«¢«É«ì«¹ªÎôğªïªêªËNATªÎ?İ»IPª¬ìããÛªµªìªëª«ªéªÇª¹¡£

	\~
	*/
	class CNetServer : public IRmiHost, public HasCoreEventFunctionObjects
	{
	public:
		virtual ~CNetServer() {}

	private:
		static CNetServer* Create_Internal();
	public:

		/**
		\~korean
		»õ ÀÎ½ºÅÏ½º¸¦ »ı¼ºÇÕ´Ï´Ù.

		\~english
		Creates new instance.

		\~chinese
		ßæà÷ãæîÜ?ÖÇ¡£

		\~japanese
		ãæª·ª¤«¤«ó«¹«¿«ó«¹ªòßæà÷ª·ªŞª¹¡£
		\~
		*/
		inline static CNetServer* Create()
		{
			// ¿©±â¼­ PROUDNET_H_LIB_SIGNATURE¸¦ °Çµå¸°´Ù. ÀÌ·¸°Ô ÇÔÀ¸·Î ÀÌ Àü¿ª º¯¼ö°¡ ÄÄÆÄÀÏ·¯¿¡ ÀÇÇØ »ç¶óÁöÁö ¾Ê°Ô ÇÑ´Ù.
			PROUDNET_H_LIB_SIGNATURE++;
			return Create_Internal();
		}

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ® ¶Ç´Â Ã¤ÆÃ ±×·ì¿¡ ¼ÓÇÑ ¸ğµç Å¬¶óÀÌ¾ğÆ®¸¦ ÂÑ¾Æ³½´Ù.
		\return ÇØ´ç Å¬¶óÀÌ¾ğÆ®°¡ ¾øÀ¸¸é false.

		\~english
		Kicks out all clients in client group and/or chatting group
		\return false if there is no realted client.

		\~chinese
		?õó?éÍClientûäíºÖıô¸?îÜá¶êóclient¡£
		\return ?êóßÓ?clientîÜ?false¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªŞª¿ªÏ«Á«ã«Ã«È«°«ë?«×ªË?ª·ª¿îïªÆªÎ«¯«é«¤«¢«ó«ÈªòõÚª¤õóª·ªŞª¹¡£
		\return ú±?«¯«é«¤«¢«ó«Èª¬ªÊª±ªìªĞfalse.

		\~
		*/
		virtual bool CloseConnection(HostID clientHostID) = 0;

		/**
		\~korean
		¸ğµç Å¬¶óÀÌ¾ğÆ®¸¦ Ãß¹æÇÑ´Ù.

		\~english
		Kicks out all clients

		\~chinese
		?õóá¶êóclient¡£

		\~japanese
		îïªÆªÎ«¯«é«¤«¢«ó«ÈªòõÚª¤õóª·ªŞª¹¡£
		\~
		*/
		virtual void CloseEveryConnection() = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> À» »ı¼ºÇÕ´Ï´Ù. 
		- ÀÌ·¸°Ô »ı¼ºÇÑ ±×·ì ³»ÀÇ ÇÇ¾îµé³¢¸®´Â Áï½Ã ¼­·Î°£ ¸Ş½ÃÂ¡À» ÇØµµ µË´Ï´Ù.  (Âü°í: <a target="_blank" href="http://guide.nettention.com/cpp_ko#robust_p2p" >ProudNetÀÇ P2P Åë½Å ¼º´É</a>)
		- Å¬¶óÀÌ¾ğÆ® ¸ñ·Ï(clientHostIDs,clientHostIDNum)À» ¹ŞÀ» °æ¿ì ÀÌ¹Ì ¸â¹ö°¡ Ã¤¿öÁ® ÀÖ´Â P2P groupÀ» »ı¼ºÇÑ´Ù. 
		ÅÖ ºó ¹è¿­À» ³ÖÀ» °æ¿ì ¸â¹ö 0°³Â¥¸® P2P ±×·ìÀ» »ı¼ºÇÒ ¼ö ÀÖ´Ù. (´Ü, AllowEmptyP2PGroup ¿¡ µû¶ó ´Ù¸£´Ù.) 
		- ÀÌ ¸Ş¼­µå È£Ãâ ÈÄ, CNetClient ¿¡¼­´Â P2P ±×·ìÀÇ °¢ ¸â¹ö¿¡ ´ëÇØ(ÀÚ±â ÀÚ½Å Æ÷ÇÔ) 
		INetClientEvent.OnP2PMemberJoin ÀÌ ¿¬ÀÌ¾î¼­ È£ÃâµÈ´Ù.
		- HostID_Server °¡ µé¾î°¡µµ µÇ´ÂÁö ¿©ºÎ´Â <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_as_p2pgroup_member" >P2P ±×·ì ¸â¹ö·Î¼­ ¼­¹ö¸¦ Æ÷ÇÔ½ÃÅ°±â</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À. 

		\param clientHostIDs ¸¸µé P2P ±×·ìÀÇ ¸â¹ö ¸®½ºÆ®. HostID_Server ´Â ¸â¹ö·Î ºÒ°¡´ÉÇÏ´Ù. count=0ÀÏ¶§ ÀÌ °ªÀº ¹«½ÃµÈ´Ù. 
		\param count clientHostIDsÀÇ ¹è¿­ ¿ä¼Ò °¹¼ö. 0À» ³ÖÀ» °æ¿ì ¸â¹ö°¡ ¾ø´Â P2P group À» »ı¼ºÇÔÀ» ÀÇ¹ÌÇÑ´Ù. 
		\param customField P2P ±×·ìÀ» Ãß°¡ÇÏ¸é¼­ ¼­¹ö¿¡¼­ °ü·Ã Å¬¶óÀÌ¾ğÆ®µé¿¡°Ô º¸³»´Â ¸Ş½ÃÁö. »ı·«ÇÏ¼Åµµ µË´Ï´Ù. 
		- INetClientEvent.OnP2PMemberJoin ¿¡¼­ ±×´ë·Î ¹Ş¾ÆÁı´Ï´Ù. 
		\param option P2P ±×·ì »ı¼º °úÁ¤¿¡¼­ »ç¿ëÀÚ°¡ ÁöÁ¤ÇÏ°í ½ÍÀº Ãß°¡ ¿É¼ÇÀÔ´Ï´Ù. »ı·«ÇÏ¼Åµµ µË´Ï´Ù. 
		\param assignedHostID »ç¿ëÀÚ°¡ ¿øÇÏ´Â HostID ¸¦ °¡Áø P2P ±×·ìÀ» »ı¼ºÇÒ ¼ö ÀÖ½À´Ï´Ù. ±âº»°ªÀº NoneÀÔ´Ï´Ù. NoneÀ» ÁöÁ¤ÇÏ¸é ÀÚµ¿ ÇÒ´çµË´Ï´Ù. ¸¸¾à ÀÌ¹Ì »ç¿ëÁßÀÎ HostID ¸¦ ÀÔ·ÂÇÒ °æ¿ì P2P group »ı¼ºÀº ½ÇÆĞÇÏ°í NoneÀ» ¸®ÅÏÇÒ ¼ö ÀÖ½À´Ï´Ù.
		\return ¸¸µé¾îÁø P2P ±×·ìÀÇ Host ID ÀÔ´Ï´Ù. Å¸ÀÔÀº HostID ÀÔ´Ï´Ù.

		\~english 
		Generate a <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>. 
		- The peers in the group generated in this way can do messaging with one another immediately (<a target="_blank" href="http://guide.nettention.com/cpp_en#robust_p2p" >P2P performance of ProudNet</a>)
		- After calling this method, for each member of P2P group(including itself), INetClientEvent.OnP2PMemberJoin will be called one after another to CNetClient.
		When you insert an empty array, you can generate a P2P group with 0 members (however, it depends on AllowEmptyP2PGroup).
		- After calling this method, in CNetClient, INetClientEvent.OnP2PMemberJoin is called continuously to each member of the P2P group (including itself).
		- To find out whether HostID_Server can enter or not, please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#server_as_p2pgroup_member" >How to include a server as a peer - to - peer group member</a> .

		\param clientHostIDs The member list of the P2P group to make clientHostIDs. HostID_Server is not possible as a member. When count=0, this value is ignored. 
		\param count The number of array elements of clientHostIDs. If you input 0, it means it will generate a P2P group without a member. 
		\param The message to be sent to the related clients from the server when a P2P group is added. You can skip it. 
		- It is received in INetClientEvent.OnP2PMemberJoin as it is. 
		\param This is an additional option that users want to designate during creation of a P2P group. You can skip it. 
		\param You can create a P2P group with the HostID users want. The default value is None. If you select None, it is automatically allocated. If you enter a HostID already being used, P2P group creation will fail and None can be returned. 
		\return HostID of the created P2P group. The type is HostID.  

		\~chinese
		ßæà÷<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%¡£
		- ??ßæà÷îÜ??peerñı?Ê¦ì¤Ø¡??ú¼ßÓû»ñı?îÜmessaging¡££¨?ÍÅ£º<a target="_blank" href="http://guide.nettention.com/cpp_zh#robust_p2p" >ProudNet îÜP2P÷×ãáÍíÒö</a>£©
		- â¥ÓğclientÙÍ?£¨clientHostIDs,clientHostIDNum£©îÜ?ßæà÷ì«??õöà÷?îÜP2P group¡£
		- ?ìıÍö??îÜ?Òößæà÷0?à÷?îÜP2P?¡££¨Ó£ĞÆËßAllowEmptyP2Pgroup?êóá¶ÜôÔÒ£©
		- û¼Ğ£ó®Û°Ûöı¨?P2P?îÜÊÀ?à÷?£¨øĞÎÀí»ĞùÜâãó£©î¤ CNetClient%??û¼Ğ£ INetClientEvent.OnP2PmemberJoin¡£
		- HostID_Server ãÀÜúÒö?ìı??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_as_p2pgroup_member" >ì¤P2PîÜ?à÷?ùŞÎÀÜ×?Ğï</a>%¡£

		\param clientHostIDs é©?ËïîÜP2P?à÷?list¡£ HostID_Server ÜôÊ¦Òöà÷?à÷?¡£Count=0?ù¬ûì?¡£
		\param count clientHostIDsîÜ??ì×áÈ??¡£?ìı0îÜ?ëòÚ«ó·ßæà÷?êóà÷?îÜP2Pgroup
		\param customField ôÕÊ¥P2P?£¬?Ê¦ì¤àıÕÔÜ×?ĞïèÙßÓ?client?áêîÜãáãÓ¡£
		- î¤ INetClientEvent.OnP2PMemberJoin%åı?îÜù¬ïÈâ¥¡£

		\param option î¤P2P?îÜßæà÷?ïïñééÄ?ßÌé©ò¦ïÒîÜôÕÊ¥??¡£Ê¦ì¤àıÕÔ¡£
		\param assignedHostID Ê¦ì¤ßæà÷ò¥êóéÄ?ıñØĞîÜHostIDîÜP2P?¡£ĞñÜâ?ãÀNone¡£åıÍıò¦ïÒ?None??í»??ú¼İÂÛÕ¡£åıÍı?ìıì«î¤ŞÅéÄñéîÜ HostID%£¬?ßæà÷P2P group??ã÷?£¬ñıı¨Return None¡£
		\return ?ËïîÜP2P?Host ID¡£?úşãÀHost ID¡£

		\~japanese
		\ref p2p_group ªòßæà÷ª·ªŞª¹¡£
		- ª³ªÎªèª¦ªËßæà÷ª·ª¿«°«ë?«×?ªÎPeerÊàªÏòÁªÁªË«µ?«Ğ?ÊàªÇ«á«Ã«»?«¸«ó«°ªòª·ªÆªâÕŞª¤ªÇª¹¡£(?ÍÅ£º \ref robust_p2p)
		- «¯«é«¤«¢«ó«È«ê«¹«È(clientHostIDs,clientHostIDNum)ªòáôª±ªëíŞùê¡¢?ªË«á«ó«Ğ?ª¬?ª¿ªµªìªÆª¤ªëP2P groupªòßæà÷ª·ªŞª¹¡£
		ÍöªÎÛÕÖªªòìıªìªëíŞùê¡¢«á«ó«Ğ?0ËÁªÎP2P«°«ë?«×ªòßæà÷ª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£(Ó£ª·¡¢AllowEmptyP2PGroup ªËªèªÃªÆêŞª¤ªŞª¹¡£)
		- ª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª·ı­¡¢CNetClientªÇªÏP2P«°«ë?«×ªÎÊÀ«á«ó«Ğ?ªË?ª·ªÆ(í»İÂí»ãóªòùßªà)
		INetClientEvent.OnP2PMemberJoinª¬?ª±ªéªìªÆû¼ªÓõóªµªìªŞª¹¡£
		- HostID_Server ª¬ìıªÃªÆªâÕŞª¤ªÎª«ªÉª¦ª«ªÏ¡¢\ref server_as_p2pgroup_memberªòª´?ğÎª¯ªÀªµª¤¡£
		\param clientHostIDs íÂªëP2P«°«ë?«×ªÎ«á«ó«Ğ?«ê«¹«È¡£HostID_ServerªÏ«á«ó«Ğ?ªÇÜôÊ¦ÒöªÇª¹¡£count=0ªÇª¢ªëãÁ¡¢ª³ªÎö·ªÏÙíãÊªµªìªŞª¹¡£
		\param count clientHostIDsªÎÛÕÖªé©áÈ?¡£0ªòìıªìªëíŞùê¡¢«á«ó«Ğ?ª¬ªÊª¤P2P groupªòßæà÷ª¹ªëª³ªÈªòëòÚ«ª·ªŞª¹¡£
		\param customField P2P«°«ë?«×ªòõÚÊ¥ª·ªÊª¬ªé¡¢«µ?«Ğ?ªÇ?Ö§«¯«é«¤«¢«ó«ÈªËáêªë«á«Ã«»?«¸¡£àıÕÔª·ªÆªâÕŞª¤ªÇª¹¡£
		- INetClientEvent.OnP2PMemberJoin ªÇª½ªÎªŞªŞáôª±ªéªìªŞª¹¡£
		\param option P2P «°«ë?«×ªÎßæà÷Î¦ïïªÇ«æ?«¶?ª¬ò¦ïÒª·ª¿ª¤õÚÊ¥«ª«×«·«ç«óªÇª¹¡£àıÕÔª·ªÆªâÕŞª¤ªÇª¹¡£
		\param assignedHostID «æ?«¶?ª¬ØĞªàHostIDªòò¥ªÄP2P«°«ë?«×ªòßæà÷ª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£ĞñÜâö·ªÏNoneªÇª¹¡£Noneªòò¦ïÒª¹ªìªĞí»ÔÑùÜªê?ªÆªéªìªŞª¹¡£ªâª·¡¢?ªËŞÅéÄñéªÇª¢ªëHostIDªòìıÕôª¹ªëíŞùê¡¢P2P groupªÎßæà÷ªÏã÷ø¨ª·ªÆ¡¢Noneªò«ê«¿?«óªÇª­ªŞª¹¡£
		\return íÂªéªìª¿P2P«°«ë?«×ªÎHost IDªÇª¹¡£«¿«¤«×ªÏHostIDªÇª¹¡£

		\~
		*/
		virtual HostID CreateP2PGroup(const HostID* clientHostIDs, int count, ByteArray customField = ByteArray(), CP2PGroupOption &option = CP2PGroupOption::Default, HostID assignedHostID = HostID_None) = 0;

		/**
		\~korean
		¸â¹ö°¡ ¾ø´Â P2P ±×·ìÀ» ¸¸µì´Ï´Ù.
		- AllowEmptyP2PGroup ¼³Á¤¿¡ µû¶ó ±×·ì »ı¼ºÀÌ ½ÇÆĞÇÒ ¼öµµ ÀÖ´Ù.
		\param customField P2P ±×·ìÀ» Ãß°¡ÇÏ¸é¼­ ¼­¹ö¿¡¼­ °ü·Ã Å¬¶óÀÌ¾ğÆ®µé¿¡°Ô º¸³»´Â ¸Ş½ÃÁöÀÔ´Ï´Ù. »ı·«ÇÏ¼Åµµ µË´Ï´Ù.
		\param assignedHostID »ç¿ëÀÚ°¡ ¿øÇÏ´Â HostID ¸¦ °¡Áø P2P ±×·ìÀ» »ı¼ºÇÒ ¼ö ÀÖ½À´Ï´Ù. ±âº»°ªÀº NoneÀÔ´Ï´Ù. NoneÀ» ÁöÁ¤ÇÏ¸é ÀÚµ¿ ÇÒ´çµË´Ï´Ù. ¸¸¾à ÀÌ¹Ì »ç¿ëÁßÀÎ HostID ¸¦ ÀÔ·ÂÇÒ °æ¿ì P2P group »ı¼ºÀº ½ÇÆĞÇÏ°í NoneÀ» ¸®ÅÏÇÒ ¼ö ÀÖ½À´Ï´Ù.
		\return ¸¸µé¾îÁø P2P ±×·ìÀÇ Host ID ÀÔ´Ï´Ù. Å¸ÀÔÀº HostID ÀÔ´Ï´Ù.

		\~english 
		Create a P2P group without a member. 
		- Group creation may fail depending on the AllowEmptyP2PGroup configuration. 
		\param customField This is the message sent to related clients from the server when adding a P2P group. You can skip it. 
		\param You can create a P2P group with the HostID users want. The default value is None. If you select None, it is automatically allocated. If you enter a HostID already being used, P2P group creation will fail and None can be returned.
		\return HostID of the created P2P group. The type is HostID.

		\~chinese
		?Ëï?êóà÷?îÜP2P?¡£
		- ĞÆËßAllowEmptyP2PGroup?öÇ£¬?îÜßæà÷Ê¦Òö?ã÷?¡£
		\param customField ôÕÊ¥P2P?£¬?Ê¦ì¤àıÕÔÜ×?ĞïèÙßÓ?client?áêîÜãáãÓ¡£
		\return ?ËïîÜP2P?îÜHost ID¡£?úşãÀHostID¡£

		\~japanese
		«á«ó«Ğ?ªÎªÊª¤P2P«°«ë?«×ªòíÂªêªŞª¹¡£
		- AllowEmptyP2PGroup àâïÒªËªèªÃªÆ«°«ë?«×ßæà÷ªËã÷ø¨ª¹ªëª³ªÈªâª¢ªêªŞª¹¡£
		\param customField P2P «°«ë?«×ªòõÚÊ¥ª·ªÊª¬ªé«µ?«Ğ?ªÇ?Ö§«¯«é«¤«¢«ó«ÈªËáêªë«á«Ã«»?«¸ªÇª¹¡£àıÕÔª·ªÆªâÕŞª¤ªÇª¹¡£
		\param assignedHostID «æ?«¶?ª¬ØĞªàHostIDªòò¥ªÄP2P«°«ë?«×ªòßæà÷ª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£ĞñÜâö·ªÏNoneªÇª¹¡£Noneªòò¦ïÒª¹ªìªĞí»ÔÑùÜªê?ªÆªéªìªŞª¹¡£ªâª·¡¢?ªËŞÅéÄñéªÇª¢ªëHostIDªòìıÕôª¹ªëíŞùê¡¢P2P groupªÎßæà÷ªÏã÷ø¨ª·ªÆNoneªò«ê«¿?«óªÇª­ªŞª¹¡£
		\return íÂªéªìª¿P2P«°«ë?«×ªÎHost IDªÇª¹¡£«¿«¤«×ªÏHostIDªÇª¹¡£

		\~
		*/
		inline HostID CreateP2PGroup(ByteArray customField = ByteArray(), CP2PGroupOption &option = CP2PGroupOption::Default, HostID assignedHostID = HostID_None)
		{
			return CreateP2PGroup(NULL, 0, customField, option, assignedHostID);
		}

		/**
		\~korean
		1°³ ¸â¹ö·Î ±¸¼ºµÈ P2P ±×·ìÀ» ¸¸µì´Ï´Ù.
		- ÀÌ·¸°Ô »ı¼ºÇÑ ±×·ì ³»ÀÇ ÇÇ¾îµé³¢¸®´Â Áï½Ã ¼­·Î°£ ¸Ş½ÃÂ¡À» ÇØµµ µË´Ï´Ù. (Âü°í: \ref robust_p2p) 

		\param memberID ±×·ì¿¡ Ã³À½ µé¾î°¡ ÀÖÀ» ¸â¹öÀÇ HostID ÀÔ´Ï´Ù.
		\param customField P2P ±×·ìÀ» Ãß°¡ÇÏ¸é¼­ ¼­¹ö¿¡¼­ °ü·Ã Å¬¶óÀÌ¾ğÆ®µé¿¡°Ô º¸³»´Â ¸Ş½ÃÁöÀÔ´Ï´Ù. »ı·«ÇÏ¼Åµµ µË´Ï´Ù.
		\param assignedHostID »ç¿ëÀÚ°¡ ¿øÇÏ´Â HostID ¸¦ °¡Áø P2P ±×·ìÀ» »ı¼ºÇÒ ¼ö ÀÖ½À´Ï´Ù. ±âº»°ªÀº NoneÀÔ´Ï´Ù. NoneÀ» ÁöÁ¤ÇÏ¸é ÀÚµ¿ ÇÒ´çµË´Ï´Ù. ¸¸¾à ÀÌ¹Ì »ç¿ëÁßÀÎ HostID ¸¦ ÀÔ·ÂÇÒ °æ¿ì P2P group »ı¼ºÀº ½ÇÆĞÇÏ°í NoneÀ» ¸®ÅÏÇÒ ¼ö ÀÖ½À´Ï´Ù.
		\return ¸¸µé¾îÁø P2P ±×·ìÀÇ Host ID ÀÔ´Ï´Ù. Å¸ÀÔÀº HostID ÀÔ´Ï´Ù.

		\~english 
		You can create a P2P group consisted of one member
		- The peers in the group generated in this way can do messaging with one another immediately (refer to: \ref robust_p2p)

		\param memberID The HostID of the member when joining the group for the first time. 
		\param customField This is the message sent to related clients from the server when adding a P2P group. You can skip it.
		\param You can create a P2P group with the HostID users want. The default value is None. If you select None, it is automatically allocated. If you enter a HostID already being used, P2P group creation will fail and None can be returned.
		\return HostID of the created P2P group. The type is HostID.

		\~chinese
		?Ëïë¦ìé?à÷??à÷îÜP2P?¡£
		- ??ßæà÷îÜ??peerñı?Ê¦ì¤Ø¡??ú¼ßÓû»îÜmessaging¡££¨?ÍÅ£º<a target="_blank" href="http://guide.nettention.com/cpp_en#robust_p2p" >P2P performance of ProudNet</a>£©
		\param memberID ğ¯ìéó­?ìı?îÜà÷?Host ID¡£
		\param customField ôÕÊ¥P2P?£¬?Ê¦ì¤àıÕÔÜ×?ĞïèÙßÓ?client?áêîÜãáãÓ¡£
		\param assignedHostID Ê¦ì¤ßæà÷ò¥êóéÄ?ıñØĞîÜHostIDîÜP2P?¡£ĞñÜâ?ãÀNone¡£åıÍıò¦ïÒ?None??í»??ú¼İÂÛÕ¡£åıÍı?ìıì«î¤ŞÅéÄñéîÜ HostID%£¬?ßæà÷P2P group??ã÷?£¬ñıı¨Return None¡£
		\return ?ËïîÜP2P?îÜHost ID¡£?úşãÀHostID¡£

		\~japanese
		1ËÁªÎ«á«ó«Ğ?ª«ªéÏ°à÷ªµªìª¿P2P«°«ë?«×ªòíÂªêªŞª¹¡£
		- ª³ªÎªèª¦ªËßæà÷ª·ª¿«°«ë?«×?ªÎPeerÊàªÇªÏ¡¢òÁªÁªËªªû»ª¤«á«Ã«»?«¸«ó«°ªòª·ªÆªâÕŞª¤ªÇª¹¡£(?ÍÅ£º\ref robust_p2p)
		\param memberID «°«ë?«×ªËôøªáªÆìıªÃªÆª¤ªë«á«ó«Ğ?ªÎHostIDªÇª¹¡£
		\param customField P2P «°«ë?«×ªòõÚÊ¥ª·ªÊª¬ªé¡¢«µ?«Ğ?ªÇ?Ö§«¯«é«¤«¢«ó«ÈªËáêªë«á«Ã«»?«¸ªÇª¹¡£àıÕÔª·ªÆªâÕŞª¤ªÇª¹¡£
		\param assignedHostID «æ?«¶?ª¬ØĞªàHostIDªòò¥ªÄP2P«°«ë?«×ªòßæà÷ª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£ĞñÜâö·ªÏNoneªÇª¹¡£Noneªòò¦ïÒª¹ªìªĞí»ÔÑùÜªê?ªÆªéªìªŞª¹¡£ªâª·¡¢?ªËŞÅéÄñéªÇª¢ªëHostIDªòìıÕôª¹ªëíŞùê¡¢P2P groupßæà÷ªÏã÷ø¨ª·ªÆ¡¢Noneªò«ê«¿?«óªÇª­ªŞª¹¡£
		\return íÂªéªìª¿P2P«°«ë?«×ªÎHost IDªÇª¹¡£«¿«¤«×ªÏHostIDªÇª¹¡£

		\~
		*/
		inline HostID CreateP2PGroup(HostID memberID, ByteArray customField = ByteArray(), CP2PGroupOption &option = CP2PGroupOption::Default, HostID assignedHostID = HostID_None)
		{
			return CreateP2PGroup(&memberID, 1, customField, option, assignedHostID);
		}

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> À» ÆÄ±«ÇÑ´Ù.
		- ¾È¿¡ ÀÖ´ø ¸ğµç memberµéÀº P2P ±×·ì¿¡¼­ Å»ÅğµÈ´Ù´Â ÀÌº¥Æ®(Proud.INetClientEvent.OnP2PMemberLeave)¸¦ ³ëÆ¼¹Ş´Â´Ù.
		¹°·Ğ, ¼­¹ö¿ÍÀÇ ¿¬°áÀº À¯ÁöµÈ´Ù.
		\param groupHostID ÆÄ±«ÇÒ P2P ±×·ìÀÇ ID
		\return ÇØ´ç P2P ±×·ìÀÌ ¾øÀ¸¸é false.

		\~english
		Destructs <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>
		- All members within will receive an event(Proud.INetClientEvent.OnP2PMemberLeave) that they will be withdrawn from P2P group. Of course, the connection to server will be sustained.
		\param groupHostID ID of P2P group to be destructed
		\return false if there is no P2P group related

		\~chinese
		÷ò?<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%¡£
		- î¤×ìØüîÜá¶êómemberù¬÷×ò±?P2P?÷ÜõóîÜevent£¨Proud.INetClientEvent.OnP2PMemberLeave£©¡£
		?æÔ£¬???ò¥?Ü×?ĞïîÜ?ïÈ¡£
		\param groupHostID é©÷ò?îÜP2P?ID¡£
		\return ?êóßÓ?P2P?îÜ?false¡£

		\~japanese
		\ref p2p_group ªò÷ò?ª·ªŞª¹¡£
		- ?İ»ªËª¢ªÃª¿îïªÆªÎ«á«ó«Ğ?ªÏ¡¢P2P«°«ë?«×ªèªê?÷ÜªµªìªëªÈª¤ª¦«¤«Ù«ó«È(Proud.INetClientEvent.OnP2PMemberLeave)ªò÷×ò±ª·ªÆªâªéª¤ªŞª¹¡£
		Ú¨Öå¡¢«µ?«Ğ?ªÈªÎïÈ?ªÏë«ò¥ªµªìªŞª¹¡£
		\param groupHostID ÷ò?ª¹ªëP2P«°«ë?«×ªÎID
		\return ú±?P2P«°«ë?«×ª¬ªÊª±ªìªĞfalse.

		\~
		*/
		virtual bool DestroyP2PGroup(HostID groupHostID) = 0;

		/**
		\~korean
		¼­¹ö¿¡ »ı¼ºµÇ¾î ÀÖ´Â ¸ğµç <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> À» µÚÁ®¼­, ¸â¹ö°¡ ÀüÇô ¾ø´Â P2P ±×·ì¸¸ °ñ¶ó¼­ ¸ğµÎ ÆÄ±«ÇÑ´Ù.

		\~english
		Search all <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> that is created within server then destructs all P2P groups consist of 0 member.

		\~chinese
		??î¤Ü×?Ğïßæà÷îÜá¶êó <a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%£¬ñş???êóà÷?îÜP2P?ı¨îïİ»÷ò?¡£

		\~japanese
		«µ?«Ğ?ªËßæà÷ªµªìªÆª¤ªëîïªÆªÎ\ref p2p_groupªò÷®ª·ªÆ¡¢«á«ó«Ğ?ª¬îïª¯ªÊª¤P2P«°«ë?«×ªÀª±ªòàÔªóªÇîïªÆ÷ò?ª·ªŞª¹¡£
		\~
		*/
		virtual void DestroyEmptyP2PGroups() = 0;

		/**
		\~korean
		³»ºÎ »óÈ²À» ¹®ÀÚ¿­·Î ¸®ÅÏÇÑ´Ù. µğ¹ö±×¿ëÀ¸·Î ¾µ¸¸ÇÏ´Ù.

		\~english
		Returns internal status as text string. Useful when debugging.

		\~chinese
		éÄí®İ¬ÍúÚ÷üŞ?İ»ï×?¡£Ê¦éÄéÍ??éÄ¡£

		\~japanese
		?İ»?üÏªòÙşí®ÖªªÇ«ê«¿?«óª·ªŞª¹¡£«Ç«Ğ«Ã«°éÄªÇŞÅª¦?ö·ª¬ª¢ªêªŞª¹¡£
		\~
		*/
		virtual String DumpGroupStatus() = 0;

		/**
		\~korean
		Á¢¼ÓÇÑ Å¬¶óÀÌ¾ğÆ® °¹¼ö¸¦ ¾ò´Â´Ù.

		\~english
		Gets the number of connected clients

		\~chinese
		?Ôğ?ïÈîÜclient??¡£

		\~japanese
		ïÈ?ª·ª¿«¯«é«¤«¢«ó«È?ªòÔğªŞª¹¡£
		\~
		*/
		virtual int GetClientCount() = 0;

		/**
		\~korean
		¼­¹ö Ã³¸®·® Åë°è¸¦ ¾ò´Â´Ù.

		\~english
		Gets server process statistics

		\~chinese
		?ÔğÜ×?Ğï?×âÕá??¡£

		\~japanese
		«µ?«Ğ??×âÕáªÎ÷ÖÍªªòÔğªŞª¹¡£
		\~
		*/
		virtual void GetStats(CNetServerStats &outVal) = 0;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ® HostID ¸ñ·ÏÀ» ¾ò´Â´Ù.
		- ÀÌ ¸Ş¼­µå·Î ¾ò´Â ¸ñ·ÏÀº È£ÃâÇÒ ½ÃÁ¡ÀÇ ½º³À¼¦ÀÏ »ÓÀÌ´Ù. ÀÌ ÇÔ¼ö°¡ ¸®ÅÏµÈ ÈÄ¿¡µµ
		Å¬¶óÀÌ¾ğÆ® ¸ñ·ÏÀÇ ³»¿ëÀÌ ½ÇÁ¦ ¼­¹öÀÇ »óÅÂ¿Í µ¿ÀÏÇÔÀ» º¸ÀåÇÏÁö´Â ¾Ê´Â´Ù.
		µû¶ó¼­ Á¤È®ÇÑ Å¬¶óÀÌ¾ğÆ® ¸®½ºÆ®¸¦ ¾ò°íÀÚ ÇÏ¸é INetServerEvent.OnClientJoin,
		INetServerEvent.OnClientLeave ¿¡¼­ À¯Àú°¡ ÇÊ¿ä·Î ÇÏ´Â Å¬¶óÀÌ¾ğÆ® ¸®½ºÆ®¸¦ µû·Î
		¸¸µé¾î °ü¸®ÇÏ´Â °ÍÀ» ±ÇÀåÇÑ´Ù.
		\param output HostID ¸ñ·ÏÀÌ Ã¤¿öÁú °÷
		\param outputLength ¸ñ·ÏÀÇ ÃÖ´ë Å©±â
		\return ½ÇÁ¦ Ã¤¿öÁø Ç×¸ñÀÇ °¹¼ö

		\~english
		Gets client HostID list
		- The list acquired by this method is only a snapshot. After this function is returned, there is no guarantee that the contents in the list matche the status of real server.
		Therefore, in order to get precise client list, it is recommended to create and manage a separate client list needed by user at INetServerEvent.OnClientJoin, INetServerEvent.OnClientLeave.
		\param output Where HostID list to be filled
		\param outputLength Maximum size of the list
		\return The number of clause really filled

		\~chinese
		?Ôğclient Host IDÙÍ?¡£
		- éÄó®Û°Ûö?ÔğîÜÙÍ?ñşãÀé©û¼Ğ£îÜ?ïÃîÜsnapshotì»ì«¡£ó®ùŞ?Ú÷üŞì¤ı¨ÜôÜÁ?clientÙÍ?îÜ?é»???Ü×?Ğï??ßÓÔÒ¡£
		á¶ì¤ßÌ?Ôğïá?îÜclient listîÜ?£¬Ëï?î¤ INetServerEvent.OnClientJoin,
		INetServerEvent.OnClientLeave%?èâ?Ëï?Î·×âéÄ?âÍé©îÜclient list¡£
		\param output HostIDÙÍ??õöîÜò¢Û°¡£
		\param outputLength ÙÍ?îÜõÌÓŞÓŞá³¡£
		\return ???õöîÜ?ÙÍ??¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈHost ID«ê«¹«ÈªòÔğªŞª¹¡£
		- ª³ªÎ«á«½«Ã«ÉªÇÔğªë«ê«¹«ÈªÏû¼ªÓõóª¹ãÁïÃªÎ«¹«Ê«Ã«×«·«ç«Ã«ÈªÇª¢ªëªÀª±ªÇª¹¡£ª³ªÎ??ª¬«ê«¿?«óªµªìª¿ı­ªËªâ«¯«é«¤«¢«ó«È«ê«¹«ÈªÎ?é»ª¬?ğ·«µ?«Ğ?ªÎ?÷¾ªÈÔÒª¸ªÇª¢ªëª³ªÈªòÜÁî¡ª¹ªëª³ªÈªÏª¢ªêªŞª»ªó¡£
		ªèªÃªÆ¡¢ïáü¬ªÊ«¯«é«¤«¢«ó«È«ê«¹«ÈªòÔğª¿ª¤íŞùêªÏ¡¢INetServerEvent.OnClientJoin, INetServerEvent.OnClientLeaveªÇ«æ?«¶?ª¬ù±é©ªÈª¹ªë«¯«é«¤«¢«ó«È«ê«¹«ÈªòÜ¬ªËíÂªÃªÆÎ·×âª¹ªëª³ªÈªòªª?ªáª·ªŞª¹¡£
		\param output HostID «ê«¹«Èª¬?ª¿ªµªìªëá¶
		\param outputLength «ê«¹«ÈªÎõÌÓŞ«µ«¤«º
		\return ?ğ·?ª¿ªµªìª¿ú£ÙÍªÎ?

		\~
		*/
		virtual int GetClientHostIDs(HostID* output, int outputLength) = 0;

		/**
		\~korean
		clientHostID°¡ °¡¸®Å°´Â peer°¡ Âü¿©ÇÏ°í ÀÖ´Â P2P group ¸®½ºÆ®¸¦ ¾ò´Â´Ù.

		\~english
		Gets P2P group list of peer that is pointed by clientHostID

		\~chinese
		?ÔğclientHostIDá¶ò¦îÜpeer??îÜP2P group list¡£

		\~japanese
		clientHostIDª¬ò¦ª¹Peerª¬?Ê¥ª·ªÆª¤ªëP2P group «ê«¹«ÈªòÔğªŞª¹¡£
		\~
		*/
		virtual bool GetJoinedP2PGroups(HostID clientHostID, HostIDArray& output) = 0;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®ÀÇ ¸¶Áö¸· ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param clientID Ã£À¸·Á´Â Å¬¶óÀÌ¾ğÆ®ÀÇ HostID.
		\return ping timeÀ» ¹Ğ¸®ÃÊ´ÜÀ§·Î ¸®ÅÏÇÑ´Ù. ´Ü ¾øÀ¸¸é -1À» ¸®ÅÏÇÑ´Ù.

		\~english
		Gets the last latency of client
		\param clientID HostID of client to find
		\return returns ping time in millisecond. Returns -1 when there is none.

		\~chinese
		?ÔğclientîÜõÌı¨latency¡£
		\param clientID é©?îÜclientîÜHost ID¡£
		\return ping÷êtimeì¤ûÆõ©?êÈÚ÷üŞ¡£Ó£?êóîÜ?Ú÷üŞ-1¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªÎõÌı­ªÎ«ì?«Æ«ó«·?ªòÔğªŞª¹¡£
		\param clientID ÷®ª·ª¿ª¤«¯«é«¤«¢«ó«ÈªÎHostID.
		\return ping timeªò«ß«êõ©?êÈªÇ«ê«¿?«óª·ªŞª¹¡£Ó£ª·¡¢ªÊª±ªìªĞ-1ªò«ê«¿?«óª·ªŞª¹¡£

		\~
		\~
		*/
		inline double GetLastPingSec(HostID clientID, ErrorType* error = NULL)
		{
			int ms = GetLastUnreliablePingMs(clientID, error);

			if (ms < 0)
				return (double)ms;

			return ((double)ms) / 1000;
		}

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®ÀÇ ¸¶Áö¸· ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param clientID Ã£À¸·Á´Â Å¬¶óÀÌ¾ğÆ®ÀÇ HostID.
		\return ping timeÀ» ¹Ğ¸®ÃÊ´ÜÀ§·Î ¸®ÅÏÇÑ´Ù. ´Ü ¾øÀ¸¸é -1À» ¸®ÅÏÇÑ´Ù.

		\~english
		Gets the last latency of client
		\param clientID HostID of client to find
		\return Returns ping time in millisecond.Returns -1 when there is none.

		\~chinese
		?ÔğclientîÜõÌı¨latency¡£
		\param clientID é©?îÜclientîÜHost ID¡£
		\return ping÷êtimeì¤ûÆõ©?êÈÚ÷üŞ¡£Ó£?êóîÜ?Ú÷üŞ-1¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªÎõÌı­ªÎ«ì?«Æ«ó«·?ªòÔğªŞª¹¡£
		\param clientID ÷®ª·ª¿ª¤«¯«é«¤«¢«ó«ÈªÎHostID.
		\return ping timeªò«ß«êõ©?êÈªÇ«ê«¿?«óª·ªŞª¹¡£Ó£ª·¡¢ªÊª±ªìªĞ-1ªò«ê«¿?«óª·ªŞª¹¡£

		\~
		*/
		virtual int GetLastUnreliablePingMs(HostID clientID, ErrorType* error = NULL) = 0;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®ÀÇ ÃÖ±Ù ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param clientID Ã£À¸·Á´Â Å¬¶óÀÌ¾ğÆ®ÀÇ HostID.
		\return ping timeÀ» ÃÊ´ÜÀ§·Î ¸®ÅÏÇÑ´Ù. ´Ü ¾øÀ¸¸é -1À» ¸®ÅÏÇÑ´Ù.

		\~english
		Gets the recent latency of client
		\param clientID HostID of client to find
		\return Returns ping time in millisecond. Returns -1 when there is none.

		\~chinese
		?ÔğclientîÜõÌĞÎlatency¡£
		\param clientID é©?îÜclientîÜHost ID¡£
		\return ping÷êtimeì¤ûÆõ©?êÈÚ÷üŞ¡£Ó£?êóîÜ?Ú÷üŞ-1¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªÎõÌĞÎ«ì?«Æ«ó«·?ªòÔğªŞª¹¡£
		\param clientID ÷®ª·ª¿ª¤«¯«é«¤«¢«ó«ÈªÎHostID.
		\return ping timeªòõ©?êÈªÇ«ê«¿?«óª·ªŞª¹¡£Ó£ª·¡¢ªÊª±ªìªĞ-1ªò«ê«¿?«óª·ªŞª¹¡£

		\~
		*/
		inline double GetRecentPingSec(HostID clientID, ErrorType* error = NULL)
		{
			int ms = GetRecentUnreliablePingMs(clientID, error);

			if (ms < 0)
				return (double)ms;

			return ((double)ms) / 1000;
		}

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®ÀÇ ÃÖ±Ù ·¹ÀÌÅÏ½Ã¸¦ ¾ò´Â´Ù.
		\param clientID Ã£À¸·Á´Â Å¬¶óÀÌ¾ğÆ®ÀÇ HostID.
		\return ping timeÀ» ¹Ğ¸®ÃÊ´ÜÀ§·Î ¸®ÅÏÇÑ´Ù. ´Ü ¾øÀ¸¸é -1À» ¸®ÅÏÇÑ´Ù.

		\~english
		Gets the recent latency of client
		\param clientID HostID of client to find
		\return Returns ping time in millisecond.Returns -1 when there is none.

		\~chinese
		?ÔğclientîÜõÌĞÎlatency¡£
		\param clientID é©?îÜclientîÜHost ID¡£
		\return ping÷êtimeì¤ûÆõ©?êÈÚ÷üŞ¡£Ó£?êóîÜ?Ú÷üŞ-1¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªÎõÌĞÎ«ì?«Æ«ó«·?ªòÔğªŞª¹¡£
		\param clientID ÷®ª·ª¿ª¤«¯«é«¤«¢«ó«ÈªÎHostID.
		\return ping timeªò«ß«êõ©?êÈªÇ«ê«¿?«óª·ªŞª¹¡£Ó£ª·¡¢ªÊª±ªìªĞ-1ªò«ê«¿?«óª·ªŞª¹¡£

		\~
		*/
		virtual int GetRecentUnreliablePingMs(HostID clientID, ErrorType* error = NULL) = 0;

		/**
		\~korean
		µÎ ÇÇ¾î°£ÀÇ ÃÖ±Ù ÇÎ Á¤º¸¸¦ ¹Ş½À´Ï´Ù.

		\~english
		Gets recent ping information between two peers

		\~chinese
		ïÈâ¥??peerñı?îÜõÌĞÎpingãáãÓ¡£

		\~japanese
		ÕáPeerÊàªÎõÌĞÎpingï×ÜÃªòáôª±ªŞª¹¡£
		\~
		*/
		virtual int GetP2PRecentPingMs(HostID HostA, HostID HostB) = 0;

		/**
		\~korean
		P2P group 1°³ÀÇ Á¤º¸¸¦ ¾ò´Â´Ù.

		\~english
		Gets the information of 1 P2P group

		\~chinese
		?ÔğP2P groupìé?ãáãÓ¡£

		\~japanese
		P2P group 1ËÁªÎï×ÜÃªòÔğªŞª¹¡£
		\~
		*/
		virtual bool GetP2PGroupInfo(HostID groupHostID, CP2PGroup &output) = 0;

		/**
		\~korean
		HostID °¡ À¯È¿ÇÑÁö È®ÀÎÇÑ´Ù.
		\param id À¯È¿ÇÑÁö È®ÀÎÇÒ HostID.
		\return trueÀÌ¸é À¯È¿ÇÑ Å¬¶óÀÌ¾ğÆ®, ¼­¹ö È¤Àº <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> ÀÇ HostIDÀÓÀ» ÀÇ¹ÌÇÑ´Ù.

		\~english
		Checks if HostID is valid
		\param id HostID to be used to check if valid
		\return true then valid HsstID of client or server or <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>

		\~chinese
		??Host IDãÀÜúêóüù¡£
		\param id é©??ãÀÜúãÀêóüùîÜHost ID¡£
		\return trueîÜ?êóüùîÜclient£¬ëòÚ«ó·ãÀÜ×?Ğïûäíº<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%îÜHost ID¡£

		\~japanese
		HostID ª¬êó?ªÊªÎª«ªòü¬ìãª·ªŞª¹¡£
		\param id êó?ªÊªÎª«ªòü¬ìãª¹ªë HostID.
		\return trueªÇª¢ªìªĞêó?ªÊ«¯«é«¤«¢«ó«È¡¢«µ?«Ğ?ªŞª¿ªÏ\ref p2p_groupªÎHostIDªòëòÚ«ª·ªŞª¹¡£

		\~
		*/
		virtual bool IsValidHostID(HostID id) = 0;

		/**
		\~korean
		¸ğµç P2P group list¸¦ ¾ò´Â´Ù.
		- »çº» Ä«ÇÇ¸¦ ÇÑ´Ù.

		\~english
		Gets all P2P group list
		- Makes a back up copy

		\~chinese
		?Ôğá¶êóP2P group list¡£
		- ?ìÔÜùÜâ¡£

		\~japanese
		îïªÆªÎP2P group listªòÔğªŞª¹¡£
		- «³«Ô?ª·ªŞª¹¡£

		\~
		*/
		virtual void GetP2PGroups(CP2PGroups& output) = 0;

		/**
		\~korean
		°³¼³µÇ¾î ÀÖ´Â P2P groupÀÇ ÃÑ °¹¼ö¸¦ ¾ò´Â´Ù.

		\~english
		Gets the total number of opened P2P group.

		\~chinese
		?Ôğ??îÜP2P groupîÜ???¡£

		\~japanese
		ËÒàâªµªìªÆª¤ªëP2P groupªÎ??ªòÔğªŞª¹¡£
		\~
		*/
		virtual int GetP2PGroupCount() = 0;

		/**
		\~korean
		ÀÌ °´Ã¼¿¡ ¿¬°áµÈ peer 1°³ÀÇ Á¤º¸¸¦ ¾ò´Â´Ù.
		\param peerHostID Ã£À¸·Á´Â peerÀÇ HostID
		\param output Ã£Àº peerÀÇ Á¤º¸. ¸ø Ã£À¸¸é ¾Æ¹«°Íµµ Ã¤¿öÁöÁö ¾Ê´Â´Ù.
		\return trueÀÌ¸é Ã£¾Ò´Ù´Â ¶æ

		\~english
		Gets the information of 1 peer connected to this object
		\param peerHostID HostID of peer to find
		\param output Infoof foudn peer. Nothing will be filled when found nothing.
		\return true when found

		\~chinese
		?Ôğ?ïÈ?ó®?ßÚîÜìé?peerãáãÓ¡£
		\param peerHostID é©?îÜpeerîÜHostID¡£
		\param output ?ÓğîÜpeerãáãÓ¡£?êó?ÓğîÜ?Üô?õöìòù¼?à¤¡£
		\return trueãÀ?ÓğÖõîÜëòŞÖ¡£

		\~japanese
		ª³ªÎ«ª«Ö«¸«§«¯«ÈªËïÈ?ªµªìª¿Peer 1ËÁªÎï×ÜÃªòÔğªŞª¹¡£
		\param peerHostID ÷®ª·ª¿ª¤PeerªÎHostID
		\param output ÷®ª·ª¿PeerªÎï×ÜÃ¡£÷®ª»ªÊª«ªÃª¿ªéù¼ªâ?ª¿ªµªìªŞª»ªó¡£
		\return trueªÇª¢ªìªĞ÷®ª·ª¿ªÈª¤ª¦ëòÚ«

		\~
		*/
		virtual bool GetClientInfo(HostID clientHostID, CNetClientInfo& output) = 0;

		/**
		\~korean
		clientHostID°¡ °¡¸®Å°´Â Å¬¶óÀÌ¾ğÆ®°¡ Á¢¼ÓÁßÀÎÁö Ã¼Å©ÇÑ´Ù.
		\return Á¢¼ÓÁßÀÎ Å¬¶óÀÌ¾ğÆ®ÀÌ¸é true¸¦ ¸®ÅÏÇÑ´Ù.

		\~english
		Checks if the client pointed by clientHostID is logged on
		\return if found to be logged on client then returns true

		\~chinese
		??clientHostIDá¶ò¦îÜclientãÀÜúãÀ?ïÈñé¡£
		\return ?ïÈñéîÜclientîÜ?Ú÷üŞtrue¡£

		\~japanese
		clientHostIDª¬ò¦ª¹«¯«é«¤«¢«ó«Èª¬ïÈ?ñéªÊªÎª«ªò«Á«§«Ã«¯ª·ªŞª¹¡£
		\return ïÈ?ñéªÎ«¯«é«¤«¢«ó«ÈªÇª¢ªìªĞtureªò«ê«¿?«óª·ªŞª¹¡£

		\~
		*/
		virtual bool IsConnectedClient(HostID clientHostID) = 0;

		/**
		\~korean
		GetClientInfo¿Í °°Àº ¿ªÇÒÀ» ÇÏ¸ç, ÀÌÁ¦ ´õ ÀÌ»ó ¾È¾²´Â ÇÔ¼ö´Ù. ´ë½Å GetClientInfo¸¦ »ç¿ëÇÏ´Â °ÍÀ» ±ÇÀåÇÑ´Ù.

		\~english
		Performs roles as GetClientInfo but not to be used any more. It is recommended to use GetClientInfo instead.

		\~chinese
		ÑÃó·?GetClientInfoìé?îÜíÂéÄ£¬ì»ó¦ãÀÜôî¢ŞÅéÄîÜùŞ?¡£Ëï?ŞÅéÄGetClientInfo?ÓÛôğ¡£

		\~japanese
		GetClientInfoªÈÔÒª¸æµùÜªòª·ªÆ¡¢ª³ªìì¤ß¾ŞÅªïªÊª¤??ªÇª¹¡£ÓÛªïªêªËGetClientInfoªòŞÅª¦ª³ªÈªòªª?ªáª·ªŞª¹¡£
		\~
		*/
		PN_DEPRECATED inline bool GetPeerInfo(HostID clientHostID, CNetClientInfo& output)
		{
			return GetClientInfo(clientHostID, output);
		}

		/**
		\~korean
		ÀÌ È£½ºÆ®¿¡ ¿¬°áµÈ ´Ù¸¥ È£½ºÆ®(¼­¹öÀÇ °æ¿ì Å¬¶óÀÌ¾ğÆ®µé, Å¬¶óÀÌ¾ğÆ®ÀÇ °æ¿ì ÇÇ¾îµé)µé °¢°¢¿¡ÀÇ tag¸¦ ÁöÁ¤ÇÕ´Ï´Ù. <a target="_blank" href="http://guide.nettention.com/cpp_ko#host_tag" >°¢ È£½ºÆ®¿¡ ´ëÇÑ »ç¿ëÀÚ Á¤ÀÇ µ¥ÀÌÅÍ(Tag)</a> ±â´ÉÀÔ´Ï´Ù.
		- ÀÚ±â ÀÚ½Å(¼­¹ö È¤Àº Å¬¶óÀÌ¾ğÆ®)¿¡ ´ëÇÑ tag µµ ÁöÁ¤ÇÒ ¼ö ÀÖ½À´Ï´Ù.

		\~english
		Designates tag to each of other hosts(clients for servers, peers for clients) that are connected to this host. A <a target="_blank" href="http://guide.nettention.com/cpp_en#host_tag" >User-defined data(Tag) for each host</a> function.
		- Can designate tag to itself(server or client)

		\~chinese
		ò¦ïÒèÙ??ñ«Ïõ?ïÈîÜĞìöâñ«Ïõ£¨Ü×?ĞïîÜûÉclient£¬clientîÜ?peer£©îÜtag¡£<a target="_blank" href="http://guide.nettention.com/cpp_zh#host_tag" >?ÊÀ?ñ«ÏõîÜéÄ?ïÒ??Ëß£¨Tag£©</a>%ÍíÒö¡£
		- å¥Ê¦ì¤ò¦ïÒí»ĞùÜâãó£¨Ü×?Ğïûäíºclient£©îÜtag¡£

		\~japanese
		ª³ªÎ«Û«¹«ÈªËïÈ?ªµªìª¿öâªÎ«Û«¹«È(«µ?«Ğ?ªÎíŞùêªÏ«¯«é«¤«¢«ó«È¡¢«¯«é«¤«¢«ó«ÈªÎíŞùêªÏPeer)ªÎª½ªìª¾ªìªËtagªòò¦ïÒª·ªŞª¹¡£\ref host_tag Ñ¦ÒöªÇª¹¡£
		- í»İÂí»ãó(«µ?«Ğ?ªŞª¿ªÏ«¯«é«¤«¢«ó«È)ªË?ª¹ªëtagªâò¦ïÒª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£

		\~
		*/
		virtual bool SetHostTag(HostID hostID, void* hostTag) = 0;

		/**
		\~korean
		¼­¹öÀÇ ÇöÀç ½Ã°£À» ¾ò´Â´Ù. CNetClient.GetServerTimeMs()°ú °ÅÀÇ °°Àº °ªÀÌ´Ù.

		\~english
		Gets current time of server. Has almost same value as CNetClient.GetServerTimeMs().

		\~chinese
		?ÔğÜ×?ĞïîÜ?î¤??¡£? CNetClient.GetServerTimeMs()ĞñÜâßÓÔÒîÜ?¡£

		\~japanese
		«µ?«Ğ?ªÎúŞî¤ãÁÊàªòÔğªŞª¹¡£CNetClient.GetServerTimeMs()ªÈªÛªÜÔÒª¸ö·ªÇª¹¡£
		\~
		*/
		virtual int64_t GetTimeMs() = 0;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ® memberHostID°¡ ±â Á¸Àç <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a>  groupHostID¿¡ Áßµµ Âü¿©ÇÏ°Ô ÇÕ´Ï´Ù.
		- Âü¿© ½ÃµµµÈ ÇÇ¾îµé°ú ±âÁ¸¿¡ Âü¿©µÇ¾î ÀÖ´ø ÇÇ¾îµé ³¢¸®´Â Áï½Ã ¼­·Î°£ ¸Ş½ÃÂ¡À» ÇØµµ µË´Ï´Ù.  (Âü°í: <a target="_blank" href="http://guide.nettention.com/cpp_ko#robust_p2p" >ProudNetÀÇ P2P Åë½Å ¼º´É</a>)

		\param memberHostID P2P ±×·ì¿¡ Âü¿©ÇÒ ¸â¹öÀÇ Host ID. HostID_Server °¡ µé¾î°¡µµ µÇ´ÂÁö ¿©ºÎ´Â <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_as_p2pgroup_member" >P2P ±×·ì ¸â¹ö·Î¼­ ¼­¹ö¸¦ Æ÷ÇÔ½ÃÅ°±â</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.
		\param groupHostID ÀÌ¹Ì ¸¸µé¾îÁø P2P ±×·ìÀÇ Host IDÀÔ´Ï´Ù.
		\param customField P2P ±×·ìÀ» Ãß°¡ÇÏ¸é¼­ ¼­¹ö¿¡¼­ °ü·Ã Å¬¶óÀÌ¾ğÆ®µé¿¡°Ô º¸³»´Â ¸Ş½ÃÁöÀÔ´Ï´Ù. INetClientEvent.OnP2PMemberJoin ¿¡¼­ ±×´ë·Î ¹Ş¾ÆÁı´Ï´Ù.
		\return ¼º°ø½Ã true¸¦ ¸®ÅÏÇÕ´Ï´Ù.

		\~english
		Lets client memberHostID enter into existing <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> groupHostID
		- Messaging can do between existed peer and new peer. (Reference: <a target="_blank" href="http://guide.nettention.com/cpp_en#robust_p2p" >P2P performance of ProudNet</a>)

		\param memberHostID HostID of member to join P2P group. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#server_as_p2pgroup_member" >How to include a server as a peer-to- peer group member</a> to find out if HostID_Server can join.
		\param groupHostID HostID of existing P2P group
		\param customField Message to be sent to related clients from server when adding P2P group. Will be accepted as it is at INetClientEvent.OnP2PMemberJoin.
		\return returns true if successful

		\~chinese
		?ClientîÜmemberHostIDèÙì«ğíî¤îÜ <a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a> groupHostIDñéÔ²??¡£
		- ????îÜpeerûúñıîñ??îÜpeerñı?Ê¦ì¤Ø¡??ú¼messaging£¨?ÍÅ <a target="_blank" href="http://guide.nettention.com/cpp_zh#robust_p2p" >ProudNet îÜP2P÷×ãáÍíÒö</a>£©¡£

		\param memberHostID ??P2P?îÜà÷?Host ID¡£ HostID_Server ãÀÜúå¥Òö?ìı??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_as_p2pgroup_member" >ì¤P2PîÜ?à÷?ùŞÎÀÜ×?Ğï</a>%¡£
		\param groupHostID ì«??ËïîÜP2P?îÜHost ID¡£
		\param customField ôÕÊ¥P2P?îÜ?ı¦Ü×?ĞïèÙßÓ?client?áêîÜãáãÓ¡£î¤ INetClientEvent.OnP2PMemberJoin%ê«ÜæÜô?îÜù¬ïÈâ¥¡£
		\return à÷ÍíîÜ?ı¦Ú÷üŞtrue¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈmemberHostIDª¬?ªËğíî¤¡£\ref p2p_group  groupHostIDªËñéÔ²?Ê¥ª¹ªëªèª¦ªËª·ªŞª¹¡£
		- ?Ê¥ªòãËª·ª¿PeerªÈ?ğíªË?Ê¥ª·ªÆª¤ª¿PeerÊàªÇªÏ¡¢òÁªÁªË«á«Ã«»?«¸«ó«°ªòª·ªÆªâÕŞª¤ªÇª¹¡£(?ÍÅ£º\ref robust_p2p)
		\param memberHostID P2P «°«ë?«×ªË?Ê¥ª¹ªë«á«ó«Ğ?ªÎHost ID¡£HostID_Serverª¬ìıªÃªÆªâª¤ª¤ª«ªÏ¡¢\ref server_as_p2pgroup_memberªòª´?ğÎª¯ªÀªµª¤¡£
		\param groupHostID ?ªËíÂªéªìª¿P2P«°«ë?«×ªÎHost IDªÇª¹¡£
		\param customField P2P «°«ë?«×ªòõÚÊ¥ª·ªÊª¬ªé¡¢«µ?«Ğ?ªèªê?Ö§«¯«é«¤«¢«ó«ÈªËáêªë«á«Ã«»?«¸ªÇª¹¡£ INetClientEvent.OnP2PMemberJoin ªèªêª½ªÎªŞªŞáôª±ö¢ªéªìªŞª¹¡£
		\return à÷ÍíãÁªËtrueªò«ê«¿?«óª·ªŞª¹¡£

		\~
		*/
		virtual bool JoinP2PGroup(HostID memberHostID, HostID groupHostID, ByteArray customField = ByteArray()) = 0;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ® memberHostID°¡ <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a>  groupHostID ¸¦ ³ª°¡°Ô ÇÑ´Ù.
		- Ãß¹æµÇ´Â Å¬¶óÀÌ¾ğÆ®¿¡¼­´Â P2P ±×·ìÀÇ ¸ğµç ¸â¹ö¿¡ ´ëÇØ(ÀÚ±â ÀÚ½Å Æ÷ÇÔ) INetClientEvent.OnP2PMemberLeave ÀÌ ¿¬¼ÓÀ¸·Î È£ÃâµÈ´Ù.
		ÇÑÆí, P2P groupÀÇ ³ª¸ÓÁö ¸â¹öµéÀº Ãß¹æµÇ´Â Å¬¶óÀÌ¾ğÆ®¿¡ ´ëÇÑ INetClientEvent.OnP2PMemberLeave ¸¦ È£Ãâ¹Ş´Â´Ù.
		- ¸â¹ö°¡ ÀüÇô ¾ø´Â, Áï ºñ¾îÀÖ´Â P2P group°¡ µÉ °æ¿ì AllowEmptyP2PGroupÀÇ ¼³Á¤¿¡ µû¶ó ÀÚµ¿ ÆÄ±«µÇ°Å³ª ÀÜÁ¸ ÈÄ Àç»ç¿ë °¡´ÉÇÏ´Ù.

		\param memberHostID Ãß¹æÇÒ ¸â¹öÀÇ Host ID
		\param groupHostID ¾î¶² ±×·ìÀ¸·ÎºÎÅÍ Ãß¹æ½ÃÅ³ °ÍÀÎ°¡
		\return ¼º°øÀûÀ¸·Î Ãß¹æ½Ã true¸¦ ¸®ÅÏ

		\~english
		Client memberHostID lets <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> groupHostID go out
		- At the client being kicked out, INetClientEvent.OnP2PMemberLeave will be called one after another for all members of P2P group(including itself).
		On the other hand, INetClientEvent.OnP2PMemberLeave will be called for other members of P2P group that are to be kicked out.
		- For those of no members, in other words for an empty P2P group, they will be either auto-destructed by AllowEmptyP2PGroup setting or can be re-used after its survival.

		\param memberHostID HostID of member to be kicked out
		\param groupHostID to be kicked out from which group?
		\return returns true if successfully kicked out

		\~chinese
		Client îÜmemberHostID? <a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a> groupHostID÷Üõó¡£
		- î¤ù¬?õóËÛîÜclient?P2P?îÜá¶êóà÷?£¨øĞÎÀí»ĞùÜâãó£©INetClientEvent.OnP2PmemberLeave%??û¼Ğ£¡£
		ìéÛ°ØüP2P groupîÜí¥ù»à÷??ù¬û¼Ğ£??õóîÜclientîÜ INetClientEvent.OnP2PMemberLeave¡£
		- ?êóà÷?îÜ?£¬?à÷?ÍöîÜP2P groupîÜ?ı¦ĞÆËßAllowEmptyP2PgroupîÜ?öÇÊ¦ì¤í»?÷ò?ûäíº?×ºı¨î¢ŞÅéÄ¡£

		\param memberHostID é©?õóîÜHost ID¡£
		\param groupHostID é©?????õó¡£
		\return ?õóà÷ÍíîÜ?Ú÷üŞtrue¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈmemberHostIDª¬\ref p2p_group  groupHostID ªòõóªÆú¼ª¯ªèª¦ªËª·ªŞª¹¡£
		- õÚª¤õóªµªìªë«¯«é«¤«¢«ó«ÈªÇªÏ¡¢P2P«°«ë?«×ªÎîïªÆªÎ«á«ó«Ğ?ªË?ª·ªÆ(í»İÂí»ãóªòùßªà) INetClientEvent.OnP2PMemberLeaveª¬Ö§?ªÇû¼ªÓõóªµªìªŞª¹¡£
		ìéÛ°¡¢P2P groupªÎ?ªêªÎ«á«ó«Ğ?ªÏ¡¢õÚª¤õóªµªìªë«¯«é«¤«¢«ó«ÈªË?ª¹ªëINetClientEvent.OnP2PMemberLeaveªòû¼ªÓõóª·ªÆªâªéª¤ªŞª¹¡£
		- «á«ó«Ğ?ª¬îïª¯ªÊª¤¡¢ª¹ªÊªïªÁÍöª¤ªÆª¤ªëP2P groupªËªÊªëíŞùê¡¢AllowEmptyP2PGroupªÎàâïÒªËªèªÃªÆí»ÔÑ÷ò?ªµªìªëª«¡¢?ğíı­ªËî¢ŞÅéÄª¬Ê¦ÒöªÇª¹¡£
		\param memberHostID õÚª¤õóªµªìªë«á«ó«Ğ?ªÎHost ID
		\param groupHostID ªÉªÎ«°«ë?«×ª«ªéõÚª¤õóªµª»ªëª«£¿
		\return õÚª¤õóª·ªËà÷Ííª·ª¿ãÁ¡¢trueªò«ê«¿?«ó

		\~
		*/
		virtual bool LeaveP2PGroup(HostID memberHostID, HostID groupHostID) = 0;

		/**
		\~korean
		ÀÌº¥Æ®¸¦ ¹ŞÀ» ¼ö ÀÖ´Â °´Ã¼¸¦ ¼³Á¤ÇÑ´Ù.
		- ÇÏ³ª¸¸ ¼³Á¤ °¡´ÉÇÏ´Ù.
		- ÀÌ ¸Ş¼­µå´Â Å¬¶óÀÌ¾ğÆ®°¡ ¼­¹ö¿¡ ¿¬°áÀ» ½ÃµµÇÏ±â Àü¿¡¸¸ È£ÃâÇÒ ¼ö ÀÖ´Ù. ¾È±×·¯¸é exceptionÀÌ throwµÈ´Ù.

		\~english
		Sets an object that can receive event
		- Can set only 1 object
		- This method can only be called before client attempts to connect to server. Otherwise, an execption will be 'throw'n.

		\~chinese
		?öÇÊ¦ì¤ïÈâ¥eventîÜ?ßÚ¡£
		- ñşÒö?öÇìé?¡£
		- ó®Û°Ûöî¤client???ïÈÜ×?Ğïñıîñû¼õó¡£Üú??exceptionÀÌ throw¡£

		\~japanese
		«¤«Ù«ó«Èªòáôª±ªéªìªë«ª«Ö«¸«§«¯«ÈªòàâïÒª·ªŞª¹¡£
		- ª³ªÎ«á«½«Ã«ÉªÏ«¯«é«¤«¢«ó«Èª¬«µ?«Ğ?ïÈ?ªòãËª¹îñªÎªßû¼ªÓõóª¹ª³ªÈª¬ªÇª­ªŞª¹¡£ª½ª¦ª·ªÊª±ªìªĞ¡¢exceptionª¬throwªµªìªŞª¹¡£

		\~
		*/
		virtual void SetEventSink(INetServerEvent* eventSink) = 0;

		// ÁÖÀÇ: ½ÇÁ¸ °´Ã¼ÀÌ¹Ç·Î SUPPORTS_LAMBDA_EXPRESSION·Î °¨½ÎÁö ¸» °Í.

		/// See Proud.INetServerEvent.OnClientJoin for details.
		LambdaBaseHolder_Param1<void, CNetClientInfo*> OnClientJoin;
		/// See Proud.INetServerEvent.OnClientLeave for details.
		LambdaBaseHolder_Param3<void, CNetClientInfo *, ErrorInfo *, const ByteArray& > OnClientLeave;
		/// See Proud.INetServerEvent.OnClientHackSuspected for details.
		LambdaBaseHolder_Param2<void, HostID, HackType > OnClientHackSuspected;
		/// See Proud.INetServerEvent.OnClientOffline for details.
		LambdaBaseHolder_Param1<void, CRemoteOfflineEventArgs &> OnClientOffline;
		/// See Proud.INetServerEvent.OnClientOnline for details.
		LambdaBaseHolder_Param1<void, CRemoteOnlineEventArgs &> OnClientOnline;
		/// See Proud.INetServerEvent.OnConnectionRequest for details.
		LambdaBaseHolder_Param4<void, AddrPort, ByteArray&, ByteArray&, bool*> OnConnectionRequest;
		/// See Proud.INetServerEvent.OnP2PGroupJoinMemberAckComplete for details.
		LambdaBaseHolder_Param3<void, HostID, HostID, ErrorType > OnP2PGroupJoinMemberAckComplete;
		/// See Proud.INetServerEvent.OnP2PGroupRemoved for details.
		LambdaBaseHolder_Param1<void, HostID > OnP2PGroupRemoved;
		/// See Proud.INetServerEvent.OnUserWorkerThreadBegin for details.
		LambdaBaseHolder_Param0<void> OnUserWorkerThreadBegin;
		/// See Proud.INetServerEvent.OnUserWorkerThreadEnd for details.
		LambdaBaseHolder_Param0<void> OnUserWorkerThreadEnd;


	public:
		/**
		\~korean
		¼­¹ö¸¦ ½ÃÀÛÇÕ´Ï´Ù. ¼­¹ö ½ÃÀÛÀ» ÇÏÁö ¸øÇÒ °æ¿ì Proud.ExceptionÀÌ throw µË´Ï´Ù.
		\param ¼­¹ö ½ÃÀÛÀ» À§ÇÑ ¼³Á¤ ³»¿ëÀÔ´Ï´Ù. TCP listen port µîÀ» ÁöÁ¤ÇÕ´Ï´Ù.

		\~english
		The server starts. If the server does not start, Proud.Exception will throw.
		Setting for the initiating the \param server. Able to indicate TCP listen port.

		\~chinese
		?ã·??Ü×?Ğï£¬åıÍıÙéÛö??? Proud.Exception ?ù¬ throw¡£
		\param Ü×?Ğï??ßÓ??öÇ?é»£¬ò¦ïÒ TCP listen port Ôõ¡£


		\~japanese
		«µ?«Ğ?ªòÑÃÔÑª·ªŞª¹¡£ «µ?«Ğª¬ÑÃÔÑª·ªÆª¤ªÊª¤íŞùêªÏProud.Exceptionª¬throwªµªìªŞª¹¡£
		\Param «µ?«ĞªòÑÃÔÑª¹ªëª¿ªáªÎü¬Ø¡ªÎ?é»ªÇª¹¡£ TCP listen portÔõªòò¦ïÒª·ªŞª¹¡£
		*/
		virtual void Start(CStartServerParameter &param) = 0;

		/**
		\~korean
		¼­¹ö¸¦ ½ÃÀÛÇÕ½Ã´Ù. ¼­¹ö ½ÃÀÛÀ» ÇÏÁö ¸øÇÒ °æ¿ì outError¿¡ ¿¡·¯ ³»¿ëÀÌ µé¾î°©´Ï´Ù.
		ÀÚ¼¼ÇÑ °ÍÀº Proud.CNetServer.Start(CStartServerParameter&)¸¦ Âü°íÇÏ½Ê½Ã¿À.

		\~english
		The server starts. If the server does not start, error information goes in to outError.
		For detail information please refer to Proud.CNetServer.Start(CStartServerParameter&).

		\~chinese
		?ã·??Ü×?Ğï£¬åıÍıÙéÛö??????é»??ìı outError¡£
		???é»??ÍÅ Proud.CNetServer.Start(CStartServerParameter&)¡£

		\~japanese
		«µ?«Ğ?ªòÑÃÔÑª·ªŞª¹¡£«µ?«Ğª¬ÑÃÔÑª·ªÆª¤ªÊª¤íŞùêªÏoutErrorªË«¨«é?ªÎ?é»ª¬ìıªêªŞª¹¡£
		ßÙá¬ªËªÄª¤ªÆªÏ Proud.CNetServer.Start(CStartServerParameter&)ªò?ğÎª·ªÆª¯ªÀªµª¤¡£
		*/
		virtual void Start(CStartServerParameter &param, ErrorInfoPtr& outError) = 0;

		/**
		\~korean
		¼­¹ö¸¦ Á¾·áÇÑ´Ù.
		-ÁÖÀÇ!! ÀÌ ÇÔ¼ö´Â rmiµî UserWorkerThread¿¡¼­ È£ÃâÇÏ´Â ÇÔ¼ö³»¿¡¼­´Â È£ÃâÇØ¼­´Â ¾ÈµË´Ï´Ù.

		\~english
		Stop server.
		- Warning!! This function never call in function that call from UserWorkerThread such as rmi.

		\~chinese
		?ò­Ü×?Ğï¡£
		- ñ¼ëò£¡ÜôÒö÷êó®ùŞ?î¤rmiÔõUserWorkerThreadû¼Ğ£îÜùŞ??û¼Ğ£¡£

		\~japanese
		«µ?«Ğ?ªòğûÖõª·ªŞª¹¡£
		-ª´ñ¼ëò!! ª³ªÎ??ªÏrmiªÊªÉUserWorkerThreadªÇû¼ªÓõóª¹???ªÇªÏû¼ªÓõóª·ªÆªÏª¤ª±ªŞª»ªó¡£

		\~
		*/
		virtual void Stop() = 0;

		/**
		\~korean
		¸â¹ö°¡ ÀüÇô ¾ø´Â <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> ÀÌ À¯ÁöµÉ ¼ö ÀÖµµ·Ï ¼³Á¤ÇÏ´Â ¿É¼Ç. ±âº»ÀûÀ¸·Î´Â true·Î ¼³Á¤µÇ¾î ÀÖ´Ù.
		- true·Î ¼³Á¤µÉ °æ¿ì: CreateP2PGroup È£Ãâ½Ã ¸â¹ö 0°³Â¥¸® P2P ±×·ìÀ» »ı¼ºÇØµµ ¼º°øÇÑ´Ù. ¸â¹ö°¡ 0°³Â¥¸® P2P ±×·ìÀÌ °è¼Ó Á¸ÀçÇÑ´Ù.
		ÀÌ·¯ÇÑ °æ¿ì »ç¿ëÀÚ´Â ¸â¹ö°¡ 0°³ÀÎ P2P ±×·ìÀÌ °è¼ÓÇØ¼­ ¼­¹ö¿¡ ³²Áö ¾Êµµ·Ï, ÇÊ¿äÇÑ °æ¿ì DestroyP2PGroup ¶Ç´Â DestroyEmptyP2PGroups À» È£ÃâÇØ¾ß ÇÑ´Ù.
		- false·Î ¼³Á¤µÉ °æ¿ì: CreateP2PGroup È£Ãâ½Ã ¸â¹ö 0°³Â¥¸® P2P ±×·ìÀ» »ı¼ºÇÒ ¼ö ¾ø´Ù. P2P ±×·ìÀÇ ¸â¹ö°¡ 0°³°¡ µÇ¸é ±× P2P ±×·ìÀº ÀÚµ¿ ÆÄ±«µÈ´Ù.

		\~english
		Option to set <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> without member can be sustained. Default is true.
		- When set as true: Creating P2P group of 0 member will succeed when CreateP2PGroup is called. The P2P group of 0 member will sustain.
		In this case, user must call DestroyP2PGroup or DestroyEmptyP2PGroups to prevent the P2P group of 0 member to be left in server.
		- When set as false: Creating P2P group of 0 member will fail when CreateP2PGroup is called. If the number of P2P group becomes 0 then the P2P group will be destructed automatically.

		\~chinese
		?öÇà÷<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%?êóà÷??å¥Òö?ò¥îÜ??¡£Ùù??öÇ?true¡£
		- ?öÇ?trueîÜ?£ºû¼Ğ£CreateP2PgroupîÜ?£¬?ŞÅßæà÷0?à÷?îÜP2P?å¥?à÷Íí¡£0?à÷?îÜP2P???ğíî¤¡£
		??ı¦éÄ?Üôé©?0?à÷?îÜP2P???ğíî¤éÍÜ×?Ğï£¬?ó¦âÍé©îÜ?û¼Ğ£DestroyP2PGroupûäíºDestroyEmptyP2PGroups¡£
		- ?öÇ?falseîÜ?£ºû¼Ğ£CreateP2PGroup?ÜôÒößæà÷0?à÷?îÜP2P?¡£P2P ?îÜà÷??à÷0?îÜ?Ñá?P2P??í»?÷ò?¡£

		\~japanese
		«á«ó«Ğ?ªÎîïª¯ªÊª¤\ref p2p_groupª¬ë«ò¥ªµªìªëªèª¦ªËàâïÒª¹ªë«ª«×«·«ç«ó¡£ĞñÜâîÜªËªÏtrueªËàâïÒªµªìªÆª¤ªŞª¹¡£
		- trueªËàâïÒªµªìªëíŞùê£ºCreateP2PGroupªòû¼ªÓõóª¹ãÁ¡¢«á«ó«Ğ?0ËÁªÎP2P«°«ë?«×ªòßæà÷ª·ªÆªâà÷Ííª·ªŞª¹¡£«á«ó«Ğ?ª¬0ËÁªÎP2P«°«ë?«×ª¬?ª±ªÆğíî¤ª·ªŞª¹¡£
		ª³ªÎªèª¦ªÊíŞùê¡¢«æ?«¶?ªÏ«á«ó«Ğ?ª¬0ËÁªÇª¢ªëP2P«°«ë?«×ª¬?ª±ªÆ«µ?«Ğ?ªÎ?ªéªÊª¤ªèª¦ªË¡¢ù±é©ªÊíŞùê¡¢DestroyP2PGroupªŞª¿ªÏDestroyEmptyP2PGroupsªòû¼ªÓõóªµªÊª±ªìªĞªÊªêªŞª»ªó¡£
		- falseªËàâïÒªµªìªëíŞùê£ºCreateP2PGroupªòû¼ªÓõóª¹ãÁ¡¢«á«ó«Ğ?0ËÁªÎP2P«°«ë?«×ªòßæà÷ª¹ªëª³ªÈªÏªÇª­ªŞª»ªó¡£P2P«°«ë?«×ªÎ«á«ó«Ğ?ª¬0ËÁªËªÊªëªÈª½ªÎP2P«°«ë?«×ªÏí»ÔÑ÷ò?ªµªìªŞª¹¡£

		\~
		*/
		virtual void AllowEmptyP2PGroup(bool enable) = 0;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®¿¡¼­ ÀÎ½Ä °¡´ÉÇÑ ¼­¹öÀÇ ¸®½º´× ÁÖ¼Ò ¸®½ºÆ®¸¦ ¾ò´Â´Ù.
		- ¼­¹ö ½ÃÀÛ½Ã ¹ŞÀº ¼­¹ö ÁÖ¼Ò¸¦ Åä´ë·Î ¸®ÅÏÇÑ´Ù. NAT³ª 2°³ ÀÌ»óÀÇ ·£Ä«µå°¡ ÀÖ´Â °æ¿ì À¯¿ëÇÏ´Ù.

		\~english
		Gets listening port address of the server that can be recognized by client
		- Returns values based on the server addresses that are received when server started. This is useful when using NAT or 2 or more LAN cards.

		\~chinese
		?Ôğî¤clientÊ¦ì¤??îÜÜ×?Ğïlisteningò¢ò£list¡£
		- ??Ü×?Ğï?ĞñéÍÜ×?Ğïò¢ò£Ú÷üŞ¡£êóNATûäíº2?ì¤ß¾LAN?îÜ?ı¦êóéÄ¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªÇìããÛÊ¦ÒöªÊ«µ?«Ğ?ªÎ«ê«¹«Ë«ó«°«¢«É«ì«¹ªòÔğªŞª¹¡£
		- «µ?«Ğ?ªòËÒã·ãÁªËáôª±ª¿«µ?«Ğ?«¢«É«ì«¹ªò÷Ï÷»ªË«ê«¿?«óª·ªŞª¹¡£NATªÈª«2ËÁì¤ß¾ªÎLAN««?«Éª¬ª¢ªëíŞùêêóéÄªÇª¹¡£

		\~
		*/
		virtual void GetRemoteIdentifiableLocalAddrs(CFastArray<NamedAddrPort> &output) = 0;

		/**
		\~korean
		TCP listener portÀÇ ·ÎÄÃ ÁÖ¼Ò ¸®½ºÆ®¸¦ ¾ò´Â´Ù. ¿¹¸¦ µé¾î ¼­¹ö Æ÷Æ®¸¦ µ¿Àû ÇÒ´çÇÑ °æ¿ì ÀÌ°ÍÀ» ÅëÇØ ½ÇÁ¦ ¼­¹öÀÇ ¸®½º´× Æ÷Æ® ¹øÈ£¸¦ ¾òÀ» ¼ö ÀÖ´Ù.

		\~english
		Gets local address of TCP listener port. For an example, it is possible to acquire the listening port number of real server through this when the server ports are dynamically allocated.

		\~chinese
		?ÔğTCP listener portîÜÜâò¢ò¢ò£list¡£ÖÇåı??İÂÛÕÜ×?ĞïÓ®Ï¢îÜ?ı¦£¬÷×???Ê¦ì¤?Ôğ??Ü×?ĞïîÜlisteningÓ®Ï¢??¡£

		\~japanese
		TCP listener portªÎ«í?«««ë«¢«É«ì«¹«ê«¹«ÈªòÔğªŞª¹¡£ÖÇª¨ªĞ¡¢«µ?«Ğ?«İ?«Èªò«À«¤«Ê«ß«Ã«¯ªËùÜªê?ªÆª¿íŞùê¡¢ª³ªìªò÷×ª¸?ğ·«µ?«Ğ?ªÎ«ê«¹«Ë«ó«°«İ?«ÈÛã?ªòÔğªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\~
		*/
		virtual void GetTcpListenerLocalAddrs(CFastArray<AddrPort> &output) = 0;

		/**
		\~korean
		UDP listener portÀÇ ·ÎÄÃ ÁÖ¼Ò ¸®½ºÆ®¸¦ ¾ò´Â´Ù. ¿¹¸¦ µé¾î ¼­¹ö Æ÷Æ®¸¦ µ¿Àû ÇÒ´çÇÑ °æ¿ì ÀÌ°ÍÀ» ÅëÇØ ½ÇÁ¦ ¼­¹öÀÇ ¸®½º´× Æ÷Æ® ¹øÈ£¸¦ ¾òÀ» ¼ö ÀÖ´Ù.

		\~english
		Gets local address of UDP listener port. For an example, it is possible to acquire the listening port number of real server through this when the server ports are dynamically allocated.

		\~chinese
		?ÔğUDP listener portÜâò¢ò¢ò£list¡£ÖÇåı??İÂÛÕÜ×?ĞïÓ®Ï¢îÜ?ı¦£¬÷×???Ê¦ì¤?Ôğ??Ü×?ĞïîÜlisteningÓ®Ï¢??¡£

		\~japanese
		UDP listener portªÎ«í?«««ë«¢«É«ì«¹«ê«¹«ÈªòÔğªŞª¹¡£ÖÇª¨ªĞ¡¢«µ?«Ğ?«İ?«Èªò«À«¤«Ê«ß«Ã«¯ªËùÜªê?ªÆª¿íŞùê¡¢ª³ªìªò÷×ª¸?ğ·«µ?«Ğ?ªÎ«ê«¹«Ë«ó«°«İ?«ÈÛã?ªòÔğªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\~
		*/
		virtual void GetUdpListenerLocalAddrs(CFastArray<AddrPort> &output) = 0;

		/**
		\~korean
		³Ê¹« ¿À·§µ¿¾È ¼­¹ö¿Í Åë½ÅÇÏÁö ¸øÇÏ¸é ¿¬°áÀ» ÇØÁ¦ÇÏ±â À§ÇÑ Å¸ÀÓ ¾Æ¿ô ÀÓ°è°ª(¹Ğ¸®ÃÊ)¸¦ ÁöÁ¤ÇÑ´Ù.
		- CNetServer.Start È£Ãâ Àü¿¡¸¸ »ç¿ëÇÒ ¼ö ÀÖ´Ù. ±× ÀÌÈÄºÎÅÍ È£ÃâÇÒ °æ¿ì ¹«½ÃµÈ´Ù.
		- ¹«ÇÑÀ¸·Î Àâ´Â °ÍÀº ÃßÃµÇÏÁö ¾Ê´Â´Ù. ºñÁ¤»ó ¿¬°á ÇØÁ¦½Ã ¹«ÇÑÈ÷ ³²´Â ¿¬°á·Î ÀÚ¸®Àâ±â ¶§¹®ÀÌ´Ù. ±×·¯´À´Ï Â÷¶ó¸® 1½Ã°£À» °Å´Â °ÍÀÌ ³´´Ù.
		¹İ¸é, 1ÃÊ µî ³Ê¹« ÀÛÀº °ªÀ» ÀâÀ¸¸é Á¤»óÀûÀÎ Å¬¶óÀÌ¾ğÆ®µµ ÂÑ°Ü³¯ À§ÇèÀÌ ÀÖÀ¸¹Ç·Î ÇÇÇØ¾ß ÇÑ´Ù.
		- ±âº»°ªÀº ProudNetConfig.DefaultNoPingTimeoutTime ÀÌ´Ù.
		- Âü°í: <a target="_blank" href="http://guide.nettention.com/cpp_ko#debug_pause_problem" >µğ¹ö°Å¿¡ ÀÇÇØ ÀÏ½ÃÁ¤ÁöÇÏ¸é ¼­¹ö¿ÍÀÇ ¿¬°áÀÌ ²÷¾îÁö´Â ¹®Á¦ ÇØ°á¹ı</a>

		\~english
		Sets the critical value of time out(millisecond) to disconnect the connection with server when it has been long not communicating with it
		- Can only be used before calling CNetServer.Start. Caliing after that point will be ignored.
		- It is not recommended setting it as permanent since it will remain as an infinite connection after unexpected disconnection. It is better setting it as an hour than the case.
		- Default is ProudNetConfig.DefaultNoPingTimeoutTime.
		- Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#debug_pause_problem" >How to maintain the connection with server when the program stops due to debugger</a>.

		\~chinese
		????ÜôÒö?Ü×?Ğï÷×ãáîÜ?£¬ò¦ïÒ?Öõú°ğ¶?ïÈîÜõ±??Í£?£¨millisecond£©¡£
		- ñşÒöî¤ CNetServer.Start t û¼Ğ£ñıîñŞÅéÄ¡£ñıı¨?ã·û¼Ğ£îÜ??ù¬ûì?¡£
		- ÜôËï???ÙéùÚ¡£ì×?ŞªïáßÈ?ïÈ??à÷?ÙéùÚí¥åùîÜ?ïÈ¡£á¶ì¤Üôåı?öÇ?1á³?¡£
		ÚãØü£¬?÷¼á³îÜ?îÜ?£¬client Ê¦Òö?êóù¬?õóËÛîÜêË?¡£
		- Ùù??ãÀ ProudNetConfig.DefaultNoPingTimeoutTime%¡£
		- ?ÍÅ£º<a target="_blank" href="http://guide.nettention.com/cpp_zh#debug_pause_problem" >ì×Debugìé??ò­ì»?Ü×?Ğï???ïÈ?îÜú°?Û°Ûö</a>¡£

		\~japanese
		ªÈªÆªâíşª¤Êà«µ?«Ğ?ªÈ÷×ãáªÇª­ªÊª«ªÃª¿ªé¡¢ïÈ?ªòú°ğ¶ª¹ªëª¿ªáªÎ«¿«¤«à«¢«¦«È×üÍ£ö·(õ©)ªòò¦ïÒª·ªŞª¹¡£
		- CNetServer.Start ªòû¼ªÓõóª¹îñªÎªßŞÅª¦ª³ªÈª¬ªÇª­ªŞª¹¡£ª½ªÎı­ª«ªéû¼ªÓõóª¹íŞùêªÏÙíãÊªµªìªŞª¹¡£
		- ÙíùÚªËª¹ªëª³ªÈªÏªª?ªáª·ªŞª»ªó¡£ì¶ßÈïÈ?ú°ğ¶ãÁªËÙíùÚªË?ªëïÈ?ªËªÊªëª«ªéªÇª¹¡£ªÊªÎªÇ¡¢ªàª·ªí1ãÁÊàªËª·ª¿Û°ª¬ÕŞª¤ªÇª¹¡£
		ª½ªÎÚãØü¡¢1õ©ªÊªÉá³ªµª¹ª®ªëö·ªòö¢ªëªÈïáßÈªÊ«¯«é«¤«¢«ó«ÈªâõÚª¤õóªµªìªëêË?ª¬ª¢ªêªŞª¹ªÎªÇù­ª±ªëªÙª­ªÇª¹¡£
		- ĞñÜâö·ªÏProudNetConfig.DefaultNoPingTimeoutTimeªÇª¹¡£
		- ?ÍÅ£º\ref debug_pause_problem

		\~
		*/
		virtual void SetDefaultTimeoutTimeMs(int newValInMs) = 0;

		/**
		\~korean
		³Ê¹« ¿À·§µ¿¾È ¼­¹ö¿Í Åë½ÅÇÏÁö ¸øÇÏ¸é ¿¬°áÀ» ÇØÁ¦ÇÏ±â À§ÇÑ Å¸ÀÓ ¾Æ¿ô ÀÓ°è°ª(¹Ğ¸®ÃÊ)¸¦ ÁöÁ¤ÇÕ´Ï´Ù.
		SetDefaultTimeoutTimeMs ¿Í ´Ù¸¥Á¡Àº Æ¯Á¤ È£½ºÆ®¿¡ ´ëÇØ¼­¸¸ ·±Å¸ÀÓÁß¿¡µµ Å¸ÀÓ¾Æ¿ôÀ» º¯°æ ÇÒ ¼ö ÀÖ½À´Ï´Ù.
		- ¼­¹öÀÇ ½ÃÀÛ Àü, ÈÄ »ó°ü ¾øÀÌ »ç¿ë ÇÒ ¼ö ÀÖ½À´Ï´Ù.
		- Æ¯Á¤ È£½ºÆ®(Å¬¶óÀÌ¾ğÆ®)¿¡¸¸ Àû¿ë ½ÃÅµ´Ï´Ù.
		- º¯°æµÈ Å¸ÀÓ¾Æ¿ô °ªÀÌ Àû¿ëµÇ´Â µ¥´Â ¸î ÃÊ°£ °É¸± ¼ö ÀÖ½À´Ï´Ù.

		\~english
		Specify timeout threshold(msec.) for disconnection in case of disconnected from server too long.
		Difference from SetDefaultTimeoutTimeMS is that you can change timeout during runtime for specific host.
		-You can use it regardless of before or after starting the server.
		-Applied to specific host(client).
		-It may take some seconds to apply the time out value change.


		\~chinese TODO:translate needed.
		Specify timeout threshold(msec.) for disconnection in case of disconnected from server too long.
		Difference from SetDefaultTimeoutTimeMS is that you can change timeout during runtime for specific host.
		-You can use it regardless of before or after starting the server.
		-Applied to specific host(client).
		-It may take some seconds to apply the time out value change.


		\~japanese TODO:translate needed.
		Specify timeout threshold(msec.) for disconnection in case of disconnected from server too long.
		Difference from SetDefaultTimeoutTimeMS is that you can change timeout during runtime for specific host.
		-You can use it regardless of before or after starting the server.
		-Applied to specific host(client).
		-It may take some seconds to apply the time out value change.
		*/
		virtual void SetTimeoutTimeMs(HostID host, int newValInMs) = 0;

		/**
		\~korean
		m_enableAutoConnectionRecovery°¡ trueÀÌ¸é SetDefaultTimeoutSecÀÌ³ª SetDefaultTimeouMsÀ¸·Î ÁöÁ¤ÇÑ Å¸ÀÓ¾Æ¿ô ½Ã°£ÀÌ À¯È¿ÇÏÁö ¾Ê°Ô µË´Ï´Ù.
		µû¶ó¼­ ACRÀÇ ¿¬°á À¯Áö ½Ã°£À» ´ë½Å ÁöÁ¤ÇØÁà¾ß ÇÏ´Âµ¥, ÀÌ ÇÔ¼ö¸¦ ÅëÇÏ¿© ÁöÁ¤ÇØÁÙ ¼ö ÀÖ½À´Ï´Ù.
		¼­¹ö ½ÃÀÛ Àü¿¡ ¼³Á¤ÇÒ ¼ö ÀÖ½À´Ï´Ù.
		- ±âº»°ªÀº 60 * 1000 ÀÔ´Ï´Ù. Áï, 1ºĞÀÔ´Ï´Ù.

		\~english
		If m_enableAutoConnectionRecovery is true, The time of TimeOut is not valid.
		So, You should set the ACR time by using this method.
		- Default is 60 * 1000. ( 1 minute )

		\~chinese TODO:translate needed.

		If m_enableAutoConnectionRecovery is true, The time of TimeOut is not valid.
		So, You should set the ACR time by using this method.
		- Default is 60 * 1000. ( 1 minute )

		\~japanese TODO:translate needed.

		If m_enableAutoConnectionRecovery is true, The time of TimeOut is not valid.
		So, You should set the ACR time by using this method.
		- Default is 60 * 1000. ( 1 minute )

		*/
		virtual void SetDefaultAutoConnectionRecoveryTimeoutTimeMs(int newValInMs) = 0;

		/**
		\~korean
		m_enableAutoConnectionRecovery°¡ trueÀÌ¸é SetDefaultTimeoutSecÀÌ³ª SetDefaultTimeouMsÀ¸·Î ÁöÁ¤ÇÑ Å¸ÀÓ¾Æ¿ô ½Ã°£ÀÌ À¯È¿ÇÏÁö ¾Ê°Ô µË´Ï´Ù.
		µû¶ó¼­ ACRÀÇ ¿¬°á À¯Áö ½Ã°£À» ´ë½Å ÁöÁ¤ÇØÁà¾ß ÇÏ´Âµ¥, ÀÌ ÇÔ¼ö¸¦ ÅëÇÏ¿© ÁöÁ¤ÇØÁÙ ¼ö ÀÖ½À´Ï´Ù.
		- ¼­¹öÀÇ ½ÃÀÛ Àü, ÈÄ »ó°ü ¾øÀÌ »ç¿ë ÇÒ ¼ö ÀÖ½À´Ï´Ù.
		- Æ¯Á¤ È£½ºÆ®(Å¬¶óÀÌ¾ğÆ®)¿¡¸¸ Àû¿ë ½ÃÅµ´Ï´Ù.
		- º¯°æµÈ Å¸ÀÓ¾Æ¿ô °ªÀÌ Àû¿ëµÇ´Â µ¥´Â ¸î ÃÊ°£ °É¸± ¼ö ÀÖ½À´Ï´Ù.

		\~english
		If m_enableAutoConnectionRecovery is true, The time of TimeOut is not valid.
		So, You should set the ACR time by using this method.
		- It may take some seconds to apply the time out value change.
		- You can use it regardless of before or after starting the server.
		- Applied to specific host(client).
		- It may take some seconds to apply the time out value change.

		\~chinese TODO:translate needed.

		If m_enableAutoConnectionRecovery is true, The time of TimeOut is not valid.
		So, You should set the ACR time by using this method.
		- It may take some seconds to apply the time out value change.
		- You can use it regardless of before or after starting the server.
		- Applied to specific host(client).
		- It may take some seconds to apply the time out value change.


		\~japanese TODO:translate needed.

		If m_enableAutoConnectionRecovery is true, The time of TimeOut is not valid.
		So, You should set the ACR time by using this method.
		- It may take some seconds to apply the time out value change.
		- You can use it regardless of before or after starting the server.
		- Applied to specific host(client).
		- It may take some seconds to apply the time out value change.

		*/
		virtual void SetAutoConnectionRecoveryTimeoutTimeMs(HostID host, int newValInMs) = 0;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®°¡ UDP Åë½ÅÀ» ¾î´À Á¤µµ±îÁö¸¸ ¾²µµ·Ï Á¦ÇÑÇÒ °ÍÀÎÁö¸¦ ¼³Á¤ÇÏ´Â ¸Ş¼­µå´Ù.
		- »ç¿ëÀÚÀÇ ÀÇµµÀûÀÎ ÀÌÀ¯·Î Å¬¶óÀÌ¾ğÆ®°¡ ¼­¹ö¿ÍÀÇ ¶Ç´Â peer°£ÀÇ UDP Åë½ÅÀ» Â÷´ÜÇÏ°íÀÚ ÇÒ ¶§
		ÀÌ ¸Ş¼­µå¸¦ ¾µ ¼ö ÀÖ´Ù.
		- ±Ø¾ÇÀÇ »óÈ², ¿¹¸¦ µé¾î UDP Åë½Å Àå¾Ö°¡ ½É°¢ÇÏ°Ô ¹ß»ıÇÏ´Â ¼­¹ö¿¡¼­ ÀÓ½Ã¹æÆíÀ¸·Î ÀÌ ¿É¼ÇÀ» ÄÑ¼­
		¹®Á¦¸¦ ÀÏ½ÃÀûÀ¸·Î ÁÙÀÏ ¼ö ÀÖ´Ù. ÇÏÁö¸¸ UDP Åë½ÅÀº °ÔÀÓ ¼­ºñ½º¿¡¼­ Áß¿äÇÏ±â ¶§¹®¿¡
		ÃÖ´ëÇÑ »¡¸® ¹®Á¦¸¦ ÇØ°á ÈÄ ÀÌ ¿É¼ÇÀ» ´Ù½Ã ÄÑ´Â °ÍÀÌ ÁÁ´Ù.

		- ÀÌ °ªÀ» º¯°æÇÑ ÈÄ »õ·Î Á¢¼ÓÇÏ´Â Å¬¶óÀÌ¾ğÆ®¿¡ ´ëÇØ¼­¸¸ Àû¿ëµÈ´Ù.
		- ÃÊ±â »óÅÂ´Â FallbackMethod_None ÀÌ´Ù.

		\param newValue Á¦ÇÑ Á¤Ã¥. Proud.FallbackMethod_CloseUdpSocket ´Â ¾µ ¼ö ¾ø´Ù.

		\~english
		The method to set limits to how far the client uses UDP communication
		- This method can be used to block UDP communication between client and server or client and peer due to intentional reason by user.
		- The worst case, for an example, if there occurs a serious UDP communication hurdle at a server then the problem can be temporarily reduced by turning this option up.
		However, since UDP communication is crucial to game service so it is recommended to solve the problems ASAP then thrun this option back on.

		- Only applied to those newly connected clients after this value is changed
		- The initial status is FallbackMethod_None.

		\param newValue a limitation policy. Proud.FallbackMethod_CloseUdpSocket cannot be used.

		\~chinese
		?öÇclienté©ùÚğ¤UDP÷×ãáò¸ä§?ïïÓøîÜÛ°Ûö¡£
		- ì×éÄ?ÍºëòßÌé©ñé?clientûúÜ×?ĞïûäíºpeerîÜUDP÷×ãáîÜ?ı¦£¬Ê¦ì¤ŞÅéÄó®Û°Ûö¡£
		- õÌ?îÜï×?£¬ÖÇåıî¤UDP÷×ãáî¡äô?ñì?ßæîÜÜ×?Ğï×ìì¤?ĞáÛ°Ûö??ó®??îÜ?Ê¦ì¤???á´ó®??¡£Ó£ãÀUDP÷×ãáî¤êı?Ü×?×ì?ñìé©£¬?öá÷ê??ú°?ı¨ñìãæ??ó®???û¿¡£

		- ñş?áóËÇó®?ì¤ı¨ñìãæ?ïÈîÜclientÎÁéÄ¡£
		- ôøã·??ãÀFallbackMethod_None¡£

		\param newValue ùÚğ¤ïÙóş¡£ÜôÒöŞÅéÄ Proud.FallbackMethod_CloseUdpSocket%¡£

		\~japanese
		«¯«é«¤«¢«ó«Èª¬UDP÷×ãáªòªÉªìªÛªÉªŞªÇŞÅª¦ªèª¦ªËğ¤ùÚª¹ªëª«ªòàâïÒª¹ªë«á«½«Ã«ÉªÇª¹¡£
		- «æ?«¶?ªÎëò?îÜªÊ×âë¦ªÇ«¯«é«¤«¢«ó«Èª¬«µ?«Ğ?ªÈªÎ¡¢ªŞª¿ªÏPeerÊàªÎUDP÷×ãáªòó´?ª·ªèª¦ªÈª¹ªëãÁ¡¢ª³ªÎ«á«½«Ã«ÉªòŞÅª¦ª³ªÈª¬ªÇª­ªŞª¹¡£
		- õÌ?ªÎ?üÏ¡¢ÖÇª¨ªĞ¡¢UDP÷×ãáî¡úªª¬ä¢Ê¾ªË?ßæª¹ªë«µ?«Ğ?ªÇ×üãÁÛ°øµªÈª·ªÆª³ªÎ«ª«×«·«ç«óªòªÄª±ªÆÙığ¹ªòìéãÁîÜªËÊõªéªµª»ªëª³ªÈªÏªÇª­ªŞª¹¡£ª·ª«ª·¡¢UDP÷×ãáªÏ«²?«à«µ?«Ğ?ªÇñìé©ªÊªÎªÇ¡¢õÌÓŞùÚªËáÜª¯Ùığ¹ªòú°Ì½ı­¡¢ª³ªÎ«ª«×«·«ç«óªòî¢ªÓÜõª±ª¿Û°ª¬ÕŞª¤ªÇª¹¡£
		- ª³ªÎö·ªò?ÌÚª·ª¿ı­¡¢ãæª¿ªËïÈ?ª¹ªë«¯«é«¤«¢«ó«ÈªË?ª·ªÆªÎªßîêéÄªµªìªŞª¹¡£
		- ôøÑ¢?÷¾ªÏFallbackMethod_NoneªÇª¹¡£
		\param newValue ğ¤ùÚ«İ«ê«·?¡£Proud.FallbackMethod_CloseUdpSocketªÏŞÅª¦ª³ªÈª¬ªÇª­ªŞª»ªó¡£

		\~
		*/
		virtual void SetDefaultFallbackMethod(FallbackMethod newValue) = 0;

		/**
		\~korean
		³»ºÎ ½ÇÇà ·Î±×¸¦ ÆÄÀÏ·Î ³²±â´Â ±â´ÉÀ» ÄÒ´Ù.
		- ÀÌ ±â´ÉÀÌ ÇÊ¿äÇÑ °æ¿ì´Â º°·Î ¾ø´Ù. Nettention¿¡¼­ ¹®Á¦¸¦ ¼öÁıÇÏ±â À§ÇÑ ¸ñÀûÀ¸·Î »ç¿ëµÈ´Ù.
		- ÀÌ¹Ì EnableLog ¸¦ ÇÑ »óÅÂ¿¡¼­ ÀÌ ÇÔ¼ö¸¦ ¶Ç È£ÃâÇÏ¸é ÀÌ ÇÔ¼ö´Â ¾Æ¹«°Íµµ ÇÏÁö ¾Ê´Â´Ù. ¸¸¾à ´Ù¸¥ ÆÄÀÏ¸íÀ¸·Î
		·Î±×¸¦ °è¼ÓÇØ¼­ ½×°í ½ÍÀ¸¸é DisableLog¸¦ È£Ãâ ÈÄ EnableLog¸¦ È£ÃâÇØ¾ß ÇÑ´Ù.
		\param logFileName ·Î±× ÆÄÀÏ ÀÌ¸§

		\~english
		Turns on the option that leaves internal execution log as file
		- There are not many cases that require this function. Used to collect problems at Nettention.
		- Calling this function again while already 'EnableLog'ed, this function will not do anything. If you need to keep stacking the log with other file name the you must call DisableLog then call EnableLog.
		\param logFileName log file name

		\~chinese
		??÷ê?İ»?ú¼logÜÁ×º?ÙşËìîÜÍíÒö¡£
		- ìéÚõ?êóâÍé©ó®ÍíÒöîÜï×?¡£ Nettention ì¤â¥ó¢???ÙÍîÜŞÅéÄó®ÍíÒö¡£
		- ì«EnableLogîÜ??ù»û¼Ğ£ó®ùŞ?îÜ?£¬ó®ùŞ?Üô?ñ®ìòù¼ŞÀï×¡£åıÍıßÌéÄĞìöâÙşËìÙ£??÷Ø?logîÜ?£¬é©û¼Ğ£DisableLogì¤ı¨î¢û¼Ğ£EnableLog¡£
		\param logFileName logÙşËìÙ£¡£

		\~japanese
		?İ»?ú¼«í«°ªò«Õ«¡«¤«ëªÇ?ª¹Ñ¦ÒöªòÜõª±ªŞª¹¡£
		- ª³ªÎÑ¦Òöª¬ù±é©ªÊíŞùêªÏÜ¬ªËª¢ªêªŞª»ªó¡£NettentionªÇÙığ¹ªò?ó¢ª¹ªëª¿ªáªÎÙÍîÜªÇŞÅªïªìªŞª¹¡£
		- ?ªËEnableLogªòª·ª¿?÷¾ªÇª³ªÎ??ªòªŞª¿û¼ªÓõóª¹ªÈª³ªÎ??ªÏù¼ªâª·ªŞª»ªó¡£ªâª·¡¢öâªÎ«Õ«¡«¤«ëÙ£ªÇ«í«°ªò?ª±ªÆÜÁğíª·ª¿ª¤íŞùêªÏDisableLogªòû¼ªÓõóª·ª¿ı­¡¢EnableLogªòû¼ªÓõóª·ªÆª¯ªÀªµª¤¡£
		\param logFileName «í«°«Õ«¡«¤«ëÙ£

		\~
		*/
		virtual void EnableLog(const PNTCHAR* logFileName) = 0;

		/**
		\~korean
		EnableLog·Î ÄÒ ·Î±×¸¦ ²ö´Ù.

		\~english
		Turns off the log that is thrned on by EnableLog

		\~chinese
		??EnableLogîÜlog¡£

		\~japanese
		EnableLogªÇªÄª±ª¿«í«°ªò«ª«Õª·ªŞª¹¡£
		\~
		*/
		virtual void DisableLog() = 0;

		/**
		\~korean
		½ºÇÇµåÇÙ Å½Áö ±â´ÉÀÇ ½ÅÁßÇÔÀÇ Á¤µµ¸¦ ¼³Á¤ÇÕ´Ï´Ù.
		- 0~100 »çÀÌ °ªÀ¸·Î ¼³Á¤ÇÕ´Ï´Ù. 100¿¡ °¡±î¿ï¼ö·Ï ½ÅÁßÇÏ°Ô ½ºÇÇµåÇÙÀ» Å½ÁöÇÑ´Ù.
		- ProudNetÀÇ ½ºÇÇµåÇÙ Å½Áö ±â´ÉÀº Å¬¶óÀÌ¾ğÆ®¿Í ¼­¹ö°£ÀÇ ping°ú Å¸ÀÓ½ºÅÆÇÁ °ªÀ¸·Î ÀÛµ¿ÇÕ´Ï´Ù.
		0¿¡ °¡±î¿î °ªÀ» ¼³Á¤ÇÒ ¼ö·Ï ½ºÇÇµåÇÙÀ» ¾²´Â Å¬¶óÀÌ¾ğÆ®¸¦ Å½ÁöÇÏ´Â µ¥ °É¸®´Â ½Ã°£Àº Âª¾ÆÁöÁö¸¸
		½ºÇÇµåÇÙÀ» ¾²Áö ¾ÊÀ½¿¡µµ ºÒ±¸ÇÏ°í Åë½Å È¸¼±ÀÇ ºÒ·®À¸·Î ÀÎÇØ pingÀÌ ºÒ±ÔÄ¢ÇÏ°Ô µµ´ŞÇÏ´Â Å¬¶óÀÌ¾ğÆ®¸¶Àúµµ
		½ºÇÇµåÇÙÀ» ¾²´Â Å¬¶óÀÌ¾ğÆ®·Î ¿ÀÀÎµÉ °¡´É¼ºÀÌ ³ô¾ÆÁı´Ï´Ù.
		- ÃÊ±â°ªÀº 1ÀÔ´Ï´Ù.
		- ½ÅÁßÇÔÀÇ Á¤µµ¸¦ Á¶ÀıÇÑ ÈÄ ÀÌÈÄºÎÅÍ Á¢¼ÓÇÏ´Â Å¬¶óÀÌ¾ğÆ®¿¡ ÇÑÇØ º¯°æµÈ °ªÀÌ Àû¿ëµË´Ï´Ù.

		\~english
		Set the intensity of speed hack detection
		- Sets between the value of 0 and 100. Closer to 100 detects with more intensity.
		- The speed hack detection function of ProudNet operates based on ping among servers and time stamp values.
		Using the value closer to 0 provides less time taken for detection but those clients with inconsistant ping can be detected as a speed hack.

		- Initial value is 100.
		- Changed value will be applied to clients connected after the intensity is changed.

		\~chinese
		?öÇspeed hack÷®ò±ÍíÒöîÜ?ñìïïÓø¡£
		- ?öÇà÷0~100ñı??¡£êÆïÈĞÎ1êÆ?ñì÷®ò±speed hack¡£
		- ProuNetîÜspeed hack÷®ò±ÍíÒö???clientûúÜ×?Ğïñı?pingûútime stamp?¡£
		?öÇ?êÆïÈĞÎ0îÜ?£¬÷®ò±ŞÅéÄspeed hackîÜclientîÜ??êÆ??Ó­£¬?ŞÅÜôŞÅéÄspeed hack£¬ì×?÷×ãá?ÖØîÜÜôÕŞ£¬ping Üô??Óğ?îÜclientù¬???ãÀŞÅéÄspeed hackîÜclientîÜÊ¦Òöàõ?ñòÊ¥¡£
		- Ùù??ãÀ1¡£
		- ?ïÚ?ñìîÜïïÓøì¤ı¨£¬ùÚğ¤î¤ì«?ïÈîÜclient£¬ÎÁéÄáóËÇîÜ?¡£

		\~japanese
		«¹«Ô?«Éú·÷®ò±Ñ¦ÒöªÎ?ñìªµªÎïïÓøªòàâïÒª·ªŞª¹¡£
		- 0~100ªÎÊàªÎö·ªËàâïÒª·ªŞª¹¡£100ªËĞÎª¤ªÛªÉ?ñìªË«¹«Ô?«Éú·ªò÷®ò±ª·ªŞª¹¡£
		- ProudNetªÎ«¹«Ô?«Éú·÷®ò±Ñ¦ÒöªÏ¡¢«¯«é«¤«¢«ó«ÈªÈ«µ?«Ğ?ÊàªÎpingªÈ«¿«¤«à«¹«¿«ó«×ö·ªÇíÂÔÑª·ªŞª¹¡£
		0ªËĞÎª¤ö·ªòàâïÒª¹ªëªèª¦ªË«¹«Ô?«Éú·ªòŞÅª¦«¯«é«¤«¢«ó«Èªò÷®ò±ª¹ªëªËª«ª«ªëãÁÊàªÏÓ­ª¯ªÊªêªŞª¹ª¬¡¢«¹«Ô?«Éú·ªòŞÅªïªÊª¤ªËªâ?ªïªéªº¡¢÷×ãáüŞàÊªÎÜôÕŞªËªèªÃªÆpingª¬ÜôĞ®öÎªËÓğÓ¹ª¹ªë«¯«é«¤«¢«ó«Èªµª¨ªâ«¹«Ô?«Éú·ªòŞÅª¦«¯«é«¤«¢«ó«ÈªËè¦ìãªµªìªëÊ¦Òöàõª¬ÍÔª¯ªÊªêªŞª¹¡£
		- ôøÑ¢ö·ªÏ1ªÇª¹¡£
		- ?ñìªµªÎïïÓøªòğàï½ª·ª¿ı­¡¢ì¤Ë½ª«ªéïÈ?ª¹ªë«¯«é«¤«¢«ó«ÈªËùÚªÃªÆ?ÌÚªµªìª¿ö·ª¬îêéÄªµªìªŞª¹¡£

		\~
		*/
		virtual void SetSpeedHackDetectorReckRatioPercent(int newValue) = 0;

		/**
		\~korean
		½ºÇÇµåÇÙ Å½Áö ±â´ÉÀ» ÄÑ°Å³ª ²ö´Ù.
		\param clientID ½ºÇÇµåÇÙ Å½Áö ±â´ÉÀ» ²ô°Å³ª ÄÓ Å¬¶óÀÌ¾ğÆ®ÀÇ HostID
		\param enable ÄÑ·Á¸é true.
		\return À¯È¿ÇÑ Å¬¶óÀÌ¾ğÆ®¸¦ Ã£¾ÒÀ¸¸é true. Àû¿ëÇÒ Å¬¶óÀÌ¾ğÆ®°¡ ¾ø´Â °æ¿ì false.

		\~english
		Turns on/off speed hack detection function
		\param clientID HostID of client that speed hack detection to be turned on/off
		\param enable must set true to turn on
		\return True if found valid client, false if no related clients.

		\~chinese
		??ûäíº??speed hack÷®ò±ÍíÒö¡£
		\param clientID é©??ûäíº??speed hack÷®ò±ÍíÒöîÜclient Host ID¡£
		\param enable ??îÜ?true¡£
		\return ?ÓğêóüùîÜclientîÜ?true¡£?êóßÌÎÁéÄîÜclientîÜ?false¡£

		\~japanese
		«¹«Ô?«Éú·÷®ò±Ñ¦Òöªò«ª«ó?«ª«Õª·ªŞª¹¡£
		\param clientID «¹«Ô?«Éú·÷®ò±Ñ¦Òöªò«ª«ó?«ª«Õª¹ªë«¯«é«¤«¢«ó«ÈªÎHostID
		\param enableªÄª±ªëª¿ªáªËªÏtrue.
		\return êó?ªÊ«¯«é«¤«¢«ó«Èªò÷®ª·ª¿ªétrue¡£îêéÄª¹ªë«¯«é«¤«¢«ó«Èª¬ªÊª¤íŞùêªÏfalse

		\~
		*/
		virtual bool EnableSpeedHackDetector(HostID clientID, bool enable) = 0;

		/**
		\~korean
		ÇØÅ·µÈ Å¬¶óÀÌ¾ğÆ®¿¡¼­ ¸Á°¡¶ß·Á³õÀº ¸Ş½ÃÁö Çì´õ¸¦ º¸³¾ °æ¿ì(Æ¯È÷ ¸Ş½ÃÁö Å©±â ºÎºĞ)
		ÀÌ¸¦ Â÷´ÜÇÏ±â À§ÇØ¼­´Â ¼­¹öÃø¿¡¼­ ¹Ş´Â ¸Ş½ÃÁö Å©±âÀÇ »óÇÑ¼±À» ÁöÁ¤ÇØ¾ß ÇÑ´Ù.
		ÀÌ ¸Ş¼­µå´Â ±× »óÇÑ¼±À» ÁöÁ¤ÇÏ´Â ¿ªÇÒÀ» ÇÑ´Ù.
		ÃÊ±â°ªÀº 64KBÀÌ´Ù.
		\param value_s serverMessageMaxLength
		\param value_c clientMessageMaxLength

		\~english
		To stop the damaged message header sent by a hacked client(especially the size part), it is crucial to set the maximum size of messages received by server.
		This method sets the limit and the default value is 64KB.
		\param value_s serverMessageMaxLength
		\param value_c clientMessageMaxLength

		\~chinese
		?ù¬ıÙîÜclient?áêıÃ?îÜãáãÓheaderîÜ?ı¦£¨÷å?ãÀãáãÓÓŞá³İ»İÂ£©£¬?Öõñé???é©ò¦ïÒî¤Ü×?ĞïÛ°ïÈâ¥îÜãáãÓÓŞá³îÜß¾ùÚ¡£
		ó®Û°ÛöÑÃó·ò¦ïÒÑá?ß¾ùÚîÜíÂéÄ¡£
		ôøã·?ãÀ64KB¡£
		\param value_s serverMessageMaxLength
		\param value_c clientMessageMaxLength

		\~japanese
		«Ï«Ã«­«ó«°ªµªìª¿«¯«é«¤«¢«ó«ÈªÇ?ª·ªÆªªª¤ª¿«á«Ã«»?«¸«Ø«Ã«À?ªòáêªëíŞùê(÷åªË¡¢«á«Ã«»?«¸«µ«¤«ºİ»İÂ)
		ª³ªÎ«á«½«Ã«ÉªÏª½ªÎß¾ùÚàÊªòò¦ïÒª¹ªëæµùÜªòª·ªŞª¹¡£
		ôøÑ¢ö·ªÏ64kbªÇª¹¡£
		\param value_s serverMessageMaxLength
		\param value_c clientMessageMaxLength
		

		\~
		*/
		virtual void SetMessageMaxLength(int value_s, int value_c) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#delayed_send" >TCP Áö¿¬ ¼Û½Å ±â´É°ú Nagle ¾Ë°í¸®Áò</a> »óÅÂ¸¦ ¾ò´Â´Ù.

		\~english
		Gets <a target="_blank" href="http://guide.nettention.com/cpp_en#delayed_send" >TCP delayed transmitting function and Nagle algorism</a> condition.

		\~chinese
		?Ôğ<a target="_blank" href="http://guide.nettention.com/cpp_zh#delayed_send" >TCP æÅ?áêãáÍíÒöûúNagleß©Ûö</a>%??¡£

		\~japanese
		\ref delayed_send  ?÷¾ªòÔğªŞª¹¡£
		
		\~
		*/
		virtual bool IsNagleAlgorithmEnabled() = 0;

		// ProudNetÀÇ ¿©·¯°¡Áö unit test¸¦ ½ÃÇàÇÑ´Ù. DLL ¹öÀüÀÇ °æ¿ì ¼¼ºÎ API¸¦ export°¡ ºÒ°¡´ÉÇÏ¹Ç·Î ÀÌ·¸°Ô ±¸ÇöµÇ¾î ÀÖ´Ù.
		// virtual void TEST_SomeUnitTests() = 0;

		/**
		\~korean
		ÁöÁ¤ÇÑ Å¬¶óÀÌ¾ğÆ®°¡ ¸ÎÀ» ¼ö ÀÖ´Â ÃÖ´ë Direct P2P ¿¬°á °¹¼ö¸¦ ÁöÁ¤ÇÕ´Ï´Ù.
		- ¿©±â¼­ ÁöÁ¤ÇÑ °ªÀ» ÃÊ°úÇÑ ³ª¸ÓÁö P2P ¿¬°áÀº Ç×»ó Relayed°¡ µË´Ï´Ù.
		- Direct P2PÀÇ ½ÇÁ¦ °¹¼ö´Â ¿©±â¼­ ÁöÁ¤ÇÑ °ª ÀÌÇÏ°¡ ³ª¿Ã ¼ö ÀÖ´Âµ¥, ÀÌ´Â ProudNetÀÇ <a target="_blank" href="http://guide.nettention.com/cpp_ko#jit_p2p" >JIT(Just-in-time) P2P ¿¬°á</a> ±â´É ¶§¹®ÀÌ¸ç, Á¤»óÀûÀÎ »óÈ²ÀÔ´Ï´Ù.

		\~english
		Designates the maximum number of Direct P2P connections that the desinated clients can be connected to
		- Those other P2P connections that have values that exceed the designated value will always be relayed.
		- Actual number of P2P connections may be less than newVal due to <a target="_blank" href="http://guide.nettention.com/cpp_ko#jit_p2p" >JIT(Just-in-time) P2P connection</a>, but it is not a problem.

		\~chinese
		ò¦ïÒù¬ò¦ïÒîÜclientÊ¦ì¤?ïÈîÜõÌÓŞDirect P2P?ïÈ??¡£
		- î¤?×ìõ±?ò¦ïÒ??îÜP2P?ïÈìéòÁ?Relayed¡£
		- Direct P2PîÜ????Ê¦Òö?ãÀî¤?×ìò¦ïÒîÜ?ì¤ù»£¬?ãÀì×?ProudNetîÜ<a target="_blank" href="http://guide.nettention.com/cpp_zh#jit_p2p" >JIT(Just-in-time) P2P?ïÈ</a> %ÍíÒö¡£ãÀïáßÈï×?¡£

		\~japanese
		ò¦ïÒª·ª¿«¯«é«¤«¢«ó«Èª¬Ì¿ªÙªëõÌÓŞDirect P2PïÈ??ªòò¦ïÒª·ªŞª¹¡£
		- ª³ª³ªÇò¦ïÒª·ª¿ö·ªòõ±Î¦ª·ª¿?ªêªÎP2PïÈ?ªÏª¤ªÄªâRelayedªµªìªŞª¹¡£
		- Direct P2PªÎ?ğ·?ªÏª³ª³ªÇò¦ïÒª·ª¿ö·ì¤ù»ªËªÊªëª³ªÈª¬ª¢ªêªŞª¹ª¬¡¢ª³ªìªÏProudNetªÎ\ref jit_p2pÑ¦ÒöªÎª¿ªáªÇ¡¢ïáßÈªÊ?üÏªÇª¹¡£

		\~
		*/
		virtual void SetMaxDirectP2PConnectionCount(HostID clientID, int newVal) = 0;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®°£ P2P È¦ÆİÄªÀ» ½ÃÀÛÇÏ±â À§ÇÑ Á¶°ÇÀ» ÁöÁ¤ÇÕ´Ï´Ù. ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#jit_p2p" >JIT(Just-in-time) P2P ¿¬°á</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.
		- ÀÌ ¸Ş¼­µå¸¦ È£ÃâÇÑ ÀÌÈÄ¿¡ Á¢¼ÓÇÑ Å¬¶óÀÌ¾ğÆ®ºÎÅÍ º» °ªÀÌ Àû¿ëµË´Ï´Ù.
		- ±âº»°ªÀº JIT ÀÔ´Ï´Ù.

		\param newVal Å¬¶óÀÌ¾ğÆ®°£ P2P Åë½ÅÀ» À§ÇÑ È¦ÆİÄªÀ» ½ÃÀÛÇÏ´Â Á¶°ÇÀÔ´Ï´Ù.
		\return ¼º°øÀûÀ¸·Î ¹İ¿µ½Ã true¸¦ ¸®ÅÏÇÕ´Ï´Ù.

		\~english

		\todo retranslate required.

		Designates the condition to begin P2P hole-punching among clients <a target="_blank" href="http://guide.nettention.com/cpp_en#jit_p2p" >JIT(Just-in-time) P2P connection</a>
		- The clients that the designated value will be applied to are the client that connected after this method is called.
		- Default is the value that is designated at Proud.CNetConfig.DefaultDirectP2PStartCondition.

		\param newVal the condition to begin P2P hole-punching among clients
		\return returns true if successfully applied

		\~chinese
		?Öõ?ã·P2PöèÔ×ì»ò¦ïÒ?Ëì¡£????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#jit_p2p" >JIT(Just-in-time) P2P?ïÈ</a> %¡£
		- û¼Ğ£ó®Û°Ûöì¤ı¨?ïÈîÜclient?ã·ŞÅéÄó®?¡£
		- Ùù??ãÀJIT¡£

		\param newVal ?ã·?Öõclientñı?P2P÷×ãáîÜ?Ëì¡£
		\return Úãç±à÷Íí?Ú÷üŞtrue¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈÊàP2P«Û?«ë«Ñ«ó«Á«ó«°ªòËÒã·ª¹ªëª¿ªáªÎ?Ëìªòò¦ïÒª·ªŞª¹¡£ßÙª·ª¯ªÏ¡¢\ref jit_p2pªòª´?ğÎª¯ªÀªµª¤¡£
		- ª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª·ª¿ı­ªËïÈ?ª·ª¿«¯«é«¤«¢«ó«ÈªèªêÜâö·ª¬îêéÄªµªìªŞª¹¡£
		- ĞñÜâö·ªÏJITªÇª¹¡£
		\param newVal «¯«é«¤«¢«ó«ÈÊàªÎP2P÷×ãáªÎª¿ªáªÎ«Û?«ë«Ñ«ó«Á«ó«°ªòËÒã·ª¹ªë?ËìªÇª¹¡£
		\return Úãç±ªËà÷ÍíãÁªËtrueªò«ê«¿?«óª·ªŞª¹¡£

		\~
		*/
		virtual bool SetDirectP2PStartCondition(DirectP2PStartCondition newVal) = 0;

		/**
		\~korean
		¼öÆÛ ÇÇ¾î·Î¼­ °¡Àå Àû°İÀÇ ¿ªÇÒÀ» ÇÒ Å¬¶óÀÌ¾ğÆ®¸¦ Ã£´Â´Ù.
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#super_peer" >Super Peer(¼öÆÛÇÇ¾î È¤Àº È£½ºÆ®) Áß½ÉÀÇ P2P ³×Æ®¿öÅ·</a> Çü½ÄÀÇ °ÔÀÓÀ» °³¹ßÁßÀÎ °æ¿ì, ÀÌ ¸Ş¼­µå´Â groupID°¡ °¡¸®Å°´Â P2P±×·ì ¿¡ ÀÖ´Â ¸â¹öµé Áß
		°¡Àå ÃÖÀûÀÇ ¼öÆÛ ÇÇ¾î¸¦ Ã£¾Æ¼­ ¾Ë·ÁÁØ´Ù.
		- ÀÌ ¸Ş¼­µå´Â P2P ±×·ìÀ» »ı¼ºÇÏ°Å³ª º¯°æÇÑ Á÷ÈÄ ¹Ù·Î ¾òÀ» °æ¿ì Á¦´ë·Î Ã£Áö ¸øÇÒ ¼ö ÀÖ´Ù.
		- Ã³À½ ÀÌ ¸Ş¼­µå¸¦ È£ÃâÇÑ ÈÄºÎÅÍ ¾à 2~5ÃÊ Á¤µµ Áö³­ ÈÄ¿¡ ´Ù½Ã È£ÃâÇÏ¸é ´õ Á¤È®ÇÑ ¼öÆÛÇÇ¾î¸¦ Ã£´Â´Ù.
		\param groupID ÀÌ <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> ¿¡¼­ Ã£´Â´Ù
		\param policy ¼öÆÛ ÇÇ¾î¸¦ ¼±Á¤ÇÏ´Â Á¤Ã¥. ÀÚ¼¼ÇÑ ¼³¸íÀº CSuperPeerSelectionPolicy Âü°í.
		\param exclusdees groupID°¡ °¡¸®Å°´Â <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> ÀÇ ¸â¹ö Áß exclusdees¿¡ µé¾îÀÖ´Â ¸â¹öµéÀº Á¦¿ÜÇÏ°í ¼±º°ÇÑ´Ù.
		¿¹¸¦ µé¾î ÀÌ¹Ì »ç¿ëÇÏ´ø ¼öÆÛÇÇ¾î°¡ ÀÚ°İ ¹ÚÅ»µÈ °æ¿ì ´Ù½Ã ÀÌ°ÍÀÌ Àç ¼±¹ßµÊÀ» ÀÇµµÀûÀ¸·Î ¸·°íÀÚ ÇÒ ¶§ À¯¿ëÇÏ´Ù.
		\return ¼öÆÛÇÇ¾î·Î¼­ °¡Àå Àû°İÀÎ Å¬¶óÀÌ¾ğÆ®ÀÇ HostID. P2P ±×·ìÀ» Ã£Áö ¸øÇÏ°Å³ª excludees¿¡ ÀÇÇØ ¸ğµÎ°¡ ÇÊÅÍ¸µµÇ¸é HostID_None À» ¸®ÅÏÇÕ´Ï´Ù.

		\~english
		Finds the clients that can perform best as super peer
		When developing game of <a target="_blank" href="http://guide.nettention.com/cpp_en#super_peer" >P2P Networking for Super Peer (Super Peer or host)</a> format, this method finds and notifies the best possible super peer among members of the P2P group that is pointed by groupID.
		- There are possibilities that this method cannot find properly right after P2P group is eiter created or modified.
		- It will find more suitable super peer when called about 2 to 5 seconds after this method is called.
		\param groupID finds within this <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>
		\param policy policy that designates super peer. Please refer CSuperPeerSelectionPolicy.
		\param exclusdees Selects excluding the members within excludees among <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> that is pointed by groupID
		For an example, it is useful to prevent intentionally the super peer to be re-selected when the super peer wass once disqualified.
		\return HostID of the best possible client as super peer. Returns HostID_None either when no P2P group was found or all filtered by excludees.

		\~chinese
		??íÂ?super peerÑÃó·õÌùêÎÁíÂéÄîÜclient¡£
		ïáî¤??<a target="_blank" href="http://guide.nettention.com/cpp_zh#super_peer" >Super Peer(ûäñ«Ïõ) ñéãıîÜP2P÷×ãá</a>%û¡ãÒêı?îÜ?£¬ó®Û°Ûö??Óğî¤groupIDá¶ò¦îÜP2P?à÷?ñéõÌÎÁùêîÜsuperpeer?Í±ò±¡£
		- ó®Û°Ûöî¤ßæà÷P2P?ûäíºáóËÇı¨Ø¡??ÔğîÜ?ı¦Ê¦Òö??ÔğÜô?ñ×?¡£
		- ?ã·û¼Ğ£ó®Û°Ûöì¤ı¨ÓŞ?2~5õ©ı¨ñìãæû¼Ğ£îÜ?Òö?Óğïá?îÜsuperpeer¡£
		\param groupID î¤ó®<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%??¡£
		\param policy ?ÚûsuperpeerîÜïÙóş¡£????ÍÅ CSuperPeerSelectionPolicy%¡£
		\param exclusdees groupIDá¶ò¦îÜ<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%à÷?ñé÷êexclusdees×ìîÜà÷?ğ¶èâñıı¨?Úû¡£
		ÖÇåıì«ŞÅéÄîÜsuperpeerù¬???Ì«ì¤ı¨£¬ßÌÍºëòğæò­?ñìãæù¬?ïÒîÜ?ı¦êóéÄ¡£
		\return íÂ?superpeerõÌÎÁùêîÜclientHost ID¡£?ÜôÓğP2P?ûäíºù¬excludeesîïİ»??îÜ?Ú÷üŞHostID_None¡£

		\~japanese
		«¹?«Ñ?«Ô?«¢ªÈª·ªÆìéÛãîêÌ«ªÎæµùÜªòª¹ªë«¯«é«¤«¢«ó«Èªò÷®ª·ªŞª¹¡£
		\ref super_peer  û¡ãÒªÎ«²?«àªòËÒ?ñéªÎíŞùê¡¢ª³ªÎ«á«½«Ã«ÉªÏgroupIDª¬ò¦ª¹P2P«°«ë?«×ªËª¢ªë«á«ó«Ğ?ªÎª¦ªÁìéÛãõÌîêªÊ«¹?«Ñ?«Ô?«¢ªò÷®ª·ªÆª¯ªìªŞª¹¡£
		- ª³ªÎ«á«½«Ã«ÉªÏP2P«°«ë?«×ªòßæà÷ª·ª¿ªê?ÌÚª·ª¿ı­¡¢ª¹ª°ÔğªéªìªëíŞùê¡¢ª­ªÁªóªÈ÷®ª¹ª³ªÈª¬ªÇª­ªÊª¤íŞùêª¬ª¢ªêªŞª¹¡£
		- ôøªáªÆª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª·ª¿ı­ª«ªéå³2~5õ©ªÛªÉª¬Î¦ª®ª¿ı­¡¢î¢ªÓû¼ªÓõóª¹ªÈªâªÃªÈïáü¬ªÊ«¹?«Ñ?«Ô?«¢ªò÷®ª·ªŞª¹¡£
		\param groupID ª³ªÎ\ref p2p_groupªÇ÷®ª·ªŞª¹¡£
		\param policy «¹?«Ñ?«Ô?«¢ªòàÔïÒª¹ªë«İ«ê«·?¡£ßÙª·ª¯ªÏ¡¢CSuperPeerSelectionPolicy ªòª´?ğÎª¯ªÀªµª¤¡£
		\param exclusdees groupIDª¬ò¦ª¹\ref p2p_groupªÎ«á«ó«Ğ?ªÎª¦ªÁ¡¢exclusdeesªËìıªÃªÆª¤ªë«á«ó«Ğ?ªÏğ¶èâª·ªÆàÔÜ¬ª·ªŞª¹¡£
		ÖÇª¨ªĞ¡¢?ªËŞÅªÃªÆª¤ª¿«¹?«Ñ?«Ô?«¢ªÎíÀÌ«ª¬?÷¬ªµªìª¿íŞùê¡¢î¢ªÓª³ªìª¬î¢à»?ªµªìªëª³ªÈªòëò?îÜªËÛÁª®ª¿ª¤ãÁªËêóéÄªÇª¹¡£
		\return «¹?«Ñ?«Ô?«¢ªÈª·ªÆìéÛãîêÌ«ªÊ«¯«é«¤«¢«ó«ÈªÎHostID¡£P2P«°«ë?«×ªò÷®ª¹ª³ªÈª¬ªÇª­ªÊª¤ªÈª«¡¢excludeesªËªèªÃªÆîïªÆª¬«Õ«£«ë«¿«ê«ó«°ªµªìªìªĞHostID_Noneªò«ê«¿?«óª·ªŞª¹¡£

		\~
		*/
		virtual HostID GetMostSuitableSuperPeerInGroup(HostID groupID, const CSuperPeerSelectionPolicy& policy = CSuperPeerSelectionPolicy::GetOrdinary(), const HostID* excludees = NULL, intptr_t excludeesLength = 0) = 0;

		/**
		\~korean
		µ¿¸í ¸Ş¼­µå ¼³¸íÀ» Âü°í¹Ù¶÷

		\~english
		Please refer same name method.

		\~chinese
		??ÍÅÔÒÙ£Û°Ûö?Ù¥¡£

		\~japanese
		ÔÒÙ£«á«½«Ã«ÉªÎ?Ù¥ªòª´?ğÎª¯ªÀªµª¤¡£
		\~
		*/
		virtual HostID GetMostSuitableSuperPeerInGroup(HostID groupID, const CSuperPeerSelectionPolicy& policy, HostID excludee) = 0;

		/**
		\~korean
		GetMostSuitableSuperPeerInGroup´Â °¡Àå Àû°İÀÇ <a target="_blank" href="http://guide.nettention.com/cpp_ko#super_peer" >Super Peer(¼öÆÛÇÇ¾î È¤Àº È£½ºÆ®) Áß½ÉÀÇ P2P ³×Æ®¿öÅ·</a> ¸¦ ¾ò´Â ±â´ÉÀÔ´Ï´Ù.
		ÀÌ ÇÔ¼ö´Â °¡Àå Àû°İÀÇ ¼öÆÛÇÇ¾î »Ó¸¸ ¾Æ´Ï¶ó Â÷¼øÀ§ Àû°İ ¼öÆÛÇÇ¾îµéÀÇ ¸ñ·ÏÀ» Á¦°øÇÕ´Ï´Ù.
		ÀÌ ÇÔ¼ö°¡ ¸®ÅÏÇÏ´Â ¸®½ºÆ®ÀÇ Ã¹¹øÂ° Ç×¸ñÀº GetMostSuitableSuperPeerInGroup¿¡¼­ ¸®ÅÏÇÏ´Â ¼öÆÛÇÇ¾î¿Í µ¿ÀÏÇÕ´Ï´Ù.

		\param groupID ÀÌ <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> ¿¡¼­ Àû°İ ¼öÆÛÇÇ¾î ¸ñ·ÏÀ» Á¦°øÇÕ´Ï´Ù.
		\param ratings ¿©±â¿¡ Àû°İ ¼öÆÛÇÇ¾î ¸ñ·ÏÀÌ Ã¤¿öÁı´Ï´Ù. °¡Àå Àû°İÀÎ ¼öÆÛÇÇ¾î ¼øÀ¸·Î Á¤·ÄµÇ¾î Ã¤¿öÁı´Ï´Ù.
		\param ratingsBufferCount rating ÀÇ ¹è¿­ Ç×¸ñ °¹¼öÀÔ´Ï´Ù. ÀÌ ÇÔ¼ö°¡ ¸®ÅÏÇÏ´Â ¹è¿­ÀÇ Å©±â´Â ÀÌ Å©±â ÀÌ»óÀº Ã¤¿ìÁö ¾Ê½À´Ï´Ù.
		\param policy GetMostSuitableSuperPeerInGroup ¿¡¼­ °°Àº ÀÌ¸§ÀÇ ÆÄ¶ó¸ŞÅÍ¸¦ Âü°íÇÏ½Ê½Ã¿À.
		\param excludees GetMostSuitableSuperPeerInGroup ¿¡¼­ °°Àº ÀÌ¸§ÀÇ ÆÄ¶ó¸ŞÅÍ¸¦ Âü°íÇÏ½Ê½Ã¿À.
		\return ratings ¿¡ Ã¤¿öÁø Ç×¸ñÀÇ °¹¼öÀÔ´Ï´Ù. P2P ±×·ìÀ» Ã£Áö ¸øÇÏ°Å³ª excludees ¿¡ ÀÇÇØ ¸ğµÎ°¡ ÇÊÅÍ¸µµÇ¸é 0À» ¸®ÅÏÇÕ´Ï´Ù.

		\~english
		GetMostSuitableSuperPeerInGroup is the function to get the best possible <a target="_blank" href="http://guide.nettention.com/cpp_en#super_peer" >P2P Networking for Super Peer (Super Peer or host)</a>.
		Provides not only the best possible super peer but also the list of the next to the best possible super peer as well
		The first clause of the list that this function returns is same as the super peer returned by GetMostSuitableSuperPeerInGroup.

		\param groupID Provides the list of the best possible super peer among this <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>
		\param ratings This is where the list of super peer will be filled. The best super peer is to be at the top as sorted.
		\param ratingsBufferCount The number of array clause of rating. The size of the array returned by this function does not fill more than this size.
		\param policy Please refer the same name parameter at	GetMostSuitableSuperPeerInGroup.
		\param excludees Please refer the same name parameter at	GetMostSuitableSuperPeerInGroup.
		\return the number of clause that is filled at ratings. Returns 0 either when no P2P group was found or filtered all of them by excludees.

		\~chinese
		GetMostSuitableSuperPeerInGroup ãÀ?Ôğ<a target="_blank" href="http://guide.nettention.com/cpp_zh#super_peer" >Super Peer(ûäñ«Ïõ) ñéãıîÜP2P÷×ãá</a>%õÌÎÁùêîÜÍíÒö¡£
		ó®ùŞ?Üô?ğ«Íêsuperpeer£¬ì»ó¦?ğ«Íêó­?ßíîÜÎÁùêsuperpeerîÜÙÍ?¡£
		ó®ùŞ?Ú÷üŞîÜlistîÜğ¯ìé??ÙÍ?î¤GetMostSuitableSuperPeerInGroupÚ÷üŞîÜsuperpeerßÓÔÒ¡£
		\param groupID î¤<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%ğ«ÍêùêÎÁîÜsuperpeerîÜÙÍ?¡£
		\param ratings î¤?×ì?õöùêÎÁîÜsuperpeerÙÍ?¡£ì¤õÌÎÁùêîÜsuperpeer?ßíÛÉßí?õö¡£
		\param ratingsBufferCount rating???ÙÍ??¡£ó®ùŞ?Ú÷üŞîÜ??Üô??õöó®ÓŞá³ì¤ß¾îÜÓŞá³¡£
		\param policy î¤GetMostSuitableSuperPeerInGroup?ÍÅßÓÔÒÙ£í®îÜ??¡£
		\param excludees î¤GetMostSuitableSuperPeerInGroup?ÍÅßÓÔÒÙ£í®îÜ??¡£
		\return èÙratings?õöîÜ?ÙÍ??¡£?ÜôÓğP2P?ûäíºù¬excludeesîïİ»??îÜ?Ú÷üŞ0¡£

		\~japanese
		GetMostSuitableSuperPeerInGroupªÏìéÛãîêÌ«ªÊ\ref super_peer ªòÔğªëÑ¦ÒöªÇª¹¡£
		ª³ªÎ??ªÏìéÛãîêÌ«ªÊ«¹?«Ñ?«Ô?«¢ªÀª±ªÇªÊª¯¡¢ó­â÷êÈªÎîêÌ««¹?«Ñ?«Ô?«¢ªÎ«ê«¹«Èªòğ«Íêª·ªŞª¹¡£
		ª³ªÎ??ª¬«ê«¿?«óª¹ªë«ê«¹«ÈªÎõÌôøú£ÙÍªÏ¡¢GetMostSuitableSuperPeerInGroupª¬«ê«¿?«óª¹ªë«¹?«Ñ?«Ô?«¢ªÈÔÒª¸ªÇª¹¡£
		\param groupID ª³ªÎ\ref p2p_groupªÇîêÌ««¹?«Ñ?«Ô?«¢«ê«¹«Èªòğ«Íêª·ªŞª¹¡£
		\param ratings ª³ª³ªËîêÌ««¹?«Ñ?«Ô?«¢«ê«¹«Èª¬?ª¿ªµªìªŞª¹¡£ìéÛãîêÌ«ªÊ«¹?«Ñ?«Ô?«¢ªÎâ÷ªÇïÚÖªªµªìªÆ?ª¿ªµªìªŞª¹¡£
		\param ratingsBufferCount rating ªÎÛÕÖªú£ÙÍ?ªÇª¹¡£ª³ªÎ??ª¬«ê«¿?«óª¹ªëÛÕÖªªÎ«µ«¤«ºªÏª³ªìì¤ß¾ªÏ?ª¿ª·ªŞª»ªó¡£
		\param policy GetMostSuitableSuperPeerInGroup ªÇÔÒª¸Ù£îñªÎ«Ñ«é«á?«¿?ªòª´?ğÎª¯ªÀªµª¤¡£
		\param excludees GetMostSuitableSuperPeerInGroup ªÇÔÒª¸Ù£îñªÎ«Ñ«é«á?«¿?ªòª´?ğÎª¯ªÀªµª¤¡£
		\return ratings ªË?ª¿ªµªìª¿ú£ÙÍªÎ?ªÇª¹¡£P2P«°«ë?«×ªò÷®ª¹ª³ªÈª¬ªÇª­ªÊª¤ªÈª«¡¢excludeesªËªèªÃªÆîïªÆª¬«Õ«£«ë«¿«ê«ó«°ªµªìªìªĞ0ªò«ê«¿?«óª·ªŞª¹¡£

		\~
		*/
		virtual int GetSuitableSuperPeerRankListInGroup(HostID groupID, SuperPeerRating* ratings, int ratingsBufferCount, const CSuperPeerSelectionPolicy& policy = CSuperPeerSelectionPolicy::GetOrdinary(), const CFastArray<HostID> &excludees = CFastArray<HostID>()) = 0;

		/**
		\~korean
		¼­¹ö¿¡¼­ ÁØºñµÈ UDP ¼ÒÄÏ ÁÖ¼ÒµéÀ» ¾ò´Â´Ù.

		\~english
		Gets UDP socket addresses that are prepared by server

		\~chinese
		?Ôğî¤Ü×?Ğïñ×?îÜUDP socketò¢ò£¡£

		\~japanese
		«µ?«Ğ?ªÇñŞİáªµªìª¿UDP«½«±«Ã«È«¢«É«ì«¹ªòÔğªŞª¹¡£
		\~
		*/
		virtual void GetUdpSocketAddrList(CFastArray<AddrPort> &output) = 0;

		/**
		\~korean
		¿£Áø ÇÁ·ÎÅäÄİ ¹öÀüÀ» ¾ò´Â´Ù. ÀÌ °ªÀÌ Å¬¶óÀÌ¾ğÆ®¿¡¼­ ¾ò´Â ¿£Áø ÇÁ·ÎÅäÄİ ¹öÀü°ú ´Ù¸£¸é Á¢¼ÓÀÌ ºÒÇãµÈ´Ù.

		\~english
		Gets engine protocol version. Connection will be rejected if this value is different to engine protocol version from client.

		\~chinese
		?ÔğìÚÌÖ??÷úÜâ¡£ó®???client?ÔğîÜìÚÌÖ??÷úÜâÜôÔÒîÜ?ÜôëÃ??ïÈ¡£

		\~japanese
		«¨«ó«¸«ó«×«í«È«³«ë«Ğ?«¸«ç«óªòÔğªŞª¹¡£ª³ªÎö·ª¬«¯«é«¤«¢«ó«ÈªèªêÔğªë«¨«ó«¸«ó«×«í«È«³?«ë«Ğ?«¸«ç«óªÈêŞª¨ªĞïÈ?ªÏÜôúÉªËªÊªêªŞª¹¡£
		\~
		*/
		virtual int GetInternalVersion() = 0;

		/**
		\~korean
		ÁöÁ¤ÇÑ ´ë»ó°ú °ü·ÃµÈ ¸ğµç P2P ¿¬°áÀÇ »óÅÂ Åë°è¸¦ ¾ò½À´Ï´Ù.
		°¡·É Direct P2P¿Í relayed P2PÀÇ ºñÀ²À» ¾òÀ» ¶§ ÀÌ ¸Ş¼­µå°¡ À¯¿ëÇÕ´Ï´Ù.
		\param remoteHostID Å¬¶óÀÌ¾ğÆ® ¶Ç´Â <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> ÀÇ HostID ÀÔ´Ï´Ù.
		- 1°³ Å¬¶óÀÌ¾ğÆ®ÀÇ HostID ÀÎ °æ¿ì, ÀÌ ¸Ş¼­µå´Â ±× Å¬¶óÀÌ¾ğÆ®°¡ P2P Åë½ÅÇÏ´Â ´Ù¸¥ ÇÇ¾îµé°úÀÇ ¿¬°á Åë°è¸¦ ¹İÈ¯ÇÕ´Ï´Ù.
		- 1°³ P2P ±×·ìÀÇ HostID ÀÎ °æ¿ì, ÀÌ ¸Ş¼­µå´Â ±× P2P ±×·ì ³»ÀÇ ¸ğµç Å¬¶óÀÌ¾ğÆ®³¢¸®ÀÇ P2P Åë½Å¿¡ ´ëÇÑ Åë°è¸¦ ¹İÈ¯ÇÕ´Ï´Ù.
		\param status P2PÄ¿³Ø¼Ç °ü·Ã º¯¼öµéÀÌ ¿©±â¿¡ Ã¤¿öÁı´Ï´Ù.
		\return remoteHostID°¡ À¯È¿ÇÏ¸é true,À¯È¿ÇÏÁö ¾ÊÀ¸¸é false¸¦ ¸®ÅÏ ÇÕ´Ï´Ù.

		\~english
		Gets status statistics of all P2P connections related to designated target
		This method is useful to get the proportion of Direct P2P and relayed P2P.
		\param remoteHostID HostID of client or <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>
		- If this is HostID of 1 client then this method returns connection statistics of other peers that the client is P2P communicating with.
		- If this is HostID of 1 P2Pgroup then this method returns the statistics of all P2P communications among all clients in the P2P group.
		\param status P2P connection related vairables are to be filled in here.
		\return Returns true if remoteHostID is valid, false if not valid

		\~chinese
		?Ôğ?ò¦ïÒîÜ?ßÚßÓ?îÜá¶êóP2P?ïÈ????¡£
		åıÍı?ÔğDirect P2Pûúrelayed P2PîÜİïáãîÜ?ı¦ó®Û°ÛöêóéÄ¡£
		\param remoteHostID clientûäíº<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%îÜHost ID¡£
		- ìé?clientîÜHost IDîÜ?£¬ó®Û°ÛöÚ÷üŞÑá?client?Ğìöâpeer?ú¼P2P÷×ãáîÜ?ïÈ??¡£
		- ìé?P2P?îÜHost IDîÜ?£¬ó®Û°ÛöÚ÷üŞ?Ñá?P2P??îÜá¶êóclientñı?P2P÷×ãáîÜ??¡£
		\param status ?×ì?õöP2P connectionßÓ???¡£
		\return remoteHostIDêóüùîÜ?true£¬ÙéüùîÜ?Ú÷üŞfalse¡£

		\~japanese
		ò¦ïÒª·ª¿?ßÚªË?ªïªëîïªÆªÎP2PïÈ?ªÎ?÷¾÷ÖÍªªòÔğªŞª¹¡£
		ªâª·¡¢Direct P2PªÈrelayed P2PªÎİïáãªòÔğªëãÁ¡¢ª³ªÎ«á«½«Ã«Éª¬êóéÄªÇª¹¡£
		\param remoteHostID «¯«é«¤«¢«ó«ÈªŞª¿ªÏ\ref p2p_groupªÎHostIDªÇª¹¡£
		- 1«¯«é«¤«¢«ó«ÈªÎHostIDªÇª¢ªëíŞùê¡¢ª³ªÎ«á«½«Ã«ÉªÏª½ªÎ«¯«é«¤«¢«ó«Èª¬P2P÷×ãáª¹ªëöâªÎPeerªÈªÎïÈ?÷ÖÍªªòÚ÷ü½ª·ªŞª¹¡£
		- ìéP2P«°«ë?«×ªÎHostIDªÎíŞùê¡¢ª³ªÎ«á«½«Ã«ÉªÏª½ªÎP2P«°«ë?«×?ªÎîïªÆªÎ«¯«é«¤«¢«ó«ÈªÎP2P÷×ãáªË?ª¹ªë÷ÖÍªªòÚ÷ü½ª·ªŞª¹¡£
		\param status P2P«³«Í«¯«·«ç«ó?Ö§??ª¬ª³ª³ªË?ª¿ªµªìªŞª¹¡£
		\return remoteHostIDª¬êó?ªÇª¢ªìªĞtrue¡¢êó?ªÇªÏÙíª±ªìªĞfalseªò«ê«¿?«óª·ªŞª¹¡£

		\~
		*/
		virtual bool GetP2PConnectionStats(HostID remoteHostID,/*output */CP2PConnectionStats& status) = 0;

		/**
		\~korean
		remoteA ¿Í remoteB »çÀÌÀÇ udp message ½ÃµµÈ½¼ö¿Í ¼º°øÈ½¼ö¸¦ ¹İÈ¯ÇØÁİ´Ï´Ù.
		- »ç¿ë ÀÚ´Â ÀÌ¸¦ ¹ÙÅÁÀ¸·Î udp ¼Õ½ÇÀ² µîÀ» °è»êÇÒ¼öÀÖ½À´Ï´Ù.

		\~english
		Return attempted number and succeed number of udp message between remoteA and remoteB
		- User can calculate udp loss rate based on it.

		\~chinese
		Ú÷üŞremoteA?remoteBñı?udp message??ó­?ûúà÷Ííó­?¡£
		- éÄ?Ê¦ì¤ì¤ó®?Ğñ??ß©UDP?ã÷áãÔõ¡£

		\~japanese
		remoteA ªÈremoteBÊàªÎudp messageªÎ?ú¼üŞ?ªÈà÷ÍíÍ­?ªòÚ÷ü½ª·ªŞª¹¡£
		- «æ?«¶?ªÏª³ªìªò÷Ï÷»ªËUDPáßã÷áãªÊªÉªòÍªß©ª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£

		\~
		*/
		virtual bool GetP2PConnectionStats(HostID remoteA, HostID remoteB, CP2PPairConnectionStats& status) = 0;

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
		\ref thread_pool ªÎÊÀ«¹«ì«Ã«ÉªÎï×ÜÃªòÔğªŞª¹¡£
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
		\param output this is where the information is filled.

		\~chinese
		?Ôğ???ïïîÜãáãÓ¡£
		ProudNet ?<a target="_blank" href="http://guide.nettention.com/cpp_zh#thread_pool" >?ïïò®(Thread pool)</a>%ÜôÔÒ£¬?öÇó·?ìò??I/O?×âîÜ?ïï¡£?Ôğ?îÜãáãÓ¡£
		\param output èÙ?×ì?õöãáãÓ¡£

		\~japanese
		«Í«Ã«È«ï?«­«ó«°«¹«ì«Ã«ÉªÎï×ÜÃªòÔğªŞª¹¡£
		ProudNetªÏ¡¢\ref thread_poolªÈªÏÜ¬ªË«Í«Ã«È«ï?«¯I/O?×âªò??ª¹ªë«¹«ì«Ã«Éª¬??ªµªìªÆª¤ªŞª¹¡£ª³ªìªÎï×ÜÃªòÔğªŞª¹¡£
		\param output ª³ª³ªËï×ÜÃª¬?ª¿ªµªìªŞª¹¡£

		\~
		*/
		virtual void GetNetWorkerThreadInfo(CFastArray<CThreadInfo> &output) = 0;

		/**
		\~korean
		»ç¿ëÀÚ Á¤ÀÇ ¸Ş½ÃÁö¸¦ Àü¼ÛÇÕ´Ï´Ù. ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#send_user_message" >RMI¸¦ ÀüÇô ¾È¾²°í »ç¿ëÀÚ Á¤ÀÇ ¸Ş½ÃÁö¸¦ ÁÖ°í ¹Ş±â</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.
		\param remotes ¼ö½ÅÀÚ ¹è¿­ÀÔ´Ï´Ù. RMI¿Í ¸¶Âù°¡Áö·Î, Å¬¶óÀÌ¾ğÆ®, ¼­¹ö(HostID_Server), <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a>  µîÀ» ³ÖÀ» ¼ö ÀÖ½À´Ï´Ù.
		\param remoteCount ¼ö½ÅÀÚ ¹è¿­ Å©±â
		\param rmiContext ¼Û½Å ºÎ°¡Á¤º¸. ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#protocol_overview" >ProudNetÀÇ ÇÁ·ÎÅäÄİ Á¾·ù</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.
		\param payload º¸³¾ ¸Ş½ÃÁö µ¥ÀÌÅÍ
		\param payloadLength º¸³¾ ¸Ş½ÃÁö µ¥ÀÌÅÍÀÇ ±æÀÌ. ¹ÙÀÌÆ® ´ÜÀ§ÀÔ´Ï´Ù.

		\~english
		Send user defined message. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#send_user_message" >Exchanging user-defined message without using RMI at all</a> for more detail
		\param remotes Receiver array. You can put client, server(HostID_Server), <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a>, etc like RMI.
		\param remoteCount Size of receiver array
		\param rmiContext Additional information of sending. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#protocol_overview" >Protocol type of ProudNet</a>.
		\param payload Message data for sending.
		\param payloadLength Length of sending message data. It is byte.

		\~chinese
		?áêéÄ?ïÒ?ãáãÓ¡£????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#send_user_message" >èÇîïÜôŞÅéÄRMIÎß?éÄ?ïÒ?ãáãÓ</a>%¡£
		\param remotes â¥ãáíº??¡£?RMIßÓÔÒÊ¦ì¤?ìıclient£¬Ü×?Ğï£¨HostID_Server£©£¬<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%Ôõ¡£
		\param remoteCount â¥ãáíº??ÓŞá³¡£
		\param rmiContext ?áêãáãÓîÜİ¾Ê¥ãáãÓ¡£????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#protocol_overview" >ProudNet îÜ??????</a>%¡£
		\param payload é©?áêîÜãáãÓ?Ëß¡£
		\param payloadLength é©?áêîÜãáãÓ?Ëß?Óø¡£Byte?êÈ¡£

		\~japanese
		«æ?«¶?ïÒëù«á«Ã«»?«¸ªò?áêª·ªŞª¹¡£ßÙª·ª¯ªÏ¡¢\ref send_user_messageªòª´?ğÎª¯ªÀªµª¤¡£
		\param remotes áôãáíºÛÕÖªªÇª¹¡£RMIªÈÔÒ?ªË¡¢«¯«é«¤«¢«ó«È¡¢«µ?«Ğ?(HostID_Server)¡¢ \ref p2p_group  ªÊªÉªòìıªìªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\param remoteCount áôãáíºÛÕÖª«µ«¤«º
		\param rmiContext áêãáªË?ª¹ªëÜõÊ¥ï×ÜÃ¡£ßÙª·ª¯ªÏ¡¢\ref protocol_overview ªòª´?ğÎª¯ªÀªµª¤¡£
		\param payload áêªê«á«Ã«»?«¸«Ç?«¿
		\param payloadLength áêªë«á«Ã«»?«¸«Ç?«¿íşªµ¡£«Ğ«¤«È?êÈªÇª¹¡£

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
		\param remote â¥ãáíº¡£
		\param rmiContext ?áêãáãÓîÜİ¾Ê¥ãáãÓ¡£????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#protocol_overview" >ProudNet îÜ??????</a>%¡£
		\param payload é©?áêîÜãáãÓ?Ëß¡£
		\param payloadLength é©?áêîÜãáãÓ?Ëß?Óø¡£Byte?êÈ¡£

		\~japanese
		«æ?«¶?ïÒëù«á«Ã«»?«¸ªò?áêª·ªŞª¹¡£ßÙª·ª¯ªÏ¡¢\ref send_user_messageªòª´?ğÎª¯ªÀªµª¤¡£
		\param remote áôãáíº
		\param rmiContext áêãáªË?ª¹ªëÜõÊ¥ï×ÜÃ¡£ßÙª·ª¯ªÏ¡¢\ref protocol_overview ªòª´?ğÎª¯ªÀªµª¤¡£
		\param payload áêªë«á«Ã«»?«¸«Ç?«¿
		\param payloadLength áêªë«á«Ã«»?«¸«Ç?«¿ªÎíşªµ¡£«Ğ«¤«È?êÈªÇª¹¡£

		\~
		*/
		inline bool SendUserMessage(HostID remote, const RmiContext &rmiContext, uint8_t* payload, int payloadLength)
		{
			return SendUserMessage(&remote, 1, rmiContext, payload, payloadLength);
		}

		/** @copydoc Proud::CNetClient::SetCoalesceIntervalMs() */
		virtual ErrorType SetCoalesceIntervalMs(HostID remote, int intervalMs) = 0;
		/** @copydoc Proud::CNetClient::SetCoalesceIntervalToAuto() */
		virtual ErrorType SetCoalesceIntervalToAuto(HostID remote) = 0;

		virtual void TEST_SetOverSendSuspectingThresholdInBytes(int newVal) = 0;

		virtual void TEST_SetTestping(HostID hostID0, HostID hostID1, int ping) = 0;

		// TCP ¿¬°áÀÌ µé¾î¿À´Â °ÍÀ» ¹«Á¶°Ç °ÅºÎÇÑ´Ù. ¿¬°áÀÌ µé¾î¿ÀÀÚ¸¶ÀÚ ÂÑ°Ü³ª´Â Å¬¶óÀÌ¾ğÆ®¸¦ Å×½ºÆ®ÇÏ±â À§ÇÔ.
		// Å¬¶óÃø¿¡¼­ ¿¬°á °ÅºÎ¸¦ ¹Ì¸® °É°í µé¾î¿À´Â °Íµµ ¹æ¹ıÀÌÁö¸¸, ¼­¹ö¿¡¼­ TCP ¿¬°áÀÌ µé¾î¿ÀÀÚ¸¶ÀÚ ±×°ÍÀ» Ã¼Å©ÇÏ±â¿¡´Â ³Ê¹« ´Ê´Ù.
		virtual void TEST_ForceDenyTcpConnection() = 0;

		/**
		\~korean
		ÀÏ¹İÀûÀÎ ¿Â¶óÀÎ °ÔÀÓ¿¡¼­´Â unreliable ¸Ş½ÃÂ¡ÀÌ ÀüÃ¼ Æ®·¡ÇÈÀÇ ´ëºÎºĞÀ» Â÷ÀÌÁöÇÔ¿¡ µû¶ó ±âÁ¸ unreliable ¸Ş½ÃÂ¡ ±â´É¿¡ Æ®·¡ÇÈ ·Î½ºÀ²À» ¾ò´Â ±â´ÉÀ» Ãß°¡ÇÕ´Ï´Ù.
		ÆĞÅ¶ ·Î½ºÀ² ÃøÁ¤±â
		\param remoteHostID ¾î´À remote ¿ÍÀÇ Åë½Å¿¡ ´ëÇÑ ·Î½ºÀ²À» ¾òÀ» °ÈÀÎÁö. ÀÚ±â ÀÚ½Å peer, server ¹¹µçÁö ÀÔ·Â °¡´ÉÇÕ´Ï´Ù. ÀÚ±â ÀÚ½ÅÀÌ¸é 0% ÀÔ´Ï´Ù
		\param outputPercent ÆĞÅ¶ ·Î½ºÀ²À» %´ÜÀ§·Î Ã¤¿öÁü(Áï 0~100)

		\~english 
		As unreliable messaging takes most of the entire traffic in common on-line games, we add the feature to get the traffic loss rate in the existing unreliable messaging feature.
		Packet loss rate measuring device

		\param remoteHostID Which loss rate with communication with which remote would be obtained. You can input anything, including your own peer, server, etc. If it is itself, it is 0%.
		\param outputPercent The packet loss rate is filled up in % unit (i.e., 0 to 100)

		\~chinese
		î¤ìéÚõî¤?êı?ñé?UnreliableãáãÓîÜ??÷×ãáÕáï¿Ëß?ÓŞİ»İÂ?£¬î¤ê«êóUnreliableãáãÓÍíÒöß¾ôÕÊ¥?Ôğ÷×ãáÕáLossáãîÜÍíÒö¡£
		?ËßøĞLossáã?ïÒ?¡£
		\param remoteHostID é©?Ôğ??ìé?remote?îÜ÷×ãáLossáã£¬Ê¦ì¤?ìıåıí»ãóPeer£¬serverÔõ¡£åıÍıãÀí»ĞùîÜ???0%¡£
		\param outputPercent  ?ËßøĞîÜLossáã?ì¤%?êÈ?õö£¬£¨?0~100£©

		\~japanese
		ìéÚõîÜªÊ«ª«ó«é«¤«ó«²?«àªÇªÏ¡¢unreliable«á«Ã«»?«¸«ó«°ª¬îï?«È«é«Õ«£«Ã«¯ªÎªÛªÈªóªÉªòï¿ªáªëª³ªÈªËªèªÃªÆ¡¢?ğíªÎunreliable«á«Ã«»?«¸«ó«°Ñ¦ÒöªË«È«é«Õ«£«Ã«¯«í«¹áãªòÔğªëÑ¦ÒöªòõÚÊ¥ª·ªŞª¹¡£
		«Ñ«±«Ã«È«í«¹áãö´ïÒÑ¦
		\param remoteHostID ªÉªÎ«ê«â?«ÈªÈªÎ÷×ãáªË?ª¹ªë«í«¹áãªòÔğªëª«£¿í»İÂí»ãóªÎpeer¡¢server ªÊªóªÇªâìıÕôÊ¦ÒöªÇª¹¡£í»İÂí»ãóªÇª¢ªìªĞ0%ªÇª¹¡£
		\param outputPercent¡¡«Ñ«±«Ã«È«í«¹áãª¬%?êÈªÇ?ª¿ªµªìªŞª¹¡£(ª¹ªÊªïªÁ¡¢0~100)

		\~
		*/
		virtual ErrorType GetUnreliableMessagingLossRatioPercent(HostID remotePeerID, int *outputPercent) = 0;

		//		virtual void SetTimerCallbackIntervalMs(int newVal) = 0;
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