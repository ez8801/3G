/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


ÀÌ ÇÁ·Î±×·¥ÀÇ ÀúÀÛ±ÇÀº ³ÝÅÙ¼Ç¿¡°Ô ÀÖ½À´Ï´Ù.
ÀÌ ÇÁ·Î±×·¥ÀÇ ¼öÁ¤, »ç¿ë, ¹èÆ÷¿¡ °ü·ÃµÈ »çÇ×Àº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾àÀ» µû¸£¸ç,
°è¾àÀ» ÁØ¼öÇÏÁö ¾Ê´Â °æ¿ì ¿øÄ¢ÀûÀ¸·Î ¹«´Ü »ç¿ëÀ» ±ÝÁöÇÕ´Ï´Ù.
¹«´Ü »ç¿ë¿¡ ÀÇÇÑ Ã¥ÀÓÀº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾à¼­¿¡ ¸í½ÃµÇ¾î ÀÖ½À´Ï´Ù.

** ÁÖÀÇ : ÀúÀÛ¹°¿¡ °üÇÑ À§ÀÇ ¸í½Ã¸¦ Á¦°ÅÇÏÁö ¸¶½Ê½Ã¿À.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


ó®ïïßíîÜ÷ú??NettentionÍëÞÉá¶êó¡£
?ó®ïïßíîÜáóËÇ¡¢ÞÅéÄ¡¢?øÖßÓ?îÜÞÀ?é©ñåáúó®ïïßíîÜá¶êó?íºîÜ??¡£
Üôñåáú???é©ê«?àõîÜÐ×ò­ôºí»ÞÅéÄ¡£
ôºí»ÞÅéÄîÜ?ìòÙ¥ãÆî¤?ó®ïïßíá¶êó?íºîÜùêÔÒ?×ì¡£

** ñ¼ëò£ºÜôé©ì¹ð¶?éÍð¤íÂÚªîÜß¾âûÙ¥ãÆ¡£


ª³ªÎ«×«í«°«é«àªÎîÊíÂ?ªÏNettentionªËª¢ªêªÞª¹¡£
ª³ªÎ«×«í«°«é«àªÎáóïá¡¢ÞÅéÄ¡¢ÛÕøÖªË?ª¹ªëÞÀú£ªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ªË?ª¤¡¢
Ìøå³ªòñåáúª·ªÊª¤íÞùê¡¢ê«öÎîÜªËÙí?ÞÅéÄªòÐ×ª¸ªÞª¹¡£
Ùí?ÞÅéÄªËªèªëô¡ìòªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ßöªËÙ¥ãÆªµªìªÆª¤ªÞª¹¡£

** ñ¼ëò£ºîÊíÂÚªªË?ª¹ªëß¾ÑÀªÎÙ¥ãÆªòð¶ËÛª·ªÊª¤ªÇª¯ªÀªµª¤¡£

*/

#pragma once

#include "FakeClr.h"
#include "Enums.h"
#include "pnstdint.h"

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
	ProudNet °ü·Ã ¿©·¯°¡Áö ¼³Á¤ °ªµéÀÌ´Ù.
	- µû·Î ¹®¼­È­µÇ¾î ÀÖÁö ¾ÊÀº °ªµéÀº ÇÔºÎ·Î º¯°æÇÏÁö ¸» °Í.

	\~english
	ProudNet related setting values
	- DO NOT change the values that are separately documented!

	\~chinese
	ProudNet ßÓ?ÊÀ??ïÒ?¡£
	- ?êóÙþ?ûùîÜ?Üôé©ôºí»áóËÇ¡£

	\~japanese
	ProudNetªË?Ö§ª¹ªë??ªÊàâïÒö·ªÇª¹¡£
	- Ü¬ªËÙþßöûùªµªìªÆª¤ªÊª¤ö·ªÏ¡¢ã­â¢ªË?ÌÚª·ªÊª¤ª³ªÈ¡£
	\~

	*/
	class CNetConfig
	{
	public:
		//////////////////////////////////////////////////////////////////////////
		// socket
		PROUD_API static int UdpIssueRecvLength;
		PROUD_API static int UdpRecvBufferLength_Client;
		PROUD_API static int UdpRecvBufferLength_Server;
		PROUD_API static int UdpRecvBufferLength_ServerStaticAssigned;
		PROUD_API static int TcpIssueRecvLength;
		PROUD_API static int TcpRecvBufferLength;
		PROUD_API static int TcpSendBufferLength;
		PROUD_API static int UdpSendBufferLength_Client;
		PROUD_API static int UdpSendBufferLength_Server;
		PROUD_API static int UdpSendBufferLength_ServerStaticAssigned;
		PROUD_API static bool EnableSocketTcpKeepAliveOption;
		PROUD_API static int64_t ReliableUdpHeartbeatIntervalMs_Real;
		PROUD_API static int64_t ReliableUdpHeartbeatIntervalMs_ForDummyTest;

		PROUD_API static int64_t TcpSocketConnectTimeoutMs;
		PROUD_API static int64_t ClientConnectServerTimeoutTimeMs;

		//////////////////////////////////////////////////////////////////////////
		// time
		PROUD_API static int64_t DefaultConnectionTimeoutMs;
		PROUD_API static int64_t MinConnectionTimeoutMs;
		PROUD_API static int64_t MaxConnectionTimeoutMs;
		PROUD_API static uint32_t WaitCompletionTimeoutMs;
		PROUD_API static uint32_t HeartbeatIntervalMs;
		PROUD_API static uint32_t GarbageCollectIntervalMs;

		PROUD_API static int64_t ServerHolepunchIntervalMs;
		PROUD_API static int64_t UdpHolepunchIntervalMs;
		PROUD_API static int64_t ServerUdpRepunchIntervalMs;
		PROUD_API static int ServerUdpRepunchMaxTrialCount;
		PROUD_API static int ServerUdpHolepunchMaxTrialCount;
		PROUD_API static int64_t P2PHolepunchIntervalMs;
		PROUD_API static int P2PShotgunStartTurn;
		PROUD_API static int P2PHolepunchMaxTurnCount;
		PROUD_API static int64_t PurgeTooOldUnmatureClientTimeoutMs;
		PROUD_API static int64_t PurgeTooOldAddMemberAckTimeoutMs;
		PROUD_API static int64_t DisposeGarbagedHostsTimeoutMs;
		PROUD_API static int64_t RemoveTooOldUdpSendPacketQueueTimeoutMs;
		PROUD_API static int64_t AssembleFraggedPacketTimeoutMs;
		PROUD_API static bool EnablePacketDefragWarning;
		PROUD_API static int64_t GetP2PHolepunchEndTimeMs();
		PROUD_API static int ShotgunTrialCount;
		PROUD_API static int ShotgunRange;

		PROUD_API static int64_t UnreliablePingIntervalMs;
		PROUD_API static int64_t ReliablePingIntervalMs;

		PROUD_API static bool UseReportRealUdpCount;
		PROUD_API static int64_t ReportRealUdpCountIntervalMs;

		PROUD_API static uint32_t LanClientHeartbeatIntervalMs;

		PROUD_API static int64_t LanPeerConnectPeerTimeoutTimeMs;
		PROUD_API static int64_t PurgeTooOldJoiningTimeOutIntervalMs;
		PROUD_API static int64_t RemoveLookaheadMessageTimeoutIntervalMs;

		PROUD_API static int RecyclePairReuseTimeMs;
		PROUD_API static int64_t GarbageTooOldRecyclableUdpSocketsIntervalMs;
		PROUD_API static int ServerUdpSocketLatentCloseMs;

		PROUD_API static int64_t TcpInDangerThresholdMs;
		PROUD_API static int64_t TcpUnstableDetectionWaitTimeMs;
		PROUD_API static int64_t PauseUdpSendDurationOnTcpInDangerMs;

		PROUD_API static int64_t RecentAssemblyingPacketIDsClearIntervalMs;

		PROUD_API static int AutoConnectionRecoveryTimeoutTimeMs;
		PROUD_API static int64_t AutoConnectionRecoveryTimeoutMinTimeMs;

		/**
		\~korean
		¸ðµç »ó´ë Remote µéÀÇ IssueSend¸¦ ¸ð¾Æ¼­ ¼Û½ÅÇÑ´Ù.
		- ±âº»°ªÀº 3ms ÀÌ´Ù.
		- ÀÌ°ªÀ» ±æ°Ô ÀâÀ¸¸é ¼Û½Å·ºÀÌ »ý±æ¼ö ÀÖÀ¸´Ï ÁÖÀÇ¿ä¸Á! (3ms ~ 10ms)»çÀÌ°¡ Àû´çÇÏ´Ù.

		\~english
		It sends IssueSend of all other Remotes
		- Defualt value is 3ms
		- It may occur lag of sending, if you set too longe. It will suitable between 3ms ~ 10ms.

		\~chinese
		÷êá¶êó?Û°RemoteîÜIssueSendâ¥ó¢ý¨?áêãáãÓ¡£
		- Ùù??ãÀ3ms¡£
		- ?ñ¼ëò£¡åýÍý÷ê????öÇ÷¼?îÜ?Ê¦Òö??ßæ?áê?Ø·?ßÚ¡££¨3ms ~ 10ms£©ñý??ýæ?¡£

		\~japanese
		îïªÆªÎßÓâ¢RemoteªÎIssueSendªòó¢ªáªÆáêãáª·ªÞª¹¡£
		- ÐñÜâö·ªÏ3msªÇª¹¡£
		- ª³ªÎö·ªòíþª¯ö¢ªìªÐáêãá«é«Ã«¯ª¬?ßæª¹ªëª³ªÈª¬ª¢ªêªÞª¹ªÎªÇª´ñ¼ëòª¯ªÀªµª¤!(3ms~10ms)Êàª¬îê?ªÇª¹¡£
		\~
		*/
		PROUD_API static int EveryRemoteIssueSendOnNeedIntervalMs;

		__forceinline static int64_t GetFallbackServerUdpToTcpTimeoutMs()
		{
			// ³ªÁß¿¡, UdpPingInterval·Î °³¸íÇÏÀÚ. C-S UDP°¡ Áõ¹ßÇÏ°Ç P2P UDP°¡ Áõ¹ßÇÏ°Ç ÇÑÂÊÀÌ Áõ¹ßÇÏ¸é ³ª¸ÓÁöµµ ºÒ¾ÈÇÑ°Ç ¸ÅÇÑ°¡Áö ÀÌ¹Ç·Î.
			assert(UnreliablePingIntervalMs > 0);

			// ¿¬¼Ó 3¹ø º¸³½ °ÍÀ» ¸ø ¹Þ´Â´Ù´Â °ÍÀº 80% ÀÌ»ó ÆÐÅ¶ ·Î½º¶ó´Â ÀÇ¹Ì. ÀÌ Á¤µµ¸é È¦ÆÝÄª µÇ¾î ÀÖ¾îµµ ¸·ÀåÀÌ´Ù.
			// µû¶ó¼­ 10->4 ÇÏÇâ.
			return UnreliablePingIntervalMs * 4;
		}

		__forceinline static int64_t GetFallbackP2PUdpToTcpTimeoutMs()
		{
			// ³ªÁß¿¡, UdpPingInterval·Î °³¸íÇÏÀÚ. C-S UDP°¡ Áõ¹ßÇÏ°Ç P2P UDP°¡ Áõ¹ßÇÏ°Ç ÇÑÂÊÀÌ Áõ¹ßÇÏ¸é ³ª¸ÓÁöµµ ºÒ¾ÈÇÑ°Ç ¸ÅÇÑ°¡Áö ÀÌ¹Ç·Î.
			assert(UnreliablePingIntervalMs > 0);

			// ¿¬¼Ó 3¹ø º¸³½ °ÍÀ» ¸ø ¹Þ´Â´Ù´Â °ÍÀº 80% ÀÌ»ó ÆÐÅ¶ ·Î½º¶ó´Â ÀÇ¹Ì. ÀÌ Á¤µµ¸é È¦ÆÝÄª µÇ¾î ÀÖ¾îµµ ¸·ÀåÀÌ´Ù.
			// µû¶ó¼­ 10->4 ÇÏÇâ.
			// GetFallbackServerUdpToTcpTimeoutMs°ú GetFallbackP2PUdpToTcpTimeoutMsÀº ¼­·Î °°Àº °ªÀÌ¾î¾ß. 
			// C-S UDP°¡ Áõ¹ßÇÏ°Ç P2P UDP°¡ Áõ¹ßÇÏ°Ç ÇÑÂÊÀÌ Áõ¹ßÇÏ¸é ³ª¸ÓÁöµµ ºÒ¾ÈÇÑ°Ç ¸ÅÇÑ°¡Áö ÀÌ¹Ç·Î.
			return UnreliablePingIntervalMs * 4;
		}

		// TCP ÇÎ Å¸ÀÓ ¾Æ¿ô¿¡ °É¸®´Â ½Ã°£
		// Âü°í: TCP ÇÎ Å¸ÀÓ ¾Æ¿ôÀ» °¨ÁöÇÏ±â À§ÇØ ÇÎÀ» ÁÖ°í ¹Þ´Â ÁÖ±â´Â CNetClientImpl::GetReliablePingTimerInterval ¿¡¼­ °áÁ¤.
		static int DefaultNoPingTimeoutTimeMs;

		/**
		\~korean
		¼±Çü°èÈ¹¹ý(?)
		- ³Ê¹« ÀÛ°Ô ÀâÀ¸¸é °ªÀÇ º¯È­°¡ ÀÛ¾Æ¼­ ±âÁ¸ °ªÀÇ ¿À·ù¸¦ ½±°Ô ±Øº¹ ¸øÇÏ°í
		³Ê¹« Å©°Ô ÀâÀ¸¸é °ªÀÇ º¯È­°¡ Ä¿¼­ ´ëÃ¼Àû °ªÀÇ Áß°£Á¡À» À¯ÁöÇÏ±â ¾î·Æ´Ù.

		\~english
		Linear planning(?)
		- If too small then hard to overcome error from exisiting value to its change being too small,
		If too big then hard to keep the mid-point value due to its change being too big.

		\~chinese
		?àõ??Ûö£¨£¿£©
		- ?÷¼á³îÜ?£¬ì×??îÜ?ûùá³ì»ÜôÒöé»æ¶ÐºÜ×ñýîñ?îÜ??£¬÷¼ÓÞîÜ?£¬??ûùÓÞì»???ò¥ÓÞ??îÜñé?ïÃ¡£

		\~japanese
		àÊû¡Íª?Ûö(?)
		- ª¢ªÞªêªËªâá³ªµª¯ö¢ªëªÈö·ªÎ?ûùª¬á³ªµª¯ªÆ?ðíö·ªÎ«¨«é?ªòÊÛ?ªË?ªêêÆª¨ªëª³ªÈª¬ªÇª­ªº¡¢ª¢ªÞªêªËªâÓÞª­ª±ªìªÐö·ªÎ?ûùª¬ÓÞª­ª¯ªÆÓÞ?ªÎö·ªÎñéÊàïÃªòë«ò¥ª·ªËª¯ª¤ªÇª¹¡£
		\~
		*/
		PROUD_API static int LagLinearProgrammingFactorPercent;

		PROUD_API static int StreamGrowBy;

		PROUD_API static int InternalNetVersion;

		PROUD_API static int InternalLanVersion;

		/** \~korean º» ÇÔ¼ö´Â ProudNet Version Á¤º¸¸¦ ¹ÝÈ¯ÇÕ´Ï´Ù.
		\~english This function returns ProudNet Version information.
		\~chinese ó®ùÞ?Ú÷üÞProudNet VersionãáãÓ
		\~japanese ª³ªÎ??ªÏ ProudNet Version ï×ÜÃªòÚ÷ü½ª·ªÞª¹¡£
		\~ */
		PROUD_API static Proud::String GetVersion();

		PROUD_API static int MtuLength;

		PROUD_API static int64_t ElectSuperPeerIntervalMs;

		/**
		\~korean
		ÇÑ °³ÀÇ ¸Þ½ÃÁö°¡ °¡Áú ¼ö ÀÖ´Â ÃÖ´ë Å©±â
		- °íÁ¤µÈ °ªÀÌ ¾Æ´Ï´Ù. °³¹ßÀÚ´Â ÀÌ °ªÀ» ¾ðÁ¦µçÁö º¯°æÇØµµ µÈ´Ù.
		- ÀÌ °ªÀº CNetServer ³ª CNetClient °´Ã¼¸¦ »ý¼ºÇÏ±â Àü¿¡ ¹Ì¸® ¼³Á¤ÇØ¾ß ÇÑ´Ù.
		- ÇÏÁö¸¸ À¢¸¸ÇØ¼­´Â º¯°æÇÏÁö ¾Ê´Â °ÍÀ» ±ÇÀåÇÑ´Ù. ´Ü, ¼­¹ö°£ Åë½Å¿¡¼­ 1°³ÀÇ ¸Þ½ÃÁö°¡ 1MB¸¦ ³Ñ¾î°¡´Â ¼öÁØÀÌ¶ó¸é ¿¹¿Ü´Ù.
		- ÇØÅ·µÈ Å¬¶óÀÌ¾ðÆ®¿¡¼­ Àß¸øµÈ ¸Þ½ÃÁö Å©±â¸¦ º¸³»´Â °æ¿ì¸¦ Â÷´ÜÇÏ·Á¸é CNetServer.SetMessageMaxLength ¸¦ ¾²´Â °ÍÀ» ±ÇÀåÇÑ´Ù.

		\~english
		The maximum size of a message can have
		- Not a fixed value. Developer can change this at any time.
		- This value must be set previously before creating the CNetServer object or CNetClient object.
		- However, it is not recommended to change this. But, there can be an exception when a message has a size around 1 MB among server communications.
		- To stop a hacked client sending incorrect message size, it is recommended to use CNetServer.SetMessageMaxLength.

		\~chinese
		ìé?ãáãÓÒö?êóîÜõÌÓÞÓÞá³¡£
		- ÜôãÀÍ³ïÒ?¡£??íº??Ê¦ì¤áóËÇó®?¡£
		- ó®?é©î¤ßæà÷ CNetServer%ûäíº CNetClient%?ßÚñýîñ?öÇ¡£
		- Ó£ãÀËï??ÕáÜôé©áóËÇ¡£Üô?î¤Ü×?Ðïñý?÷×ãáñéãáãÓõ±?1MBîÜâ©øÁîÜ?ÖÇèâ¡£
		- î¤ù¬ýÙîÜclientñéßÌ?øÌ?áê??ãáãÓÓÞá³îÜï×?îÜ?Ëï?ÞÅéÄ CNetServer.SetMessageMaxLength%¡£

		\~japanese
		1ËÁªÎ«á«Ã«»?«¸ª¬ò¥ªÄª³ªÈª¬ªÇª­ªëõÌÓÞ«µ«¤«º
		- Í³ïÒªµªìª¿ö·ªÇªÏª¢ªêªÞª»ªó¡£ËÒ?íºªÏª³ªÎö·ªòª¤ªÄªÇªâ?ÌÚª·ªÆªâÕÞª¤ªÇª¹¡£
		- ª³ªÎö·ªÏ CNetServerªÈª«CNetClient«ª«Ö«¸«§«¯«Èªòßæà÷ª¹ªëîñªËîñªâªÃªÆàâïÒª·ªÊª±ªìªÐªÊªêªÞª»ªó¡£
		- ª·ª«ª·¡¢ªÇª­ªìªÐ?ÌÚª·ªÊª¤ª³ªÈªòªª?ªáª·ªÞª¹¡£Ó£ª·¡¢«µ?«Ð?ÊàªÎ÷×ãáªÇ1ËÁªÎ«á«Ã«»?«¸ª¬1MBªò?ªêêÆª¨ªëâ©ñÞªÊªéÖÇèâªÇª¹¡£
		- «Ï«Ã«­«ó«°ªµªìª¿«¯«é«¤«¢«ó«ÈªÇÊàêÞªÃª¿«á«Ã«»?«¸ªÎ«µ«¤«ºªòáêªëíÞùêªòó´?ª¹ªëª¿ªáªËªÏ CNetServer.SetMessageMaxLengthªòÞÅª¦ª³ªÈªòªª?ªáª·ªÞª¹¡£
		\~
		*/
		// Åð¿ª
		//PROUD_API static int MessageMaxLength;

		static const int MessageMaxLengthInOrdinaryCase = 64 * 1024;
		static const int MessageMaxLengthInServerLan = 1024 * 1024;

		// ´ë·«, °íÁ¤ Å©±âÀÇ ÀÛÀº ¸Þ½ÃÁö Çì´õ¸¸ ´ã´Â °æ¿ì Çã¿ë °¡´ÉÇÑ Å©±â. Å©±â°¡ ¸Å¿ì ÀÛÀ¸¹Ç·Î Á¶½ÉÇØ¼­ ¾µ °Í!
		static const int MessageMinLength = 128;

		// ¸Þ½ÃÁö 1°³ÀÇ ÃÖ´ë Å©±â ÇÑ°è (°íÁ¤°ª)
		static const int MessageMaxLength;

		PROUD_API static int64_t DefaultGracefulDisconnectTimeoutMs;

		/**
		\~korean
		¼­¹ö¿¡¼­ Å¬¶óÀÌ¾ðÆ®·Î P2P routed multicast¸¦ ÇÒ ¶§ ÃÖ´ë º¸³¾ ¼ö ÀÖ´Â °¹¼ö(router ¿ªÇÒÀ» ÇÏ´Â Å¬¶ó¸¦ Á¦¿ÜÇÔ)

		\~english
		The maximum number of P2P routed multicast from server to client (client that acts as router is excluded)

		\~chinese
		?Ü×?ÐïèÙclient?ú¼P2P routed multicastîÜ?ý¦£¬Ê¦ì¤?áêîÜõÌÒý??£¨?routeríÂéÄîÜclientÖÇèâ£©

		\~japanese
		«µ?«Ð?ªÇ«¯«é«¤«¢«ó«ÈªØP2P routed multicastªòª¹ªëãÁ¡¢õÌÓÞªÇáêªéªìªëËÁ?(«ë?«¿?æµùÜªòª¹ªë«¯«é«¤«¢«ó«ÈªÏð¶èâª¹ªë)
		\~
		*/
		PROUD_API static int MaxS2CMulticastRouteCount;

		PROUD_API static int UnreliableS2CRoutedMulticastMaxPingDefaultMs;

		PROUD_API static bool ForceCompressedRelayDestListOnly;

		/**
		\~korean
		¼­¹ö´ç ÃÖ´ë µ¿Á¢ÀÚ¼ö

		\~english
		Maximum number of con-current user per server

		\~chinese
		Øß?Ü×?ÐïõÌÓÞÔÒ??ïÈíº?¡£

		\~japanese
		«µ?«Ð??ª¿ªêõÌÓÞÔÒãÁïÈ?íº?
		\~
		*/
		static const int MaxConnectionCount = 60000;

		/**
		\~korean
		¼­¹ö¿¡¼­ ÇÑ¹øÀÇ multicast¸¦ ÇÒ¶§ heap allocÀÌ ºÒÇÊ¿äÇÑ ¼öÁØÀÇ Åë»óÀûÀÎ ÃÖ´ë ¼Û½Å·®

		\~english
		Maximum amount of normal communication that does not require heap alloc when server performs 1 multicast

		\~chinese
		î¤Ü×?Ðï?ú¼ìéó­multicastîÜ?ý¦£¬heap alloc Üôù±é©â©ñ×îÜìéÚõõÌÓÞ?áêãáãÓÕá¡£

		\~japanese
		«µ?«Ð?ªÇìéÓøªÎ«Þ«ë«Á«­«ã«¹«Èªòª¹ªëãÁheap allocª¬Üôé©ªÊâ©ñÞªÎ÷×ßÈîÜªÊõÌÓÞáêãáÕá
		\~
		*/
		static const int OrdinaryHeavyS2CMulticastCount = 100;

		/**
		\~korean
		test splitter¸¦ ÄÓ °ÍÀÎ°¡ ¸» °ÍÀÎ°¡?
		- ÄÓ °æ¿ì Åë½Å·®Àº ¾à°£ Áõ°¡ÇÏ³ª splitter test¸¦ ÅëÇØ ±úÁø serializationÀ» Ã£´Âµ¥ µµ¿òÀÌ µÈ´Ù.

		\~english
		test splitter is to be turned on or off?
		- If on then amount of communication slightly increases but it helps finding cracked serialization through splitter test.

		\~chinese
		ãÀÜú?test splitter£¿
		- ?îÜ?÷×ãáÕá?õªÚ°ñòÊ¥£¬Ó£ãÀ?÷×?splitter test??áïîÜserialization?êó?ð¾¡£

		\~japanese
		test splitterªòªÄª±ªëª«ªÄª±ªÊª¤ª«£¿
		- ªÄª±ªëíÞùê¡¢÷×ãáÕáªÏá´ª·?Ê¥ª·ªÞª¹ª¬¡¢splitter testªò÷×ª¸?ªìª¿serializationªò÷®ª¹ªÎªËð¾ª«ªêªÞª¹¡£
		\~
		*/
		PROUD_API static const bool EnableTestSplitter;

		static const uint32_t ClientListHashTableValue = 101;
	private:
		/**
		\~korean
		configÀÇ °ªÀ» º¯°æÇÒ ¶§¸¸ ÀÌ°ÍÀ» °É¾î¾ß ÇÑ´Ù!

		\~english
		Use it only for changing config value

		\~chinese
		ñþî¤áóËÇconfig?îÜ?ý¦ÞÅéÄ¡£

		\~japanese
		ConfigªÎö·ªò?ÌÚª¹ªëãÁªÎªßª³ªìªòª«ª±ªëù±é©ª¬ª¢ªêªÞª¹!
		\~
		*/
		static CriticalSection m_writeCritSec;
	public:
		PROUD_API static bool EnableSpeedHackDetectorByDefault;

		/**
		\~korean
		»ç¿ëÀÚ´Â ÀÌ °ªÀ» false·Î ¹Ù²Ù¾î ¸Þ½ÃÁö ¿ì¼±¼øÀ§ ±â´ÉÀ» ²ø ¼ö ÀÖ´Ù. Å×½ºÆ® ¸ñÀûÀ¸·Î¸¸ ¾²´Â °ÍÀ» ±ÇÀåÇÑ´Ù.

		\~english
		User can turn off message priority function by changing it to false. We recommend to use it for testing

		\~chinese
		éÄ?Ê¦ì¤÷êó®?ËÇ?falseì»??ãáãÓîÜ?à»?ßíÍíÒö¡£Ëï?ñþî¤ì¤test?ÙÍîÜ?ÞÅéÄ¡£

		\~japanese
		«æ?«¶?ªÏª³ªÎö·ªòfalseªË?ª¨ªÆ«á«Ã«»?«¸ªÎ«×«é«¤«ª«ê«Æ«£Ñ¦Òöªò«ª«Õª¹ªëª³ªÈª¬ªÇª­ªÞª¹¡£«Æ«¹«ÈÙÍîÜªÇªÎªßÞÅª¦ª³ªÈªòªª?ªáª·ªÞª¹¡£
		\~
		*/
		PROUD_API static bool EnableMessagePriority;

		PROUD_API static const int64_t SpeedHackDetectorPingIntervalMs;

		PROUD_API static CriticalSection& GetWriteCriticalSection();

		PROUD_API static int DefaultMaxDirectP2PMulticastCount;

		PROUD_API static bool UpnpDetectNatDeviceByDefault, UpnpTcpAddPortMappingByDefault;

		PROUD_API static int64_t MeasureClientSendSpeedIntervalMs;

		PROUD_API static int64_t MeasureSendSpeedDurationMs;

		PROUD_API static DirectP2PStartCondition DefaultDirectP2PStartCondition;

		/**
		\~korean
		ProudNet ³»ºÎ ¶Ç´Â ProudNet¿¡ ÀÇÇØ ÄÝ¹éµÇ´Â ¸Þ¼­µå(RMI ¼ö½Å ·çÆ¾, ÀÌº¥Æ® ÇÚµé·¯ µî)¿¡¼­ unhandled exception(°¡·É ¸Þ¸ð¸® ±Ü±â)ÀÌ ¹ß»ýÇßÀ¸¸ç ±×°ÍÀ» »ç¿ëÀÚ°¡ catchÇÏÁö ¾ÊÀº °æ¿ì roudNetÀÌ ´ë½Å catch Ã³¸®ÇÑ ÈÄ OnUnhandledExceptionÀ¸·Î ³Ñ°ÜÁÙ °ÍÀÎÁö ¾Æ´Ï¸é ±×³É unhandled exceptionÀ» ³ÀµÑ °ÍÀÎÁö¸¦ °áÁ¤ÇÏ´Â º¯¼öÀÌ´Ù.
		- ±âº»°ªÀº trueÀÌ´Ù.
		- »ç¿ëÀÚ´Â ¾ðÁ¦µçÁö ÀÌ °ªÀ» ¹Ù²ãµµ µÈ´Ù.

		\~english
		The variable that decides whether:

		1. to pass as OnUnhandledException after Proudnet processes it as catch when unhandled exception(such as scratching memory) occurs at the method(RMI reception routine, event handler)
		called back by either ProudNet internal or ProudNet while user did not catch,

		2. or to leave unhandled exception as it is.
		- Default is true.
		- User can change this value at any time.

		\~chinese
		ù¬ProudNet?Ý»ûäíºProudNetÚ÷üÞîÜÛ°Ûö£¨RMI â¥ãároutine£¬event handler Ôõ£©?ßæÖõunhandled exceptionì»ó¦éÄ??êócatchîÜ?ý¦£¬?ïÒProudNet?catch?×âý¨??OnUnhandledException?ãÀ??×ºó·unhandled exceptionîÜ??¡£
		- Ùù??ãÀtrue¡£
		- éÄ?Ê¦ì¤??áóËÇó®?¡£

		\~japanese
		ProudNet?Ý»ªÞª¿ªÏProudNetªËªèªÃªÆ«³?«ë«Ð«Ã«¯ªµªìªë«á«½«Ã«É(RMIáôãá«ë?«Á«ó¡¢«¤«Ù«ó«È«Ï«ó«É«é?ªÊªÉ)ªÇunhandled exceptionª¬?ßæª·ªÆ¡¢ª½ªìªò«æ?«¶?ª¬catchª·ªÊª¤íÞùê¡¢roudNetª¬ÓÛªïªêªËcatch?×âª·ª¿ý­¡¢OnUnhandledExceptionªËìÚª­Ô¤ª¹ª«¡¢ª½ªìªÈªâª½ªÎªÞªÞunhandled exceptionªòöÇª¤ªÆöÇª¯ª«ªòÌ½ïÒª¹ªë??ªÇª¹¡£
		- ÐñÜâö·ªÏtureªÇª¹¡£
		- «æ?«¶?ªÏª¤ªÄªÇªâª³ªÎö·ªò?ÌÚª·ªÆªâÕÞª¤ªÇª¹¡£

		\~
		*/
		PROUD_API static bool CatchUnhandledException;

		/**
		\~korean
		ProudNet »ç¿ëÀÚ°¡ ½Ç¼ö¸¦ ÇÑ °æ¿ì ´ëÈ­ »óÀÚ·Î º¸ÀÏ °ÍÀÎÁö ¿©Å¸ ¹æ½ÄÀ¸·Î Ã³¸®ÇÒ °ÍÀÎÁö¸¦
		°áÁ¤ÇÏ´Â º¯¼ö´Ù.
		- »ç¿ëÀÚ´Â ¾ðÁ¦µçÁö ÀÌ °ªÀ» ¹Ù²ãµµ µÈ´Ù.
		- ±âº»°ªÀº ErrorReaction_MessageBox ÀÌ´Ù.

		\~english
		A variable to decide to display ProudNet user mistake as chat box or other way
		- User can change this value at any time.
		- Default is ErrorReaction_MessageBox.

		\~chinese
		?ïÒProudNetéÄ?ã÷?îÜ?ý¦??????ãÀéÄÐìöâÛ°ãÒ?×âîÜ??¡£
		- éÄ?Ê¦ì¤?ñýáóËÇó®?¡£
		- Ùù??ãÀErrorReaction_MessageBox¡£

		\~japanese
		ProudNet «æ?«¶?ª¬ÊàêÞª¤ªòª·ª¿íÞùê¡¢«À«¤«¢«í«°«Ü«Ã«¯«¹ªÇøúãÆª¹ªëª«¡¢öâªÎÛ°ãÒªÇ?×âª¹ªëª«ªòÌ½ïÒª¹ªë??ªÇª¹¡£
		- «æ?«¶?ªÏª¤ªÄªÇªâª³ªÎö·ªò?ÌÚª·ªÆªâÕÞª¤ªÇª¹¡£
		- ÐñÜâö·ªÏErrorReaction_MessageBoxªÇª¹¡£
		\~
		*/
		PROUD_API static ErrorReaction UserMisuseErrorReaction;

		/**
		\~korean
		CNetClient ÀÇ ³»ºÎ Ã³¸®¿ë worker thread ÀÇ ¿ì¼±¼øÀ§¸¦ Åë»óº¸´Ù ³ô°Ô ¼³Á¤ÇÏ´ÂÁö ¿©ºÎ
		- ±âº»°ª: trueÀÌ´Ù.
		- Å¬¶óÀÌ¾ðÆ® ¾îÇÃ¸®ÄÉÀÌ¼Ç¿¡¼­ CNetClient ÀÎ½ºÅÏ½º¸¦ »ç¿ëÇÏ´Â °æ¿ì ·»´õ¸µ ÇÁ·¹ÀÓÀÌ ¶³¾îÁö´Â °æ¿ì
		ÀÌ °ªÀ» false·Î ¼¼ÆÃÇØ¼­ ¹®Á¦ ÇØ°áÀ» ÇÒ °¡´É¼ºÀÌ ÀÖ±âµµ ÇÏ´Ù. ÇÏÁö¸¸ µå¹°´Ù. Â÷¶ó¸® Åë½Å·®À» ÁÙÀÌ´Â °ÍÀÌ ³´´Ù.
		- ÃÖÃÊÀÇ CNetClient ÀÎ½ºÅÏ½º¸¦ ¸¸µé±â Àü¿¡¸¸ ÀÌ °ªÀ» ¼³Á¤ÇÒ ¼ö ÀÖ´Ù.

		\~english
		To decide whether to set priority of internal worker thread of CNetClient to be higher than normal
		- Default: true
		- When using CNetClient instance at client application causes lowering renderinf frames, there is a possibility to solve that by setting this as false. But very rare. It is better to redice communication traffic.
		- This value can be set only, before creating the very first CNetClient.

		\~chinese
		ãÀÜú÷ê CNetClient%îÜ?Ý»?×âéÄworker threadîÜ?à»?ßí?öÇà÷ÝïìéÚõÍÔÞÁ¡£
		- Ùù??£ºtrue¡£
		- î¤client?éÄñéÞÅéÄ CNetClient%?ÖÇîÜ?ý¦£¬àÂæø?ù»Ë½îÜ?ý¦£¬Ê¦ì¤÷êó®??öÇ?false?ì»ú°???¡£Ó£ãÀ?á´ùÖ?¡£?ãÀ?á´÷×ãáÕáîÜÌÚû¿¡£
		- ñþî¤?ËïÑÃôø CNetClient%?ÖÇñýîñÊ¦ì¤?öÇó®?¡£

		\~japanese
		CNetClientªÎ?Ý»?×âéÄworker threadªÎ«×«é«¤«ª«ê«Æ«£ªò÷×ßÈªèªêÍÔª¯àâïÒª¹ªëª«ªÎÊ¦Üú
		- ÐñÜâö·£ºtrueªÇª¹¡£
		-¡¡«¯«é«¤«¢«ó«È«¢«×«ê«±?«·«ç«óªÇCNetClient«¤«ó«¹«¿«ó«¹ªòÞÅª¦íÞùê¡¢«ì«ó«À«ê«ó«°«Õ«ì?«àª¬ÕªªÁªëíÞùê¡¢ª³ªÎö·ªòfalseªËàâïÒª·ªÆÙýð¹ú°Ì½ªòª¹ªëÊ¦Òöàõªâª¢ªêªÞª¹¡£ª·ª«ª·¡¢ýüªÇª¹¡£ªàª·ªí¡¢÷×ãáÕáªòÊõªéª·ª¿Û°ª¬?ªÇª¹¡£
		- õÌôøªÎCNetClinet«¤«ó«¹«¿«ó«¹ªòíÂªëîñªÎªßª³ªÎö·ªòàâïÒª¹ªëª³ªÈª¬ªÇª­ªÞª¹¡£
		\~
		*/
		PROUD_API static bool NetworkerThreadPriorityIsHigh;

		/**
		\~korean
		¼ÒÄÏÀÇ Shutdown ÀÛ¾÷À» abortive or hardÀ¸·Î ÁøÇàÇÏ°íÀÚ ÇÒ ¶§ ¼³Á¤ÇÏ´Â º¯¼öÀÔ´Ï´Ù.
		Å×½ºÆ® ¸ñÀûÀ¸·Î¸¸ ¾²´Â °ÍÀ» ±ÇÀåÇÕ´Ï´Ù.
		- ±âº»°ª: falseÀÌ´Ù.
		\~english
		It is the variable which is setted when progressing shutdown of socket by aboritive or  hard.
		We recommend to use it for testing
		- Default: false
		\~chinese TODO:translate needed.
		It is the variable which is setted when progressing shutdown of socket by aboritive or  hard.
		We recommend to use it for testing
		- Default: false
		\~japanese TODO:translate needed.
		It is the variable which is setted when progressing shutdown of socket by aboritive or  hard.
		We recommend to use it for testing
		- Default: false
		\~
		*/
		PROUD_API static bool EnableAbortiveSocketClose;

		/**
		\~korean
		ÇÁ¶ó¿ìµå³Ý ³»ºÎ¿¡¼­ »ç¿ëµÇ°í ÀÖ´Â Object Pooling ±â´ÉÀ» on/off ÇÒ ¼ö ÀÖ´Â º¯¼ö ÀÔ´Ï´Ù.
		»ç¿ëÀÚ´Â ÀÌ °ªÀ» º¯°æÇÏÁö ¾Ê´Â °ÍÀ» ±ÇÀåÇÕ´Ï´Ù.
		- ±âº»°ª: trueÀÌ´Ù.
		\~english
		This variable can turn on or off Object Pooling function in ProudNet.
		We recommend not to change it.
		- Default: true
		\~chinese TODO:translate needed.
		This variable can on/off Object Pooling function in ProudNet.
		We recommend not to change it.
		- Default: true
		\~japanese TODO:translate needed.
		This variable can on/off Object Pooling function in ProudNet.
		We recommend not to change it.
		- Default: true
		\~
		*/
		PROUD_API static bool EnableObjectPooling;

		/**
		\~korean
		¼­¹ö TCP ListenSocket ÀÛ¾÷½Ã¿¡ SocketReuseAddress ¼ÒÄÏ ¿É¼ÇÀ» ¼³Á¤ÇÑ´Ù.
		- ±âº»°ª : trueÀÌ´Ù.
		\~english
		\~chinese
		\~japanese
		\~
		*/
		PROUD_API static bool EnableSocketReuseAddress;

		//PROUD_API static double ReportP2PGroupPingIntervalMs;
		PROUD_API static int64_t ReportLanP2PPeerPingIntervalMs;
		PROUD_API static int64_t ReportP2PPeerPingTestIntervalMs;
		PROUD_API static int64_t ReportServerTimeAndPingIntervalMs;
		PROUD_API static int64_t LongIntervalMs;

		PROUD_API static int64_t MinSendSpeed;

		PROUD_API static int DefaultOverSendSuspectingThresholdInBytes;
		PROUD_API static bool ForceUnsafeHeapToSafeHeap;
		PROUD_API static bool EnableSendBrake;
		PROUD_API static int UdpCongestionControl_MinPacketLossPercent;
		PROUD_API static int64_t VizReconnectTryIntervalMs;
		PROUD_API static int64_t SuperPeerSelectionPremiumMs;

		/**
		\~korean
		ProudNet ¿¡¼­ HostID Àç»ç¿ë ¹ß±Þ½Ã ¸îÃÊ°¡ Áö³ª¾ß ¹ß±ÞÇÒÁö¸¦ °áÁ¤ÇÏ´Â °ªÀÔ´Ï´Ù.

		\~english
		It will decide issue timing for issuing HostID re-use at ProudNet.

		\~chinese
		î¤ProudNet?Û¯Host IDî¢ó­ÞÅéÄ?£¬?ïÒî¤?õ©ñýý¨î¦??Û¯îÜ?¡£

		\~japanese
		ProudNetªÇ HostID î¢ÞÅéÄ?ú¼ãÁªËù¼õ©ª¬Î¦ª®ªÆ?ú¼ª¹ªëª«ªòÌ½ïÒª¹ªëö·ªÇª¹¡£
		\~
		*/
		PROUD_API static int64_t HostIDRecycleAllowTimeMs;

		/**
		\~korean
		SendqueueÀÇ ¿ë·®ÀÌ ¾ó¸¶³ª ÃÊ°úµÇ¸é warning¸¦ ³ª¿À°Ô ÇÒ°ÍÀÎÁö¿¡ ´ëÇÑ °ªÀÔ´Ï´Ù.

		\~english
		It will decide warning message timing depends on amount of Sendqueue

		\~chinese
		?Sendqueueé»Õáõ±?Òýá´î¦õó?warningîÜ?¡£

		\~japanese
		SendqueueªÎé»Õáª¬ªÉªìªÀª±õ±Î¦ª¹ªìªÐwarningªòøúãÆª¹ªëª«ªË?ª¹ªëö·ªÇª¹¡£
		\~
		*/
		PROUD_API static int SendQueueHeavyWarningCapacity;

		PROUD_API static int64_t SendQueueHeavyWarningTimeMs;
		PROUD_API static int64_t SendQueueHeavyWarningCheckCoolTimeMs;

		/**
		\~korean
		emergency log¸¦ À§ÇÑ NetClientStats ÀÇ »çº»À» °»½ÅÇÒ coolTime °ªÀÔ´Ï´Ù.

		\~english 
		This is the coolTime value to renew the copy of NetClientStats for the emergency log. 

		\~chinese
		?Öõemergency log£¬é©ÌÚãæNetClientStatsÜùÜâîÜcoolTime?¡£

		\~japanese
		emergency logªÎª¿ªáªÎNetClientStatsªÎ«³«Ô?ªòÌÚãæª¹ªëcoolTimeö·ªÇª¹¡£
		\~
		*/
		PROUD_API static int64_t UpdateNetClientStatCloneCoolTimeMs;

		PROUD_API static bool EnableErrorReportToNettention;

		PROUD_API static int64_t ManagerGarbageFreeTimeMs;
		PROUD_API static unsigned int ManagerAverageElapsedTimeCollectCount;
		PROUD_API static bool	EnableStarvationWarning;

		PROUD_API static bool FraggingOnNeedByDefault;
		PROUD_API static bool CheckDeadLock;
		PROUD_API static bool UseIsSameLanToLocalForMaxDirectP2PMulticast;

		PROUD_API static const int TcpSendMaxAmount;

		/**
		\~korean
		Thread local storage (TLS) ÇÔ¼ö¸¦ »ç¿ëÇÒÁö ¿©ºÎ¸¦ °áÁ¤ÇÕ´Ï´Ù.
		±âº»°ªÀº trueÀÔ´Ï´Ù.
		TLS ÇÔ¼ö¸¦ »ç¿ëÇÒ ¼ö ¾ø´Â È¯°æ¿¡ ÇÑÇØ¼­, ÀÌ °ªÀ» false·Î ¼³Á¤ÇÏ½Ê½Ã¿À.
		(¿¹¸¦ µé¾î ¸î ÇØÅ· ¹æÁö 3rd party ¼ÒÇÁÆ®¿þ¾î È¥¿ëÀ» ÇÏ´Â °æ¿ì)

		\~english 
		This is to determine whether to use the Thread local storage (TLS) function. 
		The default value is true. 
		For the environment where the TLS function cannot be used only, set this value as false. 
		(for example, when an anti-hacking 3rd party software is used together)

		\~chinese
		?ïÒãÀÜúÞÅéÄThread local storage (TLS)ùÞ?¡£
		ÐñÜâ?ãÀtrue¡£
		ùÚéÍî¤ÙéÛöÞÅéÄTLSùÞ??îÜ?ÌÑù»??ó®??öÇ?false¡£
		£¨ÖÇåýûèéÄ??ÛÁ?3rd party?ËìîÜ?ý¦¡££©

		\~japanese
		Thread local storage (TLS)??ªòÞÅª¦ª«ªÉª¦ª«ªòÌ½ïÒª·ªÞª¹¡£
		ÐñÜâö·ªÏtrueªÇª¹¡£
		TLS??ªòÞÅéÄªÇª­ªÊª¤ü»ÌÑªËùÚªÃªÆ¡¢ª³ªÎö·ªòfalseªËàâïÒª·ªÆª¯ªÀªµª¤¡£
		(ÖÇª¨ªÐ¡¢«Ï«Ã«­«ó«°ÛÁò­3rd party«½«Õ«È«¦«§«¢ªÈûèéÄª¹ªëíÞùê)
		\~
		*/
		PROUD_API static const bool AllowUseTls;

		PROUD_API static bool ConcealDeadlockOnDisconnect;

		//kdh MessageOverload Warning Ãß°¡
		PROUD_API static int MessageOverloadWarningLimit;
		PROUD_API static int MessageOverloadWarningLimitTimeMs; //sec

		// 		PROUD_API static int64_t LanServerMessageOverloadTimerIntervalMs;
		// 		PROUD_API static int64_t LanClientMessageOverloadTimerIntervalMs;
		// 		PROUD_API static int64_t NetServerMessageOverloadTimerIntervalMs;
		// 		PROUD_API static int64_t NetClientMessageOverloadTimerIntervalMs;
		PROUD_API static int64_t MessageOverloadTimerIntervalMs;
		PROUD_API static int64_t LanRemotePeerHeartBeatTimerIntervalMs;

		PROUD_API static void AssertTimeoutTimeAppropriate(int64_t ms);
		PROUD_API static int P2PFallbackTcpRelayResendTimeIntervalMs;

		PROUD_API static int CleanUpOldPacketIntervalMs;
		PROUD_API static int NormalizePacketIntervalMs;
		PROUD_API static void ThrowExceptionIfMessageLengthOutOfRange(int length);

		PROUD_API static double MessageRecovery_MessageIDAckIntervalMs;

		PROUD_API static bool ListenSocket_RetryOnInvalidArgError;
		PROUD_API static bool AllowOutputDebugString;

		PROUD_API static bool DefensiveSendReadyListAdd;
		PROUD_API static bool DefensiveCustomValueEvent;

		PROUD_API static bool EnablePeriodicDetectingTransitionNetwork;
	};
	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
