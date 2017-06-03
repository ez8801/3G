#include "Common.h"

#include "../TeamGGCommon/C2S_common.cpp"
#include "../TeamGGCommon/S2C_common.cpp"
#include "../TeamGGCommon/C2S_stub.h"
#include "../TeamGGCommon/S2C_proxy.h"
#include "../TeamGGCommon/C2S_stub.cpp"
#include "../TeamGGCommon/S2C_proxy.cpp"

#include "User.h"

class C2SStub : public C2S::Stub
{
public:
	DECRMI_C2S_Chat;
};

C2SStub g_C2SStub;
S2C::Proxy g_S2CProxy;
HostID g_groupHostID = HostID_None;
HostID g_lastClientID = HostID_None;
DEFRMI_C2S_Chat(C2SStub)
{
	cout << "[Server] chat message received :";
	cout << " a=" << string(a);
	cout << " b=" << b;
	cout << " c=" << c;
	cout << endl;

	// Echo chatting message which received from server to client.
	g_S2CProxy.ShowChat(remote, RmiContext::ReliableSend, a, b + 1, c + 1);
	return true;
}

int main()
{
	

	// NetServer 클래스 선언하기    
	shared_ptr<CNetServer> srv(CNetServer::Create());

	srv->OnClientJoin = [](CNetClientInfo *clientInfo) {
		printf("Client %d connected.\n", clientInfo->m_HostID);
		g_lastClientID = clientInfo->m_HostID;
	};
	srv->OnClientLeave = [](CNetClientInfo *clientInfo, ErrorInfo *errorInfo, const ByteArray& comment) {
		printf("Client %d disconnected.\n", clientInfo->m_HostID);
	};
	srv->OnError = [](ErrorInfo *errorInfo) {
		printf("OnError : %s\n", StringT2A(errorInfo->ToString()).GetString());
	};
	srv->OnWarning = [](ErrorInfo *errorInfo) {
		printf("OnWarning : %s\n", StringT2A(errorInfo->ToString()).GetString());
	};
	srv->OnInformation = [](ErrorInfo *errorInfo) {
		printf("OnInformation : %s\n", StringT2A(errorInfo->ToString()).GetString());
	};

	srv->OnException = [](const Exception &e) {
		printf("OnInformation : %s\n", e.what());
	};

	// RmiStub, RmiProxy 클래스 NetServer에 Attach하기
	srv->AttachStub(&g_C2SStub);
	srv->AttachProxy(&g_S2CProxy);

	// 서버 시작에 필요한 Parameter 설정하기
	CStartServerParameter p1;
	p1.m_protocolVersion = g_Version;
	p1.m_tcpPorts.Add(g_ServerPort);

	try
	{
		// 서버 시작하기
		// 서버 시작시 문제가 발생할 경우 Exception을 throw 합니다.
		srv->Start(p1);
	}
	catch (Exception &e)
	{
		cout << "Server start failed: " << e.what() << endl;
		return 0;
	}

	
	// 테스트 코드 작성
	puts("Team GG's Base Server \n");
	puts("Ver 0.001\n");
	
	puts("q: Quit.\n");

	string userInput;

	while (1)
	{
		cin >> userInput;
		
		if (userInput == "1")
		{
			HostID list[100];
			int listCount = srv->GetClientHostIDs(list, 100);
			g_groupHostID = srv->CreateP2PGroup(list, listCount, ByteArray());
		}
		else if (userInput == "2")
		{
			g_S2CProxy.SystemChat(g_groupHostID, RmiContext::ReliableSend, _PNT("Hello~~~!"));
		}
		else if (userInput == "3")
		{
			srv->DestroyP2PGroup(g_groupHostID);
		}
		else if (userInput == "4")
		{

			HostID list[100];
			int listCount = srv->GetClientHostIDs(list, 100);
			for (int i = 0; i < listCount; i++)
			{
				g_S2CProxy.sendUserInfo(list[i], RmiContext::UnreliableSend, _PNT("soong"), 10, 10);
			}
		}
		if (userInput == "q")
		{
			break;
		}

		// CPU 점유를 100% 차지하지 않게 하기 위함
		// To prevent 100% occupation rate of CPU
		Sleep(10);
	}

	return 0;
}