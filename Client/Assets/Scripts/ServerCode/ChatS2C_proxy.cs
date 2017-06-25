﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;

namespace ChatS2C
{
	internal class Proxy:Nettention.Proud.RmiProxy
	{
public bool ShowChat(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String userName, System.String text)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.ShowChat;
		__msg.Write(__msgid);
		Nettention.Proud.Marshaler.Write(__msg, userName);
		Nettention.Proud.Marshaler.Write(__msg, text);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_ShowChat, Common.ShowChat);
}

public bool ShowChat(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, System.String userName, System.String text)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.ShowChat;
__msg.Write(__msgid);
Nettention.Proud.Marshaler.Write(__msg, userName);
Nettention.Proud.Marshaler.Write(__msg, text);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_ShowChat, Common.ShowChat);
}
public bool UserList_Add(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String userName, Nettention.Proud.HostID hostID)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.UserList_Add;
		__msg.Write(__msgid);
		Nettention.Proud.Marshaler.Write(__msg, userName);
		Nettention.Proud.Marshaler.Write(__msg, hostID);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_UserList_Add, Common.UserList_Add);
}

public bool UserList_Add(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, System.String userName, Nettention.Proud.HostID hostID)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.UserList_Add;
__msg.Write(__msgid);
Nettention.Proud.Marshaler.Write(__msg, userName);
Nettention.Proud.Marshaler.Write(__msg, hostID);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_UserList_Add, Common.UserList_Add);
}
public bool UserList_Remove(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID hostID)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
		__msg.SimplePacketMode = core.IsSimplePacketMode();
		Nettention.Proud.RmiID __msgid= Common.UserList_Remove;
		__msg.Write(__msgid);
		Nettention.Proud.Marshaler.Write(__msg, hostID);
		
	Nettention.Proud.HostID[] __list = new Nettention.Proud.HostID[1];
	__list[0] = remote;
		
	return RmiSend(__list,rmiContext,__msg,
		RmiName_UserList_Remove, Common.UserList_Remove);
}

public bool UserList_Remove(Nettention.Proud.HostID[] remotes,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID hostID)
{
	Nettention.Proud.Message __msg=new Nettention.Proud.Message();
__msg.SimplePacketMode = core.IsSimplePacketMode();
Nettention.Proud.RmiID __msgid= Common.UserList_Remove;
__msg.Write(__msgid);
Nettention.Proud.Marshaler.Write(__msg, hostID);
		
	return RmiSend(remotes,rmiContext,__msg,
		RmiName_UserList_Remove, Common.UserList_Remove);
}
#if USE_RMI_NAME_STRING
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_ShowChat="ShowChat";
const string RmiName_UserList_Add="UserList_Add";
const string RmiName_UserList_Remove="UserList_Remove";
       
const string RmiName_First = RmiName_ShowChat;
#else
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_ShowChat="";
const string RmiName_UserList_Add="";
const string RmiName_UserList_Remove="";
       
const string RmiName_First = "";
#endif
		public override Nettention.Proud.RmiID[] GetRmiIDList() { return Common.RmiIDList; } 
	}
}
