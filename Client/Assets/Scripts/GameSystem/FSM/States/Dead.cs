/* 
 * Dead.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

public class Dead : StateBase
{
    private float m_elapsedTime = 0f;
    private const float kTime = 0.2f;

    protected override void OnEnter()
    {
        base.OnEnter();

        NotificationCenter.Instance.Post((int)Notification.Entity.OnDead, m_owner.EntityID);

        // @TODO : Animation
    }

    private void OnDead()
    {        
        GameObjectPool.Instance.Release(m_owner.gameObject);
    }
    
    protected override bool OnUpdate()
    {
        m_elapsedTime += Time.deltaTime;
        if (m_elapsedTime >= kTime)
        {
            OnDead();
        }
        return base.OnUpdate();
    }
}