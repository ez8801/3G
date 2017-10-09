using UnityEngine;
using System.Collections.Generic;

/// <summary>
/// UI 매니저
/// </summary>
public partial class UIManager : MonoSingleton<UIManager>
{
    public const int kUIDepth = 50;

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

    private Dictionary<UIType, UIBase> m_cachedUIs = new Dictionary<UIType, UIBase>();
    private List<UIType> m_stack = new List<UIType>();

    public int StackedUICount
    {
        get
        {
            return m_stack.Count;
        }
    }

    private int m_currUIDepth = 0;
    public UIType CurrentUIType
    {
        private set
        {
            m_currUIType = value;
            NotificationCenter.Post(R.Id.OnUIChanged);
        }
        get
        {
            return m_currUIType;
        }
    }
    private UIType m_currUIType = UIType.None;

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
    
    private GameObject LoadResource(string resourceName)
    {
        GameObject prefab = Resources.Load(resourceName) as GameObject;
        GameObject newOne = Instantiate(prefab) as GameObject;
        if (newOne != null)
            newOne.name = newOne.name.Replace("(Clone)", string.Empty);
        AttachUI(newOne);
        return newOne;
    }

    public T LoadUI<T>(string resourceName) where T : UIBase
    {
        T cachedUI = GetCachedUI<T>();
        if (cachedUI != null)
        {
            return cachedUI;
        }

        GameObject newOne = LoadResource(resourceName);

        T view = Util.RequireComponent<T>(newOne);
        view.OnCreate();
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

    public UIBase GetCurrentUI()
    {
        return GetUIWith(m_currUIType);
    }
    
    public void CacheUI(UIType typeOfUI, UIBase view)
    {
        if (m_cachedUIs.ContainsKey(typeOfUI))
            m_cachedUIs[typeOfUI] = view;
        else
            m_cachedUIs.Add(typeOfUI, view);
    }

    public void DecreaseDepth()
    {
        m_currUIDepth = Mathf.Max(--m_currUIDepth, 0);
    }
    
    public void HideUI()
    {
        if (StackedUICount > 0)
        {
            UIType typeOfUI = m_stack[m_stack.Count - 1];
            HideUI(typeOfUI);
            m_stack.RemoveAt(m_stack.Count - 1);

            if (StackedUICount > 0)
            {
                typeOfUI = m_stack[m_stack.Count - 1];
                Show(typeOfUI);
            }
        }
    }

    public void HideUI(UIType typeOfUI)
    {
        UIBase cachedUI = GetUIWith(typeOfUI);
        if (cachedUI != null)
        {
            cachedUI.Hide();
        }
    }

    public void HideAllUI()
    {
        var enumerator = m_cachedUIs.GetEnumerator();
        while (enumerator.MoveNext())
        {
            var current = enumerator.Current;
            if (current.Value != null)
            {
                current.Value.Hide();
            }
        }

        m_currUIDepth = 0;
    }

    public void Pop()
    {
        UIBase baseUI = GetCurrentUI();
        if (baseUI != null)
        {
            baseUI.Hide();
            if (baseUI.PreviousUIType != UIType.None)
            {
                Show(baseUI.PreviousUIType);
            }
        }
    }

    public void ReleaseUI(UIType typeOfUI)
    {
        if (m_cachedUIs.ContainsKey(typeOfUI))
        {
            m_cachedUIs.Remove(typeOfUI);
        }
    }

    public void DestroyUI(UIType typeofUI)
    {
        UIBase baseUI = GetUIWith(typeofUI);
        if (baseUI != null)
        {
            HideUI(typeofUI);
            Destroy(baseUI.gameObject);
            baseUI = null;
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

    public string GetUIPrefabPath(UIType typeOfUI)
    {
        switch (typeOfUI)
        {
            case UIType.UIAlertView:
                return "Prefabs/UI/AlertView";
            case UIType.UITitle:
                return "Prefabs/UI/TitleUI";
            case UIType.UINavigationBar:
                return "Prefabs/UI/NavigationBar";
            case UIType.UILobby:
                return "Prefabs/UI/LobbyUI";
            case UIType.UIInventory:
                return "Prefabs/UI/InventoryUI";
            case UIType.UIForge:
                return "Prefabs/UI/ForgeUI";
            case UIType.UIPassiveInventory:
                return "Prefabs/UI/PassiveInventoryUI";
            case UIType.UIBattle:
                return "Prefabs/UI/BattelUI";
            case UIType.UIBattleResult:
                return "Prefabs/UI/BattleResultUI";
            case UIType.UIWorld:
                return "Prefabs/UI/WorldUI";
            case UIType.UIStageInfo:
                return "Prefabs/UI/StageInfoUI";
        }
        return string.Empty;
    }
}
