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
#include "PNString.h"
#include "Singleton.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

#ifdef _WIN32
#pragma comment(lib, "Shlwapi.lib") // PathCombine() µîÀ» ¾²¹Ç·Î.
#endif

namespace Proud
{
	const int MaxCpuCoreCount = 4096; // 2050³âÀÌ ³Ñ¾î°¡¸é ÀÌ °ªÀ» °íÃÄ¾ß ÇÒÁöµµ ¸ğ¸¥´Ù.
	   
	/** \addtogroup util_group
	*  @{
	*/

	/**
	\~korean
	Microsecond Sleep Function.

	\~englich TODO:suspend execution for microsecond intervals.

	\~chinese
	?Ôğ?îñ?ïïîÜ??¡£

	\~japanese
	\~
	*/
	PROUD_API void USleep(long uSec);

	/**
	\~korean
	CPU°¹¼ö¸¦ ±¸ÇÑ´Ù.

	\~englich 
	Get the number of CPUs. 

	\~chinese
	Ï´CPU??¡£

	\~japanese
	CPU?ªòÏ´ªáªŞª¹¡£
	\~
	*/
	PROUD_API uint32_t GetNoofProcessors();

	/**
	\~korean
	ÇÁ·Î¼¼½ºÀÇ ÀÌ¸§À» ¾ò¾î¿Â´Ù.

	\~english 
	Get the name of the process. 

	\~chinese
	?ö¢?æ´Ù£¡£

	\~japanese
	«×«ë«»«¹Ù£ªòö¢ªê?ªßªŞª¹¡£
	\~
	*/
	PROUD_API String GetProcessName();

	/** Returns current thread ID.
	- win32 kinds: same to ::GetCurrentThreadId().
	- unix kinds: same to pthread_self(). */
	uint64_t GetCurrentThreadID();

	/**
	 \~korean
	 ProudNet »ç¿ëÀÚ°¡ ½Ç¼öÇÑ °æ¿ì¿¡¸¸ º¸¿©ÁÖ´Â ¿¡·¯´Ù.
	 - CNetConfig::UserMisuseErrorReaction ÀÇ type¿¡ µû¶ó¼­ MessageBoxÈ¤Àº µğ¹ö±×ºä·Î È®ÀÎ ÇÒ ¼ö ÀÖ´Â ¿¡·¯¸¦ Ãâ·ÂÇØÁØ´Ù.
	 \param text Error Comment

	 \~english 
	This is an error shown only when a ProudNet user makes a mistake. 
	- Depending on the type of CNetConfig::UserMisuseErrorReaction, it outputs the error that can be confirmed with either MessageBox or debugview. 
	\param text Error Comment


	 \~chinese
	 ProudNetéÄ?ã÷?îÜ?ı¦?ãÆîÜ??¡£
	 - ĞÆËß CNetConfig::UserMisuseErrorReaction%îÜtype£¬öèìÔéÄMessageBoxûäíº??viewÊ¦ì¤??îÜ??¡£
	 \param text Error Comment

	 \~japanese
	ProudNet«æ?«¶?ª¬ÊàêŞªÃª¿íŞùêªÎªßøúãÆª¹ªë«¨«é?ªÇª¹¡£
	- CNetConfig::UserMisuseErrorReactionªÎtypeªËªèªÃªÆMessageBoxªŞª¿ªÏ«Ç«Ğ«Ã«°«Ó«å?ªÇü¬ìãªÇª­ªë«¨«é?ªòõóÕôª·ªŞª¹¡£
	\param text Error Comment

	 \~
	 */
	PROUD_API void ShowUserMisuseError(const PNTCHAR* text);


	/**
	\~korean
	debug output or console¿¡ µğ¹ö±ë¿ë ¹®±¸¸¦ Ãâ·ÂÇÕ´Ï´Ù. newlineÀº Ãß°¡µÇÁö ¾Ê½À´Ï´Ù.

	\~english
	Prints text for debugging to debugger output window or console, without newline.

	\~chinese
	î¤debug output or consoleñé?õó??éÄ?Ï£¡£Üô?ôÕÊ¥newline¡£

	\~japanese
	debug output or consoleªË«Ç«Ğ«Ã«®«ó«°éÄÙşÏ£ªòõóÕôª·ªŞª¹¡£NewlineªÏõÚÊ¥ªµªìªŞª»ªó¡£
	\~
	*/
	void TraceA(const char * format, ...);


#ifdef _WIN32
	/**
	\~korean
	¹°¸®Àû ¸Ş¸ğ¸® Á¡À¯À²À» ±¸ÇÑ´Ù.

	\~english 
	Calculate the physical memory occupancy rate

	\~chinese
	Ï´Úª×â?ğíï¿êóáã¡£

	\~japanese
	Úª×âîÜ«á«â«ê?ï¿êóáãªòÏ´ªáªŞª¹¡£
	\~
	*/
	PROUD_API size_t GetOccupiedPhysicalMemory();

	/**
	\~korean
	ÃÑ ¸Ş¸ğ¸®¸¦ ±¸ÇÑ´Ù.

	\~english 
	Calculate the total memory

	\~chinese
	Ï´??ğí¡£

	\~japanese
	?«á«â«ê?ªòÏ´ªáªŞª¹¡£
	\~
	*/
	PROUD_API size_t GetTotalPhysicalMemory();

	/**
	\~korean
	ÄÄÇ»ÅÍ ÀÌ¸§À» ±¸ÇÑ´Ù.

	\~english 
	Get the computer name. 

	\~chinese
	Ï´??Ù£?¡£

	\~japanese
	«³«ó«Ô«å?«¿?Ù£ªòÏ´ªáªŞª¹¡£
	\~
	*/
	PROUD_API String GetComputerName();

	/**
	\~korean
	Windows XP, 2003¿¡¼­¸¸ Áö¿øÇÏ´Â ±â´ÉÀ¸·Î low-fragmentation heapÀ» ¾´´Ù.
	- ÀÌ°É ¾²¸é SMP È¯°æ¿¡¼­ heap Á¢±Ù ¼Óµµ°¡ ´ëÆø Çâ»óµÈ´Ù. ¹°·Ğ low-fragmentationÀÇ ÀÌÀÍµµ ¾ò´Â´Ù.
	µû¶ó¼­ °¡´ÉÇÏ¸é ÀÌ°ÍÀ» ¾²´Â °ÍÀÌ °­·Â ±ÇÀåµÈ´Ù.
	- ÀÌ ¸Ş¼­µå´Â Windows 98 µî¿¡¼­´Â Áö¿øµÇÁö ¾Ê´Âµ¥, ÀÌ·± °æ¿ì ÀÌ ¸Ş¼­µå´Â ¾Æ¹« °Íµµ ÇÏÁö ¾Ê´Â´Ù.
	ÇÏÁö¸¸ Windows 98¿¡¼­ ÇÊ¿ä Win32 API¸¦ ¸ø Ã£¾Æ ¿¡·¯°¡ ¹ß»ıÇÏÁö´Â ¾Ê´Â´Ù.

	\~english 
	As the feature supported only in Window XP and 2003, it uses low-fragmentation heap. 
	- When you use this, the heap access speed increases dramatically in SMP environment. Of course, you also get the benefits of low-fragmentation. 
	Therefore, we strongly recommend you to use this if possible. 
	- This method is not supported in Windows 98, etc. and in this case, this method does not do anything. 
	However, errors do not occur when an essential Win32 API is not searched in Window 98. 

	\~chinese
	ãÀñşî¤Windows XP, 2003ò¨ò¥îÜÍíÒö£¬ŞÅéÄlow-fragmentation heap¡£
	- ŞÅéÄ??îÜ?î¤SMP?ÌÑù»ïÈĞÎheapáÜÓø?ÓŞøëÓøğ«ÍÔ¡£?ñıå¥?ÔğÓğlow-fragmentation ××ìÌ¡£á¶ì¤Ê¦ì¤îÜ?Ë­ÕôõÏ?ŞÅéÄ??¡£
	- ó®Û°Ûöî¤Windows 98Üôò¨ò¥£¬??ı¦ó®Û°ÛöÜô?ñ®ìòù¼ŞÀï×¡£Ó£ãÀÜô?ì×Windows 98?êó?Óğù±é©Win32 APIì»?ßæ??¡£

	\~japanese
	Windows XP, 2003ªÇªÎªß«µ«İ?«Èª¹ªëÑ¦ÒöªÇlow-fragmentation heapªòŞÅª¤ªŞª¹¡£
	- ª³ªìªòŞÅª¦ªÈSMPü»ÌÑªÇheapªÎ«¢«¯«»«¹áÜÓøª¬ÓŞøëú¾ß¾ªµªìªŞª¹¡£Ú¨Öå¡¢low-fragmentationªÎ××ìÌªâÔğªŞª¹¡£
	ªèªÃªÆ¡¢ªÇª­ªìªĞª³ªìªòŞÅª¦ª³ªÈªò?Õôªª?ªáª·ªŞª¹¡£
	- ª³ªÎ«á«½«Ã«ÉªÏWindows 98ªÊªÉªÇªÏ«µ«İ?«Èª·ªŞª»ªóª¬¡¢ª³ªÎªèª¦ªÊíŞùê¡¢ª³ªÎ«á«½«Ã«ÉªÏù¼ªâª·ªŞª»ªó¡£
	ª·ª«ª·¡¢Windows 98ªÇù±é©ªÊWind 32 APIª¬Ì¸ªÄª«ªéªº«¨«é?ª¬?ßæª¹ªëª³ªÈªÏª¢ªêªŞª»ªó¡£
	\~
	*/
	PROUD_API bool EnableLowFragmentationHeap();

	String GetCurrentProgramDirectory();

	/**
	\~korean
	ÀÌ ÇÁ·Î±×·¥ÀÌ ½ÇÇàµÇ°í ÀÖ´Â Æú´õ¸¦ Ã£¾Æ¼­ current directory·Î ¼¼ÆÃÇÑ´Ù.
	- ÀÌ·¸°Ô ÇÏ´Â °æ¿ì ´Ù¸¥ µğ·ºÅä¸®¿¡¼­ ÀÌ ÇÁ·Î±×·¥À» ½ÇÇà½ÃÄÑµµ media fileÀ» Á¦´ë·Î Ã£´Â´Ù.

	\~english 
	Look for the folder where this program is being run and set as the current directory. 
	- In this case, the media file is searched properly even this program is run in other directories. 

	\~chinese
	?Óğó®ïïßíïáî¤?ú¼îÜÙşËìı¨?öÇ?current directory¡£
	- ??îÜ?£¬î¤Ğìöâdirectory?ú¼ó®ïïßíå¥?ïá??Óğmedia file¡£

	\~japanese
	ª³ªÎ«×«í«°«é«àª¬?ú¼ªµªìªÆª¤ªë«Õ«©«ë«À?ªòÌ¸ªÄª±ªÆcurrent directoryªÇàâïÒª·ªŞª¹¡£
	- ª³ªÎªèª¦ªËª¹ªëíŞùê¡¢öâªÎ«Ç«£«ì«¯«È«ê?ªÇª³ªÎ«×«í«°«é«àªò?ú¼ªµª»ªÆªâmedia fileªòïáª·ª¯Ì¸ªÄª±ªŞª¹¡£
	\~
	*/
	PROUD_API void SetCurrentDirectoryWhereProgramExists();

	/**
	\~korean
	ÇöÀç Process°¡ Service Mode·Î ½ÇÇàÁßÀÎÁö ¿©ºÎ¸¦ °Ë»çÇÕ´Ï´Ù.
	\return ¼­ºñ½º¸ğµå¸é 1 ¾Æ´Ï¸é 0

	\~english 
	Check whether the current process is being executed in service mode. 
	\return  1 if service mode, otherwise 0. 

	\~chinese
	???î¤îÜProcessãÀÜúì¤Service Mode?ú¼¡£
	\return ãÀÜ×?Ù¼ãÒîÜ?ãÀ1ÜôãÀîÜ?0¡£

	\~japanese
	úŞî¤Processª¬Service ModeªÇ?ú¼ñéªÊªÎª«ªÉª¦ª«ªò?ŞÛª·ªŞª¹¡£
	\return «µ?«Ó«¹«â?«ÉªÇª¢ªìªĞ1¡¢ª½ªìªÈªâ0
	\~
	*/
	PROUD_API bool IsServiceMode();

	/**
	\~korean
	GetQueuedCompletionStatusEx »ç¿ë °¡´É ¿©ºÎ¸¦ °Ë»çÇÑ´Ù. Server2008ÀÌ»ó¸¸ »ç¿ëÇÒ¼ö ÀÖ´Ù°í ¾Ë·ÁÁ® ÀÖ´Ù.
	\return »ç¿ë°¡´ÉÇÏ¸é 1 ¾Æ´Ï¸é 0

	\~english 
	Check whether it can be used. It is known that it can only be used in Server2008 or higher. 
	\return 1 if usable, otherwise 0. 

	\~chinese
	??GetQueuedCompletionStatusExãÀÜúÊ¦ì¤ŞÅéÄ¡£Ëß?ñşî¤Server2008ì¤ß¾Ê¦ì¤ŞÅéÄ¡£
	\return Ê¦ì¤ŞÅéÄîÜ?1£¬ÜôãÀîÜ?0¡£

	\~japanese
	GetQueuedCompletionStatusEx ŞÅéÄÊ¦ÒöÊ¦Üúªò?ŞÛª·ªŞª¹¡£Server2008ì¤ß¾ªÎªßŞÅª¦ª³ªÈª¬ªÇª­ªëªÈò±ªéªìªÆª¤ªŞª¹¡£
	\return ŞÅéÄÊ¦ÒöªÇª¢ªìªĞ1¡¢ª½ªìªÈªâ0
	\~
	*/
	PROUD_API bool IsGqcsExSupported();

	/**
	\~korean
	HyperThreading¸¦ Áö¿øÇÏ´ÂÁö¸¦ °Ë»çÇÑ´Ù.

	\~english 
	Check whether it supports HyperThreading. 

	\~chinese
	??ãÀÜúò¨ò¥HyperThreading¡£

	\~japanese
	HyperThreadingªò«µ«İ?«Èª¹ªëª«ªÉª¦ª«ªò?ŞÛª·ªŞª¹¡£
	\~
	*/
	PROUD_API bool IsHyperThreading();

	/**
	\~korean
	ºñÆ®°¡ 1ÀÎ ¼ö¸¦ Ã¼Å©ÇÕ´Ï´Ù.
	\param bitMask ºñÆ®¸¦ °Ë»çÇÒ º¯¼ö
	\return ºñÆ®°¡ 1ÀÎ ¼ö

	\~english 
	Check the number with the bit as 1. 
	\param bitMask Parameter to check the bit. 
	\return Number with the bit as 1. 


	\~chinese
	öèÎşbit?1îÜ?¡£
	\param bitmask ??bitîÜ??¡£
	\return bit?1îÜ?¡£

	\~japanese
	«Ó«Ã«Èª¬1ªÇª¢ªë?ªò«Á«§«Ã«¯ª·ªŞª¹¡£
	\param bitMask «Ó«Ã«Èªò?ŞÛª¹ªë??
	\return «Ó«Ã«Èª¬1ªÇª¢ªë?
	\~
	*/
	PROUD_API uint32_t CountSetBits(uintptr_t bitMask);

	typedef WINBASEAPI
		/*__out_opt*/
		HANDLE
		(WINAPI* CreateIoCompletionPortProc)(
		/*__in*/     HANDLE FileHandle,
		/*__in_opt*/ HANDLE ExistingCompletionPort,
		/*__in*/     ULONG_PTR CompletionKey,
		/*__in*/     uint32_t NumberOfConcurrentThreads
		);

	typedef WINBASEAPI
		BOOL
		(WINAPI* HeapSetInformationProc) (
		/*__in_opt*/ HANDLE HeapHandle,
		/*__in*/ HEAP_INFORMATION_CLASS HeapInformationClass,
		/*__in_bcount_opt HeapInformationLength*/ PVOID HeapInformation,
		/*__in*/ size_t HeapInformationLength
		);

	typedef WINBASEAPI
		BOOL
		(WINAPI* QueueUserWorkItemProc) (
		/*__in*/     LPTHREAD_START_ROUTINE Function,
		/*__in_opt*/ PVOID Context,
		/*__in*/     uint32_t Flags
		);

	typedef WINBASEAPI
		BOOL
		(WINAPI* GetQueuedCompletionStatusProc) (
		/*__in*/  HANDLE CompletionPort,
		/*__out*/ LPDWORD lpNumberOfBytesTransferred,
		/*__out*/ PULONG_PTR lpCompletionKey,
		/*__out*/ LPOVERLAPPED *lpOverlapped,
		/*__in*/  uint32_t dwMilliseconds
		);

	// win32 api¿¡¼­ º¹»çÇØ¿Â °ÍÀÓ
	struct PN_OVERLAPPED_ENTRY {
		ULONG_PTR lpCompletionKey;
		LPOVERLAPPED lpOverlapped;
		ULONG_PTR Internal;
		DWORD dwNumberOfBytesTransferred;
	};

	typedef WINBASEAPI
		BOOL
		(WINAPI* GetQueuedCompletionStatusExProc) (
		/*__in  */HANDLE CompletionPort,
		/*__out_ecount_part(ulCount, *ulNumEntriesRemoved)*/ PN_OVERLAPPED_ENTRY* lpCompletionPortEntries,
		/*__in  */uint32_t ulCount,
		/*__out */PULONG ulNumEntriesRemoved,
		/*__in  */uint32_t dwMilliseconds,
		/*__in  */BOOL fAlertable
		);

	typedef WINBASEAPI
		PVOID
		(WINAPI* AddVectoredExceptionHandlerProc) (
		/*__in*/          uint32_t FirstHandler,
		/*__in*/          PVECTORED_EXCEPTION_HANDLER VectoredHandler
		);

	typedef WINBASEAPI
		BOOL
		(WINAPI* GetLogicalProcessorInformation)(
		/*__out */	PSYSTEM_LOGICAL_PROCESSOR_INFORMATION Buffer,
		/*))inout */ PDWORD ReturnLength
		);

	/**
	\~korean
	ÆÄÀÏÀÇ Àı´ë °æ·Î ÀÌ¸§À» ±¸ÇÑ´Ù. ÀÌ¹Ì Àı´ë °æ·Î ÀÌ¸§ÀÌ¸é ±×´ë·Î ¸®ÅÏÇÑ´Ù.

	\~english 
	Get the absolute pathname of the file. If it is already the absolute pathname, return as it is. 

	\~chinese
	Ï´ÙşËìîÜ??ÖØ?Ù£?¡£ì«?ãÀ??ÖØ?Ù£?îÜ?ê«?Ú÷üŞ¡£

	\~japanese
	«Õ«¡«¤«ëªÎï¾??ÖØÙ£ªòÏ´ªáªŞª¹¡£?ªËï¾??ÖØÙ£ªÇª¢ªìªĞª½ªÎªŞªŞ«ê«¿?«óª·ªŞª¹¡£
	\~
	*/
	PROUD_API String GetFullPath(const PNTCHAR* fileName);

	/**
	\~korean
	µğ·ºÅä¸®¸¦ »ı¼ºÇÏ°í Ç®ÆĞ½º¸¦ ±¸ÇÑ´Ù.

	\~english 
	Generate a directory and get the full path. 

	\~chinese
	ßæà÷directory£¬Ï´fullpath¡£

	\~japanese
	«Ç«£«ì«¯«È«ê?ªòßæà÷ª·ªÆ«Õ«ë«Ñ«¹ªòÏ´ªáªŞª¹¡£
	\~
	*/
	PROUD_API bool CreateFullDirectory(const PNTCHAR* lpPathName, String& outCreatedDirectory);

	/**
	\~korean
	ÇöÀç µğ·ºÅä¸®¸¦ ±¸ÇÑ´Ù.

	\~english 
	Get the current directory. 

	\~chinese
	Ï´?î¤directory¡£

	\~japanese
	úŞî¤«Ç«£«ì«¯«È«ê?ªòÏ´ªáªŞª¹¡£
	\~
	*/
	PROUD_API String GetCurrentDirectory();

	/**
	\~korean
	Å¸ÀÌ¸Ó À¯Àú Äİ¹é ÇÔ¼ö
	- Å¸ÀÌ¸Ó Äİ¹é ¶Ç´Â µî·ÏµÈ ´ë±â Äİ¹éÀ» À§ÇÑ ½ÃÀÛ ÁÖ¼Ò¸¦ Á¦°øÇÏ´Â ¾îÇÃ¸®ÄÉÀÌ¼Ç Á¤ÀÇ ÇÔ¼ö ÀÌ´Ù.
	ÀÌ ÁÖ¼Ò´Â CreateTimerQueueTimer¿Í RegisterWaitForSingleObject ÇÔ¼ö·Î ÁöÁ¤ ÇÑ´Ù.

	WaitOrTimerCallbackProc Å¸ÀÔÀº Äİ¹é ÇÔ¼ö·ÎÀÇ Æ÷ÀÎÅÍ¸¦ Á¤ÀÇÇÑ´Ù. WaitOrTimerCallbackProcÀº ¾îÇÃ¸®ÄÉÀÌ¼Ç Á¤ÀÇ ÇÔ¼ö ÀÌ¸§À» À§ÇÑ ÇÃ·¹ÀÌ½ºÈ¦´õ ÀÌ´Ù.

	\param [in] lpParameter ½º·¹µå µ¥ÀÌÅÍ´Â CreateTimerQueueTimer ¹× RegisterWaitForSingleObject ÇÔ¼öÀÇ ÆÄ¶ó¹ÌÅÍ¸¦ »ç¿ëÇÏ´Â ÇÔ¼ö·Î º¸³»Áø´Ù.
	\param TimerOrWaitFired ¸¸¾à ÀÌ ÆÄ¶ó¹ÌÅÍ°¡ TRUE ¶ó¸é ´ë±â½Ã°°ÀÌ ³¡³­´Ù. ¸¸¾à ÀÌ ÆÄ¶ó¹ÌÅÍ°¡ FALSE ¶ó¸é ´ë±â ÀÌº¥Æ®´Â ½ÅÈ£¸¦ ¹ß»ı½ÃÅ²´Ù. (ÀÌ ÆÄ¶ó¹ÌÅÍ´Â Å¸ÀÌ¸Ó Äİ¹éÀ» À§ÇØ Ç×»ó TRUE ÀÌ´Ù.)

	\~english
	Timer user callback function
	- An application-defined function that serves as the starting address for a timer callback or a registered wait callback.
	Specify this address when calling the CreateTimerQueueTimer, RegisterWaitForSingleObject function.

	The WaitOrTimerCallbackProc type defines a pointer to this callback function. WaitOrTimerCallback is a placeholder for the application-defined function name.

	\param [in] lpParameter The thread data passed to the function using a parameter of the CreateTimerQueueTimer or RegisterWaitForSingleObject function.
	\param TimerOrWaitFired If this parameter is TRUE, the wait timed out. If this parameter is FALSE, the wait event has been signaled. (This parameter is always TRUE for timer callbacks.)

	\~chinese
	Timer éÄ?üŞ?ùŞ?
	- ?ÖõtimerüŞ?ûäíºğ«Íêì«Ôô?îÜÔõÓâüŞ?îÜ?ã·ò¢ò£îÜ?éÄïÒ?ùŞ?¡£
	ó®ò¢ò£ãÀë¦CreateTimerQueueTimerûúRegisterWaitForSingleObjectùŞ?ò¦ïÒ¡£

	WaitOrTimerCallbackProc ?úşïÒ?ì¤üŞ?ùŞ?îÜò¦?¡£ WaitOrTimerCallbackProc ãÀ?Öõ?éÄïÒ?ùŞ?Ù£?îÜï¿êÈİ¬¡£

	\param [in] lpParameter ?ïï?Ëß?èÙŞÅéÄCreateTimerQueueTimerĞàRegisterWaitForSingleObjectùŞ???îÜùŞ?¡£
	\param TimerOrWaitFired åıÍıó®??ãÀTRUEîÜ?ÔõÓâ?ìéÑÃ?áÖ¡£åıÍıó®??ãÀFALSEîÜ?£¬ÔõÓâevent??ßæãá?¡££¨ó®???ÖõtimerüŞ?ìéòÁãÀTRUE¡££©

	\~japanese
	«¿«¤«Ş?«æ?«¶?«³?«ë«Ğ«Ã«¯??
	- «¿«¤«Ş?«³?«ë«Ğ«Ã«¯ªŞª¿ªÏÔô?ªµªìª¿ÓâÑ¦«³?«ë«Ğ«Ã«¯ªÎª¿ªáªÎËÒã·«¢«É«ì«¹ªòğ«Íêª¹ªë«¢«×«ê«±?«·«ç«óïÒëù??ªÇª¹¡£
	ª³ªÎ«¢«É«ì«¹ªÏCreateTimerQueueTimerªÈRegisterWaitForSingleObjectªÎ??ªÇò¦ïÒª·ªŞª¹¡£
	WaitOrTimerCallbackProc«¿«¤«×ªÏ«³?«ë«Ğ«Ã«¯??ªØªÎ«İ«¤«ó«¿?ªòïÒëùª·ªŞª¹¡£WaitOrTimerCallbackProcªÏ«¢«×«ê«±?«·«ç«óïÒëù??Ù£ªÎª¿ªáªÎ«×«ì«¤«¹«Û«ë«À?ªÇª¹¡£
	\param [in] lpParameter «¹«ì«Ã«É«Ç?«¿ªÏ¡¢CreateTimerQueueTimerĞàªÓRegisterWaitForSingleObject??ªÎ«Ñ«é«á?«¿?ªòŞÅª¦??ªËáêªéªìªŞª¹¡£
	\param TimerOrWaitFired ªâª·¡¢ª³ªÎ«Ñ«é«á?«¿?ª¬TRUEªÇª¢ªìªĞÓâÑ¦ãÁªËìé?ªËğûªïªêªŞª¹¡£ªâª·¡¢ª³ªÎ«Ñ«é«á?«¿?ª¬FALSEªÇª¢ªìªĞÓâÑ¦«¤«Ù«ó«ÈªÏãá?ªò?ßæª·ªŞª¹¡£(ª³ªÎ«Ñ«é«á?«¿?ªÏ«¿«¤«Ş?«³?«ë«Ğ«Ã«¯ªÎª¿ªáªËª¤ªÄªâTRUEªÇª¹¡£)

	\~
	*/
	typedef VOID (NTAPI * WaitOrTimerCallbackProc) (PVOID lpParameter , BOOLEAN TimerOrWaitFired );

	typedef WINBASEAPI
		HANDLE
		(WINAPI* CreateTimerQueueProc) (
		VOID
		);

	typedef WINBASEAPI
		BOOL
		(WINAPI* CreateTimerQueueTimerProc ) (
		/*__deref_out*/ PHANDLE phNewTimer,
		/*__in_opt   */ HANDLE TimerQueue,
		/*__in       */ WaitOrTimerCallbackProc Callback,
		/*__in_opt   */ PVOID Parameter,
		/*__in       */ uint32_t DueTime,
		/*__in       */ uint32_t Period,
		/*__in       */ uint32_t Flags
		) ;


	typedef WINBASEAPI
		BOOL
		(WINAPI* DeleteTimerQueueTimerProc) (
		/*__in_opt*/ HANDLE TimerQueue,
		/*__in    */ HANDLE Timer,
		/*__in_opt*/ HANDLE CompletionEvent
		);

	typedef WINBASEAPI
		BOOL
		(WINAPI* DeleteTimerQueueExProc) (
		/*__in    */ HANDLE TimerQueue,
		/*__in_opt*/ HANDLE CompletionEvent
		);

	typedef WINBASEAPI
		BOOL
		(WINAPI* InitializeCriticalSectionExProc) (
		/*__out*/ LPCRITICAL_SECTION lpCriticalSection,
		/*__in*/  uint32_t dwSpinCount,
		/*__in  */uint32_t Flags
		);

#if defined(_WIN32)
	bool GetWindowsVersion(DWORD& major, DWORD& minor, DWORD& servicePack);
#endif

	/**
	\~korean
	Windows NT Àü¿ë API¸¦ µ¿ÀûÀ¸·Î ¾ò¾î¿À´Â Å¬·¡½º
	- Windows 98¿¡¼­´Â ºñ·Ï È£ÃâÀº ¸øÇÏÁö¸¸ ¾Æ¿¹ ÇØ´ç API°¡ ¾ø¾î¼­ exe ½ÇÇà Á¶Â÷µµ ¸øÇÏ´Â ¹®Á¦´Â ÇØ°áÇÒ ÇÊ¿ä°¡
	ÀÖÀ»¶§ ÀÌ Å¬·¡½º°¡ À¯¿ëÇÏ´Ù.
	- Æò¼Ò¿¡´Â ¾µ ÇÊ¿ä°¡ ¾ø´Ù. ´Ù¸¸, Windows 98¿¡¼­µµ ÀÛµ¿ÇØ¾ß ÇÏ´Â ¸ğµâÀ» ¸¸µç´Ù¸é À¯¿ëÇÏ´Ù.

	\~english
	Class that gets Windows NT custom API as dynamic
	- Though it cannot be called by Windows 98 but this can be very useful sovling troubles that even exe cannot be run.
	- Does not need to be used normally. But useful when creating a module that is to run on Windows 98.

	\~chinese
	÷êWindows NT?éÄAPIì¤???ö¢îÜ?¡£
	- ?æÔî¤Windows 98ÜôÒöû¼Ğ££¬Ó£âÍé©ú°?ì×?êó??îÜAPIì»ĞÆÜâÙéÛö?ú¼exeîÜ???£¬ó®??êóüùÍı¡£
	- øÁ??êóù±é©ŞÅéÄ¡£Ó£ãÀğ¤ğãî¤Windows 98å¥Òö??îÜÙ¼???êóéÄ¡£

	\~japanese
	Windows NT?éÄªÎAPIªò«À«¤«Ê«ß«Ã«¯ªÇÔğªÆ?ªë«¯«é«¹
	- Windows 98ªÇªÏ¡¢ª¿ªÈª¨û¼ªÓõóª·ªÏªÇª­ªŞª»ªóª¬¡¢?ôøú±?APIª¬ªÊª¯ªÆexe?ú¼ªµª¨ªÇª­ªÊª¤Ùığ¹ªÏú°Ì½ª¹ªëù±é©ª¬ª¢ªëãÁªËª³ªÎ«¯«é«¹ª¬êóéÄªÇª¹¡£
	- ÷×ßÈªËªÏŞÅª¦ù±é©ª¬ª¢ªêªŞª»ªó¡£Ó£ª·¡¢Windows 98ªÇªâíÂÔÑª·ªÊª±ªìªĞªÊªéªÊª¤«â«¸«å?«ëªòíÂªëªÊªéêóéÄªÇª¹¡£
	
	\~
	*/
	class CKernel32Api/*:protected CSingleton<CKernel32Api> ½Ì±ÛÅæ Áñ. ¾îÂ÷ÇÇ ÆÄ±«ÀÚ ÄİÀÌ ¾øÀ¸¹Ç·Î. °Ô´Ù°¡ CSingletonÀº ¹Ì·¡ ¾÷µ¥ÀÌÆ®¿¡ µû¶ó ´À·ÁÁú ¼ö ÀÖÀ¸¹Ç·Î. */
	{
		//modify by rekfkno1 - ÀÌ·¸°Ô ¸â¹öº¯¼ö·Î µÎ´Â°ÍÀº »ı¼ºÀÚ È£ÃâÀÌ ´Ê´Â°æ¿ì°¡ ÀÖ´õ¶ó.
		//±×·¡¼­ static ÇÔ¼ö³»ÀÇ static ·ÎÄÃº¯¼ö·Î ½Ì±ÛÅÏÀ» ÇÏ´Â°ÍÀÌ ÁÁÀ» µíÇÏ´Ù.
		//static CKernel32Api g_instance;
	public:
		CKernel32Api();

		PROUD_API static CKernel32Api& Instance();

		// ÇÔ¼ö Æ÷ÀÎÅÍ ¸â¹ö º¯¼öµé
		HeapSetInformationProc HeapSetInformation;
		GetQueuedCompletionStatusExProc GetQueuedCompletionStatusEx;  // windows 2008 server ÀÌÈÄºÎÅÍ ¾²´Â ±â´É

		InitializeCriticalSectionExProc InitializeCriticalSectionEx;
		GetLogicalProcessorInformation GetLogicalProcessInformation;

		HINSTANCE m_dllHandle;               // Handle to DLL
	};

	class CLocale:protected CSingleton<CLocale>
	{
	public:
		int m_languageID;

		CLocale();

		PROUD_API static CLocale& GetUnsafeRef();
	};

	class CSystemInfo:protected CSingleton<CSystemInfo>
	{
	public:
		SYSTEM_INFO m_info;

		CSystemInfo();
		inline uint32_t GetMemoryPageSize() { return m_info.dwPageSize; }

		PROUD_API static CSystemInfo& GetUnsafeRef();
	};

	/**
	\~korean
	ÇöÀç ÇÁ·Î¼¼½º¿¡¼­ »ç¿ëµÇ°í ÀÖ´Â ÃÑ ½º·¹µåÀÇ ¼ö¸¦ ¾ò¾î¿Â´Ù.

	\~english
	Gain the number of whole threads which is used in process now.

	\~chinese
	?Ôğ?î¤ŞÅéÄñéîÜ??ïï?¡£

	\~japanese
	úŞî¤«×«í«»«¹ªÇŞÅªïªìªÆª¤ªë?«¹«ì«Ã«ÉªÎ?ªòÔğªŞª¹¡£
	\~
	*/
	PROUD_API int GetTotalThreadCount();

	/**
	\~korean
	ÇöÀç ½º·¹µåÀÇ »óÅÂ¸¦ ¾ò¾î¿Â´Ù.

	\~english
	Gain the condition of that thead currently.

	\~chinese
	Gain the condition of that thead currently.

	\~japanese
	úŞî¤«¹«ì«Ã«ÉªÎ?÷¾ªòÔğªŞª¹¡£
	\~
	*/
	PROUD_API DWORD GetThreadStatus(HANDLE const handle);

#endif //#ifdef _WIN32

	/**  @} */

#ifdef _MSC_VER
	#if !defined(_NO_NTTNTRACE) && (defined(_DEBUG)||defined(IW_DEBUG))
		#define NTTNTRACE Proud::TraceA
	#else
		#define NTTNTRACE __noop // ºñ VC++¿¡¼­´Â ÀÌ°ÍÀ» »ç¿ë ¸øÇÏ¹Ç·Î ¾Æ·¡ °ÍÀÌ »ç¿ëµÊ
	#endif
#else
	#if !defined(_NO_NTTNTRACE) && (defined(_DEBUG)||defined(IW_DEBUG))
		#define NTTNTRACE(...) Proud::TraceA(__VA_ARGS__)
	#else
		#define NTTNTRACE(...) //VC++¿¡¼­´Â C4390 °æ°í°¡ ³ª¿È. ±×·¡¼­ À§ÀÇ °ÍÀÌ »ç¿ëµÊ.
	#endif
#endif

	// _MAX_PATH´Â 260¹Û¿¡ ¾ÈµÈ´Ù. ¿äÁò ¼¼´ë¿¡¼­ ÀÌ°ÍÀº ³Ê¹« ÀÛ´Ù. ÀÌ°ÍÀ» ¾²ÀÚ.
	const int LongMaxPath = 4000;

	// non-win32¿¡ ¾ø´Â °ÍµéÀ» À¯»ç ÇüÅÂ·Î Å¸ ÇÃ·§ÆûÀ» À§ÇØ ±¸Çö
	// ÀÏºÎ·¯ namespace Proud ¾È¿¡ µÎ¾ú´Ù. ¾ø´Â °ÍÀ» global namespace¿¡ ±¸ÇöÇÏ´Â °æ¿ì Å¸»ç°¡ ±¸ÇöÇÑ °Í°ú Ãæµ¹ÇÒ ¼ö ÀÖÀ¸´Ï.
	// °Ô´Ù°¡ ÀÌ Å¬·¡½ºÀÇ ¸â¹ö·Î µĞ ÀÌÀ¯: ¾È±×·¨´õ´Ï ATLÀ» Ãß°¡ÇÏ´Â °æ¿ì IsDebuggerPresent ÇÔ¼ö¸¦ ¾²´Â °÷¿¡¼­ ÄÄÆÄÀÏ ¿¡·¯°¡ ¹ß»ıÇØ¼­.
	class CFakeWin32
	{
	public:
		PROUD_API static unsigned int GetTickCount();
		PROUD_API static bool IsDebuggerPresent();
		PROUD_API static void OutputDebugStringA(const char *text);
		PROUD_API static void OutputDebugStringW(const wchar_t *text);
	};

#ifdef _PNUNICODE
#define OutputDebugStringT OutputDebugStringW
#else
#define OutputDebugStringT OutputDebugStringA
#endif


#ifdef _WIN32
	String GetMessageTextFromWin32Error(uint32_t errorCode);
#endif // _WIN32

#ifndef _WIN32
	bool fd_is_valid(int fd);
#endif


}

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

