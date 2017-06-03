/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
/*
ProudNet 1.8.38132-dev012


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

#if defined(_WIN32)

#include <map>
#include <vector>
#include "FakeClr.h"
#include "Singleton.h"
#include "Marshaler.h"
#include "Message.h"
#include "PNString.h"
#include "Variant.h"

#include "strpool.h"
#include "ReaderWriterMonitor.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup db_group
	*  @{
	 */

	class CProperty;

	/**
	\~korean 
	PropCollectionÀÇ Message Á÷·ÄÈ­ ÇïÆÛ ±â´É 
	
	\~english 
	PropCollection's Message serialization helper functions

	\~chinese
	PropCollection îÜMessageÍú?helperÍíÒö¡£

	\~japanese
	PropCollectionªÎMessageòÁÖªûù«Ø«ë«Ñ?Ñ¦Òö 
	\~
	*/
	PROUD_API CMessage& operator<<(CMessage& packet, const CProperty &rhs);

	/**
	\~korean 
	PropCollectionÀÇ Message º´·ÄÈ­ ÇïÆÛ ±â´É 
	
	\~english 
	PropCollection's Message deserialization helper functions

	\~chinese
	PropCollection îÜMessage??helperÍíÒö¡£

	\~japanese
	PropCollectionªÎMessage?Öªûù«Ø«ë«Ñ?Ñ¦Òö 
	\~
	*/
	PROUD_API CMessage& operator>>(CMessage& packet,CProperty &rhs);

	/** 
	\~korean
	\brief 0°³ ÀÌ»óÀÇ Named Property¸¦ °¡Áö´Â Collection °´Ã¼ÀÌ´Ù. 
	
	Á¤ÀÇ
	- Unique key container associated with one value. Áï,
	Set of (key as case insensitive string, value as variant).
	Áï, key°ªÀ¸·Î ´ë¼Ò¹®ÀÚ¸¦ ¾È°¡¸®´Â stringÀÌ µé¾î°£´Ù´Â Á¡À» Á¦¿ÜÇÏ¸é Visual BasicÀÇ 
	Collection°ú °°Àº ¿ªÇÒÀ» ÇÑ´Ù. ¿¹¸¦ µé¾î, 
	\code
		{ ('name','baehj'), ('id',123), ('height',176) }
	\endcode

	±â´É
	- value typeÀÌ _variant_t typeÀÌ¹Ç·Î, ÀÌ º¯¼ö¸¦ ´Ù·ê ¶§ÀÇ ÁÖÀÇÁ¡
	ÀÌ ±×´ë·Î Àû¿ëµÈ´Ù.(¿¹¸¦ µé¾î, longÀº ¾²ÀÏ ¼ö ÀÖÀ¸³ª int´Â È£È¯ÀÌ ¾ÈµÊ)
	- PropCollection °´Ã¼ ÀÚÃ¼´Â _variant_t °´Ã¼·Î Ä³½ºÆÃµÉ ¼ö ÀÖ´Ù. ¶ÇÇÑ ¹İ´ëµµ
	°¡´ÉÇÏ´Ù. ÀÌ¶§, PropCollectionÀÇ ³»¿ëÀº _variant_t·Î serializeµÈ´Ù.
	ÀÌ´Â OLE DB¿¡¼­ PropCollectionÀÇ ³»¿ëÀ» binary type field¿¡ ÀúÀåÇÒ ¼ö ÀÖ´Ù.

	»ç¿ë ¿¹
	\code
		PropCollection a;
		a.Fields[L"name"]=L"baehj";
		a.Fields[L"id"]=123L;
		a.Fields[L"height"]=176L;
	\endcode
	ÀÌÁ¦ a¿¡´Â { ('name','baehj'), ('id',123), ('height',176) }°¡ µé¾î°£´Ù.
	\code
		_bstr_t name=a.GetField(L"name");  -- name º¯¼ö¿¡´Â "baehj"°¡ µé¾î°£´Ù.
		_variant_t serialized=a;  //-- serialized¿¡´Â a°¡ serializeµÈ ÇüÅÂÀÇ binary type data°¡ µé¾î°£´Ù.
		PropCollection b;
		b=serialized;	 //-- b´Â a¿Í °°°Ô µÈ´Ù. 
	\endcode 

	\~english
	\brief A collection object that has more than 0 unit of Named Property 
	
	Definition
	- Unique key container associated with one value. Áï, Set of (key as case insensitive string, value as variant).
	  In other words, except the fact that a sting that does not distinguish capital/small letters as key value enters, this acts as Collection of Visual Basic.
	For an example, 
	\code
		{ ('name','baehj'), ('id',123), ('height',176) }
	\endcode

	Function
	- Since its value type is _variant_t type, the considerations must be taken when using this variable apply directly. (For an example, long can be used but int cannot be compatible.)
	- PropCollection object itself can be casted to _variant_t object. And the opposite is also possible. At that time, the contents of PropCollection will serialize to _variant_t.
	  This allows the contents of PropCollection can be stored at binary type field in OLE DB.

	Usage example
	\code
		PropCollection a;
		a.Fields[L"name"]=L"baehj";
		a.Fields[L"id"]=123L;
		a.Fields[L"height"]=176L;
	\endcode
	Now a has { ('name','baehj'), ('id',123), ('height',176) }.
	\code
		_bstr_t name=a.GetField(L"name");  -- "baehj" enters to name variable.
		_variant_t serialized=a;  //-- binary type data that a is serialized will enter serialized.
		PropCollection b;
		b=serialized;	 //-- b becomes equal to a. 
	\endcode 

	\~chinese
	\brief ?êó0?ì¤ß¾Named PropertyîÜCollection?ßÚ¡£

	ïÒ?
	- Unique key container associated with one value. ?,
	Set of (key as case insensitive string, value as variant).
	?£¬ğ¶ÖõéÄkey?Üô?İÂÓŞá³Ùşí®îÜstringù¬?ìıîÜ?£¬ÑÃó·?Visual BasicîÜCollectionìé?îÜíÂéÄ¡£ÖÇåı£¬
	\code
		{ ('name','baehj'), ('id',123), ('height',176) }
	\endcode

	ÍíÒö
	- ì×?value typeãÀ_variant_t type£¬ŞÅéÄó®??îÜ?ı¦îÜñ¼ëòŞÀ??ê«ÜæÜô?îÜù¬ÎÁéÄ¡££¨ÖÇåılongÊ¦ì¤ù¬ŞÅéÄ£¬Ó£ãÀintÜôÒöù¬ÌÂé»£©
	- PropCollection?ßÚÜâãóÊ¦ì¤ù¬casting?_variant_t?ßÚ¡£ì»ó¦ßÓÚãå¥êóÊ¦Òö¡£??PropCollectionîÜ?é»ì¤_variant_tù¬serialize¡£?Ê¦ì¤î¤OLE DB÷êPropCollectionîÜ?é»?ğíî¤binary type fieldñé¡£

	ŞÅéÄÖÇ
	\code
		PropCollection a;
		a.Fields[L"name"]=L"baehj";
		a.Fields[L"id"]=123L;
		a.Fields[L"height"]=176L;
	\endcode
	ïÈù»?a×ì?ìı{ ('name','baehj'), ('id',123), ('height',176) }¡£
	\code
		_bstr_t name=a.GetField(L"name");  -- name??×ì?ìı"baehj"¡£
		_variant_t serialized=a;  //-- serialized×ì?ìıaù¬serializeû¡ãÒîÜbinary type data¡£
		PropCollection b;
		b=serialized;	 //-- b?a?ßÓÔÒ¡£ 
	\endcode

	\~japanese
	\brief 0ËÁì¤ß¾ªÎNamed Propertyªòò¥ªÄCollection«ª«Ö«¸«§«¯«ÈªÇª¹¡£ 

	ïÒëù
	- Unique key container associated with one value. ?ªÁ¡¢
	Set of (key as case insensitive string, value as variant).
	
	?ªÁ¡¢«­?ö·ªÇÓŞá³Ùşí®ªËÏ¬ªéªºªËstringª¬ìıªëªÈª¤ª¦ïÃªòğ¶èâª·ª¿ªéVisual BasicªÎCollectionªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£ÖÇª¨ªĞ¡¢ 
	\code
	{ ('name','baehj'), ('id',123), ('height',176) }
	\endcode

	Ñ¦Òö
	- value typeª¬_variant_t typeªÊªÎªÇ¡¢ª³ªÎ??ªòĞâª¦ãÁªÎñ¼ëòïÃª¬ª½ªÎªŞªŞîêéÄªµªìªŞª¹¡£(ÖÇª¨ªĞ¡¢longªÏŞÅªïªìªŞª¹ª¬¡¢intªÏû»üµªµªìªŞª¹)
	- PropCollection «ª«Ö«¸«§«¯«Èí»?ªÏ¡¢_variant_t «ª«Ö«¸«§«¯«ÈªÇ«­«ã«¹«Æ«£«ó«°ªÇª­ªŞª¹¡£ªŞª¿¡¢Úã?ªâÊ¦ÒöªÇª¹¡£ª³ªÎãÁ¡¢PropCollectionªÎ?é»ªÏ¡¢_variant_tªËserializeªµªìªŞª¦£ó¡£
	ª³ªìªÏOLE DBªÇPropCollectionªÎ?é»ªòbinary type fieldªËÜÁğíª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£

	ŞÅéÄÖÇ
	\code
	PropCollection a;
	a.Fields[L"name"]=L"baehj";
	a.Fields[L"id"]=123L;
	a.Fields[L"height"]=176L;
	\endcode

	ªâª¦¡¢aªËªÏ{ ('name','baehj'), ('id',123), ('height',176) }ª¬ìıªêªŞª¹¡£
	\code
	_bstr_t name=a.GetField(L"name");  -- name ??ªËªÏ"baehj"ª¬ìıªêªŞª¹¡£
	_variant_t serialized=a;  //-- serializedªËªÏaª¬serializeªµªìª¿û¡÷¾ªÎbinary type dataª¬ìıªêªŞª¹¡£
	PropCollection b;
	b=serialized;	 //-- bªÏaªÎªèª¦ªËªÊªêªŞª¹¡£ 
	\endcode 



	\~
	*/
	class CProperty
	{
		friend CMessage& operator<<(CMessage& packet, const CProperty &rhs);
		friend CMessage& operator>>(CMessage& packet,CProperty &rhs);
		CStringPool::Holder m_strpool;

	public:
		/** 
		\~korean
		field ÀÌ¸§°ú °ª¿¡ ´ëÀÀÇÏ´Â map °´Ã¼ÀÌ´Ù.
		- ÁÖÀÇ!! iterationÀ» À§ÇØ ÀÌ µ¥ÀÌÅÍ ¸â¹ö¸¦ Á÷Á¢ Á¢±ÙÇÏ´Â °ÍÀº Çã¶ôÇÏ³ª, ÀĞ±â Àü¿ëÀ¸·Î¸¸ ¾²´Â °ÍÀ» Çã¶ôÇÑ´Ù.  

		\~english
		Map object that corresponds to field name and value
		- Caution!! It is allowed to directly access to this data member for iteration, but only allowed to write as read only.

		\~chinese
		??fieldÙ£ûú?îÜmap?ßÚ¡£
		-ñ¼ëò£¡£¡?ëÃ?ì×iterationïÈĞÎó®?Ëß£¬Ó£ñşëÃ??ñş?ÙşËì¡£

		\~japanese
		fieldÙ£ªÈö·ªË??ª¹ªë«Ş«Ã«×«ª«Ö«¸«§«¯«ÈªÇª¹¡£
		- ª´ñ¼ëò!! IterationªÎª¿ªáªËª³ªÎ«Ç?«¿«á«ó«Ğ?ªòòÁïÈ«¢«¯«»«¹ª¹ªëª³ªÈªÏúÉÊ¦ª·ªŞª¹ª¬¡¢?ªßö¢ªê?éÄªÇªÎªßŞÅª¦ª³ªÈªòúÉÊ¦ª·ªŞª¹¡£  
		\~
		*/
		typedef CFastMap<String, CVariant, StringTraits> MapType;
	protected:
		// ÁÖÀÇ: ¿©±â¿¡ µé¾î°¡´Â value´Â ¹İµå½Ã CStringPool::GetUnsafeRef().GetString(String(key).MakeUpper()) À¸·Î ¾òÀº °Í¸¸ µé¾î°¡¾ß!
		MapType m_map;
	private:
#ifdef _DEBUG
		RefCount<CReaderWriterAccessChecker> m_RWAccessChecker;
#endif // _DEBUG
	public:
		class const_iterator 
		{
			friend CProperty;

//			CProperty* m_owner;
			MapType::const_iterator m_intl;
		public:
			const_iterator() {}
			inline const_iterator(const const_iterator &src) 
			{
//				m_owner = src.m_owner;
				m_intl = src.m_intl;
			}

			inline const_iterator& operator=(const const_iterator &src) 
			{
//				m_owner = src.m_owner;
				m_intl = src.m_intl;

				return *this;
			}

			const_iterator& operator++()
			{
				// preincrement
				m_intl++;
				return (*this);
			}

			const_iterator operator++(int)
			{
				// postincrement
				const_iterator _Tmp = *this;
				++(*this);
				return (_Tmp);
			}

			inline bool operator==(const const_iterator& a) const 
			{
				return m_intl==a.m_intl /*&& m_owner==a.m_owner */;
			}

			inline bool operator!=(const const_iterator& a) const 
			{
				return !(m_intl==a.m_intl /*&& m_owner==a.m_owner */);
			}

			const String GetKey()
			{
				return m_intl->GetFirst();
			}
			CVariant GetValue()
			{
				return m_intl->GetSecond();
			}
			void SetValue(const CVariant &val)
			{
				m_intl->SetSecond(val);
			}
		
#if defined (WIN32)
			__declspec(property(get=GetKey)) const String Key;
			__declspec(property(get=GetValue,put=SetValue)) CVariant Value;
#endif

		};

		const_iterator begin() const
		{
			AssertThreadID(eAccessMode_Read);
			const_iterator ret;
			ret.m_intl = m_map.begin();
			
			ClearThreadID();
			return ret;
		}

		const_iterator end() const
		{
			AssertThreadID(eAccessMode_Read);
			const_iterator ret;
			ret.m_intl = m_map.end();

			ClearThreadID();
			return ret;
		}

		inline size_t GetCount() const
		{
			AssertThreadID(eAccessMode_Read);
			size_t count = m_map.GetCount();
			ClearThreadID();
			return count;
		}
#if defined (WIN32)
		__declspec(property(get = GetCount)) size_t Count;
#endif

		inline void Remove(const String& key)
		{
			AssertThreadID(eAccessMode_Write);
			m_map.Remove(String(key).MakeUpper());
			ClearThreadID();
		}
		inline void Clear()
		{
			AssertThreadID(eAccessMode_Write);
			m_map.Clear();
			ClearThreadID();
		}
		inline bool TryGetValue(const String& key, CVariant& ret)
		{
			AssertThreadID(eAccessMode_Read);
			bool bRet = m_map.TryGetValue(String(key).MakeUpper(), ret);
			ClearThreadID();

			return bRet;
		}
		inline bool ContainsKey(const String& key)
		{
			AssertThreadID(eAccessMode_Read);
			bool bRet = m_map.ContainsKey(String(key).MakeUpper());
			ClearThreadID();
			return bRet;
		}
		inline bool Add(const String& key, const CVariant& val)
		{
			AssertThreadID(eAccessMode_Write);
			bool bRet =m_map.Add(CStringPool::GetUnsafeRef().GetString(String(key).MakeUpper()),val);
			ClearThreadID();
			return bRet;
		}
		inline void CopyKeysTo(CFastArray<String> &dest)
		{
			AssertThreadID(eAccessMode_Read);
			dest.Clear();
			for(const_iterator i = begin(); i!=end();i++)
			{
				dest.Add(i.Key);
			}

			ClearThreadID();
		}

	protected:
		virtual void	AssertThreadID(eAccessMode eMode) const;
		virtual void	ClearThreadID() const;
	public:
		/** 
		\~korean
		ÀÌ collection °´Ã¼¿¡ ÀÖ´Â Æ¯Á¤ (key, value) pair¸¦ ±¸ÇÑ´Ù.
		- ÀÌ ¸Ş¼­µå ´ë½Å Fields[]¸¦ Á÷Á¢ ´Ù·ç´Â °ÍÀÌ ´õ ÆíÇÏ¹Ç·Î ±ÇÀåµÈ´Ù.
		\return pairÀÇ value. ¸¸¾à key¿¡ ÇØ´çÇÏ´Â pair°¡ ¾øÀ¸¸é empty type variant¸¦ ¸®ÅÏÇÑ´Ù.
		\param name key of pair whose value should be retrieved  

		\~english
		Gets a specific (key, value) pair in this collection object
		- Direct handling of Fields[] is recommended since it is easier than using this method.
		\return value of the pair. Returns empty type variant when there is no pair corresponds to key.
		\param name key of pair whose value should be retrieved
		\~chinese
		Ï´î¤ó®collection?ßÚîÜ÷åïÒ(key, value) pair¡£
		- İïÑÃ??Û°Ûö£¬òÁïÈŞÅéÄFields[]ÌÚÛ°øµ£¬ì×ó®Ëï?ŞÅéÄ?¡£
		\return pairîÜvalue¡£åıÍı?êóêó?keyîÜpairîÜ?Ú÷üŞempty type variant¡£
		\param name key of pair whose value should be retrieved

		\~japanese
		ª³ªÎcollection«ª«Ö«¸«§«¯«ÈªËª¢ªë÷åïÒ(key, value)«Ú«¢ªòÏ´ªáªŞª¹¡£
		- ª³ªÎ«á«½«Ã«ÉªÎÓÛªïªêªËFields[]ªòòÁïÈĞâª¦ªÎª¬ªâªÃªÈ?ªÇª¹ªÎªÇªª?ªáª·ªŞª¹¡£
		\return pairªÎvalue¡£ªâª·¡¢keyªËú±?ª¹ªëpairª¬ªÊª±ªìªĞempty type variantªò«ê«¿?«óª·ªŞª¹¡£
		\param name key of pair whose value should be retrieved  
		\~
		*/
		PROUD_API CVariant GetField(const String &name);

		/** 
		\~korean
		ÀÌ collection °´Ã¼¿¡ Æ¯Á¤ (key, value) pair¸¦ ³Ö´Â´Ù. ÀÌ¹Ì °°Àº key¸¦ °¡Áö´Â pair°¡ ÀÖÀ¸¸é ±×°ÍÀ» »õ°É·Î ±³Ã¼ÇÑ´Ù.
		- ÀÌ ¸Ş¼­µå ´ë½Å Fields[]¸¦ Á÷Á¢ ´Ù·ç´Â °ÍÀÌ ´õ ÆíÇÏ¹Ç·Î ±ÇÀåµÈ´Ù.
		\param name key of pair
		\param value value of pair  

		\~english
		Specific (key, value) pair to be entered to this collection object. If there is the pair that has same key than new comer replaces itself with old one.
		- Direct handling of Fields[] is recommended since it is easier than using this method.
		\param name key of pair
		\param value value of pair

		\~chinese
		èÙ??collection?ßÚ?ìı÷åïÒ(key, value) pair¡£åıÍığíî¤?êóßÓÔÒkeyîÜpairîÜ?£¬éÄãæîÜÓÛôğ¡£
		- İïÑÃ??Û°Ûö£¬òÁïÈŞÅéÄFields[]ÌÚÛ°øµ£¬ì×ó®Ëï?ŞÅéÄ?¡£
		\param name key of pair
		\param value value of pair

		\~japanese
		ª³ªÎcollection«ª«Ö«¸«§«¯«ÈªË÷åïÒ(key, value)pairªòìıªìªŞª¹¡£?ªËÔÒª¸keyªòò¥ªÄpairª¬ª¢ªìªĞ¡¢ª½ªìªòãæª·ª¤ªâªÎªËìıªìôğª¨ªŞª¹¡£
		- ª³ªÎ«á«½«Ã«ÉªÎÓÛªïªêªËFields[]ªòòÁïÈĞâª¦ª³ªÈª¬ªâªÃªÈøµ××ªÇª¹ªÎªÇªª?ªáª·ªŞª¹¡£
		\param name key of pair
		\param value value of pair  

		\~
		*/
		PROUD_API virtual void SetField(const String &name,const CVariant &value);

		/** 
		\~korean
		ÀÌ collection °´Ã¼¿¡¼­ Æ¯Á¤ (key, value) pair¸¦ Á¦°ÅÇÑ´Ù.
		\param name Á¦°ÅÇÒ pairÀÇ key °ª  

		\~english
		Removes specific (key, value) pair from this collection object
		\param name key value of pair to be removed

		\~chinese
		?collection?ßÚ?ğ¶÷åïÒ(key, value) pair¡£
		\param name é©?ğ¶îÜpairîÜkey?¡£

		\~japanese
		ª³ªÎcollection«ª«Ö«¸«§«¯«ÈªÇ÷åïÒ(key, value) pairªòğ¶ËÛª·ªŞª¹¡£
		\param name ğ¶ËÛª¹ªëpairªÎkeyö·  
		\~
		*/
		PROUD_API virtual void RemoveField(const String &name);

		/** 
		\~korean
		serialize°¡ µÇ¾î ÀÖ´Â bytearray typeÀÇ variantÀÇ ³»¿ëÀ» deserializeÇØ¼­ ÀÌ °´Ã¼¿¡ Ã¤¿î´Ù.
		\param from.. º¹»ç ¿øº»  

		\~english
		The contents of variant of serialized bytearray type are to be deserialized and to be filled to this object.
		\param from.. oriinal to copy

		\~chinese
		ù¬serializeîÜ bytearray typeîÜvariant?é»?ú¼deserializeı¨?õöÓğó®?ßÚ¡£
		\param from.. ?ğ¤ê«Üâ

		\~japanese
		SerializeªµªìªÆª¤ªëbytearray typeªÎvariantªÎ?é»ªòdeserializeª·ªÆª³ªÎ«ª«Ö«¸«§«¯«ÈªË?ª¿ª·ªŞª¹¡£
		\param from.. «³«Ô?ê«Üâ 
		\~
		*/
		PROUD_API virtual void FromVariant(_variant_t from);

		virtual void FromByteArray(const ByteArray &from);

		PROUD_API virtual void FromByteArray(const uint8_t* data,int length);

		PROUD_API virtual void ToByteArray(ByteArray &output);


		/** 
		\~korean
		±âº» »ı¼ºÀÚ  

		\~english
		Base constructor

		\~chinese
		ĞñÜâßæà÷íº¡£

		\~japanese
		ĞñÜâßæà÷í­  
		\~
		*/
		PROUD_API CProperty();
		PROUD_API CProperty(const CProperty& rhs);

		virtual ~CProperty();

		/** 
		\~korean 
		CVariant type°ú È£È¯µÇ°Ô ÇÏ´Â helper function 
		
		\~english 
		Helper function that make compatibility with CVariant type

		\~chinese
		? CVariant typeÌÂé»îÜhelper function

		\~japanese
		CVariant typeªÈû»üµªµªìªëªèª¦ªËª¹ªëhelper function 
		\~
		*/
		CProperty(_variant_t from);

		/** 
		\~korean 
		_variant_t type°ú È£È¯µÇ°Ô ÇÏ´Â helper function 
		
		\~english 
		Helper function that make compatibility with _variant_t type

		\~chinese
		?_variant_t type ÌÂé»îÜhelper function¡£

		\~japanese
		_variant_t typeªÈû»üµªµªìªëªèª¦ªËª¹ªëhelper function 
		\~
		*/
		PROUD_API operator _variant_t() const;
		PROUD_API operator ByteArrayPtr() const;

		/** 
		\~korean 
		º¹»ç »ı¼ºÀÚ 
		
		\~english 
		Copy creator

		\~chinese
		?ğ¤ßæà÷íº¡£

		\~japanese
		«³«Ô?ßæà÷í­
		\~
		*/
		inline CProperty & operator=( const _variant_t &from)
		{
			FromVariant(from);
			return *this;
		}
		inline CProperty & operator=( ByteArray &from)
		{
			FromByteArray(from);
			return *this;
		}

		inline CProperty & operator=( const CProperty &rhs)
		{
			rhs.AssertThreadID(eAccessMode_Read);
			AssertThreadID(eAccessMode_Write);
			m_map = rhs.m_map;
			ClearThreadID();
			rhs.ClearThreadID();

			return *this;
		}

		/** 
		\~korean
		ÇÊµåÀÇ °ªÀ» ÀĞ°Å³ª ±â·ÏÇÒ ¶§ »ç¿ëÇÑ´Ù. ÀÚ¼¼ÇÑ °ÍÀº \ref dbc1_adding_fields  ÂüÁ¶.  

		\~english
		Used to read or write field value. Please refer \ref db_adding_fields

		\~chinese
		?ûäíº???æ´?îÜ?ı¦ŞÅéÄ¡£????ÍÅ\ref dbc1_adding_fields%¡£

		\~japanese
		«Õ«£?«ë«ÉªÎö·ªò?ªóªÀªêÑÀ?ª¹ªëãÁªËŞÅª¤ªŞª¹¡£ßÙª·ª¯ªÏ¡¢\ref dbc1_adding_fieldsªòª´?ğÎª¯ªÀªµª¤¡£
		\~
		*/
#if defined (WIN32)
		__declspec(property(get=GetField,put=SetField)) CVariant Fields[];
#endif

		/** 
		\~korean
		ÀÌ Äİ·º¼Ç °´Ã¼ÀÇ ³»¿ëÀ» ¹®ÀÚ¿­·Î ¸¸µé¾î¼­ Ãâ·ÂÇÑ´Ù. 
		- µğ¹ö±ëÀ» ÇÒ ¶§ ¿ëÀÌÇÏ´Ù.  

		\~english
		Converts the contents of this collection object into text string then outputs 
		- Useful when debugging

		\~chinese
		÷êó®collection?ßÚîÜ?é»??à÷í®İ¬Íúı¨?õó¡£
		- ?ú¼??îÜ?ı¦????áæ¡£

		\~japanese
		ª³ªÎ«³«ì«¯«·«ç«ó«ª«Ö«¸«§«¯«ÈªÎ?é»ªòÙşí®ÖªªÇíÂªÃªÆõóÕôª·ªŞª¹¡£
		- «Ç«Ğ«Ã«®«ó«°ªòª¹ªëãÁªËé»æ¶ªÇª¹¡£
		\~
		*/
		PROUD_API String GetDumpedText();
	};

	class CDbCacheServerImpl;
	class CDbCacheClientImpl;
    class CDbCacheServer3Impl;
    class CDbCacheClient3Impl;
	class CLoadedData;
	class CLoadedData_S;
	class CLoadedDataTree;
	class CLoadedDataTree_S;
	class CPropForest;
	class CDataTree;
	typedef RefCount<CDataTree> CDataTreePtr;

	/** 
	\~korean 
	PropCollectionÀÇ Message Á÷·ÄÈ­ ÇïÆÛ ±â´É 
	
	\~english 
	PropCollection's Message serialization helper functions 

	\~chinese
	PropCollection îÜMessageÍú?helperÍíÒö¡£

	\~japanese
	PropCollectionªÎMessageòÁÖªûù«Ø«ë«Ñ?Ñ¦Òö 
	\~
	*/
	PROUD_API CMessage& operator<<(CMessage& packet,CDataTree &rhs);

	/** 
	\~korean 
	PropCollectionÀÇ Message º´·ÄÈ­ ÇïÆÛ ±â´É 
	
	\~english 
	PropCollection's Message deserialization helper functions 

	\~chinese
	PropCollection îÜMessage??helperÍíÒö¡£

	\~japanese
	PropCollectionªÎMessage?Öªûù«Ø«ë«Ñ?Ñ¦Òö 
	\~
	*/
	PROUD_API CMessage& operator>>(CMessage& packet,CDataTree &rhs);

	/** 
	\~korean
	Property ¸¦ »ó¼Ó¹ŞÀº Å¬·¡½º·Î¼­ CPropForest ÀÇ ÇÑ°³ÀÇ ³ëµå¸¦ °¡¸®Å²´Ù.
	CDataTreePtr ·Î »ı¼ºÇÏ¿© CLoadedData ÀÇ Á¦°øÇÔ¼öµé¿¡¼­ »ğÀÔÀÌ³ª »èÁ¦¸¦ ÇÏ¸é µÈ´Ù.
	CDataTreePtr node = new(CDataTree(L"Å×ÀÌºíÀÌ¸§"));
	»ç¿ë¿¹´Â CProperty ¸¦ Âü°í.

	\~english
	As the class that inherited Property, it points a node of CPropForest.
	Created using CDataTreePtr and to perform insertion or deletion at the functions provided by CLoadedData
	CDataTreePtr node = new(CDataTree(L"table name"));
	Please refer CProperty for how to use.

	\~chinese
	ãÀ?ã¯PropertyîÜ?£¬ò¦ú¾ CPropForest%îÜìé??ïÃ¡£
	éÄ CDataTreePtr%ßæà÷ı¨î¤ CLoadedData%îÜğ«ÍêùŞ??ìıûäíº?ğ¶?Ê¦¡£
	CDataTreePtr node = new(CDataTree(L"øúÌ«Ù£í®"));
	ŞÅéÄÖÇ??ÍÅ CProperty%¡£

	\~japanese
	PropertyªòßÓ?ª·ªÆªâªéªÃª¿«¯«é«¹ªÈª·ªÆCPropForestªÎìé«Î?«Éªòò¦ª·ªŞª¹¡£
	CPropNodePtrªÇßæà÷ª·ªÆCLoadedDataªÎğ«Íê??ªÊªÉªÇ?ìıªŞª¿ªÏŞûğ¶ª¹ªìªĞÕŞª¤ªÇª¹¡£
	CPropNodePtr node = new(CPropNode(L"«Æ?«Ö«ëÙ£"));
	ŞÅéÄÖÇªÏCPropertyªòª´?ğÎª¯ªÀªµª¤¡£
	\~
	*/
	class CDataTree:public CProperty
	{
		// NOTE: childrenÀ» °¡Áø´Ù. child=ÇÏÀ§ ³ëµå, sibling=¿ìÃø ³ëµå
		friend CLoadedData;
		friend CLoadedData_S;
		friend CLoadedDataTree;
		friend CLoadedDataTree_S;
		friend CPropForest;
		friend CMessage& operator<<(CMessage& packet,CDataTree &rhs);
		friend CMessage& operator>>(CMessage& packet,CDataTree &rhs);
		friend CDbCacheClientImpl;
		friend CDbCacheServerImpl;

		friend CDbCacheClient3Impl;
		friend CDbCacheServer3Impl;

	private:
		//modify by rekfkno1 - ¼­·Î ptr·Î ÂüÁ¶ÇÏ°í ÀÖÀ¸¸é ¿µ¿øÈ÷ ÆÄ±«µÇÁö ¾Ê´Â 
		// Çö»óÀÌ ÀÖ´Ù!!!! ²À!!! Æ÷ÀÎÅÍ·Î »ç¿ëÇÒ°Í...

		/** 
		\~korean
		°´Ã¼¸¦ child·Î ÂüÁ¶ÇÏ°í ÀÖ´Â NodeÀÇ Æ÷ÀÎÅÍ

		\~english
		Pointer of node that refer to object as child

		\~chinese
		÷ê?ßÚ?ğÎ?childîÜNodeîÜò¦?¡£

		\~japanese
		«ª«Ö«¸«§«¯«ÈªòchildªË?ğÎª·ªÆª¤ªëNodeªÎ«İ«¤«ó«¿?
		\~
		*/
		CDataTree*  m_parent;

		/** 
		\~korean
		°´Ã¼¸¦ parent·Î ÂüÁ¶ÇÏ°í ÀÖ´Â NodeÀÇ Æ÷ÀÎÅÍ

		\~english
		Pointer of node that refer to object as parent

		\~chinese
		÷ê?ßÚ?ğÎ?parentîÜNodeò¦?¡£

		\~japanese
		«ª«Ö«¸«§«¯«ÈªòparentªË?ğÎª·ªÆª¤ªëNodeªÎ«İ«¤«ó«¿?
		\~
		*/
		CDataTree*  m_child;

		/** 
		\~korean
		°´Ã¼¿Í µ¿±ŞÀÇ ÂüÁ¶ Æ÷ÀÎÅÍ

		\~english
		Reference point that has same level with object

		\~chinese
		??ßÚÔÒ??îÜ?ğÎò¦?¡£

		\~japanese
		«ª«Ö«¸«§«¯«ÈªÈÔÒĞäªÎ?ğÎ«İ«¤«ó«¿?
		\~
		*/
		CDataTree*  m_sibling;
 
		/*
		sibling ³ëµåÀÇ ¸¶Áö¸· Æ÷ÀÎÅÍ¸¦ °¡Áö°í ÀÖ´Ù.
		*/
		CDataTree*  m_endSibling;

		// 3°¡Áö ±âº» ÇÊµå. ³ëµå ÀÚÃ¼ÀÇ guid
		Guid		m_UUID;
		// »óÀ§ ³ëµåÀÇ guid
		Guid		m_ownerUUID;
		// ÃÖ»óÀ§ ³ëµåÀÇ guid. loaded dataÀÇ ´ÜÀ§ÀÌ±âµµ ÇÏ´Ù.
		Guid		m_RootUUID;

		// 1°³ ÀÌ»óÀÇ field°¡ º¯°æµÇ¾úÁö¸¸ ¾ÆÁ÷ DB¿¡ ±â·ÏµÇÁö ¾Ê¾ÒÀ¸¸é true
		bool		m_dirtyFlag;

		// ·ÎÄÃ ¸Ş¸ğ¸®°¡ º¯È­ÇÏ¸é ¼¼ÆÃµÇ´Â °ª.(soft=unilateral, hard=request/response)
		bool		m_issuedSoft;
	public:
		/** 
		\~korean
		ÀÌ ³ëµåÀÇ Å¸ÀÔÀÌ¸§.
		- DbCacheSystem ¿¡¼­´Â º¸Åë Å×ÀÌºí ÀÌ¸§À¸·Î »ç¿ëµË´Ï´Ù.

		\~english
		Type name of this node.
		- It use for normal table name at DbCacheSystem

		\~chinese
		ó®?ïÃîÜ?úşÙ£í®¡£
		- î¤DbCacheSystemìéÚõŞÅéÄéÍøúÌ«Ù£í®¡£

		\~japanese
		ª³ªÎ«Î?«ÉªÎ«¿«¤«×Ù£
		- DbCacheSystemªÇªÏÜÅ÷×«Æ?«Ö«ëÙ£ªÇŞÅéÄªµªìªŞª¹¡£
		\~
		*/
		String	m_INTERNAL_TypeName;
		inline const PNTCHAR* GetTypeName() const { return m_INTERNAL_TypeName; }
		void SetTypeName(const PNTCHAR* str);

		inline String GetStringTypeName() const {return m_INTERNAL_TypeName;}
		void SetStringTypeName(String str);
	private:
		virtual void FromVariant(_variant_t from) PN_OVERRIDE;

		virtual void FromByteArray(const ByteArray &from) PN_OVERRIDE;

		virtual void FromByteArray(const uint8_t* data,int length) PN_OVERRIDE;
		void	FromByteArray(const uint8_t* data,int length,Guid& siblingUUID);

		void	SoftWorkIssued(){m_issuedSoft = true;}
		void	ClearSoftWorkIssued(){m_issuedSoft = false;}
	public:

		/** 
		\~korean 
		ÀÚ½Ä ³ëµå¸¦ Á¦¿ÜÇÑ »çº»À» »ı¼ºÇÕ´Ï´Ù. 

		\~english
		Clones of this node without children. 

		\~chinese
		Ğº×Ì???ïÃ?êóú©í­¡£(TODO: translation review needed)

		\~japanese
		í­«Î?«Éªòğ¶èâª·ª¿«³«Ô?ªòßæà÷ª·ªŞª¹¡£
		\~ 
		*/
		CDataTreePtr CloneNoChildren();

	public:

		/** 
		\~korean
		ÀÌ node °´Ã¼¿¡ Æ¯Á¤ (key, value) pair¸¦ ³Ö´Â´Ù. ÀÌ¹Ì °°Àº key¸¦ °¡Áö´Â pair°¡ ÀÖÀ¸¸é ±×°ÍÀ» »õ°É·Î ±³Ã¼ÇÑ´Ù.
		- ÀÌ ¸Ş¼­µå ´ë½Å Fields[]¸¦ Á÷Á¢ ´Ù·ç´Â °ÍÀÌ ´õ ÆíÇÏ¹Ç·Î ±ÇÀåµÈ´Ù.
		\param name key of pair
		\param value value of pair  

		\~english
		Put specific (key, value) pair to node object. If pair with same key is existed then replace it to brandnew one.
		- We recommend to use Fields[] instead of this method.
		\param name key of pair
		\param value value of pair  

		\~chinese
		èÙ??node?ßÚ?ìı÷åïÒ(key, value) pair¡£åıÍığíî¤?êóßÓÔÒkeyîÜpairîÜ?£¬éÄãæîÜÓÛôğ¡£
		- İïÑÃ??Û°Ûö£¬òÁïÈŞÅéÄFields[]ÌÚÛ°øµ£¬ì×ó®Ëï?ŞÅéÄ?¡£
		\param name key of pair
		\param value value of pair

		\~japanese
		ª³ªÎnode«ª«Ö«¸«§«¯«ÈªË÷åïÒ(key, value) pairªòìıªìªŞª¹¡£?ªËÔÒª¸keyªòò¥ªÄpairª¬ª¢ªìªĞª½ªìªòãæª·ª¤ªâªÎªËìıªìôğª¨ªŞª¹¡£
		- ª³ªÎ«á«½«Ã«ÉªÎÓÛªïªêªËFields[]ªòòÁïÈĞâªÃª¿Û°ª¬ªâªÃªÈ?ªÇª¹ªÎªÇªª?ªáª·ªŞª¹¡£
		\param value value of pair  
		\~
		*/
		PROUD_API virtual void SetField(const String &name,const CVariant &value) PN_OVERRIDE;

		/** 
		\~korean
		ÀÌ node °´Ã¼¿¡¼­ Æ¯Á¤ (key, value) pair¸¦ Á¦°ÅÇÑ´Ù.
		\param name Á¦°ÅÇÒ pairÀÇ key °ª  

		\~english
		Remove specific (key, value) pair from this node object.
		\param name Key value of pair that need to remove

		\~chinese
		?node?ßÚ?ğ¶÷åïÒ(key, value) pair¡£
		\param name é©?ğ¶îÜpairîÜkey?¡£

		\~japanese
		ª³ªÎnode«ª«Ö«¸«§«¯«ÈªÇ÷åïÒ(key, value) pairªòğ¶ËÛª·ªŞª¹¡£
		\param name ğ¶ËÛª¹ªëpairªÎkeyö·
		\~
		*/
		PROUD_API virtual void RemoveField(const String &name) PN_OVERRIDE;

		/** 
		\~korean
		µ¥ÀÌÅÍ Á¤º¸¸¦ ByteArray ¿¡ ´ã½À´Ï´Ù.
		- º¸Åë »ç¿ëÀÚ´Â »ç¿ëÇÒ ÀÏÀÌ ¾ø½À´Ï´Ù.

		\~english
		Put data information to ByteArray.
		- Ordinary user does not need to use.

		\~chinese
		÷ê?ËßãáãÓ?Óğ ByteArray¡£
		- ìéÚõîÜéÄ?ÜôâÍé©ŞÅéÄ¡£

		\~japanese
		«Ç?«¿ï×ÜÃªò ByteArrayªËìıªìªŞª¹¡£
		- ÜÅ÷×«æ?«¶?ªÏŞÅéÄª¹ªëª³ªÈª¬ª¢ªêªŞª»ªó¡£
		\~
		*/
		PROUD_API virtual void ToByteArray(ByteArray &output) PN_OVERRIDE;

		inline CDataTree* GetChild(){return m_child;}
		inline CDataTree* GetSibling(){return m_sibling;}
		inline CDataTree* GetEndSibling(){ return m_endSibling; }
#if defined (WIN32)
		__declspec(property(get=GetChild)) CDataTree* Child;
		__declspec(property(get=GetSibling)) CDataTree* Sibling;
		__declspec(property(get = GetEndSibling)) CDataTree* EndSibling;
#endif

		inline Guid	GetUUID() { return m_UUID; }
		inline Guid	GetOwnerUUID() { return m_ownerUUID;  }
		inline Guid GetRootUUID() { return m_RootUUID; }

#if defined (WIN32)
		__declspec(property(get=GetUUID)) Guid UUID;
		__declspec(property(get=GetOwnerUUID)) Guid OwnerUUID;
		__declspec(property(get=GetRootUUID)) Guid RootUUID;
		__declspec(property(get=GetStringTypeName,put=SetStringTypeName)) String TypeName; 
#endif

		bool	IsSoftWorkIssued(){return m_issuedSoft;}
		
		/**
		\~korean
		±âº» »ı¼ºÀÚ 

		\~english
		Base constructor

		\~chinese
		ĞñÜâßæà÷íº¡£

		\~japanese
		ĞñÜâßæà÷í­
		\~
		*/
		PROUD_API CDataTree(const PNTCHAR* TypeName);
		PROUD_API CDataTree(const CDataTree& from);
		virtual ~CDataTree();

		inline CDataTree & operator=( const CDataTree& from )
		{
			AssertThreadID(eAccessMode_Write);
			m_map = from.m_map;
			m_parent = from.m_parent;
			m_child = from.m_child;
			m_sibling = from.m_sibling;
			m_endSibling = from.m_endSibling;
			m_INTERNAL_TypeName = CStringPool::GetUnsafeRef().GetString(String(from.m_INTERNAL_TypeName));
			m_UUID = from.m_UUID;
			m_ownerUUID = from.m_ownerUUID;
			m_RootUUID = from.m_RootUUID;
			m_dirtyFlag = from.m_dirtyFlag;
			ClearThreadID();
			return *this;
		}

		inline CDataTree& operator =(const CProperty& from)
		{
			CProperty::operator=(from);
			return *this;
		}

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
	CPropForest ´Â 1°³ ÀÌ»óÀÇ tree¸¦ °¡Áö´Â ½£ °´Ã¼ÀÔ´Ï´Ù.
	CPropForest ÀÇ ³ëµå´Â CDataTree Å¸ÀÔÀÔ´Ï´Ù.
	- »ç¿ëÀÚ´Â °¡±ŞÀû »ç¿ëÇÏÁö ¸¶½Ê½Ã¿ä.

	´ÙÀ½Àº »ç¿ë ¿¹½ÃÀÔ´Ï´Ù.
	\code

		CPropForest f; // °¡°èµµÀÔ´Ï´Ù.

		// jackÀÌ ·çÆ®·Î ºÙ½À´Ï´Ù.
		CDataTree* jack = new CDataTree;
		f.InsertChild(NULL, jack);

		// janeÀÌ jack°ú °áÈ¥Çß½À´Ï´Ù.
		CDataTree* jane = new CDataTree;
		f.InsertSiblingAfter(jack, jane);

		// µş wendy°¡ ÅÂ¾î³µ½À´Ï´Ù.
		CDataTree* wendy = new CDataTree;
		f.InsertChild(jack, wendy);

		// wendy°¡ ½Å¶û tony¿Í °áÈ¥Çß½À´Ï´Ù. 
		CDataTree* tony = new CDataTree;
		f.InsertSiblingBefore(wendy, tony);

		// tony¿Í wendy »çÀÌ¿¡ terry°¡ ÅÂ¾î³µ½À´Ï´Ù.
		CDataTree* terry = new CDataTree;
		f.InsertChild(tony, terry);

		// tony°¡ ¹Ù¶÷³ª¼­ µµ¸Á°¬½À´Ï´Ù. terryµµ °°ÀÌ µ¥·Á°¡ ¹ö·È½À´Ï´Ù. 
		f.RemoveNode(tony);

	\endcode

	\~english
	CPropForest is a forest type object that has more than 1 tres.
	    Node of CPropForest is CDataTree type.

	Following is an example for usage.
	\code

		CPropForest f; // Family tress

		// Jack is attached to root.
		CDataTree* jack = new CDataTree;
		f.InsertChild(NULL, jack);

		// Jane is married to Jack.
		CDataTree* jane = new CDataTree;
		f.InsertSiblingAfter(jack, jane);

		// Daughter Wendy is born.
		CDataTree* wendy = new CDataTree;
		f.InsertChild(jack, wendy);

		// Wendy is married to Tony. 
		CDataTree* tony = new CDataTree;
		f.InsertSiblingBefore(wendy, tony);

		// Tony and Wendy bore Terry.
		CDataTree* terry = new CDataTree;
		f.InsertChild(tony, terry);

		// Tony left haveing an affair. He took Terry as well. 
		f.RemoveNode(tony);
	\endcode

	\~chinese
	CpropForest ãÀ?êóìé?ì¤ß¾îÜtreeîÜßµ×ù?ßÚ¡£
	CPropForest îÜ?ïÃãÀ CDataTree%?úş¡£
	- éÄ??Ê¦ÒöÜôé©ŞÅéÄ¡£

	ì¤ù»ãÀŞÅéÄÖÇí­¡£
	\code

		CPropForest f; // Ê«Í§?¡£

		// jack??ĞÆ?¡£.
		CDataTree* jack = new CDataTree;
		f.InsertChild(NULL, jack);

		// jane?jack?ûæÖõ¡£
		CDataTree* jane = new CDataTree;
		f.InsertSiblingAfter(jack, jane);

		// Ò³?wendyõóßæÖõ¡£
		CDataTree* wendy = new CDataTree;
		f.InsertChild(jack, wendy);

		// wendy?ãæÕÈtony?ûæÖõ¡£ 
		CDataTree* tony = new CDataTree;
		f.InsertSiblingBefore(wendy, tony);

		// tony?wendyñı?terryõóßæÖõ¡£
		CDataTree* terry = new CDataTree;
		f.InsertChild(tony, terry);

		// tonyèâéçÔ±?Öõ¡£?Terryå¥ìéÑÃ?ñËÖõ¡£ 
		f.RemoveNode(tony);

	\endcode

	\~japanese
	CPropForest ªÏ1ËÁì¤ß¾ªÎtreeªòò¥ªÄßµ«ª«Ö«¸«§«¯«ÈªÇª¹¡£
	CPropForestªÎ«Î?«ÉªÏCPropNode«¿«¤«×ªÇª¹¡£
	- «æ?«¶?ªÏªÊªëªÙª¯ŞÅªïªÊª¤ªÇª¯ªÀªµª¤¡£
	ó­ªÏŞÅéÄÖÇãÆªÇª¹¡£
	\code
	CPropForest f; // Ê«Í§?ªÇª¹¡£
	// jackª¬«ë?«ÈªËªÄª­ªŞª¹¡£
	CPropNode* jack = new CPropNode;
	f.InsertChild(NULL, jack);

	// janeª¬jackªÈÌ¿ûæª·ªŞª·ª¿¡£.
	CPropNode* jane = new CPropNode;
	f.InsertSiblingAfter(jack, jane);

	// Ò¦ªÎwendyª¬ßæªŞªìªŞª·ª¿¡£
	CPropNode* wendy = new CPropNode;
	f.InsertChild(jack, wendy);

	// wendyª¬ü£?ªÎtonyªÈÌ¿ûæª·ªŞª·ª¿¡£
	CPropNode* tony = new CPropNode;
	f.InsertSiblingBefore(wendy, tony);

	// tonyªÈwendyªÎÊàªÇterryª¬ßæªŞªìªŞª·ª¿¡£
	CPropNode* terry = new CPropNode;
	f.InsertChild(tony, terry);

	// tonyª¬İ©?ªòª·ªÆÔ±ª²ªÆª·ªŞª·ªŞª·ª¿¡£Terryªâìé?ªËÖ§ªìªÆú¼ª­ªŞª·ª¿¡£ 
	f.RemoveNode(tony);
	\endcode


	\~
	*/


	/**  @}  */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif

#endif // _WIN32