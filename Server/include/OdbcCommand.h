/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


ÀÌ ÇÁ·Î±×·¥ÀÇ ÀúÀÛ±ÇÀº ³ÝÅÙ¼Ç¿¡°Ô ÀÖ½À´Ï´Ù.
ÀÌ ÇÁ·Î±×·¥ÀÇ ¼öÁ¤, »ç¿ë, ¹èÆ÷¿¡ °ü·ÃµÈ »çÇ×Àº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾àÀ» µû¸£¸ç,
°è¾àÀ» ÁØ¼öÇÏÁö ¾Ê´Â °æ¿ì ¿øÄ¢ÀûÀ¸·Î ¹«´Ü »ç¿ëÀ» ±ÝÁöÇÕ´Ï´Ù.
¹«´Ü »ç¿ë¿¡ ÀÇÇÑ Ã¥ÀÓÀº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾à¼­¿¡ ¸í½ÃµÇ¾î ÀÖ½À´Ï´Ù.

** ÁÖÀÇ : ÀúÀÛ¹°¿¡ °üÇÑ À§ÀÇ ¸í½Ã¸¦ Á¦°ÅÇÏÁö ¸¶½Ê½Ã¿À.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


ó®ïïßíîÜ÷ú??NettentionÍëÞÉá¶êó¡£
?ó®ïïßíîÜáóËÇ¡¢ÞÅéÄ¡¢?øÖßÓ?îÜÞÀ?é©ñåáúó®ïïßíîÜá¶êó?íºîÜ??¡£
Üôñåáú???é©ê«?àõîÜÐ×ò­ôºí»ÞÅéÄ¡£
ôºí»ÞÅéÄîÜ?ìòÙ¥ãÆî¤?ó®ïïßíá¶êó?íºîÜùêÔÒ?×ì¡£

** ñ¼ëò£ºÜôé©ì¹ð¶?éÍð¤íÂÚªîÜß¾âûÙ¥ãÆ¡£


ª³ªÎ«×«í«°«é«àªÎîÊíÂ?ªÏNettentionªËª¢ªêªÞª¹¡£
ª³ªÎ«×«í«°«é«àªÎáóïá¡¢ÞÅéÄ¡¢ÛÕøÖªË?ª¹ªëÞÀú£ªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ªË?ª¤¡¢
Ìøå³ªòñåáúª·ªÊª¤íÞùê¡¢ê«öÎîÜªËÙí?ÞÅéÄªòÐ×ª¸ªÞª¹¡£
Ùí?ÞÅéÄªËªèªëô¡ìòªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ßöªËÙ¥ãÆªµªìªÆª¤ªÞª¹¡£

** ñ¼ëò£ºîÊíÂÚªªË?ª¹ªëß¾ÑÀªÎÙ¥ãÆªòð¶ËÛª·ªÊª¤ªÇª¯ªÀªµª¤¡£

*/

#pragma once

#include "OdbcEnum.h"
#include "OdbcException.h"
#include "OdbcVariant.h"
#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class COdbcCommandImpl;
	class COdbcConnection;
	class COdbcRecordset;

	/**
	 \~korean
	 Prepared Statement¸¦ Ã³¸®ÇÏ±â À§ÇÑ Å¬·¡½º ÀÔ´Ï´Ù.
	 COdbcConnectionÀÇ Execute¿Í´Â ´Þ¸® ÇÑ ¹ø ¼³Á¤µÈ Äõ¸®¸¦ ÆÄ¶ó¹ÌÅÍ °ª¸¸ º¯°æÇÏ¿© °è¼Ó »ç¿ëÇÒ ¶§ À¯¿ëÇÕ´Ï´Ù.
	 Input, Output, Input&Output ÆÄ¶ó¹ÌÅÍ°¡ ÇÊ¿äÇÑ Stored Procedure¸¦ ½ÇÇàÇÒ ¶§µµ »ç¿ë µË´Ï´Ù.

	 \~english
	 It is a class that deals with Prepared Statement.
	 It is useful for continuous use by changing parameter value of a query, differently from Execute in COdbcConnection.
	 Also used when executing Stored Procedure that Input, Output and  Input&Output parameter need. 

	 \~chinese
	 ?×âPrepared StatementîÜclass¡£
	 ?COdbcConnectionîÜ Execute ÜôÔÒ£¬ñþâÍ?ÌÚì«?ïÒìéó­îÜqueryîÜ???£¬?êó××éÍ??ÞÅéÄ¡£
	 î¤?ú¼Input, Output, Input&Output ??á¶âÍîÜ Stored Procedure?£¬å¥ù¬ÞÅéÄ¡£

	 \~japanese
	 Prepared Statementªò?×âª¹ªëª¿ªáªÎ«¯«é«¹ªÇª¹¡£
	 COdbcConnectionÀÇ ExecuteªÈªÏì¶ªÊªê¡¢ìéÓøàâïÒªµªìª¿«¯«¨«ê?ªò«Ñ«é«á?«¿ö·ªÀª±?ÌÚª·ªÆÞÅéÄª·?ª±ªëíÞùêªËæµØ¡ªÁªÞª¹¡£
	 Input, Output, Input&Output «Ñ«é«á?«¿ª¬ù±é©ªÊStored Procedureªò?ú¼ª¹ªëªÈª­ªËªâÞÅéÄªµªìªÞª¹¡£


	 \~
	 */
	class COdbcCommand
	{
	public:
		COdbcCommand();
		~COdbcCommand();

		/**
		 \~korean
		 Äõ¸®¹®À» ÀÔ·ÂÇÒ ¶§ »ç¿ëÇÕ´Ï´Ù.
		 Äõ¸®¹®ÀÇ Value´Â ?·Î ÀÔ·ÂÇÕ´Ï´Ù. (ex> INSERT INTO test(id, name) VALUES(?, ?))
		 °ªÀ» Á¦¿ÜÇÑ ¸í·ÉÀÌ³ª Å×ÀÌºí ÀÌ¸§, ÇÊµå ÀÌ¸§µîÀº ?·Î ÀÔ·ÂÇÒ ¼ö ¾ø½À´Ï´Ù.
		 \param conn COdbcConnection °´Ã¼
		 \param query Äõ¸®¹®

		 \~english
		 It is used when inputting a query.
		 Input the query as ?. (ex> INSERT INTO test(id, name) VALUES(?, ?)).
		 Table name and field name cannot be inputted as ?. 
		 \param conn COdbcConnection Object
		 \param query Query

		 \~chinese
		 î¤?ìýqueryÙþËì?ÞÅéÄ¡£
		 ?queryÙþËìîÜValue?ìý?£¿¡£(ex> INSERT INTO test(id, name) VALUES(?, ?))
		 ð¶Öõ?ì¤èâîÜÙ¤ÖµûätableÙ£?£¬fieldÙ£?ÔõÜôÊ¦?ìý?£¿¡£
		 \param conn COdbcConnection ?ßÚ
		 \param query queryÙþËì

		 \~japanese
		 «¯«¨«ê?ÙþªòìýÕôª¹ªëãÁªËÞÅéÄª·ªÞª¹¡£.
		 «¯«¨«ê?ÙþªÎ ValueªÏ?ªÈìýÕôª·ªÞª¹¡£ (ex> INSERT INTO test(id, name) VALUES(?, ?))
		 ö·ªòð¶ª¤ª¿Ù¤Öµªä«Æ?«Ö«ëÙ£¡¢«Õ«£?«ë«ÉÙ£ªÊªÉªÏ?ªÈìýÕôõó?ªÞª»ªó¡£
		 \param conn COdbcConnection «ª«Ö«¸«§«¯«È
		 \param query«¯«¨«ê?Ùþ

		 \~
		 */
		void Prepare(COdbcConnection &conn, const String& query);

		/**
		 \~korean
		 Input ÆÄ¶ó¹ÌÅÍ¸¦ ÀÔ·ÂÇÒ ¶§ »ç¿ëµË´Ï´Ù.
		 º¯¼öÀÇ °ª¸¸ Áö¼ÓÀûÀ¸·Î º¯°æÇÏ¿© ½ÇÇàÇÏ°íÀÚ ÇÒ °æ¿ì Æ÷ÀÎÅÍ Çü½ÄÀ¸·Î µ¥ÀÌÅÍ¸¦ ÀÔ·ÂÇÏ¸é µË´Ï´Ù.
		 Æ÷ÀÎÅÍ·Î ÀÔ·ÂÇÒ °æ¿ì ÇØ´ç º¯¼öÀÇ Scope¿¡ ÀÇÇØ ¹®Á¦°¡ ¹ß»ýÇÏÁö ¾Ê´ÂÁö È®ÀÎÇØ¾ß ÇÕ´Ï´Ù.
		 1.	int a = 10;
		 2.	cmd.AppendInputParameter(a); // aÀÇ °ªÀÌ º¹»çµÇ¾î Call by Value Çü½ÄÀ¸·Î ÀÛµ¿ÇÕ´Ï´Ù.
		 3.	cmd.AppendInputParameter(&a); // aÀÇ ÁÖ¼Ò°ªÀ» »ç¿ëÇÏ´Â Call by Pointer Çü½ÄÀ¸·Î ÀÛµ¿ÇÕ´Ï´Ù.

		 ÀÔ·Â µ¥ÀÌÅÍ¿¡ µû¶ó sqlTypeÀÌ ÀÚµ¿ÀûÀ¸·Î °áÁ¤µÇ±â ¶§¹®¿¡ µ¥ÀÌÅÍº£ÀÌ½º¿¡ ¸í½ÃÀûÀ¸·Î ¿øÇÏ´Â Å¸ÀÔÀ» ³Ö°í ½ÍÀ» °æ¿ì OdbcSqlDataTypeÀ» ÀÔ·ÂÇÏ¸é µË´Ï´Ù.
		 ex> int32_t Å¸ÀÔÀÇ º¯¼ö¸¦ int64_tÅ¸ÀÔÀÇ µ¥ÀÌÅÍ·Î µ¥ÀÌÅÍº£ÀÌ½º¿¡ ³Ö°í ½ÍÀ» °æ¿ì
		 1.	int a = 10;
		 2.	cmd.AppendInputParameter(a, OdbcSqlDataType_BIGINT);

		 ÀÌÁø µ¥ÀÌÅÍ¸¦ ÀÔ·ÂÇÒ °æ¿ì Proud::COdbcByteData Å¬·¡½º¸¦ ÀÌ¿ëÇØ¾ß ÇÕ´Ï´Ù.
		 COdbcByteData´Â Æ÷ÀÎÅÍ·Î¸¸ ÀÔ·ÂÇÒ ¼ö ÀÖ½À´Ï´Ù.
		 1. unsigned char byte[10000] = "........................."; // 1000¹ÙÀÌÆ® µ¥ÀÌÅÍ ÀÔ·Â
		 2. COdbcByteData byteData(byte, 1000, 10000);
		 3. cmd.AppendInputParameter(&byteData);

		 \~english
		 It is used when inputting ¡°Input parameter¡±.
		 You can just input data in the form of pointer in case you want to change variables only. 
		 In case of inputting in the form of pointer, you must check if there is problem occurred by scope of the relevant variable. 
		 1.         int a = 10;
		 2.         cmd.AppendInputParameter(a); // It is executed in the form of Call by Value as ¡°a¡± is copied.
		 3.         cmd.AppendInputParameter(&a); // It is executed in the form of Call by Pointer that uses ¡°a¡± address. 
		 
		 Depending on inputted data, sqlType is automatically decided, so in case you input a type you want in the database, you can input OdbcSqlDataType.
		 ex> In case of inputting variable whose type is int32_t as data whose type is int64_t, 
		 1.         int a = 10;
		 2.         cmd.AppendInputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 In case of inputting binary data, you must use Proud::COdbcByteData class.
		 COdbcByteData is only allowed to be inputted by the pointer. 
		 1. unsigned char byte[10000] = "........................."; // Input 1,000 byte data.
		 2. COdbcByteData byteData(byte, 1000, 10000);
		 3. cmd.AppendInputParameter(&byteData);

		 \~chinese
		 ?ìý Input???ÞÅéÄ¡£
		 åýÍýßÌìéòÁñþ?ÌÚ????ú¼îÜï×?£¬ì¤pointerîÜû¡ãÒ?ìý?Ëß?Ê¦¡£
		 ì¤pointerîÜû¡ãÒ?ìý?£¬âÍ??ì×???îÜScope£¬ãÀÜú??ßæ??¡£
		 1.         int a = 10;
		 2.         cmd.AppendInputParameter(a); // aîÜ?ù¬?ð¤£¬ì¤ Call by Value û¡ãÒ?ú¼¡£.
		 3.         ì¤ÞÅéÄcmd.AppendInputParameter(&a); // aò¢ò£?îÜCall by Pointer û¡ãÒ?ú¼¡£
		 
		 ì×?ó·?ìý?ËßîÜÜôÔÒ£¬sqlType?í»??ïÒ£¬á¶ì¤åýÍýßÌî¤?Ëß?ñéÙ¥?ò¢Û¯ìýá¶âÍtype?£¬?ìýOdbcSqlDataType?Ê¦¡£
		 åýÍýßÌ?ex> int32_t typeîÜ??ì¤int64_t typeîÜ?ËßÛ¯ìý?Ëß??
		 1.         int a = 10;
		 2.         cmd.AppendInputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 ?ìýì£?ð¤?Ëß?£¬?××éÄ Proud::COdbcByteData class¡£
		 COdbcByteDatañþÒöéÄpointer?ìý¡£
		 1. ?ìýunsigned char byte[10000] = "........................."; // 1000 byte ?Ëß¡£
		 2. COdbcByteData byteData(byte, 1000, 10000);
		 3. cmd.AppendInputParameter(&byteData);

		 \~japanese
		 Input «Ñ«é«á?«¿ªòìýÕôª¹ªëãÁªËÞÅéÄªµªìªÞª¹¡£
		 ??ªÎö·ªÀª±ò¥?îÜªË?ÌÚª·ªÆ?ú¼ª·ªèª¦ªÈª¹ªëíÞùê¡¢«Ý«¤«ó«¿?û¡ãÒªÇ«Ç?«¿ªòìýÕôª·ªÆª¯ªÀªµª¤¡£
		 «Ý«¤«ó«¿?ªÇìýÕôª¹ªëíÞùê¡¢ú±???ªÎScopeªËªèªëÙýð¹ª¬?ßæª·ªÊª¤ª«ü¬ìãª¹ªëù±é©ª¬ª¢ªêªÞª¹¡£
		 1.         int a = 10;
		 2.         cmd.AppendInputParameter(a); // aªÎö·ª¬«³«Ô?ªµªìCall by Valueû¡ãÒªËíÂÔÑª·ªÞª¹¡£
		 3.         cmd.AppendInputParameter(&a); // aªÎ«¢«É«ì«¹ö·ªòÞÅéÄª¹ªëCall by Pointerû¡ãÒªÇíÂÔÑª·ªÞª¹¡£

		 ìýÕô«Ç?«¿ªËªèªêsqlTypeª¬í»ÔÑîÜªËÌ½ïÒªµªìªëª¿ªá¡¢«Ç?«¿«Ù?«¹ªËÙ¥ãÆîÜªËØÐªà«¿«¤«×ªòìýªìª¿ª¤íÞùêªËªÏOdbcSqlDataTypeªòìýÕôª·ªÆª¯ªÀªµª¤¡£
		 ex> int32_t «¿«¤«×ªÎ??ªòint64_t«¿«¤«×ªÎ«Ç?«¿ªÇ«Ç?«¿«Ù?«¹ªËìýªìª¿ª¤íÞùê
		 1.         int a = 10;
		 2.         cmd.AppendInputParameter(a, OdbcSqlDataType_BIGINT);

		 «Ñ«¤«Ê«ê«Ç?«¿ªòìýÕôª¹ªëíÞùê Proud::COdbcByteData «¯«é«¹ªò××éÄª·ªÆª¯ªÀªµª¤¡£
		 COdbcByteDataªÏ«Ý«¤«ó«¿?ªÇªÀª±ìýÕôªÇª­ªÞª¹¡£
		 1. unsigned char byte[10000] = "........................."; // 1000«Ð«¤«È«Ç?«¿ìýÕô
		 2. COdbcByteData byteData(byte, 1000, 10000);
		 3. cmd.AppendInputParameter(&byteData);

		 \~
		 */
		void AppendInputParameter(const COdbcVariant &param, OdbcSqlDataType sqlType = OdbcSqlDataType_UNKNOWN);

		/**
		 \~korean
		 Output ÆÄ¶ó¹ÌÅÍ¸¦ ÁöÁ¤ÇÒ ¶§ »ç¿ëµË´Ï´Ù.
		 µ¥ÀÌÅÍ¸¦ ¹Þ¾Æ¾ß ÇÏ¹Ç·Î Æ÷ÀÎÅÍ Çü½ÄÀ¸·Î¸¸ µ¥ÀÌÅÍ¸¦ ÀÔ·ÂÇÒ ¼ö ÀÖ½À´Ï´Ù.
		 Æ÷ÀÎÅÍ·Î ÀÔ·ÂÇÒ °æ¿ì ÇØ´ç º¯¼öÀÇ Scope¿¡ ÀÇÇØ ¹®Á¦°¡ ¹ß»ýÇÏÁö ¾Ê´ÂÁö È®ÀÎÇØ¾ß ÇÕ´Ï´Ù.
		 1.	int a;
		 2.	cmd.AppendOutputParameter(&a);

		 ÀÔ·Â µ¥ÀÌÅÍ¿¡ µû¶ó sqlTypeÀÌ ÀÚµ¿ÀûÀ¸·Î °áÁ¤µÇ±â ¶§¹®¿¡ µ¥ÀÌÅÍº£ÀÌ½º¿¡ ¸í½ÃÀûÀ¸·Î ¿øÇÏ´Â Å¸ÀÔÀ» ³Ö°í ½ÍÀ» °æ¿ì OdbcSqlDataTypeÀ» ÀÔ·ÂÇÏ¸é µË´Ï´Ù.
		 ex> µ¥ÀÌÅÍº£ÀÌ½º·Î ºÎÅÍ int64_t Å¸ÀÔÀÇ µ¥ÀÌÅÍ¸¦ int32_tÅ¸ÀÔÀÇ º¯¼ö·Î ¹Þ°í ½ÍÀ» °æ¿ì
		 1.	int a;
		 2.	cmd.AppendOutputParameter(a, OdbcSqlDataType_BIGINT);

		 ¹®ÀÚ¿­À» ¹ÞÀ» °æ¿ì ¹Ýµå½Ã Excute ÀüÈÄ¿¡ Proud::String Å¬·¡½ºÀÇ GetBuffer¿Í ReleaseBuffer¸¦ »ç¿ëÇØ¾ß ÇÕ´Ï´Ù.
		 1. String str;
		 2. str.GetBuffer(100);
		 3. cmd.AppendOutputParameter(&str);
		 4. cmd.Execute();
		 5. str.ReleaseBuffer();
		 6. str.GetBuffer(100);	// 2, 4, 5¸¦ ¹Ýº¹ÇØ¾ß ÇÕ´Ï´Ù.
		 7. cmd.Execute();
		 8. str.ReleaseBuffer();

		 ÀÌÁø µ¥ÀÌÅÍ¸¦ ¹ÞÀ» °æ¿ì Proud::COdbcByteData Å¬·¡½º¸¦ »ç¿ëÇØ¾ß ÇÕ´Ï´Ù.
		 COdbcByteData´Â Æ÷ÀÎÅÍ·Î¸¸ ÀÔ·ÂÇÒ ¼ö ÀÖ½À´Ï´Ù.
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();

		 \~english
		 It is used when designating ¡°Output parameter¡±.
		 You can only input data in the form of pointer in order to receive data. 
		 In case of inputting in the form of pointer, you must check if there is problem occurred by scope of the relevant variable. 
		 1.         int a;
		 2.         cmd.AppendOutputParameter(&a);
		 
		 Depending on inputted data, sqlType is automatically decided, so in case you input a type you want in the database, you can input OdbcSqlDataType.
		 ex> In case of receiving data whose type is int64_t as variable whose type is int32_t, 
		 1.         int a;
		 2.         cmd.AppendOutputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 In case of receiving string, you must use GetBuffer¿Í ReleaseBuffer of Proud::String class before/after execution.
		 1. String str;
		 2. str.GetBuffer(100);
		 3. cmd.AppendOutputParameter(&str);
		 4. cmd.Execute();
		 5. str.ReleaseBuffer();
		 6. str.GetBuffer(100);       // You must repeat 2, 4 and 5.
		 7. cmd.Execute();
		 8. str.ReleaseBuffer();
		 
		 In case of receiving binary data, you must use Proud::COdbcByteData class. 
		 COdbcByteData is only allowed to be inputted by the pointer.
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();
		 
		 \~chinese
		 ò¦ïÒOutput???ÞÅéÄ¡£
		 ì×âÍïÈâ¥?Ëß£¬á¶ì¤ñþÒöì¤pointerîÜû¡ãÒ?ìý?Ëß¡£
		 ì¤pointerîÜû¡ãÒ?ìý?£¬âÍ??ì×???îÜScope£¬ãÀÜú??ßæ??¡£
		 1.         int a;
		 2.         cmd.AppendOutputParameter(&a);
		 
		 ì×?ó·?ìý?ËßîÜÜôÔÒ£¬sqlType?í»??ïÒ£¬á¶ì¤åýÍýßÌî¤?Ëß?ñéÙ¥?ò¢Û¯ìýá¶âÍtype?£¬?ìýOdbcSqlDataType?Ê¦¡£
		 åýÍýßÌ?ex> int32_t typeîÜ??ì¤int64_t typeîÜ?ËßÛ¯ìý?Ëß??
		 1.         int a;
		 2.         cmd.AppendOutputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 ïÈâ¥í®Ý¬Íú?£¬ù±?î¤ Excute îñý¨ÞÅéÄProud::String classîÜ GetBufferûú ReleaseBuffer¡£
		 1. String str;
		 2. str.GetBuffer(100);
		 3. cmd.AppendOutputParameter(&str);
		 4. cmd.Execute();
		 5. str.ReleaseBuffer();
		 6. str.GetBuffer(100);       // âÍÚã?2, 4, 5
		 7. cmd.Execute();
		 8. str.ReleaseBuffer();
		 
		 ïÈâ¥ì£?ð¤?Ëß?£¬âÍÞÅéÄ Proud::COdbcByteData class¡£
		 COdbcByteDatañþÒöì¤pointerîÜû¡ãÒ?ìý¡£
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();

		 \~japanese
		 Output «Ñ«é«á?«¿ªòò¦ïÒª¹ªëªÈª­ÞÅéÄªµªìªÞª¹¡£
		 «Ç?«¿ªòáôª±ªëª¿ªá«Ý«¤«ó«¿?û¡ãÒªÇªÀª±«Ç?«¿ªòìýÕôªÇª­ªÞª¹¡£
		 «Ý«¤«ó«¿?ªÇìýÕôª¹ªëíÞùê¡¢ú±???ªÎScopeªËªèªëÙýð¹ª¬?ßæª·ªÊª¤ª«ü¬ìãª¹ªëù±é©ª¬ª¢ªêªÞª¹¡£
		 1.         int a;
		 2.         cmd.AppendOutputParameter(&a);

		 ìýÕô«Ç?«¿ªËªèªêsqlTypeª¬í»ÔÑîÜªËÌ½ïÒªµªìªëª¿ªá«Ç?«¿«Ù?«¹ªËÙ¥ãÆîÜªËØÐªà«¿«¤«×ªòìýªìª¿ª¤íÞùê¡¢OdbcSqlDataTypeªòìýÕôª·ªÆª¯ªÀªµª¤¡£
		 ex> «Ç?«¿«Ù?«¹ª«ªéint64_t«¿«¤«×ªÎ«Ç?«¿ªòint32_t«¿«¤«×ªÎ??ªÇáôª±ª¿ª¤íÞùê
		 1.         int a;
		 2.         cmd.AppendOutputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 Ùþí®Öªªòáôª±ªëíÞùê¡¢ù±ªºExcuteîñý­ªËProud::String«¯«é«¹ªÎGetBufferªÈReleaseBufferªòÞÅéÄª·ªÆª¯ªÀªµª¤¡£
		 1. String str;
		 2. str.GetBuffer(100);
		 3. cmd.AppendOutputParameter(&str);
		 4. cmd.Execute();
		 5. str.ReleaseBuffer();
		 6. str.GetBuffer(100);       // 2, 4, 5ªòðÛªêÚ÷ª·ªÆª¯ªÀªµª¤¡£
		 7. cmd.Execute();
		 8. str.ReleaseBuffer();
		 
		 «Ñ«¤«Ê«ê«Ç?«¿ªòáôª±ªëíÞùêProud::COdbcByteData«¯«é«¹ªòÞÅéÄª·ªÆª¯ªÀªµª¤¡£
		 CodbcByteDataªÏ«Ý«¤«ó«¿?ªÇªÀª±ìýÕôªÇª­ªÞª¹¡£
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();

		 \~
		 */
		void AppendOutputParameter(const COdbcVariant &param, OdbcSqlDataType sqlType = OdbcSqlDataType_UNKNOWN);

		/**
		 \~korean
		 Input&Output ÆÄ¶ó¹ÌÅÍ¸¦ ÁöÁ¤ÇÒ ¶§ »ç¿ëµË´Ï´Ù.
		 µ¥ÀÌÅÍ¸¦ ¹Þ¾Æ¾ß ÇÏ¹Ç·Î Æ÷ÀÎÅÍ Çü½ÄÀ¸·Î¸¸ µ¥ÀÌÅÍ¸¦ ÀÔ·ÂÇÒ ¼ö ÀÖ½À´Ï´Ù.
		 Æ÷ÀÎÅÍ·Î ÀÔ·ÂÇÒ °æ¿ì ÇØ´ç º¯¼öÀÇ Scope¿¡ ÀÇÇØ ¹®Á¦°¡ ¹ß»ýÇÏÁö ¾Ê´ÂÁö È®ÀÎÇØ¾ß ÇÕ´Ï´Ù.
		 1.	int a;
		 2.	cmd.AppendInputOutputParameter(&a);

		 ÀÔ·Â µ¥ÀÌÅÍ¿¡ µû¶ó sqlTypeÀÌ ÀÚµ¿ÀûÀ¸·Î °áÁ¤µÇ±â ¶§¹®¿¡ µ¥ÀÌÅÍº£ÀÌ½º¿¡ ¸í½ÃÀûÀ¸·Î ¿øÇÏ´Â Å¸ÀÔÀ» ³Ö°í ½ÍÀ» °æ¿ì OdbcSqlDataTypeÀ» ÀÔ·ÂÇÏ¸é µË´Ï´Ù.
		 ex> int32_tÅ¸ÀÔÀÇ º¯¼ö¸¦ int64_t Å¸ÀÔÀÇ µ¥ÀÌÅÍ·Î µ¥ÀÌÅÍº£ÀÌ½º·Î ºÎÅÍ ÀÔÃâ·Â ÇÏ°í ½ÍÀ» °æ¿ì
		 1.	int a;
		 2.	cmd.AppendInputOutputParameter(a, OdbcSqlDataType_BIGINT);

		 ¹®ÀÚ¿­À» ÀÔÃâ·Â ÇÒ °æ¿ì ¹Ýµå½Ã Excute ÀüÈÄ¿¡ Proud::String Å¬·¡½ºÀÇ GetBuffer¿Í ReleaseBuffer¸¦ »ç¿ëÇØ¾ß ÇÕ´Ï´Ù.
		 1. String str;
		 2. str = "ABCD";	// 2, 3ÀÇ ¼ø¼­°¡ ¹Ù²î¸é ¾ÈµË´Ï´Ù.
		 3. str.GetBuffer(100);
		 4. cmd.AppendInputOutputParameter(&str);
		 5. cmd.Execute();
		 6. str.ReleaseBuffer();
		 7. str = "EFGH"; // 2, 3, 5, 6À» ¹Ýº¹ÇØ¾ß ÇÕ´Ï´Ù.
		 8. str.GetBuffer(100);
		 9. cmd.Execute();
		 10. str.ReleaseBuffer();

		 ÀÌÁø µ¥ÀÌÅÍ¸¦ ¹ÞÀ» °æ¿ì Proud::COdbcByteData Å¬·¡½º¸¦ »ç¿ëÇØ¾ß ÇÕ´Ï´Ù.
		 COdbcByteData´Â Æ÷ÀÎÅÍ·Î¸¸ ÀÔ·ÂÇÒ ¼ö ÀÖ½À´Ï´Ù.
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();

		 \~english
		 It is used when designating ¡°Input&Output parameter¡±.
		 You can only input data in the form of pointer in order to receive data. 
		 In case of inputting in the form of pointer, you must check if there is problem occurred by scope of the relevant variable. 
		 1.         int a;
		 2.         cmd.AppendInputOutputParameter(&a);
		 
		 Depending on inputted data, sqlType is automatically decided, so in case you input a type you want in the database, you can input OdbcSqlDataType.
		 ex> In case of inputting & outputting variable whose type is int32_t as data whose type is int64_t, 
		 1.         int a;
		 2.         cmd.AppendInputOutputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 In case of inputting & outputting string, you must use GetBuffer¿Í ReleaseBuffer of Proud::String class before/after execution.
		 1. String str;
		 2. str = "ABCD";  // 2 and 3 must be right order. 
		 3. str.GetBuffer(100);
		 4. cmd.AppendInputOutputParameter(&str);
		 5. cmd.Execute();
		 6. str.ReleaseBuffer();
		 7. str = "EFGH"; // You must repeat 2,3,5 and 6. 
		 8. str.GetBuffer(100);
		 9. cmd.Execute();
		 10. str.ReleaseBuffer();
		 
		 In case of receiving binary data, you must use Proud::COdbcByteData class. 
		 COdbcByteData is only allowed to be inputted by the pointer.
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();
		 
		 \~chinese
		 ò¦ïÒInput&Output???ÞÅéÄ¡£
		 ì×âÍïÈâ¥?Ëß£¬á¶ì¤ñþÒöì¤pointerîÜû¡ãÒ?ìý?Ëß¡£
		 ì¤pointerîÜû¡ãÒ?ìý?£¬âÍ??ì×???îÜScope£¬ãÀÜú??ßæ??¡£
		 1.         int a;
		 2.         cmd.AppendInputOutputParameter(&a);
		 
		 ì×?ó·?ìý?ËßîÜÜôÔÒ£¬sqlType?í»??ïÒ£¬á¶ì¤åýÍýßÌî¤?Ëß?ñéÙ¥?ò¢Û¯ìýá¶âÍtype?£¬?ìýOdbcSqlDataType?Ê¦¡£
		 åýÍýßÌ?ex> int32_t typeîÜ??ì¤int64_t typeîÜ?ËßÛ¯ìý?Ëß??
		 1.         int a;
		 2.         cmd.AppendInputOutputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 ïÈâ¥í®Ý¬Íú?£¬ù±?î¤ Excute îñý¨ÞÅéÄProud::String classîÜ GetBufferûú ReleaseBuffer¡£
		 1. String str;
		 2. str = "ABCD";  // ÜôÊ¦??2, 3îÜ?ßí¡£
		 3. str.GetBuffer(100);
		 4. cmd.AppendInputOutputParameter(&str);
		 5. cmd.Execute();
		 6. str.ReleaseBuffer();
		 7. str = "EFGH"; // âÍÚã?2, 3, 5, 6
		 8. str.GetBuffer(100);
		 9. cmd.Execute();
		 10. str.ReleaseBuffer();
		 
		 ïÈâ¥ì£?ð¤?Ëß?£¬âÍÞÅéÄ Proud::COdbcByteData class¡£
		 COdbcByteDatañþÒöì¤pointerîÜû¡ãÒ?ìý¡£
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();

		 \~japanese
		 Input&Output «Ñ«é«á?«¿ªòò¦ïÒª¹ªëªÈª­ªËÞÅéÄªµªìªÞª¹¡£
		 «Ç?«¿ªòáôª±ªëª¿ªá¡¢«Ý«¤«ó«¿?û¡ãÒªÇªÀª±«Ç?«¿ªòìýÕôªÇª­ªÞª¹¡£
		 «Ý«¤«ó«¿?ªÇìýÕôª¹ªëíÞùêú±???ªÎScopeªËªèªëÙýð¹ª¬?ßæª·ªÊª¤ª«ü¬ìãª¹ªëù±é©ª¬ª¢ªêªÞª¹¡£
		 1.         int a;
		 2.         cmd.AppendInputOutputParameter(&a);

		 ìýÕô«Ç?«¿ªËªèªêsqlTypeª¬í»ÔÑîÜªËÌ½ïÒªµªìªëª¿ªá«Ç?«¿«Ù?«¹ªËÙ¥ãÆîÜªËØÐªà«¿«¤«×ªòìýªìª¿ª¤íÞùêOdbcSqlDataTypeªòìýÕôª·ªÆª¯ªÀªµª¤¡£
		 ex> int32_t«¿«¤«×ªÎ??ªòint64_t «¿«¤«×ªÎ«Ç?«¿ªÇ«Ç?«¿«Ù?«¹ª«ªéìýõóÕôª·ª¿ª¤íÞùê
		 1.         int a;
		 2.         cmd.AppendInputOutputParameter(a, OdbcSqlDataType_BIGINT);
		 
		 Ùþí®ÖªªòìýõóÕôª¹ªëíÞùêù±ªºExcuteîñý­ªËProud::String«¯«é«¹ªÎGetBufferªÈReleaseBufferªòÞÅéÄª·ªÆª¯ªÀªµª¤¡£
		 1. String str;
		 2. str = "ABCD";  // 2, 3ªÎâ÷Ûãª¬?ªïªéªÊª¤ªèª¦ªËª´ñ¼ëòª¯ªÀªµª¤¡£
		 3. str.GetBuffer(100);
		 4. cmd.AppendInputOutputParameter(&str);
		 5. cmd.Execute();
		 6. str.ReleaseBuffer();
		 7. str = "EFGH"; // 2, 3, 5, 6ªòðÛªêÚ÷ª·ªÆª¯ªÀªµª¤¡£
		 8. str.GetBuffer(100);
		 9. cmd.Execute();
		 10. str.ReleaseBuffer();
		 
		 «Ñ«¤«Ê«ê«Ç?«¿ªòáôª±ªëíÞùêProud::COdbcByteData«¯«é«¹ªòÞÅéÄª¹ªëù±é©ª¬ª¢ªêªÞª¹¡£
		 COdbcByteDataªÏ«Ý«¤«ó«¿?ªÇªÀª±ìýÕôªÇª­ªÞª¹¡£
		 1. unsigned char byte[10000];
		 2. COdbcByteData byteData(byte, 0, 10000);
		 3. cmd.AppendOutputParameter(&byteData);
		 4. cmd.Execute();

		 \~
		 */
		void AppendInputOutputParameter(const COdbcVariant &param, OdbcSqlDataType sqlType = OdbcSqlDataType_UNKNOWN);

		/**
		 \~korean
		 ÆÄ¶ó¹ÌÅÍ¸¦ NULL »óÅÂ¸¦ ¼³Á¤ÇÕ´Ï´Ù.
		 DB¿¡ µ¥ÀÌÅÍ¸¦ NULL·Î ÀÔ·ÂÇÏ°í ½ÍÀ» °æ¿ì ÀÌ ÇÔ¼ö¸¦ ÀÌ¿ëÇØ NULL »óÅÂ¸¦ TRUE·Î º¯°æ ÇÕ´Ï´Ù.
		 ÇÑ¹ø ¼³Á¤µÈ »óÅÂ´Â Áö¼ÓÀûÀ¸·Î »ç¿ëµÇ¹Ç·Î ¿ø »óÅÂ·Î µ¹¸®±â À§ÇØ¼± Execute ÈÄ¿¡ FALSE·Î ´Ù½Ã ¼¼ÆÃÇØ¾ß ÇÕ´Ï´Ù.
		 \param paramIndex ÆÄ¶ó¹ÌÅÍ Index (ex> 1, 2, 3, ...)
		 \param state true or false

		 \~english
		 Set a parameter as NULL.
		 In case you want to input data as NULL in the database, change the status of NULL to TRUE by using this function.
		 Once setting is done, the status is continuously used, so in case of restring the status, you must reset it as FALSE after execution. 
		 \param paramIndex parameter Index (ex> 1, 2, 3, ...)
		 \param state true or false
		 
		 \~chinese
		 ????öÇ? NULL??¡£
		 åýÍýßÌî¤DB?ìýNULL?Ëß?£¬××éÄ?ùÞ?? NULL ???ÌÚ?TRUE??¡£
		 ì×?öÇìéó­îÜ???ìéòÁù¬ÞÅéÄ£¬á¶ì¤?Öõ?ê«£¬âÍî¤ Executeý¨ì¤FALSE??ñìãæ?öÇ¡£
		 \param paramIndex ÆÄ¶ó¹ÌÅÍ Index (ex> 1, 2, 3, ...)
		 \param state true or false

		 \~japanese
		 «Ñ«é«á?«¿ªò NULL?÷¾ªòàâïÒª·ªÞª¹¡£
		 DBªË«Ç?«¿ªòNULLªÇìýÕôª·ª¿ª¤íÞùê¡¢ª³ªÎ??ªò××éÄª·NULL?÷¾ªòTRUEªË?ÌÚª·ªÞª¹¡£
		 ìéÓøàâïÒªµªìª¿?÷¾ªÏò¥?îÜªËÞÅéÄªµªìªëª¿ªáêªªÎ?÷¾ªË?ª¹ª¿ªáªËªÏExecuteý­ªËFALSEªÇªâª¦ìéÓø«»«Ã«Æ«£«ó«°ª¹ªëù±é©ª¬ª¢ªêªÞª¹¡£
		 \param paramIndex «Ñ«é«á?«¿Index (ex> 1, 2, 3, ...)
		 \param state true or false

		 \~
		 */
		void SetNullParameter(unsigned int paramIndex, bool state);

		/**
		 \~korean
		 Äõ¸®¸¦ ½ÇÇàÇÕ´Ï´Ù.
		 Äõ¸® ½ÇÇàÀ¸·Î ¿µÇâÀ» ¹ÞÀº Row °³¼ö¸¦ ¹ÝÈ¯ÇÕ´Ï´Ù.

		 \~english
		 Execute the query.

		 \~chinese
		 ?ú¼query¡£

		 \~japanese
		 «¯«¨«ê?ªò?ú¼ª·ªÞª¹¡£

		 \~
		 */
		int Execute(COdbcWarnings* odbcWarnings = NULL);

		/**
		 \~korean
		 Äõ¸®¸¦ ½ÇÇàÇÕ´Ï´Ù.
		 Äõ¸® ½ÇÇàÀ¸·Î ¿µÇâÀ» ¹ÞÀº Row °³¼ö¸¦ ¹ÝÈ¯ÇÕ´Ï´Ù.
		 \param recordset Äõ¸® ½ÇÇàÈÄ ¹Þ¾ÆÁö´Â Recordset °´Ã¼

		 \~english
		 Execute the query.
		 \param recordset It is a Recordset object that is received after query execution.

		 \~chinese
		 ?ú¼query¡£
		 \param recordset query ?ú¼ý¨ïÈâ¥ÓðîÜ Recordset ?ßÚ

		 \~japanese
		 «¯«¨«ê?ªò?ú¼ª·ªÞª¹¡£
		 \param recordset «¯«¨«ê??ú¼ý­áôª±ªëRecordset«ª«Ö«¸«§«¯«È

		 \~
		 */
		int Execute(COdbcRecordset &recordset, COdbcWarnings* odbcWarnings = NULL);

	private:
		COdbcCommandImpl* m_pImpl;

		// º¹»ç ±ÝÁö
		COdbcCommand(const COdbcCommand& other);
		COdbcCommand& operator=(const COdbcCommand& other);
	};
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif