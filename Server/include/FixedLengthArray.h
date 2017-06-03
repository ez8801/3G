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
	°íÁ¤ Å©±âÀÇ ¹è¿­ Å¬·¡½º. 
	- T data[] Çü½ÄÀÇ °íÁ¤ Å©±â ´Ü¼ø ¹è¿­À» bounds checkingÀ» ÇÏ·Á¸é ÀÌ Å¬·¡½º·Î ´ëÃ¼ÇØ¼­ ¾ÈÁ¤¼ºÀ» µµ¸ğÇÒ ¼ö ÀÖ´Ù.

	ÀÏ¹İÀû ¿ëµµ
	- CAtlArray ¸¦ Ä«ÇÇÇØ´Ù ¸¸µé¾úÀ¸¹Ç·Î CAtlArray ¿Í »ç¿ë¹ıÀÌ °ÅÀÇ À¯»çÇÏ´Ù. ´Ü, staticÀÌ´Ï ´ç¿¬ÇÏÁö¸¸, »ğÀÔ/Á¦°Å/Ã»¼Ò µîÀÇ ±â´ÉÀÌ ºüÁ®ÀÖ´Ù. 

	ÁÖÀÇ»çÇ×
	- ±âÁ¸ Á¤Àû ¹è¿­À» CFixedLengthArray ·Î ¹Ù²Ü °æ¿ì _countof()³ª sizeof()¸¦ ¾²´Â °æ¿ì°¡ ÀÖÀ» ÅÍÀÎµ¥, ÀÌ·¯ÇÑ ºÎºĞÀ» Ã£¾Æ¼­ ¼öÁ¤ÇØ¾ß ÇÑ´Ù.
	¿¹ÄÁ´ë _countof()´Â Ç×»ó 1À» ¸®ÅÏÇÒ °ÍÀÌ±â ¶§¹®ÀÌ´Ù.

	\~english
	Array class with fixed size 
	- To 'bounds check' a simple, fixed size array of T data[] format, it is possible to replace with this class to draw stability.

	General usage
	- Has similar usage of CAtlArray since this is copied and made from it, but it does not have insertion/removal/cleanup functions since it is static. (of course...) 

	Note
	- If replacing the existing static array with CFixedLengthArray then there can be cases that either _countof() or sizeof() is used. << must modify them correctly.
	This is because of the fact that _countof() will always return 1.

	\~chinese
	Í³ïÒÓŞá³îÜ???¡£
	- ßÌbounds checking T data[]û¡ãÒîÜÍ³ïÒÓŞá³????£¬éÄó®?ÓÛôğı¨Ê¦?ÔğÌÚû¿îÜ?ïÒàõ¡£

	ìéÚõéÄÔ²
	- ì×?ãÀ?ğ¤ CAtlArray%ğ¤íÂîÜ£¬á¶ì¤? CAtlArray%îÜŞÅéÄÛ°ÛöĞñÜâßÓŞÄ¡£ì×?ãÀstaticá¶ì¤ù±ïÒ?ßÓŞÄ£¬Ó£×ìØüÊ¿?êó?ìı/?ğ¶/?ğ¶ÔõÍíÒö¡£

	ñ¼ëòŞÀßÚ
	- ßÌ÷êñıîñ????ôğ?? CFixedLengthArray%îÜ?£¬Ê¦Òö?êóéÄ_countof()ûäíºsizeof()£¬é©?Óğ?ŞÁ?????ú¼áóËÇ¡£
	ÖÇåı£¬ì×?_countof()ìéòÁ?Ú÷üŞ1¡£

	\~japanese
	Í³ïÒ«µ«¤«ºªÎÛÕÖª«¯«é«¹
	- T data[] û¡ãÒªÎÍ³ïÒ«µ«¤«ºªÎ?âíÛÕÖªªòbounds checkingª¹ªëª¿ªáªËªÏ¡¢ª³ªÎ«¯«é«¹ªËôğªïªÃªÆäÌïÒàõªò?ªëª³ªÈª¬ªÇª­ªŞª¹¡£

	ìéÚõîÜªÊéÄÔ²
	- CAtlArrayªò«³«Ô?ª·ªÆŞÅªÃª¿ª¿ªá¡¢CAtlArrayªÈŞÅéÄÛ°Ûöª¬ªÛªÜ×¾ŞÄª·ªÆª¤ªŞª¹¡£Ó£ª·¡¢staticªÊªÎªÇ?æÔªÇª¹ª¬¡¢?ìı/ğ¶ËÛ/á·ğ¶ªÊªÉªÎÑ¦Òöª¬?ª±ªÆª¤ªŞª¹¡£ 

	ª´ñ¼ëòŞÀú£
	- ?ğíªÎ«¹«¿«Æ«£«Ã«¯ÛÕÖªªòCFixedLengthArrayªË?ª¨ªëíŞùê¡¢_countof()ª«sizeof()ªòŞÅª¦íŞùêª¬ª¢ªêªŞª¹ª¬¡¢ª³ªÎªèª¦ªÊİ»İÂªò÷®ª·ªÆáóïáª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
	ÖÇª¨ªĞ¡¢_countof()ªÏª¤ªÄªâ1ªò«ê«¿?«óª¹ªëªÏªºªÀª«ªéªÇª¹¡£
	\~
	*/
	template<int size,typename TYPE, typename ARG_TYPE = const TYPE&>
	class CFixedLengthArray 
	{
	public:

		// Á¦´ë·Î µÈ ÀÎµ¦½º ¹øÈ£°¡ ¾Æ´Ï¸é ¿¡·¯ ¹ß»ıÇÑ´Ù.
		inline void CheckValidIndex(int nIndex) const
		{
			if(!(0<=nIndex && nIndex<size) )
				ThrowArrayOutOfBoundException();
		}

		/**
		\~korean
		¹è¿­ ±æÀÌ¸¦ ±¸ÇÑ´Ù.

		\~english
		Gets length of array

		\~chinese
		Ï´???Óø¡£

		\~japanese
		ÛÕÖªªÎíşªµªòÏ´ªáªŞª¹¡£
		\~
		*/
		inline int GetSize() const { return size; }

		/**
		\~korean
		¹è¿­ ±æÀÌ¸¦ ±¸ÇÑ´Ù.

		\~english
		Gets length of array

		\~chinese
		Ï´???Óø¡£

		\~japanese
		ÛÕÖªªÎíşªµªòÏ´ªáªŞª¹¡£
		\~
		*/
		inline int GetCount() const { return size; }

		/**
		\~korean
		¹è¿­ÀÌ ºñ¾ú´Â°¡?

		\~english
		Is array empty?

		\~chinese
		??ÍöÖõ?£¿

		\~japanese
		ÛÕÖªª¬Íöª¤ªÆª¤ªŞª¹ª«£¿
		\~
		*/
		inline bool IsEmpty() const { return size==0; }

		/**
		\~korean
		¹è¿­ Ç×¸ñ Á¢±ÙÀÚ 

		\~english
		Array item accessor

		\~chinese
		???ÙÍ??íº¡£

		\~japanese
		ÛÕÖªú£ÙÍªÎïÈĞÎíº
		\~
		*/
		inline const TYPE& GetAt(int nIndex) const { CheckValidIndex(nIndex); return m_data[nIndex]; }

		/**
		\~korean
		¹è¿­ Ç×¸ñ Á¢±ÙÀÚ

		\~english
		Array item accessor 

		\~chinese
		???ÙÍ??íº¡£

		\~japanese
		ÛÕÖªú£ÙÍªÎïÈĞÎíº
		\~
		*/
		inline TYPE& GetAt(int nIndex) { CheckValidIndex(nIndex); return m_data[nIndex]; }	

		/**
		\~korean
		¹è¿­ Ç×¸ñ Á¢±ÙÀÚ

		\~english
		Array item accessor 

		\~chinese
		???ÙÍ??íº¡£

		\~japanese
		ÛÕÖªú£ÙÍªÎïÈĞÎíº
		\~
		*/
		inline void SetAt(int nIndex, ARG_TYPE newElement) { CheckValidIndex(nIndex); m_data[nIndex]=newElement; }

		/**
		\~korean
		¹è¿­ Ç×¸ñ Á¢±ÙÀÚ

		\~english
		Array item accessor

		\~chinese
		???ÙÍ??íº¡£

		\~japanese
		ÛÕÖªú£ÙÍªÎïÈĞÎíº
		\~
		*/
		inline const TYPE& ElementAt(int nIndex) const {CheckValidIndex(nIndex); return m_data[nIndex]; }

		/**
		\~korean
		¹è¿­ Ç×¸ñ Á¢±ÙÀÚ

		\~english
		Array item accessor

		\~chinese
		???ÙÍ??íº¡£

		\~japanese
		ÛÕÖªú£ÙÍªÎïÈĞÎíº
		\~
		*/
		inline TYPE& ElementAt(int nIndex){CheckValidIndex(nIndex); return m_data[nIndex];}

		/**
		\~korean
		¹è¿­ ¹öÆÛ °´Ã¼ÀÇ Æ÷ÀÎÅÍ¸¦ ¾ò´Â´Ù.

		\~english
		Gets pointer of array buffer object

		\~chinese
		?ö¢???ğí??ßÚîÜò¦?¡£

		\~japanese
		ÛÕÖª«Ğ«Ã«Õ«¡?«ª«Ö«¸«§«¯«ÈªÎ«İ«¤«ó«¿?ªòÔğªŞª¹¡£
		\~
		*/
		inline const TYPE* GetData() const {return m_data;}

		/**
		\~korean
		¹è¿­ ¹öÆÛ °´Ã¼ÀÇ Æ÷ÀÎÅÍ¸¦ ¾ò´Â´Ù.

		\~english
		Gets pointer of array buffer object

		\~chinese
		?ö¢???ğí??ßÚîÜò¦?¡£

		\~japanese
		ÛÕÖª«Ğ«Ã«Õ«¡?«ª«Ö«¸«§«¯«ÈªÎ«İ«¤«ó«¿?ªòÔğªŞª¹¡£
		\~
		*/
		inline TYPE* GetData(){return m_data;}

		/**
		\~korean
		¹è¿­ Ç×¸ñ Á¢±ÙÀÚ

		\~english
		Array item accessor

		\~chinese
		???ÙÍ??íº¡£

		\~japanese
		ÛÕÖªú£ÙÍªÎïÈĞÎíº
		\~
		*/
		inline const TYPE& operator[](int nIndex) const{CheckValidIndex(nIndex); return m_data[nIndex];}	
		
		/**
		\~korean
		¹è¿­ Ç×¸ñ Á¢±ÙÀÚ

		\~english
		Array item accessor

		\~chinese
		???ÙÍ??íº¡£

		\~japanese
		ÛÕÖªú£ÙÍªÎïÈĞÎíº
		\~
		*/
		inline TYPE& operator[](int nIndex){CheckValidIndex(nIndex); return m_data[nIndex];}

	private:
		TYPE m_data[size];   // the actual array of data
	};

	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
