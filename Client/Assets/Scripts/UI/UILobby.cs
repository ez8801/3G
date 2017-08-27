/* 
 * UILobby.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-21
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using GameSystem;

/// <summary>
/// 로비 UI
/// </summary>
/// <seealso cref="UIType.UILobby"/>
public class UILobby : UIBase
{
    [System.Serializable]
    public struct View
    {
        public UIEventListener BtnChat;
        public UIEventListener BtnInventory;
        public UIEventListener BtnForge;
        public UIEventListener BtnDungeon;
        public UIEventListener BtnPvp;
    }
    public View m_view;
    
    internal override void OnCreate()
    {
        base.OnCreate();
        Debug.Log(Macros.__PRETTY_FUNCTION__);
        BindComponents();
    }

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        Debug.Log(Macros.__PRETTY_FUNCTION__);
        if (IsAssigned(m_view) == false)
            m_view = new View();
        this.Bind(ref m_view.BtnChat, "AnchorTopRight/BtnChat");
        this.Bind(ref m_view.BtnInventory, "ToolBar/AnchorBottomRight/Grid/BtnInventory");
        this.Bind(ref m_view.BtnForge, "ToolBar/AnchorBottomRight/Grid/BtnForge");
        this.Bind(ref m_view.BtnDungeon, "ToolBar/AnchorBottomRight/Grid/BtnDungeon");
        this.Bind(ref m_view.BtnPvp, "ToolBar/AnchorBottomRight/Grid/BtnPvp");

        m_view.BtnChat.onClick = OnClickChat;
        // m_view.BtnInventory.onClick = OnClickInventory;
        m_view.BtnForge.onClick = OnClickForge;
        m_view.BtnDungeon.onClick = OnClickDungeon;
        m_view.BtnPvp.onClick = OnClickPassiveInventory;
    }

    //-------------------------------------------------------------------------
    //  UIActions
    //-------------------------------------------------------------------------
    #region UIActions

    public void OnClickChat(GameObject sender)
    {
        Debug.Log(Macros.__PRETTY_FUNCTION__);

    }

    public void OnClickInventory(GameObject sender)
    {
        Debug.Log(Macros.__PRETTY_FUNCTION__);
        UIInventory inventoryUI = UIManager.Instance.Push<UIInventory>(UIType.UIInventory);
        inventoryUI.ReloadData();
    }

    public void OnClickPassiveInventory(GameObject sender)
    {
        Debug.Log(Macros.__PRETTY_FUNCTION__);
        UIPassiveInventory passiveInventoryUI 
            = UIManager.Instance.Push<UIPassiveInventory>(UIType.UIPassiveInventory);
        passiveInventoryUI.ReloadData();
    }

    public void OnClickForge(GameObject sender)
    {
        Debug.Log(Macros.__PRETTY_FUNCTION__);
        UIManager.Instance.Push(UIType.UIForge);
    }

    public void OnClickDungeon(GameObject sender)
    {
        Debug.Log(Macros.__PRETTY_FUNCTION__);

        UIWorld worldUI = UIManager.Instance.RequireUI<UIWorld>(UIType.UIWorld);

        // @TODO: Load Data
        worldUI.SetData(1);

        UIManager.Instance.Push(UIType.UIWorld);
    }

    public void OnClickPvp(GameObject sender)
    {
        Debug.Log(Macros.__PRETTY_FUNCTION__);

    }

    #endregion UIActions
}