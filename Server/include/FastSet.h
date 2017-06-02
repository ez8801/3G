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

#include "FastMap.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	/** 
	\~korean
	CFastMap °ú ´Ş¸® key¸¸À» °¡Áö´Â Å¬·¡½ºÀÌ´Ù. 
	- ³ª¸ÓÁö´Â CFastMap °ú ¼ºÇâÀÌ °°´Ù. CFastMap À» Âü°íÇÒ °Í. 

	\param K Äİ·º¼ÇÀÇ °ª Å¸ÀÔ
	\param KTraits Äİ·º¼ÇÀÇ °ª Å¸ÀÔÀ» ´Ù·ç´Â Æ¯¼ºÀ» Á¤ÀÇÇÑ Å¬·¡½º
	\param AllocT AllocType °ª Áß ÇÏ³ª

	\~english
	Not like CFastMap, this is a class that only possesses key. 
	- Has same nature as CFastMap for the rest. Please refer CFastMap. 

	\param K value type of collection
	\param KTraits class that defines the characteristics that handle value type of collection
	\param AllocT one of the values of AllocType

	\~chinese
	? CFastMap%ÜôÔÒ£¬ñş?êókeyîÜ?¡£
	- í¥ù»îÜ?? CFastMap%?ú¾ßÓÔÒ¡£??ÍÅ CFastMap%¡£

	\param K collectionîÜ??úş¡£
	\param KTraits ïÒ??×âcollection??úşîÜ÷åàõîÜ?¡£
	\param AllocT AllocType?ñéñıìé¡£

	\~japanese
	CfastMapªÈªÏêŞªÃªÆ¡¢«­?ªÎªßªòò¥ªÄ«¯«é«¹ªÇª¹¡£ 
	- ?ªêªÏCFastMapªÈàõú¾ª¬ÔÒª¸ªÇª¹¡£CFastMap ªòª´?ğÎª¯ªÀªµª¤¡£ 

	\param K «³«ì«¯«·«ç«óªÎö·«¿«¤«×
	\param KTraits «³«ì«¯«·«ç«óªÎö·«¿«¤«×ªòĞâª¦÷åàõªòïÒëùª·ª¿«¯«é«¹
	\param AllocT AllocType ö·ªÎìéªÄ
	\~
	*/
	template < typename K, typename KTraits = CPNElementTraits< K > >
	class CFastSet
	{
		typedef CFastMap<K,char,KTraits, CPNElementTraits< char > > MapType;
		MapType m_intl;
	public:
		class iterator;
		friend class iterator;
		
		/** 
		\~korean
		STLÀÇ iterator¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as iterator of STL

		\~chinese
		ÑÃó·?STLîÜinteratorìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎiteratorªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		class iterator 
		{
			friend class CFastSet;
		public:
			typename MapType::iterator m_iterIntl;

			iterator& operator++()
			{
				// preincrement
				m_iterIntl++;
				return (*this);
			}

			iterator operator++(int)
			{
				// postincrement
				iterator _Tmp = *this;
				m_iterIntl++;
				return (_Tmp);
			}

			inline bool operator==(const iterator& a) const 
			{
				return m_iterIntl == a.m_iterIntl;
			}

			inline bool operator!=(const iterator& a) const 
			{
				return !(m_iterIntl == a.m_iterIntl);
			}

			const K& operator*() const
			{
				return m_iterIntl->GetFirst();
			}

		};

		/** 
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline iterator begin()
		{
			iterator ret;
			ret.m_iterIntl = m_intl.begin();

			return ret;
		}

		/** 
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline iterator end()
		{
			iterator ret;
			ret.m_iterIntl = m_intl.end();

			return ret;
		}

		/** 
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline void insert(const K& val)
		{
			m_intl.Add(val,0);
		}

		/** 
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline intptr_t GetCount()
		{
			return m_intl.GetCount();
		}

#if defined(_MSC_VER)       
		__declspec(property(get=GetCount)) intptr_t Count;
#endif

		inline bool empty()
		{
			return m_intl.IsEmpty();
		}

		inline bool IsEmpty()
		{
			return m_intl.IsEmpty();
		}

		/** 
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline void RemoveAll()
		{
			m_intl.Clear();
		}
		/** 
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline void Clear()
		{
			m_intl.Clear();
		}

		/** 
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline iterator erase(iterator iter)
		{
			iterator ret;
			ret.m_iterIntl = m_intl.erase(iter.m_iterIntl);
			return ret;
		}

		/** 
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Performs a role as same name method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline void erase( const K &key,bool rehashOnNeed = false)
		{
			m_intl.Remove(key,rehashOnNeed);
		}

		/** 
		\~korean
		Ç×¸ñ ÇÏ³ª¸¦ Ã£¾Æ¼­ Á¦°ÅÇÑ´Ù.

		\~english
		Finds a clause and removes it

		\~chinese
		?Óğìé??ÙÍ??ğ¶¡£

		\~japanese
		ìéú£ÙÍªò÷®ª·ªÆğ¶ËÛª·ªŞª¹¡£
		\~
		*/
		inline bool Remove( const K& key,bool rehashOnNeed=false ) 
		{
			return m_intl.Remove(key,rehashOnNeed);
		}

		/** 
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°À½

		\~english
		Same as same name method of STL

		\~chinese
		?STLîÜÔÒÙ£Û°Ûöìé?¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÈÔÒª¸ªÇª¹¡£
		\~
		*/
		inline K front()
		{
			return m_intl.front().GetFirst();
		}

		/** 
		\~korean
		key °¡ ÀÌ ÄÁÅ×ÀÌ³Ê¿¡ ÀÖÀ¸¸é true¸¦ ¸®ÅÏÇÑ´Ù.

		\~english
		Returns true when key is in this container

		\~chinese
		Key î¤container×ìîÜ?Ú÷üŞtrue¡£

		\~japanese
		«­?ª¬ª³ªÎ«³«ó«Æ«Ê?ªËª¢ªìªĞtrueªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		inline bool ContainsKey(const K& key)
		{
			return m_intl.ContainsKey(key);
		}

		/** 
		\~korean
		»õ Ç×¸ñÀ» Ãß°¡ÇÑ´Ù.
		\param key Ãß°¡ÇÒ Ç×¸ñÀÇ key
		\return ¼º°øÀûÀ¸·Î µé¾î°¬À¸¸é true, ¾Æ´Ï¸é false¸¦ ¸®ÅÏÇÑ´Ù.

		\~english
		Adds a new clause
		\param key key of the clause to be added
		\return True if successfully entered, otherwise returns false.

		\~chinese
		ôÕÊ¥ãæ?ÙÍ¡£
		\param key ôÕÊ¥?ÙÍîÜkey¡£
		\return à÷Íí?ìıîÜ?true£¬ÜôãÀîÜ?Ú÷üŞfalse¡£

		\~japanese
		ãæª·ª¤ú£ÙÍªòõÚÊ¥ª·ªŞª¹¡£
		\param key õÚÊ¥ª¹ªëú£ÙÍªÎ«­?
		\return à÷ÍíîÜªËìıªÃª¿ªétrue¡¢ª½ªìªÇªÏªÊª±ªìªĞfalseªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		inline bool Add(const K& key)
		{
			if(ContainsKey(key))
				return false;

			m_intl[key] = 0;
			return true;
		}

		void UseFastHeap(CFastHeap* heap)
		{
			m_intl.UseFastHeap(heap);		
		}
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
