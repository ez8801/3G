/* 
 * UIPvpMakeRoom.cs
 * 
 * Writer : user
 * Date   : 2017-10-30
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class UIPvpMakeRoom : UIBase 
{
    private Client m_client;
    //나가기 버튼
    [System.Serializable]
    public struct View
    {
        public GameObject BtnMake;
        public GameObject BtnOut;
        public UILabel LblGetText;
        public UIPvpRoom PvpRoom;
    }
    public View m_view;

    private SimplePvpRoom m_newRoom;

    internal override void OnStart()
    {
        m_client = Client.Instance;
        base.OnStart();
        BindComponents();
        //텍스트 부분 초기화 추가 필요. + 따로 함수로 텍스트필드 만드는 방법.
    }
    

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        this.Bind(ref m_view.BtnMake, "BtnMakeRoom");
        this.Bind(ref m_view.BtnOut, "BtnOut");
        this.Bind(ref m_view.PvpRoom, "PvpRoom");
    }


    public void SendText()
    {
        //서버로 전송.
        //리턴값은 만든 텍스트(이름)과 아이디(몇번째인지 방 번호) 등등이 포함된 심플 룸 정보.
    }

    public void OnClickClose()
    {
        Hide();
    }

    public void OnClickMakeRoom()
    {
        //m_newRoom = 
        SendText();

        Hide();
        
        Debug.Log("RoomMake");
        string m_MakeRoomName = "아무이름";
        Debug.Log("RoomName : " + m_MakeRoomName);
        m_client.RequestMakePVPRoom(Nettention.Proud.HostID.HostID_Server, Nettention.Proud.RmiContext.UnreliableSend, MyInfo.Account.LocalHost, MyInfo.Account.NickName, m_MakeRoomName);
        //GameObject.Find("PvpUI").GetComponent<UIPvp>().Hide();
        //GameObject.Find("LobbyUI").GetComponent<UILobby>().CallPvpRoom(2, m_MakeRoomName);


        //무엇인가 심플룸을 센드 텍스트로 리턴 받아서..
        //방만드는 함수에 정보를 집어넣어서 열면댐.



    }
}