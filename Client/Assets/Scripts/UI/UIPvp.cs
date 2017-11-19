/* 
 * UIPvp.cs
 * 
 * Writer : user
 * Date   : 2017-10-30
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public struct SimplePvpRoom
{
    public long Id;
    public int RoomId;
    public string RoomName;
}


public class UIPvp : UIBase 
{
	[System.Serializable]
    public struct View
    {
        public GameObject BtnAutoMatch;
        public GameObject BtnMakeRoom;
        public GameObject BtnFindRoom;
        public UIPvpMakeRoom PvpMakeRoom;
        public UIPvpRoomFind PvpRoomFind;
    }
    public View m_view;

    public List<SimplePvpRoom> m_findRooms;
    

    internal override void OnCreate()
    {
        m_findRooms = new List<SimplePvpRoom>();
        base.OnCreate();
        BindComponents();
    }

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        if (IsAssigned(m_view) == false)
            m_view = new View();
        this.Bind(ref m_view.BtnAutoMatch, "MainView/BtnAutoMatch");
        this.Bind(ref m_view.BtnMakeRoom, "MainView/BtnMakeRoom");
        this.Bind(ref m_view.BtnFindRoom, "MainView/BtnFindRoom");
        this.Bind(ref m_view.PvpMakeRoom, "MiddleView/PvpMakeRoom");
        this.Bind(ref m_view.PvpRoomFind, "MiddleView/PvpRoomFind");
    }

    public void GetNewRoomList()
    {
        //m_findRooms에 서버에서 리스트 받을필요 있음
        //임의 리스트
        m_findRooms = new List<SimplePvpRoom>();
        SimplePvpRoom roomone = new SimplePvpRoom();
        roomone.Id = 0;
        roomone.RoomId = 1;
        roomone.RoomName = "today";
        Debug.Log("this time one");
        Debug.Log(roomone.RoomName);
        m_findRooms.Add(roomone);
        Debug.Log("this time two");
    }

    #region UIActions

    public void OnClickClose()
    {
        Hide();
    }

    public void OnClickAutoMatch()
    {
        //자동 매칭 터치시 이벤트 작성
        //서버에 매칭 정보 받아옴
        //이후 등급전 pvp 씬으로 이동
    }

    public void OnClickMakeRoom()
    {
        m_view.PvpMakeRoom.Show();
        
    }

    public void OnClickRoomFind()
    {
        GetNewRoomList(); // 서버에서 리스트 겟
        m_view.PvpRoomFind.SetData(m_findRooms);
        m_view.PvpRoomFind.Show();
    }//10-30 11:45 --> 프리팹에 리스트랑 이름입력창 만들고 코딩, 로그인창 제작

    # endregion UIActions





}
