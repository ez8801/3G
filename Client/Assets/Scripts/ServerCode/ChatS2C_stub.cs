﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;	     

namespace ChatS2C
{
	internal class Stub:Nettention.Proud.RmiStub
	{
public AfterRmiInvocationDelegate AfterRmiInvocation = delegate(Nettention.Proud.AfterRmiSummary summary) {};
public BeforeRmiInvocationDelegate BeforeRmiInvocation = delegate(Nettention.Proud.BeforeRmiSummary summary) {};

		public delegate bool ShowChatDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String userName, System.String text);  
		public ShowChatDelegate ShowChat = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String userName, System.String text)
		{ 
			return false;
		};
		public delegate bool UserList_AddDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String userName, Nettention.Proud.HostID hostID);  
		public UserList_AddDelegate UserList_Add = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String userName, Nettention.Proud.HostID hostID)
		{ 
			return false;
		};
		public delegate bool UserList_RemoveDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID hostID);  
		public UserList_RemoveDelegate UserList_Remove = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID hostID)
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
			
		System.String userName; Nettention.Proud.Marshaler.Read(__msg,out userName);	
System.String text; Nettention.Proud.Marshaler.Read(__msg,out text);	
core.PostCheckReadMessage(__msg, RmiName_ShowChat);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=userName.ToString()+",";
parameterString+=text.ToString()+",";
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
		bool __ret=ShowChat (remote,ctx , userName, text );
			
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
case Common.UserList_Add:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		System.String userName; Nettention.Proud.Marshaler.Read(__msg,out userName);	
Nettention.Proud.HostID hostID; Nettention.Proud.Marshaler.Read(__msg,out hostID);	
core.PostCheckReadMessage(__msg, RmiName_UserList_Add);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=userName.ToString()+",";
parameterString+=hostID.ToString()+",";
			NotifyCallFromStub(Common.UserList_Add, RmiName_UserList_Add,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.UserList_Add;
			summary.rmiName = RmiName_UserList_Add;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=UserList_Add (remote,ctx , userName, hostID );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_UserList_Add);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.UserList_Add;
			summary.rmiName = RmiName_UserList_Add;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.UserList_Remove:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		Nettention.Proud.HostID hostID; Nettention.Proud.Marshaler.Read(__msg,out hostID);	
core.PostCheckReadMessage(__msg, RmiName_UserList_Remove);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=hostID.ToString()+",";
			NotifyCallFromStub(Common.UserList_Remove, RmiName_UserList_Remove,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.UserList_Remove;
			summary.rmiName = RmiName_UserList_Remove;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=UserList_Remove (remote,ctx , hostID );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_UserList_Remove);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.UserList_Remove;
			summary.rmiName = RmiName_UserList_Remove;
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
		public override Nettention.Proud.RmiID[] GetRmiIDList { get{return Common.RmiIDList;} }
		
	}
}
