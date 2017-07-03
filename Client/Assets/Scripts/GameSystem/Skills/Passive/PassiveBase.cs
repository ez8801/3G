using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public abstract class PassiveBase
{
    public virtual PassiveType Type
    {
        get
        {
            return PassiveType.None;
        }
    }

    private float m_exp;
    public float Exp
    {
        get
        {
            return m_exp;
        }
        set
        {
            m_exp = value;
            CheckLevel();
        }
    }
    private float m_maxExp;
    public float MaxExp
    {
        get
        {
            return m_maxExp;
        }
        set
        {
            m_maxExp = value;
            CheckLevel();
        }
    }

    private int m_maxLevel;
    public int MaxLevel
    {
        get
        {
            return m_maxLevel;
        }
        set
        {
            m_maxLevel = value;
        }
    }


    public float FinalLevel { private set; get; }

    private void CheckLevel()
    {
        if(Exp >= MaxExp)
        {
            if (FinalLevel < MaxLevel)
            {
                Exp -= MaxExp;
                FinalLevel++;
            }
        }

    }
}
