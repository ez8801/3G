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
#include "FastArray.h"
#include "FastArrayPtr.h"
#include "CriticalSect.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	·£´ı°ª »ı¼º±â

	Æ¯Â¡
	- seed°¡ °°À¸¸é ·£´ı°ªµéÀº µ¿ÀÏÇÏ´Ù.

	ÀÏ¹İÀû ¿ëµµ
	- CRandom °´Ã¼¸¦ »ı¼ºÇÑ ÈÄ InitializeSeed()³ª SetSeed() ÃÖÃÊ 1È¸ ÈÄ GetInt(), GetInt64, GetFloat µîÀ» ¾²¸é µÈ´Ù.
	- ¸í½ÃÀû ·£´ı ºĞÆ÷¸¦ ¿ä±¸ÇÏÁö ¾ÊÀ¸¸é ±×³É StaticGet*()¸¦ »ç¿ëÇÏ¶ó.
	- ¸í½ÃÀû ·£´ı ºĞÆ÷¸¦ ÇÊ¿ä·Î ÇÏ¸é ÀÌ °´Ã¼¸¦ ¸¸µé¾î¼­ InitializeSeed()¸¦ ÃÖÃÊ ÇÑ¹ø¸¸ È£ÃâÇÑ ÈÄ
	Get*()¸¦ »ç¿ëÇÏ¶ó. 

	\~english
	Random value generator

	Characteristics
	- If seeds are same then the randome values are same.

	General usage
	- After creating CRandom object,use GetInt(), GetInt64, GetFloat and so on after calling InitializeSeed() or SetSeed() once for the first time.
	- If explicit random distribution is not required then just use StaticGet*().
	- If explicit random distribution is required then create this object, call InitializeSeed() once for the first time then use Get*().

	\~chinese
	?Ïõ?ßæà÷Ğï

	÷åïÖ
	- seedßÓÔÒîÜ??Ïõ?ßÓÔÒ¡£

	ìéÚõîÜéÄÔ²
	- ßæà÷ CRandom%?ßÚì¤ı¨InitializeSeed()ûäíºSetSeed()õÌôø1üŞì¤ı¨ŞÅéÄGetInt(), GetInt64, GetFloatÔõ?Ê¦¡£
	- Üôé©Ï´??îÜ?ÏõİÂøÖîÜ?ö¦ŞÅéÄStaticGet*()?¡£
	- âÍé©??îÜ?ÏõİÂøÖîÜ??Ëïó®?ßÚì¤ı¨£¬ò¸á´û¼Ğ£ìéó­InitializeSeed()î¢ŞÅéÄGet*()?¡£

	\~japanese
	«é«ó«À«àö·«¸«§«ì«ì?«¿?

	÷å?
	- seedª¬ÔÒª¸ªÇª¢ªìªĞ«é«ó«À«àö·ªÏÔÒª¸ªÇª¹¡£

	ìéÚõîÜªÊéÄÔ²
	- CRandom «ª«Ö«¸«§«¯«Èªòßæà÷ª·ª¿ı­¡¢InitializeSeed()ªÈª«SetSeed()ªòõÌôø1üŞı­¡¢GetInt(), GetInt64, GetFloat ªÊªÉªòŞÅªÃªÆª¯ªÀªµª¤¡£
	- Ù¥ãÆîÜ«é«ó«À«àİÂøÖªòé©Ï´ª·ªÊª±ªìªĞª¿ªÀ StaticGet*()ªòŞÅªÃªÆª¯ªÀªµª¤¡£
	- Ù¥ãÆîÜ«é«ó«À«àİÂøÖªòù±é©ªÈª¹ªìªĞª³ªÎ«ª«Ö«¸«§«¯«ÈªòíÂªÃªÆInitializeSeed()ªòõÌôø1üŞªÎªßû¼ªÓõóª·ª¿ı­¡¢Get*()ªòŞÅªÃªÆª¯ªÀªµª¤¡£ 
	\~
	*/
	class CRandom
	{
	private:
		uint32_t m_dwState[625];
		uint32_t *m_pdwNext;
		int m_lLeft;
	
		uint32_t LoadMersenneTwister();
		double GetFloat_INTERNAL();
		static double StaticGetFloat_INTERNAL();

		CriticalSection m_cs;
	public:
		PROUD_API CRandom();
		PROUD_API virtual ~CRandom();

		/** 
		\~korean
		³­¼ö»ı¼º seed °ªÀ» ¼³Á¤ÇÕ´Ï´Ù. 

		\~english
		Set random number creating seed value

		\~chinese
		?öÇ??ßæà÷seed?¡£

		\~japanese
		??ßæà÷seedö·ªòàâïÒª·ªŞª¹¡£
		\~
		*/
		PROUD_API void InitializeSeed();

		/** 
		\~korean
		³­¼ö»ı¼º seed °ªÀ» Æ¯Á¤ °ªÀ¸·Î ¼³Á¤ÇÕ´Ï´Ù. 
		\param dwSeed ½Ãµå°ª

		\~english TODO:translate needed.
		Set random number creating seed value to specific value.

		\~chinese
		?öÇ??ßæà÷seed??÷åïÒ?¡£
		\param dwSeed seed?

		\~japanese
		??ßæà÷seedö·ªò÷åïÒö·ªËàâïÒª·ªŞª¹¡£
		\param dwSeed «·?«Éö·
		\~
		*/
		PROUD_API void SetSeed(uint32_t dwSeed);

		/** 
		\~korean
		·£´ı°ªÀ» ¸¸µç´Ù. INT_MIN~INT_MAX Áß ÇÏ³ªÀÌ´Ù. 

		\~english
		Creates random value. One value between INT_MIN~INT_MAX

		\~chinese
		ßæà÷?Ïõ?¡£INT_MIN~INT_MAX ñéñıìé¡£

		\~japanese
		«é«ó«À«àö·ªòíÂªêªŞª¹¡£INT_MIN~INT_MAXªÎìéªÄªÇª¹¡£ 
		\~
		*/
		PROUD_API int GetInt();

		/** 
		\~korean
		·£´ı°ªÀ» ¸¸µç´Ù. INT64_MIN~INT64_MAX Áß ÇÏ³ªÀÌ´Ù.

		\~english
		Creates random value. One value between INT64_MIN~INT64_MAX

		\~chinese
		ßæà÷?Ïõ?¡£INT64_MIN~INT64_MAX ñéñıìé¡£

		\~japanese
		«é«ó«À«àö·ªòíÂªêªŞª¹¡£INT64_MIN~INT64_MAXªÎìéªÄªÇª¹¡£
		\~
		*/
		PROUD_API int64_t GetInt64();

		/** 
		\~korean
		Àü¿ª °´Ã¼·Î ¸¸µé¾îÁø CRandom À¸·ÎºÎÅÍ °ªÀ» ±¸ÇÑ´Ù. thread safeÇÏ´Ù.

		\~english
		Gets value from CRandom that created with global object. It does thread safe.

		\~chinese
		î¤îïæ´?ßÚßæà÷îÜ CRandom%ñéÏ´?¡£ãÀthread safeîÜ¡£

		\~japanese
		îïæ´«ª«Ö«¸«§«¯«ÈªÇíÂªéªìª¿CRandomªèªêö·ªòÏ´ªáªŞª¹¡£thread safeªÇª¹¡£
		\~
		*/
		PROUD_API static int StaticGetInt();

		/** 
		\~korean
		Àü¿ª °´Ã¼·Î ¸¸µé¾îÁø CRandom À¸·ÎºÎÅÍ °ªÀ» ±¸ÇÑ´Ù. thread safeÇÏ´Ù. 

		\~english
		Gets value from CRandom that created with global object. It does thread safe.

		\~chinese
		î¤îïæ´?ßÚßæà÷îÜ CRandom%ñéÏ´?¡£ãÀthread safeîÜ¡£

		\~japanese
		îïæ´«ª«Ö«¸«§«¯«ÈªÇíÂªéªìª¿CRandomªèªêö·ªòÏ´ªáªŞª¹¡£thread safeªÇª¹¡£
		\~
		*/
		PROUD_API static int64_t StaticGetInt64();

		/** 
		\~korean
		Àü¿ª °´Ã¼·Î ¸¸µé¾îÁø CRandom À¸·ÎºÎÅÍ °ªÀ» ±¸ÇÑ´Ù. 0~1 »çÀÌÀÇ ºÎµ¿¼Ò¼öÁ¡ °ªÀÌ´Ù. thread safeÇÏ´Ù. 

		\~english
		Gets value from CRandom that created with global object. It is floating point value between 0 to 1. It does thread safe.

		\~chinese
		î¤îïæ´?ßÚßæà÷îÜ CRandom%ñéÏ´?¡£0~1ñı?îÜİ©ïÃ?¡£ãÀthread safeîÜ¡£

		\~japanese
		îïæ´«ª«Ö«¸«§«¯«ÈªÇíÂªéªìª¿CRandomªèªêö·ªòÏ´ªáªŞª¹¡£0~1ªÎÊàªÎÜôÔÑá³?ïÃö·ªÇª¹¡£thread safeªÇª¹¡£
		\~
		*/
		PROUD_API double GetFloat();
		
		/** 
		\~korean
		Àü¿ª °´Ã¼·Î ¸¸µé¾îÁø CRandom À¸·ÎºÎÅÍ °ªÀ» ±¸ÇÑ´Ù. 0~1 »çÀÌÀÇ ºÎµ¿¼Ò¼öÁ¡ °ªÀÌ´Ù. thread safeÇÏ´Ù. 

		\~english
		Gets value from CRandom that created with global object. It is floating point value between 0 to 1. It does thread safe.

		\~chinese
		î¤îïæ´?ßÚßæà÷îÜ CRandom%ñéÏ´?¡£0~1ñı?îÜİ©ïÃ?¡£ãÀthread safeîÜ¡£

		\~japanese
		îïæ´«ª«Ö«¸«§«¯«ÈªÇíÂªéªìª¿CRandomªèªêö·ªòÏ´ªáªŞª¹¡£0~1ªÎÊàªÎÜôÔÑá³?ïÃö·ªÇª¹¡£thread safeªÇª¹¡£
		\~
		*/
		PROUD_API static double StaticGetFloat();
	};


	template<typename T>
	T GetRandomElement(const CFastArray<T>& arr)
	{
		if (arr.GetSize() == 0)
			return 0;
		else
			return arr[CRandom::StaticGetInt()%arr.GetSize()];
	}

#if defined(_WIN32)    
	template<typename T>
	T GetRandomElement(const std::vector<T>& arr)
	{
		if (arr.size() == 0)
			return 0;
		else
			return arr[CRandom::StaticGetInt()%arr.size()];
	}
#endif
    
	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
