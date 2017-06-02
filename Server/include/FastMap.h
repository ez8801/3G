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
#include <map>
#include "FastHeap.h"
#include "BasicTypes.h"
#include "Singleton.h"
#include "LookasideAllocator.h"
#include "FastArray.h"
#include "Enums.h"
#include "sysutil.h"
#include "Exception.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#if defined(_MSC_VER)
#pragma warning(disable:4290)
#endif

namespace Proud
{
	extern const uint32_t FastMap_primes[];

	/** \addtogroup util_group
	*  @{
	*/

	/**
	\~korean
	(Key,Value) pairÀÇ hash ¾Ë°í¸®Áò ±â¹İ map classÀÔ´Ï´Ù. »ó¼¼ÇÑ ³»¿ëÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#hash_map" >¸Ê Å¬·¡½º</a> ¿¡ ÀÖ½À´Ï´Ù.
	- CAtlMap°ú »ç¿ë¹ıÀÌ µ¿ÀÏÇÕ´Ï´Ù. ±×·¯¸é¼­µµ STL.mapÀÇ iterator ¹× ÀÏºÎ ¸Ş¼­µå¿Í µ¿ÀÏÇÏ°Ô »ç¿ëÇÒ ¼ö ÀÖ½À´Ï´Ù.
	°Ô´Ù°¡ .Net frameworkÀÇ Dictionary class¿Í °°Àº Çü½ÄÀ¸·Îµµ ¾µ ¼ö ÀÖ½À´Ï´Ù.
	- ÀÌ Å¬·¡½ºÀÇ iterator´Â STL.mapÀÇ iteratorº¸´Ù ¼º´ÉÀÌ ÈÎ¾À ºü¸¥ ¼º´ÉÀ» ³À´Ï´Ù.

	\param K Äİ·º¼ÇÀÇ Å° Å¸ÀÔ
	\param V Äİ·º¼ÇÀÇ °ª Å¸ÀÔ
	\param KTraits Äİ·º¼ÇÀÇ Å° Å¸ÀÔÀ» ´Ù·ç´Â Æ¯¼ºÀ» Á¤ÀÇÇÑ Å¬·¡½º
	\param VTraits Äİ·º¼ÇÀÇ °ª Å¸ÀÔÀ» ´Ù·ç´Â Æ¯¼ºÀ» Á¤ÀÇÇÑ Å¬·¡½º
	\param AllocT AllocType °ª Áß ÇÏ³ª

	\~english
	An hash algorithm base map class of (Key,Value) pair. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#hash_map" >Map class</a> for further detail.
	- Has very same usage as CAtlMap while still can be used same as iterator of STL.map and some methods.
	  Plus, can be used as same format as Dictionary class of .NET framework.
	- The iterator of this class performs much faster that the iterator of STL.map.

	\param K key type of collection
	\param V value tpe of collection
	\param KTraits class that defines the characteristics that handle key type of collection
	\param VTraits class that defines the characteristics that handle value type of collection

	\~chinese
	ãÀ(Key,Value) pairîÜhashß©ÛöĞñ?îÜmap class¡£???é»î¤<a target="_blank" href="http://guide.nettention.com/cpp_zh#hash_map" >Map?</a>%¡£
	- ? CAtlMap%ŞÅéÄÛ°ÛöìéöÈ¡£ì»ó¦Òö? STL.map%îÜiteratorĞàìéŞÁÛ°ÛößÓÔÒŞÅéÄ¡£Ê¥ß¾Òö?.Net framework îÜDictionary classéÄéÍßÓÔÒû¡ãÒ¡£
	- ó®?îÜiteratorİï STL.map%îÜiterator?ãÆõóÌÚöáîÜàõÒö¡£

	\param K collection key?úş¡£
	\param V collection??úş¡£
	\param KTraits ïÒ?Öõ?×âcollectionîÜkey?úşîÜ÷åàõîÜ?¡£
	\param VTraits ïÒ?Öõ?×âcollectionîÜ??úşîÜ÷åàõîÜ?¡£
	\param AllocT AllocType?ñéñıìé¡£

	\~japanese
	(Key,Value) pairªÎhash«¢«ë«´«ê«º«àĞñ÷ùªÎmap classªÇª¹¡£ßÙª·ª¯ªÏ¡¢\ref hash_mapªËª¢ªêªŞª¹¡£
	- CAtlMapªÈŞÅéÄÛöª¬ÔÒª¸ªÇª¹¡£ª·ª«ª·¡¢STL.mapªÎiteratorĞàªÓìéİ»ªÎ«á«½«Ã«ÉªÈÔÒìéªËŞÅéÄª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
	ªµªéªË.Net frameworkªÎDictionary classªÈÔÒª¸û¡ãÒªÇªâŞÅª¨ªŞª¹¡£
	- ª³ªÎ«¯«é«¹ªÎiteratorªÏSTL.mapªÎiteratorªèªêàõÒöª¬ªâªÃªÈáÜª¤ªÇª¹¡£
	\param K «³«ì«¯«·«ç«óªÎ«­?«¿«¤«×
	\param V «³«ì«¯«·«ç«óªÎ«­?«¿«¤«×
	\param KTraits «³«ì«¯«·«ç«óªÎ«­?«¿«¤«×ªòĞâª¦÷åàõªòïÒëùª·ª¿«¯«é«¹
	\param VTraits «³«ì«¯«·«ç«óªÎ«­?«¿«¤«×ªòĞâª¦÷åàõªòïÒëùª·ª¿«¯«é«¹
	\param AllocT AllocType ö·ªÎìéªÄ

	\~

	example code of traits class

	\code

	class Foo
	{
		public:
		string a;
		int b;
	};

	class FooTraits
	{
	public:
		// returns hash value of element
		uint32_t Hash(const Foo& v)
		{
			// regularily, variables are XORed for hashing values.
			return Hash(v.a) ^ Hash(v.b);
		}

		// true if two values are the same
		inline static bool CompareElements(const Foo& e1, const Foo& e2)
		{
			return e1.a == e2.a && e1.b == e2.b;
		}

		// negative value if left is smaller.
		// zero if the same.
		// positive value if left is larger.
		inline static int CompareElementsOrdered(const Foo& e1, const Foo& e2)
		{
			if (e1.a < e2.a)
				return -1;
			if (e1.a > e2.a)
				return 1;
			else
			{
				return e1.b - e2.b;
			}
		}
	};

	CFastMap<Foo, int, FooTraits> fooToIntMap;

	\endcode

	*/
	template < typename K, typename V, typename KTraits = CPNElementTraits< K >, typename VTraits = CPNElementTraits< V > >
	class CFastMap
	{
	public:
#ifndef PROUDNET_NO_CONST_ITERATOR
		class const_iterator;
		friend class const_iterator;
#endif
		typedef typename KTraits::INARGTYPE KINARGTYPE;
		typedef typename KTraits::OUTARGTYPE KOUTARGTYPE;
		typedef typename VTraits::INARGTYPE VINARGTYPE;
		typedef typename VTraits::OUTARGTYPE VOUTARGTYPE;
		typedef typename CFastMap<K,V>::const_iterator ConstIterType;
	public:
		class CPair : public __Position
		{
		protected:
			inline CPair(KINARGTYPE key) :
				 m_key( key )
				 {
				 }
		private:
			inline CPair& operator =(const CPair&);

		public:
			K m_key;
			V m_value;

		};

	private:
		class CNode :
			public CPair
		{
		public:
			inline CNode( KINARGTYPE key ) :
				CPair( key )
			{
				m_pNext = NULL;
				m_pPrev = NULL;
			}
			inline ~CNode()
			{

			}

		private:
			inline const CNode& operator =(const CNode&);

		public:
			// bin³»ÀÇ ¸¶Áö¸· nodeÀÎ °æ¿ì next´Â ´Ù¸¥ binÀÇ head node¸¦ °¡¸®Å²´Ù.  next=NULLÀÎ °æ¿ì ÀÌ node´Â last binÀÇ last nodeÀÌ´Ù.
			// prev´Â nextÀÇ ¹İ´ë ¿ªÇÒÀ» ÇÑ´Ù. prev = NULLÀÎ °æ¿ì, ÀÌ node´Â head binÀÇ head nodeÀÌ´Ù
			CNode *m_pNext, *m_pPrev;

			// ÀÌ nodeÀÇ hashed key °ª. rehash¸¦ ÇÒ ¶§ °úµµÇÑ hash ÇÔ¼ö »ç¿ëÀ» Àı¾àÇÏ±â À§ÇÔ.
			uint32_t m_nHash;

			// ÀÌ ³ëµå°¡ ¸î ¹øÂ° bin¿¡ µé¾î°¡ ÀÖ´Â°¡.
			// rehash¸¦ ÇÒ ¶§¸¶´Ù ¹Ù²ñ. ±× ¿Ü¿¡´Â ¾È ¹Ù²ñ.
			uint32_t m_nBin;
		};
	private:
		bool m_enableSlowConsistCheck;
		// hash table. ¹è¿­ÀÇ N¹øÂ° Ç×¸ñÀº hash % bin size°¡ NÀÎ °³Ã¼µéÀÇ linked list headÀÌ´Ù.
		// ÇÒ´ç/ÇØÁ¦½Ã ProudNet DLL½Ã ·±Å¸ÀÓ ¿À·ù¸¦ ÇÇÇÏ±â À§ÇØ CFirstHeapÀ» ¾´´Ù.
		CNode** m_ppBins;

		// °¢ binÀÇ head node´Â ´Ù¸¥ binÀÇ tail nodeÀÌ´Ù. ÀÌ º¯¼ö´Â head bin, Áï ´Ù¸¥ binÀÇ tail nodeÀÇ ´ÙÀ½ÀÌ ¾Æ´Ñ
		// ³ëµåÀÌ´Ù. Áï iterationÀÇ ÃÖÃÊ ´ë»óÀÓÀ» ÀÇ¹ÌÇÑ´Ù.
		CNode* m_pHeadBinHead;

		// °¡Àå ¸¶Áö¸·¿¡ µé¾îÀÖ´Â Ç×¸ñ
		CNode* m_pTailBinTail;
		// ÀÌ map¿¡ ÀÖ´Â ÃÑ Ç×¸ñÀÇ °¹¼ö
		intptr_t m_nElements;

		// hash table Å©±â
		uint32_t m_nBins;

		float m_fOptimalLoad;
		float m_fLoThreshold;
		float m_fHiThreshold;
		intptr_t m_nHiRehashThreshold;
		intptr_t m_nLoRehashThreshold;
		uint32_t m_nLockCount;

		CFastHeap* m_refHeap;
	private:
		void InitVars( uint32_t nBins, float fOptimalLoad, float fLoThreshold, float fHiThreshold )
		{
			m_ppBins= NULL;
			m_pHeadBinHead=NULL;
			m_pTailBinTail = NULL;
			m_nBins=nBins ;
			m_nElements= 0 ;
			m_nLockCount=0;  // Start unlocked
			m_fOptimalLoad= fOptimalLoad ;
			m_fLoThreshold= fLoThreshold ;
			m_fHiThreshold= fHiThreshold ;
			m_nHiRehashThreshold= UINT_MAX ;
			m_nLoRehashThreshold= 0 ;

			SetOptimalLoad( fOptimalLoad, fLoThreshold, fHiThreshold, false );
		}

	public:
		/**
		\~korean
		»ı¼ºÀÚÀÔ´Ï´Ù.

		\param nBins ±âº» ÇØ½Ã Å×ÀÌºíÀÇ Å©±âÀÔ´Ï´Ù. ¼Ú¼ö·Î ¼³Á¤ÇØ¾ß Á¦ ¼º´ÉÀ» ³À´Ï´Ù. »ó¼¼ÇÑ ³»¿ëÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#hash_map" >¸Ê Å¬·¡½º</a> ¿¡ ÀÖ½À´Ï´Ù.
		\param fOptimalLoad ÃÖÀû ºÎÇÏ ºñÀ²ÀÔ´Ï´Ù. »ó¼¼ÇÑ ³»¿ëÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#hash_map_load" >¸Ê Å¬·¡½ºÀÇ ºÎÇÏ</a> ¿¡ ÀÖ½À´Ï´Ù.
		\param fLoThreshold ÃÖ¼Ò ºÎÇÏ ºñÀ²ÀÔ´Ï´Ù. »ó¼¼ÇÑ ³»¿ëÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#hash_map_load" >¸Ê Å¬·¡½ºÀÇ ºÎÇÏ</a> ¿¡ ÀÖ½À´Ï´Ù.
		\param fHiThreshold ÃÖ´ë ºÎÇÏ ºñÀ²ÀÔ´Ï´Ù. »ó¼¼ÇÑ ³»¿ëÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#hash_map_load" >¸Ê Å¬·¡½ºÀÇ ºÎÇÏ</a> ¿¡ ÀÖ½À´Ï´Ù.

		\~english
		This is constructor

		\param nBins The size of base hash table. Performs ok when set with prime number. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#hash_map" >Map class</a> for further detail.
		\param fOptimalLoad Optimized load proportion. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#hash_map_load" >Load of map class</a> for further detail.
		\param fLoThreshold Minimum load proportion. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#hash_map_load" >Load of map class</a> for further detail.
		\param fHiThreshold Maximum load proportion. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#hash_map_load" >Load of map class</a> for further detail.

		\~chinese
		ãÀßæà÷íº¡£

		\param nBins ãÀĞñÜâhash tableîÜÓŞá³¡£?öÇ?áÈ?î¦Òö???îÜàõÒö¡£???é»î¤<a target="_blank" href="http://guide.nettention.com/cpp_zh#hash_map" >Map ?îÜ?ùÃ</a>%¡£
		\param fOptimalLoad õÌÊ¢?ùÃİïáã¡£???é»î¤ <a target="_blank" href="http://guide.nettention.com/cpp_zh#hash_map_load" >Map ?îÜ?ùÃ</a> %¡£
		\param fLoThreshold õÌá³?ùÃİïáã¡£???é»î¤ <a target="_blank" href="http://guide.nettention.com/cpp_zh#hash_map_load" >Map ?îÜ?ùÃ</a> %¡£
		\param fHiThreshold õÌÓŞ?ùÃİïáã¡£???é»î¤ <a target="_blank" href="http://guide.nettention.com/cpp_zh#hash_map_load" >Map ?îÜ?ùÃ</a> %¡£

		\~japanese
		ßæà÷í­ªÇª¹¡£
		\param nBins ĞñÜâ«Ï«Ã«·«å«Æ?«Ö«ëªÎ«µ«¤«ºªÇª¹¡£á³?ªÇàâïÒª·ªÊª±ªìªĞàõÒöªòä¨İÂ?ıÆªÇª­ªŞª»ªó¡£ßÙª·ª¯ªÏ¡¢\ref hash_mapªòª´?ğÎª¯ªÀªµª¤¡£
		\param fOptimalLoad õÌîêİ¶ùÃİïáãªÇª¹¡£ßÙª·ª¯ªÏ¡¢\ref hash_map_loadªòª´?ğÎª¯ªÀªµª¤¡£
		\param fLoThreshold õÌá³İ¶ùÃİïáãªÇª¹¡£ßÙª·ª¯ªÏ¡¢\ref hash_map_loadªòª´?ğÎª¯ªÀªµª¤¡£
		\param fHiThreshold õÌÓŞİ¶ùÃİïáãªÇª¹¡£ßÙª·ª¯ªÏ¡¢\ref hash_map_loadªòª´?ğÎª¯ªÀªµª¤¡£

		\~
		*/
		CFastMap( uint32_t nBins = 17, float fOptimalLoad = 0.75f, float fLoThreshold = 0.25f, float fHiThreshold = 2.25f)
		{
			m_enableSlowConsistCheck = false;
			m_refHeap = NULL;

			assert( nBins > 0 );

			InitVars(nBins, fOptimalLoad, fLoThreshold, fHiThreshold);
		}

#if defined(_MSC_VER)
		/**
		\~korean
		ÀÌ¹Ì °®°í ÀÖ´Â Ç×¸ñÀÇ °¹¼ö¸¦ ±¸ÇÑ´Ù.

		\~english
		Gets number of item that already owned

		\~chinese
		Ï´ì«?êó?ÙÍîÜ?Õá¡£

		\~japanese
		?ªËò¥ªÃªÆª¤ªëú£ÙÍ?ªòÏ´ªáªŞª¹¡£
		\~
		*/
		__declspec(property(get = GetCount)) intptr_t Count;
#endif

		inline intptr_t GetCount() const throw()
		{
			return( m_nElements );
		}

		/**
		\~korean
		ÀÌ¹Ì °®°í ÀÖ´Â Ç×¸ñÀÇ °¹¼ö¸¦ ±¸ÇÑ´Ù.

		\~english
		Gets number of item that already owned

		\~chinese
		Ï´ì«?êó?ÙÍîÜ?Õá¡£

		\~japanese
		?ªËò¥ªÃªÆª¤ªëú£ÙÍ?ªòÏ´ªáªŞª¹¡£
		\~
		*/
		inline intptr_t size() const
		{
			return GetCount();
		}

		/**
		\~korean
		ÅÖºó »óÅÂÀÎ°¡?

		\~english
		Is it empty?

		\~chinese
		ãÀÜú?Íö£¿

		\~japanese
		Íöª­?÷¾ªÇª¹ª«£¿
		\~
		*/
		inline bool IsEmpty() const throw()
		{
			return( m_nElements == 0 );
		}

		/**
		\~korean
		key¿¡ ´ëÀÀÇÏ´Â value¸¦ ¾ò´Â´Ù.
		\param [in] key Ã£À» Å°
		\param [out] value Ã£Àº Å°¿¡ ´ëÀÀÇÏ´Â °ªÀÌ ÀúÀåµÉ °÷
		\return key¸¦ Ã£¾ÒÀ¸¸é true¸¦ ¸®ÅÏÇÑ´Ù.

		\~english
		Gets value correspnds to key
		\param [in] key key to find
		\param [out] value a space where the value corresponds to the key found to be stored
		\return returns true if key is found.

		\~chinese
		?Ôğ??keyîÜvalue¡£
		\param [in] key é©?îÜkey¡£
		\param [out] value ?ßÚì«?îÜkeyîÜ?é©ù¬?ğíîÜêÈöÇ¡£
		\return ?ÓğkeyîÜ?Ú÷üŞtrue¡£

		\~japanese
		KeyªË??ª¹ªëvalueªòÔğªŞª¹¡£
		\param [in] key ÷®ª¹«­?
		\param [out] value ÷®ª·ª¿«­?ªË??ª¹ªëö·ª¬ÜÁğíªµªìªëá¶
		\return keyªò÷®ª·ª¿ªé¡¢trueªò«ê«¿?«óª·ªŞª¹¡£

		\~
		 */
		bool Lookup( KINARGTYPE key, VOUTARGTYPE value ) const
		{
			// ºó °ÍÀº »¡¸® Ã£¾Æ¹ö¸®ÀÚ.
			if(m_nElements == 0)
				return false;

			uint32_t iBin;
			uint32_t nHash;
			CNode* pNode;

			pNode = GetNode( key, iBin, nHash );
			if ( pNode == NULL )
			{
				return false;
			}

			value = pNode->m_value;

			return true;
		}

		/**
		\~korean
		key¿¡ ´ëÀÀÇÏ´Â value¸¦ Ã£µÇ, CPair °´Ã¼¸¦ ¸®ÅÏÇÑ´Ù.

		\~english
		Finds value corrsponds to key but returns CPair object

		\~chinese
		???keyîÜvalue£¬Ú÷üŞ CPair%?ßÚ¡£

		\~japanese
		KeyªË??ª¹ªëvalueªò÷®ª·ªŞª¹ª¬¡¢CPair«ª«Ö«¸«§«¯«Èªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		const CPair* Lookup( KINARGTYPE key ) const throw()
		{
			// ºó °ÍÀº »¡¸® Ã£¾Æ¹ö¸®ÀÚ.
			if(m_nElements == 0)
				return NULL;

			uint32_t iBin;
			uint32_t nHash;
			CNode* pNode;

			pNode = GetNode( key, iBin, nHash );

			return( pNode );
		}

		/**
		\~korean
		key¿¡ ´ëÀÀÇÏ´Â value¸¦ Ã£µÇ, CPair °´Ã¼¸¦ ¸®ÅÏÇÑ´Ù.

		\~english
		Finds value corrsponds to key but returns CPair object.

		\~chinese
		???keyîÜvalue£¬Ú÷üŞ CPair%?ßÚ¡£

		\~japanese
		KeyªË??ª¹ªëvalueªò÷®ª·ªŞª¹ª¬¡¢CPair«ª«Ö«¸«§«¯«Èªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		CPair* Lookup( KINARGTYPE key ) throw()
		{
			// ºó °ÍÀº »¡¸® Ã£¾Æ¹ö¸®ÀÚ.
			if(m_nElements == 0)
				return NULL;

			uint32_t iBin;
			uint32_t nHash;
			CNode* pNode;

			pNode = GetNode( key, iBin, nHash );

			return( pNode );
		}

		/**
		\~korean
		key¿¡ ´ëÀÀÇÏ´Â value °ªÀ» Ã£´Â´Ù. ¾øÀ» °æ¿ì »õ entry¸¦ ³»ºÎÀûÀ¸·Î ¸¸µç´Ù

		\return ÀÌ¹Ì ÀÖ°Å³ª »õ·Î Ãß°¡µÈ entryÀÇ reference¸¦ ¸®ÅÏÇÑ´Ù.

		\~english
		Finds value corrsponds to key. If not existed then internally creates a new entry.

		\return returns reference of entry that is eiter alread existing or newly added

		\~chinese
		???keyîÜvalue?¡£?êóîÜ?î¤?İ»?ËïãæîÜentry¡£

		\return Ú÷üŞì«êóûäíºãæôÕÊ¥îÜentryîÜreference¡£

		\~japanese
		keyªË??ª¹ªëvalueö·ªò÷®ª·ªŞª¹¡£Ùíª±ªìªĞãæª·ª¤entryªò?İ»îÜªËíÂªêªŞª¹¡£
		\return ?ªËª¢ªëª«¡¢ãæª¿ªËõÚÊ¥ªµªìª¿entryªÎreferenceªò«ê«¿?«óª·ªŞª¹¡£

		\~
		*/
		V& operator[]( KINARGTYPE key ) throw()
		{
			CNode* pNode;
			uint32_t iBin;
			uint32_t nHash;

			pNode = GetNode( key, /*out */ iBin, /*out */ nHash);
			if ( pNode == NULL )
			{
				pNode = CreateNode( key, iBin, nHash );
			}

			return( pNode->m_value );
		}

		/**
		\~korean
		key,value pair¸¦ »õ·Î Ãß°¡ÇÑ´Ù. ÀÌ¹Ì ÀÖÀ¸¸é ¿À¹ö¶óÀÌÆ®ÇÑ´Ù.
		\param key Ãß°¡ÇÒ Å°°ª
		\param value Ãß°¡ÇÒ °ª °´Ã¼
		\return Ãß°¡¸¦ ÇÑ ÈÄ Ãß°¡ À§Ä¡¸¦ °¡¸®Å°´Â Æ÷ÀÎÅÍ. PositionÀÌ º£ÀÌ½º Å¬·¡½ºÀÌ¹Ç·Î ¹Ù·Î PositionÀ» ¸®ÅÏ°ªÀ¸·Î °£ÁÖÇØµµ µÈ´Ù.

		\~english
		Newly addes key and value pair. If already exist then overwrites.
		\param key key value to be added
		\param value value object to be added
		\return pointer that points additional location after adding. Since Position is a base class, it is possible to regards Position as return value.

		\~chinese
		ãæôÕÊ¥key,value pair¡£ì«êóîÜ?ö¦ÜİËÌ¡£
		\param key é©ôÕÊ¥îÜkey?¡£
		\param value é©ôÕÊ¥îÜ??ßÚ¡£
		\return ôÕÊ¥ı¨ò¦ú¾ôÕÊ¥êÈöÇîÜò¦?¡£ì×?PositionãÀÙù??£¬Ê¦ì¤òÁïÈ÷êPositionÊ×íÂãÀÚ÷üŞ?¡£

		\~japanese
		key,value pairªòãæª¿ªËõÚÊ¥ª·ªŞª¹¡£?ªËª¢ªìªĞ«ª?«Ğ?«é«¤«Èª·ªŞª¹¡£
		\param key õÚÊ¥ª¹ªë«­?ö·
		\param value õÚÊ¥ª¹ªë«ª«Ö«¸«§«¯«È
		\return õÚÊ¥ªòª·ª¿ı­¡¢õÚÊ¥êÈöÇªòò¦ª¹«İ«¤«ó«¿?¡£Positionª¬«Ù?«¹«¯«é«¹ªÊªÎªÇ¡¢ª¹ª°Positionªò«ê«¿?«óö·ªËÌ¸ªÊª·ªÆªâÕŞª¤ªÇª¹¡£
 
		\~
		*/
		CNode* SetAt( KINARGTYPE key, VINARGTYPE value )
		{
			CNode* pNode;
			uint32_t iBin;
			uint32_t nHash;

			pNode = GetNode( key, iBin, nHash );
			if ( pNode == NULL )
			{
				pNode = CreateNode( key, iBin, nHash );
        pNode->m_value = value;
			}
			else
			{
				pNode->m_value = value;
			}

			return pNode;/*( Position( pNode ) ); */
		}

		/**
		\~korean
		ÀÏÀü¿¡ ¾òÀº Position °´Ã¼°¡ °¡¸®Å°´Â °÷ÀÇ value¸¦ »õ·Î ³Ö´Â´Ù.
		\param pos value¸¦ ³ÖÀ» nodeÀÇ Position
		\param value node¿¡ ³ÖÀ» data

		\~english 
		Insert a new value of the place where the previously obtained position object points at. 
		\param pos Position of the node to insert the value
		\param value Data to be inserted into the node

		\~chinese
		ãæ?ìıŞÀà»?ÔğîÜPosition?ßÚò¦ú¾îÜêÈöÇîÜvalue¡£
		\param pos é©Û¯ìıvalueîÜnodeîÜPosition¡£
		\param value é©èÙnodeÛ¯ìıîÜdata¡£

		\~japanese
		ª³ªÎîñªËÔğª¿Position«ª«Ö«¸«§«¯«Èª¬ò¦ª¹á¶ªÎvalueªòãæª¿ªËìıªìªŞª¹¡£
		\param pos valueªòìıªìªënodeªÎPosition
		\param value nodeªËìıªìªë«Ç?«¿

		\~
		*/
		void SetValueAt( Proud::Position pos, VINARGTYPE value )
		{
			if( pos == NULL )
			{
				assert(0);
			}
			else
			{
				CNode* pNode = static_cast< CNode* >( pos );
				pNode->m_value = value;
			}
		}

		/**
		\~korean
		\copydoc Á¦°Å

		\~english
		\copydoc Remove

		\~chinese
		\copydoc Remove

		\~japanese
		\copydoc Remove
		\~
		*/
		bool RemoveKey( KINARGTYPE key,bool rehashOnNeed=false ) throw()
		{
			CNode* pNode;
			uint32_t iBin;
			uint32_t nHash;

			pNode = GetNode( key, iBin, nHash );
			if ( pNode == NULL )
			{
				return( false );
			}

			RemoveNode( pNode,rehashOnNeed );

			return( true );
		}

		/**
		\~korean
		¿ÏÀüÈ÷ ºñ¿î´Ù

		\~english
		Completely empty it

		\~chinese
		èÇîï?Íö¡£

		\~japanese
		èÇîïªËÍöª­ªËª·ªŞª¹¡£
		\~
		*/
		inline void Clear()
		{
			RemoveAll();
		}

		/**
		\~korean
		key°¡ °¡¸®Å°´Â Ç×¸ñÀ» Ã£¾Æ Á¦°ÅÇÑ´Ù.
		\param key Á¦°ÅÇÒ Å°
		\param rehashOnNeed trueÀÎ °æ¿ì, hash tableÀÌ ÃæºĞÈ÷ ÀÛ¾ÆÁø °æ¿ì hash tableÀ» ÀçÁ¶Á¤ÇÑ´Ù.
		ÀÌ¶§ »ç¿ëÁßÀÌ´ø iterator³ª Position °¡ ÀÖÀ» °æ¿ì ÀÌ´Â ¹«È¿È­µÊÀ» ÁÖÀÇÇØ¾ß ÇÑ´Ù.
		\return Ã£¾Æ¼­ Á¦°Å¸¦ ÇßÀ¸¸é true¸¦ ¸®ÅÏÇÑ´Ù. ¸øÃ£¾ÒÀ¸¸é false´Ù.

		\~english
		Finds the clause pointed by key then removes it.
		\param key key to be removed
		\param rehashOnNeed if ture then hash table is re-modified when hash table became small enough
		Must pay attention to the fact that if there exists either iterator and/or Position during the process, it/they will be nullified.
		\return returns if found and removed. False if failed to find.

		\~chinese
		?Óğkeyò¦ú¾îÜ?ÙÍ??ğ¶¡£
		\param key é©?ğ¶îÜkey¡£
		\param rehashOnNeed ãÀtrueîÜ?£¬î¤hash tableõöİÂ?á³?îÜï×?ñìãæ?ïÚhash table¡£
		é©ñ¼ëò??ı¦åıêóŞÅéÄñéîÜiterator ³ª Position£¬ñ¼ëò?øµ?Ùéüù¡£
		\return ?Óğ??ğ¶ÖõîÜ?Ú÷üŞtrue¡£?êó?ÓğîÜ?ãÀfalse¡£

		\~japanese
		«­?ª¬ò¦ª¹ú£ÙÍªò÷®ª·ªÆğ¶ËÛª·ªŞª¹¡£
		\param key ğ¶ËÛª¹ªë«­?
		\param rehashOnNeed trueªÎíŞùê¡¢hash tableª¬ä¨İÂá³ªµª¯ªÊªÃª¿íŞùê¡¢hash tableªòî¢ğàïÚª·ªŞª¹¡£ 
		ª³ªÎãÁ¡¢ŞÅªÃªÆª¤ª¿iteratorª«Positionª¬ª¢ªëíŞùê¡¢ª³ªìªÏªâ?Íıªµªìªëª³ªÈªËñ¼ëòª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
		\return ÷®ª·ªÆğ¶ËÛª·ª¿ªé¡¢trueªò«ê«¿?«óª·ªŞª¹¡£÷®ª¹ª³ªÈª¬ªÇª­ªÊª«ªÃª¿ªéfalseªÇª¹¡£

		\~
		*/
		inline bool Remove( KINARGTYPE key,bool rehashOnNeed=false )
		{
			return RemoveKey(key,rehashOnNeed);
		}

		/**
		\~korean

		\~english

		\~chinese

		\~japanese

		\~
		\copydoc Clear
		*/
		void RemoveAll()
		{
			DisableAutoRehash();

			AssertConsist();

			// ¸ğµç nodeµéÀ» Á¦°ÅÇÑ´Ù.
			// mapÀÌ ¸ğµç nodeµéÀº bin Á¾·ù ¸··ĞÇÏ°í ¸ğµÎ ¿¬°áµÇ¾î ÀÖ´Ù.
			CNode* pNode;
			int removeCount = 0;
			for (pNode = m_pHeadBinHead; pNode != NULL; )
			{
				CNode* pNext = pNode->m_pNext; // save
				assert(m_nElements > 0);
				FreeNode(pNode,false);
				pNode = pNext; // restore
				removeCount++;
			}

			assert(m_nElements == 0);

			CProcHeap::Free(m_ppBins);
			m_ppBins = NULL;

			m_nElements = 0;

			m_pHeadBinHead = NULL;

			m_pTailBinTail = NULL;

			AssertConsist();

			if ( !IsLocked() )
			{
				if(!InitHashTable( PickSize( m_nElements ), false ))
					ThrowBadAllocException();
			}

			AssertConsist();

			EnableAutoRehash();
		}

		/**
		\~korean
		PositionÀÌ °¡¸®Å°´Â °÷ÀÇ key-value pair¸¦ Á¦°ÅÇÑ´Ù.
		\param pos ÀÏÀü¿¡ ¾òÀº Position °ª. ÀÌ °ªÀº À¯È¿ÇÑ °ªÀÌ¾î¾ß ÇÑ´Ù!
		\param rehashOnNeed trueÀÏ ¶§, hash tableÀÌ ÃæºĞÈ÷ ÀÛ¾ÆÁø °æ¿ì hash tableÀ» ÀçÁ¶Á¤ÇÑ´Ù.
		ÀÌ¶§ »ç¿ëÁßÀÌ´ø iterator³ª Position °¡ ÀÖÀ» °æ¿ì ÀÌ´Â ¹«È¿È­µÊÀ» ÁÖÀÇÇØ¾ß ÇÑ´Ù.

		\~english
		Removes key-value pair of where pointed by Position
		\param pos Position value acquired before. This value must be valid!
		\param rehashOnNeed if ture then hash table is re-modified when hash table became small enough
		Must pay attention to the fact that if there exists either iterator and/or Position during the process, it/they will be nullified.

		\~chinese
		?ğ¶Positionò¦ú¾îÜò¢Û°îÜkey-value pair¡£
		\param pos ŞÀà»?ÔğîÜPosition?¡£ó®?ÔğãÀêóüùîÜ?£¡
		\param rehashOnNeed true?£¬åıhash tableõöİÂ?á³£¬?é©ñìãæ?ïÚhash table¡£
		é©ñ¼ëò£¬??î¤ŞÅéÄîÜiteratorûäPosition£¬ñ¼ëò???ÔğÙéüù¡£

		\~japanese
		Positionª¬ò¦ª¹á¶ªÎkey-value pairªòğ¶ËÛª·ªŞª¹¡£
		\param pos ª³ªÎîñªËÔğª¿Positionö·¡£ª³ªÎö·ªÏêó?ªÊö·ªÇªÏªÊª±ªìªĞªÊªêªŞª»ªó¡£
		\param rehashOnNeed trueªÎãÁ¡¢hash tableª¬ä¨İÂá³ªµª¯ªÊªÃª¿íŞùê¡¢hash tableªòî¢ğàïÚª·ªŞª¹¡£ 
		ª³ªÎãÁ¡¢ŞÅªÃªÆª¤ª¿ iteratorª«Positionª¬ª¢ªëíŞùê¡¢ª³ªìªÏÙí?ª«ªµªìªëª³ª³ªÈªËñ¼ëòª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£

		\~
		*/
		void RemoveAtPos( Proud::Position pos ,bool rehashOnNeed=false) throw()
		{
			assert( pos != NULL );

			CNode* pNode = static_cast< CNode* >( pos );

			RemoveNode( pNode ,rehashOnNeed);
		}

		/**
		\~korean
		º¸À¯ÇÏ°í ÀÖ´Â Ç×¸ñ Áß ¸Ç ¾ÕÀÇ °ÍÀ» ¾ò´Â´Ù. ÁÖ·Î iterationÀ» À§ÇØ¼­ ¾²ÀÎ´Ù.
		GetNext µîÀ» ½á¼­ ´ÙÀ½ Ç×¸ñÀ» iterationÇØ ³ª°¥ ¼ö ÀÖ´Ù.
		\return ¸Ç¾Õ Ç×¸ñÀÇ Position

		\~english
		Gets the foremost thing among possessed clauses. Mainly used for iteration.
		It is possible to perform iteration to next clause by using GetNext or others.
		\return position of the foremost clause

		\~chinese
		?Ôğá¶?êóîÜ?ÙÍñéõÌîñØüîÜ?ÙÍ¡£ñ«é©?Öõiterationá¶éÄ¡£
		î¤ŞÅéÄGetNextÔõı¨£¬î¦Òö?ú¼iterationñıı¨îÜ?ÙÍ¡£
		\return õÌîñØü?ÙÍîÜPosition¡£

		\~japanese
		ÜÁêóª·ªÆª¤ª¿ú£ÙÍªÎª¦ªÁìéÛãà»ªÎªâªÎªòÔğªŞª¹¡£ñ«ªËiterationªÎª¿ªáªËŞÅªïªìªŞª¹¡£
		GetNext ªÊªÉªòŞÅªÃªÆó­ªÎú£ÙÍªòiterationª·ªÆú¼ª¯ª³ªÈª¬ªÇª­ªŞª¹¡£
		\return ìéÛãà»ªÎú£ÙÍªÎPosition

		\~
		*/
		inline Proud::Position GetStartPosition() const throw()
		{
			if ( IsEmpty() )
			{
				return( NULL );
			}

			return Proud::Position(m_pHeadBinHead);
		}

		/**
		\~korean
		º¸À¯ÇÏ°í ÀÖ´Â Ç×¸ñ Áß ¸Ç µÚÀÇ °ÍÀ» ¾ò´Â´Ù.ÁÖ·Î reverse_iterationÀ» À§ÇØ¼­ ¾²ÀÎ´Ù.
		GetPrev µîÀ» ½á¼­ ´ÙÀ½ Ç×¸ñÀ» iterationÇØ ³ª°¥ ¼öÀÖ´Ù.
		\return ¸Ç ¸¶Áö¸· Ç×¸ñÀÇ Position

		\~english
		Gets the very last thing among possessed clauses. Mainly used for reverse_iteration.
		It is possible to perform iteration to next clause by using GetPrev or others.
		\return position of the last clause

		\~chinese
		?Ôğ?êóîÜ?ÙÍñéõÌı¨ØüîÜ?ÙÍ¡£ñ«é©?Öõreverse_iterationá¶éÄ¡£
		î¤ŞÅéÄGetPrevÔõı¨£¬î¦Òö?ú¼iterationñıı¨îÜ?ÙÍ¡£
		\return õÌı¨?ÙÍîÜPosition¡£


		\~japanese
		ÜÁêóª·ªÆª¤ªëú£ÙÍªÎª¦ªÁìéÛãı­ªíªÎªâªÎªòÔğªŞª¹¡£ñ«ªËreverse_iterationªÎª¿ªáªËŞÅªïªìªŞª¹¡£
		GetPrev ªÊªÉªòŞÅªÃªÆó­ªÎú£ÙÍªòiterationª·ªÆú¼ª±ªŞª¹¡£
		\return ìéÛãõÌı­ªÎú£ÙÍªÎPosition

		\~
		*/
		inline Proud::Position GetEndPosition() const throw()
		{
			if( IsEmpty() )
			{
				return ( NULL );
			}

			return Proud::Position(m_pTailBinTail);
		}


		/**
		\~korean
		´ÙÀ½ Ç×¸ñÀ» ¾ò´Â´Ù.
		\param [in,out] pos ´ÙÀ½ Ç×¸ñÀÇ Position°ª
		\param [out] key ´ÙÀ½Ç×¸ñÀÇ key
		\param [out] value ´ÙÀ½ Ç×¸ñÀÇ °ª

		\~english 
		Obtain the following
		\param [in,out] Position value of the next item. 
		\param [out] Key of the next item. 
		\param [out] Value of the next item. 

		\~chinese
		?Ôğñıı¨?ÙÍ¡£
		\param [in,out] pos ñıı¨?ÙÍîÜPosition?¡£
		\param [out] key ñıı¨?ÙÍîÜkey¡£
		\param [out] value ñıı¨?ÙÍîÜ?¡£

		\~japanese
		ó­ªÎú£ÙÍªòÔğªŞª¹¡£
		\param [in,out] pos ó­ªÎú£ÙÍªÎPositionö·
		\param [out] key ó­ªÎú£ÙÍªÎkey
		\param [out] value ó­ªÎú£ÙÍªÎö·

		\~
		*/
		void GetNextAssoc( Proud::Position& pos, KOUTARGTYPE key, VOUTARGTYPE value ) const
		{
			CNode* pNode;
			CNode* pNext;

			assert( m_ppBins != NULL );
			assert( pos != NULL );

			pNode = (CNode*)pos;
			pNext = pNode != NULL? pNode->m_pNext : NULL; //FindNextNode( pNode );

			pos = Proud::Position( pNext );
			key = pNode->m_key;
			value = pNode->m_value;
		}

		/**
		\~korean
		´ÙÀ½ Ç×¸ñÀ» ¾ò´Â´Ù.
		\param pos °¡¸®Å°°í ÀÖ´Â nodeÀÇ ´ÙÀ½ PositionÀ» ¾ò¾î¿Â´Ù.
		\return ´ÙÀ½ nodeÀÇ const CPair°ªÀ» ¸®ÅÏ

		\~english 
		Obtain the following:
		\param pos Obtain the next position of the node being pointed at. 
		\return Return the const CPair value of the next node

		\~chinese
		?Ôğñıı¨îÜ?ÙÍ¡£
		\param pos ?Ôğá¶ò¦îÜnodeîÜñıı¨Position¡£
		\return Ú÷üŞñıı¨nodeîÜconst CPair%?¡£

		\~japanese
		ó­ªÎú£ÙÍªòÔğªŞª¹¡£
		\param pos ò¦ª·ªÆª¤ªënodeªÎó­ªÎPositionªòÔğªÆª­ªŞª¹¡£
		\return ó­ªÎnodeªÎconst CPairö·ªò«ê«¿?«ó

		\~
		*/
		const CPair* GetNext( Proud::Position& pos ) const throw()
		{
			CNode* pNode;
			CNode* pNext;

			assert( m_ppBins != NULL );
			assert( pos != NULL );

			pNode = (CNode*)pos;
			pNext = pNode != NULL? pNode->m_pNext : NULL; //FindNextNode( pNode );

			pos = Proud::Position( pNext );

			return( pNode );
		}

		/**
		\~korean
		´ÙÀ½ Ç×¸ñÀ» ¾ò´Â´Ù.
		\param pos pos °¡¸®Å°°í ÀÖ´Â nodeÀÇ ´ÙÀ½ PositionÀ» ¾ò¾î¿Â´Ù.
		\return ´ÙÀ½ nodeÀÇ \ref CPair °ªÀ» ¸®ÅÏ

		\~english 
		Obtain the next item.
		\param pos Obtain the next position of the node being pointed at. 
		\return Return the const CPair value of the next node


		\~chinese
		?Ôğñıı¨îÜ?ÙÍ¡£
		\param pos pos?Ôğá¶ò¦îÜnodeñıı¨îÜPosition¡£
		\return Ú÷üŞñıı¨nodeîÜ\ref CPair%? ¡£

		\~japanese
		ó­ªÎú£ÙÍªòÔğªŞª¹¡£
		\param pos pos ò¦ª·ªÆª¤ªënodeªÎó­ªÎPositionªòÔğªŞª¹¡£
		\return ó­ªÎnodeªÎ\ref CPair ö·ªò«ê«¿?«ó

		\~
		*/
		CPair* GetNext( Proud::Position& pos ) throw()
		{
			assert( m_ppBins != NULL );
			assert( pos != NULL );

			CNode* pNode = static_cast< CNode* >( pos );
			CNode* pNext = pNode != NULL? pNode->m_pNext : NULL; //FindNextNode( pNode );

			pos = Proud::Position( pNext );

			return( pNode );
		}

		/**
		\~korean
		ÀÌÀü Ç×¸ñÀ» ¾ò´Â´Ù.
		\param pos pos°¡ °¡¸£Å°°í ÀÖ´Â nodeÀÇ ÀÌÀü PositionÀ» ¾ò¾î¿Â´Ù.
		\return ÀÌÀü³ëµåÀÇ \ref CPair °ª

		\~english 
		Obtain the previous item. 
		\param pos Obtain the next position of the node being pointed at by this pos.
		\return Key value of the next node. 

		\~chinese
		?Ôğñıîñ?ÙÍ¡£
		\param pos ?Ôğposá¶ò¦îÜnodeîÜñıîñPosition¡£
		\return ñıîñnodeîÜ\ref CPair%? ¡£

		\~japanese
		ì¤îñªÎú£ÙÍªòÔğªŞª¹¡£
		\param pos posª¬ò¦ª·ªÆª¤ªënodeªÎì¤îñªÎPositionªòÔğªÆª­ªŞª¹¡£
		\return ì¤îñ«Î?«ÉªÎ\ref CPairö·

		\~
		*/
		CPair* GetPrev( Proud::Position& pos ) throw()
		{
			assert( m_ppBins != NULL );
			assert( pos != NULL );

			CNode* pNode = static_cast< CNode* >( pos );
			CNode* pNext = FindPrevNode( pNode );

			pos = Proud::Position( pNext );

			return( pNode );
		}

		/**
		\~korean
		´ÙÀ½ Ç×¸ñÀ» ¾ò´Â´Ù.
		\param pos ÀÌ pos °¡¸®Å°°í ÀÖ´Â nodeÀÇ ´ÙÀ½ PositionÀ» ¾ò¾î¿Â´Ù.
		\return ´ÙÀ½ nodeÀÇ key°ª

		\~english 
		Obtain the next item
		\param pos Obtain the next position of the node being pointed at by this pos.
		\return const value of the next node 

		\~chinese
		?Ôğñıı¨?ÙÍ¡£
		\param pos ?Ôğ??posá¶ò¦îÜnodeñıı¨îÜPosition¡£
		\return ñıı¨nodeîÜkey?¡£

		\~japanese
		ó­ªÎú£ÙÍªòÔğªŞª¹¡£
		\param pos ª³ªÎposª¬ò¦ª·ªÆª¤ªënodeªÎó­ªÎPositionªòÔğªÆª­ªŞª¹¡£
		\return ó­ªÎnodeªÎkeyö·

		\~
		*/
		const K& GetNextKey( Proud::Position& pos ) const
		{
			CNode* pNode;
			CNode* pNext;

			assert( m_ppBins != NULL );
			assert( pos != NULL );

			pNode = (CNode*)pos;
			pNext = pNode != NULL? pNode->m_pNext : NULL; //FindNextNode( pNode );

			pos = Proud::Position( pNext );

			return( pNode->m_key );
		}

		/**
		\~korean
		´ÙÀ½ Ç×¸ñÀ» ¾ò´Â´Ù.
		\param pos ÀÌ pos °¡¸®Å°°í ÀÖ´Â nodeÀÇ ´ÙÀ½ PositionÀ» ¾ò¾î¿Â´Ù.
		\return ´ÙÀ½ nodeÀÇ const value°ª

		\~english 
		Obtain the next item
		\param pos Obtain the next position of the node being pointed at by this pos.
		\return const value of the next node 

		\~chinese
		?Ôğñıı¨?ÙÍ¡£
		\param pos ?Ôğ??posá¶ò¦îÜnodeñıı¨îÜPosition¡£
		\return ñıı¨nodeîÜconst value?¡£

		\~japanese
		ó­ªÎú£ÙÍªòÔğªŞª¹¡£
		\param pos ª³ªÎposª¬ò¦ª·ªÆª¤ªënodeªÎó­ªÎPositionªòÔğªÆª­ªŞª¹¡£
		\return ó­ªÎnodeªÎconst valueö·

		\~
		*/
		const V& GetNextValue( Proud::Position& pos ) const
		{
			CNode* pNode;
			CNode* pNext;

			assert( m_ppBins != NULL );
			assert( pos != NULL );

			pNode = (CNode*)pos;
			pNext = pNode != NULL? pNode->m_pNext : NULL; //FindNextNode( pNode );

			pos = Proud::Position( pNext );

			return( pNode->m_value );
		}

		/**
		\~korean
		´ÙÀ½ Ç×¸ñÀ» ¾ò´Â´Ù.
		\param pos ÀÌ pos °¡¸®Å°°í ÀÖ´Â nodeÀÇ ´ÙÀ½ PositionÀ» ¾ò¾î¿Â´Ù.
		\return ´ÙÀ½ nodeÀÇ value°ª

		\~english 
		Obtain the next item
		\param pos Obtain the next position of the node being pointed at by this pos.
		\return Value of the next node

		\~chinese
		?Ôğñıı¨îÜ?ÙÍ¡£
		\param pos ?Ôğ??posá¶ò¦îÜnodeñıı¨îÜPosition¡£
		\return ñıı¨nodeîÜvalue?¡£

		\~japanese
		ó­ªÎú£ÙÍªòÔğªŞª¹¡£
		\param pos ª³ªÎposª¬ò¦ª·ªÆª¤ªënodeªÎó­ªÎPositionªòÔğªÆª­ªŞª¹¡£
		\return ó­ªÎnodeªÎvalueö·

		\~
		*/
		V& GetNextValue( Proud::Position& pos )
		{
			CNode* pNode;
			CNode* pNext;

			assert( m_ppBins != NULL );
			assert( pos != NULL );

			pNode = (CNode*)pos;
			pNext = pNode != NULL? pNode->m_pNext : NULL; //FindNextNode( pNode );

			pos = Proud::Position( pNext );

			return( pNode->m_value );
		}

		/**
		\~korean
		PositionÀÌ °¡¸®Å°°í ÀÖ´Â °÷ÀÇ key¿Í value¸¦ ¾ò´Â´Ù.
		\param pos ³ëµå¸¦ °¡¸®Å°´Â Position
		\param key ÇØ´ç³ëµåÀÇ keyÀ» ¾ò¾î¿È
		\param value ÇØ´ç ³ëµåÀÇ data¸¦ ¾ò¾î¿È

		\~english 
		Obtain the key and value of the place where the position is pointing at. 
		\param pos Position pointing the node 
		\param key Obtain the key of the node
		\param value Obtain the data of the node

		\~chinese
		?ÔğPositioná¶ò¦îÜêÈöÇîÜkeyûúvalue¡£
		\param pos ò¦ú¾nodeîÜPosition¡£
		\param key ?ÔğßÓ?nodeîÜkey¡£
		\param value ?ÔğßÓ?nodeîÜdata¡£

		\~japanese
		Positionª¬ò¦ª·ªÆª¤ªëá¶ªÎkeyªÈvalueªòÔğªŞª¹¡£
		\param pos «Î?«Éªòò¦ª¹Position
		\param key ú±?«Î?«ÉªÎkeyªòÔğªÆª­ªŞª¹¡£
		\param value ú±?«Î?«ÉªÎ«Ç?«¿ªòÔğªÆª­ªŞª¹¡£

		\~
		*/
		inline void GetAt( Proud::Position pos, KOUTARGTYPE key, VOUTARGTYPE value ) const
		{
			assert( pos != NULL );

			CNode* pNode = static_cast< CNode* >( pos );

			key = pNode->m_key;
			value = pNode->m_value;
		}

		/**
		\~korean
		ÇØ´ç index¿¡ ÀÖ´Â °÷ÀÇ key¿Í value¸¦ ¾ò´Â´Ù.
		\param index Ã¹¹øÂ° Á¤º¸·Î ºÎÅÍ ÀÌ index¸¸Å­ ´ÙÀ½³ëµå·Î ÀÌµ¿ÇÑ´Ù.
		\return Ã£Àº ³ëµåÀÇ CPair

		\~english 
		Obtain the key and value of the place located in the index 
		\param index Move to the next node as much as this index from the first information. 
		\return CPair of the searched node

		\~chinese
		?Ôğî¤ßÓ?indexêÈöÇîÜkeyûúvalue¡£
		\param index ?ğ¯ìé?ãáãÓ?ã·ì¹?ò¸ßÓ?éÍó®index£¬ñıı¨ì¹?Óğù»ìé?node¡£
		\return ?ÓğîÜnodeîÜ CPair%¡£

		\~japanese
		ú±?indexªËª¢ªëá¶ªÎkeyªÈvalueªòÔğªŞª¹¡£
		\param index ìéÛãÙÍªÎï×ÜÃª«ªéª³ªÎindexªÀª±ó­ªÎ«Î?«ÉªØì¹ÔÑª·ªŞª¹¡£
		\return ÷®ª·ª¿«Î?«ÉªÎCPair

		\~
		*/
		inline CPair* GetPairByIndex(int index) throw()
		{
			assert( index < (int)GetCount() );

			CNode* node = m_pHeadBinHead;

			for (int i = 0; i < index; ++i)
				node = node->m_pNext;

			return( static_cast< CPair* >( node ) );
		}

		/**
		\~korean
		ÇØ´ç index¿¡ ÀÖ´Â °÷ÀÇ key¿Í value¸¦ ¾ò´Â´Ù.
		\param index Ã¹¹øÂ° Á¤º¸·Î ºÎÅÍ ÀÌ index¸¸Å­ ´ÙÀ½³ëµå·Î ÀÌµ¿ÇÑ´Ù.
		\return Ã£Àº ³ëµåÀÇ const CPair

		\~english 
		Obtain the key and value of the place located in the index
		\param index Move to the next node as much as this index from the first information.
		\return const CPair of the searched node

		\~chinese
		?Ôğî¤ßÓ?indexêÈöÇîÜkeyûúvalue¡£
		\param index ?ğ¯ìé?ãáãÓ?ã·ì¹?ò¸ßÓ?éÍó®index£¬ñıı¨ì¹?Óğù»ìé?node¡£
		\return ?ÓğîÜnodeîÜconst CPair%¡£

		\~japanese
		ú±?indexªËª¢ªëá¶ªÎkeyªÈvalueªòÔğªŞª¹¡£
		\param index ìéÛãÙÍªÎï×ÜÃª«ªéª³ªÎindexªÀª±ó­ªÎ«Î?«ÉªØì¹ÔÑª·ªŞª¹¡£
		\return ÷®ª·ª¿«Î?«ÉªÎconst CPair

		\~
		*/
		inline const CPair* GetPairByIndex(int index) const throw()
		{
			assert( index < (int)GetCount() );

			CNode* node = m_pHeadBinHead;

			for (int i = 0; i < index; ++i)
				node = node->m_pNext;

			 return( static_cast< CPair* >( node ) );
		}

		/**
		\~korean
		PositionÀÌ °¡¸®Å°°í ÀÖ´Â °÷ÀÇ key¿Í value¸¦ ¾ò´Â´Ù.
		\param pos PositionÁ¤º¸
		\return Position¿¡ ÇØ´çÇÏ´Â CPair

		\~english 
		Obtain the key and value of the place where the position is pointing at
		\param pos Position information
		\return CPair corresponding to the position

		\~chinese
		?ÔğPositionò¦ú¾îÜêÈöÇîÜkeyûúvalue¡£
		\param pos PositionãáãÓ¡£
		\return ßÓ?éÍPositionîÜ CPair%¡£

		\~japanese
		Positionª¬ò¦ª·ªÆª¤ªëá¶ªÎkeyªÈvalueªòÔğªŞª¹¡£
		\param pos Positionï×ÜÃ
		\return PositionªËú±?ª¹ªëCPair

		\~
		*/
		inline CPair* GetAt( Proud::Position pos ) throw()
		{
			assert( pos != NULL );

			return( static_cast< CPair* >( pos ) );
		}

		/**
		\~korean
		PositionÀÌ °¡¸®Å°°í ÀÖ´Â °÷ÀÇ key¿Í value¸¦ ¾ò´Â´Ù.
		\param pos PositionÁ¤º¸
		\return Position¿¡ ÇØ´çÇÏ´Â const CPair

		\~english 
		Obtain the key and value of the place where the position is pointing at
		\param pos Position information
		\return const CPair corresponding to the position

		\~chinese
		?ÔğPositionò¦ú¾îÜêÈöÇîÜkeyûúvalue¡£
		\param pos PositionãáãÓ¡£
		\return ßÓ?éÍPositionîÜconst CPair%¡£

		\~japanese
		Positionª¬ò¦ª·ªÆª¤ªëá¶ªÎkeyªÈvalueªòÔğªŞª¹¡£
		\param pos Positionï×ÜÃ
		\return PositionªËú±?ª¹ªëconst CPair

		\~
		 */
		inline const CPair* GetAt( Proud::Position pos ) const throw()
		{
			assert( pos != NULL );

			return( static_cast< const CPair* >( pos ) );
		}

		/**
		\~korean
		PositionÀÌ °¡¸®Å°°í ÀÖ´Â °÷ÀÇ key¿Í value¸¦ ¾ò´Â´Ù.
		\param pos node¸¦ °¡¸®Å°´Â Position
		\return PositionÀÌ °¡¸®Å°´Â nodeÀÇ key

		\~english 
		Obtain the key and value of the place where the position is pointing at
		\param pos Position pointing at the node
		\return Key of the node pointed at by the position

		\~chinese
		?ÔğPositionò¦ú¾îÜêÈöÇîÜkeyûúvalue¡£
		\param pos ò¦ú¾nodeîÜPosition¡£
		\return Positionò¦ú¾îÜnodeîÜkey¡£

		\~japanese
		Positionª¬ò¦ª·ªÆª¤ªëá¶ªÎkeyªÈvalueªòÔğªŞª¹¡£
		\param pos nodeªòò¦ª¹Position
		\return Positionª¬ò¦ª¹nodeªÎkey

		\~
		*/
		inline const K& GetKeyAt( Proud::Position pos ) const
		{
			assert( pos != NULL );

			CNode* pNode = (CNode*)pos;

			return( pNode->m_key );
		}

		/**
		\~korean
		PositionÀÌ °¡¸®Å°°í ÀÖ´Â °÷ÀÇ key¿Í value¸¦ ¾ò´Â´Ù.
		\param pos node¸¦ °¡¸®Å°´Â Position
		\return PositionÀÌ °¡¸®Å°´Â nodeÀÇ const data

		\~english 
		Obtain the key and value of the place where the position is pointing at
		\param Position pointing at the node
		\return const data of the node pointed at by the position

		\~chinese
		?ÔğPositionò¦ú¾îÜêÈöÇîÜkeyûúvalue¡£
		\param pos ò¦ú¾nodeîÜPosition¡£
		\return Positionò¦ú¾îÜnodeîÜcons data¡£

		\~japanese
		Positionª¬ò¦ª·ªÆª¤ªëá¶ªÎkeyªÈvalueªòÔğªŞª¹¡£
		\param pos nodeªòò¦ª¹Position
		\return Positionª¬ò¦ª¹nodeªÎconst data

		\~
		*/
		inline const V& GetValueAt( Proud::Position pos ) const
		{
			assert( pos != NULL );

			CNode* pNode = (CNode*)pos;

			return( pNode->m_value );
		}

		/**
		\~korean
		PositionÀÌ °¡¸®Å°°í ÀÖ´Â °÷ÀÇ key¿Í value¸¦ ¾ò´Â´Ù.
		\param pos node¸¦ °¡¸®Å°´Â Position
		\return PositionÀÌ °¡¸®Å°´Â nodeÀÇ data

		\~english 
		Obtain the key and value of the place where the position is pointing at
		\param pos Position pointing at the node
		\return Data of the node pointed at by the position

		\~chinese
		?ÔğPositionò¦ú¾îÜêÈöÇîÜkeyûúvalue¡£
		\param pos ò¦ú¾nodeîÜPosition¡£
		\return Positionò¦ú¾îÜnodeîÜdata¡£

		\~japanese
		Positionª¬ò¦ª·ªÆª¤ªëá¶ªÎkeyªÈvalueªòÔğªŞª¹¡£
		\param pos nodeªòò¦ª¹Position
		\return Positionª¬ò¦ª¹nodeªÎdata

		\~
		*/
		inline V& GetValueAt( Proud::Position pos )
		{
			assert( pos != NULL );

			CNode* pNode = (CNode*)pos;

			return( pNode->m_value );
		}

		/**
		\~korean
		hash Å×ÀÌºíÀÇ Å©±â¸¦ ¾ò½À´Ï´Ù.

		\~english 
		Get the size of the hash table
		
		\~chinese
		?ö¢hash tableîÜÓŞá³¡£

		\~japanese
		hash«Æ?«Ö«ëªÎ«µ«¤«ºªòÔğªŞª¹¡£
		\~
		*/
		uint32_t GetHashTableSize() const throw()
		{
			return( m_nBins );
		}

		/**
		\~korean
		hash Å×ÀÌºíÀ» ÃÊ±âÈ­ ÇÕ´Ï´Ù.
		- ³ëµå »ı¼º½Ã ÀÚµ¿À¸·Î È£ÃâµË´Ï´Ù.
		\param nBins Çì½¬ »çÀÌÁî
		\param bAllocNow Çì½¬ ¸Ş¸ğ¸® »ı¼º ¿©ºÎ ¼³Á¤
		\return hash ÃÊ±âÈ­¿¡ ¼º°øÇÏ¸é true, ½ÇÆĞÇÏ¸é false ¸®ÅÏ

		\~english 
		Initialize the hash table. 
		- It automatically calls when generating a node. 
		\param nBins Hash size
		\param bAllocNow Configure whether to generate hash memory
		\return hash True if successful in initializing, false if failed. 


		\~chinese
		ôøã·ûùhash table¡£
		- ßæà÷nodeîÜ?ı¦?í»?ù¬û¼Ğ£¡£
		\param nBins hashîÜÓŞá³¡£
		\param bAllocNow ?öÇhash?ğíßæà÷?Üú¡£
		\return hashôøã·ûùà÷ÍíîÜ?true£¬ã÷?îÜ?Ú÷üŞfalse¡£

		\~japanese
		hash«Æ?«Ö«ëªòôøÑ¢ûùª·ªŞª¹¡£
		- «Î?«Éßæà÷ãÁªËí»ÔÑªËû¼ªÓõóªµªìªŞª¹¡£
		\param nBins «Ï«Ã«·«å«µ«¤«º
		\param bAllocNow «Ï«Ã«·«å«á«â«ê?ßæà÷Ê¦ÜúªòàâïÒ
		\return hash ôøÑ¢ûùªËà÷Ííª¹ªëªÈtrue¡¢ã÷ø¨ª¹ªëªÈfalseªò«ê«¿?«ó

		\~
		*/
		bool InitHashTable( uint32_t nBins, bool bAllocNow = true )
		{
			assert( m_nElements == 0 );
			assert( nBins > 0 );

			if ( m_ppBins != NULL )
			{
				CProcHeap::Free(m_ppBins);
				m_ppBins = NULL;
			}

			if ( bAllocNow )
			{
				m_ppBins = (CNode**)CProcHeap::Alloc(sizeof(CNode*) * nBins);
				if ( m_ppBins == NULL )
				{
					return false;
				}
				memset( m_ppBins, 0, sizeof( CNode* )*nBins );
			}
			m_nBins = nBins;

			UpdateRehashThresholds();

			return true;
		}

		/**
		\~korean
		ÀÚµ¿À¸·Î Rehash¸¦ ÇÕ´Ï´Ù.

		\~english 
		Rehash automatically 

		\~chinese
		í»?Rehash¡£

		\~japanese
		í»ÔÑªÇRehashªòª·ªŞª¹¡£
		\~
		*/
		void EnableAutoRehash() throw()
		{
			assert( m_nLockCount > 0 );
			m_nLockCount--;
		}

		/**
		\~korean
		ÀÚµ¿À¸·Î Rehash¸¦ ÇÏÁö ¾Ê½À´Ï´Ù.

		\~english 
		Do not rehash automatically 

		\~chinese
		Üôí»?Rehash¡£

		\~japanese
		í»ÔÑªÇRehashªòª·ªŞª¹¡£
		\~
		*/
		void DisableAutoRehash() throw()
		{
			m_nLockCount++;
		}

		/**
		\~korean
		hash Å×ÀÌºíÀ» ´Ù½Ã »ı¼ºÇÑ´Ù.
		\param nBins hashÅ×ÀÌºíÀÇ Å©±â

		\~english 
		Generate a hash table again
		\param Size of the hash table 

		\~chinese
		ñìãæßæà÷hash table¡£
		\param nBins hash tableîÜÓŞá³¡£

		\~japanese
		hash «Æ?«Ö«ëªòî¢Óøßæà÷ª·ªŞª¹¡£
		\param nBins hash«Æ?«Ö«ëªÎ«µ«¤«º

		\~
		*/
		void Rehash( uint32_t nBins = 0 )
		{
			CNode** ppBins = NULL;

			if ( nBins == 0 )
			{
				nBins = PickSize( m_nElements );
			}

			if ( nBins == m_nBins )
			{
				return;
			}

			// NTTNTRACE(atlTraceMap, 2, "Rehash: %u bins\n", nBins );

			if ( m_ppBins == NULL )
			{
				// Just set the new number of bins
				if(!InitHashTable( nBins, false ))
					ThrowBadAllocException();

				return;
			}

			// »õ hash tableÀ» ÁØºñÇÑ´Ù. ¿©±â¿¡ ±¸ hash tableÀÌ ¿Å°ÜÁú °ÍÀÌ´Ù.
			ppBins = (CNode**)CProcHeap::Alloc(sizeof(CNode*) * nBins);
			if (ppBins == NULL)
				ThrowBadAllocException();

			memset( ppBins, 0, nBins*sizeof( CNode* ) );

			// °¢ Ç×¸ñÀÇ hash °ªÀ» ´Ù½Ã ¾ò¾î¼­ ±¸ Å×ÀÌºí·ÎºÎÅÍ »õ Å×ÀÌºí·Î ¿Å±ä´Ù. ÀÌ¶§ linked list °ü°èµµ Àç¼³Á¤ÇÑ´Ù.
			CNode* pHeadBinHead = NULL;
			CNode* pTailBinTali = NULL;
			int reAddCount = 0;
			for(CNode* pNode = m_pHeadBinHead; pNode != NULL; )
			{
				uint32_t iDestBin;

				CNode* pOldNext = pNode->m_pNext;

				iDestBin = pNode->m_nHash % nBins; // »õ·Î hash °ªÀ» ¾ò´Â´Ù. ±×¸®°í head·Î¼­ ³Öµµ·Ï ÇÑ´Ù.
				pNode->m_nBin = iDestBin;

				CNode* pOldBinHead = ppBins[iDestBin];

				// ¿ÏÀü ÃÖÃÊÀÇ Ãß°¡ÀÎ °æ¿ì
				if(reAddCount == 0)
				{
					assert(pHeadBinHead == NULL);
					assert(pOldBinHead == NULL);
					pHeadBinHead = pNode;
					pTailBinTali = pNode;
					pNode->m_pPrev = NULL;
					pNode->m_pNext = NULL;

					ppBins[iDestBin] = pNode;

					reAddCount++; // ¸¶¹«¸®
					//AssertConsist();
				}
				else
				{
					//AssertConsist();

					if(pOldBinHead != NULL)
					{
						// µé¾îÀÖ´Â bin¿¡ Ãß°¡ÇÏ´Â °æ¿ì bin head·Î¼­ Ãß°¡ÇÑ´Ù.
						//AssertConsist();

						if(pOldBinHead->m_pPrev != NULL)
						{
							pOldBinHead->m_pPrev->m_pNext = pNode;
						}
						else
						{
							// head binÀÌ´Ù. head bin ptrµµ ±³Ã¼ ÇÊ¼ö
							pHeadBinHead = pNode;
						}

						pNode->m_pPrev = pOldBinHead->m_pPrev; // pOldBinHead->m_pPrev = NULL OK
						pNode->m_pNext = pOldBinHead;
						pOldBinHead->m_pPrev = pNode;
						assert(pOldBinHead == ppBins[iDestBin]);
						ppBins[iDestBin] = pNode;

						reAddCount++; // ¸¶¹«¸®

						//AssertConsist();
					}
					else
					{
						// ºó bin¿¡ Ãß°¡ÇÏ´Â °æ¿ì, ÃÖÃÊÀÇ linked binÀÌ µÇ°Ô rewireÇÑ´Ù.
						//AssertConsist();

						CNode* pOldHeadBin = pHeadBinHead;

						pNode->m_pPrev = NULL;
						pNode->m_pNext = pOldHeadBin;
						if(pNode->m_pNext != NULL)
							pNode->m_pNext->m_pPrev = pNode;
						pHeadBinHead = pNode;
						ppBins[iDestBin] = pNode;

						reAddCount++; // ¸¶¹«¸®

						//AssertConsist();
					}

				}

				/*pNode->m_pNext = ppBins[iDestBin];
				pNode->m_pPrev = NULL;
				if(ppBins[iDestBin] != NULL)
					ppBins[iDestBin]->m_pPrev = pNode;

				ppBins[iDestBin] = pNode;
				pHeadBinHead = pNode; */

				pNode = pOldNext;
				//reAddCount++;
			}

			assert(reAddCount == m_nElements);

			// ±¸ hash tableÀ» Á¦°ÅÇÏ°í ½Å hash table·Î ±³Ã¼ÇÑ´Ù.
			CProcHeap::Free(m_ppBins);
			m_ppBins = ppBins;
			m_nBins = nBins;
			m_pHeadBinHead = pHeadBinHead;
			m_pTailBinTail = pTailBinTali;

			AssertConsist();

			UpdateRehashThresholds();

#ifdef ENABLE_REHASH_COUNT
			InterlockedIncrement(&FastMap_RehashCount);
#endif // ENABLE_REHASH_COUNT
		}

		/**
		\~korean
		¸ÊÀÇ ÃÖÀû ºÎÇÏ¸¦ Àç¼³Á¤ÇÕ´Ï´Ù. ¸ÊÀÇ ÃÖÀû ºÎÇÏ¿¡ ´ëÇØ¼­´Â <a target="_blank" href="http://guide.nettention.com/cpp_ko#hash_map_load" >¸Ê Å¬·¡½ºÀÇ ºÎÇÏ</a> ¿¡ ÀÖ½À´Ï´Ù.

		\param fOptimalLoad ÃÖÀû ºÎÇÏ ºñÀ²ÀÔ´Ï´Ù.
		\param fLoThreshold ºÎÇÏ ºñÀ²ÀÇ ÃÖ¼Ò ÇÑ°èÀÔ´Ï´Ù.
		\param fHiThreshold ºÎÇÏ ºñÀ²ÀÇ ÃÖ´ë ÇÑ°èÀÔ´Ï´Ù.
		\param bRehashNow trueÀÌ¸é ÇØ½ÃÅ×ÀÌºí Àç¼³Á¤ÀÌ Áï½Ã ½ÃÇàµË´Ï´Ù.

		\~english
		Re-sets the optimal load to map. Please refer <a target="_blank" href="http://guide.nettention.com/cpp_en#hash_map_load" >Load of map class</a> for further detail.

		\param fOptimalLoad Optimal load proportion
		\param fLoThreshold Minimum limit of load proportion
		\param fHiThreshold Maximum limit of load proportion
		\param bRehashNow hash table re-setting proccess runs immediately if true.

		\~chinese
		ñìãæ?öÇmapîÜõÌÊ¢?ùÃ¡£?mapîÜõÌÊ¢?ùÃîÜ?é»î¤<a target="_blank" href="http://guide.nettention.com/cpp_zh#hash_map_load" >Map ?îÜ?ùÃ</a> %¡£
		\param fOptimalLoad õÌÊ¢?ùÃîÜİïáã¡£
		\param fLoThreshold õÌÊ¢?ùÃİïáãîÜõÌá³Í£ùÚ¡£
		\param fHiThreshold õÌÊ¢?ùÃİïáãîÜõÌÓŞÍ£ùÚ¡£
		\param bRehashNow trueîÜ??Ø¡??ú¼hash tableîÜñìãæ?öÇ?Ø¡??ú¼¡£

		\~japanese
		«Ş«Ã«×ªÎõÌîêİ¶ùÃªòî¢àâïÒª·ªŞª¹¡£«Ş«Ã«×ªÎõÌîêİ¶ùÃªË?ª·ªÆªÏ¡¢\ref hash_map_loadªËª¢ªêªŞª¹¡£
		\param fOptimalLoad õÌîêİ¶ùÃİïáãªÇª¹¡£
		\param fLoThreshold İ¶ùÃİïáãªÎõÌá³ùÚÍ£ªÇª¹¡£
		\param fHiThreshold İ¶ùÃİïáãªÎõÌÓŞùÚÍ£ªÇª¹¡£
		\param bRehashNow trueªÇª¢ªìªĞ«Ï«Ã«·«å«Æ?«Ö«ëî¢àâïÒª¬òÁªÁªËã¿ú¼ªµªìªŞª¹¡£

		\~
		*/
		void SetOptimalLoad( float fOptimalLoad, float fLoThreshold, float fHiThreshold,
			bool bRehashNow = false )
		{
			assert( fOptimalLoad > 0 );
			assert( (fLoThreshold >= 0) && (fLoThreshold < fOptimalLoad) );
			assert( fHiThreshold > fOptimalLoad );

			m_fOptimalLoad = fOptimalLoad;
			m_fLoThreshold = fLoThreshold;
			m_fHiThreshold = fHiThreshold;

			UpdateRehashThresholds();

			if ( bRehashNow && ((m_nElements > m_nHiRehashThreshold) ||
				(m_nElements < m_nLoRehashThreshold)) )
			{
				Rehash( PickSize( m_nElements ) );
			}
		}

		/**
		\~korean
		lookup ÃÖÀû ¼º´É, À¢¸¸ÇØ¼­´Â rehash¸¦ ÃÖ´ëÇÑ ¾ÈÇÏ°í, ±× ´ë½Å ¸Ş¸ğ¸®¸¦ ¸¹ÀÌ »ç¿ëÇÏ´Â ¼³Á¤.
		Áõ°¨ÆøÀÌ ¿ö³« Å«µ¥´Ù rehash cost°¡ Å« °æ¿ì¿¡ À¯¿ëÇÏ´Ù.

		\param rehashNow ¼³Á¤ÇÏ¸é¼­ Rehash¸¦ ÇÒ°ÍÀÎÁö¸¦ ¼±ÅÃÇÑ´Ù. trueÀÌ¸é Rehash¸¦ ÇÔ

		\~english 
		Lookup optimum performance. Configuration to avoid rehash as much as possible but instead use a lot of memory. 
		\param Select whether to rehash when configuring. If true, rehash. 

		\~chinese
		Lookup õÌÊ¢àõÒö£¬?Ê¦ÒöÜôé©õÌÓŞûùrehash£¬ŞÅéÄ?Òı?ğíîÜ?öÇ¡£
		ñò?øëÓøÜâ?ö¦ÓŞ£¬rehash cost ÓŞîÜ?ı¦??êóéÄ¡£

		\param rehashNow ĞÆËß?öÇ??ãÀÜúé©Rehash¡£True îÜ??Rehash¡£

		\~japanese
		lookup õÌîêàõÒö¡¢ªÇª­ªìªĞrehashªòª·ªÊª¯ªÆ¡¢ª½ªÎÓÛªïªêªË«á«â«ê?ªòÒıª¯ŞÅéÄª¹ªëàâïÒ¡£
		?Êõøëª¬ªÈªÆªâÓŞª­ª¤ª·¡¢rehash costª¬ÓŞª­ª¤íŞùêªËêóéÄªÇª¹¡£
		\param rehashNow àâïÒª·ªÊª¬ªéRehashªòª¹ªëª«ªÉª¦ª«ªòàÔ?ª·ªŞª¹¡£TrueªÇª¢ªìªĞRehashªòú¼ª¤ªŞª¹¡£

		\~
		*/
		void SetOptimalLoad_BestLookup(bool rehashNow = false)
		{
			SetOptimalLoad(0.1f,0.0000001f,2.1f,rehashNow);
		}


		/**
		\~korean
		°¢ binÀ» µÚÁ®¼­, ÃÖ¾ÇÀÇ bin, Áï °¡Àå ¸¹Àº itemÀ» °¡Áø binÀÇ item °¹¼ö¸¦ ¸®ÅÏÇÑ´Ù.

		\~english 
		Search each bin and return the worst bin, in other words, the number of items of the bin with the most items. 

		\~chinese
		?ÊÀ?bin£¬Ú÷üŞõÌ?îÜbin£¬??êóõÌÒıitemîÜbinîÜitem??¡£

		\~japanese
		ÊÀbinªò÷®ª·ªÆ¡¢õÌ?ªÎbin¡¢?ªÁìéÛãÒıª¤itemªòò¥ªÄbinªÎitem?ªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		intptr_t GetWorstBinItemCount()
		{
			intptr_t worstValue = 0;

			CNode* prevNode = NULL;
			intptr_t itemCountInCurrentBin = 0;
			for(CNode* pNode = m_pHeadBinHead; pNode!=NULL;pNode=pNode->m_pNext)
			{
				if(prevNode != NULL && prevNode->m_nBin == pNode->m_nBin)
				{
					itemCountInCurrentBin++;
				}
				else
					itemCountInCurrentBin = 1;
				worstValue = PNMAX(worstValue, itemCountInCurrentBin);
			}

			return worstValue;
		}


// #ifdef _DEBUG
// 		void AssertValid() const
// 		{
		// 			assert( m_nBins > 0 );
// 			// non-empty map should have hash table
// 			assert( IsEmpty() || (m_ppBins != NULL) );
// 		}
// #endif  // _DEBUG

		void EnableSlowConsistCheck()
		{
			m_enableSlowConsistCheck = true;
		}

		/**
		\~korean
		map °´Ã¼ÀÇ keyµéÀ» ¸ğÀº ¹è¿­À» ¸¸µé¾î Á¦°øÇÕ´Ï´Ù.

		\~english
		Provide array that contain key of map objects

		\~chinese
		?Ëï?ğ«Íêâ¥ó¢map?ßÚkeyîÜ??¡£

		\~japanese
		map «ª«Ö«¸«§«¯«ÈªÎkeyªòó¢ªáª¿ÛÕÖªªòíÂªÃªÆğ«Íêª·ªŞª¹¡£
		\~
		 */
		void KeysToArray(CFastArray<K> &output) const
		{
			output.Clear();
			output.SetCount(GetCount());
			int c = 0;

			for(ConstIterType i=CFastMap<K,V>::begin();i!=CFastMap<K,V>::end();i++)
			{
				output[c] = i.GetFirst();
				c++;
			}
		}

		/**
		\~korean
		map °´Ã¼ÀÇ valueµéÀ» ¸ğÀº ¹è¿­À» ¸¸µé¾î Á¦°øÇÕ´Ï´Ù.

		\~english
		Provide array that contain value of map objects

		\~chinese
		?Ëï?ğ«Íêâ¥ó¢map?ßÚvalueîÜ??¡£

		\~japanese
		map «ª«Ö«¸«§«¯«ÈªÎvalueªòó¢ªáª¿ÛÕÖªªòíÂªÃªÆğ«Íêª·ªŞª¹¡£
		\~
		 */
		void ValuesToArray(CFastArray<V> &output) const
		{
			output.Clear();
			output.SetCount(GetCount());
			int c = 0;
			for(ConstIterType i=CFastMap<K,V>::begin();i!=CFastMap<K,V>::end();i++)
			{
				output[c] = i.GetSecond();
				c++;
			}
		}

		/**
		\~korean
		³»ºÎ »óÅÂ°¡ ±úÁø °ÍÀÌ ¾ø´ÂÁö È®ÀÎÇÑ´Ù.
		- Å©±â°¡ Å©´õ¶óµµ inlineÀ¸·Î ÇØµÖ¾ß ºó ÇÔ¼öÀÏ¶§ noop°¡ µÈ´Ù. (regardless of compilers)

		\~english
		Must check if there exitst any cracked internal status
		- Must set this as inline though its size is big in order to make noop when function is empty. (regardless of compilers)

		\~chinese
		??ãÀÜúêó?İ»??ÜôÕŞîÜ¡£
		- ?ŞÅé»ÕáÓŞå¥é©inlineî¦Òöî¤ÍöùŞ?îÜ?ı¦à÷?noop¡£(regardless of compilers)

		\~japanese
		?İ»?÷¾ª¬?ªìª¿ªâªÎª¬ªÊª¤ª«ü¬ìãª·ªŞª¹¡£
		- «µ«¤«ºª¬ÓŞª­ª¯ªÆªâinlineªËª·ªÆª³ª½ÍöªÎ??ªÇª¢ªëãÁªËnoopªËªÊªêªŞª¹¡£(regardless of compilers)

		\~
		 */
		inline void AssertConsist() const
		{
			// UnitTester¿¡¼­ ¸±¸®Áî ºôµå¿¡¼­µµ ÀÛµ¿ÇØ¾ß ÇÏ¹Ç·Î
			if(m_enableSlowConsistCheck)
			{
				int count=0;

				if( ! (IsEmpty() || (m_ppBins != NULL) ) )
				{
					assert(0);
					ThrowException("CFastMap consistency error #0!");
				}

				for(CNode* pNode = m_pHeadBinHead; pNode!=NULL;pNode=pNode->m_pNext)
				{
					if(pNode->m_pNext)
					{
						if(pNode->m_pNext->m_pPrev != pNode)
						{
							assert(0);
							ThrowException("CFastMap consistency error #1!");
						}
					}
					if(pNode==m_pHeadBinHead)
					{
						if(pNode->m_pPrev)
						{
							assert(0);
							ThrowException("CFastMap consistency error #2!");
						}
					}
					if(pNode==m_pTailBinTail)
					{
						if(pNode->m_pNext)
						{
							assert(0);
							ThrowException("CFastMap consistency error #3!");
						}
					}
					count++;
				}

				if(count != (int)m_nElements)
				{
					for(CNode* pNode = m_pHeadBinHead; pNode!=NULL;pNode=pNode->m_pNext)
					{
						NTTNTRACE("Node at Bin #%d\n",pNode->m_nBin);
					}

					assert(0);
					ThrowException("CFastMap consistency error #4!");
				}
			}
		}


		// Implementation
	private:
		inline bool IsLocked() const throw()
		{
			return( m_nLockCount != 0 );
		}

		// map¿¡ µé¾îÀÖ´Â ÃÑ Ç×¸ñ °¹¼ö¿¡ ±Ù°ÅÇØ¼­ °¡Àå ÀûÀıÇÑ hash tableÀÇ Å©±â°ªÀ» ¾ò´Â´Ù.
		uint32_t PickSize( intptr_t nElements ) const throw()
		{

			intptr_t nBins = (intptr_t)(nElements / m_fOptimalLoad);
			uint32_t nBinsEstimate = uint32_t(  UINT_MAX < (uintptr_t)nBins ? UINT_MAX : nBins );

			// Find the smallest prime greater than our estimate
			int iPrime = 0;
			while ( nBinsEstimate > FastMap_primes[iPrime] )
			{
				iPrime++;
			}

			if (FastMap_primes[iPrime] == UINT_MAX )
			{
				return( nBinsEstimate );
			}
			else
			{
				return(FastMap_primes[iPrime] );
			}
		}

		// iBinÀÌ °¡¸®Å°´Â bin¿¡ key °ªÀ» °¡Áö´Â »õ node¸¦ Ãß°¡ÇÏµµ·Ï ÇÑ´Ù. ÀÌ¶§ hash °ªÀº nHashÀÌ´Ù.
		CNode* NewNode( KINARGTYPE key, uint32_t iBin, uint32_t nHash )
		{
			//CNode* pNewNode = new CNode( key, nHash );
			CNode* pNewNode;

			if(m_refHeap)
				pNewNode = (CNode*) m_refHeap->Alloc(sizeof(CNode));
			else
				pNewNode = (CNode*) CProcHeap::Alloc(sizeof(CNode));

			if(pNewNode == NULL)
				ThrowBadAllocException();


			CallConstructor<CNode>(pNewNode, key);
			pNewNode->m_nHash = nHash;
			pNewNode->m_nBin = iBin;

			CNode* pOldBinHead = m_ppBins[iBin];

			AssertConsist();

			// ¿ÏÀü ÃÖÃÊÀÇ Ãß°¡ÀÎ °æ¿ì
			if(m_nElements == 0)
			{
				assert(m_pHeadBinHead == NULL);
				assert(pOldBinHead == NULL);
				m_pHeadBinHead = pNewNode;
				m_pTailBinTail = pNewNode;
				pNewNode->m_pPrev = NULL;
				pNewNode->m_pNext = NULL;

				m_ppBins[iBin] = pNewNode;

				m_nElements++; // ¸¶¹«¸®

				AssertConsist();
			}
			else
			{
				//¾ÕÂÊ Çìµå·Î ºÙÀÌ¹Ç·Î tail¿¡´Â º¯È­°¡ ¾ø´Ù.
				AssertConsist();

				if(pOldBinHead != NULL)
				{
					// µé¾îÀÖ´Â bin¿¡ Ãß°¡ÇÏ´Â °æ¿ì bin head·Î¼­ Ãß°¡ÇÑ´Ù.
					AssertConsist();

					if(pOldBinHead->m_pPrev != NULL)
					{
						pOldBinHead->m_pPrev->m_pNext = pNewNode;
					}
					else
					{
						// head binÀÌ´Ù. head bin ptrµµ ±³Ã¼ ÇÊ¼ö
						m_pHeadBinHead = pNewNode;
					}

					pNewNode->m_pPrev = pOldBinHead->m_pPrev; // pOldBinHead->m_pPrev = NULL OK
					pNewNode->m_pNext = pOldBinHead;
					pOldBinHead->m_pPrev = pNewNode;
					assert(pOldBinHead == m_ppBins[iBin]);
					m_ppBins[iBin] = pNewNode;

					m_nElements++; // ¸¶¹«¸®

					AssertConsist();
				}
				else
				{
					// ºó bin¿¡ Ãß°¡ÇÏ´Â °æ¿ì, ÃÖÃÊÀÇ linked binÀÌ µÇ°Ô rewireÇÑ´Ù.
					AssertConsist();

					CNode* pOldHeadBin = m_pHeadBinHead;

					pNewNode->m_pPrev = NULL;
					pNewNode->m_pNext = pOldHeadBin;
					if(pNewNode->m_pNext != NULL)
						pNewNode->m_pNext->m_pPrev = pNewNode;
					m_pHeadBinHead = pNewNode;
					m_ppBins[iBin] = pNewNode;

					m_nElements++; // ¸¶¹«¸®

					AssertConsist();
				}

			}

			AssertConsist();

			// °¹¼ö°¡ Áö³ªÄ¡°Ô ¸¹¾ÆÁ³À¸¸é rehashÇÑ´Ù.
			if ( (m_nElements > m_nHiRehashThreshold) && !IsLocked() )
			{
				Rehash( PickSize( m_nElements ) );
			}

			AssertConsist();

			return( pNewNode );
		}

		// node Á¦°ÅÀÇ ¸¶Áö¸· ´Ü°è
		void FreeNode( CNode* pNode, bool rehashOnNeed )
		{
			assert( pNode != NULL );
			CallDestructor<CNode>(pNode);
			if(m_refHeap)
				m_refHeap->Free(pNode);
			else
				CProcHeap::Free(pNode);

			//delete pNode;

			assert( m_nElements > 0 );
			m_nElements--;

			if ( rehashOnNeed && (m_nElements < m_nLoRehashThreshold) && !IsLocked() )
			{
				Rehash( PickSize( m_nElements ) );
			}
		}

		/*
		\~korean
		Æ¯Á¤ key¸¦ °¡Áø node¸¦ Ã£µÇ ºÎ¼ö Á¤º¸µµ °°ÀÌ Ã£´Â´Ù. ³»ºÎ ÇÔ¼ö
		\param [out] iBin node°¡ ¼ÓÇÑ binÀÇ index
		\param [out] nHash nodeÀÇ hashed value
		\param [out] pPrev nodeÀÇ prev node

		\~english
		Finds the node with certain key but also searches attached info. An internal function.
		\param [out] iBin index of bin that node is possessed
		\param [out] nHash hashed value of node
		\param [out] pPrev prev node of node


		\~chinese
		?Óğ?êó÷åïÒkeyîÜnode£¬ÔÒ?å¥é©?Óğİ¾Ê¥ãáãÓ¡£?İ»ùŞ?¡£
		\param [out] iBin nodeá¶?îÜbinîÜindex¡£
		\param [out] nHash nodeîÜhashed value¡£
		\param [out] pPrev nodeîÜprey node¡£

		\~japanese
		÷åïÒkeyªòò¥ªÄnodeªò÷®ª·ªŞª¹ª¬¡¢Üõ?ï×ÜÃªâìé?ªË÷®ª·ªŞª¹¡£?İ»??
		\param [out] iBin nodeª¬?ª·ª¿binªÎindex
		\param [out] nHash nodeªÎhashed value
		\param [out] pPrev nodeªÎprev node

		\~
		*/
		CNode* GetNode( KINARGTYPE key, uint32_t& iBin, uint32_t& nHash ) const throw()
		{
			// hashÇÑ °ªÀ» ¾ò°í, ÀûÀıÇÑ bin index¸¦ ¾ò´Â´Ù.
			nHash = KTraits::Hash( key );
			iBin = nHash % m_nBins;

			// ¾ÆÁ÷ binÀÌ ¾øÀ¸¸é Áñ
			if ( m_ppBins == NULL )
			{
				return( NULL );
			}

			// bin¿¡¼­ key¿Í °°Àº Ç×¸ñÀ» ¼øÈ¸ÇÏ¸ç Ã£´Â´Ù.
			for ( CNode* pNode = m_ppBins[iBin];
				(pNode != NULL && iBin == pNode->m_nBin);
				pNode = pNode->m_pNext )
			{
				if ( KTraits::CompareElements( pNode->m_key, key ) )
				{
					return( pNode );
				}
			}

			return( NULL );
		}

		CNode* CreateNode( KINARGTYPE key, uint32_t iBin, uint32_t nHash ) throw(Exception)
		{
			CNode* pNode;

			if ( m_ppBins == NULL )
			{
				if(!InitHashTable( m_nBins ))
					ThrowBadAllocException();
			}

			AssertConsist();

			pNode = NewNode( key, iBin, nHash );

			AssertConsist();

			return( pNode );
		}

		void RemoveNode( CNode* pNode,bool rehashOnNeed=false ) throw(Exception)
		{
			assert( pNode != NULL );
			uint32_t iBin = pNode->m_nBin;

			// Á¦°ÅÇÏ·Á´Â node°¡ À¯ÀÏÇÑ °³Ã¼ÀÎ °æ¿ì
			if(m_nElements == 1)
			{
				m_ppBins[iBin] = NULL;
				m_pHeadBinHead = NULL;
				m_pTailBinTail = NULL;
			}
			else
			{
				// ÀÌ ³ëµå°¡ binÀÇ ¸¶Áö¸· nodeÀÎ °æ¿ì bin entryµµ ¼öÁ¤ÇÑ´Ù.
				if(IsBinUniqueNode(pNode))
					m_ppBins[iBin] = NULL;
				else if(IsBinHeadNode(pNode, iBin))
					m_ppBins[iBin] = pNode->m_pNext;

				// ÀÌ ³ëµå°¡ head binÀÇ head nodeÀÌ¸é head binµµ º¯°æÇÑ´Ù.
				if(pNode == m_pHeadBinHead)
				{
					m_pHeadBinHead = pNode->m_pNext;
					pNode->m_pPrev = NULL;
				}

				// ÀÌ ³ëµå°¡ ÀüÃ¼ binÀÇ ¸¶Áö¸· ³ëµå¶ó¸é ³ëµå º¯°æ..
				if(pNode == m_pTailBinTail)
				{
					m_pTailBinTail = pNode->m_pPrev;
					pNode->m_pNext = NULL;
				}

				// ÀÌ ³ëµåÀÇ ¾ÕµÚ¸¦ ¼­·Î ¿¬°áÇÑ´Ù.
				if(pNode->m_pPrev!=NULL)
					pNode->m_pPrev->m_pNext = pNode->m_pNext;
				if(pNode->m_pNext!=NULL)
					pNode->m_pNext->m_pPrev = pNode->m_pPrev;
			}

			// ¸¶Áö¸· ´Ü°è
			FreeNode( pNode ,rehashOnNeed);

			AssertConsist();
		}

		inline bool IsBinUniqueNode(CNode* pNode) const
		{
			if (pNode->m_pPrev != NULL && (pNode->m_pPrev->m_nBin) == pNode->m_nBin)
				return false;

			if (pNode->m_pNext != NULL && (pNode->m_pNext->m_nBin) == pNode->m_nBin)
				return false;

			return true;
		}

		inline bool IsBinHeadNode(CNode* pNode,int iBin) const
		{
			return pNode == m_ppBins[iBin];
		}

		inline CNode* FindNextNode( CNode* pNode ) const throw()
		{
			if (pNode == NULL)
			{
				assert(false);
				return NULL;
			}

			return pNode->m_pNext;
		}

		inline CNode* FindPrevNode( CNode* pNode ) const throw()
		{
			if (pNode == NULL)
			{
				assert(false);
				return NULL;
			}

			return pNode->m_pPrev;
		}

		void UpdateRehashThresholds() throw()
		{
			m_nHiRehashThreshold = intptr_t( m_fHiThreshold * m_nBins );
			m_nLoRehashThreshold = intptr_t( m_fLoThreshold * m_nBins );
			if ( m_nLoRehashThreshold < 17 )
			{
				m_nLoRehashThreshold = 0;
			}
		}

		public:
		~CFastMap()
		{
#if !defined(_WIN32)
		//try
		//{
				RemoveAll();
		//}
		//    catch(...)
		//{
		//        assert(false);
		//    }
#else
			//_ATLTRY
			//try
			//{
				RemoveAll();
			//}
			//_ATLCATCHALL()
			//catch(...)
			//{
			//	assert(false);
			//}
#endif
		}


		/**
		\~korean
		CFastMap Àº º¹»ç °¡´ÉÇÑ °´Ã¼ÀÌ´Ù.

		\~english
		CFastMap is an object can be copied.


		\~chinese
		CHashMap ãÀÊ¦ì¤?ğ¤îÜ?ßÚ¡£

		\~japanese
		CFastMapªÏ«³«Ô?Ê¦ÒöªÊ«ª«Ö«¸«§«¯«ÈªÇª¹¡£
		\~
		 */
		CFastMap( const CFastMap& a)
		{
			m_refHeap = a.m_refHeap;
			m_enableSlowConsistCheck = false;

			InitVars(a.m_nBins,a.m_fOptimalLoad,a.m_fLoThreshold,a.m_fHiThreshold);

			RemoveAll();

			for(iterator i=a.begin();i!=a.end();i++)
			{
				Add(i->GetFirst(),i->GetSecond());
			}
		}

		/**
		\~korean
		CFastMap Àº º¹»ç °¡´ÉÇÑ °´Ã¼ÀÌ´Ù.

		\~english
		CFastMap is an object can be copied.


		\~chinese
		CHashMap ãÀÊ¦ì¤?ğ¤îÜ?ßÚ¡£

		\~japanese
		CFastMapªÏ«³«Ô?Ê¦ÒöªÊ«ª«Ö«¸«§«¯«ÈªÇª¹¡£
		\~
		 */
		CFastMap& operator=( const CFastMap& a)
		{
			RemoveAll();

			m_refHeap = a.m_refHeap;
			for(iterator i=a.begin();i!=a.end();i++)
			{
				Add(i->GetFirst(),i->GetSecond());
			}

			return *this;
		}

		/**
		\~korean
		CFastMap Àº ºñÁ¤·Ä containerÀÎÁö¶ó ºñ±³ ¿¬»êÀÌ std.map º¸´Ù ´À¸³´Ï´Ù.

		\~english
		CFastMap is non-array container so it shows slower comparison operation than std.map

		\~chinese
		ì×?ChashMapãÀŞªÖª?container£¬İï??ß©İï std.map%?Ø·¡£

		\~japanese
		CFastMapªÏŞªïÚÖªcontainerì×í­ªÊªÎªÇİïÎòæÑß©ª¬std.mapªèªê?ª¤ªÇª¹¡£
		\~
		 */
		bool Equals( const CFastMap& a) const
		{
			if(a.GetCount() != GetCount())
				return false;

			std::map<K,V> t2,a2;
			for(const_iterator i=begin();i!=end();i++)
			{
				t2.insert(typename std::map<K, V>::value_type(i.GetFirst(), i.GetSecond()));
			}

			for(const_iterator i=a.begin();i!=a.end();i++)
			{
				a2.insert(typename std::map<K, V>::value_type(i.GetFirst(), i.GetSecond()));
			}
			return t2==a2;
		}

	public:
		/**
		\~korean
		key ÁıÇÕÀ» ¸ğ¾Æ¼­ ÁØ´Ù.

		\~english
		Collects and gives key

		\~chinese
		â¥ó¢keyó¢ùê??åø¡£

		\~japanese
		key ó¢ùêªòó¢ªáªÆªäªêªŞª¹¡£
		\~
		 */
		void CopyKeysTo(CFastArray<K> &dest)
		{
			dest.SetCount(size());
			int c = 0;
			for (iterator i = begin();i != end();i++)
			{
				dest[c++] = i->GetFirst();
			}
		}

		/**
		\~korean
		key°¡ ÀÖ´ÂÁö È®ÀÎÇÑ´Ù.
		\return Å°°¡ ÀÖÀ¸¸é true

		\~english
		Checks if there is key
		\return If there is key then true

		\~chinese
		??ãÀÜúêókey¡£
		\retur êókeyîÜ?true¡£

		\~japanese
		Keyª¬ª¢ªëª«ü¬ìãª·ªŞª¹¡£ 
		\return «­?ª¬ª¢ªìªĞ true

		\~
		 */
		inline bool ContainsKey(const K& key)
		{
			return find(key) != end();
		}

		/**
		\~korean
		value°¡ ÀÖ´ÂÁö È®ÀÎÇÑ´Ù.

		\~english
		Checks if there is value

		\~chinese
		??ãÀÜúêóvalue¡£

		\~japanese
		Valueª¬ª¢ªëª«ü¬ìãª·ªŞª¹¡£
		\~
		 */
		bool ContainsValue(const V& val)
		{
			for (iterator i = begin();i!= end();i++)
			{
				if (val == i->GetSecond())
					return true;
			}
			return false;
		}

		/**
		\~korean
		key¿¡ ´ëÀÀÇÏ´Â value°¡ ÀÖÀ¸¸é true¸¦ ¸®ÅÏÇÑ´Ù.

		\~english
		Returns true if there exist value corresponds to key

		\~chinese
		êó??keyîÜvalueîÜ?Ú÷üŞtrue¡£

		\~japanese
		KeyªË??ª¹ªëvalueª¬ª¢ªìªĞ¡¢trueªò«ê«¿?«óª·ªŞª¹¡£
		\~
		 */
		inline bool TryGetValue(KINARGTYPE key, VOUTARGTYPE value)
		{
			return Lookup(key, value);
		}

		/**
		\~korean
		»õ Ç×¸ñÀ» Ãß°¡ÇÑ´Ù.
		\param key Ãß°¡ÇÒ Ç×¸ñÀÇ key
		\param value Ãß°¡ÇÒ Ç×¸ñÀÇ value
		\return ¼º°øÀûÀ¸·Î µé¾î°¬À¸¸é true, ¾Æ´Ï¸é false¸¦ ¸®ÅÏÇÑ´Ù.

		\~english
		Adds a new clause
		\param key key of the clause to be added
		\param value value of the clause to be added
		\return true if successfully entered, otherwise, returns false.

		\~chinese
		ôÕÊ¥ãæ?ÙÍ¡£
		\param key é©ôÕÊ¥îÜ?ÙÍîÜkey¡£
		\param value é©ôÕÊ¥îÜ?ÙÍîÜvalue¡£
		\return à÷Íí?ìıîÜ?true£¬Üú?Ú÷üŞfalse¡£

		\~japanese
		ãæª·ª¤ú£ÙÍªòõÚÊ¥ª·ªŞª¹¡£
		\param key õÚÊ¥ª¹ªëú£ÙÍªÎkey
		\param value õÚÊ¥ª¹ªëú£ÙÍªÎvalue
		\return à÷ÍíîÜªËìıªÃª¿ªétrue¡¢ª½ªìªÈªâfalseªò«ê«¿?«óª·ªŞª¹¡£

		\~
		 */
		inline bool Add(KINARGTYPE key, VINARGTYPE value)
		{
			// Áßº¹ ÄÚµùÀÌÁö¸¸ ¿ö³« ÀÚÁÖ È£ÃâµÇ±â¿¡ optimize off then code profileÀ» ÇÒ ¶§
			// ´õ Àß º¸ÀÌ°Ô ÇÑ´Ù.
			CNode* pNode;
			uint32_t iBin;
			uint32_t nHash;

			pNode = GetNode(key, iBin, nHash);
			if (pNode != NULL)
			{
				// SetAt°ú ´Ş¸®, ¿©±â¼­´Â ±âÁ¸ °ªÀ» ±³Ã¼ÇÏÁö ¾Ê°í,±×³É Æ÷±âÇÑ´Ù.
				return false;
			}

			pNode = CreateNode(key, iBin, nHash);
			pNode->m_value = value;

			return true;
		}

		class value_type
		{
		public:
			Proud::Position m_pos;
			CFastMap* m_owner;

#if defined(_MSC_VER)
			__declspec(property(get=GetFirst)) const K& first;
			__declspec(property(get=GetSecond,put=SetSecond)) V& second;
#endif

			inline const K& GetFirst() const { return m_owner->GetKeyAt(m_pos); }
			inline V& GetSecond() const { return m_owner->GetValueAt(m_pos); }
			inline void SetSecond(const V& val) const { return m_owner->SetValueAt(m_pos,val); }
		};

		class iterator;
		friend class iterator;

		class reverse_iterator;
		friend class reverse_iterator;

#ifndef PROUDNET_NO_CONST_ITERATOR

		/**
		\~korean
		STLÀÇ const_iterator¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as const_iterator of STL

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

			const_iterator& operator++()
			{
				// preincrement
				value_type::m_owner->GetNext(value_type::m_pos);
				return (*this);
			}

			const_iterator operator++(int)
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

// 			inline const K& first() const
// 			{
// 				return m_owner->GetKeyAt(m_pos);
// 			}
//
// 			inline const V& second() const
// 			{
// 				return m_owner->GetValueAt(m_pos);
// 			}

			inline const value_type& operator*() const
			{
				return *this;
			}

			inline const value_type* operator->() const
			{
				return this;
			}
		};

		class const_reverse_iterator;
		friend class const_reverse_iterator;

		/**
		\~korean
		STLÀÇ iterator°ú °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as iterator of STL

		\~chinese
		ÑÃó·?STLîÜiteratorìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎiteratorªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		 */
		class const_reverse_iterator:public value_type
		{
		public:
			inline const_reverse_iterator(){}
			inline const_reverse_iterator(const reverse_iterator& src):value_type(src){}

			const_reverse_iterator& operator++()
			{
				// preincrement
				value_type::m_owner->GetPrev(value_type::m_pos);
				return (*this);
			}

			const_reverse_iterator operator++(int)
			{
				// postincrement
				const_reverse_iterator _Tmp = *this;
				++*this;
				return (_Tmp);
			}

			inline bool operator==(const const_reverse_iterator& a) const
			{
				return value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner;
			}

			inline bool operator!=(const const_reverse_iterator& a) const
			{
				return !(value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner);
			}

			inline const value_type& operator*() const
			{
				return *this;
			}

			inline const value_type* operator->() const
			{
				return this;
			}

		};
#endif
		/**
		\~korean
		STLÀÇ iterator¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as iterator of STL

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

			/**
			\~korean
			STL iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			ŞÅÔğÑÃó·?STL iteratorìé?íÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline bool operator==(const iterator& a) const
			{
				return value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner;
			}

			/**
			\~korean
			STL iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			ŞÅÔğÑÃó·?STL iteratorìé?íÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline bool operator!=(const iterator& a) const
			{
				return !(value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner);
			}

			/**
			\~korean
			STL iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			ŞÅÔğÑÃó·?STL iteratorìé?íÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline iterator& operator++()
			{
				// preincrement
				value_type::m_owner->GetNext(value_type::m_pos);
				return (*this);
			}

			/**
			\~korean
			STL iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			ŞÅÔğÑÃó·?STL iteratorìé?íÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline iterator operator++(int)
			{
				// postincrement
				iterator _Tmp = *this;
				++*this;
				return (_Tmp);
			}

			/**
			\~korean
			STL iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			ŞÅÔğÑÃó·?STL iteratorìé?íÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline iterator& operator--()
			{
				// preincrement
				value_type::m_owner->GetPrev(value_type::m_pos);
				return (*this);
			}

			/**
			\~korean
			STL iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			ŞÅÔğÑÃó·?STL iteratorìé?íÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline iterator operator--(int)
			{
				// predecrement
				--(*this);
				return (*this);
			}

			/**
			\~korean
			STL iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			ŞÅÔğÑÃó·?STL iteratorìé?íÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline const value_type& operator*() const
			{
				return *this;
			}

			/**
			\~korean
			STL iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL iterator

			\~chinese
			ŞÅÔğÑÃó·?STL iteratorìé?íÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline const value_type* operator->() const
			{
				return this;
			}
		};

		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°ÛößÓÔÒîÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		 */
		inline iterator begin()
		{
			iterator ret;
			ret.m_pos = GetStartPosition();
			ret.m_owner=this;

			return ret;
		}

		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°ÛößÓÔÒîÜíÂéÄ¡£

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

		inline value_type front()
		{
			if(GetCount()==0)
				ThrowInvalidArgumentException();

			return *begin();
		}

		/**
		\~korean
		STLÀÇ iterator¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as iterator of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°ÛößÓÔÒîÜíÂéÄ¡£

		\~japanese
		STLªÎiteratorªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~ */
		class reverse_iterator:public value_type
		{
		public:
			inline reverse_iterator() {}
			inline reverse_iterator(const const_reverse_iterator& src):value_type(src) {}

			/**
			\~korean
			STL reverse_iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			ŞÅÔğÑÃó·?STL reverse_iterator ßÓÔÒíÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL reverse_iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline bool operator==(const reverse_iterator& a) const
			{
				return value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner;
			}

			/**
			\~korean
			STL reverse_iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			ŞÅÔğÑÃó·?STL reverse_iterator ßÓÔÒíÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL reverse_iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline bool operator!=(const reverse_iterator& a) const
			{
				return !(value_type::m_pos==a.m_pos && value_type::m_owner==a.m_owner);
			}

			/**
			\~korean
			STL reverse_iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			ŞÅÔğÑÃó·?STL reverse_iterator ßÓÔÒíÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL reverse_iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline reverse_iterator& operator++()
			{
				// preincrement
				value_type::m_owner->GetPrev(value_type::m_pos);
				return (*this);
			}

			/**
			\~korean
			STL reverse_iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			ŞÅÔğÑÃó·?STL reverse_iterator ßÓÔÒíÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL reverse_iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline reverse_iterator operator++(int)
			{
				// postincrement
				reverse_iterator _Tmp = *this;
				++*this;
				return (_Tmp);
			}

			/**
			\~korean
			STL reverse_iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			ŞÅÔğÑÃó·?STL reverse_iterator ßÓÔÒíÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL reverse_iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline reverse_iterator& operator--()
			{
				// preincrement
				value_type::m_owner->GetNext(value_type::m_pos);
				return (*this);
			}

			/**
			\~korean
			STL reverse_iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			ŞÅÔğÑÃó·?STL reverse_iterator ßÓÔÒíÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL reverse_iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline reverse_iterator operator--(int)
			{
				// predecrement
				--(*this);
				return (*this);
			}

			/**
			\~korean
			STL reverse_iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			ŞÅÔğÑÃó·?STL reverse_iterator ßÓÔÒíÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL reverse_iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline const value_type& operator*() const
			{
				return *this;
			}

			/**
			\~korean
			STL reverse_iterator¿Í °°Àº ¿ªÇÒÀ» ÇÏ°Ô ÇØÁÖ´Â ¿¬»êÀÚ ÇÔ¼ö

			\~english
			Operator Function that lets this perform a role as STL reverse_iterator

			\~chinese
			ŞÅÔğÑÃó·?STL reverse_iterator ßÓÔÒíÂéÄîÜ?ß©íºùŞ?¡£

			\~japanese
			STL reverse_iteratorªÎªèª¦ªÊæµùÜªòª¹ªëªèª¦ªËª¹ªëæÑß©í­??
			\~
			 */
			inline const value_type* operator->() const
			{
				return this;
			}
		};

		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLÔÒÙ£Û°ÛößÓÔÒîÜîÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline reverse_iterator rbegin()
		{
			reverse_iterator ret;
			ret.m_pos = GetEndPosition();
			ret.m_owner=this;

			return ret;
		}

		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLÔÒÙ£Û°ÛößÓÔÒîÜîÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		 */
		inline reverse_iterator rend()
		{
			reverse_iterator ret;
			ret.m_pos=NULL;
			ret.m_owner=this;

			return ret;
		}


#ifndef PROUDNET_NO_CONST_ITERATOR
		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLÔÒÙ£Û°ÛößÓÔÒîÜîÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline const_iterator begin() const
		{
			const_iterator ret;
			ret.m_pos = GetStartPosition();
			ret.m_owner = (CFastMap*)this;

			return ret;
		}

		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLÔÒÙ£Û°ÛößÓÔÒîÜîÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		 */
		inline const_iterator end() const
		{
			const_iterator ret;
			ret.m_pos=NULL;
			ret.m_owner=(CFastMap*)this;

			return ret;
		}

		inline const_reverse_iterator rbegin() const
		{
			const_reverse_iterator ret;
			ret->m_pos = GetEndPosition();
			ret->m_owner = (CFastMap*)this;

			return ret;
		}

		inline const_reverse_iterator rend() const
		{
			const_reverse_iterator ret;
			ret->m_pos = NULL;
			ret->m_owner = (CFastMap*)this;

			return ret;
		}
#endif


		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLÔÒÙ£Û°ÛößÓÔÒîÜîÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		 */
		reverse_iterator erase(reverse_iterator iter)
		{
			if(iter.m_owner!=this)
			{
				ThrowInvalidArgumentException();
			}
			reverse_iterator ret = iter;
			ret++;
			RemoveAtPos(iter.m_pos);

			return ret;
		}

		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLÔÒÙ£Û°ÛößÓÔÒîÜîÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		 */
		iterator erase(iterator iter)
		{
			if(iter.m_owner!=this)
			{
				ThrowInvalidArgumentException();
			}
			iterator ret = iter;
			ret++;
			RemoveAtPos(iter.m_pos);

			return ret;
		}
		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLÔÒÙ£Û°ÛößÓÔÒîÜîÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		 */
		iterator find(const K& key)
		{
			iterator ret;
			ret.m_owner=this;
			uint32_t iBin,nHash;
			CNode* node = GetNode(key,iBin,nHash);
			if(node!=NULL)
			{
				ret.m_pos=Proud::Position(node);
			}
			else
			{
				ret.m_pos=NULL;
			}

			return ret;
		}

#ifndef PROUDNET_NO_CONST_ITERATOR
		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLÔÒÙ£Û°ÛößÓÔÒîÜîÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		 */
		const_iterator find(const K& key) const
		{
			const_iterator ret;
			ret.m_owner=(CFastMap*)this;
			uint32_t iBin,nHash;
			CNode* node = GetNode(key,iBin,nHash);
			if(node!=NULL)
			{
				ret.m_pos=Proud::Position(node);
			}
			else
			{
				ret.m_pos=NULL;
			}

			return ret;
		}

#endif
		/**
		\~korean
		³»ºÎ ¹öÆÛ·Î CFastHeap À» »ç¿ëÇÑ´Ù.
		\param heap CFastHeap Æ÷ÀÎÅÍ

		\~english 
		Use CFastHeap with the internal buffer. 
		\param CFastHeap pointer 

		\~chinese
		ŞÅéÄ CFastHeap%??İ»buffer¡£
		\param heap CFastHeap%ò¦?¡£

		\~japanese
		?İ»«Ğ«Ã«Õ«¡?ªÇCFastHeapªòŞÅéÄª·ªŞª¹¡£
		\param heap CFastHeap «İ«¤«ó«¿?

		*/
		void UseFastHeap(CFastHeap* heap)
		{
			if(heap == NULL)
			{
				ThrowInvalidArgumentException();
			}
			if(GetCount() > 0)
				ThrowException(CannotUseFastHeapForFilledCollectionErrorText);
			m_refHeap = heap;
		}

		inline CFastHeap* GetRefFastHeap() { return m_refHeap; }
	};

#ifdef ENABLE_REHASH_COUNT
	extern PROUDNET_VOLATILE_ALIGN int32_t FastMap_RehashCount;
#endif // ENABLE_REHASH_COUNT

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif