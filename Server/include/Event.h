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



/*
LICENSE

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/



#pragma once

#include "BasicTypes.h"

#if !defined(_WIN32)
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
	¸ÖÆ¼½º·¹µå ÇÁ·Î±×·¡¹Ö¿¡¼­ÀÇ ÀÌº¥Æ® °´Ã¼ÀÌ´Ù.

	\~english
	Event object in multi-thread programming

	\~chinese
	Òı?ïï?ïï×ìîÜŞÀËì?ßÚ¡£

	\~japanese
	«Ş«ë«Á«¹«ì«Ã«É«×«í«°«é«ß«ó«°ªÇªÎ«¤«Ù«ó«È«ª«Ö«¸«§«¯«ÈªÇª¹¡£
	\~
	*/
	class Event
	{
	public:

#if defined(_WIN32)
		HANDLE m_event;

#elif defined(__linux__) || defined(__MACH__) || defined(__FreeBSD__)

		pthread_mutex_t	m_mutex;
		pthread_cond_t m_condVar;

		bool	m_manualReset;
		bool	m_isSignaled;
#endif

		/**
		\~korean
		»ı¼ºÀÚ
		\param manualReset ::WaitForSingleObject ¶Ç´Â WaitAny, WaitAll µîÀ» ÅëÇØ ÀÌ °´Ã¼ÀÇ ½Ã±×³ÎÀ» ´ë±âÇÏ´Â ½º·¹µå°¡ ÀÖ´Â »óÅÂ¿¡¼­
		½Ã±×³ÎÀÌ ¹ß»ıÇÏ¸é ´ë±â°¡ ³¡³ª°Ô µÈ´Ù. ÀÌ¶§ ÀÌº¥Æ® °´Ã¼°¡ ÀÚµ¿À¸·Î non-singal »óÅÂ(event reset)ÀÌ µÇ°Ô ÇÒ °ÍÀÌ¶ó¸é true¸¦ ³Öµµ·Ï ÇÑ´Ù.
		\param initialState ÀÌ ÀÌº¥Æ® °´Ã¼°¡ ½Ã±×³ÎÀ» Ã³À½ºÎÅÍ ¹ŞÀº »óÅÂ·Î »ı¼ºµÇ°Ô ÇÏ·Á¸é true

		\~english
		Constructor
		\param manualReset Waiting will end when signal occurs while there exists thread waiting for this object's signal through ::WaitForSingleObject or WaitAny or WaitAll.
		Enter true to make event object be non-signal state (event reset) automatically.
		\param initialState True in order to create this event object as to make it received signal initially.

		\~chinese
		ßæà÷íº
		\param manualReset ÷×?::WaitForSingleObject ûäíºWaitAny, WaitAllÔõ£¬ÔõÓâó®??îÜãá?îÜ?ïïğíî¤îÜ??ù»£¬?ßæãá?îÜ???áÖÔõÓâ¡£??ı¦ßÌ?ŞÀËì?ßÚí»??à÷non-signal ??£¨event reset£©îÜ??ìıtrue¡£
		\param initialState ßÌ?ó®ŞÀËì?ßÚßæà÷???ïÈâ¥ãá?îÜ??îÜ?true¡£

		\~japanese
		ßæà÷í­
		\param manualReset ::WaitForSingleObject ªŞª¿ªÏ WaitAny, WaitAll ªÊªÉªò÷×ª¸¡¢ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎ«·«°«Ê«ëªòÓâÑ¦ª¹ªë«¹«ì«Ã«Éª¬ª¢ªë?÷¾ªÇ«·«°«Ê«ëª¬?ßæª¹ªëªÈÓâÑ¦ª¬ğûªïªêªŞª¹¡£ª³ªÎãÁ¡¢«¤«Ù«ó«È«ª«Ö«¸«§«¯«Èª¬í»ÔÑªËnon-signal?÷¾(event reset)ªËªÊªëªèª¦ªËª·ª¿ª¤íŞùêªÏtrueªòìıªìªÆª¯ªÀªµª¤¡£
		\param initialState ª³ªÎ«¤«Ù«ó«È«ª«Ö«¸«§«¯«Èª¬«·«°«Ê«ëªòõÌôøª«ªéáôª±ª¿?÷¾ªÇßæà÷ªµªìªëªèª¦ªËª·ª¿ª¤íŞùêªÏ true
		\~
		*/
		PROUD_API Event(bool manualReset, bool initialState);

		/**
		\~korean
		±âº» ¿É¼ÇÀ¸·Î »ı¼ºÇÑ´Ù.
		- auto reset, non signaled·Î ½ÃÀÛÇÑ´Ù.

		\~english
		Creates with default option
		- Begins as auto reset and non signaled

		\~chinese
		ßæà÷ĞñÜâ??¡£
		- ?auto reset, non signaled ?ã·¡£

		\~japanese
		ĞñÜâ«ª«×«·«ç«óªÈª·ªÆßæà÷ª·ªŞª¹¡£
		- auto reset, non signaledªÇËÒã·ª·ªŞª¹¡£
		\~
		*/
		PROUD_API Event();

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
		PROUD_API ~Event();

		/**
		\~korean
		ÀÌº¥Æ®¿¡ ½Ã±×³ÎÀ» ³Ö´Â´Ù.

		\~english
		Enters signal into event

		\~chinese
		î¤ŞÀËì?ñéÊ¥ìıãá?¡£

		\~japanese
		«¤«Ù«ó«ÈªË«·«°«Ê«ëªòìıªìªŞª¹¡£
		\~
		*/
		inline void Set()
		{
#if defined(_WIN32)
			::SetEvent(m_event);
#elif defined(__linux__) || defined(__FreeBSD__)
			int ret = 0;

			// mutex lock Àâ°í ÀÛ¾÷ ÇØ¾ßÇÔ
			ret = pthread_mutex_lock(&m_mutex);
			assert(ret == 0);

			m_isSignaled = true;

			// windows event ´Â manual reset ÀÏ¶§ ¸ğµç ¾²·¹µå°¡ ±ú¾î³²
			// (reset À» ¾È½ÃÅ°´Ï °è¼Ó signal »óÅÂ¶ó...)
			if (m_manualReset)
			{
				ret = pthread_cond_broadcast(&m_condVar);
				assert(ret == 0);
			}
			else  // Auto Reset...
			{
				// WFSO ÁßÀÎ ¾²·¹µå¿¡°Ô signal ³¯¸²
				ret = pthread_cond_signal(&m_condVar);
				assert(ret == 0);

				// !! ¿©±â¼­ state °ªÀ» º¯°æÇÏ¸é ¾ÈµÊ
				// ±ú¾î³­ ¾²·¹µå°¡ ¹Ù²ã¾ßÇÔ
				// m_isSignaled = false;
			}

			ret = pthread_mutex_unlock(&m_mutex);
			assert(ret == 0);
#endif
		}

		/**
		\~korean
		½Ã±×³ÎÀ» Á¦°ÅÇÑ´Ù.

		\~english
		Revmoes signal

		\~chinese
		ì¹ğ¶ãá?¡£

		\~japanese
		«·«°«Ê«ëªòğ¶ËÛª·ªŞª¹¡£
		\~
		*/
		inline void Reset()
		{
#if defined(_WIN32)
			::ResetEvent(m_event);
#elif defined(__linux__)
			int ret = 0;

			ret = pthread_mutex_lock(&m_mutex);
			assert(ret == 0);

			m_isSignaled = false;

			ret = pthread_mutex_unlock(&m_mutex);
			assert(ret == 0);
#endif
		}

		/**
		\~korean
		½Ã±×³ÎÀÌ ¿Ã ¶§±îÁö ±â´Ù¸°´Ù.
		\param timeOut (¹Ğ¸®ÃÊ) ½Ã±×³Î ´ë±â ÃÖ´ë ½Ã°£. INFINITE¸¦ ³ÖÀ¸¸é ¹«ÇÑÁ¤ ±â´Ù¸°´Ù.

		\~english
		Waits until signal arrives
		\param timeOut (in milliseconds) signal waiting max time. It waits permanantly when infinite entered.

		\~chinese
		ÔõÓğãá?Óğ?¡£
		\param timeOut £¨ûÆÙØ£©ÔõÓâãá?õÌÓŞ??¡£Ê¥ìıINFINITEîÜ?ãÀÙéùÚÔõÓâ¡£

		\~japanese
		«·«°«Ê«ëª¬?ªëãÁªŞªÇÓâªÁªŞª¹¡£
		\param timeOut («ß«êõ©) «·«°«Ê«ëÓâÑ¦õÌÓŞãÁÊà¡£INFINITEªòìıªìªëªÈÙíùÚïÒªÇÓâªÁªŞª¹¡£
		\~
		*/
		PROUD_API bool WaitOne(uint32_t timeOut);

		/**
		\~korean
		½Ã±×³ÎÀÌ ¿Ã ¶§±îÁö ¹«ÇÑÁ¤ ±â´Ù¸°´Ù.

		\~english
		Waits indefinitely until signal arrives
		
		\~chinese
		ÙéùÚÔõò¸ãá?Óğ?¡£

		\~japanese
		«·«°«Ê«ëª¬?ªëãÁªŞªÇÙíùÚïÒªÇÓâªÁªŞª¹¡£
		\~
		*/
		PROUD_API bool WaitOne();

		/**
		\~korean
		ÀÔ·ÂµÈ ÀÌº¥Æ® °´Ã¼µé Áß ÇÏ³ª¶óµµ ½Ã±×³ÎÀÌ ¹ß»ıÇÒ ¶§±îÁö ±â´Ù¸°´Ù.
		\return -1 ¶Ç´Â ¿Ï·á ¼º°øÇÑ ÀÌº¥Æ® °´Ã¼ÀÇ ¹è¿­ Ç×¸ñ

		\~english
		Waits until at least one of event objects entered occurs
		\return -1 or allocation clause of event object that has been successfully completed

		\~chinese
		ÔõÓâ?ìıîÜŞÀËì??ñéò¸á´ìé?ŞÀËì?ßæãá?¡£
		\return -1ûäíºèÇ?à÷ÍíîÜŞÀËì?ßÚîÜÛÉÖª?ÙÍ¡£

		\~japanese
		ìıÕôªµªìª¿«¤«Ù«ó«È«ª«Ö«¸«§«¯«ÈªÎª¦ªÁìéªÄªÇªâ«·«°«Ê«ëª¬?ßæª¹ªëãÁªŞªÇÓâªÁªŞª¹¡£
		\return -1 ªŞª¿ªÏèÇÖõªËà÷Ííª·ª¿«¤«Ù«ó«È«ª«Ö«¸«§«¯«ÈªÎÛÕÖªú£ÙÍ
		\~
		*/
#if defined(_WIN32)
		inline static int WaitAny(Event** events, int count)
		{
			return WaitAny(events, count, PN_INFINITE);
		}
#endif

		/**
		\~korean
		ÀÔ·ÂµÈ ÀÌº¥Æ® °´Ã¼µé Áß ÇÏ³ª¶óµµ ½Ã±×³ÎÀÌ ¹ß»ıÇÒ ¶§±îÁö ±â´Ù¸°´Ù.
		\return -1 ¶Ç´Â ¿Ï·á ¼º°øÇÑ ÀÌº¥Æ® °´Ã¼ÀÇ ¹è¿­ Ç×¸ñ

		\~english
		Waits until at least one of event objects entered occurs
		\return -1 or allocation clause of event object that has been successfully completed

		\~chinese
		ÔõÓğ?ìıîÜŞÀËì??ñéò¸á´ìé??ßæãá?¡£
		\return -1ûäíºèÇ?à÷ÍíîÜŞÀËì?ßÚîÜÛÉÖª?ÙÍ¡£

		\~japanese
		ìıÕôªµªìª¿«¤«Ù«ó«È«ª«Ö«¸«§«¯«ÈªÎª¦ªÁìéªÄªÇªâ«·«°«Ê«ëª¬?ßæª¹ªëãÁªŞªÇÓâªÁªŞª¹¡£
		\return -1 ªŞª¿ªÏèÇÖõªËà÷Ííª·ª¿«¤«Ù«ó«È«ª«Ö«¸«§«¯«ÈªÎÛÕÖªú£ÙÍ
		\~
		*/
#if defined(_WIN32)
		static int WaitAny(Event** events, int count, uint32_t timeOut);
#endif

		/**
		\~korean
		ÀÔ·ÂµÈ ÀÌº¥Æ® °´Ã¼ÀÌ ¸ğµÎ ½Ã±×³ÎÀÌ ¹ß»ıÇÒ ¶§±îÁö ±â´Ù¸°´Ù.

		\~english
		Waits until all of event objects entered occur

		\~chinese
		ÔõÓğŞÀËìîÜ?ßÚîïİ»?ßæãá?¡£

		\~japanese
		ìıÕôªµªìª¿«¤«Ù«ó«È«ª«Ö«¸«§«¯«ÈîïªÆªËªªª¤ªÆ«·«°«Ê«ëª¬?ßæª¹ªëãÁªŞªÇÓâªÁªŞª¹¡£
		\~
		*/
#if defined(_WIN32)
		inline static int WaitAll(Event** events, int count)
		{
			return WaitAll(events, count, PN_INFINITE);
		}
#endif

		/**
		\~korean
		ÀÔ·ÂµÈ ÀÌº¥Æ® °´Ã¼ÀÌ ¸ğµÎ ½Ã±×³ÎÀÌ ¹ß»ıÇÒ ¶§±îÁö ±â´Ù¸°´Ù.

		\~english
		Waits until all of event objects entered occur

		\~chinese
		ÔõÓğŞÀËìîÜ?ßÚîïİ»?ßæãá?¡£

		\~japanese
		ìıÕôªµªìª¿«¤«Ù«ó«È«ª«Ö«¸«§«¯«ÈîïªÆªËªªª¤ªÆ«·«°«Ê«ëª¬?ßæª¹ªëãÁªŞªÇÓâªÁªŞª¹¡£
		\~
		*/
#if defined(_WIN32)
		static int WaitAll(Event** events, int count, uint32_t timeOut);
#endif
	private:
#if defined(_WIN32)
		static int WaitForSignal(Event** events, int count, uint32_t timeOut, bool waitForAll);
#endif

	public:
		// called by CObjectPool. does nothing.
		void SuspendShrink() {}
		void OnRecycle() {}
		void OnDrop() {
			// handleÀ» Áö¿ìÁö ¾Ê´Â´Ù. Ä¿³Î ¸®¼Ò½º ÀÚÃ¼¸¦ Àç»ç¿ëÇÏ´Ï±î.
		}
	};
	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
