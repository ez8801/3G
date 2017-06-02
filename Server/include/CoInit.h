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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup db_group
	*  @{
	*/

	/** 
	\~korean
	CoInitialize, CoUninitialize È£Ãâ ½ÖÀ» ¸ÂÃá´Ù.
	- ÀÏ¹İÀûÀ¸·Î CoInitialize¿Í CoUninitialize´Â È£Ãâ È½¼ö°¡ ±ÕÇüÀ» ¸ÂÃç¾ß ÇÏ¸ç, °¢ ½º·¹µå º°·Î È£ÃâÇØ¾ß ÇÏ´Â ¸Ş¼­µåÀÌ´Ù.
	ÀÚ¼¼ÇÑ °ÍÀº °¢ APIÀÇ ¹®¼­¸¦ Âü°íÇÒ °Í.
	- Á÷Á¢ CoInitialize(), CoUninitialize()¸¦ È£ÃâÇÏ´Â °Íº¸´Ù ÀÌ Å¬·¡½º¸¦ ·ÎÄÃ º¯¼ö·Î ¼±¾ğÇÏ´Â °ÍÀÌ ´õ ¾ÈÁ¤ÀûÀÌ´Ù.
	ÀÌ Å¬·¡½º´Â ÀÚµ¿À¸·Î CoUninitialize()¸¦ ÇÊ¿äÇÒ ¶§ È£ÃâÇÏ±â ¶§¹®ÀÌ´Ù.
	
	\~english
	This method works in a set of CoInitialize and CoUninitialize call.
	- It needs to be called per each threads and normally the number of calls for CoInitialize and CoUninitialize should be balanced.
	Refer to API document for more detailed information.
	- It's safer to declare this class as a local variable rather than directly calling for CoInitialize() and CoUninitialize(),
	since it automatically calls for CoUninitialize() when needed.
	
	\~chinese
	CoInitialize, CoUninitializeû¼Ğ£??¡£
	- ìéÚõ??CoInitializeûúCoUninitializeîÜû¼Ğ£ó­?é©?ñ×øÁû¬£¬ì¤Øß?ïïû¼Ğ£îÜÛ°ãÒ¡£
	??îÜ??ÍÅÊÀAPIÙşËì¡£
	- İïÑÃòÁïÈû¼Ğ£CoInitialize()£¬CoUninitialize()Û°Ûö£¬÷êó®?à¾Í±?Üâò¢??ÌÚ?ïÒ¡£
	ì×?ó®?âÍé©CoUninitialize()îÜ?ı¦?í»?û¼Ğ£¡£
	
	\~japanese
	CoInitialize, CoUninitialize û¼ªÓõóª·«Ú«¢ªòùêªïª»ªŞª¹¡£
	- ìéÚõîÜªË¡¢CoInitializeªÈCoUninitializeªÏû¼ªÓõóª·üŞ?ªË«Ğ«é«ó«¹ªòö¢ªëù±é©ª¬ª¢ªÃªÆ¡¢ÊÀ«¹«ì«Ã«ÉÜ¬ªËû¼ªÓõóªµªÊª±ªìªĞªÊªéªÊª¤«á«½«Ã«ÉªÇª¹¡£
	ßÙª·ª¯ªÏÊÀAPIªÎÙşßöªòª´?ğÎª¯ªÀªµª¤¡£
	- òÁïÈCoInitialize(), CoUninitialize()ªòû¼ªÓõóª¹ª³ªÈªèªêªÏ¡¢ª³ªÎ«¯«é«¹ªò«í?«««ë??ªÇà¾åëª·ª¿Û°ª¬ªâªÃªÈäÌïÒîÜªÇª¹¡£
	ª³ªÎ«¯«é«¹ªÏí»ÔÑªËCoUninitialize()ªòù±é©ªÈª¹ªëãÁªËû¼ªÓõóª¹ª¿ªáªÇª¹¡£
	\~
	*/
	class CCoInitializer
	{
	private:
		bool m_success;

	public:
		PROUD_API CCoInitializer();
		PROUD_API ~CCoInitializer();
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif