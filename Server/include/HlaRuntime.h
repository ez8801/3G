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

#include "HlaDef.h"
#include "Message.h"
#include "Ptr.h"
#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class SynchEntity_S;
	class SynchEntity_C;
	class SynchViewport_S;

#define DECLARE_HLA_MEMBER(behavior,type,name) \
private: behavior<type> m_##name##_INTERNAL; \
public: type get_##name() { return m_##name##_INTERNAL.Get(); } \
	void set_##name(type newVal) { m_##name##_INTERNAL.Set(newVal); } \
	__declspec(property(get=get_##name,put=set_##name)) type name;

	class SynchEntities_S: public map<HlaInstanceID, SynchEntity_S*>
	{
	};

	class SynchViewports_S: public map<HlaInstanceID, SynchViewport_S*>
	{
	};

	/** 
	\~korean
	SynchEntity Å¬¶óÀÌ¾ğÆ®Ãø Äİ·º¼Ç

	³ëÆ®
	- ¼­¹ö ÂÊ Äİ·º¼Ç°ú ´Ş¸®, ÀÌ Äİ·º¼ÇÀº °´Ã¼ ½º½º·Î ¼ÒÀ¯±ÇÀ» °¡Áö°í ÀÖ´Ù. ¿Ö³ÄÇÏ¸é ÀÌ Äİ·º¼Ç ¾ÆÀÌÅÛÀº À¯ÀúÀÇ ÄÁÆ®·ÑÇÏ¿¡ ¸¸µé¾î Áø°ÍÀÌ ¾Æ´Ï±â ¶§¹®ÀÌ´Ù.

	\~english
	SynchEntity client-side collection

	Note
	- Unlike the collection in server-side, this collection has the ownership of the objects. Because the collection items are
	created not under control of user.

	\~chinese
	SynchEntity client-side collection

	÷×ò±
	- ?Ü×?ĞïîÜ collection ÜôÔÒ£¬ó® collection ?ßÚÜâãó?êóó·á¶êó?¡£ì×?ó® collection Ô³ÎıÜôãÀî¤éÄ?îÜÍóğ¤ù»?ËïîÜ¡£

	\~japanese
	SynchEntity «¯«é«¤«¢«ó«Èö°«³«ì«¯«·«ç«ó

	«Î?«È
	- «µ?«Ğ?ö°ªÎ«³«ì«¯«·«ç«óªÈªÏêŞªÃªÆ¡¢ª³ªÎ«³«ì«¯«·«ç«óªÏ«ª«Ö«¸«§«¯«Èí»?ª¬á¶êó?ªòò¥ªÃªÆª¤ªŞª¹¡£ªÊª¼ªÊªé¡¢ª³ªÎ«³«ì«¯«·«ç«ó«¢«¤«Æ«àªÏ«æ?«¶?ªÎ«³«ó«È«í?«ëªÎù»ªÇíÂªéªìªëªâªÎªÇªÏªÊª¤ª«ªéªÇª¹¡£
	\~
	*/
	class SynchEntities_C: public map<HlaInstanceID, RefCount<SynchEntity_C> >
	{
	};

	class IHlaRuntimeDelegate_S
	{
	public:
		virtual ~IHlaRuntimeDelegate_S();

		virtual void Send(HostID dest, Protocol protocol, CMessage& message) = 0;

		// determines if one synch entity is visible (tangible) to one viewport
		virtual bool IsOneSynchEntityTangibleToOneViewport(SynchEntity_S* entity, SynchViewport_S *viewport) = 0;
	};

	/** 
	\~korean
	¼­¹öÃø HLA ·±Å¸ÀÓ ¸ğµâ

	»ç¿ë¹ı
	- ÀÌ °´Ã¼¸¦ »ı¼ºÇÑ´Ù.
	- SWD compiler-generated Å¬·¡½º ÀÎ½ºÅÏ½º¸¦ »ı¼ºÇÏ°í ÀÌ °´Ã¼¿¡ ÇÕÄ£´Ù.

	\~english
	Server-side HLA runtime module

	Usage
	- Create this object
	- Create SWD compiler-generated class instances and associate them to this object

	\~chinese
	Ü×?ĞïÛ° HLA ?ú¼??Ù¼?

	ŞÅéÄÛ°Ûö
	- ßæà÷ó®?ßÚ¡£
	- ßæà÷ SWD compiler-generated ??ÖÇ??ó®?ßÚùê?¡£

	\~japanese
	«µ?«Ğ?ö°HLA«é«ó«¿«¤«à«â«¸«å?«ë

	ŞÅéÄÛ°Ûö
	- ª³ªÎ«ª«Ö«¸«§«¯«Èªòßæà÷ª·ªŞª¹¡£
	- SWD compiler-generated «¯«é«¹ªÎ«¤«ó«¹«¿«ó«¹ªòßæà÷ª·ªÆª³ªÎ«ª«Ö«¸«§«¯«ÈªÈùêªïª»ªŞª¹¡£
	\~
	*/

	class CHlaRuntime_S
	{
		HlaInstanceID m_instanceIDFactory;
		IHlaRuntimeDelegate_S* m_dg;
	public:
		CHlaRuntime_S(IHlaRuntimeDelegate_S* dg);
		~CHlaRuntime_S(void);

		SynchEntities_S m_synchEntities;
		SynchViewports_S m_synchViewports;

		HlaInstanceID CreateInstanceID();
		void FrameMove(double elapsedTime);

		void Check_OneSynchEntity_EveryViewport(SynchEntity_S *entity);
		void Check_EverySynchEntity_OneViewport(SynchViewport_S *viewport);
		void Check_EverySynchEntity_EveryViewport();
	private:
		void Check_OneSynchEntity_OneViewport( SynchEntity_S * entity, SynchViewport_S* viewport, CMessage appearMsg, CMessage disappearMsg );
		void Send_INTERNAL(vector<HostID> sendTo, Protocol protocol, CMessage &msg);
	public:
		void RemoveOneSynchEntity_INTERNAL(SynchEntity_S* entity);
		void RemoveOneSynchViewport_INTERNAL( SynchViewport_S* entity );
	};

	class IHlaRuntimeDelegate_C
	{
	public:
		virtual ~IHlaRuntimeDelegate_C();
		virtual SynchEntity_C* CreateSynchEntityByClassID(HlaClassID classID) = 0;
	};

	/** 
	\~korean
	Å¬¶óÀÌ¾ğÆ®Ãø HLA ¸ŞÀÎ ·±Å¸ÀÓ

	»ç¿ë¹ı
	- ÀÌ °´Ã¼¸¦ »ı¼ºÇÏ°í SWD ÄÄÆÄÀÏ·¯¿¡ ÀÇÇØ ¸¸µé¾îÁø ÇÏ³ª ¶Ç´Â ÀÌ»óÀÇ HLA ·±Å¸ÀÓ delegateµé°ú ÇÕÄ£´Ù.
	- ProcessReceivedMessage()¿¡ ÀÇÇØ ÀÌ °´Ã¼·Î ¹ŞÀº ¸Ş¼¼Áö¸¦ Àü´ŞÇÑ´Ù.
	\~english
	HLA client-side main runtime

	Usage
	- Create this object and associate one or more HLA runtime delegates which are generated by SWD compiler.
	- Pass the received message to this object by ProcessReceivedMessage(). 

	\~chinese
	Client Û° HLA ñ«é©?ú¼??

	ŞÅéÄÛ°Ûö
	- ßæà÷ó®?ßÚì¤ı¨?ë¦ SWD ßæà÷Ğï?ËïîÜìé?ûäíºìé?ì¤ß¾îÜ HLA ?ú¼?? delegate ?ú¼ùê?¡£
	- ë¦ ProcessReceivedMessage()???ó®??ïÈâ¥îÜãáãÓ¡£

	\~japanese
	«¯«é«¤«¢«ó«Èö°HLA«á«¤«ó«é«ó«¿«¤«à

	ŞÅéÄÛ°Ûö
	- ª³ªÎ«ª«Ö«¸«§«¯«Èªòßæà÷ª·ªÆSWD«³«ó«Ñ«¤«é?ªËªèªÃªÆíÂªéªìª¿ìéªÄªŞª¿ªÏª½ªìì¤ß¾ªÎHLA«é«ó«¿«¤«àdelegateªÊªÉªÈùêªïª»ªŞª¹¡£
	- ProcessReceivedMessage()ªËªèªÃªÆª³ªÎ«ª«Ö«¸«§«¯«ÈªÇáôª±ª¿«á«Ã«»?«¸ªò?Ó¹ª·ªŞª¹¡£
	\~
	*/
	class CHlaRuntime_C
	{
		SynchEntity_C* CreateSynchEntityByClassID( HlaClassID classID , HlaInstanceID instanceID);
		typedef vector<IHlaRuntimeDelegate_C*> DgList;
		DgList m_dgList;
		String m_lastProcessMessageReport;
	public:
		SynchEntities_C m_synchEntities;

		CHlaRuntime_C() {}
		~CHlaRuntime_C() {}

		void AddDelegate(IHlaRuntimeDelegate_C *dg);
		void ProcessReceivedMessage(CMessage& msg);
		SynchEntity_C* GetSynchEntityByID(HlaInstanceID instanceID);

		String GetLastProcessMessageReport();
		void Clear();
	};

	Protocol CombineProtocol(Protocol a, Protocol b);
}

//#pragma pack(pop)

?/*
ProudNet

ÀÌ ÇÁ·Î±×·¥ÀÇ ÀúÀÛ±ÇÀº ³İÅÙ¼Ç¿¡°Ô ÀÖ½À´Ï´Ù.
ÀÌ ÇÁ·Î±×·¥ÀÇ ¼öÁ¤, »ç¿ë, ¹èÆ÷¿¡ °ü·ÃµÈ »çÇ×Àº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾àÀ» µû¸£¸ç,
°è¾àÀ» ÁØ¼öÇÏÁö ¾Ê´Â °æ¿ì ¿øÄ¢ÀûÀ¸·Î ¹«´Ü »ç¿ëÀ» ±İÁöÇÕ´Ï´Ù.
¹«´Ü »ç¿ë¿¡ ÀÇÇÑ Ã¥ÀÓÀº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾à¼­¿¡ ¸í½ÃµÇ¾î ÀÖ½À´Ï´Ù.

** ÁÖÀÇ: ÀúÀÛ¹°¿¡ °üÇÑ À§ÀÇ ¸í½Ã¸¦ Á¦°ÅÇÏÁö ¸¶½Ê½Ã¿À.

ProudNet

This program is soley copyrighted by Nettention. 
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE. 

ProudNet

ó®ïïßíîÜ÷ú??NettentionÍëŞÉá¶êó¡£
?ó®ïïßíîÜáóËÇ¡¢ŞÅéÄ¡¢?øÖßÓ?îÜŞÀ?é©ñåáúó®ïïßíîÜá¶êó?íºîÜ??¡£
Üôñåáú???é©ê«?àõîÜĞ×ò­ôºí»ŞÅéÄ¡£
ôºí»ŞÅéÄîÜ?ìòÙ¥ãÆî¤?ó®ïïßíá¶êó?íºîÜùêÔÒ?×ì¡£

** ñ¼ëò£ºÜôé©ì¹ğ¶?éÍğ¤íÂÚªîÜß¾âûÙ¥ãÆ¡£

*/

#pragma once

#include "hladef.h"
#include "message.h"
#include "ptr.h"
#include "PNString.h"

#ifndef __GNUC__

//#pragma pack(push,8)

namespace Proud
{
	class SynchEntity_S;
	class SynchEntity_C;
	class SynchViewport_S;

#define DECLARE_HLA_MEMBER(behavior,type,name) \
private: behavior<type> m_##name##_INTERNAL; \
public: type get_##name() { return m_##name##_INTERNAL.Get(); } \
	void set_##name(type newVal) { m_##name##_INTERNAL.Set(newVal); } \
	__declspec(property(get=get_##name,put=set_##name)) type name;

	class SynchEntities_S: public map<HlaInstanceID, SynchEntity_S*>
	{
	};

	class SynchViewports_S: public map<HlaInstanceID, SynchViewport_S*>
	{
	};

	/** 
	\~korean
	SynchEntity Å¬¶óÀÌ¾ğÆ®Ãø Äİ·º¼Ç

	³ëÆ®
	- ¼­¹ö ÂÊ Äİ·º¼Ç°ú ´Ş¸®, ÀÌ Äİ·º¼ÇÀº °´Ã¼ ½º½º·Î ¼ÒÀ¯±ÇÀ» °¡Áö°í ÀÖ´Ù. ¿Ö³ÄÇÏ¸é ÀÌ Äİ·º¼Ç ¾ÆÀÌÅÛÀº À¯ÀúÀÇ ÄÁÆ®·ÑÇÏ¿¡ ¸¸µé¾î Áø°ÍÀÌ ¾Æ´Ï±â ¶§¹®ÀÌ´Ù.

	\~english
	SynchEntity client-side collection

	Note
	- Unlike the collection in server-side, this collection has the ownership of the objects. Because the collection items are
	created not under control of user.

	\~chinese
	SynchEntity client-side collection

	÷×ò±
	- ?Ü×?ĞïîÜ collection ÜôÔÒ£¬ó® collection ?ßÚÜâãó?êóó·á¶êó?¡£ì×?ó® collection Ô³ÎıÜôãÀî¤éÄ?îÜÍóğ¤ù»?ËïîÜ¡£

	\~japanese
	SynchEntity «¯«é«¤«¢«ó«Èö°«³«ì«¯«·«ç«ó

	«Î?«È
	- «µ?«Ğ?ö°ªÎ«³«ì«¯«·«ç«óªÈªÏêŞªÃªÆ¡¢ª³ªÎ«³«ì«¯«·«ç«óªÏ«ª«Ö«¸«§«¯«Èí»?ª¬á¶êó?ªòò¥ªÃªÆª¤ªŞª¹¡£ªÊª¼ªÊªé¡¢ª³ªÎ«³«ì«¯«·«ç«ó«¢«¤«Æ«àªÏ«æ?«¶?ªÎ«³«ó«È«í?«ëªÎù»ªÇíÂªéªìª¿ªâªÎªÇªÏªÊª¤ª«ªéªÇª¹¡£
	\~
	*/
	class SynchEntities_C: public map<HlaInstanceID, RefCount<SynchEntity_C> >
	{
	};

	class IHlaRuntimeDelegate_S
	{
	public:
		virtual ~IHlaRuntimeDelegate_S();

		virtual void Send(HostID dest, Protocol protocol, CMessage& message) = 0;

		// determines if one synch entity is visible (tangible) to one viewport
		virtual bool IsOneSynchEntityTangibleToOneViewport(SynchEntity_S* entity, SynchViewport_S *viewport) = 0;
	};

	/** 
	\~korean
	¼­¹öÃø HLA ·±Å¸ÀÓ ¸ğµâ

	»ç¿ë¹ı
	- ÀÌ °´Ã¼¸¦ »ı¼ºÇÑ´Ù.
	- SWD compiler-generated Å¬·¡½º ÀÎ½ºÅÏ½º¸¦ »ı¼ºÇÏ°í ÀÌ °´Ã¼¿¡ ÇÕÄ£´Ù.

	\~english
	Server-side HLA runtime module

	Usage
	- Create this object
	- Create SWD compiler-generated class instances and associate them to this object

	\~chinese
	Ü×?ĞïÛ° HLA ?ú¼??Ù¼?

	ŞÅéÄÛ°Ûö
	- ßæà÷ó®?ßÚ¡£
	- ßæà÷ SWD compiler-generated ??ÖÇ??ó®?ßÚùê?¡£

	\~japanese
	«µ?«Ğ?ö°HLA«é«ó«¿«¤«à«â«¸«å?«ë

	ŞÅéÄÛ°Ûö
	- ª³ªÎ«ª«Ö«¸«§«¯«Èªòßæà÷ª·ªŞª¹¡£
	- SWD compiler-generated «¯«é«¹«¤«ó«¹«¿«ó«¹ªòßæà÷ª·ªÆª³ªÎ«ª«Ö«¸«§«¯«ÈªËùêªïª»ªŞª¹¡£
	\~
	*/
	class CHlaRuntime_S
	{
		HlaInstanceID m_instanceIDFactory;
		IHlaRuntimeDelegate_S* m_dg;
	public:
		CHlaRuntime_S(IHlaRuntimeDelegate_S* dg);
		~CHlaRuntime_S(void);

		SynchEntities_S m_synchEntities;
		SynchViewports_S m_synchViewports;

		HlaInstanceID CreateInstanceID();
		void FrameMove(double elapsedTime);

		void Check_OneSynchEntity_EveryViewport(SynchEntity_S *entity);
		void Check_EverySynchEntity_OneViewport(SynchViewport_S *viewport);
		void Check_EverySynchEntity_EveryViewport();
	private:
		void Check_OneSynchEntity_OneViewport( SynchEntity_S * entity, SynchViewport_S* viewport, CMessage appearMsg, CMessage disappearMsg );
		void Send_INTERNAL(vector<HostID> sendTo, Protocol protocol, CMessage &msg);
	public:
		void RemoveOneSynchEntity_INTERNAL(SynchEntity_S* entity);
		void RemoveOneSynchViewport_INTERNAL( SynchViewport_S* entity );
	};

	class IHlaRuntimeDelegate_C
	{
	public:
		virtual ~IHlaRuntimeDelegate_C();
		virtual SynchEntity_C* CreateSynchEntityByClassID(HlaClassID classID) = 0;
	};

	/** 
	\~korean
	Å¬¶óÀÌ¾ğÆ®Ãø HLA ¸ŞÀÎ ·±Å¸ÀÓ

	»ç¿ë¹ı
	- ÀÌ °´Ã¼¸¦ »ı¼ºÇÏ°í SWD ÄÄÆÄÀÏ·¯¿¡ ÀÇÇØ ¸¸µé¾îÁø ÇÏ³ª ¶Ç´Â ÀÌ»óÀÇ HLA ·±Å¸ÀÓ delegateµé°ú ÇÕÄ£´Ù.
	- ProcessReceivedMessage()¿¡ ÀÇÇØ ÀÌ °´Ã¼·Î ¹ŞÀº ¸Ş¼¼Áö¸¦ Àü´ŞÇÑ´Ù.

	\~english
	HLA client-side main runtime

	Usage
	- Create this object and associate one or more HLA runtime delegates which are generated by SWD compiler.
	- Pass the received message to this object by ProcessReceivedMessage().

	\~chinese
	ClientÛ°HLAñ«é©?ú¼??

	ŞÅéÄÛ°Ûö
	- ßæà÷ó®?ßÚì¤ı¨?ë¦SWDßæà÷Ğï?ËïîÜìé?ûäíºìé?ì¤ß¾îÜHLA?ú¼??delegate?ú¼ùê?¡£
	- ë¦ ProcessReceivedMessage()???ó®??ïÈâ¥îÜãáãÓ¡£

	\~japanese
	«¯«é«¤«¢«ó«Èö°HLA«á«¤«ó«é«ó«¿«¤«à

	ŞÅéÄÛ°Ûö
	- ª³ªÎ«ª«Ö«¸«§«¯«Èªòßæà÷ª·ªÆSWD«³«ó«Ñ«¤«é?ªËªèªÃªÆíÂªéªìª¿ìéªÄªŞª¿ªÏª½ªìì¤ß¾ªÎHLA«é«ó«¿«¤«àdelegateªÊªÉªÈùêªïª»ªŞª¹¡£
	- ProcessReceivedMessage()ªËªèªÃªÆª³ªÎ«ª«Ö«¸«§«¯«ÈªÇáôª±ª¿«á«Ã«»?«¸ªò?Ó¹ª·ªŞª¹¡£
	\~
	*/
	class CHlaRuntime_C
	{
		SynchEntity_C* CreateSynchEntityByClassID( HlaClassID classID , HlaInstanceID instanceID);
		typedef vector<IHlaRuntimeDelegate_C*> DgList;
		DgList m_dgList;
		String m_lastProcessMessageReport;
	public:
		SynchEntities_C m_synchEntities;

		CHlaRuntime_C() {}
		~CHlaRuntime_C() {}

		void AddDelegate(IHlaRuntimeDelegate_C *dg);
		void ProcessReceivedMessage(CMessage& msg);
		SynchEntity_C* GetSynchEntityByID(HlaInstanceID instanceID);

		String GetLastProcessMessageReport();
		void Clear();
	};

	Protocol CombineProtocol(Protocol a, Protocol b);
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif // __GNUC__
<<<<
