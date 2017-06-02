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
#include "Random.h"
#include "FakeClr.h"
#include "pnguid.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/
	class Random
	{
		CRandom m_rand;
	public:
		Random()
		{
			m_rand.InitializeSeed();
		}

		/** 
		\~korean
		0~1 »çÀÌ ³­¼ö ºÎµ¿¼Ò¼öÁ¡ °ªÀ» »ı¼ºÇÕ´Ï´Ù.

		\~english
		Create random floating point value between 0 to 1

		\~chinese
		ßæà÷0~1ñı??Ïõİ©ïÃ£¨floating point£©?¡£

		\~japanese
		0~1ªÎÊàªÎ??ÜôÔÑá³?ïÃö·ªòßæà÷ª·ªŞª¹¡£
		\~
		*/
		PROUD_API double NextDouble();

		/** 
		\~korean
		³­¼ö°ªÀ» »ı¼ºÇÕ´Ï´Ù.
		»ı¼ºµÈ ³­¼ö°ªÀº 0ºÎÅÍ maxVal±îÁö Áß ÇÏ³ªÀÔ´Ï´Ù.

		\~english
		Create random number.
		Created random number will be one of between 0 to maxVal.

		\~chinese
		ßæà÷?Ïõ?¡£
		ßæà÷îÜ?Ïõ?ãÀ0ÓğmaxValñı?îÜìé?¡£

		\~japanese
		??ö·ªòßæà÷ª·ªŞª¹¡£
		ßæà÷ªµªìª¿??ö·ªÏ0ª«ªémaxValªŞªÇªÎñéªÎìéªÄªÇª¹¡£
		\~
		*/
		PROUD_API int Next(int maxVal);

		/** 
		\~korean
		GUID ³­¼ö°ªÀ» »ı¼ºÇÕ´Ï´Ù.

		\~english
		Create GUID random number.

		\~chinese
		ßæà÷GUID?Ïõ?¡£

		\~japanese
		GUID??ö·ªòßæà÷ª·ªŞª¹¡£
		\~
		*/
		PROUD_API Guid NextGuid();
	};
	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
