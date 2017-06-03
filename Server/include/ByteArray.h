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

#include "FastArray.h"
#include "PNString.h"

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
	¹ÙÀÌÆ® ¹è¿­. ProudNetÀÇ ¿ëµµ¿¡ ¸Â°Ô ÃÖÀûÈ­µÇ¾î ÀÖ´Ù.
	- ³×Æ®¿öÅ© ÆĞÅ¶À» ÁÖ°í ¹Ş´Â ¸ñÀûÀÌ¹Ç·Î int32·Î¸¸ »ç¿ëÀ» °­Á¦ÇÑ´Ù.
	- ByteArray´Â operator new,deleteµµ ¿À¹ö¶óÀÌµåµÇ¾î¼­ fast heapÀ» Á¢±ÙÇÏ°í ÀÖ´Ù. µû¶ó¼­	»ç¿ë½Ã Proud.CFastHeapÀÇ ÁÖÀÇ»çÇ× ±Ô¾àÀ» ÁØ¼öÇØ¾ß ÇÑ´Ù.

	\~english TODO:translate needed.
	Byte array. It is optimized for the use of ProudNet
	- Since the purpose is to give and receive network packets, use is mandatory only in int32
	- The ByteArray is overridden in the operator new and delete, so it approaches fast heap. When using, the caution rules of Proud.CFastHeap must be complied with


	\~chinese
	Byte ÛÉÖª¡£ì«?ûùà÷ÎÁéÄProudNetéÄÔ²¡£
	- ì×ĞìÙÍîÜãÀ????ËßøĞñı?îÜÎß?£¬ì×ó®Ë­ğ¤ŞÅéÄint32¡£
	- BytesArrayõ±?Öõoperator new,delete,ì×ó®ïÈĞÎfast heap¡£á¶ì¤î¤ŞÅéÄ?é©ñåáú Proud.CFastHeap%îÜñ¼ëòŞÀ??íñ¡£

	\japanese
	«Ğ«¤«ÈÛÕÖª¡£ProudNetªÎéÄÔ²ªËùêªïª»ªÆõÌîêûùªµªìªÆª¤ªŞª¹¡£
	- «Í«Ã«È«ï?«¯«Ñ«±«Ã«Èªòªäªêö¢ªêª¹ªëÙÍîÜªÇª¹ªÎªÇ¡¢int32ªÇªÎªßŞÅéÄªò?ğ¤ª·ªŞª¹¡£
	- ByteArrayªÏoperator new¡¢deleteªâ«ª?«Ğ?«é«¤«ÉªµªìªÆ¡¢fast heapªË«¢«×«í?«Áª·ªÆª¤ªŞª¹¡£ªèªÃªÆ¡¢ŞÅéÄãÁªËProud.CFastHeapªÎª´ñ¼ëòŞÀú£ªÎĞ®å³ªòâ÷áúª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
	\~
	\todo translate it.
	 */
	class ByteArray :public CFastArray < uint8_t, false, true, int >
	{
	public:
		typedef CFastArray<uint8_t, false, true, int> Base;
// 		PROUD_API static void* LookasideAllocator_Alloc(size_t length);
// 		PROUD_API static void LookasideAllocator_Free(void* ptr);
        
	public:
//#ifndef __MARMALADE__
//#pragma push_macro("new")
//#undef new
		//DECLARE_NEW_AND_DELETE
//		void* operator new(size_t size)
//		{
//			return LookasideAllocator_Alloc(size);
//		}
//		void operator delete(void* ptr, size_t /*size */)
//		{
//			LookasideAllocator_Free(ptr);
//		}
//#pragma pop_macro("new")
//#endif // __MARMALADE__

		/** 
		\~korean
		±âº» »ı¼ºÀÚ

		\~english
		Defalut constructor

		\~chinese
		ĞñÜâßæà÷íº¡£

		\~japanese
		ĞñÜâßæà÷í­
		\~
		 */
		inline ByteArray()
		{
		}

		/** 
		\~korean
		¿ÜºÎ µ¥ÀÌÅÍ¸¦ º¹»çÇØ¿À´Â »ı¼ºÀÚ
		\param data º¹»çÇØ¿Ã BYTE¹è¿­ÀÇ Æ÷ÀÎÅÍ
		\param count count ¸¸Å­À» º¹»çÇÑ´Ù.

		\~english TODO:translate needed.
		Constructor copies external data 
		\param data
		\param count

		\~chinese
		?ğ¤èâİ»?ËßîÜßæà÷íº¡£
		\param date é©?ğ¤îÜBYTEÛÉÖªîÜò¦?¡£
		\param count ?ğ¤ßÓ?éÍcountîÜÕá¡£ 

		\~japanese
		èâİ»«Ç?«¿ªò«³«Ô?ª·ªÆª¯ªëßæà÷í­
		\param data «³«Ô?ª·ªÆª¯ªëBYTEÛÕÖªªÎ«İ«¤«ó«¿?
		\param count count ªÀª±ªò«³«Ô?ª·ªŞª¹¡£
		\~
		 */
		inline ByteArray(const uint8_t* data, int count):Base(data,count)
		{
		}

		/** 
		\~korean
		¿ÜºÎ µ¥ÀÌÅÍ¸¦ º¹»çÇØ¿À´Â »ı¼ºÀÚ
		\param src º¹»çÇÒ ByteArray ¿øº»

		\~english TODO:translate needed.
		Constructor copies external data
		\param src

		\~chinese
		?ğ¤èâİ»?ËßîÜßæà÷íº¡£
		\param src é©?ğ¤îÜBytesArrayê«Ëì¡£

		\~japanese
		èâİ»«Ç?«¿ªò«³«Ô?ª·ªÆª¯ªëßæà÷í­
		\param src «³«Ô?ª¹ªëByteArrayê«Üâ
		\~
		 */
		inline ByteArray(const ByteArray &src):Base(src)
		{
		}

		virtual ~ByteArray();

// 		BUG PRONE! µû¶ó¼­ ¸·¾Æ¹ö·È´Ù.
		/*
						\~korean
						»ı¼ºÀÚ. ´Ü, ¹è¿­ Å©±â¸¦ ¹Ì¸® ¼³Á¤ÇÑ´Ù.
						\~english
						Constructor. But it must have previously set array size.
						\~
						 */
// 		inline ByteArray(int count):CFastArray<BYTE,true>(count)
// 		{
// 		}

		/** 
		\~korean
		¹è¿­À» 16Áø¼öÀÇ StringÀ¸·Î º¯È¯ÇÏ¿© returnÇØÁØ´Ù.
		\return StringÀ¸·Î º¯È¯µÈ 16Áø¼ö ¹è¿­ (¿¹ L"FFAB123")

		\~english TODO:translate needed.
		The array is returned by being transformed in a hexadecimal string
		\return Hexadecimal array converted with String (ex: L¡±FFAB123¡±)

		\~chinese
		?ÛÉÖª??à÷16??¡£
		??à÷
		\return StringîÜ16??ÛÉÖª¡££¨ÖÇ£ºL¡±FFAB123¡±£©

		\~japanese
		ÛÕÖªªò16òä?ªÎStringªË?üµª·ªÆreturnª·ªÆª¯ªìªŞª¹¡£
		\return StringªË?üµªµªìª¿16òä?ªÎÛÕÖª£¨ÖÇ£ºL"FFAB123")
		\~
		*/
		String ToHexString();

		/**
		\~korean
		16Áø¼ö ¹è¿­ StringÀ» 16Áø¼ö·Î ¹Ù²Ù¾îÁØ´Ù.
		\param 16Áø¼ö ¹è¿­ String (¿¹ text = L"FFFFEAB12")
		\return º¯È¯ÀÌ ¼º°øÇÏ¸é true, ½ÇÆĞÇÏ¸é false

		\~english TODO:translate needed.
		A hexadecimal array string is converted into a hexadecimal number
		\param hexadecimal array String (ex. Text = L"FFFFEAB12")
		\return conversion is successful, it is true. If failed, it is false. 	

		\~chinese
		?16??ÛÉÖªString?à÷16??¡£
		\param 16??ÛÉÖªString £¨ÖÇ£ºtext=L¡±FFFFEAB12¡±£©
		\return ??à÷Íí?true£¬Üú??false¡£

		\~japanese
		16òä?ªÎÛÕÖªStringªò16òä?ªË?ª¨ªÆª¯ªìªŞª¹¡£
		\param 16òä?ªÎÛÕÖªString (ÖÇ£ºtext = L"FFFFEAB12")
		\return ?üµª¬à÷Ííª¹ªëªÈtrue¡¢ã÷ø¨ª¹ªëªÈfalse
		\~
		*/
		bool FromHexString(String text);
	};
	
	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

