using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.SceneManagement;
using Nettention.Proud;

public class loginToServer : MonoBehaviour {
	// Client 객체 생성.
	private Client m_client;
	
	private string m_userPassword; // 유저의 Password값
	private string m_serverIP; // 서버아이피를 저장할 스트링 변수.
    private string m_userID; // 유저의 ID값
	private string m_logonButtonString;

	
	// Use this for initialization
	void Start () {
		m_client = Client.Instance; // Client 만들어진 객체가 있다면 그것을 아니라면 새로 만들어서 가져온다.
		m_logonButtonString = "Login";
		m_serverIP = "121.131.147.109"; // m_serverIP 초기화.

        m_userID = ""; // m_userName 초기화.
        m_userPassword = "";
	}
	
	
	// Update is called once per frame
	void Update () {
		// 서버 연결이 정상적으로 되었는지 확인 한다.
		if (m_client.IsConnect == true) // 서버 연결이 되었다면.
		{
            //SceneManager.LoadScene(4);
			//Application.LoadLevel("globalChat"); // 다음씬으로 전환 한다.
		}
	}
	
	void OnGUI()
	{
		// 라벨을 ServerIP 라는 문자로 그린다.
		GUI.Label( new Rect(m_client.ScreenWidth / 2 - m_client.ScreenOneW * 2, m_client.ScreenOneH, m_client.ScreenOneW * 4, m_client.ScreenOneH),"ID");
        // 텍스트 필드를 그린다. 여기에는 serverIP 가 입력 된다.
        m_userID = GUI.TextField(new Rect(m_client.ScreenWidth / 2 - m_client.ScreenOneW * 2, m_client.ScreenOneH * 2, m_client.ScreenOneW * 4, m_client.ScreenOneH), m_userID);
		// 라벨을 userName 이라는 문자로 그린다.
		GUI.Label( new Rect(m_client.ScreenWidth / 2 - m_client.ScreenOneW * 2, m_client.ScreenOneH * 4, m_client.ScreenOneW * 4, m_client.ScreenOneH),"Password");
        // 텍스트필드를 그린다. 여기에는 닉네임이 입력 된다.
        m_userPassword = GUI.TextField(new Rect(m_client.ScreenWidth / 2 - m_client.ScreenOneW * 2, m_client.ScreenOneH * 5, m_client.ScreenOneW * 4, m_client.ScreenOneH), m_userPassword);
		
		/* 버튼 클릭시 userName 과 serverIP 를 CCleint 객체에 저장하고 서버 연결을 시도한다.
		 * 정상적으로 연결 되었다면 다음 씬으로 전환된다.
		 * */
		// LogOn 버튼을 그린다. 

		if (GUI.Button(new Rect(m_client.ScreenWidth / 2, m_client.ScreenOneH * 7, m_client.ScreenOneW, m_client.ScreenOneH), m_logonButtonString))
		{
			if (!m_userID.Equals("") && !m_serverIP.Equals("")) // 닉네임과 서버 아이피가 모두 입력 되어 있다면.
			{
				m_client.ServerIP = m_serverIP; // m_client 에 서버아이피를 설정.
				m_client.userName = m_userID; // m_client 에 닉네임을 설정.
                m_client.userPassword = m_userPassword;
				m_client.Connect(); // 서버에 접속 요청.
				m_client.IsWait = true; // 서버 연결요청을 하였을음 체크하는 변수의 속성에 true 값을 넣어준다.
				m_logonButtonString = "connecting...";
			}
		}
        if (GUI.Button(new Rect(m_client.ScreenWidth / 3 - 50, m_client.ScreenOneH * 7, m_client.ScreenOneW, m_client.ScreenOneH), "Make"))
        {
            int i = 0;
            m_client.RequestMakeRaidRoom(Nettention.Proud.RmiContext.UnreliableSend, m_client.GetLocalHostID());

            foreach (KeyValuePair<Nettention.Proud.HostID, Client.ChatRoomInfo> pair in m_client.ChatRooms) // dictionary 에 있는 아이템을 하나씩 빼온다.
            {
                if (pair.Key != Nettention.Proud.HostID.HostID_Server) // 키가 Server 가 아니면. ChatRooms 에는 server hostID, P2P그룹들의 hostID 가 있다. serverID 는 glovalChat에서 쓰고 있으니 필요가 없다..
                {
                    // 버튼을 그린다. 
                    if (GUI.Button(new Rect(m_client.ScreenWidth / 2 - m_client.ScreenOneW * 2, m_client.ScreenOneH * (i + 1), m_client.ScreenOneW * 4, m_client.ScreenOneH), "GroupHostID:" + pair.Key.ToString()))
                    {// 버튼 클릭시.
                     // P2PChat 에서 채팅창에 뿌려줄 그룹 의 아이디를 셋팅.
                        m_client.P2PChatGroupID = pair.Key;
                        
                    }
                }
                i++;
            }
        }
        if (GUI.Button(new Rect(m_client.ScreenWidth / 3 - 250, m_client.ScreenOneH * 7, m_client.ScreenOneW, m_client.ScreenOneH), "getRoom"))
        {
            
            m_client.RequestGetRaidRoomInfo(Nettention.Proud.RmiContext.UnreliableSend);

            
        }

        if (GUI.Button(new Rect(m_client.ScreenWidth / 2 + m_client.ScreenOneW, m_client.ScreenOneH * 7, m_client.ScreenOneW, m_client.ScreenOneH), "QUIT"))
		{
            SceneManager.LoadScene(1); // 어플리케이션 종료. -> 메인화면으로 씬 전환
		}
	}
}

public struct items
{
    public int inId;
    public int itemIdx;
    public int count;
};
public struct raidrooms
{
    public int hostId;
    public int groupId;
    public int curCrew;
};
public struct equipinfo
{
    public int equipslot1;
    public int equipslot2;
    public int equipslot3;
    public int equipslot4;
    public int equipslot5;
    public int equipslot6;

};
public struct passiveskillinfo
{
    public int passiveSlot1;
    public int passiveSlot2;
    public int passiveSlot3;
    public int passiveSlot4;

};
public struct battleinfo
{
    public int curA;
    public int totalA;
    public int curB;
    public int totalB;
};
public struct pvprooms
{
    public int roomId;
    public int hostId;
    public string hostname;
    public int groupId;
    public string pvproomname;
};


class Test : Nettention.Proud.Marshaler
{
    public static void Write(Nettention.Proud.Message msg, Nettention.Proud.FastArray<raidrooms> strMsg)
    {

    }
    public static void Write(Nettention.Proud.Message msg, Nettention.Proud.FastArray<pvprooms> strMsg)
    {
        for (int i = 0; i < strMsg.Count; ++i)
        {
            msg.WriteScalar(strMsg[i].roomId);
            msg.WriteScalar(strMsg[i].hostId);
            msg.Write(strMsg[i].hostname);
            msg.WriteScalar(strMsg[i].groupId);
            msg.Write(strMsg[i].pvproomname);
        }
    }

    public static void Write(Nettention.Proud.Message msg, Nettention.Proud.FastArray<items> strMsg)
    {
        for (int i = 0; i < strMsg.Count; ++i)
        {
            msg.WriteScalar(strMsg[i].inId);
            msg.WriteScalar(strMsg[i].itemIdx);
            msg.WriteScalar(strMsg[i].count);
        }
    }
    public static void Write(Nettention.Proud.Message msg, Nettention.Proud.FastArray<battleinfo> strMsg)
    {
        for (int i = 0; i < strMsg.Count; ++i)
        {
            msg.WriteScalar(strMsg[i].curA);
            msg.WriteScalar(strMsg[i].totalA);
            msg.WriteScalar(strMsg[i].curB);
            msg.WriteScalar(strMsg[i].totalB);
        }
    }
    public static void Write(Nettention.Proud.Message msg, Nettention.Proud.FastArray<passiveskillinfo> strMsg)
    {
        for (int i = 0; i < strMsg.Count; ++i)
        {
            msg.WriteScalar(strMsg[i].passiveSlot1);
            msg.WriteScalar(strMsg[i].passiveSlot2);
            msg.WriteScalar(strMsg[i].passiveSlot3);
            msg.WriteScalar(strMsg[i].passiveSlot4);
        }
    }

    public static void Write(Nettention.Proud.Message msg, Nettention.Proud.FastArray<equipinfo> strMsg)
    {
        for (int i = 0; i < strMsg.Count; ++i)
        {
            msg.WriteScalar(strMsg[i].equipslot1);
            msg.WriteScalar(strMsg[i].equipslot2);
            msg.WriteScalar(strMsg[i].equipslot3);
            msg.WriteScalar(strMsg[i].equipslot4);
            msg.WriteScalar(strMsg[i].equipslot5);
            msg.WriteScalar(strMsg[i].equipslot6);
            //msg.WriteScalar(strMsg[i].ActiveSkill_1_idx);
            //msg.WriteScalar(strMsg[i].ActiveSkill_2_idx);
            //msg.WriteScalar(strMsg[i].ActiveSkill_3_idx);
            //msg.WriteScalar(strMsg[i].ActiveSkill_4_idx);
            //msg.WriteScalar(strMsg[i].PassiveSkill_1_idx);
            //msg.WriteScalar(strMsg[i].PassiveSkill_2_idx);
            //msg.WriteScalar(strMsg[i].PassiveSkill_3_idx);
            //msg.WriteScalar(strMsg[i].PassiveSkill_4_idx);
        }
}


    public static bool Read(Nettention.Proud.Message msg, out Nettention.Proud.FastArray<items> strMsg)
    {
        strMsg = new Nettention.Proud.FastArray<items>();
        int count = 0;
        msg.ReadScalar(ref count);

        items contain_items = new items();
        for (int i = 0; i < count; i++)
        {
            msg.ReadScalar(ref contain_items.inId);
            msg.ReadScalar(ref contain_items.itemIdx);
            msg.ReadScalar(ref contain_items.count);
            
            strMsg.Add(contain_items);
        }

        return true;
    }
    public static bool Read(Nettention.Proud.Message msg, out Nettention.Proud.FastArray<raidrooms> strMsg)
    {
        strMsg = new Nettention.Proud.FastArray<raidrooms>();
        int count = 0;
        msg.ReadScalar(ref count);

        raidrooms contain_items = new raidrooms();
        for (int i = 0; i < count; i++)
        {
            msg.ReadScalar(ref contain_items.hostId);
            msg.ReadScalar(ref contain_items.groupId);
            msg.ReadScalar(ref contain_items.curCrew);
            strMsg.Add(contain_items);
        }

        return true;
    }
    public static bool Read(Nettention.Proud.Message msg, out Nettention.Proud.FastArray<pvprooms> strMsg)
    {
        strMsg = new Nettention.Proud.FastArray<pvprooms>();
        int count = 0;
        msg.ReadScalar(ref count);

        pvprooms contain_items = new pvprooms();
        for (int i = 0; i < count; i++)
        {
            msg.ReadScalar(ref contain_items.roomId);
            msg.ReadScalar(ref contain_items.hostId);
            msg.Read(out contain_items.hostname);
            msg.ReadScalar(ref contain_items.groupId);
            msg.Read(out contain_items.pvproomname);
            strMsg.Add(contain_items);
        }

        return true;
    }
    public static bool Read(Nettention.Proud.Message msg, out Nettention.Proud.FastArray<battleinfo> strMsg)
    {
        strMsg = new Nettention.Proud.FastArray<battleinfo>();
        int count = 0;
        msg.ReadScalar(ref count);

        battleinfo contain_items = new battleinfo();
        for (int i = 0; i < count; i++)
        {
            msg.ReadScalar(ref contain_items.curA);
            msg.ReadScalar(ref contain_items.totalA);
            msg.ReadScalar(ref contain_items.curB);
            msg.ReadScalar(ref contain_items.totalB);
            strMsg.Add(contain_items);
        }

        return true;
    }

    public static bool Read(Nettention.Proud.Message msg, out Nettention.Proud.FastArray<passiveskillinfo> strMsg)
    {
        strMsg = new Nettention.Proud.FastArray<passiveskillinfo>();
        int count = 0;
        msg.ReadScalar(ref count);

        passiveskillinfo contain_items = new passiveskillinfo();
        for (int i = 0; i < count; i++)
        {
            msg.ReadScalar(ref contain_items.passiveSlot1);
            msg.ReadScalar(ref contain_items.passiveSlot2);
            msg.ReadScalar(ref contain_items.passiveSlot3);
            msg.ReadScalar(ref contain_items.passiveSlot4);
            strMsg.Add(contain_items);
        }

        return true;
    }

    public static bool Read(Nettention.Proud.Message msg, out Nettention.Proud.FastArray<equipinfo> strMsg)
    {
        strMsg = new Nettention.Proud.FastArray<equipinfo>();
        int count = 0;
        msg.ReadScalar(ref count);

        equipinfo contain_items = new equipinfo();
        for (int i = 0; i < count; i++)
        {
            msg.ReadScalar(ref contain_items.equipslot1);
            msg.ReadScalar(ref contain_items.equipslot2);
            msg.ReadScalar(ref contain_items.equipslot3);
            msg.ReadScalar(ref contain_items.equipslot4);
            msg.ReadScalar(ref contain_items.equipslot5);
            msg.ReadScalar(ref contain_items.equipslot6);
            //msg.ReadScalar(ref contain_items.ActiveSkill_1_idx);
            //msg.ReadScalar(ref contain_items.ActiveSkill_2_idx);
            //msg.ReadScalar(ref contain_items.ActiveSkill_3_idx);
            //msg.ReadScalar(ref contain_items.ActiveSkill_4_idx);
            //msg.ReadScalar(ref contain_items.PassiveSkill_1_idx);
            //msg.ReadScalar(ref contain_items.PassiveSkill_2_idx);
            //msg.ReadScalar(ref contain_items.PassiveSkill_3_idx);
            //msg.ReadScalar(ref contain_items.PassiveSkill_4_idx);
            strMsg.Add(contain_items);
        }

        return true;
    }
}



