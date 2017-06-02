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

#include "PNString.h"
#if !defined(_WIN32)
#include "BasicTypes.h"
#endif
#include <time.h>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#ifdef _WIN32
// 윈도 버전이라도 #include <oledb.h>를 include할 수 없는 환경 때문에 전방 선언만 한다.
struct tagDBTIMESTAMP;
typedef tagDBTIMESTAMP DBTIMESTAMP;
#endif // _WIN32



// #ikpil.choi 2017-02-17 : Visual Studio 2015 이상부터 timespec 지원, 그 이하는 지원 안하므로, 별도로 정의
#if defined(_WIN32) && !defined(_CRT_NO_TIME_T) && (1900 > _MSC_VER)
struct timespec
{
	time_t tv_sec;  // Seconds - >= 0
	long   tv_nsec; // Nanoseconds - [0, 999999999]
};
#endif

namespace Proud
{
	// #ikpil.choi 2017-02-17 : timespec_get 의 필요 define, 크로스 플랫폼 지원으로 선언되어 있지 않으면, 선언합니다.
#ifndef TIME_UTC
	enum
	{
		// #ikpil.choi 2017-03-03 : 다른곳에서 TIME_UTC 를 재정의 할 수 있으므로, enum으로 정의
		TIME_UTC = 1
	};
#endif
	/**
	\~korean
	\brief localtime_s 를 크로스 플랫폼에서 지원하기 위한 함수.
	\param[in]  time tm으로 바꾸기 위한 utc 기준의 time_t 포인터 변수
	\param[out] t    tm 인자로 넣은 time을 tm으로 출력하는 변수

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/
	errno_t localtime_pn(const ::time_t* time, ::tm* t);

	/**
	\~korean
	\brief gmtime_s 를 크로스 플랫폼에서 지원하기 위한 함수.
	\param[in]  time tm으로 바꾸기 위한 utc 기준의 time_t 포인터 변수
	\param[out] t    tm 인자로 넣은 time을 tm으로 출력하는 변수

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/
	errno_t gmtime_pn(const ::time_t* time, ::tm* t);

	/**
	\~korean
	\brief timespec_get 을 크로스 플랫폼에서 지원하기 위한 함수.
	\param[out] tp   출력될 timespec 구조체
	\param[in]  base TIME_UTC 또는 타임베이스를 나타내는 다른 0이 아닌 정수 값 (현재는 TIME_UTC만 지원함)

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/
	int timespec_get_pn(::timespec *tp, int const base);

	/**
	\~korean
	\brief struct timespec을 나노세컨드로 바꾸는 함수
	\param[in] ts 나노세컨트로 변환시킬 struct timespec

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/
	long long timespec_to_nanosecond(const ::timespec& ts);

	/**
	\~korean
	\brief 나노세컨드를 struct timespec으로 바꾸는 함수
	\param[in]  ns struct timespec 으로 바꿀 나노세컨드
	\param[out] tp 출력될 struct timespec

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/
	int nanosecond_to_timespec(const long long& ns, timespec *tp);

	/**
	\~korean
	\brief struct timespec을 밀리세컨드로 바꾸는 함스
	\param[in] ts 밀리세컨드로 바꿀 struct timespec

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/
	long long timespec_to_millisecond(const ::timespec& ts);

	/**
	\~korean
	\brief 밀리세컨드를 struct timespec으로 바꾸는 함수
	\param[in] ts 밀리세컨드로 바꿀 struct timespec

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/

	int millisecond_to_timespec(const long long& ms, timespec *tp);

	/**
	\~korean
	\brief UTC 기준으로 현재 머신의 나노세컨드를 반환하는 함수

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/
	long long GetCurrentTimeNanoSecond();

	/**
	\~korean
	\brief UTC 기준으로 현재 머신의 밀리세컨드를 반환하는 함수

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/

	long long GetCurrentTimeMilliSecond();
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
