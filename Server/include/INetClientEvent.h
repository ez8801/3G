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
#include "acr.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	/**
	\~korean
	CNetClient ¿ë event sink

	¿ë¹ı
	- ÀÌ °´Ã¼¸¦ ±¸ÇöÇÑ´Ù.
	- CNetClient ¿¡ ÆÄ¶ó¸ŞÅÍ·Î Àü´ŞÇÑ´Ù.

	\~english
	Event sink for CNetClient

	Usage
	- Realize this object.
	- Passed as a parameter to CNetClient

	\~chinese
	CNetClient éÄevent sink

	éÄÛö
	- ??ó®?ßÚ¡£
	- éÄ???áê? CNetClient%¡£

	\~japanese
	CNetClient éÄ event sink

	éÄÛö
	- ª³ªÎ«ª«Ö«¸«§«¯«Èªò?úŞª·ªŞª¹¡£
	- CNetClientªË«Ñ«é«á?«¿?ªÇ?Ó¹ª·ªŞª¹¡£
	\~
	*/
	class INetClientEvent : public INetCoreEvent
	{
	public:
		INetClientEvent() {}
		virtual ~INetClientEvent() {}

		/**
		\~korean
		CNetServer.Connect ¸¦ ÅëÇØ ¼­¹ö ¿¬°áÀ» ½ÃµµÇÑ °á°ú°¡ µµÂøÇÏ¸é ¹ß»ıÇÏ´Â ÀÌº¥Æ®ÀÌ´Ù.

		\param info ¼­¹ö ¿¬°á °á°ú¸¦ ´ÙÀ½ °´Ã¼. ¼­¹ö¿ÍÀÇ ¿¬°áÀÌ ¼º°øÇÑ °æ¿ì ErrorInfo.m_type ÀÌ success value¸¦ °®´Â´Ù.
		¼­¹ö¿ÍÀÇ ¿¬°áÀÌ ½ÇÆĞÇÑ °æ¿ì ÀÌ °ªÀ» ¿­¶÷ÇÏ¸é µÈ´Ù. ÀÚ¼¼ÇÑ °ÍÀº ErrorInfo Å¬·¡½º ¼³¸íÀ» Âü°í.
		\param replyFromServer ¼­¹ö·ÎºÎÅÍ ¹ŞÀº Ãß°¡ ¸Ş½ÃÁöÀÌ´Ù. ÀÌ °ªÀº
		INetServerEvent.OnConnectionRequest ¿¡¼­ º¸³½ °ªÀÌ´Ù.

		\~english
		Event that occurs after arrival of the result of attempt to connect to server through CNetServer.Connect

		\param info object that contains the result of connection to server. ErrorInfo.m_type has success value when it is successful.
		View this value when connection attempt to server failed. Please refer ErrorInfo class description.
		\param replyFromServer Additional message from server. This value is from INetServerEvent.OnConnectionRequest.

		\~chinese
		÷×? CNetServer.Connect%??Ü×?Ğï?ïÈîÜ?ÍıÓğ?îÜ??ßæîÜevent¡£

		\param info øĞùßÜ×?Ğï?ïÈîÜ?ÍıîÜ?ßÚ¡£?Ü×?ĞïîÜ?ïÈà÷ÍíîÜ?£¬ ErrorInfo.m_type%?êósuccess value¡£
		?Ü×?ĞïîÜ?ïÈã÷?îÜ?£¬?Ê×ó®??Ê¦¡£??îÜ??ÍÅErrorInfo??Ù¥¡£
		\param replyFromServer ?Ü×?ĞïïÈâ¥îÜİ¾Ê¥ãáãÓ¡£ó®?ãÀ? INetServerEvent.OnConnectionRequest%?áêîÜ?¡£

		\~japanese
		CNetServer.Connectªò÷×ª¸«µ?«Ğ?ïÈ?ªòãËª·ª¿Ì¿Íıª¬Óğó·ª¹ªëªÈ?ßæª¹ªë«¤«Ù«ó«ÈªÇª¹¡£

		\param info«µ?«Ğ?ïÈ?ªÎÌ¿Íıªòó­ªÎ«ª«Ö«¸«§«¯«È¡£«µ?«Ğ?ªÈªÎïÈ?ª¬à÷Ííª·ª¿íŞùê¡¢ErrorInfo.m_typeª¬success valueªòò¥ªÁªŞª¹¡£
		«µ?«Ğ?ªÈªÎïÈ?ªËã÷ø¨ª·ª¿íŞùê¡¢ª³ªÎö·ªò??ª¹ªìªĞÕŞª¤ªÇª¹¡£ßÙª·ª¯ªÏ¡¢ErrorInfo«¯«é«¹ªÎ?Ù¥ªòª´?ğÎª¯ªÀªµª¤¡£
		\param replyFromServer «µ?«Ğ?ª«ªéáôª±ª¿õÚÊ¥«á«Ã«»?«¸ªÇª¹¡£ª³ªÎö·ªÏ¡¢
		INetServerEvent.OnConnectionRequestªèªêáêªéªìª¿ö·ªÇª¹¡£ 
		\~
		*/
		virtual void OnJoinServerComplete(ErrorInfo *info, const ByteArray& replyFromServer) = 0;

		/**
		\~korean
		¼­¹ö ¿¬°á ÇØÁ¦½Ã ¹ß»ı ÀÌº¥Æ®ÀÔ´Ï´Ù.
		- Å¬¶óÀÌ¾ğÆ®¿¡¼­ ¸ÕÀú ¿¬°á ÇØÁ¦(Disconnect È£Ãâ)¸¦ ÇÑ °æ¿ì¿¡´Â ÀÌ ÀÌº¥Æ®°¡ ¹ß»ıÇÏÁö ¾Ê½À´Ï´Ù.
		±×·¯³ª, NetClient.FrameMove¸¦ È£ÃâÇÏ´Â ½º·¹µå°¡ NetClient.Disconnect ¶Ç´Â NetClient.Dispose¸¦ È£ÃâÇÏ´Â ½º·¹µå°¡ °°À¸¸é Äİ¹éµÉ ¼ö ÀÖ½À´Ï´Ù.
		\param errorInfo ¾î¶² ÀÌÀ¯·Î ¼­¹ö¿ÍÀÇ ¿¬°áÀÌ ÇØÁ¦µÇ¾ú´ÂÁö¸¦ ´ã°í ÀÖ½À´Ï´Ù. ÀÚ¼¼ÇÑ °ÍÀº ErrorInfo µµ¿ò¸»¿¡ ÀÖ½À´Ï´Ù.

		\~english
		Event that occurs when server connection is terminated
		- This event also occurs when client terminates the connection to server.
		However, it will be called back if the thread where NetClient.FrameMove is called and NetClient.Disconnect is called are same.
		\param errorInfo Contains the reason why the connection was terminated. Please refer ErrorInfo.

		\~chinese
		Ü×?Ğïú°ğ¶?ïÈ??ßæîÜŞÀËì¡£
		- èÌÊ«à»ú°ğ¶?ïÈîÜ£¨û¼Ğ£Disconnect£©?ı¦Üô??ßæ¡£
		However, it will be called back if the thread where NetClient.FrameMove is called and NetClient.Disconnect is called are same.
		\param errorInfo ??ó·?Ü×?ĞïîÜ?ïÈú°ğ¶îÜ×âë¦¡£??îÜî¤ErrorInfo?ğ¾×ì¡£

		\~japanese
		«µ?«Ğ?ïÈ?ªòú°ğ¶ãÁªË?ßæª¹ªë«¤«Ù«ó«ÈªÇª¹¡£
		- «¯«é«¤«¢«ó«ÈªÇà»ªËïÈ?ú°ğ¶(Disconnectû¼ªÓõóª·)ªòª·ª¿íŞùêªËªÏ¡¢ª³ªÎ«¤«Ù«ó«Èª¬?ßæª·ªŞª»ªó¡£
		ª·ª«ª·¡¢ NetClient.FrameMoveªòû¼ªÓõóª¹«¹«ì«Ã«Éª¬NetClient.DisconnectªŞª¿ªÏNetClient.Disposeªòû¼ªÓõóª¹«¹«ì«Ã«Éª¬ÔÒª¸ªÇª¢ªìªĞ«³?«ë«Ğ«Ã«¯ªµªìªëª³ªÈª¬ª¢ªêªŞª¹¡£
		\param errorInfo ù¼ª¬×âë¦ªÇ«µ?«Ğ?ªÈªÎïÈ?ª¬ú°ğ¶ªµªìª¿ªÎª«ªòò¥ªÃªÆª¤ªŞª¹¡£ßÙª·ª¯ªÏ¡¢ErrorInfoªÎ«Ø«ë«×ªËª¢ªêªŞª¹¡£
		\~
		*/
		virtual void OnLeaveServer(ErrorInfo *errorInfo) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> ÀÌ »ı¼ºµÇ°Å³ª P2P±×·ì¿¡ »õ ¸â¹ö°¡ Ãß°¡µÇ´Â °æ¿ì ÀÌ ¸Ş¼­µå°¡ Äİ¹éµË´Ï´Ù.
		·ÎÄÃ È£½ºÆ® ÀÚ½Å¿¡ ´ëÇØ¼­µµ ÀÌ°ÍÀÌ È£ÃâµË´Ï´Ù.

		¿¹¸¦ µé¾î Å¬¶óÀÌ¾ğÆ® A°¡ ÀÌ¹Ì µé¾î°¡ ÀÖ´Â ±×·ì G¿¡ B°¡ »õ·Î µé¾î¿À¸é
		A´Â (B,G)¸¦ ¹Ş°í, B´Â (A,G), (B,G)¸¦ ¹Ş°Ô µË´Ï´Ù.

		\param memberHostID ÀÚ±â ¶Ç´Â Å¸ peerÀÇ HostIDÀÔ´Ï´Ù.
		\param groupHostID P2P ±×·ìÀÇ HostIDÀÔ´Ï´Ù.
		\param memberCount Ã³¸®µÈ ÈÄ ¸â¹ö ¼ö ÀÔ´Ï´Ù.
		\param customField CNetServer.CreateP2PGroup ¶Ç´Â CNetServer.JoinP2PGroup ¿¡¼­ »ç¿ëÀÚ°¡ ÀÔ·ÂÇÑ Ä¿½ºÅÒ µ¥ÀÌÅÍ°¡ ¿©±â¿¡¼­ ±×´ë·Î Àü´ŞµË´Ï´Ù.

		\~english
		This method is to be called back either when <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> is created or when a new member is added to P2P group.
		Also called for local host iteself.

		For an example, if B enters into group G which already has client A in it, then A receives (B,G) and B recieves (A,G) and (B,G).
		\param memberHostID HostID of itself or other peer
		\param groupHostID HostID of P2P group
		\param memberCount The number of menebers after being processed
		\param customField The custom data entered by user via either CNetServer.CreateP2PGroup or CNetServer.JoinP2PGroup will be passed onto here as they are.

		\~chinese
		?ßæ<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%£¬ûäíºèÙP2P?ôÕÊ¥ãæà÷?îÜ?ı¦üŞ?ó®Û°Ûö¡£
		??å¥?Üâò¢ñ«ÏõÜâãóû¼Ğ£¡£

		ÖÇåı£¬B ?ìıèÌÊ«Aì«??ìıîÜ?GîÜ?£¬A â¥Óğ(B,G)£¬B â¥Óğ(A,G)£¬(B,G)¡£

		\param memberHostID í»ĞùûäíºĞìöâpeerîÜHostID¡£
		\param groupHostID P2P?îÜHostID¡£
		\param memberCount ù¬?×âı¨îÜà÷??¡£
		\param customField î¤ CNetServer.CreateP2PGroup%ûäíº CNetServer.JoinP2PGroup £¬éÄ??ìıîÜcustom?Ëß?åı?ò¢?áêò¸?×ìáê¡£

		\~japanese
		\ref p2p_groupª¬ßæà÷ªµªìª¿ªê¡¢P2P«°«ë?«×ªËãæª·ª¤«á«ó«Ğ?ª¬õÚÊ¥ªµªìªëíŞùê¡¢ª³ªÎ«á«½«Ã«Éª¬«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		«í?«««ë«Û«¹«ÈªÎí»ãóªË?ª·ªÆªâª³ªìª¬û¼ªÓõóªµªìªŞª¹¡£
		ÖÇª¨ªĞ¡¢«¯«é«¤«¢«ó«ÈAª¬?ªËìıªÃªÆª¤ªë«°«ë?«×GªËBª¬ãæª¿ªËìıªÃª¿ªéAªÏ(B,G)ªòáôª±ªÆ¡¢BªÏ(A,G), (B,G)ªòáôª±ªëª³ªÈªËªÊªêªŞª¹¡£

		\param memberHostID í»İÂªŞª¿ªÏöâªÎpeerªÎHostIDªÇª¹¡£
		\param groupHostID P2P«°«ë?«×ªÎHostIDªÇª¹¡£
		\param memberCount ?×âªµªìª¿ı­ªÎ«á«ó«Ğ??ªÇª¹¡£
		\param customField CNetServer.CreateP2PGroupªŞª¿ªÏCNetServer.JoinP2PGroupªÇ«æ?«¶?ª¬ìıÕôª·ª¿«««¹«¿«à«Ç?«¿ª¬ª³ª³ªÇª½ªÎªŞªŞ?Ó¹ªµªìªŞª¹¡£
		\~
		*/
		virtual void OnP2PMemberJoin(HostID memberHostID, HostID groupHostID, int memberCount, const ByteArray& customField) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> ÀÌ »ı¼ºµÇ°Å³ª ±âÁ¸ P2P±×·ì¿¡¼­ ÇÇ¾î°¡ Å»Åğ½Ã ÀÌ ¸Ş¼­µå°¡ Äİ¹éµË´Ï´Ù.
		·ÎÄÃ È£½ºÆ® ÀÚ½Å¿¡ ´ëÇØ¼­µµ ÀÌ°ÍÀÌ È£ÃâµË´Ï´Ù.

		\param memberHostID ÀÚ±â ¶Ç´Â Å¸ peerÀÇ HostIDÀÔ´Ï´Ù.
		\param groupHostID P2P ±×·ìÀÇ HostIDÀÔ´Ï´Ù.
		\param memberCount Ã³¸®µÈ ÈÄ ¸â¹ö ¼öÀÔ´Ï´Ù.

		\~english
		This method is to be called back either when <a target="_blank" href="http://guide.nettention.com/cpp_en#p2p_group" >P2P Group</a> is created or when a peer withdraws.
		Also called for local host iteself.

		\param memberHostID HostID of itself or other peer
		\param groupHostID HostID of P2P group
		\param memberCount The number of members after processed

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%ù¬ßæà÷ûäíºpeer?ñıîñîÜP2P?÷Üõó?ó®Û°Ûö?ù¬üŞ?¡£
		?Üâò¢ñ«ÏõÜâãó£¬??å¥?ù¬û¼Ğ£¡£

		\param memberHostID í»ĞùûäíºĞìöâpeerîÜHostID¡£
		\param groupHostID P2P?îÜHostID¡£
		\param memberCount ù¬?×âı¨îÜà÷??¡£

		\~japanese
		\ref p2p_groupª¬ßæà÷ªµªìªëª«¡¢?ğíªÎP2P«°«ë?«×ªÇ«Ô?«¢ª¬?÷ÜãÁªËª³ªÎ«á«½«Ã«Éª¬«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		«í?«««ë«Û«¹«ÈªÎí»ãóªË?ª·ªÆªâª³ªìª¬û¼ªÓõóªµªìªŞª¹¡£
		\param memberHostID ªÎí»İÂªŞª¿ªÏöâªÎpeerªÎHostIDªÇª¹¡£
		\param groupHostID P2P«°«ë?«×ªÎHostIDªÇª¹¡£
		\param memberCount ?×âªµªìª¿ı­ªÎ«á«ó«Ğ??ªÇª¹¡£
		\~
		*/
		virtual void OnP2PMemberLeave(HostID memberHostID, HostID groupHostID, int memberCount) = 0;

		/**
		\~korean
		Å¸ Å¬¶óÀÌ¾ğÆ®¿ÍÀÇ P2P Åë½Å °æ·Î(¸±·¹ÀÌ È¤Àº Á÷Á¢)°¡ ¹Ù²î´Â ¼ø°£ ÀÌ ¸Ş¼­µå°¡ È£ÃâµË´Ï´Ù.
		- ¹Ù²ï ÈÄ È£ÃâµÇ´Â °ÍÀÌ¹Ç·Î CNetClient.GetPeerInfo ¸¦ È£ÃâÇØ¼­ CNetPeerInfo.Proud.CNetPeerInfo.m_RelayedP2P ÀÇ °ªÀ» ¿­¶÷ÇØµµ µË´Ï´Ù.
		- ÀÌ°ÍÀÌ Äİ¹éµÇ´Â °Í°ú »ó°ü¾øÀÌ P2P°£ ¼­·Î Åë½ÅÀº Ç×»ó °¡´ÉÇÕ´Ï´Ù. ´Ù¸¸, ÇÇ¾î°£ ¸Ş½ÃÂ¡ÀÌ ¸±·¹ÀÌ¸¦ ÇÏ´À³Ä Á÷Á¢ ÀÌ·ç¾îÁö´À³ÄÀÇ Â÷ÀÌ°¡ ÀÖÀ» »ÓÀÔ´Ï´Ù.
		- ProudNetÀÇ P2P Åë½Å °æ·Î¿¡ ´ëÇÑ ÀÚ¼¼ÇÑ ³»¿ëÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#robust_p2p" >ProudNetÀÇ P2P Åë½Å ¼º´É</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.

		\param remoteHostID P2P ¿¬°áÀÌ µÇ¾î ÀÖ´Â Å¸ peerÀÇ HostID
		\param reason P2P ¿¬°áÀÌ ¼º°øÇÑ °æ¿ì¿¡´Â ErrorType_Ok °¡ µé¾îÀÖ´Ù. ¿©Å¸ÀÇ °ªÀÎ °æ¿ì´Â '¿Ö ¿¬°áÀÌ relay·Î ¹Ù²î¾ú´ÂÁö'¸¦ ´ã´Â´Ù.

		\~english
		This method is called at the moment the connection status to other client via P2P (relay or not) changes.
		Since it is called after the change so it is ok to call CNetClient.GetPeerInfo to view the value of CNetPeerInfo.Proud.CNetPeerInfo.m_RelayedP2P.
		<a target="_blank" href="http://guide.nettention.com/cpp_en#robust_p2p" >P2P performance of ProudNet</a>

		\param remoteHostID HostID of other peer that is connected via P2P
		\param reason If the P2P connection is successful then contains ErrorType_Ok. For other values it contain 'why the connection changed to relay'.

		\~chinese
		?ĞìöâèÌÊ«îÜP2P÷×ãáÖØ?£¨relay ûäíºòÁïÈ£©ËÇ?îÜâë?£¬ó®Û°Ûö?ù¬û¼Ğ£¡£
		- ì×?ãÀËÇ?ì¤ı¨ù¬û¼Ğ£îÜ£¬Ê¦ì¤û¼Ğ£ CNetClient.GetPeerInfo%ì¤ı¨?Ê× CNetPeerInfo.Proud.CNetPeerInfo.m_RelayedP2P%îÜ?¡£
		- ???üŞ?Ùé?£¬P2P ñı?îÜ÷×ãáãÀìéòÁÊ¦ú¼îÜ¡£ñşãÀğíî¤peerñı?îÜmessaging?ú¼relay?ãÀòÁïÈ?ú¼îÜ??¡£
		- ?ProudNetîÜP2P÷×ãáÖØ?îÜ???é»??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#robust_p2p" >ProudNet îÜP2P÷×ãáÍíÒö</a>%¡£

		\param remoteHostID P2P?ïÈı¨îÜĞìöâpeerîÜHost ID¡£
		\param reason P2P?ïÈà÷ÍíîÜ?£¬êóErrorType_Ok¡£Ğìöâ?îÜ?øĞùß¡®?ïÈ?ä§?ËÇ?à÷relayÖõ¡¯¡£

		\~japanese
		öâªÎ«¯«é«¤«¢«ó«ÈªÈªÎP2P÷×ãá?ÖØ(«ê«ì?ªŞª¿ªÏòÁïÈ)ª¬?ªïªëâëÊà¡¢ª³ªÎ«á«½«Ã«Éª¬û¼ªÓõóªµªìªŞª¹¡£
		- ?ªïªÃª¿ı­ªËû¼ªÓõóªµªìªŞª¹ªÎªÇ¡¢CNetClient.GetPeerInfoªòû¼ªÓõóª·ªÆCNetPeerInfo.Proud.CNetPeerInfo.m_RelayedP2PªÎö·ªò??ª·ªÆªâÕŞª¤ªÇª¹¡£
		- ª³ªìª¬«³?«ë«Ğ«Ã«¯ªµªìªëªÎªÈ?ÌõªÊª¯P2PÊàªÎªªû»ª¤ªÎ÷×ãáªÏª¤ªÄªâÊ¦ÒöªÇª¹¡£Ó£ª·¡¢PeerÊàªÎ«á«Ã«»?«¸«ó«°ª¬«ê«ì?ªòª¹ªëª«¡¢òÁïÈú¼ªïªìªëªÎª«ªÎó¬ª¬ª¢ªëªÀª±ªÇª¹¡£
		- ProudNetªÎP2P÷×ãá?ÖØªË?ª¹ªëßÙª·ª¤?é»ªÏ¡¢\ref robust_p2pªòª´?ğÎª¯ªÀªµª¤¡£

		\param remoteHostID P2PïÈ?ª¬ªÇª­ªÆª¤ªëöâªÎpeerªÎHostID
		\param reason P2P ïÈ?ªËà÷Ííª·ª¿íŞùêªËªÏ¡¢ErrorType_Okª¬ìıªÃªÆª¤ªŞª¹¡£öâªÎö·ªÎíŞùêªÏ¡¢¡¸ªÉª¦ª·ªÆïÈ?ª¬«ê«ì?ªË?ªïªÃª¿ªÎª«¡¹ªòò¥ªÁªŞª¹¡£
		\~
		*/
		virtual void OnChangeP2PRelayState(HostID remoteHostID, ErrorType reason) = 0;

		/**
		\~korean
		¼­¹ö¿ÍÀÇ ¿¬°áÀÌ ²÷°åÀ» ¶§ Äİ¹é µË´Ï´Ù.
		ÇØ´ç ÀÌº¥Æ®°¡ Äİ¹éÀÌ µÈ µÚ, ¼­¹ö¿¡ Àç Á¢¼ÓÀÌ ÀÌ·ç¾îÁöÁö ¾ÊÀ¸¸é
		OnLeaveServer °¡ Äİ¹é µË´Ï´Ù.
		(ÇØ´ç ÇÔ¼ö´Â NetClient ÀÇ  NetConnectionParam.m_enableAutoConnectionRecovery °¡ true ·Î ¼³Á¤ µÇ¾î¾ß ÇÕ´Ï´Ù.)

		\param args ¿¬°áÀÌ ²÷°åÀ» ¶§ ¿©·¯°¡Áö Á¤º¸¸¦ ´ã°í ÀÖ½À´Ï´Ù.

		\~english
		When connection to the server is lost, a callback is called. After the callback is called for a particular event, if reconnection to the server is not established, a callback occurs for OnLeaveServer.
		(The particular function shall have NetConnectionParam.m_enableAutoConnectionRecovery of NetClient as ¡°True¡±)

		\param args When connection is lost, it has a variety of information.

		\~chinese
		?Ü×?Ğï?ïÈñé??Ê¦ì¤üŞ?¡£ßÓ?ŞÀËìüŞ?ı¨åıÍıÜôÒöñìãæ?ïÈÜ×?Ğï OnLeaveServer£¨??Ü×?Ğï£©??ú¼üŞ?¡£
		£¨ßÓ?ùŞ? NetClient£¨??ËÔ?Ó®£©îÜ NetConnectionParam.m_enableAutoConnectionRecovery£¨???ïÈïïßí_Òö?üá?í»??ïÈ£©???ïÒ? true£¨ñ×?ò¢£©

		\param args (?Õá£©î¤?ïÈñéÓ®?øĞùßÖõÊÀ?ãáãÓ

		\~japanese
		«µ?«ĞªÈªÎïÈ?ª¬ï·?ªµªìª¿ªÈª­ªË«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£ª½ªÎ«¤«Ù«ó«Èª¬«³?«ë«Ğ«Ã«¯ªµªìª¿ı­¡¢«µ?«ĞªËî¢ïÈ?ª¬ú¼ªïªìªÊª¤íŞùêªÏOnLeaveServerª¬«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		(ª½ªÎ??ªÏNetClientªÎNetConnectionParam.m_enableAutoConnectionRecoveryªòtrueªËàâïÒª¹ªëù±é©ª¬ª¢ªêªŞª¹¡£)

		\param argsïÈ?ª¬ï·?ªµªìª¿ªÈª­¡¢ª¤ª¯ªÄª«ªÎï×ÜÃªòùßªóªÇª¤ªŞª¹¡£

		\~
		*/
		virtual void OnServerOffline(CRemoteOfflineEventArgs& /*args*/) {}

		/**
		\~korean
		¼­¹ö¿ÍÀÇ ¿¬°áÀÌ ²÷±ä µÚ Àç Á¢¼ÓÀÌ ÀÌ·ç¾îÁö¸é Äİ¹é µË´Ï´Ù.
		(ÇØ´ç ÇÔ¼ö´Â NetClient ÀÇ  NetConnectionParam.m_enableAutoConnectionRecovery °¡ true ·Î ¼³Á¤ µÇ¾î¾ß ÇÕ´Ï´Ù.)

		\param args Àç ¿¬°á¿¡ ´ëÇÑ Á¤º¸¸¦ ´ã°í ÀÖ½À´Ï´Ù.

		\~english
		After connection to the server is lost and then established again, a callback occurs.
		(The particular function shall have NetConnectionParam.m_enableAutoConnectionRecovery of NetClient as ¡°True¡±)

		\param args It has information on reconnection.

		\~chinese
		?Ü×?Ğï?ïÈñé?ì¤ı¨??ú¼ñìãæ?ïÈ??ú¼üŞ?
		£¨ßÓ?ùŞ? NetClient£¨??ËÔ?Ó®£©îÜ NetConnectionParam.m_enableAutoConnectionRecovery£¨???ïÈïïßí_Òö?üá?í»??ïÈ£©???ïÒ? true£¨ñ×?ò¢£©

		\param args (?Õá£©ñìãæ?ïÈîÜßÓ?ãáãÓ

		\~japanese
		«µ?«ĞªÈªÎïÈ?ª¬ï·?ªµªìª¿ı­¡¢î¢ïÈ?ª¬ú¼ªïªìªëªÈ«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		(ª½ªÎ??ªÏNetClientªÎNetConnectionParam.m_enableAutoConnectionRecoveryªòtrueªËàâïÒª¹ªëù±é©ª¬ª¢ªêªŞª¹¡£)

		\param argsî¢ïÈ?ªË?ª¹ªëï×ÜÃªòùßªóªÇª¤ªŞª¹¡£

		\~
		*/
		virtual void OnServerOnline(CRemoteOnlineEventArgs& /*args*/) {}

		/**
		\~korean
		ÀÚ½ÅÀÌ ¼ÓÇÑ P2P Group ³»ÀÇ Å¸ ÇÇ¾î°¡ ¼­¹ö¿ÍÀÇ ¿¬°áÀÌ ²÷°åÀ» ¶§ Äİ¹é µË´Ï´Ù.
		(ÇØ´ç ÇÔ¼ö´Â NetClient ÀÇ  NetConnectionParam.m_enableAutoConnectionRecovery °¡ true ·Î ¼³Á¤ µÇ¾î¾ß ÇÕ´Ï´Ù.)

		\param args ¿¬°áÀÌ ²÷±ä ÇÇ¾îÀÇ Á¤º¸°¡ ´ã°Ü ÀÖ½À´Ï´Ù.

		\~english
		When other peers within the P2P group where it belongs to lost connection to the server, a callback occurs.
		(The particular function shall have NetConnectionParam.m_enableAutoConnectionRecovery of NetClient as ¡°True¡±)

		\param args It has information on the peers that have lost connection.

		\~chinese
		î¤í»ãóá¶?îÜ P2P Group£¨P2PÍïíÂ?£©ñéåıÍıĞìöâÔÒÔõ PEER£¨?Ëì??øÁ÷»£©?Ü×?Ğï?ïÈñé??Ê¦ì¤?ú¼üŞ?
		£¨ßÓ?ùŞ? NetClient£¨??ËÔ?Ó®£©îÜ NetConnectionParam.m_enableAutoConnectionRecovery£¨???ïÈïïßí_Òö?üá?í»??ïÈ£©???ïÒ? true£¨ñ×?ò¢£©

		\param args (?Õá£©?ïÈñé?îÜPEER£¨?Ëì??øÁ÷»£©îÜßÓ?ãáãÓ

		\~japanese
		í»İÂª¬?ª·ªÆª¤ªëP2P Group?ªÎöâªÎ«Ô«¢ª¬«µ?«ĞªÈªÎïÈ?ª¬ï·?ªµªìª¿ªÈª­¡¢«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		(ª½ªÎ??ªÏNetClientªÎNetConnectionParam.m_enableAutoConnectionRecoveryªòtrueªËàâïÒª¹ªëù±é©ª¬ª¢ªêªŞª¹¡£)

		\param argsïÈ?ª¬ï·?ªµªìª¿«Ô«¢ªÎï×ÜÃª¬ùßªŞªìªÆª¤ªŞª¹¡£

		\~
		*/
		virtual void OnP2PMemberOffline(CRemoteOfflineEventArgs& /*args*/) {}

		/**
		\~korean
		ÀÚ½ÅÀÌ ¼ÓÇÑ P2P Group ³»ÀÇ Å¸ ÇÇ¾î°¡ ¼­¹ö¿ÍÀÇ ¿¬°áÀÌ ²÷±ä µÚ Àç Á¢¼ÓÀÌ ÀÌ·ç¾îÁö¸é Äİ¹é µË´Ï´Ù.
		(ÇØ´ç ÇÔ¼ö´Â NetClient ÀÇ  NetConnectionParam.m_enableAutoConnectionRecovery °¡ true ·Î ¼³Á¤ µÇ¾î¾ß ÇÕ´Ï´Ù.)

		\param args Àç ¿¬°áÀÌ µÈ ÇÇ¾îÀÇ Á¤º¸°¡ ´ã°Ü ÀÖ½À´Ï´Ù.

		\~english
		When other peers within the P2P group where it belongs to lost connection to the server and then gains reconnection, a callback occurs.
		(The particular function shall have NetConnectionParam.m_enableAutoConnectionRecovery of NetClient as ¡°True¡±)

		\param args It contains information of the peer reconnected.

		\~chinese
		î¤í»ãóá¶?îÜ P2P Group£¨P2PÍïíÂ?£©ñéåıÍıĞìöâÔÒÔõ PEER£¨?Ëì??øÁ÷»£©?Ü×?Ğï?ïÈñé??Ê¦ì¤?ú¼üŞ?
		£¨ßÓ?ùŞ? NetClient£¨??ËÔ?Ó®£©îÜ NetConnectionParam.m_enableAutoConnectionRecovery£¨???ïÈïïßí_Òö?üá?í»??ïÈ£©???ïÒ? true£¨ñ×?ò¢£©

		\param args(?Õá£©ñìãæ?ïÈîÜPEER£¨?Ëì??øÁ÷»£©îÜßÓ?ãáãÓ

		\~japanese
		í»İÂª¬?ª·ªÆª¤ªëP2P Group?ªÎöâªÎ«Ô«¢ª¬«µ?«ĞªÈªÎïÈ?ª¬ï·?ªµªìª¿ı­¡¢î¢ïÈ?ªµªìªëíŞùêªË«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		(ª½ªÎ??ªÏNetClientªÎNetConnectionParam.m_enableAutoConnectionRecoveryªòtrueªËàâïÒª¹ªëù±é©ª¬ª¢ªêªŞª¹¡£)

		\param argsî¢ïÈ?ª¬ú¼ªïªìª¿«Ô«¢ªÎï×ÜÃª¬ùßªŞªìªÆª¤ªŞª¹¡£

		\~
		*/
		virtual void OnP2PMemberOnline(CRemoteOnlineEventArgs& /*args*/) {}


		/**
		\~korean
		¼­¹ö¿ÍÀÇ UDP Åë½ÅÀÌ Á¤»óÀûÀÌ³ÄÀÇ ¿©ºÎ°¡ ¹Ù²î´Â ¼ø°£ ÀÌ ¸Ş¼­µå°¡ È£ÃâµÈ´Ù.
		\param reason ErrorType_Ok ÀÎ °æ¿ì ¼­¹ö¿ÍÀÇ UDP Åë½ÅÀÌ Á¤»óÀûÀ¸·Î ¼öÇàÁßÀÌ¸ç ¼­¹ö¿ÍÀÇ unreliable RMI ¸Ş½ÃÂ¡ÀÌ UDP¸¦ °æÀ¯ÇÑ´Ù.
		¿©Å¸ °ªÀÎ °æ¿ì ¼­¹ö¿ÍÀÇ UDP Åë½ÅÀÌ ºÒ°¡´ÉÇÏ°Ô µÆÀ½À» ÀÇ¹ÌÇÏ¸ç ÀÌ ±â°£ µ¿¾È ¼­¹ö¿ÍÀÇ unreliable RMI ¸Ş½ÃÂ¡Àº TCP¸¦ °æÀ¯ÇÑ´Ù.

		\~english
		This method is called at the moment that the communication status of UDP communication with server change.
		\param reason If ErrorType_Ok then UDP communication with server is normal and unreliable RMI messaging goes to server via UDP.
		Having other values means UDP communication witer server is unavailable and during this state, unreliable RMI messaging goes to server via TCP.

		\~chinese
		?Ü×?ĞïîÜUDP÷×ãáïáßÈ?ÜúËÇ?îÜâë?£¬ó®Û°Ûöù¬û¼Ğ£¡£
		\param reason ErrorType_Ok îÜ?ãÀ?Ü×?ĞïîÜUDP÷×ãá?ú¼ïáßÈ£¬?Ü×?ĞïîÜunreliable RMI messaging?ë¦UDP¡£
		Ğìöâ?îÜ?ëòÚ«ó·ÙéÛö?Ü×?ĞïîÜUDP?ú¼÷×ãá£¬?Ñ¢??Ü×?ĞïîÜunreliable RMI messaging?ë¦TCP¡£

		\~japanese
		«µ?«Ğ?ªÈªÎUDP÷×ãáª¬ïáßÈªÊªÎª«ªÉª¦ª«ª¬?ªïªëâëÊà¡¢ª³ªÎ«á«½«Ã«Éª¬û¼ªÓõóªµªìªŞª¹¡£
		\param reason ErrorType_Ok ªÎíŞùê¡¢«µ?«Ğ?ªÈªÎUDP÷×ãáª¬ïáßÈªËâÄú¼ñéªÊªÎªÇ¡¢«µ?«Ğ?ªÈªÎunreliable RMI«á«Ã«»?«¸«ó«°ª¬UDPªò?ë¦ª·ªŞª¹¡£
		öâªÎö·ªÎíŞùê¡¢«µ?«Ğ?ªÈªÎUDP÷×ãáª¬ªÇª­ªÊª¯ªÊªÃª¿ª³ªÈªòëòÚ«ª·ªÆ¡¢ª³ªÎÑ¢ÊàñéªË«µ?«Ğ?ªÈªÎunreliable RMI«á«Ã«»?«¸«ó«°ªÏTCPªò?ë¦ª·ªŞª¹¡£
		\~
		*/
		virtual void OnChangeServerUdpState(ErrorType /*reason*/) {}

		/**
		\~korean
		¼­¹ö¿ÍÀÇ ½Ã°£ÀÌ µ¿±âÈ­ µÉ ¶§¸¶´Ù È£ÃâµÈ´Ù.
		¼­¹ö ½Ã°£ µ¿±âÈ­´Â ÀÌ ¸Ş¼­µåÀÇ È£Ãâ È½¼ö°¡ Áõ°¡ÇÒ¼ö·Ï Á¡Â÷ Á¤È®µµ°¡ Áõ°¡ÇÑ´Ù.
		ÀÌ ¸Ş¼­µå ³»¿¡¼­µµ GetServerTimeMs()À» È£ÃâÇØµµ µÈ´Ù.

		\~english
		Called every time when time is synchronized with server
		Server time sybchronization becomes more accurate with as frequency of calling this method increases.
		It is also possible to call GetServerTimeMs() within this metod.

		\~chinese
		Øß??Ü×?ĞïîÜ??ÔÒÜÆîÜ?ı¦ù¬û¼Ğ£¡£
		Ü×?Ğï??îÜÔÒÜÆûù?ó·ó®Û°ÛöîÜû¼õóó­?ñòÊ¥ì»ñòÊ¥¡£
		î¤ó®Û°Ûö?å¥Ê¦ì¤û¼õóGetServerTime()¡£

		\~japanese
		«µ?«Ğ?ªÈªÎãÁÊàª¬ÔÒÑ¢ûùªµªìªëãÁª´ªÈªËû¼ªÓõóªµªìªŞª¹¡£
		«µ?«Ğ?ãÁÊàªÎÔÒÑ¢ûùªÏ¡¢ª³ªÎ«á«½«Ã«ÉªÎû¼ªÓõóª·üŞ?ª¬?Ê¥ª¹ªëªÛªÉßï?ªËïáü¬Óøª¬?Ê¥ª·ªŞª¹¡£
		ª³ªÎ«á«½«Ã«É?ªÇªâ GetServerTimeMs()ªòû¼ªÓõóª·ªÆªâÕŞª¤ªÇª¹¡£
		\~
		*/
		virtual void OnSynchronizeServerTime() = 0;
	};

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
