/* 
 * Stats.cs
 * 
 * Writer : bmw122
 * Date   : 2017-06-22
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

public enum StatsType
{
    None,
    AttackDamage,
    Armor,
    Hp,
}

public abstract class Stats 
{
    public virtual StatsType Type
    {
        get
        {
            return StatsType.None;
        }
    }

    private float m_value;
    public float Value
    {
        get
        {
            return m_value;
        }
        set
        {
            m_value = value;
            Calculate();
        }
    }

    private float m_percent;
    public float Percent
    {
        get
        {
            return m_percent;
        }
        set
        {
            m_percent = value;
            Calculate();
        }
    }

    private float m_max;
    public float Max
    {
        get
        {
            return m_max;
        }
        set
        {
            m_max = value;
            Calculate();
        }
    }

    public float Ratio { get { return Final * 0.01f; } }
    public float Final { private set; get; }

    public void Intialize(float value, float percent)
    {
        Value = value;
        Percent = percent;
    }
    
    public void Calculate()
    {
        Final = m_value * (m_percent * 0.01f + 1);
        Final = (Max > Final) ? Final : Max;
    }
}