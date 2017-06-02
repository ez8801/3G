/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once 

#include "AddrPort.h"
#include "ClusterParameterBase.h"

namespace Proud
{
	typedef int32_t UniqueNumber;

	/** Cluster Server에 접속하기 위한 정보. */
	class ClusterClientStartParameter : public CClusterParameterBase
	{
	public:
		// Precense 를 통하여 동기화를 진행 할 tag 값입니다.
		CFastArray<String> m_shareTags;

		// Visualizer 사용시에 해당 값을 true로 설정 해야만 정상 작동 합니다.
		bool m_useVisualizer;

		// Visualizer 게이트웨이의 포트 번호입니다.
		uint16_t m_visualizerGatewayPort;

		// 클러스터 클라이언트 간의 통신 할 수 있는 지정 포트
		uint16_t m_cucCommunicationPort;

		NamedAddrPortInfo m_clusteredNetServerInfo;

		uint32_t m_timerCallbackIntervalMs;
	};

	/** 클러스터 서버 시작시 필요한 정보 */
	class ClusterServerStartParameter : public CClusterParameterBase
	{
	public:
		// 서버의 식별자 값입니다.
		String m_localIdentifier;

		// listening 될 서버의 포트 번호 입니다.
		uint16_t m_port;

		// No SPOF를 위한 다른 Cluster Server 정보
		CFastArray<ClusterInfo> m_clusterServerPeerInfos;
	};
}