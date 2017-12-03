#pragma once
// 서버매니져 클래스
// 싱글톤으로 되어 있으며 
// 서버 전체적으로 사용하는 글로벌한 내용들을 담고있음
// exception : s2cProxy의 경우 프라우드넷 구조상 글로벌로 사용중
// 이유 : s2cProxy를 Attach해줄경우 최초의 한개의 proxy에 대해서만 attach가 가능하기 때문
#ifndef __PACKET_H_
#define __PACKET_H_

#include "Common.h"
#include "mymarshaler.h"
#include "../TeamGGCommon/C2S_stub.h"
#include "../TeamGGCommon/S2C_proxy.h"

class C2SStub : public C2S::Stub
{
public:
	DECRMI_C2S_Chat;
	DECRMI_C2S_Login;
	DECRMI_C2S_RequestMakeRaidRoom;
	DECRMI_C2S_RequestJoinRaidRoom;
	DECRMI_C2S_RequestGetRaidRoomInfo;
	DECRMI_C2S_RequestMakePVPRoom;
	DECRMI_C2S_RequestGetPVPRoomInfo;
	DECRMI_C2S_RequestJoinPVPRoom;
	DECRMI_C2S_RequestLeavePVPRoom;
	DECRMI_C2S_RequestMakeAccount;
	DECRMI_C2S_RequestLoginAccount;
	DECRMI_C2S_RequestInventoryData;
	DECRMI_C2S_RequestSkillData;
	DECRMI_C2S_RequestEquipData;
	DECRMI_C2S_RequestChangeEquipWeapon;
	DECRMI_C2S_RequestBattleInfo;
	DECRMI_C2S_RequestBattleEnd;
	DECRMI_C2S_AddItemToInventory;
	DECRMI_C2S_UseItemFromInventory;
	DECRMI_C2S_AddGold;
	DECRMI_C2S_UseGold;
	DECRMI_C2S_SellAllItem;
	DECRMI_C2S_SendEquipInfo;
	DECRMI_C2S_SendPassiveEquipInfo;
};


class ServerManager
{
private:
	static ServerManager *S2CInstance;

	HostID m_groupHostID;
	HostID m_lastClientID ;
	ServerManager();


public:
	////////GET FUNC/////////
	S2C::Proxy& getS2CProxy();
	C2SStub getC2SStub();
	HostID getGroupHostID();
	HostID getLastClientID();
	CNetServer*  srv;
	

	///////SET FUNC//////////
	void setGroupHostID(Proud::HostID setHostID);
	void setLastClientHostID(Proud::HostID setLastClientID);

	void setS2CProxyValue(S2C::Proxy m_proxy);

	static ServerManager *getInstance();


};


#endif // !__PACKET_H_