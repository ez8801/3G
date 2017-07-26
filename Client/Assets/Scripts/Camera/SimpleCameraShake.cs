using UnityEngine;

public class SimpleCameraShaker : MonoBehaviour
{
    private Transform m_cachedTransform;

    public float m_duration = 0.3f;
    public float m_shakeAmount = 0.5f;

    private float m_elapsedTime;
    private bool m_isPlaying;

    Vector3 m_originalPosition;
    System.Action m_onShakeEndListener;

    public void Awake()
    {
        if (m_cachedTransform == null)
            SetTarget(transform);
    }

    public Transform GetTarget()
    {
        return m_cachedTransform;
    }

    public void SetTarget(Transform target)
    {
        m_cachedTransform = transform;
        m_originalPosition = m_cachedTransform.localPosition;
    }

    public void SetOnShakeEndListener(System.Action l)
    {
        m_onShakeEndListener = l;
    }

    public void Shake()
    {
        if (m_isPlaying == false)
        {
            m_elapsedTime = 0f;
            m_isPlaying = true;
        }
    }
    
    public void Update()
    {
        if (m_isPlaying)
        {
            m_cachedTransform.localPosition
                = m_originalPosition + Random.insideUnitSphere * m_shakeAmount;

            m_elapsedTime += Time.deltaTime;
            if (m_elapsedTime >= m_duration)
            {
                OnShakeEnd();
            }
        }
    }

    private void OnShakeEnd()
    {
        m_elapsedTime = 0f;
        m_isPlaying = false;

        m_cachedTransform.localPosition = m_originalPosition;
        if (m_onShakeEndListener != null)
            m_onShakeEndListener();
    }
}
