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

#include "HlaEntity_C.h"
#include "HlaDelagate_Common.h" 

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud 
{
	class CHlaEntityManagerBase_C;
	class CriticalSection;
	class IHlaDelegate_C;

	/**
	\~korean
	HLA ¼¼¼Ç Å¬¶óÀÌ¾ğÆ® ¸Ş¼­µå ÀÎÅÍÆäÀÌ½ºÀÔ´Ï´Ù. 

	\~english TODO:translate needed.
	This is the HLA session client method interface. 

	\~chinese
	ãÀHLA sessionèÌÊ«Û°ÛöÍ£Øü¡£
	
	\~japanese
	HLA«»«Ã«·«ç«ó«¯«é«¤«¢«ó«È«á«½«Ã«É«¤«ó«¿?«Õ«§?«¹ªÇª¹¡£
	\~
	*/
	class IHlaHost_C
	{
	public:
		virtual ~IHlaHost_C() {};

		/** 
		\~korean
		HLA entity class¸¦ µî·ÏÇÕ´Ï´Ù. 
		HLA entity class´Â HLA compiler outputÀÌ¾î¾ß ÇÕ´Ï´Ù. 

		\~english TODO:translate needed.
		Register the HLA entity class
		The HLA entity class shall be HLA complier output. 
	
		\~chinese
		Ôô?HLA entity class¡£
		HLA entity classÔğãÀHLA compiler output¡£

		\~japanese
		HLA entity classªòÔô?ª·ªŞª¹¡£
		HLA entity classªÏHLA compiler outputªÇªÏªÊª±ªìªĞªÊªêªŞª»ªó¡£
		\~
		*/
		virtual void HlaAttachEntityTypes(CHlaEntityManagerBase_C* entityManager) = 0;

		/** 
		\~korean
		ÀÌ ¸ğµâ¿¡ ÀÇÇØ Äİ¹éµÇ´Â ¸Ş¼­µåµéÀ» ±¸ÇöÇÑ °´Ã¼¸¦ ¹Ş¾ÆµéÀÔ´Ï´Ù.

		\~english TODO:translate needed.
		It receives the objects implementing the methods called back by this module. 
	
		\~chinese
		î¤ïÈâ¥??ù¬ó®Ù¼?îÜüŞ?Û°ÛöîÜ?ßÚ¡£

		\~japanese
		ª³ªÎ«â«¸«å?«ëªËªèªÃªÆ«³?«ë«Ğ«Ã«¯ªµªìªë«á«½«Ã«Éªò?úŞª·ª¿«ª«Ö«¸«§«¯«Èªòáôª±ìıªìªŞª¹¡£
		\~
		*/
 		virtual void HlaSetDelegate(IHlaDelegate_C* dg) = 0;

		/** 
		\~korean
		»ç¿ëÀÚ´Â ÀÌ ÇÔ¼ö¸¦ ÀÏÁ¤ ½Ã°£¸¶´Ù Äİ ÇØ¾ß ÇÕ´Ï´Ù.

		\~english TODO:translate needed.
		The user shall call this function at a regular interval. 
	
		\~chinese
		éÄ?é©ØßÌ°ìéÓ«ìéïÒ??üŞ?ó®ùŞ?¡£

		\~japanese
		«æ?«¶?ªÏª³ªÎ??ªòá¶ïÒãÁÊàª´ªÈªË«³?«ëª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
		\~
		*/
		virtual void HlaFrameMove() = 0;

	};

	/** 
	\~korean
	HLA ¼¼¼Ç Å¬¶óÀÌ¾ğÆ®¿¡ ÀÇÇØ Äİ¹éµÇ´Â ÀÎÅÍÆäÀÌ½ºÀÔ´Ï´Ù. 
	
	Âü°í
	- C++ ÀÌ¿Ü ¹öÀü¿¡¼­´Â º» ¸Ş¼­µå´Â delegate callback ÇüÅÂÀÏ ¼ö ÀÖ½À´Ï´Ù.
	
	\~english TODO:translate needed.
	This is an interface called back by HLA session client. 

	Note
	- In versions other than C++, this method may be in the form of delegate callback. 
	
	\~chinese
	ù¬HLA sessionèÌÊ«üŞ?îÜÍ£Øü¡£

	?ÍÅ
	- î¤C++ì¤èâîÜ÷úÜâ£¬ó®Û°ÛöÊ¦ÒöãÀdelegate callbackû¡ãÒ¡£

	\~japanese
	HLA«»«Ã«·«ç«ó«¯«é«¤«¢«ó«ÈªËªèªÃªÆ«³?«ë«Ğ«Ã«¯ªµªìªë«¤«ó«¿?«Õ«§?«¹ªÇª¹¡£

	?ÍÅ
	- C++ ì¤èâªÎ«Ğ?«¸«ç«óªÇªÏ¡¢Üâ«á«½«Ã«ÉªÏdelegate callback û¡÷¾ªËªÊªëíŞùêª¬ª¢ªêªŞª¹¡£
	\~
	*/
	class IHlaDelegate_C:public IHlaDelegate_Common
	{
	public:
		virtual ~IHlaDelegate_C() {}

		/** 
		\~korean
		HLA entity°¡ »ı¼ºµÇ¸é ÀÌ ¸Ş¼­µå°¡ Äİ¹éµË´Ï´Ù.
		HlaOnLockCriticalSection()¿¡ ÀÇÇØ lockÀ» ½ÃÇàÇÑ »óÅÂ¿¡¼­ È£ÃâµË´Ï´Ù.

		\~english TODO:translate needed.
		When an HLA entity is generated, this method is called back. 
		This is called when the lock is performed by HlaOnLockCriticalSection()
	
		\~chinese
		ßæà÷HLA entityîÜ?ó®Û°Ûö?üŞ?¡£
		ù¬HlaOnLockCriticalSection()?ú¼lockîÜ??ù»ù¬û¼õó¡£

		\~japanese
		HLA entityª¬ßæà÷ªµªìªìªĞª³ªÎ«á«½«Ã«Éª¬«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		HlaOnLockCriticalSection()ªËªèªÃªÆ«í«Ã«¯ªòã¿ú¼ª·ª¿?÷¾ªÇû¼ªÓõóªµªìªŞª¹¡£
		\~
		*/
		virtual void HlaOnEntityAppear( CHlaEntity_C* entity ) = 0;

		/** 
		\~korean
		HLA entity°¡ ÆÄ±«µÇ¸é ÀÌ ¸Ş¼­µå°¡ Äİ¹éµË´Ï´Ù.
		´ç½ÅÀº ÀÌ ÇÔ¼ö¿¡¼­ entity¸¦ ´ÙÀ½°ú °°ÀÌ ÆÄ±«ÇØ¾ß ÇÕ´Ï´Ù. ¾È±×·¯¸é memory leakÀ¸·Î ÀÌ¾îÁı´Ï´Ù.
		(C# ¹öÀü¿¡¼­´Â ÆÄ±«¸¦ ÇÒ ÇÊ¿ä°¡ ¾ø½À´Ï´Ù. garbage collector¿¡ ÀÇÇØ Á¦°ÅµÇ±â ¶§¹®ÀÔ´Ï´Ù.)
		\code
			delete entity;
		\endcode
		HlaOnLockCriticalSection()¿¡ ÀÇÇØ lockÀ» ½ÃÇàÇÑ »óÅÂ¿¡¼­ È£ÃâµË´Ï´Ù.

		\~english TODO:translate needed.
		When an HLA entity is destroyed, this method is called back. 
		You must destroy the entity as shown below, otherwise it will lead to memory leak. 
		(You don¡¯t have to destroy in C# version, for it is removed by the garbage collector)
		\code
		delete entity;
		\endcode It is called while the lock is performed by HlaOnLockCriticalSection()
		
	
		\~chinese
		HLA entity ù¬÷ò?îÜ?ó®Û°Ûö?üŞ?¡£
		?é©î¤ó®ùŞ?åıù»÷ò?entity¡£Üú??ğãà÷memory leak¡£
		£¨î¤ C# ÷úÜâ?êóù±é©÷ò?¡£ì×??ù¬garbage collector?ğ¶£©
		\code
			delete entity;
		\endcode
		ù¬HlaOnLockCriticalSection()?ú¼lockîÜ??ù»ù¬û¼õó¡£

		\~japanese
		HLA entityª¬÷ò?ªµªìªìªĞª³ªÎ«á«½«Ã«Éª¬«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		ª¢ªÊª¿ªÏª³ªÎ??ªÇentityªòó­ªÎªèª¦ªË÷ò?ª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£ª½ªìªÈªâ¡¢memory leakªËªÄªÊª¬ªêªŞª¹¡£
		(C#«Ğ?«¸«ç«óªÇªÏ÷ò?ª¹ªëù±é©ª¬ª¢ªêªŞª»ªó¡£garbage collectorªËªèªÃªÆğ¶ËÛªµªìªëª¿ªáªÇª¹¡£)
		\code
		delete entity;
		\endcode
		HlaOnLockCriticalSection()ªËªèªÃªÆ«í«Ã«¯ªòã¿ú¼ª·ª¿?÷¾ªÇû¼ªÓõóªµªìªŞª¹¡£
		

		\~
		*/
		virtual void HlaOnEntityDisappear( CHlaEntity_C* entity ) = 0;
	};
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif