/* 
 * UIPassiveInventory.cs
 * 
 * Writer : user
 * Date   : 2017-08-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class UIPassiveInventory : UIBase
{
    [System.Serializable]
    public struct View
    {
        public Transform GridEquip;
        public UIEventListener BtnClose;
        public UIPassiveDetailView DetailView;
        public Transform ScrollView;
        public UIAdvancedGrid Grid;
    }
    public View m_view;

    private int m_currentTabIndex;
    private bool[] m_isDirtyFlags = new bool[0];
    private List<UserData.PassiveSkill> m_selectedPassives = new List<UserData.PassiveSkill>();

    public override void Initialize()
    {
        base.Initialize();

        m_currentTabIndex = 0;
        
        //
        //

        //
        //

    }

    [ContextMenu("Bind")]
    private void BindComponents()
    {
        if (IsAssigned(m_view) == false) m_view = new View();
        this.Bind(ref m_view.GridEquip, "GridEquip");
        this.Bind(ref m_view.BtnClose, "BtnClose");
        this.Bind(ref m_view.DetailView, "DetailView");
        this.Bind(ref m_view.ScrollView, "ScrollView");
        this.Bind(ref m_view.Grid, "ScrollView/Grid");
    }

    public override void ReloadData()
    {
        base.ReloadData();

        //
        //
        ///
        ///
        ///
        ///
        //
        ///
    }

    public void SetEquipSlots()
    {
        for(int i = 0; i < m_view.GridEquip.childCount; i++)
        {
            Transform child = m_view.GridEquip.GetChild(i);
            UIPassiveCell passiveCellUI = Util.FindInChildren<UIPassiveCell>(child);
            int passiveSlot = i + 1;
            passiveCellUI.Initialize();

            if(passiveSlot < SkillSlot.Max)
            {
                UserData.PassiveSkill equippedPassive = MyInfo.PassiveInventory.GetEquipPassive(passiveSlot);
                if(equippedPassive != null)
                {
                    passiveCellUI.InitWithData(equippedPassive);
                    passiveCellUI.SetOnClickListener(OnClickEquipPassive);
                }
            }
        }
    }







    #region UIActions

    public void OnClickClose(GameObject sender)
    {
        for(int i = 0; i < m_isDirtyFlags.Length; i++)
        {
            m_isDirtyFlags[i] = false;
        }
        MyInfo.Inventory.ClearDirtyFlag();
        NGUITools.SetActive(gameObject, false);
    }

    private void OnClickEquipPassive(GameObject sender)
    {
        int index = -1;
        if(int.TryParse(sender.transform.parent.name, out index))
        {
            UserData.PassiveSkill equippedPassive = MyInfo.PassiveInventory.GetEquipPassive(index + 1);
            m_view.DetailView.Initialize();
            m_view.DetailView.InitWithData(equippedPassive);
        }
    }

    private void OnClickPassive(GameObject sender)
    {
        int index = -1;
        if(int.TryParse(sender.name, out index))
        {
            UserData.PassiveSkill clickedPassive = m_selectedPassives[index];
            m_view.DetailView.Initialize();
            m_view.DetailView.InitWithData(clickedPassive);
        }
    }

    #endregion UIActions
}