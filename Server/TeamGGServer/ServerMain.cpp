#include "ServerMain.h"
//changetest
//�۷ι��� ����� g_S2CProxy
extern S2C::Proxy g_S2CProxy;
enum
{
	ENUM_MAIN_SCENE = 1
};
ServerMain::ServerMain()
{
	m_InMain = ServerManager::getInstance();
	cur_scene = ENUM_MAIN_SCENE;
}
void ServerMain::Team3GServerMain()
{
	C2SStub g_C2SStub;

	// NetServer Ŭ���� �����ϱ�    
	

	//Ŭ���̾�Ʈ�� ������ ����������
	m_InMain->srv->OnClientJoin = [](CNetClientInfo *clientInfo)
	{
		ServerManager * m_SM = ServerManager::getInstance();
		printf("Client %d connected.\n", clientInfo->m_HostID);
		m_SM->setLastClientHostID(clientInfo->m_HostID);
	};
	//Ŭ���̾�Ʈ�� �������� ��������
	m_InMain->srv->OnClientLeave = [](CNetClientInfo *clientInfo, ErrorInfo *errorInfo, const ByteArray& comment)
	{
		printf("Client %d disconnected.\n", clientInfo->m_HostID);
	};
	//������ �߻�������
	m_InMain->srv->OnError = [](ErrorInfo *errorInfo)
	{
		printf("OnError : %s\n", StringT2A(errorInfo->ToString()).GetString());
	};

	m_InMain->srv->OnWarning = [](ErrorInfo *errorInfo)
	{
		printf("OnWarning : %s\n", StringT2A(errorInfo->ToString()).GetString());
	};
	m_InMain->srv->OnInformation = [](ErrorInfo *errorInfo)
	{
		printf("OnInformation : %s\n", StringT2A(errorInfo->ToString()).GetString());
	};

	m_InMain->srv->OnException = [](const Exception &e)
	{
		printf("OnInformation : %s\n", e.what());
	};

	// RmiStub, RmiProxy Ŭ���� NetServer�� Attach�ϱ�
	m_InMain->srv->AttachStub(&g_C2SStub);
	m_InMain->srv->AttachProxy(&g_S2CProxy);
	

	// ���� ���ۿ� �ʿ��� Parameter �����ϱ�
	CStartServerParameter p1;
	p1.m_protocolVersion = g_Version;
	p1.m_tcpPorts.Add(g_ServerPort);
	
	try
	{
		// ���� �����ϱ�
		// ���� ���۽� ������ �߻��� ��� Exception�� throw �մϴ�.
		m_InMain->srv->Start(p1);
	}
	catch (Exception &e)
	{
		cout << "Server start failed: " << e.what() << endl;
		return ;
	}


	// ���� ���� ���� ����
	main_scene();

	string userInput;
	HostID whileGroupHostID;
	//���� ����
	while (1)
	{
		cin >> userInput;
		//�������� ��ǲ�޾Ƽ� ���� ó���ϱ�
		////////////ENUM_MAIN_SCENE///////////////

		if (userInput == "1")
		{
			HostID list[100];
			
			int listCount = m_InMain->srv->GetClientHostIDs(list, 100);
			whileGroupHostID = m_InMain->srv->CreateP2PGroup(list, listCount, ByteArray());
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
			m_InMain->srv->DestroyP2PGroup(whileGroupHostID);
			m_InMain->setGroupHostID(HostID_None);
		}
		else if (userInput == "4")
		{

			HostID list[100];
			int listCount = m_InMain->srv->GetClientHostIDs(list, 100);
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

void ServerMain::main_scene()
{
	puts("Team GG's Base Server \n");
	puts("Ver 0.001\n");

	puts("q: Quit.\n");
}