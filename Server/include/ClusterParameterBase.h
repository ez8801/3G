/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once

#include <memory>

#include "pnguid.h"
#include "ClusterInfo.h"
#include "ThreadPool.h"
#include "FastArray.h"
#include "PNString.h"

namespace Proud
{
	class CClusterParameterBase
	{
	public:
		CThreadPool* m_externalUserWorkerThreadPool;
		CThreadPool* m_externalNetWorkerThreadPool;
		int m_netWorkerThreadCount;
		int m_threadCount;

		// 클러스터의 키 값입니다. 절대 노출 되어선 안됩니다.
		Guid m_secureKey;

		// 클러스터의 통신 프로토콜 버전입니다.
		Guid m_protocolVersion;

		// 클러스터 서버로의 자동 접속 혹은 클러스터 서버 이중화 기능을 할 서버 리스트 입니다.
		CFastArray<ClusterInfo> m_serverList;

		// 클러스터 서버의 Listen 주소 값 혹은 서버간 통신시의 Bind 될 주소 값입니다.
		// 클라우드 서버에 띄울 경우 외부에서 인식 가능한 서버 주소 혹은 FQDN 을 입력 해야 합니다.
		String m_localNicAddr;

		CClusterParameterBase()
			: m_externalUserWorkerThreadPool(nullptr)
			, m_externalNetWorkerThreadPool(nullptr)
			, m_netWorkerThreadCount(0)
			, m_threadCount(0)
		{}
	};
}