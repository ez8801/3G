/* 
 * UIInventory.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

public class UIInventory : UIBase
{
	[System.Serializable]
	public struct View
	{
		public UIEventListener BtnDetail;
		public Transform LblName;
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
	}
	public View m_view;

	public override void Initialize()
	{
        BindComponents();

        m_view.BtnClose.onClick = OnClickClose;
    }

    [ContextMenu("Bind")]
    private void BindComponents()
    {
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
    }

    public override void ReloadData()
    {
        base.ReloadData();
        m_view.Grid.DataSource = CellForRowAtIndex;
        m_view.Grid.Delegate = NumberOfRowsInGrid;
    }
    
    public Transform CellForRowAtIndex(int index, GameObject contentView)
    {
        UIItemCell itemCellUI = Util.RequireComponent<UIItemCell>(contentView);

        return null;
    }

    private int NumberOfRowsInGrid()
    {
        return ConfigTable.Instance.Find(2).Value;
    }

    //-------------------------------------------------------------------------
    //  UIActions
    //-------------------------------------------------------------------------
    #region UIActions

    private void OnClickClose(GameObject sender)
    {
        NGUITools.SetActive(gameObject, false);
    }

    #endregion UIActions
}
