/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once 

#include "AddrPort.h"
#include "ClusterParameterBase.h"

namespace Proud
{
	typedef int32_t UniqueNumber;

	/** Cluster Server�� �����ϱ� ���� ����. */
	class ClusterClientStartParameter : public CClusterParameterBase
	{
	public:
		// Precense �� ���Ͽ� ����ȭ�� ���� �� tag ���Դϴ�.
		CFastArray<String> m_shareTags;

		// Visualizer ���ÿ� �ش� ���� true�� ���� �ؾ߸� ���� �۵� �մϴ�.
		bool m_useVisualizer;

		// Visualizer ����Ʈ������ ��Ʈ ��ȣ�Դϴ�.
		uint16_t m_visualizerGatewayPort;

		// Ŭ������ Ŭ���̾�Ʈ ���� ��� �� �� �ִ� ���� ��Ʈ
		uint16_t m_cucCommunicationPort;

		NamedAddrPortInfo m_clusteredNetServerInfo;

		uint32_t m_timerCallbackIntervalMs;
	};

	/** Ŭ������ ���� ���۽� �ʿ��� ���� */
	class ClusterServerStartParameter : public CClusterParameterBase
	{
	public:
		// ������ �ĺ��� ���Դϴ�.
		String m_localIdentifier;

		// listening �� ������ ��Ʈ ��ȣ �Դϴ�.
		uint16_t m_port;

		// No SPOF�� ���� �ٸ� Cluster Server ����
		CFastArray<ClusterInfo> m_clusterServerPeerInfos;
	};
}