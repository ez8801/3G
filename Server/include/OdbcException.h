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

#include <sqltypes.h>

#include "Exception.h"
#include "FastArray.h"
#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/**
	 \~korean
	 ODBCÀÇ ÀÍ¼Á¼Ç Ã³¸®¸¦ À§ÇÑ Å¬·¡½ºÀÔ´Ï´Ù.
	 what() ÇÔ¼ö¸¦ ÀÌ¿ëÇÏ¿© »ó¼¼ ³»¿ëÀ» È®ÀÎÇÒ ¼ö ÀÖ½À´Ï´Ù.

	 \~english
	 It is a class that deals with ODBC exception. 
	 You can check the detailed information by what() function. 

	 \~chinese
	 ?×âODBC?ßÈîÜclass¡£
	 ÷×?what()ùŞ?Ê¦ì¤?????é»¡£

	 \~japanese
	 ODBCªÎexception?×âªÎª¿ªáªÎ«¯«é«¹ªÇª¹¡£
	 what() ??ªò××éÄª·ªÆßÙá¬?é»ªòü¬ìãªÇª­ªŞª¹¡£

	 \~
	 */
	class COdbcException: public Exception
	{
	protected:
		SQLRETURN m_ret;

	public:
		COdbcException();
		COdbcException(const SQLRETURN ret, const StringA& errorString);

		/**
		 \~korean
		 sql.h³ª sqlext.h¿¡ Á¤ÀÇµÈ return value¸¦ ¹İÈ¯ ÇÕ´Ï´Ù.

		 \~english
		 It returns the return value that has been defined in sql.h or sqlext.h.

		 \~chinese
		 Ú÷?î¤sql.hûä sqlext.hïÒ?îÜreturn value¡£

		 \~japanese
		 sql.hªäsqlext.hªËïÒëùªµªìª¿return valueªòÚ÷ü½ª·ªŞª¹¡£

		 \~
		 */
		int GetSqlErrorCode();

		COdbcException(const COdbcException& other);
		COdbcException& operator=(const COdbcException& other);
	};

	/**
	 \~korean
	 SqlErrorCode°¡ SQL_SUCCESS_WITH_INFOÀÏ °æ¿ì Warning ExceptionÀÌ ¹ß»ıÇÕ´Ï´Ù.
	 ÇØ´ç ÀÍ¼Á¼ÇÀº ±âº»ÀûÀ¸·Ğ ¹«½ÃÇØµµ »ó°ü¾øÀ¸³ª Áß¿äÇÑ Á¤º¸¸¦ ´ã°íÀÖ´Â °æ¿ìµµ ÀÖÀ¸¹Ç·Î ÁÖÀÇÇØ¾ß ÇÕ´Ï´Ù.
	 ex> Warning ¹ß»ı ¿¹
	 1. MSSQLÀÇ °æ¿ì »ç¿ëÇÏ´Â µ¥ÀÌÅÍº£ÀÌ½º(½ºÅ°¸¶)°¡ º¯°æµÇ´Â °æ¿ì¿¡ º¯°æµÇ¾ú´Ù´Â ¾Ë¸²À» À§ÇØ ¹ß»ı
	 2. Insert½Ã Primary Key°¡ Áßº¹µÈ µ¥ÀÌÅÍÀÏ °æ¿ì ¹ß»ı(Primary Key Duplicate Error)

	 \~english
	 In case SqlErrorCode is SQL_SUCCESS_WITH_INFO, Warning Exception will occur. 
	 It does not matter if you ignore this exception, but it contains important information, so you should take extra caution. 
	 ex> Example of Warning Occurrence
	 1. In case of MSSQL, when the database (schema) is changed, warning will occur.
	 2. In case primary keys are duplicated when inserting, warning will occur. (Primary Key Duplicate Error)

	 \~chinese
	 SqlErrorCodeãÀ SQL_SUCCESS_WITH_INFOîÜï×?£¬?ßæ Warning Exception¡£
	 ìéÚõï×?ù»Ùé???ßÈå¥?êó÷¼ÓŞ??£¬Ó£å¥êóñìé©ãáãÓîÜï×?£¬á¶ì¤âÍñ¼ëò¡£
	 ex> Warning ?ßæ ÖÇ
	 1. . MSSQLîÜï×?£¬ŞÅéÄîÜ?Ëß??ÌÚ?£¬?ğ«ãÆ?ÌÚì»?ßæ¡£
	 2. Insert½Ã Primary Key?ñì??Ëß??ßæ(Primary Key Duplicate Error)

	 \~japanese
	 SqlErrorCodeª¬SQL_SUCCESS_WITH_INFOªÎíŞùêWarning Exceptionª¬?ßæª·ªŞª¹¡£
	 ú±?exceptionªÏĞñÜâîÜªËÙíãÊª·ªÆªâÏ°ª¤ªŞª»ªóª¬¡¢ñìé©ªÊï×ÜÃªòùßªáªÆª¤ªëíŞùêªâª¢ªëª¿ªáª´ñ¼ëòª¯ªÀªµª¤¡£
	 ex> Warning ?ßæªÎÖÇ
	 1. MSSQLªÎíŞùê¡¢ŞÅéÄª·ªÆª¤ªë«Ç?«¿«Ù?«¹£¨«¹«­?«Ş£©ª¬?ÌÚªµªìªëíŞùêªË?ÌÚªÎªªò±ªéª»ªÎª¿ªá?ßæ
	 2. InsertãÁPrimary Keyª¬ñìÜÜªµªìª¿«Ç?«¿ªÎíŞùê?ßæ(Primary Key Duplicate Error)

	 \~
	 */
	class COdbcWarning: public COdbcException
	{
	public:
		COdbcWarning();
		COdbcWarning(const SQLRETURN ret, const StringA& errorString);

		COdbcWarning(const COdbcWarning& other);
		COdbcWarning& operator=(const COdbcWarning& other);
	};

	typedef CFastArray<COdbcWarning> COdbcWarnings;
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif