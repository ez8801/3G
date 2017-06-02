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

#include "ErrorInfo.h"
#include "Enums.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/


	class RmiContext;

	/** user worker thread callback context. */
	class CUserWorkerThreadCallbackContext
	{
	};



	/** 
	\~korean
	ProudNet¿ë event sink
	- ÆÄ»ı Å¬·¡½º¿¡¼­ »ç¿ëµÊ.

	\~english
	Event sink for ProudNet
	- Use it with derivation class

	\~chinese
	ProudNetéÄevent sink¡£
	- î¤÷ïßæ?×ìŞÅéÄ¡£

	\~japanese
	ProudNetéÄ event sink
	- ÷ïßæ«¯«é«¹ªÇŞÅªïªìªŞª¹¡£
	\~
	*/
	class INetCoreEvent
	{
	public:

	public:
		virtual ~INetCoreEvent();

		/** 
		\~korean
		³»ºÎ ¿¡·¯ ¹ß»ı½Ã È£ÃâµÊ
		\param errorInfo ¿¡·¯ Á¤º¸. ErrorInfo::ToString() À» ÅëÇÏ¿© ÇÊ¿äÇÑ Á¤º¸¸¦ ½±°Ô ¾òÀ¸½Ç ¼ö ÀÖ½À´Ï´Ù. ÀÚ¼¼ÇÑ °ÍÀº ErrorInfo µµ¿ò¸»¿¡ ÀÖ½À´Ï´Ù.

		\~english TODO:translate needed.
		It is called when an internal error is called. 
		\param errorInfo Error information. You can easily obtain the necessary information through ErrorInfo::ToString(). More details are in the ErrorInfo help. 

		\~chinese
		?ßæ?İ»???ù¬û¼Ğ£¡£
		\param errorInfo ??ãáãÓ¡£÷×? ErrorInfo::ToString()%Ê¦ì¤?áæ?ÔğâÍé©îÜãáãÓ¡£??îÜî¤ErrorInfo?ğ¾×ì¡£

		\~japanese
		?İ»«¨«é?ª¬?ßæãÁªËû¼ªÓõóªµªìªŞª¹¡£
		\param errorInfo «¨«é?ï×ÜÃ¡£ErrorInfo::ToString()ªò÷×ª¸ù±é©ªÊï×ÜÃªòÊÛ?ªËâ¢ªËìıªìªëª³ªÈª¬ªÇª­ªŞª¹¡£ßÙª·ª¯ªÏ¡¢ErrorInfoªÎ«Ø«ë«×ªòª´?ğÎª¯ªÀªµª¤¡£
		\~
		*/
		virtual void OnError(ErrorInfo *errorInfo) = 0;

		/** 
		\~korean
		³»ºÎ °æ°í ¹ß»ı½Ã È£ÃâµÊ. ¿¡·¯º¸´Ù´Â ³·Àº ¼öÀ§ÀÇ ¹®Á¦¸¦ º¸°íÇÔ.
		\param errorInfo ¿¡·¯ Á¤º¸. ErrorInfo::ToString() À» ÅëÇÏ¿© ÇÊ¿äÇÑ Á¤º¸¸¦ ½±°Ô ¾òÀ¸½Ç ¼ö ÀÖ½À´Ï´Ù. ÀÚ¼¼ÇÑ °ÍÀº ErrorInfo µµ¿ò¸»¿¡ ÀÖ½À´Ï´Ù. 

		\~english TODO:translate needed.
		It is called when an internal warning is called. This reports a problem on a lower level than an error. 
		\param errorInfo Error information. You can easily obtain the necessary information through ErrorInfo::ToString(). More details are in the ErrorInfo help.

		\~chinese
		?ßæ?İ»ÌíÍ±?ù¬û¼Ğ£¡£?Í±İï??î¸?îÜ??
		\param errorInfo ??ãáãÓ¡£÷×? ErrorInfo::ToString()%Ê¦ì¤?áæ?ÔğâÍé©îÜãáãÓ¡£??îÜî¤ErrorInfo?ğ¾×ì¡£

		\~japanese
		?İ»ÌíÍ±ª¬?ßæãÁªËû¼ªÓõóªµªìªŞª¹¡£«¨«é?ªèªêªÏî¸ª¤«ì«Ù«ëªÎÙığ¹ªòÜÃÍ±ª·ªŞª¹¡£
		\param errorInfo «¨«é?ï×ÜÃ¡£ErrorInfo::ToString()ªò÷×ª¸ù±é©ªÊï×ÜÃªòÊÛ?ªËâ¢ªËìıªìªëª³ªÈª¬ªÇª­ªŞª¹¡£ßÙª·ª¯ªÏ¡¢ErrorInfoªÎ«Ø«ë«×ªòª´?ğÎª¯ªÀªµª¤¡£
		\~
		*/
		virtual void OnWarning(ErrorInfo *errorInfo) = 0;

		/** 
		\~korean
		³»ºÎ ¾Ë¸² ¹ß»ı½Ã È£ÃâµÊ. ³»ºÎ »óÈ² ÃßÀû µîÀ» À§ÇÑ °ÍÀ¸·Î ¹®Á¦ »óÈ²À» ¸»ÇÏ´Â °ÍÀº ¾Æ´Ô.
		\param errorInfo ¿¡·¯ Á¤º¸. ErrorInfo::ToString() À» ÅëÇÏ¿© ÇÊ¿äÇÑ Á¤º¸¸¦ ½±°Ô ¾òÀ¸½Ç ¼ö ÀÖ½À´Ï´Ù.

		\~english TODO:translate needed.
		It is called when an internal notification is called. This is for internal status tracing, etc. and does not mean a problem situation. 
		\param errorInfo Error information. You can easily obtain the necessary information through ErrorInfo::ToString(). More details are in the ErrorInfo help.

		\~chinese
		?ßæ?İ»Í±ò±?ù¬û¼Ğ£¡£ãÀ?Öõ?İ»ï×?õÚñ¡Ôõ£¬?ÜôãÀ????îÜï×?¡£
		\param errorInfo ??ãáãÓ¡£÷×? ErrorInfo::ToString()%Ê¦ì¤?áæ?ÔğâÍé©îÜãáãÓ¡£

		\~japanese
		?İ»«¢«é?«àª¬?ßæãÁªËû¼ªÓõóªµªìªŞª¹¡£?İ»?üÏõÚîæªÊªÉªÎª¿ªáªÎª³ªÈªÇ¡¢Ùığ¹?üÏªòåëª¦ªÎªÇªÏª¢ªêªŞª»ªó¡£
		\param errorInfo «¨«é?ï×ÜÃ¡£ErrorInfo::ToString()ªò÷×ª¸ù±é©ªÊï×ÜÃªòÊÛ?ªËâ¢ªËìıªìªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\~
		*/
		virtual void OnInformation(ErrorInfo *errorInfo) = 0;

		/** 
		\~korean
		Proud.Exception À¸·Î ÅëÇÕ
		- ÀÏ¹İÀûÀ¸·Î À¯Àú ÄÚµå¿¡¼­ ³ª´Â ¿¡·¯¸¦ Ã³¸®ÇÑ´Ù.
		- À¯Àú´Â ÇÊ¿äÇÑ °ÍµéÀ» ±¸ÇöÇÏ¸é µÈ´Ù.
		- ExceptionType À¸·Î ÇØ´ç Exception °´Ã¼¸¦ ¾ò¾î¼­ »ç¿ëÇÏ¸é µÈ´Ù.
		- _com_error, void*, std::exception µîÀ» ¸ğµÎ Ã³¸®ÇÑ´Ù.
		¶ÇÇÑ catch(...)¸¦ Ã³¸®ÇÏ´Â OnUnhandledException()µµ ÀÖ´Ù.
		- void*´Â ¿¹¿Ü °´Ã¼ÀÇ Å¸ÀÔÀ» Ä³½ºÆÃÇØ¼­ ¹ŞÀ» ¼ö ÀÖ´Ù. °¡·É MFC CException À» ¹Ş´Âµ¥ »ç¿ëµÈ´Ù.

		\~english
		Merge to Proud.Exception
		- It handles error that occur from user code. 
		- User realize things that user needed. 
		- You can use Exceptiontype that obtain Exception object. 
		- It process _com_error, void*, std::exception, etc. Also there is OnUnhandledException() that handle catch(...) 
		- void* can obtain exceptional object type by casting. For example, it uses obtaining MFC CException. 

 		\~chinese
		ùê?? Proud.Exception%¡£
		- ìéÚõ?×âî¤éÄ?ÓÛ??ßæîÜ??¡£
		- éÄ???á¶âÍé©îÜ?Ê¦¡£
		- éÄExceptionType?ÔğßÓ?Exception?ßÚ?îïİ»?×â¡£
		- ?×âîïİ»îÜ_com_error, void*, std::exception¡£
		å¥êó?×âcatch(...)îÜOnUnhandledException()¡£
		- void*Ê¦ì¤?ÖÇèâ?ßÚ?úş??ïÈâ¥¡£ÖÇåıéÄéÍïÈâ¥MFC CException%¡£

		\~japanese
		Proud.Exception ªË÷Öùê
		- ìéÚõîÜªË«æ?«¶?«³?«Éªèªêõóªë«¨«é?ªò?×âª·ªŞª¹¡£
		- «æ?«¶?ªÏù±é©ªÊª³ªÈªò?úŞª¹ªìªĞÕŞª¤ªÇª¹¡£
		- ExceptionTypeªÇú±?Exception«ª«Ö«¸«§«¯«ÈªòÔğªÆŞÅª¨ªĞÕŞª¤ªÇª¹¡£
		- _com_error, void*, std::exception ªÊªÉªòîïªÆ?×âª·ªŞª¹¡£
		ªŞª¿¡¢catch(...)ªò?×âª¹ªëOnUnhandledException()ªâª¢ªêªŞª¹¡£
		- void*ªÏÖÇèâ«ª«Ö«¸«§«¯«ÈªÎ«¿«¤«×ªò«­«ã«¹«Æ«£«ó«°ª·ªÆáôª±ªéªìªŞª¹¡£?ªËMFC CExceptionªòáôª±ªëª³ªÈªËŞÅªïªìªŞª¹¡£
		\~
		*/
		virtual void OnException(const Exception &e) = 0;

		/** 
		\~korean
		RMI°¡ È£ÃâÀÌ µé¾î¿ÔÀ¸³ª AttachµÈ Stub Áß¿¡ ´ëÀÀÇÏ´Â RMI°¡ ÀüÇô ¾øÀ¸¸é ÀÌ°ÍÀÌ Äİ¹éµÈ´Ù.

		\~english
		When RMI is called but there is no RMI in Stub that attached then this will callback.

		\~chinese
		êóRMIû¼Ğ££¬Ó£ãÀ?êó??éÍAttachîÜStubîÜRMIîÜ?£¬??ù¬üŞ?¡£

		\~japanese
		RMIªËû¼ªÓõóª·ª¬ìıªêªŞª·ª¿ª¬¡¢Attachªµªìª¿StubªÎª¦ªÁ??ª¹ªëRMIª¬îïª¯Ùíª±ªìªĞª³ªìª¬«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		\~
		*/
		virtual void OnNoRmiProcessed(RmiID rmiID) = 0;

		/** 
		\~korean
		»ç¿ëÀÚ°¡ Á¤ÀÇÇÑ ¸Ş½ÃÁö¸¦ ¼ö½ÅÇÏ¸é ÀÌ ÇÔ¼ö°¡ Äİ¹éµË´Ï´Ù. »ç¿ëÀÚ´Â ÀÌ ÇÔ¼ö¸¦ ¿À¹ö¶óÀÌµåÇØ¼­ ¿øÇÏ´Â Ã³¸®¸¦ ÇÒ ¼ö ÀÖ½À´Ï´Ù.
		ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#send_user_message" >RMI¸¦ ÀüÇô ¾È¾²°í »ç¿ëÀÚ Á¤ÀÇ ¸Ş½ÃÁö¸¦ ÁÖ°í ¹Ş±â</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.
		- Visual Studio 2005 ÀÌ»óÀÇ ÄÄÆÄÀÏ·¯¿¡¼­´Â override Å°¿öµå »ç¿ëÀ» ±ÇÀåÇÕ´Ï´Ù. 
		
		\param sender ¸Ş½ÃÁö¸¦ ¼Û½ÅÇÑ È£½ºÆ®ÀÔ´Ï´Ù.
		\param rmiContext ¼ö½Å ºÎ°¡ Á¤º¸ÀÔ´Ï´Ù.
		\param payload ¼ö½ÅµÈ ¸Ş½ÃÁö º»¹®ÀÔ´Ï´Ù.
		\param payloadLength ¼ö½ÅµÈ ¸Ş½ÃÁö º»¹®ÀÇ ±æÀÌ(¹ÙÀÌÆ®)ÀÔ´Ï´Ù.

		\~english
		This function will callback once user received defined message. Then user can process as overriding this function.
		Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#send_user_message" >Exchanging user-defined message without using RMI at all</a> for more detail.
		- We recommend to use override keyword on Visual Studio 2005 or above.

		\param sender Host that sent message.
		\param rmiContext Additional information of receiving
		\param payload Main text of received message.
		\param payloadLength Length(byte) of received main text.

		\~chinese
		â¥ÓğéÄ?ïÒ?îÜãáãÓîÜ?£¬ó®ùŞ?ù¬üŞ?¡£éÄ?Ê¦ì¤ÜİËÌó®ùŞ?ı¨?ú¼ßÌé©îÜ?×â¡£
		??îÜ??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#send_user_message" >èÇîïÜôŞÅéÄRMIÎß?éÄ?ïÒ?ãáãÓ</a>%¡£
		- î¤Visual Studio 2005ì¤ß¾îÜßæà÷Ğï×ìËï?ŞÅéÄoverride??í®¡£

		\param sender ?áêãáãÓîÜñ«Ïõ¡£
		\param rmiContext â¥ãáİ¾Ê¥ãáãÓ¡£
		\param payload â¥ãáîÜãáãÓê«Ùş¡£.
		\param payloadLength â¥ãáîÜãáãÓê«ÙşîÜ?Óø£¨byte£©¡£

		\~japanese
		«æ?«¶?ª¬ïÒëùª·ª¿«á«Ã«»?«¸ªòáôãáª¹ªìªĞª³ªÎ??ª¬«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£«æ?«¶?ªÏª³ªÎ??ªò«ª?«Ğ?«é«¤«Éª·ªÆêÃª¤?×âªòª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
		ßÙª·ª¯ªÏ¡¢\ref send_user_messageªòª´?ğÎª¯ªÀªµª¤¡£
		- Visual Studio 2005 ì¤ß¾ªÎ«³«ó«Ñ«¤«é?ªÇªÏoverride«­?«ï?«ÉªÎŞÅéÄªòªª?ªáª·ªŞª¹¡£ 

		\param sender «á«Ã«»?«¸ªòáêãáª·ª¿«Û«¹«ÈªÇª¹¡£
		\param rmiContext áôãáÜõÊ¥ï×ÜÃªÇª¹¡£
		\param payload áôãáªµªìª¿«á«Ã«»?«¸ªÎÜâÙşªÇª¹¡£
		\param payloadLength áôãáªµªìª¿«á«Ã«»?«¸ÜâÙşªÎíşªµ£¨«Ğ«¤«È£©ªÇª¹¡£
		\~
		*/
		virtual void OnReceiveUserMessage(HostID sender, const RmiContext &rmiContext, uint8_t* payload, int payloadLength);

		/** 
		\~korean
		ÀÏÁ¤ ½Ã°£¸¶´Ù user worker thread pool¿¡¼­ Äİ¹éµÇ´Â ÇÔ¼öÀÔ´Ï´Ù. <a target="_blank" href="http://guide.nettention.com/cpp_ko#server_timer_callback" >¼­¹ö¿¡¼­ Å¸ÀÌ¸Ó ·çÇÁ RMI ÀÌº¥Æ® Ã³¸®ÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù. 		
		\param context CStartServerParameter.m_timerCallbackContext ¿¡¼­ ÀÔ·ÂµÈ °ª°ú µ¿ÀÏÇÕ´Ï´Ù.

		\~english
		Function called back at user worker thread pool periodically. This is a <a target="_blank" href="http://guide.nettention.com/cpp_en#server_timer_callback" >Managing Timer loop RMI Event from server</a> function.		
		\param context same as the value entered at CStartLanServerParameter.m_timerCallbackContext

		\~chinese
		ØßÌ°ìéÓ«??î¤user worker thread poolüŞ?îÜùŞ?¡£<a target="_blank" href="http://guide.nettention.com/cpp_zh#server_timer_callback" >î¤Ü×?Ğï?×âTimer Loop£¬RMI£¬Event</a> ÍíÒö¡£
		\param context ?î¤ CStartLanServerParameter.m_timerCallbackContext%?ìıîÜ?ßÓÔÒ¡£

		\~japanese
		á¶ïÒãÁÊàª´ªÈªËuser worker thread poolªÇ«³?«ë«Ğ«Ã«¯ªµªìªë??ªÇª¹¡£\ref server_timer_callbackÑ¦ÒöªÇª¹¡£
		\param context CStartServerParameter.m_timerCallbackContextªÇìıÕôªµªìª¿ö·ªÈÔÒª¸ªÇª¹¡£
		\~
		*/
		virtual void OnTick(void* /*context*/){}	
		
		/** 
		\~korean
		RMI È£Ãâ ¶Ç´Â ÀÌº¥Æ® ¹ß»ıÀ¸·Î ÀÎÇØ user worker¿¡¼­ callbackÀÌ È£ÃâµÇ±â Á÷Àü¿¡ È£ÃâµË´Ï´Ù.
		ÇÁ·Î±×·¥ ½ÇÇà ¼º´É ÃøÁ¤À» À§ÇØ »ç¿ëÇÏ¼Åµµ µË´Ï´Ù.

		\~english
		It calls before calling callback at user worker because of RMI calling or event occuring.
		You can use it for measuring program running performance.

		\~chinese
		RMI û¼Ğ£ûäíºì×eventîÜ?ßæ£¬î¤user workerñécallbackù¬û¼Ğ£ñıîñû¼Ğ£¡£
		å¥Ê¦ì¤?Öõ?ïÒïïßí?ú¼àõÒöì»ŞÅéÄ¡£

		\~japanese
		RMIû¼ªÓõóª·ªŞª¿ªÏ«¤«Ù«ó«È?ßæªËªèªÃªÆuser workerªÇcallbackª¬û¼ªÓõóªµªìªëòÁîñªËû¼ªÓõóªµªìªŞª¹¡£
		«×«í«°«é«à?ú¼àõÒöö´ïÒªÎª¿ªáªËŞÅªÃªÆªâÕŞª¤ªÇª¹¡£
		\~
		*/
		virtual void OnUserWorkerThreadCallbackBegin(CUserWorkerThreadCallbackContext* /*ctx*/){}
		/** 
		\~korean
		RMI È£Ãâ ¶Ç´Â ÀÌº¥Æ® ¹ß»ıÀ¸·Î ÀÎÇØ user worker¿¡¼­ callbackÀÌ ¸®ÅÏÇÑ Á÷ÈÄ¿¡ È£ÃâµË´Ï´Ù.
		ÇÁ·Î±×·¥ ½ÇÇà ¼º´É ÃøÁ¤À» À§ÇØ »ç¿ëÇÏ¼Åµµ µË´Ï´Ù.

		\~english
		It calls right after calling callback at user worker because of RMI calling or event occuring.
		You can use it for measuring program running performance.

		\~chinese
		RMI û¼Ğ£ûäíºì×event?ßæ£¬î¤user workerñécallbackÚ÷üŞñıı¨û¼Ğ£¡£
		å¥Ê¦ì¤éÄî¤?ïÒïïßí?ú¼àõÒöÛ°Øü¡£

		\~japanese
		RMIû¼ªÓõóª·ªŞª¿ªÏ«¤«Ù«ó«È?ßæªËªèªÃªÆuser workerªÇcallbackª¬«ê«¿?«óª·ª¿òÁı­ªËû¼ªÓõóªµªìªŞª¹¡£
		«×«í«°«é«à?ú¼àõÒöö´ïÒªÎª¿ªáªËŞÅªÃªÆªâÕŞª¤ªÇª¹¡£
		\~
		*/
		virtual void OnUserWorkerThreadCallbackEnd(CUserWorkerThreadCallbackContext* /*ctx*/){}

	};

	/**  @} */



	/** Add your event handler to these member objects. 
	
	Example:
	\code
	CNetClient* c = CNetClient::Create();
	c->OnError = [&](ErrorInfo* e)->{
		// Your event handler code here.
	};
	\endcode
	*/
	class HasCoreEventFunctionObjects
	{
	public:
		/// See Proud.INetCoreEvent.OnError for details.
		LambdaBaseHolder_Param1<void, ErrorInfo *> OnError;
		/// See Proud.INetCoreEvent.OnException for details.
		LambdaBaseHolder_Param1<void, const Exception&> OnException;
		/// See Proud.INetCoreEvent.OnInformation for details.
		LambdaBaseHolder_Param1<void, ErrorInfo*> OnInformation;
		/// See Proud.INetCoreEvent.OnNoRmiProcessed for details.
		LambdaBaseHolder_Param1<void, RmiID> OnNoRmiProcessed;
		/// See Proud.INetCoreEvent.OnReceiveUserMessage for details.
		LambdaBaseHolder_Param4<void, HostID, const RmiContext&, uint8_t*, int> OnReceiveUserMessage;
		/// See Proud.INetCoreEvent.OnWarning for details.
		LambdaBaseHolder_Param1<void, ErrorInfo*> OnWarning;
		/// See Proud.INetCoreEvent.OnTick for details.
		LambdaBaseHolder_Param1<void, void*> OnTick;
		/// See Proud.INetCoreEvent.OnUserWorkerThreadCallbackBegin for details.
		LambdaBaseHolder_Param0<void> OnUserWorkerThreadCallbackBegin;
		/// See Proud.INetCoreEvent.OnUserWorkerThreadCallbackEnd for details.
		LambdaBaseHolder_Param0<void> OnUserWorkerThreadCallbackEnd;
	};
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
