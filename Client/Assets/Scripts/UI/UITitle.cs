/* 
 * UITitle.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-21
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

/// <summary>
/// 타이틀 UI
/// </summary>
/// <seealso cref="UIType.UITitle"/>
public class UITitle : UIBase 
{
    [System.Serializable]
    public struct View
    {
        public UILabel lblGameVersion;
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
        this.Bind(ref m_view.lblGameVersion, "LblGameVersion");
    }

    public override void ReloadData()
    {
        base.ReloadData();
        
        m_view.lblGameVersion.SetTextSafely(GameDefine.VersionString);
    }
}