/* 
 * UINavigationBar.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-21
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System;
using UnityEngine;

public class UINavigationBar : UIBase, IObserver, IObserver<GoodsInfo>
{
    [Serializable]
    public struct View
    {
        public GameObject BtnBack;
        public GameObject BtnHome;
        public UILabel LblGold;
    }
    public View m_view;

    internal override void OnCreate()
    {
        base.OnCreate();
        BindComponents();
    }

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        if (IsAssigned(m_view) == false)
            m_view = new View();
        this.Bind(ref m_view.BtnBack, "BtnBack");
        this.Bind(ref m_view.BtnHome, "BtnHome");
        this.Bind(ref m_view.LblGold, "Gold/LblGold");

        UIEventListener.Get(m_view.BtnBack).onClick = OnClickBack;
        UIEventListener.Get(m_view.BtnHome).onClick = OnClickHome;
    }

    public override void Awake()
    {
        base.Awake();
        NotificationCenter.Instance.AddObserver(R.Id.OnStageChanged, this);
        NotificationCenter.Instance.AddObserver(R.Id.OnUIChanged, this);
        NotificationCenter.GoodsMonitor.Subscribe(this);
    }

    public override void ReloadData()
    {
        base.ReloadData();

        m_view.LblGold.SetTextSafely(MyInfo.Account.Gold.ToString());

        UIBase baseUI = UIManager.Instance.GetCurrentUI();
        if (baseUI != null)
        {
            m_view.BtnBack.SetActiveSafely(baseUI.PreviousUIType != UIType.None);
            m_view.BtnHome.SetActiveSafely(baseUI.PreviousUIType != UIType.None);
        }
    }

    public void HandleNotification(Notification notification)
    {
        switch (notification.id)
        {
            case R.Id.OnStageChanged:
            case R.Id.OnUIChanged:
                ReloadData();
                break;
        }
    }

    public void OnCompleted()
    {

    }

    public void OnError(Exception error)
    {

    }

    public void OnNext(GoodsInfo goodsInfo)
    {
        m_view.LblGold.SetTextSafely(goodsInfo.Gold.ToString());
    }

    //-------------------------------------------------------------------------
    //  UIActions
    //-------------------------------------------------------------------------
    #region UIActions

    private void OnClickBack(GameObject sender)
    {
        UIManager.Instance.Pop();
    }

    private void OnClickHome(GameObject sender)
    {
        // @TODO
    }

    #endregion UIActions

    internal override void OnDestroy()
    {
        NotificationCenter.Instance.RemoveObserver(R.Id.OnStageChanged, this);    
        NotificationCenter.Instance.RemoveObserver(R.Id.OnUIChanged, this);    
    }
}