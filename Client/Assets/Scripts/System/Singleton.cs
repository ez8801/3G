using UnityEngine;

public abstract class MonoSingleton<T> : MonoBehaviour where T : MonoBehaviour
{
    private static T m_instance;
    public static T Instance
    {
        get
        {
            if (m_instance == null)
            {
                T t = FindObjectOfType<T>();
                if (t == null)
                {
                    GameObject go = new GameObject(typeof(T).ToString());
                    m_instance = go.AddComponent<T>();
                    DontDestroyOnLoad(go);
                }
            }

            return m_instance;
        }
    }
}

public abstract class DestroyableMonoSingleton<T> : MonoBehaviour where T : MonoBehaviour
{
    private static T m_instance;
    public static T Instance
    {
        get
        {
            if (m_instance == null)
            {
                T t = FindObjectOfType<T>();
                if (t == null)
                {
                    GameObject go = new GameObject(typeof(T).ToString());
                    m_instance = go.AddComponent<T>();
                }
            }

            return m_instance;
        }
    }
}

public abstract class Singleton<T> where T : new()
{
    private static T m_instance;
    public static T Instance
    {
        get
        {
            if (m_instance == null)
            {
                m_instance = new T();
            }
            return m_instance;
        }
    }
}