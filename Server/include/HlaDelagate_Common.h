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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** 
	\~korean
	»ç¿ëÀÚ´Â ÀÌ ¸Ş¼­µåµµ ±¸ÇöÇØ¾ß ÇÕ´Ï´Ù.
	
	Âü°í
	- C++ ÀÌ¿Ü ¹öÀü¿¡¼­´Â º» ¸Ş¼­µå´Â delegate callback ÇüÅÂÀÏ ¼ö ÀÖ½À´Ï´Ù. 
	
	\~english TODO:translate needed.
	Users must implement this method. 
	
	Note
	- In versions other than C++, this method may be in the form of delegate callback. 

	\~chinese
	éÄ?å¥é©????Û°Ûö¡£

	?ÍÅ
	- C++ì¤èâ÷úÜâñéó®Û°ÛöÊ¦ÒöãÀdelegate callbackû¡ãÒ¡£

	\~japanese
	«æ?«¶?ªÏª³ªÎ«á«½«Ã«Éªâ?úŞª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£

	?ÍÅ
	- C++ ì¤èâªÎ«Ğ?«¸«ç«óªÇªÏ¡¢ª³ªÎ«á«½«Ã«ÉªÏdelegate callbackû¡÷¾ªËªÊªëª³ªÈª¬ª¢ªêªŞª¹¡£ 

	*/
	class IHlaDelegate_Common
	{
	public:
		virtual ~IHlaDelegate_Common() {}
		
		/** 
		\~korean
		HLA ³»ºÎ ¸ğµâ¿¡ ÀÇÇØ Àá±İ º¸È£°¡ ¿äÃ»µÇ¸é ÀÌ ¸Ş¼­µå°¡ Äİ¹éµË´Ï´Ù. »ç¿ëÀÚ´Â ÀÌ¸¦ ±¸ÇöÇØ¾ß ÇÕ´Ï´Ù.
		¿¹¸¦ µé¾î, ´ç½ÅÀº ÀÌ ·çÆ¾¿¡¼­ ¸Ş¸ğ¸®¸¦ º¸È£ÇÒ critical section Àá±İÀ» ÇÏ½Ç ¼ö ÀÖ°Ú½À´Ï´Ù. 
		
		\~english TODO:translate needed.
		If lock protection is requested by an HLA internal module, this method is called back. Users must implement this. 
		For example, you may do critical section lock that would protect the memory from this routine. 
		
		\~chinese
		ù¬HLA?İ»Ù¼?é­??ïÒÜÁ?îÜ?ó®Û°Ûö?üŞ?¡£éÄ?é©????¡£
		ÖÇåı£¬?Ê¦ì¤î¤ó®routine?ú¼ÜÁ??ğíîÜcritical section?ïÒ¡£

		\~japanese
		HLA?İ»«â«¸«å?«ëªËªèªÃªÆ«í«Ã«¯ÜÁûŞª¬é©ôëªµªìª¿ªéª³ªÎ«á«½«Ã«Éª¬«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£«æ?«¶?ªÏª³ªìªò?úŞª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
		ÖÇª¨ªĞ¡¢ª¢ªÊª¿ªÏª³ªÎ«ë?«Á«óªÇ«á«â«ê?ªòÜÁûŞª¹ªëcritical section«í«Ã«¯ªòª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£

		*/
		virtual void HlaOnLockCriticalSection() = 0;

		/** 
		\~korean
		HlaOnLockCriticalSection()ÀÇ ¹İ´ë ¿ªÇÒÀ» ÇÕ´Ï´Ù. 
		
		\~english TODO:translate needed.
		It performs the opposite role of HlaOnLockCriticalSection()
		
		\~chinese
		ÑÃó·HlaOnLockCriticalSection()îÜßÓÚãíÂéÄ¡£

		\~japanese
		HlaOnLockCriticalSection()ªÎÚã?æµùÜªòª·ªŞª¹¡£ 

		*/
		virtual void HlaOnUnlockCriticalSection() = 0;
	};
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
