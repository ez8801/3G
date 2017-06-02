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
#include "Enums.h"
#include "AddrPort.h"
//#include "NetPtr.h"
#include "Ptr.h"
#include "ProcHeap.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	class ErrorInfo;

	/** 
	\~korean
	¿¡·¯ Á¤º¸¸¦ ´ã´Â °´Ã¼ÀÇ ½º¸¶Æ® Æ÷ÀÎÅÍ
	- ErrorInfoPtr Àº ÀÚÁÖ »ı±â´Â °´Ã¼µµ ¾Æ´Ï¹Ç·Î fast allocÀ» ¾È¾´´Ù.

	\~english
	Smart pointer of the object that contains error info
	- ErrorInfoPtr does not use fast alloc since it does not exist often

	\~chinese
	??õó?ãáãÓîÜòªÒöpointer¡£
	- ì×?ErrorInfoPtrÜôãÀ?ßÈßæà÷îÜ?ßÚ£¬ÜôéÄfast alloc¡£

	\~japanese
	«¨«é?ï×ÜÃªòìıªìªë«ª«Ö«¸«§«¯«ÈªÎ«¹«Ş?«È«İ«¤«ó«¿?
	- ErrorInfoPtrªÏªèª¯?ßæª¹ªë«ª«Ö«¸«§«¯«ÈªÇªâªÊª¤ªÎªÇ¡¢fast allocªòŞÅª¤ªŞª»ªó¡£
	\~
	*/
	typedef RefCount<ErrorInfo> ErrorInfoPtr;

	/** 
	\~korean
	¿¡·¯(¶Ç´Â ¼º°ø) Á¤º¸¸¦ ´ãÀº °´Ã¼ÀÔ´Ï´Ù.

	\~english
	Object contains error(or success) info

	\~chinese
	??õó?£¨ûäíºà÷Íí£©ãáãÓîÜ?ßÚ¡£

	\~japanese
	«¨«é?£¨ªŞª¿ªÏà÷Íí£©ï×ÜÃªòìıªìª¿«ª«Ö«¸«§«¯«ÈªÇª¹¡£
	\~
	*/
	class ErrorInfo
	{
	public:
		/** 
		\~korean
		¿¡·¯ÀÇ Á¾·ùÀÔ´Ï´Ù. ¿¡·¯°¡ ¾øÀ¸¸é ErrorType_Ok ÀÔ´Ï´Ù.

		\~english
		Error type. If there is no error then ErrorType_Ok.

		\~chinese
		??îÜ??¡£?êó??îÜ?ErrorType_Ok¡£

		\~japanese
		«¨«é?ªÎğú×¾ªÇª¹¡£«¨«é?ª¬ªÊª±ªìªĞErrorType_OkªÇª¹¡£
		\~
		*/
		ErrorType m_errorType;
		/** 
		\~korean
		m_errorType ÀÇ ¼¼ºÎ °ªÀÔ´Ï´Ù. 
		
		INetClientEvent.OnLeaveServer ¿Í INetServerEvent.OnClientLeave ¿¡¼­
		m_detailType Àº ¿¬°á ÇØÁ¦ÀÇ ´õ ÀÚ¼¼ÇÑ °æÀ§¸¦ ³ªÅ¸³À´Ï´Ù.
		¿¹¸¦ µé¾î Å¬¶óÀÌ¾ğÆ® ÇÁ·Î±×·¥ÀÌ Á¾·áÇÏ¸é¼­ ¿¬°áÀÌ ÇØÁ¦µÇ¸é ErrorType_TCPConnectFailure ¸¦, 
		Å¬¶óÀÌ¾ğÆ®ÀÇ Àü¿øÀÌ³ª È¸¼±ÀÌ ²÷¾îÁ®¼­ ÇØÁ¦µÈ °æ¿ì¸é ErrorType_ConnectServerTimeout °¡ µé¾î°©´Ï´Ù.

		\~english
		Value for m_errorType 
		
		m_detailType indicates how disconnection occurs with more details at INetClientEvent.OnLeaveServer and INetServerEvent.OnClientLeave
		For an example, it enters ErrorType_TCPConnectFailure when disconnection occurs as client program terminates
 		or enters ErrorType_ConnectServerTimeout when disconnection occurs due to power failure and/or physical cable disconnection.

		\~chinese
		m_errorType îÜ???¡£

		î¤ INetClientEvent.OnLeaveServer%ûú INetServerEvent.OnClientLeave%ñém_detailType?ãÆú°ğ¶?ïÈîÜÌÚ???é»¡£
		ÖÇåıèÌÊ«îÜïïßí?ò­????ïÈîÜ?£¬åıÍı ErrorType_TCPConnectFailure%ú°ğ¶ãÀì×?èÌÊ«îÜ?ê¹ûäíº?ÖØ??ğãà÷îÜ£¬??ìıErrorType_ConnectServerTimeout¡£

		\~japanese
		m_errorType ªÎá¬İ»ö·ªÇª¹¡£

		INetClientEvent.OnLeaveServerªÈINetServerEvent.OnClientLeaveªÇm_detailTypeªÏ¡¢Ö§Ì¿ú°ğ¶ªÎªâªÃªÈßÙª·ª¤?êÕªòøúª·ªŞª¹¡£
		ÖÇª¨ªĞ¡¢«¯«é«¤«¢«ó«È«×«í«°«é«àª¬ğûÖõª·ªÊª¬ªéïÈ?ª¬ú°ğ¶ªµªìª¿ªéErrorType_TCPConnectFailure ªò¡¢«¯«é«¤«¢«ó«ÈªÎï³ê¹ªäüŞàÊª¬ï·ªìªÆú°ğ¶ªµªìª¿íŞùêªÊªéErrorType_ConnectServerTimeoutª¬ìıªêªŞª¹¡£
		
		\~
		*/
		ErrorType m_detailType;

		/**
		\~korean
		¿¡·¯°¡ ¼ÒÄÏ ¿¡·¯ÀÎ °æ¿ì ¼ÒÄÏ ¿¡·¯ ÄÚµå

		\~english
		Error code for socket error 

		\~chinese
		??ãÀsocket???îÜsocket??ÓÛ?¡£

		\~japanese
		«¨«é?ª¬«½«±«Ã«È«¨«é?ªÇª¢ªëíŞùê¡¢«½«±«Ã«È«¨«é?«³?«É
		\~
		*/
		SocketErrorCode m_socketError;

		/**
		\~korean
		¿¡·¯ÀÇ ¹ß»ı È£½ºÆ®

		\~english
		Host that occur error

		\~chinese
		?ßæ??ñ«Ïõ¡£

		\~japanese
		«¨«é?ªÎ?ßæ«Û«¹«È
		\~
		*/
		HostID m_remote;

		/**
		\~korean
		Ãß°¡ ¹®ÀÚ¿­ Á¤º¸ 

		\~english
		Information of additional string

		\~chinese
		ôÕÊ¥í®İ¬ÍúãáãÓ¡£

		\~japanese
		õÚÊ¥Ùşí®Öªï×ÜÃ
		\~
		*/
		String m_comment;

		// ¼­¹ö ¿¬°á ½ÃµµÁß ¿¡·¯ µî¿¡¼­ À¯È¿ÇÑ °ªÀ¸·Î, »ó´ë¹æ ÁÖ¼Ò
		AddrPort m_remoteAddr;

		/**
		\~korean
		ErrorType_InvalidPacketFormat ÀÇ °æ¿ì Àß¸øµÈ ¸¶Áö¸· ¸Ş¼¼Áö¸¦ ÀúÀåÇÑ´Ù.

		\~english
		Save wrong last message when case of ErrorType_InvalidPacketFormat

		\~chinese
		ErrorType_InvalidPacketFormat îÜ?ı¦?ğí??îÜõÌı¨ãáãÓ¡£

		\~japanese
		ErrorType_InvalidPacketFormat ªÎíŞùê¡¢ÊàêŞªÃª¿õÌı­ªÎ«á«Ã«»?«¸ªòÜÁğíª·ªŞª¹¡£
		\~
		*/
		ByteArray m_lastReceivedMessage;

#if defined(_WIN32)    

		/**
		\~korean
		DB¿¡¼­ »ç¿ëµÉ HRESULT°ªÀÔ´Ï´Ù.

		\~english
		HRESULT value using for DB

		\~chinese
		î¤DBé©ŞÅéÄîÜHRESULT?¡£

		\~japanese
		DBªÇŞÅªïªìªëHRESULTö·ªÇª¹¡£
		\~
		*/
		HRESULT m_hResult;
#endif
        
		/**
		\~korean
		DB¿¡¼­ »ç¿ëµÉ ¼Ò½ºÀÔ´Ï´Ù.

		\~english
		Source using for DB

		\~chinese
		î¤DBé©ŞÅéÄîÜê¹£¨source£©¡£

		\~japanese
		DBªÇŞÅªïªìªë«½?«¹ªÇª¹¡£
		\~
		*/
		String m_source;

#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// ÀÌ Å¬·¡½º´Â ProudNet DLL °æ¿ì¸¦ À§ÇØ Ä¿½ºÅÒ ÇÒ´çÀÚ¸¦ ¾²µÇ fast heapÀ» ¾²Áö ¾Ê´Â´Ù.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif 


		PROUD_API ErrorInfo();

		/**
		\~korean
		ErrorInfo::FromSocketError() À» ÅëÇÏ¿© Á» ´õ °£ÆíÇÏ°Ô ErrorInfo ¸¦ ¸¸µì´Ï´Ù. 
		\param code ErrorType
		\param se ¼ÒÄÏ ¿¡·¯ type
		\return »ı¼ºµÈ ErrorInfoPtr

		\~english TODO:translate needed.
		Through ErrorInfo::FromSocketError(), you can make ErrorInfo more conveniently. 
		\param code ErrorType
		\param se Socket error type
		\return generated ErrorInfoPtr

		\~chinese
		÷×? ErrorInfo::FromSocketError()%£¬ÌÚÛ°øµîÜğ¤íÂErrorInfo¡£
		\param code ErrorType
		\param se socket??type¡£
		\return ßæà÷îÜErrorInfoPtr¡£

		\~japanese
		ErrorInfo::FromSocketError()ªò÷×ª¸ªâªÃªÈÊÛ?ªËErrorInfoªòíÂªêªŞª¹¡£ 
		\param code ErrorType
		\param se «½«±«Ã«È«¨«é? type
		\return ßæà÷ªµªìª¿ ErrorInfoPtr
		
		\~
		*/
		PROUD_API static ErrorInfoPtr FromSocketError(ErrorType code, SocketErrorCode se);

		/**
		\~korean
		ErrorInfo::From() À» ÅëÇÏ¿© Á» ´õ °£ÆíÇÏ°Ô ErrorInfo ¸¦ ¸¸µì´Ï´Ù.
		\param errorType ErrorType ÀÔ´Ï´Ù.
		\param remote »ó´ëÃøÀÇ HostID
		\param comment Error¿¡ °ü·ÃÇÑ Ã·ºÎ String
		\param lastReceivedMessage ¸¶Áö¸· ¹ŞÀº Message
		\return »ı¼ºµÈ ErrorInfoPtr

		\~english TODO:translate needed.
		Through ErrorInfo::From(), you can make ErrorInfo more more conveniently.
		\param errorType This is ErrorType
		\param remote HostID of the remote correspondent
		\param comment String Attached string related to the error
		\param lastReceivedMessage Message Last received message
		\return Generated ErrorInfoPtr

		\~chinese
		÷×? ErrorInfo::From()%£¬ÌÚÛ°øµîÜğ¤íÂErrorInfo¡£
		\param errorType ãÀErrorType¡£
		\param remote ?Û°îÜHostID¡£
		\param comment ?éÍErrorîÜİ¾Ê¥String¡£
		\param lastReceivedMessage õÌı¨ïÈâ¥îÜMessage¡£
		\return ßæà÷îÜErrorInfoPtr¡£

		\~japanese
		ErrorInfo::From() ªò÷×ª¸ªâªÃªÈÊÛ?ªË ErrorInfoªòíÂªêªŞª¹¡£
		\param errorType ErrorType ªÇª¹¡£
		\param remote ßÓâ¢ö°ªÎ HostID
		\param comment ErrorªË?Ö§ª¹ªëôÕÜõString
		\param lastReceivedMessage õÌı­ªËáôª±ª¿Message
		\return ßæà÷ªµªìª¿ErrorInfoPtr
		\~
		*/
		PROUD_API static ErrorInfoPtr From(ErrorType errorType, HostID remote = HostID_None, const String &comment = String(), const ByteArray &lastReceivedMessage = ByteArray() );

		/** 
		\~korean 
		ErrorInfo ¿¡ ÀúÀåµÈ ¸ğµç Á¤º¸¸¦ String À¸·Î ¸®ÅÏÇØÁİ´Ï´Ù.

		\~english 
		Change error contents to string 

		\~chinese
		÷êá¶êó?ğíÓğErrorInfoîÜãáãÓÚ÷üŞò¸String¡£

		\~japanese
		ErrorInfoªËÜÁğíªµªìª¿îïªÆªÎï×ÜÃªòStringªË«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		PROUD_API String ToString() const;

		/** 
		\~korean 
		°´Ã¼ ÀÚ½ÅÀ» »õ °´Ã¼¿¡ »çº»À» ¶å´Ï´Ù. 

		\~english TODO:translate needed.
		The object itself is copied in a new object. 

		\~chinese
		÷ê?ßÚÜâãó?ğ¤ÓğãæîÜ?ßÚ×ì¡£

		\~japanese
		«ª«Ö«¸«§«¯«Èí»?ªòãæª·ª¤«ª«Ö«¸«§«¯«ÈªË«³«Ô?ª·ªŞª¹¡£
		\~
		*/
		ErrorInfo* Clone();

		/** 
		\~korean 
		¿¡·¯ ³»¿ëÀ» ¹®ÀÚ¿­·Î º¯È¯ÇÑ´Ù.

		\~english 
		Change error contents to string

		\~chinese
		÷ê??ãáãÓ??à÷í®İ¬Íú¡£

		\~japanese
		«¨«é??é»ªòÙşí®ÖªªË?üµª·ªŞª¹¡£
		\~
		*/
		PROUD_API static const PNTCHAR* TypeToString(ErrorType e);
		PROUD_API static const PNTCHAR* TypeToStringByLangID(ErrorType e, int languageID);

		/** 
		\~korean 
		ErrorType °ªÀ» ¹®ÀÚ¿­·Î º¯È¯ÇÑ´Ù. (ÇÑ±¹¾î)

		\~english 
		Change ErrorType value to string (Korean)

		\~chinese
		÷êErrorType???à÷í®İ¬Íú¡££¨?Ùş£©

		\~japanese
		ErrorTypeö·ªòÙşí®ÖªªË?üµª·ªŞª¹¡££¨ùÛ?åŞ£©
		\~
		*/
		PROUD_API static const PNTCHAR* TypeToString_Kor(ErrorType e);

		/** 
		\~korean 
		ErrorType °ªÀ» ¹®ÀÚ¿­·Î º¯È¯ÇÑ´Ù. (¿µ¾î)

		\~english 
		Change ErrorType value to string (English)

		\~chinese
		÷êErrorType???à÷í®İ¬Íú¡££¨çÈÙş£©

		\~japanese
		ErrorTypeö·ªòÙşí®ÖªªË?üµª·ªŞª¹¡££¨çÈåŞ£©
		\~
		*/
		PROUD_API static const PNTCHAR* TypeToString_Eng(ErrorType e);

		/** 
		\~korean 
		ErrorType °ªÀ» ¹®ÀÚ¿­·Î º¯È¯ÇÑ´Ù. (°£Ã¼ Áß±¹¾î)

		\~english 
		Change ErrorType value to string (Simplified Chinese)

		\~chinese
		÷êErrorType???à÷í®İ¬Íú¡££¨??ñéÙş£©

		\~japanese
		ErrorTypeö·ªòÙşí®ÖªªË?üµª·ªŞª¹¡££¨ÊÛ?ñé?åŞ£©
		\~
		*/
		PROUD_API static const PNTCHAR* TypeToString_Chn(ErrorType e);
	};

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
