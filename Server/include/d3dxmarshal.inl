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

	inline CMessage& operator>>(CMessage &a, D3DXVECTOR3 &b)
	{
		a.Read(b.x);
		a.Read(b.y);
		a.Read(b.z);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, const D3DXVECTOR3 &b)
	{
		a.Write(b.x);
		a.Write(b.y);
		a.Write(b.z);
		return a;
	}

	inline CMessage& operator>>(CMessage &a, D3DXMATRIX &b)
	{
		a.Read((uint8_t*)&b,sizeof(b));
		return a;
	}
	inline CMessage& operator<<(CMessage &a, const D3DXMATRIX &b)
	{
		a.Write((const uint8_t*)&b,sizeof(b));
		return a;
	}

	inline CMessage& operator>>(CMessage &a, D3DXQUATERNION &b)
	{
		a.Read((uint8_t*)&b,sizeof(b));
		return a;
	}
	inline CMessage& operator<<(CMessage &a, const D3DXQUATERNION &b)
	{
		a.Write((const uint8_t*)&b,sizeof(b));
		return a;
	}

	inline CMessage& operator>>(CMessage &a,D3DXVECTOR2 &b)
	{
		a>>b.x>>b.y;
		return a;
	}

	inline CMessage& operator<<(CMessage &a,const D3DXVECTOR2 &b)
	{
		a<<b.x<<b.y;
		return a;
	}

	inline void AppendTextOut(String &a,const D3DXMATRIX &)
	{
		a+=_PNT("<D3DXMATRIX>");
	}
	inline void AppendTextOut(String &a,const D3DXQUATERNION &b)
	{
		String f;
		f.Format(_PNT("{x=%f,y=%f,z=%f,w=%f}"),b.x,b.y,b.z,b.w);
		a+=f;
	}
	inline void AppendTextOut(String &a,const D3DXVECTOR3 &b)
	{
		String f;
		f.Format(_PNT("{x=%f,y=%f,z=%f}"),b.x,b.y,b.z);
		a+=f;
	}

	inline void AppendTextOut(String &a,const D3DXVECTOR2 &b)
	{
		String f;
		f.Format(_PNT("{x=%f,y=%f}"),b.x,b.y);
		a+=f;
	}

}
#ifdef _MSC_VER
#pragma pack(pop)
#endif