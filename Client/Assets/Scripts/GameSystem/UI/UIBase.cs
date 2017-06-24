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

    public virtual void Initialize()
    {

    }

    public virtual void ViewDidLoad()
    {

    }

    public virtual void ReloadData()
    {
        gameObject.SetActiveSafely(true);
    }
}
