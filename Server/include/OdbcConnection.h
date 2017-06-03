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

#include "OdbcEnum.h"
#include "OdbcException.h"
#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class COdbcHandle;
	class COdbcRecordset;
	class COdbcConnectionImpl;

	/**
	 \~korean
	 Connection °ü¸®¿Í Transaction Á¦¾î, DirectExecute¸¦ ½ÇÇàÇÒ ¼ö ÀÖ´Â Å¬·¡½º ÀÔ´Ï´Ù.
	 ODBC ¸Å´ÏÀú¸¦ ÅëÇØ »ç¿ëÇÏ½Ã´Â µ¥ÀÌÅÍº£ÀÌ½ºÀÇ µå¶óÀÌ¹ö¸¦ µî·ÏÇÏ¿© ÇØ´ç DSN(Data Source Name)À» ÅëÇØ Á¢±ÙÇÏ½Ã¸é µË´Ï´Ù.

	 \~english
	 It is a class that can manage Connection, control Transaction and execute DirectExecute.
	 Register a driver of database that you are using by the ODBC manager and access through DSN(Data Source Name).

	 \~chinese
	 Ê¦?ú¼Connection Î·×â£¬ Transaction ğ¤åÙ, DirectExecute îÜclass¡£
	 ÷×? ODBCÎ·×â£¬ñ¼?ŞÅéÄîÜ?Ëß?driver£¬÷×??DSN(Data Source Name)???Ê¦¡£

	 \~japanese
	 Connection Î·×âªÈ Transaction «³«ó«È«í?«ë¡¢DirectExecuteªò?ú¼ªÇª­ªë«¯«é«¹ªÇª¹¡£
	 ODBC«Ş«Í?«¸«ã?ªò÷×ª¸ªÆŞÅéÄª¹ªë«Ç?«¿«Ù?«¹ªÎ«É«é«¤«Ğ?ªòÔô?ª·¡¢ú±?DSN(Data Source Name)ªò÷×ª¸ªÆïÈĞÎª·ªÆª¯ªÀªµª¤¡£

	 \~
	 */
	class COdbcConnection
	{
	public:
		COdbcConnection();
		~COdbcConnection();

		/**
		 \~korean
		 µ¥ÀÌÅÍº£ÀÌ½º¿¡ ¿¬°áÇÒ ¶§ »ç¿ëÇÕ´Ï´Ù.

		 \~english
		 It is used when connecting to the database. 

		 \~chinese
		 ?ïÈ?Ëß??ŞÅéÄ¡£

		 \~japanese
		 «Ç?«¿«Ù?«¹ªËÖ§Ì¿ª¹ªëªÈª­ªËŞÅéÄª·ªŞª¹¡£

		 \~
		 */
		void Open(const String& dsn, const String& id, const String& passwd, COdbcWarnings* odbcWarnings = NULL);

		/**
		 \~korean
		 µ¥ÀÌÅÍº£ÀÌ½º¿¡ ¿¬°áÇÒ ¶§ »ç¿ëÇÕ´Ï´Ù.
		 ex> conn.Open("DSN=MsSqlDsn;UID=root;PWD=1234")

		 \~english
		 It is used when connecting to the database. 
		 ex> conn.Open("DSN=MsSqlDsn;UID=root;PWD=1234")

		 \~chinese
		 ?ïÈ?Ëß??ŞÅéÄ¡£
		 ex> conn.Open("DSN=MsSqlDsn;UID=root;PWD=1234").

		 \~japanese
		 «Ç?«¿«Ù?«¹ªËÖ§Ì¿ª¹ªëªÈª­ªËŞÅéÄª·ªŞª¹¡£
		 ex> conn.Open("DSN=MsSqlDsn;UID=root;PWD=1234")

		 \~
		 */
		void Open(const String& connectionString, COdbcWarnings* odbcWarnings = NULL);

		/**
		 \~korean
		 ¿¬°áÀ» Á¾·áÇÒ ¶§ »ç¿ëÇÕ´Ï´Ù.
		 ÀÌ Ä¿³Ø¼ÇÀ» ÅëÇØ »ı¼ºµÈ ¸ğµç COdbcCommand, COdbcRecordset °´Ã¼¿¡°Ô ¿µÇâÀ» ¹ÌÄ¨´Ï´Ù.

		 \~english
		 It is used when disconnection.
		 It has an effect on all COdbcCommand objects and COdbcRecordset objects that have been created by this connection. 

		 \~chinese
		 ?ïÈ?Öõ?ŞÅéÄ¡£
		 ?ç¯?Óğá¶êó÷×?ó®?ïÈßæà÷îÜ COdbcCommand, COdbcRecordset ?ßÚ¡£

		 \~japanese
		 Ö§Ì¿ªòğûÖõª¹ªëªÈª­ªËŞÅéÄª·ªŞª¹¡£
		 ª³ªÎ«³«Í«¯«·«ç«óªò÷×ª¸ªÆßæà÷ªµªìª¿îïªÆªÎCOdbcCommand, COdbcRecordset«ª«Ö«¸«§«¯«ÈªËç¯úÂªò?ª¨ªŞª¹¡£

		 \~
		 */
		void Close();

		/**
		 \~korean
		 Æ®·£Àè¼ÇÀ» ½ÃÀÛÇÒ ¶§ »ç¿ëÇÕ´Ï´Ù.
		 RollbackTrans() ÀÌ³ª CommitTrans()À» ½ÇÇàÇÏ¿© Æ®·£Àè¼ÇÀ» Á¾·áÇÏ¸é ´Ù½Ã È£ÃâÇØ¾ß Àû¿ë µË´Ï´Ù.

		 \~english
		 It is used when starting transaction. 
		 In case transaction ends by executing RollbackTrans() or CommitTrans(), it is applied only when re-calling. 

		 \~chinese
		 Transaction?ã·?ŞÅéÄ¡£
		 ÷×??ú¼ RollbackTrans() ûä CommitTrans()?ÖõTransaction?£¬âÍñìãæû¼õóî¦Òöù¬ÎÁéÄ¡£

		 \~japanese
		 «È«é«ó«¶«¯«·«ç«óªòã·ªŞªëãÁªËŞÅéÄª·ªŞª¹¡£
		 RollbackTrans() ªä CommitTrans()ªò?ú¼ª·¡¢«È«é«ó«¶«¯«·«ç«óªòğûÖõª·ª¿íŞùê¡¢îêéÄªÎª¿ªáªËªÏªâª¦ìéÓøû¼ªÓõóª¹ù±é©ª¬ª¢ªêªŞª¹¡£

		 \~
		 */
		void BeginTrans();

		/**
		 \~korean
		 Æ®·£Àè¼ÇÀ» RollbackÇÒ ¶§ »ç¿ëÇÕ´Ï´Ù.

		 \~english
		 It is used when transaction rollback. 

		 \~chinese
		 Rollback Transaction?ŞÅéÄ¡£

		 \~japanese
		 «È«é«ó«¶«¯«·«ç«óªòRollbackª¹ªëãÁªËŞÅéÄª·ªŞª¹¡£

		 \~
		 */
		void RollbackTrans();

		/**
		 \~korean
		 Æ®·£Àè¼ÇÀ» CommitÇÒ ¶§ »ç¿ëÇÕ´Ï´Ù.

		 \~english
		 It is used when committing transaction. 

		 \~chinese
		 Transaction Commit ?ŞÅéÄ¡£

		 \~japanese
		 «È«é«ó«¶«¯«·«ç«óªòCommitª¹ªëãÁªËŞÅéÄª·ªŞª¹¡£

		 \~
		 */
		void CommitTrans();

		/**
		 \~korean
		 µ¥ÀÌÅÍº£ÀÌ½º¿¡ ÇöÀç ¿¬°áÁßÀÎÁö È®ÀÎÇÒ ¶§ »ç¿ëÇÕ´Ï´Ù.

		 \~english
		 It is used when checking if connection to the database is normal. 

		 \~chinese
		 ???î¤ãÀÜú??Ëß??ïÈ?ŞÅéÄ¡£

		 \~japanese
		 úŞî¤«Ç?«¿«Ù?«¹ªËÖ§Ì¿ñéªÇª¢ªëª«ü¬ìãª¹ªëªÈª­ªËŞÅéÄª·ªŞª¹¡£

		 \~
		 */
		bool IsOpened();

		/**
		 \~korean
		 ´ÙÀÌ·ºÆ® Äõ¸®¸¦ ½ÇÇàÇÕ´Ï´Ù.
		 Äõ¸® ½ÇÇàÀ¸·Î ¿µÇâÀ» ¹ŞÀº Row °³¼ö¸¦ ¹İÈ¯ÇÕ´Ï´Ù.
		 \param query Äõ¸®¹®

		 \~english
		 It executed a direct query.
		 \param query It is a query.

		 \~chinese
		 ?ú¼ direct query¡£
		 \param query queryÙşËì¡£

		 \~japanese
		 «À«¤«ì«¯«È«¯«¨«ê?ªò?ú¼ª·ªŞª¹¡£
		 \param query «¯«¨«ê?Ùş

		 \~
		 */
		int Execute(const String& query, COdbcWarnings* odbcWarnings = NULL);

		/**
		 \~korean
		 ´ÙÀÌ·ºÆ® Äõ¸®¸¦ ½ÇÇàÇÕ´Ï´Ù.
		 Äõ¸® ½ÇÇàÀ¸·Î ¿µÇâÀ» ¹ŞÀº Row °³¼ö¸¦ ¹İÈ¯ÇÕ´Ï´Ù.
		 \param recordset SELECT Äõ¸® ½ÇÇà ½Ã ¹Ş¾ÆÁö´Â Recordset °´Ã¼
		 \param query Äõ¸®¹®

		 \~english
		 It executed a direct query.
		 \param recordset It is a Recordset object that is received when executing SELECT query.
		 \param query It is a query.

		 \~chinese
		 ?ú¼ direct query ¡£
		 \param recordset SELECT query ?ú¼?£¬ïÈâ¥îÜ Recordset ?ßÚ¡£
		 \param query queryÙşËì

		 \~japanese
		 «À«¤«ì«¯«È«¯«¨«ê?ªò?ú¼ª·ªŞª¹¡£
		 \param recordset SELECT «¯«¨«ê??ú¼ª·«í?«ÉªµªìªëRecordset«ª«Ö«¸«§«¯«È
		 \param query «¯«¨«ê?Ùş

		 \~
		 */
		int Execute(COdbcRecordset &recordset, const String& query, COdbcWarnings* odbcWarnings = NULL);

		// WARNING::³»ºÎ¿¡¼­ »ç¿ëµÇ´Â ÇÔ¼öÀÔ´Ï´Ù. »ç¿ëÇÏÁö ¸¶½Ã±â ¹Ù¶ø´Ï´Ù.
		// WARNING::Internal use only. Don't use this function.
		void AllocStmtHandle(COdbcHandle* hstmt, OdbcPrepareType typem, COdbcWarnings* odbcWarnings = NULL);

	private:
		COdbcConnectionImpl* m_pImpl;

		COdbcConnection(const COdbcConnection& other);
		COdbcConnection& operator=(const COdbcConnection& other);
	};

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif