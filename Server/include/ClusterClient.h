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
		// Ŭ������ ������ ������ �ξ��� ��, Secure Key ��ȯ ������ �Ϻ��ϰ� ��ġ�� P2P �׷��� �ξ����� �ݹ� �˴ϴ�.
		LambdaBaseHolder_Param1<void, const ErrorInfo*> OnJoinServerComplete;

		// Ŭ������ ������ ������ �������� �ݹ� �˴ϴ�.
		LambdaBaseHolder_Param1<void, const ErrorInfo*> OnLeaveServer;

		// Ŭ������ ������ ������ CUC �� ���� �Ͽ��� ��� ���ʷ� �ݹ� �˴ϴ�.
		LambdaBaseHolder_Param1<void, const CFastArray<HostID>&> OnPeerJoin;

		// Ŭ������ ������ ������ CUC �� ���� ���� �Ǿ��� ��� �ݹ� �˴ϴ�. ���� �̷� ��Ȳ�� �߻����� �ʽ��ϴ�.
		LambdaBaseHolder_Param1<void, const ErrorInfo*> OnPeerLeave;

		// Ư�� Ŭ������ Ŭ���̾�Ʈ�� ������ Ȯ�� �Ǿ��� ��� �ݹ� �˴ϴ�.
		LambdaBaseHolder_Param1<void, HostID> OnP2PConnected;

		// Ư�� Ŭ������ Ŭ���̾�Ʈ�� ������ ���� �Ǿ��� ��� �ݹ� �˴ϴ�.
		LambdaBaseHolder_Param1<void, HostID> OnP2PDisconnected;

		// ���� ���� �ʴ� RMI ID �� ��� �ش� �Լ��� �ݹ� �˴ϴ�.
		LambdaBaseHolder_Param1<void, int> OnNoRmiProcessed;

		// RMI ó�� ���� ���� �߻� ��, �� �Լ��� �ݹ� �˴ϴ�.
		LambdaBaseHolder_Param1<void, const Exception&> OnException;

		// ��� �߻� �� ��, �� �Լ��� �ݹ� �˴ϴ�. ���� �̷� ��Ȳ�� �߻����� �ʽ��ϴ�.
		LambdaBaseHolder_Param1<void, const ErrorInfo*> OnWarning;

		// HA Viz���� ���Ǵ� APIGateway ������ ���� ���� �Ǹ� �ݹ� �˴ϴ�.
		LambdaBaseHolder_Param1<void, const ErrorInfo*> OnJoinApiGatewayServerComplete;

		// HA Viz���� ���Ǵ� APIGateway ������ ������ �������� ��� �ݹ� �˴ϴ�.
		LambdaBaseHolder_Param1<void, const ErrorInfo*>	OnLeaveApiGatewayServer;

		// ClusterClientStartParameter.timerCallbackIntervalMs �� 0�� �ƴ϶�� �ش� ms���� �ݹ� �˴ϴ�.
		LambdaBaseHolder_Param1<void, void*> OnTick;

		// PresenceEntity�� ����� �ݹ� �˴ϴ�.
		LambdaBaseHolder_Param2<void, HostID, UniqueNumber> OnCreatePresenceEntity;

		// PresenceEntity�� ���ŵǸ� �ݹ� �˴ϴ�.
		LambdaBaseHolder_Param3<void, HostID, UniqueNumber, const CFastArray<String>&> OnUpdatePresenceEntity;

		// PresenceEntity�� �������� �ݹ� �˴ϴ�.
		LambdaBaseHolder_Param2<void, HostID, UniqueNumber> OnDeletePresenceEntity;

	public:
		/** Cluster Server���� ������ �մϴ�. */
		virtual void Start(const ClusterClientStartParameter& param) = 0;
		virtual void StopAsync() = 0;
		virtual void Stop() = 0;

		// Ŭ������ ������ ȣ��Ʈ ���̵� �����´�.
		// �̴� Ŭ������ ���ݿ� ���� ����ũ�� ���̴�.
		virtual HostID GetLocalHostID() = 0;

		// ���� �� Ŭ���̾�Ʈ�� �˰� �ִ� �Ǿ���� ȣ��Ʈ ���̵� ���� ��� �ɴϴ�.
		virtual void GetPeerHostIDs(CFastArray<HostID>& output) = 0;

		// CUS�� ������ �Ǿ� �ִ���
		virtual bool HasServerConnection() = 0;

	public:
		/* Presence ���� API ���� */

		// Presence �� ��� ��ü�� �����´�.
		virtual CriticalSection& GetPresenceCriticalSection() = 0;

		// ���ο� Entity �� ���� �մϴ�. �� Entity �� �ش� CUC�� Owner�� ����ϴ�.
		virtual HAEntity* CreatePresenceEntity(String typeName) = 0;

		// CreatePresenceEntity�� ������ HAEntity�� �ʿ� �� AddShareTag�� ȣ���ϰ� ���������� RegistePresenceEntity�� ȣ���մϴ�.
		virtual bool RegisterPresenceEntity(HAEntity* entity) = 0;

		virtual void DeletePresenceEntity(UniqueNumber entityID) = 0;

		// Entity �� �����´�.
		virtual HAEntity* GetPresenceEntity(UniqueNumber entityID) = 0;

		// ��� Entity ���� �����´�.
		virtual const CFastMap<UniqueNumber, HAEntity*>* GetPresenceEntities() = 0;
		
		virtual int GetPresenceEntityCount() = 0;

		virtual int GetPeerCount() = 0;

		virtual const CFastArray<String>* GetShareTags() const = 0;

		virtual bool ContainsShareTag(const String& tag) const = 0;

		// type, field, value�� ���� PresenceEntity�� ã��
		virtual void FindPresenceEntity(const PNTCHAR* typeName, const PNTCHAR* fieldName, const NetVariant& fieldValue, CFastArray<HAEntity*>& output) = 0;

		// PresenceEntity�� �ε��� ���
		virtual void SetPresenceEntityIndex(const PNTCHAR* typeName, const PNTCHAR* fieldName) = 0;

		// �ش� �޼���� SWIG �������̽��� ���� ���Դϴ�. ���� C++���� ȣ������ ���ʽÿ�.
		virtual void GetPresenceEntityKeysArray(int *refKeyArray) = 0;
		virtual void SetEventSink(IClusterClientEvent *eventSink) = 0;
		virtual void GetPeerHostIDs(int *peerArray) = 0;

	public:
		static ClusterClient* Create();
	};
}