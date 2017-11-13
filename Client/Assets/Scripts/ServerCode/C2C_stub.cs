﻿




// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
using System.Net;	     

namespace C2C
{
	internal class Stub:Nettention.Proud.RmiStub
	{
public AfterRmiInvocationDelegate AfterRmiInvocation = delegate(Nettention.Proud.AfterRmiSummary summary) {};
public BeforeRmiInvocationDelegate BeforeRmiInvocation = delegate(Nettention.Proud.BeforeRmiSummary summary) {};

		public delegate bool P2PChatDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String a, int b, float c);  
		public P2PChatDelegate P2PChat = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, System.String a, int b, float c)
		{ 
			return false;
		};
		public delegate bool DamagedFromEnemyDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int Damage, int RestHP);  
		public DamagedFromEnemyDelegate DamagedFromEnemy = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int Damage, int RestHP)
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
case Common.P2PChat:
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
core.PostCheckReadMessage(__msg, RmiName_P2PChat);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=a.ToString()+",";
parameterString+=b.ToString()+",";
parameterString+=c.ToString()+",";
			NotifyCallFromStub(Common.P2PChat, RmiName_P2PChat,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.P2PChat;
			summary.rmiName = RmiName_P2PChat;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=P2PChat (remote,ctx , a, b, c );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_P2PChat);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.P2PChat;
			summary.rmiName = RmiName_P2PChat;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.DamagedFromEnemy:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		int Damage; Test.Read(__msg,out Damage);	
int RestHP; Test.Read(__msg,out RestHP);	
core.PostCheckReadMessage(__msg, RmiName_DamagedFromEnemy);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=Damage.ToString()+",";
parameterString+=RestHP.ToString()+",";
			NotifyCallFromStub(Common.DamagedFromEnemy, RmiName_DamagedFromEnemy,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.DamagedFromEnemy;
			summary.rmiName = RmiName_DamagedFromEnemy;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=DamagedFromEnemy (remote,ctx , Damage, RestHP );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_DamagedFromEnemy);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.DamagedFromEnemy;
			summary.rmiName = RmiName_DamagedFromEnemy;
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
const string RmiName_P2PChat="P2PChat";
const string RmiName_DamagedFromEnemy="DamagedFromEnemy";
       
const string RmiName_First = RmiName_P2PChat;
#else
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_P2PChat="";
const string RmiName_DamagedFromEnemy="";
       
const string RmiName_First = "";
#endif
		public override Nettention.Proud.RmiID[] GetRmiIDList { get{return Common.RmiIDList;} }
		
	}
}

