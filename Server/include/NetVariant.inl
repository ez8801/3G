#include "NetVariant.h"

namespace Proud
{
	void ThrowInvalidTypeException(NetVariantType type1, NetVariantType type2);

	// NetVariant�� buffer ���� �ٷ� POD ���� �ְ�, ���� Ÿ���� �����Ѵ�.
	// �����ڿ����� �� ����.
	template<typename T>
	inline void NetVariant::Init_Raw(NetVariantType type, T value)
	{
		m_type = type;
		*(T*)(GetBuffer_Internal()) = value;
	}

	// NetVariant�� POD type�� ��, buffer�κ��� ���� �ٷ� �����´�.
	// ���� ����.
	// Ÿ���� �� ������ ���ܰ� ��������.
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