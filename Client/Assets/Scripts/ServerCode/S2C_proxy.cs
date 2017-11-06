﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;

namespace S2C
{
	internal class Proxy:Nettention.Proud.RmiProxy
	{
public bool ShowChat(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String a, int b, float c)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.ShowChat;
		__msg.Write(__msgid);
		Test.Write(__msg, a);
		Test.Write(__msg, b);
		Test.Write(__msg, c);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_ShowChat, Common.ShowChat);
}

public bool ShowChat(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, System.String a, int b, float c)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.ShowChat;
__msg.Write(__msgid);
Test.Write(__msg, a);
Test.Write(__msg, b);
Test.Write(__msg, c);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_ShowChat, Common.ShowChat);
}
public bool SystemChat(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String txt)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.SystemChat;
		__msg.Write(__msgid);
		Test.Write(__msg, txt);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_SystemChat, Common.SystemChat);
}

public bool SystemChat(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, System.String txt)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.SystemChat;
__msg.Write(__msgid);
Test.Write(__msg, txt);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_SystemChat, Common.SystemChat);
}
public bool sendUserInfo(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String userName, int att, int def)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.sendUserInfo;
		__msg.Write(__msgid);
		Test.Write(__msg, userName);
		Test.Write(__msg, att);
		Test.Write(__msg, def);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_sendUserInfo, Common.sendUserInfo);
}

public bool sendUserInfo(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, System.String userName, int att, int def)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.sendUserInfo;
__msg.Write(__msgid);
Test.Write(__msg, userName);
Test.Write(__msg, att);
Test.Write(__msg, def);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_sendUserInfo, Common.sendUserInfo);
}
public bool sendInventoryData(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.FastArray<items> ivData)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.sendInventoryData;
		__msg.Write(__msgid);
		Test.Write(__msg, ivData);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_sendInventoryData, Common.sendInventoryData);
}

public bool sendInventoryData(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.FastArray<items> ivData)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.sendInventoryData;
__msg.Write(__msgid);
Test.Write(__msg, ivData);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_sendInventoryData, Common.sendInventoryData);
}
public bool sendRaidRoomInfo(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.FastArray<raidrooms> roomData)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.sendRaidRoomInfo;
		__msg.Write(__msgid);
		Test.Write(__msg, roomData);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_sendRaidRoomInfo, Common.sendRaidRoomInfo);
}

public bool sendRaidRoomInfo(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.FastArray<raidrooms> roomData)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.sendRaidRoomInfo;
__msg.Write(__msgid);
Test.Write(__msg, roomData);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_sendRaidRoomInfo, Common.sendRaidRoomInfo);
}
#if USE_RMI_NAME_STRING
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_ShowChat="ShowChat";
const string RmiName_SystemChat="SystemChat";
const string RmiName_sendUserInfo="sendUserInfo";
const string RmiName_sendInventoryData="sendInventoryData";
const string RmiName_sendRaidRoomInfo="sendRaidRoomInfo";
       
const string RmiName_First = RmiName_ShowChat;
#else
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_ShowChat="";
const string RmiName_SystemChat="";
const string RmiName_sendUserInfo="";
const string RmiName_sendInventoryData="";
const string RmiName_sendRaidRoomInfo="";
       
const string RmiName_First = "";
#endif
		public override Nettention.Proud.RmiID[] GetRmiIDList() { return Common.RmiIDList; } 
	}
}

