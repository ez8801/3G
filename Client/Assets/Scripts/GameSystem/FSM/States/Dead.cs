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

        NotificationCenter.Post(R.Id.OnEntityDead, m_owner.EntityID);

        // @TODO : Animation
    }
    
    protected override bool OnUpdate()
    {
        m_elapsedTime += Time.deltaTime;
        if (m_elapsedTime >= kTime)
        {
            m_actor.OnDead();
        }
        return base.OnUpdate();
    }
}