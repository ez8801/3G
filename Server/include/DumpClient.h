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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

    
#if defined(_WIN32)    
	/** \addtogroup minidump_group
	*  @{
	*/

	/** 
	\~korean
	CDumpClient °¡ ¿ä±¸ÇÏ´Â delegate ÀÎÅÍÆäÀÌ½º. CDumpClient ¸¦ »ý¼ºÇÒ ¶§ ÀÎÀÚ·Î ÇÊ¿äÇÏ´Ù.

	\~english
	Delegate interface that is requested by CDumpClient. It is needed as as index when creating CDumpClient.

	\~chinese
	CDumpClient é©Ï´îÜdelegate?ÖÇ¡£ßæà÷ CDumpClient%îÜ?ý¦âÍé©îÜì×í­¡£

	\~japanese
	CDumpClientª¬é©Ï´ª¹ªëdelegate«¤«ó«¿?«Õ«§?«¹¡£CDumpClientªòßæà÷ª¹ªëãÁªËì×í­ªÈª·ªÆù±é©ªÇª¹¡£
	\~
	*/
	class IDumpClientDelegate
	{
	public:
		virtual ~IDumpClientDelegate() {}

		/** 
		\~korean
		CDumpClient °¡ ´ýÇÁ ÆÄÀÏÀ» ¼­¹ö·Î º¸³»´Â µ¿¾È ÀÏÁ¤ ½Ã°£¸¶´Ù È£ÃâµÈ´Ù. À¯Àú¿¡ ÀÇÇØ
		º¸³»±â¸¦ Ãë¼ÒÇÒ °æ¿ì ÀÌ ÇÔ¼ö´Â true¸¦ ¸®ÅÏÇÏ¸é µÈ´Ù.

		\~english
		Called periodically while CDumpClient sends dump file to server. This function must return true in order to let user cancel the sending process.

		\~chinese
		CDumpClien ÷ê??ÙþËì?áêÓðÜ×?ÐïîÜÑ¢?£¬ØßìéïÒ??Ô´?ù¬û¼Ð£¡£ù¬éÄ?ö¢á¼?áêîÜ?ý¦£¬ó®ùÞ?Ú÷üÞtrue?Ê¦¡£

		\~japanese
		CDumpClientª¬«À«ó«×«Õ«¡«¤«ëªò«µ?«Ð?ªËáêªëÊàªËá¶ïÒãÁÊàª´ªÈªËû¼ªÓõóªµªìªÞª¹¡£«æ?«¶?ªËªèªÃªÆáêãáªò«­«ã«ó«»«ëª¹ªëíÞùê¡¢ª³ªÎ??ªÏtrueªò«ê«¿?«óª¹ªìªÐÕÞª¤ªÇª¹¡£
		\~
		*/
		virtual bool MustStopNow() = 0;

		/** 
		\~korean
		¼Û½Å Ã³¸®Áß ¿¹¿Ü°¡ ¹ß»ýÇÒ °æ¿ì ÀÌ ¸Þ¼­µå°¡ ÄÝ¹éµÈ´Ù.
		\param e ¿¹¿ÜÁ¤º¸ Exception::what() À» ÅëÇÏ¿© ¹®Á¦¿¡ °ü·ÃµÈ String ¹ÞÀ¸½Ç ¼ö ÀÖ½À´Ï´Ù.

		\~english 
		This method is called back when an exception occurs during processing transmission. 
		\param e      You can get the string related to the problem through the exception information Exception::what().


		\~chinese
		ÙþËì?áê?×âñé?ßæÖÇèâîÜ?ý¦üÞ?ó®Û°Ûö¡£
		\param e ÷×?ÖÇèâãáãÓ Exception::what()%Ê¦ì¤?Ôð??ßÓ?îÜString¡£

		\~japanese
		áêãá?×âñéªËÖÇèâª¬?ßæª¹ªëíÞùê¡¢ª³ªÎ«á«½«Ã«Éª¬«³?«ë«Ð«Ã«¯ªµªìªÞª¹¡£
		\param e ÖÇèâï×ÜÃ Exception::what() ªò÷×ª¸Ùýð¹ªË?Ö§ªµªìª¿Stringªòáôª±ªéªìªÞª¹¡£
		\~
		*/
		virtual void OnException(const Exception &e) = 0;
		
		/** 
		\~korean
		¼Û½ÅÀÌ ¿Ï·áµÇ¸é ÀÌ°ÍÀÌ È£ÃâµÈ´Ù. ¼Û½Å ´ëÈ­ »óÀÚ¸¦ ÀÌ¶§ ´ÝÀ¸¸é µÈ´Ù.

		\~english
		This will be called once sending is completed. Sending chat box can be closed at this point. 

		\~chinese
		?áêèÇ?îÜ????ù¬û¼Ð£¡£??ý¦???áê????Ê¦¡£

		\~japanese
		áêãáª¬èÇÖõª·ª¿ªéª³ªìª¬û¼ªÓõóªµªìªÞª¹¡£áêãá«À«¤«¢«í«°«Ü«Ã«¯«¹ªòª³ªÎãÁªËøÍª¸ªìªÐÕÞª¤ªÇª¹¡£
		\~
		*/
		virtual void OnComplete() = 0;
	};

	/** 
	\~korean
	´ýÇÁ Å¬¶óÀÌ¾ðÆ®
	- CDumpServer ·ÎÀÇ ¿¬°áÀ» ÇÑ ÈÄ ¼­¹ö·Î DMP ÆÄÀÏÀ» º¸³»´Â ¿ªÇÒÀ» ÇÑ´Ù.
	- HTTP ¹æ½Ä¿¡ ºñÇØ È¿À²ÀûÀÌ¸ç ´ëºÎºÐÀÇ À¥ È£½ºÆÃ ¼­ºñ½º°¡ ÆÄÀÏ ±â·Ï Çã°¡¸¦ ²¨³õ±â ¶§¹®¿¡ Â÷¶ó¸® ÀÚÃ¼ ¼­¹ö ±¸ÃàÀÌ
	ºÒ°¡ÇÇÇÏ´Ù´Â Á¡À» °¨¾ÈÇÏ¸é ÀÌ·¸°Ô ÀÚÃ¼ ÇÁ·ÎÅäÄÝÀÌ ´õ Çö½ÇÀûÀÌ´Ù.

	ÀÏ¹ÝÀû ¿ëµµ
	- »ý¼ºÀº Create()·Î ÇÑ´Ù.
	- ÀÌ °´Ã¼¸¦ »ý¼ºÇÑ ÈÄ Start()·Î ¼Û½ÅÀ» ÇÑ´Ù.
	- ¸Å ÀÏÁ¤ ½Ã°£(´ë·« 1ÃÊ¿¡ 10È¸ ÀÌ»ó) FrameMove¸¦ È£ÃâÇÑ´Ù.
	- ¼Û½ÅÁß Áßµµ »óÈ²Àº GetState(),GetSendProgress(),GetSendTotal()·Î ¾òÀ» ¼ö ÀÖ´Ù. ÀÌ°ÍÀ» ´ëÈ­ »óÀÚ¿¡ Ç¥½ÃÇÏ¸é µÈ´Ù.
	- OnException, OnComplete°¡ ¿Ã ¶§±îÁö ±â´Ù¸°´Ù.

	\~english
	Dump client
	- Manages sending DMP files to server after connected to CDumpServer
	- Inefficeint compared to HTTP and this kind of custom protocol is more realistic since most of web hosting services turn off file record permission pushing publishers to setup own servers.

	General usage
	- Use Create() to create.
	- After creating the object the use Start() to send.
	- Calls FrameMove periodically (approx. 10 or more times per second)
	- The sending status during sending process can be acquired by using GetState(), GetSendProgress() and GetSendTotal(). And those can be displayed in chat box.
	- ait until OnException and OnComplete arrive.

	\~chinese
	??èÌÊ«
	- ? CDumpServer%îÜ?ïÈý¨£¬ÑÃó·èÙÜ×?Ðï?áêDMPÙþËìîÜíÂéÄ¡£
	- ÝïHTTPÛ°ãÒêóüùáã£¬ì×?ÓÞÝ»ÝÂweb hostingÜ×???ÙþËì???Ê¦£¬ÍÅ?ÜâãóÜ×?Ðï?ËïãÀÜôÊ¦ù­Øó£¬??í»ãóîÜprotocolãÀÌÚ??îÜ¡£

	ìéÚõîÜéÄÔ²
	- ë¦Create()ßæà÷¡£
	- ßæà÷ó®?ßÚì¤ý¨éÄStart()?áê¡£
	- ØßìéïÒ??£¨ÓÞ?Øßõ©10üÞì¤ß¾£©û¼Ð£FrameMove¡£
	- ÙþËì?áêîÜ??ë¦GetState(),GetSendProgress(),GetSendTotal()?Ôð¡£÷ê???ãÆî¤????Ê¦¡£
	- ÔõÓðOnException, OnCompleteÓð?¡£

	\~japanese
	«À«ó«×«¯«é«¤«¢«ó«È
	- CDumpServerªØªÎª»ªÆéÔðéªòú¼ªÃª¿ý­¡¢«µ?«Ð?ªËDMP«Õ«¡«¤«ëªòáêªëæµùÜªòª·ªÞª¹¡£
	- HTTPÛ°ãÒªËÝïªÙ?áãîÜªÇ¡¢ªÛªÈªóªÉªÎ«¦«§«Ö«Û«¹«Æ«£«ó«°«µ?«Ó«¹ª¬«Õ«¡«¤«ëÑÀ?úÉÊ¦ªò«ª«Õª·ªÆöÇª¯ª¿ªá¡¢ª«ª¨ªÃªÆí»?«µ?«Ð?Ï°õéª¬ªäªàªòÔðªÊª¤ªÈª¤ª¦ª³ªÈªòÊüªßª¿ªé¡¢ª³ªÎªèª¦ªËí»?«×«í«È«³«ëª¬ªâªÃªÈúÞ?îÜªÇª¹¡£

	ìéÚõîÜªÊéÄÔ²
	- ßæà÷ªÏCreate()ªÈª¹ªë¡£
	- ª³ªÎ«ª«Ö«¸«§«¯«Èªòßæà÷ª·ª¿ý­¡¢Start()ªËáêãáª·ªÞª¹¡£
	- á¶ïÒãÁÊàª´ªÈªË(å³1õ©ªË10üÞì¤ß¾)FrameMoveªòû¼ªÓõóª·ªÞª¹¡£
	- áêãáñéªËñéÔ²?üÏªÏ¡¢GetState(),GetSendProgress(),GetSendTotal()ª«ªéÔðªéªìªÞª¹¡£ª³ªìªò«À«¤«¢«í«°«Ü«Ã«¯«¹ªËøúãÆª¹ªìªÐÕÞª¤ªÇª¹¡£
	- OnException, OnCompleteª¬?ªëªÞªÇÓâªÁªÞª¹¡£
	\~
	*/
	class CDumpClient
	{
	public:
		enum State { Connecting, Sending, Closing, Stopped};

		virtual ~CDumpClient() {};

		/** 
		\~korean
		´ýÇÁ ¼­¹ö·Î ´ýÇÁ ÆÄÀÏÀ» º¸³»±â ½ÃÀÛÇÑ´Ù.
		\param serverAddr ¼­¹ö ÁÖ¼Ò
		\param serverPort ¼­¹ö Æ÷Æ®
		\param filePath ÆÄÀÏÀÇ °æ·Î

		\~english TODO:translate needed.
		Start sending dump file to dump server.
		\param serverAddr
		\param serverPort
		\param filePath

		\~chinese
		èÙ??Ü×?Ðï?ã·?áê??ÙþËì¡£
		\param serverAddr Ü×?Ðïò¢ò£¡£
		\param serverPort Ü×?ÐïÓ®Ï¢¡£
		\param filePath ÙþËìîÜÖØ?¡£

		\~japanese
		«À«ó«×«µ?«Ð?ªÇ«À«ó«×«Õ«¡«¤«ëªòáêªêã·ªáªÞª¹¡£
		\param serverAddr «µ?«Ð?«¢«É«ì«¹
		\param serverPort «µ?«Ð?«Ý?«È
		\param filePath «Õ«¡«¤«ëªÎ?ÖØ
		\~
		*/
		virtual void Start(String serverAddr, uint16_t serverPort, String filePath) = 0;

		/** 
		\~korean
		ÀÏÁ¤ ½Ã°£¸¶´Ù ÀÌ ¸Þ¼­µå¸¦ È£ÃâÇØÁà¾ß ¼Û½Å °úÁ¤ÀÌ ÁøÇàµÉ ¼ö ÀÖ´Ù.

		\~english
		Sending process is sustained by calling this method periodically.

		\~chinese
		ØßìéïÒ??û¼Ð£ó®Û°Ûö£¬?áê?ïïî¦Òö?ú¼¡£

		\~japanese
		á¶ïÒãÁÊàª´ªÈªËª³ªÎ«á«½«Ã«Éªòû¼ªÓõóª·ªÆª«ªéáêãáÎ¦ïïª¬òäú¼ªµªìªëª³ªÈª¬ªÇª­ªÞª¹¡£
		\~
		*/
		virtual void FrameMove() = 0;

		/** 
		\~korean
		ÇöÀç ´ýÇÁ ÆÄÀÏ ¼Û½Å °æ°ú¸¦ ¾ò´Â´Ù.

		\~english
		Gets current dump file sending status

		\~chinese
		?Ôð?î¤îÜ??ÙþËì?áê?Íý¡£

		\~japanese
		úÞî¤«À«ó«×«Õ«¡«¤«ëªÎáêãáÌ¿ÍýªòÔðªÞª¹¡£
		\~
		*/
		virtual State GetState() = 0;

		/** 
		\~korean
		ÇöÀç ´ýÇÁ ÆÄÀÏ ¼Û½ÅÀÌ ¸î ¹ÙÀÌÆ®°¡ ³¡³­´ÂÁö ¾ò´Â´Ù.

		\~english
		Gets how many bytes of dump file has been completed

		\~chinese
		?Ôð?î¤??ÙþËì?áê?áÖÒýá´í®?¡£

		\~japanese
		úÞî¤«À«ó«×«Õ«¡«¤«ëªÎáêãáª¬ù¼«Ð«¤«ÈèÇÖõª·ªÆª¤ªëª«ªòÔðªÞª¹¡£
		\~
		*/
		virtual int GetSendProgress() = 0;

		/** 
		\~korean
		º¸³»¾ß ÇÏ´Â ÃÑ ¼Û½Å µ¥ÀÌÅÍ¸¦ ¾ò´Â´Ù.

		\~english
		Gets total sending data to be sent

		\~chinese
		?Ôðé©?áêîÜ??áê?Ëß¡£

		\~japanese
		áêªëªÙª­?áêãá«Ç?«¿ªòÔðªÞª¹¡£
		\~
		*/
		virtual int GetSendTotal() = 0;

		/** 
		\~korean
		CDumpClient °´Ã¼¸¦ »ý¼ºÇÑ´Ù.
		\param dg IDumpClientDelegate ÀÇ Æ÷ÀÎÅÍ

		\~english TODO:translate needed.
		Generate CDumpClient object
		\param dg Pointer of IDumpClientDelegate

		\~chinese
		CDumpClient ßæà÷?ßÚ
		\param dg IDumpClientDelegateîÜpointer¡£

		\~japanese
		CDumpClient «ª«Ö«¸«§«¯«Èªòßæà÷ª·ªÞª¹¡£
		\param dg IDumpClientDelegate ªÎ«Ý«¤«ó«¿?
		\~
		*/
		PROUD_API static CDumpClient* Create(IDumpClientDelegate* dg);

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
