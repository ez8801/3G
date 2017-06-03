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

#include "Message.h"
#include "HlaDef.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	template<typename type>
	class CStaticBehaviorMember
	{
		type m_value_INTERNAL;
	public:
		inline void Set(type value)
		{
			m_value_INTERNAL = value;
		}
		inline type Get()
		{
			return m_value_INTERNAL;
		}

		// does nothing, but it is needed because it is called by SWD compiler output.
		// \return always false
		inline bool GatherTheChangeToMessage(HlaFieldGroupID memberID, CMessage &outputMessage, Protocol &outProtocol)
		{
			outProtocol = Protocol_Undefined;
			return false;
		}

		inline void ClearTheChange()
		{
		}

		inline bool IsChanged()
		{
			return false;
		}

		// does nothing, but it is needed because it is called by SWD compiler output.
		inline void GatherAllToMessage(HlaFieldGroupID memberID, CMessage &outputMessage)
		{
		}
	};

	/** 
	\~korean
	Conditional behavior member¸¦ À§ÇÑ ÀÓ½Ã Class
	
	\~english
	a template class for conditional behavior member
	
	\~chinese
	?ÖõConditional behavior memberîÜ??Class¡£
	
	\~japanese
	Conditional behavior memberªÎª¿ªáªÎ×üãÁ«¯«é«¹
	\~
	*/
	template<typename type>
	class CConditionalBehaviorMember
	{
		type m_value_INTERNAL;
		bool m_valueChanged_INTERNAL;
	public:
		inline CConditionalBehaviorMember()
		{
			m_valueChanged_INTERNAL = false;
		}
		inline void Set(type value)
		{
			if (value != m_value_INTERNAL)
			{
				// A variable whose 'changed'
				// is true will be multicasted soon.
				m_valueChanged_INTERNAL = true;
				m_value_INTERNAL = value;
			}
		}
		inline type Get()
		{
			return m_value_INTERNAL;
		}

		// append the value to the message if it has been changed.
		// \return true if the value is written to the message.
		inline bool GatherTheChangeToMessage(HlaFieldGroupID memberID, CMessage &outputMessage, Protocol &outProtocol)
		{
			outProtocol = Protocol_Undefined;
			if (m_valueChanged_INTERNAL)
			{
				outputMessage.Write(memberID);
				outputMessage<<m_value_INTERNAL;
				outProtocol = Protocol_ReliableSend;

				return true;
			}

			return false;
		}

		inline void ClearTheChange()
		{
			m_valueChanged_INTERNAL = false;
		}

		inline bool IsChanged()
		{
			return m_valueChanged_INTERNAL;
		};

		// does nothing, but it is needed because it is called by SWD compiler output.
		inline void GatherAllToMessage(HlaFieldGroupID memberID, CMessage &outputMessage)
		{
			outputMessage.Write(memberID);
			outputMessage<<m_value_INTERNAL;
		}
	};

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif