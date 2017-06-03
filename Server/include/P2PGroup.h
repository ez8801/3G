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
#include "HostIDArray.h"
#include "Ptr.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup net_group
	*  @{
	*/

	class CP2PGroup;
	typedef RefCount<CP2PGroup> CP2PGroupPtr;

	/** 
	\~korean
	P2P ±×·ì Á¤º¸ ±¸Á¶Ã¼ 

	\~english
	Information construct of P2P group

	\~chinese
	P2P?ãáãÓ?ğã?

	\~japanese
	P2P«°«ë?«×ï×ÜÃªÎÏ°ğã?
	\~
	*/
	class CP2PGroup
	{
	public:
		/** 
		\~korean
		±×·ì ID 

		\~english
		Group ID 

		\~chinese
		?ID

		\~japanese
		«°«ë?«×ID
		\~
		*/
		HostID m_groupHostID;
		/** 
		\~korean
		±×·ì¿¡ ¼Ò¼ÓµÈ client peerµéÀÇ HostID 

		\~english
		HostID of client peer that is possessed by group

		\~chinese
		á¶?éÍ?îÜclient peerîÜHost ID¡£

		\~japanese
		«°«ë?«×ªËá¶?ªµªìª¿client peerªÊªÉªÎHostID
		\~
		*/
		HostIDArray m_members;

		PROUD_API CP2PGroup();

#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// ÀÌ Å¬·¡½º´Â ProudNet DLL °æ¿ì¸¦ À§ÇØ Ä¿½ºÅÒ ÇÒ´çÀÚ¸¦ ¾²µÇ fast heapÀ» ¾²Áö ¾Ê´Â´Ù.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif
	};
	/** 
	\~korean
	P2P ±×·ì ¸®½ºÆ®
	- º¸´Ù ÀÚ¼¼ÇÑ »ç¿ë¹ıÀº º£ÀÌ½º Å¬·¡½º¸¦ Âü°íÇÒ °Í. 

	\~english
	 P2P group list
	- Please refer base class for more details.

	\~chinese
	P2P?list¡£
	- ÌÚ??îÜŞÅéÄÛ°Ûö??ÍÅbase?¡£

	\~japanese
	P2P«°«ë?«×«ê«¹«È
	- ªèªêßÙª·ª¤ŞÅéÄÛ°ÛöªÏ«Ù?«¹«¯«é«¹ªò?ğÎª¹ªëª³ªÈ¡£
	\~
	*/
	class CP2PGroups : public CFastMap<HostID, CP2PGroupPtr>
	{
	public:
#ifndef SWIG
#ifndef __MARMALADE__
#pragma push_macro("new")
#undef new
		// ÀÌ Å¬·¡½º´Â ProudNet DLL °æ¿ì¸¦ À§ÇØ Ä¿½ºÅÒ ÇÒ´çÀÚ¸¦ ¾²µÇ fast heapÀ» ¾²Áö ¾Ê´Â´Ù.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif //__MARMALADE__
#endif //SWIG 
	};

	/**
	\~korean
	\brief <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P ±×·ì</a> ÇÑ °³ÀÇ »ç¿ëÀÚ ÁöÁ¤ ¼³Á¤ÀÔ´Ï´Ù. 
	ÇÊ¿äÇÑ °æ¿ì°¡ ¾Æ´Ñ ÀÌ»ó ÀÌ °´Ã¼¸¦ »ç¿ëÇÏ½Ç ÇÊ¿ä´Â ¾ø½À´Ï´Ù.

	\~english 
	Additional settings for a P2P group. 
	Unless necessary, you don¡¯t have to use this object. 

	\~chinese
	\brief <a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%ìé?éÄ?ò¦ïÒ?öÇ¡£
        åıÍıÜôãÀù±é©îÜï×?£¬ÜôâÍé©ŞÅéÄó®?ßÚ¡£

	\~japanese
	\brief \ref p2p_group  1ËÁªÎ«æ?«¶?ò¦ïÒàâïÒªÇª¹¡£ 
	ù±é©ªÊíŞùêªÇªÏªÊª¤ì¤ß¾¡¢ª³ªÎ«ª«Ö«¸«§«¯«ÈªòŞÅª¦ù±é©ªÏª¢ªêªŞª»ªó¡£
	\~
	*/
	class CP2PGroupOption
	{
	public:
		/**
		\~korean
		trueÀÌ¸é ±×·ì ¸â¹ö°£ Direct P2P Åë½ÅÀ» Á¦°øÇÕ´Ï´Ù. ±âº»°ªÀº trueÀÔ´Ï´Ù.
		±×·ìÀ» ¸ÎµÇ ¸â¹ö°£ P2P Åë½ÅÀ» Â÷´ÜÇÏ°íÀÚ ÇÒ ¶§ ÀÌ °ªÀ» false·Î ¼³Á¤ÇÏ¸é µË´Ï´Ù. 
		
		±×·ì ³» ¸â¹ö°£ ÀÌ¹Ì Å¸ ±×·ì Á¾¼Ó¿¡ ÀÇÇØ ¼­·Î Direct P2P¸¦ ÀÌ¹Ì ÇÏ°í ÀÖ´Â »óÅÂÀÎ °æ¿ì, ÀÌ °ªÀ» false·Î ¼³Á¤ÇÏ´Â °ÍÀÌ ±×µéÀÇ Direct P2P¸¦ Â÷´ÜÇÏÁö´Â ¾Ê½À´Ï´Ù.

		\~english TODO:translate needed.
		If true, this provides direct P2P communication among group members. The default value is true. 
		You can set this value as false when you form a group but want to block P2P communication among members. 

		When direct P2P is already being done due to being subordinated by another group among the members in the group, selecting this value as false does not block the direct P2P among them. 

		\~chinese
		TrueîÜ?ğ«Íê?à÷?ñı?Direct P2P÷×ãá¡£Ùù??ãÀtrue¡£
		û¡à÷?£¬Ó£ãÀßÌï·?à÷?ñı?P2P÷×ãáîÜ?ı¦÷êó®??öÇà÷false¡£

		??à÷?ñı?ì«?ù¬Ğìöâİ¾??ßÓû»?ú¼Direct P2P?ı¦£¬÷êó®??öÇà÷falseÜô?ï·?öâ?îÜDirect P2P¡£

		\~japanese
		TrueªÇª¢ªìªĞ«°«ë?«×«á«ó«Ğ?ÊàªÎDirect P2P÷×ãáªòğ«Íêª·ªŞª¹¡£ĞñÜâö·ªÏtrueªÇª¹¡£
		«°«ë?«×ªòÌ¿ªÖª¬«á«ó«Ğ?ÊàªÇªÎP2P÷×ãáªòó´?ª·ª¿ª¤ãÁªÏª³ªÎö·ªòfalseªËàâïÒª·ªÆª¯ªÀªµª¤¡£

		«°«ë?«×?ªÇªÎ«á«ó«Ğ?ÊàªËªªª¤ªÆ¡¢?ªËöâªÎ«°«ë?«×ªÎ??ªËªèªÃªÆªªû»ª¤Direct P2Pªò?ªËªäªÃªÆª¤ªë?÷¾ªÎíŞùê¡¢ª³ªÎö·ªòfalseªËàâïÒª¹ªëª³ªÈª¬ª½ªìªéªÎDirect P2Pªòó´?ª¹ªëª³ªÈªÏª¢ªêªŞª»ªó¡£
		\~
	*/
		bool m_enableDirectP2P;

		CP2PGroupOption();		

		static PROUD_API CP2PGroupOption Default;
	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
