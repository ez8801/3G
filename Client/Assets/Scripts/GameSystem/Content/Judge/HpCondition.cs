/* 
 * HpCondition.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ SHAprojectVer001. DefaultCompany, All rights reserved
 */

public class HpCondition : ICondition
{
    private CompareOperation m_compareOperation = CompareOperation.None;
    private float m_targetValue;
    private Actor m_targetActor;

    public HpCondition(Actor targetActor
        , CompareOperation compareOperation
        , float targetValue)
    {
        SetTarget(targetActor, compareOperation, targetValue);
    }

    public void SetTarget(Actor targetActor
        , CompareOperation compareOperation
        , float targetValue)
    {
        m_targetActor = targetActor;
        m_compareOperation = compareOperation;
        m_targetValue = targetValue;
    }

    public bool IsDone()
    {
        switch (m_compareOperation)
        {
            case CompareOperation.NotEqual:
                return m_targetActor.CurrentHp != m_targetValue;
            case CompareOperation.Equal:
                return m_targetActor.CurrentHp != m_targetValue;
            case CompareOperation.LessThan:
                return m_targetActor.CurrentHp < m_targetValue;
            case CompareOperation.LessThanOrEqual:
                return m_targetActor.CurrentHp <= m_targetValue;
            case CompareOperation.GreaterThan:
                return m_targetActor.CurrentHp > m_targetValue;
            case CompareOperation.GreaterThanOrEqual:
                return m_targetActor.CurrentHp >= m_targetValue;
        }
        return false;
    }	
}