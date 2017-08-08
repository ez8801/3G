/* 
 * UIInventory.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */
 
using UnityEngine;
using System.Collections.Generic;

public class UIInventory : UIBase
{
	[System.Serializable]
	public struct View
	{
		public UIEventListener BtnDetail;
		public UILabel LblName;
		public Transform GridEquip;
		public UIEventListener BtnClose;
		public UILabel LblItemCount;
		public UIEventListener BtnSort;
		public UILabel LblSort;
		public UIEventListener BtnAllSell;
		public UILabel LblAllSell;
		public UIEventListener BtnAutoEquip;
		public GameObject WidgetBadge;
		public UILabel LblAutoEquip;
		public Transform TabHost;
		public Transform ScrollView;
		public UIAdvancedGrid Grid;
        public UIItemDetailView LeftItemDetailView;
        public UIItemDetailView RightItemDetailView;
	}
	public View m_view;

    private int m_currentTabIndex;
    private bool[] m_isDirtyFlags = new bool[0];
    private List<UserData.Item> m_selectedItems = new List<UserData.Item>();

	public override void Initialize()
	{
        BindComponents();

        m_currentTabIndex = 0;

        m_view.Grid.DataSource = CellForRowAtIndex;
        m_view.Grid.Delegate = NumberOfRowsInGrid;
        m_view.BtnClose.onClick = OnClickClose;
    }

    [ContextMenu("Bind")]
    private void BindComponents()
    {
        if (IsAssigned(m_view) == false)
            m_view = new View();
        this.Bind(ref m_view.BtnDetail, "HeaderView/BtnDetail");
        this.Bind(ref m_view.LblName, "HeaderView/LblName");
        this.Bind(ref m_view.GridEquip, "GridEquip");
        this.Bind(ref m_view.BtnClose, "BtnClose");
        this.Bind(ref m_view.LblItemCount, "LblItemCount");
        this.Bind(ref m_view.BtnSort, "BtnSort");
        this.Bind(ref m_view.LblSort, "BtnSort/LblSort");
        this.Bind(ref m_view.BtnAllSell, "BtnAllSell");
        this.Bind(ref m_view.LblAllSell, "BtnAllSell/LblAllSell");
        this.Bind(ref m_view.BtnAutoEquip, "BtnAutoEquip");
        this.Bind(ref m_view.WidgetBadge, "BtnAutoEquip/WidgetBadge");
        this.Bind(ref m_view.LblAutoEquip, "BtnAutoEquip/LblAutoEquip");
        this.Bind(ref m_view.TabHost, "TabHost");
        this.Bind(ref m_view.ScrollView, "ScrollView");
        this.Bind(ref m_view.Grid, "ScrollView/Grid");
        this.Bind(ref m_view.LeftItemDetailView, "LeftView/ItemDetailView");
        this.Bind(ref m_view.RightItemDetailView, "RightView/ItemDetailView");
    }

    public override void ReloadData()
    {
        base.ReloadData();
        
        m_view.LblName.SetTextSafely(StringEx.Format("Lv.{0} {1}"
            , MyInfo.Account.Level
            , MyInfo.Account.NickName));

        if (CollectionEx.IsNullOrEmpty(m_isDirtyFlags))
            m_isDirtyFlags = new bool[m_view.TabHost.childCount];

        List<UserData.Item> totalItems = MyInfo.Inventory.GetItemList();
        for (int i = 0; i < totalItems.Count; i++)
        {
            UserData.Item match = totalItems[i];
            if (MyInfo.Inventory.GetDirty(match.Id))
            {
                Data.Item itemData = ItemTable.Instance.Find(match.ItemId);
                int tabId = GetTabId((ItemCategory)itemData.Category);
                m_isDirtyFlags[tabId] = true;
            }
        }
        
        SetEquipSlots();
        SetItemCount(MyInfo.Inventory.Count, NumberOfRowsInGrid());
        SetTabHost();
        m_view.Grid.ReloadData();
    }

    public void SetItemCount(int itemCount, int capacity)
    {
        m_view.LblItemCount.SetTextSafely(StringEx.Format("{0}/{1}", itemCount, capacity));
    }

    public void SetEquipSlots()
    {
        for (int i = 0; i < m_view.GridEquip.childCount; i++)
        {
            Transform child = m_view.GridEquip.GetChild(i);
            UIItemCell itemCellUI = Util.FindInChildren<UIItemCell>(child);
            int itemSlot = i + 1;
            itemCellUI.Initialize();
            
            if (itemSlot < ItemSlot.Max)
            {
                UserData.Item equippedItem = MyInfo.Inventory.GetEquipItem(itemSlot);
                if (equippedItem != null)
                {
                    itemCellUI.InitWithData(equippedItem);
                    itemCellUI.SetOnClickListener(OnClickEquipItem);
                }
                else
                {
                    itemCellUI.Disable();
                }
            }
            else
            {
                child.SetActiveSafely(false);
            }
        }
    }

    public void SetTabHost()
    {
        int tabCount = GetTabCount();
        for (int i = 0; i < m_view.TabHost.childCount; i++)
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
                    m_selectedItems = MyInfo.Inventory.FindAll(IsMatchItem);
            }
        }
    }

    public string GetTabName(int tabIndex)
    {
        string key = StringEx.Format("UI.Inventory.Tab.Name.{0}", tabIndex);
        return R.String.GetText(key);
    }

    public int GetTabCount()
    {
        return 3;
    }

    public int GetTabId(ItemCategory itemCategory)
    {
        switch (itemCategory)
        {
            case ItemCategory.Weapon:
                return 0;
            case ItemCategory.Armor:
                return 1;
            case ItemCategory.Material:
            case ItemCategory.Misc:
                return 2;
        }
        return 0;
    }

    public bool IsMatchItem(UserData.Item match)
    {
        Data.Item itemData = ItemTable.Instance.Find(match.ItemId);
        int tabId = GetTabId((ItemCategory)itemData.Category);        
        return (m_currentTabIndex == tabId);
    }

    //-------------------------------------------------------------------------
    //  DataSource & Delegate
    //-------------------------------------------------------------------------
    #region DataSource & Delegate

    public Transform CellForRowAtIndex(int index, GameObject contentView)
    {
        UIItemCell itemCellUI = Util.RequireComponent<UIItemCell>(contentView);
        itemCellUI.Initialize();

        if (index < m_selectedItems.Count)
        {
            UserData.Item item = m_selectedItems[index];
            itemCellUI.InitWithData(item);
            itemCellUI.SetOnClickListener(OnClickItem);
        }
        else
        {
            itemCellUI.Disable();
        }
        
        return null;
    }

    private int NumberOfRowsInGrid()
    {
        return R.Integer.GetInteger("InventoryBasicSlotAmount");
    }

    #endregion DataSource & Delegate
    
    //-------------------------------------------------------------------------
    //  UIActions
    //-------------------------------------------------------------------------
    #region UIActions

    private void OnClickClose(GameObject sender)
    {
        for (int i = 0; i < m_isDirtyFlags.Length; i++)
        {
            m_isDirtyFlags[i] = false;
        }
        MyInfo.Inventory.ClearDirtyFlag();
        NGUITools.SetActive(gameObject, false);
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

    private void OnClickItem(GameObject sender)
    {
        int index = -1;
        if (int.TryParse(sender.name, out index))
        {
            UserData.Item clickedItem = m_selectedItems[index];
            m_view.RightItemDetailView.Initialize();
            m_view.RightItemDetailView.InitWithData(clickedItem);
        }
    }

    private void OnClickEquipItem(GameObject sender)
    {
        int index = -1;        
        if (int.TryParse(sender.transform.parent.name, out index))
        {
            UserData.Item equippedItem = MyInfo.Inventory.GetEquipItem(index + 1);
            m_view.LeftItemDetailView.Initialize();
            m_view.LeftItemDetailView.InitWithData(equippedItem);
        }
    }

    #endregion UIActions
}
