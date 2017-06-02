/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once

#include "pnstdint.h"

namespace Proud
{
	// variant type ����.
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

	/** �Ϲ����� variant type Ŭ����.
	
	����� ������ �ٸ� ��ü���� ���̴� ������ �����ϴ�.
	
	- CVariant�� ADO,OLE,COM���� ���� ���̴� ��������, ���� �����̴�. ������ �̰��� ��� �÷������� �� �� �ִ�.
	- COdbcVariant�� ODBC���� �����ϴ� ���� Ÿ���� ���� ��������, Ŭ��,���� ��ΰ� ���⿡�� ���ʿ��ϰ� ���̴�. ������ �̰��� �ܺ� �ڵ忡 �������� �ʴ´�.

	�Ϲ����� ����

	- ������ �����Ѵ�.
	- ���ó�� ������ ���� �Է��ϰų� ����ϸ� �ȴ�.
	
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

		/** ���빰�� ���ְ� �ʱ�ȭ�մϴ�. */
		void Reset();

		//////////////////////////////////////////////////////////////////////////
		// �� ����¿� �Լ���

		NetVariant(bool value);
		operator bool() const;

		NetVariant(int64_t value);
		operator int64_t() const;

		//////////////////////////////////////////////////////////////////////////

		/** � ������ ���� ���� �ִ���? */
		inline NetVariantType GetType() const
		{
			return m_type;
		}
	private:
		// ���� Ÿ��
		NetVariantType m_type;

		// �� �ȿ� ��� ������ ��ü�� ĳ���õǾ� ����.
		char m_buffer[BufferLength];

		template<typename T>
		void Init_Raw(NetVariantType type, T value);

		template<typename T>
		T Get_Raw(NetVariantType type) const;
	public:
		
		// public������, ���� ���� �Լ����̴�.
		inline void* GetBuffer_Internal() { return m_buffer; }
		inline const void* GetBuffer_Internal() const { return m_buffer; }
	};

}

// ���ɿ� �ΰ��� Ŭ������. ���� inline �Լ��� �����Ǿ� �ִ�.
#include "NetVariant.inl"
