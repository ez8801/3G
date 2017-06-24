using UnityEngine;

public class UIManager : MonoSingleton<UIManager>
{
    public GameObject Root
    {
        get
        {
            if (m_root == null)
            {
                EnsureRoot();
            }
            return m_root;
        }
    }
    private GameObject m_root;
    
    private Camera m_uiCamera;
    private UIPanel m_uiPanel;
    
    public void Initialize()
    {
        EnsureRoot();
        m_uiCamera = Util.FindInChildren<Camera>(m_root);
        m_uiPanel = Util.FindComponentByName<UIPanel>(m_root, "Panel");
    }

    private void EnsureRoot()
    {
        m_root = GameObject.FindGameObjectWithTag("UIRoot");
        Assert.IsNotNull(m_root, string.Empty);
        DontDestroyOnLoad(m_root);
    }

    private T GetCachedUI<T>() where T : UIBase
    {
        GameObject root = Root;
        return Util.FindInChildren<T>(root);
    }

    public T LoadUI<T>(string resourceName) where T : UIBase 
    {
        T cachedUI = GetCachedUI<T>();
        if (cachedUI != null)
        {
            return cachedUI;
        }

        GameObject prefab = Resources.Load(resourceName) as GameObject;
        GameObject newOne = Instantiate(prefab) as GameObject;
        AttachUI(newOne);

        T view = Util.RequireComponent<T>(newOne);
        view.ViewDidLoad();
        return view;
    }

    public void AttachUI(GameObject go)
    {
        if (m_uiPanel != null && go != null)
        {
            Transform child = go.transform;
            Vector3 prevPosition = child.localPosition;
            child.parent = m_uiPanel.transform;
            child.localScale = Vector3.one;
            child.localRotation = Quaternion.identity;
            child.localPosition = prevPosition;
        }
    }
}
