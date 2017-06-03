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

#if defined _WIN32 || defined _WIN64
#include <winbase.h>
#endif
#include "ProcHeap.h"
#include "Singleton.h"
#include "Event.h"
#include "PnThread.h"
#include "sysutil.h"
#include "BasicTypes.h"
#include "SysTime.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/*	ÀÌ ÇÔ¼öµéÀº Windows Vista ÀÌÈÄ¿¡³ª ¾µ ¼ö ÀÖÀ½. µû¶ó¼­ ¸·À½.

	// º¯¼ö ÇÏ³ª °®°í critical sectionÀ¸·Î º¸È£µÇ´Â read/write´Â ¿À¹ö¾×¼Ç.
	// 32bit OS¿¡¼­ 64bit °ªÀ» volatile keyword¿¡¸¸ ÀÇÁ¸ÇØ¼­ i/oÇÏ´Â °ÍÀº non-atomic. Áï tearingÀÇ À§ÇèÀÌ ÀÖÀ½.
	// ÀÌ¸¦ ¿¹¹æÇÏ°íÀÚ ÀÌ ÇÔ¼öµéÀÌ ÀÖÀ½
	// ÀÎÀÚ °ªÀº, align(8)ÀÌ µÇ¾î ÀÖ¾î¾ß ÇÔ
	inline double InterlockedRead(volatile double* src)
	{
	LONGLONG *src2 = (LONGLONG*)src;
	LONGLONG ret0 = InterlockedOr64(&src2, 0);
	double* pRet = (double*)&ret0; // raw data cast
	return *pRet;
	}

	inline void InterlockedWrite(volatile double* dest, double newValue)
	{
	LONGLONG* dest2 = (LONGLONG*)dest;
	LONGLONG* pNewValue2 = (LONGLONG*)&newValue; // raw cast
	InterlockedExchange64(&dest2, *pNewValue);
	}*/

	/** \addtogroup util_group
	*  @{
	*/

	/**
	\~korean
	CTimerQueue::NewTimer ¸¦ »ç¿ë½Ã ³Ñ°ÜÁÖ´Â ÆÄ¶ó¸ŞÅÍ ÀÔ´Ï´Ù.

	\~english
	Parameter that pass CTimerQueue::NewTimer when it needs

	\~chinese
	ŞÅéÄ CTimerQueue::NewTimer%??ÎßîÜ??¡£

	\~japanese
	CTimerQueue::NewTimer ªòŞÅéÄãÁªËìÚª­Ô¤ª¹«Ñ«é«á?«¿?ªÇª¹¡£
	\~
	*/
#if defined(_WIN32)
	struct NewTimerParam {
		/**
		\~korean
		¸Å ½Ã°£¸¶´Ù Äİ¹é µÇ¾îÁú ÇÔ¼ö¸¦ ¼³Á¤ÇÕ´Ï´Ù.

		\~english
		Set function that will callback every hours

		\~chinese
		?öÇØßÓ«??ù¬üŞ?îÜùŞ?¡£

		\~japanese
		?ãÁÊàª´ªÈªË«³?«ë«Ğ«Ã«¯ªµªìªë??ªòàâïÒª·ªŞª¹¡£
		\~
		*/
		WaitOrTimerCallbackProc m_callback;

		/**
		\~korean
		Callback µÇ¾îÁö´Â Æ÷ÀÎÅÍ°ªÀ» ÁöÁ¤ÇÕ´Ï´Ù.

		\~english
		Designate pointer value that can callback

		\~chinese
		ò¦ïÒcallbackîÜò¦??¡£

		\~japanese
		«³?«ë«Ğ«Ã«¯ªµªìªë«İ«¤«ó«¿?ö·ªòò¦ïÒª·ªŞª¹¡£
		\~
		*/
		void *m_pCtx;

		/**
		\~korean
		¸Å¹ø Callback µÇ¾îÁö´Â ½Ã°£À» ÀÔ·ÂÇÕ´Ï´Ù.

		\~english
		Enter the time to callback

		\~chinese
		?ìıØßó­callbackîÜ??¡£

		\~japanese
		?üŞ«³?«ë«Ğ«Ã«¯ªµªìªëãÁÊàªòìıÕôª·ªŞª¹¡£
		\~
		*/
		uint32_t m_period;

		/**
		\~korean
		DueTime À¸·Î ÁöÁ¤µÈ ½Ã°£ ÀÌÈÄ ºÎÅÍ Callback ÀÌ ½ÃÀÛµË´Ï´Ù.

		\~english
		Callback will start time which is set by Duetime

		\~chinese
		?ò¦ïÒ?DueTime??ì¤ı¨?ã·?ú¼callback¡£

		\~japanese
		DueTimeªÇò¦ïÒªµªìª¿ãÁÊàì¤Ë½ª«ªéCallbackª¬ËÒã·ªµªìªŞª¹¡£
		\~
		*/
		uint32_t m_DueTime;

		NewTimerParam() : m_callback(0), m_pCtx(0), m_period(0), m_DueTime(0) {}
		NewTimerParam(WaitOrTimerCallbackProc callback, void *pCtx, uint32_t period, uint32_t DueTime);
	};

	class CTimerQueueTimer;

	/**
	\~korean
	½º·¹µå¿¡ ÀÌ¸§À» ÁöÁ¤ÇÑ´Ù. ÀÌ·¸°Ô ÇÏ¸é µğ¹ö°Å ½º·¹µå ºä¿¡¼­ °¢ ½º·¹µå¿¡ ÀÌ¸§ÀÌ Ç¥½ÃµÈ´Ù.
	- µğ¹ö±ëÀÌ ÆíÇØÁú °ÍÀÌ´Ù.
	- º¸´Ù ÀÚ¼¼ÇÑ ³»¿ëÀº
	ms-help://MS.VSCC.2003/MS.MSDNQTR.2003APR.1033/vsdebug/html/vxtskSettingThreadName.htm Âü°í

	\~english
	Designates a name to thread. By doing so, each thread will have their names shown at debugger thread view.
	- Debugging will be easier.
	- Please refer
	ms-help://MS.VSCC.2003/MS.MSDNQTR.2003APR.1033/vsdebug/html/vxtskSettingThreadName.htm

	\~chinese
	??ïïò¦ïÒÙ£í®¡£??îÜ?î¤???ïïview×ì??ãÆØß??ïïîÜÙ£í®¡£
	- ???ÌÚÊ¥Û°øµ¡£
	- ???é»??ÍÅ
	ms-help://MS.VSCC.2003/MS.MSDNQTR.2003APR.1033/vsdebug/html/vxtskSettingThreadName.htm ¡£

	\~japanese
	«¹«ì«Ã«ÉªËÙ£îñªòò¦ïÒª·ªŞª¹¡£ª³ªÎªèª¦ªËª¹ªëªÈ¡¢«Ç«Ğ«Ã«¬?«¹«ì«Ã«É«Ó«å?ªÇÊÀ«¹«ì«Ã«ÉªËÙ£îñª¬øúãÆªµªìªŞª¹¡£
	- «Ç«Ğ«Ã«®«ó«°ª¬é»æ¶ª¯ªÊªêªŞª¹¡£
	- ªèªêßÙª·ª¯ªÏ¡¢
	ms-help://MS.VSCC.2003/MS.MSDNQTR.2003APR.1033/vsdebug/html/vxtskSettingThreadName.htm ªòª´?ğÎª¯ªÀªµª¤¡£

	\~
	*/
	PROUD_API void SetThreadName(uint32_t dwThreadID, const char* szThreadName);

	/**
	\~korean
	ÀÌ ½º·¹µåÀÇ ½ÇÁ¦ ÇÚµéÀ» ±¸ÇÑ´Ù.

	\~english
	Gets the real handle of this thread

	\~chinese
	Ï´ó®?ïïîÜ??handle¡£

	\~japanese
	ª³ªÎ«¹«ì«Ã«ÉªÎ?ğ·«Ï«ó«ÉªòÏ´ªáªŞª¹¡£
	\~
	*/
	PROUD_API HANDLE GetCurrentRealThread();

	/**
	\~korean
	¿î¿µÃ¼Á¦¿¡¼­ Á¦°øÇÏ´Â Thread Pool¿¡¼­ ÀÏÁ¤ ½Ã°£¸¶´ÙÀÇ tick event¸¦ ½ÇÇàÇÒ ¼ö ÀÖ°Ô ÇÏ´Â
	½Ì±ÛÅæ Å¬·¡½ºÀÌ´Ù.
	- CTimerQueueTimer ¿Í È¥¿ëµÈ´Ù.
	- ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#timer_queue" >Timer Queue (Thread pool¿¡¼­ tick event¸¦ ¼öÇàÇÏ´Â ¸ğµâ)</a> ¸¦ Âü°í¹Ù¶÷
	- Windows 98 ÀÌÇÏ ¹öÀü¿¡¼­´Â ¾µ ¼ö ¾ø´Ù.

	\~english
	Singleton class that can execute periodic tick event at thread pool provided by OS
	- Regarded as CTimerQueueTimer
	- Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#timer_queue" >Timer Queue (A module that operates tick event from thread pool)</a>
	- Cannot be used Windows 98 or older version

	\~chinese
	??ú¼?Í§ğ«ÍêîÜThread Pool×ìØßìéïÒ??Òö?ú¼tick eventîÜsingleton?¡£
	- ? CTimerQueueTimer%ûèéÄ¡£
	- ??îÜ??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#timer_queue" >Timer Queue (î¤Thread poolñé?ú¼tick eventîÜÙ¼?)</a>%¡£
	- î¤Windows 98÷úÜâì¤ù»ÜôÒöŞÅéÄ¡£

	\~japanese
	OSª¬ğ«Íêª¹ªëThreadPoolªÇá¶ïÒãÁÊàª´ªÈªÎtick eventªò?ú¼ªÇª­ªëªèª¦ªËª¹ªë«·«ó«°«ë«È«ó«¯«é«¹ªÇª¹¡£
	- CTimerQueueTimer ªÈûèéÄªµªìªŞª¹¡£
	- ßÙª·ª¯ªÏ¡¢\ref timer_queueªòª´?ğÎª¯ªÀªµª¤¡£
	- Windows 98 ì¤ù»ªÎ«Ğ?«¸«ç«óªÇªÏŞÅª¨ªŞª»ªó¡£
	\~
	*/
	class CTimerQueue : public CSingleton<CTimerQueue>
	{
		friend CTimerQueueTimer;
		HANDLE m_timerQueue;
		Event m_endEvent;

	public:
		CTimerQueue();
		~CTimerQueue();

		/**
		\~korean
		ÀÏÁ¤ ½Ã°£¸¶´Ù À¯Àú ÇÔ¼öÀÇ È£ÃâÀ» µî·ÏÇÑ´Ù.
		- À¯Àú ÇÔ¼ö È£ÃâÀ» µî·ÏÇÏ¸é CTimerQueueTimer °´Ã¼°¡ ¸®ÅÏµÈ´Ù.
		- À¯Àú ÇÔ¼ö È£ÃâÀº CTimerQueue ½Ì±ÛÅæ¿¡ ¿©·µÀ» Áßº¹ÇØ¼­ µî·ÏÇØµµ µÈ´Ù.

		\param callback ÀÏÁ¤ ½Ã°£¸¶´Ù È£ÃâµÉ À¯Àú ÇÔ¼ö
		\param ctx callback¿¡ Àü´ŞµÉ À¯Àú ÆÄ¶ó¸ŞÅÍ
		\param period À¯Àú ÇÔ¼ö°¡ È£ÃâµÉ ÁÖ±â(¹Ğ¸®ÃÊ)

		\~english
		Periodically registeres user function calling
		- Once registered then CTimerQueueTimer object is returned.
		- Calling user function can be repeatedly registered at CTimerQueue singleton.

		\param callback User function to be called periodically
		\param ctx user parameter to be delivered to callback
		\param period the period that user function to be called in millisecond

		\~chinese
		ØßìéïÒ??Ôô?éÄ?ùŞ?îÜû¼Ğ£¡£
		- Ôô?éÄ?ùŞ?û¼Ğ£îÜ?Ú÷üŞ CTimerQueueTimer%?ßÚ¡£
		- éÄ?ùŞ?îÜû¼Ğ£Ê¦ì¤î¤ CTimerQueue singletonñì???ı¨Ôô?¡£

		\param callback ØßìéïÒ??é©û¼Ğ£îÜéÄ?ùŞ?¡£
		\param ctx ???callbackîÜéÄ???¡£
		\param period é©û¼Ğ£éÄ?ùŞ?îÜñ²Ñ¢£¨ûÆõ©£©¡£

		\~japanese
		á¶ïÒãÁÊàª´ªÈªÎ«æ?«¶???ªÎû¼ªÓõóª·ªòÔô?ª·ªŞª¹¡£
		- «æ?«¶???ªÎû¼ªÓõóª·ªòÔô?ª¹ªëªÈ CTimerQueueTimer «ª«Ö«¸«§«¯«Èª¬«ê«¿?«óªµªìªŞª¹¡£
		- «æ?«¶???ªÎû¼ªÓõóª·ªÏCTimerQueue «·«ó«°«ë«È«óªËÜÜ?ªòñìÜÜª·ªÆÔô?ª·ªÆªâÕŞª¤ªÇª¹¡£

		\param callback á¶ïÒãÁÊàª´ªÈªËû¼ªÓõóªµªìªë«æ?«¶???
		\param ctx callbackªË?ªïªìªë«æ?«¶?«Ñ«é«á?«¿?
		\param period «æ?«¶???ª¬û¼ªÓõóªµªìªëñ²Ñ¢£¨«ß«êõ©£©
		\~
		*/
		PROUD_API CTimerQueueTimer* NewTimer(NewTimerParam& Param);
	};

	/**
	\~korean
	ÀÏÁ¤ ½Ã°£¸¶´Ù ½º·¹µå Ç®¿¡¼­ ÁÖ¾îÁø ÇÔ¼ö¸¦ È£ÃâÇÏ´Â Å¸ÀÌ¸Ó °´Ã¼
	- ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#timer_queue" >Timer Queue (Thread pool¿¡¼­ tick event¸¦ ¼öÇàÇÏ´Â ¸ğµâ)</a> ¸¦ Âü°í¹Ù¶÷
	- CTimerQueue.NewTimer ¿¡ ÀÇÇØ¼­ ¸®ÅÏµÇ´Â °´Ã¼ÀÇ Å¸ÀÔÀÌ´Ù. ÀÌ °´Ã¼¸¦ ÆÄ±«ÇÏ±â Àü±îÁö CTimerQueue.NewTimer ¿¡ ÀÇÇØ
	µî·ÏµÈ ÇÔ¼ö°¡ ÀÏÁ¤ ½Ã°£¸¶´Ù ½º·¹µå Ç®¿¡¼­ ½ÇÇàµÈ´Ù.
	- ¼­¹ö ¿ëµµ·Î ¾²´Â °ÍÀ» ±ÇÀåÇÑ´Ù. Windows 98 ÀÌÇÏ ¹öÀü¿¡¼­´Â ¾µ ¼ö ¾ø´Ù.

	\~english
	Timer object that periodicaly calls the functions provided by thread pool
	- Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#timer_queue" >Timer Queue (A module that operates tick event from thread pool)</a>.
	- Type of object that is returned by CTimerQueue.NewTimer. Until this object is destructed, the function registered by CTimerQueue.NewTimer is executed periodically in thread pool.
	- Recommended to use for server. Cannot be used for Windows 98 or older version.

	\~chinese
	ØßìéïÒ??ú°??ïï?û¼Ğ£á¶ğ«ÍêùŞ?îÜtimer?ßÚ¡£
	- ????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#timer_queue" >Timer Queue (î¤Thread poolñé?ú¼tick eventîÜÙ¼?)</a>%¡£
	- ù¬ CTimerQueue.NewTimer%Ú÷üŞîÜ?ßÚ?úş¡£Óğ÷ò?ó®?ßÚ?ò­£¬ù¬ CTimerQueue.NewTimer%Ôô?îÜùŞ?ØßìéïÒ??î¤?ïïğË?ú¼¡£
	- Ëï?éÄéÍÜ×?ĞïéÄÔ²¡£î¤Windows 98ì¤ù»÷úÜâÙéÛöŞÅéÄ¡£

	\~japanese
	á¶ïÒãÁÊàª´ªÈªË«¹«ì«Ã«É«×?«ëªèªê?ª¨ªéªìª¿??ªòû¼ªÓõóª¹«¿«¤«Ş?«ª«Ö«¸«§«¯«È
	- ßÙª·ª¯ªÏ\ref timer_queueªòª´?ğÎª¯ªÀªµª¤¡£
	- CTimerQueue.NewTimer ªËªèªÃªÆ«ê«¿?«óªµªìªë«ª«Ö«¸«§«¯«ÈªÎ«¿«¤«×ªÇª¹¡£ª³ªÎ«ª«Ö«¸«§«¯«Èªò÷ò?ª¹ªëîñªŞªÇCTimerQueue.NewTimerªËªèªÃªÆÔô?ªµªìª¿??ª¬åøïÒãÁÊàª´ªÈªË«¹«ì«Ã«É«×?«ëªÇ?ú¼ªµªìªŞª¹¡£
	- «µ?«Ğ?éÄÔ²ªÇŞÅª¦ª³ªÈªòªª?ªáª·ªŞª¹¡£ Windows 98ì¤ù»ªÎ«Ğ?«¸«ç«óªÇªÏŞÅª¨ªŞª»ªó¡£
	\~
	*/
	class CTimerQueueTimer
	{
		friend CTimerQueue;

		CTimerQueue *m_manager;
		HANDLE m_timer;
		Event m_endEvent;

		CTimerQueueTimer() {} // ¸í½ÃÀû »ı¼º ±İÁö
	public:

		PROUD_API ~CTimerQueueTimer();

#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// ÀÌ Å¬·¡½º´Â ProudNet DLL °æ¿ì¸¦ À§ÇØ Ä¿½ºÅÒ ÇÒ´çÀÚ¸¦ ¾²µÇ fast heapÀ» ¾²Áö ¾Ê´Â´Ù.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif
	};

#endif // _WIN32
	/**  @} */

	// win32 or notÀ» À§ÇØ
	inline void* TlsGetValue(uint32_t tlsIndex)
	{
#ifdef _WIN32
		return ::TlsGetValue(tlsIndex);
#else
		return pthread_getspecific(tlsIndex);
#endif
	}

	// win32 or notÀ» À§ÇØ
	inline bool TlsSetValue(uint32_t tlsIndex, void* tlsValue)
	{
#ifdef _WIN32
		return ::TlsSetValue(tlsIndex, tlsValue) != 0;
#else
		return pthread_setspecific(tlsIndex, (const void*)tlsValue) == 0;
#endif
	}

	uint32_t TlsAlloc();
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
