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

#include "BasicTypes.h"
#include "FakeClr.h"
#include "Enums.h"
#include "IRmiHost.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	class RmiContext;
	class CNetCoreImpl;
	class CMessage;
	class MessageSummary;

	/** 
	\~korean
	PIDL ÄÄÆÄÀÏ·¯°¡ »ı¼ºÇÑ Proxy Å¬·¡½ºÀÇ º£ÀÌ½º Å¬·¡½º

	ÁÖÀÇ »çÇ×
	- ÀÌ Å¬·¡½º¸¦ À¯Àú°¡ Á÷Á¢ ±¸ÇöÇÏÁö ¸» °Í. PIDL ÄÄÆÄÀÏ·¯¿¡¼­ ±¸ÇöÇÑ °ÍÀ» ¾²µµ·Ï ÇØ¾ß ÇÑ´Ù.

	\~english
	Base class of Proxy class created by PIDL compiler

	Note
	- User must not create this class. Must be realized by PIDL compiler.

	\~chinese
	PIDL??Ğïßæà÷îÜProxy?îÜĞñÜâ?¡£

	ñ¼ëòŞÀßÚ
	- éÄ?Üôé©òÁïÈ??ó®?¡£î¤PIDL??Ğïé©ŞÅéÄ??îÜ?à¤¡£

	\~japanese
	PIDL«³«ó«Ñ«¤«é?ª¬ßæà÷ª·ª¿Proxy«¯«é«¹ªÎ«Ù?«¹«¯«é«¹

	ª´ñ¼ëòŞÀú£
	- ª³ªÎ«¯«é«¹ªò«æ?«¶?ª¬òÁïÈ?úŞª·ªÊª¤ª³ªÈ¡£PIDL«³«ó«Ñ«¤«é?ªËªèªÃªÆ?úŞª·ª¿ªâªÎªòŞÅª¦ªèª¦ªËª·ªŞª¹¡£
	\~
	*/
	class IRmiProxy
	{
	public:
		IRmiHost* m_core;
		bool m_internalUse; // trueÀÌ¸é ProudNet Àü¿ë. »ç¿ëÀÚ´Â °ÇµéÁö ¸»°Í
		int m_signature;

		/** 
		\~korean
		true·Î ¼¼ÆÃÇÏ¸é NotifySendByProxy À» È£Ãâ¹ŞÀ» ¼ö ÀÖ´Ù.
		- true·Î ¼³Á¤ÇÏ¸é ½ÇÇà ¼º´ÉÀÌ Á¶±İ ¶³¾îÁø´Ù. ÇÏÁö¸¸ ÀÌ ¼º´É Â÷ÀÌµµ ¾Æ±î¿î »óÈ²ÀÌ¶ó¸é ÀÌ °ªÀ» false·Î ¼³Á¤ÇØÁÖ¸é µÈ´Ù.
		- ±âº»°ªÀº trueÀÌ´Ù.

		\~english
		If set as true then NotifySendByProxy can be called
		- When set as true, it lowers process performance  by a little. But, if you cannot afford to hasve the loss then set this as false.
		- Default is true.

		\~chinese
		?öÇ?trueîÜ?Ê¦ì¤û¼Ğ£NotifySendByProxy¡£
		- ?öÇ?trueîÜ??ú¼àõÒö?õªÚ°ù»Ë½¡£Ó£?ó®àõÒöñıó¬ÊïÓğÜôøµîÜ?£¬÷êó®??öÇ?false?Ê¦¡£
		- Ùù??ãÀtrue¡£

		\~japanese
		trueªÇàâïÒª¹ªëªÈNotifySendByProxyªòû¼ªÓõóª·ªÆªâªéª¨ªŞª¹¡£
		- trueªÇàâïÒª¹ªëªÈ?ú¼àõÒöª¬á´ª·ÕªªÁªŞª¹¡£ª·ª«ª·¡¢ª³ªÎàõÒöó¬ªâªâªÃª¿ª¤ªÊª¤?üÏªÊªéª³ªÎö·ªòfalseªËàâïÒª·ªÆª¯ªÀªµª¤¡£
		- ĞñÜâö·ªÏtureªÇª¹¡£
		\~
		*/
		bool m_enableNotifySendByProxy;

		/** 
		\~korean
		»ç¿ëÀÚ´Â ÀÌ ÇÔ¼ö¸¦ ¿À¹ö¶óÀÌµåÇÏÁö ¸¶½Ê½Ã¿À.

		\~english
		User must not override this function.

		\~chinese
		éÄ?Üôé©ÜİËÌó®ùŞ?¡£

		\~japanese
		«æ?«¶?ªÏª³ªÎ??ªò«ª?«Ğ?«é«¤«Éª·ªÊª¤ªÇª¯ªÀªµª¤¡£
		\~
		*/
		virtual RmiID* GetRmiIDList() = 0;
		/** 
		\~korean
		»ç¿ëÀÚ´Â ÀÌ ÇÔ¼ö¸¦ ¿À¹ö¶óÀÌµåÇÏÁö ¸¶½Ê½Ã¿À.

		\~english
		User must not override this function.

		\~chinese
		éÄ?Üôé©ÜİËÌó®ùŞ?¡£

		\~japanese
		-«æ?«¶?ªÏª³ªÎ??ªò«ª?«Ğ?«é«¤«Éª·ªÊª¤ªÇª¯ªÀªµª¤¡£
		\~
		*/
		virtual int GetRmiIDListCount() = 0;
	
		/** 
		\~korean
		¸Ş½ÃÁö ¼Û½ÅÀ» À§ÇØ RMI¸¦ È£ÃâÇÒ ¶§(Áï proxy¿¡¼­ È£ÃâÇÏ±â)¸¶´Ù ÀÌ ÇÔ¼ö°¡ callbackµË´Ï´Ù.
		ÇÁ·ÎÇÊ·¯³ª RMI »ç¿ë ·Î±×¸¦ ³²±â°íÀÚ ÇÒ ¶§ ÀÌ ÇÔ¼ö¸¦ »ç¿ëÇÏ½Ã¸é µË´Ï´Ù. ÀÚ¼¼ÇÑ ³»¿ëÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#monitor_rmi_proxy" >¼Û½ÅÃø(Proxy) È£Ãâ ½ÃÁ¡À» Á¢±ÙÇÏ±â</a> ¸¦ Âü°íÇÏ½Ê½Ã¿À.
		- ¼ö½ÅÀÚ°¡ ¿©·µÀÎ °æ¿ì ¿©·¯¹ø È£ÃâµË´Ï´Ù. 
		- ±âº» ÇÔ¼ö´Â ¾Æ¹«°Íµµ ÇÏÁö ¾Ê½À´Ï´Ù.
		
		¶ÇÇÑ ¼Û½Å Á÷Àü¿¡ RmiContext ¸¦ ÃÖÁ¾ ¼öÁ¤ÇÒ ¼ö ÀÖ´Â ±âÈ¸¸¦ Á¦°øÇÕ´Ï´Ù. 
		(±âÈ¸¸¦ ÁÖ´Â ÀÌÀ¯: ¼Û½Å½Ã Àß¸øµÈ °ªÀÌ ÀÖÀ¸¸é °æ°í¿Í ÇÔ²² ÃÖÁ¾ ¼öÁ¤À» À§ÇÔÀÔ´Ï´Ù.
		¿ÀÇÂº£Å¸½ÃÁ¡¿¡¼­´Â ¹®Á¦ ºĞ¼®°ú ÇØ°áÀ» µ¿½Ã¿¡ ÇØ¾ß ÇÏ´Ï±î¿ä. )
		\param sendTo ¼ö½ÅÀÚ
		\param summary º¸³»´Â RMI ¸Ş½ÃÁöÀÇ ¿ä¾à Á¤º¸
		\param rmiContext »ç¿ëÀÚ°¡ È£ÃâÇÑ RmiContext °ªÀÔ´Ï´Ù.

		\~english
		This function is called back every time RMI is called for message send(e.g. calling from proxy).
		This function is used when there is a need to leave porfiler or RMI use log. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#monitor_rmi_proxy" >Approaching Transmission (Proxy) call</a>.
		- Multiple reciever cause multiple calling.
		- Base function does not do anything. 
		
		Plus, this provides a cance to finally modify RmiContext before sending.
		(Why the last chance is given: for the case there is an incorrect value and to notify, warn and modify finally. During OBT, we need to do prob analysis and solving at the same time.)
		\param sendTo reciever
		\param summary gist of RMI message to be sent
		\param rmiContext RmiContext value called by user

		\~chinese
		?ÖõãáãÓîÜ?áê£¬Øß?û¼Ğ£RMIîÜ?ı¦(?î¤proxyû¼Ğ£)£¬ó®ùŞ??callback¡£
		ßÌí¥profilerûäíºRMIŞÅéÄlogîÜ?Ê¦ì¤ŞÅéÄó®ùŞ?¡£???é»??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#monitor_rmi_proxy" >áêãáÛ°(Proxy) ïÈĞÎû¼õóã·ïÃ</a>%¡£
		- â¥ãáíºãÀ??ìÑîÜ?ı¦û¼Ğ£?ó­¡£
		- ĞñÜâùŞ?Üôñ®ìòù¼ŞÀï×¡£

		ì»ó¦î¤?áêñıîñğ«ÍêõÌ?áóËÇRmiContextîÜÏõ?¡£
		£¨?Ïõ?îÜ×âë¦£º?Öõ?áê?åıÍıêó???£¬é©?ÌíÍ±ìéÑÃõÌ?áóËÇ¡£î¤Íë??é©ÔÒ??ú¼??İÂà°ûúú°?£©
		\param sendTo â¥ãáíº¡£
		\param summary ?áêîÜRMIãáãÓîÜ?é©ãáãÓ¡£
		\param rmiContext éÄ?û¼Ğ£îÜRmiContext?¡£

		\~japanese
		«á«Ã«»?«¸áêãáªÎª¿ªáªËRMIªòû¼ªÓõóª¹ãÁ£¨?ªÁ¡¢proxyªÇû¼ªÓõóª¹£©ª´ªÈªËª³ªÎ??ª¬callbackªµªìªŞª¹¡£
		«×«í«Õ«£?«é?ªÈª«RMIŞÅéÄ«í«°ªò?ª·ª¿ª¤ãÁ¡¢ª³ªÎ??ªòŞÅªÃªÆª¯ªÀªµª¤¡£ßÙª·ª¯ªÏ¡¢\ref monitor_rmi_proxyªòª´?ğÎª¯ªÀªµª¤¡£
		- áôãáíºª¬ÜÜ?ªÇª¢ªëíŞùêªÏÜÜ?üŞû¼ªÓõóªµªìªŞª¹¡£
		- ĞñÜâ??ªÏù¼ªâª·ªŞª»ªó¡£

		ªŞª¿¡¢áêãáªÎòÁîñªËRmiContextªòõÌğûáóïáª¹ªëÑ¦?ªòğ«Íêª·ªŞª¹¡£
		£¨Ñ¦?ªò?ª¨ªë×âë¦£ºáêãáãÁªËÊàêŞªÃª¿ö·ª¬ª¢ªìªĞÌíÍ±ªÈªÈªâªËõÌğûáóïáªÎª¿ªáªÇª¹¡£
		«ª?«×«ó«Ù«¿?ãÁïÃªÇªÏÙığ¹İÂà°ªÈú°Ì½ªòÔÒãÁªËª·ªÊª±ªìªĞªÊªêªŞª»ªóª«ªé£©
		\param sendTo áôãáíº
		\param summary áêªëRMI«á«Ã«»?«¸ªÎé©å³ï×ÜÃ
		\param rmiContext «æ?«¶?ª¬û¼ªÓõóª·ª¿RmiContext ö·ªÇª¹¡£
		\~
		*/
		PROUD_API virtual void NotifySendByProxy(const HostID* remotes, int remoteCount, const MessageSummary &summary, RmiContext &rmiContext, const CMessage &msg);
		
		/** 	
		\~korean
		³»ºÎ ÇÔ¼öÀÔ´Ï´Ù. »ç¿ëÀÚ´Â ÀÌ ÇÔ¼ö¸¦ ¿À¹ö¶óÀÌµåÇÏÁö ¸¶½Ê½Ã¿À. 
		ProudClr ¿¡¼­ ¿À¹ö¶óÀÌµåÇÏ±âÀ§ÇØ public À¸·Î ÇØ¾ßÇÔ

		\~english
		User must not override this function.
		Must be public in order to override at ProudClr 

		\~chinese
		?İ»ùŞ?¡£éÄ?Üôé©ÜİËÌó®ùŞ?¡£
		î¤ProudClr£¬?ÖõÜİËÌé©public¡£

		\~japanese
		?İ»??ªÇª¹¡£«æ?«¶?ªÏª³ªÎ??ªò«ª?«Ğ?«é«¤«Éª·ªÊª¤ªÇª¯ªÀªµª¤¡£
		ProudClrªÇ«ª?«Ğ?«é«¤«Éª¹ªëª¿ªáªËªÏpublicªËª·ªÆª¯ªÀªµª¤¡£
		\~
		*/
		PROUD_API virtual bool RmiSend(const HostID* remotes, int remoteCount, RmiContext &rmiContext, const CMessage &msg, const PNTCHAR* RMIName, RmiID RMIId);

		PROUD_API IRmiProxy();
		PROUD_API virtual ~IRmiProxy();
	};

	extern const PNTCHAR* ProxyBadSignatureErrorText;

	/**  @} */
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
