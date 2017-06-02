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

#include "INetCoreEvent.h"
#include "AddrPort.h"
#include "NetClientInfo.h"
#include "acr.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	//class CUserWorkerThreadCallbackContext;
	/** \addtogroup net_group
	*  @{
	*/

	/** 
	\~korean
	CNetServer ¿ë event sink

	¿ë¹ı
	- ÀÌ °´Ã¼¸¦ ±¸ÇöÇÑ´Ù.
	- CNetServer ¿¡ ÆÄ¶ó¸ŞÅÍ·Î Àü´ŞÇÑ´Ù.

	\~english
	event sink for CNetServer

	Usage
	- Realize this object
	- Pass to CLanServer as a parmeter.

	\~chinese
	CNetServer éÄevent sink

	éÄÛö
	- ??ó®?ßÚ¡£
	- éÄ???áê? CNetServer%¡£

	\~japanese
	CnetServeréÄevent sink

	éÄÛö
	- ª³ªÎ«ª«Ö«¸«§«¯«Èªò?úŞª·ªŞª¹¡£
	- CNetServerªË«Ñ«é«á?«¿?ªÇ?Ó¹ª·ªŞª¹¡£
	\~
	*/
	class INetServerEvent : public INetCoreEvent
	{
	public:
		virtual ~INetServerEvent() {}

		/** 
		\~korean
		Å¬¶óÀÌ¾ğÆ®°¡ ¿¬°áÀ» µé¾î¿À¸é ¹ß»ıÇÏ´Â ÀÌº¥Æ®
		- OnConnectionRequest¿¡¼­ ÁøÀÔ Çã°¡¸¦ ÇÑ Å¬¶óÀÌ¾ğÆ®¿¡ ´ëÇØ¼­¸¸ Äİ¹éµÈ´Ù.
		\param clientInfo ¿¬°áÀÌ µé¾î¿Â Å¬¶óÀÌ¾ğÆ®

		\~english
		Event that occurs when client attempts to connect
		- Only called back for the client that received access permission from OnConnectionRequest  
		\param clientInfo client requested to connect

		\~chinese
		õó?èÌÊ«îÜ?ïÈîÜ??ßæîÜevent¡£
		- ñş?î¤OnConnectionRequestëÃ??ìıîÜèÌÊ«üŞ?¡£
		\param clientInfo õó??ïÈîÜèÌÊ«¡£

		\~japanese
		«¯«é«¤«¢«ó«Èª¬ïÈ?ªµªìªëªÈ?ßæª¹ªë«¤«Ù«ó«È
		- OnConnectionRequestªÇòäìıúÉÊ¦ªòª·ª¿«¯«é«¤«¢«ó«ÈªË?ª·ªÆªÎªß«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		\param clientInfo ïÈ?ªµªìª¿«¯«é«¤«¢«ó«È
		\~
		*/
		virtual void OnClientJoin(CNetClientInfo *clientInfo) = 0;

		/** 
		\~korean
		Å¬¶óÀÌ¾ğÆ®°¡ ¿¬°áÀ» ÇØÁ¦ÇÏ¸é ¹ß»ıÇÏ´Â ÀÌº¥Æ®ÀÔ´Ï´Ù.
		\param clientInfo ¿¬°áÀÌ ÇØÁ¦µÈ Å¬¶óÀÌ¾ğÆ®ÀÇ Á¤º¸ÀÔ´Ï´Ù.
		\param errorInfo ¿¬°áÀÌ ÇØÁ¦µÈ Å¬¶óÀÌ¾ğÆ®ÀÇ ¿¬°á ÇØÁ¦ Á¤º¸ÀÔ´Ï´Ù. 
		ErrorInfo.m_type °ªÀº ¿¬°á ÇØÁ¦ÀÇ °æÀ§¸¦, ErrorInfo.
		ÀÚ¼¼ÇÑ °ÍÀº ErrorInfo µµ¿ò¸»¿¡ ÀÖ½À´Ï´Ù.
		\param comment Å¬¶óÀÌ¾ğÆ®°¡ CNetClient.Disconnect ÀÇ ÆÄ¶ó¸ŞÅÍ comment ¸¦ ÅëÇØ º¸³»¿Â ¹®ÀÚ¿­ÀÔ´Ï´Ù.

		\~english
		Event that occurs when client terminates connection
		\param clientInfo client info that is disconnected
		\param errorInfo disconnection info of client that is disconneced 
		ErrorInfo.m_type value shows how disconnection processed
		Please refer ErrorInfo help section.
		\param comment text string sent by client via parameter comment of CNetClient.Disconnect

		\~chinese
		èÌÊ«ú°ğ¶?ïÈîÜ??ßæîÜevent¡£
		\param clientInfo ú°ğ¶?ïÈîÜèÌÊ«ãáãÓ¡£
		\param errorInfo ú°ğ¶?ïÈèÌÊ«îÜ?ïÈú°ğ¶ãáãÓ¡£
		ErrorInfo.m_type ?øúãÆ?ïÈú°ğ¶îÜ??¡£
		??îÜî¤ErrorInfo?ğ¾×ì¡£
		\param comment èÌÊ«÷×? CNetClient.Disconnect%îÜ??comment???îÜí®İ¬Íú¡£

		\~japanese
		«¯«é«¤«¢«ó«Èª¬ïÈ?ªòú°ğ¶ª¹ªëªÈ?ßæª¹ªë«¤«Ù«ó«ÈªÇª¹¡£
		\param clientInfo ïÈ?ª¬ú°ğ¶ªµªìª¿«¯«é«¤«¢«ó«ÈªÎï×ÜÃªÇª¹¡£
		\param errorInfo ïÈ?ªÎú°ğ¶ªµªìª¿«¯«é«¤«¢«ó«ÈªÎïÈ?ú°ğ¶ï×ÜÃªÇª¹¡£ 
		ErrorInfo.m_type ö·ªÏïÈ?ú°ğ¶ªÎ?êÕªò¡¢ErrorInfo¡£
		ßÙª·ª¯ªÏ¡¢ErrorInfoªÎ«Ø«ë«×ªòª´?ğÎª¯ªÀªµª¤¡£
		\param comment «¯«é«¤«¢«ó«Èª¬ CNetClient.Disconnect ªÎ«Ñ«é«á?«¿?«³«á«ó«Èªò÷×ª¸áêªéªìª¿Ùşí®ÖªªÇª¹¡£
		\~
		*/
		virtual void OnClientLeave(CNetClientInfo *clientInfo, ErrorInfo *errorinfo, const ByteArray& comment) = 0;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®°¡ ²÷°åÀ» ¶§ Äİ¹é µË´Ï´Ù.
		ÇØ´ç ÀÌº¥Æ®°¡ Äİ¹éÀÌ µÈ µÚ, Àç Á¢¼ÓÀÌ ÀÌ·ç¾îÁöÁö ¾ÊÀ¸¸é
		OnClientLeave °¡ Äİ¹é µË´Ï´Ù.
		(ÇØ´ç ÇÔ¼ö´Â NetClient ÀÇ  NetConnectionParam.m_enableAutoConnectionRecovery °¡ true ·Î ¼³Á¤ µÇ¾î¾ß ÇÕ´Ï´Ù.)

		\param args ¿¬°áÀÌ ²÷±ä Å¬¶óÀÌ¾ğÆ®ÀÇ Á¤º¸¸¦ ´ã°í ÀÖ½À´Ï´Ù.

		\~english
		A callback occurs when the client is disconnected.
		A callback occurs for OnClientLeave if reconnection does not occur.
		(The particular function shall have NetConnectionParam.m_enableAutoConnectionRecovery of NetClient as ¡°True¡±)

		\param ars It contains information on a disconnected client.

		\~chinese
		??ËÔ?Ó®ñé??üŞ?
		ßÓ?ŞÀËìüŞ?ì¤ı¨£¬åıÍıñìãæ?ïÈÜôÒö??? OnClientLeave£¨ËÔ?Ó®??£©??ú¼üŞ?¡£
		£¨ßÓ?ùŞ? NetClient£¨??ËÔ?Ó®£©îÜ NetConnectionParam.m_enableAutoConnectionRecovery£¨???ïÈïïßí_Òö?üá?í»??ïÈ£©???ïÒ? true£¨ñ×?ò¢£©

		\param args(?Õá£©?ïÈñé?îÜËÔ?Ó®ßÓ?ãáãÓ

		\~japanese
		«¯«é«¤«¢«ó«Èª¬ï·?ªµªìª¿ªÈª­ªË«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		ª½ªÎ«¤«Ù«ó«Èª¬«³?«ë«Ğ«Ã«¯ªµªìª¿ı­¡¢î¢ïÈ?ª¬ú¼ªïªìªÊª¤íŞùêªÏ
		OnClientLeaveª¬«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		(ª½ªÎ??ªÏNetClientªÎNetConnectionParam.m_enableAutoConnectionRecoveryªòtrueªËàâïÒª¹ªëù±é©ª¬ª¢ªêªŞª¹¡£)

		\param argsïÈ?ª¬ï·?ªµªìª¿«¯«é«¤«¢«ó«ÈªÎï×ÜÃªòùßªóªÇª¤ªŞª¹¡£

		\~
		*/
		virtual void OnClientOffline(CRemoteOfflineEventArgs& /*args*/) {}

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®°¡ ²÷±ä µÚ Àç Á¢¼Ó µÇ¾úÀ» ¶§ Äİ¹é µË´Ï´Ù.
		(ÇØ´ç ÇÔ¼ö´Â NetClient ÀÇ  NetConnectionParam.m_enableAutoConnectionRecovery °¡ true ·Î ¼³Á¤ µÇ¾î¾ß ÇÕ´Ï´Ù.)

		\param args Àç ¿¬°áÀÌ µÈ Å¬¶óÀÌ¾ğÆ®ÀÇ Á¤º¸¸¦ ´ã°í ÀÖ½À´Ï´Ù.

		\~english
		A callback occurs when the client is disconnected and then reconnected.
		(The particular function shall have NetConnectionParam.m_enableAutoConnectionRecovery of NetClient as ¡°True¡±)

		\param args It contains information on a reconnected client.

		\~chinese
		ËÔ?Ó®ñé?ı¨ñìãæ?ïÈ??ú¼üŞ?
		£¨ßÓ?ùŞ? NetClient£¨??ËÔ?Ó®£©îÜ NetConnectionParam.m_enableAutoConnectionRecovery£¨???ïÈïïßí_Òö?üá?í»??ïÈ£©???ïÒ? true£¨ñ×?ò¢£©

		\param args(?Õá£©ñìãæ?ïÈîÜËÔ?Ó®îÜßÓ?ãáãÓ

		\~japanese
		«¯«é«¤«¢«ó«Èª¬ï·?ªµªìª¿ı­¡¢î¢ïÈ?ª·ª¿ªÈª­ªË«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		(ª½ªÎ??ªÏNetClientªÎNetConnectionParam.m_enableAutoConnectionRecoveryªòtrueªËàâïÒª¹ªëù±é©ª¬ª¢ªêªŞª¹¡£)

		\param argsî¢ïÈ?ª¬ú¼ªïªìª¿«¯«é«¤«¢«ó«ÈªÎï×ÜÃªòùßªóªÇª¤ªŞª¹¡£
		\~
		*/
		virtual void OnClientOnline(CRemoteOnlineEventArgs& /*args*/) {}


		/** 
		\~korean
		Å¬¶óÀÌ¾ğÆ®°¡ ¼­¹ö·Î Ã³À½ ¿¬°áÀ» ½ÃµµÇÏ¸é Äİ¹éµÇ´Â ÀÌº¥Æ®
		- ÀÌ ÀÌº¥Æ®¿¡¼­´Â ¼­¹ö°¡ Å¬¶óÀÇ ¿¬°á ½Ãµµ¸¦ ¼ö¿ëÇÒ °ÍÀÎÁö °ÅÀıÇÒ °ÍÀÎÁö¸¦ °áÁ¤ÇÑ´Ù.
		¸¸¾à °ÅÀıÇÒ °æ¿ì Å¬¶óÀÌ¾ğÆ®´Â ¼­¹ö¿ÍÀÇ ¿¬°áÀÌ ½ÇÆĞÇÏ¸ç Å¬¶óÀÌ¾ğÆ®´Â
		ErrorType_NotifyServerDeniedConnection ¸¦ ¹Ş°Ô µÈ´Ù.
		¸¸¾à ¼ö¿ëÇÒ °æ¿ì Å¬¶óÀÌ¾ğÆ®´Â ¼­¹ö¿ÍÀÇ ¿¬°áÀÌ ¼º°øÇÏ°Ô µÇ¸ç Å¬¶óÀÌ¾ğÆ®´Â »õ HostID ¸¦
		ÇÒ´ç¹Ş°Ô µÈ´Ù. ÀÌ¶§ ¼­¹ö´Â OnClientJoin ÀÌº¥Æ®°¡ Äİ¹éµÈ´Ù.

		ÁÖÀÇ»çÇ×
		- Àı´ë! ¿©±â¿¡¼­ À¯ÀúÀÇ ·Î±×¿Â Á¤º¸(¾ÆÀÌµğ,ºñ¹Ğ¹øÈ£)¸¦ ÁÖ°í¹ŞÁö ¸»¾Æ¾ß ÇÑ´Ù.
		¿Ö³ÄÇÏ¸é ¿©±â¼­ Å¬¶óÀÌ¾ğÆ®°¡ ¼­¹ö·Î º¸³»´Â Ä¿½ºÅÒ µ¥ÀÌÅÍ´Â ºñ ¾ÏÈ£È­µÇ¾î ÀÖ±â
		¶§¹®ÀÌ´Ù.

		\param clientAddr Å¬¶óÀÌ¾ğÆ®ÀÇ ÀÎÅÍ³İ ÁÖ¼Ò
		\param userDataFromClient Å¬¶óÀÌ¾ğÆ®¿¡¼­ º¸³½ Ä¿½ºÅÒ µ¥ÀÌÅÍ. ÀÌ °ªÀº Å¬¶óÀÌ¾ğÆ®¿¡¼­ ¼­¹ö·Î ¿¬°á½Ã
		³Ö¾ú´ø ÆÄ¶ó¸ŞÅÍ CNetConnectionParam::m_userData ¿¡¼­ ³Ö¾ú´ø °ªÀÌ´Ù.
		\param reply ÀÌ ÀÌº¥Æ® Äİ¹é¿¡¼­ ÀÌ ÇÊµå¿¡ °ªÀ» Ã¤¿ì¸é Å¬¶óÀÌ¾ğÆ®´Â ¼­¹ö¿ÍÀÇ ¿¬°á °á°ú
		INetClientEvent::OnJoinServerComplete ¿¡¼­ ¹Ş°Ô µÈ´Ù.
		\return Å¬¶óÀÌ¾ğÆ®·ÎºÎÅÍÀÇ ¿¬°áÀ» ¼ö¿ëÇÒ °ÍÀÌ¶ó¸é ÀÌ ÇÔ¼ö´Â true¸¦ ¸®ÅÏÇÏ¸é µÈ´Ù. 

		\~english
		 Event called back when client attempts to connect to server for the first time
		- This event is where to decide if server accepts the attempt or not
		If refused then client fails to connect to server and client receives ErrorType_NotifyServerDeniedConnection.
		If accepted then client succeeds to connect to server and a new HostID will be allocated to client.
   		This is when OnClientJoin event is called back to server

		Note
		- NEVER! to send/receive user logon info(user account name and/or password) in here.
	 	  That is because the custom data from cliet to server is not encrypted.

		\param clientAddr Internet address of client
		\param userDataFromClient The custom data from client
					    This value is the value that was entered at parameter CNetConnectionParam::m_userData when client was connected to server.
		\param reply If this event callback fills a value to this field then client will receive the result of connection to server from INetClientEvent::OnJoinServerComplete.
		\return If to accept the connection reqeust from client then this function should return true.

		\~chinese
		èÌÊ«âÏó­???ïÈÜ×?Ğï?üŞ?îÜevent¡£
		- î¤ó®event?ïÒÜ×?Ğïé»?èÌÊ«îÜ???ïÈ?ãÀËŞ?¡£
		åıÍıËŞ?îÜ?£¬èÌÊ«?Ü×?ĞïîÜ?ïÈ?ã÷?£¬èÌÊ«?â¥ÓğErrorType_NotifyServerDeniedConnection¡£
		åıÍıâ¥?îÜ?£¬èÌÊ«?Ü×?ĞïîÜ?ïÈ?à÷Íí£¬èÌÊ«?İÂÛÕÓğãæîÜHost ID¡£??ı¦Ü×?ĞïüŞ?OnClientJoin event¡£

		ñ¼ëòŞÀßÚ
		- ??£¡î¤?×ìÜôÒöêó?éÄ?îÜÔô?ãáãÓ£¨??£¬ÚË?£©îÜ?èÙ¡£
		ì×?î¤?×ìèÌÊ«èÙÜ×?Ğï?áêîÜcustom?ËßãÀŞªÊ¥ÚËîÜ¡£

		\param clientAddr èÌÊ«îÜû»??ò¢ò£¡£
		\param userDataFromClient èÌÊ«?áêîÜcustom?Ëß¡£???ãÀ?èÌÊ«?ïÈÓğÜ×?ĞïîÜ?ı¦?ìıîÜî¤?? CNetConnectionParam::m_userData%?ìıîÜ?¡£
		\param reply åıÍıî¤eventîÜüŞ?ñé?õö???æ´îÜ?îÜ?£¬èÌÊ«?Ü×?ĞïîÜ?ïÈ?Íı?INetClientEvent::OnJoinServerComplete ïÈâ¥¡£
		\return é©â¥??èÌÊ«îÜ?ïÈ?£¬÷êó®ùŞ?Ú÷üŞtrue?Ê¦¡£

		\~japanese
		«¯«é«¤«¢«ó«Èª¬«µ?«Ğ?ªØôøªáªÆïÈ?ªòãËª¹ªÈ«³?«ë«Ğ«Ã«¯ªµªìªë«¤«Ù«ó«ÈªÇª¹¡£
		- ª³ªÎ«¤«Ù«ó«ÈªÇªÏ«µ?«Ğ?ª¬«¯«é«¤«¢«ó«ÈªÎïÈ?ªòáôª±ìıªìªëª«ËŞï¾ª¹ªëª«ªòÌ½ïÒª·ªŞª¹¡£
		ªâª·¡¢ËŞï¾ª¹ªëíŞùê¡¢«¯«é«¤«¢«ó«ÈªÏ«µ?«Ğ?ªÈªÎïÈ?ªËã÷ø¨ª·ªÆ¡¢«¯«é«¤«¢«ó«ÈªÏ
		ErrorType_NotifyServerDeniedConnection ªòáôª±ªëªèª¦ªËªÊªêªŞª¹¡£
		ªâª·¡¢áôª±ìıªìªëíŞùê¡¢«¯«é«¤«¢«ó«ÈªÏ«µ?«Ğ?ªÈªÎïÈ?ªËà÷Ííª·ªÆ¡¢«¯«é«¤«¢«ó«ÈªÏãæª·ª¤HostIDªòùÜªê?ªÆªÆªâªéª¦ª³ªÈªËªÊªêªŞª¹¡£ª³ªÎãÁ¡¢«µ?«Ğ?ªÏOnClientJoin«¤«Ù«ó«Èª¬«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£

		ª´ñ¼ëòŞÀú£
		- ï¾?¡¢ª³ª³ªÇ«æ?«¶?ªÎ«í«°«ª«óï×ÜÃ(ID¡¢«Ñ«¹«ï?«É)ªòªäªêö¢ªêª·ªÆªÏª¤ª±ªŞª»ªó¡£
		ªÊª¼ªÊªé¡¢ª³ª³ªÇ«¯«é«¤«¢«ó«Èª¬«µ?«Ğ?ªØáêªë«««¹«¿«à«Ç?«¿ªÏŞªäŞ?ûùªµªìªÆª¤ªëª«ªéªÇª¹¡£

		\param clientAddr «¯«é«¤«¢«ó«ÈªÎ«¤«ó«¿?«Í«Ã«È«¢«É«ì«¹
		\param userDataFromClient «¯«é«¤«¢«ó«Èª«ªéáêªÃª¿«««¹«¿«à«Ç?«¿¡£ª³ªÎö·ªÏ«¯«é«¤«¢«ó«Èªèªê«µ?«Ğ?ªØïÈ?ãÁªËìıªìª¿«Ñ«é«á?«¿?ªÎCNetConnectionParam::m_userDataªÇìıªìª¿ö·ªÇª¹¡£
		\param reply ª³ªÎ«¤«Ù«ó«È«³?«ë«Ğ«Ã«¯ªÇª³ªÎ«Õ«£?«ë«ÉªËö·ªòìıªìªëªÈ¡¢«¯«é«¤«¢«ó«ÈªÏ«µ?«Ğ?ªÈªÎïÈ?Ì¿Íı¡¢INetClientEvent::OnJoinServerCompleteªÇáôª±ªëªèª¦ªËªÊªêªŞª¹¡£
		\return «¯«é«¤«¢«ó«Èª«ªéªÎïÈ?ªòáôª±ìıªìªëªÊªé¡¢ª³ªÎ??ªÏtrueªò«ê«¿?«óª·ªŞª¹¡£ 
		\~
		*/
		virtual bool OnConnectionRequest(AddrPort /*clientAddr*/, ByteArray& /*userDataFromClient*/, ByteArray& /*reply*/) {
			return true;
		}

		/** 
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> ¿¡ »õ ¸â¹ö°¡ Ãß°¡µÇ´Â °úÁ¤ÀÌ ¸ğµç Å¬¶óÀÌ¾ğÆ®¿¡¼­µµ ¿Ï·áµÇ¸é ¹ß»ıÇÏ´Â ÀÌº¥Æ®ÀÔ´Ï´Ù.
		- ¸¸¾à ±×·ì G¿¡ ±â ¸â¹ö M1,M2,M3°¡ ÀÖ´Ù°í °¡Á¤ÇÒ °æ¿ì ½Å±Ô ¸â¹ö M4¸¦ ³Ö´Â´Ù°í ÇÕ½Ã´Ù.
		ÀÌ¶§ JoinP2PGroup()¿¡ ÀÇÇØ M4°¡ Ãß°¡µÇ´õ¶óµµ Áï½Ã ¿Ï·áµÇ´Â °ÍÀº ¾Æ´Õ´Ï´Ù. °¢ Å¬¶óÀÌ¾ğÆ®
		M1,M2,M3¿¡¼­´Â ¾ÆÁ÷ 'M4ÀÇ Ãß°¡µÇ¾úÀ½' º¸°í(INetClientEvent.OnP2PMemberJoin)¸¦ ¹ŞÁö ¾Ê¾Ò°í M4¿¡¼­µµ M1,M2,M3,M4 ¸ğµÎ¿¡ ´ëÇÑ 'Ãß°¡µÇ¾úÀ½ º¸°í'(INetClientEvent.OnP2PMemberJoin)¸¦ ¹ŞÁö ¾Ê¾Ò±â ¶§¹®ÀÔ´Ï´Ù.
		ÀÌ ÀÌº¥Æ®´Â M4¿¡ ´ëÇØ, M1,M2,M3,M4¿¡¼­ ÀÌµéÀ» ¸ğµÎ ¹ŞÀº °ÍÀ» ¼­¹ö¿¡¼­ È®ÀÎÇÑ ÈÄ¿¡¾ß ¹ß»ıµË´Ï´Ù.
		- CreateP2PGroup¿¡ ´ëÇØ¼­µµ ¸¶Âù°¡Áö·Î ÀÌ ÀÌº¥Æ®°¡ ¹ß»ıÇÕ´Ï´Ù. 
		
		\param groupHostID \ref ±×·ìÀÇ HostID
		\param memberHostID ±×·ì ¸â¹öÀÇ HostID
		\param result ErrorType_Ok ÀÌ¸é ¼º°øÀûÀ¸·Î Ãß°¡µÆÀ½À» ÀÇ¹ÌÇÏ¸ç,ErrorType_AlreadyExists ÀÌ¸é ÀÌ¹Ì ±×·ì³» µé¾î°¡ÀÖ´Â ¸â¹öÀÓÀ» ÀÇ¹Ì ÇÕ´Ï´Ù.(½ÇÆĞ Çß´Ù´Â ÀÇ¹Ì´Â ¾Æ´Ô)
		±×¿Ü ´Ù¸¥ °ªÀÌ¸é Ãß°¡°¡ ½ÇÆĞÇßÀ½À» ÀÇ¹ÌÇÕ´Ï´Ù. 
		¿¹¸¦ µé¾î CNetServer.CreateP2PGroup È¤Àº CNetServer.JoinP2PGroup È£Ãâ ÈÄ¿¡ ÀÌ Äİ¹éÀÌ ÀÖ±â Àü¿¡
		CNetServer.LeaveP2PGroup È¤Àº CNetServer.DestroyP2PGroup ¸¦ È£Ãâ ÇÏ°Å³ª, ÇØ´ç Å¬¶óÀÌ¾ğÆ®°¡ µ¿½Ã¿¡ ¼­¹ö¿ÍÀÇ ¿¬°áÀ» ²÷°í ÀÖ´Â ÁßÀÌ¾ú´Ù¸é
		´Ù¸¥ °ªÀÌ ¿©±â¿¡ µé¾î°¥ ¼ö ÀÖ½À´Ï´Ù. 

		\~english
		The event that occurs when the process adding a new member to <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> is completed in all client
		- Assuming that there are existing member M1, M2 and M3 in group G and we try to add a new member M4.
		Even if M4 is added by JoinP2PGroup(), the process is not to be completed immediately.
		This is because each client M1, M2 and M3 did not yet receive the report(INetClientEvent.OnP2PMemberJoin) that 'M4 is added',
		and M4 did not yet receive the report(INetClientEvent.OnP2PMemberJoin) that M4 is added to M1, M2, M3 and M4. 
		This event, for M4, occurs only after server acknowledges that M1, M2, M3 and M4 received necesary info.
		- The event also occurs for CreateP2PGroup. 
		
		\param groupHostID HostId of \ref group
		\param memberHostID HostID of group member
		\param result If ErrorType_Ok then it means successfully added, if ErrorType_AlreadyExists then it is a member that already in group. (does not mean it falied to)
		If has other values then it means failed to add. 
		For an example,
		Case1. Calling CNetServer.LeaveP2PGroup or CNetServer.DestroyP2PGroup between the moment after calling CNetServer.CreateP2PGroup or CNetServer.JoinP2PGroup and the moment before this callback occurs, OR  
		Case2. the client was terminating its connection to server at the same time,
		For each case, an other value can enter here.

		\~chinese
		èÙ<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%ôÕÊ¥ãæà÷?îÜ?ïïî¤á¶êóèÌÊ«ñéå¥?áÖîÜ???ßæîÜevent¡£
		- åıÍıÊ£??G×ìêóê«?îÜà÷?M1¡¢M2¡¢M3£¬ôÕÊ¥ãæà÷?M4.
		???ŞÅù¬JoinP2PGroup()ôÕÊ¥M4£¬Üô?Ø¡?èÇ?¡£ì×?Øß?èÌÊ«M1,M2,M3 ??êóâ¥Óğ¡®M4îÜôÕÊ¥¡¯îÜ?Í±£¨INetClientEvent.OnP2PmemberJoin£©£¬î¤M4å¥?êóâ¥Óğ?M1¡¢M2¡¢M3¡¢M4á¶êóìÑîÜ¡®ì«ôÕÊ¥¡¯îÜ?Í±£¨INetClientEvent.OnP2PMemberJoin£©¡£
		ó®event?M4£¬î¤Ü×?Ğï??M1¡¢M2¡¢M3¡¢M4îïİ»ïÈâ¥ì¤ı¨î¦??ßæ¡£
		- å¥?CreateP2PGroup?ßæó®event¡£

		\param groupHostID \ref ?îÜHost ID¡£
		\param memberHostID ?à÷?îÜHost ID¡£
		\param result ErrorType_Ok îÜ?ëòÚ«ó·ôÕÊ¥à÷Íí£¬åıÍıãÀErrorType_AlreadyExistsîÜ?ëòÚ«ó·ì«ãÀ?ìı??îÜà÷?¡££¨ÜôãÀã÷?ÖõîÜëòŞÖ£©
		ó®èâåıôÕÊ¥Ğìöâ?îÜ?ëòÚ«ó·ã÷?¡£
		ÖÇåı£¬û¼Ğ£ CNetServer.CreateP2PGroup%ûäíº CNetServer.JoinP2PGroup%£¬ßÓ?èÌÊ«ÔÒ?ñé??Ü×?ĞïîÜ?ïÈ?ı¦£¬Ğìöâ?Ê¦ì¤?ìı?×ì¡£

		\~japanese
		\ref p2p_groupªËãæª·ª¤«á«ó«Ğ?ª¬õÚÊ¥ªµªìªëÎ¦ïïª¬îïªÆªÎ«¯«é«¤«¢«ó«ÈªÇªâèÇÖõªµªìªëªÈ?ßæª¹ªë«¤«Ù«ó«ÈªÇª¹¡£
		- ªâª·¡¢«°«ë?«×GªË?ğí«á«ó«Ğ?M1,M2,M3ª¬ª¤ªëªÈ?ïÒª¹ªëíŞùê¡¢ãæĞ®«á«ó«Ğ?M4ªòìıªìªëªÈª·ªŞª·ªçª¦¡£
		ª³ªÎãÁ¡¢JoinP2PGroup()ªËªèªÃªÆM4ª¬õÚÊ¥ªµªìªëªÈª·ªÆªâòÁªÁªËèÇÖõªµªìªëªïª±ªÇªÏª¢ªêªŞª»ªó¡£ÊÀ«¯«é«¤«¢«ó«ÈM1,M2,M3ªÇªÏªŞªÀ¡¸M4ª¬õÚÊ¥ªµªìª¿¡¹ªÈª¤ª¦ÜÃÍ±(INetClientEvent.OnP2PMemberJoin)ªòáôª±ªÆª¤ªÊª¯¡¢M4ªÇªâM1,M2,M3,M4ªÎîïªÆªË?ª¹ªë¡¸õÚÊ¥ªµªìª¿¡¹ªÈª¤ª¦ÜÃÍ±(INetClientEvent.OnP2PMemberJoin)ªòáôª±ªÆª¤ªÊª¤ª«ªéªÇª¹¡£
		ª³ªÎ«¤«Ù«ó«ÈªÏM4ªË?ª·ªÆ¡¢M1,M2,M3,M4ªÇª³ªìªéªòîïªÆáôª±ª¿ªâªÎªò«µ?«Ğ?ªÇü¬ìãª·ªÆª«ªé?ßæªµªìªŞª¹¡£
		- CreateP2PGroupªË?ª·ªÆªâÔÒ?ªËª³ªÎ«¤«Ù«ó«Èª¬?ßæª·ªŞª¹¡£

		\param groupHostID \ref «°«ë?«×ªÎ HostID
		\param memberHostID «°«ë?«×«á«ó«Ğ?ªÎ HostID
		\param result ErrorType_Ok ªÇª¢ªìªĞõÚÊ¥ªËà÷Ííª·ª¿ª³ªÈªòëòÚ«ª·ªÆ¡¢ErrorType_AlreadyExistsªÇª¢ªìªĞ?ªË«°«ë?«×?ªËìıªÃªÆª¤ªë«á«ó«Ğ?ªÇª¢ªëª³ªÈªòëòÚ«ª·ªŞª¹¡£(ã÷ø¨ª·ª¿ªÈª¤ª¦ëòÚ«ªÇªÏª¢ªêªŞª»ªó)
		ª½ªÎèâªÎö·ªÇª¢ªìªĞõÚÊ¥ªËã÷ø¨ª·ª¿ª³ªÈªòëòÚ«ª·ªŞª¹¡£
		ÖÇª¨ªĞ¡¢CNetServer.CreateP2PGroup ªŞª¿ªÏCNetServer.JoinP2PGroupªòû¼ªÓõóª·ª¿ı­¡¢ª³ªÎ«³?«ë«Ğ«Ã«¯ª¬ª¢ªëîñªË¡¢CNetServer.LeaveP2PGroupªŞª¿ªÏCNetServer.DestroyP2PGroupªòû¼ªÓõóª¹ª«¡¢ú±?«¯«é«¤«¢«ó«Èª¬ÔÒãÁªË«µ?«Ğ?ªÈªÎïÈ?ªòï·ªÃªÆª¤ªëÊàªÇª·ª¿ªé¡¢öâªÎö·ª¬ª³ª³ªËìıªëª³ªÈª¬ªÇª­ªŞª¹¡£ 

		\~
		*/
		virtual void OnP2PGroupJoinMemberAckComplete(HostID groupHostID, HostID memberHostID, ErrorType result) = 0;

		/** 
		\~korean
		user work thread poolÀÇ ½º·¹µå°¡ ½ÃÀÛÇÒ ¶§ ÀÌ ¸Ş¼­µå°¡ È£ÃâµÈ´Ù.

		\~english
		This method is called when thread of user work thread pool starts.

		\~chinese
		user work thread poolîÜ?ïï?ã·îÜ?ı¦£¬ó®Û°Ûö?ù¬û¼Ğ£¡£

		\~japanese
		user work thread poolªÎ«¹«ì«Ã«Éª¬ËÒã·ª¹ªëãÁªËª³ªÎ«á«½«Ã«Éª¬û¼ªÓõóªµªìªŞª¹¡£
		\~
		*/
		virtual void OnUserWorkerThreadBegin() = 0;

		/** 
		\~korean
		user work thread poolÀÇ ½º·¹µå°¡ Á¾·áÇÒ ¶§ ÀÌ ¸Ş¼­µå°¡ È£ÃâµÈ´Ù.

		\~english
		This method is called when thread of user work thread pool terminates.

		\~chinese
		user work thread poolîÜ?ïï?ò­îÜ?ı¦£¬ó®Û°Ûö?ù¬û¼Ğ£¡£

		\~japanese
		user work thread poolªÎ«¹«ì«Ã«Éª¬ËÒã·ª¹ªëãÁªËª³ªÎ«á«½«Ã«Éª¬û¼ªÓõóªµªìªŞª¹¡£
		\~
		*/
		virtual void OnUserWorkerThreadEnd() = 0;

		/** 
		\~korean
		Å¬¶óÀÌ¾ğÆ®°¡ ÇØÅ·´çÇß´Ù´Â ÀÇÈ¤ÀÌ ÀÖÀ» ¶§ ÀÌ ¸Ş¼­µå°¡ È£ÃâµÈ´Ù.
		\param clinetID ÀÇ½ÉµÇ´Â clientÀÇ HostID
		\param hackType ÇØÅ·ÀÇ Á¾·ù 

		\~english TODO:translate needed.
		This method is called when there is suspicion that the client has been hacked. 
		\param clinetID HostID of the client under suspicion
		\param hackType Type of hacking. 

		\~chinese
		ë÷ûãèÌÊ«ù¬ıÙîÜ?ı¦£¬ó®Û°Ûöù¬û¼Ğ£¡£
		\param clinetID Ê¦ë÷îÜclientîÜHost ID¡£
		\param hackType ıÙËÔ??¡£

		\~japanese
		«¯«é«¤«¢«ó«Èª¬«Ï«Ã«­«ó«°ªµªìª¿ªÈª¤ª¦ë÷ª¤ª¬ª¢ªëãÁªËª³ªÎ«á«½«Ã«Éª¬û¼ªÓõóªµªìªŞª¹¡£
		\param clinetID ë÷ªïªìªëclientªÎHostID
		\param hackType «Ï«Ã«­«ó«°ªÎğú×¾
		\~
		*/
		virtual void OnClientHackSuspected(HostID /*clientID*/,HackType /*hackType*/) {}

		/** 
		\~korean
		P2P groupÀÌ Á¦°ÅµÈ Á÷ÈÄ ÀÌ ¸Ş¼­µå°¡ È£ÃâµË´Ï´Ù.
		- P2P groupÀÌ Á¦°ÅµÇ´Â Á¶°ÇÀº Proud.CNetServer.DestroyP2PGroup ¸¦ È£ÃâÇÏ°Å³ª P2P group ¿¡ ¼Ò¼ÓµÈ ¸¶Áö¸· ¸â¹ö°¡
		¼­¹ö¿ÍÀÇ Á¢¼ÓÀ» Á¾·áÇÒ ¶§ µîÀÔ´Ï´Ù.

		\~english
		This method is called right after P2P group is removed. 
		- The condition P2P froup is removed is EITHER calling Proud.CNetServer.DestroyP2PGroup OR the last member of P2P group terminates its connection to server.

		\~chinese
		P2P groupù¬?ğ¶ñıı¨£¬ó®Û°Ûöù¬û¼Ğ£¡£
		- P2P groupù¬?ğ¶îÜ?ËìãÀû¼Ğ£ Proud.CNetServer.DestroyP2PGroup%ûäíº?á¶?éÍP2P groupîÜõÌı¨à÷?îÜ?ïÈ?ò­ÔõîÜ?ı¦¡£

		\~japanese
		P2P groupª¬ğ¶ËÛªµªìª¿òÁı­ªËª³ªÎ«á«½«Ã«Éª¬û¼ªÓõóªµªìªŞª¹¡£
		- P2P groupª¬ğ¶ËÛªµªìªë?ËìªÏ¡¢Proud.CNetServer.DestroyP2PGroupªòû¼ªÓõóª¹ª«¡¢P2P groupªËá¶?ªµªìª¿õÌı­ªÎ«á«ó«Ğ?ª¬«µ?«Ğ?ªÈªÎïÈ?ªòğûÖõª¹ªëãÁªÊªÉªÇª¹¡£
		\~
		*/
		virtual void OnP2PGroupRemoved(HostID /*groupID*/) {}

		/** 
		\~korean
		RMI È£Ãâ ¶Ç´Â ÀÌº¥Æ® ¹ß»ıÀ¸·Î ÀÎÇØ user worker¿¡¼­ callbackÀÌ È£ÃâµÇ±â Á÷Àü¿¡ È£ÃâµË´Ï´Ù.
		ÇÁ·Î±×·¥ ½ÇÇà ¼º´É ÃøÁ¤À» À§ÇØ »ç¿ëÇÏ¼Åµµ µË´Ï´Ù.

		\~english
		Called right before calling callback by either RMI calling or user worker due to event occur. Also can be used for performance test purpose.

		\~chinese
		ì×?RMIû¼õóûäíºeventîÜ?ßæ£¬î¤user workerñécallbackû¼Ğ£ñıîñû¼Ğ£¡£
		å¥Ê¦ì¤î¤?ïÒïïßí?ú¼àõÒö?ŞÅéÄ¡£

		\~japanese
		RMIû¼ªÓõóª·ªŞª¿ªÏ«¤«Ù«ó«ÈªÎ?ßæªËªèªÃªÆuser workerªÇ«³?«ë«Ğ«Ã«¯ª¬û¼ªÓõóªµªìªëòÁîñªËû¼ªÓõóªµªìªŞª¹¡£
		«×«í«°«é«àªÎ?ú¼àõÒöö´ïÒªÎª¿ªáªËŞÅªÃªÆªâÕŞª¤ªÇª¹¡£
		\~
		*/
		//virtual void OnUserWorkerThreadCallbackBegin(CUserWorkerThreadCallbackContext* ctx){}
		/** 
		\~korean
		RMI È£Ãâ ¶Ç´Â ÀÌº¥Æ® ¹ß»ıÀ¸·Î ÀÎÇØ user worker¿¡¼­ callbackÀÌ ¸®ÅÏÇÑ Á÷ÈÄ¿¡ È£ÃâµË´Ï´Ù.
		ÇÁ·Î±×·¥ ½ÇÇà ¼º´É ÃøÁ¤À» À§ÇØ »ç¿ëÇÏ¼Åµµ µË´Ï´Ù.

		\~english
		Called right before calling callback by either RMI calling or user worker due to event occur. Also can be used for performance test purpose.

		\~chinese
		ì×?RMIû¼õóûäíºeventîÜ?ßæ£¬î¤user workerñécallbackÚ÷üŞñıı¨û¼Ğ£¡£
		å¥Ê¦ì¤?Öõïïßí?ú¼àõÒö?ïÒì»ŞÅéÄ¡£

		\~japanese
		RMIû¼ªÓõóª·ªŞª¿ªÏ«¤«Ù«ó«ÈªÎ?ßæªËªèªÃªÆuser workerªÇ«³?«ë«Ğ«Ã«¯ª¬«ê«¿?«óª·ª¿òÁı­ªËû¼ªÓõóªµªìªŞª¹¡£
		«×«í«°«é«àªÎ?ú¼àõÒöö´ïÒªÎª¿ªáªËŞÅªÃªÆªâÕŞª¤ªÇª¹¡£
		\~
		*/
		//virtual void OnUserWorkerThreadCallbackEnd(CUserWorkerThreadCallbackContext* ctx){}

		/** 
		\~korean
		ÀÏÁ¤ ½Ã°£¸¶´Ù user worker thread pool¿¡¼­ Äİ¹éµÇ´Â ÇÔ¼öÀÔ´Ï´Ù.  <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_timer_callback" >¼­¹ö¿¡¼­ Å¸ÀÌ¸Ó ·çÇÁ RMI ÀÌº¥Æ® Ã³¸®ÇÏ±â</a>±â´ÉÀÔ´Ï´Ù. 		
		\param context CStartServerParameter.m_timerCallbackContext ¿¡¼­ ÀÔ·ÂµÈ °ª°ú µ¿ÀÏÇÕ´Ï´Ù.

		\~english
		Function called back at user worker thread pool periodically. This is a <a target="_blank" href="http://guide.nettention.com/cpp_en#server_timer_callback" >Managing Timer loop RMI Event from server</a> function.		
		\param context same as the value entered at CStartLanServerParameter.m_timerCallbackContext

		\~chinese
		ØßÌ°ìéÓ«??î¤user worker thread poolüŞ?îÜùŞ?¡£<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_timer_callback" >î¤Ü×?Ğï?×âTimer Loop£¬RMI£¬Event</a> ÍíÒö¡£
		\param context ?î¤ CStartLanServerParameter.m_timerCallbackContext%?ìıîÜ?ßÓÔÒ¡£

		\~japanese
		á¶ïÒãÁÊàª´ªÈªËuser worker thread poolªÇ«³?«ë«Ğ«Ã«¯ªµªìªë??ªÇª¹¡£\ref server_timer_callback Ñ¦ÒöªÇª¹¡£ 
		\param context CStartServerParameter.m_timerCallbackContext ªÇìıÕôªµªìª¿ö·ªÈÔÒª¸ªÇª¹¡£
		\~
		*/
		//virtual void OnTick(void* context){}

	};

	/** 
	\~korean
	½º·¹µå °ü·Ã Äİ¹é ÀÎÀÚ ±¸Á¶Ã¼ÀÔ´Ï´Ù.
	¾ÆÁ÷Àº Á¦°øµÇ´Â º¯¼ö°¡ ¾ø½À´Ï´Ù¸¸, ÇÏÀ§È£È¯¼ºÀ» À§ÇØ ¹Ì¸® ÁØºñµÇ¾î ÀÖÀ» »ÓÀÔ´Ï´Ù.

	\~english
	Callback factor structure that related with thread
	It does not supply any variable yet. It exists for lower compatibility.

	\~chinese
	ãÀ?éÍ?ïïüŞ?ì×í­?ğã?¡£
	?î¤??êóù¬ğ«ÍêîÜ??£¬ñşãÀ?Öõù»?ÌÂé»àõ£¬ŞÀà»ñ×?Öõì»ì«¡£

	\~japanese
	«¹«ì«Ã«É?Ö§«³?«ë«Ğ«Ã«¯ì×í­Ï°ğã?ªÇª¹¡£
	ªŞªÀğ«ÍêªµªìªÊª¤??ªÏª¢ªêªŞª»ªóª¬¡¢ù»êÈû»üµàõªÎª¿ªáªËîñªâªÃªÆñŞİáªµªìªÆª¤ªëªÀª±ªÇª¹¡£
	\~
	*/
// 	class CUserWorkerThreadCallbackContext
// 	{
// 	};
	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
