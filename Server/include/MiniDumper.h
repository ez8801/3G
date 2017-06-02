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

#include "sysutil.h"
#include "Singleton.h"
#include "MiniDumpAction.h"

#if defined(_WIN32)
#include <DbgHelp.h>
#pragma comment(lib,"dbghelp.lib")
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup minidump_group
	*  @{
	*/

#if defined(_WIN32)

	/**
	\~korean
	¹Ì´Ï ´ıÇÁ¸¦ »ç¿ëÇÏ±â À§ÇØ Á¦°øÇØ¾ß ÇÏ´Â ÆÄ¶ó¸ŞÅÍ

	\~english
	It is a parameter that needs to be provided for using mini dump.

	\~chinese
	?ÖõŞÅéÄMini dumpì»âÍğ«ÍêîÜ??¡£

	\~japanese
	«ß«Ë«À«ó«×ªòŞÅéÄª¹ªëª¿ªáªËğ«Íêª¹ªë«Ñ«é«á?«¿
	*/
	class CMiniDumpParameter
	{
	public:
		/**
		\~korean
		¹Ì´Ï ´ıÇÁ°¡ »ı¼ºÇÒ ÆÄÀÏ ÀÌ¸§ÀÇ °æ·Î¸¦ Ã¤¿ö³Ö´Â´Ù.

		\~english
		Please input the directory of file name that mini dump is going to create.

		\~chinese
		?õöMini dump?ËïîÜÙşËìÙ£îÜÖØ?¡£

		\~japanese
		«ß«Ë«À«ó«×ª¬ßæà÷ª¹ªë«Õ«¡«¤«ëÙ£ªÎ?ÖØªòìıªìªë¡£
		*/
		Proud::String m_dumpFileName;

		/**
		\~korean
		¹Ì´Ï ´ıÇÁ Å¸ÀÔÀ» ÁöÁ¤ÇÑ´Ù.

		\~english
		Sets the type of mini dump

		\~chinese
		ò¦ïÒÚ°úş???úş¡£

		\~japanese
		«ß«Ë«À«ó«×«¿«¤«×ªòò¦ïÒª¹ªë¡£
		*/
		MINIDUMP_TYPE m_miniDumpType;

		CMiniDumpParameter();
	};

#define SmallMiniDumpType MiniDumpNormal // MiniDumpWithDataSegs°¡ °¡Àå ¾µ¸¸ÇÏ´Ù°ï ÇÏÁö¸¸ 6MB³ª µÇ´Ï±î À¯ÀúµéÀÌ Àß ¾Èº¸³½´Ù.

	/**
	\~korean
	¹Ì´Ï ´ıÇÁ ¸ğµâ

	Æ¯Â¡
	- ÀÌ °´Ã¼´Â ¼­¹ö Å©·¡½¬ ¹ß»ı½Ã .DMP ÆÄÀÏÀ» ¸¸µç´Ù.
	- .DMP ÆÄÀÏÀº visual studio.net¿¡¼­ Á÷Á¢ ¿­¾î¼­ ¿À·ù À§Ä¡¸¦ ÃßÀûÇÏ´Âµ¥ µµ¿òÀÌ µÈ´Ù.
	- µ¿½Ã ´Ù¹ßÀûÀ¸·Î ¿©·¯ ½º·¹µå¿¡¼­ unhandled exceptionÀÌ ¹ß»ıÇØµµ ÃÖÃÊ 1È¸¿¡ ´ëÇÑ ´ıÇÁ ÆÄÀÏ¸¸ »ı¼ºµÈ´Ù.
	³ª¸ÓÁö ½º·¹µå´Â ´ıÇÁ°¡ ³¡³¯¶§±îÁö ´ë±âÇÑ´Ù. ±×·¡¾ß ´ıÇÁÁß¿¡ ÇÁ·Î¼¼½º°¡ µı ¹®Á¦°¡ »ı±âÁö ¾Ê´Â´Ù.

	ÀÏ¹İÀû ¿ëµµ
	- ÀÌ °´Ã¼´Â ½Ì±ÛÅæÀÌ´Ù. ÀÏ´Ü ÀÌ °´Ã¼ÀÇ Delegate¸¦ ÁöÁ¤ÇÔÀ¸·Î JIT creationÀÌ µÈ´Ù. Delegate ÁöÁ¤Àº
	Init()·Î ÇÑ´Ù. ÀÌÈÄºÎÅÍ´Â ÇÁ·Î±×·¥ ¿À·ù½Ã ´ıÇÁ ÇÁ·Î±×·¥ÀÌ ÀÛµ¿ÇÑ´Ù.
	- ¼öµ¿ ¹Ì´Ï ´ıÇÁ¸¦ »ı¼ºÀº Dump()·Î ÇÑ´Ù.

	\~english
	Mini dump module

	Characterictics
	- This object creates .DMP files when server crash occurs.
	- .DMP can be opened by visual studio.net directly and helps tracking where error occurred.
	- The first cump file will be created even if there are multiple unhandled exceptionals occured from many thread simultaneously.
	Other thread will standby until dump ends. There will be no other problems while dumping the process by doing so.

	General usage
	- This object is Singleton. This will become JIT creation by designating Delegate of this object. Delegate is designated by using Init(). From this point and then, dump program will automatically run when error occurs.
	- Dump() is used to create manual mini dump.

	\~chinese
	Ú°úş??Ù¼?¡£

	÷åïÖ
	- ó®?ßÚî¤?ßæÜ×?ĞïcrashîÜ?ı¦?Ëï.DMP¡£
	- .DMPÙşËìî¤visual  studio.net%òÁïÈöè??õÚñ¡êÈöÇ?êó?ğ¾¡£
	- ?ŞÅÔÒ?î¤Òı?àõîÜÒı??ïïß¾?ßæunhandled exception£¬ñşßæà÷?õÌôøìéó­îÜ??ÙşËì¡£
	í¥ù»îÜ?ïïÔõÓğ???áÖ¡£??î¦Òöî¤??ñéïïßíÜô??ßæĞìöâ??¡£

	ìéÚõéÄÔ²
	- ó®?ßÚãÀsingleton¡£à»ò¦ïÒó®?ßÚîÜDelegateñıı¨?JIT creation¡£éÄInit()?ú¼DelegateîÜò¦ïÒ¡£ñıı¨åıÍıïïßí?ßæ??£¬??ïïßíö¦???¡£
	- â¢?ßæà÷Ú°úş??ãÀéÄDump()¡£

	\~japanese
	«ß«Ë«À«ó«×«â«¸«å?«ë

	÷å?
	-ª³ªÎ«ª«Ö«¸«§«¯«ÈªÏªµ?ªĞ«¯«é«Ã«·«å?ßæãÁ¡¢.DMP «Õ«¡«¤«ëªòíÂªêªŞª¹¡£
	-.DMP«Õ«¡«¤«ëªÏvisual studio.netªÇòÁïÈËÒª¤ªÆ«¨«é?ªÎêÈöÇªòõÚîæª¹ªëªÎªËæµªËØ¡ªÁªŞª¹¡£
	-ÔÒãÁÒı?îÜªËÒı?ªÊ«¹«ì«Ã«ÉªÇunhandled exceptionª¬?ßæª·ªÆªâõÌôø£±üŞªË?ª¹ªë«À«ó«×«Õ«¡«¤«ëªÀª±ßæà÷ªµªìªŞª¹¡£
	?ªêªÎ«¹«ì«Ã«ÉªÏ«À«ó«×ª¬ğûªïªëªŞªÇÓâÑ¦ª·ªŞª¹¡£ª½ª¦ª·ªÊª¤ªÈ«À«ó«×ñé¡¢«×«í«»«¹ªËöâªÎÙığ¹ª¬?ßæª·ªŞª¹¡£

	ìéÚõîÜªÊéÄÔ²
	-ª³ªÎ«ª«Ö«¸«§«¯«ÈªÏ«·«ó«°«ë«È«óªÇª¹¡£ìéÓ©ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎDelegateªòò¦ïÒª¹ªëª³ªÈªÇJIT creationªËªÊªêªŞª¹¡£ Delegateò¦ïÒªÏ
	Init()ªËª·ªŞª¹¡£ª½ªìª«ªéªÏ«×«í«°«é«àªÎ«¨«é?ªÎğ·«À«ó«×«×«í«°«é«àª¬íÂÔÑª·ªŞª¹¡£
	-â¢ÔÑ«ß«Ë«À«ó«×ªÎßæà÷ªÏ Dump()ªËª·ªŞª¹¡£
	*/
	class CMiniDumper : public CSingleton<CMiniDumper>
	{
		/**
		\~korean
		¿©·¯ ½º·¹µå¿¡¼­ ´ıÇÁ¸¦ ½×À¸¸é ²¿ÀÎ´Ù. µû¶ó¼­ ÀÌ°É·Î Á÷·ÄÈ­ÇÑ´Ù.

		\~english
		Will cras if many threads stack dump. So must be serialized by using this.

		\~chinese
		î¤???ïï÷Ø???îÜ?Üôû¿¡£á¶ì¤éÄ??Íú?ûù¡£

		\~japanese
		Òı?ªÊ«¹«ì«Ã«ÉªÇ«À«ó«×«Õ«¡«¤«ëªò?ª¹ªÈª³ª¸ªìªŞª¹¡£ªÇª¹ªÎªÇª³ªìªÇòÁÖªûùª·ªŞª¹¡£
		*/
		CriticalSection m_filterWorking;

		/**
		\~korean
		TopLevelFilter ½Ç ÀÛµ¿À» 1È¸·Î Á¦ÇÑÇÏ´Â ¸ñÀû

		\~english
		To limit the real execution of TopLevelFilter by once.

		\~chinese
		TopLevelFilter ùÚğ¤????1üŞîÜÙÍîÜ¡£

		\~japanese
		TopLevelFilter?íÂÔÑªòìéüŞªÈğ¤ùÚª¹ªëÙÍîÜ
		*/
		PROUDNET_VOLATILE_ALIGN LONG m_hitCount;

		PROUD_API void SetUnhandledExceptionHandler();

		PROUD_API uint32_t CreateProcessAndWaitForExit(const PNTCHAR *args, MINIDUMP_TYPE miniDumpType, _EXCEPTION_POINTERS *pExceptionInfo = NULL);

		static LONG WINAPI TopLevelFilter(_EXCEPTION_POINTERS *pExceptionInfo);
		LONG TopLevelFilter_(_EXCEPTION_POINTERS *pExceptionInfo);

#if defined(_WIN64)
		bool DumpWithFlags(const PNTCHAR *dumpFileName, const uint32_t processID, const MINIDUMP_TYPE minidumpFlags, const uint32_t threadID, const uint64_t exceptionInfoAddr);
#else
		bool DumpWithFlags(const PNTCHAR *dumpFileName, const uint32_t processID, const MINIDUMP_TYPE minidumpFlags, const uint32_t threadID, const uint32_t exceptionInfoAddr);
#endif

	private:
		/**
		\~korean
		¹Ì´Ï ´ıÇÁ¸¦ »ç¿ëÇÏ±â À§ÇÑ ÆÄ¶ó¸ŞÅÍ

		\~english 
		The parameter to use the mini dump. 

		\~chinese 
		éÄéÍmini dumperîÜ??
		\~

		\~japanese 
		«ß«Ë«À«ó«×ªòŞÅª¦ª¿ªáªÎ«Ñ«é«á?«¿?
		\~
		*/
		CMiniDumpParameter m_parameter;

	public:
		CMiniDumper();
		~CMiniDumper();

		/**
		\~korean
		ÃÊ±âÈ­ ÇÔ¼öÀÔ´Ï´Ù.
		\param cmdLine ¾ÛÀÇ Command-Line argumentÀÇ ÀÎÀÚ¸¦ ³Ö¾îÁÖ½Ã¸é µË´Ï´Ù.

		ProudNetÀº ¾Û¿¡¼­ ¿À·ù ¹ß»ı ½Ã, ¾Û ÀÚ½ÅÀ» »õ·Î¿î ÇÁ·Î¼¼½º·Î ½ÇÇàÇÕ´Ï´Ù.
		ÀÌ ¶§, Startup ÇÔ¼ö¿¡¼­ ÀÎ½ÄÇÒ ¼ö ÀÖ´Â Æ¯¼ö ±¸¹®À» Commad Line Argument¿¡ Ãß°¡ÇÏ¿© »õ·Î¿î ÇÁ·Î¼¼½º¸¦ ½ÇÇàÇÏ°Ô µË´Ï´Ù.

		ÀÌ ÇÔ¼ö´Â Win32 ÀÀ¿ë ÇÁ·Î±×·¥ ¹× MFC ÀÀ¿ëÇÁ·Î±×·¥¿¡¼­ È£ÃâÇÏ½Ã¸é µË´Ï´Ù.
		\code
		void main(int argc, char* argv[])
		{
		...

		CMiniDumpParameter parameter;
		switch(CMiniDumper::GetSharedPtr()->Startup(parameter))
		{
		case MiniDumpAction_AlarmCrash:
		// ¿À·ù ¹ß»ıÀ¸·Î »õ·Î¿î ÇÁ·Î¼¼½º¿¡¼­ ´ıÇÁ ÆÄÀÏÀ» »ı¼ºÇÑ ÈÄ, ÀÌ °ªÀÌ returnÀÌ µË´Ï´Ù.
		// »ı¼ºµÈ ´ıÇÁ ÆÄÀÏÀ» ¸ŞÀÏ·Î º¸³»°Å³ª ¿¡·¯ Ã¢À» º¸ÀÌ´Â µî À¯Àú°¡ ´ıÇÁ ÆÄÀÏ »ı¼º ÈÄ, Ã³¸®ÇØ¾ßÇÒ ÀÛ¾÷À» Ã³¸®ÇØÁÖ½Ã¸é µË´Ï´Ù.
		...
		break;

		case MiniDumpAction_DoNothing:
		// À¯Àú È£Ãâ·Î »õ·Î¿î ÇÁ·Î¼¼½º¿¡¼­ ´ıÇÁ ÆÄÀÏÀ» »ı¼ºÇÑ ÈÄ, ÀÌ °ªÀÌ ¹İÈ¯µË´Ï´Ù.
		// ÀÌ °æ¿ì¿¡´Â ¾Æ¹«°Íµµ ÇÏÁö ¸»¾Æ¾ßÇÕ´Ï´Ù.
		break;

		default: // MiniDumpAction_None
		// ÀÏ¹İÀûÀ¸·Î ¾Û ½ÇÇà ½Ã, ÀÌ °ªÀÌ ¹İÈ¯µË´Ï´Ù.
		// ¿©±â¼­´Â ÀÏ¹İÀûÀ¸·Î Ã³¸®ÇØ¾ßÇÒ ÀÏÀ» Ã³¸®ÇØÁÖ½Ã¸é µË´Ï´Ù.
		...
		break;
		}
		}
		\endcode

		\~english
		It is an initialized function.
		\param cmdLine Please insert Command-Line argument factor of application.

		When an error occurs in application, ProudNet executes the application with new process.
		\code
		void main(int argc, char* argv[])
		{
		...

		CMiniDumpParameter parameter;
		switch(CMiniDumper::GetSharedPtr()->Startup(parameter))
		{
		case MiniDumpAction_AlarmCrash:
		// After dump file creation at a new process due to error occurrence, this value will return.
		// Please proceed with works (such as sending created dump file by email & error window management) that need to be done right after dump file creation.
		...
		break;

		case MiniDumpAction_DoNothing:
		// After dump file creation at a new process by user calling, this value will return.
		// In this case, you should not do anything.
		break;

		default: // MiniDumpAction_None
		// Generally, this value returns when executing the application.
		// At this time, you should proceed with the relevant works.
		...
		break;
		}
		}
		\endcode

		\~chinese
		ôøã·ûùùŞ?¡£
		\param cmdLine ?ìıAppîÜCommand-Line argument ???Ê¦¡£

		î¤App?ñéåıÍı?ßæ??£¬ProudNet?éÄãæîÜProcess?ú¼App¡£
		ó®??î¤Command-Line ArgumentñéôÕÊ¥StartupùŞ?Ê¦ì¤??îÜ÷åâ¨?Ï£ı¨?ú¼ãæîÜProcess¡£.
		\code
		void main(int argc, char* argv[])
		{
		...

		CMiniDumpParameter parameter;
		switch(CMiniDumper::GetSharedPtr()->Startup(parameter))
		{
		case MiniDumpAction_AlarmCrash:
		// ì×???ßæî¤ãæîÜProcessñéßæà÷DumpÙşËìı¨ó®??ù¬return¡£
		// ?×âåıéÄ?Ëì?áêì«ßæà÷îÜDumpÙşËì¡¢?ãÆ???Ï¢ÔõéÄ?ßæà÷DumpÙşËìı¨á¶é©?×âîÜŞÀËì?Ê¦¡£
		...
		break;

		case MiniDumpAction_DoNothing:
		// éÄéÄ?û¼õóî¤ãæîÜProcessñéßæà÷DumpÙşËìı¨?Ú÷?ó®?¡£
		// ó®??Üôé©?ú¼ìòù¼ğÃíÂ¡£
		break;

		default: // MiniDumpAction_None
		// ÷×ßÈî¤?ú¼App??Ú÷?ó®?¡£
		// î¤?×ì?×âìéÚõâÍé©?ú¼îÜğÃíÂ?Ê¦¡£
		...
		break;
		}
		}
		\endcode

		\~japanese
		ôøÑ¢ûùªÎ??ªÇª¹¡£
		\param cmdLine App(Application)ªÎCommand-Line argumentªÎ«Ñ«é«á?«¿?ªòìıªìªÆª¯ªÀªµª¤¡£

		ProudNetªÏAppªÇ«¨«é?ª¬?ßæª¹ªëğ·,Appí»ãóªòãæª·ª¤«×«í«»«¹(Process)ªÇ?ú¼ª·ªŞª¹¡£
		ª³ªÎğ·¡¢Startup ??ªÇìããÛªÇª­ªë÷åâ¨Ï°Ùşªò Commad Line ArgumentªËõÚÊ¥ª·ªÆãæª·ª¤«×«í«»«¹ªò?ú¼ª·ªŞª¹¡£
		\code
		void main(int argc, char* argv[])
		{
		...

		CMiniDumpParameter parameter;
		switch(CMiniDumper::GetSharedPtr()->Startup(parameter))
		{
		case MiniDumpAction_AlarmCrash:
		// «¨«é?ªÎ?ßæªÇãæª·ª¤«×«í«»«¹ªÇ«À«ó«×«Õ«¡«¤«ëªòßæà÷ı­¡¢ª³ªÎö·ª¬ returnªµªìªŞª¹¡£
		// ßæà÷ªµªìª¿«À«ó«×«Õ«¡«¤«ëªò«á?«ëªÇáêªÃª¿ªê«¨«é?ªÎ?ØüªòÌ¸ª»ªëªÊªÉ«æ?«¶ª¬«À«ó«×«Õ«¡«¤«ëªòßæà÷ı­¡¢?×âª·ªÊª±ªìªĞªÊªéªÊª¤íÂåöªò?×âª·ªÆª¯ªÀªµª¤¡£
		...
		break;

		case MiniDumpAction_DoNothing:
		// «æ?«¶ªÎû¼ªÓõóª·ªÇãæª·ª¤«×«í«»«¹ªË«À«ó«×«Õ«¡«¤«ëªòßæà÷ı­¡¢ª³ªÎö·ª¬Ú÷ü½ªµªìªŞª¹¡£
		// ª³ªÎíŞùêªËªÏù¼ªâª·ªÊª¤ªÇª¯ªÀªµª¤¡£
		break;

		default: // MiniDumpAction_None
		// ìéÚõîÜªËªÏApp?ú¼ãÁ,ª³ªÎö·ª¬Ú÷ü½ªµªìªŞª¹¡£
		// ª³ª³ªÇªÏìéÚõîÜªË?×âª·ªÊª±ªìªĞªÊªéªÊª¤ª³ªÈªò?×âª·ªÆª¯ªÀªµª¤¡£
		...
		break;
		}
		}
		\endcode
		*/
		static MiniDumpAction Startup(const CMiniDumpParameter &parameter);
	private:
		MiniDumpAction Startup_(const CMiniDumpParameter &parameter);
	public:

		/***
		\~korean
		À¯Àú È£Ãâ¿¡ ÀÇÇØ ¹Ì´Ï ´ıÇÁ ÆÄÀÏÀ» »ı¼ºÇÑ´Ù. ´Ü, ¸Ş¸ğ¸® ÀüÃ¼ ´ıÇÁ¸¦ ÇÏ¹Ç·Î ¿ë·®ÀÌ Å« ÆÄÀÏÀÌ »ı¼ºµÈ´Ù.

		\~english
		Create mini dump file by user calling, however, the capacity of file becomes larger because the whole memory is dumped.

		\~chinese
		ù¬éÄ?û¼Ğ£ßæà÷Ú°úş??ÙşËì¡£Ó£ãÀ£¬ì×??ú¼?ğíîïİ»??£¬?ßæà÷é»ÕáÓŞîÜÙşËì¡£

		\~japanese
		«æ?«¶ªÎû¼ªÓõóª·ªËªèªê«ß«Ë«À«ó«×«Õ«¡«¤«ëªòßæà÷ª·ªŞª¹¡£ª¿ªÀª·¡¢«á«â«ê?îï?ªò«À«ó«×ª¹ªëªÎªÇé»ÕáªÎÓŞª­ª¤«Õ«¡«¤«ëª¬ßæà÷ªµªìªŞª¹¡£
		*/
		PROUD_API void ManualFullDump();

		/**
		\~korean
		À¯Àú È£Ãâ¿¡ ÀÇÇØ ¹Ì´Ï ´ıÇÁ ÆÄÀÏÀ» »ı¼ºÇÑ´Ù.

		\~english
		Create mini dump file by user calling.

		\~chinese
		ù¬éÄ?û¼Ğ£ßæà÷Ú°úş??ÙşËì¡£

		\~japanese
		«æ?«¶ªÎû¼ªÓõóª·ªËªèªê«ß«Ë«À«ó«×«Õ«¡«¤«ëªòßæà÷ª·ªŞª¹¡£
		*/
		PROUD_API void ManualMiniDump();

		/**
		\~korean
		ÀÌ ÇÔ¼ö¸¦ È£ÃâÇÑ ½ÃÁ¡¿¡¼­ÀÇ ÇÁ·Î¼¼½º »óÅÂ¸¦ ´ıÇÁ ÆÄÀÏ·Î ³²±ä´Ù.
		\param fileName ´ıÇÁ ÆÄÀÏ ÀÌ¸§. È®ÀåÀÚ´Â dmp·Î ÁöÁ¤ÇÒ °Í.

		\~english
		Process status of calling this function as dump file
		\param fileName Name of dump file. Its extension must be .dmp.

		\~chinese
		?û¼Ğ£ó®ùŞ?îÜ?ïÃîÜïïßí??×º???ÙşËì¡£
		\param filename ??ÙşËìÙ£¡£?î÷íºò¦ïÒ?dmp¡£

		\~japanese
		ª³ªÎ??ªòû¼ªÓõóª·ª¿ãÁïÃªÇªÎ«×«í«»«¹?÷¾ªò«À«ó«×«Õ«¡«¤«ëªÇ?ª·ªŞª¹¡£
		\param fileName«À«ó«×«Õ«¡«¤«ëªÎÙ£îñ¡£?íåí­ªÏdmpªÇò¦ïÒª¹ªëª³ªÈ¡£
		*/
		PROUD_API static void WriteDumpFromHere(const PNTCHAR* fileName, bool fullDump = false);
		//		PROUD_API static void WriteDumpAtExceptionThrower(const PNTCHAR* fileName, bool fullDump = false);
	};

	/**
	\~korean
	CExceptionLogger ¿¡¼­ ÇÊ¿ä·ÎÇÏ´Â delegate °´Ã¼ÀÌ´Ù. °³¹ßÀÚ´Â ÀÌ °´Ã¼¸¦ ¿À¹ö¶óÀÌµåÇÑ ÈÄ CExceptionLogger °¡
	Á¸ÀçÇÏ´Â µ¿¾È ÀÌ °´Ã¼¸¦ À¯ÁöÇØ¾ß ÇÑ´Ù.

	\~english
	Delegate object that is needed by CExceptionLogger. Developer must sustain this object while CExceptionLogger exists after overriding this object.

	\~chinese
	î¤ CExceptionLogger%âÍé©îÜdelegate?ßÚ¡£??íºî¤÷êó®?ßÚÜİËÌı¨£¬ CExceptionLogger%ğíî¤îÜÑ¢?é©?ò¥ó®?ßÚ¡£

	\~japanese
	CExceptionLoggerªÇù±é©ªÈª¹ªë delegate«ª«Ö«¸«§«¯«ÈªÇª¹¡£ËÒ?íºªÏª³ªÎ«ª«Ö«¸«§«¯«Èªò«ª?«Ğ?«é«¤«Éª·ª¿ı­¡¢ CExceptionLoggerª¬
	ğíî¤ª¹ªëÊà¡¢ª³ªÎ«ª«Ö«¸«§«¯«Èªòë«ò¥ª·ªÊªìªĞªÊªêªŞª»ªó¡£

	*/
	class IExceptionLoggerDelegate
	{
	public:
		/**
		\~korean
		Dump ÆÄÀÏµéÀÌ ÀúÀåµÉ Æú´õ¸¦ ¸®ÅÏÇÑ´Ù. »ó´ë °æ·Î ¶Ç´Â Àı´ë °æ·Î¸¦ ÁöÁ¤ÇÒ ¼ö ÀÖ´Ù.
		°³¹ßÀÚ´Â ÀÌ ¸Ş¼­µå¸¦ ¿À¹ö¶óÀÌµåÇØ¾ß ÇÑ´Ù.

		\~english
		Returns the folder where Dump files are to be stored. Either relative or absolute path can be designated.
		Developer must override this method.

		\~chinese
		Ú÷üŞÜÁğídumpÙşËìîÜÙşËì?¡£Ê¦ì¤ò¦ïÒßÓ?ÖØ?ûäíº??ÖØ?¡£??íºé©÷êó®Û°ÛöÜİËÌ¡£

		\~japanese
		Dump«Õ«¡«¤«ëª¿ªÁª¬ÜÁğíªµªìªë«Õ«©«ë«À?ªò«ê«¿?«óª·ªŞª¹¡£ßÓ??ÖØªŞª¿ªÏï¾??ÖØªòò¦ïÒªÇª­ªŞª¹¡£
		ËÒ?íºªÏª³ªÎ«á«½«Ã«Éªò«ª?«Ğ?«é«¤«Éª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
		*/
		virtual String GetDumpDirectory() = 0;
	};

	/**
	\~korean
	Å©·¡½¬ µî ÇÁ·Î±×·¥¿¡¼­ ¿¹¿Ü°¡ ¹ß»ıÇÒ °æ¿ì ¿¹¿Ü°¡ ¹ß»ıÇÑ ÁöÁ¡À» DMP ÆÄÀÏ·Î¼­ ·Î±×¸¦ ³²±â°í
	°è¼ÓÇØ¼­ ÇÁ·Î±×·¥À» ½ÇÇà½ÃÅ°´Â ¿ªÇÒÀ» ÇÏ´Â °´Ã¼
	- ÀÚ¼¼ÇÑ °ÍÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#exception_logger" >Áß´Ü¾ø´Â ¿À·ù´ıÇÁ½Ã½ºÅÛ(Exception Logger)</a> ¸¦ Âü°íÇÒ °Í
	- Windows XP ¶Ç´Â 2003 Server ÀÌ»óÀ» ÇÊ¿ä·Î ÇÑ´Ù.
	- Singleton °´Ã¼·Î¸¸ »ç¿ëÇÒ ¼ö ÀÖ´Ù. ÀÚ¼¼ÇÑ °ÍÀº CSingleton Âü°í.

	\~english
	The object that records the point where exception occurred as DMP file when crash occurs then has a role to keep running the program
	- Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#exception_logger" >Pauseless error dump system (Exception Logger)</a>.
	- Requires Windows XP or 2003 Server or later version
	- Can be only used as Singleton object. Please refer CSingleton.

	\~chinese
	î¤crashÔõïïßíñé?ßæÖÇèâîÜ?ı¦£¬÷ê?ßæÖÇèâîÜò¢ïÃéÄDMPÙşËì×ºlog£¬ÑÃó·???ú¼ïïßíîÜíÂéÄîÜ?ßÚ¡£
	- ????ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#exception_logger" >Üôñé?îÜ??logÍ§?(Exception Logger)</a>%¡£
	- âÍé©Windows XPûäíº2003 Serverì¤ß¾¡£
	- ñşÒöéÄéÍSingleton?ßÚ¡£????ÍÅ CSingleton%¡£

	\~japanese
	«¯«é«Ã«·«åªÊªÉ«×«í«°«é«àªÇÖÇèâª¬?ßæª¹ªëíŞùê¡¢ÖÇèâª¬?ßæª·ª¿ò¢ïÃªòDMP«Õ«¡«¤«ëªÇ«í«°ªò?ª·¡¢
	?ª±ªÆ«×«í«°«é«àªò?ú¼ªµª»ªëæµùÜªòª¹ªë«ª«Ö«¸«§«¯«È
	- ßÙª·ª¯ªÏ<a target="_blank" href="http://guide.nettention.com/cpp_jp#exception_logger" >Ùé??????Í§?(Exception Logger)</a>ªò?ÍÅª·ªÆª¯ªÀªµª¤¡£
	- Windows XPªŞª¿ªÏ2003 Serverì¤ß¾ªòù±é©ªÈª¹ªë¡£
	- Singleton«ª«Ö«¸«§«¯«ÈªÀª±ªÇŞÅéÄªÇª­ªŞª¹¡£ßÙª·ª¯ªÏ CSingletonªò?ÍÅª·ªÆª¯ªÀªµª¤¡£
	*/
	class CExceptionLogger : public CSingleton<CExceptionLogger>
	{
		CriticalSection m_cs;

		// ´ıÇÁ ÆÄÀÏÀÌ ÀúÀåµÉ µğ·ºÅÍ¸®
		String m_directory;
		// ´ıÇÁ ÆÄÀÏÀÇ ÀÌ¸§
		String m_dumpName;
		// ´ıÇÁ ÆÄÀÏ¿¡ »õ°ÜÁú ÀÏ·Ã ¹øÈ£
		int m_dumpSerial;
		// °¡Àå ¸¶Áö¸·¿¡ ´ıÇÁ¸¦ ³²±ä ½Ã°£
		uint32_t m_lastLoggedTick;

		IExceptionLoggerDelegate* m_dg;

		static LONG CALLBACK ExceptionLoggerProc(PEXCEPTION_POINTERS pExceptionInfo);
	private:
		LONG ExceptionLoggerProc_(PEXCEPTION_POINTERS pExceptionInfo);

	public:
		/**
		\~korean
		º» ·Î±× ½Ã½ºÅÛÀ» ÁØºñÇÑ´Ù.
		\param dg ÀÌ ½Ã½ºÅÛÀÌ ÇÊ¿ä·Î ÇÏ´Â Ãß°¡ÀûÀÎ ±â´ÉÀ» Á¦°øÇÒ delegate °´Ã¼ÀÇ Æ÷ÀÎÅÍ

		\~english
		Prepares this log system
		\param dg Pointer of the delegate object that will provide additional functions required by this system

		\~chinese
		ñ×?ÜâlogÍ§?¡£
		\param dg ğ«Íêó®Í§?âÍé©îÜİ¾Ê¥ĞüÒöîÜdelegate?ßÚîÜò¦?¡£

		\~japanese
		Üâ«í«°«·«¹«Æ«àªòñŞİáª·ªŞª¹¡£
		\param dg¡¡ª³ªÎ«·«¹«Æ«àª¬ù±é©ªÈª¹ªëõÚÊ¥îÜªÊÑ¦Òöªòğ«Íêª¹ªë delegate«ª«Ö«¸«§«¯«ÈªÎ«İ«¤«ó«¿?
		*/
		void Init(IExceptionLoggerDelegate* dg, Proud::String dumpName = _PNT("dump"));


		inline int GetDumpSerial() { return m_dumpSerial; }
	};
#endif

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
