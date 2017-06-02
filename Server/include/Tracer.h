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
#include "PNString.h"
#include "Enums.h"

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
	Tracer.h ÆÄÀÏÀ» IncludeÇØ¾ß ÇÕ´Ï´Ù.
	ÆÄÀÏ¿¡ ·Î±×¸¦ ±â·ÏÇÏ´Â ¸ğµâÀÔ´Ï´Ù. ( <a target="_blank" href="http://guide.nettention.com/cpp_ko#write_pidl" >PIDL ÆÄÀÏ ÀÛ¼ºÇÏ±â</a>  Âü°í)

	ÀÏ¹İÀû ¿ëµµ
	- CLogWriter.New ¸¦ ½á¼­ ÀÌ °´Ã¼¸¦ »ı¼ºÇÕ´Ï´Ù. »ı¼º½Ã ÀúÀåÇÒ ·Î±× ÆÄÀÏ ÀÌ¸§°ú »õ·Î¿î ÆÄÀÏÀ» ¸¸µé ¶óÀÎ¼ö¸¦ ÁöÁ¤ÇÕ´Ï´Ù.
	- WriteLine, WriteLine¸¦ ½á¼­ ·Î±×¸¦ ±â·ÏÇÕ´Ï´Ù. ÀúÀåµÈ ·Î±×´Â ºñµ¿±â·Î ÆÄÀÏ¿¡ ÀúÀåµË´Ï´Ù.

	\~english
	 Module that records log to a file (Refer <a target="_blank" href="http://guide.nettention.com/cpp_en#write_pidl" >Making a PIDL file</a> )

	General usage
	- Use CLogWriter.New to create this object. Designates log file name when created.
	- Use WriteLine, WriteLine to record log. Saved log is saved in file as asynchronous.

	\~chinese
	èÙÙşËì??logîÜÙ¼?¡££¨?ÍÅ <a target="_blank" href="http://guide.nettention.com/cpp_zh#write_pidl" >?ËïPIDLÙşËì</a>£©

	ìéÚõéÄÔ²
	- ŞÅéÄ CLogWriter.New%ßæà÷ó®?ßÚ¡£ßæà÷îÜ?ı¦ò¦ïÒé©ÜÁğíîÜlogÙşËìÙ£ûúé©?ËïãæÙşËìîÜú¼?¡£
	- ŞÅéÄWriteLine, WriteLine??log¡£ÜÁğíîÜlogì¤ŞªÔÒÜÆû¡ãÒÜÁğíÓğÙşËì¡£

	\~japanese
	Tracer.h«Õ«¡«¤«ëªòIncludeª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
	«Õ«¡«¤«ëªË«í«°ªòÑÀ?ª¹ªë«â«¸«å?«ëªÇª¹¡££¨\ref logwriter_file?ÍÅ£©

	ìéÚõîÜªÊéÄÔ²
	- CLogWriter.NewªòŞÅªÃªÆª³ªÎ«ª«Ö«¸«§«¯«Èªòßæà÷ª·ªŞª¹¡£ßæà÷ãÁªËÜÁğíª¹ªë«í«°«Õ«¡«¤«ëÙ£ªÈãæª·ª¤«Õ«¡«¤«ëªòíÂªë«é«¤«ó?ªòò¦ïÒª·ªŞª¹¡£
	- WriteLine, WriteLineªòŞÅªÃªÆ«í«°ªòÑÀ?ª·ªŞª¹¡£ÜÁğíªµªìª¿«í«°ªÏŞªÔÒÑ¢ªÇ«Õ«¡«¤«ëªËÜÁğíª·ªŞª¹¡£
	\~
	*/
	class CLogWriter
	{
	public:
		enum eLogType
		{
			eLogTypeNewFile = 0,
			eLogTypeDefault,
			eLogTypeUserDefine
		};
	
		/** 
		\~korean
		\brief »õ CLogWriter °´Ã¼¸¦ »ı¼ºÇÕ´Ï´Ù.
		\param logFileName ·Î±× ÆÄÀÏ ÀÌ¸§
		\param newFileForLineLimit ·Î±× ÁÙ ¼ö°¡ ¿©±â¼­ ÁöÁ¤ÇÑ °ª ÀÌ»óÀ¸·Î Ä¿Áö¸é »õ ·Î±× ÆÄÀÏ¿¡ ±â·ÏÇÏ±â ½ÃÀÛÇÕ´Ï´Ù. 0ÀÌ¸é ¹«Á¦ÇÑÀÔ´Ï´Ù.
		\param putFileTimeString true¸¦ ÁöÁ¤ÇÏ¸é ÆÄÀÏ¸í¿¡ ÇöÀç ½Ã°£Á¤º¸(¿¬¿ùÀÏ½ÃºĞÃÊ)¸¦ ºÙ¿© ÆÄÀÏ¸í Áßº¹À» ¹æÁöÇÕ´Ï´Ù.

		\~english TODO:translate needed.
		\brief Generate a new CLogWriter object.
		\param logFileName log file name. 
		\param newFileForLineLimit If the number of the log lines gets bigger than the designated value her, then it starts recording in a new log file. It is limitless if 0.
		\param putFileTimeString If set as ¡°true¡±, the current time information (year/month/date/hour/minute/second) is added to prevent duplication of file names. 

		\~chinese
		\brief ßæà÷ãæîÜ CLogWriter%?ßÚ¡£
		\param logFileName logÙşËìÙ£¡£
		\param newFileForLineLimit logú¼?İïî¤?×ìò¦ïÒ?ÌÚÒıîÜ?£¬?ã·??ÓğãæÙşËì×ì¡£

		\~japanese
		\brief ãæª·ª¤CLogWriter«ª«Ö«¸«§«¯«Èªòßæà÷ª·ªŞª¹¡£
		\param logFileName «í«°«Õ«¡«¤«ëÙ£
		\param newFileForLineLimit «í«°ú¼?ª¬ª³ª³ªÇò¦ïÒª·ª¿ö·ì¤ß¾ªËÓŞª­ª¯ªÊªëªÈãæª·ª¤«í«°«Õ«¡«¤«ëªËÑÀ?ª·ã·ªáªŞª¹¡£0ªÇª¢ªìªĞÙíğ¤ùÚªÇª¹¡£
		\param putFileTimeString trueªòò¦ïÒª¹ªëªÈ«Õ«¡«¤«ëÙ£ªËúŞî¤ªÎãÁÊàï×ÜÃ(Ò´êÅìíãÁİÂõ©)ªòªÄª±ªÆ«Õ«¡«¤«ëÙ£ñìÜÜªòÛÁò­ª·ªŞª¹¡£
		\~
		*/
		PROUD_API static CLogWriter* New(const String& logFileName, unsigned int newFileForLineLimit = 0, bool putFileTimeString = true);

	protected:
		CLogWriter(); // CLogWriter::New()¸¦ ´ë½Å »ç¿ëÇÏ¼¼¿ä!

	public:
		virtual ~CLogWriter();

		/** 
		\~korean
		·Î±× ÆÄÀÏÀ» ´Ù¸¥ ÀÌ¸§À¸·Î ¹Ù²ß´Ï´Ù. ±â·Ï ÁßÀÌ´ø ÆÄÀÏÀº ´İÈ÷°í ´Ù¸¥ ÀÌ¸§À¸·Î ¹Ù²ï ÆÄÀÏ·Î »õ·Î ¿­¸³´Ï´Ù. 
		- ÀÌ ÇÔ¼ö´Â ºñµ¿±â·Î ½ÇÇàµË´Ï´Ù.  Áï, Áï½Ã ¸®ÅÏµË´Ï´Ù.
		- ¸¸¾à ·Î±× ÆÄÀÏÀ» ´Ù¸¥ ÀÌ¸§À¸·Î ¹Ù²Ù´Â °ÍÀÌ ½ÇÆĞÇÏ¸é ÀÌ ÇÔ¼ö´Â ¿À·ù¸¦ ¸®ÅÏÇÏÁö ¾Ê½À´Ï´Ù. ±× ´ë½Å ·Î±×¸¦ ±â·ÏÇÏ´Â ÇÔ¼ö¸¦ 
		»ç¿ëÇÒ ¶§ Proud.Exception ¿¹¿Ü°¡ ¹ß»ıÇÒ °ÍÀÔ´Ï´Ù. 
		\param logFileName »õ ·Î±× ÆÄÀÏ ÀÌ¸§ 

		\~english
		The log file is changed to another name. The file being recorded is closed and opens newly as a file changed to a different name.
		- This function is executed asynchronously. In other words, it is returned immediately. 
		- If the log file fails to change to a different name, this function does not return the error. Instead, Proud.Exception exception will occur when the function to record the log is used. 
		\param logFileName New log file name

		\~chinese
		÷êìíò¤ÙşËìáóËÇ?ĞìöâÙ£?¡£??ñéîÜÙşËì?ù¬??£¬ÔÒ?öè?ĞìöâÙ£?îÜÙşËì¡£ 
		- ó®ùŞ?ŞªÔÒÜÆ?ú¼¡£?£¬Ø¡?Ú÷üŞ¡£
		- åıÍıìíò¤ÙşËìîÜÙ£?ÌÚËÇã÷?£¬?ÜôÚ÷üŞ??¡£ Ó£î¤ŞÅéÄìíò¤??ùŞ???ßæProud.ExceptionÖÇèâ¡£ 
		\paramlogFileName ãæìíò¤ÙşËìÙ£? 

		\~japanese
		«í«°«Õ«¡«¤«ëªÎÙ£îñªò?ÌÚª·ªŞª¹¡£ÑÀ?ª·ªÆª¤ª¿«Õ«¡«¤«ëªÏøÍª¸ªÆ¡¢?ÌÚªµªìª¿Ù£îñªÎ«Õ«¡«¤«ëª¬ãæª¿ªËËÒª«ªìªŞª¹¡£
		- ª³ªÎ??ªÏŞªÔÒÑ¢ªÇ?ú¼ªµªìªŞª¹¡£?ªÁ¡¢òÁªÁªË«ê«¿?«óªµªìªŞª¹¡£
		- ªâª·¡¢«í«°«Õ«¡«¤«ëªÎÙ£îñ?ÌÚªËã÷ø¨ª·ª¿ªé¡¢ª³ªÎ??ªÏ«¨«é?ªò«ê«¿?«óª·ªŞª»ªó¡£ª½ªÎÓÛªïªêªË«í«°ªòÑÀ?ª¹ªë??ªòŞÅª¦ãÁ¡¢Proud.ExceptionÖÇèâª¬?ßæª·ªŞª¹¡£
		\param logFileName ãæª·ª¤«í«°«Õ«¡«¤«ëÙ£
		\~
		*/
		virtual void SetFileName(const String& logFileName) = 0;

		/** 
		\~korean
		·Î±× ÇÑÁÙÀ» ProudNet ¾ç½Ä¿¡ ¸ÂÃç ÆÄÀÏ¿¡ ±â·ÏÇÕ´Ï´Ù.
		- ÀÌ ÇÔ¼ö´Â ºñµ¿±â·Î ½ÇÇàµË´Ï´Ù. Áï, Áï½Ã ¸®ÅÏµË´Ï´Ù.
		 -ÀÌ ÇÔ¼ö´Â ¾Æ·¡ ¿¹Á¦Ã³·³ ÃÖÁ¾ Ãâ·Â µË´Ï´Ù. 
		  logWriteLineTime: logLevel / logCategory(logHostID): logMessage {logFunction(logLine)}
		\param logLevel ·Î±× ³»¿ëÀÇ ½É°¢µµ
		\param logCategory ¾î¶² Á¾·ùÀÇ ·Î±×ÀÎÁö?
		\param logHostID ÀÌ ·Î±×¸¦ Àü¼ÛÇÑ È£½ºÆ®
		\param logMessage ·Î±× ¸Ş½ÃÁö
		\param logFunction ·Î±×¸¦ È£ÃâÇÑ ÇÔ¼ö ÀÌ¸§
		\param logLine ·Î±×¸¦ È£ÃâÇÑ ¶óÀÎ

		\~english
		One line of the log is recorded in the file in the ProudNet format. 
		- This function is executed asynchronously. In other words, it is returned immediately.
		- This function is finally output as the examples below.
		logWriteLineTime: logLevel / logCategory(logHostID): logMessage {logFunction(logLine)}
		\param logLevel Severity of the log content
		\param logCategory What type of a log is this?
		\param logHostID The host transmitting this log. 
		\param logMessage Log message
		\param logFunction Name of the function that has called the log
		\param logLine Line that has called the log


		\~chinese
		÷êìéú¼ìíò¤äÎğÎProudNet?ãÒ??ÓğÙşËì¡£
		- ó®ùŞ?ŞªÔÒÜÆ?ú¼£¬?£¬Ø¡?Ú÷üŞ¡£
		-ó®ùŞ?õÌ?ù¬?õó£¬åıù»ÖÇí­¡£ 
		logWriteLineTime: logLevel / logCategory(logHostID): logMessage {logFunction(logLine)}
		\param logLevel ìíò¤?é»îÜñìé©Óø
		\param logCategory ù¼??úşîÜìíò¤?
		\param logHostID ??ó®ìíò¤îÜñ«Ïõ
		\param logMessage ìíò¤á¼ãÓ
		\param logFunction ?éÄìíò¤îÜùŞ?Ù£?
		\param logLine ?éÄìíò¤îÜline

		\~japanese
		«í«°1ú¼ªòProudNetªÎ?ãÒªËùêªïª»ªÆ«Õ«¡«¤«ëªËÑÀ?ª·ªŞª¹¡£
		- ª³ªÎ??ªÏŞªÔÒÑ¢ªÇ?ú¼ªµªìªŞª¹¡£?ªÁ¡¢òÁªÁªË«ê«¿?«óªµªìªŞª¹¡£
		- ª³ªÎ??ªÏù»ªÎÖÇğ¹ªÎªèª¦ªËõÌğûõóÕôªµªìªŞª¹¡£
		logWriteLineTime: logLevel / logCategory(logHostID): logMessage {logFunction(logLine)}
		\param logLevel «í«°?é»ªÎä¢Ê¾Óø
		\param logCategory ªÉªóªÊğú×¾ªÎ«í«°ªÊªÎª«£¿
		\param logHostID ª³ªÎ«í«°ªò?áêª·ª¿«Û«¹«È
		\param logMessage «í«°«á«Ã«»?«¸
		\param logFunction «í«°ªòû¼ªÓõóª·ª¿??Ù£
		\param logLine «í«°ªòû¼ªÓõóª·ª¿«é«¤«ó
		\~
		*/
		virtual void WriteLine(int logLevel, LogCategory logCategory, HostID logHostID, const String& logMessage, const String& logFunction = _PNT(""), int logLine = 0) = 0;

		/**
		\~korean
		·Î±× ÇÑÁÙÀ» ÆÄÀÏ¿¡ ±â·ÏÇÕ´Ï´Ù.
		- ÀÌ ÇÔ¼ö´Â ºñµ¿±â·Î ½ÇÇàµË´Ï´Ù. Áï, Áï½Ã ¸®ÅÏµË´Ï´Ù.
		- ´Ü, void WriteLine(TraceID TID, LPCWSTR text) ¿Í ´Ş¸® ¾Æ¹«·± Çì´õ¸¦ Æ÷ÇÔÇÏÁö ¾Ê½À´Ï´Ù.
		\param logMessage ·Î±×¸¦ ÂïÀ» ¹®ÀÚ¿­. 
		- String ÇüÅÂ ¶Ç´Â WriteLine(String::NewFormat(L"Test Log %d", 10)) ÇüÅÂ·Î »ç¿ë °¡´ÉÇÕ´Ï´Ù.

		\~english
		Writes a line of log to the file
		- This function is asynchronous so returned immediately.
		- But not like void WriteLine(TraceID TID, LPCWSTR text), does not have any header.
		\param logMessage text string to record log.
		- You are able to use string type or WriteLine(String::NewFormat(L"Test Log %d", 10)) type

		\~chinese
		÷êìéú¼log??ÓğÙşËì¡£
		- ó®ùŞ?ì¤ŞªÔÒÜÆ?ú¼¡£?£¬?Ø¡?Ú÷üŞ¡£
		- Ó£ãÀ£¬?void WriteLine(TraceID TID, LPCWSTR text)ÜôÔÒ?Üô?øĞÎÀìòù¼header¡£
		\param logMessage ??logîÜí®İ¬Íú¡£
		- You are able to use string type or WriteLine(String::NewFormat(L"Test Log %d", 10)) type

		\~japanese
		«í«°1ú¼ªò«Õ«¡«¤«ëªËÑÀ?ª·ªŞª¹¡£
		- ª³ªÎ??ªÏŞªÔÒÑ¢ªÇ?ú¼ªµªìªŞª¹¡£?ªÁ¡¢òÁªÁªË«ê«¿?«óªµªìªŞª¹¡£
		- Ó£ª·¡¢void WriteLine(TraceID TID, LPCWSTR text)ªÈªÏêŞªÃªÆ¡¢ù¼ªéªÎ«Ø«Ã«À?ªòùßªáªŞª»ªó¡£
		\param logMessage «í«°ªò?ª¹Ùşí®Öª 
		- String û¡÷¾ªŞª¿ªÏWriteLine(String::NewFormat(L"Test Log %d", 10))û¡÷¾ªÇŞÅéÄÊ¦ÒöªÇª¹¡£
		\~
		*/
		virtual void WriteLine(const String& logMessage) = 0;

		/**
		\~korean
		- CLogWriter °´Ã¼¸¦ Á¦°Å(Á¾·á) ÇÒ ¶§ ¹ÌÃ³ Ãâ·ÂÇÏÁö ¸øÇÑ ·Î±×µéÀ» ¸¶Àú Ãâ·ÂÇÒÁö ¶Ç´Â ¹«½ÃÇÒÁö ¿©ºÎ¸¦ °áÁ¤ÇÕ´Ï´Ù.
		- ±âº»°ªÀº falseÀÔ´Ï´Ù.
		- true·Î ¼³Á¤µÇ¸é Ãâ·ÂÇÏÁö ¸øÇÑ ·Î±×°¡ ÀÖ¾îµµ ¹«½ÃÇÏ°í Áï½Ã Á¾·áÇÕ´Ï´Ù.
		- false·Î ¼³Á¤µÈ °æ¿ì Ãâ·ÂÇÏÁö ¸øÇÑ ·Î±×µéÀ» ¸ğµÎ Ãâ·Â ÇÒ ¶§ ±îÁö Á¾·á°¡ Áö¿¬µË´Ï´Ù.

		\param flag ÀÌ ¿É¼ÇÀ» »ç¿ëÇÒÁö ¿©ºÎÀÔ´Ï´Ù.
		
		\~english 
		- This determines whether to output the rest of the logs not yet output when the object is terminated (ended) or ignore them. 
		- The default value is false. 
		- If set true, it terminates immediately even if there is a log not yet output. 
		- If set false, termination is delayed until not yet output logs are all output. 

		\param flag Whether to use this option or not. 

		\~chinese
		- ??ğ¶£¨?áÖ£©CLogWriter ?ßÚ?Ú±Ğà??õóîÜìíò¤?ú¼???õóûäûìÕÔğÃíÂñ®õó?ïÒ¡£
		- Ùù???false¡£
		- åıÍıãÀtrue£¬?øµğíî¤Ú±?õóèÇîÜìíò¤å¥?ûìÕÔ?Ø¡??áÖ¡£
		- åıÍıãÀfalse£¬?áÖğÃíÂ?ù¬æÅ?£¬òÁÓğÚ±?õóîÜìíò¤èÇà÷?õó¡£

		\param flag ãÀÜúŞÅéÄó®??¡£

		\~japanese
		- CLogWriter «ª«Ö«¸«§«¯«Èªòğ¶ËÛ£¨ğûÖõ£©ª¹ªëãÁ¡¢ªŞªÀõóÕôªÇª­ªÊª«ªÃª¿«í«°ªòõÌı­ªŞªÇõóÕôª¹ªëª«¡¢ªŞª¿ªÏÙíãÊª¹ªëª«ªòÌ½ïÒª·ªŞª¹¡£
		- ĞñÜâö·ªÏfalseªÇª¹¡£
		- trueªËàâïÒª¹ªëªÈõóÕôªÇª­ªÊª«ªÃª¿«í«°ª¬ª¢ªÃªÆªâÙíãÊª·ªÆòÁªÁªËğûÖõª·ªŞª¹¡£
		- falseªËàâïÒª·ª¿íŞùê¡¢õóÕôªÇª­ªÊª«ªÃª¿«í«°ªòîïªÆõóÕôª¹ªëãÁªŞªÇğûÖõª¬?æÅªµªìªŞª¹¡£
		\param flag ª³ªÎ«ª«×«·«ç«óªòŞÅéÄª¹ªëª«ªÉª¦ª«ªÇª¹¡£
		
		\~
		*/
		virtual void SetIgnorePendedWriteOnExit(bool flag) = 0;
	};

	/**  @} */

	String GetFileTimeString();
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
