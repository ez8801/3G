using UnityEngine;

public class NestedPrefab : MonoBehaviour
{
    public enum GenerateTime
    {
        Lazy,		// OnEnable
        Immediate,	// Awake
    }

    public GenerateTime m_generateTime;
    public GameObject m_prefabObject;
    public bool m_clearWhenInactive = false;
    public GameObject m_instance;
    
    private void Awake()
    {
        if (m_generateTime == GenerateTime.Immediate && m_instance == null)
            InstantiateObject();
    }

    private void OnEnable()
    {
        if (m_instance == null)
        {
            InstantiateObject();
        }
    }

    private void OnDisable()
    {
        if (m_clearWhenInactive)
        {
            RemoveObject();
        }
    }

    [ContextMenu("Instantiate Object")]
    public void InstantiateObject()
    {
        RemoveObject();

        Assert.IsNotNull(m_prefabObject, "Prefab Object was not found");

        Transform cachedTransform   = m_prefabObject.transform;
        Vector3 localPosition       = cachedTransform.localPosition;
        Quaternion localRotation    = cachedTransform.localRotation;
        Vector3 localScale          = cachedTransform.localScale;

        m_instance = Instantiate(m_prefabObject) as GameObject;
        Assert.IsNotNull(m_instance, "PrefabObject Couldn't Instantiate Object");
        m_instance.name = m_instance.name.Replace("(Clone)", string.Empty);

        m_instance.transform.parent = transform;
        m_instance.transform.localPosition = localPosition;
        m_instance.transform.localRotation = localRotation;
        m_instance.transform.localScale = localScale;
    }

    public void RemoveObject()
    {
        if (m_instance != null)
        {
#if UNITY_EDITOR
            m_instance.transform.parent = null;

            if (Application.isPlaying == false)
            {
                DestroyImmediate(m_instance);
                m_instance = null;
                return;
            }
#endif
            
            Destroy(m_instance);
            m_instance = null;
        }
    }

    private void OnDestroy()
    {
        RemoveObject();
    }        
}
