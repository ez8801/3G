/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once 

/* The _Noreturn keyword of draft C1X.  */
// iconv �ҽ����� ����.
// http://www.open-std.org/jtc1/sc22/wg14/www/docs/n1453.htm
#ifdef _MSC_VER
#  define _Noreturn __declspec (noreturn)
#else
#  define _Noreturn __attribute__ ((__noreturn__))
#endif


// #ifndef _Noreturn
// # if (3 <= __GNUC__ || (__GNUC__ == 2 && 8 <= __GNUC_MINOR__) \
// 	  || 0x5110 <= __SUNPRO_C)
// #  define _Noreturn __attribute__ ((__noreturn__))
// # elif 1200 <= _MSC_VER
// #  define _Noreturn __declspec (noreturn)
// # else
// #  define _Noreturn
// # endif
// #endif

#ifdef _MSC_VER
#define _Noinline __declspec(noinline)
#else
#define _Noinline __attribute__ ((noinline))
#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/* C++ exception�� throw �ϴ� ������ ������ �Լ���.
	
	Q: �� ���� throw�� ���ϰ� �Լ��� �����߳���?
	A: NDK, PS4, UE4 �� �Ϻ� ��Ȳ������ throw keyword�� �� ���ϴ�. �� exception handling�� ���ϴ� �����Ϸ� ������ ���ϴ�.
	�̷��� ��Ȳ������ �̷��� �Լ��� ���ε� ���� �� ���ۿ� �����ϴ�.
	����, �׷��� ��������, ȣ��Ǵ� �Լ�X�� throw�� �ϸ� �ȵ�����, ȣ��Ǵ� �Լ����� ȣ���ϴ� ���� �Լ���Y�� throw�� �ϴ���,
	X���� catch�� ���شٸ�, ���� �����ϴ�. 
	
	Q: exception.h�� ������ ���ٵ���?
	A: exception.h�� pnstring.h�� include�ϴµ�, pnstring.h�� �Ʒ� �Լ����� ���ϴ�.
	*/
	_Noreturn void ThrowInvalidArgumentException();
	_Noreturn void ThrowArrayOutOfBoundException();
	_Noreturn void ThrowBadAllocException();
	_Noreturn void ThrowException(const char* text);
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif