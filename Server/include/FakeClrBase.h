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

#include <vector>

#if defined(_WIN32)
	#include <WinSock2.h>
	#include <MMSystem.h>
#else
	#include <pthread.h>
	#include <sys/types.h>
#endif

#include "BasicTypes.h"
#include "Deque.h"
#include "FastArrayPtr.h"
#include "Ptr.h"
#include "Event.h"
#include "Exception.h"
#include "TimeUtil.h"
#include "PnThread.h"
#include "Singleton.h"
#include "StackNew.h"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4324)
#endif // _MSC_VER


#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/


	// CLR¿¡ ´ëµî Å¬·¡½º Âü°í
	class IClonable
	{
	public:
		virtual void Clone() = 0;
		virtual ~IClonable() {}
	};

#ifdef _WIN32
	/** 
	\~korean
	Å¸ÀÌ¸Ó Å¬·¡½º
	- ÀÏÁ¤ ½Ã°£¸¶´Ù ÀÌº¥Æ® °´Ã¼(Proud.Event Âü°í)¸¦ SetEvent, Áï ½Ã±×³ÎÇÑ´Ù.
	- .Net frameworkÀÇ System.Timer¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

	\~english
	Timer class
	- Periodically lets SetEvent evenrt object(Please refer Proud.Event), in other words, this lets it signal.
	- Acts similar to System.Timer of .NET framework

	\~chinese
	??Ğï?
	- ØßÌ°ìéÓ«??÷êŞÀËì?ßÚ£¨ ?ÍÅ Proud.Event £©SetEvent£¬??ãá?÷×ò±¡£
	- ?Net frameworkîÜ System.Timer%ÑÃó·ìé?îÜíÂéÄ¡£

	\~japanese
	«¿«¤«Ş?«¯«é«¹
	- á¶ïÒãÁÊàª´ªÈªË«¤«Ù«ó«È«ª«Ö«¸«§«¯«È£¨Proud.Eventªò?ÍÅ£©ªòSetEvent¡¢?ªÁ«·«°«Ê«ëª·ªŞª¹¡£
	- .Net frameworkªÎSystem.TimerªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
	\~
	*/
	class Timer
	{
		TimerEventHandle m_timerID;
		HANDLE m_eventHandle; // ÀÌ °´Ã¼¿¡ ´ëÇØ¼­ setÀÌ µÈ´Ù.

		static void EventSetter(void* ctx);

	public:
		/** 
		\~korean
		»ı¼ºÀÚ
		\param eventHandle ÀÏÁ¤ ½Ã°£¸¶´Ù ½Ã±×³ÎÀ» ³ÖÀ» ÀÌº¥Æ® °´Ã¼. Proud.Event¸¦ ÆÄ¶ó¸ŞÅÍ·Î ³Ö¾îµµ µÈ´Ù.
		\param interval ½Ã±×³ÎÀ» ³ÖÀ» ÁÖ±â. ¹Ğ¸®ÃÊÀÌ´Ù.

		\~english
		 Constructor
		\param eventHandle Evnet object where signal to be entered periodically. It is possible to use Proud.event as parameter.
		\param interval The period to enter signal. Unit is millisecond.

		\~chinese
		ßæà÷íº
		\param eventHandle ØßìéïÒ??Û¯ìıãá?îÜŞÀËì?ßÚ¡£Ê¦ì¤÷ê Proud.Event%Û¯ìı???¡£
		\param interval Û¯ìıãáãÓîÜñ²Ñ¢¡£Ú°ÙØ¡£

		\~japanese
		ßæà÷í­
		\param eventHandle á¶ïÒãÁÊàª´ªÈªË«·«°«Ê«ëªòìıªìªë«¤«Ù«ó«È«ª«Ö«¸«§«¯«È¡£Proud.Eventªò«Ñ«é«á?«¿?ªÈª·ªÆìıªìªÆªâÕŞª¤ªÇª¹¡£
		\param interval «·«°«Ê«ëªòìıªìªëñ²Ñ¢¡£«ß«êõ©ªÇª¹¡£
		\~
		*/
		PROUD_API Timer(HANDLE eventHandle, uint32_t interval, DWORD_PTR dwUser = 0);

		/** 
		\~korean
		ÆÄ±«ÀÚ
		- °´Ã¼¸¦ ÆÄ±«ÇÑ Á÷ÈÄºÎÅÍ´Â ÀÌº¥Æ® °´Ã¼¿¡ ½Ã±×³ÎÀ» ³ÖÁö ¾Ê´Â´Ù.

		\~english
		Destructor
		- From right after destructing objct, it is not to enter signal into event object.

		\~chinese
		÷ò?íº
		- ÷ò??ßÚı¨?ã·£¬Üô÷êãáãÓÛ¯ìıŞÀËì?ßÚ¡£

		\~japanese
		÷ò?íº
		- «ª«Ö«¸«§«¯«Èªò÷ò?ª·ª¿òÁı­ª«ªéªÏ«¤«Ù«ó«È«ª«Ö«¸«§«¯«ÈªË«·«°«Ê«ëªòìıªìªŞª»ªó¡£
		\~
		*/
		PROUD_API ~Timer();
	};
#endif
	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif // _MSC_VER
