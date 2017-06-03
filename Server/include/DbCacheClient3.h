/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
/*
ProudNet 1.8.38132-dev012


ÀÌ ÇÁ·Î±×·¥ÀÇ ÀúÀÛ±ÇÀº ³İÅÙ¼Ç¿¡°Ô ÀÖ½À´Ï´Ù.
ÀÌ ÇÁ·Î±×·¥ÀÇ ¼öÁ¤, »ç¿ë, ¹èÆ÷¿¡ °ü·ÃµÈ »çÇ×Àº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾àÀ» µû¸£¸ç,
°è¾àÀ» ÁØ¼öÇÏÁö ¾Ê´Â °æ¿ì ¿øÄ¢ÀûÀ¸·Î ¹«´Ü »ç¿ëÀ» ±İÁöÇÕ´Ï´Ù.
¹«´Ü »ç¿ë¿¡ ÀÇÇÑ Ã¥ÀÓÀº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾à¼­¿¡ ¸í½ÃµÇ¾î ÀÖ½À´Ï´Ù.

** ÁÖÀÇ: ÀúÀÛ¹°¿¡ °üÇÑ À§ÀÇ ¸í½Ã¸¦ Á¦°ÅÇÏÁö ¸¶½Ê½Ã¿À.


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
#include "Ptr.h"
#include "NetServerInterface.h"
#include "dbenums.h"
#include "DbLoadedData2.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup db_group
	*  @{
	*/
	class IDbCacheClientDelegate2;


	/**
	\~korean
	DB cache server¿¡ Á¢¼ÓÇÏ±â À§ÇÑ ¿¬°á Á¤º¸

	\~english
	Connect information in order to connect to DB cache server

	\~chinese
	?Öõ?ïÈDB cache server îÜ?ïÈãáãÓ¡£

	\~japanese
	DB cache serverªËïÈ?ª¹ªëª¿ªáªÎïÈ?ï×ÜÃ
	\~
	*/
	class CDbCacheClient2ConnectParameter
	{
	public:
		/**
		\~korean
		¼­¹ö ÁÖ¼Ò

		\~english
		Server address

		\~chinese
		Ü×?Ğïò¢ò£

		\~japanese
		«µ?«Ğ?«¢«É«ì«¹
		\~
		*/
		String m_serverAddr;

		/**
		\~korean
		Å¬¶óÀÌ¾ğÆ®ÀÇ ¸®½º´× ¼ÒÄÏÀÌ ¹ÙÀÎµùµÉ ÁÖ¼ÒÀÔ´Ï´Ù.
		- ÃÊ±â°ªÀº ºó ¹®ÀÚ¿­ÀÔ´Ï´Ù.
		- Åë»óÀûÀ¸·Î ºó ¹®ÀÚ¿­À» ÁöÁ¤ÇÏÁö¸¸ Å¬¶óÀÌ¾ğÆ®°¡ ³×Æ®¿öÅ© ÀÎÅÍÆäÀÌ½º(NIC)¸¦ 2°³ ÀÌ»ó °¡Áö´Â °æ¿ì,
		±×¸®°í ±×°Íµé Áß ÇÏ³ª¸¸ÀÌ ´Ù¸¥ CLanClient¿¡¼­ ¿À´Â Á¢¼Ó ¿äÃ»À» ¹ŞÀ» ¼ö ÀÖ´Â °æ¿ì ¿©±â¿¡ ÇØ´çµË´Ï´Ù.
		NIC¿¡ ÁöÁ¤µÈ IP ¶Ç´Â È£½ºÆ® ÀÌ¸§À» ÁöÁ¤ÇØ¾ß ÇÕ´Ï´Ù. È£½ºÆ®¿¡ ÀÖ´Â NIC ÁÖ¼Ò ¸®½ºÆ®¸¦ ¾òÀ¸·Á¸é Proud.GetLocalIPAddresses¸¦ ¾µ ¼ö ÀÖ½À´Ï´Ù.
		- È£½ºÆ® ÀÌ¸§À» ÁöÁ¤ÇÒ °æ¿ì Å¬¶óÀÌ¾ğÆ®´Â ¼­¹ö·Î Á¢¼ÓÇÏ±â À§ÇÑ ÁÖ¼Ò·Î localhost¸¦ ÀÔ·ÂÇÒ °æ¿ì ¿¬°á ½ÇÆĞ¸¦ ÇÒ ¼ö ÀÖ½À´Ï´Ù. ÀÌ·¯ÇÑ °æ¿ì
		Å¬¶óÀÌ¾ğÆ®´Â ¼­¹ö·Î Á¢¼ÓÇÏ±â À§ÇØ ¼­¹ö È£½ºÆ®ÀÇ ÁÖ¼Ò¸¦ ¸í½ÃÀûÀ¸·Î ÀÔ·ÂÇØ¾ß ÇÕ´Ï´Ù.

		\~english
		The address that the listening socket of the client to be bound.
		- The initial value is an empty string.
		- Usually set as an empty string but in case when the client has 2 or more of network interfaces (NICs)
		and when only one of them is able to recieve the connection request from other CLanClient, it is the case to use this.
		The IP address or the host name designated by the NIC must be used. Proud.GetLocalIPAddresses can be used to get the NIC address list located in the host.
		- In the case that a host name is used, a connection failure can occur when localhost is set as the address to connect to the server for a client.
		In this case, the client must be set clearly as the server host address in order to connect to the server.

		\~chinese
		èÌÊ«îÜâ¥??Ï¢é©ù¬boudîÜò¢ò£¡£
		- Ùù??ãÀÍöí®İ¬?¡£
		- ÷×ßÈ?ò¦ïÒÍöîÜí®İ¬Íú£¬?èÌÊ«?êó??ì¤ß¾??Í£Øü£¨NIC£©îÜ?ı¦£¬?êóñşêóĞìñéìé?î¤ïÈâ¥??îÜ CLanClient%??îÜ?ïÈé­?îÜ?ı¦??ó®??¡£
		é©ò¦ïÒ?NICò¦ïÒîÜIPûäíºñ«ÏõÙ£í®¡£é©ßÌ?Ôğñ«ÏõîÜNICò¢ò£ÖªøúîÜ?Ê¦ì¤ŞÅéÄ Proud.GetLocalIPAddresses%¡£
		- ò¦ïÒñ«ÏõÙ£í®îÜ?ı¦£¬èÌÊ«?Öõ?ïÈÜ×?Ğï?ìılocalhotîÜ?ı¦Ê¦Òö??ïÈã÷?¡£??îÜï×?ù»£¬éÄ??Öõ?ïÈÜ×?Ğï??Ù¥ãÆàõîÜ?ìıÜ×?Ğïñ«ÏõîÜò¢ò£¡£

		\~japanese
		«¯«é«¤«¢«ó«ÈªÎ«ê«¹«Ë«ó«°«½«±«Ã«Èª¬«Ğ«¤«ó«Ç«£«ó«°ªµªìªë«¢«É«ì«¹ªÇª¹¡£
		- ôøÑ¢ö·ªÏÍöªÎÙşí®ÖªªÇª¹¡£
		- ÷×ßÈ¡¢ÍöªÎÙşí®Öªªòò¦ïÒª·ªŞª¹ª¬¡¢«¯«é«¤«¢«ó«Èª¬«Í«Ã«È«ï?«¯«¤«ó«¿?«Õ«§?«¹(NIC)ªò2ËÁì¤ß¾ò¥ªÃªÆª¤ªëíŞùê¡¢ª½ª·ªÆª½ªìªéªÎª¦ªÁìéªÄªÎªßª¬êŞª¦CLanClientª«ªé?ªëïÈ?é©ôëªòáôª±ªéªìªëíŞùêª¬ª³ªìªËú±?ª·ªŞª¹¡£
		NICªËò¦ïÒªµªìª¿IPªŞª¿ªÏ«Û«¹«ÈÙ£ªòò¦ïÒª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£«Û«¹«ÈªËª¢ªëNIC«¢«É«ì«¹«ê«¹«ÈªòÔğªëª¿ªáªËªÏProud.GetLocalIPAddressesªòŞÅª¦ª³ªÈª¬ªÇª­ªŞª¹¡£
		- «Û«¹«ÈÙ£ªòò¦ïÒª¹ªëíŞùê¡¢«¯«é«¤«¢«ó«ÈªÏ«µ?«Ğ?ªËïÈ?ª¹ªëª¿ªáªÎ«¢«É«ì«¹ªËlocalhostªòìıÕôª¹ªëíŞùê¡¢ïÈ?ã÷ø¨ªÎÊ¦Òöàõª¬ª¢ªêªŞª¹¡£ª³ªÎªèª¦ªÊíŞùê¡¢«¯«é«¤«¢«ó«ÈªÏ«µ?«Ğ?ªËïÈ?ª¹ªëª¿ªáªË«µ?«Ğ?«Û«¹«ÈªÎ«¢«É«ì«¹ªòÙ¥ãÆîÜªËìıÕôª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£

		\~
		*/
		String m_localNicAddr;

		/**
		\~korean
		¼­¹ö Æ÷Æ®

		\~english
		Server port

		\~chinese
		Ü×?ĞïÓ®Ï¢

		\~japanese
		«µ?«Ğ?«İ?«È
		\~
		*/
		uint16_t m_serverPort;

		/**
		\~korean
		¼­¹ö ÀÎÁõÅ°. CDbCacheServer2StartParameter.m_authenticationKey ¿Í °°Àº °ªÀÌ¾î¾ß ÇÕ´Ï´Ù.

		\~english
		Server authentication key. It has to same value with bCacheServer2StartParameter.m_authenticationKey

		\~chinese
		Ü×?Ğï???¡£é©? CDbCacheServer2StartParameter.m_authenticationKey%ìé?îÜ?¡£

		\~japanese
		«µ?«Ğ?ìã?«­?¡£CDbCacheServer2StartParameter.m_authenticationKeyªÈÔÒª¸ö·ªÇªÏªÊª±ªìªĞªÊªêªŞª»ªó¡£
		\~
		*/
		String m_authenticationKey;

		/**
		\~korean
		ÀÌº¥Æ® Äİ¹éÀ» ¹Ş±â À§ÇÑ delegate °´Ã¼

		\~english
		Delegate object to receive event callback

		\~chinese
		?ÖõÔğÓğeventüŞ?îÜdelegate?ßÚ¡£

		\~japanese
		«¤«Ù«ó«È«³?«ë«Ğ«Ã«¯ªòáôª±ªëª¿ªáªÎdelegate«ª«Ö«¸«§«¯«È
		\~
		*/
		IDbCacheClientDelegate2* m_delegate;

		/**
		\~korean
		½º·¹µå Ç®ÀÇ ½º·¹µå °¹¼ö. ÃÖ¼ÒÇÑ 1Àº ÁöÁ¤µÇ¾î¾ß ÇÕ´Ï´Ù.
		- ÃÊ±â°ªÀº 0ÀÌ´Ù. 0À» ÁöÁ¤ÇÏ¸é CPU °¹¼ö·Î ÁöÁ¤µË´Ï´Ù.

		\~english
		The number of threads in thread pool. Must be set as at least 1.
		- The initial value is 0. If it is set as 0 then it is set as the number of CPUs.

		\~chinese
		?ïïğËîÜ?ïï??¡£õÌá´é©ò¦ïÒ?1¡£
		- ôøã·?ãÀ0¡£ò¦ïÒ0îÜ?øµ?ò¦ïÒ?CUP??¡£

		\~japanese
		«¹«ì«Ã«É«×?«ëªÎ«¹«ì«Ã«ÉËÁ?¡£õÌá³ùÚ1ªÏò¦ïÒªµªìªÊª±ªìªĞªÊªêªŞª»ªó¡£
		- ôøÑ¢ö·ªÏ0ªÇª¹¡£0ªòò¦ïÒª¹ªìªĞCPU?ªÇò¦ïÒªµªìªŞª¹¡£
		\~
		*/
		int m_userWorkerThreadCount;

		/**
		\~korean
		ÀÌ °ªÀÌ nullÀÌ ¾Æ´Ï¸é, ¿ÜºÎ networker thread ¸¦ »ç¿ëÇÕ´Ï´Ù.
		Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool ¿Í °°Àº ¿ªÇÒÀ» ÇÕ´Ï´Ù.

		\~english
		If this value is not null, an external networker thread will be used.
		It acts as Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool.

		\~chinese
		ó®?ÜôãÀnullîÜ?ŞÅéÄèâİ»networker thread¡£
		ÑÃó·? Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool%ìé?îÜíÂéÄ¡£

		\~japanese
		ª³ªÎö·ª¬nullªÇªÏªÊª¤íŞùê¡¢èâİ» networker threa ªòŞÅéÄª·ªŞª¹¡£
		Proud.CStartLanServerParameter.m_externalNetWorkerThreadPool ªÈÔÒª¸æµùÜªòª·ªŞª¹¡£

		*/
		CThreadPool* m_externalNetWorkerThreadPool;

		/**
		\~korean
		ÀÌ °ªÀÌ nullÀÌ ¾Æ´Ï¸é, ¿ÜºÎ user worker thread¸¦ »ç¿ëÇÕ´Ï´Ù.
		Proud.CStartLanServerParameter.m_externalUserWorkerThreadPool ¿Í °°Àº ¿ªÇÒÀ» ÇÕ´Ï´Ù.

		\~english
		If this value is not null, an external user worker thread will be used.
		It acts as Proud.CStartLanServerParameter.m_externalUserWorkerThreadPool.

		\~chinese
		ó®?ÜôãÀnullîÜ?£¬ŞÅéÄèâİ»user worker thread¡£
		ÑÃó·? Proud.CStartLanServerParameter.m_externalUserWorkerThreadPool%ìé?îÜíÂéÄ¡£


		\~japanese
		ª³ªÎö·ª¬nullªÇªÏªÊª¤íŞùê¡¢èâİ» user worker threa ªòŞÅéÄª·ªŞª¹¡£
		Proud.CStartLanServerParameter.m_externalUserWorkerThreadPool ªÈÔÒª¸æµùÜªòª·ªŞª¹¡£

		*/
		CThreadPool* m_externalUserWorkerThreadPool;

		/**
		\~korean
		- OnException Äİ¹é ±â´ÉÀ» »ç¿ëÇÒ Áö ¿©ºÎ¸¦ ¼±ÅÃÇÕ´Ï´Ù.
		- ±âº»°ªÀº trueÀÔ´Ï´Ù.
		- ¸¸¾à false¸¦ ÁöÁ¤ÇÏ¸é À¯Àú Äİ¹é¿¡¼­ ¿¹»óÄ¡ ¸øÇÑ Exception ¹ß»ı ½Ã OnExceptionÀÌ È£ÃâµÇÁö ¾Ê°í Å©·¡½Ã°¡ ¹ß»ıÇÕ´Ï´Ù.

		\~english
		- Decide whether it uses OnException callback function or not.
		- Default value is true.
		- If setting it as false, when exception occurs during  user callback, crash will occur as OnException is not called.

		\~chinese
		- ??ãÀÜúŞÅéÄ OnException CallbackÍíÒö¡£
		- ĞñÜâ?? true¡£
		- åıÍıò¦ïÒfalse£¬éÄ?î¤Callback?ïïñé?ßæëòßÌÜôÓğîÜ Exception ?£¬OnException?Üôù¬û¼õó£¬ó¦?ßæCrash¡£

		\~japanese
		- OnException CallbackÑ¦ÒöªòŞÅéÄª¹ªëª«ªÉª¦ª«ªòàÔ?ª·ªŞª¹¡£
		- «Ç«Õ«©«ë«Èö·ªÏtrueªÇª¹¡£
		- ªâª·falseªòò¦ïÒª¹ªëªÈ«æ?«¶?Callbackª«ªéåøßÌªÇª­ªÊª¤Exceptionª¬?ßæª·ª¿ãÁ¡¢OnExceptionª¬û¼ªÓõóªµªìªºªË«¯«é«Ã«·«åª¬?ßæª·ªŞª¹¡£

		\~
		*/
		bool m_allowExceptionEvent;

		CDbCacheClient2ConnectParameter();
	};

	/**
	\~korean
	DB cache client2·ÎºÎÅÍÀÇ ÀÌº¥Æ® Äİ¹éÀ» ¹Ş±â À§ÇÑ delegate °´Ã¼

	\~english
	Delegate object to receive event callback from DB cache client

	\~chinese
	?Öõ?DB cache client2ÔğÓğeventüŞ?îÜîÜdelegate?ßÚ¡£

	\~japanese
	DB cache client2ª«ªéªÎ«¤«Ù«ó«È«³?«ë«Ğ«Ã«¯ªòáôª±ªëª¿ªáªÎdelegate«ª«Ö«¸«§«¯«È
	\~
	*/
	class IDbCacheClientDelegate2
	{
	public:
		/**
		\~korean
		ÀÌº¥Æ®°¡ Äİ¹éÇßÀ»¶§ÀÇ Arguments

		\~english
		Arguments when event called back

		\~chinese
		event üŞ?îÜ?ı¦îÜArguments¡£

		\~japanese
		«¤«Ù«ó«Èª¬«³?«ë«Ğ«Ã«¯ª·ª¿ãÁªÎArguments
		\~
		*/
		class CCallbackArgs
		{
		public:
			/**
			\~korean
			µ¥ÀÌÅÍ Æ®¸® 1°³¿¡ ´ëÇÑ Á¤º¸¸¦ ´ãÀº Å¬·¡½ºÀÔ´Ï´Ù.

			\~english
			This is a class containing the information on one data tree.

			\~chinese
			øĞùßìé??Ëß?ãáãÓîÜ?¡£

			\~japanese
			«Ç?«¿«Ä«ê?1ËÁªË?ª¹ªëï×ÜÃªòìıªìª¿«¯«é«¹ªÇª¹¡£

			\~
			*/
			class CItem
			{
			public:
				/**
				\~korean
				DBCacheClientÀÇ ¸Ş¼Òµåµé Áß message¸¦ ÀÎÀÚ·Î ¹Ş´Â ¿äÃ»µéÀº
				ÇØ´ç ¿äÃ»À¸·Î ÀÎÇØ ¿µÇâÀ» ¹Ş´Â ´Ù¸¥ Loader È¤Àº ¿äÃ»ÀÚ¿¡°Ô message¸¦ Àü´Ş ÇÒ ¼ö ÀÖ½À´Ï´Ù.
				±× message¸¦ Àü´Ş¹Ş´Â ÆÄ¶ó¸ŞÅÍ°¡ ¹Ù·Î ÀÌ°ÍÀÔ´Ï´Ù.

				\~english
				The requests receiving the message as a factor amongst the methods of DBCacheClient can deliver the message to another loader or the requester. 
				The parameter receiving the message is this.

				\~chinese
				î¤DBCacheClientîÜÛ°ÛöñéïÈâ¥á¼ãÓ??îÜ?Ï´Ê¦ì¤ú¾áôÓğ??Ï´ç¯?îÜĞìöâLoaderûä?Ï´íº?áêá¼ãÓ¡£
				ïÈâ¥?á¼ãÓîÜ??ö¦ãÀ??¡£

				\~japanese
				DBCacheClientªÎ«á«½«Ã«ÉªÎª¦ªÁmessageªòì×í­ªÇáôª±ªëé©ôëªÏ¡¢ú±?é©ôëªËªèªÃªÆç¯úÂªòáôª±ªëöâªÎ«í?«¿?ªŞª¿ªÏé©ôëíºªËmessageªò?Ó¹ª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
				ª½ªÎmessageªò?Ó¹ª·ªÆªâªéª¦«Ñ«é«á?«¿?ª¬ª¹ª°ª³ªìªÇª¹¡£

				\~
				*/
				ByteArray m_message;

				/**
				\~korean
				ÇØ´ç Callback°ú °ü·ÃµÈ µ¥ÀÌÅÍÀÇ SessionÀÔ´Ï´Ù.

				\~english
				The data session related to the Callback. 

				\~chinese
				??CallbackßÓ?îÜ?Ëß??¡£

				\~japanese
				ú±?CallbackªÈ?Ö§ªµªìª¿«Ç?«¿ªÎSessionªÇª¹¡£
				\~
				*/
				Guid m_sessionGuid;

				/**
				\~korean
				ÇØ´ç Callback°ú °ü·ÃµÈ µ¥ÀÌÅÍÀÇ RootUUID

				\~english
				The data RootUUID related to the Callback

				\~chinese
				??CallbackßÓ?îÜ?ËßîÜRootUUID

				\~japanese
				ú±?CallbackªÈ?Ö§ªµªìª¿«Ç?«¿ªÎRootUUID
				\~
				*/
				Guid m_rootUUID;

				/**
				\~korean
				- Ãß°¡,¾÷µ¥ÀÌÆ®, »èÁ¦½Ã¿¡ ÀÛ¾÷ÀÌ ¿Ï·áµÈ ÀüÃ¼ dataÀÇ ½º³À¼¦ (ÀÌ°ªÀ» º¯°æÇÏ´Â °ÍÀº ½ÇÁ¦ °ÔÀÓ Á¤º¸ ÀúÀå°ú ¾Æ¹«·± ¿¬°üÀÌ ¾ø½À´Ï´Ù.)
				- ÇØ´ç Callback°ú °ü·ÃµÈ µ¥ÀÌÅÍ Æ®¸®ÀÔ´Ï´Ù.

				\~english
				Snapshot of all completed data when you do add, update, remove (Changing this value does not affect saving actual game information)

				\~chinese
				ôÕÊ¥£¬ã®?£¬?ğ¶îÜ?ı¦ÍïíÂèÇà÷îÜîïİ»dataîÜsnapshot£¨ËÇ?ó®????êı?ãáãÓîÜ?ğí?êóìòù¼?Í§¡££©¡£

				\~japanese
				- õÚÊ¥¡¢«¢«Ã«×«Ç?«È¡¢Şûğ¶ãÁªËíÂåöª¬èÇÖõªµªìª¿îï?«Ç?«¿ªÎ«¹«Ê«Ã«×«·«ç«Ã«È(ª³ªÎö·ªò?ÌÚª¹ªëª³ªÈªÏ?ğ·«²?«àï×ÜÃªÎÜÁğíªÈù¼ªéªÎ?Ö§ª¬ª¢ªêªŞª»ªó)
				- ú±?CallbackªÈ?Ö§ªµªìª¿«Ç?«¿«Ä«ê?ªÇª¹¡£

				\~
				*/
				CLoadedData2Ptr m_loadedData;

				/**
				\~korean
				ÇØ´ç Callback°ú °ü·ÃÇÏ¿© º¯°æÀÌ ÀÏ¾î³­ ³ëµåÀÇ UUID

				\~english
				The UUID of the node where a change occurred related to the Callback

				\~chinese
				??CallbackßÓ?ìÚÑÃ?ÌÚîÜ?ïÃîÜUUID

				\~japanese
				ú±?CallbackªÈ?Ö§ª·ªÆ?ÌÚª¬ÑÃª­ª¿«Î?«ÉªÎUUDI
				\~
				*/
				Guid m_UUID;

				/**
				\~korean
				- Ãß°¡,¾÷µ¥ÀÌÆ®, »èÁ¦½Ã¿¡ ÀÛ¾÷ÀÌ ¿Ï·áµÈ ½ÇÀÛ¾÷ dataÀÇ ½º³À¼¦ (ÀÌ°ªÀ» º¯°æÇÏ´Â °ÍÀº ½ÇÁ¦ °ÔÀÓ Á¤º¸ ÀúÀå°ú ¾Æ¹«·± ¿¬°üÀÌ ¾ø½À´Ï´Ù.)
				- ÇØ´ç Callback°ú °ü·ÃµÈ ³ëµåÀÔ´Ï´Ù.

				\~english
				Snapshot of actual data when you do add, update, remove (Changing this value does not affect saving actual game information)

				\~chinese
				ôÕÊ¥£¬ã®?£¬?ğ¶îÜ?ı¦ÍïíÂèÇà÷îÜîïİ»dataîÜsnapshot£¨ËÇ?ó®????êı?ãáãÓîÜ?ğí?êóìòù¼?Í§¡££©¡£

				\~japanese
				- õÚÊ¥¡¢«¢«Ã«×«Ç?«È¡¢Şûğ¶ãÁªËíÂåöª¬èÇÖõªµªìª¿«ê«¢«ëíÂåö«Ç?«¿ªÎ«¹«Ê«Ã«×«·«ç«Ã«È(ª³ªÎö·ªò?ÌÚª¹ªëª³ªÈªÏ?ğ·«²?«àï×ÜÃªÎÜÁğíªÈù¼ªéªÎ?Ö§ª¬ª¢ªêªŞª»ªó)
				-¡¡ú±?CallbackªÈ?Ö§ªµªìª¿«Î?«ÉªÇª¹¡£

				\~
				*/
				CPropNodePtr m_data;

				/**
				\~korean
				- ½ÇÆĞ ½Ã ½ÇÆĞÇÑ »çÀ¯.
				- ¿äÃ»ÀÇ ¼º°ø/½ÇÆĞ ¿©ºÎ¸¦ ±¸ºĞÇÏ·Á¸é ÀÌ °ªÀÌ ErrorType_Ok°¡ ¾Æ´ÑÁö È®ÀÎÇØ¾ß ÇÕ´Ï´Ù.

				\~english
				- Reason for the failure when failed
				- whether the request has succeeded or failed should be determined, check to make sure whether this value is ErrorType_Ok or not. 

				\~chinese
				- ã÷?×âë¦¡£
				- ?İÂ?Ï´ãÀÜúà÷Ííñıîñ£¬âÍé©à»??ó®?ãÀÜúãÀErrorType_Ok¡£

				\~japanese
				- ã÷ø¨ãÁªËã÷ø¨ª·ª¿ŞÀë¦
				- é©ôëªÎà÷Íí/ã÷ø¨Ê¦Üúªò?İÂª¹ªëª¿ªáªËªÏ¡¢ª³ªÎö·ª¬ErrorType_OKªÇªÏªÊª¤ª«ü¬ìãª¹ªëù±é©ª¬ª¢ªêªŞª¹¡£

				\~
				*/
				ErrorType m_reason;

				/**
				\~korean
				½ÇÆĞ ½Ã °ü·Ã ÄÚ¸àÆ®

				\~english
				When it failed, comment about reason

				\~chinese
				ã÷??ã÷?îÜ??ñ¼?¡£

				\~japanese
				ã÷ø¨ãÁªÎ?Ö§«³«á«ó«È
				\~
				*/
				String m_comment;

				/**
				\~korean
				½ÇÆĞ½Ã¿¡ ³ª¿ÂHRESULT ÀÌ°ÍÀÌ S_OK¶ó¸é com_error·Î ½ÇÆĞÇÑ°ÍÀÌ ¾Æ´Õ´Ï´Ù.

				\~english
				HRESULT from when it failed. If it is S_OK, it is not failed with com_error

				\~chinese
				ã÷??õó?îÜHRESULTãÀS_OKîÜ?ÜôãÀcom_errorã÷?¡£

				\~japanese
				ã÷ø¨ãÁªËõóª¿HRESULT¡¡ª³ªìª¬S_OKªÊªécom_errorªÇã÷ø¨ª·ª¿ªÎªÇªÏª¢ªêªŞª»ªó¡£
				\~
				*/
				HRESULT m_hResult;

				/**
				\~korean
				½ÇÆĞ½Ã¿¡ ³ª¿Â source ÀÌ°ÍÀÌ ¾ø´Ù¸é Äõ¸®Áß ½ÇÆĞÇÑ°ÍÀÌ ¾Æ´Õ´Ï´Ù.

				\~english
				Source from when it failed. If it have not got this, it is not failed during quary

				\~chinese
				ã÷???êóõó?source£¬ö¦ÜôãÀî¤quary?ã÷?îÜ¡£

				\~japanese
				ã÷ø¨ãÁªËõóª¿source¡¡ª³ªìª¬ªÊª±ªìªĞ«¯«¨«ê?ñéªËã÷ø¨ª·ª¿ªÎªÇªÏª¢ªêªŞª»ªó¡£
				\~
				*/
				String m_source;

				CItem();
			};
			typedef CFastArray<CItem> Items;

			/**
			\~korean
			¿äÃ»¿¡ °ü·ÃµÈ µ¥ÀÌÅÍ Æ®¸®µéÀ» ´ãÀº ¸ñ·ÏÀÔ´Ï´Ù.
			¿¹¸¦µé¾î byQuery °è¿­ÀÇ ¿äÃ»µéÀº Äõ¸® Á¶°Ç¿¡ ¸Â´Â ¿©·¯ °³ÀÇ µ¥ÀÌÅÍ Æ®¸®µéÀ» ¹İÈ¯ÇÏ°Ô µÇ´Âµ¥
			ÀÌµéÀ» ¹Ş¾Æ Ã³¸®ÇÏ·Á¸é ÀÌ ¸ñ·ÏÀ» ¼øÈ¸ÇØ¾ß ÇÕ´Ï´Ù.

			\code
			// example
			void IDbCacheClientDelegate2::OnExclusiveLoadDataComplete(CCallbackArgs& args)
			{
			    for ( CLoadResults::iterator it=m_loadResults.begin(); it!=m_loadResults.end(); ++it )
			    {
			        CLoadResult& result = *it;
			        if ( result.m_reason == ErrorType_Ok )
			        {
			            // success
			        }
			        else
			        {
			            // fail
			        }
			    }
			    // ...
			}

			\endcode

			\~english
			This is the list containing the data trees related to the request. 
			. For example, the byQuery series requests return several data trees matching the query condition and to receive to process them, this list must be circulated. 


			\~chinese
			øĞùß?Ï´ßÓ??Ëß?îÜÖªøú¡£
			ÖÇåı£¬byQuery Í§ÖªîÜ?Ï´?Ú÷üŞİ¬ùê?ËìîÜÒı??Ëß?£¬?×â?ŞÁ?ËßâÍé©?Öªøú?ú¼âà?¡£

			\endcode

			\~japanese
			é©ôëªË?Ö§ª·ª¿«Ç?«¿«Ä«ê?ªò?ªáª¿«ê«¹«ÈªÇª¹¡£
			ÖÇª¨ªĞ¡¢byQueryÍ§ÖªªÎé©ôëªÏ«¯«¨«ê??ËìªËùêª¦ÜÜ?ªÎ«Ç?«¿«Ä«ê?ªòÚ÷ü½ª¹ªëªèª¦ªËªÊªêªŞª¹ª¬¡¢ª³ªìªòáôª±ªÆ?×âª¹ªëª¿ªáªËªÏª³ªÎ«ê«¹«ÈªòâŞüŞª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£

			\endcode

			\~

			\code
			// example
			void IDbCacheClientDelegate2::OnExclusiveLoadDataComplete(CCallbackArgs&args)
			{
				for ( CLoadResults::iterator it=m_loadResults.begin(); it!=m_loadResults.end(); ++it )
				{
					CLoadResult& result = *it;
					if ( result.m_reason == ErrorType_Ok )
					{
						// success
					}
					else
					{
						// fail
					}
				}
				// ...
			}
			\endcode
			*/
			Items m_items;

			/**
			\~korean
			¿äÃ» ½Ã È£ÃâÀÚ°¡ ³Ö¾ú´ø »ç¿ëÀÚ Á¤ÀÇ °ª. º¸ÅëÀº Æ÷ÀÎÅÍ·Î »ç¿ëµË´Ï´Ù.
			tag¸¦ ¹Ş´Â ¿äÃ»µéÀº È£Ãâ ½Ã ÀÔ·ÂÇÑ tag°ªÀ» ÀÀ´ä¿¡¼­ ÀÌ º¯¼ö¸¦ ÅëÇØ ±×´ë·Î µ¹·ÁÁİ´Ï´Ù.

			\~english
			User defined value that entered by invoker when it requested.
			Normally it uses for pointer. If you request with it then will receive same thing

			\~chinese
			é­??û¼Ğ£íº?ìıîÜéÄ?ïÒ?îÜ?¡£÷×ßÈÎÁéÄéÍpointer¡£ŞÅéÄ???õóé­?? ?ïÈâ¥ÔÒ?îÜüŞ?¡£

			\~japanese
			é©ôëãÁªËû¼õóíºª¬ìıªìª¿«æ?«¶?ïÒëùö·¡£ÜÅ÷×ªÏ«İ«¤«ó«¿?ªÇŞÅéÄªµªìªŞª¹¡£
			Tagªòáôª±ª¿é©ôëªÏû¼ªÓõóª·ãÁªËìıÕôª·ª¿tagö·ªò¡¢?ÓÍªÇª³ªÎ??ªò÷×ª¸ª½ªÎªŞªŞÚ÷ª·ªŞª¹¡£

			\~
			*/
			intptr_t m_tag;

			CCallbackArgs();
		};

		virtual ~IDbCacheClientDelegate2() {}

		/**
		\~korean
		¼­¹ö ¿¬°á ½Ãµµ °á°ú¸¦ ¸®ÅÏÇÕ´Ï´Ù.
		\param info ½ÇÆĞÇßÀ»¶§ÀÇ ½ÇÆĞÁ¤º¸ÀÔ´Ï´Ù. ¼º°ø½Ã¿¡´Â info.m_errorType ¿¡ ErrorType_Ok ÀÔ´Ï´Ù.

		\~english
		Returns the results of server connection attempts.
		\param info This is failed information. When it succeed, ErrorType_Ok will be in info.m_errorType.

		\~chinese
		Ú÷üŞÜ×?Ğï???ïÈîÜ?Íı¡£
		\param info ã÷??ı¥îÜã÷?ãáãÓ¡£à÷Íí?î¤ info.m_errorType%?ErrorType_Ok¡£

		\~japanese
		«µ?«Ğ?ïÈ?ãËª·ªÎÌ¿Íıªò«ê«¿?«óª·ªŞª¹¡£
		\param info ã÷ø¨ª·ª¿ãÁªÎã÷ø¨ï×ÜÃªÇª¹¡£à÷ÍíãÁªËªÏinfo.m_errorTypeªËErrorType_OkªÇª¹¡£

		\~
		*/
		virtual void OnJoinDbCacheServerComplete(ErrorInfo *info) = 0;

		/**
		\~korean
		DB cache server¿ÍÀÇ ¿¬°áÀÌ ÇØÁ¦µÆÀ½À» ³ëÆ¼ÇÕ´Ï´Ù.
		- ÀÌ°ÍÀÌ È£ÃâµÈ »óÈ²¿¡¼­´Â, ÀÌ¹Ì DB cache clientÀÇ ¸ğµç µ¥ÀÌÅÍ°¡ unloadµÈ »óÅÂÀÔ´Ï´Ù.
		\param reason ¿¬°áÇØÁ¦ »çÀ¯

		\~english
		Notifies that the connection to DB cache server is finished
		- Under the circumstance that this is called, all data in DB cache client is already unloaded.
		\param reason reason to disconnecting

		\~chinese
		÷×ò±?DB cache server îÜ?ïÈù¬ú°ğ¶Öõ¡£
		- ??ù¬û¼Ğ£îÜï×?ù»£¬DB cache client îÜá¶êó?Ëßì«?ãÀunloadîÜ??¡£
		\param reason ú°ğ¶?ïÈîÜ×âë¦¡£

		\~japanese
		DB cache serverªÈªÎïÈ?ª¬ú°ğ¶ªµªìª¿ª³ªÈªò÷×ò±ª·ªŞª¹¡£
		- ª³ªìª¬û¼ªÓõóªµªìª¿?üÏªÇªÏª¹ªÇªËDB cache clientªÎîïªÆªÎ«Ç?«¿ª¬unloadªµªìª¿?÷¾ªÇª¹¡£
		\param reason ïÈ?ú°ğ¶ŞÀë¦

		\~
		*/
		virtual void OnLeaveDbCacheServer(ErrorType reason) = 0;

		/**
		\~korean
		DB cache server¿¡¼­ DBMS¿¡ ±â·ÏÇÏ´Â °úÁ¤ÀÌ ³¡³¯ ¶§¸¶´Ù µµÂøÇÏ´Â ÀÌº¥Æ®ÀÔ´Ï´Ù.
		\param type ¾î¶²ÀÛ¾÷À» Çß´ÂÁö¿¡´ëÇÑ typeÀÔ´Ï´Ù.
		\param loadedDataGuid ¿Ï·áÇÑ ÀÛ¾÷ dataÀÇ GuidÀÔ´Ï´Ù.

		\~english
		Receiving event when writting process to DBMS on DB cache server.
		\param type Type for what process has done.
		\param loadedDataGuid Guid of finished work data

		\~chinese
		Øß??DB cache server ?áÖ?DBM???ïïîÜ?ı¦Óğ?îÜevent¡£
		\param type ãÀ?ñ®Öõä§?ÍïíÂîÜtype¡£
		\param loadedDataGuid ?áÖîÜÍïíÂdataîÜGuid¡£

		\~japanese
		DB cache serverªÇDBMSªËÑÀ?ª¹ªëÎ¦ïïª¬ğûªïªëãÁª´ªÈªËÓğó·ª¹ªë«¤«Ù«ó«ÈªÇª¹¡£
		\param type ªÉªóªÊíÂåöªòª·ª¿ªÎª«ªË?ª¹ªëtypeªÇª¹¡£
		\param loadedDataGuid èÇÖõª·ª¿íÂåö«Ç?«¿ªÎGuidªÇª¹¡£

		\~
		*/
		virtual void OnDbmsWriteDone(DbmsWritePropNodePendType type, Guid loadedDataGuid) = 0;

		/**
		\~korean
		- µ¶Á¡·Îµå ¿äÃ»¿¡ ´ëÇÑ ÀÀ´äÀÔ´Ï´Ù.
		- ¿äÃ» ½Ã ÀÔ·ÂÇÑ °Ë»ö Á¶°Ç¿¡ µû¶ó args.m_items¸¦ ÅëÇØ º¹¼öÀÇ µ¥ÀÌÅÍ Æ®¸®¸¦ ¹ŞÀ» ¼öµµ ÀÖ½À´Ï´Ù.
		- args.m_items¿¡´Â µ¶Á¡·Îµå¿¡ ¼º°øÇÑ °á°ú¿Í ½ÇÆĞÇÑ °á°ú°¡ ¼¯¿©ÀÖÀ» ¼ö ÀÖ´Âµ¥ CItem.m_reason°ªÀÌ ErrorType_OkÀÌ¸é ¼º°øÇÑ °á°úÀÔ´Ï´Ù.
		- ¼º°øÇÑ °æ¿ì CItem°´Ã¼ÀÇ ¸â¹öº¯¼ö Áß m_loadedData, m_data, m_sessionGuid, m_rootUUID, m_UUID, m_message¿¡ °ü·Ã Á¤º¸°¡ ±â·ÏµË´Ï´Ù.
		- ½ÇÆĞÇÑ °æ¿ì CItem°´Ã¼ÀÇ ¸â¹öº¯¼ö Áß m_reason, m_comment, m_UUID, m_hResult, m_message¿¡ °ü·Ã Á¤º¸°¡ ±â·ÏµË´Ï´Ù.
		- m_message´Â ÇØ´ç µ¥ÀÌÅÍ°¡ ÀÌ¹Ì µ¶Á¡µÇ¾îÀÖ´Â °æ¿ì ±âÁ¸ µ¶Á¡ÀÚ°¡ µ¶Á¡±Ç ÀÌ¾ç ¶Ç´Â °ÅºÎ¸¦ ÇÏ¸é¼­ ³Ñ±ä ¸Ş½ÃÁö°¡ ±â·ÏµË´Ï´Ù.
		- args.m_tag¿¡ ¿äÃ» ½Ã »ç¿ëÀÚ°¡ ÀÓÀÇ·Î ÀÔ·ÂÇß´ø tag°ªÀÌ ±×´ë·Î µ¹¾Æ¿À¹Ç·Î ÀÌ¸¦ ÅëÇØ ¾î¶² ¿äÃ»¿¡ ´ëÇÑ ÀÀ´äÀÎÁö ¾Ë ¼ö ÀÖ½À´Ï´Ù.

		\~english
		- This is the response for the exclusive load request. 
		- When requesting, you may receive multiple data trees through args.m_items depending on the input search conditions. 
		- args.m_items may have successful results and failed results mixed for exclusive load and if the value of CItem.m_reason is ErrorType_Ok, then this is a successful result. 
		- If successful, the related information is recorded in m_loadedData, m_data, m_sessionGuid, m_rootUUID, m_UUID and m_message among the member variables of the CItem object.
		- If failed, the related information is recorded in m_reason, m_comment, m_UUID, m_hResult and m_message among the member variable of the CItem object. 
		- When the data is already excluded, the message transmitted by the current excluder when it transfers or rejects the exclusivity is recorded in m_message.
		- When requesting to args.m_tag, the tag value input randomly by the user is returned as the original value so you can see this is a response to which request. 

		\~chinese
		- ????Ê¥??Ï´îÜ??¡£
		- ĞÆËß?Ï´??ìıîÜâ¤ßã?Ëì£¬î¢÷×?args.m_items?ÔğÒı??Ëß?¡£
		- args.m_itemsñéÊ¦ÒöøĞùßà÷ÍíîÜ?Íıûúã÷?îÜ?Íı£¬åıÍıCItem.m_reasonîÜ?? ErrorType_Ok£¬ö¦øúãÆà÷Íí¡£
		- åıÍıà÷Íí£¬CItem?ßÚîÜà÷??ÕáñéîÜm_loadedData, m_data, m_sessionGuid, m_rootUUID, m_UUID, m_message??ßÓ?ãáãÓ¡£
		- åıÍıã÷?£¬CItem?ßÚîÜà÷??ÕáñéîÜm_reason, m_comment, m_UUID, m_hResult, m_message??ßÓ?ãáãÓ¡£
		- ?îñîÜ??íº??ûäËŞ??????ßæîÜá¼ãÓ???Óğm_message¡£
		- ú¾args.m_tag?Ï´?£¬éÄ?ìòëò?ìıîÜtag??ê«?Ú÷üŞ£¬÷×???Ê¦ì¤ò±Ô³ãÀ??ìé??Ï´îÜ??¡£

		\~japanese
		- ?ï¿«í?«Éé©ôëªË?ª¹ªë?ÓÍªÇª¹¡£
		- é©ôëãÁªËìıÕôª·ª¿?ßã?ËìªËªèªÃªÆargs.m_itemsªò÷×ª¸ÜÜ?ªÎ«Ç?«¿«Ä«ê?ªòáôª±ªëª³ªÈªâªÇª­ªŞª¹¡£
		- args.m_itemsªËªÏ?ï¿«í?«ÉªËà÷Ííª·ª¿Ì¿ÍıªÈã÷ø¨ª·ª¿Ì¿Íıª¬ûèª¸ªÃªÆª¤ªëª³ªÈª¬ª¢ªêªŞª¹ª¬¡¢CItem.m_reasonö·ª¬ErrorType_OkªÇª¢ªìªĞà÷Ííª·ª¿Ì¿ÍıªÇª¹¡£
		- à÷Ííª·ª¿íŞùê¡¢CItem«ª«Ö«¸«§«¯«ÈªÎ«á«ó«Ğ???ªÎª¦ªÁ¡¢m_loadedData, m_data, m_sessionGuid, m_rootUUID, m_UUID, m_messageªË?Ö§ï×ÜÃª¬ÑÀ?ªµªìªŞª¹¡£
		- ã÷ø¨ª·ª¿íŞùê¡¢CItem«ª«Ö«¸«§«¯«ÈªÎ«á«ó«Ğ???ªÎª¦ªÁ¡¢m_reason, m_comment, m_UUID, m_hResult, m_messageªË?Ö§ï×ÜÃª¬ÑÀ?ªµªìªŞª¹¡£
		- m_messageªÏú±?«Ç?«¿ª¬?ªË?ï¿ªËªÊªÃªÆª¤ªëíŞùê¡¢?ğíªÎ?ï¿íºª¬?ï¿?ªÎì¹?ªŞª¿ªÏËŞÜúªòª·ªÊª¬ªéÔ¤ª·ª¿«á«Ã«»?«¸ª¬ÑÀ?ªµªìªŞª¹¡£
		- args.m_tagªËé©ôëãÁªË«æ?«¶?ª¬ìòëòªËìıÕôª·ª¿tagö·ª¬ª½ªÎªŞªŞ?ªÃªÆª­ªŞª¹ªÎªÇ¡¢ª³ªìªò÷×ª¸¡¢ªÉªóªÊé©ôëªË?ª¹ªë?ÓÍªÊªÎª«ò±ªìªŞª»ªó¡£


		\~
		*/
		virtual void OnExclusiveLoadDataComplete(CCallbackArgs& args) = 0;

		/**
		\~korean
		´Ù¸¥ DB cache client2°¡ <a target="_blank" href="http://guide.nettention.com/cpp_ko#exclusive_load" >µ¶Á¡Àû ºÒ·¯¿À±â</a> À» ½ÃµµÇÏ´Â ¹Ù¶÷¿¡ ÀÌ¹Ì ·ÎµùÇß´ø µ¥ÀÌÅÍÀÇ µ¶Á¡ Á¢±Ù ±ÇÇÑÀ» ¼Ò½ÇÇÒ °ÍÀÎÁö °áÁ¤ÇÒ¼ö ÀÖ´Â ÀÌº¥Æ® ÀÔ´Ï´Ù.
		- args.m_loadResults[index].m_loadedData ¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		- DbCacheClient ÀÇ DenyUnloadData ¸¦ Äİ ÇÏ°Å³ª, UnloadDataBySessionGuid ¸¦ ÄİÇÏ¿© µ¶Á¡±ÇÀ» ³Ñ°Ü ÁÙ°ÍÀÎÁö °áÁ¤ÇÒ¼ö ÀÖ½À´Ï´Ù.
		\param args IDbCacheClientDelegate2ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		This is event that decide losing exclusive loading or not because other DB cahce client2 tried <a target="_blank" href="http://guide.nettention.com/cpp_en#exclusive_load" >Exclusive Load</a>
		- Value will write to args.m_loadResults[index].m_loadedData
		- It can choose passing exclusive rights with calling DenyUnloadData or UnloadDataBySessionGuid in DbCacheClient
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		ì×?ĞìöâDB cache client2?? <a target="_blank" href="http://guide.nettention.com/cpp_zh#exclusive_load" >?ï¿àõìÚìı</a>%£¬?ïÒãÀÜú?ã÷ì«?Ê¥?îÜ?Ëß?ï¿ïÈĞÎ?ùÚîÜevent¡£
		-?õö?Óğ args.m_loadResults[index].m_loadedData¡£
		- Ê¦ì¤? DbCacheClientîÜDenyUnloadData%ûäíº? UnloadDataBySessionGuid%£¬?ïÒãÀÜúáêõó?ï¿?¡£
		\param args IDbCacheClientDelegate2ãÀeventîÜargument?ğã?¡£?ÍÅ\ref CcallbackArgs%¡£

		\~japanese
		öâªÎDB cache client2ª¬\ref exclusive_loadªòãËª·ª¿ª¿ªá¡¢?ªË«í?«Ç«£«ó«°ª·ª¿«Ç?«¿ªÎ?ï¿«¢«¯«»«¹?ùÚªòá¼ã÷ª¹ªëª«ªÉª¦ª«ªòÌ½ïÒªÇª­ªë«¤«Ù«ó«ÈªÇª¹¡£
		- args.m_loadResults[index].m_loadedDataªËö·ª¬?ª¿ªµªìªŞª¹¡£
		- DbCacheClientªÎDenyUnloadDataªòû¼ªÓõóª¹ª«¡¢UnloadDataBySessionGuidªòû¼ªÓõóª·ªÆ?ï¿?ªòÔ¤ª¹ª«ªÉª¦ª«ªòÌ½ïÒª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
		\param args IDbCacheClientDelegate2ªÎ«¤«Ù«ó«ÈargumentÏ°ğã?ªÇª¹¡£?ÍÅ \ref CCallbackArgs

		*/
		virtual void OnDataUnloadRequested(CCallbackArgs& args) = 0;

		/**
		\~korean
		Æ¯Á¤ µ¥ÀÌÅÍ°¡ ¼­¹ö·ÎºÎÅÍ °­Á¦·Î Unload µÇ¾úÀ» ¶§ ¹ß»ıÇÏ´Â ÀÌº¥Æ®ÀÔ´Ï´Ù.
		ÇöÀç µ¶Á¡·Îµå ÁßÀÎ µ¥ÀÌÅÍ¿¡ ¶Ç´Ù¸¥ µ¶Á¡¿äÃ»ÀÌ µé¾î¿À´Â °æ¿ì OnDataUnloadRequested()°¡ Äİ¹éµÇÁö¸¸,
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache°¡ ´Ù·ç´Â µ¥ÀÌÅÍ¸¦ DB°¡ Á÷Á¢ ¾ï¼¼½ºÇÏ±â</a> ¸¦ ÇÏ·Á°í ÇÏ´Â °æ¿ì¿¡´Â ºÒ°¡ÇÇÇÏ°Ô ÀÌ ÇÔ¼ö°¡ Äİ¹éµË´Ï´Ù.

		\~english
		This is the event when particular data is forcibly unloaded from the server.
		If another exclusivity request is received by the data exclusively loaded currently, OnDataUnloadRequested() is called back, but
		If \ref dbc2_isolate_overview is attempted, inevitably this function is called back. 

		\~chinese
		?÷åïÒ?Ëß?Ü×?ĞïË­ğ¤ß¾???ßæîÜŞÀËì¡£
		????îñì«ù¬??ñéîÜ?Ëß?õóĞìöâîÜ???Ï´£¬ö¦?üŞ?OnDataUnloadRequested()£¬åıÍıé©?ú¼\ref dbc2_isolate_overview £¬ ?ÜôÊ¦ù­Øóò¢üŞ?ó®ùŞ?¡£

		\~japanese
		÷åïÒ«Ç?«¿ª¬«µ?«Ğ?ª«ªé?ğ¤ªËUnloadªµªìª¿ãÁªË?ßæª¹ªë«¤«Ù«ó«ÈªÇª¹¡£
		úŞî¤?ï¿«í?«ÉñéªÇª¢ªë«Ç?«¿ªËªŞª¿êŞª¦?ï¿é©ôëª¬ìıªëíŞùê¡¢ OnDataUnloadRequested()ª¬«³?«ë«Ğ«Ã«¯ªµªìªŞª¹ª¬¡¢
		\ref dbc2_isolate_overview ªòª·ªèª¦ªÈª¹ªëíŞùêªËªÏªäªàªòÔğªºªËª³ªÎ??ª¬«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£

		*/
		virtual void OnDataForceUnloaded(CCallbackArgs& args) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache°¡ ´Ù·ç´Â µ¥ÀÌÅÍ¸¦ DB°¡ Á÷Á¢ ¾ï¼¼½ºÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù.
		Proud.CDbCacheClient2.RequestIsolateData() ½ÇÇà ¼º°øÀ» ¾Ë¸³´Ï´Ù.
		args¿¡´Â m_rootUUID, m_data, m_sessionGuid°¡ Ã¤¿öÁı´Ï´Ù.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_isolate_overview" >DB directly has access to data that DB cache deals with </a> function.
		Proud.CDbCacheClient2.RequestIsolateData() inform you of execution success.
		m_rootUUID, m_data and m_sessionGuid are included in args.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_isolate_overview" >DBòÁïÈ??DB cacheğÃíÂîÜ?Ëß</a> ÍíÒö¡£
		Í±ò±Proud.CDbCacheClient2.RequestIsolateData() ?ú¼à÷Íí¡£
		î¤argsñé??õö m_rootUUID, m_data, m_sessionGuid¡£

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_isolate_overview" >DB cacheª¬ğÃªë«Ç?«¿ªòDBª¬òÁïÈ«¢«¯«»«¹</a>Ñ¦ÒöªÇª¹¡£
		Proud.CDbCacheClient2.RequestIsolateData()?ú¼ªÎà÷Ííªòò±ªéª»ªŞª¹¡£
		ArgsªËªÏm_rootUUID, m_data, m_sessionGuidª¬ØØªáªéªìªŞª¹¡£
		*/
		virtual void OnIsolateDataSuccess(CCallbackArgs& args) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache°¡ ´Ù·ç´Â µ¥ÀÌÅÍ¸¦ DB°¡ Á÷Á¢ ¾ï¼¼½ºÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù.
		Proud.CDbCacheClient2.RequestIsolateData() ½ÇÇà ½ÇÆĞ¸¦ ¾Ë¸³´Ï´Ù.
		args¿¡´Â m_rootUUID, m_data, m_sessionGuid°¡ Ã¤¿öÁı´Ï´Ù.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_isolate_overview" >DB directly has access to data that DB cache deals with </a> function.
		Proud.CDbCacheClient2.RequestIsolateData() inform you of execution failure.
		m_rootUUID, m_data and m_sessionGuid are included in args.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_isolate_overview" >DBòÁïÈ??DB cacheğÃíÂîÜ?Ëß</a> ÍíÒö¡£
		Í±ò±Proud.CDbCacheClient2.RequestIsolateData() ?ú¼ã÷?¡£
		î¤args??õö m_rootUUID, m_data, m_sessionGuid¡£

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_isolate_overview" >DB cacheª¬ğÃªë«Ç?«¿ªòDBª¬òÁïÈ«¢«¯«»«¹</a>Ñ¦ÒöªÇª¹¡£
		Proud.CDbCacheClient2.RequestIsolateData() ?ú¼ªÎã÷ø¨ªòò±ªéª»ªŞª¹¡£
		ArgsªËªÏm_rootUUID, m_data, m_sessionGuidª¬ØØªáªéªìªŞª¹¡£
		*/
		virtual void OnIsolateDataFailed(CCallbackArgs& args) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache°¡ ´Ù·ç´Â µ¥ÀÌÅÍ¸¦ DB°¡ Á÷Á¢ ¾ï¼¼½ºÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù.
		Proud.CDbCacheClient2.RequestDeisolateData() ½ÇÇà ¼º°øÀ» ¾Ë¸³´Ï´Ù.
		args¿¡´Â m_rootUUID, m_data, m_sessionGuid°¡ Ã¤¿öÁı´Ï´Ù.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_isolate_overview" >DB directly has access to data that DB cache deals with </a> function.
		Proud.CDbCacheClient2.RequestDeisolateData() inform you of execution success.
		m_rootUUID, m_data and m_sessionGuid are included in args.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_isolate_overview" >DBòÁïÈ??DB cacheğÃíÂîÜ?Ëß</a> ÍíÒö¡£
		Í±ò±Proud.CDbCacheClient2.RequestDeisolateData() ?ú¼à÷Íí¡£
		î¤argsñé??õö m_rootUUID, m_data, m_sessionGuid¡£

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_isolate_overview" >DB cacheª¬ğÃªë«Ç?«¿ªòDBª¬òÁïÈ«¢«¯«»«¹</a>Ñ¦ÒöªÇª¹¡£
		Proud.CDbCacheClient2.RequestDeisolateData() ?ú¼ªÎà÷Ííªòò±ªéª»ªŞª¹¡£
		ArgsªËªÏ m_rootUUID, m_data, m_sessionGuidª¬ØØªáªéªìªŞª¹¡£
		*/
		virtual void OnDeisolateDataSuccess(CCallbackArgs& args) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache°¡ ´Ù·ç´Â µ¥ÀÌÅÍ¸¦ DB°¡ Á÷Á¢ ¾ï¼¼½ºÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù.
		Proud.CDbCacheClient2.RequestDeisolateData() ½ÇÇà ½ÇÆĞ¸¦ ¾Ë¸³´Ï´Ù.
		args¿¡´Â m_rootUUID, m_data, m_sessionGuid°¡ Ã¤¿öÁı´Ï´Ù.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_isolate_overview" >DB directly has access to data that DB cache deals with </a> function.
		Proud.CDbCacheClient2.RequestDeisolateData() inform you of execution failure.
		m_rootUUID, m_data and m_sessionGuid are included in args.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_isolate_overview" >DBòÁïÈ??DB cacheğÃíÂîÜ?Ëß</a> ÍíÒö¡£
		Í±ò±Proud.CDbCacheClient2.RequestDeisolateData() ?ú¼ã÷?¡£
		î¤argsñé??õö m_rootUUID, m_data, m_sessionGuid¡£

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_isolate_overview" >DB cacheª¬ğÃªë«Ç?«¿ªòDBª¬òÁïÈ«¢«¯«»«¹</a>Ñ¦ÒöªÇª¹¡£
		Proud.CDbCacheClient2.RequestDeisolateData()?ú¼ªÎã÷ø¨ªòò±ªéª»ªŞª¹¡£.
		ArgsªËªÏ m_rootUUID, m_data, m_sessionGuidª¬ØØªáªéªìªŞª¹¡£
		*/
		virtual void OnDeisolateDataFailed(CCallbackArgs& args) = 0;

		/**
		\~korean
		CDbCacheClient2.RequestAddData, CDbCacheClient2.BlockedAddData ¿¡¼­ ½ÇÆĞÇßÀ»¶§ µµÂøÇÏ´Â ÀÌº¥Æ®ÀÔ´Ï´Ù.
		- args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		This event will arrive when it failed in CDbCacheClient2.RequestAddData or CDbCacheClient2.BlockedAddData
		- Value will write to args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		î¤ CDbCacheClient2.RequestAddData, CDbCacheClient2.BlockedAddData%ã÷??Óğ?îÜEvent¡£
		- ?õö?Óğ args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment¡£
		\param args IDbCacheClientDelegate2%îÜŞÀËìargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		CDbCacheClient2.RequestAddData, CDbCacheClient2.BlockedAddDataªÇã÷ø¨ª·ª¿ãÁªËÓğó·ª¹ªë«¤«Ù«ó«ÈªÇª¹¡£
		- args.m_loadResults[index].m_reason,args.m_loadResults[index].m_commentªËö·ª¬?ª¿ªµªìªŞª¹¡£
		\param args IDbCacheClientDelegate2ªÎ«¤«Ù«ó«ÈargumentªÎÏ°ğã?ªÇª¹¡£?ÍÅ \ref CCallbackArgs

		\~
		*/
		virtual void OnAddDataFailed(CCallbackArgs& args) = 0;

		/**
		\~korean
		CDbCacheClient2.RequestAddData, CDbCacheClient2.BlockedAddData ¿¡¼­ ¼º°øÇßÀ»¶§ µµÂøÇÏ´Â ÀÌº¥Æ®ÀÔ´Ï´Ù.
		- args.m_loadResults[index].m_loadedData,args.m_loadResults[index].m_data¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		This event will arrive when it succeed in CDbCacheClient2.RequestAddData or CDbCacheClient2.BlockedAddData
		- Value will write to args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		î¤ CDbCacheClient2.RequestAddData, CDbCacheClient2.BlockedAddData%à÷Íí?Óğ?îÜevent¡£
		- èÙ args.m_loadResults[index].m_loadedData,args.m_loadResults[index].m_data ?õö?¡£
		\param args IDbCacheClientDelegate2ãÀeventîÜargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		CDbCacheClient2.RequestAddData, CDbCacheClient2.BlockedAddData ªÇà÷Ííª·ª¿ãÁªËÓğó·ª¹ªë«¤«Ù«ó«ÈªÇª¹¡£
		- args.m_loadResults[index].m_loadedData,args.m_loadResults[index].m_dataªËö·ª¬?ª¿ªµªìªŞª¹¡£
		\param args IDbCacheClientDelegate2ªÎ«¤«Ù«ó«ÈargumentÏ°ğã?ªÇª¹¡£?ÍÅ \ref CCallbackArgs

		*/
		virtual void OnAddDataSuccess(CCallbackArgs& args) = 0;

		/**
		\~korean
		\ref OnAddDataFailed Âü°í.
		- args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		Refer to OnAddDataFailed
		- Value will write to args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		?ÍÅ\ref OnAddDataFailed%¡£
		- ?õö?Óğ args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment¡£
		\param args IDbCacheClientDelegate2ãÀeventîÜargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		\ref OnAddDataFailed ?ÍÅ
		- args.m_loadResults[index].m_reason,args.m_loadResults[index].m_commentªËö·ª¬?ª¿ªµªìªŞª¹¡£
		\param args IDbCacheClientDelegate2ªÎ«¤«Ù«ó«ÈargumentÏ°ğã?ªÇª¹¡£?ÍÅ \ref CCallbackArgs

		\~
		*/
		virtual void OnUpdateDataFailed(CCallbackArgs& args) = 0;

		/**
		\~korean
		\ref OnAddDataSuccess Âü°í.
		-  args.m_loadResults[index].m_loadedData,args.m_loadResults[index].m_data¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		Refer to OnAddDataSuccess
		- Value will write to args.m_loadResults[index].m_loadedData,args.m_loadResults[index].m_data
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		?ÍÅ \ref OnAddDataSuccess%¡£
		-?õö?Óğ args.m_loadResults[index].m_loadedData,args.m_loadResults[index].m_data¡£
		\param args IDbCacheClientDelegate2%ãÀeventîÜargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		\ref OnAddDataSuccess ?ÍÅ
		-  args.m_loadResults[index].m_loadedData,args.m_loadResults[index].m_dataªËö·ª¬?ª¿ªµªìªŞª¹¡£
		\param args IDbCacheClientDelegate2ªÎ«¤«Ù«ó«ÈargumentÏ°ğã?ªÇª¹¡£?ÍÅ \ref CCallbackArgs

		\~
		*/
		virtual void OnUpdateDataSuccess(CCallbackArgs& args) = 0;

		/**
		\~korean
		\ref OnAddDataFailed Âü°í.
		-  args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		Refer to OnAddDataFailed
		- Value will write to args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		?ÍÅ \ref OnAddDataFailed%¡£
		- ?õö?Óğ args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment¡£
		\param args IDbCacheClientDelegate2%ãÀeventîÜargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		\ref OnAddDataFailed ?ÍÅ
		-  args.m_loadResults[index].m_reason,args.m_loadResults[index].m_commentªËö·ª¬?ª¿ªµªìªŞª¹¡£
		\param args IDbCacheClientDelegate2ªÎ«¤«Ù«ó«ÈargumentÏ°ğã?ªÇª¹¡£?ÍÅ \ref CCallbackArgs

		\~
		*/
		virtual void OnRemoveDataFailed(CCallbackArgs& args) = 0;

		/**
		\~korean
		\ref OnAddDataFailed Âü°í.
		-  args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		Refer to OnAddDataFailed
		- Value will write to args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		?ÍÅ \ref OnAddDataFailed%¡£
		-?õö?Óğ args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment¡£
		\param args IDbCacheClientDelegate2%ãÀeventîÜargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		\ref OnAddDataFailed ?ÍÅ
		-  args.m_loadResults[index].m_reason,args.m_loadResults[index].m_commentªËö·ª¬?ª¿ªµªìªŞª¹¡£
		\param args IDbCacheClientDelegate2ªÎ«¤«Ù«ó«ÈargumentÏ°ğã?ªÇª¹¡£?ÍÅ \ref CCallbackArgs

		\~
		*/
		virtual void OnRemoveDataSuccess(CCallbackArgs& args) = 0;

		/**
		\~korean
		- ºñµ¶Á¡ Á¶È¸ ¿äÃ»¿¡ ´ëÇÑ ÀÀ´äÀÔ´Ï´Ù.
		- ¿äÃ» ½Ã ÀÔ·ÂÇÑ °Ë»ö Á¶°Ç¿¡ µû¶ó args.m_items¸¦ ÅëÇØ º¹¼öÀÇ µ¥ÀÌÅÍ Æ®¸®¸¦ ¹ŞÀ» ¼öµµ ÀÖ½À´Ï´Ù.
		- args.m_items¿¡´Â Á¶È¸¿¡ ¼º°øÇÑ °á°ú¿Í ½ÇÆĞÇÑ °á°ú°¡ ¼¯¿©ÀÖÀ» ¼ö ÀÖ´Âµ¥ CItem.m_reason°ªÀÌ ErrorType_OkÀÌ¸é ¼º°øÇÑ °á°úÀÔ´Ï´Ù.
		- ¼º°øÇÑ °æ¿ì CItem°´Ã¼ÀÇ ¸â¹öº¯¼ö Áß m_loadedData, m_data, m_sessionGuid, m_rootUUID, m_UUID¿¡ °ü·Ã Á¤º¸°¡ ±â·ÏµË´Ï´Ù.
		- ½ÇÆĞÇÑ °æ¿ì CItem°´Ã¼ÀÇ ¸â¹öº¯¼ö Áß m_reason, m_comment, m_UUID, m_hResult¿¡ °ü·Ã Á¤º¸°¡ ±â·ÏµË´Ï´Ù.
		- args.m_tag¿¡ ¿äÃ» ½Ã »ç¿ëÀÚ°¡ ÀÓÀÇ·Î ÀÔ·ÂÇß´ø tag°ªÀÌ ±×´ë·Î µ¹¾Æ¿À¹Ç·Î ÀÌ¸¦ ÅëÇØ ¾î¶² ¿äÃ»¿¡ ´ëÇÑ ÀÀ´äÀÎÁö ¾Ë ¼ö ÀÖ½À´Ï´Ù.

		\~english
		- This is the request for the nonexclusive search request. 
		- When requesting, you may receive multiple data trees through args.m_items depending on the input search conditions
		- args.m_items may have successful results and failed results mixed for search success and if the value of CItem.m_reason is ErrorType_Ok, then this is a successful result.
		- If successful, the related information is recorded in m_loadedData, m_data, m_sessionGuid, m_rootUUID and m_UUID among the member variables of the CItem object.
		- If failed, the related information is recorded in m_reason, m_comment, m_UUID and m_hResult among the member variable of the CItem object.
		- When requesting to args.m_tag, the tag value input randomly by the user is returned as the original value so you can see this is a response to which request.


		\~chinese
		- ??Şª?????Ï´îÜ??¡£
		- ĞÆËß?Ï´??ìıîÜâ¤ßã?Ëì£¬î¢÷×?args.m_items?ÔğÒı??Ëß?¡£
		- args.m_itemsñéÊ¦ÒöøĞùßà÷ÍíîÜ?Íıûúã÷?îÜ?Íı£¬åıÍıCItem.m_reasonîÜ?? ErrorType_Ok£¬ö¦øúãÆà÷Íí¡£
		- åıÍıà÷Íí£¬CItem?ßÚîÜà÷??ÕáñéîÜm_loadedData, m_data, m_sessionGuid, m_rootUUID, m_UUID, m_message??ßÓ?ãáãÓ¡£
		- åıÍıã÷?£¬CItem?ßÚîÜà÷??ÕáñéîÜm_reason, m_comment, m_UUID, m_hResult, m_message??ßÓ?ãáãÓ¡£
		- ú¾args.m_tag?Ï´?£¬éÄ?ìòëò?ìıîÜtag??ê«?Ú÷üŞ£¬÷×???Ê¦ì¤ò±Ô³ãÀ??ìé??Ï´îÜ??¡£

		\~japanese
		- Şª?ï¿ğÎ?é©ôëªË?ª¹ªë?ÓÍªÇª¹¡£
		- é©ôëãÁªËìıÕôª·ª¿?ßã?ËìªËªèªÃªÆargs.m_itemsªò÷×ª¸ÜÜ?ªÎ«Ç?«¿«Ä«ê?ªòáôª±ªëª³ªÈªâªÇª­ªŞª¹¡£
		- args.m_itemsªËªÏğÎ?ªËà÷Ííª·ª¿Ì¿ÍıªÈã÷ø¨ª·ª¿Ì¿Íıª¬ûèª¸ªéªìªŞª¹ª¬¡¢CItem.m_reasonö·ª¬ErrorType_OkªÇª¢ªìªĞà÷Ííª·ª¿Ì¿ÍıªÇª¹¡£
		- à÷Ííª·ª¿íŞùê¡¢CItem«ª«Ö«¸«§«¯«ÈªÎ«á«ó«Ğ???ªÎª¦ªÁ¡¢m_loadedData, m_data, m_sessionGuid, m_rootUUID, m_UUIDªË?Ö§ï×ÜÃª¬ÑÀ?ªµªìªŞª¹¡£
		- ã÷ø¨ª·ª¿íŞùê¡¢CItem«ª«Ö«¸«§«¯«ÈªÎ«á«ó«Ğ???ªÎª¦ªÁ¡¢m_reason, m_comment, m_UUID, m_hResultªË?Ö§ï×ÜÃª¬ÑÀ?ªµªìªŞª¹¡£	
		- args.m_tagªËé©ôëãÁªË«æ?«¶?ª¬ìòëòªËìıÕôª·ª¿tagö·ª¬ª½ªÎªŞªŞ?ªÃªÆª¯ªëªÎªÇ¡¢ª³ªìªò÷×ª¸ªÉªóªÊé©ôëªË?ª¹ªë?ÓÍªÊªÎª«ò±ªéªìªŞª¹¡£

		\~
		*/
		virtual void OnNonExclusiveSnapshotDataComplete(CCallbackArgs& args) { args; }

		/**
		\~korean
		ºñµ¶Á¡Àû Á¢±Ù¿¡ ´ëÇÑ Äİ¹é. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> Âü°í.
		- ½ÇÆĞ½Ã¿£  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		- ¼º°ø½Ã¿£  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2 ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment when it succeed.
		- Value will write in to args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data when it failed.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?Şª?ï¿àõïÈĞÎîÜüŞ?¡£??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%¡£
		- ã÷???õö?Óğ  args.m_loadResults[index].m_reason,args.m_loadResults[index].m_comment¡£
		- à÷Íí??õö?Óğ  args.m_loadResults[index].m_rootUUID,args.m_loadResults[index].m_data¡£
		\param args IDbCacheClientDelegate2%ãÀeventîÜargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		Şª?ï¿îÜïÈĞÎªË?ª¹ªë«³?«ë«Ğ«Ã«¯ <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?ÍÅ
		- ã÷ø¨ãÁªËªÏ  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_commentªËö·ª¬ØØªáªéªìªŞª¹¡£
		- à÷ÍíãÁªËªÏ  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_removeUUIDªËö·ª¬ØØªáªéªìªŞª¹¡£
		\param args IDbCacheClientDelegate2 ªÎ«¤«Ù«ó«È argument Ï°ğã?ªÇª¹¡£ ?ÍÅ \ref CCallbackArgs

		\~
		*/
		virtual void OnNonExclusiveAddDataAck(CCallbackArgs& args) { args; }

		/**
		\~korean
		ºñµ¶Á¡Àû Á¢±Ù¿¡ ´ëÇÑ Äİ¹é. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> Âü°í.
		- ½ÇÆĞ½Ã¿£  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		- ¼º°ø½Ã¿£  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_removeUUID¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2 ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment when it succeed.
		- Value will write in to args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data when it failed.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?Şª?ï¿àõïÈĞÎîÜüŞ?¡£??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%¡£
		- ã÷???õö?Óğ  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment¡£
		- à÷Íí??õö?Óğ  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_removeUUID¡£
		\param args IDbCacheClientDelegate2ãÀeventîÜargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		Şª?ï¿îÜïÈĞÎªË?ª¹ªë«³?«ë«Ğ«Ã«¯<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>?ÍÅ
		- ã÷ø¨ãÁªËªÏ  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_commentªËö·ª¬ØØªáªéªìªŞª¹¡£
		- à÷ÍíãÁªËªÏ  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_removeUUIDªËö·ª¬ØØªáªéªìªŞª¹¡£
		\param args IDbCacheClientDelegate2 ªÎ«¤«Ù«ó«È argument Ï°ğã?ªÇª¹¡£ ?ÍÅ \ref CCallbackArgs


		\~
		*/
		virtual void OnNonExclusiveRemoveDataAck(CCallbackArgs& args) { args; }


		/**
		\~korean
		ºñµ¶Á¡Àû Á¢±Ù¿¡ ´ëÇÑ Äİ¹é. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> Âü°í.
		-  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2 ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?Şª?ï¿àõïÈĞÎîÜüŞ?¡£??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%¡£
		- ?õö?Óğ  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data¡£
		\param args IDbCacheClientDelegate2%ãÀeventîÜargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		Şª?ï¿îÜïÈĞÎªË?ª¹ªë«³?«ë«Ğ«Ã«¯ <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?ÍÅ
		-  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_dataªËö·ª¬ØØªáªéªìªŞª¹¡£
		\param args IDbCacheClientDelegate2 ªÎ«¤«Ù«ó«Èargument Ï°ğã?ªÇª¹¡£ ?ÍÅ \ref CCallbackArgs

		\~
		*/
		virtual void OnNonExclusiveModifyValueSuccess(CCallbackArgs& args) { args; }

		/**
		\~korean
		ºñµ¶Á¡Àû Á¢±Ù¿¡ ´ëÇÑ Äİ¹é. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> Âü°í.
		-  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2 ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?Şª?ï¿àõïÈĞÎîÜüŞ?¡£??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%¡£
		- ?õö?Óğ  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment¡£
		\param args IDbCacheClientDelegate2%îÜŞÀËìargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		Şª?ï¿îÜïÈĞÎªË?ª¹ªë«³?«ë«Ğ«Ã«¯ <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?ÍÅ
		-  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_commentªËö·ª¬ØØªáªéªìªŞª¹¡£
		\param args IDbCacheClientDelegate2 ªÎ«¤«Ù«ó«Èargument Ï°ğã?ªÇª¹¡£ ?ÍÅ \ref CCallbackArgs

		\~
		*/
		virtual void OnNonExclusiveModifyValueFailed(CCallbackArgs& args) { args; }

		/**
		\~korean
		ºñµ¶Á¡Àû Á¢±Ù¿¡ ´ëÇÑ Äİ¹é. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> Âü°í.
		-  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2 ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?Şª?ï¿àõïÈĞÎîÜüŞ?¡£??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%¡£
		- ?õö?Óğ  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_data¡£
		\param args IDbCacheClientDelegate2%îÜŞÀËìargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		Şª?ï¿îÜïÈĞÎªË?ª¹ªë«³?«ë«Ğ«Ã«¯ <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?ÍÅ
		-  args.m_loadResults[index].m_rootUUID, args.m_loadResults[index].m_dataªËö·ª¬ØØªáªéªìªŞª¹¡£
		\param args IDbCacheClientDelegate2 ªÎ«¤«Ù«ó«Èargument Ï°ğã?ªÇª¹¡£ ?ÍÅ \ref CCallbackArgs

		\~
		*/
		virtual void OnNonExclusiveSetValueIfSuccess(CCallbackArgs& args) { args; }

		/**
		\~korean
		ºñµ¶Á¡Àû Á¢±Ù¿¡ ´ëÇÑ Äİ¹é. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> Âü°í.
		-  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2 ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?Şª?ï¿àõïÈĞÎîÜüŞ?¡£??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%¡£
		- ?õö?Óğ  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_comment¡£
		\param args IDbCacheClientDelegate2%îÜŞÀËìargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		Şª?ï¿îÜïÈĞÎªË?ª¹ªë«³?«ë«Ğ«Ã«¯ <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?ÍÅ
		-  args.m_loadResults[index].m_reason, args.m_loadResults[index].m_commentªËö·ª¬ØØªáªéªìªŞª¹¡£
		\param args IDbCacheClientDelegate2 ªÎ«¤«Ù«ó«Èargument Ï°ğã?ªÇª¹¡£ ?ÍÅ \ref CCallbackArgs

		\~
		*/
		virtual void OnNonExclusiveSetValueIfFailed(CCallbackArgs& args) { args; }

		/**
		\~korean
		ºñµ¶Á¡Àû Á¢±Ù¿¡ ´ëÇÑ Äİ¹é. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> Âü°í.
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data, args.m_loadResults[index].m_message¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2 ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_loadedData and args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?Şª?ï¿àõïÈĞÎîÜüŞ?¡£??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%¡£
		- ?õö?Óğ args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data, args.m_loadResults[index].m_message¡£
		\param args IDbCacheClientDelegate2îÜŞÀËìargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		Şª?ï¿îÜïÈĞÎªË?ª¹ªë«³?«ë«Ğ«Ã«¯ <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?ÍÅ
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data, args.m_loadResults[index].m_messageªËö·ª¬ØØªáªéªìªŞª¹¡£
		\param args IDbCacheClientDelegate2 ªÎ«¤«Ù«ó«Èargument Ï°ğã?ªÇª¹¡£ ?ÍÅ \ref CCallbackArgs

		\~
		*/
		virtual void OnSomeoneAddData(CCallbackArgs& args) { args; }

		/**
		\~korean
		ºñµ¶Á¡Àû Á¢±Ù¿¡ ´ëÇÑ Äİ¹é. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> Âü°í.
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data, args.m_loadResults[index].m_message¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2 ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_loadedData and args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?Şª?ï¿àõïÈĞÎîÜüŞ?¡£??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%¡£
		- ?õö?Óğ args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message¡£
		\param args IDbCacheClientDelegate2%ãÀeventîÜargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		Şª?ï¿îÜïÈĞÎªË?ª¹ªë«³?«ë«Ğ«Ã«¯ <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?ÍÅ
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data,  args.m_loadResults[index].m_messageªËö·ª¬ØØªáªéªìªŞª¹¡£
		\param args IDbCacheClientDelegate2 ªÎ«¤«Ù«ó«Èargument Ï°ğã?ªÇª¹¡£ ?ÍÅ \ref CCallbackArgs

		\~
		*/
		virtual void OnSomeoneRemoveData(CCallbackArgs& args) { args; }

		/**
		\~korean
		ºñµ¶Á¡Àû Á¢±Ù¿¡ ´ëÇÑ Äİ¹é. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> Âü°í.
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2 ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_loadedData and args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?Şª?ï¿àõïÈĞÎîÜüŞ?¡£??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%¡£
		- ?õö?Óğ args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message¡£
		\param args IDbCacheClientDelegate2%ãÀeventîÜargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		Şª?ï¿îÜïÈĞÎªË?ª¹ªë«³?«ë«Ğ«Ã«¯ <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?ÍÅ
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data,  args.m_loadResults[index].m_messageªËö·ª¬ØØªáªéªìªŞª¹¡£
		\param args IDbCacheClientDelegate2 ªÎ«¤«Ù«ó«Èargument Ï°ğã?ªÇª¹¡£ ?ÍÅ \ref CCallbackArgs

		\~
		*/
		virtual void OnSomeoneModifyValue(CCallbackArgs& args) { args; }

		/**
		\~korean
		ºñµ¶Á¡Àû Á¢±Ù¿¡ ´ëÇÑ Äİ¹é. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> Âü°í.
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message¿¡ °ªÀÌ Ã¤¿öÁı´Ï´Ù.
		\param args IDbCacheClientDelegate2 ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		A callback to non monopolistic approach. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>.
		- Value will write in to args.m_loadResults[index].m_loadedData and args.m_loadResults[index].m_data,  args.m_loadResults[index].m_message.
		\param args Event argument object of IDbCacheClientDelegate2.

		\~chinese
		?Şª?ï¿àõïÈĞÎîÜüŞ?¡£??ÍÅ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%¡£
		- ?õö?Óğ args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data, args.m_loadResults[index].m_message¡£
		\param args IDbCacheClientDelegate2%ãÀeventîÜargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		Şª?ï¿îÜïÈĞÎªË?ª¹ªë«³?«ë«Ğ«Ã«¯ <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> ?ÍÅ
		- args.m_loadResults[index].m_loadedData, args.m_loadResults[index].m_data, args.m_loadResults[index].m_messageªËö·ª¬ØØªáªéªìªŞª¹¡£
		\param args IDbCacheClientDelegate2 ªÎ«¤«Ù«ó«Èargument Ï°ğã?ªÇª¹¡£ ?ÍÅ \ref CCallbackArgs

		\~
		*/
		virtual void OnSomeoneSetValue(CCallbackArgs& args) { args; }

		/**
		\~korean
		Data Access ¿¡·¯
		- Äİ¹éµÇ´Â ¿¹ : ¿äÃ»Çü ¸Ş¼­µå°¡ ½ÇÇàµÇ´Â »çÀÌ¿¡ ÀÏ¹æÀû ¸Ş¼­µå°¡ È£ÃâµÈ°æ¿ì
		¾÷µ¥ÀÌÆ®½Ã¿¡ ¾÷µ¥ÀÌÆ®ÇÒ µ¥ÀÌÅÍ¸¦ ¸øÃ£´Â °æ¿ì, È¤Àº Áö¿ö¾ßÇÒ µ¥ÀÌÅÍ¸¦ ¸øÃ£´Â °æ¿ì µîµî¿¡ ÀÌ ÀÌº¥Æ®°¡ È£ÃâµË´Ï´Ù.
		\param args IDbCacheClientDelegate2ÀÇ ÀÌº¥Æ® argument ±¸Á¶Ã¼ÀÔ´Ï´Ù. Âü°í \ref CCallbackArgs

		\~english
		Data Access error
		- Example of callback : This event will call some situation such as one-sided method is called while requested method is running, could not find update data or could not find data that need to delete.
		\param args Event argument object of IDbCacheClientDelegate2

		\~chinese
		Data Access ??
		- üŞ?îÜÖÇ£ºé­?úşÛ°Ûö?ú¼Ñ¢?£¬?Û°ØüîÜÛ°Ûöû¼Ğ£îÜï×?£¬ã®???ÜôÓğã®??ËßîÜï×?£¬ûäíº?êó?Óğé©?ğ¶îÜ?ËßîÜï×?Ôõ?ı¦ó®event?ù¬û¼Ğ£¡£
		\param args IDbCacheClientDelegate2ãÀeventîÜargument?ğã?¡£?ÍÅ\ref CCallbackArgs%¡£

		\~japanese
		Data Access «¨«é?
		- «³?«ë«Ğ«Ã«¯ªµªìªëÖÇ£ºé©ôëúş«á«½«Ã«Éª¬?ú¼ªµªìªëÊàªËìéÛ°îÜªË«á«½«Ã«Éª¬û¼ªÓõóªµªìªëíŞùê
		«¢«Ã«×«Ç?«ÈãÁªË«¢«Ã«×«Ç?«Èª¹ªë«Ç?«¿ª¬Ì¸ªÄª«ªéªÊª¤íŞùê¡¢ªŞª¿ªÏŞûğ¶ª¹ªÙª­«Ç?«¿ª¬Ì¸ªÄª«ªéªÊª¤íŞùêªÊªÉªËª³ªÎ«¤«Ù«ó«Èª¬û¼ªÓõóªµªìªŞª¹¡£
		\param args IDbCacheClientDelegate2ªÎ«¤«Ù«ó«ÈargumentÏ°ğã?ªÇª¹¡£?ÍÅ \ref CCallbackArgs

		\~
		*/
		virtual void OnAccessError(CCallbackArgs& args) = 0;

		/**
		\~korean
		³»ºÎ ¿¡·¯ ¹ß»ı½Ã È£ÃâµË´Ï´Ù
		\param errorInfo ¿¡·¯¿¡ ´ëÇÑ Á¤º¸ÀÔ´Ï´Ù. ErrorInfo::ToString À¸·Î ÆíÇÏ°Ô ÀÚ¼¼ÇÑ Error Á¤º¸¸¦ È®ÀÎÇÏ½Ç ¼ö ÀÖ½À´Ï´Ù.

		\~english
		It calls when it occurs internal error.
		Information of \param errorinfo error.

		\~chinese
		?İ»?ßæ????ù¬û¼Ğ£¡£
		\param errorInfo ???îÜãáãÓ¡£××éÄ ErrorInfo::ToString()%îÜ?ÒöÛ°øµîÜÊ×õó??îÜErrorãáãÓ¡£

		\~japanese
		?İ»«¨«é?ª¬?ßæãÁªËû¼ªÓõóªµªìªŞª¹¡£
		\param errorInfo «¨«é?ªË?ª¹ªëï×ÜÃªÇª¹¡£ErrorInfo::ToStringªÇ?ªËßÙª·ª¤Errorï×ÜÃªòü¬ìãª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£

		\~
		*/
		virtual void OnError(ErrorInfo *errorInfo) = 0;

		/**
		\~korean
		³»ºÎ °æ°í ¹ß»ı½Ã È£ÃâµË´Ï´Ù. ¿¡·¯º¸´Ù´Â ³·Àº ¼öÀ§ÀÇ ¹®Á¦¸¦ º¸°íÇÔ.
		\param errorInfo ¿¡·¯¿¡ ´ëÇÑ Á¤º¸ÀÔ´Ï´Ù. ErrorInfo::ToString À¸·Î ÆíÇÏ°Ô ÀÚ¼¼ÇÑ Error Á¤º¸¸¦ È®ÀÎÇÏ½Ç ¼ö ÀÖ½À´Ï´Ù.

		\~english
		It calls when it occurs internal warning. It reports problem that not serious than error.
		Information of \param errorinfo error.

		\~chinese
		?İ»?ßæÌíÍ±??ù¬û¼Ğ£¡£?Í±İï??â©øÁî¸îÜ??¡£
		\param errorInfo ???îÜãáãÓ¡£××éÄ ErrorInfo::ToString()%îÜ?ÒöÛ°øµîÜÊ×õó??îÜErrorãáãÓ¡£

		\~japanese
		?İ»ÌíÍ±ª¬?ßæãÁªËû¼ªÓõóªµªìªŞª¹¡£«¨«é?ªèªêªÏî¸ª¤«ì«Ù«ëªÎÙığ¹ªòÜÃÍ±ª·ªŞª¹¡£
		\param errorInfo «¨«é?ªË?ª¹ªëï×ÜÃªÇª¹¡£ErrorInfo::ToString ªÇ?ªËßÙª·ª¤Errorï×ÜÃªòü¬ìãª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£

		\~
		*/
		virtual void OnWarning(ErrorInfo *errorInfo) = 0;

		/**
		\~korean
		Proud.Exception À¸·Î ÅëÇÕµÇ¾ú½À´Ï´Ù.
		- ÀÏ¹İÀûÀ¸·Î À¯Àú ÄÚµå¿¡¼­ ³ª´Â ¿¡·¯¸¦ Ã³¸®ÇÕ´Ï´Ù.
		- À¯Àú´Â ÇÊ¿äÇÑ °ÍµéÀ» ±¸ÇöÇÏ¸é µË´Ï´Ù.
		- ExceptionType À¸·Î ÇØ´ç Exception °´Ã¼¸¦ ¾ò¾î¼­ »ç¿ëÇÏ¸é µË´Ï´Ù.
		- _com_error, void*, std::exception µîÀ» ¸ğµÎ Ã³¸®ÇÕ´Ï´Ù.
		¶ÇÇÑ catch(...)¸¦ Ã³¸®ÇÏ´Â OnUnhandledException()µµ ÀÖ½À´Ï´Ù.
		- void*´Â ¿¹¿Ü °´Ã¼ÀÇ Å¸ÀÔÀ» Ä³½ºÆÃÇØ¼­ ¹ŞÀ» ¼ö ÀÖ½À´Ï´Ù. °¡·É MFC CExceptionÀ» ¹Ş´Âµ¥ »ç¿ëµË´Ï´Ù.

		\~english
		Merge to Proud.Exception
		- It handle error that occur from user code.
		- User realize things that user needed.
		- You can use Exceptiontype that obtain Exception object.
		- It process _com_error, void*, std::exception, etc. Also there is OnUnhandledException() that handle catch(...)
		- void* can obtain exceptional object type by casting. For example, it uses obtaining MFC CException.

		\~chinese
		?ìéà÷ Proud.Exception%¡£
		- ìéÚõ?×â?éÄ?ÓÛ??ßæîÜ??¡£
		- éÄ?ñşé©??âÍé©îÜ?à¤¡£
		- éÄExceptionType?Ôğêó?Exception??ı¨ŞÅéÄ?Ê¦¡£
		- ?×â_com_error, void*, std::exception Ôõîïİ»¡£
		?êó?×âcatch(...)îÜOnUnhandledException()¡£
		- ??ÖÇèâ?ßÚîÜ?úşì¤ı¨Ê¦ì¤ïÈâ¥void*¡£İïåıïÈâ¥MFC CException îÜ?ı¦ŞÅéÄ¡£

		\~japanese
		Proud.Exception ªÇ÷ÖùêªµªìªŞª·ª¿¡£
		- ìéÚõîÜªË«æ?«¶?«³?«Éª«ªéõóªë«¨«é?ªò?×âª·ªŞª¹¡£
		- «æ?«¶?ªÏù±é©ªÊª³ªÈªò?úŞª¹ªìªĞÕŞª¤ªÇª¹¡£
		- ExceptionType ªÇú±?ExceptionªÎ«ª«Ö«¸«§«¯«ÈªòÔğªÆŞÅª¨ªĞÕŞª¤ªÇª¹¡£
		- _com_error, void*, std::exception ªÊªÉªòîïªÆ?×âª·ªŞª¹¡£
		ªŞª¿¡¢catch(...)ªò?×âª¹ªëOnUnhandledException()ªâª¢ªêªŞª¹¡£
		- void*ªÏÖÇèâ«ª«Ö«¸«§«¯«ÈªÎ«¿«¤«×ªò«­«ã«¹«Æ«£«ó«°ª·ªÆªâªéª¦ª³ªÈª¬ªÇª­ªŞª¹¡£?ªËMFC CExceptionªòáôª±ªëª³ªÈªËŞÅªïªìªŞª¹¡£

		\~
		*/
		virtual void OnException(const Exception &e) = 0;

	};

	/**
	\~korean
	<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_client_server" >DB cache Å¬¶óÀÌ¾ğÆ®¿Í ¼­¹ö</a> ÀÔ´Ï´Ù.

	\~english
	<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_client_server" >DB cache client and server</a>

	\~chinese
	ãÀ <a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_client_server" >DB cacheËÔ?Ó®ûúÜ×?Ğï</a> %¡£

	\~japanese
	\ref dbc2_clientªÇª¹¡£
	\~
	*/
	class CDbCacheClient2
	{
	protected:
		CDbCacheClient2() {}
	public:
		virtual ~CDbCacheClient2() {}

		/**
		\~korean
		DB cache client2 ÀÎ½ºÅÏ½º¸¦ »ı¼ºÇÕ´Ï´Ù.

		\~english
		Creates DB cache client2 instance

		\~chinese
		ßæà÷DB cache client2?ÖÇ¡£

		\~japanese
		DB cache client2 «¤«ó«¹«¿«ó«¹ªòßæà÷ª·ªŞª¹¡£
		\~
		*/
		PROUDSRV_API static CDbCacheClient2* New();

		/**
		\~korean
		DB cache server2¿¡ Á¢¼ÓÀ» ½ÃµµÇÕ´Ï´Ù.
		\param param CDbCacheClient2¸¦ ±¸µ¿ÇÏ°í DBCacheServer2¿¡ Á¢¼ÓÇÏ±â À§ÇÑ Á¤º¸ °´Ã¼ ÀÔ´Ï´Ù.

		\~english
		Attempts to connect to DB cache server2

		\~chinese
		???DB cache server2?ïÈ¡£
		\param param ?? CDbCacheClient2%£¬?Öõ?ïÈDBCacheServer2îÜãáãÓ?ßÚ¡£

		\~japanese
		DB cache server2ªËïÈ?ªòãËª·ªŞª¹¡£
		\param param CDbCacheClient2ªò?ÔÑª·ªÆDBCacheServer2ªËïÈ?ª¹ªëª¿ªáªÎï×ÜÃ«ª«Ö«¸«§«¯«ÈªÇª¹¡£

		\~
		*/
		virtual bool Connect(CDbCacheClient2ConnectParameter& param, ErrorInfoPtr& outError) = 0;
		virtual bool Connect(CDbCacheClient2ConnectParameter& param) = 0;

		/**
		\~korean
		DB cache server2¿Í Á¢¼ÓÀ» Á¾·áÇÏ°í ¸ğµç µ¥ÀÌÅÍ¸¦ ÀÏ¼ÒÇÕ´Ï´Ù.

		\~english
		Disconnect from DB cache server2 and sweep all data

		\~chinese
		?ò­?DB cache server2îÜ?ïÈ£¬?ğ¶á¶êó?Ëß¡£

		\~japanese
		DB cache server2ªÈïÈ?ªòğûÖõª·ªÆîïªÆªÎ«Ç?«¿ªòìéá·ª·ªŞª¹¡£
		\~
		*/
		virtual void Disconnect() = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#exclusive_load" >µ¶Á¡Àû ºÒ·¯¿À±â</a> ¿äÃ» ¸Ş¼­µåÀÔ´Ï´Ù.
		\param rootTableName Ãß°¡ÇÒ µ¥ÀÌÅÍÀÇ root Å×ÀÌºí ÀÌ¸§
		\param fieldName Ã£À» fieldNameÀÔ´Ï´Ù.
		\param cmpValue Ã£¾Æ¼­ ºñ±³ÇÒ °ªÀÔ´Ï´Ù.
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataComplete ÀÀ´äÀ» ¹ŞÀ» ¶§ ±×´ë·Î µ¹·Á¹ŞÀ» »ç¿ëÀÚ ÀÓÀÇ µ¥ÀÌÅÍÀÔ´Ï´Ù. ÀÌ °ªÀº ÀÎÀÚ args.m_tag¸¦ ÅëÇØ µ¹·Á¹Ş½À´Ï´Ù.
		\param message ÀÌ¹Ì µ¶Á¡·ÎµùµÇ¾îÀÖ´Â µ¥ÀÌÅÍ¸¦ ¿äÃ»ÇÒ °æ¿ì ±âÁ¸ µ¶Á¡ÀÚ¿¡°Ô Àü´ŞµÇ´Â »ç¿ëÀÚ ÀÓÀÇ µ¥ÀÌÅÍÀÔ´Ï´Ù. ±âÁ¸ µ¶Á¡ÀÚ´Â IDbCacheClientDelegate2.OnDataUnloadRequestedÀÇ ÀÎÀÚ args.m_loadResults[index].m_message¸¦ ÅëÇØ ÀÌ ¸Ş½ÃÁö¸¦ Àü´Ş¹Ş½À´Ï´Ù.


		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#exclusive_load" >Exclusive Load</a> request method.
		\param rootTbaleName root table name of additional data
		\param fieldName fieldName that will search
		\param cmpValue coparable value
		\param tag It is a user random data that returns when IDbCacheClientDelegate2.OnExclusiveLoadDataComplete is responded. This value returns through parameter args.m_tag.
		\param message It is a user random data that is sent to the existing sole owner in case of requesting exclusive data (loaded exclusively). This message is sent to the existing sole owner through parameter args.m_loadResults[index].m_message of IDbCacheClientDelegate2.OnDataUnloadRequested.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#exclusive_load" >?ï¿àõìÚìı</a> é­?Û°Ûö¡£
		\param rootTableName é©ôÕÊ¥îÜroot table Ù£?¡£
		\param fieldName é©?îÜfieldName¡£
		\param cmpValue ?Óğ?ó¦İï?îÜ?¡£
		\param tag î¤ïÈâ¥Óğ IDbCacheClientDelegate2.OnExclusiveLoadDataCompleteîÜ?ÓÍ?£¬ê«?â¥üŞîÜìòëòéÄ??Ëß¡£ó®?÷×?Parameter args.m_tagâ¥üŞ¡£
		\param messageî¤?Ï´?ï¿Ê¥?ñéîÜ?Ëß?£¬ ????êó?ï¿íºîÜìòëòéÄ??Ëß¡£


		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#exclusive_load" >?ï¿îÜ«í?«É</a> é©ôë«á«Ã«½«ÉªÇª¹¡£
		\param rootTableName õÚÊ¥ª¹ªë«Ç?«¿ªÎroot«Æ?«Ö«ëÙ£
		\param fieldName ÷®ª¹ fieldNameªÇª¹¡£
		\param cmpValue ÷®ª·ªÆİïªÙªëö·ªÇª¹¡£
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataComplete?ÓÍªòáôª±ªëãÁªËª½ªÎªŞªŞÚ÷ª·ªÆá®ª¦«æ?«¶?ìòëò«Ç?«¿ªÇª¹¡£ª³ªÎö·ªÏì×í­args.m_tagªò÷×ª·ªÆÚ÷ª·ªÆá®ª¤ªŞª¹¡£
		\param message ?ªË?ï¿«í?«Ç«£«ó«°ªµªìªÆª¤ªë«Ç?«¿ªòé©ôëª¹ªëíŞùê¡¢?ğí?ï¿íºªË?Ó¹ªµªìªë«æ?«¶?ìòëò«Ç?«¿ªÇª¹¡£
		?ğí?ï¿íºªÏ IDbCacheClientDelegate2.OnDataUnloadRequestedªÎì×í­ args.m_loadResults[index].m_messageªò÷×ª·ªÆª³ªÎ«á«Ã«»?«¸ªòáôª±ªŞª¹¡£

		*/
		virtual void RequestExclusiveLoadData(String rootTableName, String fieldName, CVariant cmpValue, intptr_t tag, const ByteArray& message = ByteArray()) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#exclusive_load" >µ¶Á¡Àû ºÒ·¯¿À±â</a> ¿äÃ» ¸Ş¼­µåÀÔ´Ï´Ù.
		\param rootTableName Ãß°¡ÇÒ µ¥ÀÌÅÍÀÇ root Å×ÀÌºí ÀÌ¸§
		\param rootUUID Ã£À» rootUUIDÀÔ´Ï´Ù.
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataComplete ÀÀ´äÀ» ¹ŞÀ» ¶§ ±×´ë·Î µ¹·Á¹ŞÀ» »ç¿ëÀÚ ÀÓÀÇ µ¥ÀÌÅÍÀÔ´Ï´Ù. ÀÌ °ªÀº ÀÎÀÚ args.m_tag¸¦ ÅëÇØ µ¹·Á¹Ş½À´Ï´Ù.
		\param message ÀÌ¹Ì µ¶Á¡·ÎµùµÇ¾îÀÖ´Â µ¥ÀÌÅÍ¸¦ ¿äÃ»ÇÒ °æ¿ì ±âÁ¸ µ¶Á¡ÀÚ¿¡°Ô Àü´ŞµÇ´Â »ç¿ëÀÚ ÀÓÀÇ µ¥ÀÌÅÍÀÔ´Ï´Ù. ±âÁ¸ µ¶Á¡ÀÚ´Â IDbCacheClientDelegate2.OnDataUnloadRequestedÀÇ ÀÎÀÚ args.m_loadResults[index].m_message¸¦ ÅëÇØ ÀÌ ¸Ş½ÃÁö¸¦ Àü´Ş¹Ş½À´Ï´Ù.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#exclusive_load" >Exclusive Load</a> it is a request method.
		\param rootTableName it is a root table name of data that needs to be added.
		\param rootUUID it is rootUUID that needs to be found.
		\param tag It is a user random data that returns when IDbCacheClientDelegate2.OnExclusiveLoadDataComplete is responded. This value returns through parameter args.m_tag.
		\param message It is a user random data that is sent to the existing sole owner in case of requesting exclusive data (loaded exclusively). This message is sent to the existing sole owner through parameter args.m_loadResults[index].m_message of IDbCacheClientDelegate2.OnDataUnloadRequested.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#exclusive_load" >?ï¿àõìÚìı</a> ãÀ?Ï´Method¡£
		\param rootTableName é©ôÕÊ¥îÜ?Ëßroot TableÙ£
		\param rootUUID é©??îÜ rootUUID
		\param tag î¤ïÈâ¥Óğ IDbCacheClientDelegate2.OnExclusiveLoadDataSuccess ûä IDbCacheClientDelegate2.OnExclusiveLoadDataFailedîÜ?ÓÍ?£¬ê«?â¥üŞîÜìòëòéÄ??Ëß¡£ó®?÷×?Parameter args.m_tagâ¥üŞ¡£
		\param messageî¤?Ï´?ï¿Ê¥?ñéîÜ?Ëß?£¬ ????êó?ï¿íºîÜìòëòéÄ??Ëß¡£

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#exclusive_load" >?ï¿îÜ«í?«É</a> é©ôë«á«½«Ã«ÉªÇª¹¡£
		\param rootTableName õÚÊ¥ª¹ªë«Ç?«¿ªÎ root «Æ?«Ö«ëªÎÙ£îñ
		\param rootUUID ÷®ª¹ rootUUIDªÇª¹¡£
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataSuccess ªŞª¿ªÏ IDbCacheClientDelegate2.OnExclusiveLoadDataFailed?ÓÍªòáôª±ªëãÁªËª½ªÎªŞªŞÚ÷ª·ªÆá®ª¦«æ?«¶?ìòëò«Ç?«¿ªÇª¹¡£ª³ªÎö·ªÏì×í­args.m_tagªò÷×ª·ªÆÚ÷ª·ªÆá®ª¤ªŞª¹¡£
		\param message ?ªË?ï¿«í?«Ç«£«ó«°ªµªìªÆª¤ªë«Ç?«¿ªòé©ôëª¹ªëíŞùê¡¢?ğí?ï¿íºªË?Ó¹ªµªìªë«æ?«¶?ìòëò«Ç?«¿ªÇª¹¡£
		?ğí?ï¿íºªÏ IDbCacheClientDelegate2.OnDataUnloadRequestedªÎì×í­ args.m_loadResults[index].m_messageªò÷×ª·ªÆª³ªÎ«á«Ã«»?«¸ªòáôª±ªŞª¹¡£

		\~
		*/

		virtual void RequestExclusiveLoadDataByGuid(String rootTableName, Guid rootUUID, intptr_t tag, const ByteArray &message = ByteArray()) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#exclusive_load" >µ¶Á¡Àû ºÒ·¯¿À±â</a> ¿äÃ» ¸Ş¼­µåÀÔ´Ï´Ù.
		\param rootTableName Ãß°¡ÇÒ µ¥ÀÌÅÍÀÇ root Å×ÀÌºí ÀÌ¸§
		\param queryString RootUUID¸¦ Ã£±âÀ§ÇØ "select RootUUID from %s where %s" ´ÙÀ½°ú °°Àº Äõ¸®¸¦ ³¯¸®°Ô µÇ´Âµ¥ Ã¹¹øÂ° ÀÎÀÚ´Â rootTableNameÀÌ°í whereÀÌÈÄ ÇÊµå¿¡ µé¾î°¥ ¹®ÀÚ¿­ÀÌ´Ù.
		SQL¹®¹ı¿¡ ¸Â°Ô ÀÛ¼ºÇØ¾ß ÇÑ´Ù.
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataComplete ÀÀ´äÀ» ¹ŞÀ» ¶§ ±×´ë·Î µ¹·Á¹ŞÀ» »ç¿ëÀÚ ÀÓÀÇ µ¥ÀÌÅÍÀÔ´Ï´Ù. ÀÌ °ªÀº ÀÎÀÚ args.m_tag¸¦ ÅëÇØ µ¹·Á¹Ş½À´Ï´Ù.
		\param message ÀÌ¹Ì µ¶Á¡·ÎµùµÇ¾îÀÖ´Â µ¥ÀÌÅÍ¸¦ ¿äÃ»ÇÒ °æ¿ì ±âÁ¸ µ¶Á¡ÀÚ¿¡°Ô Àü´ŞµÇ´Â »ç¿ëÀÚ ÀÓÀÇ µ¥ÀÌÅÍÀÔ´Ï´Ù. ±âÁ¸ µ¶Á¡ÀÚ´Â IDbCacheClientDelegate2.OnDataUnloadRequestedÀÇ ÀÎÀÚ args.m_loadResults[index].m_message¸¦ ÅëÇØ ÀÌ ¸Ş½ÃÁö¸¦ Àü´Ş¹Ş½À´Ï´Ù.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#exclusive_load" >Exclusive Load</a> it is a request method.
		\param rootTableName it is a root table name of data that needs to be added.
		\param queryString send the query like "select RootUUID from %s where %s" to find RootUUID. The first parameter is rootTableName and it is a string that is going to be inserted into a field after where.
		It must be written in accordance with SQL syntax.
		\param tag It is a user random data that returns when IDbCacheClientDelegate2.OnExclusiveLoadDataComplete is responded. This value returns through parameter args.m_tag.
		\param message It is a user random data that is sent to the existing sole owner in case of requesting exclusive data (loaded exclusively). This message is sent to the existing sole owner through parameter args.m_loadResults[index].m_message of IDbCacheClientDelegate2.OnDataUnloadRequested.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#exclusive_load" >?ï¿àõìÚìı</a> ãÀ?Ï´Method¡£
		\param rootTableName é©ôÕÊ¥îÜ?Ëß root TableÙ£
		\param queryString ???RootUUID£¬ "select RootUUID from %s where %s" ??õóåıù»Query,ğ¯ìé???? rootTableName£¬ãÀî¤whereı¨??ìıFieldñéîÜí®İ¬Íú¡£
		âÍé©äÎğÎSQL?Ûöğ¤íÂ¡£
		\param tag î¤ïÈâ¥Óğ IDbCacheClientDelegate2.OnExclusiveLoadDataSuccess ûä IDbCacheClientDelegate2.OnExclusiveLoadDataFailedîÜ?ÓÍ?£¬ê«?â¥üŞîÜìòëòéÄ??Ëß¡£ó®?÷×?Parameter args.m_tagâ¥üŞ¡£
		\param messageî¤?Ï´?ï¿Ê¥?ñéîÜ?Ëß?£¬ ????êó?ï¿íºîÜìòëòéÄ??Ëß¡£

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#exclusive_load" >?ï¿îÜ«í?«É</a> é©ôë«á«½«Ã«ÉªÇª¹¡£
		\param rootTableName õÚÊ¥ª¹ªë«Ç?«¿ªÎroot«Æ?«Ö«ëªÎÙ£îñ
		\param queryString RootUUIDªò÷®ª¹ª¿ªáªË"select RootUUID from %s where %s"ó­ªÎªèª¦ªÊ«¯«¨«ê?ªòáêªëª¬¡¢1ÛãÙÍªÎ«Ñ«é«á?«¿?ªÏ rootTableNameªÇª¢ªê¡¢ whereì¤Ë½ªÎ«Õ«£?«ë«ÉªËìıªëÙşí®ÖªªÇª¹¡£
		SQLÙşÛöªËùêª¦ªèª¦ªËíÂà÷ª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataSuccess ªŞª¿ªÏ IDbCacheClientDelegate2.OnExclusiveLoadDataFailed?ÓÍªòáôª±ªëãÁªËª½ªÎªŞªŞÚ÷ª·ªÆá®ª¦«æ?«¶?ìòëò«Ç?«¿ªÇª¹¡£ª³ªÎö·ªÏì×í­args.m_tagªò÷×ª·ªÆÚ÷ª·ªÆá®ª¤ªŞª¹¡£
		\param message ?ªË?ï¿«í?«Ç«£«ó«°ªµªìªÆª¤ªë«Ç?«¿ªòé©ôëª¹ªëíŞùê¡¢?ğí?ï¿íºªË?Ó¹ªµªìªë«æ?«¶?ìòëò«Ç?«¿ªÇª¹¡£
		?ğí?ï¿íºªÏ IDbCacheClientDelegate2.OnDataUnloadRequestedªÎì×í­ args.m_loadResults[index].m_messageªò÷×ª·ªÆª³ªÎ«á«Ã«»?«¸ªòáôª±ªŞª¹¡£

		\~
		*/
		virtual void RequestExclusiveLoadDataByQuery(String rootTableName, String queryString, intptr_t tag, const ByteArray &message = ByteArray()) = 0;

		/**
		\~korean
		RootTable¿¡ µ¥ÀÌÅÍ¸¦ Ãß°¡ÇÏ°í ¹Ù·Î »ç¿ëÇÒ¶§ »ç¿ëµÇ´Â ÇÔ¼öÀÔ´Ï´Ù.
		- ¾Æ·¡´Â »ç¿ë¿¹ÀÔ´Ï´Ù.

		\code
		CPropNodePtr newNode = CPropNodePtr(new CPropNode(L"Gamer"));
		newNode->Fields[L"GamerID"] = "Ulelio";

		intptr_t tag; // User Defined Identifier
		m_dbCacheClient->RequestExclusiveLoadNewData(L"Gamer", newNode, tag, transaction);
		\endcode

		\param rootTableName Ãß°¡ÇÒ µ¥ÀÌÅÍÀÇ root Å×ÀÌºí ÀÌ¸§
		\param addData Ãß°¡ÇÒ µ¥ÀÌÅÍ
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataComplete ÀÀ´äÀ» ¹ŞÀ» ¶§ ±×´ë·Î µ¹·Á¹ŞÀ» »ç¿ëÀÚ ÀÓÀÇ µ¥ÀÌÅÍÀÔ´Ï´Ù. ÀÌ °ªÀº ÀÎÀÚ args.m_tag¸¦ ÅëÇØ µ¹·Á¹Ş½À´Ï´Ù.
		\param transaction º»¿äÃ»¿¡ transactionÀ» ÇÒÁö¿¡ ´ëÇÑ ¿©ºÎÀÔ´Ï´Ù.

		\~english
		Function use for add data to RootTable and use it immediately.
		- Sample is as followed

		\code
		CPropNodePtr newNode = CPropNodePtr(new CPropNode(L"Gamer"));
		newNode->Fields[L"GamerID"] = "Ulelio";

		intptr_t tag; // User Defined Identifier
		m_dbCacheClient->RequestExclusiveLoadNewData(L"Gamer", newNode, tag, transaction);
		\endcode

		\param rootTbaleName root table name of additional data
		\param addData Additional data
		\param tag It is a user random data that returns when IDbCacheClientDelegate2.OnExclusiveLoadDataComplete is responded. This value returns through parameter args.m_tag.
		\param transaction Do transaction as request whether or not

		\~chinese
		èÙRootTableôÕÊ¥?Ëßı¨Ø¡?ŞÅéÄîÜùŞ?¡£
		- ù»ØüãÀŞÅéÄÖÇ¡£

		\code
		CPropNodePtr newNode = CPropNodePtr(new CPropNode(L"Gamer"));
		newNode->Fields[L"GamerID"] = "Ulelio";

		intptr_t tag; // User Defined Identifier
		m_dbCacheClient->RequestExclusiveLoadNewData(L"Gamer", newNode, tag, transaction);
		\endcode

		\param rootTableName é©ôÕÊ¥îÜ?ËßîÜroot table Ù£?
		\param addData é©ôÕÊ¥îÜ?Ëß¡£
		\param tag î¤ïÈâ¥Óğ IDbCacheClientDelegate2.OnExclusiveLoadDataSuccess ûä IDbCacheClientDelegate2.OnExclusiveLoadDataFailedîÜ?ÓÍ?£¬ê«?â¥üŞîÜìòëòéÄ??Ëß¡£ó®?÷×?Parameter args.m_tagâ¥üŞ¡£
		\param transaction ?ó®é­?ãÀÜúé©transactionîÜ?Üú¡£

		\~japanese
		RootTableªË«Ç?«¿ªòõÚÊ¥ª·ªÆª¹ª°ŞÅéÄª¹ªëãÁªËŞÅªïªìªë??ªÇª¹¡£
		- ù»ªÏŞÅéÄÖÇªÇª¹¡£
		\code
		CPropNodePtr newNode = CPropNodePtr(new CPropNode(L"Gamer"));
		newNode->Fields[L"GamerID"] = "Ulelio";
		intptr_t tag; // User Defined Identifier
		m_dbCacheClient->RequestExclusiveLoadNewData(L"Gamer", newNode, tag, transaction);
		\endcode
		\param rootTableName õÚÊ¥ª¹ªë«Ç?«¿ªÎroot«Æ?«Ö«ëÙ£
		\param addData õÚÊ¥ª¹ªë«Ç?«¿
		\param tag IDbCacheClientDelegate2.OnExclusiveLoadDataComplete ?ÓÍªòáôª±ª¿ãÁ¡¢ª½ªÎªŞªŞÚ÷ª·ªÆªâªéª¦«æ?«¶?ìòëòªÎ«Ç?«¿ªÇª¹¡£ª³ªÎö·ªÏì×í­ args.m_tagªò÷×ª¸Ú÷ª·ªÆªâªéª¤ªŞª¹¡£
		\param transaction Üâé©ôëªËtransactionªòª¹ªëª«ªÉª¦ª«ªÇª¹¡£

		\~
		*/
		virtual void RequestExclusiveLoadNewData(String rootTableName, CPropNodePtr addData, intptr_t tag, bool transaction = false) = 0;

		/**
		\~korean
		¿äÃ» ÀÀ´äÇü ¸Ş¼­µåÀÔ´Ï´Ù.
		- field¿¡ constraints°¡ ÀÖ´Â °æ¿ì ÀÌ ¸Ş¼­µå¸¦ ¾²¸é µË´Ï´Ù.
		- °¢ ÇÔ¼ö¿¡´ëÇØ Sucess ¹× failed ÀÌº¥Æ®°¡ µµÂøÇÕ´Ï´Ù.
		- µ¥ÀÌÅÍ¸¦ ¸Ş¸ğ¸®¿¡ Ä³½¬ÇÑµÚ ³ªÁß¿¡ DBMS¿¡ ±â·ÏÇÏ´Â°Ô ¾Æ´Ï¶ó ¿äÃ»½Ã DBMS¿¡ ±â·ÏÈÄ ¸Ş¸ğ¸®¿¡ ¾÷µ¥ÀÌÆ®µË´Ï´Ù.
		- ¾Æ·¡´Â »ç¿ë ¿¹ÀÔ´Ï´Ù.
		\code
		intptr_t tag = new object;
		RequestAddData(rootUUID,ownerUUID,addData,tag);

		->ÀÌÈÄ
		OnAddDataSuccess(CCallbackArgs &args)
		{
		args.m_tag;//¿©±â·Î ¾Æ±î ¼³Á¤ÇÑ °ªÀÌ µé¾î¿É´Ï´Ù.
		}
		\endcode
		\param rootUUID addÇÒ µ¥ÀÌÅÍÀÇ rootUUID
		\param ownerUUID addÇÒ µ¥ÀÌÅÍÀÇ ownerUUID
		\param addData addÇÒ µ¥ÀÌÅÍ
		\param tag ÀÌ ¿äÃ»¿¡´ëÇÑ »ç¿ëÀÚ°¡ ³Ö¾îÁÙ ½Äº° °ªÀÔ´Ï´Ù. Äİ¹é½Ã \ref CCallbackArg ¾ÈÀÇ m_tag ·Î µé¾î°©´Ï´Ù.

		\~english
		Request response type method
		- If field contain constraints, use this method
		- Succeed or failed event will arrive to each functions
		- It writes data to DBMS then update to memory rather than cached to memory then write to DBMS.
		- Example is as followed
		\code
		intptr_t tag = new object;
		RequestAddData(rootUUID,ownerUUID,addData,tag);

		->ÀÌÈÄ
		OnAddDataSuccess(CCallbackArgs &args)
		{
		args.m_tag;// Setting value will be here
		}
		\endcode
		\param rootUUID rootUUID of additional data
		\param ownerUUID ownerUUID of additional data
		\param addData additional data
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.

		\~chinese
		é­??ÓÍúşÛ°Ûö¡£
		- field×ìêóconstraintsîÜï×?éÄ??Û°Ûö?Ê¦¡£
		- ?ÊÀ?ùŞ?Óğ?SuccessĞàfailedevent¡£
		- ÜôãÀ÷ê?Ëß?ğíÑÃ?ì¤ı¨ì¤ı¨èÙDBMS??£¬ì»ãÀé­????î¤DBMSì¤ı¨î¤?ğíã®?¡£
		- ì¤ù»ãÀŞÅéÄÖÇ¡£
		\code
		intptr_t tag = new object;
		RequestAddData(rootUUID,ownerUUID,addData,tag);

		->ñıı¨
		OnAddDataSuccess(CCallbackArgs &args)
		{
		args.m_tag;//ñıîñ?öÇîÜ?Óğ?×ì¡£
		}
		\endcode
		\param rootUUID é©addîÜ?ËßrootUUID
		\param ownerUUID é©addîÜ?ËßownerUUID
		\param addData é©addîÜ?Ëß
		\param tag ?ó®é­?£¬éÄ?é©?õöîÜ???¡£üŞ???ìı\ref CcallbackArg%îÜm_tag¡£

		\~japanese
		é©ôë?ÓÍúş«á«½«Ã«ÉªÇª¹¡£
		- field¿¡ constraintsª¬ª¢ªëíŞùê¡¢ª³ªÎ«á«½«Ã«ÉªòŞÅª¨ªĞÕŞª¤ªÇª¹¡£
		- ÊÀ??ªË?ª·ªÆSuccessĞàªÓfailed«¤«Ù«ó«Èª¬Óğó·ª·ªŞª¹¡£
		- «Ç?«¿ªò«á«â«ê?ªË«­«ã«Ã«·«åª·ªÆ¡¢ı­ªÇDBMSªËÑÀ?ª¹ªëªÎªÇªÏªÊª¯¡¢é©ôëãÁªËDBMSªËÑÀ?ª·«á«â«ê?ªË«¢«Ã«×«Ç?«ÈªµªìªŞª¹¡£
		- ù»ªÏŞÅéÄÖÇªÇª¹¡£
		\code
		intptr_t tag = new object;
		RequestAddData(rootUUID,ownerUUID,addData,tag);

		->ì¤Ë½
		OnAddDataSuccess(CCallbackArgs &args)
		{args.m_tag;//ª³ª³ªËà»ªËàâïÒª·ª¿ö·ª¬ìıªÃªÆª­ªŞª¹¡£}
		\endcode
		\param rootUUID addª¹ªë«Ç?«¿ªÎrootUUID
		\param ownerUUID addª¹ªë«Ç?«¿ªÎownerUUID
		\param addData addª¹ªë«Ç?«¿
		\param tag ª³ªÎé©ôëªË?ª¹ªë«æ?«¶?ª¬ìıªìªÆª¯ªìªëãÛÜ¬ö·ªÇª¹¡£«³?«ë«Ğ«Ã«¯ãÁ¡¢\ref CCallbackArg?ªÎm_tagªËìıªêªŞª¹¡£

		\~
		*/
		virtual bool RequestAddData(Guid rootUUID, Guid ownerUUID, CPropNodePtr addData, intptr_t tag) = 0;

		/**
		\~korean
		ÀÚ¼¼ÇÑ ¼³¸íÀº \ref RequestAddData Âü°í
		\param updateData º¯°æµÈ ³ëµåÀÇ data
		\param tag ÀÌ ¿äÃ»¿¡´ëÇÑ »ç¿ëÀÚ°¡ ³Ö¾îÁÙ ½Äº° °ªÀÔ´Ï´Ù. Äİ¹é½Ã \ref CCallbackArg ¾ÈÀÇ m_tag ·Î µé¾î°©´Ï´Ù.

		\~english
		Refer to RequestAddData
		\param updateData
		\param tag

		\~chinese
		???Ù¥??ÍÅ\ref RequestAddData%¡£
		\param updateData áóËÇîÜnodeîÜdata
		\param tag ?ó®é­?éÄ?é©ôÕÊ¥îÜ???¡£üŞ???ìı\ref CCallbackArg%×ìîÜm_tag¡£

		\~japanese
		ßÙª·ª¯ªÏ¡¢\ref RequestAddDataªò?ÍÅ
		\param updateData ?ÌÚªµªìª¿«Î?«ÉªÎ«Ç?«¿
		\param tag ª³ªÎé©ôëªË?ª¹ªë«æ?«¶?ª¬ìıªìªÆª¯ªìªëãÛÜ¬ö·ªÇª¹¡£«³?«ë«Ğ«Ã«¯ãÁ¡¢\ref CCallbackArg?ªÎm_tagªËìıªêªŞª¹¡£

		\~
		*/
		virtual bool RequestUpdateData(CPropNodePtr updateData, intptr_t tag) = 0;

		/**
		\~korean
		ÀÚ¼¼ÇÑ ¼³¸íÀº \ref RequestAddData Âü°í
		\param rootUUID rootÀÇ UUID
		\param removeUUID Á¦°ÅÇÒ UUID
		\param tag ÀÌ ¿äÃ»¿¡´ëÇÑ »ç¿ëÀÚ°¡ ³Ö¾îÁÙ ½Äº° °ªÀÔ´Ï´Ù. Äİ¹é½Ã \ref CCallbackArg ¾ÈÀÇ m_tag·Î µé¾î°©´Ï´Ù.

		\~english TODO:translate needed.
		Refer to RequestAddData

		\~chinese
		???Ù¥??ÍÅ\ref RequestAddData%¡£
		\param rootUUID root îÜUUID¡£
		\param removeUUID é©?ğ¶îÜUUID¡£
		\param tag ?ó®é­?éÄ?é©ôÕÊ¥îÜ???¡£üŞ???ìı\ref CCallbackArg%×ìîÜm_tag¡£

		\~japanese
		ßÙª·ª¯ªÏ¡¢\ref RequestAddDataªò?ÍÅ
		\param rootUUID rootªÎUUID
		\param removeUUID ğ¶ËÛª¹ªë UUID
		\param tag ª³ªÎé©ôëªË?ª¹ªë«æ?«¶?ª¬ìıªìªÆª¯ªìªëãÛÜ¬ö·ªÇª¹¡£«³?«ë«Ğ«Ã«¯ãÁ¡¢\ref CCallbackArg?ªÎm_tagªËìıªêªŞª¹¡£

		\~
		*/
		virtual bool RequestRemoveData(Guid rootUUID, Guid removeUUID, intptr_t tag) = 0;

		/**
		\~korean
		RequestUpdateData(CPropNodePtr,Guid&)°ú ´Ş¸® LoadedData°¡ °¡Áö°í ÀÖ´Â
		ÇÏÀ§ÀÇ ¸ğµç node ¸¦ °Ë»öÇÏ¿© add,update,removeµîÀ» Ã³¸®ÇØ Áİ´Ï´Ù.
		- transactionalÀ» ÁöÁ¤ÇÏÁö ¾ÊÀ¸¸é ½ÇÆĞÇÏ¿´À»¶§ ÀÏºÎ µ¥ÀÌÅÍ°¡ dbms ¿¡ commit µÇ¾úÀ»¼ö ÀÖ½À´Ï´Ù.
		- Notify¸¦ ¹Ş±âÀü¿¡´Â µ¥ÀÌÅÍ¸¦ ½Å·Ú ÇÏ½Ã¸é ¾ÈµË´Ï´Ù.
		- ½ÇÆĞÇßÀ» °æ¿ì ·Ñ¹éÇÏ½Ã·Á¸é GetClonedDataBySessionGuid ¸¦ »ç¿ëÇÏ½Ê½Ã¿ä.
		\param loadedData º¯È­¸¦ ÀúÀåÇÒ LoadedDataÀÔ´Ï´Ù.
		\param tag ÀÌ¿äÃ»¿¡´ëÇÑ »ç¿ëÀÚ°¡ ³Ö¾îÁÙ ½Äº° °ªÀÔ´Ï´Ù. Äİ¹é½Ã \ref CCallbackArg ¾ÈÀÇ m_tag·Î µé¾î°©´Ï´Ù.
		\param transactional º»¿äÃ»¿¡ transactionÀ» ÇÒÁö¿¡ ´ëÇÑ ¿©ºÎÀÔ´Ï´Ù.

		\~english
		Instead RequestUpdateData(CPropNodePtr,Guid&), it process add, update, remove, etc to search all under node that LoadedData owned.
		- If you do not set transactional, some data will commit to dbms when it failed.
		- Do not believe data before you receive Notify.
		- Use GetClonedDataBySessionGuid when you need to roll-back.
		\param loadedData LoadedData to save changes
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.
		\param transactional Do transaction as request whether or not

		\~chinese
		?RequestUpdateData(CPropNodePtr,Guid&)ÜôÔÒ£¬â¤ßãLoadedData?êóîÜù»?îÜá¶êónode??×âadd,update,remove Ôõ¡£
		- Üôò¦ïÒtransactionalîÜ?£¬?ã÷?îÜ?ı¦ìéİ»İÂ?ËßÊ¦Òöî¤dbmsù¬commit¡£
		- ïÈÓğNotifyñıîñÜôÒöãá??Ëß¡£
		- ã÷?îÜ?ı¦ßÌroll-back îÜ??ŞÅéÄGetClonedDataBySessionGuid¡£
		\param loadedData ?ğí?ûùîÜLoadedData¡£
		\param tag ?ó®é­?éÄ?é©ôÕÊ¥îÜ???¡£üŞ???ìı\ref CCallbackArg%×ìîÜm_tag¡£
		\param transactional ?ó®é­?ãÀÜúé©transactionîÜ?Üú¡£

		\~japanese
		RequestUpdateData(CPropNodePtr,Guid&)ªÈªÏêŞªÃªÆ¡¢LoadedDataª¬ò¥ªÃªÆª¤ªëù»êÈªÎîïªÆªÎ«Î?«Éªò?ßãª·ªÆadd,update,removeªÊªÉªò?×âª·ªŞª¹¡£
		- transactionalªòò¦ïÒª·ªÊª±ªìªĞ¡¢ã÷ø¨ª·ª¿ãÁªËìéİ»ªÎ«Ç?«¿ª¬dbmsªËcommitªµªìª¿Ê¦Òöàõª¬ª¢ªêªŞª¹¡£
		- Notifyªòáôª±ªëîñªËªÏ«Ç?«¿ªòãá?ª·ªÆªÏª¤ª±ªŞª»ªó¡£
		- ã÷ø¨ª·ª¿íŞùê¡¢«í?«ë«Ğ«Ã«¯ª¹ªëª¿ªáªËªÏ¡¢GetClonedDataBySessionGuidªòŞÅªÃªÆª¯ªÀªµª¤¡£
		\param loadedData ?ûùªòÜÁğíª¹ªëLoadedDataªÇª¹¡£
		\param tag ª³ªÎé©ôëªË?ª¹ªë«æ?«¶?ª¬ìıªìªÆª¯ªìªëãÛÜ¬ö·ªÇª¹¡£«³?«ë«Ğ«Ã«¯ãÁ¡¢\ref CCallbackArg?ªÎm_tagªËìıªêªŞª¹¡£
		\param transactional ª³ªÎé©ôëªËtransactionªòª¹ªëª«ªÉª¦ª«ªË?ª¹ªëÊ¦ÜúªÇª¹¡£

		\~
		*/
		virtual bool RequestRecursiveUpdateData(CLoadedData2Ptr loadedData, intptr_t tag, bool transactional = false) = 0;

		/**
		\~korean
		ºí·ÏÇü ¸Ş¼­µå ÀÔ´Ï´Ù.
		- ¿äÃ»ÀÀ´äÇü°ú ¸¶Âù°¡Áö·Î ¸ÕÀú DBMS¿¡ ±â·ÏÈÄ ¸Ş¸ğ¸®¿¡ ¾÷µ¥ÀÌÆ® µË´Ï´Ù.
		- ¿äÃ»ÀÀ´äÇü°úÀÇ Â÷ÀÌ´Â ¿äÃ»ÀÌ Ã³¸®µÇ±â Àü±îÁö ¸®ÅÏÇÏÁö ¾Ê½À´Ï´Ù. ¿äÃ»ÀÌ Ã³¸®µÇ¸é ¸®ÅÏÇÕ´Ï´Ù.
		\param rootUUID addÇÒ µ¥ÀÌÅÍÀÇ rootUUID
		\param ownerUUID addÇÒ µ¥ÀÌÅÍÀÇ ownerUUID
		\param addData addÇÒ µ¥ÀÌÅÍ
		\param timeOutTime ¹«ÇÑ·çÇÁ¿¡ ºüÁöÁö ¾Ê±âÀ§ÇØ ¸®ÅÏÀ» ±â´Ù¸®´Â½Ã°£. default 30sec
		\param outError ¿¡·¯Å¸ÀÔ

		\~english
		Block type method.
		- It write to DBMS first then update to memory like request response type.
		- Only difference is not return before request has done. Once request is finished then return.
		\param rootUUID rootUUID of additional data
		\param ownerUUID ownerUUID of additional data
		\param addData additional data
		\param timeOutTime Waiting time to prevent unlimited roop. default 30sec
		\param outError Error type

		\~chinese
		Block úşÛ°Ûö¡£
		- ?é­??ÓÍúşìé?£¬à»èÙDBMS??ı¨ã®?Óğ?ğí¡£
		- ?é­??ÓÍúşîÜ??ãÀ£¬é­?ù¬?×âñıîñÜô?Ú÷üŞ¡£é­?ù¬?×âîÜ??Ú÷üŞ¡£
		\param rootUUID é©addîÜ?ËßrootUUID
		\param ownerUUID é©addîÜ?ËßownerUUID
		\param addData é©addîÜ?Ëß¡£
		\param timeOutTime ?ÖõÜôùèìıÙéùÚroop£¬ÔõÚ÷üŞîÜ??¡£default 30sec¡£
		\param outError ???úş¡£

		\~japanese
		«Ö«í«Ã«¯úş«á«½«Ã«ÉªÇª¹¡£
		- é©ôë?ÓÍúşªÈÔÒ?ªËà»ªËDBMSªËÑÀ?ı­«á«â«ê?ªË«¢«Ã«×«Ç?«ÈªµªìªŞª¹¡£
		- é©ôë?ÓÍúşªÈªÎó¬ªÏé©ôëª¬?×âªµªìªëîñªŞªÇ«ê«¿?«óª·ªŞª»ªó¡£é©ôëª¬?×âªµªìª¿ªé«ê«¿?«óª·ªŞª¹¡£
		\param rootUUID addª¹ªë«Ç?«¿ªÎrootUUID
		\param ownerUUID addª¹ªë«Ç?«¿ªÎownerUUID
		\param addData addª¹ªë«Ç?«¿
		\param timeOutTime ÙíùÚ«ë?«×ªËÕªªÁªÊª¤ªèª¦ªËª¹ªëª¿ªá¡¢«ê«¿?«óªòÓâªÄãÁÊà¡£default 30sec
		\param outError «¨«é?«¿«¤«×

		\~
		*/
		virtual bool BlockedAddData(Guid rootUUID, Guid ownerUUID, CPropNodePtr addData, uint32_t timeOutTime = 30000, ErrorInfoPtr outError = ErrorInfoPtr()) = 0;

		/**
		\~korean
		ÀÚ¼¼ÇÑ ¼³¸íÀº \ref BlockedNonCacheAddData Âü°í
		\param updateData updateÇÒ node
		\param timeOutTime ¹«ÇÑ·çÇÁ¿¡ ºüÁöÁö ¾Ê±âÀ§ÇØ ¸®ÅÏÀ» ±â´Ù¸®´Â½Ã°£. default 30sec
		\param outError ¿¡·¯Å¸ÀÔ

		\~english
		For a detailed explanation, refer to \ref BlockedNonCacheAddData
		\param updateData Node to be updated.
		\param timeOutTime  The time waiting for the return to avoid falling into an infinite loop. Default is 30 seconds. 
		\param outError Error type

		\~chinese
		???Ù¥??ÍÅ\ref BlockedNonCacheAddData%¡£
		\param updateData é©updateîÜ?Ëß¡£
		\param timeOutTime ?ÖõÜôùèìıÙéùÚroop£¬ÔõÚ÷üŞîÜ??¡£default 30sec¡£
		\param outError ???úş¡£

		\~japanese
		ßÙª·ª¯ªÏ¡¢\ref BlockedNonCacheAddData ?ÍÅ
		\param updateData updateª¹ªënode
		\param timeOutTime ÙíùÚ«ë?«×ªËÕªªÁªÊª¤ªèª¦ªËª¹ªëª¿ªá¡¢«ê«¿?«óªòÓâªÄãÁÊà¡£default 30sec
		\param outError «¨«é?«¿«¤«×

		\~
		*/
		virtual bool BlockedUpdateData(CPropNodePtr updateData, uint32_t timeOutTime = 30000, ErrorInfoPtr outError = ErrorInfoPtr()) = 0;

		/**
		\~korean
		BlockedNonCacheAddData Âü°í
		\param rootUUID addÇÒ µ¥ÀÌÅÍÀÇ rootUUID
		\param removeUUID Á¦°ÅÇÏ°íÀÚ ÇÏ´Â UUID
		\param timeOutTime ¹«ÇÑ·çÇÁ¿¡ ºüÁöÁö ¾Ê±âÀ§ÇØ ¸®ÅÏÀ» ±â´Ù¸®´Â½Ã°£. default 30sec
		\param outError ¿¡·¯Å¸ÀÔ

		\~english
		Refer to BlockedNonCacheAddData
		\param rootUUID rootUUID of the data to be added 
		\param removeUUID to be deleted
		\param The time waiting for the return to avoid falling into an infinite loop. Default is 30 seconds.
		\param outError type

		\~chinese
		?ÍÅBlockedNonCacheAddData¡£
		\param rootUUID é©addîÜ?ËßrootUUID¡£
		\param removeUUID é©?ğ¶îÜUUID¡£
		\param timeOutTime ?ÖõÜôùèìıÙéùÚroop£¬ÔõÚ÷üŞîÜ??¡£default 30sec¡£
		\param outError ???úş¡£

		\~japanese
		BlockedNonCacheAddData ?ÍÅ
		\param rootUUID addª¹ªë«Ç?«¿ªÎrootUUID
		\param removeUUID ğ¶ËÛª·ªèª¦ªÈª¹ªëUUID
		\param timeOutTime ÙíùÚ«ë?«×ªËÕªªÁªÊª¤ªèª¦ªËª¹ªëª¿ªá¡¢«ê«¿?«óªòÓâªÄãÁÊà¡£default 30sec
		\param outError «¨«é?«¿«¤«×

		\~
		*/
		virtual bool BlockedRemoveData(Guid rootUUID, Guid removeUUID, uint32_t timeOutTime = 30000, ErrorInfoPtr outError = ErrorInfoPtr()) = 0;

		/**
		\~korean
		BlockedUpdateData(CPropNodePtr,...)°ú ´Ş¸® LoadedData°¡ °¡Áö°í ÀÖ´Â ÇÏÀ§ÀÇ ¸ğµç node¸¦ °Ë»öÇÏ¿© add,update,removeµîÀ» Ã³¸®ÇØ Áİ´Ï´Ù.
		- transactionalÀ» ÁöÁ¤ÇÏÁö ¾ÊÀ¸¸é ½ÇÆĞÇÏ¿´À»¶§ ÀÏºÎ µ¥ÀÌÅÍ°¡ dbms¿¡ commitµÇ¾úÀ»¼ö ÀÖ½À´Ï´Ù.
		- Notify¸¦ ¹Ş±âÀü¿¡´Â µ¥ÀÌÅÍ¸¦ ½Å·Ú ÇÏ½Ã¸é ¾ÈµË´Ï´Ù.
		- ½ÇÆĞÇßÀ» °æ¿ì ·Ñ¹éÇÏ½Ã·Á¸é GetClonedDataBySessionGuid¸¦ »ç¿ëÇÏ½Ê½Ã¿ä.
		\param loadedData º¯È­¸¦ ÀúÀåÇÒ LoadedDataÀÔ´Ï´Ù.
		\param transactional º»¿äÃ»¿¡ transactionÀ» ÇÒÁö¿¡ ´ëÇÑ ¿©ºÎÀÔ´Ï´Ù.
		\param timeOutTime ¹«ÇÑ´ë±â¿¡ ºüÁöÁö ¾Ê±âÀ§ÇØ ¸®ÅÏÀ» ±â´Ù¸®´Â ½Ã°£.default 30sec
		\param outError ¿¡·¯Å¸ÀÔ

		\~english
		Instead BlockedUpdateData(CPropNodePtr,...), it process add, update, remove, etc to search all under node that LoadedData owned.
		- If you do not set transactional, some data will commit to dbms when it failed.
		- Do not believe data before you receive Notify.
		- Use GetClonedDataBySessionGuid when you need to roll-back.
		\param loadedData LoadedData to save changes
		\param transactional Do transaction as request whether or not
		\param timeOutTime Waiting time to prevent unlimited roop. default 30sec
		\param outError Error type

		\~chinese
		?RequestUpdateData(CPropNodePtr,Guid&)ÜôÔÒ£¬â¤ßãLoadedData?êóîÜù»?îÜá¶êónode??×âadd,update,remove Ôõ¡£
		- Üôò¦ïÒtransactionalîÜ?£¬?ã÷?îÜ?ı¦ìéİ»İÂ?ËßÊ¦Òöî¤dbmsù¬commit¡£
		- ïÈÓğNotifyñıîñÜôÒöãá??Ëß¡£
		- ã÷?îÜ?ı¦ßÌroll-back îÜ??ŞÅéÄGetClonedDataBySessionGuid¡£
		\param loadedData ?ğí?ûùîÜLoadedData¡£
		\param transactional ?ó®é­?ãÀÜúé©transactionîÜ?Üú¡£
		\param timeOutTime ?ÖõÜôùèìıÙéùÚroop£¬ÔõÚ÷üŞîÜ??¡£default 30sec¡£
		\param outError ???úş¡£

		\~japanese
		BlockedUpdateData(CPropNodePtr,...)ªÈªÏêŞªÃªÆ¡¢LoadedDataª¬ò¥ªÃªÆª¤ªëù»êÈªÎîïªÆªÎnodeªò?ßãª·ªÆadd,update,removeªÊªÉªò?×âª·ªŞª¹¡£
		- transactionalªòò¦ïÒª·ªÊª±ªìªĞã÷ø¨ª·ª¿ãÁ¡¢ìéİ»ªÎ«Ç?«¿ª¬dbmsªËcommitªµªìª¿Ê¦Òöàõª¬ª¢ªêªŞª¹¡£
		- Notifyªòáôª±ªëîñªËªÏ«Ç?«¿ªòãá?ª·ªÆªÏª¤ª±ªŞª»ªó¡£
		- ã÷ø¨ª·ª¿íŞùê¡¢«í?«ë«Ğ«Ã«¯ª¹ªëª¿ªáªËªÏ¡¢GetClonedDataBySessionGuidªòŞÅªÃªÆª¯ªÀªµª¤¡£
		\param loadedData ?ûùªòÜÁğíª¹ªëLoadedDataªÇª¹¡£
		\param transactional ª³ªÎé©ôëªËtransactionªòª¹ªëª«ªÉª¦ª«ªÇª¹¡£
		\param timeOutTime ÙíùÚ«ë?«×ªËÕªªÁªÊª¤ªèª¦ªËª¹ªëª¿ªá¡¢«ê«¿?«óªòÓâªÄãÁÊà¡£default 30sec
		\param outError «¨«é?«¿«¤«×

		\~
		*/
		virtual bool BlockedRecursiveUpdateData(CLoadedData2Ptr loadedData, bool transactional = false, uint32_t timeOutTime = 30000, ErrorInfoPtr outError = ErrorInfoPtr()) = 0;

		/**
		\~korean
		ÀÏ¹æÀû(Unilateral) ¸Ş¼­µåÀÔ´Ï´Ù.
		- µ¥ÀÌÅÍ°¡ ¸Ş¸ğ¸®¿¡ CacheµÈµÚ ³ªÁß¿¡ DBMS¿¡ ±â·ÏµË´Ï´Ù.
		- ±âÁ¸ÀÇ DbCacheClient °ú °°Àº¹æ½ÄÀÔ´Ï´Ù.
		- field¿¡ constraints°¡ ¾ø´Ù¸é ÀÌ¹æ½ÄÀ» ¾²´Â°ÍÀ» ±ÇÀåÇÕ´Ï´Ù.
		- ÀÏ¹æ¸Ş¼­µåÀÌ±â ¶§¹®¿¡ µû·Î ÀÌº¥Æ® Äİ¹éÀÌ ¿ÀÁö ¾Ê½À´Ï´Ù.
		\param rootUUID addÇÒ µ¥ÀÌÅÍÀÇ rootUUID
		\param ownerUUID addÇÒ µ¥ÀÌÅÍÀÇ ownerUUID
		\param addData addÇÒ µ¥ÀÌÅÍ
		\param writeDbmsImmediately trueÀÌ¸é DBMS¿¡ ¾ÆÀÌÅÛ Ãß°¡ »ç½ÇÀ» ÃÖ´ëÇÑ »¡¸® ±â·ÏÀ» ¼öÇàÇÑ´Ù.

		\~english
		Unilateral method
		- Data get cached to memory first then write to DBMS
		- Same type as DbCacheClient
		- We recommend to use it if field does not contain constraints.
		- It does not send event callback because it is one-sided method
		\param rootUUID rootUUID of additional data
		\param ownerUUID ownerUUID of additional data
		\param addData additional data
		\param writeDbmsImmediately If it is true, it write information of added item to DBMS as soon as possible.

		\~chinese
		ãÀ?Û°Øü£¨Unilateral£©Û°Ûö¡£
		- ?Ëßî¤?ğíCacheı¨£¬î¢èÙDBMS??¡£
		- ??êóîÜDbCacheClientßÓÔÒîÜÛ°ãÒ¡£
		- field×ì?êóconstraintsîÜ?Ëï?ŞÅéÄó®Û°ãÒ¡£
		- ì×?ãÀ?Û°ØüÛ°Ûö£¬Üô??èâî¢?üŞ?event¡£
		\param rootUUID é©addîÜ?ËßîÜrootUUID¡£
		\param ownerUUID é©addîÜ?ËßîÜownerUUID¡£
		\param addData é©addîÜ?Ëß¡£
		\param writeDbmsImmediately true îÜ?õÌöááÜîÜ?ú¼??î¤DBMSôÕÊ¥Ô³ÎıîÜŞÀï×¡£

		\~japanese
		ìéÛ°îÜ(Unilateral)ªÊ«á«½«Ã«ÉªÇª¹¡£
		- «Ç?«¿ª¬«á«â«ê?ªËCacheªµªìªÆ¡¢ı­ªÇDBMSªËÑÀ?ªµªìªŞª¹¡£
		- ?ğíªÎDbCacheClientªÈÔÒª¸Û°ãÒªÇª¹¡£
		- fieldªËconstraintsª¬ªÊª±ªìªĞª³ªÎÛ°ãÒªòŞÅª¦ª³ªÈªòªª?ªáª·ªŞª¹¡£
		- ìéÛ°«á«½«Ã«ÉªÇª¢ªëª¿ªá¡¢Ü¬ªË«¤«Ù«ó«È«³?«ë«Ğ«Ã«¯ª¬?ªŞª»ªó¡£
		\param rootUUID addª¹ªë«Ç?«¿ªÎrootUUID
		\param ownerUUID addª¹ªë«Ç?«¿ªÎownerUUID
		\param addData addª¹ªë«Ç?«¿
		\param writeDbmsImmediately trueªÇª¢ªìªĞDBMSªË«¢«¤«Æ«àõÚÊ¥ŞÀ?ªòõÌÓŞùÚªËáÜª¯ÑÀ?ªòâÄú¼ª·ªŞª¹¡£

		\~
		*/
		virtual bool UnilateralAddData(Guid rootUUID, Guid ownerUUID, CPropNodePtr addData, bool writeDbmsImmediately = true) = 0;

		/**
		\~korean
		ÀÚ¼¼ÇÑ ¼³¸íÀº \ref UnilateralAddData Âü°í
		\param update ÇÏ°íÀÚ ÇÏ´Â nodeÀÇ data
		\param writeDbmsImmediately trueÀÌ¸é DBMS¿¡ ÃÖ´ëÇÑ »¡¸® ±â·ÏÀ» ¼öÇà

		\~english TODO:translate needed.
		For a detailed explanation, refer to \ref UnilateralAddData
		\param update Node data to be updated
		\param writeDbmsImmediately     If true, execute record as fast as possible in DBMS. 

		\~chinese
		??îÜ??ÍÅ\ref UnilateralAddData%¡£
		\param update ßÌñ®îÜnodeîÜdata¡£
		\param writeDbmsImmediately true îÜ?õÌöááÜîÜ?ú¼??¡£

		\~japanese
		ßÙª·ª¯ªÏ¡¢\ref UnilateralAddData ?ÍÅ
		\param update ª·ª¿ª¤nodeªÎdata
		\param writeDbmsImmediately trueªÇª¢ªìªĞDBMSªËõÌÓŞùÚªËáÜª¯ÑÀ?ªòâÄú¼

		\~
		*/
		virtual bool UnilateralUpdateData(CPropNodePtr updateData, bool writeDbmsImmediately = true) = 0;


		/**
		\~korean
		ÀÏ¹æÀû(Unilateral) ¸Ş¼­µåÀÔ´Ï´Ù.
		- µ¥ÀÌÅÍ°¡ ¸Ş¸ğ¸®¿¡ CacheµÈµÚ ³ªÁß¿¡ DBMS¿¡ ±â·ÏµË´Ï´Ù.
		- µ¥ÀÌÅÍ ³ëµå(rootUUID,nodeUUID)¸¦ Á¤ÇØÁø Æ®¸® ³ëµå(destRootUUID,destNodeUUID) ÇÏÀ§·Î ÀÌµ¿ ½Ã Åµ´Ï´Ù.
		- field¿¡ constraints°¡ ¾ø´Ù¸é ÀÌ¹æ½ÄÀ» ¾²´Â°ÍÀ» ±ÇÀåÇÕ´Ï´Ù.
		- µ¥ÀÌÅÍ°¡ ÀÌµ¿µÈ DBCacheClient ¿¡°Ô ÀÌº¥Æ®°¡ Äİ¹éµË´Ï´Ù.
		\param rootUUID moveÇÒ rootUUID ³ëµå
		\param ownerUUID moveÇÒ ownerUUID ³ëµå
		\param destRootUUID attachÇÒ destRootUUID ³ëµå
		\param destNodeUUID attachÇÒ destNodeUUID ³ëµå

		\~english
		Unilateral method
		- Data get cached to memory first then write to DBMS
		- Data node(rootUUID,nodeUUID) attach to specified tree node(destRootUUID,destNodeUUID)
		- We recommend to use it if field does not contain constraints.
		- An event is callbacked to DBCacheclient in which data has been moved.
		\param rootUUID rootUUID of move node
		\param ownerUUID ownerUUID of move node
		\param destRootUUID destNodeUUID of attach node
		\param writeDbmsImmediately If it is true, it write information of added item to DBMS as soon as possible.

		\~chinese
		ãÀ?Û°Øü£¨Unliateral£©îÜÛ°Ûö¡£
		- Data?î¤?ğíCashe£¬ñıı¨?ù¬??ÓğDBMS¡£
		- ?Datanode(rootUUID,nodeUUID)ì¹ò¸ì«?ïÒîÜTreenode(destRootUUID,destNodeUUID)îÜù»êÈ¡£
		- åıÍıfield??êóconstraints?ÜôËï?ŞÅéÄó®Û°Ûö¡£
		- ?ú¾ì¹??ËßîÜDBCacheClientüŞ?Event¡£
		\param rootUUID é©moveîÜrootUUID node¡£
		\param ownerUUID é©moveîÜownerUUID node¡£
		\param destRootUUID é©attachîÜdestRootUUID node¡£
		\param destNodeUUID  é©attachîÜdestNodeUUID node¡£

		\~japanese
		ìéÛ°îÜ(Unilateral)«á«½«Ã«ÉªÇª¹¡£
		- «Ç?«¿ª¬«á«â«ê?ªËCacheªµªìªÆ¡¢ı­ªÇDBMSªËÑÀ?ªµªìªŞª¹¡£
		- «Ç?«¿«Î?«É(rootUUID,nodeUUID)ªòÌ½ªŞªÃª¿«Ä«ê?«Î?«É(destRootUUID,destNodeUUID)ªÎù»êÈªËì¹ÔÑªµª»ªŞª¹¡£
		- fieldªËconstraintsª¬ªÊª±ªìªĞª³ªÎÛ°ãÒªòŞÅª¦ª³ªÈªòªª?ªáª·ªŞª¹¡£
		- «Ç?«¿ª¬ì¹ÔÑªµªìª¿DBCacheClientªË«¤«Ù«ó«Èª¬«³?«ë«Ğ«Ã«¯ªµªìªŞª¹¡£
		\param rootUUID moveª¹ªë rootUUID «Î?«É
		\param ownerUUID moveª¹ªë ownerUUID «Î?«É
		\param destRootUUID attachª¹ªë destRootUUID «Î?«É
		\param destNodeUUID attachª¹ªë destNodeUUID «Î?«É

		\~
		*/
		virtual bool UnilateralMoveData(String rootTableName, Guid rootUUID, Guid nodeUUID, Guid destRootUUID, Guid destNodeUUID, bool writeDbmsImmediately = true) = 0;

		/**
		\~korean
		ÀÚ¼¼ÇÑ ¼³¸íÀº \ref UnilateralAddData Âü°í
		\param rootUUID rootÀÇ UUID
		\param removeUUID Á¦°ÅÇÒ UUID
		\param writeDbmsImmediately trueÀÌ¸é DBMS¿¡ ÃÖ´ëÇÑ »¡¸® ±â·ÏÀ» ¼öÇà

		\~english TODO:translate needed.
		For a detailed explanation, refer to \ref UnilateralAddData
		\param rootUUID     UUID of the root
		\param removeUUID      UUID to be deleted
		\param writeDbmsImmediately          If true, execute record as fast as possible in DBMS.

		\~chinese
		????ÍÅ\ref UnilateralAddData%¡£
		\param rootUUID ãÀrootîÜUUID¡£
		\param removeUUID é©?ğ¶îÜUUID¡£
		\param writeDbmsImmediately true îÜ?õÌöááÜîÜî¤DBMS?ú¼??¡£

		\~japanese
		ßÙª·ª¯ªÏ¡¢\ref UnilateralAddData ?ÍÅ
		\param rootUUID rootªÎ UUID
		\param removeUUID ğ¶ËÛª¹ªë UUID
		\param writeDbmsImmediately trueªÇª¢ªìªĞDBMSªËõÌÓŞùÚáÜª¯ÑÀ?ªòâÄú¼ª·ªŞª¹¡£

		\~
		*/
		virtual bool UnilateralRemoveData(Guid rootUUID, Guid removeUUID, bool writeDbmsImmediately = true) = 0;

		/**
		\~korean
		ÀÚ¼¼ÇÑ ¼³¸íÀº \ref UnilateralAddData Âü°í
		\param loadedData ·ÎµåµÈ Data
		\param transactional Æ®·»Á§¼Ç ±â´É »ç¿ë ¿©ºÎ
		\param writeDbmsImmediately trueÀÌ¸é DBMS¿¡ ÃÖ´ëÇÑ »¡¸® ±â·ÏÀ» ¼öÇà

		\~english TODO:translate needed.
		For a detailed explanation, refer to \ref UnilateralAddData
		\param loadedData         Data Loaded data
		\param transactional      Whether to use the transaction feature 
		\param writeDbmsImmediately      If true, execute record as fast as possible in DBMS.

		\~chinese
		???Ù¥??ÍÅ\ref UnilateralAddData%¡£
		\param loadedData Ê¥?îÜData¡£
		\param transactional ŞÅéÄtransactionĞüÒö?Üú¡£
		\param writeDbmsImmediately true îÜ?õÌöááÜîÜî¤DBMS?ú¼??¡£

		\~japanese
		ßÙª·ª¯ªÏ¡¢\ref UnilateralAddData ?ÍÅ
		\param loadedData «í?«Éªµªìª¿Data
		\param transactional «È«é«ó«¶«¯«·«ç«óÑ¦ÒöªÎŞÅéÄÊ¦Üú
		\param writeDbmsImmediately trueªÇª¢ªìªĞDBMSªËõÌÓŞùÚªËáÜª¯ÑÀ?ªòâÄú¼ª·ªŞª¹¡£

		
		\~
		*/
		virtual bool UnilateralRecursiveUpdateData(CLoadedData2Ptr loadedData, bool transactional = false, bool writeDbmsImmediately = true) = 0;


		/**
		\~korean
		- Æ¯Á¤ SessionÀÇ Unload¸¦ ¿äÃ»ÇÏ°í ÇØ´ç µ¥ÀÌÅÍÀÇ µ¶Á¡±ÇÀ» Æ÷±âÇÕ´Ï´Ù.
		- \ref OnUnloadDataRequested °¡ È£ÃâµÇ¾úÀ» ¶§ ¿äÃ»ÀÚ¿¡°Ô µ¶Á¡±ÇÀ» ³Ñ°ÜÁÖ·Á¸é ÀÌ ÇÔ¼ö¸¦ È£ÃâÇØ¾ß ÇÕ´Ï´Ù.
		\param sessionGuid Unload ÇÒ µ¥ÀÌÅÍÀÇ session GuidÀÔ´Ï´Ù.
		\param messageToNextLoader µ¶Á¡±Ç ¿äÃ»ÀÚ¿¡°Ô Àü´ŞÇÏ´Â »ç¿ëÀÚ ÀÓÀÇ ¸Ş½ÃÁöÀÔ´Ï´Ù. ¿äÃ»ÀÚ´Â IDbCacheClientDelegate2.OnExclusiveLoadDataSuccessÀÇ args.m_loadResults[index].m_message¸¦ ÅëÇØ ÇØ´ç ¸Ş½ÃÁö¸¦ È®ÀÎ ÇÒ ¼ö ÀÖ½À´Ï´Ù.

		\~english
		- It requests Unload of the certain session and abandons the exclusive right of the relevant data.
		- In order to devolve the exclusive right upon a requester, you need to call this function when \ref OnUnloadDataRequested is called.
		\param sessionGuid It is a session Guid of data that needs to be unloaded.
		\param messageToNextLoader It is a user random message that is sent to the exclusive right requester. The requester may check the relevant message through args.m_loadResults[index].m_message of IDbCacheClientDelegate2.OnExclusiveLoadDataSuccess.

		\~chinese
		- ?Ï´÷åïÖSessionîÜUnloadı¨£¬Û¯???ßÓ??îÜ?ï¿?¡£
		- \ref OnUnloadDataRequestedù¬û¼õó?£¬ßÌé©??ï¿?????Ï´íºîÜ?£¬âÍû¼õóó®ùŞ?¡£
		\param sessionGuid Unload?ËßîÜsession Guid¡£
		\param messageToNextLoader ????ï¿??Ï´íºîÜìòëòéÄ?ãáãÓ¡£?Ï´íº÷×? IDbCacheClientDelegate2.OnExclusiveLoadDataSuccessîÜ args.m_loadResults[index].m_message£¬Ê¦ì¤???á¼ãÓ¡£

		\~japanese
		- ÷åïÒ SessionªÎ Unloadªòé©ôëª·¡¢ú±?«Ç?«¿ªÎ?ï¿ËìªòôôªáªŞª¹¡£
		- \ref OnUnloadDataRequested ª¬û¼ªÓõóªµªìª¿ãÁ¡¢é©ôëíºªË?ï¿?ªòÔ¤ª¹ª¿ªáªËªÏª³ªÎ??ªòû¼ªÓõóª¹ù±é©ª¬ª¢ªêªŞª¹¡£
		\param sessionGuid Unload ª¹ªë«Ç?«¿ªÎsession GuidªÇª¹¡£
		\param messageToNextLoader ?ï¿?é©ôëíºªË?Ó¹ª¹ªë«æ?«¶?ìòëò«á«Ã«»?«¸ªÇª¹¡£é©ôëíºªÏIDbCacheClientDelegate2.OnExclusiveLoadDataSuccessªÎ args.m_loadResults[index].m_messageªò÷×ª·ªÆú±?«á«Ã«»?«¸ªòü¬ìãªÇª­ªŞª¹¡£
		*/
		virtual bool UnloadDataBySessionGuid(Guid sessionGuid, const ByteArray& messageToNextLoader = ByteArray()) = 0;


		/**
		\~korean
		Unload¸¦ ÀÎÁ¤ÇÏÁö ¾Ê½À´Ï´Ù.
		- \ref OnUnloadDataRequested ¿¡ Äİ¹éÀÌ ¿Â ÀÌÈÄ È£ÃâÇØ¾ß ÇÏ´Â ÀÎÅÍÆäÀÌ½ºÀÔ´Ï´Ù.
		- ÀÌ ÇÔ¼ö¸¦ È£ÃâÇÏ¸é ´Ù¸¥ Å¬¶óÀÌ¾ğÆ®ÀÇ µ¶Á¡±ÇÀ» ³Ñ°ÜÁÖÁö ¾Ê½À´Ï´Ù.
		\param sessionGuid µ¶Á¡ÁßÀÎ µ¥ÀÌÅÍÀÇ session GuidÀÔ´Ï´Ù.
		\messageToRequester µ¶Á¡±Ç ¿äÃ»ÀÚ¿¡°Ô Àü´ŞÇÏ´Â »ç¿ëÀÚ ÀÓÀÇ ¸Ş½ÃÁöÀÔ´Ï´Ù. ¿äÃ»ÀÚ´Â IDbCacheClientDelegate2.OnExclusiveLoadDataFailedÀÇ args.m_loadResults[index].m_message¸¦ ÅëÇØ ÇØ´ç ¸Ş½ÃÁö¸¦ È®ÀÎ ÇÒ ¼ö ÀÖ½À´Ï´Ù.

		\~english
		It does not admit Unload
		- This interface has to call after callback arrived to \ref OnUnloadDataRequested.
		- If you call this function, it does not pass exclusive rights to other client.
		\param sessionGuid It is a session Guid of the exclusive data.
		\param messageToRequester It is a user random message that is sent to the exclusive right requester. The requester may check the relevant message through args.m_loadResults[index].m_message of IDbCacheClientDelegate2.OnExclusiveLoadDataFailed.

		\~chinese
		Üôã¯?unload¡£
		- üŞ?Óğ\ref OnUnloadDataRequested%ì¤ı¨é©û¼Ğ£îÜ?ÖÇ¡£
		- û¼Ğ£ó®ùŞ?îÜ?£¬Üô??ĞìöâèÌÊ«îÜ?ï¿?¡£
		\param sessionGuid ?ï¿ñé?ËßîÜsession Guid¡£
		\param messageToRequester ????ï¿??Ï´íºîÜìòù¼éÄ?ãáãÓ¡£?Ï´íº÷×?IDbCacheClientDelegate2.OnExclusiveLoadDataFailedîÜ args.m_loadResults[index].m_message£¬Ê¦ì¤???á¼ãÓ¡£

		\~japanese
		UnloadªòìãªáªŞª»ªó¡£
		- \ref OnUnloadDataRequested ªË«³?«ë«Ğ«Ã«¯ª¬?ª¿ì¤ı­¡¢û¼õóù±é©ª¬ª¢ªë«¤«ó«¿?«Õ«§?«¹ªÇª¹¡£
		- ª³ªÎ??ªòû¼õóª·ª¿ªéêŞª¦«¯«é«¤«¢«ó«ÈªÎ?ï¿?ªòÔ¤ª·ªŞª»ªó¡£
		\param sessionGuid ?ï¿ñéªÎ«Ç?«¿ªÎ session GuidªÇª¹¡£
		\param messageToRequester ?ï¿?é©ôëíºªË?Ó¹ª¹ªë«æ?«¶?ìòëò«á«Ã«»?«¸ªÇª¹¡£é©ôëíºªÏ IDbCacheClientDelegate2.OnExclusiveLoadDataFailedªÎ args.m_loadResults[index].m_messageªò÷×ª¸ªÆú±?«á«Ã«»?«¸ªòü¬ìãªÇª­ªŞª¹¡£

		*/
		virtual void DenyUnloadData(Guid sessionGuid, const ByteArray& messageToRequester = ByteArray()) = 0;

		/*
		\~korean
		°°Àº ÀÌ¸§ÀÇ ¸Ş¼­µå Âü°í

		\~english
		Refer to same name method

		\~chinese
		?ÍÅÔÒÙ£îÜÛ°Ûö¡£

		\~japanese
		ÔÒÙ£ªÎ«á«½«Ã«É?ÍÅ
		\~
		*/
		/*inline bool UnloadDataBySessionGuid(CLoadedDataPtr data)
		{
		return UnloadDataBySessionGuid(data->m_sessionGuid);
		} */

		/**
		\~korean
		Data tree¸¦ DB cache·ÎºÎÅÍ ¿ÏÀüÈ÷ unloadÇØ ¹ö¸³´Ï´Ù. DB cache client»Ó¸¸ ¾Æ´Ï¶ó
		DB cache server¿¡¼­µµ unload¸¦ ÇÕ´Ï´Ù.

		DB cache°¡ »ç¿ëÁßÀÎ data tree¸¦ Á÷Á¢ DB ¾ï¼¼½º¸¦ ÅëÇØ ´Ù·ç°íÀÚ ÇÑ´Ù¸é,
		ÀÌ ÇÔ¼ö ´ë½Å <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache°¡ ´Ù·ç´Â µ¥ÀÌÅÍ¸¦ DB°¡ Á÷Á¢ ¾ï¼¼½ºÇÏ±â</a> ±â´ÉÀ» »ç¿ëÇÏ½Ê½Ã¿À.

		\param rootUUID unloadÇÏ°íÀÚ ÇÏ´Â data treeÀÇ root UUIDÀÔ´Ï´Ù.

		\~english
		Data tree is completely uploaded from DB cache. It must be uploaded in DB
		cache client and DB cache server.

		If you want to deal with data tree that DB cache is using by direct DB access,
		you need to use <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_isolate_overview" >DB directly has access to data that DB cache deals with </a> function instead of this function.

		\param rootUUID this is root UUID of data tree that is going to be unloaded.

		\~chinese
		?DB cacheèÇîïunload Data tree¡£ğ¶ÖõDB cache client£¬
		î¤DB cache serverñéå¥?ú¼ unload¡£

		åıÍıDB cacheßÌé©÷×?DB??ğÃíÂïáî¤ŞÅéÄñéîÜdata tree£¬
		?éÄ <a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_isolate_overview" >DBòÁïÈ??DB cacheğÃíÂîÜ?Ëß</a> ÍíÒöÓÛôğó®ùŞ?¡£

		\param rootUUID é©?ú¼unloadîÜdata treeîÜ root UUID.

		\~japanese
		Data treeªòDB cacheª«ªéèÇîïªËunloadª·ªŞª¹¡£ DB cache clientªÀª±ªÇªÏªÊª¯ªÆ¡¢
		DB cache serverªÇªâunloadªòª·ªŞª¹¡£

		DB cacheª¬ŞÅéÄñéªÎdata treeªòòÁïÈ DB«¢«¯«»«¹ªò÷×ª·ªÆĞâªªª¦ªÈª¹ªëğ·ªËªÏ¡¢
		ª³ªÎ??ªÎÓÛªïªêªË <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_isolate_overview" >DB cacheª¬ğÃªë«Ç?«¿ªòDBª¬òÁïÈ«¢«¯«»«¹</a> ªÎÑ¦ÒöªòŞÅéÄª·ªÆª¯ªÀªµª¤¡£

		\param rootUUID unloadª·ªèª¦ªÈª¹ªë data treeªÎroot UUIDªÇª¹¡£
		*/
		virtual void ForceCompleteUnload(Guid rootUUID) = 0;

		/**
		\~korean
		ºñµ¶Á¡ÀûÀ¸·Î dataÀÇ ÃÖ½Å »óÅÂ¸¦ ¾ò¾î¿É´Ï´Ù. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù. \n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)

		\param rootTableName root Å×ÀÌºíÀÇ ÀÌ¸§
		\param fieldName ÇÊµå¸í
		\param cmpValue ºñ±³ÇÒ °ª. ÀÌ¸¦ SQL¹®¿¡ ºñÀ¯ÇÏ¸é WHERE fieldName = cmpValue ¿Í µ¿ÀÏÇÕ´Ï´Ù.
		\param tag ÀÌ¿äÃ»¿¡´ëÇÑ »ç¿ëÀÚ°¡ ³Ö¾îÁÙ ½Äº° °ªÀÔ´Ï´Ù.Äİ¹é½Ã \ref CCallbackArg ¾ÈÀÇ m_tag·Î µé¾î°©´Ï´Ù.

		\~english
		Gets the latest status value as non-exclusively. <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function.
		\param rootTableName Name of root table
		\param fieldName
		\param cmpValue
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.

		\~chinese
		Şª?ï¿àõîÜ?ö¢õÌãæîÜ??¡£ãÀ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%ĞüÒö¡£\n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)
		\param rootTableName root table îÜÙ£?¡£
		\param fieldName
		\param cmpValue
		\param tag ?ó®é­?éÄ?é©?ìıîÜ???¡£üŞ???ìı\ref CCallbackArg%îÜm_tag¡£

		\~japanese
		Şª?ï¿îÜªË«Ç?«¿ªÎõÌãæ?÷¾ªòÔğªÆª­ªŞª¹¡£\ref pndb_nonexclusive_access Ñ¦ÒöªÇª¹¡£\n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)
		\param rootTableName root «Æ?«Ö«ëÙ£
		\param rootUUID «Ç?«¿?ßãªòRootUUID
		\param tag ª³ªÎé©ôëªË?ª¹ªë«æ?«¶?ª¬ìıªìªÆª¯ªìªëãÛÜ¬ö·ªÇª¹¡£«³?«ë«Ğ«Ã«¯ãÁ¡¢\ref CCallbackArg?ªÎm_tagªËìıªêªŞª¹¡£

		\~
		*/
		virtual void RequestNonExclusiveSnapshotData(String rootTableName, String fieldName, CVariant cmpValue, intptr_t tag) = 0;

		/**
		\~korean
		ºñµ¶Á¡ÀûÀ¸·Î dataÀÇ ÃÖ½Å »óÅÂ¸¦ ¾ò¾î¿É´Ï´Ù. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù. \n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)

		\param rootTableName root Å×ÀÌºíÀÇ ÀÌ¸§
		\param rootUUID µ¥ÀÌÅÍ °Ë»öÀ» RootUUID
		\param tag ÀÌ¿äÃ»¿¡´ëÇÑ »ç¿ëÀÚ°¡ ³Ö¾îÁÙ ½Äº° °ªÀÔ´Ï´Ù.Äİ¹é½Ã \ref CCallbackArg ¾ÈÀÇ m_tag·Î µé¾î°©´Ï´Ù.

		\~english
		Gets the latest status value as non-exclusively. <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function.
		\param rootTableName Name of root table
		\param rootUUID
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.

		\~chinese
		Şª?ï¿àõîÜ?ö¢õÌãæîÜ??¡£ãÀ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%ĞüÒö¡£\n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)
		\param rootTableName root table îÜÙ£?¡£
		\param rootUUID
		\param tag ?ó®é­?éÄ?é©?ìıîÜ???¡£üŞ???ìı\ref CCallbackArg%îÜm_tag¡£

		\~japanese
		
		\~
		*/
		virtual void RequestNonExclusiveSnapshotDataByGuid(String rootTableName, Guid rootUUID, intptr_t tag) = 0;

		/**
		\~korean
		ºñµ¶Á¡ÀûÀ¸·Î dataÀÇ ÃÖ½Å »óÅÂ¸¦ ¾ò¾î¿É´Ï´Ù. <a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù. \n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)

		\param rootTableName root Å×ÀÌºíÀÇ ÀÌ¸§
		\param searchString µ¥ÀÌÅÍ °Ë»öÀ» À§ÇÑ Äõ¸®¹® ( whereÀı ÀÌÈÄ¿¡ µé¾î°¥ ±¸¹® )
		\param tag ÀÌ¿äÃ»¿¡´ëÇÑ »ç¿ëÀÚ°¡ ³Ö¾îÁÙ ½Äº° °ªÀÔ´Ï´Ù.Äİ¹é½Ã \ref CCallbackArg ¾ÈÀÇ m_tag·Î µé¾î°©´Ï´Ù.

		\~english
		Gets the latest status value as non-exclusively. <a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function.
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)

		\param rootTableName Name of root table
		\param searchString Query for data searching( For after "where")
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.

		\~chinese
		Şª?ï¿àõîÜ?ö¢õÌãæîÜ??¡£ãÀ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%ĞüÒö¡£\n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)

		\param rootTableName root table îÜÙ£?¡£
		\param searchString ?Öõ?Ëßâ¤ßãîÜquery?Ï£¡££¨where ì¤ı¨?ìıîÜ?Ï££©
		\param tag ?ó®é­?éÄ?é©?ìıîÜ???¡£üŞ???ìı\ref CCallbackArg%îÜm_tag¡£

		\~japanese
		Şª?ï¿îÜªË dataªÎõÌãæ?÷¾ªò?ªß?ªßªŞª¹¡£ <a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> Ñ¦ÒöªÇª¹¡£\n
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSnapshotDataFailed (CCallbackArgs args)

		\param rootTableName root «Æ?«Ö«ëªÎÙ£îñ
		\param searchString «Ç?«¿?ßãªÎª¿ªáªÎ«¯«¨«ê?Ùş ( whereï½ªÎì¤Ë½ªËìıªëÏ°Ùş)
		\param tag ª³ªÎé©ôëªË?ª·ªÆ«æ?«¶ª¬ìıÕôª¹ªëãÛÜ¬ªÎö·ªÇª¹¡£«³?«ë«Ğ«Ã«¯ãÁ \ref CCallbackArg ñéªÎ m_tagªËìıªêªŞª¹¡£

		\~
		*/
		virtual void RequestNonExclusiveSnapshotDataByQuery(String rootTableName, String searchString, intptr_t tag) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù.
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveAddDataAck (CCallbackArgs args)

		µ¶Á¡ÁßÀÎ DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneAddData(CCallbackArgs& args)

		\param rootTableName rootÅ×ÀÌºíÀÇ ÀÌ¸§ÀÔ´Ï´Ù.
		\param rootUUID rootÀÇ UUIDÀÔ´Ï´Ù.
		\param ownerUUID ownerÀÇ UUIDÀÔ´Ï´Ù.
		\param addData Ãß°¡ÇÒ nodeÀÇ dataÀÔ´Ï´Ù.
		\param tag ¿äÃ» ½Äº°À» À§ÇÑ »ç¿ëÀÚ ÀÓÀÇ µ¥ÀÌÅÍÀÔ´Ï´Ù. Äİ¹é ½Ã \ref CCallbackArg ÀÇ m_tag¸¦ ÅëÇØ µ¹·Á¹Ş½À´Ï´Ù.
		\param messageToLoader ÇØ´ç µ¥ÀÌÅÍÀÇ µ¶Á¡ÀÚ¿¡°Ô Àü´ŞÇÏ´Â »ç¿ëÀÚ ÀÓÀÇ ¸Ş½ÃÁöÀÔ´Ï´Ù. µ¶Á¡ÀÚ´Â IDbCacheClientDelegate2::OnSomeoneAddDataÀÇ args.m_loadResults[index].m_message¸¦ ÅëÇØ ÀÌ¸¦ Àü´Ş¹Ş½À´Ï´Ù.


		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function.
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveAddDataAck (CCallbackArgs args)

		Exclusive DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneAddData(CCallbackArgs& args)

		\param rootTableName it is name of root table.
		\param rootUUID it is UUID of root.
		\param ownerUUID it is UUID of owner.
		\param addData it is data of node that is going to be added.
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.
		\param messageToLoader It is a user random message that is sent to a sole owner of the relevant data. The sole owner has this through args.m_loadResults[index].m_message of IDbCacheClientDelegate2::OnSomeoneAddData.


		\~chinese
		ãÀ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%ÍíÒö¡£
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveAddDataAck (CCallbackArgs args)

		?ï¿ñéîÜDB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneAddData(CCallbackArgs& args)
		\param rootTableName root table îÜÙ£?¡£
		\param rootUUID ãÀrootîÜUUID¡£
		\param ownerUUID ãÀownerîÜUUID¡£
		\param addData é©ôÕÊ¥îÜnodeîÜdata¡£
		\param tag ?ó®é­?£¬éÄ?é©?õöîÜ???¡£üŞ???ìı\ref CcallbackArg%îÜm_tag¡£
		\param messageToLoader ???? ßÓ??îÜ?Ëß?ï¿íºîÜìòù¼éÄ?ãáãÓ¡£?ï¿íº÷×?IDbCacheClientDelegate2::OnSomeoneAddDataîÜ args.m_loadResults[index].m_messageïÈâ¥ó®á¼ãÓ¡£

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> Ñ¦ÒöªÇª¹¡£
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveAddDataAck (CCallbackArgs args)

		?ï¿ñéªÎ DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneAddData(CCallbackArgs& args)

		\param rootTableName root«Æ?«Ö«ëªÎÙ£îñªÇª¹¡£
		\param rootUUID rootªÎ UUIDªÇª¹¡£
		\param ownerUUID ownerªÎ UUIDªÇª¹¡£
		\param addData õÚÊ¥ª¹ªënodeªÎ dataªÇª¹¡£
		\param tag ª³ªÎé©ôëªË?ª·ªÆ«æ?«¶ª¬ìıÕôª¹ªëãÛÜ¬ªÎö·ªÇª¹¡£«³?«ë«Ğ«Ã«¯ãÁ \ref CCallbackArg ñéªÎ m_tagªËìıªêªŞª¹¡£
		\param messageToLoader ú±?«Ç?«¿ªÎ?ï¿íºªËÔ¤ª¹«æ?«¶?ìòëò«á«Ã«»?«¸ªÇª¹¡£?ï¿íºªÏ IDbCacheClientDelegate2::OnSomeoneAddDataªÎ args.m_loadResults[index].m_messageªò÷×ª¸ªÆª³ªìªò?Ó¹ªµªìªŞª¹¡£

		\~
		*/
		virtual void RequestNonExclusiveAddData(String rootTableName, Guid rootUUID, Guid ownerUUID, CPropNodePtr addData, intptr_t tag, const ByteArray &messageToLoader=ByteArray()) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù.

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveRemoveDataAck (CCallbackArgs args)

		µ¶Á¡ ÁßÀÎ DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneRemoveData (CCallbackArgs& args)

		\param rootTableName rootÅ×ÀÌºíÀÇ ÀÌ¸§ÀÔ´Ï´Ù.
		\param rootUUID rootÀÇ UUIDÀÔ´Ï´Ù.
		\param removeUUID Á¦°ÅÇÏ°íÀÚ ÇÏ´Â UUIDÀÔ´Ï´Ù.
		\param tag ¿äÃ» ½Äº°À» À§ÇÑ »ç¿ëÀÚ ÀÓÀÇ µ¥ÀÌÅÍÀÔ´Ï´Ù. Äİ¹é ½Ã \ref CCallbackArg ÀÇ m_tag¸¦ ÅëÇØ µ¹·Á¹Ş½À´Ï´Ù.
		\param messageToLoader ÇØ´ç µ¥ÀÌÅÍÀÇ µ¶Á¡ÀÚ¿¡°Ô Àü´ŞÇÏ´Â ¸Ş½ÃÁöÀÔ´Ï´Ù. µ¶Á¡ÀÚ´Â IDbCacheClientDelegate2::OnSomeoneRemoveDataÀÇ args.m_loadResults[index].m_message¸¦ ÅëÇØ ÀÌ¸¦ Àü´Ş¹Ş½À´Ï´Ù.


		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function.

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveRemoveDataAck (CCallbackArgs args)

		Exclusive DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneRemoveData (CCallbackArgs& args)

		\param rootTableName it is name of root table.
		\param rootUUID it is UUID of root.
		\param removeUUID it is UUID that is going to be eliminated.
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.
		\param messageToLoader It is a user random message that is sent to a sole owner of the relevant data. The sole owner has this through args.m_loadResults[index].m_message of IDbCacheClientDelegate2::OnSomeoneAddData.


		\~chinese
		ãÀ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%ÍíÒö¡£
		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveRemoveDataAck (CCallbackArgs args)

		?ï¿ñéîÜDB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneRemoveData (CCallbackArgs& args)
		\param rootTableName root table îÜÙ£?¡£
		\param rootUUID ãÀrootîÜUUID¡£
		\param removeUUID é©?ğ¶îÜUUID¡£
		\param tag ?ó®é­?£¬éÄ?é©?õöîÜ???¡£üŞ???ìı\ref CcallbackArg%îÜm_tag¡£
		\param messageToLoader ???? ßÓ??îÜ?Ëß?ï¿íºîÜìòù¼éÄ?ãáãÓ¡£?ï¿íº÷×?IDbCacheClientDelegate2::OnSomeoneAddDataîÜ args.m_loadResults[index].m_messageïÈâ¥ó®á¼ãÓ¡£


		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> Ñ¦ÒöªÇª¹¡£

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveRemoveDataAck (CCallbackArgs args)

		?ï¿ñéªÎDB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneRemoveData (CCallbackArgs& args)

		\param rootTableName root«Æ?«Ö«ëªÎÙ£îñªÇª¹¡£
		\param rootUUID rootªÎ UUIDªÇª¹¡£
		\param removeUUID ğ¶ËÛª·ªèª¦ªÈª¹ªëUUIDªÇª¹¡£
		\param tag ª³ªÎé©ôëªË?ª·ªÆ«æ?«¶ª¬ìıÕôª¹ªëãÛÜ¬ªÎö·ªÇª¹¡£«³?«ë«Ğ«Ã«¯ãÁ \ref CCallbackArg ñéªÎ m_tagªËìıªêªŞª¹¡£
		\param messageToLoader ú±?«Ç?«¿ªÎ?ï¿íºªËÔ¤ª¹«æ?«¶?ìòëò«á«Ã«»?«¸ªÇª¹¡£?ï¿íºªÏ IDbCacheClientDelegate2::OnSomeoneAddDataªÎ args.m_loadResults[index].m_messageªò÷×ª¸ªÆª³ªìªò?Ó¹ªµªìªŞª¹¡£

		\~
		*/
		virtual void RequestNonExclusiveRemoveData(String rootTableName, Guid rootUUID, Guid removeUUID, intptr_t tag, const ByteArray &messageToLoader=ByteArray()) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù.
		- DBCacheServer¿¡ ·ÎµåµÇ¾îÀÖ´Â ±âÁ¸°ª°ú compareValue¸¦ ºñ±³ÇÏ¿© Á¶°ÇÀ» ÃæÁ·ÇÏ¸é newValue·Î º¯°æÇÕ´Ï´Ù.

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfFailed (CCallbackArgs args)

		µ¶Á¡ ÁßÀÎ DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneSetValue (CCallbackArgs& args)

		\param rootTableName rootÅ×ÀÌºíÀÇ ÀÌ¸§ÀÔ´Ï´Ù.
		\param rootUUID rootÀÇ UUIDÀÔ´Ï´Ù.
		\param nodeUUID nodeÀÇ UUIDÀÔ´Ï´Ù.
		\param propertyName °ªÀ» settingÇÒ ¼Ó¼ºÀÇ ÀÌ¸§ÀÔ´Ï´Ù.
		\param newValue ºñ±³ Á¶°ÇÀ» ÃæÁ·ÇÏ´Â °æ¿ì »õ·Î ´ëÀÔµÉ °ªÀÔ´Ï´Ù.
		\param compareType ºñ±³ Á¶°Ç typeÀÔ´Ï´Ù.
		\param compareValue ±âÁ¸ °ª°ú ºñ±³ÇÒ °ªÀÔ´Ï´Ù.
		\param tag ¿äÃ» ½Äº°À» À§ÇÑ »ç¿ëÀÚ ÀÓÀÇ µ¥ÀÌÅÍÀÔ´Ï´Ù. Äİ¹é ½Ã \ref CCallbackArg ÀÇ m_tag¸¦ ÅëÇØ µ¹·Á¹Ş½À´Ï´Ù.
		\param messageToLoader ÇØ´ç µ¥ÀÌÅÍÀÇ µ¶Á¡ÀÚ¿¡°Ô Àü´ŞÇÏ´Â ¸Ş½ÃÁöÀÔ´Ï´Ù. µ¶Á¡ÀÚ´Â IDbCacheClientDelegate2::OnSomeoneSetValueÀÇ args.m_loadResults[index].m_message¸¦ ÅëÇØ ÀÌ¸¦ Àü´Ş¹Ş½À´Ï´Ù.


		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a>	 function.
		It is changed to newValue if the conditions are satisfied, after comparing the existing value that has been loaded at DBCacheServer and compareValue.

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfFailed (CCallbackArgs args)

		Exclusive DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneSetValue (CCallbackArgs& args)

		\param rootTableName it is name of root.
		\param rootUUID it is UUID of root.
		\param nodeUUID it is UUID of node.
		\param propertyName it is name of attribute that sets values.
		\param newValue It is a value that will be substituted in case relation condition is satisfied.
		\param compareType it is the type of relation condition.
		\param compareValue It is a value that will be compared with the existing value.
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.
		\param messageToLoader It is a user random message that is sent to a sole owner of the relevant data. The sole owner has this through args.m_loadResults[index].m_message of IDbCacheClientDelegate2::OnSomeoneAddData.


		\~chinese
		ãÀ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%ÍíÒö¡£
		?İï?ìıDBCacheServerñéîÜĞñÜâ??compareValueı¨£¬åıÍı?ËìõöğëîÜ??ÌÚ? newValue¡£

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfFailed (CCallbackArgs args)

		?ï¿ñéîÜDB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneSetValue (CCallbackArgs& args)
		\param rootTableName root table îÜÙ£?¡£
		\param rootUUID ãÀrootîÜUUID¡£
		\param nodeUUID ãÀnodeîÜUUID¡£
		\param propertyName é©settingîÜ?îÜ?àõÙ£í®¡£
		\param newValue î¤?İï?ËìõöğëîÜï×?£¬?ãæÓÛìıîÜ?¡£
		\param compareType İï??Ëìtype¡£
		\param compareValue ?ĞñÜâ??İïîÜ?¡£
		\param tag ?ó®é­?£¬éÄ?é©?õöîÜ???¡£üŞ???ìı\ref CcallbackArg%îÜm_tag¡£
		\param messageToLoader ???? ßÓ??îÜ?Ëß?ï¿íºîÜìòù¼éÄ?ãáãÓ¡£?ï¿íº÷×?IDbCacheClientDelegate2::OnSomeoneAddDataîÜ args.m_loadResults[index].m_messageïÈâ¥ó®á¼ãÓ¡£


		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> Ñ¦ÒöªÇª¹¡£
		DBCacheServerªË«í?«ÉªµªìªÆª¤ª¨ªë?ğíö·ªÈ compareValueªòİïÎòª·¡¢?Ëìªò?ª¿ª·ª¿ªé newValueªË?ÌÚª·ªŞª¹¡£

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveSetValueIfFailed (CCallbackArgs args)

		?ï¿ñéªÎDB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneSetValue (CCallbackArgs& args)

		\param rootTableName root«Æ?«Ö«ëªÎÙ£îñªÇª¹¡£
		\param rootUUID rootªÎ UUIDªÇª¹¡£
		\param nodeUUID nodeªÎ UUIDªÇª¹¡£
		\param propertyName ö·ªò settingª¹ªë?àõªÎÙ£îñªÇª¹¡£
		\param newValue İïÎò?Ëìªò?ª¿ª¹íŞùêãæª·ª¯ÓÛìıªµªìªëö·ªÇª¹¡£
		\param compareType İïÎò?Ëì typeªÇª¹¡£
		\param compareValue ?ğíö·ªÈİïÎòª¹ªëö·ªÇª¹¡£
		\param tag ª³ªÎé©ôëªË?ª·ªÆ«æ?«¶ª¬ìıÕôª¹ªëãÛÜ¬ªÎö·ªÇª¹¡£«³?«ë«Ğ«Ã«¯ãÁ \ref CCallbackArg ñéªÎ m_tagªËìıªêªŞª¹¡£
		\param messageToLoader ú±?«Ç?«¿ªÎ?ï¿íºªËÔ¤ª¹«æ?«¶?ìòëò«á«Ã«»?«¸ªÇª¹¡£?ï¿íºªÏ IDbCacheClientDelegate2::OnSomeoneAddDataªÎ args.m_loadResults[index].m_messageªò÷×ª¸ªÆª³ªìªò?Ó¹ªµªìªŞª¹¡£

		\~
		*/
		virtual void RequestNonExclusiveSetValueIf(String rootTableName, Guid rootUUID, Guid nodeUUID, String propertyName, CVariant newValue, ValueCompareType compareType, CVariant compareValue, intptr_t tag, const ByteArray &messageToLoader=ByteArray()) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_nonexclusive_overview" >ºñµ¶Á¡Àû µ¥ÀÌÅÍ Á¢±ÙÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù.

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueFailed (CCallbackArgs args)

		µ¶Á¡ ÁßÀÎ DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneModifyValue (CCallbackArgs& args)

		\param rootTableName rootÅ×ÀÌºíÀÇ ÀÌ¸§ÀÔ´Ï´Ù.
		\param rootUUID rootÀÇ UUIDÀÔ´Ï´Ù.
		\param nodeUUID nodeÀÇ UUIDÀÔ´Ï´Ù.
		\param propertyName °ªÀ» settingÇÒ ¼Ó¼ºÀÇ ÀÌ¸§ÀÔ´Ï´Ù.
		\param operType ¿¬»ê Å¸ÀÔ
		\param value Àû¿ë½ÃÅ³ °ªÀÔ´Ï´Ù.
		\param tag ¿äÃ» ½Äº°À» À§ÇÑ »ç¿ëÀÚ ÀÓÀÇ µ¥ÀÌÅÍÀÔ´Ï´Ù. Äİ¹é ½Ã \ref CCallbackArg ÀÇ m_tag¸¦ ÅëÇØ µ¹·Á¹Ş½À´Ï´Ù.
		\param messageToLoader ÇØ´ç µ¥ÀÌÅÍÀÇ µ¶Á¡ÀÚ¿¡°Ô Àü´ŞÇÏ´Â ¸Ş½ÃÁöÀÔ´Ï´Ù. µ¶Á¡ÀÚ´Â IDbCacheClientDelegate2::OnSomeoneModifyValueÀÇ args.m_loadResults[index].m_message¸¦ ÅëÇØ ÀÌ¸¦ Àü´Ş¹Ş½À´Ï´Ù.


		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> function.

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueFailed (CCallbackArgs args)

		Exclusive DB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneModifyValue (CCallbackArgs& args)

		\param rootTableName it is name of root table.
		\param rootUUID it is UUID of root.
		\param nodeUUID it is UUID of node.
		\param propertyName it is name of attribute that sets values.
		\param operType it is the type of calculation.
		\param value it is value that is going to be applied.
		\param tag Verifying value about request that user need to put in. When you callback, it go throuth m_tag in CCallbackArg.
		\param messageToLoader It is a user random message that is sent to a sole owner of the relevant data. The sole owner has this through args.m_loadResults[index].m_message of IDbCacheClientDelegate2::OnSomeoneAddData.


		\~chinese
		ãÀ<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_nonexclusive_overview" >??Íìú½àõ?Ëß</a>%ÍíÒö¡£

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueFailed (CCallbackArgs args)

		?ï¿ñéîÜDB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneModifyValue (CCallbackArgs& args)
		\param rootTableName root table îÜÙ£?¡£
		\param rootUUID ãÀrootîÜUUID¡£
		\param nodeUUID ãÀnodeîÜUUID¡£
		\param propertyName é©settingîÜ?îÜ?àõÙ£í®¡£
		\param operType ?ß©úş¡£
		\param value é©ÎÁéÄîÜ?¡£
		\param tag ?ó®é­?£¬éÄ?é©?õöîÜ???¡£üŞ???ìı\ref CcallbackArg%îÜm_tag¡£
		\param messageToLoader ???? ßÓ??îÜ?Ëß?ï¿íºîÜìòù¼éÄ?ãáãÓ¡£?ï¿íº÷×?IDbCacheClientDelegate2::OnSomeoneAddDataîÜ args.m_loadResults[index].m_messageïÈâ¥ó®á¼ãÓ¡£


		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_nonexclusive_overview" >Accessing non-exclusive data</a> Ñ¦ÒöªÇª¹¡£

		Callback:
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueSuccess (CCallbackArgs args)
		- IDbCacheClientDelegate2::OnNonExclusiveModifyValueFailed (CCallbackArgs args)

		?ï¿ñéªÎDB Cache Client Callback:
		- IDbCacheClientDelegate2::OnSomeoneModifyValue (CCallbackArgs& args)

		\param rootTableName root«Æ?«Ö«ëªÎÙ£îñªÇª¹¡£
		\param rootUUID rootªÎ UUIDªÇª¹¡£
		\param nodeUUID nodeªÎ UUIDªÇª¹¡£
		\param propertyName ö·ªò settingª¹ªë?àõªÎÙ£îñªÇª¹¡£
		\param operType æÑß©«¿«¤«×
		\param value îêéÄªµª»ªëö·ªÇª¹¡£
		\param tag ª³ªÎé©ôëªË?ª·ªÆ«æ?«¶ª¬ìıÕôª¹ªëãÛÜ¬ªÎö·ªÇª¹¡£«³?«ë«Ğ«Ã«¯ãÁ \ref CCallbackArg ñéªÎ m_tagªËìıªêªŞª¹¡£
		\param messageToLoader ú±?«Ç?«¿ªÎ?ï¿íºªËÔ¤ª¹«æ?«¶?ìòëò«á«Ã«»?«¸ªÇª¹¡£?ï¿íºªÏ IDbCacheClientDelegate2::OnSomeoneAddDataªÎ args.m_loadResults[index].m_messageªò÷×ª¸ªÆª³ªìªò?Ó¹ªµªìªŞª¹¡£

		\~
		*/
		virtual void RequestNonExclusiveModifyValue(String rootTableName, Guid rootUUID, Guid nodeUUID, String propertyName, ValueOperType operType, CVariant value, intptr_t tag, const ByteArray &messageToLoader=ByteArray()) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache°¡ ´Ù·ç´Â µ¥ÀÌÅÍ¸¦ DB°¡ Á÷Á¢ ¾ï¼¼½ºÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù.
		DB cache°¡ »ç¿ëÁßÀÎ data tree¸¦ Á÷Á¢ DB ¾ï¼¼½º¸¦ ÅëÇØ Á¢±ÙÇÒ ¼ö ÀÖµµ·Ï ¿äÃ»ÇÕ´Ï´Ù.
		DB cache´Â »ç¿ëÀÚ°¡ ¾ÈÀüÇÏ°Ô Á¢±ÙÇÒ ¼ö ÀÖµµ·Ï Ä³½ÌÇÏ´ø Data tree ¸¦ unload ÇÕ´Ï´Ù.

		isolate ¿äÃ»ÀÌ ¼º°øÇÏ¸é DB cache ´Â data tree ¿¡ Àı´ë Á¢±ÙÇÏÁö ¾Ê½À´Ï´Ù.
		»ç¿ëÀÚ´Â ÀÌ ÇÔ¼ö¸¦ È£ÃâÇÑ µÚ data ¸¦ Á÷Á¢ ¾ï¼¼½ºÇÕ´Ï´Ù.
		»ç¿ëÀÚ´Â ÀÛ¾÷À» ¿Ï·áÇÏ¸é RequestDeisolateData ¸¦ È£ÃâÇÏ¿© DB cache ¿¡ ÀÛ¾÷ÀÌ ³¡³µÀ½À» ¾Ë·Á¾ß ÇÕ´Ï´Ù.

		- DB cache ¿¡¼­ data tree °¡ ¼º°øÀûÀ¸·Î isolate µÇ¸é OnIsolateDataSuccess ÀÌº¥Æ®°¡ ¹ß»ıÇÕ´Ï´Ù.
		- data tree °¡ ÀÌ¹Ì isolate »óÅÂÀÌ°Å³ª unload ¿¡ ½ÇÆĞÇÏ¸é OnIsolateDataFailed ÀÌº¥Æ®°¡ ¹ß»ıÇÕ´Ï´Ù.

		\param rootUUID isolateÇÏ°íÀÚ ÇÏ´Â data treeÀÇ root UUIDÀÔ´Ï´Ù.
		\param rootTableName isolateÇÏ°íÀÚ ÇÏ´Â data treeÀÇ rootÅ×ÀÌºíÀÇ ÀÌ¸§ÀÔ´Ï´Ù.
		\param [out] outSessionGuid session ½Äº°ÀÚÀÔ´Ï´Ù.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_isolate_overview" >DB directly has access to data that DB cache deals with </a> function.
		It requests access to data tree that DB cache is using by direct DB access.
		DB cache unloads data tree that is the process of caching for user¡¯s safe access.

		If isolate request is successful, DB cache will never have access to data tree.
		After calling this function, a user has access to data directly.
		Once works are done, a user must inform DB cache by calling RequestDeisolateData that works have been done.

		- If data tree is successfully isolated from DB cache, OnIsolateDataSuccess event will occur.
		- If data tree has been already isolated or unloading fails, OnIsolateDataFailed event will occur.

		\param rootUUID It is root UUID of data tree that is going to be isolated.
		\param rootTableName It is root table name of data tree that is going to be isolated.
		\param [out] outSessionGuid session identifier.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_isolate_overview" >DBòÁïÈ??DB cacheğÃíÂîÜ?Ëß</a> ÍíÒö¡£
		?Ï´DB cacheÒö?÷×?DB??òÁïÈ??ïáî¤ŞÅéÄñéîÜdata tree¡£
		?éÄ?Òö?äÌîï??£¬DB cache unloadïáî¤CachingîÜData tree¡£

		åıÍıisolate ?Ï´à÷Íí?DB cache?Üô?? data tree¡£
		éÄ?û¼õóó®ùŞ?ı¨Ê¦ì¤òÁïÈ??data¡£
		éÄ??áÖğÃíÂı¨âÍé©û¼õó RequestDeisolateData £¬ú¾DB cacheÍ±ò±ì«?áÖğÃíÂ¡£

		- î¤DB cache ñé data tree à÷Íí?ú¼ isolate ı¨??ßæ OnIsolateDataSuccess ŞÀËì¡£
		- åıÍıdata tree ì«?ãÀ isolate ??ûä unload ã÷????ßæOnIsolateDataFailed ŞÀËì¡£

		\param rootUUID é©?ú¼ isolateîÜ data treeîÜ root UUID¡£
		\param rootTableName é©?ú¼isolateîÜ data treeîÜ root TableÙ£¡£
		\param [out] outSessionGuid session ??íº¡£

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_isolate_overview" >DB cacheª¬ğÃªë«Ç?«¿ªòDBª¬òÁïÈ«¢«¯«»«¹</a>Ñ¦ÒöªÇª¹¡£
		DB cacheª¬ŞÅéÄñéªÎdata treeªòòÁïÈDB«¢«¯«»«¹ªò÷×ª·ªÆïÈĞÎªÇª­ªëªèª¦ªËé©ôëª·ªŞª¹¡£
		DB cacheªÏ«æ?«¶ª¬äÌîïªËïÈĞÎªÇª­ªëªèª¦ªËCachingª·ªÆª¤ª¿Data treeªòunload ª·ªŞª¹¡£

		isolateé©ôëª¬à÷Ííª¹ªëªÈDB cacheªÏdata treeªËïÈĞÎª·ªŞª»ªó¡£
		«æ?«¶ªÏª³ªÎ??ªòû¼ªÓõóª·ª¿ı­, dataªòòÁïÈ«¢«¯«»«¹ª·ªŞª¹¡£
		«æ?«¶ªÏíÂåöªòèÇÖõª¹ªëªÈ RequestDeisolateDataªòû¼ªÓõóª·ªÆ DB cacheªËíÂåöªÎğûªïªêªòò±ªéª»ªÊª±ªìªĞªÊªêªŞª»ªó¡£

		- DB cacheªÇdata treeª¬à÷ÍíîÜªËisolateªµªìªëªÈOnIsolateDataSuccess«¤«Ù«ó«Èª¬?ßæª·ªŞª¹¡£
		- data treeª¬?ªËisolate?÷¾ªÇª¢ªÃª¿unloadªËã÷ø¨ª¹ªëªÈOnIsolateDataFailed «¤«Ù«ó«Èª¬?ßæª·ªŞª¹¡£

		\param rootUUID isolateª·ªèª¦ªÈª¹ªë data treeªÎroot UUIDªÇª¹¡£
		\param rootTableName isolateª·ªèª¦ªÈª¹ªëdata treeªÎroot«Æ?«Ö«ëªÎÙ£îñªÇª¹¡£
		\param [out] outSessionGuid sessionãÛÜ¬í­ªÇª¹¡£
		*/
		virtual bool RequestIsolateData(Guid rootUUID, String rootTableName, Guid &outSessionGuid) = 0;

		/**
		\~korean
		<a target="_blank" href="http://guide.nettention.com/cpp_ko#dbc2_isolate_overview" >DB cache°¡ ´Ù·ç´Â µ¥ÀÌÅÍ¸¦ DB°¡ Á÷Á¢ ¾ï¼¼½ºÇÏ±â</a> ±â´ÉÀÔ´Ï´Ù.
		isolate ÇÑ data tree ¸¦ deisolate ÇÏµµ·Ï ¿äÃ»ÇÕ´Ï´Ù.

		deisolate ¿äÃ»ÀÌ ¼º°øÇÏ¸é ´Ù½Ã DB cache °¡ load & save ÇÒ ¼ö ÀÖ´Â »óÅÂ°¡ µË´Ï´Ù.

		- DB cache ¿¡¼­ data tree °¡ ¼º°øÀûÀ¸·Î deisolate µÇ¸é OnDeisolateDataSuccess ÀÌº¥Æ®°¡ ¹ß»ıÇÕ´Ï´Ù.
		- data tree °¡ ÀÌ¹Ì isolate »óÅÂÀÌ°Å³ª deisolate ¿¡ ½ÇÆĞÇÏ¸é OnDeisolateDataFailed ÀÌº¥Æ®°¡ ¹ß»ıÇÕ´Ï´Ù.

		\param rootUUID deisolateÇÏ°íÀÚ ÇÏ´Â data treeÀÇ root UUIDÀÔ´Ï´Ù.
		\param rootTableName deisolateÇÏ°íÀÚ ÇÏ´Â data treeÀÇ rootÅ×ÀÌºíÀÇ ÀÌ¸§ÀÔ´Ï´Ù.
		\param [out] outSessionGuid session ½Äº°ÀÚÀÔ´Ï´Ù.

		\~english
		<a target="_blank" href="http://guide.nettention.com/cpp_en#dbc2_isolate_overview" >DB directly has access to data that DB cache deals with </a> function.
		Request for deisolating data tree that has been isolated.

		If deisolating request is successful, DB cache will be ready to be loaded & saved.

		- If data tree is successfully deisolated from DB cache, OnDeisolateDataSuccess event will occur.
		- If data tree has been already isolated or deisolating fails, OnDeisolateDataFailed event will occur.

		\param rootUUID It is root UUID of data tree that is going to be deisolated.
		\param rootTableName It is root table name of data tree that is going to be deisolated.
		\param [out] outSessionGuid session identifier.

		\~chinese
		<a target="_blank" href="http://guide.nettention.com/cpp_zh#dbc2_isolate_overview" >DBòÁïÈ??DB cacheğÃíÂîÜ?Ëß</a> ÍíÒö¡£
		?Ï´?ì«?ú¼isolate îÜ data tree ?ú¼ deisolate¡£

		deisolate ?Ï´à÷Ííı¨ DB cache Ê¦ì¤?ú¼ load & save ¡£

		- î¤DB cache ñé data tree à÷Íí?ú¼Öõ deisolate ???ßæ OnDeisolateDataSuccess ŞÀËì¡£
		- åıÍıdata treeì«?éÍ isolate ??ûä deisolate ã÷????ßæ OnDeisolateDataFailed ŞÀËì¡£

		\param rootUUID é©?ú¼deisolateîÜ data treeîÜ root UUID¡£
		\param rootTableName é©?ú¼deisolateîÜ data treeîÜ root TableÙ£¡£
		\param [out] outSessionGuid session ??íº¡£

		\~japanese
		<a target="_blank" href="http://guide.nettention.com/cpp_jp#dbc2_isolate_overview" >DB cacheª¬ğÃªë«Ç?«¿ªòDBª¬òÁïÈ«¢«¯«»«¹</a>Ñ¦ÒöªÇª¹¡£
		Isolateª·ª¿data treeªòdeisolateª¹ªëªèª¦ªËé©ôëª·ªŞª¹¡£

		DeisolateªÎé©ôëª¬à÷Ííª¹ªëªÈî¢ªÓDB cacheª¬load & saveªÇª­ªë?÷¾ªËªÊªêªŞª¹¡£

		- DB cacheªÇdata treeª¬à÷ÍíîÜªËdeisolateªµªìªëªÈOnDeisolateDataSuccess«¤«Ù«ó«Èª¬?ßæª·ªŞª¹¡£
		- data treeª¬?ªËisolateªÎ?÷¾ªÇª¢ªÃª¿ªêdeisolateªËã÷ø¨ª¹ªëªÈOnDeisolateDataFailed «¤«Ù«ó«Èª¬?ßæª·ªŞª¹¡£

		\param rootUUID deisolateª·ªèª¦ªÈª¹ªë data treeªÎroot UUIDªÇª¹¡£
		\param rootTableName deisolateª·ªèª¦ªÈª¹ªë data treeªÎroot«Æ?«Ö«ëªÎÙ£îñªÇª¹¡£
		\param [out] outSessionGuid sessionãÛÜ¬ä«ªÇª¹¡£
		*/
		virtual bool RequestDeisolateData(Guid rootUUID, String filterText, Guid &outSessionGuid) = 0;

		/**
		\~korean
		µ¥ÀÌÅÍÀÇ ÃÖ½Å »óÅÂ °ªÀ» ¾ò´Â´Ù.
		\param sessionGuid RequestExclusiveLoadData ³ª RequestExclusiveLoadNewData ¿¡¼­ ¹ŞÀº session guid
		\return ¾òÀº µ¥ÀÌÅÍ °´Ã¼. »çº»ÀÌ¹Ç·Î ¾òÀº °´Ã¼ÀÇ °ªÀ» º¯ÇüÇØµµ ½ÇÁ¦ DB¿¡ ¾÷µ¥ÀÌÆ®µÇÁö ¸øÇÑ´Ù.
		½ÇÁ¦ DB¿¡ ¾÷µ¥ÀÌÆ®ÇÏ·Á¸é º¯°æÇÑ ÈÄ °´Ã¼¸¦ UpdateData ÇÔ¼ö¸¦ ÅëÇØ ¼­¹ö¿¡ Àü¼ÛÇØ¾ß ÇÑ´Ù.

		\~english
		Gets the latest status value of data
		\param sessionGuid Session guid obtained from RequestExclusiveLoadData or RequestExclusiveLoadNewData
		\return Obtained object It does not update to actual DB because it is a copy
		If you want to update it to actual DB, you need send it to server through UpdateData function.

		\~chinese
		?Ôğ?ËßîÜõÌãæ???¡£
		?\param sessionGuid RequestExclusiveLoadDataûäRequestExclusiveLoadNewDataïÈâ¥îÜsession guid¡£
		\return ?ÔğîÜ?ËßîÜ?ßÚ¡£ì×?ãÀÜùÜâ£¬ËÇ??ÔğîÜ?ßÚ?£¬å¥Üô?ß¾?Óğ??DB¡£
		ßÌß¾?Óğ??DBîÜ?£¬é©÷êáóËÇı¨îÜ?ßÚ÷×?UpdateDataùŞ??áêîÜÜ×?Ğï¡£

		\~japanese
		«Ç?«¿ªÎõÌãæ?÷¾ö·ªòÔğªŞª¹¡£
		\param sessionGuid RequestExclusiveLoadDataª«RequestExclusiveLoadNewDataªèªêáôª±ª¿session guid
		\return Ôğª¿«Ç?«¿«ª«Ö«¸«§«¯«È¡£«³«Ô?ªÊªÎªÇÔğª¿«ª«Ö«¸«§«¯«ÈªÎö·ªò?ÌÚª·ªÆªâ?ğ·DBªË«¢«Ã«×«Ç?«ÈªµªìªŞª»ªó¡£
		?ğ·DBªË«¢«Ã«×«Ç?«Èª¹ªëª¿ªáªËªÏ?ÌÚª·ª¿ı­¡¢«ª«Ö«¸«§«¯«ÈªòUpdateData??ªò÷×ª¸«µ?«Ğ?ªË?áêª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£

		\~
		*/
		virtual CLoadedData2Ptr GetClonedLoadedDataBySessionGuid(Guid sessionGuid) = 0;

		/**
		\~korean
		À§ \ref GetClonedLoadedDataBySessionGuid ¿Í °°Àº ÇÔ¼öÀÌ³ª, rootUUID·Î Ã£´Â´Ù.
		ÀÚ¼¼ÇÑ ¼³¸íÀº \ref GetClonedLoadedDataBySessionGuid ¸¦ Âü°í.
		\return ¾òÀº µ¥ÀÌÅÍ °´Ã¼. »çº»ÀÌ¹Ç·Î ¾òÀº °´Ã¼ÀÇ °ªÀ» º¯ÇüÇØµµ ½ÇÁ¦ DB¿¡ ¾÷µ¥ÀÌÆ®µÇÁö ¸øÇÑ´Ù.
		½ÇÁ¦ DB¿¡ ¾÷µ¥ÀÌÆ®ÇÏ·Á¸é º¯°æÇÑ ÈÄ °´Ã¼¸¦ UpdateData ÇÔ¼ö¸¦ ÅëÇØ ¼­¹ö¿¡ Àü¼ÛÇØ¾ß ÇÑ´Ù.

		\~english TODO:translate needed.
		It¡¯s the same function as the above \ref GetClonedLoadedDataBySessionGuid, but it is searched with rootUUID. 
		Check out \ref GetClonedLoadedDataBySessionGuid. For a detailed explanation, refer to \ref GetClonedLoadedDataBySessionGuid
		\Obtained data object. Since this is a copy, it is not updated in the real DB even though you transform the value of the obtained object. 
		If you want to update it in the actual DB, you have to transmit the object through the UpdateData function. 

		\~chinese
		?ß¾ØüîÜ\ref GetClonedLoadedDataBySessionGuid%ìé?îÜùŞ?£¬éÄrootUUID??¡£
		???Ù¥??ÍÅ\ref GetClonedLoadedDataBySessionGuid%¡£
		\return ?ÔğîÜ?Ëß?ßÚ¡£ì×?ãÀÜùÜâ£¬ËÇ??ÔğîÜ?ßÚ?£¬å¥Üô?ß¾?Óğ??DB¡£
		ßÌß¾?Óğ??DBîÜ?£¬é©÷êáóËÇı¨îÜ?ßÚ÷×?UpdateDataùŞ??áêîÜÜ×?Ğï¡£

		\~japanese
		ß¾ÑÀªÎ\ref GetClonedLoadedDataBySessionGuidªÈÔÒª¸??ªÇª¹ª¬¡¢rootUUIDªÇ÷®ª·ªŞª¹¡£
		ßÙª·ª¯ªÏ¡¢\ref GetClonedLoadedDataBySessionGuid ªò?ÍÅ¡£
		\return Ôğª¿«Ç?«¿«ª«Ö«¸«§«¯«È¡£«³«Ô?ªÊªÎªÇÔğª¿«ª«Ö«¸«§«¯«ÈªÎö·ªò?ÌÚª·ªÆªâ?ğ·DBªË«¢«Ã«×«Ç?«ÈªµªìªŞª»ªó¡£
		?ğ·DBªË«¢«Ã«×«Ç?«Èª¹ªëª¿ªáªËªÏ¡¢?ÌÚª·ª¿ı­«ª«Ö«¸«§«¯«ÈªòUpdateData??ªò÷×ª¸«µ?«Ğ?ªË?áêª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£

		\~
		*/
		virtual CLoadedData2Ptr GetClonedLoadedDataByUUID(Guid rootUUID) = 0;

		/**
		\~korean
		ÀÌ Å¬¶óÀÌ¾ğÆ®ÀÇ HostID¸¦ ¾ò´Â´Ù.

		\~english
		Obtain HostID of this client

		\~chinese
		?Ôğó®èÌÊ«îÜHost ID¡£

		\~japanese
		ª³ªÎ«¯«é«¤«¢«ó«ÈªÎHostIDªòÔğªŞª¹¡£
		\~
		*/
		virtual HostID GetLocalHostID() = 0;

		/**
		\~korean
		ÀÌ DB cache client2°¡ DB cache server2¿¡ ·Î±×¿Â(ÀÎÁõ)ÀÌ ¿Ï·áµÈ »óÅÂÀÎÁö ¿©ºÎ¸¦ ±¸ÇÑ´Ù.
		\return ·Î±×ÀÎ µÇ¾î ÀÖÀ¸¸é true.

		\~english
		Find out DB cache client2 has got authentication from DB cache server2 whether or not.

		\~chinese
		Ï´ó®DB cache client2ãÀÜúãÀÔô?£¨??£©DB cache server2èÇ???îÜ?Üú¡£

		\~japanese
		ª³ªÎDB cache client2ª¬DB cache server2ªË«í«°«ª«ó(ìã?)ª¬èÇÖõªµªìª¿?÷¾ªÊªÎª«ªÉª¦ª«ªòÏ´ªáªŞª¹¡£
		\return «í«°«¤«óªµªìªÆª¤ªìªĞtrue

		\~
		*/
		virtual bool IsLoggedOn() = 0;

	};
	/**  @} */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
#endif