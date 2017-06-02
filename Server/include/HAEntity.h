/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once

#include <vector>
#include "Message.h"
#include "FastMap.h"
#include "FastList.h"
#include "NetVariant.h"
#include "ClusterTypes.h"
#include "strpool.h"
#include "HATypedEntity.h"

namespace Proud
{
	class HATypedEntity;

	// Entity 안에 있는 1개의 field.
	class HAField
	{
	public:
		// 다양한 변수값을 담을 수 있는 객체
		// TODO: 빠른 초기 개발을 위해 CVariant를 쓰고 있지만, 추후에는 CVariant가 아니라 Proud.NetVariant로 바꾸자. NetVariant이미 여기에 구현되어 있음.
		NetVariant m_value;

		NetVariant& GetValue() { return m_value; }

#define DECLARE_HAFIELD_TRYGETVALUE(TYPE, DEFAULT, NETVARTYPE)\
		inline bool TryGetValue(TYPE& outValue) const\
		{\
			try { outValue = m_value.Get_Raw<TYPE>(NETVARTYPE); }\
			catch(...){ return false; }\
			return true;\
		}\

		DECLARE_HAFIELD_TRYGETVALUE(int8_t, 0, NetVariantType_Int8);
		DECLARE_HAFIELD_TRYGETVALUE(uint8_t, 0, NetVariantType_Uint8);
		DECLARE_HAFIELD_TRYGETVALUE(int16_t, 0, NetVariantType_Int16);
		DECLARE_HAFIELD_TRYGETVALUE(uint16_t, 0, NetVariantType_Uint16);
		DECLARE_HAFIELD_TRYGETVALUE(int32_t, 0, NetVariantType_Int32);
		DECLARE_HAFIELD_TRYGETVALUE(uint32_t, 0, NetVariantType_Uint32);
		DECLARE_HAFIELD_TRYGETVALUE(int64_t, 0, NetVariantType_Int64);
		DECLARE_HAFIELD_TRYGETVALUE(uint64_t, 0, NetVariantType_Uint64);
		DECLARE_HAFIELD_TRYGETVALUE(bool, false, NetVariantType_Bool);
		DECLARE_HAFIELD_TRYGETVALUE(float, 0.f, NetVariantType_Float);
		DECLARE_HAFIELD_TRYGETVALUE(double, 0, NetVariantType_Double);

		inline void operator=(const HAField& a)
		{
			m_value = a.m_value;
		}

		inline void operator=(const NetVariant& a)
		{
			m_value = a;
		}
	};

	class HAContainer;

	/* HABaseEntity.
	HABaseContainer 안에 들어간다.

	사용 예:

	HABaseEntityPtr e(new HABaseEntityPtr());
	e->SetField(_PNT("abc"), 345);
	e->SetField(_PNT("def"), _PNT("abc");
	*/
	class HAEntity
	{
	public:
		HAEntity(HAContainer *owner);
		HAEntity(HAContainer *owner, HostID ownerHostID, UniqueNumber entityID, String entityName = _PNT("Unknown"));
		~HAEntity();

	private:
		HAContainer *m_owner;

		// CStringPool 똑같은 스트링일 경우 pooled string 객체를 리턴합니다. 없으면 새로 추가 후 추가된 것을 리턴합니다.
		CStringPool::Holder m_stringPoolHolder;

		// key-value 데이터
		// #TODO_MEMORY 성능 최적화 단계에서, key를 String이 아니라 Proud.CStringPool을 쓰게 고치자. 메모리 아껴야 하니까.
		CFastMap<String, HAField*> m_fields;

		std::vector<StringA> m_keyVector;

		// 이 Entity 의 share tag 에 의해 매칭 된 동기화 대상
		CFastArray<HostID> m_shareTargets;

		// 이 entity 의 share tag 리스트
		// #TODO_MEMORY 성능 최적화 단계에서, key를 String이 아니라 Proud.CStringPool을 쓰게 고치자. 메모리 아껴야 하니까.
		CFastArray<String> m_shareTags;

		// 이 Base entity의 type 이름. 예: Knight, Player, ...
		String m_typeName;

		// 이 Entity 의 ID 값
		UniqueNumber m_entityID;

		// 이 entity 의 소유주
		HostID m_ownerHostID;

	private:
		HAContainer* GetContainer() const { 
			assert(m_owner); 
			return m_owner; 
		}

	public:
		// 값이 수정될 경우 콜백 (사용자는 절대 건들지 마십시오)
		LambdaBaseHolder_Param4<void, HAEntity*, HAField*, String, bool> OnChangeEntityValue_INTERNAL_ONLY;

		// 독점인 컨테이너에 속한 HAEntity에서 주인이 아닌자가 이 Entity를 수정하려 하면 이쪽으로 콜백 (사용자는 절대 건들지 마십시오)
		LambdaBaseHolder_Param4<void, HostID, UniqueNumber, const String&, const NetVariant&> OnChangeEntityValueFromAnother_INTERNAL_ONLY;

	public:
		bool IsIgnoreShareTag() { return m_shareTags.GetCount() == 0; }

		void AddShareTag(String tag);
		void AddShareTargetAfterCompareShareTag(HostID remote, const CFastArray<String>& tags);
		void RemoveShareTarget(HostID remote);

		const CFastArray<HostID>& GetShareTargets() { return m_shareTargets; }

	public:
		// 이 Base entity의 type 이름. 예: Knight, Player, ...
		String GetTypeName() { return m_typeName; }

		// 이 entity 의 유니크 아이디 값
		UniqueNumber GetEntityID() { return m_entityID; }

		// 이 entity 의 소유주 HostID
		HostID GetOwnerHostID() { return m_ownerHostID; }

		// 이 entity 의 소유주 설정
		void SetOwnerHostID(HostID owner) { m_ownerHostID = owner; }

		HAField* GetField(const String& key);

 		NetVariant GetFieldValue(const String& key);
		bool TryGetFieldValue(const String& key, NetVariant& output);

		HAField* SetFieldValue_NOSYNC(const String& key, const NetVariant& value);
		HAField* SetFieldValue_NOSYNC(const String& key, const NetVariant& value, bool& isFieldAdd);
		void SetFieldValue(const String& key, const NetVariant& value);

		void SetFieldValue_callByHACompiler(const String& key, HAField* pField, const NetVariant& value);

		const CFastMap<String, HAField*>& GetFields() const { return m_fields; }

		void CopyTo(HAEntity* entity);

		// Entity Field Index 처리
		void UpdateIndex(const PNTCHAR* fieldName, const NetVariant& oldValue, const NetVariant& newValue, HAEntity* entity);
		void RemoveIndex(const PNTCHAR* fieldName, const NetVariant& value, HAEntity* entity);
		void AddIndex(const PNTCHAR* fieldName, NetVariant& field, HAEntity* entity);

		/*
		Serialized data structure

		String		: Entity Type 이름
		int32_t		: 필드 갯수

		Field area
		String		: N 번째 필드 Key
		Variant		: N 번재 필드 Value
		*/
		void Serialize(ByteArray& output);
		void Deserialize(const ByteArray& input);

		// for SWIG
		int GetFieldCount() const { return m_keyVector.size(); }
		void GetKeys(std::vector<const char*> &refKeyArray) const;

		//////////////////////////////////////////////////////////////////////////
		// HA compiler output과 연동되는 기능들

	private:
		friend class HATypedEntity;
		
		// HA compiler에서 만들어진 typed HAEntity이다.
		// 사용자가 typed HAEntity를 사용하지 않고 있다면 이는 null이다.
		// 사용자가 typed HAEntity를 요구한 적이 있다면 그때가서 채워진다.
		// typed entity와 기본 entity는 생사를 같이 한다. typed entity가 child이다. 
		// unique_ptr을 쓰고 싶지만 prebuild lib의 API이다. 그래서 CHeldPtr을 쓴다.
		CHeldPtr<HATypedEntity> m_typedEntity;

	public:

		/** Typed HAEntity 객체를 얻어옵니다.
		여러분이 쓰실 일은 별로 없습니다. 이것 대신에 여러분이 HA compiler에서 생성한 클래스에 대해 Cast 함수를 쓰시기 바랍니다.
		
		\code
		HAEntity* e = ...;
		Boo* boo = Boo::Cast(e);
		\endcode
		
		*/
		HATypedEntity* GetTypedEntity() const 
		{ return m_typedEntity; }

		//////////////////////////////////////////////////////////////////////////

	private:
		// Binary 관련 내부 함수
		void SetBinaryField_Internal(const String& key, uint8_t* data, int length);
		// 현재는 사용되지 않고 있는 함수
		// 나중에 필요 할 수 있어서 주석 처리
// 		int GetBinaryFieldLength(const String& key);
// 		int GetBinaryField_Internal(const String& key, uint8_t* data, int length);

	public:

		template<typename T>
		void SetBinaryField(const String& key, const T& input)
		{
			CMessage msg; // 매개체로 사용
						  // 입력값을 msg로 변환
			msg.UseInternalBuffer();
			msg << input;
			// msg를 binary로 field에 채운다.
			SetBinaryField_Internal(key, msg.GetData(), msg.GetLength());
		}

		template<typename T>
		bool GetBinaryField(const String& key, T& output)
		{
			CMessage msg; // 매개체로 활용
			msg.UseInternalBuffer();

			NetVariant value;

			if (!TryGetFieldValue(key, value))
			{
				return false;
			}

			// Binary Type이 아니면 return
			if (value.GetType() != NetVariantType_Binary)
			{
				return false;
			}

			// 먼저 크기부터 얻기
			int len = value.GetBinaryLength();

			// 반환할 결과가 없음
			if (len == 0)
			{
				return false;
			}

			msg.SetLength(len);

			// 데이터 복사
			memcpy_s(msg.GetData(), len, value.GetBinaryPtr()->GetData(), len);

			// 마샬링 처리
			msg >> output;

			return true;
		}
	};
}
