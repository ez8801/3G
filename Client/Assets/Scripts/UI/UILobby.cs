/* 
 * UILobby.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-21
 * 
 * Copyright ⓒ SHAprojectVer001. DefaultCompany, All rights reserved
 */

using UnityEngine;

public class UILobby : UIBase
{
    [System.Serializable]
    public struct View
    {
        public GameObject BtnChat;
    }
    public View m_view;

    [ContextMenu("Bind")]
    public override void Initialize()
    {
        m_view = new View();
        this.Bind(ref m_view.BtnChat, "AnchorTopRight/BtnChat");

        UIEventListener.Get(m_view.BtnChat).onClick = OnClickChat;
    }

    //-------------------------------------------------------------------------
    //  UIActions
    //-------------------------------------------------------------------------
    #region UIActions

    private void OnClickChat(GameObject sender)
    {

    }

    #endregion UIActions
}