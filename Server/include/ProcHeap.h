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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	class CMemoryHeap;

	/**
	\~korean
	ProudNet ÀÚÃ¼¿¡¼­ º¸À¯ÇÏ´Â ¸Ş¸ğ¸® Heap. Process HeapÀÌ ¾Æ´Ï´Ù!
	- ÀÌ Å¬·¡½º´Â ProudNet ³»ºÎ¿¡¼­ ¾´´Ù. °ú°Å¿¡´Â CFastArray µî ¸¹Àº °÷¿¡¼­ malloc,free¸¦ ½èÁö¸¸
	ÀÌ°ÍÀÌ debug CRT¿¡¼­ redefineµÇ±â ¶§¹®¿¡ debug ºôµå¿¡¼­ ´Ù¸£°Ô ÀÛµ¿ÇÑ´Ù. Æ¯È÷
	ProudNetÀÌ DLL ¹öÀüÀÎ °æ¿ì malloc,free´Â msvcr90d.dll!_free_dbg µî¿¡¼­ ·±Å¸ÀÓ ¿¡·¯¸¦ ³»±â ¶§¹®¿¡
	ÀÌ Å¬·¡½ºÀÇ »ç¿ëÀÌ ºÒ°¡ÇÇÇÏ´Ù.
	- ±×·¯³ª CSingleton À» ³»ºÎÀûÀ¸·Î »ç¿ëÇÏ°í ÀÖ´Ù. CSingleton Àº CFirstHeap ÀÌ ¾Æ´Ñ CProcHeap À» ÀÇÁ¸ÇÑ´Ù.

	\~english
	This is a memory heap that is owned by ProudNet. This is not 'Process Heap' at all!
	- This class is used inside of ProudNet. In the past, malloc and free used by many such as CFastArray but since this is re-defined at debug CRT and works differently in debug build.
	Especially when ProudNet is DLL version, malloc and free cause runtime error at msvcr90d.dll!_free_dbg therefore it is necessary to use this class.
	- However, this uses CSingleton internally. CSingleton is depended on CProcHeap, not CFirstHeap.

	\~chinese
	î¤ProudNetÜâãóÜÁ×ºîÜ?ğíĞïHeap.ÜôãÀProcess Heap£¡
	- ó®?î¤ProudNet?İ»ŞÅéÄ¡£?ËÛî¤ CFastArray%Ôõ?Òıò¢Û°éÄÖõmalloc,free£¬Ó£ãÀ??î¤debug CRT×ìredefine£¬á¶ì¤î¤debug buildñéîÜ??ÜôÔÒ¡£÷å?ãÀProudNetãÀDLL÷úÜâ?£¬malloc,free î¤msvcr90d.dll!_free_dbg Ôõ?ßæ?ú¼ŞÀËì??£¬ó®?îÜŞÅéÄãÀÜôÊ¦ù­ØóîÜ¡£
	- Ó£ãÀî¤?İ»ŞÅéÄ CSingleton%¡£ CSingleton ëî? CProcHeap%ì»ÜôãÀ CFirstHeap%¡£

	\~japanese
	ProudNet ªÎí»?ª¬ÜÁêóª¹ªë«á«â«ê?Heap. Process HeapªÇªÏª¢ªêªŞª»ªó£¡
	- ª³ªÎ«¯«é«¹ªÏProudNetªÎ?İ»ªÇŞÅª¤ªŞª¹¡£Î¦ËÛªËªÏCFastArrayªÊªÉ??ªÊá¶ªÇ malloc¡¢freeªòŞÅªÃªÆª¤ªŞª·ª¿ª¬¡¢ª³ªìª¬debug CRTªÇredefineªËªÊªëª¿ªá¡¢debug«Ó«ë«ÉªÇêŞª¦íÂÔÑªòª·ªŞª¹¡£÷åªË¡¢ProudNetª¬DLL«Ğ?«¸«ç«óªÇª¢ªëíŞùê¡¢malloc¡¢freeªÏmsvcr90d.dll!_free_dbgªÊªÉªÇ«é«ó«¿«¤«à«¨«é?ªòõóª·ªŞª¹ªÎªÇ¡¢ª³ªÎ«¯«é«¹ªÎŞÅéÄªÏŞÂÛ°ª¢ªêªŞª»ªó¡£
	- ª·ª«ª·¡¢CSingletonªò?İ»îÜªËŞÅªÃªÆª¤ªŞª¹¡£CSingletonªÏCFirstHeapªÇªÏªÊª¤CProcHeapªËëîğíª·ªŞª¹¡£
	\~
	*/
	class CFirstHeap
	{
	public:
		PROUD_API static void* Alloc(size_t size);
		PROUD_API static void* Realloc(void* ptr, size_t size);
		PROUD_API static void Free(void* ptr);

		PROUD_API static CMemoryHeap* GetHeap();
	};

	/**
	\~korean
	CFirstHeap °ú ´Ş¸® ÀÌ°ÍÀº Process HeapÀ» Á÷Á¢ ´Ù·é´Ù.
	- ÀÌ°ÍÀº CSingleton ÀÌ ÀÇÁ¸ÇÏ´Â Heap Å¬·¡½ºÀÌ´Ù.

	\~english
	Not as CFirstHeap, this directly manages Process Heap.
	- This is Heap class that CSingleton is depended on.

	\~chinese
	? CFirstHeap%ÜôÔÒ£¬??òÁïÈ?×âProcess Heap¡£
	- ?ãÀ CSingleton%ëî?îÜHeap?¡£

	\~japanese
	CFirstHeapªÈêŞªÃªÆª³ªìªÏ Process HeapªòòÁïÈö¢ªêĞâª¤ªŞª¹¡£
	- ª³ªìªÏCSingletonª¬ëîğíª¹ªëHeap«¯«é«¹ªÇª¹¡£
	\~
	*/
	class CProcHeap
	{
	public:
		PROUD_API static void* Alloc(size_t size);
		PROUD_API static void* Realloc(void* ptr, size_t size);
		PROUD_API static void Free(void* ptr);
	};

	class CMemoryHeap
	{
	public:
#if !defined(_WIN32)
		PROUD_API static CMemoryHeap* NewFromHeapHandle();
		PROUD_API static CMemoryHeap* NewHeap();
#else
		PROUD_API static CMemoryHeap* NewFromHeapHandle(HANDLE hHeap, bool autoDestroy);
		PROUD_API static CMemoryHeap* NewHeap(bool autoDestroy);
#endif

		virtual void* Alloc(size_t size) = 0;
		virtual void* Realloc(void* ptr, size_t size) = 0;
		virtual void Free(void* ptr) = 0;
		virtual int DebugCheckConsistency() = 0;

		virtual ~CMemoryHeap() {}
	};

	/**  @} */

}

#define DECLARE_NEW_AND_DELETE // »ç½Ç»ó CProcHeap::Alloc() = malloc()ÀÌ±â ¶§¹®¿¡, ±×³É ¸·¾Æ¹ö·È´Ù.
// #define DECLARE_NEW_AND_DELETE					\
// 	void* operator new(size_t size)					\
// 		{															\
// 		void *ret = CProcHeap::Alloc(size);						\
// 		if (ret == NULL)										\
// 			ThrowBadAllocException();							\
// 		return ret;												\
// 		}															\
// 	void operator delete(void* ptr, size_t)			\
// 		{															\
// 		return CProcHeap::Free(ptr);							\
// 		}
// 

/* UE4 µîÀº operator new, delete¸¦ overrideÇÏ´Âµ¥, ÀÌ¹Ì ÀÚÃ¼ÀûÀ¸·Î obj-pool µîÀ» ¾²´Â °æ¿ì ²¿ÀÏ ¼ö ÀÖ´Ù.
ÀÌ ¶§¹®¿¡ obj-pool·Î ´Ù·ïÁö´Â °ÍµéÀº ¾Æ·¡ ¸ÅÅ©·Î¸¦ ¾È¿¡¼­ ¾²µµ·Ï ÇÏÀÚ.
UE4´Â throw keyword¸¦ ¸ø ¾²¹Ç·Î ThrowBadAllocException¸¦ ¾´´Ù.
*/
#define DECLARE_NEW_AND_DELETE_THROWABLE \
 	void* operator new(size_t size)					\
 		{															\
 		void *ret = CProcHeap::Alloc(size);						\
 		if (ret == NULL)										\
 			ThrowBadAllocException();							\
 		return ret;												\
 		}															\
 	void operator delete(void* ptr, size_t)			\
 		{															\
 		return CProcHeap::Free(ptr);							\
 		}
 
#ifdef _MSC_VER
#pragma pack(pop)
#endif