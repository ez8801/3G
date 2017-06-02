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
#ifndef _WIN32
    #include "CriticalSect.h"
    #include <pthread.h>
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	¸ÖÆ¼½º·¹µå ÇÁ·Î±×·¡¹Ö¿¡¼­ semaphore °´Ã¼ÀÌ´Ù.
	- .Net FrameworkÀÇ System.Threading.Semaphore¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

	\~english
	Semaphore object of multi-thread programming.
	- This works same as System.Threading.Semaphore of .Net Framework.

	\~chinese
	Òı?ïï?ïïñéîÜsemaphore?ßÚ¡£
	- ÑÃó·?.Net Framework îÜSystem.Threading.Semaphore%ßÓÔÒîÜíÂéÄ¡£

	\~japanese
	«Ş«ë«Á«¹«ì«Ã«É«×«í«°«é«ß«ó«°ªÇsemaphore«ª«Ö«¸«§«¯«ÈªÇª¹¡£
	- .Net FrameworkªÎSystem.Threading.SemaphoreªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
	\~
	*/
	class Semaphore
	{
#ifdef _WIN32
		HANDLE m_sema;
#else
		// m_cs¿¡ ÀÇÇØ º¸È£µÊ. ÀÌ °ªÀÌ 0ÀÌ µÉ¶§±îÁö ½º·¹µå¸¦ awakeÇÑ´Ù.
		int32_t m_count, m_maxCount; 

		// semaphore ´ë½Å condition variableÀ» »ç¿ëÇÑ´Ù. ios¿¡¼­´Â ¹«Á¶°Ç named object¸¦ ¿ä±¸ÇÔ ¤¾¤§¤§
		pthread_cond_t m_cond;

		// m_cond°¡ ÇÊ¿ä·Î ÇÔ
		CriticalSection m_cs;
#endif 

	public:

		/** 
		\~korean
		»ı¼ºÀÚ
		\param initialCount semaphore °´Ã¼°¡ °¡Áú ÃÊ±â ³»ºÎ °ª
		\param maxCount semaphore °´Ã¼°¡ °¡Áú ¼ö ÀÖ´Â ÃÖ´ë°ª

		\~english
		Creator
		\param initialCount the initial value that semaphore object will have.
		\param maxCount the maximum value that semaphore object can have.

		\~chinese
		ßæà÷íº
		\param initialCount semaphore?ßÚ???êóîÜôøã·?İ»?¡£
		\param maxCount semaphoreÊ¦ì¤?êóîÜõÌÓŞ?¡£

		\~japanese
		ßæà÷í­
		\param initialCount semaphore «ª«Ö«¸«§«¯«Èª¬ò¥ªÄôøÑ¢?İ»ö·
		\param maxCount semaphore «ª«Ö«¸«§«¯«Èª¬ò¥ªÆªëõÌÓŞö·
		\~
		*/
		Semaphore(int initialCount, int maxCount);

		/** 
		\~korean
		ÆÄ±«ÀÚ 

		\~english
		Destructor

		\~chinese
		÷ò?íº

		\~japanese
		÷ò?í­
		\~
		*/
		~Semaphore();

		/** 
		\~korean
		³»ºÎ Ä«¿îÆ®°¡ 1 ÀÌ»óÀÌ µÉ ¶§±îÁö ¹«ÇÑÁ¤ ±â´Ù¸°´Ù. 
		³»ºÎ Ä«¿îÆ®°¡ 1 ÀÌ»óÀÎ °æ¿ì Ä«¿îÆ®¸¦ 1 °¨¼Ò½ÃÅ°¸é¼­ ¸®ÅÏÇÑ´Ù.

		\~english
		It waits endlessly untill the internal counte becomes higher than 1. 
		If the count becomes higher than 1, it reduces the count by 1 and returns.

		\~chinese
		ÙéùÚÔõÓğ?İ»count?1ì¤ß¾¡£
		?İ»count?1ì¤ß¾îÜ?ı¦£¬÷êcount?á´1?Ú÷üŞ¡£

		\~japanese
		?İ»«««¦«ó«Èª¬1ì¤ß¾ªËªÊªëãÁªŞªÇùÚªêªÊª¯ÓâªÁªŞª¹¡£
		?İ»«««¦«ó«Èª¬1ì¤ß¾ªÇª¢ªëíŞùê¡¢«««¦«ó«Èªò1Êõá´ªµª»ªÊª¬ªé«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		bool WaitOne()
		{
			return WaitOne(PN_INFINITE);
		}
		/** 
		\~korean
		³»ºÎ Ä«¿îÆ®°¡ 1 ÀÌ»óÀÌ µÉ ¶§±îÁö ÀÏÁ¤ ½Ã°£ ±â´Ù¸°´Ù. 
		³»ºÎ Ä«¿îÆ®°¡ 1 ÀÌ»óÀÎ °æ¿ì Ä«¿îÆ®¸¦ 1 °¨¼Ò½ÃÅ°¸é¼­ ¸®ÅÏÇÑ´Ù. 
		\param timeOut (¹Ğ¸®ÃÊ) ½Ã±×³Î ´ë±â ÃÖ´ë ½Ã°£. INFINITE¸¦ ³ÖÀ¸¸é ¹«ÇÑÁ¤ ±â´Ù¸°´Ù.

		\~english
		It waits for a specific time until the internal count becomes higher than 1. 
		If the count becomes higher than 1, it reduces the count by 1 and returns. 
		\param timeOut (millisecond) The maximum waiting time for signal standby. Input INFINITE if you want it to wait endlessly.

		\~chinese
		ÔõÓâìéïÒ??ò¸?İ»count?à÷1ì¤ß¾¡£
		?İ»count?1ì¤ß¾îÜ?ı¦£¬÷êcount?á´1?Ú÷üŞ¡£
                \param timeOut £¨ûÆõ©£©ÔõÓâãá?îÜõÌÓŞ??¡£?ìıINFINITEîÜ?ãÀÙéùÚÑ¢ÔõÓâ¡£

		\~japanese
		?İ»«««¦«ó«Èª¬1ì¤ß¾ªËªÊªëãÁªŞªÇá¶ïÒãÁÊàªòÓâªÁªŞª¹¡£
		?İ»«««¦«ó«Èª¬1ì¤ß¾ªÇª¢ªëíŞùê¡¢«««¦«ó«Èªò1Êõá´ªµª»ªÊª¬ªé«ê«¿?«óª·ªŞª¹¡£
		\param timeOut£¨«ß«êõ©£©«·«°«Ê«ëÓâªÁõÌÓŞãÁÊà¡£INFINITEªòìıªìªìªĞùÚªêªÊª¯ÓâªÁªŞª¹¡£
		\~
		*/
		bool WaitOne(uint32_t timeOut);

		/** 
		\~korean
		³»ºÎ Ä«¿îÆ®¸¦ Æ¯Á¤ °ª¸¸Å­ Áõ°¡½ÃÅ²´Ù.
		\param releaseCount Áõ°¡½ÃÅ³ °ª 
		\return Áõ°¡½ÃÅ°±â ÀüÀÇ semaphoreÀÇ ³»ºÎ °ª

		\~english TODO:translate needed.
		Increase the internal count with a certain value. 
		\param releaseCount Value to be increased
		\return Internal value of semaphore before the increase. 

		\~chinese
		ñòÊ¥?İ»countßÓ?éÍ÷åïÒ?¡£
		\param releaseCount é©ôÕÊ¥îÜ?¡£
		\return ñòÊ¥ñıîñîÜsemaphore?İ»?¡£

		\~japanese
		?İ»«««¦«ó«Èªò÷åïÒö·ªÀª±?Ê¥ªµª»ªŞª¹¡£
		\param releaseCount ?Ê¥ªµª»ªëö·
		\return ?Ê¥ªµª»ªëîñªÎ semaphoreªÎ?İ»ö·
		\~
		*/
		void Release(int releaseCount = 1);
	};

	/** @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
