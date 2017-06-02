/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once 

#include "BasicTypes.h"
#include "PNString.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class CMessage;

	struct PNGUID
	{
		uint32_t Data1;
		uint16_t Data2;
		uint16_t Data3;
		uint8_t Data4[8];
	};

	/** Platform independent Global Unique ID object. 
	For Win32 features, refer to Proud::Win32Guid class.
	*/
	class Guid:public PNGUID
	{
	public:
		/**
		\~korean
		GUID¸¦ ·£´ıÀ¸·Î »ı¼ºÇÕ´Ï´Ù. NewGuid()¿Í ´Ş¸®, ÀÌ °ªÀº °íÀ¯¼ºÀÌ º¸ÀåµÇÁö ¾Ê½À´Ï´Ù.

		\~english
		Generates a 'random' GUID. Unlike NewGuid(), this does not guarantee uniqueness.

		\~chinese
		?Ïõßæà÷GUIDE¡£?NewGuid£¨£©ÜôÔÒ£¬ó®?ÜôÜÁî¡Í³êóàõ¡£

		\~japanese
		GUIDªò«é«ó«À«àªÇßæà÷ª·ªŞª¹¡£NewGuid()ªÈªÏêŞªÃªÆ¡¢ª³ªÎö·ªÏÍ³êóàõª¬ÜÁî¡ªµªìªÊª±ªìªĞªÊªêªŞª»ªó¡£
		\~
		*/
		PROUD_API static Guid RandomGuid();

		Guid();
		Guid(PNGUID src);

		/**
		\~korean
		Guid¸¦ String°ªÀ¸·Î º¯È¯ÇØ Áİ´Ï´Ù.

		\~english TODO:translate needed.
		It converts Guid to a string value. 

		\~chinese
		÷êGuid??à÷String?¡£

		\~japanese
		GuidªòStringö·ªË?üµª·ªÆª¯ªìªŞª¹¡£
		\~
		*/
		PROUD_API String ToString() const;

		/**
		\~korean
		Guid¸¦ Bracket({}) ¸¦ Æ÷ÇÔÇÑ StringÀ¸·Î º¯È¯ÇØ Áİ´Ï´Ù.

		\~english TODO:translate needed.
		It converts Guid with a string including brakets({}). 

		\~chinese
		÷êGuid??à÷øĞÎÀBracket({})îÜString¡£

		\~japanese
		GuidªòBracket({})ªòùßªóªÀStringªË?üµª·ªÆª¯ªìªŞª¹¡£
		\~
		*/
		PROUD_API String ToBracketString() const;

		/**
		\~korean
		Guid¸¦ String°ªÀ¸·Î º¯È¯ÇØ Áİ´Ï´Ù.
		\param uuid GuidÀÔ´Ï´Ù.
		\param uuidStr uuid¸¦ StringÇüÅÂ·Î º¯È¯ÇÑ Á¤º¸¸¦ ´ãÀ» reference ÀÔ´Ï´Ù
		\return º¯È¯¿¡ ¼º°ø true, ½ÇÆĞ false

		\~english TODO:translate needed.
		It converts Guid to a string value.
		\param This is uuid Guid. 
		\param This is the reference to hold the information which is uuid converted into a string format. 
		\return True when successful in conversion, otherwise false. 


		\~chinese
		÷êGuid??à÷String?¡£
		\param uuid ãÀGuid¡£
		\param uuidStr ãÀøĞùßó·÷êuuid??à÷Stringû¡ãÒãáãÓîÜreference¡£
		\return ??à÷ÍíîÜ?true£¬ã÷?îÜ?false¡£

		\~japanese
		GuidªòStringö·ªË?üµª·ªÆª¯ªìªŞª¹¡£
		\param uuid GuidªÇª¹¡£
		\param uuidStr uuidªòStringû¡÷¾ªË?üµª·ª¿ï×ÜÃªòìıªìªëreferenceªÇª¹¡£
		\return ?üµªËà÷Ííª¹ªëªÈtrue¡¢ã÷ø¨ª¹ªëªÈfalse
		\~
		*/
		PROUD_API static bool  ConvertUUIDToString(const Guid &uuid, String &uuidStr);

		/**
		\~korean
		Guid¸¦ Bracket({}) ¸¦ Æ÷ÇÔÇÑ StringÀ¸·Î º¯È¯ÇØ Áİ´Ï´Ù.
		\param uuid GuidÀÔ´Ï´Ù.
		\param uuidStr uuid¸¦ StringÇüÅÂ·Î º¯È¯ÇÑ Á¤º¸¸¦ ´ãÀ» reference ÀÔ´Ï´Ù
		\return º¯È¯¿¡ ¼º°ø true, ½ÇÆĞ false

		\~english TODO:translate needed.
		It converts Guid to a string value
		\param This is uuid Guid.
		\param This is the reference to hold the information which is uuid converted into a string format. 
		\return True when successful in conversion, otherwise false.

		

		\~chinese
		÷êGuid??à÷øĞÎÀBracket({}) îÜString¡£
		\param uuid ãÀGuid¡£
		\param uuidStr ãÀøĞùßó·÷êuuid??à÷Stringû¡ãÒãáãÓîÜreference¡£
		\return ??à÷ÍíîÜ?true£¬ã÷?îÜ?false¡£

		\~japanese
		GuidªòBracket({})ªòùßªóªÀStringªË?üµª·ªÆª¯ªìªŞª¹¡£
		\param uuid GuidªÇª¹¡£
		\param uuidStr uuidªòStringû¡÷¾ªË?üµª·ª¿ï×ÜÃªòìıªìªëreferenceªÇª¹¡£
		\return ?üµªËà÷Ííª¹ªëªÈtrue¡¢ã÷ø¨ª¹ªëªÈfalse
		\~
		*/
		PROUD_API static bool  ConvertUUIDToBracketString(const Guid &uuid, String &uuidStr);

		/**
		\~korean
		StringÀ» uuid°ªÀ¸·Î º¯È¯ÇÕ´Ï´Ù.
		\param uuidStr uuidÀÇ StringÇüÅÂ ÀÔ´Ï´Ù.
		\param uuidStr String¿¡¼­ uuid·Î º¯È¯ÇÑ Á¤º¸¸¦ ´ãÀ» reference ÀÔ´Ï´Ù
		\return º¯È¯¿¡ ¼º°ø true, ½ÇÆĞ false

		\~english TODO:translate needed.
		It converts string to a uuid value.
		\param uuidStr This is the string type of uuid. 
		\param uuidStr This is the reference to hold the information which is string converted into an uuid format.
		\return True when successful in conversion, otherwise false.


		\~chinese
		÷êString??à÷uuid?¡£
		\param uuidStr ãÀuuidîÜStringû¡ãÒ¡£
		\param uuidStr ãÀøĞùßó·?String??à÷uuidãáãÓîÜreference¡£
		\return ??à÷ÍíîÜ?true£¬ã÷?îÜ?false¡£

		\~japanese
		Stringªòuuidö·ªË?üµª·ªŞsª¦¡£
		\param uuidStr uuidªÎStringû¡÷¾ªÇª¹¡£
		\param uuidStr StringªÇuuidªË?üµª·ª¿ï×ÜÃªòìıªìªëreferenceªÇª¹¡£
		\return ?üµªËà÷Ííª¹ªëªÈtrue¡¢ã÷ø¨ª¹ªëªÈfalse
		
		\~
		*/
		PROUD_API static bool  ConvertStringToUUID(String uuidStr, Guid &uuid);

		/**
		\~korean
		Guid¸¦ String°ªÀ¸·Î º¯È¯ÇØ Áİ´Ï´Ù.
		\param uuid GuidÀÔ´Ï´Ù.
		\return String

		\~english TODO:translate needed.
		It converts Guid to a string value.
		\param This is Guid. 
		\return String


		\~chinese
		÷êGuid??à÷String?¡£
		\param uuid ãÀGuid¡£
		\return String

		\~japanese
		GuidªòStringö·ªË?üµª·ªÆª¯ªìªŞª¹¡£
		\param uuid GuidªÇª¹¡£
		\return String

		\~
		*/
		static inline String GetString(const Guid &uuid)
		{
			String ret;
			if (ConvertUUIDToString(uuid, ret))
				return ret;
			else
				return String();
		}

		String GetString() const
		{
			return Guid::GetString(*this);
		}

		/**
		\~korean
		Guid¸¦ Bracket({}) ¸¦ Æ÷ÇÔÇÑ StringÀ¸·Î º¯È¯ÇØ Áİ´Ï´Ù.
		\param uuid GuidÀÔ´Ï´Ù.
		\return String

		\~english TODO:translate needed.
		It converts Guid with a string including brakets({}). 
		\param This is Guid.
		\return String


		\~chinese
		÷êGuid??à÷øĞÎÀBracket({})îÜString¡£
		\param uuid ãÀGuid¡£
		\return String

		\~japanese
		GuidªòBracket({})ªòùßªóªÀStringªË?üµª·ªÆª¯ªìªŞª¹¡£
		\param uuid GuidªÇª¹¡£
		\return String

		\~
		*/
		static inline String GetBracketString(const Guid &uuid)
		{
			String ret;
			if (ConvertUUIDToBracketString(uuid, ret))
				return ret;
			else
				return String();
		}

		/**
		\~korean
		StringÀ» uuid°ªÀ¸·Î º¯È¯ÇÕ´Ï´Ù.
		\param uuidStr uuidÀÇ StringÇüÅÂ ÀÔ´Ï´Ù.
		\return Guid º¯È¯µÈ Guid ÀÔ´Ï´Ù.

		\~english TODO:translate needed.
		It converts string to a uuid value.
		\param uuidStr This is the string type of uuid. 
		\return Guid This is the converted Guid. 


		\~chinese
		÷êString??à÷uuid?¡£
		\param uuidStr ãÀuuidîÜStringû¡ãÒ¡£
		\return Guidù¬??îÜGuid¡£

		\~japanese
		Stringªòuuidö·ªË?üµª·ªŞª¹¡£
		\param uuidStr uuidªÎStringû¡÷¾ªÇª¹¡£
		\return Guid ?üµªµªìª¿GuidªÇª¹¡£
		\~
		*/
		static inline Guid GetFromString(const PNTCHAR* uuidStr)
		{
			Guid uuid;
			if (ConvertStringToUUID(uuidStr, uuid))
				return uuid;
			else
				return Guid();
		}

		/**
		\~korean
		PNGUID °´Ã¼·ÎºÎÅÍÀÇ Ä³½ºÆÃ
		\param uuid	PNGUIDÀÔ´Ï´Ù.
		\return Guid°´Ã¼

		\~english TODO:translate needed.
		Casting from PNGUID object
		\param uuid  This is PNGUID
		\return Guid object. 


		\~chinese TODO:translate needed.
		?PNGUID ?ßÚ?ã·casting
		\paramuuid	PNGUID
		\return Guid?ßÚ

		\~japanese TODO:translate needed.
		PNGUID «ª«Ö«¸«§«¯«Èª«ªéªÎ«­«ã«¹«Æ«£«ó«°
		\param uuid	PNGUIDªÇª¹¡£
		\return Guid«ª«Ö«¸«§«¯«È
		\~
		*/
		static inline Guid From(const PNGUID& uuid)
		{
			return Guid(uuid);
		}

	};

	inline bool operator<(const Guid& d1, const Guid& d2)
	{
		return memcmp(&d1, &d2, sizeof(Guid)) < 0;
	}

	inline bool operator<=(const Guid& d1, const Guid& d2)
	{
		return memcmp(&d1, &d2, sizeof(Guid)) <= 0;
	}

	inline bool operator>(const Guid& d1, const Guid& d2)
	{
		return memcmp(&d1, &d2, sizeof(Guid)) > 0;
	}

	inline bool operator>=(const Guid& d1, const Guid& d2)
	{
		return memcmp(&d1, &d2, sizeof(Guid)) >= 0;
	}

	inline bool operator==(const Guid& d1, const Guid& d2)
	{
		return memcmp(&d1, &d2, sizeof(Guid)) == 0;
	}

	inline bool operator!=(const Guid& d1, const Guid& d2)
	{
		return memcmp(&d1, &d2, sizeof(Guid)) != 0;
	}

	CMessage& operator>>(CMessage &a, Guid &b);
	CMessage& operator<<(CMessage &a, const Guid &b);
	void AppendTextOut(String &a, const Guid &b);


};

/**
\~korean
CFastMap µî¿¡ ¾²·Á¸é ÀÌ°ÍÀÌ ÇÊ¿äÇÏ´Ù.

\~english
This is needed to use CFastMap or others.

\~chinese
ßÌéÄéÍ CFasTMap%ÔõîÜ?âÍé©??¡£

\~japanese
CFastMap ªÊªÉªËŞÅª¦ª¿ªáªËªÏª³ªìª¬ù±é©ªÇª¹¡£
\~
*/
template<>
class CPNElementTraits < Proud::Guid >
{
public:
	typedef const Proud::Guid& INARGTYPE;
	typedef Proud::Guid& OUTARGTYPE;

	inline static uint32_t Hash(INARGTYPE element)
	{
		uint32_t ret = 0;
		uint32_t* data = (uint32_t*)&element;
		for (int i = 0; i < 4; i++)
		{
			ret ^= data[i];
		}

		return ret;
	}

	inline static bool CompareElements(INARGTYPE element1, INARGTYPE element2)
	{
		return (element1 == element2) ? true : false;
	}

	inline static int CompareElementsOrdered(INARGTYPE element1, INARGTYPE element2)
	{
		if (element1 < element2)
			return -1;
		else if (element1 > element2)
			return 1;
		else
			return 0;
	}
};

#ifdef _MSC_VER
#pragma pack(pop)
#endif