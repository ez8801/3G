/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once

namespace Proud
{
	class ErrorInfo;

	// ClusterClient에 람다함수로 콜백을 설정할 수 있지만
	// SWIG 3.0.10까지는 람다에 대한 지원이 없다.
	// 따라서 기존의 방식대로 가상함수 상속을 통한 콜백클래스를 구현하고
	// 그것을 SWIG로 랩핑하여 C#에서 람다를 사용할 수 있게 하였다.
	class IClusterClientEvent
	{
	public:
		virtual void OnJoinServerComplete(const ErrorInfo *errorInfo) = 0;
		virtual void OnLeaveServer(const ErrorInfo *errorInfo) = 0;
		virtual void OnPeerJoin(const CFastArray<HostID>& peers) = 0;
		virtual void OnPeerLeave(const ErrorInfo *errorInfo) = 0;
		virtual void OnP2PConnected(HostID peer) = 0;
		virtual void OnP2PDisconnected(HostID peer) = 0;
		virtual void OnNoRmiProcessed(int rmiID) = 0;
		virtual void OnException(const Exception &ex) = 0;
		virtual void OnWarning(const ErrorInfo *errorInfo) = 0;
		virtual void OnJoinApiGatewayServerComplete(const ErrorInfo *errorInfo) = 0;
		virtual void OnLeaveApiGatewayServer(const ErrorInfo *errorInfo) = 0;
		virtual void OnTick(void* context) = 0;
		virtual void OnCreatePresenceEntity(HostID reqCucHostID, int entityID) = 0;
		virtual void OnDeletePresenceEntity(HostID reqCucHostID, int entityID) = 0;
		virtual void OnUpdatePresenceEntity(HostID reqCucHostID, int entityID, const CFastArray<String>& keyArray) = 0;
	};
}