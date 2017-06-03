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
#include "Event.h"
#include "CallbackContext.h"
#include "LambdaWrap.h"

#ifdef SUPPORTS_LAMBDA_EXPRESSION
#include <functional>
#endif
#include <memory>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

namespace Proud 
{
	class ThreadProcContext;

	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	´Ü¼ø ½º·¹µå Wrapper Å¬·¡½ºÀÔ´Ï´Ù.
	- ÀÌ ÀÎ½ºÅÏ½º¸¦ »ı¼ºÇÑ ÈÄ Start¸¦ È£ÃâÇÏ¸é ½º·¹µå°¡ »ı¼ºµË´Ï´Ù. ±×¸®°í ÀÌ ÀÎ½ºÅÏ½º°¡ ÆÄ±«µÇ¸é »ı¼ºµÇ¾ú´ø ½º·¹µå°¡ Á¾·áÇÒ ¶§±îÁö ºí·¯Å·µË´Ï´Ù.
	- ÀÌ Å¬·¡½º´Â .net frameworkÀÇ System.Threading.Thread Å¬·¡½º¿Í °°Àº ÀÛµ¿ ¹æ½ÄÀ» °¡Áı´Ï´Ù.

	ÀÏ¹İÀû »ç¿ë¹ı
	- Thread °´Ã¼¸¦ »ı¼ºÇÏµÇ, ÆÄ¶ó¸ŞÅÍ·Î ½º·¹µå ÇÔ¼ö¸¦ ÁöÁ¤ÇÕ´Ï´Ù. ½º·¹µå ÇÔ¼ö´Â »ı¼ºÀÚ¿¡¼­ ÁöÁ¤ÇÕ´Ï´Ù.
	- Thread °´Ã¼¸¦ »ı¼ºÇÑ´Ù°í ÇØ¼­ ¹Ù·Î ½º·¹µå°¡ ÀÛµ¿ÇÏÁö´Â ¾Ê½À´Ï´Ù. Start¸¦ ½ÇÇàÇØ¾ß¸¸ ÇÕ´Ï´Ù.
	- JoinÀ» È£ÃâÇÏ°Å³ª Thread °´Ã¼°¡ ÆÄ±«µÉ ¶§ ½ÇÇàÁßÀÎ ½º·¹µå°¡ Á¾·áÇÒ ¶§±îÁö ±â´Ù¸³´Ï´Ù.

	\~english
	Simple thread wrapper class
	- After creating this instance, a thread will be created by calling Start. And if this instance is destructed then it will be blocked until created thread is terminated.
	- This class has the same operating process as System.Threading.Thread class of .NET framework. 

	General usage
	- Creates a thread object and designates thread function as a parameter. The thread function is designated by constructor.
	- Creating a thread object does not mean immediate thread execution. Start must be run. 
	- Either when calls Join or destructing the thread object, this waits until the running thread ends.

	\~chinese
	??ïïWrapper?
	- ßæà÷ó®?ÖÇı¨û¼õóStart?Ê¦ßæà÷?ïï¡£ó®?ÖÇù¬÷ò?ı¨£¬î¤á¶ßæà÷îÜ?ïï?ò­?ò­?ú¼Blocking¡£
	- ó®?? .net frameworkîÜ System.Threading.Thread ?ÎıêóßÓÔÒîÜ?ú¼Û°ãÒ¡£

	ìéÚõŞÅéÄÛ°Ûö
	- ßæà÷Thread?ßÚ?éÄ??ò¦ïÒ?ïïùŞ?¡£?ïïùŞ?î¤ßæà÷íºñéò¦ïÒ¡£
	- ?ŞÅßæà÷ÖõThread?ßÚå¥Üô?Ø¡??ú¼?ïï£¬âÍé©?ú¼Start¡£
	- û¼õóJoinûäThread?ßÚù¬÷ò??ìéòÁÔõÓğ?ú¼ñéîÜ?ïï?ò­?ò­¡£
	\~japanese
	«·«ó«×«ë«¹«ì«Ã«ÉWrapper«¯«é«¹
	- ª³ªÎ«¤«ó«¹«¿«ó«¹ªòßæà÷ª·ªÆStartªòû¼ªÓõóª¹ªÈ«¹«ì«Ã«Éª¬ßæà÷ªµªìªŞª¹¡£ª½ª·ªÆª³ªÎ«¤«ó«¹«¿«ó«¹ª¬÷ò?ªµªìªëªÈßæà÷ªµªìªÆª¿«¹«ì«Ã«Éª¬ğûÖõªµªìªëªŞªÇ«Ö«í«Ã«¯ªµªìªŞª¹¡£
	-ª³ªÎ«¯«é«¹ªÏ.net frameworkªÎSystem.Threading.Thread«¯«é«¹ªÈÔÒª¸ªèª¦ªÊíÂÔÑÛ°ãÒªòò¥ªÁªŞª¹¡£

	ìéÚõîÜªÊŞÅª¤Û°
	-Thread«ª«Ö«¸«§«¯«Èªòßæà÷ª·ªŞª¹ª¬¡¢«Ñ«é«á?«¿?ªÇ«¹«ì«Ã«ÉªÎ??ªòò¦ïÒª·ªŞª¹¡£«¹«ì«Ã«É??ªÏÏ°õéí­ªÇò¦ïÒª·ªŞª¹¡£
	-Thread«ª«Ö«¸«§«¯«Èªòßæà÷ª·ªÆªâ¡¢ª¹ª°ªË«¹«ì«Ã«Éª¬íÂÔÑª¹ªëªïª±ªÇªÏª¢ªêªŞª»ªó¡£Startªò?ú¼ª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
	-Joinªòû¼ªÓõóª·ª¿ªêThread«ª«Ö«¸«§«¯«Èª¬÷ò?ªµªìªëğ·¡¢?ú¼ñéªÎ«¹«ì«Ã«Éª¬ğûÖõªµªìªëªŞªÇÓâªÁªŞª¹¡£
	\~

	\~korean ¿©·¯ºĞÀº ½º·¹µå°¡ ½ÇÇàÇÒ ·çÆ¾À» ¾Æ·¡Ã³·³ ¶÷´Ù½Ä(lambda expression)À¸·Î ¸¸µå¼Åµµ µË´Ï´Ù.
	\~english You may create a routine that a thread will execute as Lambda Expression below.
	\~chinese ?éÍ?ïï??ú¼îÜRoutine?Ê¦ì¤éÄì¤ù»Lambdaû¡ãÒ?Ëï¡£
	\~japanese «¹«ì«Ã«Éª¬?ú¼ª¹ªë«ë?«Á«óªòù»ÑÀªÎªèª¦ªË«é«à«ÀãÒ(lambda expression)ªËíÂªÃªÆªâÙığ¹ª¢ªêªŞª»ªó¡£

	\~
	\code
	CriticalSection critSec;
	int totalWorkCount = 0;
	volatile bool stopThread = false;
	ThreadPtr th = ThreadPtr(new Thread([&]()
	{
		// note that thread function is defined exactly here 
		// and even the variables out of the scope are
		// used here, thankfully by lambda capture above.
		while (!stopThread)
		{
			CriticalSectionLock lock(critSec, true);
			do_something();
			totalWorkCount++;
		}
	});
	th->Start();
	do_something_or_wait();
	stopThread = true;
	th->Join();
	print(totalWorkCount);
	\endcode
	*/
	class Thread
	{
		friend class ThreadProcContext;

#if defined(_WIN32)
		//static void __cdecl InternalThreadProc(void* ctx);
		static DWORD __stdcall InternalThreadProc(void* ctx);
#else
		static void* InternalThreadProc(void* ctx);
#endif

#if defined(_WIN32)
		HANDLE m_handle;
#else
		pthread_t m_thread;
#endif
		// Thread ID.
		// win32: same to GetCurrentThreadID() value.
		// unix: same to pthread_t value.
		uint64_t m_ID;

		bool m_neededJoin;
	public:
		static bool m_dllProcessDetached_INTERNAL;

		/** 
		\~korean
		»ı¼ºÀÚ
		\param threadProc ÀÌ ÀÎ½ºÅÏ½º°¡ Áã°í ÀÖÀ» ½º·¹µåÀÇ ¸ŞÀÎ ÇÔ¼ö
		\param ctx threadProc¿¡ ³Ñ°ÜÁú ÆÄ¶ó¸ŞÅÍ
		\param neededJoin Join ÇÔ¼öÀÇ »ç¿ë ¿©ºÎ
		±âº»°ªÀº trueÀÔ´Ï´Ù. ¸¸¾à º» ½º·¹µå°¡ ¸ŞÀÎ ½º·¹µåº¸´Ù ¸ÕÀú Á¾·áµÊÀÌ º¸ÀåµÇ¸ç, Join ±â´ÉÀ» »ç¿ëÇÏÁö ¾ÊÀ¸½Ã·Á¸é false·Î ÁöÁ¤ÇØÁÖ½Ã¸é µË´Ï´Ù.

		\~english TODO:translate needed.
		Constructer
		\param threadProc The main function of the thread which would be held by this instance. 
		\param ctx The parameter to be sent to threadProc
		\param neededJoin Join Whether to use the Join function
		The default value is true. If this thread is to be guaranteed to end earlier than the main thread and you don¡¯t want to use the Join feature, you can set it as false. 

		\~chinese TODO:translate needed.
		?ğãùŞ?
		\paramthreadProc ó®instance?êóîÜ?ïïîÜñ«ùŞ?
		\paramctxthreadProc ??îÜ??
		\paramneededJoin JoinùŞ?îÜŞÅéÄ?Üú
		Ùù???true¡£ åıÍıÜâ?ïïÜÁ?Òöİïñ«?ïïÌÚğÄ?áÖ£¬ÔÒ?ÜôŞÅéÄJoinÍíÒö?Ê¦ì¤÷ê??öÇ?false¡£

		\~japanese TODO:translate needed.
		ßæà÷í­
		\param threadProc ª³ªÎ«¤«ó«¹«¿«ó«¹ª¬ò¥ªÃªÆª¤ªë«¹«ì«Ã«ÉªÎ«á«¤«ó??
		\param ctx threadProcªËìÚª­Ô¤ª¹«Ñ«é«á?«¿?
		\param neededJoin Join ??ªÎŞÅéÄÊ¦Üú
		ĞñÜâö·ªÏtrueªÇª¹¡£ªâª·¡¢ª³ªÎ«¹«ì«Ã«Éª¬«á«¤«ó«¹«ì«Ã«Éªèªêà»ªËğûÖõªµªìªëª³ªÈª¬ÜÁî¡ªµªìªÆ¡¢JoinÑ¦ÒöªòŞÅéÄª·ªÊª±ªìªĞfalseªËò¦ïÒª·ªÆª¯ªÀªµª¤¡£

		\~
		*/
	private:
		void Init_INTERNAL();
	public:
		// °íÀüÀû ¹æ½Ä(C function with context ptr)
		typedef void(*ThreadProc)(void* ctx);
		PROUD_API Thread(ThreadProc threadProc, void *ctx, bool neededJoin = true);

	public:
		/** 
		\~korean
		ÆÄ±«ÀÚ
		- ½º·¹µå°¡ ¹Ì½ÇÇàÁßÀÌ¸é Áï½Ã ¸®ÅÏÇÏ³ª, ½º·¹µå°¡ ÀÌ¹Ì ½ÇÇàÁßÀÌ¸é ½º·¹µå°¡ Á¾·áÇÒ ¶§±îÁö ±â´Ù¸°´Ù.

		\~english
		Destructor
		- Immediately returns if thread is not running but waits until the thread terminates if the thread is already running.

		\~chinese
		÷ò?íº¡£
		- åıÍı?ïï?Ú±?ú¼???Ø¡??ú¼Return£¬åıÍı?ïïì«??ú¼?ÔõÓğ?ïï?ò­?ò­¡£

		\~japanese
		÷ò?íº
		- «¹«ì«Ã«Éª¬Ú±?ú¼ñéªÇª¢ªìªĞòÁªÁªË«ê«¿?«óª·ªŞª¹ª¬¡¢«¹«ì«Ã«Éª¬?ªË?ú¼ñéªÇª¢ªìªĞ«¹«ì«Ã«Éª¬ğûÖõª¹ªëãÁªŞªÇÓâªÁªŞª¹¡£

		\~
		*/
		PROUD_API ~Thread();

		/** 
		\~korean
		½º·¹µå¸¦ »ı¼ºÇÑ´Ù.
		- ÀÌ¹Ì »ı¼ºÇÑ »óÅÂ¸é ¿¹¿Ü°¡ ¹ß»ıÇÑ´Ù.

		\~english
		Creates thread
		- An exeption will ocur if already created.

		\~chinese
		ßæà÷?ïï¡£
		- åıÍıì«?ßæà÷Öõ?ïï??ßæÖÇèâ¡£

		\~japanese
		«¹«ì«Ã«Éªòßæà÷ª·ªŞª¹¡£
		- ?ªËßæà÷ª·ª¿?÷¾ªÇª¢ªìªĞÖÇèâª¬?ßæª·ªŞª¹¡£

		\~
		*/
		PROUD_API void Start();

		/** 
		\~korean
		½º·¹µå°¡ Á¾·áÇÒ ¶§±îÁö ±â´Ù¸°´Ù.

		\~english
		Waits until the thread terminates

		\~chinese
		ÔõÓğ?ïï?ò­¡£

		\~japanese
		«¹«ì«Ã«Éª¬ğûÖõª¹ªëãÁªŞªÇÓâªÁªŞª¹¡£

		\~
		*/
		PROUD_API void Join();

		/** 
		\~korean
		½º·¹µå ÇÚµé

		\~english
		Thread handle

		\~chinese
		?ïïHandle¡£

		\~japanese
		«¹«ì«Ã«É«Ï«ó«É«ë

		\~
		*/
#if defined(_WIN32)
		__declspec(property(get = GetHandle)) HANDLE Handle;
#endif
		/** 
		\~korean
		½º·¹µå ÇÚµéÀ» ¾ò´Â´Ù.

		\~english
		Gets thread handle

		\~chinese
		?Ôğ?ïïHandle¡£

		\~japanese
		«¹«ì«Ã«É«Ï«ó«É«ëªòÔğªŞª¹¡£

		\~
		*/
#if defined(_WIN32)
		inline HANDLE GetHandle()
		{
			return m_handle;
		}
#else
		inline pthread_t GetHandle()
		{
			return m_thread;
		}
#endif

		/** 
		\~korean
		½º·¹µå ¾ÆÀÌµğ

		\~english
		Thread ID 

		\~chinese
		?Ôğ?ïïID¡£

		\~japanese
		«¹«ì«Ã«ÉID

		\~
		*/
#if defined(_WIN32)
		__declspec(property(get = GetID)) uint64_t ID;
#endif

		/** 
		\~korean
		½º·¹µå ¾ÆÀÌµğ¸¦ ¾ò½À´Ï´Ù.
		ÀÌ °ªÀº Proud.GetCurrentThreadID()ÀÇ °ª°ú È£È¯µË´Ï´Ù.

		\~english
		Gets thread ID.
		This value is compatible to Proud.GetCurrentThreadID() value.

		\~chinese
		?Ôğ?ïïID¡£
		This value is compatible to Proud.GetCurrentThreadID() value.

		\~japanese
		«¹«ì«Ã«ÉªÎIDªòö¢Ôğª·ªŞª¹¡£
		This value is compatible to Proud.GetCurrentThreadID() value.
		\~
		*/
		inline uint64_t GetID()
		{
			return m_ID;
		}

#if defined(_WIN32)
		bool IsAlive() const;
#endif

		/** 
		\~korean
		Static library·Î¼­ÀÇ ProudNetÀÌ DLL¿¡¼­ »ç¿ëµÇ´Â °æ¿ì 
		DllMainÀÇ Process detach case¿¡¼­ ÀÌ ¸Ş¼­µå¸¦ ²À È£ÃâÇØ¾ß ÇÑ´Ù.

		\~english
		When ProudNet is used at DLL as a ststic library, this method must be called at Process detach case of DllMain.

		\~chinese
		íÂ?Static libraryî¤DLLñéŞÅéÄProudNetîÜï×?¡£
		ìéïÒé©î¤DllMainîÜProcess detach caseñéû¼õóó®Û°Ûö¡£

		\~japanese
		Static libraryªÈª·ªÆªÎProudNetª¬DLLªÇŞÅªïªìªëíŞùê 
		DllMainªÎProcess detach caseªÇª³ªÎ«á«½«Ã«Éªòù±ªºû¼ªÓõóªµªÊª±ªìªĞªÊªêªŞª»ªó¡£

		\~
		*/
		PROUD_API static void NotifyDllProcessDetached();
	private:
		// »ç¿ëÀÚ°¡ ÀÔ·ÂÇÑ ÇÔ¼ö¿Í µ¥ÀÌÅÍ (°íÀü)
		ThreadProc m_threadProc;
		void* m_ctx;

		//////////////////////////////////////////////////////////////////////////
		// C++11 ¹æ½Ä(lambda expression)

	private:
		// »ç¿ëÀÚ°¡ ÀÔ·ÂÇÑ ÇÔ¼ö °´Ã¼(¶÷´Ù½Ä)
		// ÁÖÀÇ: shared_ptr·Î ¹Ù²ÙÁö ¸» °Í. »ç¿ëÀÚ°¡ boost, tr1, stdlibc++ ¼±ÅÃÇÒ ¶§ shared_ptrÀÇ ±¸Çö ³»¿ëÀÌ ´Ş¶óÁú °æ¿ì ¶§¹®¿¡.
		// ÁÖÀÇ: ½ÇÃ¼ ¸â¹öÀÌ¹Ç·Î SUPPORTS_LAMBDA_EXPRESSION Á¶°Ç ¾È¿¡ ³ÖÁö ¸» °Í. ³ÖÀ¸¸é Ã£±â Èûµç ¹ö±×·Î ÀÌ¾îÁø´Ù.
		RefCount<LambdaBase_Param0<void> > m_lambdaProc;
		
#ifdef SUPPORTS_LAMBDA_EXPRESSION
	public:
		/** Constructor. Does not create a thread until Start() is called.
		\param function Your function or lambda expression. 
		\param needJoin True if you want this to wait for thread exit. No wait if set to false. */
		Thread(const std::function<void()> &function, bool needJoin = true)
#ifdef _WIN32
			:m_threadStopped(true, true)
#endif // _WIN32
		{
			m_threadProc = NULL;
			m_ctx = NULL;
			m_lambdaProc = RefCount<LambdaBase_Param0<void>>(new Lambda_Param0<void>(function));
			m_neededJoin = needJoin;
			Init_INTERNAL();
		}
#endif // SUPPORTS_LAMBDA_EXPRESSION

		//////////////////////////////////////////////////////////////////////////

	private:
#if defined(_WIN32)
		// non-win32¿¡¼­´Â pthread_joinÀÌ ¾²ÀÌ¹Ç·Î ¸·Çôµµ µÊ
		Event m_threadStopped;

	public:
		// trueÀÌ¸é CoInitialize°¡ ½º·¹µå ½ÃÀÛ½Ã È£ÃâµÈ´Ù.
		bool m_useComModel;
#endif
	};

	/** Smart pointer of thread object. */
	typedef RefCount<Thread> ThreadPtr;

	/**  @} */
}

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif
