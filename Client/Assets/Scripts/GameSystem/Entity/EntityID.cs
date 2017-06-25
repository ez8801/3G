/* 
 * EntityID.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

public enum EntityType
{
    None,
    Character,
    Monster,
    Team,
    Max,
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