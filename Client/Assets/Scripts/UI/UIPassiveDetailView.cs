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
        this.Bind(ref m_view.LblBtnEquip, "BottomButtonGroup/LblBtnEquip");
        this.Bind(ref m_view.AboutView, "AboutView");
        this.Bind(ref m_view.LblPassiveName, "AboutView/LblPassiveName");
        this.Bind(ref m_view.LblPassiveSummary, "AboutView/LblPassiveSummary");
    }

    public void InitWithData(UserData.PassiveSkill passive)
    {
        NGUITools.SetActive(gameObject, true);
        m_view.CellPassive.InitWithData(passive);

        Data.PassiveSkill passiveData = PassiveSkillTable.Instance.Find(passive.PassiveId);

        m_view.AboutView.SetActiveSafely(true);

        m_view.LblPassiveName.SetTextSafely(R.String.GetText(passiveData.Name));
        m_view.LblPassiveSummary.SetTextSafely(R.String.GetText(passiveData.Summary));

        m_view.BtnEquip.SetActiveSafely(true);
        bool i = MyInfo.PassiveInventory.IsEquip(passive.Id);
        m_view.LblBtnEquip.SetTextSafely(i ? R.String.GetText("UI.UnEquip") : R.String.GetText("UI.Equip"));

        m_focusPassive.Id = passive.Id;
        m_focusPassive.PassiveId = passive.PassiveId;
        m_focusPassive.Level = passive.Level;
    }

    


}