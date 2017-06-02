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

#include "OdbcEnum.h"
#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class COdbcVariant;
	class COdbcRecordsetImpl;
	class COdbcConnection;

	/**
	 \~korean
	 SELECT¸¦ ÅëÇØ ¾ò¾îÁø RecordsetÀ» Á¦¾îÇÒ ¼ö ÀÖ´Â Å¬·¡½ºÀÔ´Ï´Ù.

	 \~english
	 It is a class that can control Recordset that has been received by SELECT.

	 \~chinese
	 Ê¦ì¤ÛÁåÙ÷×?SELECT?ö¢îÜRecordsetîÜclass¡£

	 \~japanese
	 SELECTªÎª¿ªáö¢Ôğªµªìª¿Recordsetªò«³«ó«È«í?«ëªÇª­ªë«¯«é«¹ªÇª¹¡£

	 \~
	 */
	class COdbcRecordset
	{
	public:
		COdbcRecordset();
		~COdbcRecordset();

		/**
		 \~korean
		 Ã¹¹øÂ° ·¹ÄÚµå·Î ÀÌµ¿ÇÕ´Ï´Ù.
		 ¼º°ø/½ÇÆĞ¸¦ ¹İÈ¯ÇÕ´Ï´Ù.
		 Stored ProcedureÀÇ Recordset¿¡¼­´Â »ç¿ëÇÒ ¼ö ¾ø½À´Ï´Ù.

		 \~english
		 Move to the first record. 
		 Return success/fail
		 You cannot use it in the Recordset of the stored procedure. 

		 \~chinese
		 ì¹?Óğğ¯ìé???¡£
		 Ú÷üŞà÷/ã÷?¡£
		 î¤Stored ProcedureîÜRecordsetñéÜôÒöŞÅéÄ¡£

		 \~japanese
		 õÌôøªÎ«ì«³?«ÉªËì¹ÔÑª·ªŞª¹¡£
		 à÷Íí/ã÷ø¨ªòÚ÷ü½ª·ªŞª¹¡£
		 Stored ProcedureªÎRecordsetªÇªÏŞÅéÄªÇª­ªŞª»ªó¡£

		 \~
		 */
		bool MoveFirst();
		/**
		 \~korean
		 ¸¶Áö¸· ·¹ÄÚµå·Î ÀÌµ¿ÇÕ´Ï´Ù.
		 ¼º°ø/½ÇÆĞ¸¦ ¹İÈ¯ÇÕ´Ï´Ù.
		 Stored ProcedureÀÇ Recordset¿¡¼­´Â »ç¿ëÇÒ ¼ö ¾ø½À´Ï´Ù.

		 \~english
		 Move to the last record 
		 Return success/fail
		 You cannot use it in the Recordset of the stored procedure. 

		 \~chinese
		 ì¹?ÓğõÌı¨ìé???¡£
		 Ú÷üŞà÷/ã÷?¡£
		 î¤Stored ProcedureîÜRecordsetñéÜôÒöŞÅéÄ¡£

		 \~japanese
		 õÌı­ªÎ«ì«³?«ÉªËì¹ÔÑª·ªŞª¹¡£
		 à÷Íí/ã÷ø¨ªòÚ÷ü½ª·ªŞª¹¡£
		 Stored ProcedureªÎRecordsetªÇªÏŞÅéÄªÇª­ªŞª»ªó¡£

		 \~
		 */
		bool MoveLast();
		/**
		 \~korean
		 ÀÌÀü ·¹ÄÚµå·Î ÀÌµ¿ÇÕ´Ï´Ù.
		 ¼º°ø/½ÇÆĞ¸¦ ¹İÈ¯ÇÕ´Ï´Ù.
		 Stored ProcedureÀÇ Recordset¿¡¼­´Â »ç¿ëÇÒ ¼ö ¾ø½À´Ï´Ù.

		 \~english
		 Move to the previous record.
		 Return success/fail
		 You cannot use it in the Recordset of the stored procedure. 

		 \~chinese
		 ì¹?Óğîñìé???¡£
		 Ú÷üŞà÷/ã÷?¡£
		 î¤Stored ProcedureîÜRecordsetñéÜôÒöŞÅéÄ¡£

		 \~japanese
		 ì¤îñªÎ«ì«³?«ÉªËì¹ÔÑª·ªŞª¹¡£
		 à÷Íí/ã÷ø¨ªòÚ÷ü½ª·ªŞª¹¡£
		 Stored ProcedureªÎRecordsetªÇªÏŞÅéÄªÇª­ªŞª»ªó¡£

		 \~
		 */
		bool MovePrev();
		
		/**
		 \~korean
		 ´ÙÀ½ ·¹ÄÚµå·Î ÀÌµ¿ÇÕ´Ï´Ù.
		 ¼º°ø/½ÇÆĞ¸¦ ¹İÈ¯ÇÕ´Ï´Ù.
		 µ¥ÀÌÅÍ¸¦ ¾òÀ» ¶§ ÀÌ ÇÔ¼ö¸¦ ¸ÕÀú È£ÃâÇØ¾ß¸¸ ¾òÀ» ¼ö ÀÖ½À´Ï´Ù.

		 \~english
		 Move to the next record. 
		 Return success/fail
		 You cannot use it in the Recordset of the stored procedure. 

		 \~chinese
		 ì¹?Óğù»ìé???¡£
		 Ú÷üŞà÷/ã÷?¡£
		 ñşêóŞÀà»?éÄùŞ?î¦Òö?Ôğ?Ëß¡£

		 \~japanese
		 ó­ªÎ«ì«³?«ÉªËì¹ÔÑª·ªŞª¹¡£
		 à÷Íí/ã÷ø¨ªòÚ÷ü½ª·ªŞª¹¡£
		 «Ç?«¿ªòÔğªëãÁªÏ¡¢ª³ªÎ??ªòà»ªËû¼ªÓõóª·ªÆª³ª½Ôğªëª³ªÈª¬ªÇª­ªŞª¹¡£

		 \~
		 */
		bool MoveNext();

		/**
		 \~korean
		 ¿©·¯°³ÀÇ ·¹ÄÚµå¼ÂÀ» °¡Á®¿À´Â °æ¿ì ÀÌ ÇÔ¼ö¸¦ ÅëÇØ ´ÙÀ½ ·¹ÄÚµå¼ÂÀ¸·Î ÀüÈ¯ÇÒ ¼ö ÀÖ½À´Ï´Ù.
		 ¼º°ø/½ÇÆĞ¸¦ ¹İÈ¯ÇÕ´Ï´Ù.

		 \~english
		 When you bring many recordsets, you can change to the next recordset using this function. 
		 Return success/fail

		 \~chinese
		 ?ö¢Òı? RecordSet ?£¬Ê¦ì¤÷×??ùŞ????ù»ìé? RecordSet¡£
		 î¤?ö¢Òı???ó¢?Ê¦÷×?ó®ùŞ?Ú÷üŞà÷Íí/ã÷?¡£

		 \~japanese
		ÜÜ?ªÎ«ì«³?«É«»«Ã«Èªòö¢ªê?ªàíŞùê¡¢ª³ªÎ??ªò÷×ª¸¡¢ó­ªÎ«ì«³?«É«»«Ã«ÈªËï·ªêôğª¨ªéªìªŞª¹¡£
		à÷Íí/ã÷ø¨ªòÚ÷ü½ª·ªŞª¹¡£

		 \~
		 */
		bool NextRecordSet();

		/**
		 \~korean
		 ÀüÃ¼ Row °³¼ö¸¦ ¹İÈ¯ÇÕ´Ï´Ù.

		 \~english
		 Return the total number of Row. 

		 \~chinese
		 Ú÷?á¶êó Row??¡£

		 \~japanese
		 îï?Row?ªòÚ÷ü½ª·ªŞª¹¡£

		 \~
		 */
		SQLLEN GetRowCount();
		/**
		 \~korean
		 ÇöÀç Row Index¸¦ ¹İÈ¯ÇÕ´Ï´Ù. (ex> 0, 1, 2, ...)
		 Row Index°¡ -1ÀÌ¸é BOF »óÅÂÀÌ¸ç, Row Count¿Í °°´Ù¸é EOF »óÅÂÀÔ´Ï´Ù.

		 \~english
		 Return the current Row Index (ex> 0, 1, 2, ...).
		 If Row Index is -1, its status is BOF and if it is same as Row Count, its status is EOF.

		 \~chinese
		 ?îñÚ÷?Row Index¡£(ex> 0, 1, 2, ...)
		 Row Index å´ãÀ -1?ãÀ BOF??,å´?Row CountßÓÔÒ?ãÀ EOF ??¡£

		 \~japanese
		 úŞî¤Row IndexªòÚ÷ü½ª·ªŞª¹¡£(ex> 0, 1, 2, ...)
		 Row Indexª¬-1ªÊªéBOF?÷¾ªÇ¡¢Row CountªÈÔÒª¸ªÊªéEOF?÷¾ªÇª¹¡£

		 \~
		 */
		SQLLEN GetCurrentRowIndex();
		/**
		 \~korean
		 ÀüÃ¼ Field °³¼ö¸¦ ¹İÈ¯ÇÕ´Ï´Ù.

		 \~english
		 Return the total number of Fields. 

		 \~chinese
		 Ú÷?á¶êóField??¡£

		 \~japanese
		 îï?Field ËÁ?ªòÚ÷ü½ª·ªŞª¹¡£

		 \~
		 */
		SQLSMALLINT GetFieldCount();

		/**
		 \~korean
		 BOF´Â Index == -1ÀÏ ¶§ ÀÌ¸ç ¾ÆÁ÷ ÀĞÀº µ¥ÀÌÅÍ°¡ ¾ø´Â »óÅÂÀÔ´Ï´Ù.

		 \~english
		 BOF indicates Index == -1 and it means there is no data that has been read. 

		 \~chinese
		 BOF? Index == -1 ?£¬ãÀÚ±??ËßîÜ??¡£

		 \~japanese
		 BOFªÏIndex == -1ªÎãÁªÇ¡¢ªŞªÀÚ±?ªÎ«Ç?«¿ª¬ªÊª¤?÷¾ªÇª¹¡£

		 \~
		 */
		bool IsBof();
		/**
		 \~korean
		 EOF´Â Index == GetRowCount()ÀÏ ¶§ ÀÌ¸ç µ¥ÀÌÅÍ¸¦ ¸ğµÎ ÀĞÀº »óÅÂÀÔ´Ï´Ù.

		 \~english
		 EOF indicates Index == GetRowCount() and it means all data has been read. 

		 \~chinese
		 EOF? Index == GetRowCount()?£¬ãÀì«?á¶êó?ËßîÜ??¡£

		 \~japanese
		 EOFªÏIndex == GetRowCount()ªÎãÁªÇª¢ªê¡¢îïªÆªÎ«Ç?«¿ª¬??ªÎ?÷¾ªÇª¹¡£

		 \~
		 */
		bool IsEof();

		/**
		 \~korean
		 Field(Column)ÀÇ ÀÌ¸§À» ¾ò¾î ¿É´Ï´Ù.
		 "SELECT COUNT(*) FROM TABLE"°ú °°ÀÌ ÄÃ·³¸íÀÌ Á¤ÇØÁöÁö ¾ÊÀº Äõ¸®¿¡¼­´Â Á¤»ó ÀÛµ¿ÇÏÁö ¾ÊÀ» ¼ö ÀÖ½À´Ï´Ù.
		 ±×·² ¶© ÄÃ·³¸í¿¡ Alias¸¦ ¼³Á¤ÇÏ¿© "SELECT COUNT(*) AS TOTAL FROM TABLE"°ú °°ÀÌ »ç¿ëÇÏ½Ã¸é µË´Ï´Ù.

		 \~english
		 Get the name of Field(Column).
		 It might not be executed normally at a query whose column name has not been defined, such as "SELECT COUNT(*) FROM TABLE".
		 In this case, set Alias in the column name  and use it like "SELECT COUNT(*) AS TOTAL FROM TABLE".

		 \~chinese
		 ?ö¢Field(Column)Ù£?¡£
		 ?"SELECT COUNT(*) FROM TABLE"ßÓÔÒ£¬î¤Column NameÚ±ïÒîÜqueryñé£¬êóÊ¦ÒöÙéÛöïáßÈ?ú¼¡£
		 ??î¤Column Name?ïÒAliası¨£¬?"SELECT COUNT(*) AS TOTAL FROM TABLE"ßÓÔÒÛ°ÛöŞÅéÄ?Ê¦¡£

		 \~japanese
		 Field(Column)ªÎÙ£ªòö¢Ôğª·ªŞª¹¡£
		 "SELECT COUNT(*) FROM TABLE"ªÎªèª¦ªË ColumnÙ£ª¬Ì½ªáªéªìªÆª¤ªÊª¤«¯«¨«ê?ªÇªÏïáßÈíÂÔÑª·ªÊª¤íŞùêªâª¢ªêªŞª¹¡£
		 ª½ªÎíŞùêªËªÏColumnÙ£ªËAliasªòàâïÒª·"SELECT COUNT(*) AS TOTAL FROM TABLE"ªÎªèª¦ªËŞÅéÄª·ªÆª¯ªÀªµª¤¡£

		 \~
		 */
		String GetFieldName(int fieldIndex);

		/**
		 \~korean
		 Field(Column)ÀÇ SqlDataTypeÀ» ¾ò¾î ¿É´Ï´Ù.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~english
		 Get SqlDataType of Field(Column).
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~chinese
		 ?ö¢Field(Column)îÜ SqlDataType¡£
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~japanese
		 Field(Column)ªÎSqlDataTypeªòö¢Ôğª·ªŞª¹¡£
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~
		 */
		OdbcSqlDataType GetFieldSqlType(int fieldIndex);
		/**
		 \~korean
		 Field(Column)ÀÇ SqlDataTypeÀ» ¾ò¾î ¿É´Ï´Ù.
		 \param fieldName Field(Column) ÀÌ¸§

		 \~english
		 Get SqlDataType of Field(Column).
		 \param fieldname It is the name of Field(Column).

		 \~chinese
		 ?ö¢Field(Column)îÜ SqlDataType
		 \param fieldName Field(Column) Ù£?¡£

		 \~japanese
		 Field(Column)ªÎSqlDataTypeªòö¢Ôğª·ªŞª¹¡£
		 \param fieldName Field(Column) Ù£

		 \~
		 */
		OdbcSqlDataType GetFieldSqlType(const String& fieldName);

		/**
		 \~korean
		 Field(Column) µ¥ÀÌÅÍÀÇ ÇöÀç Å©±â¸¦ °¡Á®¿É´Ï´Ù.
		 NULLÀÏ °æ¿ì -1À» ¹İÈ¯ ÇÕ´Ï´Ù.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~english
		 Bring the current size of Field(Column) data. 
		 In case of NULL, it returns -1. 
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~chinese
		 ?ö¢?îñÓŞá³îÜField(Column) ?Ëß¡£
		 åıÍıãÀNULLîÜï×?£¬Ú÷? -1¡£.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~japanese
		 Field(Column)«Ç?«¿ªÎúŞî¤«µ«¤«ºªò«í?«Éª·ªŞª¹¡£
		 NULLªÎíŞùê -1ªòÚ÷ü½ª·ªŞª¹¡£
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~
		 */
		SQLLEN GetFieldSizeOrNull(int fieldIndex);
		/**
		 \~korean
		 Field(Column) µ¥ÀÌÅÍÀÇ ÇöÀç Å©±â¸¦ °¡Á®¿É´Ï´Ù.
		 NULLÀÏ °æ¿ì -1À» ¹İÈ¯ ÇÕ´Ï´Ù.
		 \param fieldName Field(Column) ÀÌ¸§

		 \~english
		 Bring the current size of Field(Column) data. 
		 In case of NULL, it returns -1. 
		 \param fieldname It is the name of Field(Column).

		 \~chinese
		 ?ö¢?îñÓŞá³îÜField(Column) ?Ëß¡£
		 åıÍıãÀNULLîÜï×?£¬Ú÷? -1¡£.
		 \param fieldName Field(Column)Ù£?

		 \~japanese
		 Field(Column) «Ç?«¿ªÎúŞî¤«µ«¤«ºªò«í?«Éª·ªŞª¹¡£
		 NULLªÎíŞùê -1ªòÚ÷ü½ª·ªŞª¹¡£
		 \param fieldName Field(Column) Ù£

		 \~
		 */
		SQLLEN GetFieldSizeOrNull(const String& fieldName);

		/**
		 \~korean
		 Field(Column) µ¥ÀÌÅÍÀÇ ÃÖ´ë Å©±â(µ¥ÀÌÅÍº£ÀÌ½º ¼³Á¤)¸¦ °¡Á®¿É´Ï´Ù.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~english
		 Bring the maximum size (Database setting) of Field(Column) data.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~chinese
		 ?ö¢Field(Column)?ËßîÜõÌÓŞ?£¨?Ëß??ïÒ£©¡£
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~japanese
		 Field(Column) «Ç?«¿ªÎõÌÓŞ«µ«¤«º£¨«Ç?«¿«Ù?«¹àâïÒ£©ªò«í?«Éª·ªŞª¹¡£
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~
		 */
		SQLULEN GetFieldMaxSize(int fieldIndex);
		/**
		 \~korean
		 Field(Column) µ¥ÀÌÅÍÀÇ ÃÖ´ë Å©±â(µ¥ÀÌÅÍº£ÀÌ½º ¼³Á¤)¸¦ °¡Á®¿É´Ï´Ù.
		 \param fieldName Field(Column) ÀÌ¸§

		 \~english
		 Bring the maximum size (Database setting) of Field(Column) data.
		 \param fieldname It is the name of Field(Column).

		 \~chinese
		 ?ö¢ Field(Column)?ËßîÜõÌÓŞ?£¨?Ëß??ïÒ£©¡£
		 \param fieldName Field(Column) Ù£?

		 \~japanese
		 Field(Column) «Ç?«¿ªÎõÌÓŞ«µ«¤«º£¨«Ç?«¿«Ù?«¹àâïÒ£©ªò«í?«Éª·ªŞª¹¡£
		 \param fieldName Field(Column) Ù£

		 \~
		 */
		SQLULEN GetFieldMaxSize(const String& fieldName);

		/**
		 \~korean
		 Field(Column) µ¥ÀÌÅÍÀÇ ¼Ò¼öÁ¡ ¾Æ·¡ Á¤¹Ğµµ(ÀÚ¸®¼ö)¸¦ °¡Á®¿É´Ï´Ù.
		 Real, Float, Double, Timestamp¿Í °°Àº Çü½Ä¿¡¼­ »ç¿ëÇÕ´Ï´Ù.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~english
		 Bring a decimal place of Field(Column) data.
		 It is used at types like Real, Float, Double and Timestamp.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~chinese
		 ?ö¢Field(Column)?ËßîÜá³?ïÃì¤ù»îÜïñÚËÓø £¨êÈ?£©¡£
		 î¤?Real, Float, Double, TimestampßÓÔÒîÜû¡ãÒù»ŞÅéÄ¡£
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~japanese
		 Field(Column) «Ç?«¿ªÎá³?ïÃì¤ù»ïñÚËÓø£¨?ªÎùù£©ªò«í?«Éª·ªŞª¹¡£
		 Real, Float, Double, TimestampªÎªèª¦ªÊû¡ãÒªÇŞÅéÄªµªìªŞª¹¡£
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~
		 */
		SQLSMALLINT GetFieldPrecision(int fieldIndex);
		/**
		 \~korean
		 Field(Column) µ¥ÀÌÅÍÀÇ ¼Ò¼öÁ¡ ¾Æ·¡ Á¤¹Ğµµ(ÀÚ¸®¼ö)¸¦ °¡Á®¿É´Ï´Ù.
		 Real, Float, Double, Timestamp¿Í °°Àº Çü½Ä¿¡¼­ »ç¿ëÇÕ´Ï´Ù.
		 \param fieldName Field(Column) ÀÌ¸§

		 \~english
		 Bring a decimal place of Field(Column) data.
		 It is used at types like Real, Float, Double and Timestamp.
		 \param fieldname It is the name of Field(Column).

		 \~chinese
		 ?ö¢Field(Column)?ËßîÜá³?ïÃì¤ù»îÜïñÚËÓø £¨êÈ?£©¡£
		 î¤?Real, Float, Double, TimestampßÓÔÒîÜû¡ãÒù»ŞÅéÄ¡£
		 \param fieldName Field(Column)Ù£?

		 \~japanese
		 Field(Column) «Ç?«¿ªÎá³?ïÃì¤ù»ïñÚËÓø£¨?ªÎùù£©ªò«í?«Éª·ªŞª¹¡£
		 Real, Float, Double, TimestampªÎªèª¦ªÊû¡ãÒªÇŞÅéÄª·ªŞª¹¡£
		 \param fieldName Field(Column) Ù£

		 \~
		 */
		SQLSMALLINT GetFieldPrecision(const String& fieldName);

		/**
		 \~korean
		 Field(Column) µ¥ÀÌÅÍ·Î NULLÀ» ÀÔ·ÂÇÒ ¼ö ÀÖ´ÂÁö(µ¥ÀÌÅÍº£ÀÌ½º ¼³Á¤)¸¦ ¹İÈ¯ÇÕ´Ï´Ù.
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~english
		 Return whether or not it can input NULL by Field(Column) data (Database setting).
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~chinese
		 Ú÷?Field(Column) ?ËßãÀÜúÊ¦ì¤?ìı NULL£¨?Ëß??ïÒ£©
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~japanese
		 Field(Column) «Ç?«¿ªÇNULLªòìıÕôªÇª­ªëª«£¨«Ç?«¿«Ù?«¹àâïÒ£©ªòÚ÷ü½ª·ªŞª¹¡£
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~
		 */
		bool GetFieldNullable(int fieldIndex);
		/**
		 \~korean
		 Field(Column) µ¥ÀÌÅÍ·Î NULLÀ» ÀÔ·ÂÇÒ ¼ö ÀÖ´ÂÁö(µ¥ÀÌÅÍº£ÀÌ½º ¼³Á¤)¸¦ ¹İÈ¯ÇÕ´Ï´Ù.
		 \param fieldName Field(Column) ÀÌ¸§

		 \~english
		 Return whether or not it can input NULL by Field(Column) data (Database setting).
		 \param fieldname It is the name of Field(Column).

		 \~chinese
		 Ú÷?Field(Column) ?ËßãÀÜúÊ¦ì¤?ìı NULL£¨?Ëß??ïÒ£©
		 \param fieldName Field(Column)Ù£?

		 \~japanese
		 Field(Column) «Ç?«¿ªÇNULLªòìıÕôªÇª­ªëª«£¨«Ç?«¿«Ù?«¹àâïÒ£©ªòÚ÷ü½ª·ªŞª¹¡£
		 \param fieldName Field(Column) Ù£

		 \~
		 */
		bool GetFieldNullable(const String& fieldName);

		/**
		 \~korean
		 Field(Column) µ¥ÀÌÅÍ¸¦ ¹İÈ¯ÇÕ´Ï´Ù.
		 µ¥ÀÌÅÍ°¡ ¾î¶² ÇüÀÎÁö ¸ğ¸¦ °æ¿ì GetFieldSqlType()¸¦ ÀÌ¿ëÇÏ¿© ¾Ë ¼ö ÀÖ½À´Ï´Ù.
		 OdbcSqlDataType°ú ¸ÅÇÎµÇ´Â Default OdbcDataTypeÀº OdbcEnum.h¸¦ Âü°í ÇÏ½Ê½Ã¿À.
		 ex> int a = recordset.GetFieldValue(1);
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~english
		 Return Field(Column) data.
		 In case you do not know the type of data, use GetFieldSqlType() to get to know. 
		 Refer to OdbcEnum.h for Default OdbcDataType that is mapped with OdbcSqlDataType.
		 ex> int a = recordset.GetFieldValue(1);
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~chinese
		 Ú÷?Field(Column)?Ëß¡£
		 Üôò±Ô³?ËßãÀä§?û¡ãÒîÜï×?ù»£¬Ê¦ì¤××éÄ GetFieldSqlType()ò±Ô³¡£
		 OdbcSqlDataTypeûú mapping Default OdbcDataType ??ÍÅ OdbcEnum.h¡£
		 ex> int a = recordset.GetFieldValue(1);
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~japanese
		 Field(Column) «Ç?«¿ªòÚ÷ü½ª·ªŞª¹¡£
		 «Ç?«¿úşªòò±ªéªÊª¤íŞùêGetFieldSqlType()ªò××éÄª·ªÆò±ªëª³ªÈª¬ªÇª­ªŞª¹¡£
		 OdbcSqlDataTypeªÈ«Ş«Ã«Ô«ó«°ªÇª­ªëDefault OdbcDataTypeªÏOdbcEnum.hªòª´?ÍÅª¯ªÀªµª¤¡£
		 ex> int a = recordset.GetFieldValue(1);
		 \param fieldIndex Field(Column) Index (ex> 1, 2, 3, ...)

		 \~
		 */
		const COdbcVariant& GetFieldValue(int fieldIndex);
		/**
		 \~korean
		 Field(Column) µ¥ÀÌÅÍ¸¦ ¹İÈ¯ÇÕ´Ï´Ù.
		 µ¥ÀÌÅÍ°¡ ¾î¶² ÇüÀÎÁö ¸ğ¸¦ °æ¿ì GetFieldSqlType()¸¦ ÀÌ¿ëÇÏ¿© ¾Ë ¼ö ÀÖ½À´Ï´Ù.
		 OdbcSqlDataType°ú ¸ÅÇÎµÇ´Â Default OdbcDataTypeÀº OdbcEnum.h¸¦ Âü°í ÇÏ½Ê½Ã¿À.
		 ex> int a = recordset.GetFieldValue("name");
		 \param fieldName Field(Column) ÀÌ¸§

		 \~english
		 Return Field(Column) data.
		 In case you do not know the type of data, use GetFieldSqlType() to get to know. 
		 Refer to OdbcEnum.h for Default OdbcDataType that is mapped with OdbcSqlDataType.
		 ex> int a = recordset.GetFieldValue("name");
		 \param fieldname It is the name of Field(Column).

		 \~chinese
		 Ú÷?Field(Column)?Ëß¡£
		 Üôò±Ô³?ËßãÀä§?û¡ãÒîÜï×?ù»£¬Ê¦ì¤××éÄ GetFieldSqlType()ò±Ô³¡£
		 OdbcSqlDataTypeûú mapping Default OdbcDataType ??ÍÅ OdbcEnum.h¡£
		 ex> int a = recordset.GetFieldValue("name");
		 \param fieldName Field(Column) Ù£?

		 \~japanese
		 Field(Column) «Ç?«¿ªòÚ÷ü½ª·ªŞª¹¡£
		 «Ç?«¿úşªòò±ªéªÊª¤íŞùêGetFieldSqlType()ªò××éÄª·ªÆò±ªëª³ªÈª¬ªÇª­ªŞª¹¡£
		 OdbcSqlDataTypeªÈ«Ş«Ã«Ô«ó«°ªµªìªëDefault OdbcDataTypeªÏ OdbcEnum.hªòª´?ÍÅª¯ªÀªµª¤¡£
		 ex> int a = recordset.GetFieldValue("name");
		 \param fieldName Field(Column) Ù£

		 \~
		 */
		const COdbcVariant& GetFieldValue(const String& fieldName);

		// WARNING::³»ºÎ¿¡¼­ »ç¿ëµÇ´Â ÇÔ¼öÀÔ´Ï´Ù. »ç¿ëÇÏÁö ¸¶½Ã±â ¹Ù¶ø´Ï´Ù.
		// WARNING::Internal use only. Don't use this function.
		void SetEnvironment(COdbcConnection* conn, void *hstmt, const SQLLEN &rowcount);

	private:
		COdbcRecordsetImpl* m_pImpl;

		COdbcRecordset(const COdbcRecordset& other);
		COdbcRecordset& operator=(const COdbcRecordset& other);
	};
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif