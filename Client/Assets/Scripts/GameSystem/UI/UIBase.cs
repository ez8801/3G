using UnityEngine;

public abstract class UIBase : MonoBehaviour
{
    private static UINavigationBar m_navigationBar;
    public static UINavigationBar NavigationBar
    {
        get
        {
            if (m_navigationBar == null)
            {
                m_navigationBar 
                    = UIManager.Instance.LoadUI<UINavigationBar>("Prefabs/UI/NavigationBar");
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

    public virtual void Initialize()
    {

    }

    public virtual void ViewDidLoad()
    {

    }

    /// <summary>
    /// 해당 View가 활성화 될때 호출됩니다.
    /// </summary>
    public virtual void ViewDidAppear()
    {
        
    }

    /// <summary>
    /// 해당 View가 비활성화 될때 호출됩니다.
    /// </summary>
    public virtual void ViewDidDisAppear()
    {

    }

    public virtual void ReloadData()
    {
        gameObject.SetActiveSafely(true);
    }
}
