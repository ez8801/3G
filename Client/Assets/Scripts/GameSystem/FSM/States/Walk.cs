/* 
 * Walk.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

public class Walk : StateBase
{
    protected override bool OnUpdate()
    {
        if (m_owner.Target != null)
        {
            m_owner.CachedTransform.position += m_owner.Forward * 2f * Time.deltaTime;

            float distance = Vector3.Distance(m_owner.CachedTransform.position
                , m_owner.Target.CachedTransform.position);            
        }
        return base.OnUpdate();
    }
}