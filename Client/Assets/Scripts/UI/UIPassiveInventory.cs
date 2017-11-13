/* 
 * UIPassiveInventory.cs
 * 
 * Writer : user
 * Date   : 2017-08-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections.Generic;

/// <summary>
/// 페시브 인벤토리
/// </summary>
/// <seealso cref="UIType.UIPassiveInventory"/>
public class UIPassiveInventory : UIBase
{
    
    [System.Serializable]
    public struct View
    {
        public Transform GridEquip;
        public UIEventListener BtnClose;
        public UIPassiveDetailView PassiveDetailView;
        public Transform TabHost;
        public Transform ScrollView;
        public UIAdvancedGrid Grid;
    }
    public View m_view;

    private int m_currentTabIndex;
    private bool[] m_isDirtyFlags = new bool[0];
    private List<UserData.PassiveSkill> m_selectedPassives = new List<UserData.PassiveSkill>();
    
    internal override void OnCreate()
    {
        base.OnCreate();
        BindComponents();

        m_currentTabIndex = 0;

        m_view.Grid.DataSource = CellForRowAtIndex;
        m_view.Grid.Delegate = NumberOfRowsInGrid;
        m_view.BtnClose.onClick = OnClickClose;
    }

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        if (IsAssigned(m_view) == false) m_view = new View();
        this.Bind(ref m_view.GridEquip, "GridEquip");
        this.Bind(ref m_view.BtnClose, "BtnClose");
        this.Bind(ref m_view.PassiveDetailView, "PassiveDetailView");
        this.Bind(ref m_view.TabHost, "TabHost");
        this.Bind(ref m_view.ScrollView, "ScrollView");
        this.Bind(ref m_view.Grid, "ScrollView/Grid");
    }

    public override void ReloadData()
    {
        base.ReloadData();

        if (CollectionEx.IsNullOrEmpty(m_isDirtyFlags)) m_isDirtyFlags = new bool[m_view.TabHost.childCount];
        List<UserData.PassiveSkill> totalPassives = MyInfo.PassiveInventory.GetPassiveList();
        for(int i = 0; i < totalPassives.Count; i++)
        {
            UserData.PassiveSkill match = totalPassives[i];
            if(MyInfo.PassiveInventory.GetDirty(match.Id))
            {
                Data.PassiveSkill passiveData = PassiveSkillTable.Instance.Find(match.PassiveId);
                int tabId = GetTabId((PassiveType)passiveData.Type);
                m_isDirtyFlags[tabId] = true;
            }
        }

        SetEquipSlots();
        SetTabHost();
        m_view.Grid.ReloadData();
        
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
                else
                {
                    passiveCellUI.Disable();
                }
            }
        }
    }


    public void SetTabHost()
    {
        int tabCount = GetTabCount();
        for(int i = 0; i<m_view.TabHost.childCount; i++)
        {
            Transform child = m_view.TabHost.GetChild(i);
            child.SetActiveSafely(i < tabCount);

            Transform badge = Util.FindComponent<Transform>(child, "WidgetBadge");
            badge.SetActiveSafely(m_isDirtyFlags[i]);

            if (i < tabCount)
            {
                bool isSelected = (m_currentTabIndex == i);

                UILabel lblTab = Util.FindComponent<UILabel>(child, "LblTab", true);
                string tabName = GetTabName(i);
                lblTab.SetTextSafely(tabName);

                UISprite sprTab = Util.FindComponent<UISprite>(child, "SprTab", true);
                sprTab.SetSpriteSafely(R.Drawable.GetTabSprite(isSelected), false);

                if (isSelected)
                    m_selectedPassives = MyInfo.PassiveInventory.FindAll(IsMatchPassive);
            }


        }
    }

    public bool IsMatchPassive(UserData.PassiveSkill match)
    {
        Data.PassiveSkill passiveData = PassiveSkillTable.Instance.Find(match.PassiveId);
        int tabId = GetTabId((PassiveType)passiveData.Type);
        return (m_currentTabIndex == tabId);
    }

    public string GetTabName(int tabIndex)
    {
        string key = StringEx.Format("UI.Passiveinventory.Tab.Name.{0}", tabIndex);
        return R.GetText(key);
    }

    public int GetTabCount()
    {
        return 7;
    }

    public int GetTabId(PassiveType passiveType)
    {
        switch (passiveType)
        {
            case PassiveType.Common:
                return 0;
            case PassiveType.Staff:
                return 1;
            case PassiveType.Gem:
                return 2;
            case PassiveType.Shield:
                return 3;
            case PassiveType.Sword:
                return 4;
            case PassiveType.Spear:
                return 5;
            case PassiveType.Bow:
                return 6;
        }
        return 0;
    }
    
    #region DataSource & Delegate

    public Transform CellForRowAtIndex(int index, GameObject contentView)
    {
        UIPassiveCell passiveCellUI = Util.RequireComponent<UIPassiveCell>(contentView);
        passiveCellUI.Initialize();

        if(index < m_selectedPassives.Count)
        {
            UserData.PassiveSkill passive = m_selectedPassives[index];
            passiveCellUI.InitWithData(passive);
            passiveCellUI.SetOnClickListener(OnClickPassive);
        }
        else
        {
            passiveCellUI.Disable();
        }

        return null;
    }

    private int NumberOfRowsInGrid()
    {
        return R.Integer.GetInteger("InventoryBasicSlotAmount");
    }

    #endregion DataSource & Delegate

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
            m_view.PassiveDetailView.Show();
            m_view.PassiveDetailView.SetData(equippedPassive);
        }
    }
    public void OnClickTab(GameObject sender)
    {
        int index = -1;
        if (int.TryParse(sender.name, out index))
        {
            if (index != m_currentTabIndex)
            {
                m_currentTabIndex = index;
                SetTabHost();
                m_view.Grid.ReloadData();
            }
        }
    }

    private void OnClickPassive(GameObject sender)
    {
        int index = -1;
        if(int.TryParse(sender.name, out index))
        {
            UserData.PassiveSkill clickedPassive = m_selectedPassives[index];
            m_view.PassiveDetailView.Show();
            m_view.PassiveDetailView.SetData(clickedPassive);
        }
    }

    #endregion UIActions
}