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
//#include "ConnectParam.h"
#include "HostIDArray.h"
#include "AddrPort.h"
#include "Enums.h"
#include "EncryptEnum.h"
#include "RMIContext.h"
#include "ErrorInfo.h"
#include "LambdaEventHandler.h"

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

	class CMessage;	
	class CSendFragRefs;
	class ErrorInfo;
	class IRmiProxy;
	class IRmiStub;
	class RmiContext;
	class MessageSummary;
	class FavoriteLV;

	struct SendOpt;

	/** 
	\~korean
	\brief ProudNet RMI°¡ ÂüÁ¶ÇÏ´Â ³×Æ®¿öÅ© È£½ºÆ® ÀÎÅÍÆäÀÌ½ºÀÔ´Ï´Ù.
	À¯Àú´Â ÀÌ Å¬·¡½º¸¦ Á÷Á¢ »ç¿ëÇÒ ÇÊ¿ä°¡ ¾ø½À´Ï´Ù. 

	\~english
	\brief ProudNet Network host interface that is referred by RMI.
	User does not have to use this class directly.

	\~chinese
	\brief ProudNet RMI?ğÎîÜ??ñ«ÏõÍ£Øü¡£
	éÄ?ÜôéÄòÁïÈŞÅéÄó®?¡£

	\~japanese
	\brief ProudNet RMIª¬?ğÎª¹ªë«Í«Ã«È«ï?«¯«Û«¹«È«¤«ó«¿?«Õ«§?«¹ªÇª¹¡£
	«æ?«¶?ªÏª³ªÎ«¯«é«¹ªòòÁïÈŞÅª¦ù±é©ª¬ª¢ªêªŞª»ªó¡£
	\~
	*/
	class IRmiHost
	{
		friend class IRmiProxy;
	public:
		virtual ~IRmiHost() {}

		/** 
		\~korean
		PIDL ÄÄÆÄÀÏ·¯ÀÇ °á°ú¹° Áß proxy¸¦ ÀÌ °´Ã¼¿¡ µî·ÏÇÑ´Ù. 

		\~english
		Registers proxy among the results of PIDL compiler to this object

		\~chinese
		PIDL ??ĞïîÜ?Úªñé÷êproxyÔô?Óğó®?ßÚ¡£

		\~japanese
		PILD«³«ó«Ñ«¤«é?ªÎÌ¿ÍıÚªªÎª¦ªÁproxyªòª³ªÎ«ª«Ö«¸«§«¯«ÈªËÔô?ª·ªŞª¹¡£
		\~
		*/
		virtual void AttachProxy(IRmiProxy* proxy) = 0;
		// no-throw version for UE4, etc.
		void AttachProxy(IRmiProxy *proxy, ErrorInfoPtr& outError);

		/** 
		\~korean
		PIDL ÄÄÆÄÀÏ·¯ÀÇ °á°ú¹° Áß stubÀ» ÀÌ °´Ã¼¿¡ µî·ÏÇÑ´Ù. 

		\~english
		Registers stub among the results of PIDL compiler to this object

		\~chinese
		PIDL ??Ğï?Úªñé÷êstubÔô?Óğó®?ßÚ¡£

		\~japanese
		PILD«³«ó«Ñ«¤«é?ªÎÌ¿ÍıÚªªÎª¦ªÁstubªòª³ªÎ«ª«Ö«¸«§«¯«ÈªËÔô?ª·ªŞª¹¡£
		\~
		*/
		virtual void AttachStub(IRmiStub* stub) = 0;
		// no-throw version for UE4, etc.
		void AttachStub(IRmiStub* stub, ErrorInfoPtr& outError);
		/** 
		\~korean
		AttachProxy ÀÇ ¹İ´ë·Î¼­, ÀÌ °´Ã¼¿¡¼­ µî·Ï ÇØÁ¦¸¦ ÇÑ´Ù. 

		\~english
		As opposite to AttachProxy, this object cancels the registration.

		\~chinese
		ãÀAttachProxyîÜßÓÚã£¬ú°ğ¶î¤ó®?ßÚîÜÔô?¡£

		\~japanese
		AttachProxyªÎÚã?ªÈª·ªÆ¡¢ª³ªÎ«ª«Ö«¸«§«¯«ÈªÇÔô?ú°ğ¶ªòª·ªŞª¹¡£
		\~
		*/
		virtual void DetachProxy(IRmiProxy* proxy) = 0;
		// no-throw version for UE4, etc.
		void DetachProxy(IRmiProxy* proxy, ErrorInfoPtr& outError);
		/** 
		\~korean
		AttachStub ÀÇ ¹İ´ë·Î¼­, ÀÌ °´Ã¼¿¡¼­ µî·Ï ÇØÁ¦¸¦ ÇÑ´Ù. 

		\~english
		As opposite to AttachStub, this object cancels the registration.

		\~chinese
		ãÀAttachStubîÜßÓÚã£¬ú°ğ¶î¤ó®?ßÚîÜÔô?¡£

		\~japanese
		AttachStubªÎÚã?ªÈª·ªÆ¡¢ª³ªÎ«ª«Ö«¸«§«¯«ÈªÇÔô?ú°ğ¶ªòª·ªŞª¹¡£
		\~
		*/
		virtual void DetachStub(IRmiStub* stub) = 0;
		// no-throw version for UE4, etc.
		void DetachStub(IRmiStub* stub, ErrorInfoPtr& outError);

		// Set any value you wish. For example, owner of this object.
		virtual void SetTag(void* value) = 0;
		virtual void* GetTag() = 0;

#ifdef SUPPORTS_LAMBDA_EXPRESSION
	public:
		/**
		
		»ç¿ëÀÚ Á¤ÀÇ ÇÔ¼ö³ª ¶÷´Ù½ÄÀ» ºñµ¿±â·Î ½ÇÇàÇÕ´Ï´Ù. ÀÚ¼¼ÇÑ °ÍÀº \page run_async¸¦ Âü°íÇÏ½Ê½Ã¿À.

		\param taskOwner ¾î¶² Host¸¦ À§ÇÑ ºñµ¿±â ½ÇÇàÀÎÁö¸¦ °¡¸®Åµ´Ï´Ù.
		\param func ÇÔ¼ö È¤Àº ¶÷´Ù½ÄÀÔ´Ï´Ù. ÀÏ¹İÀûÀ¸·Î ¶÷´Ù½ÄÀÇ »ç¿ëÀ» ±ÇÀåÇÕ´Ï´Ù.
		\return taskOwner°¡ À¯È¿ÇÏ¸é true¸¦ ¸®ÅÏÇÕ´Ï´Ù. false¸¦ ¸®ÅÏÇÒ °æ¿ì func ´Â ½ÇÇàµÇÁö ¾Ê½À´Ï´Ù.
		*/
		inline bool RunAsync(HostID taskOwner, const std::function<void()> &func)
		{
			return RunAsync(taskOwner, new Lambda_Param0<void>(func));
		}

#endif
		// ¶÷´Ù½Ä ¹ÌÁö¿ø ÄÄÆÄÀÏ·¯¿¡¼­´Â ¸ø ¾²Áö¸¸, °¡»ó ÇÔ¼ö´Â ½ÇÁ¸ ¸â¹öÀÌ¹Ç·Î, 
		// Á¶°ÇºÎ ÄÄÆÄÀÏ ºí·° ¹Ù±ù¿¡ ÀÖ¾î¾ß ÇÑ´Ù.
		virtual bool RunAsync(HostID taskOwner, LambdaBase_Param0<void>* func) = 0;

	protected:
		// ³»ºÎ ¿ëµµ ÇÔ¼öÀÌ´Ù. »ç¿ëÀÚ´Â È£ÃâÇÏÁö ¸» °Í.
		// ÀÌ ÇÔ¼ö¿¡ ´ëÇÑ ¼³¸íÀº CNetClientImpl¿¡ ÀÖÀ½
		virtual bool Send(const CSendFragRefs &sendData,
			const SendOpt& sendContext,
			const HostID *sendTo, int numberOfsendTo, int &compressedPayloadLength,
			FavoriteLV& favoriteLV) = 0;

	public:

		/** 
		\~korean
		simple packet mode¸¦ »ç¿ëÇÏ°í ÀÖ´ÂÁö È®ÀÎÇÑ´Ù.

		\~english
		Check to see whether simple packet mode is being used. 

		\~chinese
		??ãÀÜúŞÅéÄsimple packet mode¡£

		\~japanese
		simple packet modeªòŞÅªÃªÆª¤ªëª«ªòü¬ìãª·ªŞª¹¡£
		\~
		*/
		virtual bool IsSimplePacketMode() = 0;

		/** 
		\~korean
		³»ºÎ ÇÔ¼ö. »ç¿ëÀÚ´Â È£Ãâ ±İÁö. 

		\~english
		Internal function. User must not call this.

		\~chinese
		?İ»ùŞ?¡£éÄ?Ğ×ò­û¼Ğ£¡£

		\~japanese
		?İ»??¡£«æ?«¶?ªÏû¼ªÓõóª·Ğ×ò­
		\~
		*/
		virtual void ShowError_NOCSLOCK( ErrorInfoPtr errorInfo ) = 0;
		virtual void ShowNotImplementedRmiWarning(const PNTCHAR* RMIName) = 0;
		virtual void PostCheckReadMessage(CMessage& msg, const PNTCHAR* RMIName) = 0;

		/** 
		\~korean
		³»ºÎ ÇÔ¼ö. »ç¿ëÀÚ´Â È£Ãâ ±İÁö. 

		\~english
		Internal function. User must not call this.

		\~chinese
		?İ»ùŞ?¡£éÄ?Ğ×ò­û¼Ğ£¡£

		\~japanese
		?İ»??¡£«æ?«¶?ªÏû¼ªÓõóª·Ğ×ò­
		\~
		*/
		virtual void ConvertGroupToIndividualsAndUnion( int numberOfsendTo, const HostID * sendTo, HostIDArray& output, FavoriteLV& favoriteLV) = 0;

		virtual CriticalSection& GetCriticalSection() = 0;

#ifdef VIZAGENT
		virtual void EnableVizAgent(const PNTCHAR* vizServerAddr, int vizServerPort, const String &loginKey) = 0;

		virtual void Viz_NotifySendByProxy(const HostID* remotes, int remoteCount, const MessageSummary &summary, const RmiContext& rmiContext) = 0;
		virtual void Viz_NotifyRecvToStub(HostID sender, RmiID RmiID, const PNTCHAR* RmiName, const PNTCHAR* paramString) = 0;
#endif
	};

	/** 
	\~korean
	\brief clientWorkerÀÇ Á¤º¸¸¦ ´ã´Â ±¸Á¶Ã¼. 

	\~english
	\brief Structure that contain information of clientWorker

	\~chinese
	\brief øĞùßclientWorkerãáãÓîÜ?ğã?¡£

	\~japanese
	\brief clientWorkerªÎï×ÜÃªòìıªìªëÏ°ğã? 
	\~
	*/
	class CClientWorkerInfo
	{
	public:

		//bool m_isWorkerThreadEnded;

		int m_connectCallCount;

		int m_disconnectCallCount;

		ConnectionState m_connectionState;

		int m_finalWorkerItemCount;

//		int64_t m_lastTcpStreamTimeMs;

		int64_t m_currentTimeMs;

		int m_peerCount;
#if !defined(_WIN32)
		pthread_t m_workerThreadID;
#else
		uint32_t m_workerThreadID;
#endif
	};

	/** 
	\~korean
	\brief socketÀÇ Á¤º¸¸¦ ´ã´Â ±¸Á¶Ã¼ÀÔ´Ï´Ù.

	\~english
	\brief Structure that contain information of socket

	\~chinese
	\brief øĞùßsocketãáãÓîÜ?ğã?¡£

	\~japanese
	\brief socketªÎï×ÜÃªòìıªìªëÏ°ğã?ªÇª¹¡£
	\~
	*/
	class CSocketInfo
	{
	public:
		/** 
		\~korean
		TCP socket handleÀÔ´Ï´Ù. ¼­¹ö¿ÍÀÇ ¿¬°áÀ» À§ÇÑ socketÀÔ´Ï´Ù. 

		\~english
		It is TCP socket handle. This socket is for connecting to server

		\~chinese
		ãÀTCP socket handle¡£?Öõ?Ü×?Ğï?ïÈîÜsocket¡£

		\~japanese
		TCP socket handleªÇª¹¡£«µ?«Ğ?ªÈªÎïÈ?ªÎª¿ªáªÎsocketªÇª¹¡£
		\~
		*/
		SOCKET m_tcpSocket;

		/** 
		\~korean
		UDP socket handleÀÔ´Ï´Ù. ¼­¹ö È¤Èç P2P peer¿ÍÀÇ ¿¬°áÀ» À§ÇÑ socketÀÔ´Ï´Ù. 

		\~english
		It is UDP socket handle. This socket is for connecting to server or P2P peer.

		\~chinese
		ãÀUDP socket handle¡£?Öõ?Ü×?ĞïûäíºP2P peerîÜ?ïÈîÜsocket¡£

		\~japanese
		UDP socket handleªÇª¹¡£«µ?«Ğ?ªŞª¿ªÏP2P peerªÈªÎïÈ?ªÎª¿ªáªÎsocketªÇª¹¡£ 
		\~
		*/
		SOCKET m_udpSocket;

		inline CSocketInfo()
		{
			m_tcpSocket = InvalidSocket;
			m_udpSocket = InvalidSocket;
		}
	};

	/** 
	\~korean
	\brief 1°³ÀÇ ½º·¹µå¿¡ ´ëÇÑ Á¤º¸°¡ ´ã°ÜÁ® ÀÖ´Â ±¸Á¶Ã¼. 

	\~english
	\brief Construct contains information of 1 thread

	\~chinese
	\brief øĞùß?ìé??ïïãáãÓîÜ?ğã?¡£

	\~japanese
	\brief 1ËÁªÎ«¹«ì«Ã«ÉªË?ª¹ªëï×ÜÃª¬ìıªÃªÆª¤ªëÏ°ğã? 
	\~
	*/
	class CThreadInfo
	{
	public:
		/**
		\~korean
		ThreadÀÇ ID 

		\~english
		ID of thread

		\~chinese
		ThreadîÜID¡£

		\~japanese
		ThreadªÎID 
		\~
		*/
		uint64_t m_threadID;

		/**
		\~korean
		ThreadÀÇ Handle 

		\~english
		Handle of thread

		\~chinese
		ThreadîÜHandle¡£

		\~japanese
		ThreadªÎHandle 
		\~
		*/
#if defined(_WIN32)
		HANDLE m_threadHandle;
#else
		pthread_t m_threadHandle;
#endif
	};

	/** 
	\~korean
	\brief »ç¿ëÀÚ ÇÁ·Î±×·¥¿¡¼­ ¿£Áø¿¡ Àü´ŞÇÏ´Â ÀÔ·Â ÆÄ¶ó¸ŞÅÍ 

	\~english
	Input parameter delivered from \brief user program to engine

	\~chinese
	\brief î¤éÄ?ïïßíñé£¬èÙìÚÌÖ??îÜ?ìı??¡£

	\~japanese
	\brief «æ?«¶?«×«í«°«é«àªÇ«¨«ó«¸«óªË?Ó¹ª¹ªëìıÕô«Ñ«é«á?«¿? 
	\~
	*/
	class CApplicationHint 
	{
	public:
		/** 
		\~korean
		»ç¿ëÀÚ°¡ ÃøÁ¤ÇÑ, ÀÀ¿ë ÇÁ·Î±×·¥ÀÇ ÇÁ·¹ÀÓ ·¹ÀÌÆ®ÀÔ´Ï´Ù. 

		\~english
		Frame rate of application program measured by user

		\~chinese
		éÄ??ïÒîÜ£¬?éÄïïßíîÜ?áÜáã¡£

		\~japanese
		«æ?«¶?ª¬ö´ïÒª·ª¿«¢«×«ê«±?«·«ç«ó«×«í«°«é«àªÎ«Õ«ì?«à«ì?«ÈªÇª¹¡£ 
		\~
		*/
		double m_recentFrameRate; 

		CApplicationHint()
		{
			m_recentFrameRate = 0;
		}
	};

	/** 
	\~korean
	\brief Åë°è Á¤º¸. µğ¹ö±ëÀÌ³ª ¼º´É ÃøÁ¤À» À§ÇÔ 

	\~english
	\brief statistics information. For debugging or performance test

	\~chinese
	\brief ??ãáãÓ¡£?Öõ??ûäàõÒö?ïÒ¡£

	\~japanese
	\brief ÷ÖÍªï×ÜÃ¡£«Ç«Ğ«Ã«®«ó«°ªÈª«àõÒöö´ïÒªÎª¿ªáªÎªâªÎªÇª¹¡£
	\~
	*/
	class ReliableUdpHostStats
	{
	public:
		// ¼ö½Å À©µµ¿¡ µé¾îÀÖ´Â ÇÁ·¹ÀÓ °¹¼ö, ¾ÆÁ÷ »Ì¾Æ³»Áö ¾ÊÀº ½ºÆ®¸² Å©±â, ¿©Áö²¯ ¹ŞÀº ½ºÆ®¸² Å©±â, ¿©Áö²¯ ¹ŞÀº ÇÁ·¹ÀÓ °¹¼ö, ÃÖ±Ù¿¡ ÇÁ·¹ÀÓ ¹Ş´Â °¹¼öÀÇ ¼Óµµ
		int m_receivedFrameCount, m_receivedStreamCount, m_totalReceivedStreamLength, m_totalAckFrameCount;
		int m_senderWindowLength;
		int m_senderWindowMaxLength;
		int m_senderWindowWidth;	// first~lastÀÇ number Â÷ÀÌ
		int m_expectedFrameNumberToReceive;
		int m_nextFrameNumberToSend;

		/** 
		\~korean
		¼Û½ÅÅ¥¿¡ ½×¿©ÀÖ´Â ½ºÆ®¸² Å©±â

		\~english
		Stream size that stacked at sending queue

		\~chinese
		÷Ø?î¤?áêqueueîÜ×µÓŞá³¡£

		\~japanese
		áêãá«­«å?ªËîİªâªÃªÆª¢ªë«¹«È«ê?«à«µ«¤«º
		\~
		*/
		int m_sendStreamCount;

		/** 
		\~korean
		ÃÊ¼Û½Å À©µµ¿¡ µé¾îÀÖ´Â ÇÁ·¹ÀÓ °¹¼ö

		\~english
		Number of frame that located in first sending window

		\~chinese
		î¤ôøã·?áê?îÜ???¡£

		\~japanese
		ôøáêãá«¦«£«ó«É«¦ªËìıªÃªÆª¤ªë«Õ«ì?«à?
		\~
		*/
		int m_senderWindowDataFrameCount;
		
        /**
		\~korean
		Àç¼Û½Å À©µµ¿¡ µé¾îÀÖ´Â ÇÁ·¹ÀÓ °¹¼ö

		\~english
		Number of frame that located in resend window

		\~chinese
		î¤î¢ó­?áê?îÜ???¡£

		\~japanese
		î¢áêãá«¦«£«ó«É«¦ªËìıªÃªÆª¤ªë«Õ«ì?«à?
		\~
		*/
		int m_resendFrameCount;

		/** 
		\~korean
		¿©Áö²¯ º¸³½ ½ºÆ®¸² Å©±â

		\~english
		Total size of sent stream

		\~chinese
		ò¸ĞÑ?áêîÜ×µÓŞá³¡£

		\~japanese
		ª³ªìªŞªÇáêªÃª¿«¹«È«ê?«à«µ«¤«º
		\~
		*/
		int m_totalSendStreamLength;

		/** 
		\~korean
		¿©Áö²¯ ÃÊ¼Û½ÅÇÑ ÇÁ·¹ÀÓ °¹¼ö
		- ÃÊ¼Û½ÅÇÑ ÇÁ·¹ÀÓ °¹¼ö¿¡ ºñÇØ ¿©Áö²¯ Àç¼Û½ÅÇÑ ÇÁ·¹ÀÓ °¹¼ö°¡ Áö³ªÄ¡°Ô Áõ°¡ÇÏ¸é P2P Reliable ¸Ş½ÃÂ¡ÀÌ Àß ÀÌ·ç¾îÁöÁö ¾ÊÀ½À» ÀÇ¹ÌÇÑ´Ù.

		\~english
		Total number of first send frame
		- If number of resent frame is dramarically increased compare to number of first send frame, it mean, it does not working P2P Reliable messaing unstably

		\~chinese
		ò¸ĞÑôøã·?áêîÜ???¡£
		- İïÑÃôøã·?áêîÜ???£¬ò¸ĞÑ?áêîÜ????İÂñòÊ¥îÜ?£¬ëòÚ«ó·P2P Reliable messaging?êó?û¿îÜèÇà÷¡£

		\~japanese
		ª³ªìªŞªÇôøáêãáª·ª¿«Õ«ì?«à?
		- ôøáêãáª·ª¿«Õ«ì?«à?ªËİïªÙ¡¢ª³ªìªŞªÇî¢áêãáª·ª¿«Õ«ì?«à?ª¬?Ê¥ª·Î¦ª®ª¿ªé¡¢P2P Reliable«á«Ã«»?«¸«ó«°ª¬ªèª¯ú¼ªïªìªÊª¤ª³ªÈªòëòÚ«ª·ªŞª¹¡£
		\~
		*/
		int m_totalFirstSendCount;

		/** 
		\~korean
		¿©Áö²¯ Àç¼Û½ÅÇÑ ÇÁ·¹ÀÓ °¹¼ö

		\~english
		Total number of resent frame

		\~chinese
		ò¸ĞÑî¢ó­?áêîÜ???¡£

		\~japanese
		ª³ªìªŞªÇî¢áêãáª·ª¿«Õ«ì?«à?
		\~
		*/
		int m_totalResendCount;

		/// if zero, it means nothing to show, or the number is zero indeed.
		int m_senderWindowLastFrame;

		int m_totalReceiveDataCount;
		int m_lastReceivedAckNumber;
		String ToString();
	};

	// ÁÖÀÇ: ÀÌ°É ¿©·¯ ½º·¹µå¿¡¼­ ³Ê¹« ÀÚÁÖ Á¢±ÙÇÒ ½Ã,¸ÖÆ¼ÄÚ¾î È¯°æ¿¡¼­ ¸ŞÀÎº¸µå»ó¿¡¼­ÀÇ º´¸ñÀÌ À¯¹ßµÇ´õ¶ó.
	class CTestStats
	{
	public:
		static double TestAllowedMaxSendSpeed;
		static double TestRecentReceiveSpeed;
		static double TestRecentSendSpeedAtReceiverSide;
	};

	// ÁÖÀÇ: ÀÌ°É ¿©·¯ ½º·¹µå¿¡¼­ ³Ê¹« ÀÚÁÖ Á¢±ÙÇÒ ½Ã,¸ÖÆ¼ÄÚ¾î È¯°æ¿¡¼­ ¸ŞÀÎº¸µå»ó¿¡¼­ÀÇ º´¸ñÀÌ À¯¹ßµÇ´õ¶ó.
	class CTestStats2
	{
	public:
		bool m_C2SReplyRecentReceiveSpeedDone;
		bool m_C2CRequestRecentReceiveSpeedDone;
		bool m_C2CReplyRecentReceiveSpeedDone;

		CTestStats2()
		{
			m_C2SReplyRecentReceiveSpeedDone = false;
			m_C2CRequestRecentReceiveSpeedDone = false;
			m_C2CReplyRecentReceiveSpeedDone = false;
		}
	};

	/** 
	\~korean
	Disconnect()¿¡¼­ »ç¿ëÇÏ´Â ÀÎÀÚÀÔ´Ï´Ù.

	\~english TODO:translate needed.
	This is the factor used in Disconnect()

	\~chinese
	Disconnect()ŞÅéÄîÜì×í­¡£
	\~japanese
	Disconnect()ªÇŞÅª¦ì×í­ªÇª¹¡£
	\~
	*/
	class CDisconnectArgs
	{
	public:
		/**
		\~korean
		graceful disconnect¸¦ ¼öÇàÇÏ´Âµ¥ °É¸®´Â ÃÖ´ë ½Ã°£ÀÔ´Ï´Ù.
		ÀÌ ½Ã°£À» ³Ñ¾î¼­¸é Proud.CNetClient.Disconnect()´Â ¹«Á¶°Ç returnÇÏ°Ô µÇ°í, ¼­¹ö¿¡¼­´Â Å¬¶óÀÌ¾ğÆ®ÀÇ ¿¬°á ÇØÁ¦¸¦ 
		Áï½Ã ÀÎ½ÄÇÏÁö ¸øÇÕ´Ï´Ù. 
		²À ÇÊ¿äÇÑ °æ¿ì°¡ ¾Æ´Ï¸é ÀÌ °ªÀ» º¯°æÇÏÁö ¸¶½Ê½Ã¿À. 

		\~english TODO:translate needed.
		If you exceed this time, Proud.CNetClient.Disconnect() unconditionally returns and the server cannot immediately recognize the disconnection of the client. 
		Unless absolutely necessary, do not change this value. 

		\~chinese
		?ú¼graceful disconnectá¶á¼ÙÄîÜõÌ???¡£
		åıÍıõ±õóó®??£¬? Proud.CNetClient.Disconnect()%???Ïõreturn£¬Ü×?Ğï?ÙéÛöØ¡Ê¾??ËÔ?Ó®îÜ?ïÈú°ğ¶¡£
		åıÜôãÀù±é©ï×?£¬???ÌÚó®?¡£

		\~japanese
		graceful disconnectªòâÄú¼ª¹ªëªËª«ª«ªëõÌÓŞãÁÊàªÇª¹¡£
		ª³ªÎãÁÊàª¬?Î¦ª·ª¿ªéProud.CNetClient.Disconnect()ªÏÙí?ËìªÇ«ê«¿?«óªµªìªÆ¡¢«µ?«Ğ?ªÇªÏ«¯«é«¤«¢«ó«ÈªÎïÈ?ú°ğ¶ªòòÁªÁªËìããÛªÇª­ªÊª¯ªÊªêªŞª¹¡£ 
		ù±ªºù±é©ªÊíŞùêªÇªÏªÊª±ªìªĞ¡¢ª³ªÎö·ªò?ÌÚª·ªÊª¤ªÇª¯ªÀªµª¤¡£
		\~
		*/
		int64_t m_gracefulDisconnectTimeoutMs;

		/**
		\~korean
		ÀÌ°ÍÀ¸·Î Disconnect½ÃÀÇ ´ë±âÇÏ´Â Sleep ½Ã°£À» Á¶ÀıÇÒ ¼ö ÀÖ½À´Ï´Ù.

		\~english TODO:translate needed.
		With this, you can adjust the sleep time waiting during disconnection. 

		\~chinese TODO:translate needed.
		÷×???Ê¦ì¤?ïÚ???ÔõÓâîÜSleep??¡£

		\~japanese TODO:translate needed.
		ª³ªìªÇDisconnectãÁªÎÓâÑ¦ª¹ªëSleepãÁÊàªòğàï½ª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\~
		*/
		uint32_t m_disconnectSleepIntervalMs;

		/**
		\~korean
		¼­¹ö¿¡¼­ Å¬¶óÀÌ¾ğÆ® ¿¬°á ÇØÁ¦ »çÀ¯¸¦ ÀÌ°ÍÀ» ÅëÇØ Àü¼ÛÇÒ ¼ö ÀÖ½À´Ï´Ù.

		\~english TODO:translate needed.
		In the server, you can transmit the client disconnection reason through this. 

		\~chinese
		Ü×?Ğï?÷×?ó®?áêËÔ?Ó®?ïÈú°ğ¶ê«ì×¡£
		\~japanese
		«µ?«Ğ?ªÇ«¯«é«¤«¢«ó«ÈïÈ?ú°ğ¶ªÎŞÀë¦ªò¡¢ª³ªìªò÷×ª¸?áêª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\~
		*/
		ByteArray m_comment;

		CDisconnectArgs();
	};

	extern StringA policyFileText;

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