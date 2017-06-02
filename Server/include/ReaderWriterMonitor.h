/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


ÀÌ ÇÁ·Î±×·¥ÀÇ ÀúÀÛ±ÇÀº ³ÝÅÙ¼Ç¿¡°Ô ÀÖ½À´Ï´Ù.
ÀÌ ÇÁ·Î±×·¥ÀÇ ¼öÁ¤, »ç¿ë, ¹èÆ÷¿¡ °ü·ÃµÈ »çÇ×Àº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾àÀ» µû¸£¸ç,
°è¾àÀ» ÁØ¼öÇÏÁö ¾Ê´Â °æ¿ì ¿øÄ¢ÀûÀ¸·Î ¹«´Ü »ç¿ëÀ» ±ÝÁöÇÕ´Ï´Ù.
¹«´Ü »ç¿ë¿¡ ÀÇÇÑ Ã¥ÀÓÀº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾à¼­¿¡ ¸í½ÃµÇ¾î ÀÖ½À´Ï´Ù.

** ÁÖÀÇ : ÀúÀÛ¹°¿¡ °üÇÑ À§ÀÇ ¸í½Ã¸¦ Á¦°ÅÇÏÁö ¸¶½Ê½Ã¿À.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


ó®ïïßíîÜ÷ú??NettentionÍëÞÉá¶êó¡£
?ó®ïïßíîÜáóËÇ¡¢ÞÅéÄ¡¢?øÖßÓ?îÜÞÀ?é©ñåáúó®ïïßíîÜá¶êó?íºîÜ??¡£
Üôñåáú???é©ê«?àõîÜÐ×ò­ôºí»ÞÅéÄ¡£
ôºí»ÞÅéÄîÜ?ìòÙ¥ãÆî¤?ó®ïïßíá¶êó?íºîÜùêÔÒ?×ì¡£

** ñ¼ëò£ºÜôé©ì¹ð¶?éÍð¤íÂÚªîÜß¾âûÙ¥ãÆ¡£


ª³ªÎ«×«í«°«é«àªÎîÊíÂ?ªÏNettentionªËª¢ªêªÞª¹¡£
ª³ªÎ«×«í«°«é«àªÎáóïá¡¢ÞÅéÄ¡¢ÛÕøÖªË?ª¹ªëÞÀú£ªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ªË?ª¤¡¢
Ìøå³ªòñåáúª·ªÊª¤íÞùê¡¢ê«öÎîÜªËÙí?ÞÅéÄªòÐ×ª¸ªÞª¹¡£
Ùí?ÞÅéÄªËªèªëô¡ìòªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ßöªËÙ¥ãÆªµªìªÆª¤ªÞª¹¡£

** ñ¼ëò£ºîÊíÂÚªªË?ª¹ªëß¾ÑÀªÎÙ¥ãÆªòð¶ËÛª·ªÊª¤ªÇª¯ªÀªµª¤¡£

*/

#pragma once

#include "./CriticalSect.h"
#include "./Event.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

#if defined(_WIN32)    
	class CReaderLock_NORECURSE;
	class CWriterLock_NORECURSE;

	// ³»ºÎÀûÀ¸·Î¸¸ ¾²´Â Å¬·¡½º°í, ¼º´ÉÀ» À§ÇØ ¹ü¿ë¼ºÀ» Èñ»ýÇÑ´Ù
	// µû¶ó¼­ Àç±Í Àá±Ý ºÒÇã
	// *ÁÖÀÇ* Àç±Í Á¢±Ù½Ã °¨ÁöÇÏÁö ¾Ê°í µ¥µå¶ôÀ¸·Î ÀÌ¾îÁø´Ù!
	class CReaderWriterMonitor_NORECURSE
	{
		friend CReaderLock_NORECURSE;
		friend CWriterLock_NORECURSE;
		CriticalSection m_cs; // ÃßÈÄ¿¡´Â lock free ¾Ë°í¸®ÁòÀ¸·Î ±¸ÇöÇØ¾ß ÇÏ°Ú´Ù. ÀÏ´ÜÀº ÀÌ·¸°Ô ¸¸µç´Ù.

		int m_readerLockCount;
		int m_writerLockCount;
		uint32_t m_owningThread;
		Event m_noReaderLocked;
		Event m_noWriterLocked;

		int ReaderLock();
		void ReaderUnlock();
		void WriterLock();
		void WriterUnlock();

	public:
		CReaderWriterMonitor_NORECURSE(void);
		~CReaderWriterMonitor_NORECURSE(void);

	};

	class CReaderLock_NORECURSE
	{
		CReaderWriterMonitor_NORECURSE* m_cs;
		bool m_locked;
		int m_multipleReaderCount;
	public:
		/** 
		\~korean
		reader lock °´Ã¼¸¦ »ý¼ºÀÚ¿¡¼­ ¹Ù·Î lockÇÒ ¼ö ÀÖ´Ù.
		\param cs Àû¿ëÇÒ reader lock °´Ã¼
		\param initialLock trueÀÌ¸é »ý¼ºÀÚ¿¡¼­ ¹Ù·Î lockÇÑ´Ù. 

		\~english
		Reader lock object can be directly locked at constructor.
		\param cs reader lock object to be applied
		\param initialLock if true then constructor locks directly

		\~chinese
		Òö÷êreader lock?ßÚî¤ßæà÷íºòÁïÈlock¡£
		\param cs é©ÎÁéÄîÜreader lock?ßÚ¡£
		\param initialLock trueîÜ??ßæà÷íºòÁïÈ?ú¼lock¡£

		\~japanese
		reader lock «ª«Ö«¸«§«¯«Èªòßæà÷í­ªèªêª¹ª°«í«Ã«¯ªÇª­ªÞª¹¡£
		\param cs îêéÄª¹ªëreader lock«ª«Ö«¸«§«¯«È
		\param initialLock trueªÇª¢ªìªÐßæà÷í­ªèªêª¹ª°«í«Ã«¯ª·ªÞª¹¡£ 
		\~
		*/
		inline CReaderLock_NORECURSE(CReaderWriterMonitor_NORECURSE& cs, bool initialLock)
		{
			m_multipleReaderCount = 0;
			m_cs = &cs;
			m_locked = false;
			if (initialLock == true)
			{
				m_multipleReaderCount = m_cs->ReaderLock();
				m_locked = true;
			}
		}

		/** 
		\~korean
		ÆÄ±«ÀÚ 
		- ÀÌ¹Ì ÀÌ °´Ã¼°¡ Á¡À¯ÇÏ°í ÀÖ´ø CriticalSection ÀÌ ÀÖÀ» °æ¿ì Á¡À¯ ÇØÁ¦¸¦ ÀÚµ¿À¸·Î ÇÑ´Ù. 

		\~english
		Destructor 
		- If there is CriticalSection that is occupied by this object already then disoccupation will be performed automatically.

		\~chinese
		÷ò?íº
		- ðíî¤ó®?ßÚì«?ï¿êóîÜCriticalSectionîÜ?ý¦£¬í»?ú°ð¶ï¿êó¡£

		\~japanese
		÷ò?í­
		- ?ªËª³ªÎ«ª«Ö«¸«§«¯«Èª¬ï¿êóª·ªÆª¤ª¿CriticalSectionª¬ª¢ªëíÞùê¡¢ï¿êóú°ð¶ªòí»ÔÑªËª·ªÞª¹¡£ 
		\~
		*/
		inline ~CReaderLock_NORECURSE()
		{
			if (m_locked)
				Unlock();
		}

		/** 
		\~korean
		reader lockÀ» Á¡À¯ÇÑ´Ù.
		\return Àá±×°í ³ª¼­ ¾òÀº multiple readerÀÇ °¹¼ö 

		\~english
		Occupies reader lock
		\return number of multiple reader required after locking

		\~chinese
		ï¿êóreader lock¡£
		\return ?ïÒì¤ý¨?ÔðîÜmultiple reader??¡£

		\~japanese
		reader lockªòï¿êóª·ªÞª¹¡£
		\return «í«Ã«¯ª·ªÆª«ªéÔðª¿multiple readerªÎ?
		\~
		*/
		inline void Lock()
		{
			m_locked = true;
			m_multipleReaderCount = m_cs->ReaderLock();
		}

		inline int GetMultipleReaderCount()
		{
			return m_multipleReaderCount;
		}

		/** 
		\~korean
		reader lockÀ» Á¡À¯ ÇØÁ¦ÇÑ´Ù. 

		\~english
		Withdraws reader lock

		\~chinese
		ú°ð¶ï¿êóreader lock¡£

		\~japanese
		reader lockªòï¿êóú°ð¶ª·ªÞª¹¡£ 
		\~
		*/
		inline void Unlock()
		{
			m_cs->ReaderUnlock();
			m_locked = false;
		}
	};

	class CWriterLock_NORECURSE
	{
		CReaderWriterMonitor_NORECURSE* m_cs;
		bool m_locked;
	public:
		/** 
		\~korean
		Writer lock °´Ã¼¸¦ »ý¼ºÀÚ¿¡¼­ ¹Ù·Î lockÇÒ ¼ö ÀÖ´Ù.
		\param Àû¿ëÇÒ Writer lock °´Ã¼
		\param initialLock trueÀÌ¸é »ý¼ºÀÚ¿¡¼­ ¹Ù·Î lockÇÑ´Ù. 

		\~english
		Writer lock object can be directly locked at constructor.
		\param to_be_applied Writer lock object
		\param initialLock if true then constructor locks directly

		\~chinese
		Writer lock Ê¦ì¤÷ê?ßÚ?ßæà÷íºòÁïÈlock¡£
		\param ÎÁéÄîÜWriter lock?ßÚ¡£
		\param initialLock trueîÜ??ßæà÷íºòÁïÈ?ú¼lock¡£

		\~japanese
		Writer lock «ª«Ö«¸«§«¯«Èªòßæà÷í­ªèªêª¹ª°«í«Ã«¯ªÇª­ªÞª¹¡£
		\param îêéÄª¹ªë Writer lock«ª«Ö«¸«§«¯«È
		\param initialLock trueªÇª¢ªìªÐßæà÷í­ªèªêª¹ª°«í«Ã«¯ª·ªÞª¹¡£ 
		\~
		*/
		inline CWriterLock_NORECURSE(CReaderWriterMonitor_NORECURSE& cs, bool initialLock)
		{
			m_cs = &cs;
			m_locked = false;
			if (initialLock == true)
			{
				m_cs->WriterLock();
				m_locked = true;
			}
		}

		/** 
		\~korean
		ÆÄ±«ÀÚ 
		- ÀÌ¹Ì ÀÌ °´Ã¼°¡ Á¡À¯ÇÏ°í ÀÖ´ø CriticalSection ÀÌ ÀÖÀ» °æ¿ì Á¡À¯ ÇØÁ¦¸¦ ÀÚµ¿À¸·Î ÇÑ´Ù. 

		\~english
		Destructor
		- If there is CriticalSection that is occupied by this object already then disoccupation will be performed automatically.

		\~chinese
		÷ò?íº
		- ðíî¤ó®?ßÚì«?ï¿êóîÜCriticalSectionîÜ?ý¦£¬í»?ú°ð¶ï¿êó¡£

		\~japanese
		÷ò?íº
		- ?ªËª³ªÎ«ª«Ö«¸«§«¯«Èª¬ï¿êóª·ªÆª¤ª¿CriticalSectionª¬ª¢ªëíÞùê¡¢ï¿êóú°ð¶ªòí»ÔÑªËª·ªÞª¹¡£ 
		\~
		*/
		inline ~CWriterLock_NORECURSE()
		{
			if (m_locked)
				Unlock();
		}

		/** 
		\~korean
		Writer lockÀ» Á¡À¯ÇÑ´Ù. 

		\~english
		Occupies writer lock

		\~chinese
		ï¿êóWriter lock¡£

		\~japanese
		Writer lockªòï¿êóª·ªÞª¹¡£
		\~
		*/
		inline void Lock()
		{
			m_locked = true;
			m_cs->WriterLock();
		}

		/** 
		\~korean
		Writer lockÀ» Á¡À¯ ÇØÁ¦ÇÑ´Ù.

		\~english
		Withdraws writer lock

		\~chinese
		ú°ð¶Writer lockï¿êó¡£

		\~japanese
		Writer lockªòï¿êóú°ð¶ª·ªÞª¹¡£
		\~
		*/
		inline void Unlock()
		{
			m_cs->WriterUnlock();
			m_locked = false;
		}
	};

	enum eAccessMode
	{
		eAccessMode_None = 0,
		eAccessMode_Read = 1,
		eAccessMode_Write = 2
	};


	class CReaderWriterAccessChecker
	{
#ifdef _DEBUG
		PROUDNET_VOLATILE_ALIGN uint32_t	m_AccessThreadID;
		PROUDNET_VOLATILE_ALIGN eAccessMode m_AccessMode;
#endif // _DEBUG
	public:
		CReaderWriterAccessChecker();
		void AssertThreadID(eAccessMode eMode) const;
		void ClearThreadID() const;
	};
#endif // __GNUC__

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
