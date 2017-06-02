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

#if defined(_WIN32)

#include "AdoWrap.h"

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
	LogWriter¿¡¼­ ¿À·ù°¡ ³µÀ» ¶§ ¿À·ù ¸Ş½ÃÁö¸¦ ¹ŞÀ» Å¬·¡½º ÀÔ´Ï´Ù. »ó¼Ó ÇÏ¿© ÇÔ¼ö¸¦ Á¤ÀÇÇØ ÁÖ½Ã¸é µË´Ï´Ù.
	- CDbLogWriter »ı¼º½Ã ÀÎÀÚ·Î ³Ö¾îÁÖ°Ô µË´Ï´Ù.

	\~english
	This class is to receive error message when error occur at LogWriter. You can define function that using inherit.
	- When you creates CDbLogWriter, put it as a factor.

	\~chinese
	î¤LogWriterõó??£¬ïÈâ¥??ãáãÓîÜ?¡£ß¾??ïÒ?ùŞ??Ê¦¡£
	- CDbLogWriter%ßæà÷?Û¯ìı?ì×í­¡£

	\~japanese
	LogWriterªÇ«¨«é?ªËªÊªÃª¿ãÁ¡¢«¨«é?«á«Ã«»?«¸ªòáôª±ªë«¯«é«¹ªÇª¹¡£ßÓ?ª·ª¿ı­¡¢??ªòïÒëùª·ªÆª¯ªÀªµª¤¡£
	- CD£âLogWriterªòßæà÷ãÁªËì×í­ªÇìıªìªÆª¯ªÀªµª¤¡£
	\~
	*/
	class ILogWriterDelegate
	{
	public:
		virtual void OnLogWriterException(Proud::AdoException &Err)=0;	//LogWriterException(exception°´Ã¼¸¦ ÆÄ¶ó¹ÌÅÍ·Î)
	};
	
	/** 
	\~korean
	CDbLogWriter ¿¡¼­ »ç¿ëµÇ´Â ±¸Á¶Ã¼

	\~english
	Structure used in CDbLogWriter 

	\~chinese
	î¤ CDbLogWriter%ŞÅéÄîÜ?ğã?¡£

	\~japanese
	CDbLogWriterªÇŞÅªïªìªëÏ°ğã?
	\~
	*/
	class CDbLogParameter
	{
	public:
		/** 
		\~korean
		·Î±× ±â·ÏÀÌ ³²À» µ¥ÀÌÅÍº£ÀÌ½º·Î Á¢±ÙÇÏ´Â DBMS Connection StringÀÔ´Ï´Ù. ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#logwriter_db" >µ¥ÀÌÅÍº£ÀÌ½º¿¡ ·Î±×¸¦ ±â·ÏÇÏ±â</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.

		\~english
		DBMS Connection String accesses to DB that log record will be written on. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#logwriter_db" >Recording a log in database</a>.

		\~chinese
		ïÈĞÎlog??×ºù»îÜ?Ëß?îÜDBMS Connection String¡£????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#logwriter_db" >î¤?Ëß?ñé??log</a>%¡£

		\~japanese
		«í«°ÑÀ?ª¬?ªë«Ç?«¿«Ù?«¹ªò«¢«¯«»«¹ª¹ªëDBMS Connection StringªÇª¹¡£ßÙª·ª¯ªÏ¡¢\reflogwriter_dbªòª´?ğÎª¯ªÀªµª¤¡£
		\~
		*/
		String m_dbmsConnectionString;
		
		/** 
		\~korean
		·Î±×¸¦ ±â·ÏÇÏ´Â ÁÖÃ¼ÀÇ ÀÌ¸§ÀÔ´Ï´Ù. ¿¹¸¦ µé¾î ÀÌ ·Î±×¸¦ ±â·ÏÇÏ´Â ÇÁ·Î¼¼½ºÀÇ ÀÌ¸§, °¡·É "BattleServer #33"À» ³ÖÀ¸½Ã¸é µË´Ï´Ù.

		\~english
		Name of the subject that writes log. For an example, the name of the process that writes this log, such as "BattleServer #33"

		\~chinese
		??logîÜñ«?îÜÙ£?¡£ÖÇåı£¬??ó®logîÜïïßíîÜÙ£?£¬Û¯ìı"BattleServer #33"?Ê¦¡£

		\~japanese
		«í«°ªòÑÀ?ª¹ªëñ«?Ù£ªÇª¹¡£ÖÇª¨ªĞ¡¢ª³ªÎ«í«°ªòÑÀ?ª¹ªë«×«í«»«¹ªÎÙ£îñ¡¢?ªË"BattleServer #33"ªòìıªìªÆª¯ªÀªµª¤¡£
		\~
		*/
		String m_loggerName;

		/** 
		\~korean
		·Î±×¸¦ ±â·ÏÇÏ´Â DbmsÅ¸ÀÔÀÔ´Ï´Ù.MsSql,MySqlµîÀ» Áö¿øÇÕ´Ï´Ù.

		\~english
		DBMS type that writes log. Supports MSSQL, MySQL and etc.

		\~chinese
		??logîÜDbms?úş¡£ò¨êµMsSql,MySql Ôõ¡£

		\~japanese
		«í«°ªòÑÀ?ª¹ªëDbms«¿«¤«×ªÇª¹¡£MsSql¡¢MySqlªÊªÉªò«µ«İ?«Èª·ªŞª¹¡£
		\~
		*/
		DbmsType m_dbmsType;

		/**
		\~korean
		·Î±× ±â·ÏÀ» ÇÒ DB¿¡ ÀÖ´Â ·Î±×Å×ÀÌºí¸í ÀÔ´Ï´Ù. default ´Â DbLog ÀÔ´Ï´Ù.

		\~english 
		This is the log table name in the DB to record the log. The default is DbLog. 

		\~chinese
		??logîÜ?ı¦ğíî¤?DBîÜlog tableÙ£¡£DefaultãÀDbLog¡£

		\~japanese
		«í«°ÑÀ?ªòª¹ªëDBªËª¢ªë«í«°«Æ?«Ö«ëÙ£ªÇª¹¡£DefaultªÏDblogªÇª¹¡£
		\~
		*/
		String m_dbLogTableName;

		PROUD_API CDbLogParameter();
	};


	

	/** 
	\~korean
	DBMS ¿¡ ·Î±×¸¦ ±â·ÏÇÕ´Ï´Ù. ( <a target="_blank" href="http://guide.nettention.com/cpp_ko#logwriter_db" >µ¥ÀÌÅÍº£ÀÌ½º¿¡ ·Î±×¸¦ ±â·ÏÇÏ±â</a> Âü°í)

	ÀÏ¹İÀû ¿ëµµ
	- CDbLogWriter ¸¦ »ç¿ëÇÏ±â Àü¿¡ ProudNet/Sample/DbmsSchema/LogTable.sql À» ½ÇÇàÇÏ¿© DbLog Å×ÀÌºíÀ» »ı¼ºÇØ¾ß ÇÕ´Ï´Ù.
	- CDbLogWriter.New ¸¦ ½á¼­ ÀÌ °´Ã¼¸¦ »ı¼ºÇÕ´Ï´Ù. 
	- WriteLine, WriteLine ¸¦ ½á¼­ ·Î±×¸¦ ±â·ÏÇÕ´Ï´Ù. ÀúÀåµÈ ·Î±×´Â ºñµ¿±â·Î ÀúÀåµË´Ï´Ù.
	- ±âº»ÀûÀ¸·Î LoggerName, LogText, DateTime ÀÌ ±â·ÏµË´Ï´Ù. À¯Àú°¡ ¿øÇÏ´Â ÄÃ·³À» ³ÖÀ¸·Á¸é WriteLineÀÇ CPropNode ¸¦ »ç¿ëÇÏ¸é µË´Ï´Ù.

	\~english
	 Write log to DBMS (Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#logwriter_db" >Recording a log in database</a>)

	General usage
	- Before using CDbLogWriter, you must create Dblog table by running ProudNet/Sample/DbmsSchema/LogTable.sql
	- Create this object by using CDbLogWriter.New
	- Record log by using WriteLine, WriteLine. (Note: maybe a typo) The recorded log will be regarded as asynchronous.
	- Basically LoggerName, LogText and DateTime will be recorded. In order to add a column that user wants, use CPropNode of WriteLine

	\~chinese
	èÙDBMS??log£¨?ÍÅ <a target="_blank" href="http://guide.nettention.com/cpp_zh#logwriter_db" >î¤?Ëß?ñé??log</a>£©
	
	ìéÚõîÜéÄÔ²
	- ŞÅéÄ CDbLogWriter%ñıîñ?ú¼ProudNet/Sample/DbmsSchema/LogTable.sql£¬é©ßæà÷DbLogtable¡£
	- ŞÅéÄ CDbLogWriter.New%ßæà÷ó®?ßÚ¡£
	- ŞÅéÄWriteLine, WriteLine??log¡£?ğíîÜlog?ÜÁğí??ÜÆ¡£
	- ĞñÜâ???LoggerName, LogText, DateTime¡£ßÌÛ¯ìıéÄ?âÍé©îÜ??îÜ?ŞÅéÄWriteLineîÜ CPropNode%?Ê¦¡£

	\~japanese
	DBMSªË«í«°ªòÑÀ?ª·ªŞª¹¡£( \ref logwriter_db ?ÍÅ)

	ìéÚõîÜªÊéÄÔ²
	- CDbLogWriterªòŞÅéÄª¹ªëîñªËProudNet/Sample/DbmsSchema/LogTable.sqlªò?ú¼ª·ªÆDbLog«Æ?«Ö«ëªòßæà÷ª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
	- CDbLogWriter.New ªòŞÅªÃªÆª³ªÎ«ª«Ö«¸«§«¯«Èªòßæà÷ª·ªŞª¹¡£ 
	- WriteLine¡¢WriteLineªòŞÅªÃªÆ«í«°ªòÑÀ?ª·ªŞª¹¡£ÜÁğíªµªìª¿«í«°ªÏŞªÔÒÑ¢ªÇÜÁğíªµªìªŞª¹¡£
	- ĞñÜâîÜªËLoggerName, LogText, DateTimeª¬ÑÀ?ªµªìªŞª¹¡£«æ?«¶?ª¬ØĞªà«««é«àªòìıªìªëª¿ªáªËªÏ¡¢WriteLineªÎCPropNode ªòŞÅªÃªÆª¯ªÀªµª¤¡£
	\~
	*/
	class CDbLogWriter
	{
	protected:
		CDbLogWriter() {} // use CDbLogWriter::New() instead.
	public:
		/** 
		\~korean
		CDbLogWriter ÀÎ½ºÅÏ½º¸¦ »ı¼ºÇÕ´Ï´Ù.
		\param logParameter ·Î±× ±â·Ï±âÀÇ ½ÃÀÛÀ» À§ÇÑ ¼³Á¤°ªµéÀÔ´Ï´Ù.
		\param pDelegate ·Î±× ±â·Ï±â°¡ ½ÇÇà Áß ÇÊ¿ä·Î ÇÏ´Â Äİ¹éÀ» ±¸ÇöÇÏ´Â delegateÀÔ´Ï´Ù.

		\~english
		Create CDbLogWriter instance.
		\param logPramerter Setup value to start log writer.
		\param pDelegate It is delegate for realizing callback that requires during log writer running.

		\~chinese
		ßæà÷ CDbLogWriter%?ÖÇ¡£
		\param logParameter ?Öõlog???îÜ?ã·îÜ?ïÒ?¡£
		\param pDelegat ??log????ú¼ñéâÍé©îÜüŞ?îÜdelegate¡£

		\~japanese
		CDbLogWriter «¤«ó«¹«¿«ó«¹ªòßæà÷ª·ªŞª¹¡£
		\param logParameter «í«°ÑÀ?ĞïªÎËÒã·ªÎª¿ªáªÎàâïÒö·ªÇª¹¡£
		\param pDelegate «í«°ÑÀ?Ğïª¬?ú¼ñéªËù±é©ªÈª¹ªë«³?«ë«Ğ«Ã«¯ªò?úŞª¹ªëdelegateªÇª¹¡£
		\~
		*/
		PROUD_API static CDbLogWriter* New(CDbLogParameter& logParameter, ILogWriterDelegate *pDelegate);

		virtual ~CDbLogWriter() {}

		/** 
		\~korean
		ÇÑ °³ÀÇ ·Î±×¸¦ ±â·ÏÇÕ´Ï´Ù. 
		- ÀÌ ÇÔ¼ö´Â ºñµ¿±â·Î ½ÇÇàµË´Ï´Ù. Áï, Áï½Ã ¸®ÅÏµË´Ï´Ù.
		\param logText ÂïÀ» ·Î±× ¹®ÀÚ¿­
		\param pProperties »ç¿ëÀÚ°¡ Ãß°¡ÇÑ ÇÊµå¿¡ µé¾î°¥ °ªµéÀÔ´Ï´Ù. »ç¿ë ¿¹´Â <a target="_blank" href="http://guide.nettention.com/cpp_ko#logwriter_db" >µ¥ÀÌÅÍº£ÀÌ½º¿¡ ·Î±×¸¦ ±â·ÏÇÏ±â</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.

		\~english
		Records 1 log 
		- this function runs as asynchronous. In other words, it will be returned immediately.
		\param logText log text string
		\param pProperties Values to be entered to the fields that were added by user. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#logwriter_db" >Recording a log in database</a>.

		\~chinese
		??ìé?log¡£
		- ó®ùŞ??ÜÆ?ú¼¡£å¥ö¦ãÀ?Ê¦ì¤Ø¡?Ú÷üŞ¡£
		\param logText logí®İ¬Íú¡£
		\param pProperties ?ìıéÄ?ôÕÊ¥îÜ?æ´îÜ?¡£ŞÅéÄÖÇ??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#logwriter_db" >î¤?Ëß?ñé??log</a>%¡£

		\~japanese
		1ËÁªÎ«í«°ªòÑÀ?ª·ªŞª¹¡£
		- ª³ªÎ??ªÏŞªÔÒÑ¢ªÇ?ú¼ªµªìªŞª¹¡£?ªÁ¡¢òÁªÁªË«ê«¿?«óªµªìªŞª¹¡£
		\param logText ?ª¹«í«°Ùşí®Öª
		\param pProperties «æ?«¶?ª¬õÚÊ¥ª·ª¿«Õ«£?«ë«ÉªËìıªëö·ªÇª¹¡£ŞÅéÄÖÇªÏ¡¢\ref logwriter_db ªòª´?ğÎª¯ªÀªµª¤¡£
		\~
		*/
		virtual void WriteLine( String logText, CProperty* const pProperties=NULL) = 0;
	};

	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif //_WIN32