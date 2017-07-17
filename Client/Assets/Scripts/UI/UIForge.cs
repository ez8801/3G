using UnityEngine;

public class UIForge : UIBase
{
	[System.Serializable]
	public struct View
	{
		public UILabel LblItemCount;
		public GameObject BtnSort;
		public GameObject BtnAutoSelect;
		public Transform TabHost;
		public UIAdvancedGrid Grid;
		public Transform Btn0;
		public UIAdvancedGrid RecipeGrid;
		public GameObject BtnFilter;
		public GameObject BtnMaking;
		public UILabel LblPrice;
		public Transform PanelCell;
	}
	public View m_view;

    private int m_selectedIndex;

    public override void Initialize()
    {
        base.Initialize();

        BindComponents();

        m_view.Grid.DataSource = CellForRowAtIndex;
        m_view.Grid.Delegate = NumberOfRowsInGrid;
    }

    [ContextMenu("Bind")]
	public void BindComponents()
	{
        if (!IsAssigned(m_view))
		    m_view = new View();
		this.Bind(ref m_view.LblItemCount, "RightView/LblItemCount");
		this.Bind(ref m_view.BtnSort, "RightView/BtnSort");
		this.Bind(ref m_view.BtnAutoSelect, "RightView/BtnAutoSelect");
		this.Bind(ref m_view.TabHost, "RightView/TabHost");
		this.Bind(ref m_view.Grid, "RightView/PanelClip/Grid");
		this.Bind(ref m_view.Btn0, "LeftView/ButtonGroup/Btn0");
		this.Bind(ref m_view.RecipeGrid, "LeftView/PanelClip/RecipeGrid");
		this.Bind(ref m_view.BtnFilter, "LeftView/BtnFilter");
		this.Bind(ref m_view.BtnMaking, "LeftView/BtnMaking");
		this.Bind(ref m_view.LblPrice, "LeftView/BtnMaking/LblCount");
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

    //-------------------------------------------------------------------------
    //  DataSource & Delegate
    //-------------------------------------------------------------------------
    #region DataSource & Delegate

    private Transform CellForRowAtIndex(int index, GameObject contentView)
    {
        UIItemCell itemCellUI = Util.RequireComponent<UIItemCell>(contentView);
        itemCellUI.Initialize();

        if (index < MyInfo.Inventory.Count)
        {
            UserData.Item item = MyInfo.Inventory[index];
            itemCellUI.InitWithData(item);
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

    /// <summary>
    /// 레시피 선택
    /// </summary>
    private void OnClickRecipe(GameObject sender)
    {

    }

    public void OnClickAutoSelect()
    {

    }

    /// <summary>
    /// 제작 버튼 클릭
    /// </summary>
    public void OnClickMaking()
    {

    }

    /// <summary>
    /// 닫기 버튼 클릭
    /// </summary>
    public void OnClickClose()
    {
        NGUITools.SetActive(gameObject, false);
    }

    #endregion UIActions
}
