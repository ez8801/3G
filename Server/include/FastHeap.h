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

#include <new>
#include "BasicTypes.h"
#include "FastHeapSettings.h"
#include "Exception.h"

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
	ºü¸¥ ¼Óµµ·Î heap allocÀ» ÇÏÁö¸¸ Á¦ÇÑ »çÇ×ÀÌ ÀÖ´Â ÇÒ´çÀÚ Å¬·¡½º.

	»ç¿ë¹ı
	- <a target="_blank" href="http://guide.nettention.com/cpp_ko#fast_heap" >Fast heap</a>  ÂüÁ¶

	ÀåÁ¡
	- ÇÒ´ç ¼Óµµ°¡ ºü¸£´Ù

	´ÜÁ¡
	- ÀÌ ÇÒ´çÀÚ·Î ÇÒ´çÇÑ ÀÎ½ºÅÏ½º´Â main() Á¾·á Àü¿¡ ÆÄ±«µÇ¾î¾ß ÇÑ´Ù. Áï Àü¿ª º¯¼ö·Î µÑ ¶§ ÁÖÀÇÇØ¾ß ÇÑ´Ù.
	- Æ¯Á¤ ÀÌ»ó Å©±â´Â °¡¼ÓÀ» ¹ŞÁö ¸øÇÑ´Ù.
	- ¸Ş¸ğ¸® Ç® ¹æ½ÄÀÌ¹Ç·Î Àå½Ã°£ »ç¿ë½Ã À×¿© ¸Ş¸ğ¸®°¡ ³²´Â´Ù. µû¶ó¼­ ÀÚÁÖ ÇÒ´ç/ÆÄ±«¸¦ ÇÏ´Â °æ¿ì¿¡¸¸ ¾²µµ·Ï ÇÏÀÚ.

	\~english
	Though this allocation class allocates heap alloc with high speed but there are some restrictions.

	Usage
	- Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#fast_heap" >Fast heap</a>

	Strength
	- High allocation speed

	Weakness
	- The instance allocated by this allocator must be destructed before main() terminates. In other words, must be carefu when set this as global variable.
	- A certain size or bigger cannot be accelerated.
	- This leaves some unused memory when used for a long time since this is memory pool way. Therefore, this can be used only when there are needs to perform frequent allocation/destruction.

	\~chinese
	?æÔÒööááÜheap alloc£¬Üô?êóó·ùÚğ¤ŞÀßÚîÜİÂÛÕíº?¡£

	ŞÅéÄÛ°Ûö
	- ??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#fast_heap" >Fast heap</a>%¡£

	?ïÃ
	- İÂÛÕáÜÓøöá¡£

	ÌÀïÃ
	- éÄó®İÂÛÕíºİÂÛÕîÜ?ÖÇé©î¤main()?ò­ñıîñ÷ò?¡£?£¬éÄéÍîïïï?ÕáîÜ?ı¦âÍñ¼ëò¡£
	- ÷åïÒì¤ß¾îÜÓŞá³ÜôÒöù¬Ê¥áÜ¡£
	- ì×??ğíãÀpoolÛ°ãÒ£¬???ŞÅéÄ??ßæ?åùîÜ?ğíé»Õá¡£á¶ì¤?ñşî¤?ßÈ?ú¼İÂÛÕ/÷ò?îÜ??ŞÅéÄ¡£?ı¦ŞÅéÄ?¡£

	\~japanese
	áÜª¤áÜÓøªÇheap allocªòª·ªŞª¹ª¬¡¢ğ¤ùÚŞÀú£ªÎª¢ªëùÜ?í­«¯«é«¹ªÇª¹¡£

	ŞÅéÄÛ°Ûö
	- \ref fast_heap  ?ğÎ

	íşá¶
	- ùÜ?áÜÓøª¬áÜª¤ªÇª¹¡£

	Ó­á¶
	- ª³ªÎùÜ?í­ªÇùÜªê?ªÆª¿«¤«ó«¹«¿«ó«¹ªÏmain()ğûÖõªÎîñªË÷ò?ª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£?ªÁ¡¢îïæ´??ªËöÇª¯ãÁªÏñ¼ëòª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
	- ÷åïÒì¤ß¾ªÎ«µ«¤«ºªÏÊ¥áÜªòáôª±ªéªìªŞª»ªó¡£
	- «á«â«ê?«×?«ëÛ°ãÒªÊªÎªÇ¡¢íşãÁÊàŞÅéÄãÁªËªÏ?åù«á«â«ê?ª¬?ªêªŞª¹¡£ªèªÃªÆ¡¢ªèª¯ùÜ?/÷ò?ªòª¹ªëíŞùêªÎªßŞÅª¦ªèª¦ªËª·ªŞª·ªçª¦¡£
	\~
	*/
	class CFastHeap
	{
	protected:
		CFastHeap(); // Á÷Á¢ »ı¼º ±İÁö
	public:
		enum { DefaultAccelBlockSizeLimit = 2048 };

		PROUD_API virtual ~CFastHeap();

		/**
		\~korean
		¸Ş¸ğ¸®¸¦ ÇÒ´çÇÑ´Ù. ÇÒ´çÇÑ ¸Ş¸ğ¸®´Â ReallocÀÌ³ª Free·Î Á¶Á¤µÉ ¼ö ÀÖ´Ù.
		\param size ÇÒ´ç¹ŞÀ» ¸Ş¸ğ¸® Å©±â

		\~english 
		Allocate the memory. The allocated memory may be adjusted by Realloc or Free. 
		\param size Size of the memory to be allocated. 


		\~chinese
		İÂÛÕ?ğí¡£İÂÛÕîÜ?ğíÊ¦ì¤éÄReallocûäíºFree?ïÚ¡£
		\param size Ê¦ì¤İÂÛÕîÜ?ğíÓŞá³¡£

		\~japanese
		«á«â«ê?ªòùÜªê?ªÆªŞª¹¡£ùÜªê?ªÆª¿«á«â«ê?ªÏReallocªÈª«FreeªËğàïÚªµªìªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\param size ùÜªê?ªÆªéªìªë«á«â«ê?«µ«¤«º
		\~
		*/
		virtual void* Alloc(size_t size) = 0;

		/**
		\~korean
		¸Ş¸ğ¸®¸¦ ÀçÇÒ´çÇÑ´Ù. ÀçÇÒ´çÇÑ ¸Ş¸ğ¸®´Â À§Ä¡°¡ ¹Ù²ğ ¼ö ÀÖ±â ¶§¹®¿¡ ¸®ÅÏµÇ´Â Æ÷ÀÎÅÍ °ªÀ» ¹İµå½Ã ÂüÁ¶ÇÒ °Í.
		\param ptr ÀçÇÒ´çÇÒ ¸Ş¸ğ¸® Æ÷ÀÎÅÍ
		\param size ÀçÇÒ´çÇÒ ¸Ş¸ğ¸® »çÀÌÁî

		\~english 
		Reallocate the memory. As reallocated memory may have its position switched, you must refer the returned pointer value. 
		\param ptr Memory pointer to be reallocated.
		\param size Memory size to be reallocated. 


		\~chinese
		ñìãæİÂÛÕ?ğí¡£ñìãæİÂÛÕîÜ?ğíîÜêÈöÇÊ¦Òö?ËÇ?£¬ù±??ÍÅÚ÷üŞîÜò¦??¡£
		\param ptr é©ñìãæİÂÛÕîÜ?ğíò¦?¡£
		\param size é©ñìãæİÂÛÕîÜ?ğíÓŞá³¡£

		\~japanese
		«á«â«ê?ªòî¢ùÜªê?ªÆª·ªŞª¹¡£î¢ùÜªê?ªÆª·ª¿«á«â«ê?ªÏêÈöÇª¬?ªïªëª³ªÈª¬ª¢ªêªŞª¹ªÎªÇ¡¢«ê«¿?«óªµªìªÊª¤«İ«¤«ó«¿?ö·ªòù±ªº?ğÎª·ªÆª¯ªÀªµª¤¡£
		\param ptr î¢ùÜªê?ªÆª¹ªë«á«â«ê?«İ«¤«ó«¿? 
		\param size î¢ùÜªê?ªÆª¹ªë«á«â«ê?«µ«¤«º
		\~
		*/
		virtual void* Realloc(void* ptr, size_t size) = 0;

		/**
		\~korean
		ÇÒ´çÇß´ø ¸Ş¸ğ¸®¸¦ ÇØÁ¦ÇÑ´Ù.
		\param ptr ÇÒ´ç ¹Ş¾Ò´ø ¸Ş¸ğ¸®ÀÇ Æ÷ÀÎÅÍ

		\~english 
		Clear the memory that was allocated. 
		\param ptr Pointer of the memory that was allocated. 

		\~chinese
		ú°ğ¶İÂÛÕ?îÜ?ğí¡£
		\param ptr ù¬İÂÛÕîÜ?ğíò¦?¡£

		\~japanese
		ùÜªê?ªÆª¿«á«â«ê?ªòú°ğ¶ª·ªŞª¹¡£
		\param ptr ùÜªê?ªÆª¿«á«â«ê?ªÎ«İ«¤«ó«¿?
		\~
		*/
		virtual void Free(void* ptr) = 0;

		/**
		\~korean
		CFastHeap °´Ã¼¸¦ »ı¼ºÇÑ´Ù.
		\param AccelBlockSizeLimit ÀÌ °ªº¸´Ù Å« Å©±âÀÇ ¸Ş¸ğ¸® ºí·°À» ÇÒ´çÇÒ ¶§¸¶´Ù lookaside allocator ¹æ½ÄÀ»
		¾²Áö ¾Ê´Â Åë»óÀûÀÎ ¸Ş¸ğ¸® ºí·°À» ÇÒ´çÇÑ´Ù. ÀÌ °ªÀÌ Å¬ ¼ö·Ï ´õ ¸¹Àº ¸Ş¸ğ¸®¸¦ ¼Ò¸ğÇÏÁö¸¸ ºü¸¥ ¼ÓµµÀÌ heap
		ÇÒ´ç È®·üÀÌ Ä¿Áø´Ù. (±×·¸´Ù°í Áö³ªÄ¡°Ô Å©¸é page fault ºñ¿ëÀ¸·Î ÀÎÇÑ ¼º´É ÀúÇÏ°¡ µÇ·¹ ¹ß»ıÇÑ´Ù.)
		\param pHeap ¸¸¾à ÀÌ Fast HeapÀÌ ProudNet¿¡¼­ ¹Ì¸® »ı¼ºÇÑ Àü¿ë HeapÀÌ ¾Æ´Ñ ´Ù¸¥ HeapÀ» »ç¿ëÇÏ°Ô ¸¸µé°íÀÚ ÇÑ´Ù¸é ¿©±â¿¡ CMemoryHeap °´Ã¼ÀÇ Æ÷ÀÎÅÍ¸¦
		³Ö¾î¾ß ÇÑ´Ù. ´Ü, ÀÌ Å¬·¡½º°¡ CMemoryHeap À» ÀÚµ¿ Á¦°ÅÇÏÁö´Â ¾Ê´Â´Ù.
		NULLÀ» ³ÖÀ¸¸é ProudNet¿¡¼­ ¹Ì¸® »ı¼ºÇÑ Àü¿ë HeapÀ» »ç¿ëÇÑ´Ù.
		\param safeMode CLookasideAllocator.New() Âü°í
		\param debugSafetyCheckCritSec µğ¹ö±×¿ëÀÌ´Ù. safeMode°¡ falseÀÎ °æ¿ì¿¡¸¸ À¯È¿ÇÏ´Ù.
		ÀÌ fast heapÀ» Á¢±ÙÇÒ ¶§¸¶´Ù debugSafetyCheckCritSec °¡ °¡¸®Å°´Â critical sectionÀÌ ÇöÀç ½º·¹µå¿¡ ÀÇÇØ Àá±İ »óÅÂÀÎÁö Ã¼Å©ÇÏ°í,
		Àá±İ »óÅÂ°¡ ¾Æ´Ï¸é ¿¡·¯¸¦ ¹ß»ı½ÃÅ°´Â ¾Ë¶÷À» ÇÑ´Ù.

		\~english
		Creates CFastHeap object
		\param AccelBlockSizeLimit Whenever allocating memory block bigger than this value, this allocates a usual memory block that does not follow lookaside allocator.
		Bigger this value becomes, occupies more memory but also increased chance of high speed heap allocation probability. (But if it is too bug then it lowers performance due to page fault cost.)
		\param pHeap In order to let this Fast Heap use other Heap that is not previously created by ProudNet, CMemoryHeap object pointer must be entered in here.
		But, this class does not automatically remove CMemoryHeap.
		If NULL is entered in here then uses previously created Heap by ProudNet.
		\param safeMode Please refer CLookasideAllocator.New()
		\param debugSafetyCheckCritSec for debugging use. Only valid when safeMode=false
		Whenever access to this fast heap, must check if critical section pointed by debugSafetyCheckCritSec is in its locked status by current thread, if not locked then this alarms that error occurs.

		\~chinese
		ßæà÷ CFastHeap%?ßÚ¡£
		\param AccelBlockSizeLimit Øß?İÂÛÕİïó®?ÓŞîÜ?ğíBLOCKîÜ?ı¦£¬İÂÛÕÜôéÄlookaside allocatorÛ°ãÒîÜìéÚõ?ğíblock¡£???êÆÓŞøµ?á¼ÙÄÌÚÒıîÜ?ğí£¬Ó£ãÀöááÜİÂÛÕheap?áã?ñòÊ¥¡££¨?Î·åıó®£¬?ÓŞîÜ?å¥??ßæì×page fault?éÄîÜàõÒöî¸ù»¡££©
		\param pHeap åıÍı??Fast HeapßÌ?ËïÜôãÀî¤ProudNetŞÀà»ßæà÷îÜ?éÄHeapîÜĞìöâheapûäãÀßÌé©ŞÅéÄĞìöâheapîÜ?£¬?×ìé©ôÕÊ¥ CMemoryHeap%?ßÚîÜò¦?¡£Ó£ãÀ£¬ó®?Üô?í»??ğ¶ CMemoryHeap%¡£
		?ìıNULL?ŞÅéÄî¤ProudNetñıîñßæà÷îÜ?éÄHeap¡£
		\param safeMode ??ÍÅ CLookasideAllocator.New()¡£
		\param debugSafetyCheckCritSec ãÀ??éÄ¡£ñşî¤safeModeãÀfalse?êóüù¡£
		Øß?????fast heapîÜ?ı¦£¬é©??debugSafetyCheckCritSeá¶ò¦ú¾îÜcritical sectionãÀÜúãÀù¬?î¤?ïï?ïÒîÜ??£¬åıÍıÜôãÀøµ?ïÒÌí???¡£

		\~japanese
		CFastHeap«ª«Ö«¸«§«¯«Èªòßæà÷ª·ªŞª¹¡£
		\param AccelBlockSizeLimit ª³ªÎö·ªèªêÓŞª­ª¤«µ«¤«ºªÎ«á«â«ê?«Ö«í«Ã«¯ªòùÜªê?ªÆªëãÁª´ªÈªËlookaside allocatorÛ°ãÒªòŞÅªïªÊª¤÷×ßÈªÎ«á«â«ê?«Ö«í«Ã«¯ªòùÜªê?ªÆªŞª¹¡£ª³ªÎö·ª¬ÓŞª­ª¤ªÛªÉªâªÃªÈÒıª¤«á«â«ê?ªòá¼ÙÄª·ªŞª¹ª¬¡¢áÜª¤áÜÓøª¬heapùÜ?ü¬áãª¬ÓŞª­ª¯ªÊªêªŞª¹¡£(ª·ª«ª·¡¢ª¢ªŞªêªËªâÓŞª­Î¦ª®ª¿ªépage fault«³«¹«ÈªËªèªëàõÒöî¸ù»ªÎª¿ªáæ½ªËàõÒöî¸ù»ª¬?ßæª·ªŞª¹¡£) 
		\param pHeap ªâª·¡¢ª³ªÎFast Heapª¬ProudNetªÇîñªâªÃªÆßæà÷ª·ª¿?éÄªÎHeapªÇªÏªÊª¤öâªÎHeapªòŞÅéÄª¹ªëªèª¦ªËª·ª¿ª¤íŞùêªÏ¡¢ª³ª³ªËCMemoryHeap«ª«Ö«¸«§«¯«ÈªÎ«İ«¤«ó«¿?ªòìıªìªÊª±ªìªĞªÊªêªŞª»ªó¡£Ó£ª·¡¢ª³ªÎ«¯«é«¹ª¬CMemoryHeapªòí»ÔÑğ¶ËÛª¹ªëª³ªÈªÏª¢ªêªŞª»ªó¡£
		NULLªòìıªìªëªÈProudNetªÇîñªâªÃªÆßæà÷ª·ª¿?éÄªÎHeapªòŞÅéÄª·ªŞª¹¡£
		\param safeMode CLookasideAllocator.New() ?ğÎ	
		\param debugSafetyCheckCritSec «Ç«Ğ«Ã«°éÄªÇª¹¡£safeModeª¬falseªÇª¢ªëíŞùêªÎªßêó?ªÇª¹¡£ 
		ª³ªÎfast heapªò«¢«¯«»«¹ª¹ªëãÁª´ªÈªËdebugSafetyCheckCritSecª¬ò¦ª¹critical sectionª¬úŞî¤ªÎ«¹«ì«Ã«ÉªËªèªÃªÆ«í«Ã«¯?÷¾ªÊªÎª«ªò«Á«§«Ã«¯ª·ªÆ¡¢«í«Ã«¯?÷¾ªÇªÏªÊª±ªìªĞ«¨«é?ªò?ßæªµª»ªë«¢«é?«àªòª·ªŞª¹¡£ 
		
		\~
		*/
		PROUD_API static CFastHeap* New( size_t AccelBlockSizeLimit = DefaultAccelBlockSizeLimit , const CFastHeapSettings& settings = CFastHeapSettings());

		/**
		\~korean
		blockÀÌ fast heap¿¡ ÀÇÇØ ¸¸µé¾îÁø °ÍÀÌ ¾Æ´Ï¸é ¿¡·¯Ã¢À» ³»°Å³ª Å©·¡½Ã°¡ ¹ß»ıÇÑ´Ù.

		\~english
		If block is not created by fast heap then it will either produce an error window or cause a crash.

		\~chinese
		åıÍıblockÜôãÀù¬fast heap?ËïîÜ?£¬?õó????ûäíº?ßæİÚ?¡£

		\~japanese
		«Ö«í«Ã«¯ª¬fast heapªËªèªÃªÆíÂªéªìª¿ªÎªÇªÏªÊª±ªìªĞ«¨«é??ØüªòøúãÆª¹ªëª««¯«é«Ã«·«åª¬?ßæª·ªŞª¹¡£
		\~
		*/
		PROUD_API static void AssureValidBlock(void* block);

		virtual int DebugCheckConsistency() = 0;
	};

	template<typename T>
	inline T* FastHeap_NewInstance(CFastHeap* heap)
	{
		T* ret = (T*)heap->Alloc(sizeof(T));

		if (ret == NULL)
			ThrowBadAllocException();

		CallConstructor<T>(ret);

		return ret;
	}

	template<typename T>
	inline void FastHeap_DeleteInstance(CFastHeap* heap, T* obj)
	{
		CallDestructor<T>(obj);
		heap->Free(obj);
	}

	/**  @} */

}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
