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
#include <exception>

#include "BasicTypes.h"

#include <exception>
#include <stdio.h>
#include <stdarg.h>
#include <string>
#include "ProcHeap.h"
#include "atomic.h"
#include "StringEncoder.h"
#include "PNStringTraits.h"

#ifdef _MSC_VER // pragma warningÀº VC++Àü¿ë
#pragma warning(push)
#pragma warning(disable:4324)
#endif // __MARMALADE__

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#if (_MSC_VER>=1400)
#pragma managed(push,off)
#endif

namespace Proud
{

	/* Win32, Marmalade¿¡¼­´Â wchar_t¸¦ ¾Ö¿ëÇÏÁö¸¸ unix¿¡¼­´Â charÀ» ¾Ö¿ëÇÑ´Ù.
	char ¹®ÀÚ¿­ÀÌ UTF-8À» Ã³¸®ÇÏ±â ¶§¹®ÀÌ´Ù.
	*/
#ifdef _PNUNICODE
#define StringT2A StringW2A
#define StringA2T StringA2W
#define StringT2W(x, ...) (::Proud::String(x))
#define StringW2T(x, ...) (::Proud::String(x))
#else
#define StringT2A(x, ...) (::Proud::String(x))
#define StringA2T(x, ...) (::Proud::String(x))
#define StringT2W StringA2W
#define StringW2T StringW2A
#endif


	PROUD_API _Noreturn void ThrowInvalidArgumentException();

	/** 
	\~korean
	¹®ÀÚ¿­ Å¬·¡½º
	- ÀÌ Å¬·¡½º¸¦ Á÷Á¢ »ç¿ëÇÏÁö ¸»°í Proud.String, Proud.StringW, Proud.StringA ¸¦ ÅëÇØ ¾²´Â °ÍÀ» ±ÇÀåÇÕ´Ï´Ù.
	- ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#string" >¹®ÀÚ¿­ Å¬·¡½º</a>À» Âü°í¹Ù¶ø´Ï´Ù.

	\~english
	Text string class
	- It is recommended not to use this class directly but to use via Proud.String, Proud.StringW and Proud.StringA.
	- Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#string" >String Class</a>.

	\~chinese
	í®İ¬Íú?
	- Üôé©òÁïÈŞÅéÄó®?£¬Ëï?÷×? Proud.String, Proud.StringW,  Proud.StringA%ŞÅéÄ¡£
	- ????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#string" >Ùşí®ÖªîÜ?</a>%¡£

	\~japanese
	Ùşí®Öª«¯«é«¹
	- ª³ªÎ«¯«é«¹ªòòÁïÈŞÅªïªº¡¢Proud.String, Proud.StringW, Proud.StringAªò÷×ª¸ŞÅª¦ª³ªÈªòªª?ªáª·ªŞª¹¡£
	- ßÙª·ª¯ªÏ¡¢\ref stringªòª´?ğÎª¯ªÀªµª¤¡£
	\~
	*/
	template<typename XCHAR, typename StringTraits>
	class StringT 
	{
		// copy-on-write ¹× shared ptr ÇüÅÂ¸¦ ¸ğµÎ Á¦°øÇÑ´Ù.
		// ¹®ÀÚ¿­ ¹öÆÛ ¹Ù·Î ¾Õ´Ü¿¡ À§Ä¡ÇÑ´Ù. 
		// NOTE: TombstoneÀÌ °¡Áø ¹®ÀÚ¿­ °´Ã¼´Â ÀÏ´Ü ÇÑ¹ø ¼³Á¤µÇ°í ³ª¸é ¼Ò¸êÇÒ ¶§±îÁö ³»¿ë¹°ÀÌ Àı´ë ¹Ù²îÁö ¸»¾Æ¾ß ÇÑ´Ù.
		// ¿Ö³ÄÇÏ¸é ¿©·¯ º¯¼öµéÀÌ ÀÌ ¹®ÀÚ¿­ µ¥ÀÌÅÍ¸¦ Àá±İ ¾øÀÌ °øÀ¯ÇÏ±â ¶§¹®ÀÌ´Ù.
		// °¢ º¯¼öµéÀº ÀÚ±â°¡ °¡Áø ¹®ÀÚ¿­ µ¥ÀÌÅÍ¸¦ º¯°æÇÏ°íÀÚ ÇÏ´Â °æ¿ì 
		// º¯ÇüÇÏ´Â ¹®ÀÚ¿­ µ¥ÀÌÅÍ¸¦ ¸¸µç ÈÄ »õ tombstone¿¡ ±× ³»¿ëÀ» º¹»çÇØ ³Ö¾î¾ß ÇÑ´Ù.
		class Tombstone
		{
		public:
			// Ä³½ÌµÈ ¹®ÀÚ¿­ ±æÀÌ
			int m_length;

			// ÂüÁ¶ È½¼ö
			PROUDNET_VOLATILE_ALIGN intptr_t m_refCount;

			inline Tombstone()
			{
				m_length = 0;
				m_refCount = 1;
			}

			inline XCHAR* GetBuffer() 
			{
				return (XCHAR*)(this+1);
			}
		};

		// ¹®ÀÚ¿­ Å¬·¡½º´Â ÀÌ µ¥ÀÌÅÍ ¸â¹ö¸¸À» À¯ÀÏÇÏ°Ô °¡Á®¾ß ÇÏ¸ç vtableÀ» °¡Áú ¼ö ¾ø´Ù.
		// ±×·¡¾ß printf °è¿­¿¡¼­ °´Ã¼ ÀÚÃ¼¸¦ Á÷Á¢ ³Ö¾îµµ Àß ÀÛµ¿ÇÏ´Ï±î.
		// ÀÌ Æ÷ÀÎÅÍ°¡ °¡¸®Å°´Â ºí·° ¹Ù·Î ¾Õ¿¡ TombstoneÀÌ ÀÖ´Ù.
		XCHAR* m_strPtr; 


		void ShareFrom(const StringT& src)
		{
			if(src.m_strPtr != m_strPtr)
			{
				ReleaseTombstone();
				
				m_strPtr = src.m_strPtr;
				
				if(GetTombstone())
                {
					AtomicIncrementPtr(&GetTombstone()->m_refCount);
                }
			}
		}

		void ReleaseTombstone()
		{
			Tombstone* ts = GetTombstone();
			if(ts)
			{
				intptr_t result = AtomicDecrementPtr(&ts->m_refCount);
				if(result == 0)
				{
					CProcHeap::Free(ts);
				}
			}			
			m_strPtr = NULL;
		}

		inline Tombstone* GetTombstone() const
		{
			if(!m_strPtr)
				return NULL;

			uint8_t* ptr = (uint8_t*)m_strPtr;
			return (Tombstone*) (ptr-sizeof(Tombstone));
		}

		// strlen: szÁ¦¿ÜÇÏ°í. charÀÇ °æ¿ì ¹ÙÀÌÆ®,wchar_tÀÎ °æ¿ì ±ÛÀÚ¼ö.
		static size_t GetBlockLen( int strLen )
		{
			if(strLen<0)
				ThrowInvalidArgumentException();
			return sizeof(Tombstone) + sizeof(XCHAR) * ((size_t)strLen+1);
		}

		void PrepareCopyOnWrite()
		{
			if (GetTombstone() == NULL)
			{
				// ¾øÀ¸¸é »õ·Î ¸¸µç´Ù.
				size_t blockLen = GetBlockLen(0);
				Tombstone* ts = (Tombstone*)CProcHeap::Alloc(blockLen);
				if(ts == NULL)
					ThrowBadAllocException();

                memset(ts,0,blockLen);
				CallConstructor<Tombstone>(ts);
				m_strPtr = ts->GetBuffer();
			}
			else if(GetTombstone()->m_refCount > 1) // ´ÜÀÏ ÂüÁ¶ÀÌ¸é »çº» ¶ß´Â °ÍÀÌ ¹«ÀÇ¹ÌÇÏ´Ù.
			{
				// »çº»
				Tombstone* newTS = (Tombstone*) CProcHeap::Alloc( GetBlockLen(GetLength()));
				if( newTS == NULL )
					ThrowBadAllocException();

				CallConstructor<Tombstone>(newTS);
				newTS->m_length = GetLength();				

				// #ikpil.choi 2016-11-10 : memcpy_s ·Î º¯°æ, destSize(2¹øÂ° ÀÎÀÚ) °ªÀÌ Ç×»ó ¿Ã¹Ù¸¥ °ªÀÌ¿©¾ß ÇÕ´Ï´Ù.
				//StringTraits::CopyString(newTS->GetBuffer(), GetString(), GetLength()); // szµµ ¸¸µé¾îÁÜ.
				StringTraits::CopyString(newTS->GetBuffer(), newTS->m_length + 1, GetString(), GetLength()); // szµµ ¸¸µé¾îÁÜ.
				
				// ¿øº» ±³Ã¼
				ReleaseTombstone();

				m_strPtr = newTS->GetBuffer();
			}
		}

		inline void InitVars()
		{
			m_strPtr = NULL;
		}

		inline void ReleaseBufferSetLength(int length)
		{
			length = PNMAX(length, 0);
			length = PNMIN(length, GetLength());

			Tombstone* ts = GetTombstone();
			if (ts != NULL)
			{
				ts->m_length = length;
				ts->GetBuffer()[length] = 0; // sz mark				
			}
		}

		void Truncate( int nNewLength )
		{
			assert( nNewLength <= GetLength() );
			GetBuffer( nNewLength );
			ReleaseBufferSetLength( nNewLength );
		}

		// length: byte(char) or ±ÛÀÚ¼ö(wchar_t)
		void SetMaxLength(int length)
		{
			length = PNMAX(length, 0);
			if(length == 0)
			{
				ReleaseTombstone();
			}
			else if(length != GetLength())
			{
				// ´Ù¸¥ º¯¼ö°¡ ÂüÁ¶ ¾ÈÇÏ°í ÀÖÀ¸¸é ±×³É reallocÇÑ´Ù.
				Tombstone* ts = GetTombstone();
				if (ts != NULL && ts->m_refCount == 1)
				{
					ts = (Tombstone*)CProcHeap::Realloc(ts, GetBlockLen(length));
					ts->m_length = length;
					m_strPtr = ts->GetBuffer(); // realloc¿¡ ÀÇÇØ ts°¡ ¹Ù²ï °æ¿ì¸¦ À§ÇØ
					m_strPtr[length] = 0;	// Å©±â°¡ ÁÙ¾îµç °æ¿ì¸¦ À§ÇØ sz¸¶°¨Ã³¸®
				}
				else
				{
					// ´Ù¸¥ º¯¼ö°¡ ÂüÁ¶ÇÏ°í ÀÖÀ¸¸é ¿øº»À» °Çµå¸®¸é ¾ÈµÈ´Ù. 
					// µû¶ó¼­ Å©±â ´Ù¸¥ »çº» Áï copy on write¿Í °°Àº ÁØºñ¸¦ ÇÑ´Ù.
					Tombstone* newTS = (Tombstone*)CProcHeap::Alloc(GetBlockLen(length));
					if( newTS == NULL)
						ThrowBadAllocException();

					CallConstructor<Tombstone>(newTS);
					newTS->m_length = length;

					// #ikpil.choi 2016-11-10 : memcpy_s ·Î º¯°æ, destSize(2¹øÂ° ÀÎÀÚ) °ªÀÌ Ç×»ó ¿Ã¹Ù¸¥ °ªÀÌ¿©¾ß ÇÕ´Ï´Ù.
					//StringTraits::CopyString(newTS->GetBuffer(), GetString(), PNMIN(length,GetLength()));
					StringTraits::CopyString(newTS->GetBuffer(), newTS->m_length + 1, GetString(), PNMIN(length, GetLength()));

					// ¿øº» ±³Ã¼
					ReleaseTombstone();

					m_strPtr = newTS->GetBuffer();
				}
			}
		}

	public:
		/**
		\~korean
		»ı¼ºÀÚ

		\~english
		Constructor

		\~chinese
		ßæà÷íº

		\~japanese
		ßæà÷í­
		\~
		*/
		StringT()
		{
			InitVars();
		}

		/**
		\~korean
		ÆÄ±«ÀÚ

		\~english
		Destructor

		\~chinese
		÷ò?íº

		\~japanese
		÷ò?í­
		\~
		*/
		~StringT()
		{
			ReleaseTombstone();
		}

		/**
		\~korean
		src°¡ °¡¸®Å°´Â ¹®ÀÚ¿­À» °¡Á®¿Â´Ù.

		\~english
		Gets string that pointed by src

		\~chinese
		ÑÚ?srcá¶ò¦îÜí®İ¬Íú¡£

		\~japanese
		srcª¬ò¦ª¹Ùşí®Öªªòö¢ªê?ªßªŞª¹¡£
		\~
		*/
		inline StringT(const StringT& src)
		{
			InitVars();
			ShareFrom(src);
		}

		/**
		\~korean
		¹®ÀÚ¿­À» °¡Á®¿Â´Ù. 

		\~english
		Gets a string

		\~chinese
		ÑÚ?í®İ¬Íú¡£

		\~japanese
		Ùşí®Öªªòö¢ªê?ªßªŞª¹¡£
		\~
		*/
		StringT(const XCHAR* src, int length = 0)
		{
			InitVars();
			int len = StringTraits::SafeStringLen(src);
			
			if(length > 0)
				len = PNMIN(len, length);
			
			XCHAR* buf = GetBuffer(len);
			// #ikpil.choi 2016-11-10 : memcpy_s ·Î º¯°æ, destSize(2¹øÂ° ÀÎÀÚ) °ªÀÌ Ç×»ó ¿Ã¹Ù¸¥ °ªÀÌ¿©¾ß ÇÕ´Ï´Ù.
			//StringTraits::CopyString(buf, src, len);
			StringTraits::CopyString(buf, len + 1, src, len);

			ReleaseBuffer();
		}

		/**
		\~korean
		ºó ¹®ÀÚ¿­ÀÎ°¡? 

		\~english
		Is it an empty string ?

		\~chinese
		ãÀÍöí®İ¬Íú??

		\~japanese
		ÍöÙşí®ÖªªÇª¹ª«£¿
		\~
		*/
		inline bool IsEmpty() const
		{
			return GetLength() == 0;
		}

		inline XCHAR operator[](int offset) const
		{
			// ¿¹Àü¿¡´Â const XCHAR* ¿¡ ´ëÇÑ cast operator°¡ ÀÖ¾ú´Ù.
			// ±×·¯³ª ÀÌÁ¦´Â std.string¿¡ ´ëÇÑ cast operator°¡ µé¾î°¡¸é¼­, ±×°Ô »ç¶óÁ³´Ù.
			// ±×¸®°í ÀÌ ÇÔ¼ö°¡ Ãß°¡µÇ¾ú´Ù.
			// std.string¿¡ ´ëÇÑ cast operator°¡ ÇÊ¿äÇÑ ÀÌÀ¯´Â, »ç¿ëÀÚ¿¡°Ô std.stringÀ» Proud::String´ë½Å ¾²°Ô ÇÏ±â À§ÇÔÀÌ´Ù.
			if (offset < 0 || offset >= GetLength())
				ThrowInvalidArgumentException();

			return GetString()[offset];
		}

		/** 
		\~korean
		¹®ÀÚ¿­ µ¥ÀÌÅÍ¸¦ ÀĞÀ» ¼ö ÀÖ°Ô ÇÑ´Ù. 

		\~english
		Let's read text string data

		\~chinese
		Ê¦ì¤ŞÅĞì?ö¢í®İ¬Íú?Ëß¡£

		\~japanese
		Ùşí®Öª«Ç?«¿ªò?ªáªëªèª¦ªËª·ªŞª¹¡£
		\~
		*/
		inline const XCHAR* GetString() const 
		{
			// °ú°Å¿¡´Â, StringT::NullStringÀ» ¸®ÅÏÇß´Ù.
			// ÀÌ°Ô ¹®Á¦°¡ ÀÖ¾ú´Ù. DLL°ú EXE°£ ¿À°¡´Â API¿¡¼­ ÀÌ°ÍÀÌ µÎ ±ºµ¥ ÀÌ»ó Á¸ÀçÇÏ¸é¼­ ²¿ÀÌ´Â ¹®Á¦¿´´Ù.
			// ÀÌ ¹®Á¦¸¦ ÇØ°áÇÏ±â À§ÇØ¼­, ±×°ÍÀ» ¾²Áö ¾Ê´Â´Ù. ´ë½Å¿¡, ÀÌ·¸°Ô ¹«ÀÛÀ§·Î Àü¿ªº¯¼ö°¡ Á¸ÀçÇÏ´õ¶óµµ ¾ÈÀüÇÏ°Ô ÇÏÀÚ.
			static XCHAR nullString[1] = { 0 }; // staticÀÌ ºüÁö¸é, ÀÌ ÇÔ¼ö°¡ ³ª°¥ ¶§ ±úÁø µ¥ÀÌÅÍ°¡ µÇ¾î¹ö¸°´Ù.
			if (m_strPtr == NULL)
				return nullString;

			return m_strPtr;
		}

		// Works same to std.string.c_str function.
		inline const XCHAR* c_str() const
		{
			return GetString();
		}

		/** 
		\~korean
		¹®ÀÚ¿­ µ¥ÀÌÅÍ¸¦ ÀĞ±â ¹× ¾²±â¸¦ À§ÇØ Æ÷ÀÎÅÍ¸¦ Á¢±ÙÇÒ ¶§ ¾²´Â ¸Ş¼­µåÀÔ´Ï´Ù.
		- ÀÌ ¸Ş¼­µå¸¦ ¾²°í ³ª¼­´Â ReleaseBuffer·Î ¸¶°¨ÇØÁà¾ß ÇÕ´Ï´Ù. ÀÌ¸¦ ÆíÇÏ°Ô ÇÏ·Á¸é
		StrBufA³ª StrBufW¸¦ ¾²¸é µË´Ï´Ù.

		\~english
		Method used to access string pointer to read from and write to string data.
		- After using this method, it must be ended by calling ReleaseBuffer(). To use this easily, use Proud::StrBufA or Proud::StrBufW.

		\~chinese
		?Öõ?ö¢ûä??Ùşí®Öª?Ëß?ì»ïÈĞÎò¦??á¶ŞÅéÄîÜÛ°Ûö¡£
		- éÄó®Û°Ûöì¤ı¨ÔğéÄReleaseBuffer?áÖ¡£ßÌ?ú¼Ôğøµ××ŞÁîÜ?ŞÅéÄStrBufAûäíºStrBufW?Ê¦¡£

		\~japanese
		Ùşí®Öª«Ç?«¿ªò?ªßö¢ªê?ßöª­?ªßªÎª¿ªáªË«İ«¤«ó«¿?ªËĞÎªÅª¯ãÁªËŞÅª¦«á«½«Ã«ÉªÇª¹¡£
		- ª³ªÎ«á«½«Ã«ÉªòŞÅªÃªÆª«ªéªÏReleaseBufferªÇŞÂß¾ª²ªÆª¯ªÀªµª¤¡£ª³ªìªò?ªËª·ª¿ª¤íŞùêªÏ¡¢StrBufAªÈª«StrBufWªòŞÅª¨ªĞÕŞª¤ªÇª¹¡£
		\~ 
		\~korean »ç¿ë ¿¹½Ã
		\~english Usage example
		\~chinese ŞÅéÄÖÇí­
		\~japanese
		ŞÅéÄÖÇãÆ
		\~

		\code
        Proud::String a = L"abc";
        wchar_t* pa = a.GetBuffer(100);
        _wsprintf(pa, L"%d", 123);
        a.ReleaseBuffer();
        \endcode

		\~
		
		\~korean ´õ ³ªÀº »ç¿ë ¿¹½Ã
		\~english Better usage example
		\~chinese ÌÚû¿îÜŞÅéÄÖÇí­¡£
		\~japanese ªâªÃªÈÕŞª¤ŞÅéÄÖÇãÆ
		\~ \code
		Proud::String a = L"abc";
		Proud::StrBuf pa(a, 100);
		_wsprintf(pa, L"%d", 123);
		\endcode

		\~
		\~korean ÀĞ±â Àü¿ë »ç¿ë ¿¹½Ã
		\~english Example for read-only access
		\~chinese ñş?éÄŞÅéÄÖÇí­¡£
		\~japanese ?ªßö¢ªê?éÄŞÅéÄÖÇãÆ
		\~
		\code
		Proud::String a = L"abc";
		wchar_t* pa = a;
		\endcode
		*/
		XCHAR* GetBuffer(int length = 0)
		{
			// length´Â ÃÖ¼Ò 1±ÛÀÚ´Â ÀúÀåÇÒ ¼ö ÀÖ´Â ±â·Ï °¡´ÉÇÑ Å©±â¸¦ ¸¸µç´Ù.
			// ±×·¡¾ß »ç¿ëÀÚ°¡ À¯È¿ÇÑ ¹®ÀÚ¿­ ÁÖ¼Ò¸¦ ¾òÀ¸¹Ç·Î.
			length = PNMAX(length, GetLength());
			length = PNMAX(length, 1);

			if(GetLength() != length)
			{
				// copy-on-write with resize
				// ±âÁ¸ Å©±âº¸´Ù ÀÛÀº Å©±â¸¦ ¾òÀ¸·Á°í ÇÑ´Ù ÇÏ´õ¶óµµ, ´Ù¸¥ ½º·¹µåÀÇ ´Ù¸¥ º¯¼ö°¡ ÀÌ tombstoneÀ» °øÀ¯ÇÏ°í ÀÖÀ» °æ¿ì¿¡ ±×ÂÊµµ ¹Ù²î¸é ¾ÈµÇ¹Ç·Î
				// ÀÌ·¸°Ô copy-on-write Ã³¸®¸¦ ÇØÁÖ¾î¾ß ÇÔ.
				SetMaxLength(length);
			}
			else
			{
				// copy-on-write without resize
				PrepareCopyOnWrite();
			}

			return (XCHAR*)GetString();
		}

		/**
		\~korean
		¹®ÀÚ¿­ ±æÀÌ¸¦ ¾ò½À´Ï´Ù. 

		\~english
		Gets length of string.

		\~chinese
		?Ôğí®İ¬Íú?Óø¡£

		\~japanese
		Ùşí®ÖªªÎíşªµªòÔğªŞª¹¡£
		\~

		\return length Number of characters if wchar_t is used, number of bytes if char is used, regardless of multibyte or unicode encoding.
		*/
		int GetLength() const
		{
			if(m_strPtr == NULL)
				return 0;
			else 
				return GetTombstone()->m_length;
		}

		/** 
		\~korean
		¹®ÀÚ¿­ ±æÀÌ¸¦ ÀçÁ¶Á¤ÇÑ´Ù. 
		\param length Number of characters if wchar_t is used, number of bytes if char is used, regardless of multibyte or unicode encoding.

		\~english
		Re-modifies the length of text string
		\param length Number of characters if wchar_t is used, number of bytes if char is used, regardless of multibyte or unicode encoding.

		\~chinese
		ñìãæ?ïÚí®İ¬Íú?Óø¡£
		\param length Number of characters if wchar_t is used, number of bytes if char is used, regardless of multibyte or unicode encoding.

		\~japanese
		Ùşí®ÖªªÎíşªµªòî¢ğàïÚª·ªŞª¹¡£
		\param length Number of characters if wchar_t is used, number of bytes if char is used, regardless of multibyte or unicode encoding.
		\~

		*/
		void SetLength(int length)
		{
			length = PNMIN(length, StringTraits::SafeStringLen(GetString()) );
			SetMaxLength(length);
		}

		/** 
		\~korean
		¹®ÀÚ¿­ µÚ¿¡ ´Ù¸¥ ¹®ÀÚ¿­À» µ¡ºÙÀÎ´Ù. 

		\~english
		Adds another text string after text string

		\~chinese
		èÙí®İ¬Íúı¨ØüôÕÊ¥Ğìöâí®İ¬Íú¡£

		\~japanese
		Ùşí®ÖªªÎı­ªËöâªÎÙşí®ÖªªòÜõª±Ê¥ª¨ªŞª¹¡£
		\~
		*/
		inline void Append(const StringT& src)
		{
			if(src.GetLength() > 0)
			{
				int oldLen = GetLength();
				XCHAR* buf = GetBuffer(oldLen + src.GetLength());

				// #ikpil.choi 2016-11-10 : memcpy_s ·Î º¯°æ, destSize(2¹øÂ° ÀÎÀÚ) °ªÀÌ Ç×»ó ¿Ã¹Ù¸¥ °ªÀÌ¿©¾ß ÇÕ´Ï´Ù.
				//StringTraits::CopyString(buf + oldLen, src.GetString(), src.GetLength() );
				StringTraits::CopyString(buf + oldLen, src.GetLength() + 1, src.GetString(), src.GetLength());
				ReleaseBufferSetLength(oldLen + src.GetLength());
			}
		}

		/** 
		\~korean
		¹®ÀÚ¿­ µÚ¿¡ ´Ù¸¥ ¹®ÀÚ¿­À» µ¡ºÙÀÎ´Ù. 

		\~english
		Adds another text string to text string

		\~chinese
		èÙí®İ¬Íúı¨ØüôÕÊ¥Ğìöâí®İ¬Íú¡£

		\~japanese
		Ùşí®ÖªªÎı­ªËöâªÎÙşí®ÖªªòÜõª±Ê¥ª¨ªŞª¹¡£
		\~
		*/
		inline void Append(const XCHAR* src)
		{
			if (src != NULL)
			{
				int srcLen = StringTraits::SafeStringLen(src);
				
				int oldLen = GetLength();
				XCHAR* buf = GetBuffer(oldLen + srcLen);

				// #ikpil.choi 2016-11-10 : memcpy_s ·Î º¯°æ, destSize(2¹øÂ° ÀÎÀÚ) °ªÀÌ Ç×»ó ¿Ã¹Ù¸¥ °ªÀÌ¿©¾ß ÇÕ´Ï´Ù.
				//StringTraits::CopyString(buf + oldLen, src, srcLen );
				StringTraits::CopyString(buf + oldLen, srcLen + 1, src, srcLen);
				ReleaseBufferSetLength(oldLen + srcLen);
			}
		}

		/** 
		\~korean
		ÀÌ °´Ã¼ÀÇ ¹®ÀÚ¿­°ú src°¡ °¡¸®Å°´Â ¹®ÀÚ¿­À» ºñ±³ÇÑ´Ù. ÀÌ °´Ã¼ÀÇ ¹®ÀÚ¿­ÀÌ ´õ '»çÀüÀû ¾Õ'ÀÌ¸é À½¼ö°¡, °°À¸¸é 0, ±×·¸Áö ¾ÊÀ¸¸é ¾ç¼ö°¡ ¸®ÅÏµÈ´Ù. 

		\~english
		Compare this objective¡¯s string to string that src indicates. If this objective¡¯s string is smaller than src, negative number will be returned (if same, 0 will be returned & if it is bigger than src, positive number will be returned).

		\~chinese
		İï?ó®?ßÚîÜí®İ¬Íúûúsrcá¶ò¦îÜí®İ¬Íú¡£åıÍıó®?ßÚîÜí®İ¬Íúİïsrcá³Ú÷üŞ??£¬ßÓÔÒÚ÷üŞ0£¬Üú?Ú÷üŞïá?¡£

		\~japanese
		ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎÙşí®ÖªªÈsrcª¬ãÆª¹Ùşí®ÖªªòİïÎòª·ªŞª¹¡£ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎÙşí®Öªª¬srcªèªêá³ªµª±ªìªĞëä?¡¢ÔÒª¸ª±ªìªĞ£°¡¢ª½ª¦ªÇªÊª±ªìªĞåÕ?ª¬«ê«¿?«óªµªìªŞª¹¡£

		\~
		*/
		inline int Compare(const StringT& src) const
		{
			XCHAR* strPtr = m_strPtr;

			if(strPtr == src.m_strPtr)
				return 0;

			return StringTraits::StringCompare(GetString(), src.GetString());
		}

		/** 
		\~korean
		ÀÌ °´Ã¼ÀÇ ¹®ÀÚ¿­°ú src°¡ °¡¸®Å°´Â ¹®ÀÚ¿­À» ºñ±³ÇÑ´Ù. ÀÌ °´Ã¼ÀÇ ¹®ÀÚ¿­ÀÌ ´õ '»çÀüÀû ¾Õ'ÀÌ¸é À½¼ö°¡, °°À¸¸é 0, ±×·¸Áö ¾ÊÀ¸¸é ¾ç¼ö°¡ ¸®ÅÏµÈ´Ù. 

		\~english
		Compare this objective¡¯s string to string that src indicates. If this objective¡¯s string is smaller than src, negative number will be returned (if same, 0 will be returned & if it is bigger than src, positive number will be returned).

		\~chinese
		İï?ó®?ßÚîÜí®İ¬Íúûúsrcá¶ò¦îÜí®İ¬Íú¡£åıÍıó®?ßÚîÜí®İ¬Íúİïsrcá³Ú÷üŞ??£¬ßÓÔÒÚ÷üŞ0£¬Üú?Ú÷üŞïá?¡£

		\~japanese
		ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎÙşí®ÖªªÈsrcª¬ãÆª¹Ùşí®ÖªªòİïÎòª·ªŞª¹¡£ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎÙşí®Öªª¬srcªèªêá³ªµª±ªìªĞëä?¡¢ÔÒª¸ª±ªìªĞ£°¡¢ª½ª¦ªÇªÊª±ªìªĞåÕ?ª¬«ê«¿?«óªµªìªŞª¹¡£

		\~
		*/
		inline int Compare(const XCHAR* src) const
		{
			return StringTraits::StringCompare(GetString(), src);
		}

		/** 
		\~korean
		ÀÌ °´Ã¼ÀÇ ¹®ÀÚ¿­°ú src°¡ °¡¸®Å°´Â ¹®ÀÚ¿­À» ºñ±³ÇÑ´Ù. ÀÌ °´Ã¼ÀÇ ¹®ÀÚ¿­ÀÌ ´õ '»çÀüÀû ¾Õ'ÀÌ¸é À½¼ö°¡, °°À¸¸é 0, ±×·¸Áö ¾ÊÀ¸¸é ¾ç¼ö°¡ ¸®ÅÏµÈ´Ù. 
		´Ü, ´ë¼Ò¹®ÀÚ ±¸º°À» ÇÏÁö ¾Ê´Â´Ù. 

		\~english
		Compare this objective¡¯s string to string that src indicates. If this objective¡¯s string is smaller than src, negative number will be returned (if same, 0 will be returned & if it is bigger than src, positive number will be returned). 
		But, not classify capital and small letter.

		\~chinese
		İï?ó®?ßÚîÜí®İ¬Íúûúsrcá¶ò¦îÜí®İ¬Íú¡£åıÍıó®?ßÚîÜí®İ¬Íúİïsrcá³Ú÷üŞ??£¬ßÓÔÒÚ÷üŞ0£¬Üú?Ú÷üŞïá?¡£
		Ó££¬Üô?İÂÓŞá³í®Ù½¡£

		\~japanese
		ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎÙşí®ÖªªÈsrcª¬ãÆª¹Ùşí®ÖªªòİïÎòª·ªŞª¹¡£ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎÙşí®Öªª¬srcªèªêá³ªµª±ªìªĞëä?¡¢ÔÒª¸ª±ªìªĞ£°¡¢ª½ª¦ªÇªÊª±ªìªĞåÕ?ª¬«ê«¿?«óªµªìªŞª¹¡£
		ª¿ªÀª·¡¢ÓŞá³Ùşí®ªÎ?Ü¬ªòª·ªŞª»ªó¡£
		\~
		*/
		inline int CompareNoCase(const StringT& src) const
		{
			const XCHAR* p1 = src.m_strPtr;
			const XCHAR* p2 = m_strPtr;
			if(p1==p2)
				return 0;

			return StringTraits::StringCompareNoCase(GetString(), src.GetString());
		}

		/** 
		\~korean
		ÀÌ °´Ã¼ÀÇ ¹®ÀÚ¿­°ú src°¡ °¡¸®Å°´Â ¹®ÀÚ¿­À» ºñ±³ÇÑ´Ù. ÀÌ °´Ã¼ÀÇ ¹®ÀÚ¿­ÀÌ ´õ '»çÀüÀû ¾Õ'ÀÌ¸é À½¼ö°¡, °°À¸¸é 0, ±×·¸Áö ¾ÊÀ¸¸é ¾ç¼ö°¡ ¸®ÅÏµÈ´Ù. 
		´Ü, ´ë¼Ò¹®ÀÚ ±¸º°À» ÇÏÁö ¾Ê´Â´Ù. 

		\~english
		Compare this objective¡¯s string to string that src indicates. If this objective¡¯s string is smaller than src, negative number will be returned (if same, 0 will be returned & if it is bigger than src, positive number will be returned). 
		But, not classify capital and small letter.

		\~chinese
		İï?ó®?ßÚîÜí®İ¬Íúûúsrcá¶ò¦îÜí®İ¬Íú¡£åıÍıó®?ßÚîÜí®İ¬Íúİïsrcá³Ú÷üŞ??£¬ßÓÔÒÚ÷üŞ0£¬Üú?Ú÷üŞïá?¡£
		Ó££¬Üô?İÂÓŞá³í®Ù½¡£

		\~japanese
		ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎÙşí®ÖªªÈsrcª¬ãÆª¹Ùşí®ÖªªòİïÎòª·ªŞª¹¡£ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎÙşí®Öªª¬srcªèªêá³ªµª±ªìªĞëä?¡¢ÔÒª¸ª±ªìªĞ£°¡¢ª½ª¦ªÇªÊª±ªìªĞåÕ?ª¬«ê«¿?«óªµªìªŞª¹¡£
		ª¿ªÀª·¡¢ÓŞá³Ùşí®ªÎ?Ü¬ªòª·ªŞª»ªó¡£
		\~
		*/
		inline int CompareNoCase(const XCHAR* src) const
		{
			return StringTraits::StringCompareNoCase(GetString(),src);
		}

		/**
		\~korean
		Format ¸Ş¼Òµå¿Í ¶È°°Àº ±â´ÉÀ» ÇÏÁö¸¸, static ¸Ş¼ÒµåÀÌ¸ç »õ·Î¿î °´Ã¼¸¦ ¸®ÅÏÇÑ´Ù.

		\~english
		It performs the same function as the Format method, but it is a static method and returns a new object. 

		\~chinese
		?Format Û°ÛöîÜÍíÒößÓÔÒ£¬Ó£?ãÀ??Û°ÛöÚ÷üŞãæ?ßÚ¡£

		\~japanese
		Format«á«½«Ã«ÉªÈÔÒª¸Ñ¦Òöªòª·ªŞª¹ª¬¡¢static«á«½«Ã«ÉªÇãæª·ª¤«ª«Ö«¸«§«¯«Èªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		static inline StringT NewFormat(const XCHAR* pszFormat, ...)
		{
			assert(pszFormat != NULL);

			StringT ret;

			va_list argList;
			va_start(argList, pszFormat);
			ret.FormatV(pszFormat, argList);
			va_end(argList);

			return ret;
		}

		/** 
		\~korean
		printf Ã³·³ ¹®ÀÚ¿­À» ¸¸µç´Ù. ( <a target="_blank" href="http://guide.nettention.com/cpp_ko#string_format" >¹®ÀÚ¿­ ¸¸µé±â ±â´É(format)</a>  Âü°í) 

		\~english
		Creates text string as printf (Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#string_format" >Creating a string(format)</a>)

		\~chinese
		ßÀprintfìé??Ëïí®İ¬Íú¡££¨?ÍÅ <a target="_blank" href="http://guide.nettention.com/cpp_zh  #string_format" >?ËïÙşí®ÖªîÜÍíÒö¡£(format)</a>£©

		\~japanese
		printf ªÎªèª¦ªËÙşí®ÖªªòíÂªêªŞª¹¡£ ( \ref string_format ?ÍÅ) 
		\~
		*/
		inline void Format( const XCHAR* pszFormat, ... )
		{
			assert( pszFormat != NULL );

			va_list argList;
			va_start( argList, pszFormat );
			FormatV( pszFormat, argList );
			va_end( argList );
		}

		/** 
		\~korean
		printf Ã³·³ ¹®ÀÚ¿­À» ¸¸µç´Ù. (  <a target="_blank" href="http://guide.nettention.com/cpp_ko#string_format" >¹®ÀÚ¿­ ¸¸µé±â ±â´É(format)</a> Âü°í) 

		\~english
		Creates text string as printf (Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#string_format" >Creating a string(format)</a>)

		\~chinese
		ßÀprintfìé??Ëïí®İ¬Íú¡££¨?ÍÅ <a target="_blank" href="http://guide.nettention.com/cpp_zh  #string_format" >?ËïÙşí®ÖªîÜÍíÒö¡£(format)</a>£©

		\~japanese
		printf ªÎªèª¦ªËÙşí®ÖªªòíÂªêªŞª¹¡£ ( \ref string_format ?ÍÅ) 
		\~
		*/
		void FormatV( const XCHAR* pszFormat, va_list args )
		{
			assert( pszFormat != NULL );

			if(pszFormat == NULL)
            {
				ThrowInvalidArgumentException();
            }

			int nLength = StringTraits::GetFormattedLength(pszFormat, args) + 1;
			
			XCHAR* buf = GetBuffer(nLength);
			StringTraits::Format(buf, nLength, pszFormat, args);
			buf[nLength] = 0;

			ReleaseBuffer();
		}

		/** 
		\~korean
		GetBuffer¸¦ È£ÃâÇßÀ¸¸é ÀÌ°É·Î ¸¶¹«¸®¸¦ ÇØÁà¾ß ÇÑ´Ù. ¾È±×·¯¸é ¹®ÀÚ¿­ ±æÀÌ¸¦ Á¤È®ÇÏ°Ô °¡ÁöÁö ¸øÇÒ ¼ö ÀÖ´Ù.
		ÀÚ¼¼ÇÑ °ÍÀº GetBuffer ¼³¸í Âü°í. 

		\~english
		Once GetBuffer is called then this must end to finalize. Otherwise, the exact length of text string may not be acquired.
		Please refer GetBuffer description

		\~chinese
		û¼Ğ£GetBufferîÜ?é©ì¤ó®?áÖ¡£Üú?êóÊ¦ÒöÜôÒöïá??êóí®İ¬Íú?Óø¡£
		????ÍÅGetBuffer?Ù¥¡£

		\~japanese
		GetBufferªòû¼ªÓõóª·ª¿ªé¡¢ª³ªìªÇŞÂß¾ª²ªëù±é©ª¬ª¢ªêªŞª¹¡£ª½ª¦ª·ªÊª±ªìªĞ¡¢Ùşí®ÖªªÎíşªµªòïáü¬ªËò¥ªÄª³ªÈª¬ªÇª­ªÊª¤ª«ªâò±ªìªŞª»ªó¡£
		ßÙª·ª¯ªÏ¡¢GetBuffer?Ù¥ªòª´?ğÎª¯ªÀªµª¤¡£
		\~
		*/
		inline void ReleaseBuffer()
		{
			ReleaseBufferSetLength(StringTraits::SafeStringLen(GetString()));
		}

		/** 
		\~korean
		¹®ÀÚ¿­ Áß chOld°¡ °¡¸®Å°´Â ±ÛÀÚ¸¦ chNew ·Î ¹Ù²Û´Ù. 

		\~english
		Among text strings, replace the character pointed by chOld with the character pointed by chNew.

		\~chinese
		?í®İ¬ÍúñéchOldá¶ò¦îÜí®ôğ?à÷chNew¡£

		\~japanese
		Ùşí®ÖªªÎª¦ªÁchOldª¬ò¦ª¹Ùşí®ªòchNewªË?ª¨ªŞª¹¡£
		\~
		*/
		int Replace( XCHAR chOld, XCHAR chNew )
		{
			int nCount = 0;

			// short-circuit the nop case
			if( chOld != chNew )
			{
				// otherwise modify each character that matches in the string
				bool bCopied = false;
				XCHAR* pszBuffer = const_cast< XCHAR* >( GetString() );  // We don't actually write to pszBuffer until we've called GetBuffer().

				int nLength = GetLength();
				int iChar = 0;
				while( iChar < nLength )
				{
					// replace instances of the specified character only
					if( pszBuffer[iChar] == chOld )
					{
						if( !bCopied )
						{
							bCopied = true;
							pszBuffer = GetBuffer( nLength );
						}
						pszBuffer[iChar] = chNew;
						nCount++;
					}
					iChar = int( StringTraits::CharNext( pszBuffer+iChar )-pszBuffer );
				}
				if( bCopied )
				{
					ReleaseBufferSetLength( nLength );
				}
			}

			return( nCount );
		}

		/** 
		\~korean
		¹®ÀÚ¿­ Áß pszOld°¡ °¡¸®Å°´Â ¹®ÀÚ¿­À» pszNew ·Î ¹Ù²Û´Ù. 

		\~english
		Among text strings, replace the character pointed by pszOld with the character pointed by pszNew.

		\~chinese
		?í®İ¬ÍúñépszOldá¶ò¦îÜí®ôğ?à÷pszNew¡£

		\~japanese
		Ùşí®ÖªªÎª¦ªÁpszOldª¬ò¦ª¹Ùşí®ÖªªòpszNewªË?ª¨ªŞª¹¡£
		\~
		*/
		int Replace( const XCHAR* pszOld, const XCHAR* pszNew )
		{
			// can't have empty or NULL lpszOld

			// nSourceLen is in XCHARs
			int nSourceLen = StringTraits::SafeStringLen( pszOld );
			if( nSourceLen == 0 )
				return( 0 );
			// nReplacementLen is in XCHARs
			int nReplacementLen = StringTraits::SafeStringLen( pszNew );

			// loop once to figure out the size of the result string
			int nCount = 0;
			{
				const XCHAR* pszStart = GetString();
				const XCHAR* pszEnd = pszStart+GetLength();
				while( pszStart < pszEnd )
				{
					const XCHAR* pszTarget;
					while( (pszTarget = StringTraits::StringFindString( pszStart, pszOld ) ) != NULL)
					{
						nCount++;
						pszStart = pszTarget+nSourceLen;
					}
					pszStart += StringTraits::SafeStringLen( pszStart )+1;
				}
			}

			// if any changes were made, make them
			if( nCount > 0 )
			{
				// if the buffer is too small, just
				//   allocate a new buffer (slow but sure)
				int nOldLength = GetLength();
				int nNewLength = nOldLength+(nReplacementLen-nSourceLen)*nCount;

				XCHAR* pszBuffer = GetBuffer( PNMAX( nNewLength, nOldLength ) );

				XCHAR* pszStart = pszBuffer;
				XCHAR* pszEnd = pszStart+nOldLength;

				// loop again to actually do the work
				while( pszStart < pszEnd )
				{
					XCHAR* pszTarget;
					while( (pszTarget = StringTraits::StringFindString( pszStart, pszOld ) ) != NULL )
					{
						int nBalance = nOldLength-int(pszTarget-pszBuffer+nSourceLen);
#if (_MSC_VER>=1400)
						memmove_s( pszTarget+nReplacementLen, nBalance*sizeof( XCHAR ), 
							pszTarget+nSourceLen, nBalance*sizeof( XCHAR ) );
						memcpy_s( pszTarget, nReplacementLen*sizeof( XCHAR ), 
							pszNew, nReplacementLen*sizeof( XCHAR ) );
#else
						memmove( pszTarget+nReplacementLen,
							pszTarget+nSourceLen, nBalance*sizeof( XCHAR ) );
						memcpy( pszTarget, 
							pszNew, nReplacementLen*sizeof( XCHAR ) );
#endif
						pszStart = pszTarget+nReplacementLen;
						pszTarget[nReplacementLen+nBalance] = 0;
						nOldLength += (nReplacementLen-nSourceLen);
					}
					pszStart += StringTraits::SafeStringLen( pszStart )+1;
				}
				assert( pszBuffer[nNewLength] == 0 );
				ReleaseBufferSetLength( nNewLength );
			}

			return( nCount );
		}

		/** 
		\~korean
		¹®ÀÚ¿­À» ´ë¹®ÀÚÈ­ÇÑ´Ù. 

		\~english
		Capitalizes text string

		\~chinese
		?í®İ¬ÍúÓŞ?í®Ù½ûù¡£

		\~japanese
		Ùşí®ÖªªòÓŞÙşí®ûùª·ªŞª¹¡£
		\~
		*/
		inline StringT& MakeUpper()
		{
			int nLength = GetLength();
			XCHAR* pszBuffer = GetBuffer( nLength );
			StringTraits::StringUppercase( pszBuffer, nLength+1 );
			ReleaseBufferSetLength( nLength );

			return( *this );
		}

		/** 
		\~korean
		¹®ÀÚ¿­À» ¼Ò¹®ÀÚÈ­ÇÑ´Ù. 

		\~english
		De-capitalize text string

		\~chinese
		?í®İ¬Íúá³?í®Ù½ûù¡£

		\~japanese
		Ùşí®ÖªªòÓŞÙşí®ûùª·ªŞª¹¡£
		\~
		*/
		inline StringT& MakeLower()
		{
			int nLength = GetLength();
			XCHAR* pszBuffer = GetBuffer( nLength );
			StringTraits::StringLowercase( pszBuffer, nLength+1 );
			ReleaseBufferSetLength( nLength );

			return( *this );
		}

		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ 

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		inline bool operator==(const StringT &src) const
		{
			return Compare(src) == 0;
		}

		inline bool operator<(const StringT& src) const
		{
			return Compare(src) < 0;
		}

		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ 

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		inline bool operator!=(const StringT& src) const
		{
			return Compare(src) != 0;
		}

		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ 

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		inline bool operator==(const XCHAR* src) const
		{
			return Compare(src) == 0;
		}

		/** 
		\~korean
		ºñ±³ ¿¬»êÀÚ 

		\~english
		Comparison operator

		\~chinese
		İï??ß©İ¬¡£

		\~japanese
		İïÎòæÑß©í­
		\~
		*/
		inline bool operator!=(const XCHAR* src) const
		{
			return Compare(src) != 0;
		}

		/** 
		\~korean
		¹®ÀÚ¿­ µ¡ºÙÀÌ±â ¿¬»êÀÚ 

		\~english
		Text string adding operator

		\~chinese
		í®İ¬ôÕÊ¥Íú?ß©İ¬¡£

		\~japanese
		Ùşí®ÖªÜõª±Ê¥ª¨æÑß©í­
		\~
		*/
		inline StringT& operator+=(const StringT& src)
		{
			Append(src);
			return *this;
		}

		/** 
		\~korean
		¹®ÀÚ¿­ µ¡ºÙÀÌ±â ¿¬»êÀÚ 

		\~english
		Text string adding operator

		\~chinese
		í®İ¬ÍúôÕÊ¥?ß©İ¬¡£

		\~japanese
		Ùşí®ÖªÜõª±Ê¥ª¨æÑß©í­
		\~
		*/
		inline StringT& operator+=(const XCHAR* src)
		{
			Append(src);
			return *this;
		}

		/** 
		\~korean
		¹®ÀÚ¿­ º¹»ç ´ëÀÔ ¿¬»êÀÚ 

		\~english
		String copy assignment operator

		\~chinese
		í®İ¬Íú?ğ¤?ß©İ¬¡£

		\~japanese
		Ùşí®Öª«³«Ô?ÓÛìıæÑß©í­
		\~
		*/
		inline StringT& operator=(const StringT& src)
		{
			ShareFrom(src);
			return *this;
		}

		/** 
		\~korean
		¹®ÀÚ¿­ º¹»ç ´ëÀÔ ¿¬»êÀÚ 

		\~english
		String copy assignment operator

		\~chinese
		í®İ¬Íú?ğ¤?ß©İ¬¡£

		\~japanese
		Ùşí®Öª«³«Ô?ÓÛìıæÑß©í­
		\~
		*/
		inline StringT& operator=(const XCHAR* src)
		{
			StringT r(src);
			ShareFrom(r);
			return *this;
		}

		/** 
		\~korean
		¹®ÀÚ¿­ÀÇ iStart ¹øÂ° Ä³¸¯ÅÍºÎÅÍ °Ë»öÇØ¼­ ch °¡ °¡¸®Å°´Â ±ÛÀÚÀÇ À§Ä¡¸¦ Ã£´Â´Ù. ¸øÃ£À¸¸é -1À» ¸®ÅÏÇÑ´Ù. 

		\~english
		Finds the location of the character that is pointed by ch through searching from 'iStart'th character of text string. Returns -1 when not found.

		\~chinese
		?í®İ¬ÍúîÜğ¯iStart?ÊÇßä?ã·â¤ßã£¬??chá¶ò¦îÜí®îÜêÈöÇ¡£?êó?ÓğîÜ?Ú÷üŞ-1¡£

		\~japanese
		Ùşí®ÖªªÎiStartÛãÙÍªÎ«­«ã«é«¯«¿?ª«ªé?ßãª·ªÆchª¬ò¦ª¹Ùşí®ªÎêÈöÇªò÷®ª·ªŞª¹¡£÷®ª»ªÊª±ªìªĞ-1ªò«ê«¿?«óª·ªŞª¹¡£ 
		\~
		*/
		int Find( XCHAR ch, int iStart = 0 ) const throw()
		{
			// iStart is in XCHARs
			assert( iStart >= 0 );

			// nLength is in XCHARs
			int nLength = GetLength();
			if( iStart < 0 || iStart >= nLength)
			{
				return( -1 );
			}

			// find first single character
			const XCHAR* psz = StringTraits::StringFindChar( GetString()+iStart, ch );

			// return -1 if not found and index otherwise
			return( (psz == NULL) ? -1 : int( psz-GetString() ) );
		}

		/** 
		\~korean
		¹®ÀÚ¿­ÀÇ iStart ¹øÂ° Ä³¸¯ÅÍºÎÅÍ °Ë»öÇØ¼­ pszSub °¡ °¡¸®Å°´Â ¹®ÀÚ¿­ÀÇ Ã¹ ±ÛÀÚ À§Ä¡¸¦ Ã£´Â´Ù. ¸øÃ£À¸¸é -1À» ¸®ÅÏÇÑ´Ù. 

		\~english
		Finds the location of the character that is pointed by pszSub through searching from 'iStart'th character of text string. Returns -1 when not found.

		\~chinese
		?í®İ¬ÍúîÜğ¯iStart?ÊÇßä?ã·â¤ßã£¬??pszSubá¶ò¦îÜí®İ¬ÍúîÜğ¯ìé?í®êÈöÇ¡£?êó?ÓğîÜ?Ú÷üŞ-1¡£

		\~japanese
		Ùşí®ÖªªÎiStartÛãÙÍªÎ«­«ã«é«¯«¿?ª«ªé?ßãª·ªÆpszSubª¬ò¦ª¹Ùşí®ÖªªÎõÌôøÙşí®ªÎêÈöÇªò÷®ª·ªŞª¹¡£÷®ª»ªÊª±ªìªĞ-1ªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		int Find( const XCHAR* pszSub, int iStart = 0 ) const throw()
		{
			// iStart is in XCHARs
			assert( iStart >= 0 );

			if(pszSub == NULL)
			{
				return( -1 );
			}
			// nLength is in XCHARs
			int nLength = GetLength();
			if( iStart < 0 || iStart > nLength )
			{
				return( -1 );
			}

			// find first matching substring
			const XCHAR* psz = StringTraits::StringFindString( GetString()+iStart, pszSub );

			// return -1 for not found, distance from beginning otherwise
			return( (psz == NULL) ? -1 : int( psz-GetString() ) );
		}

		/** 
		\~korean
		¹®ÀÚ¿­ ¾È¿¡¼­ iFirst°¡ °¡¸®Å°´Â °÷ºÎÅÍ ³ª¸ÓÁö ±ÛÀÚ¸¦ Ãß·Á¼­ ¸®ÅÏÇÑ´Ù. 

		\~english
		Returns the characters collected from the location where pointed by iFirst to the end in text string.

		\~chinese
		î¤í®İ¬Íú×ìØü£¬Óû??iFirstá¶ò¦îÜò¢Û°?ã·Óğí¥ù»îÜÙşí®ı¨Ú÷üŞ¡£

		\~japanese
		Ùşí®Öª?ªÇiFirstª¬ò¦ª¹ªÈª³ªíª«ªé?ªêªÎÙşí®ªòàÔªÓõóª·ªÆ«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		inline StringT Mid( int iFirst ) const
		{
			return( Mid( iFirst, GetLength()-iFirst ) );
		}

		/** 
		\~korean
		¹®ÀÚ¿­ ¾È¿¡¼­ iFirst°¡ °¡¸®Å°´Â °÷ºÎÅÍ nCount ¸¸Å­ÀÇ ±ÛÀÚ¸¦ Ãß·Á¼­ ¸®ÅÏÇÑ´Ù. 

		\~english
		Returns the characters collected from the location where pointed by iFirst to the point where the amount of characters become nCount in text string.

		\~chinese
		î¤í®İ¬Íú×ìØü£¬?iFirstá¶ò¦îÜò¢Û°?ã·Óû?ÓğßÓ?éÍnCountîÜí®ı¨Ú÷üŞ¡£

		\~japanese
		Ùşí®Öª?ªÇiFirstª¬ò¦ª¹ªÈª³ªíª«ªénCountªÀª±ªÎÙşí®ªòàÔªÓõóª·ªÆ«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		StringT Mid( int iFirst, int nCount ) const
		{
			// nCount is in XCHARs

			// out-of-bounds requests return sensible things
			if (iFirst < 0)
				iFirst = 0;
			if (nCount < 0)
				nCount = 0;

			if( iFirst + nCount > GetLength() )
			{
				nCount = GetLength()-iFirst;
			}
			if( iFirst > GetLength() )
			{
				nCount = 0;
			}

			assert( (nCount == 0) || ((iFirst+nCount) <= GetLength()) );

			// optimize case of returning entire string
			if( (iFirst == 0) && ((iFirst+nCount) == GetLength()) )
			{
				return( *this );
			}

			return( StringT( GetString()+iFirst, nCount) );
		}

		/** 
		\~korean
		¹®ÀÚ¿­ ³»¿¡¼­ ¿ìÃøÀ¸·ÎºÎÅÍ nCount¸¸Å­ÀÇ ¹®ÀÚ¿­¸¸ Ãß·Á¼­ ¸®ÅÏÇÑ´Ù. 

		\~english
		Returns the text stings that are collected from RHS to the point where the amount of characters become nCount in text string.

		\~chinese
		î¤í®İ¬Íú×ìØü£¬Óû??éÓ??ã·ÓğßÓ?éÍnCountîÜí®ı¨Ú÷üŞ¡£

		\~japanese
		Ùşí®Öª?ªÇéÓö°ª«ªénCountªÀª±ªÎÙşí®ÖªªÀª±ªòàÔªÓõóª·ªÆ«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		StringT Right( int nCount ) const
		{
			// nCount is in XCHARs
			if (nCount < 0)
				nCount = 0;

			int nLength = GetLength();
			if( nCount >= nLength )
			{
				return( *this );
			}

			return( StringT( GetString()+nLength-nCount, nCount ) );
		}

		/** 
		\~korean
		¹®ÀÚ¿­ ³»¿¡¼­ ÁÂÃøÀ¸·ÎºÎÅÍ nCount¸¸Å­ÀÇ ¹®ÀÚ¿­¸¸ Ãß·Á¼­ ¸®ÅÏÇÑ´Ù. 

		\~english
		Returns the text stings that are collected from LHS to the point where the amount of characters become nCount in text string.

		\~chinese
		î¤í®İ¬Íú×ìØü£¬Óû??ñ§??ã·ÓğßÓ?éÍnCountîÜí®ı¨Ú÷üŞ¡£

		\~japanese
		Ùşí®Öª?ªÇñ§ö°ª«ªénCountªÀª±ªÎÙşí®ÖªªÀª±ªòàÔªÓõóª·ªÆ«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		StringT Left( int nCount ) const
		{
			// nCount is in XCHARs
			if (nCount < 0)
				nCount = 0;

			int nLength = GetLength();
			if( nCount >= nLength )
			{
				return( *this );
			}

			return( StringT( GetString(), nCount ) );
		}

		/** 
		\~korean
		pszToken°¡ °¡¸®Å°´Â ±¸ºĞÀÚµé·Î ±¸º°µÈ ¹®ÀÚ¿­À» ¶â¾î³»¼­ ÇÏ³ª¾¿ ¸®ÅÏÇÑ´Ù.
		

		\~english
		Collects the text strings distinguished by distinguishers pointed by ofpszToken one by one then returns them one by one. 
		

		\~chinese
		??pszTokená¶ò¦îÜë¦?İÂíºá¶?İÂîÜí®İ¬Íúı¨ìé??Ú÷üŞ¡£


		\~japanese
		pszTokenª¬ò¦ª¹?İÂí­ªÊªÉªÇ?Ü¬ªµªìª¿Ùşí®ÖªªòàÔªÓõóª·ªÆìéªÄªºªÄ«ê«¿?«óª·ªŞª¹¡£


		\~


			Example:
        \code
            Proud::String str(L"%First Second#Third");
            Proud::String resToken;
            int curPos = 0;

            resToken= str.Tokenize(L"% #",curPos);
            while (resToken != L"")
            {
                _tprintf_s(L"Resulting token: %s\n", resToken);
                resToken = str.Tokenize(L"% #", curPos);
            };   
        \endcode 

		*/
        StringT Tokenize( const XCHAR* pszTokens, int& iStart ) const
		{
			assert( iStart >= 0 );

			if(iStart < 0)
			{
				ThrowInvalidArgumentException();
			}

			if( (pszTokens == NULL) || (*pszTokens == (XCHAR)0) )
			{
				if (iStart < GetLength())
				{
					return( StringT( GetString()+iStart ) );
				}
			}
			else
			{
				const XCHAR* pszPlace = GetString()+iStart;
				const XCHAR* pszEnd = GetString()+GetLength();
				if( pszPlace < pszEnd )
				{
					int nIncluding = StringTraits::StringSpanIncluding( pszPlace,
						pszTokens );

					if( (pszPlace+nIncluding) < pszEnd )
					{
						pszPlace += nIncluding;
						int nExcluding = StringTraits::StringSpanExcluding( pszPlace, pszTokens );

						int iFrom = iStart+nIncluding;
						int nUntil = nExcluding;
						iStart = iFrom+nUntil+1;

						return( Mid( iFrom, nUntil ) );
					}
				}
			}

			// return empty string, done tokenizing
			iStart = -1;

			return( StringT() );
		}

		/** 
		\~korean
		¹®ÀÚ¿­ ¿À¸¥ÂÊ ³¡¿¡ ³²¾ÆÀÖ´Â ºó ±ÛÀÚµéÀ» Àß¶ó³»¹ö¸°´Ù. 

		\~english
		Cuts off the empty characters are left at RHS end of text string

		\~chinese
		îòÓü×ºî¤í®İ¬ÍúéÓ?îÜÍöÙşí®¡£

		\~japanese
		Ùşí®ÖªªÎéÓö°ªÎğûÓ®ªË?ªÃªÆª¤ªëÍöÙşí®ªòï·ªêŞ×ªÆªŞª¹¡£
		\~
		*/
		StringT& TrimRight()
		{
			// find beginning of trailing spaces by starting
			// at beginning (DBCS aware)

			const XCHAR* psz = GetString();
			const XCHAR* pszLast = NULL;

			while( *psz != 0 )
			{
				if( StringTraits::IsSpace( *psz ) )
				{
					if( pszLast == NULL )
						pszLast = psz;
				}
				else
				{
					pszLast = NULL;
				}
				psz = StringTraits::CharNext( psz );
			}

			if( pszLast != NULL )
			{
				// truncate at trailing space start
				int iLast = int( pszLast-GetString() );

				Truncate( iLast );
			}

			return( *this );
		}

		/** 
		\~korean
		¹®ÀÚ¿­ ¿ŞÂÊ ³¡¿¡ ³²¾ÆÀÖ´Â ºó ±ÛÀÚµéÀ» Àß¶ó³»¹ö¸°´Ù. 

		\~english
		Cuts off the empty characters are left at LHS end of text string

		\~chinese
		îòÓü×ºî¤í®İ¬Íúñ§?îÜÍöÙşí®¡£

		\~japanese
		Ùşí®ÖªªÎñ§ö°ªÎğûÓ®ªË?ªÃªÆª¤ªëÍöÙşí®ªòï·ªêŞ×ªÆªŞª¹¡£
		\~
		*/
		StringT& TrimLeft()
		{
			// find first non-space character

			const XCHAR* psz = GetString();

			while( StringTraits::IsSpace( *psz ) )
			{
				psz = StringTraits::CharNext( psz );
			}

			if( psz != GetString() )
			{
				// fix up data and length
				int iFirst = int( psz-GetString() );
				XCHAR* pszBuffer = GetBuffer( GetLength() );
				psz = pszBuffer+iFirst;
				int nDataLength = GetLength()-iFirst;
#if (_MSC_VER>=1400)
				memmove_s( pszBuffer, (GetLength()+1)*sizeof( XCHAR ), 
					psz, (nDataLength+1)*sizeof( XCHAR ) );
#else
				memmove( pszBuffer,
					psz, (nDataLength+1)*sizeof( XCHAR ) );
#endif
				ReleaseBufferSetLength( nDataLength );
			}

			return( *this );
		}

		/** 
		\~korean
		¹®ÀÚ¿­ ¾çÂÊ ³¡¿¡ ³²¾ÆÀÖ´Â ºó ±ÛÀÚµéÀ» Àß¶ó³»¹ö¸°´Ù. 

		\~english
		Cuts off the empty characters are left at RHS end and at LHS end of text string

		\~chinese
		îòÓü×ºî¤í®İ¬Íú??îÜÍöÙşí®¡£

		\~japanese
		Ùşí®ÖªªÎ?ö°ªÎğûÓ®ªË?ªÃªÆª¤ªëÍöÙşí®ªòï·ªêŞ×ªÆªŞª¹¡£
		\~
		*/
		StringT& Trim()
		{
			return( TrimRight().TrimLeft() );
		}

		/** 
		\~korean
		¹®ÀÚ¿­ ¾çÂÊ ³¡¿¡ ³²¾ÆÀÖ´Â chTargetÀÌ °¡¸®Å°´Â ±ÛÀÚµéÀ» Àß¶ó³»¹ö¸°´Ù. 

		\~english
		Cuts off the characters pointed by chTarget and are left at RHS end and at LHS end of text string

		\~chinese
		îòÓü×ºî¤í®İ¬Íú??chTargetò¦ú¾îÜÙşí®¡£

		\~japanese
		Ùşí®ÖªªÎ?ö°ªÎğûÓ®ªË?ªÃªÆª¤ªëchTargetª¬ò¦ª¹Ùşí®ªòï·ªêŞ×ªÆªŞª¹¡£
		\~
		*/
		StringT& Trim( XCHAR chTarget )
		{
			return( TrimRight( chTarget ).TrimLeft( chTarget ) );
		}

		/** 
		\~korean
		¹®ÀÚ¿­ ¾çÂÊ ³¡¿¡ ³²¾ÆÀÖ´Â pszTargetsÀÌ °¡¸®Å°´Â ±ÛÀÚµéÀ» Àß¶ó³»¹ö¸°´Ù. 

		\~english
		Cuts off the characters pointed by pszTargets and are left at RHS end and at LHS end of text string

		\~chinese
		îòÓü×ºî¤í®İ¬Íú??pszTargetsò¦ú¾îÜÙşí®¡£

		\~japanese
		Ùşí®ÖªªÎ?ö°ªÎğûÓ®ªË?ªÃªÆª¤ªëpszTargetsª¬ò¦ª¹Ùşí®ªòï·ªêŞ×ªÆªŞª¹¡£
		\~
		*/
		StringT& Trim( const XCHAR* pszTargets )
		{
			return( TrimRight( pszTargets ).TrimLeft( pszTargets ) );
		}

		/** 
		\~korean
		¹®ÀÚ¿­ ¿ìÃø ³¡¿¡ ³²¾ÆÀÖ´Â chTargetÀÌ °¡¸®Å°´Â ±ÛÀÚµéÀ» Àß¶ó³»¹ö¸°´Ù. 

		\~english
		Cuts off the characters pointed by chTarget and are left at RHS end of text string 

		\~chinese
		îòÓü×ºî¤í®İ¬ÍúéÓ?chTargetò¦ú¾îÜÙşí®¡£

		\~japanese
		Ùşí®ÖªªÎéÓö°ªÎğûÓ®ªË?ªÃªÆª¤ªëchTargetª¬ò¦ª¹Ùşí®ªòï·ªêŞ×ªÆªŞª¹¡£ 
		\~
		*/
		StringT& TrimRight( XCHAR chTarget )
		{
			// find beginning of trailing matches
			// by starting at beginning (DBCS aware)			

			const XCHAR* psz = GetString();
			const XCHAR* pszLast = NULL;

			while( *psz != 0 )
			{
				if( *psz == chTarget )
				{
					if( pszLast == NULL )
					{
						pszLast = psz;
					}
				}
				else
				{
					pszLast = NULL;
				}
				psz = StringTraits::CharNext( psz );
			}

			if( pszLast != NULL )
			{
				// truncate at left-most matching character  
				int iLast = int( pszLast-GetString() );
				Truncate( iLast );
			}

			return( *this );
		}

		/** 
		\~korean
		¹®ÀÚ¿­ ¿ìÃø ³¡¿¡ ³²¾ÆÀÖ´Â pszTargetsÀÌ °¡¸®Å°´Â ±ÛÀÚµéÀ» Àß¶ó³»¹ö¸°´Ù. 

		\~english
		uts off the characters pointed by pszTargets and are left at RHS end of text string

		\~chinese
		îòÓü×ºî¤í®İ¬ÍúéÓ?pszTargetsò¦ú¾îÜÙşí®¡£

		\~japanese
		Ùşí®ÖªªÎéÓö°ªÎğûÓ®ªË?ªÃªÆª¤ªëpszTargetª¬ò¦ª¹Ùşí®ªòï·ªêŞ×ªÆªŞª¹¡£ 
		\~
		*/
		StringT& TrimRight( const XCHAR* pszTargets )
		{
			// if we're not trimming anything, we're not doing any work
			if( (pszTargets == NULL) || (*pszTargets == 0) )
			{
				return( *this );
			}

			// find beginning of trailing matches
			// by starting at beginning (DBCS aware)

			const XCHAR* psz = GetString();
			const XCHAR* pszLast = NULL;

			while( *psz != 0 )
			{
				if( StringTraits::StringFindChar( pszTargets, *psz ) != NULL )
				{
					if( pszLast == NULL )
					{
						pszLast = psz;
					}
				}
				else
				{
					pszLast = NULL;
				}
				psz = StringTraits::CharNext( psz );
			}

			if( pszLast != NULL )
			{
				// truncate at left-most matching character  
				int iLast = int( pszLast-GetString() );
				Truncate( iLast );
			}

			return( *this );
		}

		/** 
		\~korean
		¹®ÀÚ¿­ ÁÂÃø ³¡¿¡ ³²¾ÆÀÖ´Â chTargetÀÌ °¡¸®Å°´Â ±ÛÀÚµéÀ» Àß¶ó³»¹ö¸°´Ù. 

		\~english
		Cuts off the characters pointed by chTarget and are left at LHS end of text string 

		\~chinese
		îòÓü×ºî¤í®İ¬Íúñ§?chTargetò¦ú¾îÜÙşí®¡£

		\~japanese
		Ùşí®ÖªªÎñ§ö°ªÎğûÓ®ªË?ªÃªÆª¤ªëchTargetª¬ò¦ª¹Ùşí®ªòï·ªêŞ×ªÆªŞª¹¡£ 
		\~
		*/
		StringT& TrimLeft( XCHAR chTarget )
		{
			// find first non-matching character
			const XCHAR* psz = GetString();

			while( chTarget == *psz )
			{
				psz = StringTraits::CharNext( psz );
			}

			if( psz != GetString() )
			{
				// fix up data and length
				int iFirst = int( psz-GetString() );
				XCHAR* pszBuffer = GetBuffer( GetLength() );
				psz = pszBuffer+iFirst;
				int nDataLength = GetLength()-iFirst;
#if (_MSC_VER>=1400)
				memmove_s( pszBuffer, (GetLength()+1)*sizeof( XCHAR ), 
					psz, (nDataLength+1)*sizeof( XCHAR ) );
#else
				memmove( pszBuffer,
					psz, (nDataLength+1)*sizeof( XCHAR ) );
#endif
				ReleaseBufferSetLength( nDataLength );
			}

			return( *this );
		}

		/** 
		\~korean
		¹®ÀÚ¿­ ÁÂÃø ³¡¿¡ ³²¾ÆÀÖ´Â pszTargetsÀÌ °¡¸®Å°´Â ±ÛÀÚµéÀ» Àß¶ó³»¹ö¸°´Ù. 

		\~english
		Cuts off the characters pointed by pszTargets and are left at RHS end of text string

		\~chinese
		îòÓü×ºî¤í®İ¬Íúñ§?pszTargetsò¦ú¾îÜÙşí®¡£

		\~japanese
		Ùşí®ÖªªÎñ§ö°ªÎğûÓ®ªË?ªÃªÆª¤ªëpszTargetª¬ò¦ª¹Ùşí®ªòï·ªêŞ×ªÆªŞª¹¡£ 
		\~
		*/
		StringT& TrimLeft( const XCHAR* pszTargets )
		{
			// if we're not trimming anything, we're not doing any work
			if( (pszTargets == NULL) || (*pszTargets == 0) )
			{
				return( *this );
			}

			const XCHAR* psz = GetString();
			while( (*psz != 0) && (StringTraits::StringFindChar( pszTargets, *psz ) != NULL) )
			{
				psz = StringTraits::CharNext( psz );
			}

			if( psz != GetString() )
			{
				// fix up data and length
				int iFirst = int( psz-GetString() );
				XCHAR* pszBuffer = GetBuffer( GetLength() );
				psz = pszBuffer+iFirst;
				int nDataLength = GetLength()-iFirst;
#if defined(_WIN32)
				Checked::memmove_s( pszBuffer, (GetLength()+1)*sizeof( XCHAR ), 
					psz, (nDataLength+1)*sizeof( XCHAR ) );
#else
                memmove(pszBuffer, psz, (nDataLength+1)*sizeof( XCHAR ));
#endif
				ReleaseBufferSetLength( nDataLength );
			}

			return( *this );
		}

#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// ÀÌ Å¬·¡½º´Â ProudNet DLL °æ¿ì¸¦ À§ÇØ Ä¿½ºÅÒ ÇÒ´çÀÚ¸¦ ¾´´Ù.
		// proc heapÀ» ¾´´Ù. Àü¿ª º¯¼ö·Î ¼±¾ğÇØ ¾²±âµµ ÇÏ´Ï±î.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif // __MARMALADE__


	public:
		// std::string°úÀÇ Á÷Á¢ Çüº¯È¯À» ÇÏ°Ô ÇØÁİ´Ï´Ù.
		// ÀÌ°ÍÀÌ ÀÖÀ¸´Ï, ¿©·¯ºĞÀº Proud::Stringº¸´Ù´Â std::string »ç¿ëÇÏ½Ã´Â °ÍÀÌ ´õ ÁÁ½À´Ï´Ù.
		// ½ÉÁö¾î ProudNet API·Î ÁÖ°í¹Ş´Â ¹®ÀÚ¿­ °´Ã¼·Î Proud::String ´ë½Å std::stringÀ» Á÷Á¢ ¾²¼Åµµ µË´Ï´Ù.
		inline operator std::string() const
		{
			std::string a;
			StringTraits::ToStdString(*this, a);
			return a;
		}
		inline StringT(const std::string& src)
		{
			InitVars();
			StringTraits::FromStdString(src, *this);
		}

		// std::string°úÀÇ Á÷Á¢ Çüº¯È¯À» ÇÏ°Ô ÇØÁİ´Ï´Ù.
		// ÀÌ°ÍÀÌ ÀÖÀ¸´Ï, ¿©·¯ºĞÀº Proud::Stringº¸´Ù´Â std::string »ç¿ëÇÏ½Ã´Â °ÍÀÌ ´õ ÁÁ½À´Ï´Ù.
		// ½ÉÁö¾î ProudNet API·Î ÁÖ°í¹Ş´Â ¹®ÀÚ¿­ °´Ã¼·Î Proud::String ´ë½Å std::stringÀ» Á÷Á¢ ¾²¼Åµµ µË´Ï´Ù.
		inline operator std::wstring() const
		{
			std::wstring a;
			StringTraits::ToStdWString(*this, a);
			return a;
		}
		inline StringT(const std::wstring& src)
		{
			InitVars();
			StringTraits::FromStdWString(src, *this);
		}
	};
	
	template<typename XCHAR, typename StringTraits>
	StringT<XCHAR,StringTraits> operator+(const StringT<XCHAR,StringTraits> &a,const StringT<XCHAR,StringTraits> &b)
	{
		StringT<XCHAR,StringTraits> ret = a;
		ret += b;
		return ret;
	}

	template<typename XCHAR, typename StringTraits>
	StringT<XCHAR,StringTraits> operator+(const StringT<XCHAR,StringTraits> &a,const XCHAR* b)
	{
		StringT<XCHAR,StringTraits> ret = a;
		ret += b;
		return ret;
	}

	template<typename XCHAR, typename StringTraits>
	StringT<XCHAR,StringTraits> operator+(const XCHAR* a,const StringT<XCHAR,StringTraits> &b)
	{
		StringT<XCHAR,StringTraits> ret = a;
		ret += b;
		return ret;
	}

	/** 
	\~korean
	CStringT.GetBuffer, CStringT.ReleaseBuffer ÀÇ È£ÃâÀ» ÀÚµ¿È­ÇÑ´Ù. 

	\~english
	Automates calling CStringT.GetBuffer, CStringT.ReleaseBuffer

	\~chinese
	í»?ûù CStringT.GetBuffer,  CStringT.ReleaseBuffer%îÜû¼Ğ£¡£

	\~japanese
	CStringT.GetBuffer, CStringT.ReleaseBufferªÎû¼ªÓõóª·ªòí»ÔÑûùª·ªŞª¹¡£ 
	\~
	*/
	template<typename XCHAR, typename StringTraits>
	class StrBufT
	{
		StringT<XCHAR,StringTraits>* m_obj;
		XCHAR* m_bufPtr;
	public:
		StrBufT(StringT<XCHAR,StringTraits>& src, int maxLength = 0)
		{
			m_obj = &src;
			m_bufPtr = src.GetBuffer(maxLength); 
		}

		~StrBufT()
		{
			m_obj->ReleaseBuffer();
		}

		operator XCHAR*()
		{
			return m_bufPtr;
		}

		XCHAR* GetBuf()
		{
			return m_bufPtr;
		}
	};

	template<typename XCHAR, typename StringTraits>
	class StringTraitsT
	{
	public:
		typedef const StringT<XCHAR,StringTraits>& INARGTYPE;
		typedef StringT<XCHAR,StringTraits>& OUTARGTYPE;

		static uint32_t __cdecl Hash( INARGTYPE str )
		{
			assert( str.GetString() != NULL );
			uint32_t nHash = 0;
			const XCHAR* pch = str.GetString();
			while( *pch != 0 )
			{
				nHash = (nHash<<5)+nHash+(*pch);
				pch++;
			}

			return( nHash );
		}

		static bool __cdecl CompareElements( INARGTYPE str1, INARGTYPE str2 )
		{
			return(StringTraits::StringCompare(str1.GetString(), str2.GetString()) == 0);
		}

		static int __cdecl CompareElementsOrdered( INARGTYPE str1, INARGTYPE str2 )
		{
			return(StringTraits::StringCompare(str1.GetString(), str2.GetString()));
		}
	};

	/** 
	\~korean
	ANSI Ä³¸¯ÅÍ ¹®ÀÚ¿­ 

	\~english
	ANSI character text string

	\~chinese
	ANSI ÊÇßäí®İ¬Íú¡£

	\~japanese
	ANSI«­«ã«é«¯«¿?Ùşí®Öª
	\~
	*/
	typedef StringT<char,AnsiStrTraits> StringA;
	/** 
	\~korean
	Unicode Ä³¸¯ÅÍ ¹®ÀÚ¿­ 

	\~english
	Unicode character text string

	\~chinese
	Unicode ÊÇßäí®İ¬Íú¡£

	\~japanese
	Unicode«­«ã«é«¯«¿?Ùşí®Öª
	\~
	*/
	typedef StringT<wchar_t,UnicodeStrTraits> StringW;
    
	/**
	\~korean
	¹®ÀÚ¿­ Å¬·¡½ºÀÔ´Ï´Ù.
	Windows¿Í Marmalade¿¡¼­´Â UTF-16À» Áö¿øÇÏ´Â wchar_t Å¸ÀÔ ¹®ÀÚ¿­ÀÌÁö¸¸ ¿©Å¸ ÇÃ·§Æû¿¡¼­´Â UTF-8À» Áö¿øÇÏ´Â char Å¸ÀÔ ¹®ÀÚ¿­ÀÔ´Ï´Ù.

	\~english
	It is a string class.
	The string is a wchar_t type that supports UTF-16 at Windows & Marmalade but at the other platforms, it is a char type string that supports UTF-8.

	\~chinese
	í®İ¬Íú class ¡£
	?æÔî¤Windows£¬MarmaladeñéãÀò¨ò¥ UTF-16 îÜ wchar_t type îÜí®İ¬Íú£¬Ó£ãÀî¤ĞìöâøÁ÷»ñéãÀò¨ò¥ UTF-8 îÜ char type îÜí®İ¬Íú¡£

	\~japanese
	Ùşí®Öª«¯«é«¹ªÇª¹¡£
	WindowsªÈMarmaladeªÇªÏUTF-16ªòò¨êµª¹ªëwchar_t«¿«¤«×Ùşí®ÖªªÇª¹ª¬¡¢öâªÎ«×«é«Ã«È«Õ«©?«àªÇªÏUTF-8ªòò¨êµª¹ªëchar«¿«¤«×Ùşí®ÖªªÇª¹¡£
	*/
#if defined(_PNUNICODE) // VC++¿¡¼­¸¸ ÀÌ°ÍÀÌ ÄÑÁ® ÀÖ´Ù. MBSºôµå ¿É¼ÇÀ» ¼³Á¤ÇÏ¸é ²¨Áö±ä ÇÏÁö¸¸ ¿äÁò ½Ã´ë¿¡ ´©°¡ ±×·¯°Ú´Â°¡?
	typedef StringW String;
#else
	typedef StringA String;
#endif

	/** 
	\~korean
	ANSI Ä³¸¯ÅÍ ¹®ÀÚ¿­¿ë ¹®ÀÚ¿­ ¹öÆÛ Á¶ÀÛÀ» À§ÇÑ Å¬·¡½º 

	\~english
	Class for manipulating ANSI character text string buffer

	\~chinese
	?ÖõANSIÊÇßäí®İ¬ÍúéÄí®İ¬ÍúğÃ?bufferîÜ?¡£

	\~japanese
	ANSI«­«ã«é«¯«¿?Ùşí®ÖªéÄÙşí®Öª«Ğ«Ã«Õ«¡?ğÃíÂªÎª¿ªáªÎ«¯«é«¹
	\~
	*/
	typedef StrBufT<char,AnsiStrTraits> StrBufA;

	/** 
	\~korean
	Unicode Ä³¸¯ÅÍ ¹®ÀÚ¿­¿ë ¹®ÀÚ¿­ ¹öÆÛ Á¶ÀÛÀ» À§ÇÑ Å¬·¡½º 

	\~english
	Class for manipulating Unicode character text string bufferUnicode

	\~chinese
	?ÖõUnicodeÊÇßäí®İ¬ÍúéÄí®İ¬ÍúğÃ?bufferîÜ?¡£

	\~japanese
	Unicode«­«ã«é«¯«¿?Ùşí®ÖªéÄÙşí®Öª«Ğ«Ã«Õ«¡?ğÃíÂªÎª¿ªáªÎ«¯«é«¹
	\~
	*/
	typedef StrBufT<wchar_t,UnicodeStrTraits> StrBufW;
    
	typedef StringTraitsT<char,AnsiStrTraits> StringTraitsA;
	typedef StringTraitsT<wchar_t,UnicodeStrTraits> StringTraitsW;

	/** 
	\~korean
	Ä³¸¯ÅÍ ¹®ÀÚ¿­ º¯È¯ÇÔ¼ö

	\~english
	Convert to String Function

	\~chinese
	ÊÇßäí®İ¬Íú??ùŞ?¡£

	\~japanese
	«­«ã«é«¯«¿?Ùşí®Öª?üµ??
	\~
	*/
	StringA StringW2A(const wchar_t *src, CStringEncoder* encoder = NULL);		
	StringW StringA2W(const char *src, CStringEncoder* encoder = NULL);
	inline StringA StringW2A(const StringW& src, CStringEncoder* encoder = NULL)
	{
		return StringW2A(src.GetString(), encoder);
	}
	inline StringW StringA2W(const StringA& src, CStringEncoder* encoder = NULL)
	{
		return StringA2W(src.GetString(), encoder);
	}

	/* Win32, Marmalade¿¡¼­´Â wchar_t¸¦ ¾Ö¿ëÇÏÁö¸¸ unix¿¡¼­´Â charÀ» ¾Ö¿ëÇÑ´Ù.
	char ¹®ÀÚ¿­ÀÌ UTF-8À» Ã³¸®ÇÏ±â ¶§¹®ÀÌ´Ù. 
	*/
#ifdef _PNUNICODE
	typedef StringTraitsW StringTraits;
	typedef StrBufW StrBuf;
#else
	typedef StringTraitsA StringTraits;
	typedef StrBufA StrBuf;
#endif

}

#include "PNStringTraitsImpl.inl"

// NOTE: CPNElementTraitsÀÇ specialized templateÀº namespace ¹Ù±ùÀ¸·Î »©¾ß.
// CFastMapµî¿¡¼­ ¼¼¹øÂ° ÀÎÀÚ ¾È ³Ö¾îµµ µÇ°Ô ÇÏ·Á°í.
template<>
class CPNElementTraits<Proud::StringW> :public Proud::StringTraitsW{};

template<>
class CPNElementTraits<Proud::StringA> :public Proud::StringTraitsA{};

/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#ifdef _MSC_VER 
#pragma warning(pop)
#endif // __MARMALADE__
