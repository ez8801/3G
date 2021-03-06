﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;	     

namespace ChatC2S
{
	internal class Stub:Nettention.Proud.RmiStub
	{
public AfterRmiInvocationDelegate AfterRmiInvocation = delegate(Nettention.Proud.AfterRmiSummary summary) {};
public BeforeRmiInvocationDelegate BeforeRmiInvocation = delegate(Nettention.Proud.BeforeRmiSummary summary) {};

		public delegate bool RequestLogonDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String userName);  
		public RequestLogonDelegate RequestLogon = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String userName)
		{ 
			return false;
		};
		public delegate bool ChatDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String text);  
		public ChatDelegate Chat = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String text)
		{ 
			return false;
		};
		public delegate bool RequestP2PGroupDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostIDArray groupMemberList);  
		public RequestP2PGroupDelegate RequestP2PGroup = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostIDArray groupMemberList)
		{ 
			return false;
		};
		public delegate bool RequestLeaveP2PGroupDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID groupID);  
		public RequestLeaveP2PGroupDelegate RequestLeaveP2PGroup = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, Nettention.Proud.HostID groupID)
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
case Common.RequestLogon:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		System.String userName; Nettention.Proud.Marshaler.Read(__msg,out userName);	
core.PostCheckReadMessage(__msg, RmiName_RequestLogon);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=userName.ToString()+",";
			NotifyCallFromStub(Common.RequestLogon, RmiName_RequestLogon,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.RequestLogon;
			summary.rmiName = RmiName_RequestLogon;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=RequestLogon (remote,ctx , userName );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_RequestLogon);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.RequestLogon;
			summary.rmiName = RmiName_RequestLogon;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.Chat:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		System.String text; Nettention.Proud.Marshaler.Read(__msg,out text);	
core.PostCheckReadMessage(__msg, RmiName_Chat);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=text.ToString()+",";
			NotifyCallFromStub(Common.Chat, RmiName_Chat,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.Chat;
			summary.rmiName = RmiName_Chat;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=Chat (remote,ctx , text );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_Chat);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.Chat;
			summary.rmiName = RmiName_Chat;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.RequestP2PGroup:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		Nettention.Proud.HostIDArray groupMemberList; Nettention.Proud.Marshaler.Read(__msg,out groupMemberList);	
core.PostCheckReadMessage(__msg, RmiName_RequestP2PGroup);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=groupMemberList.ToString()+",";
			NotifyCallFromStub(Common.RequestP2PGroup, RmiName_RequestP2PGroup,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.RequestP2PGroup;
			summary.rmiName = RmiName_RequestP2PGroup;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=RequestP2PGroup (remote,ctx , groupMemberList );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_RequestP2PGroup);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.RequestP2PGroup;
			summary.rmiName = RmiName_RequestP2PGroup;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.RequestLeaveP2PGroup:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		Nettention.Proud.HostID groupID; Nettention.Proud.Marshaler.Read(__msg,out groupID);	
core.PostCheckReadMessage(__msg, RmiName_RequestLeaveP2PGroup);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=groupID.ToString()+",";
			NotifyCallFromStub(Common.RequestLeaveP2PGroup, RmiName_RequestLeaveP2PGroup,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.RequestLeaveP2PGroup;
			summary.rmiName = RmiName_RequestLeaveP2PGroup;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=RequestLeaveP2PGroup (remote,ctx , groupID );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_RequestLeaveP2PGroup);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.RequestLeaveP2PGroup;
			summary.rmiName = RmiName_RequestLeaveP2PGroup;
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
const string RmiName_RequestLogon="RequestLogon";
const string RmiName_Chat="Chat";
const string RmiName_RequestP2PGroup="RequestP2PGroup";
const string RmiName_RequestLeaveP2PGroup="RequestLeaveP2PGroup";
       
const string RmiName_First = RmiName_RequestLogon;
#else
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_RequestLogon="";
const string RmiName_Chat="";
const string RmiName_RequestP2PGroup="";
const string RmiName_RequestLeaveP2PGroup="";
       
const string RmiName_First = "";
#endif
		public override Nettention.Proud.RmiID[] GetRmiIDList { get{return Common.RmiIDList;} }
		
	}
}

