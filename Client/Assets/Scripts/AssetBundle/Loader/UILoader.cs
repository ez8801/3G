/* 
 * UILoader.cs
 * 
 * Writer : EZ
 * Date   : 2017-08-27
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System;
using System.Collections;

public class UILoader : AssetLoader
{
    private UIType m_typeOfUI;

    public UILoader(UIType typeOfUI)
    {
        m_typeOfUI = typeOfUI;
    }

    public override bool IsValid()
    {
        return true;
    }

    public override IEnumerator Load()
    {
        UIBase baseUI = UIManager.Instance.RequireUI(m_typeOfUI);
        if (baseUI != null)
            baseUI.IsActive = false;
        yield return null;
    }
}