/* 
 * UIActiveEquipView.cs
 * 
 * Writer : user
 * Date   : 2017-10-08
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class UIActiveEquipView : UIBase 
{
    [System.Serializable]
    public struct View
    {
        public UILabel LblItemCount;
        public GameObject BtnEquip;
        public Transform TabHost;
        public UIAdvancedGrid Grid;
        public Transform Btn0;
        public UIItemCell SelectItemCell;
        public Transform PanelCell;
    }
    public View m_view;

    private SimpleItem m_selectedItem;
    private List<Data.Skill> m_actives;

    internal override void OnCreate()
    {
        base.OnCreate();
        BindComponents();
        
        //정렬 추가해야함
    }

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        if (!IsAssigned(m_view))
            m_view = new View();
        this.Bind(ref m_view.LblItemCount, "RightView/LblItemCount");
        this.Bind(ref m_view.BtnEquip, "LeftView/BtnEquip");
        this.Bind(ref m_view.TabHost, "RightView/TabHost");
        this.Bind(ref m_view.Grid, "RightView/PanelClip/Grid");
        this.Bind(ref m_view.Btn0, "LeftView/ButtonGroup/Btn0");
        this.Bind(ref m_view.SelectItemCell, "LeftView/SelectItemCell");
        this.Bind(ref m_view.PanelCell, "LeftView/PanelCell");
    }

    public override void ReloadData()
    {
        base.ReloadData();

        SetItemCount(MyInfo.Inventory.Count, NumberOfRowsInGrid());
        m_view.Grid.ReloadData();
    }

    public void SetItemCount(int itemCount, int capacity)
    {
        m_view.LblItemCount.SetTextSafely(StringEx.Format("{0}/{1}", itemCount, capacity));
    }

    private int NumberOfRowsInGrid()
    {
        return R.Integer.GetInteger("InventoryBasicSlotAmount");
    }




}