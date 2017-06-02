/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once

#include "HATypedEntity.h"
#include "ClusterTypes.h"

namespace Proud
{
	// 인덱스 객체
	class HAIndex;

	class HAContainer
	{
	public:
		HAContainer() {}
		virtual ~HAContainer() {}

	public:
		virtual const CFastMap<UniqueNumber, HAEntity*>* GetEntities() = 0;

		virtual void AddEntity(HAEntity* entity) = 0;
		virtual void RemoveEntity(UniqueNumber entityID) = 0;
		// Entity를 찾는 함수
		virtual HAEntity* FindEntity(UniqueNumber entityID) = 0;
		virtual void FindEntity(const PNTCHAR* typeName, const PNTCHAR* fieldName, const NetVariant& fieldValue, CFastArray<HAEntity*>& output) = 0;

		// 인덱스 등록
		virtual void SetIndex(const PNTCHAR* typeName, const PNTCHAR* fieldName) = 0;
		virtual HAIndex* GetIndex(const PNTCHAR* typeName, const PNTCHAR* fieldName) const = 0;

		// 이 함수는 사용자가 절대 호출하지 말것
		virtual void ReindexForDeletedEntity(HAEntity* entity) = 0;

	public:
		friend class HAContainerLock;
	};
}