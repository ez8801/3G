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
#include "Ptr.h"
#include "FastHeapSettings.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup util_group
	*  @{
	*/
	class CLookasideAllocatorInternal;

	/** 
	\~korean
	¸Å¿ì ºü¸¥ ¸Ş¸ğ¸® ÇÒ´ç,ÇØÁ¦¸¦ ÇÏÁö¸¸ ¸î °¡Áö Á¦¾àÀÌ ÀÖ´Ù.
	- Ç×»ó °°Àº Å©±âÀÇ ¸Ş¸ğ¸®¸¸ ÇÒ´çÇÒ ¼ö ÀÖ´Ù.
	- ÀÌ°É·Î ÇÒ´çÇÑ °´Ã¼´Â Àü¿ª º¯¼öÀÌ¾î¼­´Â ¾ÈµÈ´Ù. Áï ÇÒ´çÇÑ °´Ã¼ÀÇ Æó±â ½Ã°£º¸´Ù ÀÌ allocatorÀÇ Æó±â ½Ã°£º¸´Ù ¾ÕÀÌ¾î¾ß ÇÑ´Ù.

	Æ¯Â¡
	- ³»ºÎÀûÀ¸·Î memory page ´ÜÀ§ÀÇ ¸Ş¸ğ¸® ºí·°À» ¹Ì¸® ÇÒ´çÇÏ°í »ç¿ëÇÑ´Ù. µû¶ó¼­ ³Ê¹« ¸¹Àº °¹¼öÀÇ CLookasideAllocator ÀÎ½ºÅÏ½º¸¦ ¸¸µå´Â °ÍÀº ±ÇÀåÇÏÁö ¾Ê´Â´Ù.
	- memory page´Â VirtualAllocÀ¸·Î ÇÒ´çµÈ´Ù. µû¶ó¼­ internal fragmentationÀ» ¸¸µéÁö ¾ÊÀ¸¹Ç·Î win32 working setÀÇ Å©±âµµ Àı°¨ÇÏ´Â
	È¿°ú¸¦ ÁØ´Ù. 

	\~english
	Performs very high speed memory allocation/disengagement but there are some restrictions.
	- Memory of same size can only be allocated at all time.
	- The object allocated by this cannot be global variable. In other words, the destruction time of this allocator must come prior to the desruction time of allocated object.

	Characteristics
	- Allocate memory block of memory page unit in advance and then use it, so it is recommended not to make too many CLookasideAllocator instances. 
	- Memory page is allocated to VirtualAlloc. Since it will not create internal fragmentation, it brings an effect of reducing the size of win32 working set.

	\~chinese
	ŞªßÈöáîÜ?ğíİÂÛÕ£¬Ó£êó??ğ¤?¡£
	- ñşÒöİÂÛÕÔÒ?ÓŞá³îÜ?ğí¡£
	- éÄó®İÂÛÕîÜËÔ?ÜôÒöãÀîïæ´??£¬?İÂÛÕîÜËÔ?????é©î¤llocatorîñØü¡£

	÷åïÖ
	- î¤?İ»??à»İÂÛÕmemory page?êÈîÜ?ğíBlockı¨ŞÅéÄ£¬ì×ó®ÜôËï??Ëï?ÒıîÜ CLookasideAllocator%?ÖÇ¡£
	- memory page İÂÛÕà÷VirtualAlloc¡£ì×?Üô?Ëïinternal fragmentation£¬á¶ì¤å¥????á³win32 working setîÜÓŞá³îÜüùÍı¡£

	\~japanese
	ªÈªÆªâáÜª¤«á«â«ê?ùÜ?¡¢ú°ğ¶ªòª·ªŞª¹ª¬¡¢ª¤ª¯ªÄª«ªÎğ¤å³ª¬ª¢ªêªŞª¹¡£
	- ª¤ªÄªâÔÒª¸«µ«¤«ºªÎ«á«â«ê?ªÎªßªòùÜªê?ªÆªëª³ªÈª¬ªÇª­ªŞª¹¡£
	- ª³ªìªÇùÜªê?ªÆª¿«ª«Ö«¸«§«¯«ÈªÏîïæ´??ªÇªÏªÊª±ªìªĞªÊªêªŞª»ªó¡£?ªÁ¡¢ùÜªê?ªÆª¿«ª«Ö«¸«§«¯«ÈªÎ?Ñ¥ãÁÊàªèªêª³ªÎAllocatorªÎ?Ñ¥ãÁÊàªèªêà»ªÇªÏªÊª±ªìªĞªÊªêªŞª»ªó¡£

	÷å?
	- ?İ»îÜªËmemory page?êÈªÎ«á«â«ê?«Ö«í«Ã«¯ªòîñªâªÃªÆùÜªê?ªÆªÆŞÅéÄª·ªŞª¹¡£ªèªÃªÆ¡¢ªÈªÆªâÒıª¤ËÁ?ªÎCLookasideAllocator«¤«ó«¹«¿«ó«¹ªòíÂªëª³ªÈªÏªª?ªáª·ªŞª»ªó¡£
	- memory pageªÏVirtualAllocªËùÜªê?ªÆªŞª¹¡£ªèªÃªÆ¡¢internal fragmentationªòíÂªéªÊª¤ªÎªÇ¡¢win32 working setªÎ«µ«¤«ºªâï½Êõª¹ªë?Íıªò?ª¨ªŞª¹¡£ 
	\~
	*/
	class CLookasideAllocator
	{
	protected:
		CLookasideAllocator(); // »ı¼ºÀÚ¸¦ ¸·¾Æ¹ö¸². ÆÄ»ı Å¬·¡½º¿¡¼­³ª Çã¿ëÇÔ.
	public:
		virtual ~CLookasideAllocator();

		/** 
		\~korean
		¸Ş¸ğ¸®¸¦ ÇÒ´çÇÕ´Ï´Ù. 

		\~english
		Allocate memory.

		\~chinese
		İÂÛÕ?ğí¡£

		\~japanese
		«á«â«ê?ªòùÜªê?ªÆªŞª¹¡£
		\~
		*/
		virtual void* Alloc(size_t size) = 0;
		/** 
		\~korean
		ÇÒ´çÇß´ø ¸Ş¸ğ¸®¸¦ ÇØÁ¦ÇÕ´Ï´Ù.

		\~english
		Disengage the allocated memory.

		\~chinese
		ú°ğ¶İÂÛÕîÜ?ğí¡£

		\~japanese
		ùÜªê?ªÆª¿«á«â«ê?ªòú°ğ¶ª·ªŞª¹¡£
		\~
		*/
		virtual void Free(void* ptr) = 0;
		/** 
		\~korean
		±âº»ÀûÀ¸·Î thread safeÀÔ´Ï´Ù. ÇÏÁö¸¸ thread unsafe¸¦ ÇØ¼­ ½ÇÇà °¡¼ÓÈ­¸¦ ÇÏ·Á¸é thread unsafeÇÏ°Ô ¿É¼ÇÀ» ¹Ù²Ü ¼ö ÀÖ½À´Ï´Ù.
		- ÁÖÀÇÇØ¼­ »ç¿ëÇÏ¼Å¾ß ÇÕ´Ï´Ù. 

		\~english
		This is thread safe by default. the option can change to thread unsafe in order to accelerate.
		- Must be careful when use this.

		\~chinese
		ìéÚõãÀthread safe£¬Ó£ßÌéÄthread unsafe?ú¼?ú¼Ê¥áÜ?Ê¦ì¤?????à÷thread unsafe¡£
		- é©ñ¼ëòŞÅéÄ¡£

		\~japanese
		ĞñÜâîÜªËthread safeªÇª¹¡£ª·ª«ª·¡¢thread unsafeªËªèªÃªÆ?ú¼Ê¥áÜûùªòª¹ªëª¿ªáªËªÏ¡¢thread unsafeªË«ª«×«·«ç«óªò?ª¨ªëª³ªÈª¬ªÇª­ªŞª¹¡£
		- ñ¼ëòª·ªÆŞÅªÃªÆª¯ªÀªµª¤¡£
		
		\~
		*/
		virtual int DebugCheckConsistency() = 0;

		/** 
		\~korean
		»õ Lookaside allocator¸¦ »ı¼ºÇÕ´Ï´Ù.
		\param settings ÃÊ±â ¼Ó¼ºÀ» ¼³Á¤ÇÒ ¼ö ÀÖ½À´Ï´Ù. »ı·« °¡´ÉÇÑ ÆÄ¶ó¸ŞÅÍÀÔ´Ï´Ù.  

		\~english
		Creates a new Lookaside allocator
		\param settings Can set the initial attributes. This is a neglectable parameter.

		\~chinese
		ßæà÷ãæîÜLookaside allocator¡£
		\param settings Ê¦ì¤?öÇôøÑ¢?àõ¡£ãÀÊ¦ì¤àıÕÔîÜ??¡£

		\~japanese
		ãæª·ª¤Lookaside allocatorªòßæà÷ª·ªŞª¹¡£
		\param settings ôøÑ¢?àõªòàâïÒª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£àıÕÔÊ¦ÒöªÊ«Ñ«é«á?«¿?ªÇª¹¡£  
		\~
		*/
		PROUD_API static CLookasideAllocator* New(const CFastHeapSettings& settings = CFastHeapSettings());
	};
	typedef RefCount<CLookasideAllocator> CLookasideAllocatorPtr;

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif