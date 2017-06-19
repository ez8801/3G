#include "ServerMain.h"
//changetest
ServerMain::ServerMain()
{
	m_InMain = ServerManager::getInstance();
	m_S2CProxy = m_InMain->getS2CProxy();
}
void ServerMain::Team3GServerMain()
{
	C2SStub g_C2SStub;

	// NetServer 클래스 선언하기    
	shared_ptr<CNetServer> srv(CNetServer::Create());

	srv->OnClientJoin = [](CNetClientInfo *clientInfo) 
	{
		ServerManager * m_SM = ServerManager::getInstance();
		printf("Client %d connected.\n", clientInfo->m_HostID);
		m_SM->setLastClientHostID(clientInfo->m_HostID);
	};
	srv->OnClientLeave = [](CNetClientInfo *clientInfo, ErrorInfo *errorInfo, const ByteArray& comment) 
	{
		printf("Client %d disconnected.\n", clientInfo->m_HostID);
	};
	srv->OnError = [](ErrorInfo *errorInfo) 
	{
		printf("OnError : %s\n", StringT2A(errorInfo->ToString()).GetString());
	};
	srv->OnWarning = [](ErrorInfo *errorInfo) 
	{
		printf("OnWarning : %s\n", StringT2A(errorInfo->ToString()).GetString());
	};
	srv->OnInformation = [](ErrorInfo *errorInfo) 
	{
		printf("OnInformation : %s\n", StringT2A(errorInfo->ToString()).GetString());
	};

	srv->OnException = [](const Exception &e) 
	{
		printf("OnInformation : %s\n", e.what());
	};

	// RmiStub, RmiProxy 클래스 NetServer에 Attach하기
	srv->AttachStub(&g_C2SStub);
	srv->AttachProxy(&m_S2CProxy);

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
		return ;
	}


	// 테스트 코드 작성
	puts("Team GG's Base Server \n");
	puts("Ver 0.001\n");

	puts("q: Quit.\n");

	string userInput;
	HostID whileGroupHostID;
	while (1)
	{
		cin >> userInput;

		if (userInput == "1")
		{
			HostID list[100];
			
			int listCount = srv->GetClientHostIDs(list, 100);
			whileGroupHostID = srv->CreateP2PGroup(list, listCount, ByteArray());
			m_InMain->setGroupHostID(whileGroupHostID);
		}
		else if (userInput == "2")
		{
			whileGroupHostID = m_InMain->getGroupHostID();
			m_S2CProxy.SystemChat(whileGroupHostID, RmiContext::ReliableSend, _PNT("Hello~~~!"));
		}
		else if (userInput == "3")
		{
			whileGroupHostID = m_InMain->getGroupHostID();
			srv->DestroyP2PGroup(whileGroupHostID);
			m_InMain->setGroupHostID(HostID_None);
		}
		else if (userInput == "4")
		{

			HostID list[100];
			int listCount = srv->GetClientHostIDs(list, 100);
			for (int i = 0; i < listCount; i++)
			{
				m_S2CProxy.sendUserInfo(list[i], RmiContext::UnreliableSend, _PNT("soong"), 10, 10);
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

	return ;
}

