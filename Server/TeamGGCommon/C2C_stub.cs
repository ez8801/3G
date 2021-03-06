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
		public delegate bool ReadyPacketDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int Ready);  
		public ReadyPacketDelegate ReadyPacket = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int Ready)
		{ 
			return false;
		};
		public delegate bool SettingEnemyInfoDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int Id, int Hp, int Att, int def);  
		public SettingEnemyInfoDelegate SettingEnemyInfo = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int Id, int Hp, int Att, int def)
		{ 
			return false;
		};
		public delegate bool StartPacketDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int Start);  
		public StartPacketDelegate StartPacket = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int Start)
		{ 
			return false;
		};
		public delegate bool LeaveRoomDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext);  
		public LeaveRoomDelegate LeaveRoom = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext)
		{ 
			return false;
		};
		public delegate bool SyncPacketDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int LocationX, int LocationY, int Hp);  
		public SyncPacketDelegate SyncPacket = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int LocationX, int LocationY, int Hp)
		{ 
			return false;
		};
		public delegate bool DamagedFromEnemyDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int Damage, int RestHP);  
		public DamagedFromEnemyDelegate DamagedFromEnemy = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int Damage, int RestHP)
		{ 
			return false;
		};
		public delegate bool UseSkillDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int SkillId);  
		public UseSkillDelegate UseSkill = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext, int SkillId)
		{ 
			return false;
		};
		public delegate bool MatchEndDelegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext);  
		public MatchEndDelegate MatchEnd = delegate(Nettention.Proud.HostID remote,Nettention.Proud.RmiContext rmiContext)
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
case Common.ReadyPacket:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		int Ready; Test.Read(__msg,out Ready);	
core.PostCheckReadMessage(__msg, RmiName_ReadyPacket);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=Ready.ToString()+",";
			NotifyCallFromStub(Common.ReadyPacket, RmiName_ReadyPacket,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.ReadyPacket;
			summary.rmiName = RmiName_ReadyPacket;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=ReadyPacket (remote,ctx , Ready );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_ReadyPacket);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.ReadyPacket;
			summary.rmiName = RmiName_ReadyPacket;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.SettingEnemyInfo:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		int Id; Test.Read(__msg,out Id);	
int Hp; Test.Read(__msg,out Hp);	
int Att; Test.Read(__msg,out Att);	
int def; Test.Read(__msg,out def);	
core.PostCheckReadMessage(__msg, RmiName_SettingEnemyInfo);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=Id.ToString()+",";
parameterString+=Hp.ToString()+",";
parameterString+=Att.ToString()+",";
parameterString+=def.ToString()+",";
			NotifyCallFromStub(Common.SettingEnemyInfo, RmiName_SettingEnemyInfo,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.SettingEnemyInfo;
			summary.rmiName = RmiName_SettingEnemyInfo;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=SettingEnemyInfo (remote,ctx , Id, Hp, Att, def );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_SettingEnemyInfo);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.SettingEnemyInfo;
			summary.rmiName = RmiName_SettingEnemyInfo;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.StartPacket:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		int Start; Test.Read(__msg,out Start);	
core.PostCheckReadMessage(__msg, RmiName_StartPacket);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=Start.ToString()+",";
			NotifyCallFromStub(Common.StartPacket, RmiName_StartPacket,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.StartPacket;
			summary.rmiName = RmiName_StartPacket;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=StartPacket (remote,ctx , Start );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_StartPacket);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.StartPacket;
			summary.rmiName = RmiName_StartPacket;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.LeaveRoom:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		core.PostCheckReadMessage(__msg, RmiName_LeaveRoom);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
						NotifyCallFromStub(Common.LeaveRoom, RmiName_LeaveRoom,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.LeaveRoom;
			summary.rmiName = RmiName_LeaveRoom;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=LeaveRoom (remote,ctx  );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_LeaveRoom);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.LeaveRoom;
			summary.rmiName = RmiName_LeaveRoom;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.SyncPacket:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		int LocationX; Test.Read(__msg,out LocationX);	
int LocationY; Test.Read(__msg,out LocationY);	
int Hp; Test.Read(__msg,out Hp);	
core.PostCheckReadMessage(__msg, RmiName_SyncPacket);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=LocationX.ToString()+",";
parameterString+=LocationY.ToString()+",";
parameterString+=Hp.ToString()+",";
			NotifyCallFromStub(Common.SyncPacket, RmiName_SyncPacket,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.SyncPacket;
			summary.rmiName = RmiName_SyncPacket;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=SyncPacket (remote,ctx , LocationX, LocationY, Hp );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_SyncPacket);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.SyncPacket;
			summary.rmiName = RmiName_SyncPacket;
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
case Common.UseSkill:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		int SkillId; Test.Read(__msg,out SkillId);	
core.PostCheckReadMessage(__msg, RmiName_UseSkill);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
			parameterString+=SkillId.ToString()+",";
			NotifyCallFromStub(Common.UseSkill, RmiName_UseSkill,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.UseSkill;
			summary.rmiName = RmiName_UseSkill;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=UseSkill (remote,ctx , SkillId );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_UseSkill);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.UseSkill;
			summary.rmiName = RmiName_UseSkill;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			summary.elapsedTime = Nettention.Proud.PreciseCurrentTime.GetTimeMs()-t0;
			AfterRmiInvocation(summary);
		}
	}
	break;
case Common.MatchEnd:
	{
		Nettention.Proud.RmiContext ctx=new Nettention.Proud.RmiContext();
		ctx.sentFrom=pa.RemoteHostID;
		ctx.relayed=pa.IsRelayed;
		ctx.hostTag=hostTag;
		ctx.encryptMode = pa.EncryptMode;
		ctx.compressMode = pa.CompressMode;
			
		core.PostCheckReadMessage(__msg, RmiName_MatchEnd);
		if(enableNotifyCallFromStub==true)
		{
			string parameterString="";
						NotifyCallFromStub(Common.MatchEnd, RmiName_MatchEnd,parameterString);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.BeforeRmiSummary summary = new Nettention.Proud.BeforeRmiSummary();
			summary.rmiID = Common.MatchEnd;
			summary.rmiName = RmiName_MatchEnd;
			summary.hostID = remote;
			summary.hostTag = hostTag;
			BeforeRmiInvocation(summary);
		}
			
		long t0 = Nettention.Proud.PreciseCurrentTime.GetTimeMs();
			
		// Call this method.
		bool __ret=MatchEnd (remote,ctx  );
			
		if(__ret==false)
		{
			// Error: RMI function that a user did not create has been called. 
			core.ShowNotImplementedRmiWarning(RmiName_MatchEnd);
		}
			
		if(enableStubProfiling)
		{
			Nettention.Proud.AfterRmiSummary summary = new Nettention.Proud.AfterRmiSummary();
			summary.rmiID = Common.MatchEnd;
			summary.rmiName = RmiName_MatchEnd;
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
const string RmiName_ReadyPacket="ReadyPacket";
const string RmiName_SettingEnemyInfo="SettingEnemyInfo";
const string RmiName_StartPacket="StartPacket";
const string RmiName_LeaveRoom="LeaveRoom";
const string RmiName_SyncPacket="SyncPacket";
const string RmiName_DamagedFromEnemy="DamagedFromEnemy";
const string RmiName_UseSkill="UseSkill";
const string RmiName_MatchEnd="MatchEnd";
       
const string RmiName_First = RmiName_P2PChat;
#else
// RMI name declaration.
// It is the unique pointer that indicates RMI name such as RMI profiler.
const string RmiName_P2PChat="";
const string RmiName_ReadyPacket="";
const string RmiName_SettingEnemyInfo="";
const string RmiName_StartPacket="";
const string RmiName_LeaveRoom="";
const string RmiName_SyncPacket="";
const string RmiName_DamagedFromEnemy="";
const string RmiName_UseSkill="";
const string RmiName_MatchEnd="";
       
const string RmiName_First = "";
#endif
		public override Nettention.Proud.RmiID[] GetRmiIDList { get{return Common.RmiIDList;} }
		
	}
}

