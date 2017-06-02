/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	class AnsiStrTraits
	{
	public:
		typedef char CharType;

		static int SafeStringLen(const CharType* str);

		// #ikpil.choi 2016-11-10 : memcpy_s 로 변경, destSize(2번째 인자) 값이 항상 올바른 값이여야 합니다.
		//static void CopyString(CharType* dest, const CharType* src,int length);
		// dest : 복사 받을 대상, destNumOfElements : 복사 받을 대상의 요소 갯수('\0' 자리 포함)
		static void CopyString(CharType* dest, int destNumOfElements, const CharType* src, int length);

		static int StringCompare(const CharType* a, const CharType*b);
		static int StringCompareNoCase(const CharType* a, const CharType*b);
		static int GetFormattedLength(const char* pszFormat, va_list args);
		static int __cdecl Format(char* pszBuffer, size_t nlength, const char* pszFormat, va_list args) throw();

		// 해결 방법을 찾을때 까지 막아놓음.
#if defined(_WIN32) 
		static char* StringUppercase(char* psz, size_t size) throw();
		static char* StringLowercase(char* psz, size_t size) throw();
#endif
		static const char* __cdecl StringFindString(const char* pszBlock, const char* pszMatch) throw();
		static char* __cdecl StringFindString(char* pszBlock, const char* pszMatch) throw();
		static const char* __cdecl StringFindChar(const char* pszBlock, char chMatch) throw();
		static int __cdecl StringSpanIncluding(const char* pszBlock, const char* pszSet) throw();
		static int __cdecl StringSpanExcluding(const char* pszBlock, const char* pszSet) throw();
		static char* __cdecl CharNext(const char* p) throw();
		static int __cdecl IsDigit(char ch) throw();
		static int __cdecl IsSpace(char ch) throw();

		template<typename PNSTRING>
		inline static void ToStdString(const PNSTRING& src, std::string& dest);
		template<typename PNSTRING>
		inline static void ToStdWString(const PNSTRING& src, std::wstring& dest);
		template<typename PNSTRING>
		inline static void FromStdString(const std::string& src, PNSTRING& dest);
		template<typename PNSTRING>
		inline static void FromStdWString(const std::wstring& src, PNSTRING& dest);
	};

	class UnicodeStrTraits
	{
	public:
		typedef wchar_t CharType;

		static int SafeStringLen(const CharType* str);

		// #ikpil.choi 2016-11-10 : memcpy_s 로 변경, destSize(2번째 인자) 값이 항상 올바른 값이여야 합니다.
		//static void CopyString(CharType* dest, const CharType* src,int length);
		// dest : 복사 받을 대상, destNumOfElements : 복사 받을 대상의 요소 갯수('\0' 자리 포함)
		static void CopyString(CharType* dest, int destNumOfElements, const CharType* src, int length);

		static int StringCompare(const CharType* a, const CharType*b);
		static int StringCompareNoCase(const CharType* a, const CharType*b);
		static int GetFormattedLength(const wchar_t* pszFormat, va_list args);
		static int __cdecl Format(wchar_t* pszBuffer, size_t nLength, const wchar_t* pszFormat, va_list args) throw();

		// 해결 방법을 찾을때 까지 막아놓음.
#if defined(_WIN32) 
		static wchar_t* StringUppercase(wchar_t* psz, size_t size) throw();
		static wchar_t* StringLowercase(wchar_t* psz, size_t size) throw();
#endif
		static const wchar_t* __cdecl StringFindString(const wchar_t* pszBlock, const wchar_t* pszMatch) throw();
		static wchar_t* __cdecl StringFindString(wchar_t* pszBlock, const wchar_t* pszMatch) throw();
		static const wchar_t* __cdecl StringFindChar(const wchar_t* pszBlock, wchar_t chMatch) throw();
		static int __cdecl StringSpanIncluding(const wchar_t* pszBlock, const wchar_t* pszSet) throw();
		static int __cdecl StringSpanExcluding(const wchar_t* pszBlock, const wchar_t* pszSet) throw();
		static wchar_t* __cdecl CharNext(const wchar_t* psz) throw();
		static int __cdecl IsDigit(wchar_t ch) throw();
		static int __cdecl IsSpace(wchar_t ch) throw();

		template<typename PNSTRING>
		inline static void ToStdString(const PNSTRING& src, std::string& dest);
		template<typename PNSTRING>
		inline static void ToStdWString(const PNSTRING& src, std::wstring& dest);

		template<typename PNSTRING>
		inline static void FromStdString(const std::string& src, PNSTRING& dest);
		template<typename PNSTRING>
		inline static void FromStdWString(const std::wstring& src, PNSTRING& dest);
	};

}
