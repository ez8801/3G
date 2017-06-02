/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once

namespace Proud
{
	class CClusterConfig
	{
	public:
		// 클러스터 클라이언트는 전 서버에 걸쳐 유니크한 값을 가지고 있는데
		// 이때 클러스터 클라이언트당 가지고 있는 유니크한 값의 최대 크기
		// 기본 값 5000
		static int32_t UniqueNumberCountPerClusterClient;

		static const int32_t ClusterServerUniqueNumberReserveSize;

		// ClusterClient의 Credential 크기
		static const int32_t ClusterCredentialSize;

		// RESERVED
		static const int64_t ClusterTickIntervalMs;

		// CUS에서 CUC에게 Cluster 호스트 아이디를 발급해주는것이 실패 하였을 때, 재시도 횟수
		static const int32_t AllocClusterHostIDRetryCount;

		// CUS 가 각 CUC 들에게 발급해주는 HostID 의 정책이 recycle 일 때, recycle 되는 시간 값
		static const int64_t HostIDRecycleAllowTimeMs;

		// CUS 가 각 CUC 들에게 발급해주는 HostID 값을 재사용 할 것인지에 대한 값 default false
		static const bool IsHostIDRecycle;

		// 클라이언트의 Credential 이 유효한지 체킹하는 로직의 실행 간격
		static const int64_t VerifyValidCredentialIntervalMs;

		// 서버에 접속만 하고 인증은 하지 않은 클라이언트에 대하여 처리하는 로직의 실행 간격
		static const int64_t KickGhostClientIntervalMs;

		// HAServer가 죽었을 때 HostID를 처리하는 로직의 실행 간격
		static const int64_t CleanUpLeaveHAServerIntervalMs;

		// 서버에 인증하기 전까지의 클라이언트 유효성 시간
		static const int64_t ValidGhostClientTimeMs;

		// 각 클라이언트의 Credential 유효 시간
		static const int64_t ValidCredentialTimeMs;

		// Slave에서 Master로 변경될 경우 각 클라이언트의 Credential 유효 시간
		static const int64_t ChangeMasterToValidCredentialTimeMs;

		// 클러스터 코어에서 리모트 피어 제거 작업을 위한 백그라운드 스레드의 작업 주기
		static const int64_t GarbageProcessorProcessIntervalMs;

		// 유니크 넘버 할당 시, 한번에 생성 될 크기
		static const int32_t AllocUniqueNumberBlockSize;

		// Peer CUS에 연결하는 Timeout 시간
		static const int64_t ConnectPeerClusterServerIntervalMs;

		// HAServer가 연결될 경우 UniqueNumber를 할당할 사이즈.
		static const int32_t HAServerUniqueNumberReserveSize;

	};
}