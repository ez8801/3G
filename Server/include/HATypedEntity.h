/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once 

#include "HAEntity.h"

namespace Proud
{
	class HAEntity;
	class HAField;
	class HATypedEntity;

	/** 본 클래스에 대한 설명은 guide.nettention.com에서 typed HAEntity에 대한 글을 보시기 바랍니다.

	이 클래스는 사용자가 typed HAEntity에서 멤버 변수를 바로 액세스할 수 있게 해주는 기능을 제공합니다.
	*/
	template<typename T>
	class HATypedField
	{
		friend class HATypedEntity;

		// HAEntity의 map의 value를 직접 가리킨다.
		HAEntity* m_ownerEntity;
		HAField* m_pField;

		// field name이다.
		// string pool에서 가져온 이름이다.
		String m_fieldName;

	public:
		// 기본 생성자. 
		HATypedField()
			: m_ownerEntity(nullptr)
			, m_pField(nullptr)
		{
		}

		///////////////////////
		// 자연스럽게 in,out이 되게 한다.
		
		// 사용자에 의해 실행되는 get 함수
		inline operator T() const
		{
			return m_pField->m_value;
		}

		// 사용자에 의해 실행되는 set 함수.
		HATypedField& operator=(const T& src)
		{
			// HAEntity는 이 변화를 인지해야 한다. 따라서 set function을 호출하자.
			// 사용자는 player position 같은 것을 안 바뀌는데도 자주 업데이트하기도 한다.
			// 이럴떄 map lookup을 하면 성능을 크게 깎아먹는다. 서버에서.
			// 따라서 map lookup이 생략된 콜을 하도록 하자.
		
#ifdef _DEBUG
			HAField* pField_old = m_pField;
			assert(pField_old);
#endif
			// TODO: 이 함수 안에다 이렇게 구현하자.
			// field는 이미 찾았으니 건너뛰고 나머지는 그대로 작동하게 하자.
			m_ownerEntity->SetFieldValue(m_fieldName, src);
			//m_ownerEntity->SetFieldValue_callByHACompiler(m_fieldName, m_pField, src);
#ifdef _DEBUG
			HAField* pField_new = m_ownerEntity->GetField(m_fieldName);
			// 이게 달라지면, 위 코드가 정상 작동할 수 없다.
			assert(pField_old == pField_new);
#endif
			return *this;
		}

	};


	/** HAEntity의 strict type형 class의 base class입니다.

	HA compiler가 상속받습니다. 여러분은 이 클래스를 상속하지 마세요. 
	*/
	class HATypedEntity
	{		
		// 1대1 대응하는 HAEntity 객체
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

// 		/**  자동 캐스팅 함수입니다. */
// 		operator HAEntity*() const
// 		{
// 			return m_ownerEntity;
// 		}

		// HA compiler가 내부적으로 호출하는 함수입니다. 사용자는 쓰지 말 것.
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
				// 새로 만들고 쌍방 링크한다.
				TypedEntityType* typedEntity = new TypedEntityType();
				typedEntity->m_ownerEntity = entity;
				entity->m_typedEntity.Attach(typedEntity);

				// 필드들을 초기화
				typedEntity->MatchFields();
			}

			// 사용자가 다른 typed HAEntity에 대해서 이미 Cast를 한 적이 있을 수도 있다.
			// 따라서 dynamic_cast를 쓰자.
			return dynamic_cast<TypedEntityType*>(entity->GetTypedEntity());
		}

		// HATypedEntity의 상속 클래스가 이미 갖고 있는 field들을, HAEntity에 있는 필드들과 매칭하는 작업을 한다.
		// HA compiler가 실행합니다. 사용자는 쓰지 맙시다.
		virtual void MatchFields() = 0;

		// HA compiler가 내부적으로 호출하는 함수입니다. 사용자는 쓰지 말 것.
		template<typename FieldType>
		void MatchField(const PNTCHAR* fieldName, HATypedField<FieldType>& refTypedField, const FieldType& defaultValue = FieldType())
		{
			refTypedField.m_ownerEntity = m_ownerEntity;
			HAField* pField = m_ownerEntity->GetField(fieldName);
			if (!pField)
			{
				// 없으니까 일단은 추가한다.
				m_ownerEntity->SetFieldValue(fieldName, defaultValue);
			}
			
			// 필드를 찾는다. 그리고 매칭한다.
			pField = m_ownerEntity->GetField(fieldName);

			assert(pField);
			refTypedField.m_pField = pField;
			refTypedField.m_fieldName = m_ownerEntity->m_stringPoolHolder->GetString(fieldName);
		}
	};
}