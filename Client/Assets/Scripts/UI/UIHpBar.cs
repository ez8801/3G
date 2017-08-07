/* 
 * UIHpBar.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-02
 * 
 * Copyright ⓒ SHAprojectVer001. DefaultCompany, All rights reserved
 */

using UnityEngine;

public class UIHpBar : MonoBehaviour, IObserver
{
    public UISprite SprHp;

    private Transform m_cachedTransform = null;
    private int m_cachedWidth = 0;
    
    public Actor m_targetActor;
    private float m_prevRatio;

    /// <summary>
    /// 해당 인스턴스를 초기화 합니다.
    /// </summary>
    public static UIHpBar Initialize(string prefabName, Actor actor)
    {
        GameObject prefab = Resources.Load(prefabName) as GameObject;
        return Initialize(prefab, actor);
    }

    public static UIHpBar Initialize(GameObject prefab, Actor actor)
    {
        GameObject clone = GameObjectPool.Instance.Create(prefab);

        if (clone.activeInHierarchy == false)
            clone.SetActive(true);

        UIManager.Instance.AttachUI(clone);

        UIHpBar hpBar = Util.RequireComponent<UIHpBar>(clone);        
        hpBar.m_targetActor = actor;
        hpBar.m_prevRatio = actor.HpRatio;
        hpBar.Draw();
        return hpBar;
    }

    //-------------------------------------------------------------------------
    //  MonoBehaviour Life Cycle
    //-------------------------------------------------------------------------
    #region MonoBehaviour Life Cycle
    
    private void Awake()
    {
        m_cachedTransform = transform;
        m_cachedWidth = SprHp.width;
    }

    private void OnEnable()
    {
        NotificationCenter.Instance.AddObserver(R.Id.OnEntityDead, this);
    }

    private void Update()
    {
        if (m_targetActor == null || SprHp == null)
        {
            GameObjectPool.Instance.Release(gameObject);
            return;
        }

        m_cachedTransform.position = UIManager.Instance.WorldToScreen(m_targetActor.Head.position);

        if (m_prevRatio != m_targetActor.HpRatio)
            Draw();
        m_prevRatio = m_targetActor.HpRatio;
    }

    private void OnDisable()
    {
        NotificationCenter.Instance.RemoveObserver(R.Id.OnEntityDead, this);
    }

    #endregion MonoBehaviour Life Cycle

    private void Draw()
    {
        SprHp.SetFillAmountSafely(m_targetActor.HpRatio, m_cachedWidth);
    }

    // IObserver
    public void HandleNotification(Notification notification)
    {
        switch (notification.id)
        {
            case R.Id.OnEntityDead:
                Debug.Log("Notification.Entity.OnDead: " + notification.longExtra);
                if (notification.longExtra == m_targetActor.EntityID)
                    GameObjectPool.Instance.Release(gameObject);
                break;
        }
    }
}