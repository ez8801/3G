/* 
 * Damaged.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

public class Damaged : StateBase 
{
    private float DamagedTime;
    private float m_elapsedTime;

    protected override void OnEnter()
    {
        base.OnEnter();
        m_elapsedTime = 0f;
        DamagedTime = 0.4f;
    }

    protected override bool OnUpdate()
    {
        m_elapsedTime += Time.deltaTime;
        if (m_elapsedTime >= DamagedTime && m_actor.IsGrounded())
        {
            m_stateMachine.Revert();
        }
        return base.OnUpdate();
    }
}