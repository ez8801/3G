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

#include <winsvc.h>
#include "NTServiceStartParameter.h"
#include "Singleton.h"
#include "FastArray.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup ntservice_group
	*  @{
	*/

	/**
	\~korean
	CNTService °¡ ÇÊ¿ä·Î ÇÏ´Â event sink °´Ã¼

	ÀÌ °´Ã¼´Â CNTService °¡ ¿ä±¸ÇÏ´Â ´ÙÀ½ ±â´ÉÀ» Á¦°øÇÏ´Â ¿ªÇÒÀ» ÇÑ´Ù. À¯Àú´Â ÀÌ Å¬·¡½º¸¦ ±¸ÇöÇØ¾ß ÇÑ´Ù.
	- ¼­¹ö ¸ŞÀÎ ·çÆ¾
	- ·Î±× ³²±â±â ÇÔ¼ö µî Ãß°¡ ±â´É

	\~english
	Event sink that CNTService needs

	This object provides the following functions requested by CNTService. User must realize this class.
	- Server main routine
	- Addtional functions such as function that leaves log

	\~chinese
	CNTService âÍé©îÜevent sink?ßÚ¡£

	ó®?ßÚÑÃó·ğ«Íê CNTService%âÍé©îÜù»ìé?ÍíÒöîÜíÂéÄ¡£éÄ?é©??ó®?¡£
	- Ü×?Ğïñ«routine¡£
	- ×ºlogùŞ?ÔõôÕÊ¥îÜÍíÒö¡£

	\~japanese
	CNTService ª¬ù±é©ªÈª¹ªëevent sink«ª«Ö«¸«§«¯«È

	ª³ªÎ«ª«Ö«¸«§«¯«ÈªÏCNTServiceª¬é©Ï´ª¹ªëó­ªÎÑ¦Òöªòğ«Íêª¹ªëæµùÜªòª·ªŞª¹¡£«æ?«¶?ªÏª³ªÎ«¯«é«¹ªòÎıúŞª¹ªëù±é©ª¬ª¢ªêªŞª¹¡£
	- «µ?«Ğ?«á«¤«ó«ë?«Á«ó
	- «í«°?ª·??ªÊªÉªÎõÚÊ¥Ñ¦Òö
	*/
	class INTServiceEvent
	{
	public:
		virtual ~INTServiceEvent() {}

		/**
		\~korean
		ÀÌº¥Æ® ·Î±×¸¦ ³²±ä´Ù.
		\param type EVENTLOG_ERROR_TYPE,EVENTLOG_WARNING_TYPE,EVENTLOG_INFORMATION_TYPE Áß ÇÏ³ª
		\param text ³²±æ ¹®ÀÚ¿­

		\~english
		Leaves event log
		\param type Either EVENTLOG_ERROR_TYPE or EVENTLOG_WARNING_TYPE or EVENTLOG_INFORMATION_TYPE
		\param text Text string to be left

		\~chinese
		×ºêóŞÀËìlog¡£
		\param type EVENTLOG_ERROR_TYPE,EVENTLOG_WARNING_TYPE,EVENTLOG_INFORMATION_TYPE ñéñıìé¡£
		\param text é©×ºîÜí®İ¬Íú¡£

		\~japanese
		«¤«Ù«ó«È«í«°ªò?ª·ªŞª¹¡£
		\param type EVENTLOG_ERROR_TYPE,EVENTLOG_WARNING_TYPE,EVENTLOG_INFORMATION_TYPE ñéìéªÄ
		\param text ?ª¹Ùşí®Öª
		*/
		virtual void Log(int type, const PNTCHAR* text) = 0;

		/**
		\~korean
		¼­ºñ½º ¸ğµâ ¸ŞÀÎ ÇÔ¼ö
		ÀÌ ÇÔ¼ö´Â ¼­ºñ½º ¸ğµâ¿¡ ÀÇÇØ È£ÃâµÇ´Â ¸ŞÀÎ ÇÔ¼öÀÌ´Ù. ÀÌ ÇÔ¼ö¿¡ ¼­¹ö ÇÁ·Î±×·¥ ¸ŞÀÎ ·çÆ¾ÀÌ È£ÃâµÇ¾î¾ß ÇÑ´Ù.
		ÀÌ ÇÔ¼ö°¡ ¸®ÅÏÇÒ ¶§ ¼­ºñ½º°¡ Á¾·áÇÑ´Ù.

		¿ä±¸ »çÇ×
		- ÀÌ ÇÔ¼ö ³»ºÎ¿¡¼­ Å° ÀÔ·Â¿¡ ÀÇÇÑ Á¾·á ¶Ç´Â Win32 ¸Ş½ÃÁö ÇÁ·Î¼¼½º ·çÆ¾ÀÌ ¹İµå½Ã µé¾î°¡¾ß ÇÑ´Ù.
		¿Ö³ÄÇÏ¸é SCM¿¡ ÀÇÇØ ¼­ºñ½º Á¾·á ¸í·ÉÀÌ ÁÖ¾îÁú °æ¿ì WM_QUITÀ» ¼ö½ÅÇÏ±â ¶§¹®ÀÌ´Ù. ¾Æ·¡ÀÇ ¿¹Á¦ ÄÚµå¸¦ Âü°íÇÏ¶ó.

		Âü°í
		- argc,argv´Â CNTService::Instance() ·ÎºÎÅÍ ¾òÀ» ¼ö ÀÖ´Ù. ±×¹Û¿¡ CNTService::Instance() ·ÎºÎÅÍ ¿©·¯°¡Áö ¿É¼ÇÀ»
		¾òÀ» ¼ö ÀÖ´Ù.

		¿¹Á¦ ¼Ò½º
		\code
			while(1)
			{
				Sleep(100);
				if(_kbhit())
				{
					switch(getch())
					{
					case VK_ESCAPE:
						break;
					}
				}

				MSG msg;
				// ÃÖ´ë ÀÏÁ¤ ÂªÀº ½Ã°£µ¿¾È, ÄÜ¼Ö ÀÔ·Â, À©µµ ¸Ş½ÃÁö ¼ö½Å, ¸ŞÀÎ ½º·¹µå Á¾·á Áß ÇÏ³ª¸¦ ±â´Ù¸°´Ù.
				MsgWaitForMultipleObjects(0,0,TRUE,100,QS_ALLEVENTS);
				if(PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
				{
					if(!GetMessage(&msg,NULL,NULL,NULL))
						break;
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
		\endcode

		\~english
		Service module main function
		    This function is the main function that is called by service module. Server program main routine must be called to this function.
		    Service is terminated when this function is returned.

		Requirements
		- Either a termination by keyboard input or Win32 message process routine must be entered to this function.
		  This is since when service termination order is given by SCM then it recieves WM_QUIT. Please refer the example code shown below.

		Reference
		- argc,argv can be acquired from CNTService::Instance(). And other various options can be acquired from CNTService::Instance().

		Example source
		\code
			while(1)
			{
				Sleep(100);
				if(_kbhit())
				{
					switch(getch())
					{
					case VK_ESCAPE:
						break;
					}
				}

				MSG msg;
				// Waits for one of console input, Windows message reception, mina thread termination for max shcedule and short time.
				MsgWaitForMultipleObjects(0,0,TRUE,100,QS_ALLEVENTS);
				if(PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
				{
					if(!GetMessage(&msg,NULL,NULL,NULL))
						break;
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
		\endcode

		\~chinese
		Ü×?Ù¼?ñ«ùŞ?¡£
		ó®ùŞ?ãÀù¬Ü×?Ù¼?û¼Ğ£îÜñ«ùŞ?¡£é©èÙó®ùŞ?û¼Ğ£Ü×?Ğïïïßíñ«routine¡£
		ó®ùŞ?Ú÷üŞîÜ?ı¦Ü×??ò­¡£

		é©Ï´ŞÀ?
		- î¤ó®ùŞ??İ»ù±?é©?ìıéÄkey?ìıîÜ?ò­ûäíºWin32ãáãÓïïßíroutine¡£
		ì×??SCMâ¥ÓğÜ×??ò­Ù¤ÖµîÜ?ı¦?â¥ÓğWM_QUIT¡£??ÍÅì¤ù»ÖÇÓÛ?¡£

		?ÍÅ
		- argc,argv Òö? CNTService::Instance()%?Ôğ¡£ó®èâÒö? CNTService::Instance()%?ÔğÊÀ???¡£

		ÖÇsource
		\code
			while(1)
			{
				Sleep(100);
				if(_kbhit())
				{
					switch(getch())
					{
					case VK_ESCAPE:
						break;
					}
				}

				MSG msg;
				// õÌÓŞìéïÒÓ­???£¬ÔõÓâconsole?ìı¡¢windowãáãÓîÜïÈâ¥¡¢ñ«é©?ïï?ò­ñéîÜìé?¡£
				MsgWaitForMultipleObjects(0,0,TRUE,100,QS_ALLEVENTS);
				if(PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
				{
					if(!GetMessage(&msg,NULL,NULL,NULL))
						break;
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
		\endcode

		\~japanese
		-	«µ?«Ó«¹«â«¸«å?«ë«á«¤«ó??
		ª³ªÎ??ªÏ«µ?«Ó«¹«â«¸«å?«ëªËªèªêû¼ªÓõóªµªìªë«á«¤«ó??ªÇª¹¡£ª³ªÎ??ªË«µ?«Ğ?«×«í«°«é«à«á«¤«ó«ë?«Á«óª¬û¼ªÓõóªµªìªëù±é©ª¬ª¢ªêªŞª¹¡£
		ª³ªÎ??ª¬«ê«¿?«óª¹ªëãÁ¡¢«µ?«Ó«¹ª¬ğûÖõª·ªŞª¹¡£

		é©Ï´ŞÀú£
		- ª³ªÎ??ªÎ?İ»ªË«­?ìıÕôªËªèªëğûÖõ¡¢ªŞª¿ªÏWin32«á«Ã«»?«¸«×«í«»«¹«ë?«Á«óª¬ù±ªºìıªìªÆª¯ªÀªµª¤¡£
		ù¼ÍºªÊªéSCMªËªèªê«µ?«Ó«¹ğûÖõÙ¤Öµª¬?ª¨ªéªìªëíŞùêWM_QUITªòáôãáª¹ªëª«ªéªÇª¹¡£ì¤ù»ªÎ«³?«ÉÖÇªòª´?ÍÅª¯ªÀªµª¤¡£

		?ÍÅ
		- argc,argvªÏCNTService::Instance()ª«ªéÔğªéªìªŞª¹¡£ª½ªÎöâªËCNTService::Instance() ª«ªé??ªÊ«ª«×«·«ç«óªòÔğªéªìªŞª¹¡£

		«½?«¹ÖÇ
		\code
			while(1)
			{
				Sleep(100);
				if(_kbhit())
				{
					switch(getch())
					{
					case VK_ESCAPE:
						break;
					}
				}

				MSG msg;
				// õÌÓŞìíïïÓ­ª¤ãÁÊàªÎÊà¡¢«³«ó«½?«ëìıÕô¡¢«¦«£«ó«É?«á«Ã«»?«¸áôãá¡¢«á«¤«ó«¹«ì«Ã«ÉğûÖõñéìéªÄªòÓâªÁªŞª¹¡£
				MsgWaitForMultipleObjects(0,0,TRUE,100,QS_ALLEVENTS);
				if(PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
				{
					if(!GetMessage(&msg,NULL,NULL,NULL))
						break;
					TranslateMessage(&msg);
					DispatchMessage(&msg);
				}
			}
		\endcode
		*/
		virtual void Run() = 0;

		virtual void Stop() = 0;

		virtual void Pause() = 0;

		virtual void Continue() = 0;
	};

	class CNTServiceInternal;

	/**
	\~korean
	Windows ¼­ºñ½º (daemon) ¸ğµâ Å¬·¡½º
	- CNTService ´Â singleton ÀÌ´Ù. ±×³É Instance()·Î Á¢±ÙÇÏ¸é µÈ´Ù.

	ÀÏ¹İÀû ¿ë¹ı
	- ::WinMain ÀÌ³ª ::main()¿¡¼­ WinMain()À» È£ÃâÇÑ´Ù. ÆÄ¶ó¸ŞÅÍ´Â ::WinMain ÀÌ³ª ::main()¿¡¼­ ¹ŞÀº °ÍÀ» ³Ñ±â¸é µÈ´Ù.
	ÀÌ¶§ ¹Ì¸® ÁØºñÇÑ INTServiceEvent °´Ã¼¸¦ attachÇØ¾ß ÇÑ´Ù.
	- IsInstalled(), IsStartedBySCM() µîÀ» ÅëÇØ ¼­ºñ½º ½ÇÇà¿¡ °ü·ÃµÈ ¿©·¯°¡Áö ¼³Á¤ »óÅÂ¸¦ ¾òÀ» ¼ö ÀÖ´Ù.

	ÇÁ·Î±×·¥ ½ÇÇà ÆÄ¶ó¸ŞÅÍ
	- -AR : SCM¿¡ µî·Ï ½Ã ÀÌ ¿É¼ÇÀ» Ãß°¡ÇÏ¸é ¼­ºñ½º°¡ Å©·¡½¬ ½Ã ¸îºĞ ÈÄ¿¡ ÀÚµ¿ ½ÃÀÛÇÏ°Ô ÇÑ´Ù. Æí¸®ÇÑ ±â´ÉÀÌÁö¸¸
	µğ¹ö±ëÁßÀÌ¶ó¸é ¿ÀÈ÷·Á Â¥ÁõÀ» À¯¹ßÇÔ¿¡ ÁÖÀÇ.
	- -install : SCM¿¡ µî·ÏÇÑ´Ù.
	- -uninstall : SCM¿¡¼­ µî·Ï ÇØÁ¦ÇÑ´Ù.
	- -console : ÀÌ ¿É¼ÇÀº ¼­ºñ½º¸¦ ÀÏ¹İ EXE ÇüÅÂ·Î ½ÇÇàÇÏ°Ô ÇÑ´Ù. µğ¹ö±ëÀ» ÇØ¾ß ÇÏ´Â »óÈ² µî
	SCM¿¡¼­ÀÇ ½ÇÇàÀ» ¿øÇÏÁö ¾Ê´Â °æ¿ì ÀÌ ¿É¼ÇÀ» ½á¾ß ÇÑ´Ù.

	\~english
	 Windows service (daemon) module class
	- CNTService is Singleton. It can be accessed by Instance().

	General usage
	- Calls WinMain() either from ::WinMain or ::main(). Can pass parameters from ::WinMain or ::main().
	  At this time, the previously prepared INTServiceEvent obkect must be attached.
	- Various setting status related to service execution can be acquired through IsInstalled(), IsStartedBySCM() and others.

	Program execution parameter
	- -AR : If this option is added when registered to SCM, servive will auto-start after facing a crash. A handy function but can cause major irritation while debugging.
	- -install : Registers at SCM
	- -uninstall : Withdraws from SCM
	- -console : This option allows service to run as a general EXE form. When not wanted running it at SCM, you must use this option.

	\~chinese
	WindowsÜ×?£¨daemon£©Ù¼??¡£
	- CNTService%ãÀsingleton¡£ö¦éÄInstance()?ïÈ?Ê¦¡£

	ìéÚõŞÅéÄÛ°Ûö
	- î¤::WinMain ûäíº ::main()û¼Ğ£WinMain()¡£?î¤::WinMain ûäíº ::main()ïÈâ¥îÜ???Ê¦¡£
	??é©attachŞÀà»ñ×?îÜINTServiceEvent?ßÚ¡£
	- ÷×?IsInstalled(), IsStartedBySCM()Ê¦ì¤?ÔğÜ×??ú¼ßÓ????öÇ??¡£

	ïïßí?ú¼??
	- èÙ-AR : SCMÔô??ôÕÊ¥ó®??îÜ?£¬Ü×?crash??İÂ?ı¨?í»??ã·¡£?æÔãÀ?øµ××îÜÍíÒö£¬åıÍıãÀ??ñéîÜ?Ú÷üŞ???ÒÁ¡£
	- -install : Ôô?ÓğSCM¡£
	- -uninstall : î¤SCMú°ğ¶Ôô?¡£
	- -console : ó®??÷êÜ×??ú¼?ìéÚõEXEû¡ãÒ¡£ÜôßÌî¤SCMñé?ú¼îÜ?é©ŞÅéÄó®??¡£

	\~japanese
	Windows «µ?«Ó«¹ (daemon) «â«¸«å?«ë«¯«é«¹
	- CNTService ªÏ singleton ªÇª¹¡£Instance()ªÇïÈĞÎª¹ªìªĞÕŞª¤ªÇª¹¡£

	ìéÚõîÜéÄÛö
	- ::WinMainªä ::main()ª«ªé WinMain()ªòû¼ªÓõóª·ªŞª¹¡£«Ñ«é«á?«¿ªÏ ::WinMain ªä ::main()ª«ªéá®ªÃª¿ªÎªòÔ¤ª»ªĞÕŞª¤ªÇª¹¡£
	ª³ªÎãÁ¡¢?ªËéÄëòª·ª¿ INTServiceEvent «ª«Ö«¸«§«¯«Èªò attachª¹ªëù±é©ª¬ª¢ªêªŞª¹¡£
	- IsInstalled(), IsStartedBySCM() ªÊªÉªò÷×ª¸ªÆ«µ?«Ó«¹?ú¼ªË?Ö§ªµªìª¿??ªÊàâïÒ?÷¾ªòÔğªéªìªŞª¹¡£

	«×«í«°«é«à?ú¼«Ñ«é«á?«¿
	- -AR : SCMªËÔô?ãÁ¡¢ª³ªÎ«ª«×«·«ç«óªòõÚÊ¥ª¹ªëªÈ«µ?«Ó«¹ª¬«¯«é«Ã«·«å?ªµªìª¿ù¼İÂı­ªËí»ÔÑ«¹«¿?«Èª·ªŞª¹¡£øµ××ªÊÑ¦ÒöªÇª¹ª¬
	«Ç«Ğ«Ã«®«ó«°ñéªÊªéªàª·ªíÜÙª¬Ø¡ªÄª«ªâò±ªêªŞª»ªó¡£
	- -install : SCMªËÔô?ª¹ªë¡£
	- -uninstall : SCMª«ªéÔô?ú°ğ¶ª¹ªë¡£
	- -console : ª³ªÎ«ª«×«·«ç«óªÏ«µ?«Ó«¹ªòìéÚõEXEû¡÷¾ªÇ?ú¼ª¹ªëªèª¦ªËª·ªŞª¹¡£«Ç«Ğ«Ã«®«ó«°ªòª¹ªëù±é©ª¬ª¢ªë«·«Á«å«¨?«·«ç«óªÊªÉ
	SCMªÇªÎ?ú¼ªòØĞªŞªÊª¤íŞùê¡¢ª³ªÎ«ª«×«·«ç«óªòŞÅéÄª¹ªëù±é©ª¬ª¢ªêªŞª¹¡£
	*/
	class CNTService: public CSingleton<CNTService>
	{
		CNTServiceInternal* m_internal;

		static void WINAPI _ServiceMain(DWORD dwArgc, PNTCHAR** lpszArgv);

		void SetServiceStatus(uint32_t dwState);
		void Run();
		void ServiceMain(int argc, PNTCHAR* argv[]);
		void Handler(uint32_t dwOpcode);
		static void WINAPI _Handler(DWORD dwOpcode);

		void WinMain_ActualService();
		void WinMain_Console();

		BOOL Install(CServiceParameter &param);
		BOOL Uninstall();

		void WinMain_Internal(CNTServiceStartParameter &param);
		void Log(int type, const PNTCHAR* fmt, ...);

	public:

		CNTService(void);
		~CNTService(void);

		/*
		\~korean
		winmainÀÌ³ª main¿¡¼­ º¸³»ÁØ ½ÇÇà ÆÄ¶ó¸ŞÅÍ¸¦ ¾ò´Â´Ù.

		\~english
		Gets execution parameter either from winmain or main

		\~chinese
		?Ôğ?winmainûäíºmain?áêîÜ?ú¼??¡£
		\~japanese
		winmainªä mainª«ªéáêªéªìª¿?ú¼«Ñ«é«á?«¿ªòÔğªŞª¹¡£
		*/
		void GetArgv_Internal(CFastArray<String>& output);


		/*
		\~korean
		winmainÀÌ³ª main¿¡¼­ º¸³»ÁØ ½ÇÇà ÆÄ¶ó¸ŞÅÍ¸¦ ¾ò´Â´Ù.

		\~english
		Gets execution parameter either from winmain or main

		\~chinese
		?Ôğ?winmainûäíºmain?áêîÜ?ú¼??¡£
		\~japanese
		winmainªämainª«ªéáêªéªìª¿?ú¼«Ñ«é«á?«¿ªòÔğªŞª¹¡£
		*/
		void GetEnvp_Internal(CFastArray<String>& output);

		/*
		\~korean
		SCM¿¡¼­ º¸³»ÁØ ½ÇÇà ÆÄ¶ó¸ŞÅÍ¸¦ ¾ò´Â´Ù.

		\~english
		Gets execution parameter from SCM

		\~chinese
		?Ôğ?SCM?áêîÜ?ú¼??¡£

		\~japanese
		SCMª«ªéáêªéªìª¿?ú¼«Ñ«é«á?«¿ªòÔğªŞª¹¡£
		*/
		void GetArgvFromSCM_Internal(CFastArray<String>& output);

		/**
		\~korean
		INTServiceEvent ¿¡¼­ ¾òÀº ÀÌ¸§À» ¸®ÅÏÇÑ´Ù.

		\~english
		Returns the name acquired from INTServiceEvent

		\~chinese
		Ú÷üŞINTServiceEvent?ÔğîÜÙ£í®¡£

		\~japanese
		INTServiceEventª«ªéÔğªéªìª¿Ù£ªò«ê«¿?«óª·ªŞª¹¡£
		*/
		const PNTCHAR* GetName();

		/**
		\~korean
		SCM¿¡ ÀÇÇØ ½ÇÇàµÈ »óÅÂÀÎ°¡?

		\~english
		Is it run by SCM?

		\~chinese
		ãÀù¬SCM?ú¼îÜ???£¿

		\~japanese
		SCMªËªèªê?ú¼ªµªìª¿?÷¾ª«£¿
		*/
		bool IsStartedBySCM() const;

		bool FindArg(const PNTCHAR* name);
		String CreateArg();
		BOOL IsInstalled();

		/**
		\~korean
		¼­ºñ½º ¸ğµâ ¸ŞÀÎ ÇÔ¼ö. main()ÀÌ³ª ::WinMain()¿¡¼­ ÀÌ ¸Ş¼­µå¸¦ È£ÃâÇØ¾ß ÇÑ´Ù. ´ÙÀ½ ±â´ÉÀ» ´ã´çÇÑ´Ù.
		- ½ÇÇà ÆÄ¶ó¸ŞÅÍ Ã³¸®: ¼­ºñ½º µî·Ï/ÇØÁ¦, ÄÜ¼Ö ¸ğµå ½ÇÇà µî
		- ÀÌº¥Æ® ½ÌÅ© °´Ã¼ °¡Á®¿À±â
		- ¼­ºñ½º ¸ŞÀÎ ÇÔ¼ö(INTServiceEvent.Run()) ½ÇÇà
		\param argc main()¿¡¼­ ¹ŞÀº °ª
		\param argv main()¿¡¼­ ¹ŞÀº °ª
		\param envp main()¿¡¼­ ¹ŞÀº °ª
		\param param CNTServiceÀÇ ¼³Á¤ °ª

		\~english
		This method must be called either by service mudule main function main() or ::WinMain(). Manages followings.
		- Execution parameter handling: service register/withdraw, running console more and so on.
		- Getting event sink object
		- Running service main function(INTServiceEvent.Run())
		\param argc value received from main()
		\param argv value received from main()
		\param envp value received from main()
		\param param Setting Value of CNTService

		\~chinese
		Ü×?Ù¼?ñ«ùŞ?¡£î¤main()ûäíº ::WinMain()û¼Ğ£ó®ùŞ?¡£?ìòì¤ù»ÍíÒö¡£
		- ?ú¼???×â£ºÜ×?Ôô?/ú°ğ¶¡¢console Ù¼ãÒ?ú¼Ôõ¡£
		- ?Ôğevent sink?ßÚ¡£
		- Ü×?ñ«ùŞ?(INTServiceEvent.Run())?ú¼¡£
		\param argc î¤main()ïÈâ¥îÜ?¡£
		\param argv î¤main()ïÈâ¥îÜ?¡£
		\param envp î¤main()ïÈâ¥îÜ?¡£
		\param param CNTServiceîÜ?ïÒ?

		\~japanese
		«µ?«Ó«¹«â«¸«å?«ë«á«¤«ó??. main()ªä ::WinMain()ª«ªéª³ªÎ«á«Ã«½«Éªòû¼ªÓõóª¹ù±é©ª¬ª¢ªêªŞª¹¡£ó­ªÎÑ¦Òöªò??ª·ªŞª¹¡£
		- ?ú¼«Ñ«é«á?«¿?×â: «µ?«Ó«¹Ôô?/ú°ğ¶¡¢«³«ó«½?«ë«â?«É?ú¼ªÊªÉ
		- «¤«Ù«ó«È«·«ó«¯«ª«Ö«¸«§«¯«Èò¥ªÃªÆª¯ªë
		- «µ?«Ó«¹«á«¤«ó??(INTServiceEvent.Run())?ú¼
		\param argc main()ª«ªéá®ªÃª¿ö·
		\param argv main()ª«ªéá®ªÃª¿ö·
		\param envp main()ª«ªéá®ªÃª¿ö·
		\param param CNTServiceªÎàâïÒö·
		*/
		static void WinMain(int argc, char* argv[], char* envp[], CNTServiceStartParameter &param);

		/**
		\~korean
		¼­ºñ½º ¸ğµâ ¸ŞÀÎ ÇÔ¼ö. main()ÀÌ³ª ::WinMain()¿¡¼­ ÀÌ ¸Ş¼­µå¸¦ È£ÃâÇØ¾ß ÇÑ´Ù. ´ÙÀ½ ±â´ÉÀ» ´ã´çÇÑ´Ù.
		- ½ÇÇà ÆÄ¶ó¸ŞÅÍ Ã³¸®: ¼­ºñ½º µî·Ï/ÇØÁ¦, ÄÜ¼Ö ¸ğµå ½ÇÇà µî
		- ÀÌº¥Æ® ½ÌÅ© °´Ã¼ °¡Á®¿À±â
		- ¼­ºñ½º ¸ŞÀÎ ÇÔ¼ö(INTServiceEvent.Run()) ½ÇÇà
		\param argc main()¿¡¼­ ¹ŞÀº °ª
		\param argv main()¿¡¼­ ¹ŞÀº °ª
		\param envp main()¿¡¼­ ¹ŞÀº °ª
		\param param CNTServiceÀÇ ¼³Á¤ °ª

		\~english
		Service module main function. Must be called either by ::WinMain()main() or ::WinMain(). Manages followings.
		- Execution parameter handling: service register/withdraw, running console more and so on.
		- Getting event sink object
		- Running service main function(INTServiceEvent.Run())
		\param argc value received from main()
		\param argv value received from main()
		\param envp value received from main()
		\param param Setting Value of CNTService

		\~chinese
		Ü×?Ù¼?ñ«ùŞ?¡£î¤main()ûäíº ::WinMain()û¼Ğ£ó®ùŞ?¡£?ìòìéù»ÍíÒö¡£
		- ?ú¼???×â£ºÜ×?Ôô?/ú°ğ¶¡¢console Ù¼ãÒ?ú¼Ôõ¡£
		- ?Ôğevent sink?ßÚ¡£
		- Ü×?ñ«ùŞ?(INTServiceEvent.Run())?ú¼¡£
		\param argc î¤main()ïÈâ¥îÜ?¡£
		\param argv î¤main()ïÈâ¥îÜ?¡£
		\param envp î¤main()ïÈâ¥îÜ?¡£
		\param param CNTServiceîÜ?ïÒ?

		\~japanese
		«µ?«Ó«¹«â«¸«å?«ë«á«¤«ó??. main()ªä ::WinMain()ª«ªéª³ªÎ«á«Ã«½«Éªòû¼ªÓõóª¹ù±é©ª¬ª¢ªêªŞª¹¡£ó­ªÎÑ¦Òöªò??ª·ªŞª¹¡£
		- ?ú¼«Ñ«é«á?«¿?×â: «µ?«Ó«¹Ôô?/ú°ğ¶¡¢«³«ó«½?«ë«â?«É?ú¼ªÊªÉ
		- «¤«Ù«ó«È«·«ó«¯«ª«Ö«¸«§«¯«Èò¥ªÃªÆª¯ªë
		- «µ?«Ó«¹«á«¤«ó??(INTServiceEvent.Run())?ú¼
		\param argc main()ª«ªéá®ªÃª¿ö·
		\param argv main()ª«ªéá®ªÃª¿ö·
		\param envp main()ª«ªéá®ªÃª¿ö·
		\param param CNTServiceªÎàâïÒö·
		*/
		static void WinMain(int argc, wchar_t* argv[], wchar_t* envp[], CNTServiceStartParameter &param);

		void FrequentWarning(const PNTCHAR* text);
		void FrequentWarningWithCallStack(const PNTCHAR* text);


	public:
		/*
		\~korean
		winmainÀÌ³ª main¿¡¼­ º¸³»ÁØ ½ÇÇà ÆÄ¶ó¸ŞÅÍ¸¦ ¾ò´Â´Ù.

		\~english
		Gets execution parameter either from winmain or main

		\~chinese
		?Ôğ?winmainûäíºmain?áêîÜ?ú¼??¡£
		\~japanese
		winmainªämainª«ªéáêªéªìª¿?ú¼«Ñ«é«á?«¿ªòÔğªŞª¹¡£
		*/
		static void GetArgv(CFastArray<String>& output);

		/*
		\~korean
		winmainÀÌ³ª main¿¡¼­ º¸³»ÁØ ½ÇÇà ÆÄ¶ó¸ŞÅÍ¸¦ ¾ò´Â´Ù.

		\~english
		Gets execution parameter either from winmain or main

		\~chinese
		?Ôğ?winmainûäíºmain?áêîÜ?ú¼??¡£
		\~japanese
		winmainªämainª«ªéáêªéªìª¿?ú¼«Ñ«é«á?«¿ªòÔğªŞª¹¡£
		*/
		static void GetEnvp(CFastArray<String>& output);

		/*
		\~korean
		SCM¿¡¼­ º¸³»ÁØ ½ÇÇà ÆÄ¶ó¸ŞÅÍ¸¦ ¾ò´Â´Ù.

		\~english
		Gets execution parameter from SCM

		\~chinese
		?Ôğ?SCM?áêîÜ?ú¼??¡£

		\~japanese
		SCMª«ªéáêªéªìª¿?ú¼«Ñ«é«á?«¿ªòÔğªŞª¹¡£
		*/
		static void GetArgvFromSCM(CFastArray<String>& output);
	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
