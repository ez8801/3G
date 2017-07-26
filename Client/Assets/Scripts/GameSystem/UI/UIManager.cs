using UnityEngine;

/// <summary>
/// UI 매니저
/// </summary>
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

    private Camera m_mainCamera;
    private Camera m_uiCamera;
    private UIPanel m_uiPanel;
    
    public void Initialize()
    {
        EnsureRoot();
        m_uiCamera = Util.FindInChildren<Camera>(m_root);
        m_uiPanel = Util.FindComponent<UIPanel>(m_root, "Panel");
    }

    private void EnsureRoot()
    {
        m_root = GameObject.FindGameObjectWithTag("UIRoot");
        Assert.IsNotNull(m_root, string.Empty);
        DontDestroyOnLoad(m_root);
    }

    public T GetCachedUI<T>() where T : UIBase
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
        if (newOne != null)
            newOne.name = newOne.name.Replace("(Clone)", string.Empty);
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

    public void ShowLoadingUI(bool isShow)
    {
        if (isShow)
            UIBase.LoadingUI.SetProgress(0f);
    }

    /// <summary>
    /// 월드 좌표를 UI카메라 상의 좌표로 변환합니다.
    /// </summary>
    public Vector3 WorldToScreen(Vector3 v, bool clippingIfBacksideOfFrusum = false)
    {
        if (m_uiCamera == null)
            m_uiCamera = Util.GetCameraByTag("UICamera");
        if (m_mainCamera == null)
            m_mainCamera = Util.GetCameraByTag("MainCamera");

        if (m_mainCamera == null || m_uiCamera == null)
            return Vector3.one * 10000f;

        Vector3 scrPos = m_mainCamera.WorldToScreenPoint(v);

        // clippingIfBacksideOfFrusum 이 true 이면 카메라 뒷편에 있을때는 OutofZone으로 처리한다.
        if (clippingIfBacksideOfFrusum && scrPos.z < 0.0f)
            return Vector3.one * 10000f;

        Vector3 vRet = m_uiCamera.ScreenToWorldPoint(new Vector2(scrPos.x, scrPos.y));
        return vRet;
    }
}
