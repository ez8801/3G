using UnityEngine;
using System.Collections.Generic;

/// <summary>
/// 대장간 UI
/// </summary>
/// <seealso cref="UIType.UIForge"/>
/// <seealso cref="ForgeUI.prefab"/>
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
    private int m_selectedRecipeIndex;
    private List<Data.Material> m_materials;
    private List<SimpleItem> m_selecteItems;
    
    internal override void OnCreate()
    {
        base.OnCreate();
        BindComponents();

        m_selecteItems = new List<SimpleItem>();

        m_view.Grid.DataSource = CellForRowAtIndex;
        m_view.Grid.Delegate = NumberOfRowsInGrid;

        m_view.RecipeGrid.DataSource = RecipeCellForRowAtIndex;
        m_view.RecipeGrid.Delegate = NumberOfRowsInRecipeGrid;
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

    internal override void OnStart()
    {
        base.OnStart();
        ReloadData();
    }

    public override void ReloadData()
    {
        base.ReloadData();

        SetItemCount(MyInfo.Inventory.Count, NumberOfRowsInGrid());
        m_view.Grid.ReloadData();
        m_view.RecipeGrid.ReloadData();
        m_view.LblPrice.SetTextSafely(GetCost().ToString());
        UpdateMaterials();
    }

    public void SetItemCount(int itemCount, int capacity)
    {
        m_view.LblItemCount.SetTextSafely(StringEx.Format("{0}/{1}", itemCount, capacity));
    }

    public int GetCost()
    {
        if (m_selectedRecipeIndex == 0)
            return 0;
        return RecipeTable.Instance.Find(m_selectedRecipeIndex).CostGold;
    }

    public int GetSelectedCount(int groupId)
    {
        if (m_selecteItems != null)
        {
            int selectedCount = 0;
            for (int i = 0; i < m_selecteItems.Count; i++)
            {
                SimpleItem simpleItem = m_selecteItems[i];
                Data.Item itemData = ItemTable.Instance.Find(simpleItem.ItemId);
                if (itemData.ItemMaterialGroup == groupId)
                    selectedCount += simpleItem.Count;
            }
            return selectedCount;
        }
        return 0;
    }

    public bool IsMakable()
    {
        if (m_materials != null)
        {
            for (int i = 0; i < m_materials.Count; i++)
            {
                Data.Material match = m_materials[i];
                int selectedCount = GetSelectedCount(match.ItemMaterialGroup);
                if (match.RequestCount > selectedCount)
                    return false;
            }
            return true;
        }
        return false;
    }

    public bool IsSelectRecipe()
    {
        if (m_selectedRecipeIndex == 0 || Util.IsNullOrEmpty(m_materials))
        {
            // @TODO: Translation
            UIAlertView.Show(UIAlertView.Style.OK, string.Empty, "레시피를 선택해주세요.");
            return false;
        }

        return true;
    }

    private void UpdateMaterials()
    {        
        Data.Recipe selectedRecipe = RecipeTable.Instance.Find(m_selectedRecipeIndex);
        m_materials = MaterialTable.Instance.GetMaterials(selectedRecipe.MaterialGroupId);

        int materialCount = (m_materials != null) ? m_materials.Count : 0;
        for (int i = 0; i < m_view.PanelCell.childCount; i++)
        {
            Transform child = m_view.PanelCell.GetChild(i);
            child.SetActiveSafely(i < materialCount);

            UIItemCell itemCellUI = Util.FindInChildren<UIItemCell>(child);
            itemCellUI.Initialize();
            if (i < materialCount)
            {
                Data.Material material = m_materials[i];
                Data.Item materialItem = ItemTable.Instance.GetMaterialItem(material.ItemMaterialGroup);
                int selectedCount = GetSelectedCount(material.ItemMaterialGroup);
                itemCellUI.SetSelection(selectedCount == material.RequestCount);
                itemCellUI.SetData(0, materialItem.Id, selectedCount, material.RequestCount);
            }
            else
            {
                itemCellUI.Disable();
            }
        }
    }

    /// <summary>
    /// 이 함수는 임시 함수로 서버 연동후엔 삭제 예정
    /// </summary>
    private void ConsumeItem()
    {
        for (int i = 0; i < m_selecteItems.Count; i++)
        {
            SimpleItem each = m_selecteItems[i];
            MyInfo.Inventory.ConsumeItem(each.Id, each.Count);
        }
        m_selecteItems.Clear();
    }

    private void AddItem(int resultItemId)
    {
        MyInfo.Inventory.AddItem(resultItemId);
    }

    //-------------------------------------------------------------------------
    //  DataSource & Delegate
    //-------------------------------------------------------------------------
    #region DataSource & Delegate

    private Transform RecipeCellForRowAtIndex(int index, GameObject contentView)
    {
        Data.Recipe recipe = RecipeTable.Instance[index];
        UIRecipeCell recipeCellUi = Util.RequireComponent<UIRecipeCell>(contentView);
        recipeCellUi.Initialize();
        recipeCellUi.SetSelection(recipe.Id == m_selectedRecipeIndex);
        recipeCellUi.SetData(recipe);
        recipeCellUi.SetOnClickListener(OnClickRecipe);

        return null;
    }

    private int NumberOfRowsInRecipeGrid()
    {
        return RecipeTable.Instance.Count;
    }

    private Transform CellForRowAtIndex(int index, GameObject contentView)
    {
        UIItemCell itemCellUI = Util.RequireComponent<UIItemCell>(contentView);
        itemCellUI.Initialize();

        if (index < MyInfo.Inventory.Count)
        {
            UserData.Item item = MyInfo.Inventory[index];
            itemCellUI.SetData(item);
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

    /// <summary>
    /// 아이템 선택
    /// </summary>
    /// <param name="sender"></param>
    private void OnClickItem(GameObject sender)
    {
        if (!IsSelectRecipe())
            return;

        int index = -1;
        if (!int.TryParse(sender.name, out index))
        {
            Debug.LogWarning(StringEx.Format("Couldn't Parse : {0}", sender.name));
            return;
        }
        
        UserData.Item selectedItem = MyInfo.Inventory[index];
        Data.Item itemData = ItemTable.Instance.Find(selectedItem.ItemId);
            
        for (int i = 0; i < m_materials.Count; i++)
        {
            Data.Material match = m_materials[i];
            if (match.ItemMaterialGroup != itemData.ItemMaterialGroup)
                continue;
                
            int selectedCount = GetSelectedCount(match.ItemMaterialGroup);

            // 이미 모든 재료를 등록한 경우
            if (selectedCount >= match.RequestCount)
            {
                continue;
            }
            else
            {
                int requireCount = match.RequestCount - selectedCount;
                if (selectedItem.Count > requireCount)
                {
                    SimpleItem materialItem = new SimpleItem();
                    materialItem.Id = selectedItem.Id;
                    materialItem.ItemId = selectedItem.ItemId;
                    materialItem.Count = requireCount;
                    m_selecteItems.Add(materialItem);
                }
                else
                {
                    SimpleItem materialItem = new SimpleItem();
                    materialItem.Id = selectedItem.Id;
                    materialItem.ItemId = selectedItem.ItemId;
                    materialItem.Count = selectedItem.Count;
                    m_selecteItems.Add(materialItem);
                }
            }
        }

        ReloadData();
    }

    /// <summary>
    /// 레시피 선택
    /// </summary>
    private void OnClickRecipe(GameObject sender)
    {
        int index = -1;
        if (int.TryParse(sender.name, out index))
        {
            m_selectedRecipeIndex = RecipeTable.Instance[index].Id;
            m_view.RecipeGrid.ReloadData();
            m_view.LblPrice.SetTextSafely(GetCost().ToString());
            UpdateMaterials();
        }
    }

    public void OnClickAutoSelect()
    {

    }

    /// <summary>
    /// 제작 버튼 클릭
    /// </summary>
    public void OnClickMaking()
    {
        // Validation: Is Select Recipe
        if (!IsSelectRecipe())
            return;

        // Validation: Are There Materials
        if (!IsMakable())
        {
            UIAlertView.Show(UIAlertView.Style.OK, string.Empty, "재료가 부족합니다.");
            return;
        }

        // Validation: IS Enough Gold
        Data.Recipe recipe = RecipeTable.Instance.Find(m_selectedRecipeIndex);
        if (MyInfo.Account.Gold < recipe.CostGold)
        {
            UIAlertView.Show(UIAlertView.Style.OK, string.Empty, "골드가 부족합니다.");
            return;
        }

        ConsumeItem();
        AddItem(recipe.ResultItemId);

        Data.Item itemData = ItemTable.Instance.Find(recipe.ResultItemId);
        string message 
            = StringEx.Format("{0}을(를) 제작에 성공하였습니다.", R.GetText(itemData.Name));
        UIAlertView.Show(UIAlertView.Style.OK, string.Empty, message);

        MyInfo.Account.Gold -= recipe.CostGold;

        ReloadData();
    }

    /// <summary>
    /// 닫기 버튼 클릭
    /// </summary>
    public void OnClickClose()
    {
        Hide();
    }

    #endregion UIActions
}
