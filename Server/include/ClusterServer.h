/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once 

#include "ClusterTypes.h"

namespace Proud
{
	/*
		클러스터 서버는 사용자 정의 로직 탑재가 불가능 함
		따라서 콜백 되는 이벤트도 없으며 단순 시작, 정지만 가능
	*/
	enum ClusterServerType
	{
		ClusterServerType_None,
		ClusterServerType_Master,
		ClusterServerType_Slave
	};

	class ClusterServer
	{
	public:
		virtual ~ClusterServer() {}

	public:
		virtual void Start(const ClusterServerStartParameter& param) = 0;
		virtual void Stop() = 0; 
		static ClusterServer* Create();

		virtual ClusterServerType GetClusterServerType() = 0;
	};
}