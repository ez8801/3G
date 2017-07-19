/* 
 * UIInventory.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using R;
using UnityEngine;

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

        SetEquipSlots();
        SetItemCount(MyInfo.Inventory.Count, NumberOfRowsInGrid());
        m_view.Grid.ReloadData();
        SetTabHost();
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
            itemCellUI.Initialize();
            itemCellUI.Disable();
        }
    }

    public void SetTabHost()
    {
        int tabCount = GetTabCount();
        for (int i = 0; i < m_view.TabHost.childCount; i++)
        {
            Transform child = m_view.TabHost.GetChild(i);
            child.SetActiveSafely(i < tabCount);

            if (i < tabCount)
            {
                bool isSelected = (m_currentTabIndex == i);

                UILabel lblTab = Util.FindComponentByName<UILabel>(child, "LblTab", true);
                string tabName = GetTabName(i);
                lblTab.SetTextSafely(tabName);

                UISprite sprTab = Util.FindComponentByName<UISprite>(child, "SprTab", true);
                sprTab.SetSpriteSafely(Drawable.GetTabSprite(isSelected), false);
            }
        }
    }

    public string GetTabName(int tabIndex)
    {
        string key = StringEx.Format("UI.Inventory.Tab.Name.{0}", tabIndex);
        return String.GetText(key);
    }

    public int GetTabCount()
    {
        return 3;
    }

    //-------------------------------------------------------------------------
    //  DataSource & Delegate
    //-------------------------------------------------------------------------
    #region DataSource & Delegate

    public Transform CellForRowAtIndex(int index, GameObject contentView)
    {
        UIItemCell itemCellUI = Util.RequireComponent<UIItemCell>(contentView);
        itemCellUI.Initialize();

        if (index < MyInfo.Inventory.Count)
        {
            UserData.Item item = MyInfo.Inventory[index];
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
        return Integer.GetInteger("InventoryBasicSlotAmount");
    }

    #endregion DataSource & Delegate
    
    //-------------------------------------------------------------------------
    //  UIActions
    //-------------------------------------------------------------------------
    #region UIActions

    private void OnClickClose(GameObject sender)
    {
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
            }
        }
    }

    private void OnClickItem(GameObject sender)
    {
        int index = -1;
        if (int.TryParse(sender.name, out index))
        {
            UserData.Item clickedItem = MyInfo.Inventory[index];
            m_view.RightItemDetailView.Initialize();
            m_view.RightItemDetailView.InitWithData(clickedItem);
        }
    }

    #endregion UIActions
}
