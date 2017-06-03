#include "NetVariant.h"

namespace Proud
{
	void ThrowInvalidTypeException(NetVariantType type1, NetVariantType type2);

	// NetVariant의 buffer 값에 바로 POD 값을 넣고, 변수 타입을 지정한다.
	// 생성자에서만 콜 하자.
	template<typename T>
	inline void NetVariant::Init_Raw(NetVariantType type, T value)
	{
		m_type = type;
		*(T*)(GetBuffer_Internal()) = value;
	}

	// NetVariant가 POD type일 때, buffer로부터 값을 바로 가져온다.
	// 내부 전용.
	// 타입이 안 맞으면 예외가 던져진다.
	template<typename T>
	inline T NetVariant::Get_Raw(NetVariantType type) const
	{
		if (m_type != type)
			ThrowInvalidTypeException(type, m_type);
		T* pv = (T*)GetBuffer_Internal();
		return *pv;

	}

	inline NetVariant::NetVariant()
	{
		m_type = NetVariantType_None;
	}

	inline NetVariant::NetVariant(bool value)
	{
		Init_Raw<bool>(NetVariantType_Bool, value);
	}

	inline NetVariant::NetVariant(int64_t value)
	{
		Init_Raw<int64_t>(NetVariantType_Int64, value);
	}

	inline NetVariant::operator bool() const
	{
		return Get_Raw<bool>(NetVariantType_Bool);
	}

	inline NetVariant::operator int64_t() const
	{
		return Get_Raw<int64_t>(NetVariantType_Int64);
	}


	inline NetVariant::~NetVariant()
	{
		Reset();
	}

	inline void NetVariant::Reset()
	{
		m_type = NetVariantType_None;
	}


}