﻿ 





// Generated by PIDL compiler.
// Do not modify this file, but modify the source .pidl file.

using System;
namespace ChatC2S
{
	internal class Common
	{
		// Message ID that replies to each RMI method. 
			public const Nettention.Proud.RmiID RequestLogon = (Nettention.Proud.RmiID)4000+1;
			public const Nettention.Proud.RmiID Chat = (Nettention.Proud.RmiID)4000+2;
			public const Nettention.Proud.RmiID RequestP2PGroup = (Nettention.Proud.RmiID)4000+3;
			public const Nettention.Proud.RmiID RequestLeaveP2PGroup = (Nettention.Proud.RmiID)4000+4;
		// List that has RMI ID.
		public static Nettention.Proud.RmiID[] RmiIDList = new Nettention.Proud.RmiID[] {
			RequestLogon,
			Chat,
			RequestP2PGroup,
			RequestLeaveP2PGroup,
		};
	}
}

				 
