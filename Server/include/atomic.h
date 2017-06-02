/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


이 프로그램의 저작권은 넷텐션에게 있습니다.
이 프로그램의 수정, 사용, 배포에 관련된 사항은 본 프로그램의 소유권자와의 계약을 따르며,
계약을 준수하지 않는 경우 원칙적으로 무단 사용을 금지합니다.
무단 사용에 의한 책임은 본 프로그램의 소유권자와의 계약서에 명시되어 있습니다.

** 주의 : 저작물에 관한 위의 명시를 제거하지 마십시오.


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

#include "pnstdint.h"

// interlocked op 관련 멀티플랫폼 코딩을 편하게 하고자 함. 즉 #ifdef 떡칠을 줄이자.
#if defined(__MACH__) // mac,ios 전용
    #include <libkern/OSAtomic.h>
#endif

#ifdef _MSC_VER
#pragma warning(disable:4800) // warning C4800: 's3eBool' : forcing value to bool 'true' or 'false' (performance warning)
#endif

#ifdef __MARMALADE__

//#include "ProudNetEDK.h"
/*
// ProudNetEDK.h에서 복사해왔음. 엔진 유저에게는 EDK까지 #include하게 요구하는건 오버니까.
// 실제 이 함수의 prototype을 include하는 곳은 엔진 소스 cpp 안에 있음
int32 s3eAtomicIncrement32(int32* target);
int32 s3eAtomicDecrement32(int32* target);
s3eBool s3eAtomicCompareAndSwap(int32 oldValue, int32 newValue, int32* target);*/

#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif


namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

#ifdef UNTRUST_COMPILER_VOLATILE_ALIGN
	#ifdef _MSC_VER // VC++계열이면
	#if defined(__LP64__) || defined(_WIN64)
	#define PROUDNET_VOLATILE_ALIGN __declspec(align(8)) volatile
	#else
	#define PROUDNET_VOLATILE_ALIGN  __declspec(align(4)) volatile
	#endif
	#else //이외 컴파일러 계열이면
	#if defined(__LP64__) || defined(_WIN64)
	#define PROUDNET_VOLATILE_ALIGN __attribute__((aligned(8))) volatile // TODO: 만약 요고이 에러나면 그냥 volatile로만 남기자레. 어차피 compiler 자체가 align 8 or 4니껭. (apple developer의 OSAtomicIncrement 자체가 align4이면 된다고 다큐에도 적혀있으니 함 믿어보자)
	#else
	#define PROUDNET_VOLATILE_ALIGN __attribute__((aligned(4))) volatile
	#endif
	#endif
#else
	#define PROUDNET_VOLATILE_ALIGN volatile
#endif
// Marmalade 등 atomic op 자체를 지원하지 않는 플랫폼에서는 느리더라도 이렇게 작동해야 함
class CSlowAtomic
{
public:
	// 리턴: 변경 후의 값
	static int32_t Increment32(volatile int32_t *target);
	// 리턴: 변경 후의 값
	static int32_t Decrement32(volatile int32_t *target);
	// 리턴: 변경 전의 값
	static int32_t Exchange32(volatile int32_t *target, int32_t newValue);
	// 리턴: 변경 전의 값
	static int32_t CompareAndSwap(int32_t oldValue, int32_t newValue, volatile int32_t *target);

	// 리턴: 변경 전의 값
	static int32_t Swap(int32_t newValue, volatile int32_t *target);
};

	// atomic operation.
	// 주의: 당연하지만, target은 volatile & 32 or 64bit align이 되어 있어야 한다.
	// 리턴: 변경 후의 값
	inline int32_t AtomicIncrement32(volatile int32_t *target)
	{
#if defined(__MARMALADE__)
		return CSlowAtomic::Increment32(target);
		//return s3eAtomicIncrement32((int32*)target);
#elif defined(_WIN32)
		return InterlockedIncrement((volatile long*)target);
#else
		return __sync_add_and_fetch(target, 1);	// http://ecs.victoria.ac.nz/cgi-bin/info2www?%28gcc%29Atomic+Builtins 에 의하면 변경 후의 값
#endif
	}

//#ifdef _WIN32
//	inline int32_t AtomicAdd32(volatile int32_t* target, int32_t value)
//	{
//		return InterlockedAdd((volatile long*)target, value);
//	}
//#endif

	// atomic operation.
	// 주의: 당연하지만, target은 volatile & 32 or 64bit align이 되어 있어야 한다.
	// 리턴: 변경 후의 값
	inline int32_t AtomicDecrement32(volatile int32_t *target)
	{
#if defined(__MARMALADE__)
		return CSlowAtomic::Decrement32(target);
#elif defined(_WIN32)
		return InterlockedDecrement((volatile long*)target);
#else
		return __sync_sub_and_fetch(target, 1);
#endif
	}

	// atomic operation.
	// 주의: 당연하지만, target은 volatile & 32 or 64bit align이 되어 있어야 한다.
	// 리턴: 변경 전의 값
	inline int32_t AtomicCompareAndSwap32(int32_t oldValue, int32_t newValue, volatile int32_t *target)
	{
#if defined(__MARMALADE__)
		return CSlowAtomic::CompareAndSwap(oldValue,newValue,target);
		//return (bool)s3eAtomicCompareAndSwap(oldValue, newValue, (int32*)target);
#elif defined(_WIN32)
		return InterlockedCompareExchange((volatile long*)target, newValue, oldValue);
#else
		return __sync_val_compare_and_swap(target, oldValue, newValue);
#endif
	}


#if defined(_WIN64) || defined(__LP64__)
	// atomic operation.
	// 주의: 당연하지만, target은 volatile & 32 or 64bit align이 되어 있어야 한다.
	// 리턴: 변경 후의 값
	inline int64_t AtomicIncrement64(volatile int64_t *target)
	{
#if defined(__MARMALADE__)
		#error No 64bit for Marmalde yet
#elif defined(_WIN64)
		return InterlockedIncrement64(target);
#else
		return __sync_add_and_fetch(target, 1);	// http://ecs.victoria.ac.nz/cgi-bin/info2www?%28gcc%29Atomic+Builtins 에 의하면 변경 후의 값
#endif
	}

	// atomic operation.
	// 주의: 당연하지만, target은 volatile & 32 or 64bit align이 되어 있어야 한다.
	// 리턴: 변경 후의 값
	inline int64_t AtomicDecrement64(volatile int64_t *target)
	{
#if defined(__MARMALADE__)
		#error No 64bit for Marmalde yet
#elif defined(_WIN64)
		return InterlockedDecrement64(target);
#else
		return __sync_sub_and_fetch(target, 1);
#endif
	}

	// atomic operation.
	// 주의: 당연하지만, target은 volatile & 32 or 64bit align이 되어 있어야 한다.
	// 리턴: 타겟 피라미터의 초기값
	inline int64_t AtomicExchange64(int64_t newValue, volatile int64_t *target)
	{
#if defined(__MARMALADE__)
		#error No 64bit for Marmalde yet
#elif defined(_WIN64)
		return InterlockedExchange64(target, newValue);
#else
		// *target 값과 target 이 가리키는 값이 같다면 newValue 가 target 에 저장. 아니면 아무런 동작을 안함
		return __sync_val_compare_and_swap(target, *target, newValue);
#endif
	}

	// atomic operation.
	// 주의: 당연하지만, target은 volatile & 32 or 64bit align이 되어 있어야 한다.
	// 리턴: 변경 전의 값
	inline int64_t AtomicCompareAndSwap64(int64_t oldValue, int64_t newValue, volatile int64_t *target)
	{
#if defined(__MARMALADE__)
		#error No 64bit for Marmalde yet
#elif defined(_WIN64)
		return InterlockedCompareExchange64(target, newValue, oldValue);
#else
		return __sync_val_compare_and_swap(target, oldValue, newValue);
#endif
	}

#endif // _WIN64 || __LP64

	// CPU가 32bit이건 64bit이건 상관없이 쓰는 것들, 가령 object reference count 등에서 사용됨
	// NOTE:예전에는 `#define`이었으나, OSX에서 int32_t=int, intptr_t=long이라 컴파일 에러가 발생한다. 그래서 이렇게 수정해서 컴파일 에러를 피함.
#if defined(_WIN64) || defined(__LP64__) // https://developer.apple.com/library/mac/#documentation/Darwin/Conceptual/64bitPorting/MakingCode64-BitClean/MakingCode64-BitClean.html 참고
	// atomic operation.
	// 주의: 당연하지만, target은 volatile & 32 or 64bit align이 되어 있어야 한다.
	inline intptr_t AtomicIncrementPtr(volatile intptr_t *target)
	{
		return AtomicIncrement64((int64_t*)target);
	}

	// atomic operation.
	// 주의: 당연하지만, target은 volatile & 32 or 64bit align이 되어 있어야 한다.
	inline intptr_t AtomicDecrementPtr(volatile intptr_t *target)
	{
		return AtomicDecrement64((int64_t*)target);
	}

	inline void* AtomicCompareAndSwapPtr(void* oldValue, void* newValue, volatile void **target)
	{
		return (void*)AtomicCompareAndSwap64((int64_t)oldValue, (int64_t)newValue, (volatile int64_t*)target);
	}
#else
	// atomic operation.
	// 주의: 당연하지만, target은 volatile & 32 or 64bit align이 되어 있어야 한다.
	inline intptr_t AtomicIncrementPtr(volatile intptr_t *target)
	{
		return AtomicIncrement32((int32_t*)target);
	}

	// atomic operation.
	// 주의: 당연하지만, target은 volatile & 32 or 64bit align이 되어 있어야 한다.
	inline intptr_t AtomicDecrementPtr(volatile intptr_t *target)
	{
		return AtomicDecrement32((int32_t*)target);
	}

	inline void* AtomicCompareAndSwapPtr(void* oldValue, void* newValue, volatile void **target)
	{
		return (void*)AtomicCompareAndSwap32((int32_t)oldValue, (int32_t)newValue, (volatile int32_t*)target);
	}
#endif

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif