/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once

namespace Proud
{
	class CClusterConfig
	{
	public:
		// Ŭ������ Ŭ���̾�Ʈ�� �� ������ ���� ����ũ�� ���� ������ �ִµ�
		// �̶� Ŭ������ Ŭ���̾�Ʈ�� ������ �ִ� ����ũ�� ���� �ִ� ũ��
		// �⺻ �� 5000
		static int32_t UniqueNumberCountPerClusterClient;

		static const int32_t ClusterServerUniqueNumberReserveSize;

		// ClusterClient�� Credential ũ��
		static const int32_t ClusterCredentialSize;

		// RESERVED
		static const int64_t ClusterTickIntervalMs;

		// CUS���� CUC���� Cluster ȣ��Ʈ ���̵� �߱����ִ°��� ���� �Ͽ��� ��, ��õ� Ƚ��
		static const int32_t AllocClusterHostIDRetryCount;

		// CUS �� �� CUC �鿡�� �߱����ִ� HostID �� ��å�� recycle �� ��, recycle �Ǵ� �ð� ��
		static const int64_t HostIDRecycleAllowTimeMs;

		// CUS �� �� CUC �鿡�� �߱����ִ� HostID ���� ���� �� �������� ���� �� default false
		static const bool IsHostIDRecycle;

		// Ŭ���̾�Ʈ�� Credential �� ��ȿ���� üŷ�ϴ� ������ ���� ����
		static const int64_t VerifyValidCredentialIntervalMs;

		// ������ ���Ӹ� �ϰ� ������ ���� ���� Ŭ���̾�Ʈ�� ���Ͽ� ó���ϴ� ������ ���� ����
		static const int64_t KickGhostClientIntervalMs;

		// HAServer�� �׾��� �� HostID�� ó���ϴ� ������ ���� ����
		static const int64_t CleanUpLeaveHAServerIntervalMs;

		// ������ �����ϱ� �������� Ŭ���̾�Ʈ ��ȿ�� �ð�
		static const int64_t ValidGhostClientTimeMs;

		// �� Ŭ���̾�Ʈ�� Credential ��ȿ �ð�
		static const int64_t ValidCredentialTimeMs;

		// Slave���� Master�� ����� ��� �� Ŭ���̾�Ʈ�� Credential ��ȿ �ð�
		static const int64_t ChangeMasterToValidCredentialTimeMs;

		// Ŭ������ �ھ�� ����Ʈ �Ǿ� ���� �۾��� ���� ��׶��� �������� �۾� �ֱ�
		static const int64_t GarbageProcessorProcessIntervalMs;

		// ����ũ �ѹ� �Ҵ� ��, �ѹ��� ���� �� ũ��
		static const int32_t AllocUniqueNumberBlockSize;

		// Peer CUS�� �����ϴ� Timeout �ð�
		static const int64_t ConnectPeerClusterServerIntervalMs;

		// HAServer�� ����� ��� UniqueNumber�� �Ҵ��� ������.
		static const int32_t HAServerUniqueNumberReserveSize;

	};
}