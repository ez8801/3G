/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once

#include "pnstdint.h"

namespace Proud
{
	// variant type 값들.
	enum NetVariantType
	{
		NetVariantType_None,
		NetVariantType_Bool,
		NetVariantType_Int8,
		NetVariantType_Int16,
		NetVariantType_Int32,
		NetVariantType_Int64,
		NetVariantType_Float,
		NetVariantType_Double,
		NetVariantType_String,
		NetVariantType_TimeStamp,
		NetVariantType_Uuid,
		NetVariantType_Binary,
	};

	/** 일반적인 variant type 클래스.
	
	비슷한 종류의 다른 객체와의 차이는 다음과 같습니다.
	
	- CVariant는 ADO,OLE,COM등을 위해 쓰이는 것인지라, 윈도 전용이다. 하지만 이것은 모든 플랫폼에서 쓸 수 있다.
	- COdbcVariant는 ODBC에서 지원하는 변수 타입을 위한 것인지라, 클라,서버 모두가 쓰기에는 불필요하게 무겁다. 하지만 이것은 외부 코드에 의존하지 않는다.

	일반적인 사용법

	- 변수를 선언한다.
	- 평소처럼 변수에 값을 입력하거나 출력하면 된다.
	
	\code
	NetVariant a;
	a = (int)1;
	assert(a.GetType()==NetVariantType_Int32);
	int b = a;

	NetVariant b;
	b = _PNT("abc");
	
	\endcode
	*/
	class NetVariant
	{
		static const int BufferLength = 64;
	public:
		NetVariant();
		~NetVariant();

		/** 내용물을 없애고 초기화합니다. */
		void Reset();

		//////////////////////////////////////////////////////////////////////////
		// 값 입출력용 함수들

		NetVariant(bool value);
		operator bool() const;

		NetVariant(int64_t value);
		operator int64_t() const;

		//////////////////////////////////////////////////////////////////////////

		/** 어떤 종류의 값을 갖고 있는지? */
		inline NetVariantType GetType() const
		{
			return m_type;
		}
	private:
		// 변수 타입
		NetVariantType m_type;

		// 이 안에 모든 종류의 객체가 캐스팅되어 들어간다.
		char m_buffer[BufferLength];

		template<typename T>
		void Init_Raw(NetVariantType type, T value);

		template<typename T>
		T Get_Raw(NetVariantType type) const;
	public:
		
		// public이지만, 내부 전용 함수들이다.
		inline void* GetBuffer_Internal() { return m_buffer; }
		inline const void* GetBuffer_Internal() const { return m_buffer; }
	};

}

// 성능에 민감한 클래스다. 따라서 inline 함수로 구현되어 있다.
#include "NetVariant.inl"
