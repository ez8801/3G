/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


이 프로그램의 저작권은 넷텐션에게 있습니다.
이 프로그램의 수정, 사용, 배포에 관련된 사항은 본 프로그램의 소유권자와의 계약을 따르며,
계약을 준수하지 않는 경우 원칙적으로 무단 사용을 금지합니다.
무단 사용에 의한 책임은 본 프로그램의 소유권자와의 계약서에 명시되어 있습니다.

** 주의: 저작물에 관한 위의 명시를 제거하지 마십시오.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


此程序的版??Nettention公司所有。
?此程序的修改、使用、?布相?的事?要遵守此程序的所有?者的??。
不遵守???要原?性的禁止擅自使用。
擅自使用的?任明示在?此程序所有?者的合同?里。

** 注意：不要移除?于制作物的上述明示。


このプログラムの著作?はNettentionにあります。
このプログラムの修正、使用、配布に?する事項は本プログラムの所有?者との契約に?い、
契約を遵守しない場合、原則的に無?使用を禁じます。
無?使用による責任は本プログラムの所有?者との契約書に明示されています。

** 注意：著作物に?する上記の明示を除去しないでください。

*/

#pragma once

// 헤더파일과 LIB가 서로 버전이 안맞아서 생기는 삽질을 예방하기 위함
// 엔진 업데이트를 할 때마다(사소하게라도) 이 값을 바꾸는 것이 권장됨.
#ifdef _DEBUG
#define PROUDNET_H_LIB_SIGNATURE VER_7_DEBUG
#else
#define PROUDNET_H_LIB_SIGNATURE VER_7_RELEASE
#endif

#include <assert.h>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#if !defined(_WIN32)
#include <sys/types.h>
#include <limits.h>
#include <string.h>
#endif


// int32_t, int64_t, intptr_t 등을 include하기 위함
#ifdef __MARMALADE__
#include <s3eTypes.h>
#include <string.h> // memset이 여기 선언되어 있다
#endif

// fd_set does not name a type 컴파일 에러 해결 -> 헤더 파일 include, __linux__ 버전
#ifdef __linux__
#include <sys/select.h>
#endif

#include <new> // for placement new

#include "pnstdint.h"

#define PNMIN(a,b)            (((a) < (b)) ? (a) : (b))
#define PNMAX(a,b)            (((a) > (b)) ? (a) : (b))

#define PN_INFINITE 0xFFFFFFFF

#if defined(WCHAR_MAX) && (WCHAR_MAX > UINT16_MAX)
#	define WCHAR_LENGTH 4
#else
#	if defined(__MARMALADE__) || defined(_WIN32) || defined(__ORBIS__) // NOTE: Marmalade, ORBIS는 타겟 머신이 unix 기반인데도 크기2다.
#		define WCHAR_LENGTH 2
#	else
#		define WCHAR_LENGTH 4
#	endif
#endif

#include "pndefine.h"

// C4100 warning을 막고 싶다면 쓰자.
#define _pn_unused(x) ((void)(x))



#if !defined(_WIN32)

// NOTE: DWORD, UINT_PTR 같은 것들은 uint32_t or uintptr_t 등 stdint에 정의된 타입으로 쓸 것이고, 윈도용으로 따로 재정의하지 말자.
// 찾기 힘든 버그 나와서 개고생했음.

typedef int SOCKET;
typedef fd_set FD_SET;

#define WINAPI __stdcall
#define _HEAPOK (-2)

//#define _Noreturn
#define __cdecl
#define __forceinline inline

#if (_MSC_VER < 1300)

#ifndef __noop
#define __noop (void)0 // __noop가 지원되지 않는 컴파일러를 위한 기능
#endif

#endif

#define LOWORD(l) ((uint16_t)(((uint32_t)(l)) & 0xffff))
#define HIWORD(l) ((uint16_t)((((uint32_t)(l)) >> 16) & 0xffff))
#define LOBYTE(w) ((uint8_t)(((uint32_t)(w)) & 0xff))
#define HIBYTE(w) ((uint8_t)((((uint32_t)(w)) >> 8) & 0xff))
#define MAKEWORD(a, b) ((uint16_t)(((uint8_t)(((uint32_t)(a)) & 0xff)) | ((uint16_t)((uint8_t)(((uint32_t)(b)) & 0xff))) << 8))
#define MAKELONG(a, b) ((long)(((uint16_t)(((uint32_t)(a)) & 0xffff)) | ((uint32_t)((uint16_t)(((uint32_t)(b)) & 0xffff))) << 16))

#endif // non win32 platform

#if (_MSC_VER>=1600) || (__cplusplus > 199711L)
// NOTE: IoT 툴체인에서는 C++11이 지원안되는 경우가 있다. 따라서 클라 모듈에서는 C++11 기능을 가급적 피해야.
#define SUPPORTS_LAMBDA_EXPRESSION
#endif

#if (_MSC_VER>=1800) || (__cplusplus > 199711L)
//NOTE: VS2013부터 가변템플릿 인자를 지원합니다.
#define SUPPORTS_CPP11
#endif

#ifdef SUPPORTS_CPP11
#define MOVE_OR_COPY(arg) std::move(arg)
#else
#define MOVE_OR_COPY
#endif// SUPPORTS_CPP11

#if ((_MSC_VER > 1700) || (__cplusplus > 199711L)) // VS2012 이상부터 final keyword를 지원함. C++11을 지원하면 NDK 버전 상관없이 아래 키워드가 사용 가능함.
#define PN_OVERRIDE override
#define PN_FINAL final
#define PN_SEALED final // sealed는 VC++ specific이며, C++11은 final을 채택.
#else // old compilers
#define PN_OVERRIDE
#define PN_FINAL
#define PN_SEALED
#endif

#include "pntchar.h"

template< typename T >
void CallConstructor(T* pInstance)
{
#ifndef __MARMALADE__
#pragma push_macro("new")
#undef new
#endif

	::new(pInstance)T();

#ifndef __MARMALADE__
#pragma pop_macro("new")
#endif // __MARMALADE__
};

template< typename T, typename Src >
void CallConstructor(T* pInstance, const Src& src)
{
#ifndef __MARMALADE__
#pragma push_macro("new")
#undef new
#endif // __MARMALADE__

	::new(pInstance)T(src);

#ifndef __MARMALADE__
#pragma pop_macro("new")
#endif // __MARMALADE__
};

// 주의: 반드시!! 함수 사용시 <T>를 명료하게 붙일 것. 일부 컴파일러는 엉뚱한 것을 템플릿 인스턴스화한다.
template< typename T, typename Src, typename Src1 >
void CallConstructor(T* pInstance, const Src& src, const Src1 src1)
{
#ifndef __MARMALADE__
#pragma push_macro("new")
#undef new
#endif // __MARMALADE__

	::new(pInstance)T(src, src1);

#ifndef __MARMALADE__
#pragma pop_macro("new")
#endif // __MARMALADE__
};

// 주의: 반드시!! 함수 사용시 <T>를 명료하게 붙일 것. 일부 컴파일러는 엉뚱한 것을 템플릿 인스턴스화한다.
template< typename T >
void CallDestructor(T* pInstance)
{
	pInstance->T::~T();
};

#ifndef __MARMALADE__
#pragma push_macro("new")
#undef new
#endif // __MARMALADE__

// 주의: 반드시!! 함수 사용시 <T>를 명료하게 붙일 것. 일부 컴파일러는 엉뚱한 것을 템플릿 인스턴스화한다.
template< typename T >
static inline void CallConstructors(T* pElements, intptr_t nElements)
{
	int iElement = 0;

	//	try
	//	{
	for (iElement = 0; iElement < nElements; iElement++)
	{
		::new(pElements + iElement) T;

	}
	//	}
	// 	catch(...)
	// 	{
	// 		while( iElement > 0 )
	// 		{
	// 			iElement--;
	// 			pElements[iElement].~T();
	// 		}
	//
	// 		throw;
	// 	}
}

// 주의: 반드시!! 함수 사용시 <T>를 명료하게 붙일 것. 일부 컴파일러는 엉뚱한 것을 템플릿 인스턴스화한다.
template< typename T >
static inline void CallCopyConstructors(T* pElements, const T* pOldElements, intptr_t nElements)
{
	int iElement = 0;

	for (iElement = 0; iElement < nElements; iElement++)
	{
		::new(pElements + iElement) T(pOldElements[iElement]);
	}
}


// 주의: 반드시!! 함수 사용시 <T>를 명료하게 붙일 것. 일부 컴파일러는 엉뚱한 것을 템플릿 인스턴스화한다.
template< typename T >
static inline void CallDestructors(T* pElements, intptr_t nElements) throw()
{
	(void)pElements;

	for (int iElement = 0; iElement < nElements; iElement++)
	{
		pElements[iElement].~T();
	}
}
#ifndef __MARMALADE__
#pragma pop_macro("new")
#endif // __MARMALADE__

#if 1
/*
\~korean
아직 ProudNet은 DLL을 지원하지 않는다. CAtlStringW 문제는 없지만 STL 타입 파라메터가 DLL CRT / Static CRT 비호환 문제가 있다(런타임 에러)
당장 CNetServer.Start의 들어가는 CFastArray<int>에서부터 런타임 에러가 생기는 상황이다.
따라서 추후에 STL을 안쓰는 구현이 완료된 후에야 ProudNet DLL을 지원시키기로 하자.

\~english
Since ProudNet doesn't support DLL, there may be a DLL CRT / Static CRT incompatible issue for STL type parameter, which works fine in CAtlStringW(Runtime error).
This is a situation where runtime error occurs immediately from CFastArray<int> of CNetServer.Start.
Consider of supporting ProudNet DLL after completing structure without using STL.

\~chinese
ProudNet ?不支持DLL。?然?有 CAtlStringW%??，STL ?型??有着DLL CRT / Static CRT 非互???（?行????）。
??入 CNetServer.Start%的 CFastArray<int>%?始?生?行????的情?。?着之后不使用STL的??完成之后再支持ProudNet DLL?。

\~japanese
まだ、ProudNetはDLLをサポ?トしていません。CAｔｌStringW問題はありませんが、STLタイプパラメ?タ?がDLL CRT / Static CRTの非互換問題があります（ランタイムエラ?）
一?、CNetServer.Startの入るCFastArray<int>よりランタイムエラ?が?生する?況です。
よって、STLを使わないように?現された後にProudNet DLLをサポ?トするようにしましょう。
\~
*/
#	define PROUD_API
#	define PROUDSRV_API
#else
////////////// ProudNet DLL화할 경우 아래를 사용하자.
#if defined (PROUD_STATIC_LIB)
#	define PROUD_API
#	define PROUDSRV_API
#elif defined(PROUD_EXPORTS)
#	define PROUD_API __declspec(dllexport)
#	define PROUDSRV_API
#elif defined(PROUDSRV_EXPORTS)
#	define PROUD_API __declspec(dllimport)
#	define PROUDSRV_API __declspec(dllexport)
#else
#	define PROUD_API __declspec(dllimport)
#	define PROUDSRV_API __declspec(dllimport)
#endif
#endif

//#pragma pack(push,8)

#include "throw.h"

namespace Proud
{
	PROUD_API _Noreturn void ThrowInt32OutOfRangeException(const char* where);
	extern volatile int PROUDNET_H_LIB_SIGNATURE;

#ifdef _W64
	inline void BoundCheckInt32(int64_t v, const char* where)
	{
		if (v < INT64_MIN || v > INT64_MAX)
			ThrowInt32OutOfRangeException(where);
	}

	inline void BoundCheckUInt32(uint64_t v, const char* where)
	{
		if (v > UINT64_MAX)
			ThrowInt32OutOfRangeException(where);
	}
#else
#	define BoundCheckInt32 __noop
#endif


	struct __Position {};

	typedef __Position *Position;
}

template< typename T >
class CPNElementTraits
{
public:
	typedef const T& INARGTYPE;
	typedef T& OUTARGTYPE;

	// 	static void CopyElements( T* pDest, const T* pSrc, size_t nElements )
	// 	{
	// 		for( size_t iElement = 0; iElement < nElements; iElement++ )
	// 		{
	// 			pDest[iElement] = pSrc[iElement];
	// 		}
	// 	}
	//
	// 	static void RelocateElements( T* pDest, T* pSrc, size_t nElements )
	// 	{
	// 		// A simple memmove works for nearly all types.
	// 		// You'll have to override this for types that have pointers to their
	// 		// own members.
	// 		Checked::memmove_s( pDest, nElements*sizeof( T ), pSrc, nElements*sizeof( T ));
	// 	}

	inline static uint32_t Hash(const T& element) throw()
	{
		//1,2,4,8각각에 대해서 바이트 데이터를 직접 가져온다.
		// 그냥 값을 리턴하게 할 경우, float나 double인 경우 정수형 타입으로의 캐스팅을 하다 값을 버리니까 안된다.
		if (sizeof(element) == sizeof(unsigned char)) // NOTE: 상수값끼리 비교는 컴파일러가 알아서 조건 어셈 명령은 생성 안함.
		{
			unsigned char* piece = (unsigned char*)&element; // 몇줄 안되지만 반복 코드랍시고 템플릿 함수로 빼지 말자. 컴파일러 성능을 너무 믿지 말자.
			return *piece;
		}
		else if (sizeof(element) == sizeof(unsigned short))
		{
			unsigned short* piece = (unsigned short*)&element;
			return *piece;
		}
		else if (sizeof(element) == sizeof(unsigned int))
		{
			unsigned int* piece = (unsigned int*)&element;
			return *piece;
		}
		else if (sizeof(element) == sizeof(int64_t))
		{
			// 64bit 크기 타입(double등등)을 xor로 해싱하기 위해 앞뒤를 섞는다.
			// cast to smaller type을 하려고 하니 clang에서 에러를 내기에, 이렇게 해야.
			uint32_t* piece = (uint32_t*)&element;
			return piece[0] ^ piece[1];
		}
		else
		{
			// 1,2,4,8바이트 말고 또 다른 크기가 있나? 있으면 구현할 것.
			// 현재 C++ plain data type 중에는 없을 듯.
			int* a = 0;
			*a = 1;

			// meaningless
			return 0;
		}
	}


	inline static bool CompareElements(const T& element1, const T& element2)
	{
		return (element1 == element2);
	}

	inline static int CompareElementsOrdered(const T& element1, const T& element2)
	{
		if (element1 < element2)
		{
			return(-1);
		}
		else if (element1 == element2)
		{
			return(0);
		}
		else
		{
			assert(element1 > element2);
			return(1);
		}
	}
};

#define PN_LODWORD(QWordValue) ((uint32_t)(QWordValue))
#define PN_HIDWORD(QWordValue) ((uint32_t)(((QWordValue) >> 32) & 0xffffffff))

#include "atomic.h"

#include "SafeMemory.h"

#ifdef _MSC_VER
#pragma pack(pop)
#endif
