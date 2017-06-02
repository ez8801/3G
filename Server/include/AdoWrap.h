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
#include "PropNode.h"
#include "FakeClrBase.h"

#include "Variant.h"

#ifdef _WIN64
#include "./_x64/msado15.tlh"
#else
#include "msado15.tlh"
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	// UUID°¡ stringÀ¸·Î º¯È¯µÇ¸é character ¼ö
	static const int UUIDVarcharLength = 38;

	/*
	\~korean
	'#import' ±¸¹®À» ¾²´Â ´ë½Å tlh, tli¸¦ #includeÇÕ´Ï´Ù.
	- ÀÌ·¸°Ô ÇØ¾ß /MP ¿É¼ÇÀÌ Àß ÀÛµ¿ÇÕ´Ï´Ù.
	- ¶ÇÇÑ À¯Àú°¡ c:\program files\common files\system\ado¸¦ Ãß°¡ÇÏ´Â ¼ö°í¸¦ ´ş´Ï´Ù.

	\~english
	#include tlh and tli instead of #import syntax.
	- This method makes /MP options to operate better.
	- And user doesn't have to add c:\program files\common files\system\ado.

	\~chinese
	#include tlh ûútli insteadôğÓÛ#import ?Ûö¡£
	- ??î¦Òö?/MP ??ÌÚû¿îÜ??¡£
	- ì»ó¦éÄ??àıñòÊ¥c:\program files\common files\system\ado îÜØ«?¡£

	\~japanese
	'#import' Ï°ÙşªòŞÅª¦ÓÛªïªêªËtlh¡¢tliªò#includeª·ªŞª¹¡£
	- ª³ªÎªèª¦ªËª¹ªëªÈ/MP«ª«×«·«ç«óª¬ªèª¯íÂÔÑª·ªŞª¹¡£
	- ªŞª¿¡¢«æ?«¶?ª¬c:\program files\common files\system\adoªòõÚÊ¥ª¹ªëÒ½Õôªòª·ªÊª¯ªÆªâÕŞª¤ªÇª¹¡£
	\~
	 */

	/** \addtogroup db_group
	*  @{
	 */

	/**
	\~korean
	<a target="_blank" href="http://guide.nettention.com/cpp_ko#ado_overview" >ADO Wrapper API</a> ÀÇ Áö¿¬ °¨ÁöÃ¼Ä¿
	- ÀÌ °´Ã¼´Â »ç¿ëÀÚ°¡ »ç¿ëÇÏÁö ¾Ê½À´Ï´Ù.³»ºÎ ¿ëµµ·Î »ç¿ëµË´Ï´Ù.

	\~english
	This method monitors and checks delay of <a target="_blank" href="http://guide.nettention.com/cpp_en#ado_overview" >ADO Wrapper API</a>.
	- This object is for the internal purpose only, not usable by user.

	\~chinese
	<a target="_blank" href="http://guide.nettention.com/cpp_zh#ado_overview" >ADO Wrapper API</a>%îÜæÅ?Êïò±??¡£
	- éÄ?ÜôŞÅéÄ???ßÚ,ãÀéÄéÍ?İ»éÄÔ²¡£

	\~japanese
	\ref ado_overviewªÎ?æÅÊïò±«Á«§«Ã««?
	- ª³ªÎ«ª«Ö«¸«§«¯«ÈªÏ«æ?«¶?ª¬ŞÅª¤ªŞª»ªó¡£?İ»éÄÔ²ªÇŞÅªïªìªŞª¹¡£
	\~
	*/
	class CQueryChecker
	{
	protected:
		void	ExecuteBegin();
		void	ExecuteEnd(const String& command);
	protected:
		uint32_t	m_prevTime;
	};

	/**
	\~korean
	\brief DBMS Á¢±Ù½Ã ÀÌº¥Æ®¸¦ ¹Ş´Â °´Ã¼ÀÇ ÀÎÅÍÆäÀÌ½º Å¬·¡½ºÀÔ´Ï´Ù.
	- »ç¿ëÀÚ´Â ÀÌ ÀÎÅÍÆäÀÌ½º¸¦ »ó¼Ó¹Ş¾Æ ÀÌº¥Æ®¸¦ ³ëÆ¼¸¦ ¹Ş½À´Ï´Ù.
	- <a target="_blank" href="http://guide.nettention.com/cpp_ko#ado_access_tracker" >ADO ÀÛµ¿ ÃßÀûÇÏ±â</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.

	\~english
	\brief DBMS Interface class of object that receives event when it access.
	- User inherits this interface and receives notification of event.
	- Refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#ado_access_tracker" >Tracking ADO operation</a> for more details.

	\~chinese
	\brief DBMSïÈĞÎ?ïÈáôŞÀËì?ßÚîÜñ«Í£Øü?¡£
	- èÌÊ«ïÈÓğó®Í£Øü÷×ò±ïÈáôevent¡£
	- ??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#ado_access_tracker" >õÚñ¡ADO??</a>%¡£

	\~japanese
	\brief DBMS «¢«¯«»«¹ãÁªË«¤«Ù«ó«Èªòáôª±ªë«ª«Ö«¸«§«¯«ÈªÎ«¤«ó«¿?«Õ«§?«¹«¯«é«¹ªÇª¹¡£
	- «æ?«¶?ªÏª³ªÎ«¤«ó«¿?«Õ«§?«¹ªòßÓ?ª·ªÆ«¤«Ù«ó«Èªò÷×ò±ª·ªÆá®ª¤ªŞª¹¡£
	- \ref ado_access_trackerªòª´?ğÎª¯ªÀªµª¤¡£
	
	\~
	 */
	class IDbmsAccessEvent
	{
	public:
		virtual ~IDbmsAccessEvent();

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a> ¸¦ »ç¿ë½Ã¿¡ Áö¿¬µÇ´Â Ä¿¸Çµå¸¦ ¹ß°ß½Ã¿¡ Äİ¹éµË´Ï´Ù.
		\param lpszcommand »ç¿ëµÈ Ä¿¸Çµå ÀÔ´Ï´Ù. Äõ¸® ¹®±¸ÀÌ°Å³ª ÇÁ·Î½ÃÁ® ÀÌ¸§ÀÔ´Ï´Ù.
		\param curtime °¨ÁöµÈ ´ç½ÃÀÇ ½Ã°£ÀÔ´Ï´Ù.
		\param querytick Ä¿¸Çµå¸¦ »ç¿ëÇÏ´Âµ¥ Áö¿¬µÇ ½Ã°£ÀÔ´Ï´Ù. (¹Ğ¸®ÃÊ´ÜÀ§)

		\~english
		This method callbacks when it spots any delayed command while using <a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a>.
		\param lpszcommand The list of commands in use. They are either in query or procedure name.
		\param curtime The exact time of a delayed command detected.
		\param querytick The delayted time of command being used (in milliseconds).

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a>%ŞÅéÄ????æÅîÜò¦Öµ?í»?üŞ?¡£
		\param lpszcommand ãÀŞÅéÄîÜÙ¤Öµ¡£??ûäïïßíîÜÙ£?¡£
		\param curtime Êï?????¡£
		\param querytick Ù¤ÖµŞÅéÄîÜ?ı¦?æÅîÜ??¡£(ûÆõ©??êÈ)

		\~japanese
		\ref ado_overviewªòŞÅéÄãÁªË?æÅªµªìªë«³«Ş«ó«Éª¬Ì¸ªÄª«ªÃª¿ªé«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		\param lpszcommand ŞÅéÄªµªìª¿«³«Ş«ó«ÉªÇª¹¡£«¯«¨«ê?ÙşÏ£ª««×«í«·?«¸«ãÙ£ªÇª¹¡£
		\param curtime Êïò±ªµªìª¿?ãÁªÎãÁÊàªÇª¹¡£
		\param querytick «³«Ş«ó«ÉªòŞÅª¦ª¿ªá?æÅªµªìªëãÁÊàªÇª¹¡££¨«ß«êõ©?êÈ£©

		\~
		*/
		virtual void OnQueryDelayed(const PNTCHAR* lpszcommand, const ::timespec& curtime, uint32_t querytick) = 0;
	};

	/**
	\~korean
	<a target="_blank" href="http://guide.nettention.com/cpp_ko#ado_overview" >ADO Wrapper API</a> ¸¦ »ç¿ë½Ã¿¡ ÀÌº¥Æ®¸¦ ³ëÆ¼ÇÏ´Â ÁÖÃ¼ÀÔ´Ï´Ù.
	- Àü¿ªÀ¸·Î »ç¿ëµË´Ï´Ù.
	- <a target="_blank" href="http://guide.nettention.com/cpp_ko#ado_access_tracker" >ADO ÀÛµ¿ ÃßÀûÇÏ±â</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.

	\~english
	The main which notifies events while using  <a target="_blank" href="http://guide.nettention.com/cpp_en#ado_overview" >ADO Wrapper API</a>.
	- Can be used globally.
	- Refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#ado_access_tracker" >Tracking ADO operation</a> for more details.

	\~chinese
	<a target="_blank" href="http://guide.nettention.com/cpp_zh#ado_overview" >ADO Wrapper API</a>%ŞÅéÄ?event÷×ò±îÜñ«?¡£
	- Ê¦ì¤îïÛ°êÈŞÅéÄ¡£
	- ??ÍÅ <a target="_blank" href="http://guide.nettention.com/cpp_zh#ado_access_tracker" >õÚñ¡ADO?? </a>

	\~japanese
	\ref ado_overview ªòŞÅéÄãÁªË«¤«Ù«ó«Èªò÷×ò±ª¹ªëñ«?ªÇª¹¡£
	- îïæ´ªÇŞÅªïªìªŞª¹¡£
	- \ref ado_access_tracker ªòª´?ğÎª¯ªÀªµª¤¡£
	

	\~
	*/
	class CDbmsAccessTracker
	{
		friend CQueryChecker;

		CDbmsAccessTracker();
	public:
		~CDbmsAccessTracker();
		/**
		\~korean
		ÀÌº¥Æ®¸¦ ³ëÆ¼ ¹ŞÀ» ÀÎÅÍÆäÀÌ½º¸¦ ÁöÁ¤ÇÕ´Ï´Ù.
		\param pEvent ÀÌº¥Æ®¸¦ ³ëÆ¼¹ŞÀ» ÀÎÅÍÆäÀÌ½ºÀÇ Æ÷ÀÎÅÍÀÔ´Ï´Ù.

		\~english
		This method appoints an interface that will receive notification of event.
		\param pEvent The pointer of interface receiving notification of event.

		\~chinese
		ò¦ïÒ?é©÷×ò±ŞÀËìîÜñ«Í£Øü¡£
		\param pEvent ãÀïÈáô÷×ò±Í£ØüîÜ??ïÃ¡£

		\~japanese
		«¤«Ù«ó«Èªò÷×ò±ª·ªÆá®ª¦«¤«ó«¿?«Õ«§?«¹ªòò¦ïÒª·ªŞª¹¡£
		\param pEvent «¤«Ù«ó«Èªò÷×ò±ª·ªÆá®ª¦«¤«ó«¿?«Õ«§?«¹ªÎ«İ«¤«ó«¿?ªÇª¹¡£

		\~
		*/
		static void SetAdoWrapEvent(IDbmsAccessEvent* pEvent);

	private:
		static IDbmsAccessEvent*	m_DbmsAcessEvent;
	public:
		/**
		\~korean
		Äõ¸®Áö¿¬ ÀÌº¥Æ® ½Ã°£
		- <a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a> ¸¦ »ç¿ë½Ã¿¡ Ä¿¸Çµå(È¤Àº Äõ¸®)°¡ ÀÌ ½Ã°£ÀÌ»óÀÌ Áö¿¬µÇ¸é IDbmsAccessEvent·Î ÀÌº¥Æ®¸¦ ³ëÆ¼ÇÕ´Ï´Ù.
		- ±âº»°ªÀº 500À¸·Î ¼³Á¤µÇ¾î ÀÖ½À´Ï´Ù.

		\~english
		Query delay event time
		- This method notifies event through IDbmsAccessEvent when command(query) is delayed for a specified time as using <a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a>.
		- The default time is 500.

		\~chinese
		??æÅ?event??¡£
		- <a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a>%ŞÅéÄ?îÜÙ¤Öµ£¨ûä??£©?æÅîÜ??õ±?ó®??£¬?éÄIDbmsAccessEvent÷×ò±event¡£
		- Ùù??ãÀ500¡£

		\~japanese
		«¯«¨«ê??æÅ«¤«Ù«ó«ÈãÁÊà
		- \ref ado_overview ªòŞÅéÄãÁªË«³«Ş«ó«É(ªŞª¿ªÏ«¯«¨«ê?)ª¬ª³ªÎãÁÊàì¤ß¾?æÅªµªìªëªÈIDbmsAccessEventªË«¤«Ù«ó«Èªò÷×ò±ª·ªŞª¹¡£
		- ĞñÜâö·ªÏ500ªËàâïÒªµªìªÆª¤ªŞª¹¡£
		\~
		*/
		PROUD_API static uint32_t	DelayedAccessThresholdMilisec;
	};

	enum DbOpenFor { OpenForRead,OpenForFastRead,OpenForReadWrite,OpenForAppend };
	enum DbmsType  { MsSql,MySql};

	class CAdoRecordset;
	class CAdoOfflineRecord;
	class CVariant;

	/**
	\~korean
	<a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a> ÀÇ DBMS ¿¬°á °´Ã¼
	- Àü¿ªÀ¸·Î ÀÌ °´Ã¼¸¦ µÎ¾î¼­ ¿©·¯ ½º·¹µå¿¡¼­ Á¢±ÙÇÏ´Â °ÍÀº ¿©·¯°¡Áö ¹®Á¦(°¡·É race condition)À» ¾ß±âÇÕ´Ï´Ù.
	µû¶ó¼­ ÇÊ¿äÇÒ ¶§¸¶´Ù ÀÌ °´Ã¼¸¦ ·ÎÄÃ º¯¼ö·Î¼­ »ı¼ºÇØ¼­ ¾²´Â °ÍÀÌ ¹Ù¶÷Á÷ÇÕ´Ï´Ù. ÇÑÆí, ¼º´ÉÀ» À§ÇØ¼­ ¿¬°á¸¸ ÇÏ°í ´Ù¸¥ ¿ëµµ·Î »ç¿ëµÇÁö ¾Ê´Â ÇÁ·Î¼¼½º Àü¿ª
	°´Ã¼¸¦ ÇÏ³ª µÎ´Â °ÍÀÌ ÁÁ½À´Ï´Ù. ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#ado_connect" >ADO·Î µ¥ÀÌÅÍº£ÀÌ½º¿¡ Á¢±ÙÇÏ±â</a>ion_pooling À» Âü°íÇÏ½Ê½Ã¿À.
	- ÀÌ °´Ã¼¸¦ »ı¼ºÇÏ±â Àü¿¡, ÃÖ¼Ò 1È¸ÀÇ CoInitialize¸¦ È£ÃâÇØ¾ß ÇÕ´Ï´Ù.
	±×³É ½º·¹µå ¸ŞÀÎ ÇÔ¼ö¿¡ ´ÙÀ½°ú °°Àº ±¸¹®À» ³Ö¾îµÎ¸é ÆíÇÒ °ÍÀÔ´Ï´Ù.
	\code
	Proud::CCoInitializer coi;
	\endcode
	- DB¸¦ ¾ï¼¼½ºÇÏ´Â µ¿¾È critical sectionÀ» °ÇµéÁö ¾ÊÀ½À» Ã¼Å©ÇÏ´Â ±â´É: ADODB_RefCriticalSection, ADODB_RecommendCriticalSectionProc

	\~english
	DMBS link object of <a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a>

	- If you access other thread with this object, it will occur some problems (e.g. race condition)
	So we recommend to use this object with changing local variable when you needed. However it is better to leave process object without using to improve performance.
	Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#ado_connect" >Accessing database with ADO</a>ion_pooling for more detail.
	- Before creating this object, at least once of Colnitialize must be called.
	It will be much convenient if the following syntax is included in the thread main function.
	\code
	Proud::CCoInitializer coi;
	\endcode
	- Function that checks whether or not critical section has been touched while accessing DB: ADODB_RefCriticalSection, ADODB_RecommendCriticalSectionProc

	\~chinese
	<a target="_blank" href="http://guide.nettention.com/cpp_  #ado_overview" >ADO Wrapper API</a>%îÜDBMS?ïÈ?ßÚ
	- îïæ´×ìéÄó®?ßÚ??Òı?ïïïÈĞÎîÜ??öÈÜôá´??(åırace condition)¡£
	ì×ó®£¬Øß?ù±é©îÜ?ı¦÷êó®?ßÚßæà÷?Üâò¢??ŞÅéÄãÀõÌû¿îÜ¡£?èâ£¬?ÖõàõÒö£¬Ëï?×ºìé?ñş?ïÈÜôéÄéÍĞìöâéÄÔ²îÜïïßíîïæ´?ßÚ¡£??îÜ??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#ado_connect" >éÄADO???Ëß?</a>ion_pooling%¡£
	- ßæà÷ó®?ßÚñıîñ£¬é©õÌá´û¼Ğ£ìéó­CoInitialize¡£
	î¤?ïïñ«ùŞ?×ìôÕÊ¥ì¤ù»?é»îÜ??Û°øµîÜ¡£
	\code
	Proud::CCoInitializer COI;
	\endcode
	- ?ïÈDBîÜ?ı¦?Üô?critical sectionöèÎşîÜĞüÒö£ºADODB_RefCriticalSection £¬ ADODB_RecommendCriticalSectionProc

	\~japanese
	\ref ado_overviewªÎDBMSÖ§Ì¿«ª«Ö«¸«§«¯«È
	- îïæ´ªËª³ªÎ«ª«Ö«¸«§«¯«ÈªòöÇª¤ªÆÜÜ?ªÎ«¹«ì«Ã«Éªèªê«¢«¯«»«¹ª¹ªëª³ªÈªÏ??ªÊÙığ¹£¨ÖÇª¨ªĞ¡¢race condition£©ªòìÚª­ÑÃª³ª·ªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊãÁª´ªÈªËª³ªÎ«ª«Ö«¸«§«¯«Èªò«í?«««ë??ªÇßæà÷ª·ªÆŞÅª¦ªÎª¬ØĞªŞª·ª¤ªÇª¹¡£ìéÛ°¡¢àõÒöªÎª¿ªáªËïÈ?ªÀª±ªòª·ªÆöâªÎéÄÔ²ªÇªÏŞÅªïªìªÊª¤«×«í«»«¹îïæ´ªÎ«ª«Ö«¸«§«¯«ÈªòìéªÄöÇª¤ª¿Û°ª¬ÕŞª¤ªÇª¹¡£ßÙª·ª¯ªÏ\ref ado_connection_poolingªòª´?ğÎª¯ªÀªµª¤¡£
	- ª³ªÎ«ª«Ö«¸«§«¯«Èªòßæà÷ª¹ªëîñªË¡¢õÌá³1üŞªÎCoInitializeªòû¼ªÓõóª¹ù±é©ª¬ª¢ªêªŞª¹¡£ª¿ªÀ¡¢«¹«ì«Ã«ÉªÎ«á«¤«ó??ªËó­ªÎªèª¦ªÊÏ°ÙşªòìıªìªÆöÇª±ªĞøµ××ªÇª¹¡£
	\code
	Proud::CCoInitializer coi;		
	\endcode
	- DBªò«¢«¯«»«¹ª¹ªëÊàªËªÏcritical sectionªò?ªéªÊª¤ªÈ«Á«§«Ã«¯ª¹ªëÑ¦Òö£ºADODB_RefCriticalSection¡¢ADODB_RecommendCriticalSectionProc 
	\~
	 */
	class CAdoConnection:public ADODB::_ConnectionPtr,protected CQueryChecker
	{
	private:
		// Execute¿¡¼­ »ç¿ëÇÏ´Â ÇÒ´ç ¸Ş¸ğ¸®¾ç
		const static size_t SQLTEXTLEN = 12800;
		
		//CAdoConnectionPool* m_connectionPool; // NULLÀÌ¸é connection poolÀ» ¾²Áö ¾Ê°í ÀÖÀ½À» ÀÇ¹ÌÇÑ´Ù.
	public:
		PROUD_API CAdoConnection(ADODB::_Connection *conn);
		//CAdoConnection(CAdoConnectionPool* connectionPool);
		PROUD_API CAdoConnection();
		PROUD_API ~CAdoConnection();
	private:
		// º¹»ç ±İÁö. ADODB COM smartptrÀ» ·¡ÇÎÇÏ°í ÀÖÀ¸³ª, Á¤ÀÛ ÀÌ ÇÔ¼öÀÇ dtor¿¡¼­ close¸¦ ÇÏ±â ¶§¹®ÀÓ.
		CAdoConnection& operator=(const CAdoConnection&);
		CAdoConnection(const CAdoConnection&);

	public:
		/**
		\~korean
		DB¿¡ ¿¬°áÇÑ´Ù. ADODB.ConnectionÀ» È®ÀåÇÑ ±â´ÉÀ» °®°í ÀÖ´Ù.
		\param pszConnStr DBMS ¿¬°á ¹®ÀÚ¿­
		- ADO DB connection string ±Ô¾àÀ» µû¸¥´Ù. ÀÚ¼¼ÇÑ °ÍÀº <a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a> Âü°í.
		- Driver È¤Àº Provider°¡ µé¾î°¡Áö ¾Ê´Â´Ù¸é,sqloledb¸¦ provider·Î »ç¿ëÇÑ´Ù.
		¾Æ·¡´Â ÇÑ ¿¹ÀÌ´Ù.
		\code
		Data Source=.;Database=ProudDB-Test;Trusted_Connection=yes // .À» ½á¾ßÁö, localhost¸¦ ¾²Áö ¸» °Í. ÀÏºÎ ÄÄ¿¡¼­ ¿¬°á ½ÇÆĞ ¿À·ù·Î ÀÌ¾îÁü.
		Data Source=.;Database=ProudDB-Test;user id=xxx;password=yyy
		\endcode

		\param AppName SQL Server Enterprise Manager¿¡¼­ Ç¥½ÃµÇ´Â ÀÌ¸§. connectionÀÇ ÀÌ¸§¿¡ Æ¯Á¤ ·çÆ¾À» ÀÇ¹ÌÇÏ´Â ÀÌ¸§À» Ãß°¡ÇÏ°í ½ÍÀ¸¸é ÀÌ°É ³ÖÀ¸¸é µ¥µå¶ô µîÀ» °¨ÁöÇÒ ¶§ ´õ µµ¿òÀÌ µÈ´Ù. ¾È ³ÖÀ¸¸é ¹«½ÃµÈ´Ù.

		\~english
		This method connects to DB. It has a function that expanse ADODB.Connection.
		\param pszConnStr DBMS link string
		- It follows the rule of ADO DB connection string. Refer to <a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a> for more details.
		- If Driver or Provider is not included, use sqloledb as provider.
		Below is an example.
		\code
		Data Source=.;Database=ProudDB-Test;Trusted_Connection=yes // use . instead of localhost. using localhost causes connection error in some computers.
		Data Source=.;Database=ProudDB-Test;user id=xxx;password=yyy
		\endcode

		\param AppName Name being displayed on SQL Server Enterprise Manager. This method helps detecting dead-lock when adding a name that points to a specific routine to the name of connection. If you don't insert this method, this will be ignores.

		\~chinese
		?ïÈÓğDB¡£?êó?î÷ ADODB.Connection îÜÍíÒö¡£
		\param pszConnStr DBMS?ïÈí®İ¬Íú
		- ñåáúADO DB connection string??¡£????ÍÅ <a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a> ¡£
		- ?êóDriverûäíºProviderîÜ?£¬÷êsqloledbéÄà÷provider¡£
		ù»Øüö¦ãÀìé?ÖÇí­¡£
		\code
		Data Source=localhost;Database=ProudDB-Test;Trusted_Connection=yes
		Data Source=localhost;Database=ProudDB-Test;user id=xxx;password=yyy
		\endcode

		\param AppName î¤SQL ServeEnterprise Manager?ãÆîÜÙ£?¡£ßÌî¤connectionîÜÙ£í®ß¾ôÕÊ¥ëòÚ«ó·÷åïÒroutineîÜìé?Ù£í®£¬ôÕÊ¥???î¤??Şİ?ÔõîÜ?ı¦êóá¶?ğ¾¡£ÜôôÕÊ¥îÜ??ù¬ûìÕÔ¡£

		\~japanese
		DBªËÖ§Ì¿ª¹ªë¡£ADODB.Connectionªò?íåª·ª¿Ñ¦Òöªòò¥ªÃªÆª¤ªŞª¹¡£
		\param pszConnStr DBMSÖ§Ì¿Ùşí®Öª
		- ADO DB connection string Ğ®å³ªË?ª¤ªŞª¹¡£ßÙª·ª¯ªÏ<a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a>ªòª´?ğÎª¯ªÀªµª¤¡£
		- DriverªŞª¿ªÏProviderª¬ìıªéªÊª±ªìªĞ¡¢sqloledbªòproviderªÈª·ªÆŞÅª¤ªŞª¹¡£
		ù»ªÏìéÖÇªÇª¹¡£ 
		\code
		Data Source=.;Database=ProudDB-Test;Trusted_Connection=yes // .ªòŞÅªÃªÆ¡¢localhostªÏŞÅªïªÊª¤ª³ªÈ¡£ìéİ»ªÎ«³«ó«Ô«å?«¿?ªÇªÏÖ§Ì¿ã÷ø¨ªÎ«¨«é?ªËªÄªÊª¬ªêªŞª¹¡£
		Data Source=.;Database=ProudDB-Test;user id=xxx;password=yyy
		\endcode
		\param AppName SQL Server Enterprise ManagerªÇøúãÆªµªìªëÙ£îñ¡£ConnectionªÎÙ£îñªË÷åïÒªÎ«ë?«Á«óªòëòÚ«ª¹ªëÙ£îñªòõÚÊ¥ª·ª¿ª¤íŞùêªÏ¡¢ª³ªìªòìıªìªìªĞ«Ç«Ã«É«í«Ã«¯ªÊªÉªòÊïò±ª¹ªëãÁªËğ¾ª«ªêªŞª¹¡£ìıªìªÊª±ªìªĞÙíãÊªµªìªŞª¹¡£ 

		\~
		 */
		PROUD_API void OpenEx(const String& pszConnStr, const PNTCHAR* AppName);

		/**
		\~korean
		DB¿¡ ¿¬°áÇÑ´Ù. ÀÚ¼¼ÇÑ °ÍÀº OpenEx µµ¿ò¸» Âü°í
		\param pszConnStr DB Connection String

		\~english
		This method connects to DB. Refer to OpenEx guideline for more details.
		\param pszConnStr DB Connection String

		\~chinese
		?ïÈÓğDB¡£??îÜ??ÍÅOpenEx?ğ¾¡£
		\param pszConnStr DB Connection String

		\~japanese
		DBªËÖ§Ì¿ª·ªŞª¹¡£ßÙª·ª¯ªÏ¡¢OpenExªò«Ø«ë«×ªòª´?ğÎª¯ªÀªµª¤¡£
		\param pszConnStr DB Connection String

		\~
		*/
		inline void Open(const String& pszConnStr)
		{
			OpenEx(pszConnStr,0);
		}

		/**
		\~korean
		DB¿¡ ¿¬°áÇÑ´Ù. ADODB.ConnectionÀ» È®ÀåÇÑ ±â´ÉÀ» °®°í ÀÖ´Ù.
		\param pszConnStr DBMS ¿¬°á ¹®ÀÚ¿­
		- ADO DB connection string ±Ô¾àÀ» µû¸¥´Ù. ÀÚ¼¼ÇÑ °ÍÀº <a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a> Âü°í.
		¾Æ·¡´Â ÇÑ ¿¹ÀÌ´Ù.
		\code
		Data Source=.;Database=ProudDB-Test;Trusted_Connection=yes // .À» ½á¾ßÁö, localhost¸¦ ¾²Áö ¸» °Í. ÀÏºÎ ÄÄ¿¡¼­ ¿¬°á ½ÇÆĞ ¿À·ù·Î ÀÌ¾îÁü.
		Data Source=.;Database=ProudDB-Test;user id=xxx;password=yyy

		//MySql
		Driver={MySQL ODBC 5.1 Driver};server=xxx.xxx.xxx.xxx;port=3306;Database=TableName;User ID=UserID;Password=yyy;
		\endcode

		\param AppName SQL Server Enterprise Manager¿¡¼­ Ç¥½ÃµÇ´Â ÀÌ¸§. connectionÀÇ ÀÌ¸§¿¡ Æ¯Á¤ ·çÆ¾À» ÀÇ¹ÌÇÏ´Â ÀÌ¸§À» Ãß°¡ÇÏ°í ½ÍÀ¸¸é ÀÌ°É ³ÖÀ¸¸é µ¥µå¶ô µîÀ» °¨ÁöÇÒ ¶§ ´õ µµ¿òÀÌ µÈ´Ù. ¾È ³ÖÀ¸¸é ¹«½ÃµÈ´Ù.
		\param Type DbmsTypeÇüÅÂÀÇ enum°ªÀ» ³Ö½À´Ï´Ù.MsSql,MySqlµîÀÌ ÀÖ½À´Ï´Ù.(MsSqlÀº ³»ºÎÀûÀ¸·Î sqloledb ProviderÀ» »ç¿ëÇÏ°í ÀÖ½À´Ï´Ù.)

		\~english TODO:translate needed.
		This method connects to DB. It has a function that expans ADODB.Connection.
		\param pszConnStr DBMS link string
		- It follows the rule of ADO DB connection string. Refer to <a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a> for more details.
		Below is one example.
		\code
		Data Source=.;Database=ProudDB-Test;Trusted_Connection=yes // .À» ½á¾ßÁö, localhost¸¦ ¾²Áö ¸» °Í. ÀÏºÎ ÄÄ¿¡¼­ ¿¬°á ½ÇÆĞ ¿À·ù·Î ÀÌ¾îÁü.
		Data Source=.;Database=ProudDB-Test;user id=xxx;password=yyy

		//MySql
		Driver={MySQL ODBC 5.1 Driver};server=xxx.xxx.xxx.xxx;port=3306;Database=TableName;User ID=UserID;Password=yyy;
		\endcode

		\param AppName Name being displayed on SQL Server Enterprise Manager. This method helps detecting dead-lock when adding a name that points to a specific routine to the name of connection. It ignores if you don't insert this method.
		\param Type This inserts enum value of DbmsType such as for Sql,MySql and etc.(MsSql internally uses sqloledb Provider.)

		\~chinese
		?ïÈÓğDB¡£?êó?î÷ ADODB.Connection îÜÍíÒö¡£
		\param pszConnStr DBMS?ïÈí®İ¬Íú
		- ñåáúADO DB connection string??¡£????ÍÅ <a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a> ¡£
		ù»Øüö¦ãÀìé?ÖÇí­¡£
		\code
		Data Source=localhost;Database=ProudDB-Test;Trusted_Connection=yes
		Data Source=localhost;Database=ProudDB-Test;user id=xxx;password=yyy

		//MySql
		Driver={MySQL ODBC 5.1 Driver};server=xxx.xxx.xxx.xxx;port=3306;Database=TableName;User ID=UserID;Password=yyy;
		\endcode

		\param AppName î¤SQL ServeEnterprise Manager?ãÆîÜÙ£?¡£ßÌî¤connectionîÜÙ£í®ß¾ôÕÊ¥ëòÚ«ó·÷åïÒroutineîÜìé?Ù£í®£¬ôÕÊ¥???î¤??Şİ?ÔõîÜ?ı¦êóá¶?ğ¾¡£ÜôôÕÊ¥îÜ??ù¬ûìÕÔ¡£
		\param Type Û¯ìıDbmsTypeû¡ãÒîÜenum?¡£êó.MsSql£¬MySql Ôõ¡££¨MsSql ?İ»ŞÅéÄsqloledb Provider¡££©

		\~japanese
		DBªËÖ§Ì¿ª·ªŞª¹¡£ADODB.Connectionªò?íåª¹ªëÑ¦Òöªòò¥ªÃªÆª¤ªŞª¹¡£
		\param pszConnStr DBMSÖ§Ì¿Ùşí®Öª
		- ADO DB connection string Ğ®å³ªò?ª¤ªŞª¹¡£ßÙª·ª¯ªÏ¡¢ <a href="http://www.connectionstrings.com/" target="_blank">http://www.connectionstrings.com/</a>ªòª´?ğÎª¯ªÀªµª¤¡£
		ù»ªÏìéÖÇªÇª¹¡£
		\code
		Data Source=.;Database=ProudDB-Test;Trusted_Connection=yes // .ªòŞÅªÃªÆ¡¢localhostªÏŞÅªïªÊª¤ª³ªÈ¡£ìéİ»ªÎ«³«ó«Ô«å?«¿?ªÇªÏÖ§Ì¿ã÷ø¨«¨«é?ªËªÄªÊª¬ªêªŞª¹¡£
		Data Source=.;Database=ProudDB-Test;user id=xxx;password=yyy

		//MySql
		Driver={MySQL ODBC 5.1 
		Driver};server=xxx.xxx.xxx.xxx;port=3306;Database=TableName;User ID=UserID;Password=yyy;
		\endcode

		\param AppName SQL Server Enterprise ManagerªÇøúãÆªµªìªëÙ£îñ¡£ConnectionªÎÙ£îñªË÷åïÒªÎ«ë?«Á«óªòëòÚ«ª¹ªëÙ£îñªòõÚÊ¥ª·ª¿ª¤íŞùêªÏ¡¢ª³ªìªòìıªìªìªĞ«Ç«Ã«É«í«Ã«¯ªÊªÉªòÊïò±ª¹ªëãÁªËğ¾ª«ªêªŞª¹¡£ìıªìªÊª±ªìªĞÙíãÊªµªìªŞª¹¡£ 
		\param Type DbmsTypeû¡÷¾ªÎenumö·ªòìıªìªŞª¹¡£MsSql,MySqlªÊªÉª¬ª¢ªêªŞª¹¡£(MsSqlªÏ?İ»îÜªËsqloledb ProviderªòŞÅéÄª·ªÆª¤ªŞª¹¡£)

		\~
		*/
		PROUD_API void OpenEx(const String& pszConnStr, const PNTCHAR* AppName, DbmsType Type);

		/**
		\~korean
		DB¿¡ ¿¬°áÇÑ´Ù. ÀÚ¼¼ÇÑ °ÍÀº OpenEx µµ¿ò¸» Âü°í
		\param pszConnStr DB Connection String
		\param type

		\~english
		This method connects to DB. Refer to OpenEx guideline for more details.
		\param pszConnStr DB Connection String

		\~chinese
		?ïÈDB¡£??îÜ??ÍÅOpenEx?ğ¾¡£
		\param pszConnStr DB Connection String
		\param type

		\~japanese
		DBªËïÈ?ª·ªŞª¹¡£ßÙª·ª¯ªÏ¡¢OpenExªÎ«Ø«ë«×ªòª´?ğÎª¯ªÀªµª¤¡£
		\param pszConnStr DB Connection String
		\param type
		(çÈåŞ£º¡°\param type¡± ×©ªì)

		\~
		*/
		inline void Open(const String& pszConnStr, DbmsType Type)
		{
			OpenEx(pszConnStr,0,Type);
		}

		/**
		\~korean
		ADODB¸¦ ´İ½À´Ï´Ù.

		\~english
		ADODB will be closed.

		\~chinese
		??ADODB

		\~japanese
		ADODBªòøÍª¸ªŞª¹¡£
		\~
		*/
		PROUD_API void Close();

		/**
		\~korean
		ADODB¸¦ ´İ½À´Ï´Ù.
		- throw¸¦ ¹ß»ı½ÃÅ°Áö ¾Ê½À´Ï´Ù

		\~english
		ADODB will be closed.
		- throw will not occur.

		\~chinese
		??ADODB¡£
		- Üô??ßæthrow¡£

		\~japanese
		ADODBªòøÍª¸ªŞª¹¡£
		- throwªò?ßæªµª»ªŞª»ªó¡£
		\~
		*/
		PROUD_API void Close_NoThrow();

		/**
		\~korean
		ADO °´Ã¼°¡ DB ¼­¹ö¿¡ ¿¬°áµÆ´ÂÁö?
		\return ¿¬°á ¼º°øÇÏ¸é true¸¦ ¸®ÅÏÇÏ°í, ½ÇÆĞÇÏ¸é false¸¦ ¸®ÅÏÇÕ´Ï´Ù.

		\~english
		 Is ADO object connected to DB server?
		\return true if it succeed to connect DB;false if it failed to connect DB

		\~chinese
		ADO ?ßÚãÀÜú?DBÜ×?Ğï?ïÈ£¿
		\return ?ïÈà÷ÍíîÜ?Ú÷üŞtrue£¬ã÷?Ú÷üŞfalse¡£

		\~japanese
		ADO«ª«Ö«¸«§«¯«Èª¬DB«µ?«Ğ?ªËªÄªÊª¬ªÃªÆª¤ªŞª¹ª«£¿
		\return Ö§Ì¿ªËà÷Ííª¹ªëªÈtrueªò«ê«¿?«óª·ªÆ¡¢ã÷ø¨ª¹ªëªÈfalseªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		PROUD_API bool IsOpened();

		/**
		\~korean
		SQL ±¸¹®À» ½ÇÇàÇÑ´Ù. printf()Ã³·³ »ç¿ë °¡´É.
		\param lpszSQL Äõ¸® ±¸¹®
		\return stored procedure¿¡ ÀÇÇØ ¿µÇâ¹ŞÀº recordÀÇ °¹¼ö, ¿µÇâ¹ŞÀº ÇàÀÌ ¾ø°Å³ª ½ÇÆĞ½Ã 0, Select ±¸¹®ÀÌ¸é -1 ¸®ÅÏ

		\~english
		Executes SQL syntax. Can use as printf().
		\param lpszSQL SQL syntax
		\return Number of records affected by stored procedure; 0 if no rows were affected or the statement failed; and -1 for SELECT statements

		\~chinese
		?ú¼SQL?Ï£¡£?printf()ìé?Ê¦ì¤ŞÅéÄ¡£
		\param lpszSQL SQL ?Ï£
		\return ù¬stored procedureáôç¯?îÜrecordîÜ??£¬?êóáôç¯?îÜú¼ûäíºã÷??ãÀ0£¬Select ?Ï£îÜ?Ú÷üŞ-1¡£

		\~japanese
		SQLÏ°Ùşªò?ú¼ª·ªŞª¹¡£printf()ªÎªèª¦ªËŞÅéÄÊ¦ÒöªÇª¹¡£
		\param lpszSQL «¯«¨«ê?Ï°Ùş
		\return stored procedureªËªèªÃªÆç¯úÂªµªìª¿recordªÎ?¡¢ç¯úÂªòáôª±ª¿ú¼ª¬ªÊª¤ªÈª«ã÷ø¨ãÁ0¡¢SelectÏ°ÙşªÇª¢ªìªĞ-1ªò«ê«¿?«ó
		\~
		  */
		PROUD_API long Execute(const String& lpszSQL);

		/**
		\~korean
		SQL ±¸¹®À» ½ÇÇàÇÕ´Ï´Ù.°á°ú´Â outputRecords¿¡ ÀúÀåµË´Ï´Ù.
		\param outRecordset ¹Ş¾Æ¿Ã °á°ú ·¹ÄÚµå¼Â.
		\param lpszSQL Äõ¸® ±¸¹®
		\return stored procedure¿¡ ÀÇÇØ ¿µÇâ¹ŞÀº recordÀÇ °¹¼ö, ¿µÇâ¹ŞÀº ÇàÀÌ ¾ø°Å³ª ½ÇÆĞ½Ã 0, Select ±¸¹®ÀÌ¸é -1 ¸®ÅÏ

		\~english
		Executes SQL syntax. The result gets stored at outputRecords.
		\param outRecordset Recordset of results to get.
		\param lpszSQL SQL syntax
		\return Number of records affected by stored procedure; 0 if no rows were affected or the statement failed; and -1 for SELECT statements

		\~chinese
		?ú¼SQL?Ï£¡£?Íı?ğíéÍoutputRecords¡£
		\param outRecordset é©ÔğÓğRecordset?Íı
		\param lpszSQL SQL ?Ï£
		\return ù¬stored procedureáôç¯?îÜrecordîÜ??£¬?êóáôç¯?îÜú¼ûäíºã÷??ãÀ0£¬Select ?Ï£îÜ?Ú÷üŞ-1¡£

		\~japanese
		SQLÏ°Ùşªò?ú¼ª·ªŞª¹¡£Ì¿ÍıªÏoutputRecordsªËÜÁğíªµªìªŞª¹¡£
		\param outRecordset ªòáôª±ö¢ªëÌ¿Íı«ì«³?«É«»«Ã«È¡£
		\param lpszSQL «¯«¨«ê?Ï°Ùş
		\return stored procedureªËªèªÃªÆç¯úÂªµªìª¿record?¡¢ç¯úÂªµªìª¿ú¼ª¬ªÊª¤ª«ã÷ø¨ãÁ0¡¢SelectÏ°ÙşªÇª¢ªìªĞ-1ªò«ê«¿?«ó
		\~
		 */
		PROUD_API long Execute(CAdoRecordset& outputRecords, const String& lpszSQL);

		/**
		\~korean
		DB Æ®·£Àè¼ÇÀ» ½ÃÀÛÇÕ´Ï´Ù.

		\~english
		DB transaction begins

		\~chinese
		DB transaction îÜ?ã·

		\~japanese
		DB«È«é«ó«¶«¯«·«ç«óªòËÒã·ª·ªŞª¹¡£
		\~
		  */
		inline void BeginTrans() {  (*this)->BeginTrans(); }

		/**
		\~korean
		DB Æ®·£Àè¼Ç ·Ñ¹é

		\~english
		DB transaction rollback

		\~chinese
		DB transaction îÜüŞ?

		\~japanese
		DB«È«é«ó«¶«¯«·«ç«ó«í?«ë«Ğ«Ã«¯
		\~
		  */
		inline void RollbackTrans() {  (*this)->RollbackTrans(); }

		/**
		\~korean
		DB Æ®·£Àè¼Ç Ä¿¹Ô

		\~english
		 DB transaction commit

		\~chinese
		DB transaction îÜğ«Îß

		\~japanese
		DB«È«é«ó«¶«¯«·«ç«ó«³«ß«Ã«È
		\~
		  */
		inline void CommitTrans() {  (*this)->CommitTrans(); }
	private:
	};

	extern CriticalSection* ADODB_RefCriticalSection;

	typedef void(*ADODB_RecommendCriticalSectionProc_t)( const String& text );
	extern ADODB_RecommendCriticalSectionProc_t ADODB_RecommendCriticalSectionProc;

	/**
	\~korean
	ADO Recordset Å¬·¡½º + ¸î°¡Áö ±â´É Çâ»ó

	¿ëµµ
	- CAdoConnection °ú È¥¿ëÇÑ´Ù.

	\~english
	 ADO Recordset class + some enhanced functions

	Use
	- Use this method with CAdoConnection.

	\~chinese
	ADO Recordset ?+??ÍíÒöËÇ?

	éÄÔ²
	- ? CAdoConnection%ûèéÄ¡£

	\~japanese
	ADO Recordset«¯«é«¹£«ª¤ªÄª¯ª«ªÎÑ¦Òöú¾ß¾
	éÄÔ²
	- CAdoConnectionªÈûèéÄª·ªŞª¹¡£
	\~
	  */
	class CAdoRecordset:public ADODB::_RecordsetPtr,protected CQueryChecker
	{
	public:
		PROUD_API CAdoRecordset();

		inline CAdoRecordset(ADODB::_Recordset *rc)
		{
			if(rc)
				Attach(rc,true);		// AddRef, not Attach
		}

		inline ~CAdoRecordset()
		{
			Close_NoThrow(); // ÀÌ°Ô ÀÖ´Â ÀÌÀ¯´Â ~CAdoConnection()¿¡ ÀûÇôÀÖÀ½. ¹İµå½Ã ÀÖ¾î¾ß ÇÔ.
		}

		inline CAdoRecordset& operator=(ADODB::_Recordset *rc)
		{
			if(rc)
				Attach(rc,true);

			return *this;
		}
	private:
		// º¹»ç ±İÁö. ADODB COM smartptrÀ» ·¡ÇÎÇÏ°í ÀÖÀ¸³ª, Á¤ÀÛ ÀÌ ÇÔ¼öÀÇ dtor¿¡¼­ close¸¦ ÇÏ±â ¶§¹®ÀÓ.
		CAdoRecordset& operator=(const CAdoRecordset&);
		CAdoRecordset(const CAdoRecordset&);
	public:

		// various ways of accessing bind data

/*		inline void GetFV(bool& value,LPCWSTR pszFieldName)
		{ value=GetInterfacePtr()->GetCollect(pszFieldName); }

		inline void SetFV(LPCWSTR pszFieldName,bool value)
		{ GetInterfacePtr()->PutCollect(pszFieldName,value); }

		inline void GetFV(long& value,LPCWSTR pszFieldName)
		{ value=GetInterfacePtr()->GetCollect(pszFieldName); }

		inline void SetFV(LPCWSTR pszFieldName,long value)
		{ GetInterfacePtr()->PutCollect(pszFieldName,value); }

		inline void GetFV(float& value,LPCWSTR pszFieldName)
		{ value=GetInterfacePtr()->GetCollect(pszFieldName); }

		inline void SetFV(LPCWSTR pszFieldName,float value)
		{ GetInterfacePtr()->PutCollect(pszFieldName,value); }

		inline void GetFV(DATE& value,LPCWSTR pszFieldName)
		{ value=GetInterfacePtr()->GetCollect(pszFieldName); }

		inline void SetFV(LPCWSTR pszFieldName,DATE value)
		{ GetInterfacePtr()->PutCollect(pszFieldName,value); }

		inline void GetFV(String &value,LPCWSTR pszFieldName)
		{ value=(LPCWSTR)(_bstr_t)GetInterfacePtr()->GetCollect(pszFieldName); }

		inline void SetFV(LPCWSTR pszFieldName,LPCWSTR value)
		{ GetInterfacePtr()->PutCollect(pszFieldName,value); } */

		PROUD_API bool GetFieldValue(const String& pszFieldName, String &var);
		PROUD_API bool GetFieldValue(const String& pszFieldName, UUID &var);
		PROUD_API bool GetFieldValue(const String& pszFieldName, COleDateTime &var);

		PROUD_API CVariant GetFieldValue(const String& pszFieldName);
		PROUD_API void SetFieldValue(const String& pszFieldName, const CVariant &value);

		PROUD_API CVariant GetFieldValue(int index);
		PROUD_API void SetFieldValue(int index,const CVariant &value);

		/**
		\~korean
		ÇÊµåÀÇ °ªÀ» ÀĞ°í ¾´´Ù.
		- ÆÄ¶ó¸ŞÅÍ·Î CVariant¸¦ ¾²¹Ç·Î ¾î¶°ÇÑ Å¸ÀÔÀÇ µ¥ÀÌÅÍµçÁö ÀĞ°í ¾µ ¼ö ÀÖ´Ù.
		- ¹è¿­ ÀÎÀÚ·Î ÇÊµå ¹®ÀÚ¿­ÀÌ³ª 0 based ÀÎµ¦½º ¼ıÀÚ¸¦ ¾µ ¼ö ÀÖ´Ù.

		\~english
		Reads and writes field value.
		- It can read and write just about any type of data since it use CVariant as parameter.
		- It can use field string or 0 based index number as array factor.

		\~chinese
		???æ´îÜ?¡£
		- éÄ??? CVariant%£¬ì×ó®Òö??ìòù¼?úşîÜ?Ëß¡£
		- éÄÛÉÖªì×í­???æ´í®İ¬Íúûäíº0 baseßãìÚ?Ëß¡£

		\~japanese
		«Õ«£?«ë«Éö·ªò?ªßßöª­ªŞª¹¡£
		- «Ñ«é«á?«¿?ªÈª·ªÆCVariantªòŞÅª¤ªŞª¹ªÎªÇ¡¢ªÉªÎ«¿«¤«×ªÎ«Ç?«¿ªâ?ªßßöª­ªÇª­ªŞª¹¡£
		- ÛÕÖªì×í­ªÈª·ªÆ«Õ«£?«ë«ÉªÎÙşí®Öªªä0 based«¤«ó«Ç«Ã«¯«¹?í®ªòßöª¯ª³ªÈª¬ªÇª­ªŞª¹¡£
		\~
		*/
#if defined (_MSC_VER)
		__declspec(property(get=GetFieldValue,put=SetFieldValue)) CVariant FieldValues[];
#endif

		PROUD_API _bstr_t GetFieldNames(int index);

		/**
		\~korean
		ÇÊµåÀÇ ÀÌ¸§À» ¾ò´Â´Ù.
		- ¹è¿­ ÀÎÀÚ·Î 0 based ÀÎµ¦½º ¼ıÀÚ¸¦ ¾µ ¼ö ÀÖ´Ù.

		\~english
		This method obtain name of field.
		- It can use 0 based index number as an array factor.

		\~chinese
		?Ôğ?æ´îÜÙ£?¡£
		- éÄÛÉÖªì×í­?ìı0 basedßãìÚ?í®¡£

		\~japanese
		«Õ«£?«ë«ÉÙ£ªòö¢ªê?ªßªŞª¹¡£
		- ÛÕÖªì×í­ªÇ0 based«¤«ó«Ç«Ã«¯«¹?í®ªòŞÅª¦ª³ªÈª¬ªÇª­ªŞª¹¡£
		\~
		*/
#if defined (_MSC_VER)
		__declspec(property(get=GetFieldNames)) _bstr_t FieldNames[];
#endif
		/**
		\~korean
		ADODB¸¦ ´İ½À´Ï´Ù.

		\~english
		ADODB will be closed.

		\~chinese
		??ADODB¡£

		\~japanese
		ADODBªòøÍª¸ªŞª¹¡£
		\~
		*/
		PROUD_API void Close();

		/**
		\~korean
		ADODB¸¦ ´İ½À´Ï´Ù.
		- throw¸¦ ¹ß»ı½ÃÅ°Áö ¾Ê½À´Ï´Ù

		\~english
		ADODB will be closed.
		- throw will not occur.

		\~chinese
		??ADODB¡£
		- Üô??ßæthrow¡£

		\~japanese
		ADODBªòøÍª¸ªŞª¹¡£
		- throwªò?ßæªµª»ªŞª»ªó¡£
		\~
		*/
		PROUD_API void Close_NoThrow();

		/**
		\~korean
		·¹ÄÚµåÀÇ ³¡ÀÎÁö È®ÀÎÇÕ´Ï´Ù.
		\return ³¡ÀÌ¸é true ¾Æ´Ï¸é false

		\~english TODO:translate needed.
		Check whether this is the end of the record
		\return If it is the end, then true, otherwise false. 

		\~chinese
		??ãÀÜúãÀrecordîÜõÌı¨¡£
		\return ?áÖîÜ?true£¬ÜôãÀîÜ?false¡£

		\~japanese
		«ì«³?«ÉªÎğûÓ®ªÎª«ªòü¬ìãª·ªŞª¹¡£
		\return ğûÓ®ªÇª¢ªìªĞtrueª«false
		\~
		*/
		inline bool IsEOF()
		{
			return GetInterfacePtr()->adoEOF?true:false;
		}

		/**
		\~korean
		ADODB°¡ open»óÅÂÀÎÁö È®ÀÎÇÕ´Ï´Ù.
		\return open »óÅÂÀÌ¸é true, close »óÅÂÀÌ¸é false

		\~english TODO:translate needed.
		Check whether ADODB is in open status. 
		\return If open, true. If close, false. 

		\~chinese
		??ADODBãÀÜúãÀopen??¡£
		\return open??îÜ?true£¬close ??îÜ?false¡£

		\~japanese
		ADODBª¬open?÷¾ªÊªÎª«ªòü¬ìãª·ªŞª¹¡£
		\return open?÷¾ªÇª¢ªìªĞtrue¡¢close?÷¾ªÇª¢ªìªĞfalse
		\~
		*/
		PROUD_API bool IsOpened();

		/**
		\~korean
		DbmsSaveÇÔ¼ö¸¦ ÅëÇÏ¿© ÀúÀåµÈ µ¥ÀÌÅÍ¸¦ ¾÷µ¥ÀÌÆ® ½ÃÅµ´Ï´Ù.

		\~english TODO:translate needed.
		Through DbmsSave function, update the saved data


		\~chinese
		÷×?DbmsSaveùŞ?£¬ÌÚãæğí?îÜ?Ëß¡£

		\~japanese
		DbmsSave??ªò÷×ª¸ÜÁğíªµªìª¿«Ç?«¿ªò«¢«Ã«×«Ç?«Èªµª»ªŞª¹¡£
		
		\~
		*/
		PROUD_API void Update();

		/**
		\~korean
		»õ·Î¿î µ¥ÀÌÅÍ¸¦ Ãß°¡ÇÒ °ÍÀ» ¿¹¾àÇÕ´Ï´Ù.

		\~english TODO:translate needed.
		Reserve to add new data


		\~chinese
		??ôÕÊ¥ãæîÜ?Ëß¡£

		\~japanese
		ãæª·ª¤«Ç?«¿ªòõÚÊ¥ª¹ªëª³ªÈªòåøå³ª·ªŞª¹¡£
		\~
		*/
		PROUD_API void AddNew();

		/**
		\~korean
		µ¥ÀÌÅÍ¸¦ Á¦°ÅÇÕ´Ï´Ù.

		\~english TODO:translate needed.
		Get rid of data


		\~chinese
		?ğ¶?Ëß¡£

		\~japanese
		«Ç?«¿ªòğ¶ËÛª·ªŞª¹¡£
		\~
		*/
		PROUD_API void Delete();

		/**
		\~korean
		RecordsetÀ» ¿¬´Ù.
		\param conn DB ¿¬°á °´Ã¼
		\param openFor OpenForRead: ÀĞ±â Àü¿ë, OpenForReadWrite, OpenForAppend: ÀĞ±â/¾²±â. °ÔÀÓ ¼­¹ö»ó¿¡¼­ ¿ëµµ°¡ ÃÖÀûÈ­µÈ °ªÀÌ´Ù.
		\param lpszSQL Äõ¸® ±¸¹®.

		\~english
		This method opens Recordset.
		\param conn DB Link Object
		\param openFor OpenForRead: Read Only, OpenForReadWrite, OpenForAppend: Read/Write. The most optimized values for game server use.
		\param lpszSQL Query Syntax.

		\~chinese
		öè?Recordset¡£
		\param conn DB?ïÈ?ßÚ
		\param openFor OpenForRead:?éÄéÍ?£¬OpenForReadWrite, OpenForAppend:?/?£¬êı?Ü×?ĞïñééÄÔ²ù¬?ûùîÜ?¡£
		\param lpszSQL SQL?Ï£¡£

		\~japanese
		RecordsetªòËÒª¯¡£
		\param conn DBÖ§Ì¿«ª«Ö«¸«§«¯«È
		\param openFor OpenForRead£º?ªßö¢ªê?éÄ¡¢OpenForReadWrite, OpenForAppend£º?ªßö¢ªê/ßöª­?ªß¡£«²?«à«µ?«Ğ?ß¾ªÇéÄÔ²ª¬õÌîêûùªµªìª¿ö·ªÇª¹¡£ 
		\param lpszSQL «¯«¨«ê?Ï°Ùş
		\~
		*/
		PROUD_API void Open(ADODB::_Connection *conn, DbOpenFor openFor, const String& queryString);

		/**
		\~korean
		RecordsetÀ» ¿¬´Ù.
		\param conn DB ¿¬°á °´Ã¼
		\param cursorType ADODB::CursorTypeEnum
		\param lockType ADODB::LockTypeEnum
		\param lpszSQL Äõ¸® ±¸¹®.

		\~english
		This method opens Recordset.
		\param conn DB Link Object
		\param cursorType ADODB::CursorTypeEnum
		\param lockType ADODB::LockTypeEnum
		\param lpszSQL Query Syntax.

		\~chinese
		öè?Recordset¡£
		\param conn DB?ïÈ?ßÚ
		\param cursorType ADODB::CursorTypeEnum
		\param lockType ADODB::LockTypeEnum
		\param lpszSQL SQL?Ï£¡£

		\~japanese
		RecordsetªòËÒª¯
		\param conn DBÖ§Ì¿«ª«Ö«¸«§«¯«È
		\param cursorType ADODB::CursorTypeEnum
		\param lockType ADODB::LockTypeEnum		
		\param lpszSQL «¯«¨«ê?Ï°Ùş
		
		\~
		*/
		PROUD_API void Open(ADODB::_Connection *conn, ADODB::CursorTypeEnum cursorType, ADODB::LockTypeEnum lockType, const String& lpszSQL);

		/**
		\~korean
		¸ğµç parameter¸¦ default value·Î ÇÏ¿© ¿¬´Ù.
		ADO command¿¡¼­ returnÇÑ recordset object¸¦ openÇÒ ¶§ »ç¿ëµÉ ¼ö ÀÖ´Ù.

		\~english
		This method opens all parameters as default value.
		This can be used when opening recordset object returned by ADO command.

		\~chinese
		÷êá¶êóîÜparameter?ñ®default valueöè?¡£
		Ê¦ì¤î¤öè?ADO commandreturnîÜrecordset objectîÜ?ı¦Ê¦ì¤ŞÅéÄ¡£

		\~japanese
		îïªÆªÎparameterªòdefault valueªËª·ªÆËÒª­ªŞª¹¡£
		ADO commandªÇreturnª·ª¿recordset objectªòopenª¹ªëãÁªËŞÅªïªìªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\~
		*/
		PROUD_API void Open(void);

		/**
		\~korean
		ADODB::adOpenStatic Å¸ÀÔÀÇ Cursor ·Î recordset À» ¿¬´Ù.
		ADO command¿¡¼­ returnÇÑ recordset object¸¦ openÇÒ ¶§ »ç¿ëµÉ ¼ö ÀÖ´Ù.

		\~english
		This method opens all parameters as default value.
		This can be used when opening recordset object returned by ADO command.

		\~chinese
		éÄADODB::adOpenStatic ?úşîÜcursoröè?recordset¡£
		Ê¦ì¤î¤öè?ADO commandreturnîÜrecordset objectîÜ?ı¦ŞÅéÄ¡£

		\~japanese
		ADODB::adOpenStatic «¿«¤«×ªÎCursorªÇrecordsetªòËÒª­ªŞª¹¡£
		ADO commandªÇreturnª·ª¿recordset objectªòopenª¹ªëãÁªËŞÅªïªìªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\~
		*/
		PROUD_API void OpenForUpdate();

		/**
		\~korean
		\param src \ref CAdoOfflineRecord¿¡ ÀÖ´Â key°ª°ú value°ªÀ» Â÷·Ê·Î º¹»çÇØ¿É´Ï´Ù.

		\~english TODO:translate needed.
		The key value and the value in \param src \ref CAdoOfflineRecord is copied one by one. 


		\~chinese
		\param src ëîó­?ğ¤\ref CAdoOfflineRecord%îÜkey?ûúvalue?¡£

		\~japanese
		\param src \ref CAdoOfflineRecordªËª¢ªëkeyö·ªÈvalueö·ªòâ÷ªË«³«Ô?ª·ªÆª­ªŞª¹¡£
		\~
		*/
		PROUD_API void CopyFrom(CAdoOfflineRecord &src);
		const static int defaultCacheSize=100;

		/**
		\~korean
		´ÙÀ½ ·¹ÄÚµå·Î Ä¿¼­¸¦ ¿Å±ä´Ù.

		\~english
		This method moves cursor to the next record.

		\~chinese
		÷êÎÃ?ì¹?Óğù»ìé?recordß¾¡£

		\~japanese
		ó­ªÎ«ì«³?«ÉªË««?«½«ëªòì¹ª·ªŞª¹¡£
		\~
		 */
		PROUD_API void MoveNext();

		/**
		\~korean
		Ã³À½ ·¹ÄÚµå·Î Ä¿¼­¸¦ ¿Å±ä´Ù.

		\~english
		This method moves cursor to the initial record

		\~chinese
		÷êÎÃ?ì¹?Óğôøã·recordß¾¡£

		\~japanese
		õÌôøªÎ«ì«³?«ÉªË««?«½«ëªòì¹ª·ªŞª¹¡£
		\~
		 */
		PROUD_API void MoveFirst();

		/**
		\~korean
		ÀÌÀü ·¹ÄÚµå·Î Ä¿¼­¸¦ ¿Å±ä´Ù.

		\~english
		This method moves cursor to the previous record

		\~chinese
		÷êÎÃ?ì¹?Óğß¾ìé?recordß¾¡£

		\~japanese
		ì¤îñªÎ«ì«³?«ÉªË««?«½«ëªòì¹ª·ªŞª¹¡£
		\~
		 */
		PROUD_API void MovePrevious();

		/**
		\~korean
		 ¸¶Áö¸· ·¹ÄÚµå·Î Ä¿¼­¸¦ ¿Å±ä´Ù.

		\~english
		This method moves cursor to the last record.

		\~chinese
		÷êÎÃ?ì¹?ÓğõÌı¨ìé?recordß¾¡£

		\~japanese
		õÌı­ªÎ«ì«³?«ÉªË««?«½«ëªòì¹ª·ªŞª¹¡£
		\~
		 */
		PROUD_API void MoveLast();

		/**
		\~korean
		´ÙÀ½ ·¹ÄÚµå¼ÂÀ¸·Î ÀÌµ¿ÇÕ´Ï´Ù.
		- ´ÙÀ½ ·¹ÄÚµå¼ÂÀ» ÀÚ±âÀÚ½Å¿¡°Ô ÇÒ´çÇÕ´Ï´Ù.
		\param recordsAffected Äõ¸®¿¡ ¿µÇâÀ» ¹ŞÀº ·¹ÄÚµå °¹¼ö

		\~english
		This method moves to the next recordset.
		- Assign the next recordset to itself.
		\param recordsAffected Number of records being affected by query

		\~chinese
		ì¹?Óğù»ìé?recordset¡£
		- ÷êù»ìé?recordsetİÂÛÕ?í»Ğù¡£
		\param recordsAffected áôSQLç¯?îÜrecord??

		\~japanese
		ó­ªÎ«ì«³?«É«»«Ã«ÈªËì¹ÔÑª·ªŞª¹¡£
		- ó­ªÎ«ì«³?«É«»«Ã«Èªòí»İÂí»ãóªËùÜªê?ªÆªŞª¹¡£
		\param recordsAffected «¯«¨«ê?ªËªèªÃªÆç¯úÂªòáôª±ª¿«ì«³?«É?
		\~
		 */
		PROUD_API bool MoveNextRecordset(long *recordsAffected = NULL);
		/**
		\~korean
		´ÙÀ½ ·¹ÄÚµå¼ÂÀ» ´Ù¸¥ ÀÎ½ºÅÏ½º¿¡°Ô ³Ñ°ÜÁİ´Ï´Ù.
		\param outRecordset ´ÙÀ½ ·¹ÄÚµå¼ÂÀ» ³Ñ°Ü¹ŞÀ» ·¹ÄÚµå¼Â ÀÎ½ºÅÏ½º
		\param recordsAffected Äõ¸®¿¡ ¿µÇâÀ» ¹ŞÀº ·¹ÄÚµå °¹¼ö

		\~english
		This method passes the next recordset to a different instance.
		\param outRecordset Recordset instance which will receive the next recordset
		\param recordsAffected Number of records being affected by query

		\~chinese
		÷êù»ìé?recordset?Ğìöâinstance
		\param outRecordset ïÈÓğù»ìé?recordsetîÜrecordset instance
		\param recordsAffected áôqueryç¯?îÜrecordset??

		\~japanese
		ó­ªÎ«ì«³?«É«»«Ã«ÈªòöâªÎ«¤«ó«¹«¿«ó«¹ªËìÚª­Ô¤ª·ªŞª¹¡£
		\param outRecordset ó­ªÎ«ì«³?«É«»«Ã«ÈªòìÚª­Ô¤ª¹«ì«³?«É«»«Ã«ÈªÎ«¤«ó«¹«¿«ó«¹
		\param recordsAffected «¯«¨«ê?ªËªèªÃªÆç¯úÂªòáôª±ª¿«ì«³?«É?
		\~
		 */
		PROUD_API void NextRecordset(OUT CAdoRecordset& outRecordset,OUT long *recordsAffected=NULL);
	};

	/**
	\~korean
	ADO Command object¸¦ wrappingÇÑ Å¬·¡½ºÀÌ´Ù.

	ÀÌ°ÍÀ¸·Î stored procedure¸¦ È£ÃâÇÏ´Â ¹æ¹ıÀº ´ÙÀ½°ú °°´Ù.
	- Prepare·Î È£ÃâÇÒ stored procedure, active connectionÀ» ¼³Á¤ÇÑ´Ù.
	- Parameters ¸â¹ö·Î ÀÔ·Â ¾Æ±Ô¸ÕÆ®¸¦ ¼³Á¤ÇÑ´Ù.
	- Execute·Î ÁØºñµÈ stored procedure¸¦ È£ÃâÇÑ´Ù.
	- Parameters ¸â¹ö·Î Ãâ·Â ¾Æ±Ô¸ÕÆ®¸¦ ±¸ÇÑ´Ù.

	\~english
	This is a class wrapping ADO Command object.

	How to call stored procedure with this method is shown in below.
	- Set stored procedure and active connection to call as Prepare.
	- Set input arguments with Parameters member.
	- Call already prepared stored procedure with Execute.
	- Get output argument with Parameters member.

	\~chinese
	÷êADO Command object wrappingîÜ?¡£
	éÄ??û¼Ğ£stored procedureîÜÛ°Ûöåıù»¡£
	- ?öÇéÄprepareû¼õóîÜstored procedure, active connection¡£
	- éÄparametersà÷??öÇ?ìıarguments¡£
	- û¼õó û¼Ğ£éÄexecuteñ×?îÜstored procedure¡£
	- éÄparameterà÷??õóarguments¡£


	\~japanese
	ADO Command objectªòwrappingª·ª¿«¯«é«¹ªÇª¹¡£
	ª³ªìªÇstored procedureªòû¼ªÓõóª¹Û°ÛöªÏó­ªÎ÷×ªêªÇª¹¡£
	- PrepareªÇû¼ªÓõóª¹stored procedure, active connectionªòàâïÒª·ªŞª¹¡£
	- Parameters «á«ó«Ğ?ªÇìıÕô«¢?«®«å«á«ó«ÈªòàâïÒª·ªŞª¹¡£
	- ExecuteªÇñŞİáªµªìª¿stored procedureªòû¼ªÓõóª·ªŞª¹¡£
	- Parameters «á«ó«Ğ?ªÇõóÕô«¢?«®«å«á«ó«ÈªòÏ´ªáªŞª¹¡£

	Example
	\code
	CAdoConnection db;
	db.Open(L"Data Source=.;Database=ProudDB-Test;Trusted_Connection=yes");
	CAdoCommand co;
	co.Prepare(db,L"pn_sum");
	co.Parameters[1]=1L;
	co.Parameters[2]=2L;
	co.Execute();
	long x=co.Parameters[3]; 
	\endcode 

	\~
	*/
	class CAdoCommand:public ADODB::_CommandPtr,protected CQueryChecker
	{
	public:
		PROUD_API CAdoCommand(ADODB::_Command *conn);
		PROUD_API CAdoCommand();
	private:
		// º¹»ç ±İÁö. ADODB COM smartptrÀ» ·¡ÇÎÇÏ°í ÀÖÀ¸³ª, Á¤ÀÛ ÀÌ ÇÔ¼öÀÇ dtor¿¡¼­ close¸¦ ÇÏ±â ¶§¹®ÀÓ.
		CAdoCommand& operator=(const CAdoCommand&);
		CAdoCommand(const CAdoCommand&);
	public:

		/**
		\~korean
		stored procedure¸¦ È£ÃâÇÒ ÁØºñ¸¦ ÇÑ´Ù. Áï, ADO Connection, stored procedure name, inout argument ÁØºñ¸¦ ÇÑ´Ù.
		\param connection
		\param storedProcName

		\~english
		This method sets ready to call stored procedure. Meaning, it prepares ADO Connection, stored procedure name and inout argument.
		\param connection
		\param storedProcName

		\~chinese
		ñ×?û¼Ğ£stored procedure¡£?ñ×?ADO Connection, stored procedure name, inout argument¡£
		\param connection
		\param storedProcName

		\~japanese
		stored procedureªòû¼ªÓõóª¹ñŞİáªòª·ªŞª¹¡£?ªÁ¡¢ADO Connection, stored procedure name, inout argument ñŞİáªòª·ªŞª¹¡£
		\param connection
		\param storedProcName
		\~
		*/
		PROUD_API void /*FASTCALL */ Prepare(ADODB::_Connection* connection, const String& storedProcName, ADODB::CommandTypeEnum cmdType = ADODB::adCmdStoredProc);

		/**
		\~korean
		PrepareSP¿¡ ÁöÁ¤µÇ¾ú´ø stored procedure¸¦ ½ÇÇàÇÑ´Ù.
		\param recordsAffected stored procedure¿¡ ÀÇÇØ ¿µÇâ¹ŞÀº recordÀÇ °¹¼ö

		\~english
		Execute the appointed stored procedure at PrepareSP.
		\param recordsAffected Number of records affected by stored procedure

		\~chinese
		?ú¼ù¬PrepareSPò¦ïÒîÜstored procedure¡£
		\param recordsAffected ù¬stored procedureç¯?îÜrecordîÜ??¡£

		\~japanese
		PrepareSPªËò¦ïÒªµªìª¿stored procedureªò?ú¼ª·ªŞª¹¡£
		\param recordsAffected stored procedureªËªèªÃªÆç¯úÂªòáôª±ª¿record?
		\~
		  */
		PROUD_API void /*FASTCALL */ Execute(OUT long *recordsAffected=NULL);

		/**
		\~korean
		PrepareSP¿¡ ÁöÁ¤µÇ¾ú´ø stored procedure¸¦ ½ÇÇàÇÑ´Ù.
		\param outRecordset ¹Ş¾Æ¿Ã °á°ú ·¹ÄÚµå¼Â.
		\param recordsAffected stored procedure¿¡ ÀÇÇØ ¿µÇâ¹ŞÀº recordÀÇ °¹¼ö

		\~english
		Execute the appointed stored procedure at PrepareSP.
		\param outRecordset Recordset of results to get.
		\param recordsAffected Number of records affected by stored procedure

		\~chinese
		?ú¼ù¬PrepareSPò¦ïÒîÜstored procedure¡£
		\param outRecordset ïÈâ¥?ÍıîÜrecordset
		\param recordsAffected ù¬stored procedureç¯?îÜrecord??

		\~japanese
		PrepareSPªËò¦ïÒªµªìª¿stored procedureªò?ú¼ª·ªŞª¹¡£
		\param outRecordsetªòáôª±ö¢ªëÌ¿ÍıªÎ«ì«³?«É«»«Ã«È
		\param recordsAffected stored procedureªËªèªÃªÆç¯úÂªòáôª±ª¿recordªÎ?
		\~
		  */
		PROUD_API void /*FASTCALL */ Execute(OUT CAdoRecordset& outRecordset,OUT long *recordsAffected=NULL);


		/**
		\~korean
		index°¡ °¡¸®Å°´Â ¹øÂ°ÀÇ paramter °ªÀ» ±¸ÇÑ´Ù. PrepareSP¸¦ È£ÃâÇÑ ÈÄ¿¡ »ç¿ëÇÒ ¼ö ÀÖ´Ù.
		\return ¸®ÅÏµÇ´Â parameter °ª.
		\param index ¸î¹øÂ° parameterÀÇ °ªÀ» ±¸ÇÒ °ÍÀÎ°¡?
		0Àº stored procedureÀÇ return value¸¦, ³ª¸ÓÁö parameter´Â 1-based indexÀÌ´Ù.

		\~english
		Get parameter value of nth pointed by index. This can be used after PrepareSP is called.
		\return Returned parameter value.
		\param Which nth of parameter value do you want to get?
		0 is return value of stored procedure and the res of parameters are 1-based index.

		\~chinese
		index á¶ò¦îÜğ¯n?paramter?¡£û¼õóPrepareSPı¨Ê¦ì¤ŞÅéÄ¡£
		\return Ú÷üŞîÜparameter?
		\param index âÍé©Ï´ğ¯??parameterîÜ?£¿
		0ãÀstored procedureîÜreturn value£¬í¥ù»îÜparameterãÀ1-based index¡£

		\~japanese
		\~
		*/
		PROUD_API CVariant /*FASTCALL */ GetParam(int index);

		/**
		\~korean
		index°¡ °¡¸®Å°´Â ¹øÂ°ÀÇ parameter °ªÀ» ¼³Á¤ÇÑ´Ù. PrepareSP¸¦ È£ÃâÇÑ ÈÄ¿¡ »ç¿ëÇÒ ¼ö ÀÖ´Ù.
		\param index ¸î¹øÂ° parameterÀÇ °ªÀ» ¼³Á¤ÇÒ °ÍÀÎ°¡?
		0Àº stored procedureÀÇ return value¸¦, ³ª¸ÓÁö parameter´Â 1-based indexÀÌ´Ù.
		\param value ¼³Á¤ÇÒ paramter °ª

		\~english
		This method sets value of nth parameter pointed by index. It can be used after PrepareSP is called.
		\param index Which nth parameter value do you want to set?
		0 is return value of stored procedure and the res of parameters are 1-based index.
		\param value Setting paramter value

		\~chinese
		?öÇindexá¶ò¦îÜğ¯n?paramter?¡£û¼õó Ğ£PrepareSPı¨Ê¦ì¤ŞÅéÄ¡£
		\param index é©?öÇğ¯??parameterîÜ?£¿
		0ãÀstored procedureîÜreturn value£¬í¥ù»îÜparameterãÀ1-based index¡£
		\param value é©?öÇîÜparameter?

		\~japanese
		indexª¬ò¦ª¹paramterö·ªòÏ´ªáªŞª¹¡£PrepareSPªòû¼ªÓõóª·ª¿ı­ªËŞÅª¦ª³ªÈª¬ªÇª­ªŞª¹¡£
		\return«ê«¿?«óªµªìªëparameterö·
		\param index ù¼ÛãÙÍªÎparameterö·ªòÏ´ªáªŞª¹ª«£¿ 
		0ªÏstored procedureªÎreturn valueªò¡¢?ªêparameterªÏ1-based indexªÇª¹¡£
		\~

		**NOTE** This function is very slow because of executing an additional stored procedure for getting procedure information.
		It is not recommended to use this function. The workaround is to use AppendParameter() instead.
		*/
		PROUD_API void /*FASTCALL */ SetParam(int index,const CVariant &value);
#if defined (_MSC_VER)
		__declspec(property(get=GetParam,put=SetParam)) CVariant Parameters[];
#endif
		/**
		\~korean
		parameter °ªÀ» ºÙÀÎ´Ù.MsSQL¿¡¼­´Â º°·Î »ç¿ëµÉ ÀÏÀÌ ¾øÁö¸¸, MySQL¿¡¼­´Â SetParam´ë½Å ÀÌ ¸Ş¼Òµå¸¦ »ç¿ëÇØ¾ß ÇÑ´Ù.
		\return ¸¸µé¾îÁø _ParameterPtr
		\param paramName È£ÃâÇÒ ÇÁ·Î½ÃÁ®ÀÇ parameterÀÇ ÀÌ¸§
		\param paramType µ¥ÀÌÅÍÀÇ Å¸ÀÔ ADODB::DataTypeEnum ÂüÁ¶.
		\param paramDirection µ¥ÀÌÅÍÀÇ µé¾î°¥ ÇüÅÂ ADODB::ParameterDirectionEnum ÂüÁ¶.(MySQLÀº adParamInput¸¸ ¾²¿©¾ßÇÔ.output Áö¿ø ¾ÈÇÔ)
		\param defaultValue ½ÇÁ¦ ÇÁ·Î½ÃÁ®¿¡ Àü´ŞµÉ °ª

		\~english
		Add parameter value. This is not commonly used in MsSQL, but this method must be used in MySQL instead of SetParam.
		\return Created _ParameterPtr
		\param paramName Name of parameter procedure to call for
		\param paramType Refer to Data Type ADODB::DataTypeEnum
		\param paramDirection Refer to Data insertion direction ADODB::ParameterDirectionEnum.(MySQL must use adParamInput only. Output is not supported.)
		\param defaultValue Value that will be passed to the actual procedure

		\~chinese
		ïÄ?parameter?¡£?æÔî¤MsSQLÜôßÈŞÅéÄ£¬î¤MySQLé©ŞÅéÄó®Û°Ûö?ÓÛôğSetParam¡£
		\return ?ËïîÜ_ParameterPtr
		\param paramName é©û¼Ğ£îÜïïßíparameterîÜÙ£?
		\param paramType ?ÍÅ?Ëß?úşADODB::DataTypeEnum
		\param paramDirection ?Ëß?ìıîÜû¡ãÒ?ÍÅADODB::ParameterDirectionEnum¡££¨MySQL ñşÒö?ìıadParamInput¡£Üôò¨ò¥output£©
		\param defaultValue ????ÓğïïßíîÜ?¡£

		\~japanese
		parameterö·ªòôäªêÜõª±ªŞª¹¡£MsSQLªÇªÏÜ¬ªËŞÅªïªìªëª³ªÈª¬ª¢ªêªŞª»ªóª¬¡¢MySQLªÇªÏSetParamªÎÓÛªïªêªËª³ªÎ«á«½«Ã«ÉªòŞÅªïªÊª±ªìªĞªÊªêªŞª»ªó¡£
		\return íÂªéªìª¿_ParameterPtr
		\param paramName û¼ªÓõóª¹«×«í«·?«¸«ãªÎparameterÙ£
		\param paramType «Ç?«¿ªÎ«¿«¤«× ADODB::DataTypeEnum ?ğÎ
		\param paramDirection «Ç?«¿ªÎìıªëû¡÷¾ ADODB::ParameterDirectionEnum ?ğÎ(MySQLªÏadParamInputªÎªßª¬ŞÅªïªìªëù±é©ª¬ª¢ªêªŞª¹¡£OutputªÏ«µ«İ?«ÈªµªìªŞª»ªó¡£)
		\param defaultValue ?ğ·ªË«×«í«·?«¸«ãªË?ªïªìª¿ö·
		\~
		*/
		PROUD_API ADODB::_ParameterPtr /*FASTCALL */ AppendParameter(const String& paramName, ADODB::DataTypeEnum paramType, ADODB::ParameterDirectionEnum paramDirection, const CVariant &defaultValue);

		/**
		\~korean
		µ¿¸í ¸Ş¼Òµå ÂüÁ¶
		\param defaultValue ½ÇÁ¦ ÇÁ·Î½ÃÁ®¿¡ ½ºÆ®¸µ °ª

		\~english
		Refer to the same method
		\param defaultValue String value of the actual procedure

		\~chinese
		?ÍÅÔÒÙ£Û°Ûö
		\param defaultValue ïïßíîÜ??í®İ¬Íú?

		\~japanese
		ÔÒÙ£«á«½«Ã«É?ğÎ
		\param defaultValue ?ğ·«×«í«·?«¸«ãªË«¹«È«ê«ó«°ö·
		\~
		*/
		PROUD_API ADODB::_ParameterPtr /*FASTCALL */ AppendParameter(const String& paramName, ADODB::DataTypeEnum paramType, ADODB::ParameterDirectionEnum paramDirection, const String& defaultValue);
		PROUD_API ADODB::_ParameterPtr /*FASTCALL */ AppendParameter(ADODB::DataTypeEnum paramType, ADODB::ParameterDirectionEnum paramDirection, const String& defaultValue);

		/**
		\~korean
		µ¿¸í ¸Ş¼Òµå ÂüÁ¶ ´Ù¸¸, ³»ºÎÀûÀ¸·Î _variant_t°¡ µé¾î°¨

		\~english
		Refer to the same method but internally _variant_t will be added

		\~chinese
		?ÍÅÔÒÙ£Û°Ûö¡£Ó£?İ»?ìı_variant_t¡£

		\~japanese
		ÔÒÙ£«á«½«Ã«É?ğÎ¡£Ó£ª·¡¢?İ»îÜªË_variant_tª¬ìıªêªŞª¹¡£
		\~
		*/
		PROUD_API ADODB::_ParameterPtr /*FASTCALL */ AppendParameter(const String& paramName, ADODB::DataTypeEnum paramType, ADODB::ParameterDirectionEnum paramDirection);

		/**
		\~korean
		µ¿¸í ¸Ş¼Òµå ÂüÁ¶
		\param defaultValue ½ÇÁ¦ ÇÁ·Î½ÃÁ®¿¡ ½ºÆ®¸µ °ª
		\param length ½ºÆ®¸µÀÇ ÃÖ´ë ±æÀÌ

		\~english
		Refer to the same method
		\param defaultValue String value of the actual procedure
		\param length The maximum length of string

		\~chinese
		?ÍÅÔÒÙ£Û°Ûö
		\param defaultValue ïïßíîÜ??í®İ¬Íú?
		\param length í®İ¬ÍúîÜõÌÓŞ?Óø

		\~japanese
		ÔÒÙ£«á«½«Ã«É?ğÎ
		\param defaultValue ?ğ·«×«í«·?«¸«ãªË«¹«È«ê«ó«°ö·
		\param length «¹«È«ê«ó«°ªÎõÌÓŞíşªµ
		\~
		*/
		PROUD_API ADODB::_ParameterPtr /*FASTCALL */ AppendParameter(const String& paramName, ADODB::DataTypeEnum paramType, ADODB::ParameterDirectionEnum paramDirection, const String& defaultValue, long length);

		/**
		Convenient function for AppendParameter.
		*/
		ADODB::_ParameterPtr AppendInputParameter(const String& paramName, const Guid& value);

		ADODB::_ParameterPtr AppendReturnValue();

	private:
		void WarnIfParameterHasProblem();
	};

	/**
	\~korean
	ADO RecordÀÇ field ³»¿ë¿¡¼­ º¹»çµÈ »çº» °´Ã¼
	ADO recordÀ» closeÇÏ°í ³ª¼­µµ ±× ³»¿ëÀ» »ç¿ëÇÒ ¶§ À¯¿ëÇÏ´Ù.
	ADO recordsetÀÇ fieldÀÇ »çº»À» Ä«ÇÇÇÏµÇ, ¿øº» recordsetÀ» closeÇØµµ ÀĞ±â ¾ï¼¼½º Á¤µµ´Â
	ÇÒ ¼ö ÀÖ´Â ADO object°¡ Á¸ÀçÇÏ¸é, ±×°ÍÀ» ÀÌ Å¬·¡½º ´ë½ÅÀ¸·Î ½áµµ µÇ°ÚÁö¸¸, ¼º´ÉÀÌ º¸ÀåµÈ
	±×·¯ÇÑ °ÍÀÌ ¾øÀ¸¹Ç·Î ÀÌ Å¬·¡½º¸¦ ´ë½Å ¸¸µé¾ú´Ù.
	MSSQL serverÀÇ Æ¯¼º»ó, field nameÀº case insensitiveÀÌ´Ù.

	\~english
	ven after closing ADO Record, its copy ADO Record is useful
	when using the field contetns contained within.
	If there is ADO object containing copied contents of recordset
	that can be read even after its source recordset is closed,
	you may use that method but since its performance is not guaranteed,
	the below class has been made.
	Due to the characterics of MSSQL server, field name must be case insensitive.

	\~chinese
	î¤ADO RecordîÜfield?é»×ì?ğ¤îÜÜùÜâ?ßÚ
	??ADO Recordì¤ı¨?Ê¦ì¤êóéÄîÜŞÅéÄÑá??é»¡£
	÷ê ?æÔADO RecordîÜÜùÜâ?ìÔ£¬Ó£ãÀ??ê«Üârecordsetå¥Ê¦?ADDobjectğíî¤ïïßíîÜ?£¬
	ÒöÓÛôğŞÅéÄó®?£¬?êóÜÁî¡àõÒöîÜó®??à¤£¬ì×ó®ğ¤íÂÖõ???¡£
	MSSQL server îÜ÷åàõß¾£¬field name ãÀcase insensitive¡£

	\~japanese
	ADO RecordªÎfield?é»ªèªê«³«Ô?ªµªìª¿«³«Ô?«ª«Ö«¸«§«¯«È
	ADO recordªòcloseª·ªÆª«ªéªâª½ªÎ?é»ªòŞÅª¦ãÁªËêóéÄªÇª¹¡£
	ADO recordsetªÎfieldªÎ«³«Ô?ªò«³«Ô?ª·ªŞª¹ª¬¡¢ê«Üârecordsetªòcloseª·ªÆªâ?ªßö¢ªê«¢«¯«»«¹ªÛªÉªÏªÇª­ªëADO objectª¬ğíî¤ª¹ªìªĞ¡¢ª½ªìªòª³ªÎ«¯«é«¹ªÎÓÛªïªêªËŞÅªÃªÆªâÕŞª¤ªÇª¹ª¬¡¢àõÒöªÎÜÁ?ªµªìª¿ªâªÎª¬ªÊª¤ªÎªÇ¡¢ª³ªÎ«¯«é«¹ªòÓÛªïªêªËíÂªêªŞª·ª¿¡£
	MSSQL serverªÎ÷åàõª«ªé¡¢field nameªÏcase insensitiveªÇª¹¡£
	\~
	  */
	class CAdoOfflineRecord:public CProperty
	{
	public:
		/**
		\~korean
		¿øº» recordset°¡ °¡¸®Å°´Â cursor¿¡¼­ 1°³ÀÇ record¸¦ º¹»çÇÑ´Ù.
		¿øº» recordsetÀÇ cursor¿¡´Â ¿µÇâÀ» ³¢Ä¡Áö ¾Ê´Â´Ù.
		\param src  ¿øº» recordset

		\~english
		Copy one record of the source recordset pointed by cursor.
		This does not cursor of the source recordset.
		\param src  Source recordset

		\~chinese
		ê«Üârecordsetá¶ò¦îÜcursorß¾?ğ¤ìé?record¡£
		Üô?ê«ÜârecordsetîÜcursorã¿Ê¥ç¯?¡£
		\param src ê«Üârecordset

		\~japanese
		ê«Üârecordsetª¬ò¦ª¹cursorªÇ1ËÁªÎrecordªò«³«Ô?ª·ªŞª¹¡£
		ê«ÜârecordsetªÎcursorªËªÏç¯úÂªòĞàªÜª·ªŞª»ªó¡£
		\param src ê«Üâ recordset
		\~
		*/
		PROUD_API void CopyFrom(CAdoRecordset &src);

		inline CAdoOfflineRecord()
		{
		}

		inline CAdoOfflineRecord& operator=(CAdoRecordset& source)
		{
			CopyFrom(source);
			return *this;
		}
		inline CAdoOfflineRecord(CAdoRecordset& source)
		{
			CopyFrom(source);
		}
	};

	/**
	\~korean
	CAdoRecordsetÀº DBMS¿ÍÀÇ ¿¬°áÀ» À¯ÁöÇÑ Ã¤·Î ·¹ÄÚµå¸¦ Á¢±ÙÇÏ´Âµ¥, ÀÌ¿Í ´Ş¸® CAdoOfflineRecordsetÀº
	DBMS¿ÍÀÇ ¿¬°áÀÌ ¾ø´Â Ã¤·Î ·¹ÄÚµå¸¦ Á¢±ÙÇÏ°Ô ÇØÁİ´Ï´Ù.
	ÀÌ¸¦ À§ÇØ CAdoRecordsetÀ¸·ÎºÎÅÍ IterateAndCopyFrom ¶Ç´Â IterateAndAppendFrom¸¦ ÅëÇØ ·¹ÄÚµå ³»¿ëÀÇ »çº»À»
	ÀÌ °´Ã¼·Î ÀúÀåÇÒ ¼ö ÀÖ½À´Ï´Ù.

	ÀÌ °´Ã¼¸¦ È°¿ëÇÏ¸é, ¿¹¸¦ µé¾î, DBMS¿ÍÀÇ ¿¬°á À¯Áö½Ã°£À» ÃÖ¼ÒÈ­ÇÏ´Â DBMS Á¢±Ù¹ıÀ» °¡´ÉÇÏ°Ô ÇØÁİ´Ï´Ù.

	ÀÌ °´Ã¼´Â CAdoOfflineRecordÀÇ ¹è¿­ °´Ã¼ÀÔ´Ï´Ù.

	ÁÖÀÇ: ToVariant(), ToLongLong() ¼³¸í Âü°í. Windows 2000 ÀÌÇÏ °ü·Ã ¹®Á¦ÀÌ´Ù.

	\~english
	CAdoRecordset accesses record as maintaining the connection with DBMS
	while CAdoOfflineRecordset can do so without being connected DBMS.
	In order for this, you can save the copy of record through or
	IterateAndAppendFrom from CAdoRecordset as an object.
	This object can help minimizing the connection duration time of DBMS as accessing DBMS.

	This object is an array object of CAdoOfflineRecord.

	CAUTION: Refer to ToVariant(), ToLongLong(). This issue could arise in OS below than Windows 2000.

	\~chinese
	CAdoRecordset ãÀ?ò¥?DBMSîÜ?ïÈîÜï×?ù»ïÈĞÎrecord£¬?ó®ÜôÔÒîÜ CAdoOfflineRecordset%ãÀ?êó?DBMSîÜ?ïÈîÜï×?ù»ïÈĞÎrecord¡£
	?Öõ??? CAdoRecordset%ÓğIterateAndCopyFromûäíº÷×?IterateAndAppendFrom÷êrecord?é»îÜ?Ëìğí?Óğó®?ßÚ¡£
	××éÄó®?ßÚîÜ?£¬ÖÇåı£¬õÌá³ûù?DBMSîÜ?ïÈêÈöÇ??îÜDBMSïÈĞÎÛö??Ê¦Òö¡£
	ó®?ßÚãÀ CAdoOfflineRecord%îÜÛÉÖª?ßÚ¡£
	ñ¼ëò£º?ÍÅToVariant(), ToLongLong()?Ù¥¡£ãÀWindows 2000ì¤ù»ßÓ???¡£

	\~japanese
	CAdoOfflineRecordsetªÏDBMSªÈªÎÖ§Ì¿ª¬ªÊª¤?÷¾ªÇ«ì«³?«Éªò«¢«¯«»«¹ªÇª­ªëªèª¦ªËª·ªŞª¹¡£
	ª³ªÎª¿ªáªË¡¢CAdoRecordsetª«ªéIterateAndCopyFromªŞª¿ªÏIterateAndAppendFromªò÷×ª¸¡¢«ì«³?«É?é»ªÎ«³«Ô?ªòª³ªÎ«ª«Ö«¸«§«¯«ÈªËÜÁğíª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
	ª³ªÎ«ª«Ö«¸«§«¯«ÈªòüÀéÄª¹ªëªÈ¡¢ÖÇª¨ªĞ¡¢DBMSªÈªÎÖ§Ì¿ë«ò¥ãÁÊàªòõÌá³ûùª¹ªëDBMS«¢«¯«»«¹Û°ÛöªòÊ¦ÒöªËª·ªŞª¹¡£
	ª³ªÎ«ª«Ö«¸«§«¯«ÈªÏCAdoOfflineRecordªÎÛÕÖª«ª«Ö«¸«§«¯«ÈªÇª¹¡£
	ª´ñ¼ëò£ºToVariant(), ToLongLong()ªÎ?Ù¥ªòª´?ğÎª¯ªÀªµª¤¡£Windows 2000ì¤ù»ªÇªÎ?Ö§Ùığ¹ªÇª¹¡£
	\~
	*/
	class CAdoOfflineRecordset:public CFastArray<CAdoOfflineRecord>
	{
	public:

		/**
		\~korean
		sourceÀÇ ¸ğµç ·¹ÄÚµå¸¦ º¹»çÇØ¿É´Ï´Ù.
		º¹»ç°¡ ³¡³ª¸é sourceÀÇ cursor´Â EOF°¡ µË´Ï´Ù.
		\param source  ¿øº» recordset

		\~english
		This method copies all records of source.
		When copying is done, cursor of source becomes EOF.
		\param source  Source recordset

		\~chinese
		?ğ¤sourceîÜá¶êórecord¡£
		?ğ¤?áÖîÜ?sourceîÜcursor??à÷EOF¡£
		\param source ê«Üârecordset

		\~japanese
		sourceªÎîïªÆªÎ«ì«³?«Éªò«³«Ô?ª·ªÆª­ªŞª¹¡£
		«³«Ô?ª¬ğûªïªÃª¿ªé¡¢sourceªÎcursorªÏEOFªËªÊªêªŞª¹¡£
		\param source  ê«Üâ recordset
		
		\~
		*/
		PROUD_API void IterateAndCopyFrom(CAdoRecordset &source);

		/**
		\~korean
		sourceÀÇ ¸ğµç ·¹ÄÚµå¸¦ ÀÌ °´Ã¼ÀÇ ±âÁ¸ ·¹ÄÚµåµéÀÇ ¸¶Áö¸·¿¡ Ãß°¡ÇÕ´Ï´Ù.
		º¹»ç°¡ ³¡³ª¸é sourceÀÇ cursor´Â EOF°¡ µË´Ï´Ù.
		\param source  ¿øº» recordset

		\~english
		Add all records of source to the last line of existing records within this object.
		When copying is done, cursor of source becomes EOF.
		\param source  Source recordset

		\~chinese
		÷êsourceîÜá¶êórecordôÕÊ¥Óğó®?ßÚîÜê«êórecordîÜõÌı¨¡£
		?ğ¤?áÖîÜ?sourceîÜcursor??à÷EOF¡£

		\~japanese
		sourceªÎîïªÆªÎ«ì«³?«Éªòª³ªÎ«ª«Ö«¸«§«¯«ÈªÎ?ğí«ì«³?«ÉªÎõÌı­ªËõÚÊ¥ª·ªŞª¹¡£
		«³«Ô?ª¬ğûªïªÃª¿ªésourceªÎcursorªÏEOFªËªÊªêªŞª¹¡£
		\param source  ê«Üâ recordset
		\~
		*/
		PROUD_API void IterateAndAppendFrom(CAdoRecordset &source);
	};

	// Disconnected Recordset - Sample Source //
	// ¿¬°á ÇØÁ¦µÈ ·¹ÄÚµå¼Â - »ùÇÃ ¼Ò½º //
	/*
	try
	{
	ADODB::_RecordsetPtr spRS(__uuidof(ADODB::Recordset));
	ADODB::_ConnectionPtr spConn(__uuidof(ADODB::Connection));

	// Connect and get recordset.
	spConn->Open(OLESTR("dsn=SQLServer"),OLESTR("sa"),
	OLESTR(""), -1);

	spRS->CursorLocation = ADODB::adUseClient;
	spRS->Open(OLESTR("select * from Table1"),
	spConn.GetInterfacePtr(),
	ADODB::adOpenForwardOnly, ADODB::adLockBatchOptimistic, -1);

	// Disassociate the connection from the recordset.
	spRS->PutRefActiveConnection(NULL);

	// Change the value.
	spRS->Fields->Item[0L]->Value = OLESTR("NewValue");

	// Re-connect.
	spRS->PutRefActiveConnection(spConn);

	// Send updates.
	spRS->UpdateBatch(ADODB::adAffectAll);

	spRS->Close();
	spConn->Close();

	}
	catch( _com_error e)
	{
	// Do Exception handling.
	}
	*/

	struct ExecuteSQLAsyncParam
	{
		String connectionString,stmt;
	};

	/**
	\~korean
	src¹®ÀÚ¿­ ³»ÀÇ "'"¹®ÀÚ´Â ¿ÀÀÛµ¿À» À¯¹ßÇÒ ¼ö ÀÖ±â ¶§¹®¿¡ "''"·Î ¹Ù²Ù¾î Áİ´Ï´Ù.

	\~english TODO:translate needed.

	\~chinese
	Src í®İ¬Íú?îÜ"'"Ùşí®Ê¦Òö??öÈÍºî¡£¬ËÇ?"''"¡£

	\~japanese
	srcÙşí®Öª?ªÎ"'"Ùşí®ªÏ¡¢è¦íÂÔÑªòìÚª­ÑÃª³ª¹Ê¦Òöàõª¬ª¢ªëª¿ªá¡¢"''"ªËìÚª­üµª¨ªŞª¹¡£
	\~
	*/
	PROUD_API String gds(const PNTCHAR *src);

	PROUD_API void RecommendNoCriticalSectionLock();

	/**
	\~korean
	ÀÌ °´Ã¼¸¦ ·ÎÄÃ º¯¼ö·Î °®°í ÀÖ´Â »óÅÂÀÇ ½º·¹µå´Â DB¸¦ ¾ï¼¼½ºÇÏ´Â Áß¿¡ critical sectionÀÌ lockµÇ¾î ÀÖ´Ù ÇÏ´õ¶óµµ °æ°í Ç¥½Ã¸¦
	¹«½ÃÇÏ°Ô ÇÑ´Ù. ºÒ°¡ÇÇÇÏÁö¸¸ ºóµµ°¡ ¸Å¿ì ³·Àº DB º´¸ñÀ» ¹«½ÃÇÏ±â À§ÇØ¼­ ÀÌ Å¬·¡½º¸¦ ¾µ ¼ö ÀÖ´Ù.

	ÁÖÀÇ:
	- ÀÌ°É ³²¿ëÇÏÁö ¸»°Í. DB º´¸ñÀ» ¹«½ÃÇÏ´Â°ÍÀÌ´Ï¸¸Å­ ¼­¹ö ÃÖÀûÈ­ °úÁ¤¿¡¼­ ÀÌ°Í ¶§¹®¿¡ Á¤ÀÛ Áß¿äÇÑ º´¸ñÀ» ¸ø Ã£À» ¼ö ÀÖ´Ù.
	- ·ÎÄÃ º¯¼ö·Î¸¸ ÀÌ °´Ã¼¸¦ »ı¼ºÇÒ ¼ö ÀÖ´Ù.

	\~english
	Thread holding this object as a loval variable ignores warning notice even though critical section is locked as accessing DB.
	This class can be used to ignore DB bottleneck that is inevitable but low in frequency of use.

	CAUTION:
	- DO NOT USE THIS TOO MUCH. Setting to ignore DB bottleneck can cause serious issues such as skipping important DB bottleneck in the process of server optimization.
	- This object can be created only by local variable.

	\~chinese
	÷êó®?ßÚ?êó?Üâò¢????îÜ?ïïñé?ïÈDBîÜ?ı¦?Î·critical sectionù¬lock£¬å¥?Ùé?ÌíÍ±?ò¤¡£?æÔÜôÊ¦ù­Øó£¬?ÖõÙé??áã?î¸îÜDB??£¬Ê¦ì¤ŞÅéÄó®?¡£
	ñ¼ëò£º
	- ÜôéÄ?éÄó®?¡£ì×?ãÀÙé?DB??£¬î¤Ü×?Ğï?ûù?ïïñéÊ¦Òöì×????ÜôÓğñìé©îÜ??¡£
	- ŞÅéÄÜâò¢??ö¦Ê¦ì¤ßæà÷ó®?ßÚ¡£

	\~japanese
	ª³ªÎ«ª«Ö«¸«§«¯«Èªò«í?«««ë??ªÇò¥ªÃªÆª¤ªë?÷¾ªÎ«¹«ì«Ã«ÉªÏ¡¢DBªò«¢«¯«»«¹ª¹ªëÊàªËcritical sectionª¬«í«Ã«¯ªµªìªÆª¤ªëªÈª·ªÆªâÌíÍ±øúãÆªòÙíãÊª¹ªëªèª¦ªËªÊªêªŞª¹¡£ªäªàªòÔğªºªËŞºÓøªÎªÈªÆªâî¸ª¤DBªÎ«Ü«Ã«È«ë«Í«Ã«¯ªòÙíãÊª¹ªëª¿ªáªËª³ªÎ«¯«é«¹ªòŞÅª¦ª³ªÈª¬ªÇª­ªŞª¹¡£
	ª´ñ¼ëò£º
	- ª³ªìªòÕ½éÄª·ªÊª¤ª³ªÈ¡£DB«Ü«Ã«È«ë«Í«Ã«ÈªòÙíãÊª¹ªëª³ªÈªÊªÎªÇ¡¢«µ?«Ğ?ªÎõÌîêûùÎ¦ïïªÇªÏª³ªìª¬ê«ì×ªËªÊªÃªÆñìé©ªÊ«Ü«Ã«È«ë«Í«Ã«ÈªòÌ¸ªÄª±ªéªìªÊª¤íŞùêª¬ª¢ªêªŞª¹¡£
	- «í?«««ë??ªÎªßªÇª³ªÎ«ª«Ö«¸«§«¯«Èªòßæà÷ª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
	\~
	   */
	class CAdoDBTemporaryBottleneckCheckDisabler
	{
	public:
		PROUD_API CAdoDBTemporaryBottleneckCheckDisabler();
		PROUD_API ~CAdoDBTemporaryBottleneckCheckDisabler();
	};

	/**
	\~korean
	ProudDB ½ÇÇàÁß ¹ß»ıµÇ´Â ¿¡·¯ °´Ã¼
	- ¹®Á¦ ¹ß»ı ½Ã ILogWriterDelegate::OnLogWriterExceptionÇÔ¼ö¸¦ ÅëÇÏ¿© CallBack¹ŞÀ¸½Ç ¼ö ÀÖ½À´Ï´Ù.
	- AdoException::what()ÇÔ¼ö¸¦ ÅëÇÏ¿© ¹ß»ıµÈ ³»¿ëÀÇ StringÀ» ¾òÀ¸½Ç ¼ö ÀÖ½À´Ï´Ù.

	\~english TODO:translate needed.
	Error object that could occur as running ProudDB
	-When a problem occurs, you can get it called back using ILogWriterDelegate::OnLogWriterException function
	-Through - AdoException::what() function, you can get the string of what has occurred. 

	\~chinese
	ProudDB ?ú¼??ßæîÜ???ßÚ
	- ???ßæ?÷×?ILogWriterDelegate::OnLogWriterException ùŞ?ÔğÓğCallBack¡£
	- ÷×? AdoException::what()%ùŞ?Ê¦ì¤ÔğÓğ?ßæ?é»îÜString¡£

	\~japanese
	ProudDB ?ú¼ñéªË?ßæª¹ªë«¨«é?«ª«Ö«¸«§«¯«È
	- Ùığ¹ª¬?ßæãÁ¡¢ILogWriterDelegate::OnLogWriterException??ªò÷×ª¸«³?«ë«Ğ«Ã«¯ªòáôª±ªéªìªŞª¹¡£
	- AdoException::what()??ªò÷×ª¸?ßæª·ª¿?é»ªÎStringªòÔğªëª³ªÈª¬ªÇª­ªŞª¹¡£
	
	\~
	  */
	class AdoException:public Exception
	{
	public:
		/**
		\~korean
		ProudDB´Â ADO¸¦ ¾²°í ÀÖ´Ù. ProudDB°¡ ¾²´Â ADO´Â _com_error¸¦ ¿¹¿Ü·Î ´øÁö´Âµ¥
		±×°ÍÀÌ ¿©±â¿¡ ´ã±ä´Ù.

		\~english
		ProudDB uses ADO. ADO of ProudDB throws _com_error as exception
		which gets stored in here.

		\~chinese
		ProudDB éÄADO¡£ ProudDB ŞÅéÄîÜADOÖÇèâò¢øØ_com_error£¬Ñá?????×ì¡£

		\~japanese
		ProudDBªÏADOªòŞÅªÃªÆª¤ªŞª¹¡£ProudDBª¬ŞÅª¦ADOªÏ_com_errorªòÖÇèâªÈª·ªÆáêªêªŞª¹ª¬¡¢ª½ªìª¬ª³ª³ªËìıªêªŞª¹¡£
		\~
		  */
		_com_error m_comError;

		PROUD_API AdoException(const PNTCHAR *txt, _com_error &e);
	};





	/**  @}  */


}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif //_WIN32
