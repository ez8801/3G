/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


ÀÌ ÇÁ·Î±×·¥ÀÇ ÀúÀÛ±ÇÀº ³İÅÙ¼Ç¿¡°Ô ÀÖ½À´Ï´Ù.
ÀÌ ÇÁ·Î±×·¥ÀÇ ¼öÁ¤, »ç¿ë, ¹èÆ÷¿¡ °ü·ÃµÈ »çÇ×Àº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾àÀ» µû¸£¸ç,
°è¾àÀ» ÁØ¼öÇÏÁö ¾Ê´Â °æ¿ì ¿øÄ¢ÀûÀ¸·Î ¹«´Ü »ç¿ëÀ» ±İÁöÇÕ´Ï´Ù.
¹«´Ü »ç¿ë¿¡ ÀÇÇÑ Ã¥ÀÓÀº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾à¼­¿¡ ¸í½ÃµÇ¾î ÀÖ½À´Ï´Ù.

** ÁÖÀÇ: ÀúÀÛ¹°¿¡ °üÇÑ À§ÀÇ ¸í½Ã¸¦ Á¦°ÅÇÏÁö ¸¶½Ê½Ã¿À.


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

#if defined(_WIN32)
#include "BasicTypes.h"
#include "dbenums.h"
#include "DbLoadedData2.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup db_group
	*  @{
	*/

	/**
	\~korean
	DB cache¿¡ ÀÇÇØ ·ÎµùµÇ´Â Å×ÀÌºíÀÇ ÀÌ¸§µéÀÔ´Ï´Ù.

	root node¸¦ À§ÇÑ Å×ÀÌºí ÀÌ¸§°ú child node¸¦ À§ÇÑ Å×ÀÌºí ÀÌ¸§µéÀ» ³ÖÀ¸½Ê½Ã¿À.
	child node¸¦ À§ÇÑ Å×ÀÌºí ÀÌ¸§Àº 0°³ ÀÌ»óÀÌ¾î¾ß ÇÕ´Ï´Ù.
	child node¸¦ À§ÇÑ Å×ÀÌºí ÀÌ¸§µé Áß¿¡´Â root node¸¦ À§ÇÑ Å×ÀÌºí ÀÌ¸§°ú °°Àº °ÍÀÌ ¾ø¾î¾ß ÇÕ´Ï´Ù.

	\~english

	\~japanese
	DB casheªËªèªÃªÆ«í?«Éªµªìªë«Æ?«Ö«ëÙ£ªÇª¹¡£
	root nodeªÎª¿ªáªÎ«Æ?«Ö«ëÙ£ªÈchild nodeªÎª¿ªáªÎ«Æ?«Ö«ëÙ£ªÊªÉªòìıªìªÆª¯ªÀªµª¤¡£ 
	child nodeªÎª¿ªáªÎ«Æ?«Ö«ëÙ£ªÏ0ËÁì¤ß¾ªÇªÏªÊª±ªìªĞªÊªêªŞª»ªó¡£
	child nodeªÎª¿ªáªÎ«Æ?«Ö«ëÙ£ªÎñéªËªÏ¡¢root nodeªÎª¿ªáªÎ«Æ?«Ö«ëÙ£ªÈÔÒª¸ªâªÎª¬ª¢ªÃªÆªÏª¤ª±ªŞª»ªó¡£

	\~
	*/
	class CCachedTableName
	{
	public:
		/** root node¸¦ À§ÇÑ Å×ÀÌºí ÀÌ¸§ */
		String m_rootTableName;
		/** child node¸¦ À§ÇÑ Å×ÀÌºí ÀÌ¸§ */
		CFastArray<Proud::String> m_childTableNames;
	};

	/**
	\~korean
	CDbCacheServer2¿¡¼­ Äİ¹éÇÏ´Â ÀÌº¥Æ®³ª °³¹ßÀÚ°¡ ±¸ÇöÇØ¾ß ÇÏ´Â ¸Ş¼­µå¸¦ Äİ¹éÀ» Ã³¸®ÇÏ´Â delegate °´Ã¼

	\~english
	This is delegate object that handle callback event from CDbCacheServer2 or callback method which developer has to realize.

	\~chinese
	î¤ CDbCacheServer2%üŞ??×âüŞ?eventûäíº??íºé©??îÜÛ°ÛöîÜdelegate?ßÚ¡£

	\~japanese
	CDbCacheServer2ªÇ«³?«ë«Ğ«Ã«¯ª¹ªë«¤«Ù«ó«ÈªÈª«ËÒ?íºª¬?úŞª·ªÊª±ªìªĞªÊªéªÊª¤«á«½«Ã«Éªò«³?«ë«Ğ«Ã«¯ª¹ªëdelegate«ª«Ö«¸«§«¯«È
	\~
	*/
	class IDbCacheServerDelegate2
	{
	public:
		virtual ~IDbCacheServerDelegate2() {}

		/**
		\~korean
		³»ºÎ ¿¡·¯ ¹ß»ı½Ã È£ÃâµË´Ï´Ù
		\param errorInfo ¿¡·¯¿¡ ´ëÇÑ Á¤º¸ÀÔ´Ï´Ù. ErrorInfo::ToString()À» ÀÌ¿ëÇÏ½Ã¸é °£ÆíÇÏ°Ô ÀÚ¼¼ÇÑ ¹®Á¦ÀÇ Á¤º¸¸¦ º¸½Ç ¼ö ÀÖ½À´Ï´Ù.

		\~english TODO:translate needed
		It is called when an internal error occurs
		\This is the information on an error. If you use ErrorInfo::ToString(), you can see the detailed information of the problem. 

		\~chinese
		?ßæ?İ»???û¼Ğ£¡£
		\param errorInfo ???îÜãáãÓ¡£××éÄ ErrorInfo::ToString()%îÜ?Ê¦ì¤Û°øµÊ×õó??îÜãáãÓ¡£

		\~japanese
		?İ»«¨«é??ßæãÁªËû¼ªÓõóªµªìªŞª¹¡£
		\param errorInfo «¨«é?ªË?ª¹ªëï×ÜÃªÇª¹¡£ErrorInfo::ToString()ªò××éÄª¹ªìªĞÊÛ?ªËßÙª·ª¯Ùığ¹ï×ÜÃª¬Ì¸ªéªìªŞª¹¡£

		\~
		*/
		virtual void OnError(ErrorInfo *errorInfo) = 0;

		/**
		\~korean
		³»ºÎ °æ°í ¹ß»ı½Ã È£ÃâµË´Ï´Ù. ¿¡·¯º¸´Ù´Â ³·Àº ¼öÀ§ÀÇ ¹®Á¦¸¦ º¸°íÇÔ.
		\param errorInfo ¿¡·¯¿¡ ´ëÇÑ Á¤º¸ÀÔ´Ï´Ù. ErrorInfo::ToString()À» ÀÌ¿ëÇÏ½Ã¸é °£ÆíÇÏ°Ô ÀÚ¼¼ÇÑ ¹®Á¦ÀÇ Á¤º¸¸¦ º¸½Ç ¼ö ÀÖ½À´Ï´Ù.

		\~english TODO:translate needed
		It is called when an internal warning occurs. This reports a problem with the level lower than an error. 
		\param errorInfo This is the information on an error. If you use ErrorInfo::ToString(), you can see the detailed information of the problem

		\~chinese
		?ßæ?İ»ÌíÍ±?û¼Ğ£¡£?Í±İï??â©øÁî¸îÜ??¡£
		\param errorInfo ???îÜãáãÓ¡£××éÄ ErrorInfo::ToString()%îÜ?Ê¦ì¤Û°øµÊ×õó??îÜãáãÓ¡£

		\~japanese
		?İ»ÌíÍ±ª¬?ßæãÁªËû¼ªÓõóªµªìªŞª¹¡£«¨«é?ªèªêªÏî¸ª¤«ì«Ù«ëªÎÙığ¹ªòÜÃÍ±ª·ªŞª¹¡£
		\param errorInfo «¨«é?ªË?ª¹ªëï×ÜÃªÇª¹¡£ErrorInfo::ToString()ªò××éÄª¹ªìªĞÊÛ?ªËßÙª·ª¯Ùığ¹ï×ÜÃª¬Ì¸ªéªìªŞª¹¡£

		\~
		*/
		virtual void OnWarning(ErrorInfo *errorInfo) = 0;

		/**
		\~korean
		Proud.ExceptionÀ¸·Î ÅëÇÕÇÕ´Ï´Ù.
		- ÀÏ¹İÀûÀ¸·Î À¯Àú ÄÚµå¿¡¼­ ³ª´Â ¿¡·¯¸¦ Ã³¸®ÇÕ´Ï´Ù.
		- À¯Àú´Â ÇÊ¿äÇÑ °ÍµéÀ» ±¸ÇöÇÏ¸é µË´Ï´Ù.
		- ExceptionTypeÀ¸·Î ÇØ´ç Exception °´Ã¼¸¦ ¾ò¾î¼­ »ç¿ëÇÏ¸é µË´Ï´Ù.
		- _com_error, void*, std::exceptionµîÀ» ¸ğµÎ Ã³¸®ÇÕ´Ï´Ù.
		¶ÇÇÑ catch(...)¸¦ Ã³¸®ÇÏ´Â OnUnhandledException()µµ ÀÖ½À´Ï´Ù.
		- void*´Â ¿¹¿Ü °´Ã¼ÀÇ Å¸ÀÔÀ» Ä³½ºÆÃÇØ¼­ ¹ŞÀ» ¼ö ÀÖ½À´Ï´Ù. °¡·É MFC CExceptionÀ» ¹Ş´Âµ¥ »ç¿ëµË´Ï´Ù.

		\~english
		Merge to Proud.Exception
		- It handle error that occur from user code.
		- User realize things that user needed.
		- You can use Exceptiontype that obtain Exception object.
		- It process _com_error, void*, std::exception, etc. Also there is OnUnhandledException() that handle catch(...)
		- void* can obtain exceptional object type by casting. For example, it uses obtaining MFC CException.

		\~chinese
		éÄ Proud.Exception%?ìéÑÃ?¡£
		- ìéÚõ?×â?éÄ?ÓÛ??ßæîÜ??¡£
		- éÄ???âÍé©îÜ?à¤?Ê¦¡£
		- éÄExceptionType?Ôğ?ŞÅéÄßÓ?Exception?ßÚ?Ê¦¡£
		- îïİ»?×â_com_error, void*, std::exception Ôõ¡£å¥êó?×âcatch(...)îÜOnUnhandledException()¡£
		- ??ÖÇèâ?ßÚîÜ?úşì¤ı¨Ê¦ì¤ïÈâ¥void*¡£İïåıïÈâ¥MFC CException%îÜ?ı¦ŞÅéÄ¡£

		\~japanese
		Proud.ExceptionªË÷Öùêª·ªŞª¹¡£
		- ìéÚõîÜªË«æ?«¶?«³?«ÉªÇúŞªìªë«¨«é?ªò?×âª·ªŞª¹¡£
		- «æ?«¶?ªÏù±é©ªÊª³ªÈªò?úŞª¹ªìªĞÕŞª¤ªÇª¹¡£
		- ExceptionTypeªÇú±?Exception«ª«Ö«¸«§«¯«ÈªòÔğªÆŞÅª¨ªĞÕŞª¤ªÇª¹¡£
		- _com_error, void*, std::exceptionªÊªÉªòîïªÆ?×âª·ªŞª¹¡£
		ªŞª¿¡¢catch(...)ªò?×âª¹ªëOnUnhandledException()ªâª¢ªêªŞª¹¡£
		- void*ªÏÖÇèâ«ª«Ö«¸«§«¯«ÈªÎ«¿«¤«×ªò«­«ã«¹«Æ«£«ó«°ª·ªÆá®ª¨ªŞª¹¡£?ªË¡¢MFC CExceptionªòáôª±ªëª³ªÈªËŞÅªïªìªŞª¹¡£

		\~
		*/
		virtual void OnException(const Exception &e) = 0;


		/**
		\~korean
		DB cache server2¿¡¼­ DBMS¿¡ Á÷Á¢ ±â·ÏÇÏ´Â Ã³¸®´Â ºñµ¿±â·Î ½ÇÇàµÈ´Ù. ÀÌ ¸Ş¼­µå´Â ºñµ¿±â·Î ±â·ÏÇÏ´Â Ã³¸®°¡
		¿Ï·áµÉ ¶§¸¶´Ù DB cache serverÀÇ ³»ºÎ ½º·¹µå·ÎºÎÅÍ Äİ¹éµË´Ï´Ù.
		- Visual Studio 2005 ÀÌ»ó¿¡¼­´Â override keyword »ç¿ëÀ» ±ÇÀåÇÕ´Ï´Ù.
		\param type ¿Ï·áµÈ DBMS ±â·Ï(PropNode)ÀÇ Á¾·ù (Âü°í \ref DbmsWritePropNodePendType)

		\~english
		Direct writing process to DBMS is running asynchronously in DB cache server2. When asynchronous writting process has finished, this method will callback from internal thread in DB cache server.
		- We recommend to use override keyword on Visual Studio 2005 or above.
		\param type Sort of finished DBMS history (PropNode)

		\~chinese
		?DB cache serverèÙDBMSòÁïÈ??îÜ?×âé©ì¤?ÜÆ?ú¼¡£Øß??ÜÆ??îÜ?×âèÇà÷îÜ?ı¦ó®Û°Ûö???İ»?ïïüŞ?DB cache server¡£
		- Visual Studio 2005ì¤ß¾Ëï?ŞÅéÄoverride keyword¡£
		\param type èÇà÷îÜDBMS??£¨PropNode£©îÜ??£¨?ÍÅ \ref DbmsWritePropNodePendType£©¡£

		\~japanese
		DB cache serve2ªÇDBMSªËòÁïÈÑÀ?ª¹ªë?×âªÏŞªÔÒÑ¢ªÇ?ú¼ªµªìªŞª¹¡£ª³ªÎ«á«½«Ã«ÉªÏŞªÔÒÑ¢ªÇÑÀ?ª¹ªë?×âª¬èÇÖõª¹ªëãÁª´ªÈªËDB cache serverªÎ?İ»«¹«ì«Ã«Éª«ªé«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		- Visual Studio 2005ì¤ß¾ªÇªÏoverride keywordŞÅéÄªòªª?ªáª·ªŞª¹¡£
		\param type èÇÖõªµªìª¿DBMSÑÀ?(PropNode)ªÎğú×¾(?ÍÅ \ref DbmsWritePropNodePendType)

		\~
		 */
		virtual void OnDbmsWriteDone(DbmsWritePropNodePendType /*type*/) {}
	};

	/**
	\~korean
	CDbCacheServer2°¡ ¼­¹ö ÀÛµ¿À» ½ÃÀÛÇÏ±â À§ÇØ Á¦°øÇØ¾ß ÇÏ´Â ÆÄ¶ó¸ŞÅÍ

	\~english
	Parameter that must be provided in order to initiate CDbCacheServer2

	\~chinese
	CDbCacheServer ?ÖõÜ×?Ğï?ã·??ğ«ÍêîÜ??¡£

	\~japanese
	CDbCacheServer2ª¬«µ?«Ğ?íÂÔÑªòËÒã·ª¹ªëª¿ªáªËğ«Íêª·ªÊª±ªìªĞªÊªéªÊª¤«Ñ«é«á?«¿?
	\~
	 */
	class CDbCacheServer2StartParameter
	{
	public:
		/**
		\~korean
		¼­¹öÀÇ ÁÖ¼Ò. ÀÚ¼¼ÇÑ °ÍÀº CStartServerParameterÀÇ °°Àº ÀÌ¸§ÀÇ ¸â¹ö Âü°í

		\~english
		Server address. Please refer the member of same name at CStartServerParameter for further details.

		\~chinese
		Ü×?Ğïò¢ò£¡£??îÜ??ÍÅ CStartServerParameter%îÜÔÒÙ£à÷?¡£

		\~japanese
		«µ?«Ğ?ªÎ«¢«É«ì«¹¡£ßÙª·ª¯ªÏ¡¢CStartServerParameterªÎÔÒª¸Ù£îñªÎ«á«ó«Ğ?ªòª´?ğÎª¯ªÀªµª¤¡£
		\~
		 */
		Proud::String m_serverIP;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®ÀÇ ¸®½º´× ¼ÒÄÏÀÌ ¹ÙÀÎµùµÉ ÁÖ¼ÒÀÔ´Ï´Ù.
		- ÃÊ±â°ªÀº ºó ¹®ÀÚ¿­ÀÔ´Ï´Ù.
		- Åë»óÀûÀ¸·Î ºó ¹®ÀÚ¿­À» ÁöÁ¤ÇÏÁö¸¸ Å¬¶óÀÌ¾ğÆ®°¡ ³×Æ®¿öÅ© ÀÎÅÍÆäÀÌ½º(NIC)¸¦ 2°³ ÀÌ»ó °¡Áö´Â °æ¿ì,
		±×¸®°í ±×°Íµé Áß ÇÏ³ª¸¸ÀÌ ´Ù¸¥ CLanClient¿¡¼­ ¿À´Â Á¢¼Ó ¿äÃ»À» ¹ŞÀ» ¼ö ÀÖ´Â °æ¿ì ¿©±â¿¡ ÇØ´çµË´Ï´Ù.
		NIC¿¡ ÁöÁ¤µÈ IP ¶Ç´Â È£½ºÆ® ÀÌ¸§À» ÁöÁ¤ÇØ¾ß ÇÕ´Ï´Ù. È£½ºÆ®¿¡ ÀÖ´Â NIC ÁÖ¼Ò ¸®½ºÆ®¸¦ ¾òÀ¸·Á¸é Proud.GetLocalIPAddresses¸¦ ¾µ ¼ö ÀÖ½À´Ï´Ù.
		- È£½ºÆ® ÀÌ¸§À» ÁöÁ¤ÇÒ °æ¿ì Å¬¶óÀÌ¾ğÆ®´Â ¼­¹ö·Î Á¢¼ÓÇÏ±â À§ÇÑ ÁÖ¼Ò·Î localhost¸¦ ÀÔ·ÂÇÒ °æ¿ì ¿¬°á ½ÇÆĞ¸¦ ÇÒ ¼ö ÀÖ½À´Ï´Ù. ÀÌ·¯ÇÑ °æ¿ì
		Å¬¶óÀÌ¾ğÆ®´Â ¼­¹ö·Î Á¢¼ÓÇÏ±â À§ÇØ ¼­¹ö È£½ºÆ®ÀÇ ÁÖ¼Ò¸¦ ¸í½ÃÀûÀ¸·Î ÀÔ·ÂÇØ¾ß ÇÕ´Ï´Ù.

		\~english
		The address that the listening socket of the client to be bound.
		- The initial value is an empty string.
		- Usually set as an empty string but in case when the client has 2 or more of network interfaces (NICs)
		   and when only one of them is able to recieve the connection request from other CLanClient, it is the case to use this.
		  The IP address or the host name designated by the NIC must be used. Proud.GetLocalIPAddresses can be used to get the NIC address list located in the host.
		- In the case that a host name is used, a connection failure can occur when localhost is set as the address to connect to the server for a client.
		  In this case, the client must be set clearly as the server host address in order to connect to the server.

		\~chinese
		èÌÊ«îÜâ¥??Ï¢é©ù¬boudîÜò¢ò£¡£
		- Ùù??ãÀÍöí®İ¬?¡£
		- ÷×ßÈ?ò¦ïÒÍöîÜí®İ¬Íú£¬?èÌÊ«?êó??ì¤ß¾??Í£Øü£¨NIC£©îÜ?ı¦£¬?êóñşêóĞìñéìé?î¤ïÈâ¥??îÜ CLanClient%??îÜ?ïÈé­?îÜ?ı¦??ó®??¡£
		é©ò¦ïÒ?NICò¦ïÒîÜIPûäíºñ«ÏõÙ£í®¡£é©ßÌ?Ôğñ«ÏõîÜNICò¢ò£ÖªøúîÜ?Ê¦ì¤ŞÅéÄ Proud.GetLocalIPAddresses%¡£
		- ò¦ïÒñ«ÏõÙ£í®îÜ?ı¦£¬èÌÊ«?Öõ?ïÈÜ×?Ğï?ìılocalhotîÜ?ı¦Ê¦Òö??ïÈã÷?¡£??îÜï×?ù»£¬éÄ??Öõ?ïÈÜ×?Ğï??Ù¥ãÆàõîÜ?ìıÜ×?Ğïñ«ÏõîÜò¢ò£¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªÎ«ê«¹«Ë«ó«°«½«±«Ã«Èª¬«Ğ«¤«ó«Ç«£«ó«°ªµªìªë«¢«É«ì«¹ªÇª¹¡£
		- ôøÑ¢ö·ªÏÍöªÎÙşí®ÖªªÇª¹¡£
		- ÷×ßÈîÜªËÍöªÎÙşí®Öªªòò¦ïÒª·ªŞª¹ª¬¡¢«¯«é«¤«¢«ó«Èª¬«Í«Ã«È«ï?«¯«¤«ó«¿?«Õ«§?«¹(NIC)ªò2ËÁì¤ß¾ò¥ªÃªÆª¤ªëíŞùê¡¢ª½ª·ªÆª½ªìªéªÎìéªÄªÎªßª¬öâªÎCLanClientª«ªé?ªëïÈ?é©ôëªòáôª±ªéªìªëíŞùê¡¢ª³ªìªËú±?ª·ªŞª¹¡£
		NICªËò¦ïÒªµªìª¿IPªŞª¿ªÏ«Û«¹«ÈÙ£ªòò¦ïÒª·ªÆª¯ªÀªµª¤¡£«Û«¹«ÈªËª¢ªëNIC«¢«É«ì«¹«ê«¹«ÈªòÔğªëª¿ªáªËªÏ¡¢Proud.GetLocalIPAddressesªòŞÅª¦ª³ªÈª¬ªÇª­ªŞª¹¡£
		- «Û«¹«ÈÙ£ªòò¦ïÒª¹ªëíŞùê¡¢«¯«é«¤«¢«ó«ÈªÏ«µ?«Ğ?ªØïÈ?ª¹ªëª¿ªáªË«¢«É«ì«¹ªÇ¡¢localhostªòìıÕôª¹ªëíŞùê¡¢ïÈ?ã÷ø¨ªÎÊ¦Òöàõª¬ª¢ªêªŞª¹¡£ª³ªÎªèª¦ªÊíŞùê¡¢«¯«é«¤«¢«ó«ÈªÏ«µ?«Ğ?ªØïÈ?ª¹ªëª¿ªáªË«µ?«Ğ?«Û«¹«ÈªÎ«¢«É«ì«¹ªòÙ¥ãÆîÜªËìıÕôª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£

		\~
		*/
		String m_localNicAddr;

		/**
		\~korean
		TCP ¸®½º´× Æ÷Æ®.
		ÀÚ¼¼ÇÑ °ÍÀº CStartServerParameterÀÇ °°Àº ÀÌ¸§ÀÇ ¸â¹ö Âü°í

		\~english
		TCP listening port.
		Please refer the member of same name at CStartServerParameter for further details.

		\~chinese
		TCP â¥?Ó®Ï¢¡£
		??îÜ??ÍÅ CStartServerParameter%îÜÔÒÙ£à÷?¡£

		\~japanese
		TCP«ê«¹«Ë«ó«°«İ?«È
		ßÙª·ª¯ªÏ¡¢CStartServerParameterªÎÔÒª¸Ù£îñªÎ«á«ó«Ğ?ªòª´?ğÎª¯ªÀ£óªÀª¤¡£

		\~
		 */
		int m_tcpPort;

		/**
		\~korean
		DBMS¿¡ Á¢¼ÓÇÏ±â À§ÇÑ connection string.
		- ¹®ÀÚ¿­¿¡ ´ëÇØ¼­´Â CAdoConnection.Open µµ¿ò¸» Âü°í

		\~english
		Connection string to connect to DBMS.
		- Please refer CAdoConnection.Open help section for text strings

		\~chinese
		?Öõ?ïÈDBMSîÜconnection string¡£
		- ?í®İ¬Íú??ÍÅ CAdoConnection.Open%?ğ¾¡£

		\~japanese
		DBMSªËïÈ?ª¹ªëª¿ªáªÎconnection string.		
		- Ùşí®ÖªªË?ª·ªÆªÏ¡¢CAdoConnection.OpenªÎ«Ø«ë«×ªòª´?ğÎª¯ªÀªµª¤¡£

		\~
		*/
		Proud::String m_DbmsConnectionString;

		/**
		\~korean
		ÀÌ DB ¼­¹ö¿¡ Á¢¼ÓÇÒ ¼ö ÀÖ´Â ÀÎÁõÅ°
		- Àı´ë ÀÌ °ªÀº °ÔÀÓ Å¬¶óÀÌ¾ğÆ®¿¡ ³ëÃâµÇ¾î¼­´Â ¾ÈµÈ´Ù.
		ÀÌ °ªÀº DB cache client(°ÔÀÓ ¼­¹ö µî)ÀÌ º» ¼­¹ö·Î Á¢¼ÓÇÏ±â À§ÇÑ ¸ñÀûÀ¸·Î »ç¿ëµÈ´Ù.

		\~english
		The authentication key that can connect to this DB server
		- This value MUST NOT be exposed to game clients.
		  This value is used by DB cache client(e.g. game servers and etc.) to connect to main server.

		\~chinese
		Ê¦ì¤?ïÈó®DBÜ×?ĞïîÜ???¡£
		- ?????ÜôÒöàÜ×©?èÌÊ«¡£
		ó®?ãÀDB cache client£¨êı?Ü×?ĞïÔõ£©?Öõ?ïÈÜâãóÜ×?Ğï?ÙÍîÜŞÅéÄîÜ¡£

		\~japanese
		ª³ªÎDB«µ?«Ğ?ªËïÈ?ªÇª­ªëìã?«­?
		- ï¾?ª³ªÎö·ªÏ«²?«à«¯«é«¤«¢«ó«ÈªËÖÚõóªµªìªÆªÏª¤ª±ªŞª»ªó¡£ 
		ª³ªÎö·ªÏDB cache client(«²?«à«µ?«Ğ?ªÊªÉ)ª¬Üâ«µ?«Ğ?ªØïÈ?ª¹ªëª¿ªáªÎÙÍîÜªÇŞÅªïªìªŞª¹¡£

		\~
		*/
		Proud::String m_authenticationKey;

		/**
		\~korean
		CDbCacheServer2°¡ ÇÊ¿ä·Î ÇÏ´Â delegate °´Ã¼ÀÇ Æ÷ÀÎÅÍ
		- ÀÌ °´Ã¼´Â CDbCacheServer2 °´Ã¼°¡ Á¸ÀçÇÏ´Â ÇÑ °è¼Ó Á¸ÀçÇØ¾ß ÇÕ´Ï´Ù.

		\~english
		Delegate object's pointer that CDbCacheServer requires
		- This object must exist as long as CDbCacheServer object exists.

		\~chinese
		âÍé© CDbCacheServer2%îÜdelegate?ßÚîÜpointer¡£
		- ñşé© CDbCacheServer2%?ßÚğíî¤£¬ó®?ßÚé©ìéòÁğíî¤¡£

		\~japanese
		CDbCacheServer2ª¬ù±é©ªÈª¹ªëdelegate«ª«Ö«¸«§«¯«ÈªÎ«İ«¤«ó«¿?
		- ª³ªÎ«ª«Ö«¸«§«¯«ÈªÏCDbCacheServer2«ª«Ö«¸«§«¯«Èª¬ğíî¤ª¹ªëùÚªê¡¢?ª±ªÆğíî¤ª¹ªëù±é©ª¬ª¢ªêªŞª¹¡£

		\~
		*/
		IDbCacheServerDelegate2* m_delegate;

		/**
		\~korean
		DB cache¿¡ ÀÇÇØ ·Îµù,ÀúÀåÀÌ ÀÏ¾î³¯ Å×ÀÌºíµéÀÇ ÀÌ¸§ÀÔ´Ï´Ù.
		Root table°ú child tableµéÀÇ ÀÌ¸§À» ¿©±â¿¡ ³ÖÀ¸½Ê½Ã¿À.
		ÀÚ¼¼ÇÑ °ÍÀº CCachedTableName À» Âü°íÇÏ½Ê½Ã¿À.

		\~english
		Names of tables to be loaded and saved by DB cache.
		Input names of root and child tables here.
		Refer to CCachedTable for details.

		\~chinese
		î¤DB?ğíÊ¥?ÜÁğíîÜøúîÜÙ£?¡£
		î¤ó®?ìıRoot tableûúchild tableîÜÙ£?¡£
		??îÜ??ÍÅCCachedTableName¡£

		\~japanese
		DB cacheªËªèªÃªÆ«í?«Ç«£«ó«°¡¢ÜÁğíªµªìªë«Æ?«Ö«ëÙ£ªÇª¹¡£
		Root tableªÈchild £ô£á£â£ì£åªÎÙ£îñªòª³ª³ªËìıªìªÆª¯ªÀªµª¤¡£
		ßÙª·ª¯ªÏ¡¢CCachedTableNameªòª´?ğÎª¯ªÀªµª¤¡£

		\~
		 */
		CFastArray<CCachedTableName> m_tableNames;

		/**
		\~korean
		DBCacheServer2¿¡ ºñµ¶Á¡Àû Á¢±ÙÀ» Çã¿ëÇÏ´ÂÁö¿¡ ´ëÇÑ ¿©ºÎÀÔ´Ï´Ù. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù.
		- ±âº»ÀûÀ¸·Î falseÀÔ´Ï´Ù.

		\~english
		Whether to allow or not to allow a non-exclusive access to DBCacheServer. This is a <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function.
		- The default value is false.

		\~chinese
		ãÀÜúëÃ??DBCacheServer2îÜŞª?ï¿ïÈĞÎ¡£ãÀ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%ÍíÒö¡£
		- Ùù??false¡£

		\~japanese
		DBCacheServer2ªËŞª?ï¿îÜïÈĞÎªòúÉé»ª¹ªëª«ªÉª¦ª«ªË?ª¹ªë«»«Ã«Æ«£«ó«°ªÎö·ªÇª¹¡£<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> Ñ¦ÒöªÇª¹¡£
		- ĞñÜâîÜªË falseªÇª¹¡£

		\~
		*/
		bool	m_allowNonExclusiveAccess;

		/**
		\~korean
		ÀÌ °ªÀÌ nullÀÌ ¾Æ´Ï¸é, ¿ÜºÎ networker thread¸¦ »ç¿ëÇÕ´Ï´Ù.
		Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool¿Í °°Àº ¿ªÇÒÀ» ÇÕ´Ï´Ù.

		\~english 
		If this value is not null, use an external networker thread. 
		It performs the same role as Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool. 

		\~chinese
		ó®?ÜôãÀnullîÜ?£¬ŞÅéÄèâİ»networker thread¡£
		ÑÃó·? Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool%ìé?îÜíÂéÄ¡£

		\~japanese
		ª³ªÎö·ª¬nullªÇªÏªÊª±ªìªĞ¡¢èâİ»networker threadªòŞÅéÄª·ªŞª¹¡£
		Proud.CStartLanServerParameter.m_externalNetWorkerThreadPoolªÈÔÒª¸æµùÜªòª·ªŞª¹¡£

		\~
		*/
		CThreadPool* m_externalNetWorkerThreadPool;

		/**
		\~korean
		ÀÌ °ªÀÌ nullÀÌ ¾Æ´Ï¸é, ¿ÜºÎ user worker thread¸¦ »ç¿ëÇÕ´Ï´Ù.
		Proud.CStartLanServerParameter.m_externalUserWorkerThreadPool¿Í °°Àº ¿ªÇÒÀ» ÇÕ´Ï´Ù.

		\~english 
		If this value is not null, use an external networker thread.
		It performs the same role as Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool.

		\~chinese
		ó®?ÜôãÀnullîÜ?£¬ŞÅéÄèâİ»user worker thread¡£
		ÑÃó·? Proud.CStartLanServerParameter.m_externalUserWorkerThreadPool%ìé?îÜíÂéÄ¡£

		\~japanese
		ª³ªÎö·ª¬nullªÇªÏªÊª±ªìªĞ¡¢èâİ»user worker threadªòŞÅéÄª·ªŞª¹¡£
		Proud.CStartLanServerParameter.m_externalUserWorkerThreadPoolªÈÔÒª¸æµùÜªòª·ªŞª¹¡£

		\~
		*/
		CThreadPool* m_externalUserWorkerThreadPool;

		/**
		\~korean DB Ã³¸®¸¦ À§ÇÑ ½º·¹µå Ç®ÀÇ ½º·¡µå °³¼öÀÔ´Ï´Ù.
		- ÃÖ¼ÒÇÑ 1Àº ÁöÁ¤ µÇ¾î¾ß ÇÕ´Ï´Ù.
		- DB Ã³¸®´Â ³»ºÎÀûÀ¸·Î device timeÀ» °¡Áö±â ¶§¹®¿¡ ÃæºĞÈ÷ ¸¹Àº ¼ö¸¦ µÎ´Â °ÍÀÌ ÁÁ½À´Ï´Ù. (°¡·É 100°³)
		- ÃÊ±â°ªÀº 10ÀÔ´Ï´Ù. 0À» ÁöÁ¤ÇÏ¸é CPU °¹¼ö·Î ÁöÁ¤µË´Ï´Ù.

		\~english It is the number of thread pools for DB processing.
		- At least ¡°1¡± should be set.
		- DB processing has the internal device time, so it is recommended to have many threads. (ex. 100)
		- Initial value is ¡°10¡±. If setting ¡°0¡±, it will be set as the number of CPUs.

		\~chinese ãÀ??×âDBîÜ?ïïò®?ïï??¡£
		- ò¸á´é©ò¦ïÒ?1.
		- DB?×â?İ»?êó device time£¬ì×ó®Ëï?ğíêóğë?îÜ?Õá¡££¨åı100?£©
		- ôøã·??10. åıÍıò¦ïÒ?0??ò¦ïÒà÷CPU??¡£

		\~japanese DB?×âªÎª¿ªáªÎ«¹«ì«Ã«É«×?«ëªÎ«¹«ì«Ã«ÉªÎËÁ?ªÇª¹¡£
		- õÌá³ùÚ£±ªÏò¦ïÒªµªìªÊª±ªìªĞªÊªêªŞª»ªó¡£
		- DB?×âªÏ?İ»îÜªËdevice timeª¬ª«ª«ªëª¿ªáªËä¨İÂªÊ?ªòàâïÒª¹ªëÛ°ª¬ÕŞª¤ªÇª¹¡££¨?ªË100ËÁ£©
		- «Ç«Õ«©«ë«ÈªÏ10ªÇª¹¡£0ªòò¦ïÒª¹ªëªÈCPUªÎ?ªÀª±ò¦ïÒªµªìªŞª¹¡£
		\~
		*/
		int m_dbWorkThreadCount;

		/**
		\~korean DB Cache Server¿¡¼­ DBMS·Î Query¸¦ º¸³¾ ¶§ÀÇ CommandTimeout °ªÀÔ´Ï´Ù.
		- ´ÜÀ§´Â ÃÊ´ÜÀ§ÀÌ°í ÃÊ±â°ªÀº 30ÃÊ ÀÔ´Ï´Ù.

		\~english It is CommandTimeout value when sending Query from DB Cache Server to DBMS.
		- Standard unit is second and default value is 30 seconds.

		\~chinese DB Cache Serverú¾ DBMS?áê Query?îÜ CommandTimeout ?¡£
		- ì¤õ©??êÈ£¬ôøã·??30õ©¡£

		\~japanese DB Cache Serverª«ªéDBMSªØQueryªòáêªëğ·ªÎ CommandTimeoutö·ªÇª¹¡£
		-?êÈªÏõ©?êÈªÇ¡¢ôøÑ¢ö·ªÏ30õ©ªÇª¹¡£

		\~
		*/
		int m_commandTimeoutSec;

		/**
		\~korean
		- OnException Äİ¹é ±â´ÉÀ» »ç¿ëÇÒ Áö ¿©ºÎ¸¦ ¼±ÅÃÇÕ´Ï´Ù.
		- ±âº»°ªÀº trueÀÔ´Ï´Ù.
		- ¸¸¾à false¸¦ ÁöÁ¤ÇÏ¸é À¯Àú Äİ¹é¿¡¼­ ¿¹»óÄ¡ ¸øÇÑ Exception ¹ß»ı ½Ã OnExceptionÀÌ È£ÃâµÇÁö ¾Ê°í Å©·¡½Ã°¡ ¹ß»ıÇÕ´Ï´Ù.

		\~english
		- Decide whether it uses OnException callback function or not.
		- Default value is true.
		- If setting it as false, when exception occurs during  user callback, crash will occur as OnException is not called.

		\~chinese
		- ??ãÀÜúŞÅéÄ OnException CallbackÍíÒö¡£
		- ĞñÜâ?? true¡£
		- åıÍıò¦ïÒfalse£¬éÄ?î¤Callback?ïïñé?ßæëòßÌÜôÓğîÜ Exception ?£¬OnException?Üôù¬û¼õó£¬ó¦?ßæCrash¡£

		\~japanese
		- OnException CallbackÑ¦ÒöªòŞÅéÄª¹ªëª«ªÉª¦ª«ªòàÔ?ª·ªŞª¹¡£
		- «Ç«Õ«©«ë«Èö·ªÏtrueªÇª¹¡£
		- ªâª·falseªòò¦ïÒª¹ªëªÈ«æ?«¶?Callbackª«ªéåøßÌªÇª­ªÊª¤Exceptionª¬?ßæª·ª¿ãÁ¡¢OnExceptionª¬û¼ªÓõóªµªìªºªË«¯«é«Ã«·«åª¬?ßæª·ªŞª¹¡£
		\~
		*/
		bool m_allowExceptionEvent;

		/**
		\~korean
		- true·Î ¼³Á¤µÇ¸é RecursiveUpdate°è¿­ ¿äÃ»À» Ã³¸® ÇÒ ¶§ °¢ ¿äÃ»À» ¼ø¼­´ë·Î ÇÏ³ª¾¿ ¼öÇàÇÕ´Ï´Ù.
		- ¼º´É¿¡ ¾Ç¿µÇâÀ» ¹ÌÄ¡Áö¸¸ DeadlockÀ» ¹æÁöÇÏ±â À§ÇÑ ¿É¼ÇÀÔ´Ï´Ù. ¿øÀÎÀ» ¾Ë ¼ö ¾ø´Â DeadlockÀÌ ¹ß»ı ÇÒ ¶§¸¸ »ç¿ëÇÏ´Â °ÍÀ» ±ÇÀåÇÕ´Ï´Ù.
		- ±âº»°ªÀº falseÀÔ´Ï´Ù.

		\~english
		- If set to 'true', each of the request for 'RecursiveUpdate' will be conducted in order.
		- Although it can cause harm to its performance, this is an alternative for deadlock prevention. We recommend you to use only as an option when deadlock occurs with an unknown cause.
		- The default value is ¡®false¡¯.

		\~chinese
		- ?ïÒ?trueîÜ?,?×âRecursiveUpdateÍ§ÖªîÜ?Ï´?,äÎğÎÊÀ?Ï´îÜ?ßíìé??ò¢×Ûú¼¡£
		- ?æÔî¤àõÒöß¾?àï?ç¯?,Ó£Ê¿ãÀ?ÛÁò­DeadlockîÜìé?ÛÕöÇ¡£Ëï?ñşî¤?ÙéÛöÖõú°ê«ì×îÜDeadlock?ßæ?î¦ŞÅéÄ¡£
		- Ùù??ãÀÊ£îÜ¡£

		\~japanese
		- tureªËàâïÒªµªìªëªÈRecursiveUpdateÍ§ÖªªÎé©ôëªò?×âª¹ªëğ·ªËÊÀé©ôëªòâ÷ÛãªËìéªÄªºªÄú¼ª¤ªŞª¹¡£
		- ª³ªÎ«ª«×«·«ç«óªÏàõÒöªË?ç¯úÂªòĞàªÜª¹ÍğªìªÏª¢ªêªŞª¹ª¬¡¢DeadlockªòÛÁª°ª¿ªáªÎªâªÎªÇª¹¡£ê«ì×ªÎªïª«ªéªÊª¤Deadlockª¬?ßæª·ª¿ãÁªÎªßŞÅéÄª¹ªëª³ªÈªòªª?ªáª·ªŞª¹¡£
		- «Ç«Õ«©«ë«Èö·ªÏfalseªÇª¹¡£
		\~
		*/
		bool m_serializeRecursiveUpdateWork;

		/**
		\~korean
		- ÀÌ °ªÀÌ trueÀÌ¸é Å¬¶óÀÌ¾ğÆ®°¡ Á¢¼Ó Á¾·á ½Ã ÇØ´ç Å¬¶óÀÌ¾ğÆ®°¡ RequestIsolateData¸¦ ¿äÃ»ÇÑ µ¥ÀÌÅÍµéÀÇ °İ¸®¸¦ ÀÚµ¿À¸·Î ÇØÁ¦ÇÕ´Ï´Ù.
		- ±âº»°ªÀº trueÀÔ´Ï´Ù.

		\~english
		- If this value is true, the client will automatically relieve the isolation of data which requested RequestIsolateData when the client is disconnected.
		- The default value is true.

		\~chinese
		- åıÍı?ËÀÌ«ãÀtrueîÜ?, ?ËÔ?ù»??,?ËÔ??RequestlsolateDataá¶é©Ï´îÜ?ËßÌ°???ù¬í»?ú°ğ¶¡£
		- Ùù??ãÀtrue¡£

		\~japanese
		- ª³ªÎ ö·ª¬ trueªÊªé «¯«é«¤«¢«ó«Èª¬ ïÈ? ğûÖõª¹ªë ãÁ ú±? «¯«é«¤«¢«ó«Èª¬ RequestIsolateDataªò é©ôëª·ª¿ «Ç?«¿ª¿ªÁªÎ Ì°×îªò í»ÔÑîÜªË ú°ğ¶ª·ªŞª¹¡£
		- «Ç«Õ«©«ë«Èö·ªÏtrueªÇª¹¡£
		\~
		*/
		bool m_autoDeisolateData;

		CDbCacheServer2StartParameter();
	};

	/**
	\~korean
	<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_client_server" >DB cache Å¬¶óÀÌ¾ğÆ®¿Í ¼­¹ö</a> ÀÔ´Ï´Ù.

	\~english
	<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_client_server" >DB cache client and server</a>

	\~chinese
	ãÀ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_client_server" >DB cacheËÔ?Ó®ûúÜ×?Ğï</a>%¡£

	\~japanese
	\ref dbc2_server ªÇª¹¡£
	\~
	 */
	class CDbCacheServer2
	{
	protected:
		CDbCacheServer2() {}
	public:
		virtual ~CDbCacheServer2() {}

		/**
		\~korean
		Á¢¼ÓµÈ Å¬¶óÀÌ¾ğÆ® ¼ö¸¦ ¸®ÅÏÇÕ´Ï´Ù.

		\~english
		Return the client is connected

		\~chnese
		Return ì«?ïÈîÜËÔ?Ó®?¡£

		\~japanese
		ïÈ?ªµªìª¿«¯«é«¤«¢«ó«È?ªò«ê«¿?«óª·ªŞª¹¡£
		\~
		 */
		virtual intptr_t GetCachingDataTreeCount() = 0;

		/**
		\~korean
		DB cache ¼­¹ö ÀÎ½ºÅÏ½º¸¦ »ı¼ºÇÕ´Ï´Ù.

		\~english
		Creates DB cache server instance

		\~chinese
		?ËïDB cacheÜ×?Ğï?ÖÇ¡£

		\~japanese
		DB cache«µ?«Ğ?«¤«ó«¹«¿«ó«¹ªòßæà÷ª·ªŞª¹¡£
		\~
		 */
		PROUDSRV_API static CDbCacheServer2* New();

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®·ÎºÎÅÍÀÇ Á¢¼ÓÀ» È°¼ºÈ­ÇÏ°í, DBMS¿ÍÀÇ ½ÇÁ¦ ¿¬°áÀ» ½ÃÀÛÇÕ´Ï´Ù.
		\param params CDbCacheServer2¸¦ ½ÃÀÛÇÏ´Âµ¥ ÇÊ¿äÇÑ ¼³Á¤°ª (Âü°í \ref CDbCacheServer2StartParameter)

		\~english TODO:translate needed
		Enable the connection from the client and start the actual connection with DBMS. 
		\param params The configuration value required to start CDbCacheServer2 (refer to \ref CDbCacheServer2StartParameter)

		\~chinese
		Ì­üÀ?èÌÊ«îÜ?ïÈ£¬?ã·?DBMSîÜ???ïÈ¡£
		\param param ?ã· CDbCacheServe2r%âÍé©îÜ?öÇ?£¨?ÍÅ \ref CDbCacheServer2StartParameter£©¡£

		\~japanese
		«¯«é«¤«¢«ó«Èª«ªéªÎïÈ?ªòüÀàõûùª·ªÆ¡¢DBMSªÈªÎ?ğ·ïÈ?ªòËÒã·ª·ªŞª¹¡£
		\param params CDbCacheServer2ªòËÒã·ª¹ªëªËù±é©ªÊàâïÒö·(?ÍÅ \ref CDbCacheServer2StartParameter)

		\~
		 */
		virtual void Start(CDbCacheServer2StartParameter &params) = 0;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®¿ÍÀÇ Á¢¼ÓÀ» ¸ğµÎ ²÷°í, ÇÏ´ø ÀÛ¾÷À» ¸ğµÎ Ã³¸®ÈÄ¿¡ ½º·¹µå¸¦ Á¾·á ÇÕ´Ï´Ù.

		\~english
		Disconnect with all clients, finish all works that in process then close thread.

		\~chinese
		???èÌÊ«îÜ?ïÈ£¬?×âèÇ?ú¼ñéîÜÍïíÂı¨?ò­?ïï¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªÈªÎïÈ?ªòîïªÆï·ªÃªÆ¡¢ú¼ªÃªÆª¤ª¿íÂåöªòîïªÆ?×âı­ªË«¹«ì«Ã«ÉªòğûÖõª·ªŞª¹¡£
		\~
		*/
		virtual void Stop() = 0;

		/**
		\~korean
		DB cache client2·ÎºÎÅÍ ¹ŞÀº µ¥ÀÌÅÍ Ãß°¡/º¯°æ/Á¦°Å ³»¿ëÀ» ¹ŞÀº ÈÄºÎÅÍ DBMS¿¡ ±â·ÏÇÒ ¶§±îÁö
		´ë±âÇÏ´Â ½Ã°£ÀÔ´Ï´Ù.
		- ³Ê¹« ÂªÀ¸¸é DBMS¿¡ °É¸®´Â ºÎÇÏ°¡ Áõ°¡ÇÕ´Ï´Ù.
		- ³Ê¹« ±æ¸é DB cache server°¡ ºñÁ¤»ó Á¾·á(¿¹: Á¤Àü)ÇÒ °æ¿ì DBMS¿¡ ±â·ÏÇÏÁö ¸øÇÏ°í ¸Ş¸ğ¸®¿¡
		´ë±âÁßÀÌ´ø µ¥ÀÌÅÍ´Â ¼Ò½ÇµÉ È®·üÀÌ Ä¿Áı´Ï´Ù.
		\param val ¹Ğ¸®ÃÊ ´ÜÀ§ ½Ã°£

		\~english TODO:translate needed
		This is the time to stand by from after receiving the data add/modify/delete content from DB cache client 2 until recording it in DBMS. 
		- If too short, the load on DBMS increases
		- If too long, when the DB cache server terminates abnormally (e.g.: power failure), it cannot record in DBMS and the data waiting in the memory is likely to be lost.  
		\param val Time in millisecond unit

		\~chinese
		?DB cache client2ïÈâ¥ôÕÊ¥/áóËÇ/?ğ¶?ËßîÜ?é»ı¨ÔõÓâò¸èÙDBMS??îÜ??¡£
		- ÷¼Ó­îÜ??DBMSîÜ?ùÃ?ñòÊ¥¡£
		- ÷¼?îÜ?£¬?ŞªïáßÈ?ò­£¨ÖÇ£ºïÎ?£©DB cache serverîÜ?ı¦ÜôÒöèÙDBMS??£¬ì»î¤?ğíÔõÓâîÜ?Ëßá¼ã÷îÜ?áã?ñòÊ¥¡£
		\param val õ©?êÈ??¡£

		\~japanese
		DB cache client2ªèªêáôª±ª¿«Ç?«¿ªÎõÚÊ¥/?ÌÚ/ğ¶ËÛ?é»ªòáôª±ª¿ı­ª«ªéDBMSªËÑÀ?ª¹ªëãÁªŞªÇÓâªÄãÁÊàªÇª¹¡£
		- ª¢ªŞªêªËªâÓ­ª¤ªÈDBMSªËª«ª«ªëİ¶ùÃª¬?Ê¥ª·ªŞª¹¡£
		- ª¢ªŞªêªËªâíşª¤ªÈDB cache serverª¬ì¶ßÈğûÖõ(ÖÇ£ºïÎï³)ª¹ªëíŞùê¡¢DBMSªËÑÀ?ªÇª­ªºªË«á«â«ê?ªÇÓâªÃªÆª¤ª¿«Ç?«¿ªÏá¼ã÷ªµªìªëü¬áãª¬ÓŞª­ª¯ªÊªêªŞª¹¡£
		\param val «ß«êõ©?êÈãÁÊà

		\~
		 */
		virtual void SetDbmsWriteIntervalMs(int64_t val)=0;

		/**
		\~korean
		DB cache client2¿¡¼­ unloadÇÑ µ¥ÀÌÅÍ°¡ DB cache server ¸Ş¸ğ¸®¿¡¼­µµ ¿ÏÀüÈ÷ Á¦°ÅÇÒ
		¶§±îÁö ´ë±âÇÏ´Â ½Ã°£ÀÔ´Ï´Ù.
		- ³Ê¹« ÂªÀ¸¸é DBMS¿¡ °É¸®´Â ºÎÇÏ°¡ Áõ°¡ÇÕ´Ï´Ù.
		- ³Ê¹« ±æ¸é DB cache server2ÀÇ ¸Ş¸ğ¸® »ç¿ë·®ÀÌ Ä¿Áı´Ï´Ù.
		\param val ¹Ğ¸®ÃÊ ´ÜÀ§ ½Ã°£

		\~english TODO:translate needed
		Waiting time that the unloaded data at DB cache client waits until it is fully removed from DB cache memory
		- If this is set too short then the work load to DBMS will increase.
		- If this is set too long then it will increase the amount of memory usage in DB cache server.

		\~chinese
		?DB cache client2 unloadîÜ?Ëßî¤DB cache server?ğíå¥èÇîï?ğ¶îÜÔõÓâ??¡£
		- ÷¼Ó­îÜ??DBMSîÜ?ùÃ?ñòÊ¥¡£
		- ÷¼?îÜ?DB cache server2îÜ?ğíŞÅéÄÕá?Ê¥ÓŞ¡£
		\param val ûÆõ©?êÈ??

		\~japanese
		DB cache client2ªÇunloadª·ª¿«Ç?«¿ª¬DB cache server«á«â«ê?ªÇªâèÇîïªËğ¶ËÛªµªìªëãÁªŞªÇÓâªÄãÁÊàªÇª¹¡£
		- ª¢ªŞªêªËªâÓ­ª¤ªÈDBMSªËª«ª«ªëİ¶ùÃª¬?Ê¥ª·ªŞª¹¡£
		- ª¢ªŞªêªËªâíşª¤ªÈDB cache serve2ªÎ«á«â«ê?ŞÅéÄÕáª¬ÓŞª­ª¯ªÊªêªŞª¹¡£
		\param val «ß«êõ©?êÈãÁÊà

		\~
		 */
		virtual void SetUnloadedDataHibernateDurationMs(int64_t val)=0;

		/**
		\~korean
		Proud.CNetServer.SetDefaultTimeoutTimeMs°ú °°Àº ¿ªÇÒÀ» ÇÕ´Ï´Ù.

		\~english
		Performs similar role as Proud.CNetServer.SetDefaultTimeoutTimeMs

		\~chinese
		ÑÃó·? Proud.CNetServer.SetDefaultTimeoutTimeMs%ìé?îÜíÂéÄ¡£

		\~japanese
		Proud.CNetServer.SetDefaultTimeoutTimeMsªÈÔÒª¸æµùÜªòª·ªŞª¹¡£
		\~
		 */
		virtual void SetDefaultTimeoutTimeMs(int newValInMs) = 0;

		/**
		\~korean
		Proud.CNetServer.SetDefaultTimeoutTimeSec°ú °°Àº ¿ªÇÒÀ» ÇÕ´Ï´Ù.
		\param val ÃÊ ´ÜÀ§ ½Ã°£

		\~english TODO:translate needed.
		Performs similar role as Proud.CNetServer.SetDefaultTimeoutTimeSec
		\param val

		\~chinese
		ÑÃó·? Proud.CNetServer.SetDefaultTimeoutTimeSec%ìé?îÜíÂéÄ¡£
		\param val õ©?êÈ??

		\~japanese
		Proud.CNetServer.SetDefaultTimeoutTimeSecªÈÔÒª¸æµùÜªòª·ªŞª¹¡£
		\param val õ©?êÈãÁÊà

		\~
		 */
		virtual void SetDefaultTimeoutTimeSec(double newValInSec) = 0;


		/**
		\~korean
		ÀÌ DB cache server2°¡ ¿­¾î ³õÀº TCP ¸®½º´× ¼ÒÄÏÀÇ ÁÖ¼Ò¸¦ ¾ò½À´Ï´Ù.

		\~english
		Gets the address of TCP listening socket opened by this DB cache server

		\~chinese
		?Ôğó®DB cache server2öè?îÜTCPâ¥??Ï¢ò¢ò£¡£
		
		\~japanese
		ª³ªÎDB cache server2ª¬ËÒª±ªÆöÇª¤ª¿TCP«ê«¹«Ë«ó«°«½«±«Ã«ÈªÎ«¢«É«ì«¹ªòÔğªŞª¹¡£
		 */
		virtual AddrPort GetTcpListenerLocalAddr() = 0;

		/**
		\~korean
		ÀÌ DB cache Server2¿¡ Á¢¼ÓÇÑ DB Cache Cleint2 µé¿¡ ´ëÇÑ AddrPort °ªµéÀ» ¾ò´Â´Ù.
		- ÀÌ ¸Ş¼­µå·Î ¾ò´Â ¸ñ·ÏÀº È£ÃâÇÒ ½ÃÁ¡ÀÇ ½º³À¼¦ÀÏ »ÓÀÌ´Ù.
		ÀÌ ÇÔ¼ö°¡ ¸®ÅÏµÈ ÈÄ¿¡µµ Å¬¶óÀÌ¾ğÆ® ¸ñ·ÏÀÇ ³»¿ëÀÌ ½ÇÁ¦ ¼­¹öÀÇ »óÅÂ¿Í µ¿ÀÏÇÔÀ» º¸ÀåÇÏÁö´Â ¾Ê´Â´Ù.
		\param output AddrPortµéÀÇ ¸ñ·ÏÀÌ Ã¤¿öÁú °÷

		\~english TODO:translate needed.
		Obtain the AddrPort for the DB Cache Client 2 connected to this DB Cache Server2. 
		- The list obtained by this method is only the snapshot at the time of being called. 
		Even after this function is returned, it does not guarantee that the content of the client list is the same as the status of the actual server. 
		\param output Place where the list of AddrPort will be filled out. 

		\~chinese
		?Ôğ?ïÈ??DB cache Server2îÜDB Cache Cleint2îÜAddrPort?¡£
		- éÄ??Û°Ûö?ÔğîÜÙÍ?ñşãÀû¼Ğ£?ı¦îÜsnapshotì»ì«¡£
		ó®ùŞ?Ú÷üŞì¤ı¨å¥ÜôÒöÜÁî¡èÌÊ«ÙÍ?îÜ?é»???Ü×?ĞïîÜ??ãÀßÓÔÒîÜ¡£
		\param output AddrPortîÜÙÍ?é©ù¬?õöîÜò¢Û°¡£

		\~japanese
		ª³ªÎDB cache Server2ªËïÈ?ª·ª¿DB Cache Cleint2ªÊªÉªË?ª¹ªëAddrPortö·ªòÔğªŞª¹¡£
		- ª³ªÎ«á«½«Ã«ÉªÇÔğªë«ê«¹«ÈªÏû¼ªÓõóª¹ãÁïÃªÎ«¹«Ê«Ã«×«·«ç«Ã«ÈªÇª¢ªëªÀª±ªÇª¹¡£
		ª³ªÎ??ª¬«ê«¿?«óªµªìª¿ı­ªËªâ«¯«é«¤«¢«ó«È«ê«¹«ÈªÎ?é»ª¬?ğ·«µ?«Ğ?ªÎ?÷¾ªÈÔÒìéªÇª¢ªëª³ªÈªòÜÁî¡ª¹ªëª³ªÈªÏª¢ªêªŞª»ªó¡£
		\param output AddrPortªÎ«ê«¹«Èª¬?ª¿ªµªìªëá¶
		\~
		*/
		virtual bool GetAllRemoteClientAddrPort(CFastArray<AddrPort> &ret) = 0;


		/**
		\~korean
		- µ¶Á¡ ·Îµå ¿äÃ»ÀÇ Ã³¸®¸¦ ±â´Ù¸± Á¦ÇÑ ½Ã°£À» ¼³Á¤ÇÕ´Ï´Ù.
		- ÀÌ °ªÀ¸·Î ¼³Á¤µÈ ½Ã°£ ÀÌ³»¿¡ ·Îµå ¹× µ¶Á¡±Ç È¹µæÀÌ ¿Ï·áµÇÁö ¾ÊÀ¸¸é ÇØ´ç ¿äÃ»Àº Å¸ÀÓ¾Æ¿ôÀ¸·Î ½ÇÆĞ Ã³¸®µË´Ï´Ù.
		- ±âº»°ªÀº 10ÃÊÀÔ´Ï´Ù. (10000¹Ğ¸®ÃÊ)
		\param timeoutMs ÁöÁ¤ ÇÒ ½Ã°£ Á¦ÇÑÀÔ´Ï´Ù. (¹Ğ¸®ÃÊ ´ÜÀ§)

		\~english
		Configure the time limit to wait for the processing of exclusive load request. 
		- If the load and exclusivity acquisition is not completed within the time set with this value, the request is processed as a failure as a timeout. 
		- The default value is 10 seconds (10000 milliseconds)
		\param timeoutMs The time limit to be designated (millisecond unit)

		\~chinese
		- ???Ê¥??Ï´?×âŞÀËì?ïÒÔõÓâ??¡£
		- åıÍıî¤?ïÒîÜ???Ú±èÇà÷Ê¥???Ôğ???£¬??Ï´ö¦?ù¬õ±??×â¡£
		- Ùù???10õ©¡£ (10000Ú°õ©)
		\paramtimeoutMs ò¦ïÒîÜŞÀËìùÚğ¤¡£ (Ú°ÙØ?êÈ)

		\~japanese
		- ?ï¿«í?«Éé©ôëªÎ?×âªòÓâªÄğ¤ùÚãÁÊàªòàâïÒª·ªŞª¹¡£
		- ª³ªÎö·ªÇàâïÒªµªìª¿ãÁÊàì¤?ªË«í?«ÉĞàªÓ?ï¿?üòÔğª¬èÇÖõªµªìªÊª±ªìªĞ¡¢ú±?é©ôëªÏ«¿«¤«à«¢«¦«ÈªÇã÷ø¨?×âªËªÊªêªŞª¹¡£
		- ĞñÜâö·ªÏ10õ©ªÇª¹¡£(10000«ß«êõ©)
		\param timeoutMs ò¦ïÒª¹ªëãÁÊàğ¤ùÚªÇª¹¡£(«ß«êõ©?êÈ)

		\~
		*/
		virtual void SetUnloadRequestTimeoutTimeMs(int64_t timeoutMs) = 0;

		/**
		\~korean
		- µ¶Á¡ ·Îµå ¿äÃ»ÀÇ Å¸ÀÓ¾Æ¿ô ¼³Á¤°ªÀ» ¹Ğ¸®ÃÊ ´ÜÀ§·Î ¹İÈ¯ÇÕ´Ï´Ù.

		\~english
		Return the timeout configuration value of the exclusive load request in millisecond unit. 

		\~chinese
		- ÷ê??Ê¥?õ±??ïÒ???à÷Ú°ÙØ?êÈ¡£

		\~japanese
		- ?ï¿«í?«Éé©ôëªÎ«¿«¤«à«¢«¦«ÈàâïÒö·ªò«ß«êõ©?êÈªÇÚ÷ü½ª·ªŞª¹¡£
		\~
		*/
		virtual int64_t GetUnloadRequestTimeoutTimeMs() const = 0;
	};
	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
#endif