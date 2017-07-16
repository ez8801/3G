/* 
 * UIAlertView.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-16
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System;
using UnityEngine;

public class UIAlertView : UIBase
{
    [Serializable]
    public struct View
    {
        public UILabel LblTitle;
        public UILabel LblNegative;
        public UILabel LblPositive;
        public UILabel LblSummary;
    }
    public View m_view;

    private Action m_positiveAction;
    private Action m_negativeAction;

    public override void Initialize()
    {
        base.Initialize();
        BindComponents();
    }

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        if (!IsAssigned(m_view))
            m_view = new View();
        this.Bind(ref m_view.LblTitle, "LblTitle");
        this.Bind(ref m_view.LblNegative, "BtnNegative/LblNegative");
        this.Bind(ref m_view.LblPositive, "BtnPositive/LblPositive");
        this.Bind(ref m_view.LblSummary, "LblSummary");
    }
    
    public void SetPositiveButton(string buttonName, Action action)
    {
        m_view.LblPositive.SetTextSafely(buttonName);
        m_positiveAction = action;
    }

    public void SetNegativeButton(string buttonName, Action action)
    {
        m_view.LblNegative.SetTextSafely(buttonName);
        m_negativeAction = action;
    }

    //-------------------------------------------------------------------------
    //  UIActions
    //-------------------------------------------------------------------------
    #region UIActions

    public void OnClickClose()
    {
        NGUITools.SetActive(gameObject, false);
    }

    public void OnClickNegativeButton()
    {
        if (m_positiveAction != null)
            m_positiveAction();
        NGUITools.SetActive(gameObject, false);
    }

    public void OnClickPositiveButton()
    {
        if (m_negativeAction != null)
            m_negativeAction();
        NGUITools.SetActive(gameObject, false);
    }

    #endregion UIActions
}