/* 
 * ConditionCompositer.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ SHAprojectVer001. DefaultCompany, All rights reserved
 */

using System.Collections.Generic;

public interface ICondition
{
    bool IsDone();
}

public enum CompareOperation
{
    None,
    NotEqual,
    LessThan,
    LessThanOrEqual,
    Equal,
    GreaterThan,
    GreaterThanOrEqual,
}

public class ConditionCompositer
{
    public delegate bool Condition();

    private List<ICondition> m_conditions = new List<ICondition>();
    private Condition m_condition = null;

    public void AddCondition(ICondition condition)
    {
        m_conditions.Add(condition);
    }

    public void AddCondition(Condition condition)
    {
        m_condition += condition;
    }
    
    public bool IsDone()
    {
        for (int i = 0; i < m_conditions.Count; i++)
        {
            ICondition each = m_conditions[i];
            if (each.IsDone() == false)
                return false;
        }

        if (m_condition != null)
            return m_condition();
        return true;
    }
}