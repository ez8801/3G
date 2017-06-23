/* 
 * UITitle.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-21
 * 
 * Copyright ⓒ SHAprojectVer001. DefaultCompany, All rights reserved
 */

using UnityEngine;

public class UITitle : UIBase 
{
    [System.Serializable]
    public struct View
    {
        public UILabel lblGameVersion;
    }
    public View m_view;

    [ContextMenu("Bind")]
    public override void Initialize()
    {
        base.Initialize();

        m_view = new View();
        this.Bind(ref m_view.lblGameVersion, "LblGameVersion");
    }

    public override void ReloadData()
    {
        base.ReloadData();
        
        m_view.lblGameVersion.SetSafelyText(GameDefine.VersionString);
    }
}