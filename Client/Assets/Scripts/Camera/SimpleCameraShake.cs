using UnityEngine;

public class SimpleCameraShaker : MonoBehaviour
{
    private Transform m_cachedTransform;

    public float m_duration = 0.3f;
    public float m_shakeAmount = 0.05f;

    private float m_lastPlayTime;
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
    }

    public void SetOnShakeEndListener(System.Action l)
    {
        m_onShakeEndListener = l;
    }

    public void Shake()
    {
        if (m_isPlaying == false 
            && (Time.realtimeSinceStartup - m_lastPlayTime) > 0.15f)
        {
            m_elapsedTime = 0f;
            m_isPlaying = true;
            m_originalPosition = m_cachedTransform.localPosition;
        }
    }
    
    public void LateUpdate()
    {
        if (m_isPlaying)
        {
            transform.localPosition
                = transform.localPosition + new Vector3(Random.insideUnitSphere.x, 0f, 0f) * m_shakeAmount;

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
        m_lastPlayTime = Time.realtimeSinceStartup;

        m_cachedTransform.localPosition = m_originalPosition;
        if (m_onShakeEndListener != null)
            m_onShakeEndListener();
    }
}
