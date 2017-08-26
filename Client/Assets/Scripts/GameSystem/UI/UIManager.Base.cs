/* 
 * UIManager.Base.cs
 * 
 * Writer : bmw122
 * Date   : 2017-08-25
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

// For Base Class
public partial class UIManager
{
    public UIBase GetUIWith(UIType typeOfUI)
    {
        UIBase cachedUI = GetCachedUI(typeOfUI);
        if (cachedUI == null)
        {
            cachedUI = GetCachedUIInHierarchy(typeOfUI);
        }
        return cachedUI;
    }

    public UIBase GetCachedUI(UIType typeOfUI)
    {
        if (m_cachedUIs.ContainsKey(typeOfUI))
        {
            return m_cachedUIs[typeOfUI];
        }
        return null;
    }

    public UIBase GetCachedUIInHierarchy(UIType typeOfUI)
    {
        UIBase[] children = Root.GetComponentsInChildren<UIBase>(true);
        for (int i = 0; i < children.Length; i++)
        {
            UIBase childUI = children[i];
            if (childUI.UIType == typeOfUI)
                return childUI;
        }
        return null;
    }

    public UIBase RequireUI(UIType typeOfUI)
    {
        UIBase view = GetUIWith(typeOfUI);
        if (view == null)
        {
            view = CreateUI(typeOfUI);
            if (view == null)
            {
                string message = StringEx.Concat("Couldn't Create UI : ", typeOfUI.ToString());
                Debug.LogWarning(message);
                return null;
            }

            // Cache UI
            CacheUI(typeOfUI, view);
        }

        if (view != null && view.UIType == UIType.None)
            view.SetUIType(typeOfUI);
        return view;
    }

    public UIBase CreateUI(UIType typeOfUI)
    {
        string prefabPath = GetUIPrefabPath(typeOfUI);
        if (string.IsNullOrEmpty(prefabPath))
            return null;

        GameObject newOne = LoadResource(prefabPath);
        UIBase baseUI = Util.RequireComponent<UIBase>(newOne);
        baseUI.SetUIType(typeOfUI);
        baseUI.OnCreate();
        return baseUI;
    }

    public UIBase Show(UIType typeOfUI)
    {
        UIBase view = RequireUI(typeOfUI);
        if (view != null)
        {
            if (view.IsActive)
                return view;

            view.Show();
            m_currUIType = typeOfUI;
        }
        return view;
    }

    public UIBase Push(UIType typeOfUI, bool hidePreviousUI)
    {
        UIBase currentUI = GetCurrentUI();
        if (currentUI != null)
            currentUI.InterActionAble = false;

        UIBase newUI = RequireUI(typeOfUI);
        newUI.Show();
        if (hidePreviousUI)
            currentUI.Hide();
        return newUI;
    }

    public UIBase Push(UIType typeOfUI)
    {
        return Push(typeOfUI, false);
    }
}