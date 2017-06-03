/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once 

#include "HAEntity.h"

namespace Proud
{
	class HAEntity;
	class HAField;
	class HATypedEntity;

	/** �� Ŭ������ ���� ������ guide.nettention.com���� typed HAEntity�� ���� ���� ���ñ� �ٶ��ϴ�.

	�� Ŭ������ ����ڰ� typed HAEntity���� ��� ������ �ٷ� �׼����� �� �ְ� ���ִ� ����� �����մϴ�.
	*/
	template<typename T>
	class HATypedField
	{
		friend class HATypedEntity;

		// HAEntity�� map�� value�� ���� ����Ų��.
		HAEntity* m_ownerEntity;
		HAField* m_pField;

		// field name�̴�.
		// string pool���� ������ �̸��̴�.
		String m_fieldName;

	public:
		// �⺻ ������. 
		HATypedField()
			: m_ownerEntity(nullptr)
			, m_pField(nullptr)
		{
		}

		///////////////////////
		// �ڿ������� in,out�� �ǰ� �Ѵ�.
		
		// ����ڿ� ���� ����Ǵ� get �Լ�
		inline operator T() const
		{
			return m_pField->m_value;
		}

		// ����ڿ� ���� ����Ǵ� set �Լ�.
		HATypedField& operator=(const T& src)
		{
			// HAEntity�� �� ��ȭ�� �����ؾ� �Ѵ�. ���� set function�� ȣ������.
			// ����ڴ� player position ���� ���� �� �ٲ�µ��� ���� ������Ʈ�ϱ⵵ �Ѵ�.
			// �̷��� map lookup�� �ϸ� ������ ũ�� ��ƸԴ´�. ��������.
			// ���� map lookup�� ������ ���� �ϵ��� ����.
		
#ifdef _DEBUG
			HAField* pField_old = m_pField;
			assert(pField_old);
#endif
			// TODO: �� �Լ� �ȿ��� �̷��� ��������.
			// field�� �̹� ã������ �ǳʶٰ� �������� �״�� �۵��ϰ� ����.
			m_ownerEntity->SetFieldValue(m_fieldName, src);
			//m_ownerEntity->SetFieldValue_callByHACompiler(m_fieldName, m_pField, src);
#ifdef _DEBUG
			HAField* pField_new = m_ownerEntity->GetField(m_fieldName);
			// �̰� �޶�����, �� �ڵ尡 ���� �۵��� �� ����.
			assert(pField_old == pField_new);
#endif
			return *this;
		}

	};


	/** HAEntity�� strict type�� class�� base class�Դϴ�.

	HA compiler�� ��ӹ޽��ϴ�. �������� �� Ŭ������ ������� ������. 
	*/
	class HATypedEntity
	{		
		// 1��1 �����ϴ� HAEntity ��ü
		HAEntity* m_ownerEntity;

	public:
		HATypedEntity()
			: m_ownerEntity(nullptr)
		{
		}

		HAEntity* GetOwnerEntity() const
		{
			return m_ownerEntity;
		}

// 		/**  �ڵ� ĳ���� �Լ��Դϴ�. */
// 		operator HAEntity*() const
// 		{
// 			return m_ownerEntity;
// 		}

		// HA compiler�� ���������� ȣ���ϴ� �Լ��Դϴ�. ����ڴ� ���� �� ��.
		template <typename TypedEntityType>
		static TypedEntityType* CastT(HAEntity* entity, const PNTCHAR* typeName)
		{
			if (!entity)
				return nullptr;

			if (entity->GetTypeName() != typeName)
			{
				return nullptr;
			}
			if (!entity->GetTypedEntity())
			{
				// ���� ����� �ֹ� ��ũ�Ѵ�.
				TypedEntityType* typedEntity = new TypedEntityType();
				typedEntity->m_ownerEntity = entity;
				entity->m_typedEntity.Attach(typedEntity);

				// �ʵ���� �ʱ�ȭ
				typedEntity->MatchFields();
			}

			// ����ڰ� �ٸ� typed HAEntity�� ���ؼ� �̹� Cast�� �� ���� ���� ���� �ִ�.
			// ���� dynamic_cast�� ����.
			return dynamic_cast<TypedEntityType*>(entity->GetTypedEntity());
		}

		// HATypedEntity�� ��� Ŭ������ �̹� ���� �ִ� field����, HAEntity�� �ִ� �ʵ��� ��Ī�ϴ� �۾��� �Ѵ�.
		// HA compiler�� �����մϴ�. ����ڴ� ���� ���ô�.
		virtual void MatchFields() = 0;

		// HA compiler�� ���������� ȣ���ϴ� �Լ��Դϴ�. ����ڴ� ���� �� ��.
		template<typename FieldType>
		void MatchField(const PNTCHAR* fieldName, HATypedField<FieldType>& refTypedField, const FieldType& defaultValue = FieldType())
		{
			refTypedField.m_ownerEntity = m_ownerEntity;
			HAField* pField = m_ownerEntity->GetField(fieldName);
			if (!pField)
			{
				// �����ϱ� �ϴ��� �߰��Ѵ�.
				m_ownerEntity->SetFieldValue(fieldName, defaultValue);
			}
			
			// �ʵ带 ã�´�. �׸��� ��Ī�Ѵ�.
			pField = m_ownerEntity->GetField(fieldName);

			assert(pField);
			refTypedField.m_pField = pField;
			refTypedField.m_fieldName = m_ownerEntity->m_stringPoolHolder->GetString(fieldName);
		}
	};
}