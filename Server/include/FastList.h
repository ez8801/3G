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

#include <assert.h>
#include "Ptr.h"
#include "BasicTypes.h"
#include "Singleton.h"
#include "Enums.h"
#include <assert.h>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	extern const char* CannotUseFastHeapForFilledCollectionErrorText;

	/** \addtogroup util_group
	*  @{
	*/

	/**

	\~korean
	¸Å¿ì ºü¸£°Ô Ã³¸® µÇ´Â Linked List.
	- ³»ºÎÀûÀ¸·Î CFastHeap À» »ç¿ëÇÏ½Ê½Ã¿À. ±×·¯¸é element¸¦ Ãß°¡/»èÁ¦ ÇÏ´Â ºñ¿ëÀÌ ÁÙ¾îµé°ÍÀÔ´Ï´Ù.
	´Ü, <a target="_blank" href="http://guide.nettention.com/cpp_ko#fast_heap" >Fast heap</a> ¿¡ ¸í½ÃµÈ ÁÖÀÇ»çÇ×À» ÁØ¼öÇÏ½Ê½Ã¿À.
	- CFastArray ¿Í´Â ´Ù¸£°Ô class µéÀ» »ı¼ºÀÚ, ¼Ò¸êÀÚ, º¹»ç ´ëÀÔ ¿¬»êÀÚ¿Í ÇÔ²² »ç¿ëÇÒ ¼ö ÀÖ½À´Ï´Ù.

	\param E collectionÀÇ Ç×¸ñ Å¸ÀÔ.
	\param ETraits Collection Ç×¸ñÀ» ´Ù·ç´Â Æ¯¼º.
	\param AllocT AllocType °ª Áß ÇÏ³ª.

	\~english
	Linked List that can be processed with extremely fast.
	- Uses CFastHeap internally. Therefore, has little cost at adding/deleting element.
	  However, it must correctly follow all the rules described in <a target="_blank" href="http://guide.nettention.com/cpp_en#fast_heap" >Fast heap</a>.
	- In contrast with CFastArray, classes can be used with constructor, destructor and copy assignment operator.

	\param E clause type of collection
	\param ETraits characteristic that handles collection clause
	\param AllocT one of the values of AllocType

	\~chinese
	ãÀù¬öááÜ?×âîÜLinked List¡£
	-?î¤?İ»ŞÅéÄCFastHeap¡£??Ê¦ì¤?á´?elementîÜôÕÊ¥/?ğ¶?éÄ¡£
	Ó£?ñåáú<a target="_blank" href="http://guide.nettention.com/cpp_zh#fast_heap" >Fast heap</a>îÜÙ¥ãÆ?é»¡£
	-?CFastArrayÜôÔÒ£¬Ê¦ì¤ÔÒ?ŞÅéÄclass?Constructor¡¢Destructor¡¢?ğ¤???ß©İ¬¡£

	\param E CollectionîÜ?ÙÍ?úş¡£
	\param ETraits ğÃíÂCollection?ÙÍîÜ÷åàõ¡£
	\param AllocT AllocType?ñıìé¡£

	\~japanese
	ª¹ª´ª¯áÜª¤áÜÓøªÇ?×âªµªìªë Linked List.
	- ?İ»îÜªË CFastHeapªòŞÅéÄª·ªÆª¯ªÀªµª¤¡£ª½ª¦ª¹ªëªÈ elementªòõÚÊ¥/Şûğ¶ª¹ªëŞ¨éÄªòÊõªéª»ªŞª¹¡£
	ª¿ªÀª·¡¢ <a target="_blank" href="http://guide.nettention.com/cpp_jp#fast_heap" >Fast heap</a>ªËÙ¥ãÆªµªìªÆª¤ªëñ¼ëòŞÀú£ªòñåáúª·ªÆª¯ªÀªµª¤¡£
	- CFastArray ªÈªÏêŞªÃªÆ classª¿ªÁªòÏ°õéí­(«³«ó«¹«È«é«¯«¿)¡¢á¼ËÛí­£¨«Ç«¹«È«é«¯«¿£©, Copy ÓÛìıæÑß©í­(Copy assignment operator)ªÈìé?ªËŞÅéÄªÇª­ªŞª¹¡£

	\param E collectionªÎú£ÙÍ«¿«¤«×
	\param ETraits Collection ú£ÙÍªòĞâª¦÷åàõ
	\param AllocT AllocType ö·ªÎñéªÎ1ªÄ

	\~
	*/
	template < typename E, typename ETraits = CPNElementTraits< E > >
	class CFastList
	{
	public:
		typedef typename ETraits::INARGTYPE INARGTYPE;

	private:
		class CNode : public __Position
		{
		public:
			inline CNode()
			{
			}
			inline CNode( INARGTYPE element)
				:m_element( element )
			{
			}
			inline ~CNode() throw()
			{
			}

		public:
			CNode* m_pNext;
			CNode* m_pPrev;
			E m_element;

		private:
			CNode( const CNode& ) throw();
		};

	public:

		CFastList() throw()
		{
			m_nElements = 0;
			m_pHead = NULL;
			m_pTail = NULL;
		}

#if defined(_MSC_VER)
		__declspec(property(get = GetCount)) intptr_t Count;
#endif

		inline intptr_t GetCount() const throw()
		{
			return( m_nElements );
		}

		/**
		\~korean
		\return ¾Æ¹«·± µ¥ÀÌÅÍ°¡ ¾øÀ¸¸é true, Á¸ÀçÇÏ¸é false¸¦ ¸®ÅÏ

		\~english 
		If there is no data then true, otherwise return false. 

		\~chinese
		\return ?êóìòù¼?ËßîÜ?true£¬ğíî¤îÜ?Ú÷üŞfalse¡£

		\~japanese
		\return ù¼ªéªÎ«Ç?«¿ª¬ªÊª±ªìªĞtrue¡¢ğíî¤ª¹ªëªÈfalseªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		inline bool IsEmpty() const throw()
		{
			return( m_nElements == 0 );
		}

		/**
		\~korean
		\return listÀÇ Ã¹¹øÂ° data¸¦ ¸®ÅÏÇÕ´Ï´Ù.

		\~english 
		Return the first data in the \return list. 

		\~chinese
		\return Ú÷üŞlistîÜğ¯ìé?data¡£

		\~japanese
		\return listªÎõÌôø«Ç?«¿ªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		inline E& GetHead()
		{
			assert( m_pHead != NULL );
			return( m_pHead->m_element );
		}

		/**
		\~korean
		\return listÀÇ Ã¹¹øÂ° data¸¦ const º¯¼ö·Î ¸®ÅÏÇÕ´Ï´Ù.

		\~english 
		\return the first data in list as a const variable. 

		\~chinese
		\return Ú÷üŞlistîÜğ¯ìé?data?const??¡£

		\~japanese
		\return listªÎõÌôø«Ç?«¿ªòconst??ªË«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		inline const E& GetHead() const
		{
			assert( m_pHead != NULL );
			return( m_pHead->m_element );
		}

		/**
		\~korean
		\return listÀÇ ¸¶Áö¸· Data¸¦ ¸®ÅÏÇÕ´Ï´Ù.

		\~english 
		\return the last data in list. 

		\~chinese
		\return Ú÷üŞlistîÜõÌı¨data¡£

		\~japanese
		\return listªÎõÌı­«Ç?«¿ªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		inline E& GetTail()
		{
			assert( m_pTail != NULL );
			return( m_pTail->m_element );
		}

		/**
		\~korean
		\return listÀÇ ¸¶Áö¸· Data¸¦ const º¯¼ö·Î ¸®ÅÏÇÕ´Ï´Ù.

		\~english 
		\return the last data in list as a const variable. 

		\~chinese
		\return Ú÷üŞlistîÜõÌı¨data?const??¡£

		\~japanese
		\return listªÎõÌı­«Ç?«¿ªòconst??ªË«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		inline const E& GetTail() const
		{
			assert( m_pTail != NULL );
			return( m_pTail->m_element );
		}

		/**
		\~korean
		list ÀÇ Ã¹¹øÂ° Data¸¦ list³»¿¡¼­ Á¦°ÅÇÏ°í ¸®ÅÏÇØ Áİ´Ï´Ù.
		\return list¿¡¼­ Á¦°ÅµÈ data

		\~english 
		Deletes the first data within the list and returns it. 
		\return Data deleted from \return list

		\~chinese
		?list??ğ¶?Ú÷üŞlistîÜğ¯ìé?data¡£
		\return î¤listù¬?ğ¶îÜdata¡£

		\~japanese
		ListªÎõÌôø«Ç?«¿ªò«ê«¹«È?ªèªêğ¶ËÛª·ªÆ«ê«¿?«óª·ªŞª¹¡£
		\return listªèªêğ¶ËÛªµªìª¿«Ç?«¿ 
		\~
		*/
		inline E RemoveHead()
		{
			assert( m_pHead != NULL );

			CNode* pNode = m_pHead;
			E element( pNode->m_element );

			m_pHead = pNode->m_pNext;
			if ( m_pHead != NULL )
			{
				m_pHead->m_pPrev = NULL;
			}
			else
			{
				m_pTail = NULL;
			}
			FreeNode( pNode );

			return( element );
		}

		/**
		\~korean
		list ÀÇ ¸¶Áö¸· Data¸¦ list³»¿¡¼­ Á¦°ÅÇÏ°í ¸®ÅÏÇØ Áİ´Ï´Ù.
		\return list¿¡¼­ Á¦°ÅµÈ data

		\~english 
		Deletes the first data within the list and returns it. 
		\return Data deleted from \return list

		\~chinese
		?list??ğ¶?Ú÷üŞlistîÜõÌı¨data¡£
		\return î¤listù¬?ğ¶îÜdata¡£

		\~japanese
		ListªÎõÌı­ªÎ«Ç?«¿ªò«ê«¹«È?ªÇğ¶ËÛª·ªÆ«ê«¿?«óª·ªŞª¹¡£
		\return listªèªêğ¶ËÛªµªìª¿«Ç?«¿
		\~
		*/
		inline E RemoveTail()
		{
			assert( m_pTail != NULL );

			CNode* pNode = m_pTail;

			E element( pNode->m_element );

			m_pTail = pNode->m_pPrev;
			if ( m_pTail != NULL )
			{
				m_pTail->m_pNext = NULL;
			}
			else
			{
				m_pHead = NULL;
			}
			FreeNode( pNode );

			return( element );
		}

		/**
		\~korean
		listÀÇ Ã¹¹øÂ° data¸¦ Á¦°ÅÇÕ´Ï´Ù.

		\~english 
		First data of the list is deleted. 

		\~chinese
		?ğ¶listîÜğ¯ìé?data¡£

		\~japanese
		ListªÎõÌôø«Ç?«¿ªòğ¶ËÛª·ªŞª¹¡£
		\~
		*/
		inline void RemoveHeadNoReturn() throw()
		{
			assert( m_pHead != NULL );

			CNode* pNode = m_pHead;

			m_pHead = pNode->m_pNext;
			if ( m_pHead != NULL )
			{
				m_pHead->m_pPrev = NULL;
			}
			else
			{
				m_pTail = NULL;
			}
			FreeNode( pNode );
		}

		/**
		\~korean
		listÀÇ ¸¶Áö¸· data¸¦ Á¦°ÅÇÕ´Ï´Ù.

		\~english 
		Last data of the list is deleted. 

		\~chinese
		?ğ¶listîÜõÌı¨data¡£

		\~japanese
		ListªÎõÌı­«Ç?«¿ªòğ¶ËÛª·ªŞª¹¡£
		\~
		*/
		inline void RemoveTailNoReturn() throw()
		{
			assert( m_pTail != NULL );

			CNode* pNode = m_pTail;

			m_pTail = pNode->m_pPrev;
			if ( m_pTail != NULL )
			{
				m_pTail->m_pNext = NULL;
			}
			else
			{
				m_pHead = NULL;
			}
			FreeNode( pNode );
		}

		/**
		\~korean
		Data°¡ ºñ¾îÀÖ´Â ÇØ´õ¸¦ Ãß°¡ÇÑ´Ù.
		\return »õ·Î Ãß°¡µÈ ³ëµåÀÇ Position

		\~english 
		An empty header without data is added. 
		\return Position of the newly added node 

		\~chinese
		ôÕÊ¥data?ÍöîÜheader¡£
		\return ãæôÕÊ¥îÜ?ïÃPosition¡£

		\~japanese
		«Ç?«¿ª¬Íöª¤ªÆª¤ªë«Ø«Ã«À?ªòõÚÊ¥ª·ªŞª¹¡£
		\return ãæª¿ªËõÚÊ¥ªµªìª¿«Î?«ÉªÎPosition
		\~
		*/
		inline Proud::Position AddHead()
		{
			CNode* pNode = NewNode( NULL, m_pHead );
			if ( m_pHead != NULL )
			{
				m_pHead->m_pPrev = pNode;
			}
			else
			{
				m_pTail = pNode;
			}
			m_pHead = pNode;

			return( Proud::Position( pNode ) );
		}

		/**
		\~korean
		Çì´õ¸¦ Ãß°¡ÇÕ´Ï´Ù.
		\param element »õ·Î¿î Çì´õ¿¡ ³ÖÀ» Data
		\return »õ·Î Ãß°¡µÈ ³ëµåÀÇ Position

		\~english 
		Add a header 
		\param element Data to be inserted to a new header
		\return Position of a newly added node

		\~chinese
		ôÕÊ¥header¡£
		\param element èÙãæîÜheader?ìıîÜdata¡£
		\return ãæôÕÊ¥îÜ?ïÃîÜPosition¡£

		\~japanese
		«Ø«Ã«À?ªòõÚÊ¥ª·ªŞª¹¡£
		\param element ãæª·ª¤«Ø«Ã«À?ªËìıªìªë«Ç?«¿
		\return ãæª¿ªËõÚÊ¥ªµªìª¿«Î?«ÉªÎPosition
		\~
		*/
		inline Proud::Position AddHead( INARGTYPE element )
		{
			CNode* pNode;

			pNode = NewNode( element, NULL, m_pHead );

			if ( m_pHead != NULL )
			{
				m_pHead->m_pPrev = pNode;
			}
			else
			{
				m_pTail = pNode;
			}
			m_pHead = pNode;

			return( Proud::Position( pNode ) );
		}

		/**
		\~korean
		Çì´õ¿¡ »õ·Î¿î list¸¦ Ãß°¡ÇÕ´Ï´Ù.
		\param plNew Çì´õ¿¡ Ãß°¡ÇÒ list

		\~english 
		A new list is added to the header
		\param plNew List to be added to the header 

		\~chinese
		èÙheaderôÕÊ¥ãæîÜlist¡£
		\param plNew é©èÙheaderôÕÊ¥îÜlist¡£

		\~japanese
		«Ø«Ã«À?ªËãæª·ª¤ListªòõÚÊ¥ª·ªŞª¹¡£
		\param plNew «Ø«Ã«À?ªËõÚÊ¥ª¹ªëList
		\~
		*/
		inline void AddHeadList( const CFastList* plNew )
		{
			assert( plNew != NULL );

			Proud::Position pos = plNew->GetTailPosition();
			while ( pos != NULL )
			{
				INARGTYPE element = plNew->GetPrev( pos );
				AddHead( element );
			}
		}

		/**
		\~korean
		listÀÇ ¸¶Áö¸·¿¡ ºó ³ëµå¸¦ Ãß°¡ÇÑ´Ù.
		\return »õ·Î Ãß°¡µÈ ³ëµåÀÇ Position

		\~english 
		An empty node is added to the end of the list. 
		\return Position of the newly added node. 

		\~chinese
		èÙlistîÜõÌı¨ôÕÊ¥Íö?ïÃ¡£
		\return ãæôÕÊ¥îÜ?ïÃPosition¡£

		\~japanese
		ListªÎõÌı­ªËÍö«Î?«ÉªòõÚÊ¥ª·ªŞª¹¡£
		\return ãæª¿ªËõÚÊ¥ªµªìª¿«Î?«ÉªÎPosition
		\~
		*/
		inline Proud::Position AddTail()
		{
			CNode* pNode = NewNode( m_pTail, NULL );
			if ( m_pTail != NULL )
			{
				m_pTail->m_pNext = pNode;
			}
			else
			{
				m_pHead = pNode;
			}
			m_pTail = pNode;

			return( Proud::Position( pNode ) );
		}

		/**
		\~korean
		listÀÇ ¸¶Áö¸·¿¡ node¸¦ Ãß°¡
		\param element ¸¶Áö¸· ³ëµå¿¡ »ğÀÔÀ» Data
		\return »õ·Î Ãß°¡µÈ ³ëµåÀÇ Position

		\~english 
		Add a node at the end of the list
		\param element Data to be inserted to the last node 
		\return Position of the newly added node

		\~chinese
		èÙlistîÜõÌı¨ôÕÊ¥node¡£
		\param element èÙõÌı¨?ïÃ?ìıîÜdata¡£
		\return ãæôÕÊ¥îÜ?ïÃîÜPosition¡£

		\~japanese
		listªÎõÌı­ªËnodeªòõÚÊ¥
		\param element õÌı­ªÎ«Î?«ÉªË?ìıª¹ªë«Ç?«¿
		\return ãæª¿ªËõÚÊ¥ªµªìª¿«Î?«ÉªÎPosition
		\~
		*/
		inline Proud::Position AddTail( INARGTYPE element )
		{
			CNode* pNode;

			pNode = NewNode( element, m_pTail, NULL );

			if ( m_pTail != NULL )
			{
				m_pTail->m_pNext = pNode;
			}
			else
			{
				m_pHead = pNode;
			}
			m_pTail = pNode;

			return( Proud::Position( pNode ) );
		}

		/**
		\~korean
		ListÀÇ ¸¶Áö¸·³ëµå¿¡ »õ·Î¿î List¸¦ Ãß°¡
		\param plNew Ãß°¡ÇÒ List

		\~english 
		A new list is added to the last node of the list
		\param plNew List to be added 

		\~chinese
		èÙlistîÜõÌı¨?ïÃôÕÊ¥ãæîÜlist¡£
		\param plNew é©ôÕÊ¥îÜlist¡£

		\~japanese
		ListªÎõÌı­«Î?«ÉªËãæª·ª¤«ê«¹«ÈªòõÚÊ¥
		\param plNew õÚÊ¥ª¹ªëList
		\~
		*/
		inline void AddTailList( const CFastList* plNew )
		{
			assert( plNew != NULL );

			Proud::Position pos = plNew->GetHeadPosition();
			while ( pos != NULL )
			{
				INARGTYPE element = plNew->GetNext( pos );
				AddTail( element );
			}
		}

		/**
		\~korean
		¸ğµç µ¥ÀÌÅÍ¸¦ Á¦°Å. Clear()¿Í °°À½.

		\~english 
		Delete all data. Same as Clear()

		\~chinese
		?ğ¶á¶êó?Ëß¡£?Clear()ìé?¡£

		\~japanese
		îïªÆªÎ«Ç?«¿ªòğ¶ËÛ¡£ Clear()ªÈÔÒª¸ªÇª¹¡£
		\~
		*/
		inline void RemoveAll() throw()
		{
			while ( m_nElements > 0 )
			{
				CNode* pKill = m_pHead;
				assert( pKill != NULL );

				m_pHead = m_pHead->m_pNext;
				FreeNode( pKill );
			}

			assert( m_nElements == 0 );
			m_pHead = NULL;
			m_pTail = NULL;
		}

		/**
		\~korean
		¸ğµç µ¥ÀÌÅÍ¸¦ Á¦°Å.RemoveAll()°°À½.

		\~english 
		Delete all data. Same as RemoveAll()

		\~chinese
		?ğ¶á¶êó?Ëß¡£?RemoveAll()ìé?¡£

		\~japanese
		îïªÆªÎ«Ç?«¿ªòğ¶ËÛ¡£RemoveAll()ªÈÔÒª¸ªÇª¹¡£
		\~
		*/
		inline void Clear() { RemoveAll(); }

		/**
		\~korean
		\return Çì´õÀÇ PositionÀ» ¸®ÅÏ

		\~english 
		\return the position of the header.

		\~chinese
		\return Ú÷üŞheaderîÜPosition¡£

		\~japanese
		\return «Ø«Ã«À?ªÎPositionªò«ê«¿?«ó
		\~
		*/
		inline Proud::Position GetHeadPosition() const throw()
		{
			return( Proud::Position( m_pHead ) );
		}

		/**
		\~korean
		\return listÀÇ ¸¶Áö¸· ³ëµåÀÇ PositionÀ» ¸®ÅÏ

		\~english 
		\return the position of the last node of list.

		\~chinese
		\return Ú÷üŞllistîÜõÌı¨?ïÃîÜPosition¡£
		\~japanese
		\return listªÎõÌı­«Î?«ÉªÎPositionªò«ê«¿?«ó
		\~
		*/
		inline Proud::Position GetTailPosition() const throw()
		{
			return( Proud::Position( m_pTail ) );
		}

		/**
		\~korean
		ÀÎÀÚ·Î ³ÖÀº PositionÀÇ ´ÙÀ½ node PositionÀ» ¾ò´Â´Ù.
		\param pos ÇöÀç Position
		\return ´ÙÀ½ ³ëµåÀÇ Data¸¦ ¸®ÅÏ

		\~english 
		Obtain the next node position of the position inserted as a factor 
		\param pos Current position.
		\return the data of the next node.

		\~chinese
		?Ôğ?ìı?ì×í­îÜPositionñıı¨îÜnode Position¡£
		\param pos ?î¤îÜPosition¡£
		\return Ú÷üŞñıı¨?ïÃîÜdata¡£

		\~japanese
		\~
		*/
		inline E& GetNext( Proud::Position& pos )
		{
			CNode* pNode;

			assert( pos != NULL );
			pNode = (CNode*)pos;
			pos = Proud::Position( pNode->m_pNext );

			return( pNode->m_element );
		}

		/**
		\~korean
		ÀÎÀÚ·Î ³ÖÀº PositionÀÇ ´ÙÀ½ node PositionÀ» ¾ò´Â´Ù.
		\param pos ÇöÀç Position
		\return ´ÙÀ½ ³ëµåÀÇ Data¸¦ constº¯¼ö·Î ¸®ÅÏ

		\~english 
		Obtain the next node position of the position inserted as a factor
		\param pos Current position
		\return Return the data of the next node

		\~chinese
		?Ôğ?ìı?ì×í­îÜPositionñıı¨îÜnode Position¡£
		\param pos ?î¤îÜPosition¡£
		\return Ú÷üŞñıı¨?ïÃîÜdata?const??¡£

		\~japanese
		ì×í­ªÇìıªìª¿PositionªÎó­ªÎnode PositionªòÔğªŞª¹¡£
		\param pos úŞî¤ Position
		\return ó­ªÎ«Î?«ÉªÎ«Ç?«¿ªòconst??ªË«ê«¿?«ó
		\~
		*/
		inline const E& GetNext( Proud::Position& pos ) const
		{
			CNode* pNode;

			assert( pos != NULL );
			pNode = (CNode*)pos;
			pos = Proud::Position( pNode->m_pNext );

			return( pNode->m_element );
		}

		/**
		\~korean
		ÀÎÀÚ·Î ³ÖÀº PositionÀÇ Àü node PositionÀ» ¾ò´Â´Ù.
		\param pos ÇöÀç Position
		\return Àü ³ëµåÀÇ Data

		\~english 
		Obtain the previous node position of the position inserted as a factor
		\param pos Current position
		\return Data of the previous node 

		\~chinese
		ì×í­ªÇìıªìª¿PositionªÎı­ªÎnode PositionªòÔğªŞª¹¡£
		\param pos ?î¤îÜPosition¡£
		\return ñıîñ?ïÃîÜdata¡£

		\~japanese
		ì×í­ªÇìıªìª¿PositionªÎı­ªÎnode PositionªòÔğªŞª¹¡£
		\param pos úŞî¤ Position
		\return îñ«Î?«ÉªÎData
		\~
		*/
		inline E& GetPrev( Proud::Position& pos )
		{
			CNode* pNode;

			assert( pos != NULL );
			pNode = (CNode*)pos;
			pos = Proud::Position( pNode->m_pPrev );

			return( pNode->m_element );
		}

		/**
		\~korean
		ÀÎÀÚ·Î ³ÖÀº PositionÀÇ Àü node PositionÀ» ¾ò´Â´Ù.
		\param pos ÇöÀç Position
		\return Àü ³ëµåÀÇ Data¸¦ const º¯¼ö·Î ¸®ÅÏÇÑ´Ù.

		\~english 
		Obtain the previous node position of the position inserted as a factor
		\param pos Current position 
		\return Return the data of the previous node as a const variable 

		\~chinese
		?Ôğ?ìı?ì×í­îÜPositionñıîñîÜnode Position¡£
		\param pos ?î¤îÜPosition¡£
		\return Ú÷üŞñıîñ?ïÃîÜdata?const??¡£

		\~japanese
		ì×í­ªÇìıªìª¿PositionªÎı­ªÎnode PositionªòÔğªŞª¹¡£
		\param pos úŞî¤ Position
		\return îñ«Î?«ÉªÎ«Ç?«¿ªòconst ??ªË«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		inline const E& GetPrev( Proud::Position& pos ) const throw()
		{
			CNode* pNode;

			assert( pos != NULL );
			pNode = (CNode*)pos;
			pos = Proud::Position( pNode->m_pPrev );

			return( pNode->m_element );
		}

		/**
		\~korean
		ÇöÀç ³ëµåÀÇ Data ¸¦ ¾ò´Â´Ù.
		\param pos ÇöÀç ³ëµåÀÇ Position
		\return ÇöÀç ³ëµåÀÇ Data

		\~english 
		Obtain the data of the current node 
		\param pos Position of the current node
		\return Data of the current node 

		\~chinese
		?Ôğ?î¤?ïÃîÜdata¡£
		\param pos ?î¤?ïÃîÜPosition¡£
		\return ?î¤?ïÃîÜdata¡£

		\~japanese
		úŞî¤«Î?«ÉªÎ«Ç?«¿ªòÔğªŞª¹¡£
		\param pos úŞî¤«Î?«ÉªÎPosition
		\return úŞî¤«Î?«ÉªÎData
		\~
		*/
		inline E& GetAt( Proud::Position pos )
		{
			assert( pos != NULL );
			CNode* pNode = (CNode*)pos;
			return( pNode->m_element );
		}

		/**
		\~korean
		ÇöÀç ³ëµåÀÇ Data ¸¦ const º¯¼ö·Î ¾ò´Â´Ù.
		\param pos ÇöÀç ³ëµåÀÇ Position
		\return ÇöÀç ³ëµåÀÇ DataÀÇ const º¯¼ö ¸®ÅÏ

		\~english 
		Obtain the data of the current node as a const variable
		\param pos Position of the current node 
		\return Return the const variable of the current node data

		\~chinese
		?Ôğ?î¤?ïÃîÜdata?const??¡£
		\param pos ?î¤?ïÃîÜPosition¡£
		\return Ú÷üŞ?î¤?ïÃîÜdata?const??¡£

		\~japanese
		úŞî¤«Î?«ÉªÎ«Ç?«¿ªòconst??ª«ªéÔğªë¡£
		\param pos úŞî¤«Î?«ÉªÎ Position
		\return úŞî¤«Î?«ÉªÎ«Ç?«¿ªÎconst??ªò«ê«¿?«ó
		\~
		*/
		inline const E& GetAt( Proud::Position pos ) const
		{
			assert( pos != NULL );
			CNode* pNode = (CNode*)pos;
			return( pNode->m_element );
		}

		/**
		\~korean
		ÇöÀç PositionÀÌ °¡¸®Å°´Â ³ëµåÀÇ Data¸¦ ¼¼ÆÃÇÑ´Ù.
		\param pos ÇöÀç ³ëµåÀÇ Position
		\param element ¼¼ÆÃÇÒ data

		\~english 
		Configure the data of the node pointed by the current position
		\param pos Position of the current node 
		\param element Data to be configured 

		\~chinese
		?öÇ?î¤Positioná¶ò¦?ïÃîÜdata¡£
		\param pos ?î¤?ïÃîÜPosition¡£
		\return é©?öÇîÜdata¡£


		\~japanese
		úŞî¤Positionª¬ò¦ª¹«Î?«ÉªÎ«Ç?«¿ªòàâïÒª·ªŞª¹¡£
		\param pos úŞî¤«Î?«ÉªÎ Position
		\param element àâïÒª¹ªë«Ç?«¿
		\~
		*/
		inline void SetAt( Proud::Position pos, INARGTYPE element )
		{
			assert( pos != NULL );
			CNode* pNode = (CNode*)pos;
			pNode->m_element = element;
		}

		/**
		\~korean
		ÇöÀç PositionÀÌ °¡¸£Å°´Â node ¸¦ Á¦°ÅÇÏ°í ´ÙÀ½ PositionÀ» ¸®ÅÏÇØ ÁØ´Ù.
		\param pos Á¦°ÅÇÏ°íÀÚ ÇÏ´Â nodeÀÇ Position
		\return Á¦°ÅµÈ PositionÀÇ ´ÙÀ½ Position

		\~english 
		Delete the node pointed by the current position and then return the next position
		\param pos Position of the node to be deleted
		\return Next position of the deleted position 

		\~chinese
		?ğ¶?î¤Positioná¶ò¦îÜnode£¬Ú÷üŞñıı¨Position¡£
		\param pos ßÌ?ğ¶îÜnodeîÜPosition¡£
		\return ù¬?ğ¶îÜPositionîÜñıı¨Position¡£


		\~japanese
		úŞî¤Positionª¬ò¦ª¹«Î?«Éªòğ¶ËÛª·ªÆó­ªÎPositionªò«ê«¿?«óª·ªŞª¹¡£
		\param pos ğ¶ËÛª·ª¿ª¤«Î?«ÉªÎ Position
		\return ğ¶ËÛªµªìª¿PositionªÎó­ªÎPosition
		\~
		*/
		inline Proud::Position RemoveAt( Proud::Position pos ) throw()
		{
			Proud::Position newPos = pos;

			GetNext(newPos);  // ´ÙÀ½ À§Ä¡¸¦ ¹Ì¸® ¾ò¾îµĞ´Ù.
			assert( pos != NULL );

			CNode* pOldNode = (CNode*)pos;

			// remove pOldNode from list
			if ( pOldNode == m_pHead )
			{
				m_pHead = pOldNode->m_pNext;
			}
			else
			{
#if defined(_WIN32)
				assert( AtlIsValidAddress( pOldNode->m_pPrev, sizeof(CNode) ));
#endif
				pOldNode->m_pPrev->m_pNext = pOldNode->m_pNext;
			}
			if ( pOldNode == m_pTail )
			{
				m_pTail = pOldNode->m_pPrev;
			}
			else
			{
#if defined(_WIN32)
				assert( AtlIsValidAddress( pOldNode->m_pNext, sizeof(CNode) ));
#endif
				pOldNode->m_pNext->m_pPrev = pOldNode->m_pPrev;
			}
			FreeNode( pOldNode );

			return newPos;
		}

		/**
		\~korean
		ÇöÀç PositionÀÌ °¡¸®Å°´Â nodeÀÇ ¾Õ¿¡ »õ·Î¿î node¸¦ Ãß°¡ÇÑ´Ù.
		\param pos ÇöÀç node¸¦ °¡¸®Å°´Â Position
		\param element Ãß°¡ÇÒ »õ ³ëµåÀÇ Data

		\~english 
		Add a new node in front of the node pointed by the current position 
		\param pos Position pointing the current node 
		\param element Data of the new node to be added 

		\~chinese
		èÙ?î¤Positioná¶ò¦îÜnodeîñØüôÕÊ¥ãæîÜnode¡£
		\param pos ò¦ú¾?î¤nodeîÜPosition¡£
		\param element é©ôÕÊ¥îÜãæ?ïÃîÜdata¡£

		\~japanese
		úŞî¤Positionª¬ò¦ª¹«Î?«ÉªÎîñªËãæª·ª¤«Î?«ÉªòõÚÊ¥ª·ªŞª¹¡£
		\param pos úŞî¤«Î?«Éªòò¦ª¹Position
		\param element õÚÊ¥ª¹ªëãæª·ª¤«Î?«ÉªÎ«Ç?«¿
		
		\~
		*/
		inline Proud::Position InsertBefore( Proud::Position pos, INARGTYPE element )
		{
#if defined(_WIN32)
			ATLASSERT_VALID(this);
#endif

			if ( pos == NULL )
				return AddHead( element ); // insert before nothing -> head of the list

			// Insert it before position
			CNode* pOldNode = (CNode*)pos;
			CNode* pNewNode = NewNode( element, pOldNode->m_pPrev, pOldNode );

			if ( pOldNode->m_pPrev != NULL )
			{
#if defined(_WIN32)
				assert(AtlIsValidAddress(pOldNode->m_pPrev, sizeof(CNode)));
#endif
				pOldNode->m_pPrev->m_pNext = pNewNode;
			}
			else
			{
				assert( pOldNode == m_pHead );
				m_pHead = pNewNode;
			}
			pOldNode->m_pPrev = pNewNode;

			return( Proud::Position( pNewNode ) );
		}

		/**
		\~korean
		ÇöÀç PositionÀÌ °¡¸®Å°´Â nodeÀÇ µÚ¿¡ »õ·Î¿î node¸¦ Ãß°¡ÇÑ´Ù.
		\param pos ÇöÀç node¸¦ °¡¸®Å°´Â Position
		\param element Ãß°¡ÇÒ »õ ³ëµåÀÇ Data

		\~english 
		Add a new node behind the node pointed by the current position 
		\param pos Position pointing the current node 
		\param element Data of the new node to be added 

		\~chinese
		èÙ?î¤Positioná¶ò¦îÜnodeı¨ØüôÕÊ¥ãæîÜnode¡£
		\param pos ò¦ú¾?î¤nodeîÜPosition¡£
		\param element é©ôÕÊ¥îÜãæ?ïÃîÜdata¡£

		\~japanese
		úŞî¤Positionª¬ò¦ª¹«Î?«ÉªÎı­ªËãæª·ª¤«Î?«ÉªòõÚÊ¥ª·ªŞª¹¡£
		\param pos úŞî¤«Î?«Éªòò¦ª¹Position
		\param element õÚÊ¥ª¹ªëãæª·ª¤«Î?«ÉªÎ«Ç?«¿
		\~
		*/
		inline Proud::Position InsertAfter( Proud::Position pos, INARGTYPE element )
		{
#ifdef _WIN32
			ATLASSERT_VALID(this);
#endif // _WIN32

			if ( pos == NULL )
				return AddTail( element ); // insert after nothing -> tail of the list

			// Insert it after position
			CNode* pOldNode = (CNode*)pos;
			CNode* pNewNode = NewNode( element, pOldNode, pOldNode->m_pNext );

			if ( pOldNode->m_pNext != NULL )
			{
				assert(AtlIsValidAddress(pOldNode->m_pNext, sizeof(CNode)));
				pOldNode->m_pNext->m_pPrev = pNewNode;
			}
			else
			{
				assert( pOldNode == m_pTail );
				m_pTail = pNewNode;
			}
			pOldNode->m_pNext = pNewNode;

			return( Proud::Position( pNewNode ) );
		}

		/**
		\~korean
		Data·Î node¸¦ Ã£´Â´Ù.
		\param element Ã£À» nodeÀÇ data
		\param posStartAfter ÀÌ PositionÀÌÈÄºÎÅÍ ºñ±³ÇÏ¿© Ã£´Â´Ù.

		\~english 
		Find a node with data
		\param element Data of the node to be searched for
		\param posStartAfter Search by comparing after this position

		\~chinese
		ì¤data??node¡£
		\param element é©?îÜnodeîÜdata¡£
		\param posStartAfter ???Positionñıı¨?ã·İï???¡£

		\~japanese
		«Ç?«¿ªÇ«Î?«Éªò÷®ª·ªŞª¹¡£
		\param element ÷®ª¹«Î?«ÉªÎ«Ç?«¿
		\param posStartAfter ª³ªÎPositionì¤Ë½ª«ªéİïÎòª·ªÆ÷®ª·ªŞª¹¡£
		\~
		*/
		inline Proud::Position Find( INARGTYPE element, Proud::Position posStartAfter = NULL ) const throw()
		{
#ifdef _WIN32
			ATLASSERT_VALID(this);
#endif // _WIN32

			CNode* pNode = (CNode*)posStartAfter;
			if ( pNode == NULL )
			{
				pNode = m_pHead;  // start at head
			}
			else
			{
#ifdef _WIN32
				assert(AtlIsValidAddress(pNode, sizeof(CNode)));
#endif
				pNode = pNode->m_pNext;  // start after the one specified
			}

			for ( ; pNode != NULL; pNode = pNode->m_pNext )
			{
				if ( ETraits::CompareElements( pNode->m_element, element ) )
					return( Proud::Position( pNode ) );
			}

			return( NULL );
		}

		/**
		\~korean
		Çì´õ·Î ºÎÅÍ iElement°¹¼ö ¸¸Å­ÀÇ ´ÙÀ½ nodeÀÇ PositionÀ» ¸®ÅÏ
		\param iElement ´ÙÀ½À¸·Î ³Ñ¾î°¥ ³ëµåÀÇ °¹¼ö
		\return nodeÀÇ Position

		\~english 
		Return the position of the next node for the number if iElement from the header 
		\param iElement Number of the node to be passed after iElement
		\return Position of node

		\~chinese
		Ú÷üŞ?header?ã·ßÓ?éÍiElement??ñıı¨nodeîÜPosition¡£
		\param iElement é©Ô¯?ËÛîÜ?ïÃîÜ??¡£
		\return nodeîÜPosition¡£

		\~japanese
		«Ø«Ã«À?ª«ªéiElement?ªÀª±ªÎó­ªÎ«Î?«ÉªÎPositionªò«ê«¿?«ó
		\param iElement ó­ªËêÆª¨ªë«Î?«ÉªÎ?
		\return nodeªÎPosition
		\~
		*/
		inline Proud::Position FindIndex( intptr_t iElement ) const throw()
		{
#ifdef _WIN32
			ATLASSERT_VALID(this);
#endif // _WIN32

			if ( iElement >= m_nElements )
				return NULL;  // went too far

			if (m_pHead == NULL)
				return NULL;

			CNode* pNode = m_pHead;
			for ( intptr_t iSearch = 0; iSearch < iElement; iSearch++ )
			{
				pNode = pNode->m_pNext;
			}

			return( Proud::Position( pNode ) );
		}

		/**
		\~korean
		ÇöÀç PositionÀÌ °¡¸®Å°´Â node¸¦ listÀÇ Ã³À½À¸·Î º¸³½´Ù.
		\param pos ÇöÀç nodeÀÇ Position

		\~english 
		Send the node pointed by the current position to the beginning of the list 
		\param pos Position of the current node 

		\~chinese
		÷ê?î¤îÜPositioná¶ò¦îÜnode?áêÓğlistîÜõÌîñØü¡£
		\param pos ?î¤nodeîÜPosition¡£

		\~japanese
		úŞî¤Positionª¬ò¦ª¹«Î?«Éªò«ê«¹«ÈªÎõÌôøªØáêªêªŞª¹¡£
		\param pos úŞî¤«Î?«ÉªÎPosition
		\~
		*/
		inline void MoveToHead( Proud::Position pos )
		{
			assert( pos != NULL );

			CNode* pNode = static_cast< CNode* >( pos );

			if ( pNode == m_pHead )
			{
				// Already at the head
				return;
			}

			if ( pNode->m_pNext == NULL )
			{
				assert( pNode == m_pTail );
				m_pTail = pNode->m_pPrev;
			}
			else
			{
				pNode->m_pNext->m_pPrev = pNode->m_pPrev;
			}

			assert( pNode->m_pPrev != NULL );  // This node can't be the head, since we already checked that case
			pNode->m_pPrev->m_pNext = pNode->m_pNext;

			m_pHead->m_pPrev = pNode;
			pNode->m_pNext = m_pHead;
			pNode->m_pPrev = NULL;
			m_pHead = pNode;
		}

		/**
		\~korean
		ÇöÀç PositionÀÌ °¡¸®Å°´Â node¸¦ listÀÇ ¸¶Áö¸·À¸·Î º¸³½´Ù.
		\param pos ÇöÀç nodeÀÇ Position

		\~english 
		Send the node pointed by the current position to the end of the list 
		\param pos Position of the current node 

		\~chinese
		÷ê?î¤Positioná¶ò¦îÜnode?áêîÜlistîÜõÌı¨¡£
		\param pos ?î¤nodeîÜPosition¡£

		\~japanese
		úŞî¤Positionª¬ò¦ª¹«Î?«Éªò«ê«¹«ÈªÎõÌı­ªØáêªêªŞª¹¡£
		\param pos úŞî¤«Î?«ÉªÎPosition
		\~
		*/
		inline void MoveToTail( Proud::Position pos )
		{
			assert( pos != NULL );
			CNode* pNode = static_cast< CNode* >( pos );

			if ( pNode == m_pTail )
			{
				// Already at the tail
				return;
			}

			if ( pNode->m_pPrev == NULL )
			{
				assert( pNode == m_pHead );
				m_pHead = pNode->m_pNext;
			}
			else
			{
				pNode->m_pPrev->m_pNext = pNode->m_pNext;
			}

			pNode->m_pNext->m_pPrev = pNode->m_pPrev;

			m_pTail->m_pNext = pNode;
			pNode->m_pPrev = m_pTail;
			pNode->m_pNext = NULL;
			m_pTail = pNode;
		}

		/**
		\~korean
		µÎ ³ëµåÀÇ À§Ä¡¸¦ ¹Ù²Û´Ù. Elenemt¸¦ Á÷Á¢ SwapÇØÁÖ°ÔµÇ¸é Å« ³¶ºñ°¡ ÀÖÀ» ¼ö ÀÖÀ½À¸·Î µÎ ³ëµå¿¡ ÇØ´ç Æ÷ÀÎÅÍ µéÀ» ¹Ù²Ù¾îÁØ´Ù.
		\param pos1 ¹Ù²Ü Ã¹¹øÂ° nodeÀÇ Position
		\param pos2 ¹Ù²Ü µÎ¹øÂ° nodeÀÇ Position

		\~english 
		Switch the position of the two nodes. As a big waste may occur if you directly swap the elements so you change the relevant pointers of the two nodes. 
		\param pos1 Position of the first node to be changed 
		\param pos2 Position of the second node to be changed

		\~chinese
		Îß????ïÃîÜêÈöÇ¡£åıÍıòÁïÈSwap ElenemtîÜ?£¬?à÷??ÓŞÕÈ?£¬Îß???ßÓ??ïÃîÜò¦?¡£
		\param pos1 Îß?îÜğ¯ìé?nodeîÜPosition¡£
		\param pos2 Îß?îÜğ¯ì£?nodeîÜPosition¡£

		\~japanese
		?«Î?«ÉªÎêÈöÇªò?ª¨ªŞª¹¡£ElementªòòÁïÈSwapª¹ªëªÈÙí?Ìºª¤ªËªÊªìªŞª¹ªÎªÇ¡¢?«Î?«ÉªËú±?«İ«¤«ó«¿?ªò?ª¨ªÆª¯ªìªŞª¹¡£
		\param pos1 ?ª¨ªëõÌôø«Î?«ÉªÎPosition
		\param pos2 ?ª¨ªë2ÛãÙÍ«Î?«ÉªÎPosition
		\~
		*/
		void SwapElements( Proud::Position pos1, Proud::Position pos2 ) throw()
		{
			assert( pos1 != NULL );
			assert( pos2 != NULL );

			if ( pos1 == pos2 )
			{
				// Nothing to do
				return;
			}

			CNode* pNode1 = static_cast< CNode* >( pos1 );
			CNode* pNode2 = static_cast< CNode* >( pos2 );
			if ( pNode2->m_pNext == pNode1 )
			{
				// Swap pNode2 and pNode1 so that the next case works
				CNode* pNodeTemp = pNode1;
				pNode1 = pNode2;
				pNode2 = pNodeTemp;
			}
			if ( pNode1->m_pNext == pNode2 )
			{
				// Node1 and Node2 are adjacent
				pNode2->m_pPrev = pNode1->m_pPrev;
				if ( pNode1->m_pPrev != NULL )
				{
					pNode1->m_pPrev->m_pNext = pNode2;
				}
				else
				{
					assert( m_pHead == pNode1 );
					m_pHead = pNode2;
				}
				pNode1->m_pNext = pNode2->m_pNext;
				if ( pNode2->m_pNext != NULL )
				{
					pNode2->m_pNext->m_pPrev = pNode1;
				}
				else
				{
					assert( m_pTail == pNode2 );
					m_pTail = pNode1;
				}
				pNode2->m_pNext = pNode1;
				pNode1->m_pPrev = pNode2;
			}
			else
			{
				// The two nodes are not adjacent
				CNode* pNodeTemp;

				pNodeTemp = pNode1->m_pPrev;
				pNode1->m_pPrev = pNode2->m_pPrev;
				pNode2->m_pPrev = pNodeTemp;

				pNodeTemp = pNode1->m_pNext;
				pNode1->m_pNext = pNode2->m_pNext;
				pNode2->m_pNext = pNodeTemp;

				if ( pNode1->m_pNext != NULL )
				{
					pNode1->m_pNext->m_pPrev = pNode1;
				}
				else
				{
					assert( m_pTail == pNode2 );
					m_pTail = pNode1;
				}
				if ( pNode1->m_pPrev != NULL )
				{
					pNode1->m_pPrev->m_pNext = pNode1;
				}
				else
				{
					assert( m_pHead == pNode2 );
					m_pHead = pNode1;
				}
				if ( pNode2->m_pNext != NULL )
				{
					pNode2->m_pNext->m_pPrev = pNode2;
				}
				else
				{
					assert( m_pTail == pNode1 );
					m_pTail = pNode2;
				}
				if ( pNode2->m_pPrev != NULL )
				{
					pNode2->m_pPrev->m_pNext = pNode2;
				}
				else
				{
					assert( m_pHead == pNode1 );
					m_pHead = pNode2;
				}
			}
		}

#ifdef _DEBUG
		void AssertValid() const
		{
			if ( IsEmpty() )
			{
				// empty list
				assert(m_pHead == NULL);
				assert(m_pTail == NULL);
			}
			else
			{
				// ¸Ş¸ğ¸®¸¦ ±Ü´ÂÁö ½ÃÇèÇÑ´Ù.
				CNode* node = m_pHead;
				while(node!=NULL)
				{
					node = node->m_pNext;
				}
				// non-empty list
				// 		assert(AtlIsValidAddress(m_pHead, sizeof(CNode)));
				// 		assert(AtlIsValidAddress(m_pTail, sizeof(CNode)));
			}
		}

#endif  // _DEBUG

		// Implementation
	private:
		CNode* m_pHead;
		CNode* m_pTail;
		intptr_t m_nElements;

	private:
		inline CNode* NewNode( CNode* pPrev, CNode* pNext )
		{
			CNode* ret = (CNode*)CProcHeap::Alloc(sizeof(CNode));
			if(ret == NULL)
				ThrowBadAllocException();

			CallConstructor<CNode>(ret);

			ret->m_pPrev = pPrev;
			ret->m_pNext = pNext;

			m_nElements++;

			return ret;
		}
		inline CNode* NewNode( INARGTYPE element, CNode* pPrev, CNode* pNext )
		{
			CNode* ret = (CNode*)CProcHeap::Alloc(sizeof(CNode));
			if(ret == NULL)
				ThrowBadAllocException();

			CallConstructor<CNode>(ret, element);

			ret->m_pPrev = pPrev;
			ret->m_pNext = pNext;

			m_nElements++;

			return ret;
		}

		inline void FreeNode( CNode* pNode ) throw()
		{
			CallDestructor<CNode>(pNode);

				CProcHeap::Free(pNode);
			m_nElements--;
		}

	public:
		inline ~CFastList() throw()
		{
			RemoveAll();
			assert( m_nElements == 0 );
		}

	private:
		// Private to prevent use
		CFastList( const CFastList& ) throw();
		CFastList& operator=( const CFastList& ) throw();

	public:

		class value_type
		{
		public:
			Proud::Position m_pos;
			CFastList* m_owner;
		};

		class iterator;
		friend class iterator;

#ifndef PROUDNET_NO_CONST_ITERATOR
		class const_iterator;
		friend class const_iterator;

		/**
		\~korean
		STLÀÇ const_iterator¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs the same role as const_iterator of STL

		\~chinese
		ÑÃó·?STLîÜconst_iteratorìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎconst_iteratorªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		class const_iterator:public value_type
		{
		public:
			inline const_iterator() {}
			inline const_iterator(const iterator& src):value_type(src) {}

			inline const_iterator& operator++()
			{
				// preincrement
                value_type::m_owner->GetNext(value_type::m_pos);
				return (*this);
			}

			inline const_iterator operator++(int)
			{
				// postincrement
				const_iterator _Tmp = *this;
				++*this;
				return (_Tmp);
			}

			inline bool operator==(const const_iterator& a) const
			{
				return value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner;
			}

			inline bool operator!=(const const_iterator& a) const
			{
				return !(value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner);
			}

			inline const E& operator*() const
			{
				return value_type::m_owner->GetAt(value_type::m_pos);
			}
		};
#endif
		/**
		\~korean
		STLÀÇ iterator¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs the same role as iterator of STL

		\~chinese
		ÑÃó·?STLîÜiteratorìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎiteratorªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		class iterator:public value_type
		{
		public:
			inline iterator() {}
			inline iterator(const const_iterator& src):value_type(src) {}

			inline bool operator==(const iterator& a) const
			{
				return value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner;
			}

			inline bool operator!=(const iterator& a) const
			{
				return !(value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner);
			}

			inline iterator& operator++()
			{
				// preincrement
				value_type::m_owner->GetNext(value_type::m_pos);
				return (*this);
			}

			inline iterator operator++(int)
			{
				// postincrement
				iterator _Tmp = *this;
				++*this;
				return (_Tmp);
			}

			inline E& operator*() const
			{
				return value_type::m_owner->GetAt(value_type::m_pos);
			}
		};

		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs the same role as the same named method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline iterator begin()
		{
			iterator ret;
			ret.m_pos = GetHeadPosition();
			ret.m_owner=this;

			return ret;
		}

		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs the same role as the same named method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline iterator end()
		{
			iterator ret;
			ret.m_pos=NULL;
			ret.m_owner=this;

			return ret;
		}

#ifndef PROUDNET_NO_CONST_ITERATOR
		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs the same role as the same named method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline const_iterator begin() const
		{
			const_iterator ret;
			ret.m_pos = GetHeadPosition();
			ret.m_owner = (CFastList*)this;

			return ret;
		}

		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs the same role as the same named method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline const_iterator end() const
		{
			const_iterator ret;
			ret.m_pos=NULL;
			ret.m_owner = (CFastList*)this;

			return ret;
		}
#endif

		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs the same role as the same named method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline iterator erase(iterator iter)
		{
			if(iter.m_owner!=this)
			{
				ThrowInvalidArgumentException();
			}
			iterator ret = iter;
			ret++;
			RemoveAt(iter.m_pos);

			return ret;
		}

		/**
		\~korean
		ÇöÀç CFastList ¿Í ´Ù¸¥ CFastList ÀÇ ³»¿ëÀÌ °°ÀºÁö ºñ±³ÇÑ´Ù. Data¸¦ Á÷Á¢ ºñ±³ÇÏ¿© È®ÀÎÇÑ´Ù..
		\param rhs ºñ±³ÇÒ CFastList
		\return °°À¸¸é true ´Ù¸¥¸é false ¸®ÅÏ

		\~english 
		Compare whether the content of the current CFastList and other CFastList are the same. Directly compare the data to confirm. 
		\param rhs CFastList to be compared 
		\return True if the same, otherwise return false. 

		\~chinese
		İï??î¤îÜ CLinkedList%ûúĞìöâ CLinkedList%îÜ?é»ãÀÜúßÓÔÒ¡£òÁïÈİï?data???¡£
		\param rhs é©İï?îÜ CLinkedList%¡£
		\return ìé?îÜ?true£¬ÜôÔÒîÜ?Ú÷üŞfalse¡£

		\~japanese
		úŞî¤CFastListªÈöâªÎCFastListªÎ?é»ª¬ÔÒª¸ªÇª¢ªëª«ªÉª¦ª«ªòİïÎòª·ªŞª¹¡£«Ç?«¿ªòòÁïÈİïÎòª·ªÆü¬ìãª·ªŞª¹¡£
		\param rhs İïÎòª¹ªë CFastList
		\return ÔÒª¸ªÇª¢ªëªÈtrue¡¢êŞª¦ªÈfalseªò«ê«¿?«ó
		\~
		*/
		inline bool Equals(const CFastList& rhs) const
		{
			if(rhs.GetCount()!=GetCount())
				return false;

			Proud::Position i1=GetHeadPosition();
			Proud::Position i2=rhs.GetHeadPosition();
			while( i1!=NULL && i2!=NULL )
			{
				if(GetAt(i1)!=rhs.GetAt(i2))
					return false;
				GetNext(i1);
				rhs.GetNext(i2);
			}

			return true;
		}
	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
