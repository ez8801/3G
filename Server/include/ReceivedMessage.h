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

#include "Message.h"
#include "AddrPort.h"
#include "ProcHeap.h"
#include "CompressEnum.h"
#include "ClassBehavior.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/* 
	\~korean
	¼ö½ÅµÈ ¸Þ½ÃÁö. ³»ºÎ ¿ëµµ´Ù. 

	\~english
	Received messge. Internal purpose.

	\~chinese
	â¥ÓðîÜãáãÓãÀ?Ý»éÄ¡£

	\~japanese
	áôãáª·ª¿«á«Ã«»?«¸¡£?Ý»éÄÔ²ªÇª¹¡£
	\~
	*/
	class CReceivedMessage
	{
		// º¹»ç ºñ¿ëÀÌ Å©´Ù. CFinalUserWorkItemÀ» ¾²´øÁö ÇØ¼­ º¹»ç ¾ÈµÇ°Ô ÇÑ´Ù.
		NO_COPYABLE(CReceivedMessage)

	public:
		// °ú°Å ¹öÀü¿¡¼­ fast heapÀ» ¿ÜºÎ ÂüÁ¶ÇÏ±â ¶§¹®¿¡ °´Ã¼ ÆÄ±«½Ã main °´Ã¼¸¦ Àá±×°í ±× ¾ÈÀÇ fast heap access¸¦ ÇØ¾ß ÇßÁö¸¸
		// ÀÌÁ¦´Â ±×·± ±â´ÉÀÌ »ç¶óÁö°í Àü¿ª obj-pool ¹æ½ÄÀ» ¾²±â ¶§¹®¿¡ unsafe°¡ ¾Æ´Ô.
		// ÁÖÀÇ: Final user work itemÀÎ °æ¿ì ÀÌ°ÍÀº RMI IDºÎÅÍ ½ÃÀÛÇÏ´Â ³»¿ëÀÌ´Ù. Áï MessageType_XXX°¡ Á¦°ÅµÈ »óÅÂ´Ù.
		CMessage m_unsafeMessage;

		// ¼Û½ÅÀÚ
		HostID m_remoteHostID;

		// UDP ¼ö½ÅÀÎ °æ¿ì¿¡ À¯È¿ÇÑ ¸â¹ö º¯¼ö
		AddrPort m_remoteAddr_onlyUdp;

		// ¸±·¹ÀÌ·Î ¿Ô´Ï?
		bool m_relayed;

		// ACR
		int m_messageID; // m_hasMessgeID=trueÀÏ¶§¸¸ À¯È¿ 
		bool m_hasMessageID;

		//double m_actionTime;

		EncryptMode m_encryptMode;
		CompressMode m_compressMode;

		// ÃøÁ¤ °á°ú È£Ãâ È½¼ö°¡ ¸Å¿ì ¸¹Àº ¸Þ¼­µåÀÎÁö¶ó inlineÀ¸·Î µÐ´Ù.
		inline CReceivedMessage()
		{
			Clear();
		}

		inline CMessage &GetWriteOnlyMessage()
		{
			return m_unsafeMessage;
		}
		inline CMessage &GetReadOnlyMessage()
		{
			return m_unsafeMessage;
		}
		inline AddrPort GetRemoteAddr()
		{
			return m_remoteAddr_onlyUdp;
		}
		inline HostID GetRemoteHostID()
		{
			return m_remoteHostID;
		}
		inline bool IsRelayed()
		{
			return m_relayed;
		}

		// PIDL compiler output¿¡¼­ È£ÃâÇÏ¹Ç·Î, getter method¸¦ ÀÇµµ·Î µÒ.
		inline EncryptMode GetEncryptMode()
		{
			return m_encryptMode;
		}

		// PIDL compiler output¿¡¼­ È£ÃâÇÏ¹Ç·Î, getter method¸¦ ÀÇµµ·Î µÒ.
		inline CompressMode GetCompressMode()
		{
			return m_compressMode;
		}

		// called by BiasManagedPointer.
		inline void Clear()
		{
			m_relayed = false;
			m_remoteHostID = HostID_None;
			m_remoteAddr_onlyUdp = AddrPort::Unassigned;

			m_messageID = 0;
			m_hasMessageID = false;

			m_encryptMode = EM_None;
			m_compressMode = CM_None;

			m_unsafeMessage.Clear();
		}

	};


#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
