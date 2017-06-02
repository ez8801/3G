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

#include "ErrorInfo.h"
#include "ByteArray.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class CByteArray;
	class CMessage;

	class CCryptoFastKey
	{
		friend class CCryptoFast;

	private:
		// ´ëÄªÅ°
		ByteArray m_key;

	public:
		CCryptoFastKey();
		~CCryptoFastKey();

		/**
		\~korean
		Fast Å° ±æÀÌ¸¦ ¾ò¾î¿É´Ï´Ù. (byte)
		\return Fast Å° ±æÀÌ

		\~english
		Gets length of Fast key. (byte)
		\return Fast key length

		\~chinese
		?ÔğFast key?Óø¡££¨byte£©
		\return Fast key?Óø

		\~japanese
		Fast «­?ªÎíşªµªòÔğªÆª­ªŞª¹¡£(byte)
		\return Fast «­?ªÎíşªµ
		\~
		*/
		int GetKeyLength() const;


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
	};

	// ¸Å¿ì ´Ü¼øÇÑ ¼öÁØÀÇ ¾ÏÈ£È­ ¾Ë°í¸®Áò
	// °ÔÀÓ ³×Æ®¿öÅ· ¸Ş½ÃÁö¸¦ ¸ğµÎ ¾ÏÈ£È­µÇ Å« ºÎÇÏ¸¦ ÁÖÁö ¾ÊÀ»¸¸Å­ °¡º±°Ô ÀÛµ¿ÇÏÁö¸¸ ½±°Ô ÇØÅ·´çÇÑ´Ù´Â ´ÜÁ¡ÀÌ ÀÖ´Ù.
	// ÃÊº¸ÀûÀÎ ÇØÄ¿ Á¤µµ´Â °É·¯³»´Â ¿ëµµ °¡·É °ÔÀÓ ÇÃ·¹ÀÌÀÇ ¸ğµç ¸Ş½ÃÁö¸¦ ¾ÏÈ£È­ÇÏ´Âµ¥ ¾²ÀÌ¸é µÈ´Ù.
	class CCryptoFast
	{
	public:
		/**
		\~korean
		¾ÏÈ£È­¿¡ »ç¿ëµÇ´Â Å° °´Ã¼¸¦ »ı¼ºÇÏ´Â ÇÔ¼öÀÔ´Ï´Ù.
		\param outKey »ı¼ºµÈ ¾ÏÈ£È­ Å° °´Ã¼°¡ ÀúÀåµË´Ï´Ù.
		\param inputKey
		\param keyLength 16 or 24 or 32 bytes ÀÔ´Ï´Ù.

		\~english
		\param outKey
		\param inputKey
		\param keyLength 16 or 24 or 32 bytes

		\~chinese
		\param outKey
		\param inputKey
		\param keyLength 16 or 24 or 32 bytes¡£
		

		\~japanese
		äŞ?ûùªËŞÅªïªìªë«­?«ª«Ö«¸«§«¯«Èªòßæà÷ª¹ªë??ªÇª¹¡£
		\param outKey ßæà÷ªµªìª¿äŞ?ûù«­?«ª«Ö«¸«§«¯«Èª¬ÜÁğíªµªìªŞª¹¡£
		\param inputKey
		\param keyLength 16 or 24 or 32 bytes ªÇª¹¡£
		\~
		*/
		static bool ExpandFrom(CCryptoFastKey& outKey, const uint8_t* inputKey, int keyLength);

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
		static int GetEncryptSize(int inputLength);

		/**
		\~korean
		µ¥ÀÌÅÍ¸¦ ¾ÏÈ£È­ ÇÕ´Ï´Ù.
		\param key ´ëÄªÅ°ÀÔ´Ï´Ù.
		\param input Æò¹® ¸Ş½ÃÁöÀÔ´Ï´Ù.
		\param inputLength Æò¹®ÀÇ »çÀÌÁîÀÔ´Ï´Ù.
		\param output ¾ÏÈ£È­µÈ °á°ú°ªÀÔ´Ï´Ù.
		\param outputLength ¾ÏÈ£È­µÈ °á°úÀÇ »çÀÌÁîÀÔ´Ï´Ù.

		\~english
		Encrypt data
		\param key Symmetric key
		\param input Plain text message
		\param inputLength Size of plain text
		\param output Encrypted result value
		\param outputLength Size of Encrypted result

		\~chinese
		Ê¥ÚË?Ëß¡£
		\param key ??key¡£
		\param input Ù¥ÙşãáãÓ¡£
		\param inputLength Ù¥ÙşîÜÓŞá³
		\param output Ê¥ÚËîÜ?Íı?¡£
		\param outputLength Ê¥ÚËîÜ?ÍıÓŞá³¡£

		\~japanese
		«Ç?«¿ªòäŞ?ûùª·ªŞª¹¡£
		\param key ??«­?ªÇª¹¡£
		\param input øÁÙş«á«Ã«»?«¸ªÇª¹¡£
		\param inputLength øÁÙşªÎ«µ«¤«ºªÇª¹¡£
		\param output äŞ?ûùªµªìª¿Ì¿Íıö·ªÇª¹¡£
		\param outputLength äŞ?ûùªµªìª¿Ì¿ÍıªÎ«µ«¤«ºªÇª¹¡£
		\~
		*/
		static bool Encrypt(
			const CCryptoFastKey& key,
			const uint8_t* input,
			int inputLength,
			uint8_t *output,
			int& outputLength,
			ErrorInfoPtr& errorInfo
			);

		/**
		\~korean
		µ¥ÀÌÅÍ¸¦ º¹È£È­ ÇÕ´Ï´Ù.
		\param key ´ëÄªÅ° ÀÔ´Ï´Ù.
		\param input ¾ÏÈ£È­µÈ ¸Ş½ÃÁöÀÔ´Ï´Ù.
		\param inputLength ¾ÏÈ£È­µÈ ¸Ş½ÃÁöÀÇ »çÀÌÁîÀÔ´Ï´Ù.
		\param output º¹È£È­µÈ °á°ú°ª ÀÔ´Ï´Ù.
		\param outputLength º¹È£È­µÈ °á°ú°ªÀÇ »çÀÌÁîÀÔ´Ï´Ù.

		\~english
		Decrypt data
		\param key Symmetric key
		\param input Encrypted message
		\param inputLength Size of Encrypted message
		\param output Decrypted result value
		\param outputLength Size of Decrypted text

		\~chinese
		÷ò??Ëß¡£
		\param key ??key¡£
		\param input Ê¥ÚËîÜãáãÓ¡£
		\param inputLength Ê¥ÚËãáãÓîÜÓŞá³
		\param output ??îÜ?Íı?¡£
		\param outputLength ??îÜ?ÍıÓŞá³¡£

		\~japanese
		«Ç?«¿ªòÜÖ?ûùª·ªŞª¹¡£
		\param key ??«­?ªÇª¹¡£
		\param input äŞ?ûùªµªìª¿«á«Ã«»?«¸ªÇª¹¡£
		\param inputLength äŞ?ûùªµªìª¿«á«Ã«»?«¸ªÎ«µ«¤«ºªÇª¹¡£
		\param output ÜÖ?ûùªµªìª¿Ì¿Íıö·ªÇª¹¡£
		\param outputLength ÜÖ?ûùªµªìª¿Ì¿Íıö·ªÎ«µ«¤«ºªÇª¹¡£
		\~
		*/
		static bool Decrypt(
			const CCryptoFastKey& key,
			const uint8_t* input,
			int inputLength,
			uint8_t *output,
			int& outputLength,
			ErrorInfoPtr& errorInfo
			);

		/**
		\~korean
		ByteArray¸¦ ¾ÏÈ£È­ ÇÕ´Ï´Ù.
		\param key ´ëÄªÅ°ÀÔ´Ï´Ù.
		\param input Æò¹® ¸Ş½ÃÁöÀÔ´Ï´Ù.
		\param output ¾ÏÈ£È­µÈ °á°ú°ªÀÔ´Ï´Ù.

		\~english
		Encrypt ByteArray
		\param key Symmetric key
		\param input Plain text message
		\param output Encrypted result value

		\~chinese
		Ê¥ÚË ByteArray¡£
		\param key ??key¡£
		\param input Ù¥ÙşãáãÓ¡£
		\param output Ê¥ÚËîÜ?Íı?¡£

		\~japanese
		ByteArrayªòäŞ?ûùª·ªŞª¹¡£
		\param key ??«­?ªÇª¹¡£
		\param input øÁÙş«á«Ã«»?«¸ªÇª¹¡£
		\param output äŞ?ûùªµªìª¿Ì¿Íıö·ªÇª¹¡£
		
		\~
		*/
		static bool EncryptByteArray(
			const CCryptoFastKey& key,
			const ByteArray& input,
			ByteArray& output,
			ErrorInfoPtr& errorInfo
			);

		/**
		\~korean
		ByteArray¸¦ º¹È£È­ ÇÕ´Ï´Ù.
		\param key ´ëÄªÅ° ÀÔ´Ï´Ù.
		\param input ¾ÏÈ£È­µÈ ¸Ş½ÃÁöÀÔ´Ï´Ù.
		\param output º¹È£È­µÈ °á°ú°ª ÀÔ´Ï´Ù.

		\~english
		Decrypt ByteArray
		\param key Symmetric key
		\param input Encrypted message
		\param output Decrypted result value

		\~chinese
		÷ò? ByteArray¡£
		\param key ??key¡£
		\param input Ê¥ÚËîÜãáãÓ¡£
		\param output ÷ò?îÜ?Íı?¡£

		\~japanese
		ByteArrayªòÜÖ?ûùª·ªŞª¹¡£
		\param key ??«­?ªÇª¹¡£
		\param input äŞ?ûùªµªìª¿«á«Ã«»?«¸ªÇª¹¡£
		\param output ÜÖ?ûùªµªìª¿Ì¿Íıö·ªÇª¹¡£
		\~
		*/
		static bool DecryptByteArray(
			const CCryptoFastKey& key,
			const ByteArray& input, 
			ByteArray& output,
			ErrorInfoPtr& errorInfo
			);

		/**
		\~korean
		Message¸¦ ¾ÏÈ£È­ ÇÕ´Ï´Ù.
		\param key ´ëÄªÅ°ÀÔ´Ï´Ù.
		\param input Æò¹® ¸Ş½ÃÁöÀÔ´Ï´Ù.
		\param output ¾ÏÈ£È­µÈ °á°ú°ªÀÔ´Ï´Ù.
		\param offset Æò¹® ¸Ş½ÃÁö¿¡¼­ ¾ÏÈ£È­¸¦ ½ÃÀÛÇÒ À§Ä¡

		\~english
		Encrypt Message
		\param key Symmetric key
		\param input Plain text message
		\param output Encrypted result value
		\param offset Encrypt start position at plain text message

		\~chinese
		Ê¥ÚËMessage¡£
		\param key ??key¡£
		\param input Ù¥ÙşãáãÓ¡£
		\param output Ê¥ÚËîÜ?Íı?¡£
		\param offset î¤Ù¥ÙşãáãÓ?ã·Ê¥ÚËîÜêÈöÇ¡£

		\~japanese
		MessageªòäŞ?ûùª·ªŞª¹¡£
		\param key ??«­?ªÇª¹¡£
		\param input øÁÙş«á«Ã«»?«¸ªÇª¹¡£
		\param output äŞ?ûùªµªìª¿Ì¿Íıö·ªÇª¹¡£
		\param offset øÁÙş«á«Ã«»?«¸ªÇäŞ?ûùªòËÒã·ª¹ªëêÈöÇ
		\~
		*/
		static bool EncryptMessage(
			const CCryptoFastKey& key,
			const CMessage& input,
			CMessage& output,
			int offset,
			ErrorInfoPtr& errorInfo
			);

		/**
		\~korean
		Message¸¦ º¹È£È­ ÇÕ´Ï´Ù.
		\param key ´ëÄªÅ° ÀÔ´Ï´Ù.
		\param input ¾ÏÈ£È­µÈ ¸Ş½ÃÁöÀÔ´Ï´Ù.
		\param output º¹È£È­µÈ °á°ú°ª ÀÔ´Ï´Ù.
		\param offset ¾ÏÈ£È­µÈ ¸Ş½ÃÁö¿¡¼­ º¹È£È­¸¦ ½ÃÀÛÇÒ À§Ä¡

		\~english
		Decrypt Message
		\param key Symmetric key
		\param input Encrypted message
		\param output Decrypted result value
		\param offset Decrypt start position at encrypted message

		\~chinese
		÷ò?Message¡£
		\param key ??key¡£
		\param input Ê¥ÚËîÜãáãÓ¡£
		\param output ÷ò?îÜ?Íı?¡£
		\param offset î¤Ê¥ÚËãáãÓ?ã·÷ò?îÜêÈöÇ¡£

		\~japanese
		MessageªòÜÖ?ûùª·ªŞª¹¡£
		\param key ??«­?ªÇª¹¡£
		\param input äŞ?ûùªµªìª¿«á«Ã«»?«¸ªÇª¹¡£
		\param output ÜÖ?ûùªµªìª¿Ì¿Íıö·ªÇª¹¡£
		\param offset äŞ?ûùªµªìª¿«á«Ã«»?«¸ªÇÜÖ?ûùªòËÒã·ª¹ªëêÈöÇ
		\~
		*/
		static bool DecryptMessage(
			const CCryptoFastKey& key,
			const CMessage& input,
			CMessage& output,
			int offset,
			ErrorInfoPtr& errorInfo
			);
	};
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif