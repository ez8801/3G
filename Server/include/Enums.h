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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup net_group
	*  @{
	*/

	// ÁÖÀÇ: ÀÌ°Íµµ ¹Ù²Ù¸é ProudClr namespaceÀÇ µ¿¸í ½Éº¼µµ ¼öÁ¤ÇØ¾ß ÇÑ´Ù.


	/**
	\~korean
	¸Ş½ÃÁö ¼Û½Å ¿ì¼±¼øÀ§
	- <a target="_blank" href="http://guide.nettention.com/cpp_ko#message_priority" >¸Ş½ÃÁö ¼Û½Å ¿ì¼±¼øÀ§ ±â´É</a> Âü°í.

	\~english 
	Message transmission priority.
	Refer to \ref message_priority.

	\~chinese
	ãáãÓ?áê?à»?ßí¡£
	- ?ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#message_priority" >ãáãÓ?áêîÜ?à»?ßíÍíÒö¡£</a>%¡£

	\~japanese
	«á«Ã«»?«¸áêãá«×«é«¤«ª«ê«Æ«£
	- \ref message_priority ?ÍÅ 
	\~
	*/
	enum MessagePriority
	{
	// Most priority. Ping, for example. ProudNet internal. Do not use it.
		MessagePriority_Ring0 = 0,

	// ProudNet internal. Do not use it.
		MessagePriority_Ring1,

		/**
		\~korean
		³ôÀº ¿ì¼±¼øÀ§

		\~english 
		High priority

		\~chinese
		ÍÔîÜ?à»?ßí¡£

		\~japanese
		ÍÔª¤«×«é«¤«ª«ê«Æ«£
		\~
		*/
		MessagePriority_High,

		/**
		\~korean
		º¸Åë ¿ì¼±¼øÀ§. °¡Àå ¸¹ÀÌ »ç¿ëµÊ.

		\~english 
		Medium priority. Used most frequently

		\~chinese
		ìéÚõ?à»?ßí¡£éÄîÜõÌÒı¡£

		\~japanese
		ÜÅ÷×ªÎ«×«é«¤«ª«ê«Æ«£¡£ìéÛãÒıª¯ŞÅªïªìªŞª¹¡£
		\~
		*/
		MessagePriority_Medium,

		/**
		\~korean
		³·Àº ¿ì¼±¼øÀ§

		\~english 
		Low priority

		\~chinese
		î¸îÜ?à»?ßí¡£

		\~japanese
		î¸ª¤«×«é«¤«ª«ê«Æ«£
		\~
		*/
		MessagePriority_Low,

// Lowest priority. For ProudNet internal use.
		MessagePriority_Ring99,

		// For internal use. Do not use this.
		MessagePriority_LAST,
	};

	// È¦ÆİÄª ÆĞÅ¶Àº ¸¹À» ¼ö ÀÖ´Ù. ÀÌ°ÍÀÌ Æ®·¡ÇÈÀ» ¹æÇØÇÏ¸é ¾ÈµÇ¹Ç·Î ¿ì¼±¼øÀ§¸¦ ÃÖÇÏÀ§·Î µĞ´Ù.
	static const MessagePriority MessagePriority_Holepunch = MessagePriority_Ring99;

	// ÁÖÀÇ: ÀÌ°Íµµ ¹Ù²Ù¸é ProudClr namespaceÀÇ µ¿¸í ½Éº¼µµ ¼öÁ¤ÇØ¾ß ÇÑ´Ù.

	enum MessageReliability
	{
		MessageReliability_Unreliable = 0,
		MessageReliability_Reliable,
		MessageReliability_LAST,
	};

	// ÁÖÀÇ: ÀÌ°Íµµ ¹Ù²Ù¸é ProudClr namespaceÀÇ µ¿¸í ½Éº¼µµ ¼öÁ¤ÇØ¾ß ÇÑ´Ù.

	/**
	\~korean
	¿¡·¯ Å¸ÀÔ ÄÚµå

	\~english 
	Error type code.

	\~chinese
	???úşÓÛ?¡£

	\~japanese
	«¨«é?«¿«¤«×«³?«É.
	\~
	*/
	enum ErrorType
	{
		/**
		\~korean
		¼º°ø. ¹®Á¦ ¾øÀ½.

		\~english 
		Success. No problem

		\~chinese
		à÷Íí¡£?êó??¡£

		\~japanese
		à÷Íí¡£Ùığ¹ªÊª·
		\~
		*/
		ErrorType_Ok = 0,

		/**
		\~korean
		¿¹¿Ü »óÈ² ¹ß»ı

		\~english 
		Exception occurred

		\~chinese
		?ßæÖÇèâï×?¡£

		\~japanese
		ÖÇèâ?üÏ?ßæ
		\~
		*/
		ErrorType_Unexpected,

		/**
		\~korean
		ÀÌ¹Ì ¿¬°áµÇ¾î ÀÖÀ½

		\~english 
		Already connected

		\~chinese
		ì«?ãÀ?ïÈ??
		\~japanese
		?ªËïÈ?ªµªìªÆª¤ªŞª¹¡£
		\~
		*/
		ErrorType_AlreadyConnected,

		/**
		\~korean
		TCP ¿¬°á ½ÇÆĞ

		\~english 
		TCP connection failed

		\~chinese
		TCP ?ïÈã÷?¡£

		\~japanese
		TCPïÈ?ã÷ø¨
		\~
		*/
		ErrorType_TCPConnectFailure,

		/**
		\~korean
		Àß¸øµÈ ´ëÄªÅ°

		\~english 
		Wrong matching key

		\~chinese
		??îÜ??key¡£

		\~japanese
		ÊàêŞªÃª¿??«­?
		\~
		*/
		ErrorType_InvalidSessionKey,

		/**
		\~korean
		¾ÏÈ£È­°¡ ½ÇÆĞÇßÀ½

		\~english 
		Encoding failed

		\~chinese
		Ê¥ÚËã÷?¡£

		\~japanese
		äŞ?ûùª¬ã÷ø¨ª·ªŞª·ª¿¡£
		\~
		*/
		ErrorType_EncryptFail,

		/**
		\~korean
		ÇØÄ¿°¡ ±úÁø µ¥ÀÌÅÍ¸¦ Àü¼ÛÇß°Å³ª º¹È£È­°¡ ½ÇÆĞÇßÀ½

		\~english 
		Either the hacker transmitted corrupt data or decoding failed.

		\~chinese
		ıÙËÔÊ¦Òö?áêÖõ???Ëß£¬ûäíºãÀú°?ã÷?¡£

		\~japanese
		«Ï«Ã««?ª¬?ªìª¿«Ç?«¿ªò?áêª·ª¿ª«ÜÖ?ûùªËã÷ø¨ª·ªŞª·ª¿¡£
		\~
		*/
		ErrorType_DecryptFail,

		/**
		\~korean
		¼­¹ö ¿¬°á °úÁ¤ÀÌ ³Ê¹« ¿À·¡ °É·Á¼­ ½ÇÆĞ Ã³¸®µÊ

		\~english 
		Processed as failure since the server connection process took too much time.

		\~chinese
		ì×Ü×?Ğï?ïÈ????ì»ã÷?¡£

		\~japanese
		«µ?«Ğ?ïÈ?Î¦ïïª¬ªÈªÆªâª«ª«ªêÎ¦ª®ªÆã÷ø¨?×âªËªÊªêªŞª·ª¿¡£
		\~
		*/
		ErrorType_ConnectServerTimeout,

		/**
		\~korean
		¼­¹ö ¿¬°áÀ» À§ÇÑ ÇÁ·ÎÅäÄİ ¹öÀüÀÌ ´Ù¸§

		\~english 
		Protocol version for server connection is different

		\~chinese
		Ü×?Ğï?ïÈîÜ????÷úÜâÜôÔÒ¡£

		\~japanese
		«µ?«Ğ?ïÈ?ªÎª¿ªáªÎ«×«í«È«³«ë«Ğ?«¸«ç«óª¬êŞª¤ªŞª¹¡£
		\~
		*/
		ErrorType_ProtocolVersionMismatch,

		/**
		\~korean
		¼­¹ö ÂÊ ÀÎÁõ¿¡ ¹®Á¦°¡ ÀÖÀ½.

		\~english 
		Problem occured while license validation task.

		\~chinese
Problem occured while license validation task.

		\~japanese
Problem occured while license validation task.
		
		\~
		*/
		ErrorType_InvalidLicense,

		/**
		\~korean
		¼­¹ö°¡ ¿¬°áÀ» ÀÇµµÀûÀ¸·Î °ÅºÎÇßÀ½

		\~english 
		Server intentionally rejected connection

		\~chinese
		Ü×?ĞïÍºëòËŞ??ïÈ¡£

		\~japanese
		«µ?«Ğ?ª¬ïÈ?ªòëò?îÜªËËŞÜúª·ªŞª·ª¿¡£
		\~
		*/
		ErrorType_NotifyServerDeniedConnection,

		/**
		\~korean
		¼­¹ö ¿¬°á ¼º°ø!

		\~english 
		Server connection success!

		\~chinese
		Ü×?Ğï?ïÈà÷Íí£¡

		\~japanese
		«µ?«Ğ?ïÈ?à÷Íí£¡
		\~
		*/
		ErrorType_Reserved01,

		/**
		\~korean
		»ó´ëÃø È£½ºÆ®¿¡¼­ ¿¬°áÀ» ÇØÁ¦ÇßÀ½

		\~english 
		The correspondent host removed the connection

		\~chinese
		?Û°ñ«Ïõú°ğ¶Öõ?ïÈ¡£

		\~japanese
		ßÓâ¢ö°ªÎ«Û«¹«Èª¬ïÈ?ªòú°ğ¶ª·ªŞª·ª¿¡£
		\~
		*/
		ErrorType_DisconnectFromRemote,

		/**
		\~korean
		ÀÌÂÊ È£½ºÆ®¿¡¼­ ¿¬°áÀ» ÇØÁ¦ÇßÀ½

		\~english 
		Our host removed the connection

		\~chinese
		??ñ«Ïõú°ğ¶Öõ?ïÈ¡£

		\~japanese
		?ö°ªÎ«Û«¹«Èª¬ïÈ?ªòú°ğ¶ª·ªŞª·ª¿¡£
		\~
		*/
		ErrorType_DisconnectFromLocal,

		/**
		\~korean
		À§ÇèÇÑ »óÈ²À» ºÒ·¯¿Ã ¼ö ÀÖ´Â ÀÎÀÚ°¡ ÀÖÀ½

		\~english 
		There is a factor that can cause a dangerous situation

		\~chinese
		ğíî¤Ê¦ÒöìÚÑÃêË???îÜì×áÈ¡£

		\~japanese
		êË?ªÊ?üÏªòìÚª­ÑÃª³ª¹Ê¦ÒöàõªÎª¢ªëì×í­ª¬ª¢ªêªŞª¹¡£
		\~
		*/
		ErrorType_Reserved02,

		/**
		\~korean
		¾Ë ¼ö ¾ø´Â ÀÎÅÍ³İ ÁÖ¼Ò

		\~english 
		Unknown internet address

		\~chinese
		Ú±ò±îÜû»??ò¢ò£¡£

		\~japanese
		ò±ªéªìªÆª¤ªÊª¤«¤«ó«¿?«Í«Ã«È«¢«É«ì«¹
		\~
		*/
		ErrorType_UnknownAddrPort,

		/**
		\~korean
		¼­¹ö ÁØºñ ºÎÁ·

		\~english 
		Insufficient server readiness

		\~chinese
		Ü×?Ğïñ×?Üôğë¡£

		\~japanese
		«µ?«Ğ?ñŞİáÜôğë
		\~
		*/
		ErrorType_Reserved03,

		/**
		\~korean
		¼­¹ö ¼ÒÄÏÀÇ listenÀ» ½ÃÀÛÇÒ ¼ö ¾ø½À´Ï´Ù. TCP ¶Ç´Â UDP ¼ÒÄÏÀÌ ÀÌ¹Ì »ç¿ëÁßÀÎ Æ÷Æ®ÀÎÁö È®ÀÎÇÏ½Ê½Ã¿À.

		\~english
		You cannot start listen of the server socket. Please check whether either the TCP or UDP socket is a port already being used. 

		\~chinese
		ÙéÛö?ã·èÌÊ«socketîÜlistenûäíºñ×?UDP¡£???TCPûäíºUDP socketÓ®Ï¢ãÀÜúì«î¤ŞÅéÄñé?ãÀêóùÚÕáî¤Øß?processîÜsocket?Õá¡£

		\~japanese
		«µ?«Ğ?«½«±«Ã«ÈªÎlistenªòËÒã·ª¹ªëª³ªÈª¬ªÇª­ªŞª»ªó¡£TCPªŞª¿ªÏUDP«½«±«Ã«Èª¬?ªËŞÅéÄñéªÇª¢ªë«İ?«ÈªÊªÎª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£

		*/
		ErrorType_ServerPortListenFailure,

		/**
		\~korean
		ÀÌ¹Ì °³Ã¼°¡ Á¸ÀçÇÕ´Ï´Ù.

		\~english 
		Already an object exists.

		\~chinese
		?ßÚì«ğíî¤¡£

		\~japanese
		?ªËËÁ?ª¬ğíî¤ª·ªŞª¹¡£
		\~
		*/
		ErrorType_AlreadyExists,

		/**
		\~korean
		Á¢±ÙÀÌ °ÅºÎµÇ¾ú½À´Ï´Ù.
		- <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> ±â´É¿¡¼­, DB cache server°¡ ºñµ¶Á¡Àû Á¢±Ù ±â´ÉÀ» ¾²Áö ¾Ê°Ú´Ù´Â ¼³Á¤ÀÌ µÇ¾î ÀÖÀ¸¸é ¹ß»ıÇÒ ¼ö ÀÖ½À´Ï´Ù.
		- À©µµ¿ì ºñ½ºÅ¸ÀÌ»óÀÇ OS¿¡¼­ °ü¸®ÀÚ±ÇÇÑÀÌ ¾øÀÌ CNetUtil::EnableTcpOffload( bool enable ) ÇÔ¼ö°¡ È£ÃâµÇ¸é ¹ß»ıÇÒ ¼ö ÀÖ½À´Ï´Ù.

		\~english
		Access denied.
		- At <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function, it could occur if a function that DB cache server does not use exclusive access function has been set.
		- At OS over window vista, It could occur when CNetUtil::EnableTcpOffload( bool enable ) function is called without administration authority.

		\~chinese
		ïÈĞÎù¬ËŞ?¡£
		- î¤<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%ÍíÒöß¾£¬åıÍıDB cache serverù¬?öÇà÷ÜôŞÅéÄÍìú½ïÈĞÎÍíÒöîÜ?øµ??ßæó®??¡£
		- î¤window£¬vista ì¤ß¾îÜOSñé£¬?êóÎ·×â??ùÚû¼õó CNetUtil::EnableTcpOffload ( bool enable )ùŞ?îÜ?£¬Ê¦Òö??ßæó®??¡£

		\~japanese
		ïÈĞÎª¬ËŞÜúªµªìªŞª·ª¿¡£
		- <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> Ñ¦ÒöªÇ, DB cache serverª¬Şª?ï¿îÜïÈĞÎÑ¦ÒöªòŞÅéÄª·ªÊª¤ªÈàâïÒªµªìªÆª¤ªëªÈ?ßæª¹ªëÊ¦Òöàõª¬ª¢ªêªŞª¹¡£
		- Window Vistaì¤ß¾ªÎOSªÇÎ·×âíº?ùÚªÊª·ªË CNetUtil::EnableTcpOffload( bool enable ) ??ª¬û¼ªÓõóªµªìªëªÈ?ßæª¹ªëÊ¦Òöàõª¬ª¢ªêªŞª¹¡£

		\~
		*/
		ErrorType_PermissionDenied,

		/**
		\~korean
		Àß¸øµÈ session GuidÀÔ´Ï´Ù.

		\~english 
		This is a wrong session Guid

		\~chinese
		??îÜsession Guid¡£

		\~japanese
		ÊàêŞªÃª¿Session GuidªÇª¹¡£
		\~
		*/
		ErrorType_BadSessionGuid,

		/**
		\~korean
		Àß¸øµÈ credentialÀÔ´Ï´Ù.

		\~english
		This is a wrong credential.

		\~chinese
		??îÜcredential¡£

		\~japanese
		ÊàêŞªÃª¿CredentialªÇª¹¡£
		\~
		*/
		ErrorType_InvalidCredential,

		/**
		\~korean
		Àß¸øµÈ hero nameÀÔ´Ï´Ù.

		\~english 
		This is a wrong hero name.

		\~chinese
		??îÜhero name¡£

		\~japanese
		ÊàêŞªÃª¿Hero nameªÇª¹¡£
		\~
		*/
		ErrorType_InvalidHeroName,

		/**
		\~korean
		·Îµù °úÁ¤ÀÌ unlock ÈÄ lock ÇÑ ÈÄ ²¿ÀÓÀÌ ¹ß»ıÇß´Ù

		\~english 
		After the loading is locked after being unlocked, a twist occurred. 

		\~chinese
		Ê¥??ïïunlockì¤ı¨£¬lock ı¨?ßæéöó¢¡£

		\~japanese
		«í?«Ç«£«ó«°Î¦ïïª¬«¢«ó«í«Ã«¯ı­ªË«í«Ã«¯ª·¡¢ªÍª¸ªìª¬?ßæª·ªŞª·ª¿¡£
		\~
		*/
		ErrorType_Reserved06,

		/**
		\~korean
		Ãâ·Â ÆÄ¶ó¸ŞÅÍ AdjustedGamerIDNotFilled°¡ Ã¤¿öÁöÁö ¾Ê¾Ò½À´Ï´Ù.

		\~english 
		The output parameter AdjustedGamerIDNotFilled has not been filled. 

		\~chinese
		?õó??AdjustedGamerIDNotFilled?êóù¬?õö¡£

		\~japanese
		õóÕô«Ñ«é«á?«¿?ªÎAdjustedGamerIDNotFilledª¬?ª¿ªµªìªÆª¤ªŞª»ªó¡£
		\~
		*/
		ErrorType_Reserved07,

		/**
		\~korean
		ÇÃ·¹ÀÌ¾î Ä³¸¯ÅÍ°¡ Á¸ÀçÇÏÁö ¾Ê½À´Ï´Ù.

		\~english 
		The player character does not exist. 

		\~chinese
		èÌÊ«ÊÇßäÜôğíî¤¡£

		\~japanese
		«×«ì?«ä?«­«ã«é«¯«¿?ª¬ğíî¤ª·ªŞª»ªó¡£
		\~
		*/
		ErrorType_Reserved08,

		/**
		\~korean
		À¯´Ö Å×½ºÆ® ½ÇÆĞ

		\~english
		Unit test failed. 

		\~chinese
		?êª??ã÷?¡£

		\~japanese
		«æ«Ë«Ã«È«Æ«¹«Èã÷ø¨
		\~
		*/
		ErrorType_UnitTestFailed,

		/**
		\~korean
		peer-to-peer UDP Åë½ÅÀÌ ¸·Çû½À´Ï´Ù.

		\~english 
		Peer-to-peer UDP communication is blocked. 

		\~chinese
		peer-to-peer UDP ÷×ãáÓòßİ¡£

		\~japanese
		peer-to-peer UDP÷×ãáª¬ışªŞªêªŞª·ª¿¡£
		\~
		*/
		ErrorType_P2PUdpFailed,

		/**
		\~korean
		P2P reliable UDP°¡ ½ÇÆĞÇß½À´Ï´Ù.

		\~english 
		P2P reliable UDP failed. 

		\~chinese
		P2P reliable UDPã÷?¡£

		\~japanese
		P2P reliable UDPª¬ã÷ø¨ª·ªŞª·ª¿¡£
		\~
		*/
		ErrorType_ReliableUdpFailed,

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®-¼­¹ö UDP Åë½ÅÀÌ ¸·Çû½À´Ï´Ù.

		\~english 
		Client-server UDP communication is blocked. 

		\~chinese
		èÌÊ«-Ü×?ĞïîÜUDP÷×ãáÓòßİ¡£

		\~japanese
		«¯«é«¤«¢«ó«È«µ?«Ğ?UDP÷×ãáª¬ışªŞªêªŞª·ª¿¡£
		\~
		*/
		ErrorType_ServerUdpFailed,

		/**
		\~korean
		´õ ÀÌ»ó °°ÀÌ ¼Ò¼ÓµÈ P2P ±×·ìÀÌ ¾ø½À´Ï´Ù.

		\~english 
		There is no longer a P2P group that belongs together.

		\~chinese
		î¢?êóìéÔÒá¶?îÜP2P?¡£

		\~japanese
		ª³ªìì¤ß¾ìé?ªËá¶?ªµªìª¿P2P«°«ë?«×ªÏª¢ªêªŞª»ªó¡£
		\~
		*/
		ErrorType_NoP2PGroupRelation,

		/**
		\~korean
		»ç¿ëÀÚ Á¤ÀÇ ÇÔ¼ö(RMI ¼ö½Å ·çÆ¾ È¤Àº ÀÌº¥Æ® ÇÚµé·¯)¿¡¼­ exceptionÀÌ throwµÇ¾ú½À´Ï´Ù.

		\~english
		An exception is thrown in the user defined function (an RMI receiving routine or an event handler).

		\~chinese
		?éÄ?ïÒ?ùŞ?£¨RMI â¥ãáÖÇïïûäíºŞÀËìhandler£©exception ù¬throw¡£

		\~japanese
		«æ?«¶?ïÒëù??(RMIáôãá«ë?«Á«óªŞª¿ªÏ«¤«Ù«ó«È«Ï«ó«É«é?)ªÇexceptionª¬throwªµªìªŞª·ª¿¡£
		\~
		*/
		ErrorType_ExceptionFromUserFunction,

		/**
		\~korean
		»ç¿ëÀÚÀÇ ¿äÃ»¿¡ ÀÇÇÑ ½ÇÆĞÀÔ´Ï´Ù.

		\~english 
		This is a failure due to a user request.

		\~chinese
		éÄ?é­?ğãà÷îÜã÷?¡£

		\~japanese
		«æ?«¶?ªÎé©ôëªËªèªëã÷ø¨ªÇª¹¡£
		\~
		*/
		ErrorType_UserRequested,

		/**
		\~korean
		Àß¸øµÈ ÆĞÅ¶ Çü½ÄÀÔ´Ï´Ù. »ó´ëÃø È£½ºÆ®°¡ ÇØÅ·µÇ¾ú°Å³ª ¹ö±×ÀÏ ¼ö ÀÖ½À´Ï´Ù.

		\~english 
		This is a wrong packet type. Either the correspondent host is hacked or it is a bug.

		\~chinese
		??îÜ?ËßøĞû¡ãÒ¡£Ê¦ÒöãÀ?Û°ñ«Ïõù¬ıÙûäíºãÀğíî¤×©Ô×¡£

		\~japanese
		ÊàêŞªÃª¿«Ñ«±«Ã«Èû¡ãÒªÇª¹¡£ßÓâ¢ö°ªÎ«Û«¹«Èª¬«Ï«Ã«­«ó«°ªµªìª¿ª«¡¢«Ğ«°ªÇª¢ªëÊ¦Òöàõª¬ª¢ªêªŞª¹¡£
		\~
		*/
		ErrorType_InvalidPacketFormat,

		/**
		\~korean
		³Ê¹« Å« Å©±âÀÇ ¸Ş½ÃÂ¡ÀÌ ½ÃµµµÇ¾ú½À´Ï´Ù. ±â¼úÁö¿øºÎ¿¡ ¹®ÀÇÇÏ½Ê½Ã¿À. ÇÊ¿ä½Ã <a target="_blank" href="http://guide.nettention.com/cpp_ko#message_length" >Åë½Å ¸Ş½ÃÁöÀÇ Å©±â Á¦ÇÑ</a>  ¸¦ Âü°íÇÏ½Ê½Ã¿À.

		\~english 
		A messaging with too big size has been attempted. Please contact the technical support team. If necessary, refer to \ref message_length

		\~chinese
		??ŞÅéÄÖõ?ÓŞîÜmessaging¡£?íª?Ğü?ò¨êµİ»¡£ù±é©???ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#message_length" >ùÚğ¤÷×ãáãáãÓÓŞá³</a>%¡£

		\~japanese
		ª¢ªŞªêªËªâÓŞª­ª¤«µ«¤«ºªÎ«á«Ã«»?«¸«ó«°ª¬ãËªµªìªŞª·ª¿¡£Ğüâúò¨êµİ»ªŞªÇªªÙıùêª»ª¯ªÀªµª¤¡£ù±é©ªËªèªÃªÆ¡¢\ref message_lengthªòª´?ğÎª¯ªÀªµª¤¡£
		\~
		*/
		ErrorType_TooLargeMessageDetected,

		/**
		\~korean
		Unreliable ¸Ş¼¼Áö´Â encrypt ÇÒ¼ö ¾ø½À´Ï´Ù.

		\~english 
		You cannot encrypt an unreliable message. 

		\~chinese
		Unreliable ãáãÓÜôÒöencrypt¡£

		\~japanese
		Unreliable«á«Ã«»?«¸ªÏencryptªÇª­ªŞª»ªó¡£
		\~
		*/
		ErrorType_Reserved09,

		/**
		\~korean
		Á¸ÀçÇÏÁö ¾Ê´Â °ªÀÔ´Ï´Ù.

		\~english 
		This value does not exist

		\~chinese
		Üôğíî¤îÜ?¡£

		\~japanese
		ğíî¤ª·ªÊª¤ö·ªÇª¹¡£
		\~
		*/
		ErrorType_ValueNotExist,

		/**
		\~korean
		Å¸ÀÓ¾Æ¿ô ÀÔ´Ï´Ù.

		\~english 
		This is a time-out. 

		\~chinese
		õ±?¡£

		\~japanese
		«¿«¤«à«¢«¦«ÈªÇª¹¡£
		\~
		*/
		ErrorType_TimeOut,

		/**
		\~korean
		·ÎµåµÈ µ¥ÀÌÅÍ¸¦ Ã£À»¼ö ¾ø½À´Ï´Ù.

		\~english 
		The loaded data cannot be located. 

		\~chinese
		ÙéÛö?ÓğÊ¥?îÜ?Ëß¡£

		\~japanese
		«í?«Éªµªìª¿«Ç?«¿ª¬Ì¸ªÄª«ªêªŞª»ªó¡£
		\~
		*/
		ErrorType_LoadedDataNotFound,

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#send_queue_heavy" >¼Û½Å·® °ú´Ù½Ã °æ°í ¹ß»ı ±â´É</a>. ¼Û½Å queue°¡ Áö³ªÄ¡°Ô Ä¿Á³½À´Ï´Ù.

		\~english 
		<a target="_blank" href="http://guide.nettention.com/cpp_en#send_queue_heavy" >Warning function for traffic overload</a>
		\ref send_queue_heavy. Transmission queue became too big. 

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#send_queue_heavy" >áêãáÕá?Òı??ßæÌíÍ±îÜÍíÒö</a>¡£?áêqueue?ÓŞ¡£

		\~japanese
		\ref send_queue_heavy . áêãá«­«å?ª¬ª¢ªŞªêªËªâÓŞª­Î¦ª®ªÇª¹¡£ 
		\~
		*/
		ErrorType_SendQueueIsHeavy,

		/**
		\~korean
		Heartbeat°¡ Æò±ÕÀûÀ¸·Î ³Ê¹« ´À¸²

		\~english 
		The heartbeat is too slow on average. 

		\~chinese
		Heartbeat øÁĞ³÷¼Ø·¡£

		\~japanese
		Heartbeatª¬øÁĞ³îÜªËªÈªÆªâ?ª¤ªÇª¹¡£
		\~
		*/
		ErrorType_TooSlowHeartbeatWarning,

		/**
		\~korean
		¸Ş½ÃÁö ¾ĞÃàÀÌ ½ÇÆĞ ÇÏ¿´½À´Ï´Ù.

		\~english 
		The message compression has failed. 

		\~chinese
		ãáãÓ??ã÷?¡£

		\~japanese
		«á«Ã«»?«¸?õêªËã÷ø¨ª·ªŞª·ª¿¡£
		\~
		*/
		ErrorType_CompressFail,

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ® ¼ÒÄÏÀÇ listen È¤Àº UDP ÁØºñ¸¦ ÇÒ ¼ö ¾ø½À´Ï´Ù. TCP ¶Ç´Â UDP ¼ÒÄÏÀÌ ÀÌ¹Ì »ç¿ëÁßÀÎ Æ÷Æ®ÀÎÁö, ÇÁ·Î¼¼½º´ç ¼ÒÄÏ °¹¼ö Á¦ÇÑÀÌ ÀÖ´ÂÁö È®ÀÎÇÏ½Ê½Ã¿À.

		\~english
		Unable to listen client socket or prepare UDP.
		Must check if there is limitation in number of socket per process or if either TCP or UDP socket is already in use.

		\~chinese
		ÙéÛö?ã·èÌÊ«socketîÜlistenûäíºñ×?UDP¡£???TCPûäíºUDP socketÓ®Ï¢ãÀÜúì«î¤ŞÅéÄñé?ãÀêóùÚÕáî¤Øß?processîÜsocket?Õá¡£

		\~japanese
		«¯«é«¤«¢«ó«È«½«±«Ã«ÈªÎlistenªòËÒã·ª¹ªëª³ªÈª¬ªÇª­ªŞª»ªó¡£TCPªŞª¿ªÏUDP«½«±«Ã«Èª¬?ªËŞÅéÄñéªÇª¢ªë«İ?«ÈªÊªÎª«ªòª´ü¬ìãª¯ªÀªµª¤¡£
\~
		*/
		ErrorType_LocalSocketCreationFailed,

		/**
		\~korean
		SocketÀ» »ı¼ºÇÒ ¶§ Port Pool ³» port number·ÎÀÇ bind°¡ ½ÇÆĞÇß½À´Ï´Ù. ´ë½Å ÀÓÀÇÀÇ port number°¡ »ç¿ëµÇ¾ú½À´Ï´Ù. Port PoolÀÇ °¹¼ö°¡ ÃæºĞÇÑÁö È®ÀÎÇÏ½Ê½Ã¿ä.

		\~english
		Failed binding to local port that defined in Port Pool. Please check number of values in Port Pool are sufficient.

		\~chinese
		ßæà÷socketîÜ?ı¦èÙPort Pool?port numberîÜbindã÷?¡£ìòëòport numberù¬ÓÛôğŞÅéÄ¡£???Port PoolîÜ??ãÀÜúõöİÂ¡£

		\~japanese
		Socketªòßæà÷ª¹ªëãÁ¡¢Port Pool?ªÎPort NumberªØªÎ«Ğ«¤«ó«ÉªËã÷ø¨ª·ªŞª·ª¿¡£ÓÛªïªêªËìòëòªÎPort Numberª¬ŞÅªïªìªŞª·ª¿¡£Port PoolªÎ?ª¬ä¨İÂªÊªÎª«ªòª´ü¬ìãª¯ªÀªµª¤¡£
		\~
		*/
		Error_NoneAvailableInPortPool,

		/**
		\~korean
		Port pool ³» °ªµé Áß ÇÏ³ª ÀÌ»óÀÌ Àß¸øµÇ¾ú½À´Ï´Ù. Æ÷Æ®¸¦ 0(ÀÓÀÇ Æ÷Æ® ¹ÙÀÎµù)À¸·Î ÇÏ°Å³ª Áßº¹µÇÁö ¾Ê¾Ò´ÂÁö È®ÀÎÇÏ½Ê½Ã¿ä.

		\~english
		Range of user defined port is wrong. Set port to 0(random port binding) or check if it is overlaped.

		\~chinese
		Port pool ñéìé?ì¤ß¾îÜ??õó?¡£??÷êÓ®Ï¢??0£¨ìòëòÓ®Ï¢binding£©ûäíºãÀÜúñì?¡£

		\~japanese
		Port pool?ªÎö·ªÎª¦ªÁìéªÄì¤ß¾ª¬ÊàêŞªÃªÆª¤ªŞª¹¡£«İ?«Èªò0(ìòëò«İ?«È«Ğ«¤«ó«Ç«£«ó«°)ªËª¹ªëª«ñìÜÜªµªìªÆª¤ªÊª¤ª«ªòª´ü¬ìãª¯ªÀªµª¤¡£
		\~
		*/
		ErrorType_InvalidPortPool,

		/**
		\~korean
		À¯È¿ÇÏÁö ¾ÊÀº HostID °ªÀÔ´Ï´Ù.

		\~english
		Invalid HostID.

		\~chinese
		ÙéüùîÜHostID¡£

		\~japanese
		êó?ªÇªÏªÊª¤HostIDö·ªÇª¹¡£
		\~
		*/
		ErrorType_InvalidHostID, // CODEREV-FORCERELAY: enum ErrorType¿¡ º¯°æÀ» °¡ÇÏ¼Ì±º¿ä. ÀÌ·¯ÇÑ °æ¿ì TypeToString_Kor, TypeToString_Eng,TypeToString_Chn¿¡µµ º¯°æÀ» °¡ÇØ¾ß ÇÕ´Ï´Ù. C#,AS,Java¹öÀü¿¡¼­µµ ¸¶Âù°¡ÁöÀÔ´Ï´Ù.

		/**
		\~korean
		»ç¿ëÀÚ°¡ ¼ÒÈ­ÇÏ´Â ¸Ş½ÃÁö Ã³¸® ¼Óµµº¸´Ù ³»ºÎÀûÀ¸·Î ½×ÀÌ´Â ¸Ş½ÃÁöÀÇ ¼Óµµ°¡ ´õ ³ô½À´Ï´Ù.
		Áö³ªÄ¡°Ô ³Ê¹« ¸¹Àº ¸Ş½ÃÁö¸¦ ¼Û½ÅÇÏ·Á°í Çß´ÂÁö, È¤Àº »ç¿ëÀÚÀÇ ¸Ş½ÃÁö ¼ö½Å ÇÔ¼ö°¡ Áö³ªÄ¡°Ô ´À¸®°Ô ÀÛµ¿ÇÏ°í ÀÖ´ÂÁö È®ÀÎÇÏ½Ê½Ã¿À.

		\~english
		The speed of stacking messages are higher than the speed of processing them.
		Check that you are sending too many messages, or your message processing routines are running too slowly.

		\~chinese
		á¼ãÓîÜ÷Ø?áÜÓøÍÔéÍ?×â??îÜáÜÓø¡£
		???é©?áêîÜ?Ëì÷¼Òı£¬ûäá¼ãÓ?×âïïßí?ú¼?Ø·¡£

		\~japanese
		«æ?«¶?ª¬á¼ûùª¹ªë«á«Ã«»?«¸?×âáÜÓøªèªê?İ»îÜªËîİªâªë«á«Ã«»?«¸ªÎáÜÓøª¬ªâªÃªÈáÜª¤ªÇª¹¡£
		ª¢ªŞªêªËªâÒıÎ¦ª®ªë«á«Ã«»?«¸ªòáêãáª·ªèª¦ªÈª·ªÆª¤ªÊª¤ª«¡¢ªŞª¿ªÏ«æ?«¶?ªÎ«á«Ã«»?«¸áôãá??ª¬ª¢ªŞªêªËªâ?ª¯íÂÔÑª·ªÆªÏª¤ªÊª¤ª«ªòü¬ìãª·ªÆª¯ªÀªµª¤¡£
		
		\~
		*/
		ErrorType_MessageOverload,


		/** Accessing database failed. For example, query statement execution failed. You may see the details from comment variable.
		*/
		ErrorType_DatabaseAccessFailed,

		/**
		\~korean ¸Ş¸ğ¸®°¡ ºÎÁ·ÇÕ´Ï´Ù.

		\~english Out of memory.

		\~chinese ?ğíÜôğë.

		\~japanese «á«â«ê?ª¬ğëªêªŞª»ªó¡£
		\~
		*/
		ErrorType_OutOfMemory,

		/** ¼­¹ö¿ÍÀÇ ¿¬°áÀÌ ²÷¾îÁ®¼­ ¿¬°á º¹±¸ ±â´ÉÀÌ °¡µ¿µÇ¾úÁö¸¸, ÀÌ°Í ¸¶Àúµµ ½ÇÆĞÇß½À´Ï´Ù. */
		ErrorType_AutoConnectionRecoveryFailed,

		/**
		\~korean
		RMI ÇÔ¼ö¸¦ È£Ãâ ÇßÁö¸¸, ÇÔ¼ö ±¸ÇöºÎ°¡ ¾ø½À´Ï´Ù.

		\~english

		\~chinese

		\~japanese
		\~
		*/
		ErrorType_NotImplementedRmi,
	};

	/**
	\~korean
	ProudNet È£½ºÆ® ½Äº°ÀÚ

	\~english 
	ProudNet host identifier 

	\~chinese
	ProudNet ñ«Ïõ??íº¡£

	\~japanese
	ProudNet«Û«¹«ÈãÛÜ¬í­
	\~
	*/
	enum HostID
	{
		/**
		\~korean
		¾øÀ½

		\~english
		None

		\~chinese
		Ùé

		\~japanese
		ªÊª·
		\~
		*/
		HostID_None = 0,

		/**
		\~korean
		¼­¹ö

		\~english
		Server

		\~chinese
		Ü×?Ğï

		\~japanese
		«µ?«Ğ?
		\~
		*/
		HostID_Server = 1,

		/**
		\~korean
		(»ç¿ë±İÁö)

		\~english
		(Do not use it)

		\~chinese
		£¨Ğ×ò­ŞÅéÄ£©

		\~japanese
		(ŞÅéÄĞ×ò­)
		\~
		*/
		HostID_Last = 2
	};

	typedef uint16_t RmiID;

	enum _RmiID
	{
		RmiID_None = 0,
		RmiID_Last = 65535, // marmalade¿¡¼­ RMI ID°¡ word°¡ µÊÀ» º¸ÀåÇÏ±â À§ÇØ.
	};

	/** \~korean ¸ğµâ ³»¿¡¼­ ¹ß»ıÇÏ´Â ·Î±×ÀÇ ¹üÁÖ Å¸ÀÔÀÔ´Ï´Ù.
	\~english It is a category type of the log occurred within the module.
	\~chinese î¤Ù¼???ßæîÜLogÛõ??
	\~japanese «â«¸«å?«ë?ªÇ?ßæª¹ªë«í«°ªÎ«««Æ«´«ê?«¿«¤«×ªÇª¹¡£
	\~ */
	enum LogCategory
	{
		/** \~korean ±âº» ½Ã½ºÅÛ
		\~english Basic System
		\~chinese Ğñ?Í§?
		\~japanese ĞñÜâ«·«¹«Æ«à
		\~ */
		LogCategory_System,
		/** \~korean TCP Åë½Å °ü·Ã
		\~english Relevant to TCP communication
		\~chinese ßÓ? TCP ÷×ãá
		\~japanese TCP÷×ãá?Ö§
		\~ */
		LogCategory_Tcp,
		/** \~korean UDP Åë½Å °ü·Ã
		\~english Relevant to UDP communication
		\~chinese ßÓ? UDP ÷×ãá
		\~japanese UDP÷×ãá?Ö§
		\~ */
		LogCategory_Udp,
		/** \~korean P2P Åë½Å °ü·Ã
		\~english Relevant to P2P communication
		\~chinese ßÓ? P2P ÷×ãá
		\~japanese P2P÷×ãá?Ö§
		\~ */
		LogCategory_P2P
	};

	/**
	\~korean
	ÇØÅ·ÀÇ Á¾·ù

	\~english
	Type of hacking

	\~chinese
	ıÙËÔîÜ??¡£

	\~japanese
	«Ï«Ã«­«ó«°ğú×¾
	\~
	*/
	enum HackType
	{
		/**
		\~korean
		ÇØÅ· ¾Æ´Ô

		\~english
		No hacking

		\~chinese
		ÜôãÀıÙËÔ¡£

		\~japanese
		«Ï«Ã«­«ó«°ªÇªÏªÊª¤
		\~
		*/
		HackType_None,

		/**
		\~korean
		½ºÇÇµåÇÙ

		\~english
		Speek hack

		\~chinese
		áÜÓøhack¡£

		\~japanese
		«¹«Ô?«Éú·
		\~
		*/
		HackType_SpeedHack,

		/**
		\~korean
		ÆĞÅ¶ Á¶ÀÛ

		\~english
		Handle packet

		\~chinese
		?ËßøĞğÃíÂ¡£

		\~japanese
		«Ñ«±«Ã«ÈğÃíÂ
		\~
		*/
		HackType_PacketRig,
	};

	/**
	\~korean
	Å¸ È£½ºÆ®¿ÍÀÇ ¿¬°á »óÅÂ

	\~english
	Connection status with other hosts

	\~chinese
	?Ğìöâñ«ÏõîÜ?ïÈ??¡£

	\~japanese
	öâªÎ«Û«¹«ÈªÈªÎïÈ??÷¾
	\~
	*/
	enum ConnectionState
	{
		/**
		\~korean
		¿¬°áÀÌ ²÷¾îÁø »óÅÂ

		\~english
		Disconnected condition

		\~chinese
		?ïÈñé?îÜ??¡£

		\~japanese
		ïÈ?ª¬ï·ªìª¿?÷¾
		\~
		*/
		ConnectionState_Disconnected,

		/**
		\~korean
		¿¬°á ½Ãµµ¸¦ ÇßÁö¸¸ ¾ÆÁ÷ °á°ú¸¦ ¾Ë ¼ö ¾ø´Â »óÅÂ

		\~english
		Tried connecting but result is unknown

		\~chinese
		?ì«???ïÈ£¬Ó£ÙéÛöò±Ô³?ÍıîÜ??¡£

		\~japanese
		ïÈ?ªòãËª·ªŞª·ª¿ª¬¡¢ªŞªÀÌ¿Íıª¬ò±ªéªÊª¤?÷¾
		\~
		*/
		ConnectionState_Connecting,

		/**
		\~korean
		¿¬°á °úÁ¤ÀÌ ¼º°øÇÑ »óÅÂ

		\~english
		Succeed to connect

		\~chinese
		?ïÈ?ïïà÷ÍíîÜ??¡£

		\~japanese
		ïÈ?Î¦ïïªËà÷Ííª·ª¿?÷¾
		\~
		*/
		ConnectionState_Connected,

		/**
		\~korean
		¿¬°á ÇØÁ¦ °úÁ¤ÀÌ ÁøÇàÁßÀÎ »óÅÂ

		\~english
		Disconnecting is in progress

		\~chinese
		î¤?ú¼?ïÈú°ğ¶?ïïîÜ??¡£

		\~japanese
		ïÈ?ú°ğ¶Î¦ïïª¬òäú¼ñéªÎ?÷¾
		\~
		*/
		ConnectionState_Disconnecting,
	};

	PROUD_API const PNTCHAR* ToString(LogCategory logCategory);
	PROUD_API const PNTCHAR* ToString(ConnectionState val);

	/**
	\~korean
	TCP fallbackÀ» ÀÇµµÀûÀ¸·Î ½ÃÇàÇÒ ¶§ÀÇ ¹æ¹ı

	\~english
	How to intentially use TCP fallback

	\~chinese
	Íºëò?ú¼TCP fallback?îÜÛ°Ûö¡£

	\~japanese
	TCP Fallbackªòëò?îÜªËã¿ú¼ª¹ªëãÁªÎÛ°Ûö
	\~
	*/
	enum FallbackMethod // °­µµ°¡ ³·Àº ¼øÀ¸·Î enum °ªÀ» Á¤·ÄÇÒ °Í
	{
		/**
		\~korean
		FallbackÀ» ¾ÈÇÔ. Áï ¼­¹ö ¹× peer¿ÍÀÇ UDP Åë½ÅÀ» ¸ğµÎ »ç¿ëÇÔ.

		\~english
		No Fallback. In other words, UDP communication to both server and peer are in use.

		\~chinese
		Üôñ®Fallback¡£?ŞÅéÄîïİ»îÜÜ×?ĞïĞà?peerîÜUDP÷×ãá¡£

		\~japanese
		Fallbackªòª·ªÊª¤¡£?ªÁ¡¢«µ?«Ğ?ªªªèªÓPeerªÈªÎUDP÷×ãáªòîïªÆŞÅéÄª·ªŞª¹¡£
		\~
		*/
		FallbackMethod_None,
		/**
		\~korean
		¼­¹ö¿ÍÀÇ UDP Åë½ÅÀº À¯ÁöÇÏµÇ Å¸ Peerµé°úÀÇ UDP Åë½Å¸¸ÀÌ Â÷´ÜµÈ °ÍÀ¸·Î Ã³¸®ÇÑ´Ù. ÀÏ½ÃÀû Æ÷Æ®¸ÅÇÎ ½ÇÆĞ¿Í À¯»çÇÑ »óÈ²À» ÀçÇöÇÑ´Ù. °¡Àå °­µµ°¡ ³·´Ù.

		\~english
		Regards that UDP with server is sustained but UDP with other peers to be disconnected. Reproduce a circumstance similar to a temporary port mapping failure. This is the lowest option with weakest impact.

		\~chinese
		?ò¥?Ü×?ĞïîÜUDP÷×ãá£¬?×â?ñş?ĞìöâpeerîÜUDP÷×ãáñé?¡£î¢?ìé?îÜÓ®Ï¢ç±ßÀã÷?ûú?ŞÄîÜï×?¡£Ë­ÓøõÌî¸¡£

		\~japanese
		«µ?«Ğ?ªÈªÎUDP÷×ãáªÏë«ò¥ª¹ªëª¬¡¢öâªÎPeerª¿ªÁªÈªÎUDP÷×ãáªÎªßª¬ó´?ªµªìª¿ªâªÎªÈ?×âª·ªŞª¹¡£ìéãÁîÜªË«İ?«È«Ş«Ã«Ô«ó«°ã÷ø¨ªÈ×¾ŞÄª·ª¿?üÏªòî¢úŞª·ªŞª¹¡£ìéÛã?Óøª¬î¸ª¤ªÇª¹¡£
		\~
		*/
		FallbackMethod_PeersUdpToTcp,
		/**
		\~korean
		¼­¹ö¿ÍÀÇ UDP Åë½ÅÀ» Â÷´ÜµÈ °ÍÀ¸·Î Ã³¸®ÇÑ´Ù. ÀÏ½ÃÀû Æ÷Æ®¸ÅÇÎ ½ÇÆĞ¿Í À¯»çÇÑ »óÈ²À» ÀçÇöÇÑ´Ù. ¾Æ¿ï·¯ Peerµé°úÀÇ UDP Åë½Åµµ Â÷´ÜµÈ´Ù. Áß°£ °­µµ´Ù.

		\~english
		 Regards that UDP with server is disconnected. Reproduce a circumstance similar to a temporary port mapping failure. On top of that, it also disconnects UDP with peers. Intermediate impact.


		\~chinese
		?×â?ñş?ĞìöâpeerîÜUDP÷×ãáñé?¡£î¢?ìé?îÜÓ®Ï¢ç±ßÀã÷?ûú?ŞÄîÜï×?¡£?peerîÜUDP÷×ãáå¥ù¬ñé?¡£Ë­ÓøìéÚõ¡£

		\~japanese
		«µ?«Ğ?ªÈªÎUDP÷×ãáªòó´?ªµªìª¿ªâªÎªÈ?×âª·ªŞª¹¡£ìéãÁîÜªË«İ?«È«Ş«Ã«Ô«ó«°ã÷ø¨ªÈ×¾ŞÄª·ª¿?üÏªòî¢úŞª·ªŞª¹¡£ªÁªÊªßªË¡¢Peerª¿ªÁªÈªÎUDP÷×ãáªâó´?ªµªìªŞª¹¡£ñéÊà?ÓøªÇª¹¡£
		\~
		*/
		FallbackMethod_ServerUdpToTcp,
		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®ÀÇ UDP ¼ÒÄÏÀ» ¾Æ¿¹ ´İ¾Æ¹ö¸°´Ù. ¿µ±¸ÀûÀÎ UDP º¹±¸¸¦ ¸øÇÏ°Ô ÇÑ´Ù. °¡Àå °­µµ°¡ ³ô´Ù.
		- Proud.CNetServer.SetDefaultFallbackMethod ¿¡¼­´Â »ç¿ëÇÒ ¼ö ¾ø´Ù.

		\~english
		 All UDP sockets of client will be shut down. UDP restoration will never be possible. Strongest impact.
		- Unable to use in Proud.CNetServer.SetDefaultFallbackMethod

		\~chinese
		òÁïÈ??èÌÊ«îÜUDPsocket¡£Üô?ñ®çµÎùàõîÜUDPáó?¡£Ë­ÓøõÌÍÔ¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªÎUDP«½«±«Ã«ÈªòøÍª¸ªŞª¹¡£çµÎùîÜªÊUDPÜÖ?ª¬ªÇª­ªÊª¯ª·ªŞª¹¡£ìéÛã?Óøª¬ÍÔª¤ªÇª¹¡£
		- Proud.CNetServer.SetDefaultFallbackMethod ªÇªÏŞÅéÄªÇª­ªŞª»ªó¡£
		\~
		*/
		FallbackMethod_CloseUdpSocket,
	};

	/**
	\~korean
	Å¬¶óÀÌ¾ğÆ®°£ Á÷Á¢ P2P Åë½ÅÀ» À§ÇÑ È¦ÆİÄªÀ» ½ÃÀÛÇÏ´Â Á¶°Ç

	\~english
	Conditions to start hole-punching for direct P2P communication among clients

	\~chinese
	?ÖõèÌÊ«ñı??ã·òÁïÈP2P÷×ãáîÜöèÔ×?Ëì¡£

	\~japanese
	«¯«é«¤«¢«ó«ÈÊàªÎòÁïÈP2P÷×ãáªÎª¿ªáªÎ«Û?«ë«Ñ«ó«Á«ó«°ªòËÒã·ª¹ªë?Ëì
	\~
	*/
	enum DirectP2PStartCondition
	{
		/**
		\~korean
		²À ÇÊ¿äÇÑ »óÈ²ÀÌ ¾Æ´Ñ ÀÌ»ó È¦ÆİÄªÀ» ÇÏÁö ¾Ê´Â´Ù. À¢¸¸ÇÏ¸é ÀÌ°ÍÀ» ¾²´Â °ÍÀÌ ÁÁ´Ù.

		\~english
		Unless really needed, it is recommended not to do hole-punching. Using this is strongly recommended.

		\~chinese
		ÜôãÀù±é©îÜï×?îÜ?Üô?ú¼öèÔ×¡£õÌû¿éÄ??¡£

		\~japanese
		ù±ªºù±é©ªÊ?üÏªÇªÏªÊª¤ì¤ß¾¡¢«Û?«ë«Ñ«ó«Á«ó«°ªÏª·ªŞª»ªó¡£ªÊª¼ªÊªé¡¢ª³ªìªòŞÅªÃª¿Û°ª¬ÕŞª¤ªÇª¹¡£
		\~
		*/
		DirectP2PStartCondition_Jit,
		/**
		\~korean
		CNetServer.CreateP2PGroup ÀÌ³ª CNetServer.JoinP2PGroup µî¿¡ ÀÇÇØ Å¬¶óÀÌ¾ğÆ®°£ P2P Åë½ÅÀÌ Çã¿ëµÇ´Â ¼ø°£¿¡ ¹«Á¶°Ç
		È¦ÆİÄª °úÁ¤À» ½ÃÀÛÇÑ´Ù. ¿¹¸¦ µé¾î <a target="_blank" href="http://guide.nettention.com/cpp_ko#super_peer" >Super Peer(¼öÆÛÇÇ¾î È¤Àº È£½ºÆ®) Áß½ÉÀÇ P2P ³×Æ®¿öÅ·</a>  ¿¡¼­ ¼öÆÛ ÇÇ¾î¸¦ °ÔÀÓ ÇÃ·¹ÀÌ µµÁß Á¾Á¾ ¹Ù²ã¾ß ÇÑ´Ù¸é ÀÌ°ÍÀÌ
		ÇÊ¿äÇÒ ¼öµµ ÀÖÀ» °ÍÀÌ´Ù.

		\~english
		This forcefully begins hole-punching at the moment when P2P communication among clients is allowed by CNetServer.CreateP2PGroup or CNetServer.JoinP2PGroup or others.
		For an example, if there is a need to change super peer at <a target="_blank" href="http://guide.nettention.com/cpp_en#super_peer" >P2P Networking for Super Peer (Super Peer or host)</a> during game play, this may be needed.

		\~chinese
		ù¬ CNetServer.CreateP2PGroup%ûäíº CNetServer.JoinP2PGroup £¬èÌÊ«ñı?P2P÷×ãáëÃ?îÜâë?ìéïÒé©?ã·öèÔ×?ïï¡£ÖÇåıî¤<a target="_blank" href="http://guide.nettention.com/cpp_zh#super_peer" >Super Peer(ûäñ«Ïõ) ñéãıîÜP2P÷×ãá</a>%£¬êı??ú¼ñéé©÷êsuper peerËÇ??Ê¦ÒöâÍé©??¡£

		\~japanese
		CNetServer.CreateP2PGroupªÈª«CNetServer.JoinP2PGroupªÊªÉªËªèªÃªÆ«¯«é«¤«¢«ó«ÈÊàªÎP2P÷×ãáª¬úÉé»ªµªìªëâëÊàªËÙí?Ëì«Û?«ë«Ñ«ó«Á«ó«°Î¦ïïªòËÒã·ª·ªŞª¹¡£ÖÇª¨ªĞ¡¢\ref super_peerªÇ«¹?«Ñ?«Ô?«¢ªò«²?«à«×«ì«¤Ô²ñéªËéÏªË?ª¨ªÊª±ªìªĞªÊªéªÊª¤ªÈª·ª¿ªé¡¢ª³ªìª¬ù±é©ªËªÊªëª«ªâª·ªìªŞª»ªó¡£

		\~
		*/
		DirectP2PStartCondition_Always,
		DirectP2PStartCondition_LAST,
	};
	/**  @} */

	/**
	\~korean
	»ç¿ëÀÚ ½Ç¼ö·Î ÀÎÇÑ ¿¡·¯¸¦ ProudNetÀÌ º¸¿©ÁÖ´Â ¹æ¹ı

	\~english
	The way Proudnet shows error caused by user

	\~chinese
	ProudNet ?ãÆë¦éÄ?îÜã÷?ğãà÷îÜ??îÜÛ°Ûö¡£

	\~japanese
	«æ?«¶?ÊàêŞª¤ªËªèªë«¨«é?ªòProudNetª¬øúãÆª¹ªëÛ°Ûö
	\~
	*/
	enum ErrorReaction
	{
		/**
		\~korean
		´ëÈ­ »óÀÚ¸¦ º¸¿©ÁØ´Ù. °³¹ß °úÁ¤¿¡¼­´Â ¿ä±äÇÏÁö¸¸ ¿£µåÀ¯Àú ÀÔÀå¿¡¼­´Â Ç®½ºÅ©¸°ÀÎ °æ¿ì ÇÁ¸®Â¡À¸·Î º¸ÀÏ ¼ö ÀÖ¾î¼­ µÇ·¹ ¹®Á¦ Ã£±â°¡ ´õ ¾î·Á¿ï ¼ö ÀÖ´Ù.

		\~english
		Shows chat box. This may be useful during development process but it can also be very troublesome since the chat box can be seen to end users as full screen freezing.

		\~chinese
		?ãÆ???¡£?î¤???ïïñéŞªßÈñìé©£¬Ó£?éÍõÌ?éÄ?î¤îï?ñéÊ¦Òö??Ğì?freezing£¬????Ê¦ÒöÚãì»ÌÚÊ¥Íİ?¡£

		\~japanese
		«À«¤«¢«í«°«Ü«Ã«¯«¹ªòøúãÆª·ªŞª¹¡£ËÒ?Î¦ïïªÇªÏù±é©ªÇª¹ª¬¡¢«¨«ó«É«æ?«¶?ªÎØ¡íŞªÇªÏ«×?«ë«¹«¯«ê?«óªÎíŞùê¡¢FreezingªËÌ¸ª¨ªëª³ªÈª¬ª¢ªê¡¢ª«ª¨ªÃªÆÙığ¹ªò÷®ª¹ªÎª¬ÓŞ?ªËªÊªëª³ªÈªâª¢ªêªŞª¹¡£

		\~
		*/
		ErrorReaction_MessageBox,
		/**
		\~korean
		Å©·¡½Ã¸¦ À¯¹ßÇÑ´Ù. ¿£µåÀ¯Àú ÀÔÀå¿¡¼­´Â Å©·¡½Ã·Î ³ªÅ¸³ª¹Ç·Î ¸±¸®ÁîµÈ °æ¿ì ¹®Á¦¸¦ ´õ ½±°Ô Ã£À» ¼ö ÀÖ´Ù.
		´Ü, <a target="_blank" href="http://guide.nettention.com/cpp_ko#minidump_main" >MiniDump (¿À·ù´ıÇÁ½Ã½ºÅÛ)</a>  µîÀ» È¥¿ëÇØ¾ß ±× °¡Ä¡°¡ ÀÖ´Ù.

		\~english
		Causes a crash. From end users' point of view, this is definitely a crash so it can be rather easier to find what the problem is when released.
		But, it is more effective when used along with <a target="_blank" href="http://guide.nettention.com/cpp_en#minidump_main" >Error Dump System</a>.

		\~chinese
		??crash¡£î¤õÌ?éÄ??ãÆ?crash£¬Ê¦ÒöÌÚé»æ¶?ÓğreleaseîÜê«ì×¡£
		Ó£é©ûèéÄ <a target="_blank" href="http://guide.nettention.com/cpp_zh#minidump_main" >????Í§?</a>

		\~japanese
		«¯«é«Ã«·«åªòë¯?ª·ªŞª¹¡£«¨«ó«É«æ?«¶?ªÎØ¡íŞªÇªÏ«¯«é«Ã«·«åªÇúŞªìªŞª¹ªÎªÇ¡¢«ê«ê?«¹ªµªìª¿íŞùê¡¢Ùığ¹ªòªâªÃªÈ÷®ª·ªäª¹ª¤ª«ªâª·ªìªŞª»ªó¡£Ó£ª·¡¢\ref minidumpªÊªÉªòûèéÄª·ªÆª½ªÎ?ö·ª¬ª¢ªêªŞª¹¡£
\~ */
		ErrorReaction_AccessViolation,
		/**
		\~korean
		µğ¹ö°Å Ãâ·ÂÃ¢¿¡¼­¸¸ º¸¿©Áı´Ï´Ù. Å©·¡½Ã³ª ´ëÈ­»óÀÚ¸¦ ¶ç¿öÁÙ¸¸ÇÑ »óÈ²ÀÌ ¾Æ´Ï¶ó¸é ÀÌ¿É¼ÇÀ» »ç¿ëÇÏ½Ê½Ã¿À.

		\~english
		It shows only debugger output screen. If you can not pop up crash or message box, please use this option.

		\~chinese
		ñş?ãÆî¤???õó?¡£ÜôãÀ?ãÆcrashûäíº???îÜï×?îÜ?£¬?ŞÅéÄó®??¡£

		\~japanese
		«Ç«Ğ«Ã«¬?õóÕô?ØüªÇªÎªßøúãÆªµªìªŞª¹¡£«¯«é«Ã«·«åªä«À«¤«¢«í«°«Ü«Ã«¯«¹ªòøúãÆª¹ªë?üÏªÇªÏªÊª±ªìªĞª³ªÎ«ª«×«·«ç«óªòŞÅªÃªÆª¯ªÀªµª¤¡£
		\~
		*/
		ErrorReaction_DebugOutput,
		/**
		\~korean
		µğ¹ö°Å ºê·¹ÀÌÅ©¸¦ °Ì´Ï´Ù. ÇØ´ç¿É¼ÇÀº µğ¹ö±× ¸ğµå¿¡¼­¸¸ »ç¿ëÇÏ½Ê½Ã¿À.
		\~english
		Put on the debugger brake. Please use this option only in the debugging mode. 

		\~japanese
		«Ç«Ğ«Ã«¬?«Ö«ì?«­ªòª«ª±ªŞª¹¡£ú±?«ª«×«·«ç«óªÏ«Ç«Ğ«Ã«°«â?«ÉªÇªÎªßŞÅªÃªÆª¯ªÀªµª¤¡£
		\~
		 */
		ErrorReaction_DebugBreak
	};

	/**
	\~korean
	¿¬»ê Á¾·ù

	\~english
	Operation type

	\~chinese
	?ß©??¡£

	\~japanese
	æÑß©ğú×¾
	\~
	*/
	enum ValueOperType
	{
		/**
		\~korean
		µ¡¼À

		\~english
		Addition

		\~chinese
		Ê¥Ûö¡£

		\~japanese
		ğëª·ß©
		\~
		*/
		ValueOperType_Plus,
		/**
		\~korean
		»¬¼À

		\~english
		Subtraction

		\~chinese
		?Ûö

		\~japanese
		ìÚª­ß©
		\~
		*/
		ValueOperType_Minus,
		/**
		\~korean
		°ö¼À

		\~english
		Multiplication

		\~chinese
		ã«Ûö¡£

		\~japanese
		ÎĞª±ß©
		\~
		*/
		ValueOperType_Multiply,
		/**
		\~korean
		³ª´°¼À

		\~english
		Division

		\~chinese
		ğ¶Ûö¡£

		\~japanese
		ùÜªêß©
		\~
		*/
		ValueOperType_Division
	};

	/**
	\~korean
	ºñ±³ Á¾·ù

	\~english
	Comparison type

	\~chinese
	İï???¡£

	\~japanese
	İïÎòğú×¾
	\~
	*/
	enum ValueCompareType
	{
		/**
		\~korean
		Å©°Å³ª °°À¸¸é

		\~english
		Greater or equal

		\~chinese
		ÓŞûäÔõéÍ¡£

		\~japanese
		ÓŞª­ª¤ª«Ôõª·ª±ªìªĞ
		\~
		*/
		ValueCompareType_GreaterEqual,

		/**
		\~korean
		Å©¸é

		\~english
		Greater

		\~chinese
		ÓŞîÜ?¡£

		\~japanese
		ÓŞª­ª±ªìªĞ
		\~
		*/
		ValueCompareType_Greater,

		/**
		\~korean
		ÀÛ°Å³ª °°À¸¸é

		\~english
		Less or equal

		\~chinese
		á³ûäÔõéÍ¡£

		\~japanese
		á³ªµª¤ª«Ôõª·ª±ªìªĞ
		\~
		*/
		ValueCompareType_LessEqual,

		/**
		\~korean
		ÀÛÀ¸¸é

		\~english
		Less

		\~chinese
		á³îÜ?¡£

		\~japanese
		á³ªµª±ªìªĞ
		\~
		*/
		ValueCompareType_Less,

		/**
		\~korean
		°°À¸¸é

		\~english
		Equal

		\~chinese
		ÔõéÍ¡£

		\~japanese
		Ôõª·ª±ªìªĞ
		\~
		*/
		ValueCompareType_Equal,

		/**
		\~korean
		´Ù¸£¸é

		\~english
		Not equal

		\~chinese
		ÜôÔÒîÜ?¡£

		\~japanese
		êŞª¨ªĞ
		\~
		*/
		ValueCompareType_NotEqual
	};

	/**
	\~korean
	¾ÏÈ£È­ ¼öÁØ

	\~english
	Encryption Level

	\~chinese
	Ê¥ÚËâ©øÁ¡£

	\~japanese
	äŞ?ûùâ©ñŞ
	\~
	*/
	enum EncryptLevel
	{
		/**
		\~korean
		AES ¾ÏÈ£È­ ¼öÁØ ÇÏ

		\~english
		AES encryption level Low

		\~chinese
		AES Ê¥ÚËâ©øÁî¸¡£

		\~japanese
		AESäŞ?ûùâ©ñŞ¡¡ù»
		\~
		*/
		EncryptLevel_Low = 128,
		/**
		\~korean
		AES ¾ÏÈ£È­ ¼öÁØ Áß

		\~english
		AES encryption level Middle

		\~chinese
		AES Ê¥ÚËâ©øÁñé¡£

		\~japanese
		AESäŞ?ûùâ©ñŞ¡¡ñé
		\~
		*/
		EncryptLevel_Middle = 192,
		/**
		\~korean
		AES ¾ÏÈ£È­ ¼öÁØ »ó

		\~english
		AES encryption level High

		\~chinese
		AES Ê¥ÚËâ©øÁß¾¡£

		\~japanese
		AESäŞ?ûùâ©ñŞ¡¡ß¾
		\~
		*/
		EncryptLevel_High = 256,
	};

	/**
	\~korean
	Fast ¾ÏÈ£È­ ¼öÁØ

	\~english
	Fast encryption level

	\~chinese
	Fast Ê¥ÚËâ©øÁ¡£

	\~japanese
	FastäŞ?ûùâ©ñŞ
	\~
	*/
	enum FastEncryptLevel
	{
		/**
		\~korean
		Fast ¾ÏÈ£È­ ¼öÁØ ÇÏ

		\~english
		Fast encryption level Low

		\~chinese
		FastÊ¥ÚËâ©øÁî¸¡£

		\~japanese
		FastäŞ?ûùâ©ñŞ¡¡ù»
		\~
		*/
		FastEncryptLevel_Low = 512,
		/**
		\~korean
		Fast ¾ÏÈ£È­ ¼öÁØ Áß

		\~english
		Fast encryption level Middle

		\~chinese
		FastÊ¥ÚËâ©øÁñé¡£

		\~japanese
		FastäŞ?ûùâ©ñŞ¡¡ñé
		\~
		*/
		FastEncryptLevel_Middle = 1024,
		/**
		\~korean
		Fast ¾ÏÈ£È­ ¼öÁØ »ó

		\~english
		Fast encryption level High

		\~chinese
		FastÊ¥ÚËâ©øÁß¾¡£

		\~japanese
		FastäŞ?ûùâ©ñŞ¡¡ß¾
		\~
		*/
		FastEncryptLevel_High = 2048,
	};

	enum HostType
	{
		HostType_Server,
		HostType_Peer,
		HostType_All,
	};

	/**
	\~korean
	HostID Àç»ç¿ë ±â´É ¿É¼ÇÀÔ´Ï´Ù.

	\~english
	It is an option for HostID reuse function.

	\~chinese
	HostIDãÀî¢ŞÅéÄĞüÒö??¡£

	\~japanese
	HostIDî¢ŞÅéÄÑ¦Òö«ª«×«·«ç«óªÇª¹¡£

	\~
	*/
	enum HostIDGenerationPolicy
	{
		/**
		\~korean
		HostID Àç»ç¿ë ±â´ÉÀ» »ç¿ëÇÕ´Ï´Ù.
		-±âº»°ªÀÔ´Ï´Ù.

		\~english
		It uses a HostID reuse function.
		-It is a default value.

		\~chinese
		HostID ŞÅéÄî¢ŞÅéÄĞüÒö¡£
		-?ĞñÜâ?¡£.

		\~japanese
		HostIDî¢ŞÅéÄÑ¦ÒöªòŞÅª¤ªŞª¹¡£
		?«Ç«Õ«©«ë«Èö·ªÇª¹

		\~
		*/
		HostIDGenerationPolicy_Recycle = 1,

		/**
		\~korean
		HostID Àç»ç¿ë ±â´ÉÀ» »ç¿ëÇÏÁö ¾Ê½À´Ï´Ù.

		\~english
		It does not use a HostID reuse function.

		\~chinese
		HostID ÜôŞÅéÄî¢ŞÅéÄĞüÒö¡£.

		\~japanese
		HostIDî¢ŞÅéÄÑ¦ÒöªòŞÅª¤ªŞª»ªó¡£

		\~
		*/
		HostIDGenerationPolicy_NoRecycle,
	};

	/**
	\~korean
	½º·¹µå ¸ğµ¨ÀÔ´Ï´Ù.

	\~english
	Thread model.

	\~chinese
	?ïïÙ¼úş¡£

	\~japanese
	«¹«ì«Ã«É«â«Ç«ëªÇª¹¡£

	\~
	*/
	enum ThreadModel
	{
		/**
		\~korean
		´ÜÀÏ ½º·¹µå ¸ğµ¨ÀÔ´Ï´Ù. »ç¿ëÀÚ°¡ ¸¸µç ½º·¹µå À§¿¡¼­ ÀÛµ¿ÇÔÀ» ÀÇ¹ÌÇÕ´Ï´Ù.
		µû·Î ½º·¹µå°¡ ¾øÀ¸¹Ç·Î »ç¿ëÀÚ´Â Proud::CNetClient::FrameMove¸¦ ÃÖ¼Ò ¸Å 1/60ÃÊ¸¶´Ù Áö¼ÓÀûÀ¸·Î È£ÃâÇØ ÁÖ¾î¾ß ÇÕ´Ï´Ù.

		\~english
		Single thread model. Runs code on threads created by user.
		As there is no networker thread, You must call Proud::CNetClient::FrameMove for every 1/60 seconds.

		\~chinese
		??ïïÙ¼úş¡£?ú¼î¤éÄ??ËïîÜ?ïïò®¡£
		ë¦éÍ?êó?Ø¡îÜ?ïï£¬éÄ?âÍé©õÌá´ 1/60 õ©?Ì°ò¥??éÄ Proud::CNetClient::FrameMove¡£

		\~japanese
		«·«ó«°«ë«¹«ì«Ã«É«â«Ç«ëªÇª¹¡£«æ?«¶?ª¬íÂà÷ª·ª¿«¹«ì«Ã«Éß¾ªÇÔÑíÂª¹ªëª³ªÈªòëòÚ«ª·ªŞª¹¡£
		Ü¬ªË«¹«ì«Ã«Éª¬ªÊª¤ª¿ªá¡¢«æ?«¶?ªÏProud :: CNetClient :: FrameMoveªòõÌá³Øİ1/60õ©ª´ªÈªË??îÜªËû¼ªÓõóª¹ù±é©ª¬ª¢ªêªŞª¹¡£

		\~
		*/
		ThreadModel_SingleThreaded = 1,

		/**
		\~korean
		¸ÖÆ¼ ½º·¹µå ¸ğµ¨ÀÔ´Ï´Ù. Thread poolÀ» µû·Î ¸¸µé°í ±× À§¿¡¼­ ÀÛµ¿ÇÔÀ» ÀÇ¹ÌÇÕ´Ï´Ù.

		\~english
		Multi thread model. Runs code on the separated thread pool.

		\~chinese
		Òı?ïïÙ¼úş¡£???Ëï?ïïò®??ú¼î¤ó®ß¾¡£

		\~japanese
		«Ş«ë«Á«¹«ì«Ã«É«â«Ç«ëªÇª¹¡£ Thread poolªòÜ¬?ªËíÂà÷ª·¡¢ª½ªÎß¾ªÇÔÑíÂª¹ªëª³ªÈªòëòÚ«ª·ªŞª¹¡£
		\~
		*/
		ThreadModel_MultiThreaded,

		/**
		\~korean
		¿ÜÀå ½º·¹µå ¸ğµ¨ÀÔ´Ï´Ù. »ç¿ëÀÚ°¡ ¸¸µç Proud.CThreadPool À§¿¡¼­ ÀÛµ¿ÇÔÀ» ÀÇ¹ÌÇÕ´Ï´Ù.

		\~english
		Use-external-thread model. Runs code on Proud.CThreadPool instance create by user.

		\~chinese
		èâİ»?ïïÙ¼úş¡£?ú¼î¤éÄ??ËïîÜ Proud.CThreadPool¡£

		\~japanese
		èâ?«¹«ì«Ã«É«â«Ç«ëªÇª¹¡£«æ?«¶?ª¬íÂà÷ª·ª¿Proud.CThreadPoolß¾ªÇÔÑíÂª¹ªëª³ªÈªòëòÚ«ª·ªŞª¹¡£

		\~
		*/
		ThreadModel_UseExternalThreadPool,
	};
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
