/* 
 * EntityID.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System.Runtime.InteropServices;

public enum EntityType
{
    None,
    Character,
    Monster,
    Team,
    Item,
    Max,
}

[StructLayout(LayoutKind.Explicit)]
public struct EntityID
{
    [FieldOffset(0)]
    private long m_guid;

    [FieldOffset(0)]
    private EntityType m_entityType;

    [FieldOffset(4)]
    private int m_index;

    public long UID
    {
        get
        {
            return m_guid;
        }

    }

    public EntityType Type
    {
        get
        {
            return m_entityType;
        }
    }
    
    public int Id
    {
        get
        {
            return m_index;
        }
    }

	public EntityID(EntityType type, int id)
    {
        m_guid = 0;
        m_entityType = type;
        m_index = id;
    }
}