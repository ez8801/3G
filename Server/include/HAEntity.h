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

	// Entity �ȿ� �ִ� 1���� field.
	class HAField
	{
	public:
		// �پ��� �������� ���� �� �ִ� ��ü
		// TODO: ���� �ʱ� ������ ���� CVariant�� ���� ������, ���Ŀ��� CVariant�� �ƴ϶� Proud.NetVariant�� �ٲ���. NetVariant�̹� ���⿡ �����Ǿ� ����.
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
	HABaseContainer �ȿ� ����.

	��� ��:

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

		// CStringPool �Ȱ��� ��Ʈ���� ��� pooled string ��ü�� �����մϴ�. ������ ���� �߰� �� �߰��� ���� �����մϴ�.
		CStringPool::Holder m_stringPoolHolder;

		// key-value ������
		// #TODO_MEMORY ���� ����ȭ �ܰ迡��, key�� String�� �ƴ϶� Proud.CStringPool�� ���� ��ġ��. �޸� �Ʋ��� �ϴϱ�.
		CFastMap<String, HAField*> m_fields;

		std::vector<StringA> m_keyVector;

		// �� Entity �� share tag �� ���� ��Ī �� ����ȭ ���
		CFastArray<HostID> m_shareTargets;

		// �� entity �� share tag ����Ʈ
		// #TODO_MEMORY ���� ����ȭ �ܰ迡��, key�� String�� �ƴ϶� Proud.CStringPool�� ���� ��ġ��. �޸� �Ʋ��� �ϴϱ�.
		CFastArray<String> m_shareTags;

		// �� Base entity�� type �̸�. ��: Knight, Player, ...
		String m_typeName;

		// �� Entity �� ID ��
		UniqueNumber m_entityID;

		// �� entity �� ������
		HostID m_ownerHostID;

	private:
		HAContainer* GetContainer() const { 
			assert(m_owner); 
			return m_owner; 
		}

	public:
		// ���� ������ ��� �ݹ� (����ڴ� ���� �ǵ��� ���ʽÿ�)
		LambdaBaseHolder_Param4<void, HAEntity*, HAField*, String, bool> OnChangeEntityValue_INTERNAL_ONLY;

		// ������ �����̳ʿ� ���� HAEntity���� ������ �ƴ��ڰ� �� Entity�� �����Ϸ� �ϸ� �������� �ݹ� (����ڴ� ���� �ǵ��� ���ʽÿ�)
		LambdaBaseHolder_Param4<void, HostID, UniqueNumber, const String&, const NetVariant&> OnChangeEntityValueFromAnother_INTERNAL_ONLY;

	public:
		bool IsIgnoreShareTag() { return m_shareTags.GetCount() == 0; }

		void AddShareTag(String tag);
		void AddShareTargetAfterCompareShareTag(HostID remote, const CFastArray<String>& tags);
		void RemoveShareTarget(HostID remote);

		const CFastArray<HostID>& GetShareTargets() { return m_shareTargets; }

	public:
		// �� Base entity�� type �̸�. ��: Knight, Player, ...
		String GetTypeName() { return m_typeName; }

		// �� entity �� ����ũ ���̵� ��
		UniqueNumber GetEntityID() { return m_entityID; }

		// �� entity �� ������ HostID
		HostID GetOwnerHostID() { return m_ownerHostID; }

		// �� entity �� ������ ����
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

		// Entity Field Index ó��
		void UpdateIndex(const PNTCHAR* fieldName, const NetVariant& oldValue, const NetVariant& newValue, HAEntity* entity);
		void RemoveIndex(const PNTCHAR* fieldName, const NetVariant& value, HAEntity* entity);
		void AddIndex(const PNTCHAR* fieldName, NetVariant& field, HAEntity* entity);

		/*
		Serialized data structure

		String		: Entity Type �̸�
		int32_t		: �ʵ� ����

		Field area
		String		: N ��° �ʵ� Key
		Variant		: N ���� �ʵ� Value
		*/
		void Serialize(ByteArray& output);
		void Deserialize(const ByteArray& input);

		// for SWIG
		int GetFieldCount() const { return m_keyVector.size(); }
		void GetKeys(std::vector<const char*> &refKeyArray) const;

		//////////////////////////////////////////////////////////////////////////
		// HA compiler output�� �����Ǵ� ��ɵ�

	private:
		friend class HATypedEntity;
		
		// HA compiler���� ������� typed HAEntity�̴�.
		// ����ڰ� typed HAEntity�� ������� �ʰ� �ִٸ� �̴� null�̴�.
		// ����ڰ� typed HAEntity�� �䱸�� ���� �ִٸ� �׶����� ä������.
		// typed entity�� �⺻ entity�� ���縦 ���� �Ѵ�. typed entity�� child�̴�. 
		// unique_ptr�� ���� ������ prebuild lib�� API�̴�. �׷��� CHeldPtr�� ����.
		CHeldPtr<HATypedEntity> m_typedEntity;

	public:

		/** Typed HAEntity ��ü�� ���ɴϴ�.
		�������� ���� ���� ���� �����ϴ�. �̰� ��ſ� �������� HA compiler���� ������ Ŭ������ ���� Cast �Լ��� ���ñ� �ٶ��ϴ�.
		
		\code
		HAEntity* e = ...;
		Boo* boo = Boo::Cast(e);
		\endcode
		
		*/
		HATypedEntity* GetTypedEntity() const 
		{ return m_typedEntity; }

		//////////////////////////////////////////////////////////////////////////

	private:
		// Binary ���� ���� �Լ�
		void SetBinaryField_Internal(const String& key, uint8_t* data, int length);
		// ����� ������ �ʰ� �ִ� �Լ�
		// ���߿� �ʿ� �� �� �־ �ּ� ó��
// 		int GetBinaryFieldLength(const String& key);
// 		int GetBinaryField_Internal(const String& key, uint8_t* data, int length);

	public:

		template<typename T>
		void SetBinaryField(const String& key, const T& input)
		{
			CMessage msg; // �Ű�ü�� ���
						  // �Է°��� msg�� ��ȯ
			msg.UseInternalBuffer();
			msg << input;
			// msg�� binary�� field�� ä���.
			SetBinaryField_Internal(key, msg.GetData(), msg.GetLength());
		}

		template<typename T>
		bool GetBinaryField(const String& key, T& output)
		{
			CMessage msg; // �Ű�ü�� Ȱ��
			msg.UseInternalBuffer();

			NetVariant value;

			if (!TryGetFieldValue(key, value))
			{
				return false;
			}

			// Binary Type�� �ƴϸ� return
			if (value.GetType() != NetVariantType_Binary)
			{
				return false;
			}

			// ���� ũ����� ���
			int len = value.GetBinaryLength();

			// ��ȯ�� ����� ����
			if (len == 0)
			{
				return false;
			}

			msg.SetLength(len);

			// ������ ����
			memcpy_s(msg.GetData(), len, value.GetBinaryPtr()->GetData(), len);

			// ������ ó��
			msg >> output;

			return true;
		}
	};
}
