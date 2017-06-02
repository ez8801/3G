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

//#include <string> »ç¿ëÀÚ¿¡°Ô ³ëÃâµÇ´Â Çì´õ ÆÄÀÏÀº STLÀ» »ç¿ëÇÒ ¼ö ¾øÀ¸¹Ç·Î
#include "BasicTypes.h"
#include "atomic.h"
#include "PNString.h"
#include "pnmutex.h"
#include "ClassBehavior.h"

#if !defined(_WIN32)
    #include <pthread.h>
    #include <time.h>
#endif

#if defined(_MSC_VER) && defined(_WIN32)
#pragma comment(lib,"dbghelp.lib") // Lock_Interval¿¡¼­ MiniDumpWriteDump¸¦ ¾²±â ¶§¹®¿¡.
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	class CriticalSection_BottleneckDetector;
	class CriticalSection_Standard;

	uint32_t GetAppropriateSpinCount();

	/** parameters for critical section initialization.
	*/
	class CriticalSectionSettings
	{
	public:
		/// spin count. will be set to appropriate value by default.
		/// This value will be set to 0 if only one CPU core is being used.
		uint32_t m_spinCount;

		/**
		\~korean
		º´¸ñ ¹ß»ı½Ã ´ıÇÁ ÆÄÀÏÀ» ÀúÀåÇÒ ÀÌ¸§À» ¼³Á¤ÇÕ´Ï´Ù.
		(ex. L"example_dump_file_name/")
		\~english
		Select the name to save the dump file when bottleneck occurs. 
		(ex. L"example_dump_file_name/")

		\~chinese

		\~japanese
		«Ü«Ã«È«ë«Í«Ã«¯ª¬?ßæãÁ¡¢«À«ó«×«Õ«¡«¤«ëªòÜÁğíª¹ªëÙ£îñªòàâïÒª·ªŞª¹¡£
		(ex. L"example_dump_file_name/")

		\~
		*/
		String m_bottleneckWarningDumpFileName;

		/**
		\~korean
		º´¸ñ ¹ß»ı½Ã ´ıÇÁ ÆÄÀÏÀ» ÀúÀåÇÒ °æ·Î¸¦ ¼³Á¤ÇÕ´Ï´Ù.
		(ex. L"C:/")
		\~english
		Set the path to save the dump file when bottleneck occurs. 
		(ex. L"C:/")

		\~chinese

		\~japanese
		«Ü«Ã«È«ë«Í«Ã«¯ª¬?ßæãÁ¡¢«À«ó«×«Õ«¡«¤«ëªòÜÁğíª¹ªë?ÖØªòàâïÒª·ªŞª¹¡£
		(ex. L"C:/")


		\~
		*/
		String m_bottleneckWarningDumpFilePath;

		/**
		\~korean
		°æ°í°¡ ¹ß»ıÇÒ¶§ÀÇ ÃÖ´ë ½Ã°£°ªÀ» ¼³Á¤ÇÕ´Ï´Ù.
		ÇØ´ç°ªÀÌ 0 ÀÌ¿ÜÀÇ °ªÀ¸·Î ¼¼ÆÃµÇ¸é NetServer ³»ºÎ¿¡¼­ ÇØ´ç °ª ¸¸Å­ º´¸ñ ¹ß»ı½Ã °æ°í¿Í ´ıÇÁ ÆÄÀÏÀ» ³²±é´Ï´Ù.
		\~english
		Set the maximum time value when a warning occurs. 
		When the value is set for a value other than 0, it leaves a warning and a dump file when bottleneck occurs equal to the value inside NetServer.  

		\~chinese

		\~japanese
		ÌíÍ±ª¬?ßæª¹ªëãÁªÎõÌÓŞãÁÊàö·ªòàâïÒª·ªŞª¹¡£
		ú±?ö·ª¬0ì¤èâªÎö·ªÇàâïÒªµªìªìªĞ¡¢NetServer?İ»ªÇú±?ö·ªÀª±«Ü«Ã«È«ë«Í«Ã«¯ª¬?ßæãÁªËÌíÍ±ªÈ«À«ó«×«Õ«¡«¤«ëªò?ª·ªŞª¹¡£

		\~
		*/
		uint32_t m_bottleneckWarningThresholdMs;

		/** If you this value to true,
		Proud.CriticalSection.GetLastLockedThreadID() is valid. */
		bool m_updateLastLockedThreadID;

		CriticalSectionSettings();
	};


	class CriticalSection_BottleneckDetector;
	// _BottleneckDetectorAwareLock ¹İÈ¯°ª
	class LockBottleneckDetectorResult
	{
	public:
		LockResult m_lockResult;
		uint64_t m_owningThread; // lockÀ» ¼º°ø½ÃÅ² ½º·¹µåÀÇ ID. pthread_t or win32 thread ID´Ù.
	};



	/** \addtogroup util_group
	*  @{
	*/
	/**
	\~korean
	Critical section Å¬·¡½º
	- MFCÀÇ CCriticalSectionº¸´Ù ±â´ÉÀÌ ´õ º¸°­µÇ¾î ÀÖ´Ù.
	- Æ¯È÷ (SMP È¯°æ¿¡¼­) thread sleep state¸¦ ÃÖ´ëÇÑ ÁÙÀÌ±â À§ÇØ ±âº»ÀûÀ¸·Î spin lockÀÌ ¼³Á¤µÇ¾î ÀÖ´Ù.
	ÀÏ¹İÀû ¿ëµµ
	- CriticalSection °´Ã¼¸¦ ¸ÕÀú ¸¸µç ÈÄ, CriticalSectionLock °´Ã¼¸¦ ÅëÇØ critical section lock & unlockÀ» ÇÒ ¼ö ÀÖ´Ù.

	\~english
	Critical section (class)
	- More fortified features than CCriticalSection of MFC environment
	- A spin lock is set as default in order to minimize thread sleep state under SMP environment.
	General usage
	- It is possible to perform critical section lock/unlock through CriticalSectionLock object after creating it.

	\~chinese
	Critical section?
	- İïMFCîÜ CCriticalSection%ÍíÒöÊ¥Ë­Öõ¡£
	- ÷å?ãÀ£¨SMP?ÌÑù»£©?Öõ÷êthread sleep stateõÌÓŞïïÓø?á´£¬ĞñÜâÔ´?öÇÖõspin lock¡£
	ìéÚõéÄÔ²
	à»÷êCriticalSection?ßÚ?Ëïı¨£¬÷×?CriticalSectionLock?ßÚÊ¦ì¤critical section lock & unlock¡£

	\~japanese
	Critical section «¯«é«¹
	- MFCªÎCCriticalSectionªèªêÑ¦Òöª¬ªâªÃªÈÜÍ?ªµªìªÆª¤ªŞª¹¡£
	- ÷åªË(SMPü»ÌÑªÇ)¡¢thread sleep stateªòõÌÓŞùÚªËÊõªéª¹ª¿ªáªËĞñÜâîÜªËspin lockª¬àâïÒªµªìªÆª¤ªŞª¹¡£
	ìéÚõîÜªÊéÄÔ²
	- CriticalSection «ª«Ö«¸«§«¯«Èªòà»ªËíÂªÃª¿ı­¡¢CriticalSectionLock «ª«Ö«¸«§«¯«Èªò÷×ª¸critical section lock & unlockªòú¼ª¦ª³ªÈª¬ªÇª­ªŞª¹¡£

	\~
	 */
	class CriticalSection
	{
        //String m_name;
		uint32_t m_validKey;

		CriticalSectionSettings m_settings;

		CriticalSection_Standard* m_standard;

		// 0: ´ıÇÁ ¾È ³²±â´Â Áß, 1: ´ıÇÁ ³²±â°í ÀÖ´Â Áß
		CriticalSection_BottleneckDetector* m_bottleneckDetector;
	public:
		/** Initializes a critical section object. */
        PROUD_API CriticalSection();

		/** Initializes a critical section object. */
		PROUD_API CriticalSection(CriticalSectionSettings &settings);

	private:
		void _Initialize(CriticalSectionSettings &settings);
		void _Uninitialize();

		void _BottleneckDetectorAwareLock(int32_t timeout, LockBottleneckDetectorResult& result);

		void Lock_internal();
		inline bool IsBottleneckWarningEnabled()
		{
			return (bool)(m_settings.m_bottleneckWarningThresholdMs > 0);
		}

		bool IsOwningThreadAlive() const;

	public:
		/**
		\~korean
		ÆÄ±«ÀÚ
		- ÆÄ±«ÇÏ±â Àü¿¡, ÀÌ critical sectionÀ» Á¡À¯ÇÏ°í ÀÖ´Â ½º·¹µå°¡ ¾ø¾î¾ß ÇÑ´Ù!
		\~english
		Destroyer
		- There must be no thread occupying the critical section before the desruction.
		\~chinese
		÷ò?íº
		- ÷ò?ñıîñ£¬ÜôÒöêóï¿êóó®critical sectionîÜ?ïï£¡
		\~japanese
		÷ò?í­
		- ÷ò?ª¹ªëîñªË¡¢ª³ªÎcritical sectionªòï¿êóª·ªÆª¤ªë«¹«ì«Ã«Éª¬ª¢ªÃªÆªÏª¤ª±ªŞª»ªó!
		\~
		  */
		PROUD_API ~CriticalSection(void);

		/**
		\~korean
		critical sectionÀ» ÀÌ ¸Ş¼­µå¸¦ È£ÃâÇÏ´Â ½º·¹µå°¡ Á¡À¯ÇÑ´Ù.
		Àß¸øµÈ È£ÃâÀÌ ÀÏ¾î³µÀ» ½Ã MessageBox¸¦ ¶ç¿öÁİ´Ï´Ù.
		\~english
		The critical section is to be occupied by the thread calling this method.
		\~chinese
		û¼Ğ£ó®Û°ÛöîÜ?ïïï¿êócritical section¡£
		?ßæ??û¼Ğ£?öè?MessageBox¡£
		\~japanese
		\~
		 */
		PROUD_API void Lock();

		/**
		\~korean
		critical sectionÀ» ÀÌ ¸Ş¼­µå¸¦ È£ÃâÇÏ´Â ½º·¹µå°¡ Á¡À¯ÇÑ´Ù.
		Àß¸øµÈ È£ÃâÀÌ ÀÏ¾î³µÀ» ½Ã ¾Æ¹« Ã³¸®ÇÏÁö ¾Ê°í ³Ñ¾î°©´Ï´Ù.
		\~english TODO:translate needed.
		The critical section is to be occupied by the thread calling this method.
		\~chinese
		û¼Ğ£ó®Û°ÛöîÜ?ïïï¿êócritical section¡£
		?ßæ??îÜû¼?Üôñ®ìòù¼?×â¡£
		\~japanese
		critical sectionªòª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª¹«¹«ì«Ã«Éª¬ï¿êóª·ªŞª¹¡£
		ÊàêŞªÃª¿û¼ªÓõóª·ª¬?ßæª·ª¿ãÁ¡¢MessageBoxªòøúãÆª·ªŞª¹¡£
		\~
		 */
		PROUD_API void UnsafeLock();

		/**
		\~korean
		critical sectionÀ» ÀÌ ¸Ş¼­µå¸¦ È£ÃâÇÏ´Â ½º·¹µå°¡ Á¡À¯ ÇØÁ¦ÇÑ´Ù.
		\~english
		The critical section is to be relieved by the thread calling this method.
		\~chinese
		û¼Ğ£ó®Û°ÛöîÜ?ïïú°ğ¶ï¿êócritical section¡£
		\~japanese
		critical sectionªòª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª¹«¹«ì«Ã«Éª¬ï¿êóú°ğ¶ª·ªŞª¹¡£
		\~
		 */
		PROUD_API void Unlock();

		/**
		\~korean
		EnterCriticalSection ´ë½Å TryEnterCriticalSectionÀ» »ç¿ëÇÑ´Ù.
		\return ¼º°øÀûÀ¸·Î Àá±İ ÇßÀ¸¸é true.
		\~english
		Use TryEnterCriticalSection rather than EnterCriticalSection.
		\return If it locked successfully, it is true.
		\~chinese
		TryEnterCriticalSectionÓÛôğEnterCriticalSectionŞÅéÄ¡£
		\return ?ïÒà÷ÍíîÜ?true¡£
		\~japanese
		EnterCriticalSectionªÎÓÛªïªêªËTryEnterCriticalSectionªòŞÅéÄª·ªŞª¹¡£
		\return «í«Ã«¯ªËà÷Ííª·ª¿ªétrue¡£
		\~
		 */
		PROUD_API bool TryLock();
		PROUD_API bool IsValid();

#ifndef _WIN32
		/** Returns pthread_mutex_t object. */
		pthread_mutex_t* GetMutexObject() const;
#endif

#ifdef PN_LOCK_OWNER_SHOWN
		/** Returns true if this is locked by current thread. */
		bool IsLockedByCurrentThread() const;

		/** Returns true if this is locked by any thread. */
		bool IsLocked() const;
#endif

		// ÀÌ °ªÀÌ trueÀÌ¸é ÆÄ±«ÀÚ¿¡¼­ ³»ºÎ °´Ã¼¸¦ ÆÄ±« ¾ÈÇÔ.
		// ÀÌ °ª ´Ù·ç±â°¡ ÇÊ¿äÇÑ °æ¿ì: ÀÌ Å¸ÀÔÀÇ Àü¿ª °´Ã¼ÀÌ°í, ÇÁ·Î¼¼½º Á¾·á½Ã, °´Ã¼ ÆÄ±« ¼ø¼­¿Í ¹«°üÇÏ°Ô ´Ù·ç°íÀÚ ÇÒ ¶§, ´©¼ö¸¦ °¨¼öÇÏ´õ¶óµµ.
		bool m_neverCallDtor;

		// Critical Section ÀÇ Setting °ªÀ» ¹Ù²Ù°í ½ÍÀ»¶§
		void Reset(CriticalSectionSettings& settings);

		void ShowErrorOnInvalidState();

		//////////////////////////////////////////////////////////////////////////
		// lockÀ» ÇÒ ¶§ context switch°¡ ¹ß»ıÇß´ÂÁö¸¦ ¾Ë ¼ö ÀÖ´Ù.
		// ¼º´É ¿¹: object poolÀ» À§ÇÑ °æ¿ì·Î »ç¿ëµÇ´Â °æ¿ì º¸Åë 700:1 Á¤µµÀÇ contentionÀ» ÀÏÀ¸Å²´Ù.

		// try-lock ¼º°ø È¸¼ö
		int m_tryLockSuccessCount;

		// try-lock ½ÇÆĞ È½¼ö. Áï ÀÏ¹İ lock È½¼ö.
		int m_tryLockFailCount;

		NO_COPYABLE(CriticalSection)


	public:
		/** returns ID of the thread where the last acquire (lock) is done.

		This value does not set to zero if last unacquire (unlock) is done.
		You must set Proud.CriticalSectionSettings.m_updateLastLockedThreadID to true before using this function.

		NOTE: on unix, this is pthread_t value. This may differ from thread ID shown in debugger.
		*/
		uint64_t GetLastLockedThreadID();

	private:
		uint64_t m_lastLockedThreadID;
	};

	//typedef RefCount<CriticalSection,false> CriticalSectionPtr;

	/**
	\~korean
	\brief CriticalSection °´Ã¼¸¦ lock accessÇÏ´Â °´Ã¼ÀÔ´Ï´Ù.
	- ÀÏ¹İÀûÀ¸·Î ·ÎÄÃ º¯¼ö·Î¼­ »ç¿ëµË´Ï´Ù. 
	- ÀÌ °´Ã¼°¡ ÆÄ±«µÉ ¶§ ÀÚµ¿À¸·Î lockÇÏ°í ÀÖ´ø critical sectionÀ» unlockÇÕ´Ï´Ù.
	\~english
	 \brief The object that 'lock accesses' CriticalSection object.
	- Usually created and used as a local variable.
	- When this object is destroyed, it automatically unlocks the critical section that was locked by this.
	\~chinese
	\brief CriticalSection ÷ê?ßÚlock accessîÜ?ßÚ¡£
	- ñ«é©ßæà÷Üâò¢??ı¨ŞÅéÄ¡£
	- ó®?ßÚù¬÷ò?îÜ?ı¦í»?unlockïálockîÜcritical section¡£
	\~japanese
	\brief CriticalSection «ª«Ö«¸«§«¯«Èªòlock accessª¹ªë«ª«Ö«¸«§«¯«È
	- ù±ªº«í?«««ë??ªÇßæà÷ª·ªÆìéªÄªÎ«¹«ì«Ã«É?ªÇªÎªßŞÅª¤ªŞª¹¡£
	- ª³ªÎ«ª«Ö«¸«§«¯«Èª¬÷ò?ªµªìªëãÁªËí»ÔÑ«í«Ã«¯ª·ªÆª¤ª¿critical sectionªòunlockª·ªŞª¹¡£
	\~

	\code
	// Example
	void foo()
	{
		CriticalSectionLock lock(critSec, true);
		... 
		
		// automatically unlocked here.
	}
	\endcode
	*/
	class CriticalSectionLock
	{
		CriticalSection* m_cs;

		// ¸î ¹øÀÇ LockÀ» È£ÃâÇß´Â°¡?
		// ÁÖÀÇ: m_csÀÇ ½ÇÁ¦ lock È½¼ö¿Í ´Ù¸¦ ¼ö ÀÖ´Ù.
		// ÀÌ °ªÀº ÀÌ CriticalSectionLock¿¡ ÀÇÇØ¼­ LockÇÑ °Íµé¸¸ Ä«¿îÆÃÇÑ´Ù.
		int m_recursionCount;

	public:
		/**
		\~korean
		critical section °´Ã¼¸¦ »ı¼ºÀÚ¿¡¼­ ¹Ù·Î lockÇÒ ¼ö ÀÖ´Ù.
		\param cs »ç¿ëÇÒ critical section °´Ã¼
		\param initialLock trueÀÌ¸é »ı¼ºÀÚ¿¡¼­ ¹Ù·Î lockÇÑ´Ù.
		\~english
		It is possible to directly lock the critical section object at constructor.
		\param cs The critical section object to use
		\param initialLock If it is true then the constructor immediately locks it.
		\~chinese
		î¤ßæà÷íºÊ¦ì¤Ø¡?lock critical section?ßÚ¡£
		\param cs é©ŞÅéÄîÜcritical section?ßÚ
		\param initialLock trueîÜ?î¤ßæà÷íºØ¡?lock¡£
		\~japanese
		critical section «ª«Ö«¸«§«¯«Èªòßæà÷í­ªÇª¹ª°«í«Ã«¯ªÇª­ªŞª¹¡£
		\param cs ŞÅéÄª¹ªë critical section «ª«Ö«¸«§«¯«È
		\param initialLock trueªÇª¢ªìªĞßæà÷í­ªÇª¹ª°«í«Ã«¯ª·ªŞª¹¡£
		\~
		 */
		inline CriticalSectionLock(CriticalSection& cs, bool initialLock)
		{
			SetCriticalSection(cs, initialLock);
		}

		/**
		\~korean
		critical sectionÀ» ³ªÁß¿¡ ¼¼ÆÃÇÒ¶§¿¡ »ç¿ëÇÒ »ı¼ºÀÚÀÔ´Ï´Ù.
		\~english
		This is constructor that using set critical section later.
		\~chinese
		ì¤ı¨?öÇcritical sectionîÜ?ı¦é©ŞÅéÄîÜßæà÷íº¡£
		\~japanese
		critical sectionªòı­ªÇàâïÒª¹ªëãÁªËŞÅª¦ßæà÷í­ªÇª¹¡£
		\~
		*/
		inline CriticalSectionLock()
		{
			m_cs = NULL;
			m_recursionCount = 0;
		}
		inline void SetCriticalSection(CriticalSection &cs,bool initialLock)
		{
			m_cs = &cs;
			m_recursionCount = 0;
			if (initialLock)
			{
				Lock();
			}
		}
		// ¾²ÀÏ ÀÏÀÌ ¾ø¾î º¸ÀÌÁö¸¸, ÇöÀç ½º·¹µå°¡ ÀÌ critsecÀ» Àá±×°í ÀÖ´Â »óÅÂÀÎÁö °Ë»ç¸¦ ÇØ¾ß ÇÒ ¶§°¡ ÀÖ¾î¼­
		// ÀÌ ÇÔ¼ö´Â Á¸ÀçÇÔ.
		inline CriticalSection* GetCriticalSection() const
		{
			return m_cs;
		}

		/**
		\~korean
		Àá±İÀÌ µÇ¾îÀÖ³ª?
		\~english
		Is it locked?
		\~chinese
		?ïÒÖõ?£¿
		\~japanese
		«í«Ã«¯ªµªìªÆª¤ªŞª¹ª«£¿
		\~
		 */
		bool IsLocked() const
		{
			assert(m_recursionCount >= 0);
			return m_recursionCount > 0;
		}

		/**
		\~korean
		ÆÄ±«ÀÚ
		- ÀÌ¹Ì ÀÌ °´Ã¼°¡ Á¡À¯ÇÏ°í ÀÖ´ø CriticalSectionÀÌ ÀÖÀ» °æ¿ì Á¡À¯ ÇØÁ¦¸¦ ÀÚµ¿À¸·Î ÇÑ´Ù.
		\~english
		Destructor
		- If there is a Critical Section occupied by this object then it automatically relieves.
		\~chinese
		÷ò?íº
		- ó®?ßÚì«?ï¿êóCriticalSectionîÜ?ı¦í»?ú°ğ¶¡£
		\~japanese
		÷ò?í­
		- ?ªËª³ªÎ«ª«Ö«¸«§«¯«Èª¬ï¿êóª·ªÆª¤ª¿CriticalSectionª¬ª¢ªëíŞùê¡¢ï¿êóú°ğ¶ªòí»ÔÑªÇú¼ª¤ªŞª¹¡£
		\~
		 */
		inline ~CriticalSectionLock()
		{
			assert(m_recursionCount >= 0);
			for ( ; m_recursionCount > 0; --m_recursionCount )
			{
				m_cs->Unlock();
			}
		}

		/**
		\~korean
		critical sectionÀ» Á¡À¯ÇÑ´Ù.
		\~english
		This occupies the critical section.
		\~chinese
		ï¿êócritical section¡£
		\~japanese
		critical sectionªòï¿êóª·ªŞª¹¡£
		\~
		 */
		inline void Lock()
		{
			m_cs->Lock();
			++m_recursionCount;
		}

		/**
		\~korean
		Try LockÀ» ¼öÇàÇÑ´Ù.
		\return CriticalSection.TryLock()°ú °°Àº °ª
		\~english
		Perform Try Lock.
		\return Same value as CriticalSection.TryLock()
		\~chinese
		?ú¼Try Lock¡£
		\return ?CriticalSection.TryLock()ìé?îÜ?¡£
		\~japanese
		Try LockªòâÄú¼ª·ªŞª¹¡£
		\return CriticalSection.TryLock()ªÈÔÒª¸ö·
		\~
		 */
		inline bool TryLock()
		{
			bool r = m_cs->TryLock();
			if ( r )
			{
				++m_recursionCount;
			}
			return r;
		}

		// ³»ºÎÀû ¿ëµµ·Î¸¸
		inline void UnsafeLock()
		{
			m_cs->UnsafeLock();
			++m_recursionCount;
		}

		/**
		\~korean
		critical sectionÀ» Á¡À¯ ÇØÁ¦ÇÑ´Ù.
		\~english
		This relieves occupied critical section.
		\~chinese
		ú°ğ¶ï¿êócritical section¡£
		\~japanese
		critical sectionªòï¿êóú°ğ¶ª·ªŞª¹¡£
		\~
		 */
		inline void Unlock()
		{
			if ( IsLocked() )
			{
				--m_recursionCount;
				m_cs->Unlock();
			}
		}

		/**
		\~korean
		¶ôÀÌ ÁßÃ¸µÈ È½¼ö¸¦ Á¶È¸ÇÑ´Ù.

		\~english
		Inquire the time that the lock is over

		\~chinese

		\~japanese
		«í«Ã«¯ª¬ñìªÊªÃª¿üŞ?ªòğÎ?ª·ªŞª¹¡£
		\~
		*/
		inline int GetRecursionCount()
		{
			assert(m_recursionCount >= 0);
			return m_recursionCount;
		}

		NO_COPYABLE(CriticalSectionLock)
	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
};

#ifdef _MSC_VER
#pragma pack(pop)
#endif
