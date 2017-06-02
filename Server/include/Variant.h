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

// NOTE: º» ¸ğµâÀº ¼­¹ö Àü¿ëÀÌ´Ù. UE4 µî¿¡¼­´Â OLE-COM API¸¦ »ç¿ë ºÒ°¡ÇÏ¹Ç·Î.

#if defined(_WIN32)
    #include <comutil.h>
	#include <ATLComTime.h>
#endif

#include "ByteArrayPtr.h"
#include "pnguid-win32.h"
#include "./FakeClrBase.h"
#include "./PnTime.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup db_group
	*  @{
	*/

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4244)
#endif

#if defined(_WIN32)
	/** 
	\~korean
	variant.
	_variant_t¿Í ºñ½ÁÇÑ ¿ªÇÒÀ» ÇÏÁö¸¸, UUID, int64 µîÀÇ Ã³¸® ±â´ÉÀÌ ºÎ°¡ÀûÀ¸·Î µé¾î°¡ ÀÖ´Ù.
	- ÀÌ °´Ã¼´Â UUID¸¦ bracket stringÀ¸·Î º¯È¯ÇØ¼­ °¡Áø´Ù.
	- ÀÌ °´Ã¼´Â int64¸¦ VariantChangeType()´ë½Å ÀÚÃ¼ ±¸ÇöµÈ º¯È¯±â¸¦ °¡Áø´Ù. 
	(VariantChangeType¿¡¼­ 64bit integer Áö¿øÀº Windows XP¿¡¼­ºÎÅÍ Áö¿øÇÏ±â ¶§¹®ÀÌ´Ù.) 

	\~english
	variant.
	This module works similar to _variant_t, but additionally handles UUID, int64 and etc.
	- This object has an UUID after converting it to braket string.
	- This object has a custom converter of int64 instead of VariantChangeType(). 
	(Because VariantChangeType¿¡¼­ 64bit integer is already supported in Windows XP.)

	\~chinese
	variant.
	ÑÃó·?_variant_ßÓŞÄîÜíÂéÄ£¬Ó£?èâ?ôÕÊ¥ÖõUUID, int64Ôõ?×âÍíÒö¡£
	- ó®?ßÚ÷êUUIDéÄbracket string??ì»?ö¢¡£
	- ó®?ßÚ?êóÓÛôğVariantChangeType()?int64?ú¼í»ãó??îÜ??Ïõ¡£
	£¨î¤VariantChangeType×ìò¨ò¥64bit integerãÀì×??Windows XP?ã·ò¨ò¥¡££©

	\~japanese
	variant.
	_variant_tªÈ×¾ŞÄª·ª¿æµùÜªòª·ªŞª¹ª¬¡¢UUID¡¢int64ªÊªÉªÎ?×âÑ¦Òöª¬ÜõÊ¥îÜªËìıªÃªÆª¤ªŞª¹¡£
	- ª³ªÎ«ª«Ö«¸«§«¯«ÈªÏUUIDªòbracket stringªË?üµª·ªÆò¥ªÁªŞª¹¡£
	- ª³ªÎ«ª«Ö«¸«§«¯«ÈªÏint64ªòVariantChangeType()ªÎÓÛªïªêªËí»ªé?úŞª·ª¿?üµĞïªòò¥ªÁªŞª¹¡£ 
	(VariantChangeTypeªÇªÎ64bit integerªÎ«µ«İ?«ÈªÏ¡¢Windows XPª«ªé«µ«İ?«Èª¹ªëª«ªéªÇª¹¡£) 
	\~
	*/
	class CVariant
	{
	public:
		_variant_t m_val;

		// ¾Æ·¡ ¸¹Àº constructorµéÀº _variant_t¿¡¼­ µû¿Â °ÍÀÌ´Ù. ÇÊ¿äÇÑ °æ¿ì 
		// ÀÌ·¯ÇÑ °Íµé(constructor,operator=,extractor operator)¸¦ ¸¸µéµµ·Ï ÇÏÀÚ. 
		inline CVariant() {}
		inline CVariant(const _variant_t &src) { m_val=src; }
		inline CVariant(VARENUM vartype){V_VT(&m_val) = vartype;}

		inline CVariant(char a) { m_val=(long)a; }
		inline CVariant(short a) { m_val=(long)a; }
		inline CVariant(int a) { m_val=(long)a; }
		inline CVariant(long a) { m_val=a; }
		inline CVariant(int64_t a) { m_val=a; }
		inline CVariant(unsigned char a) { m_val=a; }
		inline CVariant(unsigned short a) { m_val=a; }
		inline CVariant(unsigned int a) { m_val=a; }
		inline CVariant(unsigned long a) { m_val=a; }
		inline CVariant(uint64_t a) { m_val=a; }
		inline CVariant(float a) { m_val=a; }
		inline CVariant(double a) { m_val=a; }
		inline CVariant(const wchar_t* a) { m_val = _bstr_t(a); }
		inline CVariant(const char* a) { m_val=_bstr_t(a); }
		inline CVariant(const String& a) { m_val=_bstr_t(a.GetString()); }
		inline CVariant(UUID a) { m_val = Win32Guid::From(a).ToBracketString().GetString(); }
		inline CVariant(Guid a) { m_val = a.ToBracketString().GetString(); }
		inline CVariant(bool a) { m_val=(long)a; }
		inline CVariant(const COleDateTime& a) { m_val = a; }
		inline CVariant(const ByteArray& a){FromByteArray(a);}
		inline CVariant(const ByteArrayPtr a){FromByteArray(a);}

		/** 
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator char() const { ThrowIfNull(); return (long)m_val; }

		/** 
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator short() const { ThrowIfNull(); return (long)m_val; }

		/** 
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator int() const { ThrowIfNull(); return (long)m_val; }

		/** 
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator long() const { ThrowIfNull(); return m_val; }

		/** 
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator unsigned char() const { ThrowIfNull(); return m_val; }

		/** 
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À.

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator unsigned short() const { ThrowIfNull(); return m_val; }

		/** 
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator unsigned int() const { ThrowIfNull(); return m_val; }

		/** 
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator unsigned long() const { ThrowIfNull(); return m_val; }

		/** 
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator float() const { ThrowIfNull(); return m_val; }

		/** 
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator double() const { ThrowIfNull(); return m_val; }

		/**
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator String() const { ThrowIfNull(); return String((const PNTCHAR*)(_bstr_t)m_val); }

		/** 
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator UUID() const { ThrowIfNull(); return Win32Guid::ToNative(Guid::GetFromString((_bstr_t)m_val)); }

		/** 
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator Guid() const { ThrowIfNull(); return Guid::GetFromString((_bstr_t)m_val); }

		/** 
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator bool() const { ThrowIfNull(); return m_val; }	

		/** 
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator COleDateTime() const { ThrowIfNull(); return m_val; }

		/**
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À.

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£
		\~
		*/
		inline operator int64_t() const { ThrowIfNull(); return m_val; }
		
		/** 
		\~korean
		¸®ÅÏ°ª ¿¬»êÀÚÀÔ´Ï´Ù. ¸¸¾à ÀÌ °´Ã¼°¡ null °ªÀ» °®°í ÀÖÀ¸¸é ¿¹¿Ü°¡ throwµË´Ï´Ù. µû¶ó¼­ ÇÊ¿äÇÑ °æ¿ì IsNull()·Î ¸ÕÀú nullÀÎÁö ¿©ºÎ¸¦ È®ÀÎÇÏ½Ê½Ã¿À. 

		\~english
		This is a returned value operator, which throws an exception if it contains null values. So please confirm the value is null or not by IsNull() first.

		\~chinese
		Ú÷üŞ??ß©İ¬¡£åıÍıó®?ßÚ?êónull?îÜ?£¬ÖÇèâ?ù¬throw¡£ì×ó®âÍé©îÜ?à»éÄIsNull()??nullîÜ?Üú¡£

		\~japanese
		«ê«¿?«óö·æÑß©í­ªÇª¹¡£ªâª·¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èª¬nullö·ªòò¥ªÃªÆª¤ªìªĞÖÇèâª¬throwªËªÊªêªŞª¹¡£ªèªÃªÆ¡¢ù±é©ªÊíŞùê¡¢IsNull()ªÇªŞªºnullªÊªÎª«ªÉª¦ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£ 
		\~
		*/
		inline operator uint64_t() const { ThrowIfNull(); return m_val; }
		//inline operator ByteArray() const {return ToByteArray();}
		inline operator ByteArrayPtr() const {return ToByteArrayPtr();}

		/** 
		\~korean
		°ªÀÌ µé¾îÀÖ´ÂÁö Ã¼Å©ÇÑ´Ù. 

		\~english
		This method checks whether or not a value is included.

		\~chinese
		??ãÀÜúêó?¡£

		\~japanese
		ö·ª¬ìıªÃªÆª¤ªëª«ªò«Á«§«Ã«¯ª·ªŞª¹¡£
		\~
		*/
		inline bool IsNull() const { return m_val.vt == VT_NULL; } 

		/** 
		\~koeran
		ÀÌÁø µ¥ÀÌÅÍ ºí·° ÇüÅÂ·Î µ¥ÀÌÅÍ¸¦ ¸®ÅÏÇÑ´Ù. 

		\~english
		This method returns data in byte data block.

		\~chinese
		ì¤byte?Ëßblockû¡ãÒÚ÷üŞ?Ëß¡£

		\~japanese
		ì£òä«Ç?«¿«Ö«í«Ã«¯û¡÷¾ªÇ«Ç?«¿ªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		PROUD_API void ToByteArray(ByteArray &output) const;

		/**
		\~korean
		ÀÌÁø µ¥ÀÌÅÍ ºí·° ÇüÅÂ·Î µ¥ÀÌÅÍ¸¦ ¸®ÅÏÇÑ´Ù. 

		\~english
		This method returns data in byte data block.

		\~chinese
		ì¤byte?Ëßblockû¡ãÒÚ÷üŞ?Ëß¡£

		\~japanese
		ì£òä«Ç?«¿«Ö«í«Ã«¯û¡÷¾ªÇ«Ç?«¿ªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		PROUD_API ByteArrayPtr ToByteArrayPtr() const;

		/** 
		\~korean
		ÀÌÁø µ¥ÀÌÅÍ ºí·°À» ÀÔ·Â¹Ş´Â´Ù. 

		\~english
		This method inputs data in byte data block.

		\~chinese
		?ìıbyte?Ëßblock¡£

		\~japanese
		ì£òä«Ç?«¿«Ö«í«Ã«¯ªòìıÕôª·ªÆªâªéª¤ªŞª¹¡£
		\~
		*/
		PROUD_API void  FromByteArray(const ByteArray& input);

		/** 
		\~korean
		ÀÌÁø µ¥ÀÌÅÍ ºí·°À» ÀÔ·Â¹Ş´Â´Ù. 

		\~english
		This method inputs data in byte data block.

		\~chinese
		?ìıbyte?Ëßblock¡£

		\~japanese
		ì£òä«Ç?«¿«Ö«í«Ã«¯ªòìıÕôª·ªÆªâªéª¤ªŞª¹¡£
		\~
		*/
		PROUD_API void  FromByteArray(const ByteArrayPtr input);
	//private: VariantToByteArray ¶§¹®¿¡ public
		void ThrowIfNull() const;
	};
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
