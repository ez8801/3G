﻿/* 
 * UIItemDetailView.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-16
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

public class UIItemDetailView : UIBase
{
    [System.Serializable]
    public struct View
    {
        public UIItemCell CellItem;
        public GameObject BtnEquip;
        public UILabel LblBtnEquip;
        public GameObject EquipmentView;
        public GameObject MiscView;
        public Transform Options;
        public UILabel LblBasicOption;
        public UILabel LblItemName;
        public UILabel LblSummary;
    }
    public View m_view;

    private SimpleItem m_focusItem = new SimpleItem();
    
    internal override void OnStart()
    {
        base.OnStart();
        BindComponents();
        m_view.CellItem.Initialize();
    }

    public void SetData(UserData.Item item)
    {
        NGUITools.SetActive(gameObject, true);
        m_view.CellItem.SetData(item);

        Data.Item itemData = ItemTable.Instance.Find(item.ItemId);
        
        SetCategory((ItemCategory)itemData.Category);

        m_view.LblItemName.SetTextSafely(R.GetText(itemData.Name));
        m_view.LblSummary.SetTextSafely(R.GetText(itemData.Desc));

        bool isEquipable = ItemTable.Instance.IsEquipable(itemData);
        m_view.BtnEquip.SetActiveSafely(isEquipable);

        if (isEquipable)
        {
            bool isEquip = MyInfo.Inventory.IsEquip(item);
            m_view.LblBtnEquip.SetTextSafely(isEquip ? R.GetText("UI.UnEquip") : R.GetText("UI.Equip"));
        }

        m_focusItem.Id = item.Id;
        m_focusItem.ItemId = item.ItemId;
        m_focusItem.Count = item.Count;
    }

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        if (!IsAssigned(m_view))
            m_view = new View();
        this.Bind(ref m_view.CellItem, "CellItem/CellItem");
        this.Bind(ref m_view.BtnEquip, "BottomButtonGroup/BtnEquip");
        this.Bind(ref m_view.LblBtnEquip, "ButtonGroup/BtnEquip/LblBtnEquip");
        this.Bind(ref m_view.EquipmentView, "EquipmentView");
        this.Bind(ref m_view.MiscView, "MiscView");
        this.Bind(ref m_view.Options, "EquipmentView/Options");
        this.Bind(ref m_view.LblBasicOption, "EquipmentView/LblBasicOption");
        this.Bind(ref m_view.LblItemName, "MiscView/LblItemName");
        this.Bind(ref m_view.LblSummary, "MiscView/LblSummary");
    }

    public void SetCategory(ItemCategory itemCategory)
    {
        switch (itemCategory)
        {
            case ItemCategory.Armor:
            case ItemCategory.Weapon:
                m_view.EquipmentView.SetActiveSafely(true);
                m_view.MiscView.SetActiveSafely(false);
                break;

            default:
                m_view.EquipmentView.SetActiveSafely(false);
                m_view.MiscView.SetActiveSafely(true);
                break;
        }
    }

    //-------------------------------------------------------------------------
    //  UIActions
    //-------------------------------------------------------------------------
    #region UIActions

    public void OnClickClose()
    {
        NGUITools.SetActive(gameObject, false);
    }

    public void OnClickSell()
    {
        UIAlertView alertView = UIAlertView.Show(R.GetText("UI.Item.Sell.Message"));
        alertView.SetStyle(UIAlertView.Style.OKCancel);
        alertView.SetPositiveButton(R.GetText("UI.Item.Sell.Ok"), () =>
        {
            Data.Item itemData = ItemTable.Instance.Find(m_focusItem.ItemId);
            int gold = itemData.Price * m_focusItem.Count;
            MyInfo.Account.Gold += gold;
            MyInfo.Inventory.Remove(m_focusItem.Id);

            UIAlertView.Show(StringEx.Format(R.GetText("UI.Get.Gold"), gold))
                .SetStyle(UIAlertView.Style.OK)
                .SetPositiveButton(() =>
                {
                    NGUITools.SetActive(gameObject, false);
                    UIInventory inventoryUI = UIManager.Instance.GetUI<UIInventory>(UIType.UIInventory);
                    if (inventoryUI != null)
                        inventoryUI.ReloadData();
                });
        });
        alertView.SetNegativeButton(R.GetText("UI.Item.Sell.Cancel"), null);
    }

    public void OnClickEquip()
    {
        bool isEquip = MyInfo.Inventory.IsEquip(m_focusItem.Id);
        if (isEquip)
        {
            MyInfo.Inventory.UnEquipItem(m_focusItem.Id);
        }
        else
        {
            MyInfo.Inventory.EquipItem(m_focusItem.Id);
        }

        m_view.LblBtnEquip.SetTextSafely(!isEquip ? R.GetText("UI.UnEquip") : R.GetText("UI.Equip"));

        UIInventory inventoryUI = NGUITools.FindInParents<UIInventory>(gameObject);
        if (inventoryUI != null)
            inventoryUI.ReloadData();

        gameObject.SetActiveSafely(false);
    }

    #endregion UIActions
}