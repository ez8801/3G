#include "ServerMain.h"
//changetest
//글로벌로 선언된 g_S2CProxy
extern S2C::Proxy g_S2CProxy;
ServerMain::ServerMain()
{
	m_InMain = ServerManager::getInstance();
}
void ServerMain::Team3GServerMain()
{
	C2SStub g_C2SStub;

	// NetServer 클래스 선언하기    
	shared_ptr<CNetServer> srv(CNetServer::Create());

	//클라이언트가 서버에 접속했을때
	srv->OnClientJoin = [](CNetClientInfo *clientInfo) 
	{
		ServerManager * m_SM = ServerManager::getInstance();
		printf("Client %d connected.\n", clientInfo->m_HostID);
		m_SM->setLastClientHostID(clientInfo->m_HostID);
	};
	//클라이언트가 서버에서 떠났을때
	srv->OnClientLeave = [](CNetClientInfo *clientInfo, ErrorInfo *errorInfo, const ByteArray& comment) 
	{
		printf("Client %d disconnected.\n", clientInfo->m_HostID);
	};
	//에러가 발생했을때
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
		return ;
	}


	// 실제 서버 내용 시작
	puts("Team GG's Base Server \n");
	puts("Ver 0.001\n");

	puts("q: Quit.\n");

	string userInput;
	HostID whileGroupHostID;
	//서버 루프
	while (1)
	{
		cin >> userInput;
		//서버에서 인풋받아서 내용 처리하기

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
			g_S2CProxy.SystemChat(whileGroupHostID, RmiContext::ReliableSend, _PNT("Hello~~~!"));
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
				
				g_S2CProxy.sendUserInfo(list[i], RmiContext::UnreliableSend, _PNT("soong"), 10, 10);
			}
		}
		if (userInput == "q")
		{
			break;
		}

		// CPU 점유를 100% 차지하지 않게 하기 위함
		Sleep(10);
	}

	return ;
}

