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
	/** \addtogroup net_group
	*  @{
	*/

	// ÁÖÀÇ: ÀÌ°Íµµ ¹Ù²Ù¸é ProudClr namespaceÀÇ µ¿¸í ½Éº¼µµ ¼öÁ¤ÇØ¾ß ÇÑ´Ù.

	/** 
	\~korean
	¾ÏÈ£È­ ¹× º¹È£È­ ¼³Á¤°ªÀÔ´Ï´Ù.

	\~english
	Setup value of encryption and decryption

	\~chinese
	Ê¥ÚËì¤Ğàú°ÚË?ïÒ?¡£

	\~japanese
	äŞ?ûùĞàªÓÜÖ?ûùªÎàâïÒö·ªÇª¹¡£
	\~
	*/
	enum EncryptMode
	{
		/** 
		\~korean
		¾ÏÈ£È­¸¦ ¾ÈÇÕ´Ï´Ù.

		\~english
		Do not encrypt

		\~chinese
		ÜôÊ¥ÚË¡£

		\~japanese
		äŞ?ûùªòª·ªŞª»ªó¡£
		\~
		*/
		EM_None,		
		/** 
		\~korean
		RSA¿Í AES¸¦ È¥¿ëÇÑ ¾ÏÈ£È­¸¦ ¼öÇàÇÕ´Ï´Ù. ·Î±×¿Â µî º¸¾È¼ºÀÌ ³ôÀº ¸Ş½ÃÁö¿¡ ¾²½Ê½Ã¿À.

		\~english
		Do encryption that mixture with RSA and AES. Do not use with secure message such as logon

		\~chinese
		?ú¼ûèéÄRSAûúAESîÜÊ¥ÚË¡£éÄî¤ßÀÔô?ÔõäÌîïàõÍÔîÜãáãÓß¾¡£

		\~japanese
		RSAªÈAESªòûèéÄª·ª¿äŞ?ûùªòâÄú¼ª·ªŞª¹¡£«í«°«ª«óªÊªÉ«»«­«å«ê«Æ«£àõªÎÍÔª¤«á«Ã«»?«¸ªËŞÅªÃªÆª¯ªÀªµª¤¡£
		\~
		*/
		EM_Secure,		
		/** 
		\~korean
		RSA¿Í Fast¸¦ È¥¿ëÇÑ ¾ÏÈ£È­¸¦ ¼öÇàÇÕ´Ï´Ù. Ä³¸¯ÅÍ ÀÌµ¿ µî ¾à°£ÀÇ ¾ÏÈ£È­´Â ÇÊ¿äÇÏÁö¸¸ ¼º´É ¶ÇÇÑ °í·ÁÇØ¾ß ÇÏ´Â »óÈ²¿¡¼­ ¾²½Ê½Ã¿À.

		\~english
		Do encryption that mixture with RSA and Fast. Encryption is required like moving character but please consider about performance.

		\~chinese
		?ú¼ûèéÄRSAûúFastîÜÊ¥ÚË¡£åıÊÇßäì¹?Ôõ?Ê¥ÚËïïÓøÜôÍÔ£¬Ó£âÍÍÅ?àõÒöîÜ??ù»?ŞÅéÄó®Û°Ûö¡£ 

		\~japanese
		RSAªÈFastªòûèéÄª·ª¿äŞ?ûùªòâÄú¼ª·ªŞª¹¡£«­«ã«é«¯«¿?ì¹ÔÑªÊªÉá´ª·ªÎäŞ?ûùªÏù±é©ªÇª¹ª¬¡¢àõÒöªâÍÅÕçª¹ªÙª­?üÏªÇŞÅªÃªÆª¯ªÀªµª¤¡£
		\~
		*/
		EM_Fast,			
		EM_LAST,
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
