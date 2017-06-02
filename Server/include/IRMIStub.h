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

#include "Enums.h"
#include "FakeClr.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	class CNetCoreImpl;
	class CReceivedMessage;
	class IRmiHost;
	class BeforeRmiSummary;
	class AfterRmiSummary;

	/** 
	\~korean
	PIDL ÄÄÆÄÀÏ·¯°¡ »ı¼ºÇÑ Stub Å¬·¡½ºÀÇ º£ÀÌ½º Å¬·¡½º

	ÁÖÀÇ »çÇ×
	- ÀÌ Å¬·¡½º¸¦ À¯Àú°¡ Á÷Á¢ ±¸ÇöÇÏÁö ¸» °Í. PIDL ÄÄÆÄÀÏ·¯¿¡¼­ ±¸ÇöÇÑ °ÍÀ» ¾²µµ·Ï ÇØ¾ß ÇÑ´Ù.

	\~english
	Base class of Stub class created by PIDL compiler

	Note
	- User must not create this class. Must be realized by PIDL compiler.

	\~chinese
	PIDL??Ğïßæà÷îÜStub?îÜĞñÜâ?¡£

	ñ¼ëòŞÀßÚ
	- éÄ?Üôé©òÁïÈ??ó®?¡£î¤PIDL??Ğïé©ŞÅéÄ??îÜ?à¤¡£

	\~japanese
	PIDL«³«ó«Ñ«¤«é?ª¬ßæà÷ª·ª¿Stub«¯«é«¹ªÎ«Ù?«¹«¯«é«¹

	ª´ñ¼ëòŞÀú£
	- ª³ªÎ«¯«é«¹ªò«æ?«¶?ª¬òÁïÈ?úŞª·ªÊª¤ª³ªÈ¡£PIDL«³«ó«Ñ«¤«é?ªÇ?úŞª·ª¿ªâªÎªòŞÅª¦ªèª¦ªËª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
	\~
	*/
	class IRmiStub
	{
	public:
		IRmiHost *m_core;
		bool m_internalUse; // trueÀÌ¸é ProudNet Àü¿ë. »ç¿ëÀÚ´Â °ÇµéÁö ¸»°Í

		/** 
		\~korean
		true·Î ¼¼ÆÃÇÏ¸é NotifyCallFromStub À» È£Ãâ¹ŞÀ» ¼ö ÀÖ´Ù.
		±×·¯³ª, ±× ´ñ°¡·Î ½ÇÇà ¼Óµµ°¡ ÇöÀúÈ÷ ¶³¾îÁø´Ù. µğ¹ö±ëÀ» ÇÒ ¶§¸¸ ÄÑ´Â
		°ÍÀ» ±ÇÀåÇÑ´Ù.

		\~english
		If set as true then calls NotifyCallFromStub.
		But in return, process speed will be lowered significantly. It is recommended to use this when debugging.

		\~chinese
		?öÇ?trueîÜ?Ê¦ì¤û¼Ğ£NotifyCallFromStub¡£
		Ó£?ú¼áÜÓø?Ù¥?ù»Ë½¡£Ëï?ñşî¤??îÜ?ı¦öè?¡£

		\~japanese
		trueªËàâïÒª¹ªëªÈNotifyCallFromStubªòû¼ªÓõóª·ªÆªâªéª¦ª³ªÈª¬ªÇª­ªŞª¹¡£
		ª·ª«ª·¡¢ª½ªÎ??ªÇ?ú¼áÜÓøª¬îÊª·ª¯ÕªªÁªŞª¹¡£«Ç«Ğ«Ã«®«ó«°ªòª¹ªëãÁªÎªßªÄª±ªëª³ªÈªòªª?ªáª·ªŞª¹¡£
		\~
		*/
		bool m_enableNotifyCallFromStub;

		/** 
		\~korean
		true·Î ¼³Á¤ÇÏ¸é BeforeRmiInvocation,AfterRmiInvocation ¸¦ Äİ¹éÇÑ´Ù.
		±×·¯³ª ±× ´ñ°¡·Î ½ÇÇà ¼Óµµ°¡ ¾à°£ ¶³¾îÁø´Ù. ¼º´É ÃÖÀûÈ­¸¦ À§ÇØ RMI ÇÔ¼ö Á¾·ùº° ½ÇÇà
		½Ã°£À» Ã¼Å©ÇÒ ¶§¸¸ ÄÑ´Â °ÍÀ» ±ÇÀåÇÑ´Ù.

		\~english
		If set as true then BeforeRmiInvocation and AfterRmiInvocation are called back.
		But in return, process speed will be lowered a little. It is recommended to use this when checking running time of RMI function of each type.

		\~chinese
		?öÇ?trueîÜ?üŞ?BeforeRmiInvocation,AfterRmiInvocation¡£
		Ó£?ú¼áÜÓø?Ù¥?ù»Ë½¡£?ÖõàõÒöîÜ?ûù£¬Ëï?ñşî¤??RMIùŞ????ú¼??îÜ?ı¦öè?¡£

		\~japanese
		trueªËàâïÒª¹ªëªÈ¡¢BeforeRmiInvocation,AfterRmiInvocationªò«³?«ë«Ğ«Ã«¯ª·ªŞª¹¡£
		ª·ª«ª·¡¢ª½ªÎ??ªÇ?ú¼áÜÓøª¬á´ª·ÕªªÁªŞª¹¡£àõÒöªÎõÌîêûùªÎª¿ªáªËRMI??ªÎğú×¾Ü¬?ú¼ãÁÊàªò«Á«§«Ã«¯ª¹ªëãÁªÎªßªÄª±ªëª³ªÈªòªª?ªáª·ªŞª¹¡£
		\~
		*/
		bool m_enableStubProfiling;

		/** 
		\~korean
		ÀÌ ÇÔ¼ö¸¦ ±¸ÇöÇÏÁö ¸» °Í. PIDL ÄÄÆÄÀÏ·¯ÀÇ °á°ú¹°ÀÌ overrideÇÑ´Ù.

		\~english
		DO NOT realize this function. The outcome of PIDL compiler will override.

		\~chinese
		Üôé©??ó®ùŞ?¡£PIDL ??ĞïîÜ?Úª?override¡£

		\~japanese
		ª³ªÎ??ªò?úŞª·ªÊª¤ª³ªÈ¡£PIDL«³«ó«Ñ«¤«é?ªÎÌ¿ÍıÚªª¬«ª?«Ğ?«é«¤«ÉªµªìªŞª¹¡£
		\~
		*/
		virtual RmiID* GetRmiIDList() = 0;
		/** 
		\~korean
		ÀÌ ÇÔ¼ö¸¦ ±¸ÇöÇÏÁö ¸» °Í. PIDL ÄÄÆÄÀÏ·¯ÀÇ °á°ú¹°ÀÌ overrideÇÑ´Ù.

		\~english
		DO NOT realize this function. The outcome of PIDL compiler will override.

		\~chinese
		Üôé©??ó®ùŞ?¡£PIDL ??ĞïîÜ?Úª?override¡£

		\~japanese
		ª³ªÎ??ªò?úŞª·ªÊª¤ª³ªÈ¡£PIDL«³«ó«Ñ«¤«é?ªÎÌ¿ÍıÚªª¬«ª?«Ğ?«é«¤«ÉªµªìªŞª¹¡£
		\~
		*/
		virtual int GetRmiIDListCount() = 0;
		/** 
		\~korean
		ÀÌ ÇÔ¼ö¸¦ ±¸ÇöÇÏÁö ¸» °Í. PIDL ÄÄÆÄÀÏ·¯ÀÇ °á°ú¹°ÀÌ overrideÇÑ´Ù.

		\~english
		DO NOT realize this function. The outcome of PIDL compiler will override.

		\~chinese
		Üôé©??ó®ùŞ?¡£PIDL ??ĞïîÜ?Úª?override¡£

		\~japanese
		ª³ªÎ??ªò?úŞª·ªÊª¤ª³ªÈ¡£PIDL«³«ó«Ñ«¤«é?ªÎÌ¿ÍıÚªª¬«ª?«Ğ?«é«¤«ÉªµªìªŞª¹¡£
		\~
		*/
		virtual bool ProcessReceivedMessage(CReceivedMessage& pa, void* hostTag) = 0;
		/** 
		\~korean
		RMI°¡ ½ÇÇàµÈ Á÷ÈÄ È£ÃâµÈ´Ù.
		AfterRmiInvocation.m_rmiNameÀº USE_RMI_NAME_STRINGÀ» defineÇØ¾ß ¹®ÀÚ¿­ÀÌ µîÀåÇÕ´Ï´Ù.

		\~english
		Called right after RMI is run
		In AfterRmiInvocation.m_rmiName's case, a character string appears after you define USE_RMI_NAME_STRING.

		\~chinese
		RMI?ú¼ı¨Ø¡?ù¬û¼Ğ£¡£
		AfterRmiSummary.m_rmiNameâÍé©USE_RMI_NAME_STRINGïÒ?ı¨õó?í®İ¬Íú.

		\~japanese
		RMIª¬?ú¼ªµªìª¿ı­ªËû¼ªÓõóªµªìªŞª¹¡£
		AfterRmiInvocation.m_rmiNameªÏUSE_RMI_NAME_STRINGªòdefineª·ª¿ªéÙşí®ª¬ªÇªŞª¹¡£

		\~
		*/
		virtual void AfterRmiInvocation(const AfterRmiSummary& summary);
		/** 
		\~korean
		RMI°¡ ½ÇÇàµÇ±â Á÷Àü¿¡ È£ÃâµÈ´Ù.
		BeforeRmiSummary.m_rmiNameÀº USE_RMI_NAME_STRINGÀ» defineÇØ¾ß ¹®ÀÚ¿­ÀÌ µîÀåÇÕ´Ï´Ù.

		\~english
		Called right after RMI is run
		In BeforeRmiSummary.m_rmiName's case, a character string appears after you define USE_RMI_NAME_STRING.

		\~chinese
		RMI?ú¼ñıîñù¬û¼Ğ£¡£
		BeforeRmiSummary.m_rmiNameâÍé©USE_RMI_NAME_STRINGïÒ?ı¨õó?í®İ¬Íú.

		\~japanese
		RMIª¬?ú¼ªµªìªëîñªËû¼ªÓõóªµªìªŞª¹¡£
		BeforeRmiSummary.m_rmiNameªÏUSE_RMI_NAME_STRINGªòdefineª·ª¿ªéÙşí®ª¬ªÇªŞª¹¡£

		\~
		*/
		virtual void BeforeRmiInvocation(const BeforeRmiSummary& summary);

		/** 
		\~korean
		À¯Àú°¡ ÀÌ ÇÔ¼ö¸¦ overrideÇÏ¸é, RMI°¡ ½ÇÇàµÇ¸é¼­ ¹ŞÀº ÆÄ¶ó¸ŞÅÍ¸¦ ¹®ÀÚ¿­·Î ¸ğµÎ Ç¥½ÃÇÒ ¼ö ÀÖ°Ô ÇØÁØ´Ù.
		´Ü, ¼º´ÉÀÌ ¸Å¿ì ¶³¾îÁö°Ô µÇ¹Ç·Î ÁÖÀÇÇØ¼­ ¾²µµ·Ï ÇÏÀÚ.

		\~english
		If user override this function then it lets parameter received from RMI be displayed as text string.
		But in return, process speed will be lowered significantly so be careful when you use this.

		\~chinese
		éÄ?overrideó®ùŞ?îÜ?£¬Ê¦ì¤÷êRMI?ú¼îÜ?ı¦ïÈâ¥îÜá¶êó???ãÆ?í®İ¬Íú¡£
		Ó£ãÀ£¬àõÒö?ù»Ë½£¬á¶ì¤ŞÅéÄ?é©ñ¼ëò¡£

		\~japanese
		«æ?«¶?ª¬ª³ªÎ??ªò«ª?«Ğ?«é«¤«Éª¹ªìªĞ¡¢RMIª¬?ú¼ªµªìªÊª¬ªéáôª±ª¿«Ñ«é«á?«¿?ªòÙşí®ÖªªÇîïªÆøúãÆªÇª­ªëªèª¦ªËª·ªŞª¹¡£
		Ó£ª·¡¢àõÒöª¬ŞªßÈªËÕªªÁªëªèª¦ªËªÊªëªÎªÇñ¼ëòª·ªÆŞÅªÃªÆª¯ªÀªµª¤¡£
		\~
		*/
		virtual void NotifyCallFromStub(HostID remote, RmiID RMIId, String methodName, String parameters);

		PROUD_API void ShowUnknownHostIDWarning(HostID remoteHostID);

		PROUD_API IRmiStub();
		PROUD_API virtual ~IRmiStub();
	};

	extern const PNTCHAR* DecryptFailedError;

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
