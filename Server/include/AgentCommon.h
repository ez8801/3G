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

#include "ProudNetServer.h"
#include "ProudNetClient.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif


	/**
	\~korean
	ÀÏÁ¤ ½Ã°£ È¤Àº OnReportStatsCommand °¡ ¿ÔÀ»¶§ Agent ·Î º¸°íÇÒ Report Å¬·¡½º
	- »ç¿ëÀÚ°¡ ÀÓÀÇ·Î °ªÀ» ³Ö¾î¼­ »ç¿ëÇÒ¼ö ÀÖ½À´Ï´Ù.
	- ¿©±â¼­ ÀÔ·ÂÇÑ °ªÀº PNServerAgentConsole ¿¡¼­ È®ÀÎ°¡´ÉÇÕ´Ï´Ù.

	\~english TODO:translate needed.
	The report class to report with Agent after a certain amount of time or when OnReportStatsCommand has come. 
	- Users can input values randomly to use
	- The value input here can be identified in PNServerAgentConsole


	\~chinese
	ìéïÒîÜ??ûäíºOnReportStatsCommandîÜ?ı¦éÄAgent?Í±îÜReport?¡£
	- ŞÅéÄíºÊ¦ì¤?ìıìòëò?ŞÅéÄ¡£
	- î¤?×ì?ìıîÜ?î¤PNServerAgentConsoleÊ¦ì¤??¡£

	\~japanese
	á¶ïÒãÁÊàªŞª¿ªÏOnReportStatsCommandª¬?ª¿ãÁ¡¢AgentªËÜÃÍ±ª¹ªëReport«¯«é«¹
	- «æ?«¶?ª¬ìòëòªËö·ªòìıªìªÆŞÅª¦ª³ªÈª¬ªÇª­ªŞª¹¡£
	- ª³ª³ªÇìıÕôª·ª¿ö·ªÏPNServerAgentConsoleªÇü¬ìãªÇª­ªŞª¹¡£
	\~
	*/
	class CReportStatus
	{
	public:
		/** 
		\~korean
		ÀÌ°ª¿¡ µû¶ó¼­ PNLicenseAgentConsole ¿¡¼­ ±ÛÀÚ»öÀÌ ´Ş¶óÁı´Ï´Ù. 

		\~english TODO:translate needed.
		Depending on this value, the color of the letters change in PNLicenseAgentConsole


		\~chinese
		?ó·ó®?£¬î¤PNLicenseAgentConsoleîÜí®??ßä?ËÇ?¡£

		\~japanese
		ª³ªÎö·ªËªèªÃªÆ¡¢ PNLicenseAgentConsoleªÇÙşí®ßäª¬êŞªÃªÆª­ªŞª¹¡£
		\~
		*/
		enum StatusType { StatusType_OK, StatusType_Warning, StatusType_Error };

		/** 
		\~korean
		AgentConsole ·Î º¸³¾ Á¤º¸ÀÇ Å¸ÀÔ

		\~english TODO:translate needed.
		Type of the information to be sent to AgentConsole


		\~chinese
		èÙAgentConsole?áêãáãÓîÜ?úş¡£

		\~japanese
		AgentConsole ªËáêªëï×ÜÃªÎ«¿«¤«×
		\~
		*/
		StatusType m_statusType;

		/** 
		\~korean
		Á¤º¸ÀÇ ³»¿ë. ÀÌ StringÀÌ ºñ¸é  Data¸¦ º¸³»Áö ¾Ê½À´Ï´Ù.

		\~english TODO:translate needed.
		Content of the information. If this string is empty, data is not transmitted


		\~chinese
		ãáãÓîÜ?é»¡£åıÍıó®StringÍöîÜ?Üô?áêData¡£

		\~japanese
		ï×ÜÃªÎ?é»¡£ª³ªÎStringª¬Íöª¯ªÈ«Ç?«¿ªòáêªêªŞª»ªó¡£
		\~
		*/
		String m_statusText;
		
		typedef CFastMap<String, String> KeyValueList;
		
		/**
		\~korean
		Ãß°¡ÀûÀ¸·Î ÇÊ¿äÇÑ DataµéÀÇ Á¤º¸ List
		- AgentConsoleÀÇ property ViewÀÇ Log¸¦ ÅëÇÏ¿© È®ÀÎÇÏ½Ç ¼ö ÀÖ½À´Ï´Ù.
		- AgentConsoleÀÇ property View¿¡¼­ Key : Value·Î Ãâ·ÂµË´Ï´Ù.

		\~english TODO:translate needed.
		List List of the data needed additionally
		- You can check with the log of the property view of AgentConsole.
		- It is output as Key : Value of the property view of AgentConsole.


		\~chinese
		?èââÍé©îÜDataãáãÓList¡£
		-AgentConsole îÜpropertyÊ¦ì¤÷×?View LogÊ¦ì¤??.
		-AgentConsole îÜpropertyî¤Key : Value?õó.

		\~japanese
		õÚÊ¥îÜªËù±é©ªÊ«Ç?«¿ï×ÜÃ«ê«¹«È
		- AgentConsoleªÎproperty ViewªÎLogªò÷×ª¸ü¬ìãª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£.
		- AgentConsoleªÎproperty ViewªÇKey : ValueªÇõóÕôªµªìªŞª¹¡£
		\~
		*/
		KeyValueList m_list;
	};

	/**
	\~korean
	CAgentConnector °¡ ¿ä±¸ÇÏ´Â delegate ÀÎÅÍÆäÀÌ½º. CAgentConnector ¸¦ »ı¼ºÇÒ ¶§ ÀÎÀÚ·Î ÇÊ¿äÇÏ´Ù.

	\~english TODO:translate needed.
	The delegate interface required by CAgentConnector. It is required as a factor when generating CAgentConnector


	\~chinese
	CAgentConnector âÍé©îÜdelegateÍ£Øü¡£íÂ?ì×í­£¬ßæà÷ CAgentConnector%îÜ?ı¦âÍé©¡£

	\~japanese
	CAgentConnectorª¬é©Ï´ª¹ªëdelegate«¤«ó«¿?«Õ«§?«¹¡£CAgentConnectorªòßæà÷ª¹ªëãÁªËì×í­ªÈª·ªÆù±é©ªÇª¹¡£
	\~
	*/
	class IAgentConnectorDelegate
	{
	public:
		/** 
		\~korean
		Agent connectÀÇ ÀÎÁõÀÌ ¼º°øµÈ °æ¿ì callbackµË´Ï´Ù.

		\~english TODO:translate needed.
		It is called back when Agent connect¡¯s authentication is successful


		\~chinese
		Agent connect îÜ??à÷Íí??callback¡£

		\~japanese
		Agent connectªÎìã?ªËà÷Ííª·ª¿íŞùê¡¢callbackªµªìªŞª¹¡£
		\~
		*/
		virtual void OnAuthentication(ErrorInfo* errorinfo) = 0;

		/** 
		\~korean
		Server appÀ» Á¾·á½ÃÅ°¶ó´Â ¸í·ÉÀÌ ¿Â°æ¿ì callbackµË´Ï´Ù.

		\~english TODO:translate needed.
		It is called back when the command to terminate the server app is received


		\~chinese
		ïÈÓğ?áÖServer appîÜÙ¤Öµ??callback¡£

		\~japanese
		Server appªòğûÖõªµª»ªíªÈª¤ª¦Ù¤Öµª¬?ª¿íŞùê¡¢callbackªµªìªŞª¹¡£
		\~
		*/
		virtual void OnStopCommand() = 0;

		/**
		\~korean
		Agent Server ·ÎºÎÅÍ Report ¿äÃ» ¸í·ÉÀÌ ¿Â°æ¿ì callbackµË´Ï´Ù.

		\~english TODO:translate needed.
		It is called back when the report request command has come from the agent server


		\~chinese
		?Agent ServerïÈÓğReporté­?Ù¤Öµ??callback¡£

		\~japanese
		Agent Serverª«ªéReport«ê«¯«¨«¹«ÈÙ¤Öµª¬?ª¿íŞùê¡¢callbackªµªìªŞª¹¡£
		\~
		*/
		virtual void OnReportStatsCommand() = 0;

		/** 
		\~korean
		Agent¸¦ »ç¿ëÀÚ°¡ Àß¸øµÈ ¹æ¹ıÀ¸·Î »ç¿ëÇÏ¿´À» ½Ã¿¡ È£ÃâµË´Ï´Ù.

		\~english TODO:translate needed.
		It is called when the agent is used in a wrong way by the user


		\~chinese
		éÄ?ì¤??îÜÛ°ÛöŞÅéÄAgentîÜ?ı¦û¼õó¡£

		\~japanese
		Agentªò«æ?«¶?ª¬ÊàêŞªÃª¿Û°ÛöªÇŞÅªÃª¿ãÁªËû¼ªÓõóªµªìªŞª¹¡£
		\~
		*/
		virtual void OnWarning(ErrorInfo* errorinfo) = 0;
	};

	/**
	\~korean
	Agent¿Í ¿¬°áÇÏ¿© PNServerAgentConsole ¿¡¼­ »ç¿ëÀÚÀÇ ¼­¹ö¾ÛÀ» ¿ø°İÀ¸·Î °ü¸®ÇÒ¼ö ÀÖ½À´Ï´Ù.

	\~english TODO:translate needed.
	By connecting with Agent, the server app of the user can be controlled remotely from PNServerAgentConsole


	\~chinese
	?ïÈAgentì¤ı¨î¤PNServerAgentConsoleÊ¦ì¤?ïïÎ·×âéÄ?îÜserver app¡£

	\~japanese
	AgentªÈÖ§Ì¿ª·ªÆPNServerAgentConsoleªÇ«æ?«¶?ªÎ«µ?«Ğ?«¢«×«êªò«ê«â?«ÈªÇÎ·×âª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
	\~
	*/
	class CAgentConnector
	{
	public:
		virtual ~CAgentConnector() {}

		PROUD_API static CAgentConnector* Create(IAgentConnectorDelegate* dg);

		/** 
		\~korean
		Start ÈÄ °´Ã¼¸¦ »èÁ¦ÇÏ±â Àü±îÁö Agent¿Í °è¼Ó ¿¬°áÀ» À¯ÁöÇÕ´Ï´Ù.
		- ServerAgent¿¡ ÀÇÇÏ¿© ½ÇÇà µÈ °ÍÀÌ ¾Æ´Ñ °æ¿ì StartµÇÁö ¾Ê½À´Ï´Ù.

		\~english TODO:translate needed.
		Before deleting an object after start, it maintains connection with the agent continuously
		- It does not start if it is not executed by ServerAgent


		\~chinese
		Start ì¤ı¨£¬÷ê?ßÚ?ğ¶ñıîñ????ò¥?AgentîÜ?ïÈ¡£
		- ÜôãÀù¬ServerAgent?ú¼îÜï×?ÜôStart¡£

		\~japanese
		Startı­ªË«ª«Ö«¸«§«¯«ÈªòŞûğ¶ª¹ªëîñªŞªÇAgentªÈ?ª±ªÆÖ§Ì¿ªòë«ò¥ª·ªŞª¹¡£
		- ServerAgentªËªèªÃªÆ?ú¼ªµªìª¿ªÎªÇªÏªÊª¤íŞùêªÏStartªµªìªŞª»ªó¡£
		\~
		*/
		virtual bool Start() = 0;

		/**
		\~korean
		ÀÏÁ¤ ½Ã°£ È¤Àº IAgentConnectorDelegate::OnReportStatsCommand °¡ ¿ÔÀ»¶§ ÀÌ ÇÔ¼ö¸¦ ÀÌ¿ëÇÏ¿© CReportStatus ¸¦ Agent·Î º¸³¾¼ö ÀÖ½À´Ï´Ù.
		\return ServerAgent¿¡ ÀÇÇÏ¿© ½ÇÇàµÇÁö ¾Ê¾Æ Start µÇÁö ¾Ê¾Ò°Å³ª reportStatusÀÇ Data°¡ Àß¸øµÇ¾úÀ» ½Ã¿¡ false 

		\~english TODO:translate needed.
		When a certain time or IAgentConnectorDelegate::OnReportStatsCommand has come, CReportStatus can be sent to the agent using this function
		- False when it has not started because it is not executed by \return ServerAgent or when the data of reportStatus is wrong


		\~chinese
		ìéïÒ??ûäíºIAgentConnectorDelegate::OnReportStatsCommand îÜ?ı¦£¬××éÄó®ùŞ?Ê¦ì¤÷ê CReportStatus%?áêÓğAgent¡£
		\return ?êóù¬ServerAgent?ú¼ì»?êóStartîÜûäíºreportStatusîÜDataõó?îÜ?ı¦fals¡£

		\~japanese
		á¶ïÒãÁÊàªŞª¿ªÏIAgentConnectorDelegate::OnReportStatsCommandª¬?ª¿ãÁ¡¢ª³ªÎ??ªò××éÄª·ªÆCReportStatusªòAgentªËáêªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\return ServerAgentªËªèªÃªÆ?ú¼ªµªìªºStartªµªìªÊª«ªÃª¿ªÈª«¡¢reportStatusªÎDataª¬ÊàêŞªÃªÆª¤ªëãÁªËfalse 
		\~
		*/
		virtual bool SendReportStatus(CReportStatus& reportStatus) = 0;

		/** 
		\~korean
		Agent·Î Log¸¦ º¸³»´Â ±â´É 
		- »ó¼¼ÇÑ µ¥ÀÌÅÍ°¡ ¾Æ´Ñ °£´ÜÇÑ ·Î±×¸¦ º¸³»°íÀÚ ÇÒ ¶§ SendReportStatus¸¦ »ç¿ëÇÏÁö ¾Ê°í EventLog¸¦ ÅëÇÏ¿© °£ÆíÀÌ ÀÌ¿ëÇÏ½Ç ¼ö ÀÖ½À´Ï´Ù.
		\return text°¡ ºñ¾ú°Å³ª ServerAgent°¡ StartµÇÁö ¸øÇÏ¿´À» ¶§ false

		\~english TODO:translate needed.
		Feature to send a log to Agent
		- When you wish to send a simple log instead of detailed data, you can conveniently use through an EventLog instead of using SendReportStatus. 
		\False when \return text is empty or ServerAgent does not start


		\~chinese
		÷êLog?áêÓğAgentîÜÍíÒö
		- ßÌ?áêÜôãÀ???Ëßì»ãÀ??logîÜ?ı¦£¬ÜôéÄSendReportStatus£¬ì»ãÀÊ¦ì¤÷×?EventLog??××éÄ¡£
		\return textÍöó·ûäíºServerAgent?StartîÜ?ı¦false¡£

		\~japanese
		AgentªËLogªòáêªëÑ¦Òö
		- ßÙª·ª¤«Ç?«¿ªÇªÏªÊª¤ÊÛ?ªÊ«í«°ªòáêªêª¿ª¤ãÁ¡¢SendReportStatusªòŞÅªïªÊª¯EventLogªò÷×ª¸ÊÛ?ªËª´××éÄªÇª­ªŞª¹¡£
		\return textª¬Íöª¤ªÆª¤ªëª«¡¢ServerAgentª¬StartªµªìªÊª«ªÃª¿ãÁªËfalse
		\~
		*/
		virtual bool EventLog(CReportStatus::StatusType logType, const PNTCHAR* text) = 0;

		/**
		\~korean
		ÀÏÁ¤ ½Ã°£¿¡ ÇÑ¹ø¾¿ ÇØÁÖ¾î¾ß ÇÏ´Â ÀÏµéÀ» Ã³¸®ÇÕ´Ï´Ù.
		- ¿¬°áÀÌ µÇ¾î ÀÖÁö ¾Ê´Ù¸é ÀÏÁ¤ ½Ã°£¸¶´Ù ÀÚµ¿À¸·Î ¿¬°áÀ» ½Ãµµ ÇÕ´Ï´Ù.

		\~english TODO:translate needed.
		It processes tasks that need to be done every once in a certain period of time.
		- If not connected, it attempts connection automatically every certain time.


		\~chinese
		?×âî¤ìéïÒ??Øß?ú¼ìéó­îÜŞÀï×¡£
		- ?êó?ïÈîÜ??ØßìéïÒ??í»????ïÈ¡£

		\~japanese
		á¶ïÒãÁÊàªË1üŞªºªÄú¼ª¦ªÙª­ª³ªÈªò?×âª·ªŞª¹¡£
		- Ö§Ì¿ªµªìªÊª«ªÃª¿ªéá¶ïÒãÁÊàª´ªÈªËí»ÔÑªËÖ§Ì¿ªòãËªßªŞª¹¡£
		*/
		virtual void FrameMove() = 0;

		/**
		\~korean
		FrameMove ³»ÀÇ ½Ç½Ã°£ »óÅÂ Á¤º¸ Àü¼Û¿¡ ´ëÇÑ Delay TimeÀ» Á¤ÇÕ´Ï´Ù. 
		- 1/1000ÃÊ ´ÜÀ§ÀÔ´Ï´Ù. 
		- default ´Â 1000ÀÔ´Ï´Ù.

		\~english TODO:translate needed.
		It sets the delay time for transmitting the real-time information transmission within FrameMove
		- It is in 1/1000 second unit
		- The default is 1000


		\~chinese
		?ïÒ?FrameMove?îÜ????ãáãÓ?áêîÜDelay Time¡£
		- ãÀ1/1000õ©?êÈ¡£ 
		- defaultãÀ1000¡£


		\~japanese
		FrameMove?ªÎ«ê«¢«ë«¿«¤«à?÷¾ï×ÜÃªÎ?áêªË?ª¹ªëDelay TimeªòÌ½ªáªŞª¹¡£
		- 1/1000õ©?êÈªÇª¹¡£
		- defaultªÏ1000ªÇª¹¡£
		\~
		*/
		virtual void SetDelayTimeAboutSendAgentStatus(uint32_t delay) = 0;

	};


#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif