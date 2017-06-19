using UnityEngine;
using System.Collections;

namespace ChatUnity
{
	public enum ToolBarState
	{
		GlobalChat,
		UserList,
		P2PChatRoom,
		None
	}

	public enum P2PChatToolBarState
	{
		Back,
		LeaveRoom,
		None
	}

	public class Vars
    {
        
		public static System.Guid Version = new System.Guid("{0x3ae33249,0xecc6,0x4980,{0xbc,0x5d,0x7b,0xa,0x99,0x9c,0x7,0x39}}");
		public static int ServerPort  = 52425;

		public Vars()
		{

		}
	}
}

