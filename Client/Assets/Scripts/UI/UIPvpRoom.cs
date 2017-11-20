/* 
 * UIPvpRoom.cs
 * 
 * Writer : user
 * Date   : 2017-11-18
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public struct SimplePlayer
{
    public int PlayerId;
    public string PlayerName;
    public bool IsReady;
}

public class UIPvpRoom : UIBase 
{
    private Client m_client;
    [System.Serializable]
    public struct View
    {
        public UILabel LblRoomName;
        public UILabel LblRoomNum;
        public UILabel LblFirstUserName;
        public UILabel LblFirstUserReady;
        public UILabel LblSecondUserName;
        public UILabel LblSecondUserReady;
        public GameObject BtnReady;
        public UILabel LblReady;
        public GameObject BtnCancle;
        public UILabel LblReadyCount;
    }
    public View m_view;

    //방에 들어온 유저 리스트
    private List<SimplePlayer> m_players;
    //레디한 유저 리스트
    private List<SimplePlayer> m_readyPlayers;

    public SimplePvpRoom thisRoom;

    public int PlayerValue;
    public int ReadyValue;

    public bool m_iFReady;
    public bool m_iSReady;

    internal override void OnCreate()
    {
        base.OnCreate();
        BindComponents();

        m_players = new List<SimplePlayer>();

        m_readyPlayers = new List<SimplePlayer>();
    }

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        if (!IsAssigned(m_view)) m_view = new View();
        this.Bind(ref m_view.LblRoomName, "TopView/LblRoomName");
        this.Bind(ref m_view.LblRoomNum, "TopView/LblRoomNum");
        this.Bind(ref m_view.LblFirstUserName, "BottomView/SprFirstUserName/LblFirstUserName");
        this.Bind(ref m_view.LblFirstUserReady, "BottomView/SprFirstUserName/LblFirstUserReady");
        this.Bind(ref m_view.LblSecondUserName, "BottomView/SprSecondUserName/LblSecondUserName");
        this.Bind(ref m_view.LblSecondUserReady, "BottomView/SprSecondUserName/LblSecondUserReady");
        this.Bind(ref m_view.BtnReady, "BottomView/BtnReady");
        this.Bind(ref m_view.LblReady, "BottomView/BtnReady/LblReady");
        this.Bind(ref m_view.BtnCancle, "BottomView/BtnCancle");
        this.Bind(ref m_view.LblReadyCount, "BottomView/LblReadyCount");
    }

    internal override void OnStart()
    {
        m_client = Client.Instance;
        base.OnStart();
        //서버에서 룸 인포 가져옴
        m_iFReady = false;
        m_iSReady = false;
        GetRoomInfo();
        Debug.Log("here Start");


        ReloadData();

    }

    public override void ReloadData()
    {
        base.ReloadData();
        Debug.Log("here ReLoadData");
        // Get Players 서버에서 플레이어 리스트 다시 받음
        // Get Ready 서버에서 레디한 플레이어 리스트 다시 받음
        // CheckReady 두사람이 들어왔고 두사람 다 레디 하였는지 체크.
        CheckReady();
    }

    public void SetMakeData(int roomNum, string roomName)
    {
        m_view.LblRoomNum.SetTextSafely(StringEx.Format("{0}", roomNum));
        m_view.LblRoomName.SetTextSafely(roomName);
    }
    public void GetRoomInfo()
    {
        //가져온 심플룸 정보를 thisRoom에 저장한다.
        m_view.LblRoomNum.SetTextSafely(StringEx.Format("{0}", thisRoom.RoomId));
        m_view.LblRoomName.SetTextSafely(thisRoom.RoomName);

        //m_players와 m_readyPlayers 의 정보를 받아옴.
    }

    public void CheckReady()
    {
        Debug.Log("here CheckReady");
        if (m_players.Count <= 0)
        {
            //방이 없어짐. 서버에 말해서 방 리스트에서 삭제.
        }
        m_view.LblReadyCount.SetTextSafely(StringEx.Format("{0} / {1}", m_readyPlayers.Count, m_players.Count));
        if(m_players.Count == 2 && m_players[0].IsReady == true && m_players[1].IsReady == true)
        {
            Debug.Log("PvP Battle_Start");
            //게임 스타트
        }
    }
    public void GetWhoReady(int readyPlayerId)
    {
        if(m_players[0].PlayerId == readyPlayerId)
        {
            m_view.LblFirstUserReady.SetActiveSafely(true);
            CheckReady();
        }
        if(m_players[1].PlayerId == readyPlayerId)
        {
            m_view.LblSecondUserReady.SetActiveSafely(true);
            CheckReady();
        }
    }


#region UIActions
    public void OnClickReady()
    {
        
        if (m_iFReady == false)
        {
            m_view.LblFirstUserReady.SetActiveSafely(true);//눌렀을때 레디 불 들어오는지 테스트임
                                                           //지워야하는거.
            m_view.LblReady.SetTextSafely("RELEASE");
            m_client.ReadyPacket(Nettention.Proud.RmiContext.ReliableSend, 1);
            m_iFReady = true;

            //여기는 현 클라이언트 사용자가 레디 하는것
        }
        else if (m_iFReady == true)
        {
            m_view.LblFirstUserReady.SetActiveSafely(false);
            m_view.LblReady.SetTextSafely("READY");
            m_client.ReadyPacket(Nettention.Proud.RmiContext.ReliableSend, 0);
            m_iFReady = false;
            //현 클라이언트 사용자가 레디 푸는것. 따로 서버 전송해야함.
            //여기 함수에서 하는 작업을 GetWhoReady로 올리고 여기선 서버 전송 작업으로 바꾸야함.

        }
            
        //여기서 서버로 유저 아이디와 레디 되었다는걸 보냄
    }

    public void FirstUserReady()
    {
        if (m_iFReady == false)
        {
            m_view.LblFirstUserReady.SetActiveSafely(true);//눌렀을때 레디 불 들어오는지 테스트임
                                                           //지워야하는거.
            m_view.LblReady.SetTextSafely("RELEASE");
            m_iFReady = true;

            //여기는 현 클라이언트 사용자가 레디 하는것
        }
        else if (m_iFReady == true)
        {
            m_view.LblFirstUserReady.SetActiveSafely(false);
            m_view.LblReady.SetTextSafely("READY");
            m_iFReady = false;
            //현 클라이언트 사용자가 레디 푸는것. 따로 서버 전송해야함.
            //여기 함수에서 하는 작업을 GetWhoReady로 올리고 여기선 서버 전송 작업으로 바꾸야함.

        }
    }
    public void SecondUserReady(int ready)
    {
        if (ready == 1)
        {
            m_view.LblSecondUserReady.SetActiveSafely(true);//눌렀을때 레디 불 들어오는지 테스트임
                                                           //지워야하는거.
            //m_view.LblReady.SetTextSafely("RELEASE");
            //m_iSReady = true;

            //여기는 현 클라이언트 사용자가 레디 하는것
        }
        else if (ready == 0)
        {
            m_view.LblSecondUserReady.SetActiveSafely(false);
            //m_view.LblReady.SetTextSafely("READY");
            //m_iSReady = false;
            //현 클라이언트 사용자가 레디 푸는것. 따로 서버 전송해야함.
            //여기 함수에서 하는 작업을 GetWhoReady로 올리고 여기선 서버 전송 작업으로 바꾸야함.

        }
    }



    public void OnClickCancle()
    {
        //서버에 나간 유저 ID보냄.
        //상대가 나갔으면 나갔다는걸 상대 한테 전송하고 리스트 갱신.
        if (MyInfo.Account.amIHost == true)
        {
            m_client.RequestLeavePVPRoom(Nettention.Proud.HostID.HostID_Server, Nettention.Proud.RmiContext.UnreliableSend, MyInfo.Account.LocalHost);
            MyInfo.Account.amIHost = false;
        }
        Hide();
    }
#endregion UIActions




    //아니면 아예 서버에서 클라이언트로 정보 받는 함수는 하나로 만들고
    //함수 호출 시 reloadData를 늘 불러서 방 UI정리를 해줘도 될 듯.
    //대신 이러면 하나 클릭할 때 마다 방 전체의 정보를 주고 받아야 할듯.

}