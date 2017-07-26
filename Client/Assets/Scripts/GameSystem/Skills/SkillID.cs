/* 
 * SkillID.cs
 * 
 * Writer : user
 * Date   : 2017-07-25
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.InteropServices;


public enum SkillType
{
    None,
    Active,
    Passive,
    Max
}

[StructLayout(LayoutKind.Explicit)]
public struct SkillID
{
    [FieldOffset(0)]
    private long m_sId;

    [FieldOffset(0)]
    private SkillType m_skillType;

    [FieldOffset(4)]
    private int m_index;

    public long SID
    {
        get
        {
            return m_sId;
        }
    }

    public SkillType Type
    {
        get
        {
            return m_skillType;
        }
    }

    public int Id
    {
        get
        {
            return m_index;
        }
    }

    public SkillID(SkillType type, int id)
    {
        m_sId = 0;
        m_skillType = type;
        m_index = id;
    }
}