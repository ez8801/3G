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

#include "FakeClrBase.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud 
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
#ifdef _WIN32

	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	ÀÏÁ¤ ½Ã°£¸¶´Ù Æ¯Á¤ ·çÆ¾ÀÌ ½ÇÇàµÇ°Ô ÇÏ°íÀÚ ÇÑ´Ù¸é CTimerThread ³ª CTimerQueue ¸¦ »ç¿ëÇÏ´Â ¹æ¹ýÀÌ ÀÖ½À´Ï´Ù. 
	- CTimerThread ´Â ÀÏÁ¤ ½Ã°£¸¶´Ù Å¸ÀÌ¸Ó ÄÝ¹é ÇÔ¼ö°¡ ½ÇÇàµË´Ï´Ù. ÇÏÁö¸¸ ´Ü ÇÑ°³ÀÇ ½º·¹µå¿¡¼­¸¸ÀÇ ÄÝ¹éÀÌ ÀÏ¾î³³´Ï´Ù. 
	- CTimerQueue ´Â °ú°Å Å¸ÀÌ¸Ó ÄÝ¹éÀÌ ¸®ÅÏÇÏÁö ¾ÊÀº »óÅÂ¿¡¼­ Å¸ÀÌ¸Ó ½Ã°£ÀÌ µÇ¾úÀ» ¶§¿¡´Â ¶Ç ´Ù¸¥ ½º·¹µå¿¡¼­ ÄÝ¹éÀÌ ÀÏ¾î³³´Ï´Ù.

	\~english
	 If you want to have a specific routine to run at a specific time, use  CTimerThread or CTimerQueue.
	- CTimerThread runs a timer callback function at specific times. But callback only happens in a single thread. 
	- CTimerQueue allows callback to start in a different thread at specific times even thoud the previous timer callback hasn't been returned.

	\~chinese
	åýÍýßÌî¤ØßìéïÒ???ú¼÷åïÒroutineîÜ?£¬êóÞÅéÄ CTimerThread%ûäíº CTimerQueue%îÜÛ°Ûö¡£
	- CtimerThreadî¤ØßìéïÒ???ú¼timerüÞ?ùÞ?¡£Ó£ãÀñþ?ßæìé??ïïîÜüÞ?¡£
	- CtimerQueueî¤?ËÛtimerüÞ??êóÚ÷üÞîÜ??ù»ÓðÖõtimerîÜ??£¬ûäíºî¤Ðìöâ?ïï?ßæüÞ?¡£

	\~japanese
	á¶ïÒãÁÊàª´ªÈªË÷åïÒ«ë?«Á«óª¬?ú¼ªµªìªëªèª¦ªËª·ª¿ª¤íÞùêªÏ¡¢CTimerThreadªÞª¿ªÏCTimerQueueªòÞÅª¦Û°Ûöª¬ª¢ªêªÞª¹¡£
	- CTimerThreadªÏá¶ïÒãÁÊàª´ªÈªË«¿«¤«Þ?«³?«ë«Ð«Ã«¯??ª¬?ú¼ªµªìªÞª¹¡£ª·ª«ª·¡¢ª¿ªÃª¿1ËÁªÎ«¹«ì«Ã«ÉªÇªÎªß«³?«ë«Ð«Ã«¯ª¬?ßæª·ªÞª¹¡£
	- CTimerQueueªÏÎ¦ËÛªÎ«¿«¤«Þ?«³?«ë«Ð«Ã«¯ª¬«ê«¿?«óª·ªÆª¤ªÊª¤?÷¾ªÇ«¿«¤«Þ?ãÁÊàªËªÊªÃª¿ãÁªÏ¡¢ªÞª¿êÞª¦«¹«ì«Ã«ÉªÇ«³?«ë«Ð«Ã«¯ª¬?ßæª·ªÞª¹¡£
	\~
	*/
	class CTimerThread
	{
		Event m_tickEvent;
		Timer m_timer;
		Thread m_thread;
		Thread::ThreadProc m_proc;
		void* m_procCtx;
		volatile bool m_stopThread;
		CriticalSection m_startStopMethodLock;

		static void OuterThreadProc(void* ctx);

	public:
		// trueÀÌ¸é CoInitialize°¡ ½º·¹µå ½ÃÀÛ½Ã È£ÃâµÈ´Ù.
		bool m_useComModel; 

		/** 
		\~korean
		»ý¼ºÀÚ. Å¸ÀÌ¸Ó ½º·¹µå°¡ ½ÃÀÛÇÏÁö´Â ¾Ê½À´Ï´Ù. 
		\param threadProc ÀÏÁ¤ ½Ã°£¸¶´Ù È£ÃâµÇ´Â ÇÔ¼öÀÔ´Ï´Ù. »ç¿ëÀÚ°¡ Á¤ÀÇÇØ¾ß ÇÕ´Ï´Ù.
		\param interval Å¸ÀÌ¸Ó ÁÖ±â. ¹Ð¸®ÃÊÀÔ´Ï´Ù.
		\param ctx threadProcÀÌ ½ÇÇàµÉ ¶§ ´øÁ®Áö´Â ÀÎÀÚÀÔ´Ï´Ù. »ç¿ëÀÚ°¡ ÁöÁ¤ÇØ¾ß ÇÕ´Ï´Ù. 

		\~english
		Creator and timer thead do not start here. 
		\param threadProc a function that gets called at an user-defined specific time.
		\param interval Timer cycle in millisecond.
		\param ctx A factor tht gets passed on when threadProc is running. This needs to be defined by user. 

		\~chinese
		ßæà÷íº¡£Timer ?ïï?Üô??ã·¡£
		\param threadProc ØßìéïÒ??û¼Ð£îÜùÞ?¡£é©éÄ?ïÒ?¡£
		\param interval timerñ²Ñ¢¡£ûÆõ©¡£
		\param ctx threadProc?ú¼îÜ?ý¦îÜì×í­¡£é©éÄ?ò¦ïÒ¡£

		\~japanese
		ßæà÷í­¡£«¿«¤«Þ?«¹«ì«Ã«Éª¬ËÒã·ªµªìªëª³ªÈªÏª¢ªêªÞª»ªó¡£
		\param threadProc á¶ïÒãÁÊàª´ªÈªËû¼ªÓõóªµªìªë??ªÇª¹¡£«æ?«¶?ª¬ïÒëùª·ªÊª±ªìªÐªÊªêªÞª»ªó¡£
		\param interval «¿«¤«Þ?ñ²Ñ¢¡£«ß«êõ©ªÇª¹¡£
		\param ctx threadProc ª¬?ú¼ªµªìªëãÁªËÞÅªïªìªëì×í­ªÇª¹¡£«æ?«¶?ª¬ò¦ïÒª¹ªëù±é©ª¬ª¢ªêªÞª¹¡£
		\~
		*/
		CTimerThread(Thread::ThreadProc threadProc, uint32_t interval, void *ctx);
		
		/** 
		\~korean
		ÆÄ±«ÀÚ. ÆÄ±«µÇ±â Àü¿¡ Å¸ÀÌ¸Ó ½º·¹µå¸¦ Á¾·á½ÃÅµ´Ï´Ù. 

		\~english
		Shuts down timer thread before destruction.

		\~chinese
		÷ò?íº¡£î¤÷ò?ñýîñ?ò­timer?ïï¡£

		\~japanese
		÷ò?íº¡£÷ò?ªµªìªëîñªË«¿«¤«Þ?«¹«ì«Ã«ÉªòðûÖõªµª»ªÞª¹¡£
		\~
		*/
		~CTimerThread();

		/** 
		\~korean
		Å¸ÀÌ¸Ó ½º·¹µåÀÇ ÀÛµ¿À» ½ÃÀÛÇÕ´Ï´Ù.

		\~english
		Starts the operation of timer thread.

		\~chinese
		?ã·timer?ïïîÜ??¡£

		\~japanese
		«¿«¤«Þ?«¹«ì«Ã«ÉªÎíÂÔÑªòËÒã·ª·ªÞª¹¡£
		\~
		*/
		void Start();

		/** 
		\~korean
		Å¸ÀÌ¸Ó ½º·¹µåÀÇ ÀÛµ¿À» ÁßÁöÇÏ°í, ½º·¹µå ÆÄ±«°¡ ¿Ï·áµÉ ¶§±îÁö ±â´Ù¸³´Ï´Ù. 

		\~english
		Stops the operation of timer thread and wait until a thread gets destructed.

		\~chinese
		?ò­timer?ïïîÜ??£¬ÔõÓð?ïï÷ò??áÖ¡£

		\~japanese
		«¿«¤«Þ?«¹«ì«Ã«ÉªÎíÂÔÑªòñéò­ª·ªÆ¡¢«¹«ì«Ã«É÷ò?ª¬èÇÖõª¹ªëãÁªÞªÇÓâªÁªÞª¹¡£
		\~
		*/
		void Stop();
	};

	/**  @} */
#endif
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
