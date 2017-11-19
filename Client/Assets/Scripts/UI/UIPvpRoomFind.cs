/* 
 * UIPvpRoomFind.cs
 * 
 * Writer : user
 * Date   : 2017-10-30
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class UIPvpRoomFind : UIBase 
{

    // 그리드에 리스트, 서버로부터 데이타 가져오는 SetData, 등등
    [System.Serializable]
    public struct View
    {
        public GameObject BtnClose;
        public GameObject BtnAttend;
        public UIAdvancedGrid Grid;
    }
    public View m_view;


    private int m_selectedRoomIndex;

    public List<SimplePvpRoom> m_pvpRooms;

    internal override void OnCreate()
    {
        base.OnCreate();
        BindComponents();

        m_pvpRooms = new List<SimplePvpRoom>();

        m_view.Grid.DataSource = RoomCellForRowAtIndex;
        m_view.Grid.Delegate = NumberOfRowInRecipeGrid;
    }

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        if (IsAssigned(m_view))
            m_view = new View();
        this.Bind(ref m_view.BtnClose, "BtnClose");
        this.Bind(ref m_view.BtnAttend, "BtnAttend");
        this.Bind(ref m_view.Grid, "ScrollView/Grid");

    }

    internal override void OnStart()
    {
        base.OnStart();
        ReloadData();
        
    }

    public override void ReloadData()
    {
        base.ReloadData();
        m_view.Grid.DataSource = RoomCellForRowAtIndex;
        m_view.Grid.Delegate = NumberOfRowInRecipeGrid;
        m_view.Grid.ReloadData();
        // 방의 정보 읽어와서 m_isFull 이 사실이면 참가 버튼 비활성화.

    }









    public void SetData(List<SimplePvpRoom> list)
    {
        m_pvpRooms = list;
        Debug.Log("list 1 :" + list[0].RoomName);
    }


    #region DataSource & Delegate

    private int NumberOfRowInRecipeGrid()
    {
        return m_pvpRooms.Count;
    }

    private Transform RoomCellForRowAtIndex(int index, GameObject contentView)
    {
        SimplePvpRoom room = m_pvpRooms[index];
        UIPvpRoomCell pvpRoomCell = Util.RequireComponent<UIPvpRoomCell>(contentView);
        pvpRoomCell.Initilize();
        Debug.Log("Room Cell For Row At Index");
        pvpRoomCell.SetSelection(room.Id == m_selectedRoomIndex);
        pvpRoomCell.SetData(room);
        pvpRoomCell.SetOnClickListener(OnClickRoom);


        return null;
    }


    #endregion DataSource & Delegate

    #region UIActions
    private void OnClickRoom(GameObject sender)
    {
        int index = -1;
        int.TryParse(sender.name, out index);

        m_selectedRoomIndex = m_pvpRooms[index].RoomId;
        

        ReloadData();
    }

    public void OnClickAttend()
    {
        //참가 후 서버에서 대전자 정보 불러와서 대기방 or 배틀씬으로

    }


    public void OnClickClose()
    {
        Hide();
    }
    #endregion UIActions
}