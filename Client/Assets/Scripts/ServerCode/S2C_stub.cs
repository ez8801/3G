﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;	     

namespace S2C
{
	internal class Stub:Nettention.Proud.RmiStub
	{
public AfterRmiInvocationDelegate AfterRmiInvocation = delegate(Nettention.Proud.AfterRmiSummary summary) {};
public BeforeRmiInvocationDelegate BeforeRmiInvocation = delegate(Nettention.Proud.BeforeRmiSummary summary) {};

		public delegate bool ShowChatDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String a, int b, float c);  
		public ShowChatDelegate ShowChat = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String a, int b, float c)
		{ 
			return false;
		};
		public delegate bool SystemChatDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String txt);  
		public SystemChatDelegate SystemChat = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String txt)
		{ 
			return false;
		};
		public delegate bool sendUserInfoDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String userName, int att, int def);  
		public sendUserInfoDelegate sendUserInfo = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String userName, int att, int def)
		{ 
			return false;
		};
		public delegate bool sendInventoryDataDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.FastArray<items> ivData);  
		public sendInventoryDataDelegate sendInventoryData = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.FastArray<items> ivData)
		{ 
			return false;
		};
		public delegate bool sendRaidRoomInfoDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.FastArray<raidrooms> roomData);  
		public sendRaidRoomInfoDelegate sendRaidRoomInfo = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.FastArray<raidrooms> roomData)
		{ 
			return false;
		};
	public override bool ProcessReceivedMessage(Nettention.Proud.ReceivedMessage pa, Object hostTag) 
	{
		Nettention.Proud.HostID remote=pa.RemoteHostID;
		if(remote==Nettention.Proud.HostID.HostID_None)
		{
			ShowUnknownHostIDWarning(remote);
		}

		Nettention.Proud.Message __msg=pa.ReadOnlyMessage;
		int orgReadOffset = __msg.ReadOffset;
        Nettention.Proud.RmiID __rmiID = Nettention.Proud.RmiID.RmiID_None;
        if (!__msg.Read( out __rmiID))
            goto __fail;
					
		switch(__rmiID)
		{
case Common.ShowChat:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		System.String a; Test.Read(__msg,out a);	
int b; Test.Read(__msg,out b);	
float c; Test.Read(__msg,out c);	
core.PostCheckReadMessage(__msg, RmiName_ShowChat);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=a.ToString()+",";
parameterString+=b.ToString()+",";
parameterString+=c.ToString()+",";
			NotifyCallFromStub(Common.ShowChat, RmiName_ShowChat,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.ShowChat;
			summary.rmiName = RmiName_ShowChat;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=ShowChat (remote,ctx , a, b, c );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_ShowChat);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.ShowChat;
			summary.rmiName = RmiName_ShowChat;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.SystemChat:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		System.String txt; Test.Read(__msg,out txt);	
core.PostCheckReadMessage(__msg, RmiName_SystemChat);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=txt.ToString()+",";
			NotifyCallFromStub(Common.SystemChat, RmiName_SystemChat,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.SystemChat;
			summary.rmiName = RmiName_SystemChat;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=SystemChat (remote,ctx , txt );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_SystemChat);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.SystemChat;
			summary.rmiName = RmiName_SystemChat;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.sendUserInfo:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		System.String userName; Test.Read(__msg,out userName);	
int att; Test.Read(__msg,out att);	
int def; Test.Read(__msg,out def);	
core.PostCheckReadMessage(__msg, RmiName_sendUserInfo);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=userName.ToString()+",";
parameterString+=att.ToString()+",";
parameterString+=def.ToString()+",";
			NotifyCallFromStub(Common.sendUserInfo, RmiName_sendUserInfo,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.sendUserInfo;
			summary.rmiName = RmiName_sendUserInfo;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=sendUserInfo (remote,ctx , userName, att, def );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_sendUserInfo);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.sendUserInfo;
			summary.rmiName = RmiName_sendUserInfo;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.sendInventoryData:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		Nettention.Proud.FastArray<items> ivData; Test.Read(__msg,out ivData);	
core.PostCheckReadMessage(__msg, RmiName_sendInventoryData);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=ivData.ToString()+",";
			NotifyCallFromStub(Common.sendInventoryData, RmiName_sendInventoryData,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.sendInventoryData;
			summary.rmiName = RmiName_sendInventoryData;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=sendInventoryData (remote,ctx , ivData );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_sendInventoryData);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.sendInventoryData;
			summary.rmiName = RmiName_sendInventoryData;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.sendRaidRoomInfo:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		Nettention.Proud.FastArray<raidrooms> roomData; Test.Read(__msg,out roomData);	
core.PostCheckReadMessage(__msg, RmiName_sendRaidRoomInfo);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=roomData.ToString()+",";
			NotifyCallFromStub(Common.sendRaidRoomInfo, RmiName_sendRaidRoomInfo,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.sendRaidRoomInfo;
			summary.rmiName = RmiName_sendRaidRoomInfo;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=sendRaidRoomInfo (remote,ctx , roomData );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_sendRaidRoomInfo);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.sendRaidRoomInfo;
			summary.rmiName = RmiName_sendRaidRoomInfo;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
		default:
			 goto __fail;
		}
		return true;
__fail:
	  {
			__msg.ReadOffset = orgReadOffset;
			return false;
	  }
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
		public override Nettention.Proud.RmiID[] GetRmiIDList { get{return Common.RmiIDList;} }
		
	}
}

