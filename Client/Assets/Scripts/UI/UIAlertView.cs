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
    public enum Style
    {
        None,
        OK,
        OKCancel,
        Max
    }

    public static UIAlertView Build()
    {
        UIAlertView alertView = UIManager.Instance.LoadUI<UIAlertView>("Prefabs/UI/AlertView");
        alertView.m_view.LblPositive.SetTextSafely(R.String.GetText("UI.AlertView.Ok"));
        alertView.m_view.LblNegative.SetTextSafely(R.String.GetText("UI.AlertView.Cancel"));
        return alertView;
    }

    public static UIAlertView Show(string text)
    {
        UIAlertView alertView = Build();
        alertView.SetSummary(text);
        alertView.SetActiveSafely(true);
        return alertView;
    }

    public static UIAlertView Show(string title, string text)
    {
        UIAlertView alertView = Build();
        alertView.SetTitle(title);
        alertView.SetSummary(text);
        alertView.SetActiveSafely(true);
        return alertView;
    }

    public static UIAlertView Show(Style style, string title, string text)
    {
        UIAlertView alertView = Build();
        alertView.SetTitle(title);
        alertView.SetSummary(text);
        alertView.SetActiveSafely(true);
        return alertView;
    }

    [Serializable]
    public struct View
    {
        public UILabel LblTitle;
        public UILabel LblSummary;
        public GameObject BtnNegative;
        public UILabel LblNegative;
        public GameObject BtnPositive;
        public UILabel LblPositive;
    }
    public View m_view;

    private const float Offset = 75f;

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
        this.Bind(ref m_view.LblSummary, "LblSummary");
        this.Bind(ref m_view.BtnNegative, "BtnNegative");
        this.Bind(ref m_view.BtnPositive, "BtnPositive");
        this.Bind(ref m_view.LblNegative, "BtnNegative/LblNegative");
        this.Bind(ref m_view.LblPositive, "BtnPositive/LblPositive");
    }

    public UIAlertView SetTitle(string title)
    {
        m_view.LblTitle.SetTextSafely(title);
        return this;
    }

    public UIAlertView SetSummary(string summary)
    {
        m_view.LblSummary.SetTextSafely(summary);
        return this;
    }

    public UIAlertView SetStyle(Style style)
    {
        switch (style)
        {
            case Style.OK:
                m_view.BtnPositive.transform.SetLocalPositionX(0f);
                m_view.BtnPositive.SetActiveSafely(true);
                m_view.BtnNegative.SetActiveSafely(false);
                break;

            case Style.OKCancel:
                m_view.BtnPositive.transform.SetLocalPositionX(Offset);
                m_view.BtnPositive.SetActiveSafely(true);
                m_view.BtnNegative.transform.SetLocalPositionX(-Offset);
                m_view.BtnNegative.SetActiveSafely(true);
                break;
        }
        return this;
    }

    public UIAlertView SetPositiveButton(Action action)
    {
        m_positiveAction = action;
        return this;
    }

    public UIAlertView SetPositiveButton(string buttonName, Action action)
    {
        m_view.LblPositive.SetTextSafely(buttonName);
        m_positiveAction = action;
        return this;
    }

    public UIAlertView SetNegativeButton(Action action)
    {
        m_negativeAction = action;
        return this;
    }

    public UIAlertView SetNegativeButton(string buttonName, Action action)
    {
        m_view.LblNegative.SetTextSafely(buttonName);
        m_negativeAction = action;
        return this;
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
        NGUITools.SetActive(gameObject, false);
        if (m_negativeAction != null)
            m_negativeAction();
    }

    public void OnClickPositiveButton()
    {
        NGUITools.SetActive(gameObject, false);
        if (m_positiveAction != null)
            m_positiveAction();
    }

    #endregion UIActions
}