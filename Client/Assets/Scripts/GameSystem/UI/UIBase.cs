using UnityEngine;
using System.Collections.Generic;

public abstract class UIBase : MonoBehaviour
{
    //-------------------------------------------------------------------------
    //  Memeber Variables
    //-------------------------------------------------------------------------
    #region Memeber Variables

    public virtual UIType UIType
    {
        get
        {
            return m_type;
        }
    }
    protected UIType m_type;

    public UIType PreviousUIType
    {
        get
        {
            return m_previousUIType;
        }
    }
    protected UIType m_previousUIType = UIType.None;

    private int m_depth;

    private bool m_IsActive = false;
    public bool IsActive
    {
        get
        {
            return (gameObject != null && gameObject.activeInHierarchy && m_IsActive);
        }
        set
        {
            gameObject.SetActiveSafely(value);
            if (m_IsActive != value)
            {
                if (value)
                    OnStart();
                else
                    OnStop();
            }
            m_IsActive = value;
        }
    }

    private bool m_interActionAble;
    public bool InterActionAble
    {
        get { return m_interActionAble; }
        set
        {
            if (m_interActionAble != value)
            {
                if (value)
                    OnResume();
                else
                    OnPause();
            }
            m_interActionAble = value;
        }
    }
    
    private UIPanel m_panel;
    private List<UIBase> m_children;
    
    #endregion Member Variables

    private static UINavigationBar m_navigationBar;
    public static UINavigationBar NavigationBar
    {
        get
        {
            if (m_navigationBar == null)
            {
                m_navigationBar
                    = UIManager.Instance.Show<UINavigationBar>(UIType.UINavigationBar);
            }
            return m_navigationBar;
        }
    }

    private static UILoading m_loadingUI;
    public static UILoading LoadingUI
    {
        get
        {
            if (m_loadingUI == null)
            {
                m_loadingUI
                    = UIManager.Instance.LoadUI<UILoading>("Prefabs/UI/LoadingUI");
            }
            return m_loadingUI;
        }
    }
    
    public void SetDepth(int depth)
    {
        if (m_panel == null)
            m_panel = Util.RequireComponent<UIPanel>(gameObject);

        m_depth = depth;
        m_panel.depth = depth;
    }

    public void SetUIType(UIType typeOfUI)
    {
        m_type = typeOfUI;
    }

    internal void SetPreviousUIType(UIType typeOfUI)
    {
        m_previousUIType = typeOfUI;
    }

    public void Show()
    {
        IsActive = true;
        InterActionAble = true;
    }

    public void Hide()
    {
        InterActionAble = false;
        IsActive = false;
    }

    public void Destroy()
    {
        Debug.Log(StringEx.Format("{0}.{1}", name, Macros.__PRETTY_FUNCTION__));

        Hide();
        OnDestroy();

        if (gameObject != null)
            Destroy(gameObject);
    }

    public virtual void ReloadData()
    {
        gameObject.SetActiveSafely(true);
    }

    //-------------------------------------------------------------------------
    //  MonoBehaviour LifeCycle
    //-------------------------------------------------------------------------
    #region MonoBehaviour LifeCycle

    public virtual void Awake()
    {
        Debug.Log(StringEx.Format("{0}.{1}", name, Macros.__PRETTY_FUNCTION__));

        if (transform.parent != null)
        {
            UIBase parent = transform.parent.GetComponentInParent<UIBase>();
            if (parent != null)
            {
                if (parent.m_children == null)
                    parent.m_children = new List<UIBase>();
                parent.m_children.Add(this);
            }
        }
    }

    #endregion MonoBehaviour LifeCycle
    
    //-------------------------------------------------------------------------
    //  UI LifeCycle
    //-------------------------------------------------------------------------
    #region UI LifeCycle

    /// <summary>
    /// called when ui is first created.
    /// </summary>
    internal virtual void OnCreate()
    {
        // Create And Prepare to display.
        Debug.Log(StringEx.Format("{0}.{1}", name, Macros.__PRETTY_FUNCTION__));

        if (m_children != null)
        {
            for (int i = 0; i < m_children.Count; i++)
            {
                UIBase baseUI = m_children[i];
                if (baseUI != null)
                    baseUI.OnCreate();
            }
        }
    }

    /// <summary>
    /// called when ui is becoming visible to the user.
    /// </summary>
    internal virtual void OnStart()
    {
        // On Visible
        Debug.Log(StringEx.Format("{0}.{1}", name, Macros.__PRETTY_FUNCTION__));

        if (m_children != null)
        {
            for (int i = 0; i < m_children.Count; i++)
            {
                UIBase baseUI = m_children[i];
                if (baseUI != null)
                    baseUI.OnCreate();
            }
        }
    }

    /// <summary>
    /// called after your ui is stopped, prior to start.
    /// </summary>
    internal virtual void OnRestart()
    {
        // On Prepare to display
        Debug.Log(StringEx.Format("{0}.{1}", name, Macros.__PRETTY_FUNCTION__));

        if (m_children != null)
        {
            for (int i = 0; i < m_children.Count; i++)
            {
                UIBase baseUI = m_children[i];
                if (baseUI != null)
                    baseUI.OnRestart();
            }
        }
    }

    /// <summary>
    /// called when ui will start interacting with the user.
    /// </summary>
    internal virtual void OnResume()
    {
        // On Begin Interaction
        Debug.Log(StringEx.Format("{0}.{1}", name, Macros.__PRETTY_FUNCTION__));

        if (m_children != null)
        {
            for (int i = 0; i < m_children.Count; i++)
            {
                UIBase baseUI = m_children[i];
                if (baseUI != null)
                    baseUI.OnResume();
            }
        }
    }

    /// <summary>
    /// called when ui is not visible to the user.
    /// </summary>
    internal virtual void OnPause()
    {
        // On Pause Interaction
        Debug.Log(StringEx.Format("{0}.{1}", name, Macros.__PRETTY_FUNCTION__));

        if (m_children != null)
        {
            for (int i = 0; i < m_children.Count; i++)
            {
                UIBase baseUI = m_children[i];
                if (baseUI != null)
                    baseUI.OnPause();
            }
        }
    }

    /// <summary>
    /// called when ui is no longer visible to the user.
    /// </summary>
    internal virtual void OnStop()
    {
        // On Invisible
        Debug.Log(StringEx.Format("{0}.{1}", name, Macros.__PRETTY_FUNCTION__));
        
        if (m_children != null)
        {
            for (int i = 0; i < m_children.Count; i++)
            {
                UIBase baseUI = m_children[i];
                if (baseUI != null)
                    baseUI.OnStop();
            }
        }
    }

    /// <summary>
    /// called before the ui is destroyed.
    /// </summary>
    internal virtual void OnDestroy()
    {
        // On Destroy
        Debug.Log(StringEx.Format("{0}.{1}", name, Macros.__PRETTY_FUNCTION__));
        
        if (m_children != null)
        {
            for (int i = 0; i < m_children.Count; i++)
            {
                UIBase baseUI = m_children[i];
                if (baseUI != null)
                    baseUI.OnDestroy();
            }
            m_children.Clear();
            m_children = null;
        }

        UIManager.Instance.ReleaseUI(UIType);
    }

    #endregion UI LifeCycle
    
    //-------------------------------------------------------------------------
    //  Static Methods
    //-------------------------------------------------------------------------
    #region Static Methods

    /// <summary>
    /// 해당 구조체가 할당되었는지 여부를 반환합니다.
    /// </summary>
    public static bool IsAssigned<T>(T t) where T : struct
    {
        EqualityComparer<T> Comparer = EqualityComparer<T>.Default;
        return (Comparer.Equals(t, default(T)) == false);
    }

    #endregion Static Methods
}
