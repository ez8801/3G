/* 
 * UIManager.Generic.cs
 * 
 * Writer : bmw122
 * Date   : 2017-08-25
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

// For Generic Method
public partial class UIManager
{
    public T GetUI<T>(UIType typeOfUI) where T : UIBase
    {
        T cachedUI = GetCachedUI<T>(typeOfUI);
        if (cachedUI == null)
        {
            cachedUI = GetCachedUIInHierarchy<T>();
        }
        return cachedUI;
    }

    public T GetCachedUI<T>(UIType typeOfUI) where T : UIBase
    {
        T cachedUI = null;
        if (m_cachedUIs.ContainsKey(typeOfUI))
        {
            cachedUI = m_cachedUIs[typeOfUI] as T;
            return cachedUI;            
        }
        return null;
    }

    public T GetCachedUIInHierarchy<T>() where T : UIBase
    {
        T cachedUI = Util.FindInChildren<T>(Root);
        return cachedUI;
    }

    public T RequireUI<T>(UIType typeOfUI) where T : UIBase
    {
        T view = GetUI<T>(typeOfUI);
        if (view == null)
        {
            view = CreateUI<T>(typeOfUI);
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

    public T CreateUI<T>(UIType typeOfUI) where T : UIBase
    {
        string prefabPath = GetUIPrefabPath(typeOfUI);
        if (string.IsNullOrEmpty(prefabPath))
            return null;

        GameObject go = LoadResource(prefabPath);
        T t = Util.RequireComponent<T>(go);
        t.SetUIType(typeOfUI);
        t.OnCreate();
        return t;
    }

    public T Show<T>(UIType typeOfUI) where T : UIBase
    {
        T view = RequireUI<T>(typeOfUI);
        if (view != null)
        {
            if (view.IsActive)
            {
                CurrentUIType = typeOfUI;
                return view;
            }

            view.Show();
            CurrentUIType = typeOfUI;
        }

        return view;
    }
    
    public T Push<T>(UIType typeOfUI, bool hidePreviousUI) where T : UIBase
    {
        UIBase currentUI = GetCurrentUI();
        if (currentUI != null)
            currentUI.InterActionAble = false;

        T newUI = RequireUI<T>(typeOfUI);
        newUI.SetPreviousUIType(currentUI.UIType);
        CurrentUIType = typeOfUI;
        newUI.Show();
        if (hidePreviousUI)
            currentUI.Hide();
        return newUI;
    }

    public T Push<T>(UIType typeOfUI) where T : UIBase
    {
        return Push<T>(typeOfUI, false);
    }
}