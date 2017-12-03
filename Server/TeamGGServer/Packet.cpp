#include "Packet.h"
#include "../TeamGGCommon/C2S_stub.cpp"
#include "../TeamGGCommon/S2C_proxy.cpp"
#include "../TeamGGCommon/C2S_common.cpp"
#include "../TeamGGCommon/S2C_common.cpp"
//글로벌로 선언된 g_S2CProxy변수
String ConnectString = L"Driver={MySQL ODBC 5.1 Driver};Server=127.0.0.1;UID=soongsae;PWD=soongsae9016!;DB=team3g-db;Port=3306";
S2C::Proxy g_S2CProxy;
DEFRMI_C2S_Chat(C2SStub)
{
	cout << "[Server] chat message received :";
	cout << " a=" << string(a);
	cout << " b=" << b;
	cout << " c=" << c;
	cout << endl;

	// Echo chatting message which received from server to client.
	//ServerManager *manager;
	//manager = ServerManager::getInstance();
	g_S2CProxy.ShowChat(remote, RmiContext::ReliableSend, a, b + 1, c + 1);
	return true;
}
DEFRMI_C2S_RequestMakeRaidRoom(C2SStub)
{
	cout << HostId << endl;
	ServerManager *manager;
	manager = ServerManager::getInstance();

	HostIDArray arr;
	arr.Add(HostId);
	HostID createdGroupId;

	createdGroupId = manager->srv->CreateP2PGroup(arr.GetData(), arr.Count, ByteArray());
	cout << createdGroupId << " is Created " << endl;
	//DB에 현재 만든 방에 대한 정보를 입력한다.
	CAdoConnection conn;
	conn.Open(ConnectString, DbmsType::MySql);
	conn.BeginTrans();
	conn.Execute(String::NewFormat(L"insert into raidroominfo (CharacterIdx, RoomNumber, CurCrew,isValid) VALUES('%d', '%d', %d, %d)", HostId, createdGroupId, 1, 1));
	conn.CommitTrans();
	return true;
}
DEFRMI_C2S_RequestMakePVPRoom(C2SStub)
{
	ServerManager *manager;
	manager = ServerManager::getInstance();

	HostIDArray arr;
	arr.Add(HostId);
	HostID createdGroupId;
	
	
	CAdoConnection conn;
	CAdoRecordset CheckCharacterIdx;
	int CharacterIdx = 0;
	int roomIdx = 0;

	try
	{
		conn.Open(ConnectString, DbmsType::MySql);
		if (!CheckCharacterIdx.IsOpened())
		{
			CheckCharacterIdx.Open(conn, OpenForRead, String::NewFormat(L"select * from usercharacter where CName = '%s' ", CName));
			if (CheckCharacterIdx.IsEOF() == true)
			{
				// 잘못된 캐릭터명
			}
			else
			{
				createdGroupId = manager->srv->CreateP2PGroup(arr.GetData(), arr.Count, ByteArray());
				CharacterIdx = CheckCharacterIdx.FieldValues[L"idx"];
				CheckCharacterIdx.Close();
				conn.BeginTrans();
				conn.Execute(String::NewFormat(L"insert into pvproominfo (roomName, hostIdx, hostName,p2pGroupId,isVaild) VALUES('%s', '%d', '%s','%d', '%d')", RoomName, HostId, CName, createdGroupId, 1));
				conn.CommitTrans();
				CheckCharacterIdx.Open(conn, OpenForRead, String::NewFormat(L"select * from pvproominfo where hostIdx = '%d' and isVaild = 1 ", HostId));
				if (CheckCharacterIdx.IsEOF() == true)
				{
					
				}
				else
				{
					roomIdx = CheckCharacterIdx.FieldValues[L"idx"];
					g_S2CProxy.sendMakePVPRoomResult(remote, RmiContext::ReliableSend, createdGroupId, RoomName, roomIdx, 1);
					
				}
				
			}
		}
	}
	catch (exception e)
	{

	}

	
	return true;
}
DEFRMI_C2S_RequestGetPVPRoomInfo(C2SStub)
{
	CAdoConnection conn;
	CAdoRecordset rec;
	pvprooms temp;
	Proud::CFastArray<pvprooms> arrRoominfo;
	conn.Open(ConnectString, DbmsType::MySql);
	rec.Open(conn, OpenForRead, String::NewFormat(L"select * from pvproominfo where isVaild = 1"));
	int i = 0;
	while (rec.IsEOF() != true)
	{
		temp.roomId = rec.FieldValues[L"Idx"];
		temp.hostId = rec.FieldValues[L"hostIdx"];
		temp.groupId = rec.FieldValues[L"p2pGroupId"];
		temp.hostname = rec.FieldValues[L"hostName"];
		temp.pvproomname = rec.FieldValues[L"roomName"];
		arrRoominfo.Add(temp);
		rec.MoveNext();
		i++;
	}
	g_S2CProxy.sendPVPRoomInfo(remote, RmiContext::ReliableSend, arrRoominfo);
	return true;
}
DEFRMI_C2S_RequestJoinPVPRoom(C2SStub)
{
	//cout << "requestJoinRaidRoom" << endl;
	ServerManager *manager;
	manager = ServerManager::getInstance();

	manager->srv->JoinP2PGroup(HostId, (HostID)GroupId, ByteArray()); // 방장의 그룹에 들어간다
	// DB에 isVaild를 0으로 바꿔준다
	CAdoConnection conn;
	CAdoRecordset rec;
	pvprooms temp;
	Proud::CFastArray<pvprooms> arrRoominfo;
	conn.Open(ConnectString, DbmsType::MySql);
	rec.Open(conn, OpenForRead, String::NewFormat(L"select * from pvproominfo where idx = '%d'",RoomId));
	int i = 0;
	while (rec.IsEOF() != true)
	{
		temp.roomId = rec.FieldValues[L"Idx"];
		temp.hostId = rec.FieldValues[L"hostIdx"];
		temp.groupId = rec.FieldValues[L"p2pGroupId"];
		temp.hostname = rec.FieldValues[L"hostName"];
		temp.pvproomname = rec.FieldValues[L"roomName"];
		rec.MoveNext();
	}
	g_S2CProxy.sendPVPRoomJoinResult(remote, RmiContext::ReliableSend, temp.groupId, temp.pvproomname, temp.roomId ,temp.hostId, 1);
	return true;
}
DEFRMI_C2S_RequestLeavePVPRoom(C2SStub)
{
	ServerManager *manager;
	manager = ServerManager::getInstance();

	manager->srv->LeaveP2PGroup(HostId, (HostID)GroupId); // 방장의 그룹에 들어간다
	// DB에 isVaild를 1로 바꿔준다.
	CAdoConnection conn;
	int CharacterIdx = 0;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);
		//conn.Execute(String::NewFormat(L"update userinventory set itemCount = itemCount + 1 where itemIdx = '%d' and CharacterIdx = '%d' ", itemId, CharacterIdx));
		conn.BeginTrans();
		
		conn.Execute(String::NewFormat(L"delete from pvproominfo where hostIdx = '%d' and isVaild = 1", HostId));
		conn.Execute(String::NewFormat(L"update pvproominfo set isVaild = '%d' where isVaild = 1 ", 0));
		conn.CommitTrans();
		
	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}

	return true;
}

DEFRMI_C2S_RequestGetRaidRoomInfo(C2SStub)
{
	cout << "requestGetRaidRoomInfo" << endl;
	CAdoConnection conn;
	CAdoRecordset rec;
	raidrooms temp;
	Proud::CFastArray<raidrooms> arrRoominfo;
	conn.Open(ConnectString, DbmsType::MySql);
	rec.Open(conn, OpenForRead, String::NewFormat(L"select * from raidroominfo where isValid = 1"));
	int i = 0;
	while (rec.IsEOF() != true)
	{
		temp.hostId = rec.FieldValues[L"CharacterIdx"];
		temp.groupId = rec.FieldValues[L"RoomNumber"];
		temp.curCrew = rec.FieldValues[L"CurCrew"];
		arrRoominfo.Add(temp);
		rec.MoveNext();
		i++;
	}
	g_S2CProxy.sendRaidRoomInfo(remote, RmiContext::ReliableSend, arrRoominfo);
	return true;
}
DEFRMI_C2S_RequestJoinRaidRoom(C2SStub)
{
	cout << "requestJoinRaidRoom" << endl;
	ServerManager *manager;
	manager = ServerManager::getInstance();
	
	manager->srv->JoinP2PGroup(HostId, (HostID)GroupId, ByteArray());
	return true;
}
DEFRMI_C2S_Login(C2SStub)
{
	cout << "[Login Request] id : << " << string(id) << " password : " << string(password) << endl;
	//items test;
	//Proud::CFastArray<items> cfasttest;
	/*
	for (int i = 0; i < 10; i++)
	{
		test.itemIdx = i;
		test.count = i;
		cfasttest.Add(test);
	}
	*/
	//ServerManager *manager;
	//manager = ServerManager::getInstance();
	//manager->getS2CProxy()
	CAdoConnection conn;
	CAdoRecordset rec;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);

		//conn.Open(L"Driver={MySQL ODBC 5.1 Driver};server = 127.0.0.1; port = 3306; Database = friend;User ID = soongsae; Password = soongsae9016!; ");

		wprintf(L"DB Connect Succeed!!\n");
		if (!rec.IsOpened())
		{
			// 리턴받은  recordset 객체를 먼저 열어야 접근가능
			// Has to open recordset object to access it
			rec.Open(conn, OpenForRead, String::NewFormat(L"select * from UserAccount where id = '%s' and password= '%s'", id, password));
			if (rec.IsEOF() == true)
			{
				//아이디 비번이 없다.
				wprintf(L"don't have record set \n");
				
			}
			else
			{
				//로그인 성공 데이터를 불러온다.
				wprintf(L"login success\n");
			}
		}


	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	
	//g_S2CProxy.sendInventoryData(remote, RmiContext::ReliableSend, cfasttest);
	return true;
}
DEFRMI_C2S_RequestMakeAccount(C2SStub)
{
	int AccountIdx = 0;
	int CharacterIdx = 0;
	//아이디 중복 체크
	CAdoConnection conn;
	CAdoRecordset rec;
	CAdoRecordset id_rec;
	CAdoRecordset cname_rec;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);

		if (!rec.IsOpened())
		{
			// 리턴받은  recordset 객체를 먼저 열어야 접근가능
			// Has to open recordset object to access it
			id_rec.Open(conn, OpenForRead, String::NewFormat(L"select * from UserAccount where id = '%s'", id));
			cname_rec.Open(conn, OpenForRead, String::NewFormat(L"select * from usercharacter where CName = '%d' ", CName));
			if (id_rec.IsEOF() == true && cname_rec.IsEOF() == true)
			{
				//아이디 비번이 없다.
				//신규 계정 생성하고 유저에게 성공 패킷 보내줌
				/////////////신규 계정 생성///////////////
				conn.BeginTrans();
				conn.Execute(String::NewFormat(L"insert into useraccount (id, password) VALUES('%s', '%s')", id, password));
				conn.CommitTrans();
				//////////////////////////////////////////
				/////////////새로 생성한 계정의 accountIdx를 가져온다///////////////////
				rec.Open(conn, OpenForRead, String::NewFormat(L"select * from useraccount where id = '%s' and password= '%s'", id, password));
				AccountIdx = rec.FieldValues[L"idx"];
				////////////////////////////////////////////////////////////////////////
				rec.Close();
				rec.Open(conn, OpenForRead, String::NewFormat(L"select * from usercharacter where CName = '%d' ", CName));
				//////////////신규 캐릭터 생성//////////
				conn.BeginTrans();
				conn.Execute(String::NewFormat(L"insert into usercharacter (AccountIdx, CName) VALUES('%d', '%s')", AccountIdx, CName));
				conn.CommitTrans();
				/////////////////////////////////////////
				rec.Close();
				rec.Open(conn, OpenForRead, String::NewFormat(L"select * from usercharacter where AccountIdx = '%d' ", AccountIdx));

				/////////////인벤토리 생성//////////////
				////////////////////////////////////////
				CharacterIdx = rec.FieldValues[L"idx"];
				conn.BeginTrans();
				conn.Execute(String::NewFormat(L"insert into userinventory (CharacterIdx, ItemIdx, ItemCount) VALUES('%d', '%d', '%d')", CharacterIdx, 1,1));
				////////////스킬 생성///////////////////
				////////////////////////////////////////
				conn.Execute(String::NewFormat(L"insert into userskill (CharacterIdx, skillIdx,skillType) VALUES('%d', '%d', '%d')", CharacterIdx, 1,1));
				////////////장비 장착///////////////////
				////////////////////////////////////////
				conn.Execute(String::NewFormat(L"insert into userequipment (CharacterIdx) VALUES('%d')", CharacterIdx));
				conn.CommitTrans();
				////////////////////////////////////////
				///캐릭 생성 성공
				g_S2CProxy.sendMakeAccountResult(remote, RmiContext::ReliableSend, 1);
			}
			else if(id_rec.IsEOF() == true && cname_rec.IsEOF() == false)
			{
				//캐릭명 중복
				g_S2CProxy.sendMakeAccountResult(remote, RmiContext::ReliableSend, 102);
				wprintf(L"Character Name is Duplicate \n");
			}
			else if (id_rec.IsEOF() == false)
			{
				//현재 중복되는 아이디가 있다.
				//중복된다는 패킷 보내준다.
				////아이디 중복 return result = 101;
				g_S2CProxy.sendMakeAccountResult(remote, RmiContext::ReliableSend, 101);
				wprintf(L"Character Name is Duplicate \n");
			}
		}
	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	return true;
}

DEFRMI_C2S_RequestLoginAccount(C2SStub)
{
	CAdoConnection conn;
	CAdoRecordset rec;
	CAdoRecordset cname;
	cout << "[Login Request] id : << " << string(id) << " password : " << string(password) << endl;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);

		//conn.Open(L"Driver={MySQL ODBC 5.1 Driver};server = 127.0.0.1; port = 3306; Database = friend;User ID = soongsae; Password = soongsae9016!; ");

		wprintf(L"DB Connect Succeed!!\n");
		if (!rec.IsOpened())
		{
			// 리턴받은  recordset 객체를 먼저 열어야 접근가능
			// Has to open recordset object to access it
			rec.Open(conn, OpenForRead, String::NewFormat(L"select * from UserAccount where id = '%s' and password= '%s'", id, password));
			if (rec.IsEOF() == true)
			{
				//아이디 비번이 없다.
				//101
				wprintf(L"don't have record set \n");
				string none = "";

				g_S2CProxy.sendLoginResult(remote, RmiContext::ReliableSend, 101, none, 0);
			}
			else
			{
				//로그인 성공 데이터를 불러온다.
				wprintf(L"login success\n");
				int idx;
				String CName; 
				int money;
				idx = rec.FieldValues[L"idx"];
				cname.Open(conn, OpenForRead, String::NewFormat(L"select * from usercharacter where accountIdx = '%d'", idx));
				if (rec.IsEOF() == true)
				{
					// account idx에 매칭되는 레코드가 없다.
				}
				else
				{
					CName = ((String)cname.FieldValues[L"CName"]).GetString();
					money = cname.FieldValues[L"Money"];
					g_S2CProxy.sendLoginResult(remote, RmiContext::ReliableSend, 1, CName.c_str(), money);
				}
				
			}
		}


	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	return true;
}


DEFRMI_C2S_RequestInventoryData(C2SStub)
{
	CAdoConnection conn;
	CAdoRecordset getInventoryDB;
	CAdoRecordset CheckCharacterIdx;
	items singleItem;
	Proud::CFastArray<items> inventoryInfo;
	int CharacterIdx = 0;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);
		if (!CheckCharacterIdx.IsOpened())
		{
			CheckCharacterIdx.Open(conn, OpenForRead, String::NewFormat(L"select * from usercharacter where CName = '%s' ", CName));
			if (CheckCharacterIdx.IsEOF() == true)
			{
				wprintf(L"don't have record set \n");
				//해당 캐릭터 존재 X
				//에러코드 101
			}
			else
			{
				CharacterIdx = CheckCharacterIdx.FieldValues[L"idx"];
				getInventoryDB.Open(conn, OpenForRead, String::NewFormat(L"select * from userinventory where CharacterIdx = '%d' ", CharacterIdx));
				int i = 0;
				while (getInventoryDB.IsEOF() != true)
				{
					singleItem.inId = getInventoryDB.FieldValues[L"inId"];
					singleItem.itemIdx = getInventoryDB.FieldValues[L"ItemIdx"];
					singleItem.count = getInventoryDB.FieldValues[L"ItemCount"];
					inventoryInfo.Add(singleItem);
					getInventoryDB.MoveNext();
					i++;
				}
				g_S2CProxy.sendInventoryData(remote, RmiContext::ReliableSend, inventoryInfo);
				wprintf(L"sendInventoryData success\n");
			}
		}
	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	return true;
}

DEFRMI_C2S_RequestSkillData(C2SStub)
{
	CAdoConnection conn;
	CAdoRecordset getInventoryDB;
	CAdoRecordset CheckCharacterIdx;
	passiveskillinfo singleskill;
	Proud::CFastArray<passiveskillinfo> skillInfo;
	int CharacterIdx = 0;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);
		if (!CheckCharacterIdx.IsOpened())
		{
			CheckCharacterIdx.Open(conn, OpenForRead, String::NewFormat(L"select * from usercharacter where CName = '%s' ", CName));
			if (CheckCharacterIdx.IsEOF() == true)
			{
				wprintf(L"don't have record set \n");
				//해당 캐릭터 존재 X
				//에러코드 101
			}
			else
			{
				CharacterIdx = CheckCharacterIdx.FieldValues[L"idx"];
				getInventoryDB.Open(conn, OpenForRead, String::NewFormat(L"select * from userpassiveskill where CharacterIdx = '%d' ", CharacterIdx));
				int i = 0;
				while (getInventoryDB.IsEOF() != true)
				{
					singleskill.passiveSlot1 = getInventoryDB.FieldValues[L"PassiveSlot1"];
					singleskill.passiveSlot2 = getInventoryDB.FieldValues[L"PassiveSlot2"];
					singleskill.passiveSlot3 = getInventoryDB.FieldValues[L"PassiveSlot3"];
					singleskill.passiveSlot4 = getInventoryDB.FieldValues[L"PassiveSlot4"];
					skillInfo.Add(singleskill);
					getInventoryDB.MoveNext();
					i++;
				}
				g_S2CProxy.sendSkillData(remote, RmiContext::ReliableSend, skillInfo);
				wprintf(L"sendInventoryData success\n");
			}
		}
	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	return true;
}
DEFRMI_C2S_RequestEquipData(C2SStub)
{
	CAdoConnection conn;
	CAdoRecordset getEquipDB;
	CAdoRecordset CheckCharacterIdx;
	equipinfo singleequip;
	Proud::CFastArray<equipinfo> equipInfo;
	int CharacterIdx = 0;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);
		if (!CheckCharacterIdx.IsOpened())
		{
			CheckCharacterIdx.Open(conn, OpenForRead, String::NewFormat(L"select * from usercharacter where CName = '%s' ", CName));
			if (CheckCharacterIdx.IsEOF() == true)
			{
				wprintf(L"don't have record set \n");
				//해당 캐릭터 존재 X
				//에러코드 101
			}
			else
			{
				CharacterIdx = CheckCharacterIdx.FieldValues[L"idx"];
				getEquipDB.Open(conn, OpenForRead, String::NewFormat(L"select * from userequipment where CharacterIdx = '%d' ", CharacterIdx));
				int i = 0;
				while (getEquipDB.IsEOF() != true)
				{
					singleequip.equipslot1 = getEquipDB.FieldValues[L"equipSlot1"];
					singleequip.equipslot2 = getEquipDB.FieldValues[L"equipSlot2"];
					singleequip.equipslot3 = getEquipDB.FieldValues[L"equipSlot3"];
					singleequip.equipslot4 = getEquipDB.FieldValues[L"equipSlot4"];
					singleequip.equipslot5 = getEquipDB.FieldValues[L"equipSlot5"];
					singleequip.equipslot6 = getEquipDB.FieldValues[L"equipSlot6"];
					/*singleequip.ActiveSkill_1_idx = getEquipDB.FieldValues[L"ActiveSkill_1_idx"];
					singleequip.ActiveSkill_2_idx = getEquipDB.FieldValues[L"ActiveSkill_2_idx"];
					singleequip.ActiveSkill_3_idx = getEquipDB.FieldValues[L"ActiveSkill_3_idx"];
					singleequip.ActiveSkill_4_idx = getEquipDB.FieldValues[L"ActiveSkill_4_idx"];
					singleequip.PassiveSkill_1_idx = getEquipDB.FieldValues[L"PassiveSkill_1_idx"];
					singleequip.PassiveSkill_2_idx = getEquipDB.FieldValues[L"PassiveSkill_2_idx"];
					singleequip.PassiveSkill_3_idx = getEquipDB.FieldValues[L"PassiveSkill_3_idx"];
					singleequip.PassiveSkill_4_idx = getEquipDB.FieldValues[L"PassiveSkill_4_idx"];*/
					
					equipInfo.Add(singleequip);
					getEquipDB.MoveNext();
					i++;
				}
				g_S2CProxy.sendEquipmentData(remote, RmiContext::ReliableSend, equipInfo);
				wprintf(L"sendInventoryData success\n");
			}
		}
	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	return true;
}
DEFRMI_C2S_RequestChangeEquipWeapon(C2SStub)
{
	CAdoConnection conn;
	CAdoRecordset CheckCharacterIdx;
	CAdoRecordset getInventoryDB; //인벤토리에 해당 아이템이 있는지 조회용
	CAdoRecordset updateEquipDB; //해당 아이템이 weapon이 맞는지 조회용
	equipinfo singleequip;
	int CharacterIdx = 0;
	Proud::CFastArray<equipinfo> equipInfo;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);
		if (!CheckCharacterIdx.IsOpened())
		{
			CheckCharacterIdx.Open(conn, OpenForRead, String::NewFormat(L"select * from usercharacter where CName = '%s' ", CName));
			if (CheckCharacterIdx.IsEOF() == true)
			{
				g_S2CProxy.sendChangeEquipWeaponResult(remote, RmiContext::ReliableSend, 101, equipInfo); // 잘못된 캐릭터명
			}
			else
			{
				CharacterIdx = CheckCharacterIdx.FieldValues[L"idx"];
				getInventoryDB.Open(conn, OpenForRead, String::NewFormat(L"select * from userinventory where CharacterIdx = '%d' and itemIdx = '%d' ", CharacterIdx , weaponIdx));
				if (getInventoryDB.IsEOF() == true)
				{
					g_S2CProxy.sendChangeEquipWeaponResult(remote, RmiContext::ReliableSend, 102, equipInfo); // 해당 아이템 인벤토리에 존재하지 않음
				}
				else
				{
					conn.Execute(String::NewFormat(L"update userequipment set weaponidx = '%d' where CharacterIdx = '%d' ", weaponIdx, CharacterIdx));
					updateEquipDB.Open(conn, OpenForRead, String::NewFormat(L"select * from userequipment where CharacterIdx = '%d' ",CharacterIdx));
					if (updateEquipDB.IsEOF() == true)
					{
						//update fail;
					}
					else
					{
						while (updateEquipDB.IsEOF() != true)
						{
							singleequip.equipslot1 = updateEquipDB.FieldValues[L"equipSlot1"];
							singleequip.equipslot2 = updateEquipDB.FieldValues[L"equipSlot2"];
							singleequip.equipslot3 = updateEquipDB.FieldValues[L"equipSlot3"];
							singleequip.equipslot4 = updateEquipDB.FieldValues[L"equipSlot4"];
							singleequip.equipslot5 = updateEquipDB.FieldValues[L"equipSlot5"];
							singleequip.equipslot6 = updateEquipDB.FieldValues[L"equipSlot6"];
							/*singleequip.ActiveSkill_1_idx = updateEquipDB.FieldValues[L"ActiveSkill_1_idx"];
							singleequip.ActiveSkill_2_idx = updateEquipDB.FieldValues[L"ActiveSkill_2_idx"];
							singleequip.ActiveSkill_3_idx = updateEquipDB.FieldValues[L"ActiveSkill_3_idx"];
							singleequip.ActiveSkill_4_idx = updateEquipDB.FieldValues[L"ActiveSkill_4_idx"];
							singleequip.PassiveSkill_1_idx = updateEquipDB.FieldValues[L"PassiveSkill_1_idx"];
							singleequip.PassiveSkill_2_idx = updateEquipDB.FieldValues[L"PassiveSkill_2_idx"];
							singleequip.PassiveSkill_3_idx = updateEquipDB.FieldValues[L"PassiveSkill_3_idx"];
							singleequip.PassiveSkill_4_idx = updateEquipDB.FieldValues[L"PassiveSkill_4_idx"];*/

							equipInfo.Add(singleequip);
							updateEquipDB.MoveNext();
							
						}
						g_S2CProxy.sendChangeEquipWeaponResult(remote, RmiContext::ReliableSend, 1, equipInfo); // 해당 아이템 인벤토리에 존재하지 않음
					}
				}
			}
		}
	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	return true;
}

DEFRMI_C2S_RequestBattleInfo(C2SStub)
{
	CAdoConnection conn;
	CAdoRecordset CheckCharacterIdx;
	CAdoRecordset BattleInfoDB;
	int CharacterIdx = 0;
	battleinfo b_info;
	Proud::CFastArray<battleinfo> sendBInfo;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);
		if (!CheckCharacterIdx.IsOpened())
		{
			CheckCharacterIdx.Open(conn, OpenForRead, String::NewFormat(L"select * from usercharacter where CName = '%s' ", CName));
			if (CheckCharacterIdx.IsEOF() == true)
			{
				// 잘못된 캐릭터명
			}
			else
			{
				CharacterIdx = CheckCharacterIdx.FieldValues[L"idx"];
				BattleInfoDB.Open(conn, OpenForRead, String::NewFormat(L"select * from userbattleprogress where CharacterIdx = '%d' ", CharacterIdx));
				if (BattleInfoDB.IsEOF() == true)
				{
					//update fail;
				}
				else
				{
					while (BattleInfoDB.IsEOF() != true)
					{
						b_info.curA = BattleInfoDB.FieldValues[L"AreaACur"];
						b_info.totalA = BattleInfoDB.FieldValues[L"AreaATotal"];
						b_info.curB = BattleInfoDB.FieldValues[L"AreaBCur"];
						b_info.totalB = BattleInfoDB.FieldValues[L"AreaBTotal"];
						sendBInfo.Add(b_info);
						BattleInfoDB.MoveNext();
					}
					g_S2CProxy.sendBattleInfoResult(remote, RmiContext::ReliableSend, 1, sendBInfo);
				}
			}
		}
	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	return true;
}
DEFRMI_C2S_RequestBattleEnd(C2SStub)
{
	CAdoConnection conn;
	CAdoRecordset CheckCharacterIdx;
	
	int CharacterIdx = 0;
	try
	{
		
	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	return true;
}
DEFRMI_C2S_AddItemToInventory(C2SStub)
{
	CAdoConnection conn;
	CAdoRecordset CheckCharacterIdx;
	int CharacterIdx = 0;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);
		if (!CheckCharacterIdx.IsOpened())
		{
			CheckCharacterIdx.Open(conn, OpenForRead, String::NewFormat(L"select * from usercharacter where CName = '%s' ", CName));
			if (CheckCharacterIdx.IsEOF() == true)
			{
				// 잘못된 캐릭터명
			}
			else
			{
				CharacterIdx = CheckCharacterIdx.FieldValues[L"idx"];
				if (stackAble == 1)
				{
					conn.Execute(String::NewFormat(L"update userinventory set itemCount = itemCount + '%d' where itemIdx = '%d' and CharacterIdx = '%d' ", itemCount, itemId, CharacterIdx));
				}
				else if (stackAble == 0)
				{
					//conn.Execute(String::NewFormat(L"update userinventory set itemCount = itemCount + 1 where itemIdx = '%d' and CharacterIdx = '%d' ", itemId, CharacterIdx));
					conn.Execute(String::NewFormat(L"insert into userinventory (CharacterIdx, inId, itemIdx, itemCount) VALUES('%d','%d', '%d', %d)", CharacterIdx, inId, itemId, 1));
				}
			}
		}
	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	return true;
}
DEFRMI_C2S_UseItemFromInventory(C2SStub)
{
	CAdoConnection conn;
	CAdoRecordset CheckCharacterIdx;
	int CharacterIdx = 0;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);
		if (!CheckCharacterIdx.IsOpened())
		{
			CheckCharacterIdx.Open(conn, OpenForRead, String::NewFormat(L"select * from usercharacter where CName = '%s' ", CName));
			if (CheckCharacterIdx.IsEOF() == true)
			{
				// 잘못된 캐릭터명
			}
			else
			{
				CharacterIdx = CheckCharacterIdx.FieldValues[L"idx"];
				if (stackAble == 1)
				{
					conn.Execute(String::NewFormat(L"update userinventory set itemCount = itemCount - '%d' where itemIdx = '%d' and CharacterIdx = '%d' ",itemCount, itemId, CharacterIdx));
				}
				else if (stackAble == 0)
				{
					//conn.Execute(String::NewFormat(L"update userinventory set itemCount = itemCount + 1 where itemIdx = '%d' and CharacterIdx = '%d' ", itemId, CharacterIdx));
					//conn.Execute(String::NewFormat(L"insert into userinventory (CharacterIdx, itemIdx, itemCount) VALUES('%d', '%d', %d)", CharacterIdx, itemId, 1));
				}
			}
		}
	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	return true;
}
DEFRMI_C2S_AddGold(C2SStub)
{
	CAdoConnection conn;
	CAdoRecordset CheckCharacterIdx;
	int CharacterIdx = 0;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);
		conn.Execute(String::NewFormat(L"update usercharacter set Money = Money + '%d' where CName = '%s' ", gold, CName));
	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	return true;
}
DEFRMI_C2S_UseGold(C2SStub)
{
	CAdoConnection conn;
	CAdoRecordset CheckCharacterIdx;
	int CharacterIdx = 0;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);
		conn.Execute(String::NewFormat(L"update usercharacter set Money = Money - '%d' where CName = '%s' ", gold, CName));
	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	return true;
}
DEFRMI_C2S_SellAllItem(C2SStub)
{
	CAdoConnection conn;
	CAdoRecordset CheckCharacterIdx;
	int CharacterIdx = 0;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);
		if (!CheckCharacterIdx.IsOpened())
		{
			CheckCharacterIdx.Open(conn, OpenForRead, String::NewFormat(L"select * from usercharacter where CName = '%s' ", CName));
			if (CheckCharacterIdx.IsEOF() == true)
			{
				// 잘못된 캐릭터명
			}
			else
			{
				CharacterIdx = CheckCharacterIdx.FieldValues[L"idx"];
				conn.Execute(String::NewFormat(L"delete from userinventory where inId = '%d' and itemIdx = '%d' and CharacterIdx = '%d' ", inId, itemId, CharacterIdx));
				
			}
		}
	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	return true;
}
DEFRMI_C2S_SendEquipInfo(C2SStub)
{
	CAdoConnection conn;
	CAdoRecordset CheckCharacterIdx;
	int CharacterIdx = 0;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);
		if (!CheckCharacterIdx.IsOpened())
		{
			CheckCharacterIdx.Open(conn, OpenForRead, String::NewFormat(L"select * from usercharacter where CName = '%s' ", CName));
			if (CheckCharacterIdx.IsEOF() == true)
			{
				// 잘못된 캐릭터명
			}
			else
			{
				CharacterIdx = CheckCharacterIdx.FieldValues[L"idx"];
				conn.Execute(String::NewFormat(L"update userequipment set equipSlot1 = '%d', equipSlot2 = '%d' , equipSlot3 = '%d', equipSlot4 = '%d', equipSlot5 = '%d', equipSlot6 = '%d'  where CharacterIdx = '%d' ", equipslot1, equipslot2, equipslot3, equipslot4, equipslot5, equipslot6, CharacterIdx));

			}
		}
	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	return true;
}
DEFRMI_C2S_SendPassiveEquipInfo(C2SStub)
{
	CAdoConnection conn;
	CAdoRecordset CheckCharacterIdx;
	int CharacterIdx = 0;
	try
	{
		conn.Open(ConnectString, DbmsType::MySql);
		if (!CheckCharacterIdx.IsOpened())
		{
			CheckCharacterIdx.Open(conn, OpenForRead, String::NewFormat(L"select * from usercharacter where CName = '%s' ", CName));
			if (CheckCharacterIdx.IsEOF() == true)
			{
				// 잘못된 캐릭터명
			}
			else
			{
				CharacterIdx = CheckCharacterIdx.FieldValues[L"idx"];
				conn.Execute(String::NewFormat(L"update userpassiveskill set passiveSlot1 = '%d', passiveSlot2 = '%d' , passiveSlot3 = '%d' , passiveSlot4 = '%d'  where CharacterIdx = '%d' ", equipslot1, equipslot2, equipslot3, equipslot4, CharacterIdx));

			}
		}
	}
	catch (AdoException &e)
	{
		wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
	}
	return true;
}
ServerManager* ServerManager::S2CInstance = nullptr;
ServerManager::ServerManager()
{
	m_groupHostID = HostID_None;
	m_lastClientID = HostID_None;
	srv = CNetServer::Create();
};
ServerManager* ServerManager::getInstance()
{
	if (S2CInstance == NULL)
		S2CInstance = new ServerManager();
	return S2CInstance;
};

HostID ServerManager::getGroupHostID()
{
	return  this->m_groupHostID;
}
HostID ServerManager::getLastClientID()
{
	return this->m_lastClientID;
}

void ServerManager::setGroupHostID(HostID setHostID)
{
	this->m_groupHostID = setHostID;
}
void ServerManager::setLastClientHostID(HostID setLastClientID)
{
	this->m_lastClientID = setLastClientID;
}

///////////////////////////
// ADODB 사용 예      /////
/*
CAdoConnection conn;
CAdoRecordset rec;
try
{
	conn.Open(L"Driver={MySQL ODBC 5.1 Driver};Server=127.0.0.1;UID=soongsae;PWD=soongsae9016!;DB=ProudDB2-Test;Port=3306", DbmsType::MySql);

	//conn.Open(L"Driver={MySQL ODBC 5.1 Driver};server = 127.0.0.1; port = 3306; Database = friend;User ID = soongsae; Password = soongsae9016!; ");

	wprintf(L"DB Connect Succeed!!\n");

}
catch (AdoException &e)
{
	wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
}

try
{
	
}
catch (AdoException &e)
{
	wprintf(L"DB Exception : %s\n", StringA2W(e.what()).GetString());
}
String strID, strPassword, strCountry;
while (rec.IsEOF() == false)
{
	strID = rec.FieldValues[L"UserID"];
	strPassword = rec.FieldValues[L"Password"];
	strCountry = rec.FieldValues[L"Country"];

	wprintf(L"UserID : %s, Password : %s, Country : %s\n", strID.GetString(), strPassword.GetString(), strCountry.GetString());

	// 커서를 다음행으로 이동시킨다.
	// Move a cursor to the next line.
	rec.MoveNext();
}
*/