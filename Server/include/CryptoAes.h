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

#include "Enums.h"
#include "ByteArray.h"
#include "EncryptEnum.h"
#include "ByteArrayPtr.h"

#ifdef _MSC_VER
#pragma warning(disable:4267)
#endif // __MARMALADE__

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	class CCryptoAesKey;
	class CMessage;

	/** \addtogroup util_group
	*  @{
	*/

	/**
	\~korean
	Rijndael(·¹ÀÎ´Ş)Àº ºí·° ¾ÏÈ£È­ ¾Ë°í¸®ÁòÀÔ´Ï´Ù. ·¹ÀÎ´ŞÀº Joan Daeden°ú Vincent Rijmen¿¡ ÀÇÇØ ¸¸µé¾îÁ³°í AESÀÇ ÈÄº¸¿´½À´Ï´Ù.
	ÀÌ ¾ÏÈ£È­ ¾Ë°í¸®ÁòÀº ´Ù¾çÇÑ Å©±âÀÇ ºí·° ±æÀÌ¿Í Å° ±æÀÌ¸¦ °¡Áı´Ï´Ù. Å° ±æÀÌ´Â 128,192.256ºñÆ®ÀÌ¸ç ºí·°ÀÇ Å©±â´Â 128,192,256ºñÆ®ÀÔ´Ï´Ù.
	Å° ±æÀÌ¿Í ºí·Ï ±æÀÌ´Â ´Ù¾çÇÏ°Ô ¼±ÅÃµÇ¾îµµ µË´Ï´Ù. ºí·Ï ±æÀÌ, Å° ±æÀÌ ¸ğµÎ 32ºñÆ®ÀÇ ¹è¼ö·Î ½±°Ô È®Àå °¡´ÉÇÕ´Ï´Ù.

	·¹ÀÎ´ŞÀº ¸Å¿ì ´Ù¾çÇÑ Á¾·ùÀÇ ÇÏµå¿ş¾î ÇÁ·Î¼¼¼­¿¡¼­ ¸Å¿ì È¿°úÀûÀ¸·Î ±¸ÇöµÉ ¼ö ÀÖ½À´Ï´Ù.

	ÀÌ ±¸ÇöÀº Crptix tookit¿¡ ¾²ÀÎ Javaj ±¸ÇöÀ» ±âÃÊ·Î Á¦ÀÛµÇ¾úÀ¸¸ç ÀÌ´Â ¾Æ·¡¿¡¼­ Ã£À» ¼ö ÀÖ½À´Ï´Ù.
	<a href="http://www.efgh.com/software/rijndael.zip" target="_blank">http://www.efgh.com/software/rijndael.zip</a>

	Java ÄÚµå ÀÛ¼ºÀÚ: Raif S. Naffah, Paulo S. L. M. Barreto

	ÀÌ ±¸ÇöÀº ¿øÀúÀÛÀÚ¿¡ ÀÇÇØ °ø°³µÈ KAT Å×½ºÆ®¿¡¼­ ½ÃÇèµÇ¾úÀ¸¸ç °á°ú´Â ÀÌ»ó¹«¿´½À´Ï´Ù.

	\~english
	Rijndael (pronounced Reindaal) is a block cipher, designed by Joan Daemen and Vincent Rijmen as a candidate algorithm for the AES.
	The cipher has a variable block length and key length. The authors currently specify how to use keys with a length
	of 128, 192, or 256 bits to encrypt blocks with length of 128, 192 or 256 bits (all nine combinations of
	key length and block length are possible). Both block length and key length can be extended very easily to
	multiples of 32 bits.

	Rijndael can be implemented very efficiently on a wide range of processors and in hardware.

	This implementation is based on the Java Implementation used with the Cryptix toolkit found at:
	<a href="http://www.efgh.com/software/rijndael.zip" target="_blank">http://www.efgh.com/software/rijndael.zip</a>

	Java code authors: Raif S. Naffah, Paulo S. L. M. Barreto

	This Implementation was tested against KAT test published by the authors of the method and the
	results were identical.

	\~chinese
	RijndaelãÀblockÊ¥ÚËß©Ûö¡£RijndaelãÀë¦Joan DaedenûúVincent Rijmen?Ëï£¬ãÀAESîÜôğ?¡£
	ó®Ê¥ÚËß©Ûö?êóó·Òı?ûùÓŞá³îÜblock?Óøûúkey?Óø¡£key?ÓøãÀ128,192.256bit£¬blockîÜÓŞá³ãÀ128,192,256bit¡£
	key?Óøûúblock?ÓøÊ¦ì¤Òı???¡£block?Óø£¬key?ÓøÔ´Ê¦ì¤é»æ¶??ò¸32bitîÜÛÃ?¡£
	Rijndaelî¤Òı?ûùÌãËì?×âĞï×ì?ŞªßÈêóüùîÜ??õó?.
	Rijndaelì¤î¤Crptix tookitîÜJava?Ğñ?ğ¤ğãîÜ£¬Ê¦ì¤î¤ì¤ù»ò¢ò£?Óğ¡£
	<a href="http://www.efgh.com/software/rijndael.zip" target="_blank">http://www.efgh.com/software/rijndael.zip</a>
	JavaÓÛ?íÂíº£ºRaif S. Naffah, Paulo S. L. M. Barreto
	Rijndaelê«îÊíÂÍë?îÜKAT??ß¾???£¬?ÍıÙé?ßÈ¡£

	\~japanese
	Rijndael(«ì«¤«ó«À«ë)ªÏ«Ö«í«Ã«¯äŞ?ûù«¢«ë«´«ê«º«àªÇª¹¡£«ì«¤«ó«À«ëªÏJoan DaedenªÈVincent RijmenªËªèªÃªÆíÂªéªìªÆAESªÎı¦ÜÍ£æªÇª·ª¿¡£
	ª³ªÎäŞ?ûù«¢«ë«´«ê«º«àªÏÒı?ªÊ«µ«¤«ºªÎ«Ö«í«Ã«¯íşªµªÈ«­?íşªµªòò¥ªÁªŞª¹¡£«­?ªÎíşªµªÏ128,192.256«Ó«Ã«ÈªÇ¡¢«Ö«í«Ã«¯ªÎ«µ«¤«ºªÏ128,192,256«Ó«Ã«ÈªÇª¹¡£
	«­?íşªµªÈ«Ö«í«Ã«¯íşªµªÏÒı?ªÊàÔ?ªµªìªÆªâÕŞª¤ªÇª¹¡£«Ö«í«Ã«¯íşªµ¡¢«­?íşªµªÈªâ32«Ó«Ã«ÈªÎÛÃ?ªÇÊÛ?ªË?íåªÇª­ªŞª¹¡£
	«ì«¤«ó«À«ëªÏªÈªÆªâÒı?ªÊğú×¾ªÎ«Ï?«É«¦«§«¢«×«í«»«Ã«µ?ªÇªÈªÆªâ?ÍıîÜªË?úŞªµªìªëª³ªÈª¬ªÇª­ªŞª¹¡£
	ª³ªÎ?úŞªÏ¡¢Crptix tookitªÇŞÅªïªìª¿Javaj?úŞªò÷Ï÷»ªËíÂà÷ªµªìªÆ¡¢ª³ªìªÏù»ªÇÌ¸ªÄª±ªëª³ªÈª¬ªÇª­ªŞª¹¡£
	<ahref="http://www.efgh.com/software/rijndael.zip" target="_blank">http://www.efgh.com/software/rijndael.zip</a>
	Java «³?«ÉíÂà÷íº£ºRaif S. Naffah, Paulo S. L. M. Barreto
	ª³ªÎ?úŞªÏêªîÊíÂíºªËªèªÃªÆÍëËÒªµªìª¿KAT«Æ«¹«Èª¬ú¼ªïªìªÆÌ¿ÍıªÏì¶ßÈª¢ªêªŞª»ªóªÇª·ª¿¡£
	\~
	*/
	class CCryptoAes
	{
	public:
		/**
		\~korean
		- ECB, CBC, CFB ¸ğµå
		- ECB ¸ğµå : °°Àº ºí·°À» µÎ¹ø ¾ÏÈ£È­ ÇÏ¸é º»·¡ÀÇ ¾ÏÈ£È­ µÇÁö ¾ÊÀº º»¹®ÀÌ ³ª¿É´Ï´Ù.
		- CBC ¸ğµå : ÀÌÀü ºí·°°ú xor¿¬»êÀ» ÈÄ ¾ÏÈ£È­ ÇÕ´Ï´Ù.
		- CFB ¸ğµå : ÇØ´ç ºí·°À» ¾ÏÈ£È­ ÈÄ ÀÌÀü ºí·°°ú xor¿¬»êÀ» ÇÕ´Ï´Ù.

		\~english
		- ECB, CBC, CFB Mode
		- ECB Mode: when the same block is encrypted twice, the original unencrypted test appears. 
		- CBC mode: the previous block and xor calculation is encrypted afterwards. 
		- CFB mode: after the block is encrypted, it does xor calculation with the previous block. 
		

		\~chinese
		- ECB£¬CBC£¬CFBÙ¼ãÒ
		- ECBÙ¼ãÒ£ºÊ¥ÚËÔÒ?îÜblockîÜ??õó?ê«??êóÊ¥ÚËîÜê«Ùş¡£
		- CBCÙ¼ãÒ£º?ñıîñîÜblockûúxor?ß©ñıı¨Ê¥ÚË¡£
		- CFBÙ¼ãÒ£ºÊ¥ÚËßÓ?blockì¤ı¨?ñıîñîÜblock xor?ß©¡£

		\~japanese
		- ECB, CBC, CFB «â?«É
		- ECB«â?«É£ºÔÒª¸«Ö«í«Ã«¯ªò2üŞäŞ?ûùª¹ªëªÈÜâ?ªÎäŞ?ûùªµªìªÊª«ªÃª¿ÜâÙşª¬õóªŞª¹¡£
		- CBC«â?«É£ºì¤îñªÎ«Ö«í«Ã«¯ªÈxoræÑß©ªòú¼ªÃªÆª«ªéäŞ?ûùª·ªŞª¹¡£
		- CFB«â?«É£ºú±?«Ö«í«Ã«¯ªòäŞ?ûùª·ª¿ı­¡¢ì¤îñªÎ«Ö«í«Ã«¯ªÈxoræÑß©ªòú¼ª¤ªŞª¹¡£
		\~
		*/
		enum EncryptMode
		{
			ECB = 0,
			CBC = 1,
			CFB = 2
		};

	public:
		enum { DEFAULT_BLOCK_SIZE = 16 };
		enum { MAX_BLOCK_SIZE = 32, MAX_ROUNDS = 14, MAX_KC = 8, MAX_BC = 8 };

	public:
		CCryptoAes();
		virtual ~CCryptoAes();

	public:
		/**
		\~korean
		Å°¿Í ºí·ÏÀÇ ±æÀÌ 128ºñÆ®ÀÏ ¶§ - 9¶ó¿îµå
		- Å° ¶Ç´Â ºí·ÏÀÇ ±æÀÌ°¡ 192ºñÆ®ÀÏ ¶§ - 11¶ó¿îµå
		- Å° ¶Ç´Â ºí·ÏÀÇ ±æÀÌ°¡ 256ºñÆ®ÀÏ ¶§ - 13¶ó¿îµå
		- ºí·°»çÀÌÁî : ÇÑ¹ø¿¡ ¾ÏÈ£È­ µÇ´Â »çÀÌÁî

		\param outKey »ı¼ºµÈ ¾ÏÈ£È­ Å°°¡ ÀúÀåµË´Ï´Ù..
		\param inputKey 128/192/256-bit ¸¦ »ç¿ëÇÒ ¼ö ÀÖÀ¸¸ç ÃÊ±â AesÅ°¸¦ ¸¸µé±â À§ÇÑ ·£´ı ºí·° µ¥ÀÌÅÍÀÔ´Ï´Ù.
		\param keyLength 16, 24 ¶Ç´Â 32 bytes ÀÔ´Ï´Ù.
		\param blockSize Aes ¾Ë°í¸®Áò ³»ÀÇ ºí·° »çÀÌÁî ÀÔ´Ï´Ù. (16, 24 or 32 bytes).

		\~english TODO:translate needed.
		When the length of the key and the block is 128bit ? 9 rounds 
		- When the length of the key and the block is 192bit ? 9 rounds
		- When the length of the key and the block is 256bit ? 9 rounds
		- Block size: size that can be encrypted at once. 


		\param outKey Generated encryption key is saved
		\param inputKey The 128/192/256-bit can be used and this is the random block data to make the initial Aes key. 
		\param keyLength It¡¯s either 16, 24 or 32 bytes
		\param This is the block size within the Aes algorithm (16, 24 or 32 bytes). 

		\~chinese
		KeyûúblockîÜ?ÓøãÀ128bitîÜ?ı¦ ? 9üŞùê
		- keyûäíºblockîÜ?ÓøãÀ192bitîÜ?ı¦ ? 11üŞùê
		- keyûäíºblockîÜ?ÓøãÀ256bitîÜ?ı¦ ? 13üŞùê
		- blockÓŞá³£ºìéó­ÒöÊ¥ÚËîÜÓŞá³

		\param outKey ?ğíßæà÷îÜÊ¥ÚËûùkey
		\param inputKey Ê¦ì¤ŞÅéÄ128/192/256-bit£¬?Öõ?Ëïôøã·Aes keyîÜ?Ïõblock?Ëß¡£
		\param keyLength 16£¬24ûäíº32bytes¡£
		\param blockSize Aesß©Ûö?îÜbolckÓŞá³£¨16£¬24ûäíº32bytes£©

		\~japanese
		«­?ªÈ«Ö«í«Ã«¯ªÎíşªµ128«Ó«Ã«ÈªÇª¢ªëãÁ ? 9«é«¦«ó«É
		- «­?ªŞª¿ªÏ«Ö«í«Ã«¯ªÎíşªµª¬192«Ó«Ã«ÈªÇª¢ªëãÁ ? 11«é«¦«ó«É
		- «­?ªŞª¿ªÏ«Ö«í«Ã«¯ªÎíşªµª¬256«Ó«Ã«ÈªÇª¢ªëãÁ ? 13«é«¦«ó«É
		- «Ö«í«Ã«¯«µ«¤«º£ºìéÓøªËäŞ?ûùªµªìªë«µ«¤«º

		\param outKey ßæà÷ªµªìª¿äŞ?ûù«­?ª¬ÜÁğíªµªìªŞª¹¡£
		\param inputKey 128/192/256-bit ªòŞÅª¦ª³ªÈª¬ªÇª­¡¢ôøÑ¢Aes«­?ªòíÂªëª¿ªáªÎ«é«ó«À«à«Ö«í«Ã«¯«Ç?«¿ªÇª¹¡£
		\param keyLength 16, 24 ªŞª¿ªÏ 32 bytes ªÇª¹¡£
		\param blockSize Aes «¢«ë«´«ê«º«à?ªÎ«Ö«í«Ã«¯«µ«¤«ºªÇª¹¡£(16, 24 or 32 bytes).
		\~
		*/
		PROUD_API static bool ExpandFrom(CCryptoAesKey &outKey, const uint8_t* const inputKey, int keyLength = DEFAULT_BLOCK_SIZE, int blockSize = DEFAULT_BLOCK_SIZE);

		/**
		\~korean
		\param key ´ëÄªÅ°ÀÔ´Ï´Ù.
		\param inputLength ¾ÏÈ£È­ÇÒ µ¥ÀÌÅÍÀÇ ±æÀÌ
		\return ¾ÏÈ£È­µÈ µ¥ÀÌÅÍÀÇ ±æÀÌ

		\~english
		\param key Symmetric key
		\param inputLength Size of plain text
		\return Size of Encrypted result

		\~chinese
		\param key ??key
		\param inputLength é©Ê¥ÚËîÜ?Ëß?Óø
		\return Ê¥ÚËîÜ?Ëß?Óø

		\~japanese
		\param key ??«­?ªÇª¹¡£
		\param inputLength äŞ?ûùª¹ªë«Ç?«¿ªÎíşªµ
		\return äŞ?ûùªµªìª¿«Ç?«¿ªÎíşªµ
		\~
		*/
		PROUD_API static int GetEncryptSize(const CCryptoAesKey &key, int inputLength);

		/**
		\~korean
		µ¥ÀÌÅÍ¸¦ ¾ÏÈ£È­ ÇÕ´Ï´Ù.
		\param key ´ëÄªÅ°ÀÔ´Ï´Ù.
		\param input Æò¹® ¸Ş½ÃÁöÀÔ´Ï´Ù.
		\param inputLength Æò¹®ÀÇ »çÀÌÁîÀÔ´Ï´Ù.
		\param output ¾ÏÈ£È­µÈ °á°ú°ªÀÔ´Ï´Ù.
		\param outputLength ¾ÏÈ£È­µÈ °á°úÀÇ »çÀÌÁîÀÔ´Ï´Ù.
		\param initializationVector CBC, CFB ¸ğµå¿¡¼­ ¾ÏÈ£È­¸¦ À§ÇÑ ÃÊ±âÈ­ ÇÒ¶§ »ç¿ëÇÏ´Â º¤ÅÍÀÔ´Ï´Ù.
		\param initializationVectorLength initializationVectorÀÇ ¹ÙÀÌÆ® ±æÀÌ ÀÔ´Ï´Ù.
		\param encryptMode ¾ÏÈ£È­ ¸ğµå ÀÔ´Ï´Ù. ECB, CBC, CFB ¸ğµå°¡ ÀÖ½À´Ï´Ù.

		\~english
		Encrypt data
		\param key Symmetric key
		\param input Plain text message
		\param inputLength Size of plain text
		\param output Encrypted result value
		\param outputLength Size of Encrypted result
		\param initializationVector Initialization Vector (IV) for CBC or CFB mode encryption.
		\param initializationVectorLength Length of initializationVector in bytes.
		\param encryptMode Encryption mode. (ECB, CBC, CFB mode)

		\~chinese
		Ê¥ÚË?Ëß¡£
		\param key ??key¡£
		\param input Ù¥ÙşãáãÓ¡£
		\param inputLength Ù¥ÙşîÜÓŞá³
		\param output Ê¥ÚËîÜ?Íı?¡£
		\param outputLength Ê¥ÚËîÜ?ÍıÓŞá³¡£
		\param initializationVector î¤CBC£¬CFBÙ¼ãÒñé?Ê¥ÚË?ú¼ôøã·ûù?á¶ŞÅéÄîÜVector¡£
		\param initializationVectorLength ãÀ initializationVector Byte?Óø¡£
		\param encryptMode Ê¥ÚËÙ¼ãÒ¡£êóECB£¬CBC£¬CFBÙ¼ãÒ¡£

		\~japanese
		«Ç?«¿ªòäŞ?ûùª·ªŞª¹¡£
		\param key ??«­?ªÇª¹¡£
		\param input øÁÙş«á«Ã«»?«¸ªÇª¹¡£
		\param inputLength øÁÙşªÎ«µ«¤«ºªÇª¹¡£
		\param output äŞ?ûùªµªìª¿Ì¿Íıö·ªÇª¹¡£
		\param outputLength äŞ?ûùªµªìª¿Ì¿ÍıªÎ«µ«¤«ºªÇª¹¡£
		\param initializationVector CBC, CFB «â?«ÉªÇäŞ?ûùªÎª¿ªáªÎôøÑ¢ûùãÁªËŞÅª¦«Ù«¯«È«ëªÇª¹¡£
		\param initializationVectorLength initializationVectorªÎ«Ğ«¤«ÈíşªµªÇª¹¡£
		\param encryptMode äŞ?ûù«â?«ÉªÇª¹¡£ECB, CBC, CFB«â?«Éª¬ª¢ªêªŞª¹¡£
		\~
		*/
		PROUD_API static bool Encrypt(
			const CCryptoAesKey &key, 
			const uint8_t* const input, 
			int inputLength, 
			uint8_t *output, 
			int &outputLength, 
			uint8_t * initializationVector = NULL, 
			int initializationVectorLength = 0, 
			EncryptMode encryptMode = ECB
			);

		/**
		\~korean
		µ¥ÀÌÅÍ¸¦ º¹È£È­ ÇÕ´Ï´Ù.
		\param key ´ëÄªÅ° ÀÔ´Ï´Ù.
		\param input ¾ÏÈ£È­µÈ ¸Ş½ÃÁöÀÔ´Ï´Ù.
		\param inputLength ¾ÏÈ£È­µÈ ¸Ş½ÃÁöÀÇ »çÀÌÁîÀÔ´Ï´Ù.
		\param output º¹È£È­µÈ °á°ú°ª ÀÔ´Ï´Ù.
		\param outputLength º¹È£È­µÈ °á°ú°ªÀÇ »çÀÌÁîÀÔ´Ï´Ù.
		\param initializationVector CBC, CFB ¸ğµå¿¡¼­ ¾ÏÈ£È­¸¦ À§ÇÑ ÃÊ±âÈ­ ÇÒ¶§ »ç¿ëÇÏ´Â º¤ÅÍÀÔ´Ï´Ù.
		\param initializationVectorLength initializationVectorÀÇ ¹ÙÀÌÆ® ±æÀÌ ÀÔ´Ï´Ù.
		\param encryptMode ¾ÏÈ£È­ ¸ğµå ÀÔ´Ï´Ù. ECB, CBC, CFB ¸ğµå°¡ ÀÖ½À´Ï´Ù.

		\~english
		Decrypt data
		\param key Symmetric key
		\param input Encrypted message
		\param inputLength Size of Encrypted message
		\param output Decrypted result value
		\param outputLength Size of Decrypted text
		\param initializationVector Initialization Vector (IV) for CBC or CFB mode encryption.
		\param initializationVectorLength Length of initializationVector in bytes.
		\param encryptMode Encryption mode. (ECB, CBC, CFB mode)

		\~chinese
		÷ò??Ëß¡£
		\param key ??key¡£
		\param input Ê¥ÚËîÜãáãÓ¡£
		\param inputLength Ê¥ÚËãáãÓîÜÓŞá³
		\param output ??îÜ?Íı?¡£
		\param outputLength ??îÜ?ÍıÓŞá³¡£
		\param initializationVector î¤CBC£¬CFBÙ¼ãÒñé?Ê¥ÚË?ú¼ôøã·ûù?á¶ŞÅéÄîÜVector¡£
		\param initializationVectorLength ãÀ initializationVector Byte?Óø¡£
		\param encryptMode Ê¥ÚËÙ¼ãÒ¡£êóECB£¬CBC£¬CFBÙ¼ãÒ¡£

		\~japanese
		«Ç?«¿ªòÜÖ?ûùª·ªŞª¹¡£
		\param key ??«­?ªÇª¹¡£
		\param input äŞ?ûùªµªìª¿«á«Ã«»?«¸ªÇª¹¡£
		\param inputLength äŞ?ûùªµªìª¿«á«Ã«»?«¸ªÎ«µ«¤«ºªÇª¹¡£
		\param output ÜÖ?ûùªµªìª¿Ì¿Íıö·ªÇª¹¡£
		\param outputLength ÜÖ?ûùªµªìª¿Ì¿Íıö·ªÎ«µ«¤«ºªÇª¹¡£
		\param initializationVector CBC, CFB «â?«ÉªÇäŞ?ûùªÎª¿ªáªÎôøÑ¢ûùãÁªËŞÅª¦«Ù«¯«È«ëªÇª¹¡£
		\param initializationVectorLength initializationVectorªÎ«Ğ«¤«ÈíşªµªÇª¹¡£
		\param encryptMode äŞ?ûù«â?«ÉªÇª¹¡£ ECB, CBC, CFB «â?«Éª¬ª¢ªêªŞª¹¡£
		\~
		*/
		PROUD_API static bool Decrypt(
			const CCryptoAesKey &key, 
			const uint8_t* const input, 
			int inputLength, 
			uint8_t *output, 
			int &outputLength, 
			uint8_t * initializationVector = NULL, 
			int initializationVectorLength = 0,
			EncryptMode encryptMode = ECB
			);

		/**
		\~korean
		ByteArray¸¦ ¾ÏÈ£È­ ÇÕ´Ï´Ù.
		\param key ´ëÄªÅ°ÀÔ´Ï´Ù.
		\param input Æò¹® ¸Ş½ÃÁöÀÔ´Ï´Ù.
		\param output ¾ÏÈ£È­µÈ °á°ú°ªÀÔ´Ï´Ù.
		\param initializationVector CBC, CFB ¸ğµå¿¡¼­ ¾ÏÈ£È­¸¦ À§ÇÑ ÃÊ±âÈ­ ÇÒ¶§ »ç¿ëÇÏ´Â º¤ÅÍÀÔ´Ï´Ù.
		\param initializationVectorLength initializationVectorÀÇ ¹ÙÀÌÆ® ±æÀÌ ÀÔ´Ï´Ù.
		\param encryptMode ¾ÏÈ£È­ ¸ğµå ÀÔ´Ï´Ù. ECB, CBC, CFB ¸ğµå°¡ ÀÖ½À´Ï´Ù.

		\~english
		Encrypt ByteArray
		\param key Symmetric key
		\param input Plain text message
		\param output Encrypted result value
		\param initializationVector Initialization Vector (IV) for CBC or CFB mode encryption.
		\param initializationVectorLength Length of initializationVector in bytes.
		\param encryptMode Encryption mode. (ECB, CBC, CFB mode)

		\~chinese
		Ê¥ÚË ByteArray¡£
		\param key ??key¡£
		\param input Ù¥ÙşãáãÓ¡£
		\param output Ê¥ÚËîÜ?Íı?¡£
		\param initializationVector î¤CBC£¬CFBÙ¼ãÒñé?Ê¥ÚË?ú¼ôøã·ûù?á¶ŞÅéÄîÜVector¡£
		\param initializationVectorLength ãÀ initializationVector Byte?Óø¡£
		\param encryptMode Ê¥ÚËÙ¼ãÒ¡£êóECB£¬CBC£¬CFBÙ¼ãÒ¡£

		\~japanese
		ByteArrayªòäŞ?ûùª·ªŞª¹¡£
		\param key ??«­?ªÇª¹¡£
		\param input øÁÙş«á«Ã«»?«¸ªÇª¹¡£
		\param output äŞ?ûùªµªìª¿Ì¿Íıö·ªÇª¹¡£
		\param initializationVector CBC, CFB«â?«ÉªÇäŞ?ûùªÎª¿ªáªÎôøÑ¢ûùãÁªËŞÅª¦«Ù«¯«È«ëªÇª¹¡£
		\param initializationVectorLength initializationVectorªÎ«Ğ«¤«ÈíşªµªÇª¹¡£
		\param encryptMode äŞ?ûù«â?«ÉªÇª¹¡£ECB, CBC, CFB «â?«Éª¬ª¢ªêªŞª¹¡£
		\~
		*/
		PROUD_API static bool EncryptByteArray(
			const CCryptoAesKey &key, 
			const ByteArray &input, 
			ByteArray &output, 
			uint8_t * initializationVector = NULL, 
			int initializationVectorLength = 0, 
			EncryptMode encryptMode = ECB
			);

		/**
		\~korean
		ByteArray¸¦ º¹È£È­ ÇÕ´Ï´Ù.
		\param key ´ëÄªÅ° ÀÔ´Ï´Ù.
		\param input ¾ÏÈ£È­µÈ ¸Ş½ÃÁöÀÔ´Ï´Ù.
		\param output º¹È£È­µÈ °á°ú°ª ÀÔ´Ï´Ù.
		\param initializationVector CBC, CFB ¸ğµå¿¡¼­ ¾ÏÈ£È­¸¦ À§ÇÑ ÃÊ±âÈ­ ÇÒ¶§ »ç¿ëÇÏ´Â º¤ÅÍÀÔ´Ï´Ù.
		\param initializationVectorLength initializationVectorÀÇ ¹ÙÀÌÆ® ±æÀÌ ÀÔ´Ï´Ù.
		\param encryptMode ¾ÏÈ£È­ ¸ğµå ÀÔ´Ï´Ù. ECB, CBC, CFB ¸ğµå°¡ ÀÖ½À´Ï´Ù.

		\~english
		Decrypt ByteArray
		\param key Symmetric key
		\param input Encrypted message
		\param output Decrypted result value
		\param initializationVector Initialization Vector (IV) for CBC or CFB mode encryption.
		\param initializationVectorLength Length of initializationVector in bytes.
		\param encryptMode Encryption mode. (ECB, CBC, CFB mode)

		\~chinese
		÷ò? ByteArray¡£
		\param key ??key¡£
		\param input Ê¥ÚËîÜãáãÓ¡£
		\param output ÷ò?îÜ?Íı?¡£
		\param initializationVector î¤CBC£¬CFBÙ¼ãÒñé?Ê¥ÚË?ú¼ôøã·ûù?á¶ŞÅéÄîÜVector¡£
		\param initializationVectorLength ãÀ initializationVector Byte?Óø¡£
		\param encryptMode Ê¥ÚËÙ¼ãÒ¡£êóECB£¬CBC£¬CFBÙ¼ãÒ¡£

		\~japanese
		ByteArrayªòÜÖ?ûùª·ªŞª¹¡£
		\param key ??«­?ªÇª¹¡£
		\param input äŞ?ûùªµªìª¿«á«Ã«»?«¸ªÇª¹¡£
		\param output ÜÖ?ûùªµªìª¿Ì¿Íıö·ªÇª¹¡£
		\param initializationVector CBC, CFB «â?«ÉªÇäŞ?ûùªÎª¿ªáªÎôøÑ¢ûùãÁªËŞÅª¦«Ù«¯«È«ëªÇª¹¡£
		\param initializationVectorLength initializationVectorªÎ«Ğ«¤«ÈíşªµªÇª¹¡£
		\param encryptMode äŞ?ûù«â?«ÉªÇª¹¡£ECB, CBC, CFB«â?«Éª¬ª¢ªêªŞª¹¡£
		\~
		*/
		PROUD_API static bool DecryptByteArray(
			const CCryptoAesKey &key,
			const ByteArray &input, ByteArray &output, 
			uint8_t * initializationVector = NULL, 
			int initializationVectorLength = 0, 
			EncryptMode encryptMode = ECB
			);

		/**
		\~korean
		Message¸¦ ¾ÏÈ£È­ ÇÕ´Ï´Ù.
		\param key ´ëÄªÅ°ÀÔ´Ï´Ù.
		\param input Æò¹® ¸Ş½ÃÁöÀÔ´Ï´Ù.
		\param output ¾ÏÈ£È­µÈ °á°ú°ªÀÔ´Ï´Ù.
		\param offset Æò¹® ¸Ş½ÃÁö¿¡¼­ ¾ÏÈ£È­¸¦ ½ÃÀÛÇÒ À§Ä¡
		\param initializationVector CBC, CFB ¸ğµå¿¡¼­ ¾ÏÈ£È­¸¦ À§ÇÑ ÃÊ±âÈ­ ÇÒ¶§ »ç¿ëÇÏ´Â º¤ÅÍÀÔ´Ï´Ù.
		\param initializationVectorLength initializationVectorÀÇ ¹ÙÀÌÆ® ±æÀÌ ÀÔ´Ï´Ù.
		\param encryptMode ¾ÏÈ£È­ ¸ğµå ÀÔ´Ï´Ù. ECB, CBC, CFB ¸ğµå°¡ ÀÖ½À´Ï´Ù.

		\~english
		Encrypt Message
		\param key Symmetric key
		\param input Plain text message
		\param output Encrypted result value
		\param offset Encrypt start position at plain text message
		\param initializationVector Initialization Vector (IV) for CBC or CFB mode encryption.
		\param initializationVectorLength Length of initializationVector in bytes.
		\param encryptMode Encryption mode. (ECB, CBC, CFB mode)

		\~chinese
		Ê¥ÚËMessage¡£
		\param key ??key¡£
		\param input Ù¥ÙşãáãÓ¡£
		\param output Ê¥ÚËîÜ?Íı?¡£
		\param offset î¤Ù¥ÙşãáãÓ?ã·Ê¥ÚËîÜêÈöÇ¡£
		\param initializationVector î¤CBC£¬CFBÙ¼ãÒñé?Ê¥ÚË?ú¼ôøã·ûù?á¶ŞÅéÄîÜVector¡£
		\param initializationVectorLength ãÀ initializationVector Byte?Óø¡£
		\param encryptMode Ê¥ÚËÙ¼ãÒ¡£êóECB£¬CBC£¬CFBÙ¼ãÒ¡£

		\~japanese
		MessageªòäŞ?ûùª·ªŞª¹¡£
		\param key ??«­?ªÇª¹¡£
		\param input øÁÙş«á«Ã«»?«¸ªÇª¹¡£
		\param output äŞ?ûùªµªìª¿Ì¿Íıö·ªÇª¹¡£
		\param offset øÁÙş«á«Ã«»?«¸ªÇäŞ?ûùªòËÒã·ª¹ªëêÈöÇ
		\param initializationVector CBC, CFB «â?«ÉªÇäŞ?ûùªÎª¿ªáªÎôøÑ¢ûùãÁªËŞÅª¦«Ù«¯«È«ëªÇª¹¡£
		\param initializationVectorLength initializationVectorªÎ«Ğ«¤«ÈíşªµªÇª¹¡£
		\param encryptMode äŞ?ûù«â?«ÉªÇª¹¡£ECB, CBC, CFB«â?«Éª¬ª¢ªêªŞª¹¡£
		\~
		*/
		PROUD_API static bool EncryptMessage(
			const CCryptoAesKey &key, 
			const CMessage &input, 
			CMessage &output, 
			int offset, 
			uint8_t * initializationVector = NULL, 
			int initializationVectorLength = 0, 
			EncryptMode encryptMode = ECB
			);

		/**
		\~korean
		Message¸¦ º¹È£È­ ÇÕ´Ï´Ù.
		\param key ´ëÄªÅ° ÀÔ´Ï´Ù.
		\param input ¾ÏÈ£È­µÈ ¸Ş½ÃÁöÀÔ´Ï´Ù.
		\param output º¹È£È­µÈ °á°ú°ª ÀÔ´Ï´Ù.
		\param offset ¾ÏÈ£È­µÈ ¸Ş½ÃÁö¿¡¼­ º¹È£È­¸¦ ½ÃÀÛÇÒ À§Ä¡
		\param initializationVector CBC, CFB ¸ğµå¿¡¼­ ¾ÏÈ£È­¸¦ À§ÇÑ ÃÊ±âÈ­ ÇÒ¶§ »ç¿ëÇÏ´Â º¤ÅÍÀÔ´Ï´Ù.
		\param initializationVectorLength initializationVectorÀÇ ¹ÙÀÌÆ® ±æÀÌ ÀÔ´Ï´Ù.
		\param encryptMode ¾ÏÈ£È­ ¸ğµå ÀÔ´Ï´Ù. ECB, CBC, CFB ¸ğµå°¡ ÀÖ½À´Ï´Ù.

		\~english
		Decrypt Message
		\param key Symmetric key
		\param input Encrypted message
		\param output Decrypted result value
		\param offset Decrypt start position at encrypted message
		\param initializationVector Initialization Vector (IV) for CBC or CFB mode encryption.
		\param initializationVectorLength Length of initializationVector in bytes.
		\param encryptMode Encryption mode. (ECB, CBC, CFB mode)

		\~chinese
		÷ò?Message¡£
		\param key ??key¡£
		\param input Ê¥ÚËîÜãáãÓ¡£
		\param output ÷ò?îÜ?Íı?¡£
		\param offset î¤Ê¥ÚËãáãÓ?ã·÷ò?îÜêÈöÇ¡£
		\param initializationVector î¤CBC£¬CFBÙ¼ãÒñé?Ê¥ÚË?ú¼ôøã·ûù?á¶ŞÅéÄîÜVector¡£
		\param initializationVectorLength ãÀ initializationVector Byte?Óø¡£
		\param encryptMode Ê¥ÚËÙ¼ãÒ¡£êóECB£¬CBC£¬CFBÙ¼ãÒ¡£

		\~japanese
		MessageªòÜÖ?ûùª·ªŞª¹¡£
		\param key ??«­?ªÇª¹¡£
		\param input äŞ?ûùªµªìª¿«á«Ã«»?«¸ªÇª¹¡£
		\param output ÜÖ?ûùªµªìª¿Ì¿Íıö·ªÇª¹¡£
		\param offset äŞ?ûùªµªìª¿«á«Ã«»?«¸ªÇÜÖ?ûùªòËÒã·ª¹ªëêÈöÇ
		\param initializationVector CBC, CFB «â?«ÉªÇäŞ?ûùªÎª¿ªáªÎôøÑ¢ûùãÁªËŞÅª¦ªÙª¯«È«ëªÇª¹¡£
		\param initializationVectorLength initializationVectorªÎ«Ğ«¤«ÈíşªµªÇª¹¡£
		\param encryptMode äŞ?ûù«â?«ÉªÇª¹¡£ECB, CBC, CFB«â?«Éª¬ª¢ªêªŞª¹¡£
		\~
		*/
		PROUD_API static bool DecryptMessage(
			const CCryptoAesKey &key, 
			const CMessage &input, 
			CMessage &output, 
			int offset, 
			uint8_t * initializationVector = NULL, 
			int initializationVectorLength = 0, 
			EncryptMode encryptMode = ECB
			);

	private:
		static bool DefaultEncryptBlock(const CCryptoAesKey &key, const uint8_t* in, uint8_t *result);
		static bool DefaultDecryptBlock(const CCryptoAesKey &key, const uint8_t* in, uint8_t *result);
		static bool EncryptBlock(const CCryptoAesKey &key, const uint8_t* in, uint8_t *result);
		static bool DecryptBlock(const CCryptoAesKey &key, const uint8_t* in, uint8_t *result);
		static int Mul(int a, int b);
		static int Mul4(int a, char b[]);
		static void Xor(uint8_t *buff, const uint8_t* chain, const int blockSize);

	private:
		/** Null chain */
		static char const* m_chain0;

		static const int m_alog[256];
		static const int m_log[256];

		static const int8_t m_s[256];

		static const int8_t m_si[256];

		static const int m_t1[256];
		static const int m_t2[256];
		static const int m_t3[256];
		static const int m_t4[256];

		static const int m_t5[256];
		static const int m_t6[256];
		static const int m_t7[256];
		static const int m_t8[256];

		static const int m_u1[256];
		static const int m_u2[256];
		static const int m_u3[256];
		static const int m_u4[256];
		static const int8_t m_rcon[30];
		static const int m_shifts[3][4][2];
	};

	class CCryptoAesKey
	{
		friend class CCryptoAes;

	public:
		CCryptoAesKey()
		{
			m_keyLength = 0;
		}

		/**
		\~korean
		aes Å° ±æÀÌ¸¦ ¾ò¾î¿É´Ï´Ù. (byte)
		\return aes Å° ±æÀÌ

		\~english
		Gets length of AES key. (byte)
		\return AES key length

		\~chinese
		?Ôğaes key?Óø¡££¨byte£©
		\return aes key?Óø

		\~japanese
		aes «­?ªÎíşªµªòÔğªŞª¹¡£(byte)
		\return aes «­?ªÎíşªµ
		\~
		*/
		int GetKeyLength() const;

		/**
		\~korean
		ºí·° »çÀÌÁî¸¦ ¾ò¾î¿É´Ï´Ù. (byte)
		\return m_blockSize

		\~english
		Gets block size. (byte)
		\return m_blockSize

		\~chinese
		?ÔğblockÓŞá³¡££¨byte£©
		\return m_blockSize

		\~japanese
		«Ö«í«Ã«¯«µ«¤«ºªòÔğªŞª¹¡£(byte)
		\return m_blockSize

		\~
		*/
		int	GetBlockSize() const;

		/**
		\~korean
		¶ó¿îµå ¼ö¸¦ ¾ò¾î¿É´Ï´Ù.
		\return m_rounds

		\~english
		Gets number of round.
		\return m_rounds

		\~chinese
		?ÔğüŞùê?¡£
		\return m_rounds

		\~japanese
		«é«¦«ó«É?ªòÔğªŞª¹¡£
		\return m_rounds

		\~
		*/
		int GetRounds() const;

		/**
		\~korean
		Å°°¡ ÀÌ¹Ì »ı¼ºµÇ¾ú´ÂÁö¸¦ È®ÀÎÇÕ´Ï´Ù.

		\~english
		Check key is already existed or not.

		\~chinese
		??keyãÀÜúì«?ßæà÷Öõ¡£

		\~japanese
		«­?ª¬?ªËßæà÷ªµªìªÆª¤ªëª«ªòü¬ìãª·ªŞª¹¡£
		\~
		*/
		bool KeyExists() const;

		void Clear();

	private:
		// ¾ÏÈ£È­¿¡ »ç¿ëµÇ´Â round key
		int m_ke[CCryptoAes::MAX_ROUNDS + 1][CCryptoAes::MAX_BC];
		// º¹È£È­¿¡ »ç¿ëµÇ´Â round key
		int m_kd[CCryptoAes::MAX_ROUNDS + 1][CCryptoAes::MAX_BC];
		// Å° ±æÀÌ (byte)
		int m_keyLength;
		// ºí·° »çÀÌÁî
		int	m_blockSize;
		// ¶ó¿îµå ¼ö
		int m_rounds;

#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// ÀÌ Å¬·¡½º´Â ProudNet DLL °æ¿ì¸¦ À§ÇØ Ä¿½ºÅÒ ÇÒ´çÀÚ¸¦ ¾²µÇ fast heapÀ» ¾²Áö ¾Ê´Â´Ù.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif // __MARMALADE__

	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif