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

#include "FastArrayPtr.h"
#include "ByteArray.h"
#include "BiasManagedPointer.h"

#if defined(_MSC_VER)
#pragma warning(disable:4290) // ÀÌ °æ°í´Â VC++¿¡¼­¸¸ ¹ß»ıÇÏ´Ï ¸·ÀÚ
#endif

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
	ByteArray ¿¡ smart pointer ±â´ÉÀÌ Ãß°¡µÈ ÇüÅÂ. ³×Æ®¿öÅ© ÆĞÅ¶ ÇüÅÂ·Î ¾²ÀÌ¹Ç·Î 32-64 º¯È¯¿¡µµ ¹Î°¨. µû¶ó¼­ intPtrÀÌ ¾Æ´Ñ int32 Å¸ÀÔÀÌ´Ù.
	ByteArray °¡ typedef°¡ ¾Æ´Ñ »ó¼Ó Å¬·¡½ºÀÌ±â ¶§¹®¿¡ ÇÊ¿äÇÑ ¸Ş¼­µå¸¦ ÀÌ °´Ã¼µµ ¿À¹ö¶óÀÌµåÇØ¾ß
	ºôµå ¿¡·¯¸¦ ÇÇÇÑ´Ù.

	\~english
	It is the form that smart pointer function has been added to ByteArray. It is very sensitive to conversion from 32 to 64 because of being used as the form of network packet, so its form is int32 (not intPtr).
	To avoid build error, this object has to override require method because ByreArray is inherit class instead of typedef.

	\~chinese
	î¤ ByteArray%ôÕÊ¥ÖõsmartpointerĞüÒöîÜû¡?¡£ì×Ğìå¥éÄéÍ???ËßøĞîÜû¡?á¶ì¤?32-64????ÚÂÊï¡£ì×ó®ĞìÜôãÀinPtrì»ãÀint32?úş¡£
	ì×? ByteArray%ÜôãÀtypedefì»ãÀïÈ??£¬ì×ó®?ù±é©îÜÛ°Ûöõ±êÆó®ËÔ?î¦Òöù­?Build??¡£

	\~japanese
	ByteArrayªËsmart pointerÑ¦Òöª¬õÚÊ¥ªµªìª¿û¡÷¾¡£«Í«Ã«È«ï?«¯«Ñ«±«Ã«Èû¡÷¾ªÇŞÅªïªìªŞª¹ªÎªÇ¡¢32-64?üµªËªâÚÂÊïªÇª¹¡£ªèªÃªÆ¡¢intPtrªÇªÏªÊª¤int32«¿«¤«×ªÇª¹¡£
	ByteArrayª¬typedefªÇªÏªÊª¤ßÓ?«¯«é«¹ªÇª¢ªëª¿ªá¡¢ù±é©ªÊ«á«½«Ã«Éªòª³ªÎ«ª«Ö«¸«§«¯«Èªâ«ª?«Ğ?«é«¤«Éª·ªÆ«Ó«ë«É«¨«é?ªòù­ª±ªŞª¹¡£
	\~
	 */
	class ByteArrayPtr:public BiasManagedPointer<ByteArray, true>
	{
	private:
		// base classÀÇ ÀÚÃ¼Àû buffer¿Í, ÀÌ external buffer Áß¿¡¼­´Â ÇÏ³ª¸¸ À¯È¿ÇÏ°í, ³ª¸ÓÁö´Â ºó »óÅÂ°¡ µÈ´Ù.
		CArrayWithExternalBuffer<uint8_t, false, true, int> m_externalBuffer;

	public:
		// #ikpil.choi 2016-11-29 : TÀÇ Å¸ÀÔ »çÀÌÁî Ãß°¡
		static const size_t TYPE_SIZE = sizeof(uint8_t);

	public:

		inline ByteArrayPtr() {}

		inline ByteArrayPtr(const ByteArrayPtr& src)
			: BiasManagedPointer<ByteArray, true>(src)
		{
			src.m_externalBuffer.ShareTo(m_externalBuffer);
		}

#ifdef SUPPORTS_CPP11
		// ÀÌµ¿ »ı¼ºÀÚ
 		inline ByteArrayPtr(ByteArrayPtr&& src)
 			: BiasManagedPointer<ByteArray, true>(src)
 		{
 			src.m_externalBuffer.ShareTo(m_externalBuffer);
 			src.m_externalBuffer.Uninit();
 		}
#endif
		inline ByteArrayPtr& operator=(const ByteArrayPtr& src)
		{
			// base class
			BiasManagedPointer<ByteArray, true>::operator=(src);

			src.m_externalBuffer.ShareTo(m_externalBuffer);

			return *this;
		}

#ifdef SUPPORTS_CPP11
		// ÀÌµ¿ ¿¬»êÀÚ
 		inline ByteArrayPtr& operator=(ByteArrayPtr&& src)
 		{
 			// base class
 			BiasManagedPointer<ByteArray, true>::operator=(src);

 			if (&src != this) // ÀÌµ¿ ¿¬»êÀÚ´Â ÀÌ°Å ²À Ã¼Å©ÇØ¾ß.
 			{
 				src.m_externalBuffer.ShareTo(m_externalBuffer);
 				src.m_externalBuffer.Uninit();
 			}

 			return *this;
 		}
#endif

	public:

		inline int GetCapacity() const
		{
			if (GetTombstone())
			{
				return GetTombstone()->m_substance.GetCapacity();
			}
			else if (m_externalBuffer.IsNull())
			{
				ThrowArrayIsNullError();
			}

			return m_externalBuffer.GetCapacity();
		}

		inline int GetCount() const
		{
			if (GetTombstone())
			{
				return GetTombstone()->m_substance.GetCount();
			}
			else if (m_externalBuffer.IsNull())
			{
				ThrowArrayIsNullError();
			}

			return m_externalBuffer.GetCount();
		}

#if defined(_MSC_VER)
		__declspec(property(get = GetCount)) int Count;
#endif

		inline void MustNotNull() const
		{
			if (IsNull())
			{
				ThrowArrayIsNullError();
			}
		}

		inline void MustNull() const throw(Exception)
		{
			if (!IsNull())
				ThrowException(ArrayPtrIsNotNullError);
		}

		/**
		\~korean
		\param length º¯°æÇÒ Capacity »çÀÌÁî

		\~english TODO:translate needed.
		\param length Capacity size to change the length

		\~chinese
		\param length é©??îÜCapacityÓŞá³¡£

		\~japanese
		\param length ?ÌÚª¹ªëCapacity«µ«¤«º 
		\~
		*/
		inline void SetCapacity(int length)
		{
			if(length < 0)
				ThrowInvalidArgumentException();

			if (!m_externalBuffer.IsNull())
			{
				// ¾Æ¹«°Íµµ ¾ÈÇÔ
			}
			else
			{
				if (GetTombstone() != NULL)
					GetTombstone()->m_substance.SetCapacity(length);
			}
		}

		/**
		\~korean
		¹è¿­ÀÇ »çÀÌÁî¸¦ setting ÇÑ´Ù.
		\param length º¯°æÇÒ ¹è¿­ÀÇ »çÀÌÁî

		\~english TODO:translate needed.
		Set the size of the array
		\param length Size of the array to change the length

		\~chinese
		Setting ÛÉÖªîÜÓŞá³¡£
		\param length é©??îÜÛÉÖªñıÓŞá³¡£

		\~japanese
		ÛÕÖªªÎ«µ«¤«ºªòàâïÒª¹ªë¡£
		\param length ?ÌÚª¹ªëÛÕÖªªÎ«µ«¤«º
		\~
		*/
		inline void SetCount(int length)
		{
			if(length < 0)
				ThrowInvalidArgumentException();

			if (!m_externalBuffer.IsNull())
			{
				m_externalBuffer.SetCount(length);
			}
			else
			{
				if(length > 0)
				{
					if(GetTombstone())
						GetTombstone()->m_substance.SetCount(length);
					else
					{
						ThrowArrayIsNullError();
					}
				}
				else
				{
					if(GetTombstone())
						GetTombstone()->m_substance.SetCount(0);
				}
			}
		}


		inline void AddCount(int length)
		{
			// CMessage.Write¿¡ ÀÇÇÑ È£Ãâºóµµ°¡ ³ô¾Æ¼­, ¼º´É ÃÖÀûÈ­°¡ µÇ¾î ÀÖ´Ù.
			if (!m_externalBuffer.IsNull())
			{
				m_externalBuffer.AddCount(length);
			}
			else
			{
				if (length > 0) // Å©±â ´Ã¸²ÀÌ ¾øÀ¸¸é ±×³É ¹«½ÃÇÏ°í ³Ñ¾î°£´Ù.
				{
					if (GetTombstone())
						GetTombstone()->m_substance.AddCount(length);
					else
					{
						ThrowArrayIsNullError();
					}
				}
			}

		}

		/**
		\~korean
		1 BYTE ´ÜÀ§ÀÇ Data¸¦ Ãß°¡ÇÕ´Ï´Ù.
		\param data Ãß°¡ÇÒ BYTE

		\~english TODO:translate needed.
		Add data in 1 byte unit
		\param data Byte to add data

		\~chinese
		ôÕÊ¥1BYTE?êÈîÜData¡£
		\param data é©ôÕÊ¥îÜBYTE¡£

		\~japanese
		1«Ğ«¤«È?êÈªÎ«Ç?«¿ªòõÚÊ¥ª·ªŞª¹¡£
		\param data õÚÊ¥ª¹ªë«Ğ«¤«È 
		\~
		*/
		inline void Add(uint8_t data)
		{
			AddRange(&data, 1);
		}

		/**
		\~korean
		ÇöÀçÀÇ ¹è¿­¿¡ BYTE¹è¿­ data¸¦ Ãß°¡ ÇÕ´Ï´Ù.
		\param data Ãß°¡ÇÒ BYTE¹è¿­ Æ÷ÀÎÅÍ
		\param count ¹è¿­ÀÇ Å©±â

		\~english TODO:translate needed.
		Add byte array data to the current array
		\param data Byte array pointer to add data
		\param count Size of the count array

		\~chinese
		î¤?êóîÜÛÉÖªß¾ôÕÊ¥BYTEÛÉÖªdata¡£
		\param data é©ôÕÊ¥îÜBYTEÛÉÖªò¦?¡£
		\param count ÛÉÖªîÜÓŞá³¡£

		\~japanese
		úŞî¤ªÎÛÕÖªªË«Ğ«¤«ÈÛÕÖª«Ç?«¿ªòõÚÊ¥ª·ªŞª¹¡£
		\param data õÚÊ¥ª¹ªëBYTEÛÕÖª«İ«¤«ó«¿?
		\param count ÛÕÖªªÎ«µ«¤«º
		\~
		*/
		inline void AddRange(const uint8_t* data, int count)
		{
			// InsertRangeº¸´Ù AddRange¹Ù·Î ÄİÀÌ ´õ ºü¸§
			if (m_externalBuffer.IsNull() == false)
			{
				m_externalBuffer.AddRange(data, count);
			}
			else
			{
				if(GetTombstone())
				{
					GetTombstone()->m_substance.AddRange(data, count);
				}
				else
				{
					ThrowArrayIsNullError();
				}
			}
		}

		/*
		\~korean
		ÇöÀçÀÇ ¹è¿­¿¡ BYTE¹è¿­ data¸¦ Ãß°¡ ÇÕ´Ï´Ù.
		\param indexAt ¹è¿­³»¿¡¼­ indexAt¹øÂ°µÚ¿¡ »ğÀÔÇÕ´Ï´Ù. ¿ø·¡ÀÇ indexAtµÚÀÇ µ¥ÀÌÅÍ´Â »ğÀÔµÈ µ¥ÀÌÅÍ µÚ·Î ¹Ğ¸³´Ï´Ù.
		\param data Ãß°¡ÇÒ BYTE¹è¿­ Æ÷ÀÎÅÍ
		\param count ¹è¿­ÀÇ Å©±â

		\~english TODO:translate needed.
		Add byte array data to the current array
		\Insert after (indexAt) th within the indexAt array. The data after the original indexAt is moved back to the inserted data.
		\param data Byte array pointer to add data
		\param count Size of the count array

		\~chinese
		î¤?êóîÜÛÉÖªß¾ôÕÊ¥BYTEÛÉÖªdata¡£
		\param indexAt î¤ÛÉÖªñéîÜindexAtı¨?ìı¡£ê«êóîÜindexAtı¨îÜ?Ëß??õÏÓğ?ìıîÜ?Ëßñıı¨¡£
		\param data é©ôÕÊ¥îÜBYTEÛÉÖªò¦?¡£
		\param count ÛÉÖªîÜÓŞá³¡£

		\~japanese
		úŞî¤ªÎÛÕÖªªË«Ğ«¤«ÈÛÕÖª«Ç?«¿ªòõÚÊ¥ª·ªŞª¹¡£
		\param indexAt ÛÕÖª?ªÇindexAtÛãÙÍªÎı­ªË?ìıª·ªŞª¹¡£Üâ?ªÎindexAtªÎı­ªÎ«Ç?«¿ªÏ?ìıªµªìª¿«Ç?«¿ªÎı­ªËªºªéªµªìªŞª¹¡£
		\param data õÚÊ¥ª¹ªë«Ğ«¤«ÈÛÕÖª«İ«¤«ó«¿? 
		\param count ÛÕÖªªÎ«µ«¤«º 
		\~
		*/
		inline void InsertRange(int indexAt, const uint8_t* data, int count)
		{
			if (m_externalBuffer.IsNull() == false)
			{
				m_externalBuffer.InsertRange(indexAt, data, count);
			}
			else
			{
				if(GetTombstone())
					GetTombstone()->m_substance.InsertRange(indexAt, data, count);
				else
				{
					ThrowArrayIsNullError();
				}
			}
		}

		/**
		\~korean
		µ¥ÀÌÅÍµéÀ» Á¦°Å ÇÕ´Ï´Ù.
		\param indexAt Á¦°ÅÇÑ dataÀÇ indexÀÔ´Ï´Ù.
		\param count Á¦°ÅÇÒ ¹è¿­ÀÇ ¼ö ÀÔ´Ï´Ù.

		\~english TODO:translate needed.
		Remove data
		\param indexAt Index of the removed data
		\param count Number of the array to be removed


		\~chinese
		?ğ¶Data¡£
		\param indexAt ãÀ?ğ¶îÜData index¡£
		\param count  é©?ğ¶îÜÛÉÖª?¡£

		\~japanese
		«Ç?«¿ªòğ¶ËÛª·ªŞª¹¡£
		\param indexAt ğ¶ËÛª·ª¿«Ç?«¿ªÎindexªÇª¹¡£
		\param count ğ¶ËÛª¹ªëÛÕÖªªÎ?ªÇª¹¡£
		\~
		*/
		inline void RemoveRange(int indexAt, int count)
		{
			if (m_externalBuffer.IsNull() == false)
			{
				m_externalBuffer.RemoveRange(indexAt, count);
			}
			else
			{
				if(GetTombstone())
					GetTombstone()->m_substance.RemoveRange(indexAt, count);
				else
				{
					ThrowArrayIsNullError();
				}
			}
		}

		/**
		\~korean
		¹è¿­³»ÀÇ ÇÏ³ªÀÇ µ¥ÀÌÅÍ¸¦ Á¦°ÅÇÕ´Ï´Ù.
		\param index Á¦°ÅÇÒ ¹è¿­ÀÇ index°ª

		\~english TODO:translate needed.
		Remove one datum within the array
		\param index Index value of the array to be removed


		\~chinese
		?ğ¶ÛÉÖªñéîÜìé?Data¡£
		\param index é©?ğ¶îÜÛÉÖªîÜindex?¡£

		\~japanese
		ÛÕÖª?ªÎìéªÄªÎ«Ç?«¿ªòğ¶ËÛª·ªŞª¹¡£
		\param index ğ¶ËÛª¹ªëÛÕÖªªÎindexö·
		\~
		*/
		inline void RemoveAt(int index)
		{
			RemoveRange(index, 1);
		}

		/**
		\~korean
		¹è¿­À» ºñ¿ó´Ï´Ù. capacity´Â º¯È­ÇÏÁö ¾Ê½À´Ï´Ù.

		\~english 
		Empty the array. The capacity does not change

		\~chinese
		?ÍöÛÉÖª¡£Capacity Üô??¡£

		\~japanese
		ÛÕÖªªËÍöªËª·ªŞª¹¡£CapacityªÏ?ûùª·ªŞª»ªó¡£
		\~
		*/
		inline void Clear()
		{
			SetCount(0);
			// capacity´Â ±×´ë·Î µÎ¾î¾ß ÇÔ. ¾È±×·¯¸é ¼º´ÉÀÌ °÷°÷¿¡¼­ Å©°Ô ÀúÇÏµÈ´Ù!
		}

		/**
		\~korean
		\return Data¹è¿­ÀÇ Æ÷ÀÎÅÍ¸¦ ¸®ÅÏÇÕ´Ï´Ù.

		\~english 
		\return the pointer of the data array.

		\~chinese
		\return return DataÛÉÖªîÜò¦?¡£

		\~japanese
		\return DataÛÕÖªªÎ«İ«¤«ó«¿?ªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		inline uint8_t* GetData()
		{
			if (!m_externalBuffer.IsNull())
			{
				return m_externalBuffer.GetData();
			}
			else if (GetTombstone() == NULL)
			{
				ThrowArrayIsNullError();
			}

			return GetTombstone()->m_substance.GetData();
		}

		/**
		\~korean
		\return Data¹è¿­ÀÇ const Æ÷ÀÎÅÍ¸¦ ¸®ÅÏÇÕ´Ï´Ù.

		\~english TODO:translate needed.
		\return the const pointer of the data array. 

		\~chinese
		\return return DataÛÉÖªîÜconstò¦?¡£

		\~japanese
		\return DataÛÕÖªªÎconst«İ«¤«ó«¿?ªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		inline const uint8_t* GetData() const
		{
			if (m_externalBuffer.IsNull() == false)
				return m_externalBuffer.GetData();
			else if (GetTombstone() == NULL)
			{
				ThrowArrayIsNullError();
			}

			return GetTombstone()->m_substance.GetData();
		}

		/**
		\~korean
		\return ¹è¿­ÀÇ º¹»çº»À» ¸®ÅÏÇÕ´Ï´Ù.

		\~english TODO:translate needed.
		\return the copy of the array

		\~chinese
		\return  returnÛÉÖªîÜ?Üâ¡£

		\~japanese
		\return ÛÕÖªªÎ«³«Ô?ªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		inline ByteArrayPtr Clone()
		{
			if(!m_externalBuffer.IsNull())
				ThrowException(MustNotExternalBufferError);

			ByteArrayPtr ret;

			if(GetTombstone())
			{
				ret.UseInternalBuffer();
				ret.SetCount(GetCount());
			}
			CopyRangeTo(ret, 0, GetCount());

			return ret;
		}

		/**
		\~korean
		µ¥ÀÌÅÍµéÀ» dest·Î º¹»çÇÕ
		\param dest º¹»ç¹ŞÀ» °´Ã¼
		\param srcOffset º¹»ç¸¦ ½ÃÀÛÇÒ ¿øº» ¹è¿­ÀÇ À§Ä¡
		\param count º¹»ç ¹ŞÀ» ¹è¿­ÀÇ Å©±â

		\~english TODO:translate needed.
		copy data to dest
		\param dest object to be copied 
		\param srcOffset Location of the original array to start copying
		\param count Size of the array to be copied 

		\~chinese
		??Ëß?ğ¤Óğdest¡£
		\param dest  ïÈáô?ğ¤îÜËÔ?¡£
		\param srcOffset  é©?ã·?ğ¤îÜê«ÜâîÜÛÉÖªêÈöÇ¡£
		\param count ïÈáô?ğ¤îÜÛÉÖªîÜÓŞá³¡£

		\~japanese
		«Ç?«¿ªòdestªØ«³«Ô?ª·ªŞª¹¡£
		\param dest «³«Ô?ª·ªÆªâªéª¦«ª«Ö«¸«§«¯«È
		\param srcOffset «³«Ô?ªòËÒã·ª¹ªëê«ÜâÛÕÖªªÎêÈöÇ
		\param count «³«Ô?ª·ªÆªâªéª¦ÛÕÖªªÎ«µ«¤«º
		\~
		*/
		template<typename BYTEARRAYT>
		inline void CopyRangeToT(BYTEARRAYT &dest, int srcOffset, int count) const
		{
			if (count <= 0)
				return;

			if (dest.GetCount() < srcOffset + count)
				ThrowArrayOutOfBoundException();

			if (!GetData() || !dest.GetData())
				ThrowInvalidArgumentException();

			UnsafeFastMemmove(dest.GetData(), GetData() + srcOffset, count * sizeof(uint8_t));
		}

		/**
		\~korean
		µ¥ÀÌÅÍµéÀ» dest·Î º¹»çÇÕ
		\param dest º¹»ç¹ŞÀ» ByteArrayPtr
		\param srcOffset º¹»ç¸¦ ½ÃÀÛÇÒ ¿øº» ¹è¿­ÀÇ À§Ä¡
		\param count º¹»ç ¹ŞÀ» ¹è¿­ÀÇ Å©±â

		\~english TODO:translate needed.
		copy data to dest
		\param dest ByteArrayPtr to be copied
		\param srcOffset Location of the original array to start copying
		\param count Size of the array to be copied

		\~chinese
		??Ëß?ğ¤Óğdest¡£
		\param dest ïÈáô?ğ¤îÜ ByteArrayPtr
		\param srcOffset é©?ã·?ğ¤îÜê«ÜâÛÉÖªîÜêÈöÇ¡£
		\param count ïÈáô?ğ¤îÜÛÉÖªîÜÓŞá³¡£

		\~japanese
		«Ç?«¿ªòdestªØ«³«Ô?ª·ªŞª¹¡£
		\param dest «³«Ô?ª·ªÆªâªéª¦ByteArrayPtr
		\param srcOffset «³«Ô?ªòËÒã·ª¹ªëê«ÜâÛÕÖªªÎêÈöÇ
		\param count «³«Ô?ª·ªÆªâªéª¦ÛÕÖªªÎ«µ«¤«º
		\~
		*/
		void CopyRangeTo(ByteArrayPtr &dest, int srcOffset, int count) const
		{
			CopyRangeToT<ByteArrayPtr>(dest,srcOffset,count);
		}

		/**
		\~korean
		µ¥ÀÌÅÍµéÀ» dest·Î º¹»çÇÕ
		\param dest º¹»ç¹ŞÀ» ByteArray
		\param srcOffset º¹»ç¸¦ ½ÃÀÛÇÒ ¿øº» ¹è¿­ÀÇ À§Ä¡
		\param count º¹»ç ¹ŞÀ» ¹è¿­ÀÇ Å©±â

		\~english TODO:translate needed.
		copy data to dest
		\param dest ByteArray to be copied
		\param srcOffset Location of the original array to start copying
		\param count Size of the array to be copied


		\~chinese
		??Ëß?ğ¤Óğdest¡£
		\param dest é©ïÈáô?ğ¤îÜ ByteArray
		\param srcOffset é©?ã·?ğ¤îÜê«ÜâîÜÛÉÖªêÈöÇ¡£
		\param count é©ïÈáô?ğ¤îÜÛÉÖªîÜÓŞá³¡£

		\~japanese
		«Ç?«¿ªòdestªØ«³«Ô?ª·ªŞª¹¡£
		\param dest «³«Ô?ª·ªÆªâªéª¦ByteArray
		\param srcOffset «³«Ô?ªòËÒã·ª¹ªëê«ÜâÛÕÖªªÎêÈöÇ
		\param count «³«Ô?ª·ªÆªâªéª¦ÛÕÖªªÎ«µ«¤«º
		\~
		*/
		void CopyRangeTo(ByteArray& dest, int srcOffset, int count) const
		{
			CopyRangeToT<ByteArray>(dest,srcOffset,count);
		}

		inline uint8_t& operator[](int index)
		{
			if (m_externalBuffer.IsNull()==false)
				return m_externalBuffer[index];
			else
			{
				if(GetTombstone())
					return GetTombstone()->m_substance.operator[](index);
				else
				{
					// UE4¿¡¼­´Â throw Å°¿öµå¸¦ ¸ø ¾´´Ù. µû¶ó¼­ ÀÌ·¸°Ô ÇÔ¼ö·Î Æ÷ÀåÇÏ¿© throw Å°¿öµå¸¦ ºñ³ëÃâ½ÃÅ²´Ù.
					ThrowArrayIsNullError();
					return m_externalBuffer[0]; // unreachable code. just preventing 'Control may reach end of non-void function' warning
				}
			}
		}

		inline const uint8_t operator[](int index) const
		{
			if (m_externalBuffer.IsNull() == false)
				return m_externalBuffer[index];
			else
			{
				if (GetTombstone())
					return GetTombstone()->m_substance.operator[](index);
				else
				{
					// UE4¿¡¼­´Â throw Å°¿öµå¸¦ ¸ø ¾´´Ù. µû¶ó¼­ ÀÌ·¸°Ô ÇÔ¼ö·Î Æ÷ÀåÇÏ¿© throw Å°¿öµå¸¦ ºñ³ëÃâ½ÃÅ²´Ù.
					ThrowArrayIsNullError();
					return m_externalBuffer[0]; // unreachable code. just preventing 'Control may reach end of non-void function' warning
				}
			}
		}


		/**
		\~korean
		\return ÀÌ °´Ã¼ÀÇ ¹è¿­ Å©±â°¡ Áõ°¡ÇÒ ¶§ °¡ÁßÄ¡ Å¸ÀÔ

		\~english 
		\return Weighted value when the array size of this object increases. 

		\~chinese
		\return ?ó®ËÔ?îÜÛÉÖªÓŞá³ñòÊ¥?îÜÊ¥ñì??úş¡£

		\~japanese
		\return ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎÛÕÖª«µ«¤«ºª¬?Ê¥ª¹ªëãÁªÎÊ¥ñìö·«¿«¤«×
		\~
		*/
		inline GrowPolicy GetGrowPolicy() const
		{
			if (GetTombstone() != NULL)
				GetTombstone()->m_substance.GetGrowPolicy();

			return GrowPolicy_Normal;
		}

		/**
		\~korean
		ÀÌ °´Ã¼ÀÇ ¹è¿­ Å©±â°¡ Áõ°¡ÇÒ ¶§ °¡ÁßÄ¡ Å¸ÀÔÀ» ¼³Á¤ÇÑ´Ù.
		ÀÚ¼¼ÇÑ ³»¿ëÀº GrowPolicy À» ÂüÁ¶
		\param val Áõ°¡ÇÒ ¶§ÀÇ °¡ÁßÄ¡ Å¸ÀÔ

		\~english TODO:translate needed.
		The weighted value type is set when the array size of this object increases. 
		For more details, refer to GrowPolicy
		\param val The weighted value type when increasing

		\~chinese
		?öÇó®ËÔ?îÜÛÉÖªÓŞá³ñòÊ¥?îÜÊ¥ñì?¡£
		???é»?ÍÅGrowPolicy¡£
		\param val ñòÊ¥?îÜÊ¥ñì?îÜ?úş¡£

		\~japanese
		ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎÛÕÖª«µ«¤«ºª¬?Ê¥ª¹ªëãÁªÎÊ¥ñìö·«¿«¤«×ªòàâïÒª·ªŞª¹¡£
		ßÙª·ª¯ªÏ¡¢GrowPolicy ªòª´?ğÎª¯ªÀªµª¤¡£
		\param val ?Ê¥ª¹ªëãÁªÎÊ¥ñìö·«¿«¤«× 
		\~
		*/
		void SetGrowPolicy(GrowPolicy val)
		{
			if (GetTombstone() != NULL)
				GetTombstone()->m_substance.SetGrowPolicy(val);
			else
			{
				// none
			}
		}

		/**
		\~korean
		ÃÖ¼Ò ¹öÆÛ Å©±â¸¦ ¼³Á¤ÇÑ´Ù. ¹öÆÛ(capacity)Å©±â°¡ Áõ°¡ÇÒ ¶§ ÃÖ¼ÒÇÑ ÀÌ »çÀÌÁîº¸´Ù Å©°Ô ¼³Á¤ÇÑ´Ù.
		\param val ÃÖ¼Ò Capacity size

		\~english TODO:translate needed.
		Set the minimum buffer size. When the buffer (capacity) size increases, set it at least bigger than this size. 
		\param val Minimum capacity size

		\~chinese
		?öÇõÌá³bufferîÜÓŞá³¡£?Buffer£¨Capacity£©ÓŞá³ñòÊ¥?ò¸á´é©?öÇà÷İïó®ÓŞá³ÓŞîÜ?¡£
		\param val õÌá³Capacity size

		\~japanese
		õÌá³«Ğ«Ã«Õ«¡?«µ«¤«ºªòàâïÒª·ªŞª¹¡£«Ğ«Ã«Õ«¡?(capacity)«µ«¤«ºª¬?Ê¥ª¹ªëãÁ¡¢á´ªÊª¯ªÈªâª³ªÎ«µ«¤«ºªèªêÓŞª­ª¯àâïÒª·ªŞª¹¡£ 
		\param val õÌá³ Capacity size 
		\~
		*/
		void SetMinCapacity(int val)
		{
			if(GetTombstone())
				GetTombstone()->m_substance.SetMinCapacity(val);
			else
			{
				// none
			}
		}

		/**
		\~korean
		ÀÌ°ÍÀ» ÃÊ±â¿¡ È£ÃâÇÏ¸é ³»ºÎ ¹öÆÛ¸¦ »ı¼ºÇÏ¿© »ç¿ëÇÑ´Ù.

		\~english TODO:translate needed.
		If you call this at the initial stage, generate and use an internal buffer

		\~chinese
		î¤ôøÑ¢û¼õó??£¬?ßæà÷?ŞÅéÄ?İ»Buffer¡£

		\~japanese
		ª³ªìªòôøÑ¢ªËû¼ªÓõóª¹ªÈ?İ»«Ğ«Ã«Õ«¡?ªòßæà÷ª·ªÆŞÅª¤ªŞª¹¡£
		\~
		*/
		inline void UseInternalBuffer()
		{
			if(!m_externalBuffer.IsNull())
				ThrowException(AlreadyHasExternalBufferError);

			InitTombstoneIfEmpty();

		}

		/**
		\~korean
		ÀÌ°É ÃÊ±â¿¡ È£ÃâÇÏ¸é ÀÌ °´Ã¼´Â ¿ÜºÎ ¹öÆÛ¸¦ »ç¿ëÇÑ´Ù.

		\~english
		If you call this at the beginning, this object use external buffer

		\~chinese
		î¤ôøÑ¢û¼õó??£¬ó®ËÔ??ŞÅéÄèâİ»Buffer¡£

		\~japanese
		ª³ªìªòôøÑ¢ªËû¼ªÓõóª¹ªÈ?İ»«Ğ«Ã«Õ«¡?ªòßæà÷ª·ªÆŞÅª¤ªŞª¹¡£
		\~
		*/
		inline void UseExternalBuffer(uint8_t* buf, int capacity)
		{
			if (GetTombstone() != NULL)
				ThrowException(AlreadyHasInternalBufferError);
			else if (m_externalBuffer.IsNull() == false)
				ThrowException(AlreadyHasExternalBufferError);

			m_externalBuffer.Init(buf, capacity);
		}

		/**
		\~korean
		UseInternalBuffer, UseExternalBuffer ¸¦ Àç»ç¿ëÇÏ·Á¸é ÀÌ ¸Ş¼­µå¸¦ È£ÃâÇÒ °Í.

		\~english
		Call this method if you want to reuse UseInternalBuffer,UseExternalBuffer

		\~chinese
		åıÍıßÌî¢ó­ŞÅéÄUseInternalBuffer , UseExternalBuffer £¬ û¼õóó®Û°Ûö¡£

		\~japanese
		UseInternalBuffer, UseExternalBufferªòî¢ŞÅéÄª¹ªëª¿ªáªËªÏª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª¹ª³ªÈ¡£
		\~
		*/
		void UninitBuffer()
		{
			UninitTombstone();
			m_externalBuffer.Uninit();
		}

		/**
		\~korean
		\return NULLÀÌ¸é true, NULLÀÌ ¾Æ´Ï¸é false¸¦ ¸®ÅÏÇÑ´Ù.

		\~english TODO:translate needed.
		\return true if null, otherwise return false.

		\~chinese
		\return  NULLîÜ?true,ÜôãÀNULLîÜ?return false¡£

		\~japanese
		\return NULLªÇª¢ªìªĞtrue¡¢NULLªÇªÏªÊª±ªìªĞfalseªò«ê«¿?«óª·ªŞª¹¡£ 
		\~
		*/
		inline bool IsNull() const
		{
			return (GetTombstone() == NULL && m_externalBuffer.IsNull());
		}

// 		inline ByteArray& GetInternalBufferRef()
// 		{
// 			MustInternalBuffer();
// 			return *m_tombstone;
// 		}

		/**
		\~korean
		³»ºÎ ¹öÆÛ¸¦ »ç¿ëÇÏ°í ÀÖ´Â °ÍÀÌ ¾Æ´Ï¸é ¿¹¿Ü¸¦ ¹ß»ı½ÃÅ²´Ù.

		\~english TODO:translate needed.
		Generate an exception if an internal buffer is not being used.

		\~chinese
		åıÍıÜôãÀŞÅéÄ?İ»Buffer£¬ŞÅñıßæà÷ÖÇèâ¡£

		\~japanese
		?İ»«Ğ«Ã«Õ«¡?ªòŞÅªÃªÆª¤ªëªÎªÇªÏªÊª±ªìªĞÖÇèâªò?ßæªµª»ªŞª¹¡£
		\~
		*/
		inline void MustInternalBuffer()
		{
			if (GetTombstone() == NULL)
			{
				ThrowException(MustInternalBufferError);
			}
		}

		/**
		\~korean
		rhs¿Í ³»¿ëÀÌ µ¿ÀÏÇÑÁö Ã¼Å©ÇÑ´Ù.
		- ÁÖÀÇ: ´Ü¼ø ¸Ş¸ğ¸® ºñ±³´Ù. ÀÌ Á¡À» ÁÖÀÇÇÒ °Í.
		\param rhs ºñ±³ÇÒ ByteArrayPtr
		\return °°À¸¸é true ´Ù¸£¸é false¸¦ ¸®ÅÏÇÑ´Ù.

		\~english TODO:translate needed.
		 Check to see if the content is the same as rhs
		- Caution: this is a simple comparison of memory. Use caution.
		\param rhs ByteArrayPtr to be compared
		\return true if the same, otherwise return false

		\~chinese
		??ãÀÜú?rhsîÜ?é»ìéöÈ¡£
		- ñ¼ëò£ºñşãÀ??îÜ?ğíİï?¡£é©ñ¼ëò?ìéïÃ¡£
		\param rhs é©İï?îÜ ByteArrayPtr
		\return åıÍıìé?îÜ?true£¬Üú?return false¡£

		\~japanese
		RhsªÈ?é»ª¬ÔÒª¸ªÊªÎª«ªò«Á«§«Ã«¯ª·ªŞª¹¡£
		- ª´ñ¼ëò£º?âí«á«â«ê?İïÎòªÇª¹¡£ª³ªìªËª´ñ¼ëòª¯ªÀªµª¤¡£
		\param rhs İïÎòª¹ªë ByteArrayPtr
		\return ÔÒª¸ªÇª¢ªëªÈtrue¡¢ì¶ªÊªëªÈfalseªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		inline bool Equals(const ByteArrayPtr &rhs) const
		{
			if (rhs.GetCount() != GetCount())
				return false;

			// ´Ü¼ø ¸Ş¸ğ¸® ºñ±³´Ù.
			const uint8_t* p_rhs = (uint8_t*)rhs.GetData();
			const uint8_t* p_lhs = (uint8_t*)GetData();
			return memcmp(p_rhs, p_lhs, rhs.GetCount() * sizeof(uint8_t)) == 0;
		}


	};

	//////////////////////////////////////////////////////////////////////////
	// UE4 x86 or x64¿¡¼­ link error°¡ ³­´Ù. µû¶ó¼­ ºÒ°¡ÇÇÇÏ°Ô ÀÌ·¸°Ô ºñ ÅÛÇÃ¸´ ÇüÅÂÀÇ ÇÔ¼ö¸¦ È£ÃâÇÏµµ·Ï ±¸ÇöÇÔ.
	// #UE4_PATCH
	// TODO: ¾÷±×·¹ÀÌµå °³¹ßÀ» ÇÏ´Ù°¡, ¾ğÁ¨°¡ ¾Æ·¡ ÄÚµå°¡ ¹İº¹µÉ °Í °°À¸¸é ¸ÅÅ©·ÎÈ­ÇÏ¿© ¿ìÈ¸ÇÏµµ·Ï ÇÏÀÚ.

	void* ByteArrayPtr_AllocTombstone();
	void ByteArrayPtr_FreeTombstone(void* tombstone);

	template<>
	inline BiasManagedPointer<ByteArray, true>::Tombstone* BiasManagedPointer<ByteArray, true>::AllocTombstone()
	{
		return (BiasManagedPointer<ByteArray, true>::Tombstone*)ByteArrayPtr_AllocTombstone();
	}

	template<>
	inline void BiasManagedPointer<ByteArray, true>::FreeTombstone(BiasManagedPointer<ByteArray, true>::Tombstone* tombstone)
	{
		return ByteArrayPtr_FreeTombstone((void*)tombstone);
	}


	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif