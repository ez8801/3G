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

#include "Marshaler.h"

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
	DB cache server¿¡¼­ À¯Àú°¡ Á¤ÀÇÇÑ Table ¿¡ ½ÇÁ¦·Î ±â·ÏÇÒ »ç°ÇÀÇ Á¾·ù

	\~english
	Sort of event that actually writting to user defined table in DB cache server

	\~chinese
	î¤DB cache serverß¾éÄ?ïÒ?îÜTable??é©??îÜÞÀËìîÜ??¡£

	\~japanese
	DB cache serverªÇ«æ?«¶?ª¬ïÒëùª·ª¿TableªË?ð·ªËÑÀ?ª¹ªëÞÀËìªÎðú×¾
	\~
	*/
	enum DbmsWritePropNodePendType
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
		DWPNPT_None,

		/**
		\~korean
		\ref PropNode  Ãß°¡ 

		\~english
		Add \ref PropNode 

		\~chinese
		ôÕÊ¥\ref PropNode%¡£

		\~japanese
		\ref PropNode  õÚÊ¥
		\~
		*/
		DWPNPT_AddPropNode,

		/** 
		\~korean
		\ref PropNode  »èÁ¦ 

		\~english
		Delete \ref PropNode 
		
		\~chinese
		?ð¶\ref PropNode%¡£

		\~japanese
		\ref PropNode  Þûð¶
		\~
		*/
		DWPNPT_RemovePropNode,

		/**
		\~korean
		Request ¿¡ ´ëÇÑ \ref PropNode ¾÷µ¥ÀÌÆ® 
		
		\~english TODO:Translate needed.
		Update \ref PropNode.

		\~chinese TODO:Translate needed.
		ã®?\ref PropNode%¡£

		\~japanese
		Request ªË?ª¹ªë \ref PropNode «¢«Ã«×«Ç?«È
		\~
		*/
		DWPNPT_RequestUpdatePropNode,

		/**
		\~
		\ref PropNode  SetValueIf
		*/
		DWPNPT_SetValueIf,

		/**
		\~
		\ref PropNode  ModifyValueIf
		*/
		DWPNPT_ModifyValue,

		/** 
		\~korean 
		Request ¿¡ ´ëÇÑ \ref PropNode ¾÷µ¥ÀÌÆ® 
		
		\~english TODO:Translate needed.
		Update \ref PropNod.
		
		\~chinese TODO:Translate needed.
		ã®?\ref PropNode%¡£

		\~japanese
		Request ¿¡ ´ëÇÑ \ref PropNode ¾÷µ¥ÀÌÆ® 
		\~
		*/
		DWPNPT_RequestUpdatePropNodeList,

		/** 
		\~korean
		\ref PropNode   ÀÌµ¿ 

		\~english 
		Update \ref PropNod 
		
		\~chinese
		\ref PropNode%ì¹?¡£
		\~japanese
		\ref PropNode   ì¹ÔÑ
		\~
		*/
		DWPNPT_MovePropNode,

		/**
		\~korean
		\~english
		\~chinese
		\~japanese
		\~
		Unilateral Update \ref PropNod.
		*/
		DWPNPT_UnilateralUpdatePropNode,

		/**
		\~korean
		\~english
		\~chinese
		\~japanese
		\~
		Unilateral Update \ref PropNod.
		*/
		DWPNPT_UnilateralUpdatePropNodeList,

		/**
		\~korean
		\ref PropNode ¾÷µ¥ÀÌÆ®

		\~english
		Update \ref PropNode

		\~chinese
		ã®?\ref PropNode%¡£

		\~japanese
		\ref PropNode «¢«Ã«×«Ç?«È
		\~
		*/
		DWPNPT_UpdatePropNode,
	};

	PROUDSRV_API const PNTCHAR* TypeToString(DbmsWritePropNodePendType t);

	/**  @}  */

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

PROUDNET_SERIALIZE_ENUM(DbmsWritePropNodePendType);

#ifdef _MSC_VER
#pragma pack(pop)
#endif