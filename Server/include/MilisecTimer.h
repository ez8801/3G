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
#include "BasicTypes.h"
#include "Enums.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	¹Ð¸®ÃÊ ´ÜÀ§ÀÇ Á¤¹Ðµµ¸¦ °¡Áö´Â Å¸ÀÌ¸ÓÀÔ´Ï´Ù.
	- CMilisecTimer::New ¸¦ ÅëÇØ »ý¼ºÇÏ°í, delete·Î »èÁ¦ ÇÕ´Ï´Ù.
	- ³»ºÎÀûÀ¸·Î QueryPerformanceCounterÀ» »ç¿ëÇÕ´Ï´Ù.
	- Á¤¹ÐµµÀÇ ¹®Á¦°¡ ¾øÀ¸³ª, windows ¹öÁ¯,CPU¿¡ µû¶ó Àß¸øµÈ ¿¬»êÀÌ ÀÏ¾î ³¯ ¼ö ÀÖ½À´Ï´Ù.
	- ÄÄÇ»ÅÍ¸¦ ÄÑ°í 81706³â±îÁö »ç¿ëÇÒ¼ö ÀÖ½À´Ï´Ù.

	\~english
	It is a timer whose degree of precision is millisecond. 
	Create by ¡°CMilisecTimer::New¡± and delete by ¡°delete¡±.
	QueryPerformanceCounter is internally used. 
	No problem with precision but wrong calculation might occur depending on Windows version & CPU.
	Can use it up to  81706 after turning on the computer. 

	\~chinese
	ïñ?Óø?ûÆõ©?êÈîÜïÒ?Ðï¡£
	-÷×? CMilisecTimer::New ßæà÷£¬éÄdelete?ð¶¡£
	-?Ý»ÞÅéÄ QueryPerformanceCounter¡£
	-ïñ?Óø?êó??£¬Ó£êó??ÐÆËßWindows÷úÜâ£¬CPUÔõ?ßæ??æÑß©¡£
	-î¤????ý¨Ê¦ìéòÁÞÅéÄò¸81706Ò´¡£

	\~japanese
	«ß«êõ©?êÈªÎïñÚËÓøªòò¥ªÄ«¿«¤«Þ?ªÇª¹¡£
	- CMilisecTimer::NewªòÞÅéÄª·ªÆßæà÷ª·¡¢deleteªÇÞûð¶ª·ªÞª¹¡£
	-?Ý»îÜªËªÏQueryPerformanceCounterªòÞÅéÄª·ªÞª¹¡£
	-ïñÚËÓøªÎÙýð¹ªÏªÊª¤ª¬¡¢ windows«Ð?«¸«ç«óªÎCPUªËªèªÃªÆÊàêÞªÃª¿æÑß©ª¬ÑÃª³ªëÊ¦Òöàõª¬ª¢ªêªÞª¹¡£
	-«³«ó«Ô«å?«¿?ªÎï³ê¹ªòìýªìªÆ81706Ò´ªÞªÇÞÅéÄªÇª­ªÞª¹¡£

	\~
	*/
	class CMilisecTimer
	{
	public:
		virtual ~CMilisecTimer(){}

		/**
		\~korean
		Å¸ÀÌ¸Ó¸¦ ÃÊ±âÈ­ÇÑ´Ù.

		\~english
		Initialize the timer

		\~chinese
		ôøã·ûùTimer¡£

		\~japanese
		TimerªòôøÑ¢ûùª¹ªë¡£

		\~
		*/
		PROUD_API virtual void Reset() = 0;

		/**
		\~korean
		Å¸ÀÌ¸Ó¸¦ ½ÃÀÛÇÑ´Ù.

		\~english
		Start the timer

		\~chinese
		?ã·Timer¡£

		\~japanese
		TimerªòªÏª¸ªáªë¡£

		\~
		*/
		PROUD_API virtual void Start() = 0;

		/**
		\~korean
		Å¸ÀÌ¸Ó¸¦ ÀÏ½Ã Á¤ÁöÇÑ´Ù.

		\~english
		Temporarily stop the timer. 

		\~chinese
		???ò­Timer¡£

		\~japanese
		TimerªòìéãÁïÎò­ª¹ªë¡£

		\~
		*/
		PROUD_API virtual void Stop() = 0;

		/**
		\~korean
		Å¸ÀÌ¸Ó¸¦ 0.1ÃÊ¸¸Å­ ÁøÇàµÇ°Ô ÇÑ´Ù.

		\~english
		Move the timer 0.1 second forward

		\~chinese
		?Timerñþ?ú¼0.1õ©¡£

		\~japanese
		Timerªò0.1õ©ªÀª±òäú¼ªµª»ªë¡£

		\~
		*/
		PROUD_API virtual void Advance() = 0;

		/** 
		\~korean
		ÇöÀç ½Ã°£À» ¾ò´Â´Ù. 

		\~english
		Gets current time

		\~chinese
		?ö¢?î¤îÜ??¡£

		\~japanese
		úÞî¤ªÎãÁÊàªòÔðªÞª¹¡£

		\~
		*/
		PROUD_API virtual int64_t GetTimeMs() = 0; 
		
		/** 
		\~korean
		Àü¿¡ GetElapsedTimeMs() È£Ãâ·Î ºÎÅÍ Áö³­½Ã°£À» ¾ò½À´Ï´Ù.
		- MMTimer ÀÇ °æ¿ì, Á¤¹Ðµµ¿¡ ¹®Á¦°¡ ÀÖÀ» ¼ö ÀÖ½À´Ï´Ù.
		- QPCÀÇ °æ¿ì, Á¤È®ÇÑ ½Ã°£À» ¾ò±ä ÇÏÁö¸¸, GetTickCount()º¸´Ù 50¹è Á¤µµ ´À¸®´Ù.

		\~english TODO:translate needed.
		Get the elapsed time from the previous GetElapsedTimeMs() call. 
		- In the case of MMTimer, there may be a problem with the accuracy. 
		- In the case of QPC, you get accurate time, but it is 50 times slower than GetTickCount(). 

		\~chinese
		?ö¢?ñýîñGetElapsedTimeMs()û¼Ð£?ã·??îÜ??¡£
		- MMTimerîÜ?ïñÓøÊ¦Òö?êó??¡£
		- QPCîÜ?Ê¦ì¤?Ôðïá?îÜ??£¬Ó£ÝïGetTickCount()Ø·ÓÞ?50ÛÃñ§éÓ¡£

		\~japanese
		îñªÎGetElapsedTimeMs()û¼ªÓõóª·ª«ªé?Î¦ª·ª¿ãÁÊàªòÔðªÞª¹¡£
		- MMTimerªÎíÞùê¡¢ïñÚËÓøªËÙýð¹ª¬ª¢ªêÔðªÞª¹¡£
		- QPCªÎíÞùê¡¢ïáü¬ªÊãÁÊàªòÔðªëª³ªÈªÏª¢ªêªÞª¹ª¬¡¢GetTickCount()ªèªê50ÛÃªÛªÉ?ª¤ªÇª¹¡£
		\~
		*/
		PROUD_API virtual int64_t GetElapsedTimeMs() = 0; 

		/** 
		\~korean
		Å¸ÀÌ¸Ó°¡ Á¤Áö »óÅÂÀÌ¸é true¸¦ ¸®ÅÏÇÑ´Ù. 

		\~english
		Returns true when timer is paused

		\~chinese
		??ÐïãÀïÎò­??îÜ?Ú÷üÞtrue¡£

		\~japanese
		«¿«¤«Þ?ª¬ïÎò­?÷¾ªÇª¢ªìªÐtrueªò«ê«¿?«óª·ªÞª¹¡£
\~
		*/
		PROUD_API virtual bool IsStopped() = 0; 


		/**
		\~korean
		typeÀ» ÁöÁ¤ÇÏ¿© timerÀ» »ý¼ºÇÕ´Ï´Ù.

		\~english TODO:translate needed.
		Designate the type to generate the timer. 

		\~chinese
		ò¦ïÒtype£¬ßæà÷timer¡£

		\~japanese
		Typeªòò¦ïÒª·ªÆtimerªòßæà÷ª·ªÞª¹¡£
\~
		*/
		PROUD_API static CMilisecTimer* New();
	};

	/** 
	\~korean
	¸Å¿ì Á¤¹ÐÇÑ "ÇöÀç ½Ã°£"À» ¾ò´Â´Ù. Á¤¹Ðµµ´Â 1msÀÌ¸ç, °ªÀ» ¾ò¾î¿À´Â ºÎÇÏ´Â critical section lock 1È¸ÀÌ´Ù.

	\~english
	Gets very precise "current time". 1ms resolution. the time cost of this function is a critical section lock.

	\~chinese
	?ÔðÞªßÈïñ?îÜ¡°???¡±¡£ïñ?Óø?1ms£¬?ö¢?îÜ?ùÃ?1ó­ critical section lock¡£

	\~japanese
	ªÈªÆªâïñÚËªÊ"úÞî¤ãÁÊà"ªòÔðªÞª¹¡£ïñÓøªÏ1msªÇ¡¢ö·ªòö¢ªêìýªìªëÝ¶ùÃªÏcritical section lock 1üÞªÇª¹¡£
	\~
	*/
	int64_t GetPreciseCurrentTimeMs();


	/**  @} */
	}

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif
