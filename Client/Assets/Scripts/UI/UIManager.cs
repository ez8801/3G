using UnityEngine;

public class UIManager : MonoSingleton<UIManager>
{
    private GameObject m_root;

    public void Initialize()
    {
        m_root = GameObject.FindGameObjectWithTag("UIRoot");
        Assert.IsNotNull(m_root, string.Empty);
    }

    public T LoadUI<T>(string resourceName) where T : UIViewBase 
    {
        GameObject prefab = Resources.Load(resourceName) as GameObject;
        GameObject newOne = Instantiate(prefab) as GameObject;

        T view = Util.RequireComponent<T>(newOne);
        view.ViewDidLoad();
        return view;
    }
}
