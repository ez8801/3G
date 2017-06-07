/* 
 * EntityID.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public enum EntityType
{
    None,
    Character,
    Monster,
}

public struct EntityID
{
    private EntityType m_entityType;   
    private long m_guid;

    public EntityType Type
    {
        get
        {
            return m_entityType;
        }
    }

    public long Id
    {
        get
        {
            return m_guid;
        }
    }

	public EntityID(EntityType type, long guid)
    {
        m_entityType = type;
        m_guid = guid;
    }
}