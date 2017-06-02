/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
//////////////////////////////////////////////////////////////////////////
/* Win32, Marmalade������ char = MBS, wchar_t = UTF16�Դϴ�. [1]
������ iOS, Android,Linux ����� char = UTF8, wchar_t = UTF32�Դϴ�. [2]
�̷��� �� ������ [1]������ wchar_t��, [2]������ char�� ��ȣ�մϴ�.
ProudNet�� [1] �÷��������� wchar_t��, [2] �÷��������� char�� ����ϴ� API�� �����մϴ�.
���� ����� ���α׷��� [1]�� [2]���� ��� �������� ���尡 �Ǿ�� �Ѵٸ�, �Ʒ� ���ǵ� �͵��� ����ϼž� �� ���Դϴ�. */

#pragma once 

#ifdef _MSC_VER
#pragma pack(push,8)
#endif


#if defined(_WIN32) || defined(__MARMALADE__)
#define _PNUNICODE
#endif //defined(_WIN32) || defined(__MARMALADE__)

#define __PNSTR2WSTR(str)	L## str
#define _PNSTR2WSTR(str)	__PNSTR2WSTR(str)

// PNTCHAR=char�� ����Ǵ��� �� define�� �����ؾ� �Ѵ�.
// ����: ������ �̰��� ���� �� ��. String ��ȯ ������ ������. 
#ifndef __FUNCTIONW__
#define __FUNCTIONW__		(StringA2W(__FUNCTION__).GetString())

//#define __FUNCTIONW__		_PNSTR2WSTR(__FUNCTION__) 
//  ��Ÿ���Ե� PS4���� ������ L__FUNCTION__ �� ���ٴ� ������ ����. ���� �� ���� ����. ���� ���������� ������ ����� �뵵�ε�.

#endif

#ifndef __FILEW__
//#define __FILEW__		_PNSTR2WSTR(__FILE__)
#define __FILEW__		(StringA2W(__FILE__).GetString())
#endif

// NOTE: ���� �� define�� ������ ����Ű�� �־��� ��� ���� �����ϰ� ������ ����.
// iOS, Android, Linux���� ���� �� �����Ϸ����� __FUNCTION__�� char ���ڿ��� ġȯ �˴ϴ�. �����ڵ� ������� ���̺귯���� �����ϰ� �Ǹ� char -> wchar_t�� ��������� ��ȯ�� ���־�� �մϴ�.

#if defined(_PNUNICODE) // NOTE: UE4�� ��� ����Ͽ����� PNTCHAR = wchar_t�̴�. ���� �̰��� �־�� �Ѵ�.

#define _PNT(x) L##x
#define Tprintf wprintf
#define Tsscanf swscanf
#define Tsprintf swprintf
#define Tstrlen wcslen
#define Tstrcmp wcscmp
#define Tstricmp wcsicmp
#define Tstrcpy wcscpy
#define Tofstream ::std::wofstream 
#define Tstringstream ::std::wstringstream 
typedef wchar_t PNTCHAR;

// ����: ������ �̰��� ���� �� ��. String ��ȯ ������ ������. 
#define __FUNCTIONT__ __FUNCTIONW__

// filesys.h ������
#ifndef TSTRING
#define TSTRING std::wstring
#endif // TSTRING

#else // linux, mac, ...

#define _PNT(x) x
#define Tprintf printf
#define Tsprintf sprintf
#define Tsscanf sscanf
#define Tstrlen strlen
#define Tstrcmp strcmp
#define Tstricmp stricmp
#define Tstrcpy strcpy
#define Tofstream std::ofstream
#define Tstringstream std::stringstream 
typedef char PNTCHAR;

#define __FUNCTIONT__ __FUNCTION__

// filesys.h ������
#ifndef TSTRING
#define TSTRING std::string
#endif

#endif
#ifdef _MSC_VER
#pragma pack(pop)
#endif