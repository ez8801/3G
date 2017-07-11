/* 
 * Idle.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

public class Idle : StateBase 
{
    protected override bool OnUpdate()
    {
        if (m_owner.Target != null)
        {
            float distance = Vector3.Distance(m_owner.CachedTransform.position
                , m_owner.Target.CachedTransform.position);

            if (distance > 0.1f)
            {
                m_stateMachine.Transition(StateType.Walk);
            }
            else
            {
                // m_stateMachine.Transition(StateType.Attack);
            }
        }
        return base.OnUpdate();
    }
}