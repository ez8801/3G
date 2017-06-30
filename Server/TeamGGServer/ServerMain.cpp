#include "ServerMain.h"
//changetest
//�۷ι��� ����� g_S2CProxy
extern S2C::Proxy g_S2CProxy;
ServerMain::ServerMain()
{
	m_InMain = ServerManager::getInstance();
}
void ServerMain::Team3GServerMain()
{
	C2SStub g_C2SStub;

	// NetServer Ŭ���� �����ϱ�    
	shared_ptr<CNetServer> srv(CNetServer::Create());

	//Ŭ���̾�Ʈ�� ������ ����������
	srv->OnClientJoin = [](CNetClientInfo *clientInfo) 
	{
		ServerManager * m_SM = ServerManager::getInstance();
		printf("Client %d connected.\n", clientInfo->m_HostID);
		m_SM->setLastClientHostID(clientInfo->m_HostID);
	};
	//Ŭ���̾�Ʈ�� �������� ��������
	srv->OnClientLeave = [](CNetClientInfo *clientInfo, ErrorInfo *errorInfo, const ByteArray& comment) 
	{
		printf("Client %d disconnected.\n", clientInfo->m_HostID);
	};
	//������ �߻�������
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

	// RmiStub, RmiProxy Ŭ���� NetServer�� Attach�ϱ�
	srv->AttachStub(&g_C2SStub);
	srv->AttachProxy(&g_S2CProxy);
	

	// ���� ���ۿ� �ʿ��� Parameter �����ϱ�
	CStartServerParameter p1;
	p1.m_protocolVersion = g_Version;
	p1.m_tcpPorts.Add(g_ServerPort);
	
	try
	{
		// ���� �����ϱ�
		// ���� ���۽� ������ �߻��� ��� Exception�� throw �մϴ�.
		srv->Start(p1);
	}
	catch (Exception &e)
	{
		cout << "Server start failed: " << e.what() << endl;
		return ;
	}


	// ���� ���� ���� ����
	puts("Team GG's Base Server \n");
	puts("Ver 0.001\n");

	puts("q: Quit.\n");

	string userInput;
	HostID whileGroupHostID;
	//���� ����
	while (1)
	{
		cin >> userInput;
		//�������� ��ǲ�޾Ƽ� ���� ó���ϱ�

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

		// CPU ������ 100% �������� �ʰ� �ϱ� ����
		Sleep(10);
	}

	return ;
}

