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

// Linux¿¡¼­ ODBC¸¦ ¾²°í ½ÍÀ¸¸é ODBC for unix³ª ¿©Å¸¸¦ ¼³Ä¡ÇÏ½Ê½Ã¿À.
// ¿¹: sudo apt-get install unixodbc-dev
#include <sqltypes.h>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/**
	 \~korean
	 ODBC API¿¡ ÀÌÁø µ¥ÀÌÅÍ¸¦ ÀÔÃâ·ÂÇÒ¶§ »ç¿ëµË´Ï´Ù.
	 ÀÌÁø µ¥ÀÌÅÍ°¡ µ¢Ä¡°¡ ¸Å¿ì Å« °æ¿ì, µ¥ÀÌÅÍ ÀÔÃâ·Â °úÁ¤¿¡¼­ ºÒÇÊ¿äÇÑ º¹»ç °úÁ¤À» »ı·«ÇÏ±â À§ÇØ ÀÌ Å¬·¡½º°¡ »ç¿ëµË´Ï´Ù.
	 »ç¿ëÀÚ°¡ ÀÌÁø µ¥ÀÌÅÍ¸¦ Á÷Á¢ ¼ÒÀ¯ÇØ¾ß ÇÏ°í, ÀÌ Å¬·¡½º´Â ±× µ¥ÀÌÅÍ¸¦ ÂüÁ¶ÇÏ´Â ¿ªÇÒÀ» ÇÕ´Ï´Ù.

	 \~english
	 It is used for input & output of binary data at ODBC API.
	 If the size of binary data is too big, this class will be used to omit unnecessary copy process in the process of data input & output. 
	 A user must possess binary data and this class refers to the data. 

	 \~chinese
	 î¤ODBC API?õóìıì£?ğ¤?Ëß?ŞÅéÄ¡£
	 ì£?ğ¤?ËßÕáŞªßÈÓŞ?£¬?Öõî¤?õóìı?ËßîÜ?ïïñéàıÕÔÜôù±é©îÜ?ğ¤?ïï£¬ŞÅéÄ?class¡£
	 éÄ??òÁïÈá¶êóì£?ğ¤?Ëß£¬ì»?classÑÃÓğ?ğÎ??ËßîÜíÂéÄ¡£

	 \~japanese
	 ODBC APIªË«Ñ«¤«Ê«ê«Ç?«¿ªòìıõóÕôª¹ªëíŞùêªËŞÅªïªìªŞª¹¡£
	 «Ñ«¤«Ê«ê«Ç?«¿ªÎ«µ«¤«ºª¬ÓŞ?ÓŞª­ª¤íŞùê¡¢«Ç?«¿ìıõóÕôÎ¦ïïªÇÜôù±é©ªÊ«³«Ô?Î¦ïïªòàıÕÔª¹ªëª¿ªáªËª³ªÎ«¯«é«¹ª¬ŞÅéÄªµªìªŞª¹¡£
	 «æ?«¶?ª¬«Ñ«¤«Ê«ê«Ç?«¿ªòòÁïÈá¶êóª¹ªëù±é©ª¬ª¢ªê¡¢ª³ªÎ«¯«é«¹ªÏª½ªÎ«Ç?«¿ªò?ğÎª¹ªëæµùÜªòª·ªŞª¹¡£

	 \~
	 */
	class COdbcByteData
	{
	private:
		// »ç¿ëÀÚ°¡ ¸¶À½´ë·Î ¼öÁ¤ ÇÒ ¼ö ¾ø´Â º¯¼ö ÀÔ´Ï´Ù.
		// dataPtr·Î ÁöÁ¤ÇÑ »ç¿ëÀÚ µ¥ÀÌÅÍ ¹öÆÛ ³»ºÎ´Â ¸¶À½´ë·Î ¼öÁ¤ÇÒ ¼ö ÀÖÁö¸¸ ±× °´Ã¼ ÀÚÃ¼(Æ÷ÀÎÅÍ°ª)°¡ º¯°æµÇ¸é ¾ÈµË´Ï´Ù.
		// °´Ã¼°¡ º¯°æµÇÁö ¸øÇÏ±â ¶§¹®¿¡ maxLenµµ ÇÑ¹ø ¼³Á¤ÇÏ¸é ¹Ù²ÙÁö ¸øÇÕ´Ï´Ù.
		SQLCHAR* m_dataPtr;

		SQLLEN m_dataLength;
		SQLULEN m_maxLength;

	public:
		/**
		 \~korean
		 »ı¼ºÀÚ ÇÔ¼ö. ¿©±â¼­ »ç¿ëÀÚ°¡ °®°í ÀÖ´Â ÀÌÁø µ¥ÀÌÅÍÀÇ ÁÖ¼Ò¿Í Å©±â¸¦ ÀÔ·ÂÇÏ½Ê½Ã¿À.
		 \param pData ÀÌÁø µ¥ÀÌÅÍÀÇ ÁÖ¼Ò
		 \param dataLength ÀÌÁø µ¥ÀÌÅÍÀÇ À¯È¿ÇÑ ÇöÀç Å©±âÀÔ´Ï´Ù
		 \param maxLength ÀÌÁø µ¥ÀÌÅÍ°¡ ÀúÀåµÇ´Â ÃÖ´ë Å©±â

		 \~english
		 Constructor function. Please input the size & address of binary data that a user has. 
		 \param pData Address of binary data.
		 \param dataLength Current valid size of binary data. 
		 \param maxLength Maximum size of binary data saving.

		 \~chinese
		 ßæà÷íº ùŞ?¡£î¤ó®?ìıéÄ?îÜì£?ğ¤?ËßîÜò¢ò£ûúÓŞá³¡£
		 \param pData ì£?ğ¤?ËßîÜò¢ò£
		 \param dataLength ì£?ğ¤?ËßîÜ?îñêóüùÓŞá³¡£
		 \param maxLength ì£?ğ¤?ËßÊ¦ÜÁğíîÜõÌÓŞùÚÓø¡£

		 \~japanese
		 ßæà÷íº??¡£ª³ª³ªÇ«æ?«¶?ª¬ò¥ªÃªÆª¤ªë«Ñ«¤«Ê«ê«Ç?«¿ªÎ«¢«É«ì«¹ªÈ«µ«¤«ºªòìıÕôª·ªÆª¯ªÀªµª¤¡£
		 \param pData «Ñ«¤«Ê«ê«Ç?«¿ªÎ«¢«É«ì«¹
		 \param dataLength «Ñ«¤«Ê«ê«Ç?«¿ªÎêó?ªÊúŞî¤«µ«¤«ºªÇª¹¡£
		 \param maxLength «Ñ«¤«Ê«ê«Ç?«¿ª¬«»?«ÖªµªìªëõÌÓŞ«µ«¤«º

		 \~
		 */
		COdbcByteData(SQLCHAR* pData, SQLLEN dataLength, SQLULEN maxLength);

		/**
		 \~korean
		 ¼³Á¤µÈ µ¥ÀÌÅÍÀÇ ÁÖ¼Ò¸¦ °¡Á® ¿É´Ï´Ù.

		 \~english
		 Get the data address that has been set. 

		 \~chinese
		 ?ö¢ì«?ïÒîÜ?Ëßò¢ò£¡£

		 \~japanese
		 àâïÒªµªìª¿«Ç?«¿ªÎ«¢«É«ì«¹ªò«í?«Éª·ªŞª¹¡£

		 \~
		 */
		SQLCHAR* GetDataPtr();

		/**
		 \~korean
		 ¼³Á¤µÈ µ¥ÀÌÅÍÀÇ Å©±â¸¦ °¡Á® ¿É´Ï´Ù.

		 \~english
		 Get the data size that has been set. 

		 \~chinese
		 ?ö¢ì«?ïÒîÜ?ËßÓŞá³¡£

		 \~japanese
		 àâïÒªµªìª¿«Ç?«¿ªÎ«µ«¤«ºªò«í?«Éª·ªŞª¹¡£.

		 \~
		 */
		SQLLEN GetDataLength();

		/**
		 \~korean
		 µ¥ÀÌÅÍÀÇ Å©±â¸¦ ÀçÁ¶Á¤ÇÕ´Ï´Ù.
		 »ı¼ºÀÚ¿¡¼­ ÁöÁ¤ÇÑ »ç¿ëÀÚ µ¥ÀÌÅÍ ¹öÆÛ¸¦ ¼öÁ¤ÇÏ¿´À» ¶§ ±×°ÍÀÇ ±æÀÌ°¡ ¹Ù²î¸é ÀÌ ÇÔ¼ö¸¦ È£ÃâÇÏ¿© Å©±â¸¦ º¯°æÇØ¾ß ÇÕ´Ï´Ù.

		 \~english
		 Readjust the size of data.
		 If the length of data buffer changes when modifying data buffer that has been set by a constructor, you will be required to change the size by calling this function. 

		 \~chinese
		 ñìãæ?ïÚ?ËßÓŞá³¡£
		 áóËÇßæà÷íºò¦ïÒîÜéÄ??Ëßbuffer?£¬åıÍı??Óøêóá¶ËÇ?£¬âÍû¼õóó®ùŞ??ú¼ÓŞá³?ÌÚ¡£

		 \~japanese
		 «Ç?«¿ªÎ«µ«¤«ºªòî¢ğàïÚª·ªŞª¹¡£
		 ßæà÷íºªÇò¦ïÒª·ª¿«æ?«¶?«Ç?«¿«Ğ«Ã«Õ«¡?ªòáóïáª·ª¿ªÈª­¡¢ª½ªìªÎíşªµª¬?ªïªëªÈª³ªÎ??ªòû¼ªÓõóª·¡¢«µ«¤«ºªò?ÌÚª¹ªëù±é©ª¬ª¢ªêªŞª¹¡£

		 \~
		 */
		void SetDataLength(SQLLEN dataLength);

		/**
		 \~korean
		 ¼³Á¤µÈ µ¥ÀÌÅÍÀÇ ÃÖ´ë Å©±â¸¦ ¾ò½À´Ï´Ù.

		 \~english
		 Obtain the maximum size of data. 

		 \~chinese
		 ?ö¢ì«?ïÒ?ËßîÜõÌÓŞ?¡£

		 \~japanese
		 àâïÒªµªìª¿«Ç?«¿ªÎõÌÓŞ«µ«¤«ºªòö¢Ôğª·ªŞª¹¡£

		 \~
		 */
		SQLULEN GetMaxLength();

	private:
		// º¹»ç ±İÁö
		COdbcByteData(const COdbcByteData& other);
		COdbcByteData& operator=(const COdbcByteData& other);
	};
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif