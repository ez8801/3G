/* 
 * UIPassiveDetailView.cs
 * 
 * Writer : user
 * Date   : 2017-08-09
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class UIPassiveDetailView : UIBase 
{
    [System.Serializable]
    public struct View
    {
        public UIPassiveCell CellPassive;
        public GameObject BtnEquip;
        public UILabel LblBtnEquip;
        public GameObject AboutView;
        public UILabel LblPassiveName;
        public UILabel LblPassiveSummary;
        public UILabel LblPassiveLevel;
        public UILabel LblPassiveCategory;
    }
    public View m_view;

    private SimplePassive m_focusPassive = new SimplePassive();

    public override void Initialize()
    {
        base.Initialize();
        BindComponents();
        m_view.CellPassive.Initialize();
    }

    [ContextMenu("Bind")]
    private void BindComponents()
    {
        if (!IsAssigned(m_view)) m_view = new View();
        this.Bind(ref m_view.CellPassive, "CellPassive/CellPassive");
        this.Bind(ref m_view.BtnEquip, "BottomButtonGroup/BtnEquip");
        this.Bind(ref m_view.LblBtnEquip, "BottomButtonGroup/BtnEquip/LblBtnEquip");
        this.Bind(ref m_view.AboutView, "AboutView");
        this.Bind(ref m_view.LblPassiveName, "AboutView/LblPassiveName");
        this.Bind(ref m_view.LblPassiveSummary, "AboutView/LblPassiveSummary");
        this.Bind(ref m_view.LblPassiveLevel, "AboutView/LblPassiveLevel");
        this.Bind(ref m_view.LblPassiveCategory, "AboutView/PassiveCategory");
    }

    public void InitWithData(UserData.PassiveSkill passive)
    {
        NGUITools.SetActive(gameObject, true);
        m_view.CellPassive.InitWithData(passive);
        int type;

        Data.PassiveSkill passiveData = PassiveSkillTable.Instance.Find(passive.PassiveId);

        m_view.AboutView.SetActiveSafely(true);

        m_view.LblPassiveName.SetTextSafely(R.GetText(passiveData.Name));
        m_view.LblPassiveSummary.SetTextSafely(R.GetText(passiveData.Summary));
        m_view.LblPassiveLevel.SetTextSafely(R.GetText(passiveData.Level));

        type = passiveData.Type;
        m_view.LblPassiveCategory.SetTextSafely(R.GetText(GetPassiveType(type)));


        m_view.BtnEquip.SetActiveSafely(true);
        bool i = MyInfo.PassiveInventory.IsEquip(passive.Id);
        m_view.LblBtnEquip.SetTextSafely(i ? R.GetText("UI.UnEquip") : R.GetText("UI.Equip"));

        m_focusPassive.Id = passive.Id;
        m_focusPassive.PassiveId = passive.PassiveId;
        m_focusPassive.Level = passive.Level;
    }

    public string GetPassiveType(int type)
    {
        switch (type)
        {
            case 1: return "Common";
            case 10: return "Staff";
            case 11: return "Gem";
            case 12: return "Shield";
            case 13: return "Sword";
            case 14: return "Spear";
            case 15: return "Bow";
        }
        return "error";
    }

    #region UIActions

    public void OnClickEquip()
    {
        bool isEquip = MyInfo.PassiveInventory.IsEquip(m_focusPassive.Id);
        if (isEquip)
        {
            MyInfo.PassiveInventory.UnEquipSkill(m_focusPassive.Id);
        }
        else
        {
            //빈 슬롯 확인 -> 0이라면 빈 슬롯 없음
            int i = MyInfo.PassiveInventory.FindEmptySlot();
            if (i == 0)
            {
                // alertView생성
                UIAlertView alertView = UIAlertView.Show(R.GetText("UI.Passive,Equip.Message.1"));
                alertView.SetStyle(UIAlertView.Style.OK);
                alertView.SetPositiveButton(() =>
                {
                    NGUITools.SetActive(gameObject, false);
                });
            }
            else
            {
                MyInfo.PassiveInventory.EquipPassive(m_focusPassive.Id);
            }

            UIPassiveInventory passiveInventoryUI = NGUITools.FindInParents<UIPassiveInventory>(gameObject);
            if (passiveInventoryUI != null) passiveInventoryUI.ReloadData();

            gameObject.SetActiveSafely(false);
        }
    }




    #endregion UIActions


}