using UnityEngine;
using System.Collections;

public class LerpEffector : MonoBehaviour
{
    public float m_duration;

    private float m_accumulatedTime;

    private System.Action<float> m_onUpdateListener;
    private System.Action m_onFinishListener;
    
    public void Initialize()
    {
        m_duration = 1f;
        m_accumulatedTime = 0f;
    }

    public void SetOnUpdateListener(System.Action<float> l)
    {
        m_onUpdateListener = l;
    }

    public void SetOnFinishListener(System.Action l)
    {
        m_onFinishListener = l;
    }

    public void PlayLerpEffect(float from, float to, float duration)
    {
        StartCoroutine(InternalPlayLerpEffect(from, to, duration));
    }
    
    private IEnumerator InternalPlayLerpEffect(float from, float to, float duration)
    {
        Initialize();
        while (m_accumulatedTime < m_duration)
        {
            m_accumulatedTime += m_duration * Time.deltaTime;
            if (m_onUpdateListener != null)
                m_onUpdateListener(Mathf.Lerp(from, to, m_accumulatedTime / m_duration));
            yield return null;
        }

        if (m_onFinishListener != null)
            m_onFinishListener();
        yield return null;
    }
}
