﻿/* 
 * UINavigationBar.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-21
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

public class UINavigationBar : UIBase, IObserver
{
    [System.Serializable]
    public struct View
    {
        public GameObject BtnBack;
        public Transform SprBack;
        public Transform SprHome;
        public UILabel LblGold;
    }
    public View m_view;

    [ContextMenu("Bind")]
    public override void Initialize()
    {
        m_view = new View();
        this.Bind(ref m_view.BtnBack, "BtnBack");
        this.Bind(ref m_view.SprBack, "BtnBack/SprBack");
        this.Bind(ref m_view.SprHome, "BtnBack/SprHome");
        this.Bind(ref m_view.LblGold, "Gold/LblGold");

        UIEventListener.Get(m_view.BtnBack).onClick = OnClickBackOrHome;
    }

    private void Awake()
    {
        NotificationCenter.Instance.AddObserver((int)Notification.System.OnSceneChanged, this);
    }

    public override void ReloadData()
    {
        base.ReloadData();

        m_view.LblGold.SetTextSafely(MyInfo.Account.Gold.ToString());
    }

    public void HandleNotification(Notification notification)
    {
        switch (notification.id)
        {
            case (int)Notification.System.OnSceneChanged:
                break;

            case (int)Notification.UI.OnGoldChanged:
                m_view.LblGold.SetTextSafely(MyInfo.Account.Gold.ToString());
                break;
        }
    }

    //-------------------------------------------------------------------------
    //  UIActions
    //-------------------------------------------------------------------------
    #region UIActions

    private void OnClickBackOrHome(GameObject sender)
    {

    }

    #endregion UIActions

    private void OnDestroy()
    {
        NotificationCenter.Instance.RemoveObserver((int)Notification.System.OnSceneChanged, this);    
    }
}