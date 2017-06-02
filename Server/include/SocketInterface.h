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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class CSocket;

#ifdef _WIN32

	/** \addtogroup net_group
	*  @{
	*/

	/** 
	\~korean
	SocketSelectContext class
	- »ç¿ë¹ı ¿¹Á¦´Â SampleÁß SimpleHttpConnect¸¦ Âü°íÇÏ½Ã¸é µË´Ï´Ù.
	- socketÀÇ select() non-block model À» À§ÇÑ ¿ëµµ
	- ÁÖÀÇ: Wait È£Ãâ ÈÄ¿¡´Â FD_SETÀÇ ³»¿ëÀÌ ¹Ù²ï´Ù. µû¶ó¼­ ÀÌ °´Ã¼´Â 1È¸¼ºÀ¸·Î ¾²¿©¾ß ÇÑ´Ù. 
	- Win32¿¡¼­¸¸ Áö¿øÇÏ´Â ±â´ÉÀÔ´Ï´Ù. iOS, linux¿¡¼­´Â ÀÌ°Í ´ë½Å ::poll()À» »ç¿ëÇÏ½Ê½Ã¿À.

	\~english TODO:translate needed.
	SocketSelectContext class
	- For instruction examples, please refer to SimpleHttpConnect within the samples.
	- Usage for select() non-black model of the socket.
	- Warning: after calling wait, the content of FD_SET is changed. Therefore, this object must be used on one-time basis.
	- This feature is supportedin Win32 only. In iOS and Linux, use ::poll() instead.

	\~chinese
	SocketSelectContext class
	- ŞÅéÄÛ°ÛöÖÇí­?ÍÅsampleñéSimpleHttpConnect?Ê¦¡£
	- ?ÖõsocketîÜselect() non-block modelîÜéÄÔ²¡£
	- ñ¼ëò£ºWaitû¼Ğ£ì¤ı¨?ËÇ?FD_SETîÜ?é»¡£á¶ì¤ó®?ßÚé©éÄéÍìéó­àõ¡£
	- ñşî¤Win32Ê¦ì¤ò¨ò¥¡£î¤iOS, linuxŞÅéÄ::poll()?ÓÛôğ??¡£

	\~japanese
	SocketSelectContext class
	- ŞÅéÄÛöÖÇğ¹ªÏ¡¢«µ«ó«×«ëªÎª¦ªÁSimpleHttpConnectªò?ÍÅªËª¹ªìªĞª¤ª¤ªÇª¹¡£
	- socketªÎselect() non-block modelªÎª¿ªáªÎéÄÔ²
	- ª´ñ¼ëò£ºWaitû¼ªÓõóª·ı­ªËªÏFD_SETªÎ?é»ª¬?ªïªêªŞª¹¡£ªèªÃªÆ¡¢ª³ªÎ«ª«Ö«¸«§«¯«ÈªÏ??àõªÇŞÅªïªìªÊª±ªìªĞªÊªêªŞª»ªó¡£
	- Win32ªÇªÎªß«µ«İ?«Èª¹ªëÑ¦ÒöªÇª¹¡£iOS¡¢linuxªÇªÏª³ªÎÓÛªïªêªË::poll()ªòŞÅªÃªÆª¯ªÀªµª¤¡£
	\~
	*/
	class SocketSelectContext
	{
	public:
		SocketSelectContext() {}

		virtual void AddWriteWaiter(CSocket& socket) = 0;
		virtual void AddExceptionWaiter( CSocket& socket ) = 0;
		virtual void Wait(uint32_t miliSec) = 0;
		virtual bool GetConnectResult(CSocket& socket, SocketErrorCode& outCode) = 0;

		PROUD_API static SocketSelectContext *New();
	};
#endif // _WIN32

	/**
	\~korean
	Socket Delegate Interface
	- Socket¿¡ °ü·ÃµÈ ¿¡·¯¸¦ OnSocketWarning ÇÔ¼ö¿¡¼­ ¹ŞÀ»¼ö ÀÖ´Ù.

	\~english
	Socket Delegate Interface
	- You can receive Socket related error from OnSocketWarning function.

	\~chinese
	Socket Delegate Interface
	- SocketßÓ?îÜ??Ê¦ì¤î¤OnSocketWarningùŞ?×ìïÈâ¥¡£

	\~japanese
	Socket Delegate Interface
	- SocketªË?Ö§«¨«é?ªòOnSocketWarning ??ªèªêáôª±ªéªìªŞª¹¡£
	\~
	*/
	class ISocketDelegate
	{
	public:
		virtual ~ISocketDelegate() {}
		virtual void OnSocketWarning(CSocket* soket, String msg) = 0;
	};

	/**
	\~korean
	CSocket class
	- ProudÀÇ NetClient ¸¦ ¾²Áö ¾Ê°í ¿ÜºÎÀÇ Server³ª http¿¡ Á¢±ÙÇÒ¶§ ¾²¸é À¯¿ëÇÏ´Ù.
	- ³»ºÎÀûÀ¸·Î Proud::FastSocket À» »ç¿ëÇÑ´Ù.

	\~english
	CSocket class
	- It is useful when you access external Server or http without NetClient of ProudNet.
	- Use Proud::FastSocket internally

	\~chinese
	CSocket class
	- ÜôŞÅéÄProudîÜNetClient£¬??èâİ»îÜServerûäíºhttpîÜ?ı¦ŞÅéÄîÜ?êóéÄ¡£
	- ŞÅéÄ?İ» Proud::FastSocket%¡£

	\~japanese
	CSocket class
	- ProudªÎNetClientªòŞÅªïªÊª¯èâİ»ªÎ«µ?«Ğ?ªähttpªò«¢«¯«»«¹ª¹ªëãÁªËŞÅª¨ªĞêóéÄªÇª¹¡£
	- ?İ»îÜªËProud::FastSocketªòŞÅéÄª·ªŞª¹¡£
	\~
	*/
	class CSocket
	{
	public:
		virtual ~CSocket(){}

	public:
		virtual bool Bind() = 0;
		virtual bool Bind(int port) = 0;
		virtual bool Bind( const PNTCHAR* addr, int port ) = 0;

		/**
		\~kore?an
		Connect ÇÑ´Ù.
		\param hostAddr host ÀÇ ÁÖ¼Ò
		\param hostPort host ÀÇ port

		\~english
		Connect.
		\param hostAddr Address of host
		\param hostPort Port of host


		\~chinese
		?ú¼connect¡£
		\param hostAddr hostîÜò¢ò£¡£
		\param hostPort hostîÜport¡£

		\~japanese
		ïÈ?ª·ªŞª¹¡£
		\param hostAddr host ªÎ«¢«É«ì«¹
		\param hostAddr host ªÎ«İ?«È
		\~
		*/
		virtual SocketErrorCode Connect(String hostAddr, int hostPort) = 0;

#if defined(_WIN32)
		/**
		\~korean
		UDP socket
		- Recv¸¦ IssueÇÑ´Ù.
		\param length ¹öÆÛÀÇ Å©±â
		\return ¼ÒÄÏ Error¸¦ ¸®ÅÏÇØÁİ´Ï´Ù. SocketErrorCode_Ok ÀÌ¸é Á¤»ó

		\~english
		UDP socket
		- Issue Recv
		\param length Size of length buffer
		\return Return the socket error. If SocketErrorCode_Ok, it is normal.


		\~chinese
		UDP socket
		- ÷êRecv?ú¼issue¡£
		\param length bufferîÜÓŞá³¡£
		\return Ú÷üŞsocketîÜError¡£SocketErrorCode_Ok îÜ?ïáßÈ¡£

		\~japanese
		UDP socket
		- RecvªòIssueª·ªŞª¹¡£
		\param length «Ğ«Ã«Õ«¡?ªÎ«µ«¤«º
		\return «½«±«Ã«È«¨«é?ªò«ê«¿?«óª·ªŞª¹¡£SocketErrorCode_OkªÇª¢ªìªĞïáßÈªÇª¹¡£
		\~
		*/
		virtual SocketErrorCode IssueRecvFrom(int length) = 0;
		
		/**
		\~korean
		UDP socket
		- Send¸¦ IssueÇÑ´Ù.
		\param data º¸³¾ dataÀÇ ¹è¿­
		\param count ¹è¿­ÀÇ Å©±â
		\param sendTo º¸³¾ ÁÖ¼Ò
		\return ¼ÒÄÏ Error¸¦ ¸®ÅÏÇØÁİ´Ï´Ù. SocketErrorCode_Ok ÀÌ¸é Á¤»ó

		\~english
		UDP socket
		- Does asynchronous send call.

		\~chinese
		UDP socket
		- ÷êSend?ú¼Issue¡£
		\param data é©?áêîÜdataîÜ??¡£
		\param count ??îÜÓŞá³¡£
		\param sendTo é©?áêîÜò¢ò£¡£
		\return Ú÷üŞsocketîÜError¡£SocketErrorCode_Ok îÜ?ïáßÈ¡£

		\~japanese
		UDP socket
		- SendªòIssueª·ªŞª¹¡£
		\param data áêªë«Ç?«¿ªÎÛÕÖª
		\param count ÛÕÖªªÎ«µ«¤«º
		\param sendTo áêªë«¢«É«ì«¹
		\return «½«±«Ã«È«¨«é?ªò«ê«¿?«óª·ªŞª¹¡£SocketErrorCode_OkªÇª¢ªìªĞïáßÈªÇª¹¡£
		\~
		*/
		virtual SocketErrorCode IssueSendTo( uint8_t* data, int count, AddrPort sendTo ) = 0;
		
		/**
		\~korean
		TCP socket
		- Recv¸¦ IssueÇÑ´Ù.
		\param length ¹öÆÛÀÇ Å©±â
		\return ¼ÒÄÏ Error¸¦ ¸®ÅÏÇØÁİ´Ï´Ù. SocketErrorCode_Ok ÀÌ¸é Á¤»ó

		\~english TODO:translate needed.
		TCP socket
		- Issue Recv
		\param length Size of length buffer
		\return Return the socket error. If SocketErrorCode_Ok, it is normal.


		\~chinese
		UDP socket
		- ÷êRecv?ú¼issue¡£
		\param length bufferîÜÓŞá³¡£
		\return Ú÷üŞsocketîÜError¡£SocketErrorCode_Ok îÜ?ïáßÈ¡£

		\~japanese
		TCP socket
		- RecvªòIssueª·ªŞª¹¡£
		\param length «Ğ«Ã«Õ«¡?ªÎ«µ«¤«º
		\return «½«±«Ã«È«¨«é?ªò«ê«¿?«óª·ªŞª¹¡£SocketErrorCode_OkªÇª¢ªìªĞïáßÈªÇª¹¡£
		\~
		*/
		virtual SocketErrorCode IssueRecv(int length) = 0;

		/**
		\~korean
		TCP socket
		- Send ¸¦ Issue ÇÑ´Ù.
		\param data º¸³¾ data ÀÇ ¹è¿­
		\param count ¹è¿­ÀÇ Å©±â
		\return ¼ÒÄÏ Error ¸¦ ¸®ÅÏÇØÁİ´Ï´Ù. SocketErrorCode_OkÀÌ¸é Á¤»ó

		\~english TODO:translate needed.
		TCP socket
		- Issue Send.
		\param data Array of the data to be sent.
		\param count Size of the array
		\return Return the socket error. If SocketErrorCode_Ok, it is normal.


		\~chinese
		UDP socket
		- ÷êSend?ú¼Issue¡£
		\param data é©?áêîÜdataîÜ??¡£
		\param count ??îÜÓŞá³¡£
		\return Ú÷üŞsocketîÜError¡£SocketErrorCode_Ok îÜ?ïáßÈ¡£

		\~japanese
		TCP socket
		- SendªòIssueª·ªŞª¹¡£
		\param data áêªë«Ç?«¿ªÎÛÕÖª
		\param count ÛÕÖªªÎ«µ«¤«º
		\return «½«±«Ã«È«¨«é?ªò«ê«¿?«óª·ªŞª¹¡£SocketErrorCode_OkªÇª¢ªìªĞïáßÈªÇª¹¡£
		\~
		*/
		virtual SocketErrorCode IssueSend( uint8_t* data, int count) = 0;

		/**
		\~korean
		async issueÀÇ °á°ú¸¦ ±â´Ù¸°´Ù.
		- ¾ÆÁ÷ ¾Æ¹«°Íµµ ¿Ï·áµÇÁö ¾Ê¾ÒÀ¸¸é nullÀ» ¸®ÅÏÇÑ´Ù.
		- ¸¸¾à ¿Ï·á ¼º°ø ¶Ç´Â ¼ÒÄÏ ¿¡·¯ µîÀÇ ½ÇÆĞ°¡ »ı±â¸é °´Ã¼¸¦ ¸®ÅÏÇÏµÇ m_errorCode°¡ Ã¤¿öÁ® ÀÖ´Ù.
		\param waitUntilComplete ¿Ï·áµÉ¶§±îÁö ±â´Ù¸± °ÍÀÎÁö °áÁ¤ÇÑ´Ù.
		\param ret °á°ú \ref OverlappedResult ÂüÁ¶
		\return ¼º°øÀÌ¸é true, ½ÇÆĞÀÌ¸é false¸®ÅÏ

		\~english TODO:translate needed.
		Wait for the result of async issue.
		- If nothing has been completed, return null.
		- If completion success or failures as socket errors, etc. occur, return the object but it is filled with m_errorCode.
		\param waitUntilComplete Determine whether to wait until complete.
		\param Refer to the result \ref OverlappedResult
		\return Return true if successful or false if failed.


		\~chinese
		ÔõÓâasync issueîÜ?Íı¡£
		- ä§?Ô´?êó?áÖîÜ?Ú÷üŞnull¡£
		- åıÍıà÷Íí?áÖûäíº?ßæsocket??îÜã÷?îÜîÜ?£¬Ú÷üŞ?ßÚÓ£ãÀ??õöm_errorCode¡£
		\param waitUntilComplete ?ïÒãÀÜúé©ÔõÓğ?áÖ¡£
		\param ret ?ğÎ?Íı\ref OverlappedResult%¡£
		\return à÷ÍíîÜ?true£¬ã÷?îÜ?Ú÷üŞfalse¡£

		\~japanese
		async issueªÎÌ¿ÍıªòÓâªÁªŞª¹¡£
		- ªŞªÀù¼ªâèÇÖõªµªìªÊª«ªÃª¿ªénullªò«ê«¿?«óª·ªŞª¹¡£
		- ªâª·¡¢èÇÖõà÷ÍíªŞª¿ªÏ«½«±«Ã«È«¨«é?ªÊªÉªÎã÷ø¨ª¬ßæª¸ª¿ªé«ª«Ö«¸«§«¯«Èªò«ê«¿?«óª·ªŞª¹ª¬¡¢m_errorCodeª¬?ª¿ªµªìªÆª¤ªŞª¹¡£
		\param waitUntilComplete èÇÖõª¹ªëãÁªŞªÇÓâªÄª«ªÉª¦ª«ªòÌ½ïÒª·ªŞª¹¡£
		\param ret Ì¿Íı \ref OverlappedResult ?ğÎ
		\return à÷ÍíªÇª¢ªìªĞtrue¡¢ã÷ø¨ªÇª¢ªìªĞfalseªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		virtual bool GetRecvOverlappedResult(bool waitUntilComplete, OverlappedResult &ret) = 0;
		
		/**
		\~korean
		async issueÀÇ °á°ú¸¦ ±â´Ù¸°´Ù.
		- ¾ÆÁ÷ ¾Æ¹«°Íµµ ¿Ï·áµÇÁö ¾Ê¾ÒÀ¸¸é nullÀ» ¸®ÅÏÇÑ´Ù.
		- ¸¸¾à ¿Ï·á ¼º°ø ¶Ç´Â ¼ÒÄÏ ¿¡·¯ µîÀÇ ½ÇÆĞ°¡ »ı±â¸é °´Ã¼¸¦ ¸®ÅÏÇÏµÇ m_errorCode°¡ Ã¤¿öÁ® ÀÖ´Ù.
		\param waitUntilComplete ¿Ï·áµÉ¶§±îÁö ±â´Ù¸± °ÍÀÎÁö °áÁ¤ÇÑ´Ù.
		\param ret °á°ú \ref OverlappedResult ÂüÁ¶
		\return ¼º°øÀÌ¸é true, ½ÇÆĞÀÌ¸é false¸®ÅÏ

		\~english TODO:translate needed.
		Wait for the result of async issue.
		- If nothing has been completed, return null.
		- If completion success or failures as socket errors, etc. occur, return the object but it is filled with m_errorCode.
		\param waitUntilComplete Determine whether to wait until complete.
		\param ret Refer to the result \ref OverlappedResult
		\return Return true if successful or false if failed.


		\~chinese
		Ôõasync issueîÜ?Íı¡£
		- ä§?Ô´?êó?áÖîÜ?Ú÷üŞnull¡£
		- åıÍıà÷Íí?áÖûäíº?ßæsocket??îÜã÷?îÜîÜ?£¬Ú÷üŞ?ßÚÓ£ãÀ??õöm_errorCode¡£
		\param waitUntilComplete ?ïÒãÀÜúé©ÔõÓğ?áÖ¡£
		\param ret ?ğÎ?Íı\ref OverlappedResult%¡£
		\return à÷ÍíîÜ?true£¬ã÷?îÜ?Ú÷üŞfalse¡£

		\~japanese
		async issueªÎÌ¿ÍıªòÓâªÁªŞª¹¡£
		- ªŞªÀù¼ªâèÇÖõªµªìªÊª«ªÃª¿ªé¡¢nullªò«ê«¿?«óª·ªŞª¹¡£
		- ªâª·¡¢èÇÖõà÷ÍíªŞª¿ªÏ«½«±«Ã«È«¨«é?ªÊªÉªÎã÷ø¨ª¬ßæª¸ª¿ªé«ª«Ö«¸«§«¯«Èªò«ê«¿?«óª¹ªëª¬¡¢m_errorCodeª¬?ª¿ªµªìªÆª¤ªŞª¹¡£
		\param waitUntilComplete èÇÖõª¹ªëãÁªŞªÇÓâªÄª«ªÉª¦ª«ªòÌ½ïÒª·ªŞª¹¡£
		\param ret Ì¿Íı \ref OverlappedResult ?ğÎ
		\return à÷ÍíªÇª¢ªìªĞtrue¡¢ã÷ø¨ªÇª¢ªìªĞfalseªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		virtual bool GetSendOverlappedResult(bool waitUntilComplete, OverlappedResult &ret) = 0;
#endif
        
		/**
		\~korean
		¼ÒÄÏÀÇ ÁÖ¼Ò¸¦ °¡Á®¿Â´Ù.

		\~english TODO:translate needed.
		Get the address of the socket

		\~chinese
		ÑÚ?socketîÜò¢ò£¡£

		\~japanese
		«½«±«Ã«ÈªÎ«¢«É«ì«¹ªòö¢ªê?ªßªŞª¹¡£
		\~
		*/
		virtual AddrPort GetSockName() = 0;

		/**
		\~korean
		peer ¿¡ ´ëÇÑ ¼ÒÄÏÀÇ ÁÖ¼Ò¸¦ °¡Á®¿Â´Ù.

		\~english TODO:translate needed.
		Get the socket address to the peer.

		\~chinese
		ÑÚ??peerîÜsocketò¢ò£¡£

		\~japanese
		PeerªË?ª¹ªë«½«±«Ã«È«¢«É«ì«¹ªòö¢ªê?ªßªŞª¹¡£
		\~
		*/
		virtual AddrPort GetPeerName() = 0;

		/**
		\~korean
		Åë½Å¿¡ ´ëÇÏ¿© ºí·°Å· ¸ğµå¸¦ »ç¿ëÇÒ °ÍÀÎÁö ¼±ÅÃÇÑ´Ù.

		\~english TODO:translate needed.
		Select whether to use the blocking mode for the communication.

		\~chinese
		???÷×ãáãÀÜúŞÅéÄblockingÙ¼ãÒ¡£

		\~japanese
		÷×ãáªË?ª·ªÆ«Ö«í«Ã«­«ó«°«â?«ÉªòŞÅª¦ª«ªÉª¦ª«ªòàÔ?ª·ªŞª¹¡£
		\~
		*/
		virtual void SetBlockingMode(bool isBlockingMode) = 0;

		/**
		\~korean
		recv ¹öÆÛÀÇ Æ÷ÀÎÅÍ¸¦ ¾ò¾î¿Â´Ù.

		\~english TODO:translate needed.
		Get the pointer of the recv buffer.

		\~chinese
		?ö¢recv bufferîÜò¦?¡£

		\~japanese
		recv«Ğ«Ã«Õ«¡?ªÎ«İ«¤«ó«¿?ªòÔğªŞª¹¡£
		\~
		*/
		virtual uint8_t* GetRecvBufferPtr() = 0;
		
		/**
		\~korean
		recv hostÀÇ ip Address¸¦ ¾ò¾î¿Â´Ù.

		\~english TODO:translate needed.


		\~chinese
		?ö¢recv hostîÜip Address¡£

		\~japanese
		recv hostªÎip AddressªòÔğªŞª¹¡£
		\~
		*/
		PROUD_API static String GetIPAddress(String hostName);

		/**
		\~korean
		CSocket °´Ã¼¸¦ »ı¼ºÇÑ´Ù.
		\param type ¼ÒÄÏÀÇ TypeÀ» Á¤ÇÑ´Ù.
		\param dg ¼ÒÄÏÀÇ ÀÌº¥Æ®¸¦ ¹ŞÀ» °´Ã¼. \ref ISocketDelegate ¸¦ ÂüÁ¶

		\~english TODO:translate needed.
		Generate CSocket object
		\param type Determine the type of the socket.
		\param dg Object to receive the socket event. Refer to \ref ISocketDelegate.


		\~chinese
		ßæà÷ CSocket%?ßÚ¡£
		\param type ò¦ïÒsocketîÜType¡£
		\param dg ïÈâ¥socketîÜeventîÜ?ßÚ¡£?ğÎ\ref ISocketDelegate%¡£

		\~japanese
		CSocket«ª«Ö«¸«§«¯«Èªòßæà÷ª·ªŞª¹¡£
		\param type «½«±«Ã«ÈªÎTypeªòÌ½ªáªŞª¹¡£
		\param dg «½«±«Ã«ÈªÎ«¤«Ù«ó«Èªòáôª±ªë«ª«Ö«¸«§«¯«È¡£\ref ISocketDelegate ªòª´?ğÎª¯ªÀªµª¤¡£
		\~
		*/
		PROUD_API static CSocket *New(SocketType type, ISocketDelegate *dg);
	};
	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
