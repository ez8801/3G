/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once

#include "ClusterEvent.h"
#include "ClusterTypes.h"
#include "IRmiHost.h"
#include "HAContainer.h"

namespace Proud
{
	class IClusterClientEvent;

	class ClusterClient :
		public IRmiHost
	{
	public:
		ClusterClient() {}
		virtual ~ClusterClient() {}

	public:
		// 클러스터 서버와 연결이 맺어진 뒤, Secure Key 교환 과정을 완벽하게 거치고 P2P 그룹이 맺어지면 콜백 됩니다.
		LambdaBaseHolder_Param1<void, const ErrorInfo*> OnJoinServerComplete;

		// 클러스터 서버와 연결이 끊어지면 콜백 됩니다.
		LambdaBaseHolder_Param1<void, const ErrorInfo*> OnLeaveServer;

		// 클러스터 서버와 임의의 CUC 가 접속 하였을 경우 최초로 콜백 됩니다.
		LambdaBaseHolder_Param1<void, const CFastArray<HostID>&> OnPeerJoin;

		// 클러스터 서버와 임의의 CUC 가 접속 해제 되었을 경우 콜백 됩니다. 현재 이런 상황은 발생하지 않습니다.
		LambdaBaseHolder_Param1<void, const ErrorInfo*> OnPeerLeave;

		// 특정 클러스터 클라이언트와 연결이 확립 되었을 경우 콜백 됩니다.
		LambdaBaseHolder_Param1<void, HostID> OnP2PConnected;

		// 특정 클러스터 클라이언트와 연결이 해제 되었을 경우 콜백 됩니다.
		LambdaBaseHolder_Param1<void, HostID> OnP2PDisconnected;

		// 존재 하지 않는 RMI ID 일 경우 해당 함수가 콜백 됩니다.
		LambdaBaseHolder_Param1<void, int> OnNoRmiProcessed;

		// RMI 처리 도중 예외 발생 시, 이 함수가 콜백 됩니다.
		LambdaBaseHolder_Param1<void, const Exception&> OnException;

		// 경고가 발생 할 때, 이 함수가 콜백 됩니다. 현재 이런 상황은 발생하지 않습니다.
		LambdaBaseHolder_Param1<void, const ErrorInfo*> OnWarning;

		// HA Viz에서 사용되는 APIGateway 서버에 정상 접속 되면 콜백 됩니다.
		LambdaBaseHolder_Param1<void, const ErrorInfo*> OnJoinApiGatewayServerComplete;

		// HA Viz에서 사용되는 APIGateway 서버와 연결이 끊어졌을 경우 콜백 됩니다.
		LambdaBaseHolder_Param1<void, const ErrorInfo*>	OnLeaveApiGatewayServer;

		// ClusterClientStartParameter.timerCallbackIntervalMs 이 0이 아니라면 해당 ms마다 콜백 됩니다.
		LambdaBaseHolder_Param1<void, void*> OnTick;

		// PresenceEntity를 만들면 콜백 됩니다.
		LambdaBaseHolder_Param2<void, HostID, UniqueNumber> OnCreatePresenceEntity;

		// PresenceEntity가 갱신되면 콜백 됩니다.
		LambdaBaseHolder_Param3<void, HostID, UniqueNumber, const CFastArray<String>&> OnUpdatePresenceEntity;

		// PresenceEntity가 지워지면 콜백 됩니다.
		LambdaBaseHolder_Param2<void, HostID, UniqueNumber> OnDeletePresenceEntity;

	public:
		/** Cluster Server로의 연결을 합니다. */
		virtual void Start(const ClusterClientStartParameter& param) = 0;
		virtual void StopAsync() = 0;
		virtual void Stop() = 0;

		// 클러스터 고유의 호스트 아이디를 가져온다.
		// 이는 클러스터 전반에 걸쳐 유니크한 값이다.
		virtual HostID GetLocalHostID() = 0;

		// 현재 이 클라이언트가 알고 있는 피어들의 호스트 아이디 값을 얻어 옵니다.
		virtual void GetPeerHostIDs(CFastArray<HostID>& output) = 0;

		// CUS와 연결이 되어 있는지
		virtual bool HasServerConnection() = 0;

	public:
		/* Presence 관련 API 집합 */

		// Presence 의 잠금 객체를 가져온다.
		virtual CriticalSection& GetPresenceCriticalSection() = 0;

		// 새로운 Entity 를 생성 합니다. 이 Entity 는 해당 CUC를 Owner로 삼습니다.
		virtual HAEntity* CreatePresenceEntity(String typeName) = 0;

		// CreatePresenceEntity로 생성된 HAEntity에 필요 시 AddShareTag를 호출하고 최종적으로 RegistePresenceEntity를 호출합니다.
		virtual bool RegisterPresenceEntity(HAEntity* entity) = 0;

		virtual void DeletePresenceEntity(UniqueNumber entityID) = 0;

		// Entity 를 가져온다.
		virtual HAEntity* GetPresenceEntity(UniqueNumber entityID) = 0;

		// 모든 Entity 들을 가져온다.
		virtual const CFastMap<UniqueNumber, HAEntity*>* GetPresenceEntities() = 0;
		
		virtual int GetPresenceEntityCount() = 0;

		virtual int GetPeerCount() = 0;

		virtual const CFastArray<String>* GetShareTags() const = 0;

		virtual bool ContainsShareTag(const String& tag) const = 0;

		// type, field, value가 같은 PresenceEntity를 찾기
		virtual void FindPresenceEntity(const PNTCHAR* typeName, const PNTCHAR* fieldName, const NetVariant& fieldValue, CFastArray<HAEntity*>& output) = 0;

		// PresenceEntity의 인덱스 등록
		virtual void SetPresenceEntityIndex(const PNTCHAR* typeName, const PNTCHAR* fieldName) = 0;

		// 해당 메서드는 SWIG 인터페이스를 위한 것입니다. 따라서 C++에서 호출하지 마십시오.
		virtual void GetPresenceEntityKeysArray(int *refKeyArray) = 0;
		virtual void SetEventSink(IClusterClientEvent *eventSink) = 0;
		virtual void GetPeerHostIDs(int *peerArray) = 0;

	public:
		static ClusterClient* Create();
	};
}