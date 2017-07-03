/* 
 * StateBase.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

public enum StateType
{
    None,
    Idle,
    Walk,
    Attack,
    Damaged,
    Dead,
    Max,
}

public abstract class StateBase
{
    private StateType m_stateType;
    protected Actor m_owner;

    public void Initialize(Actor owner)
    {
        m_owner = owner;
    }

    internal virtual bool AllowTransitionTo(StateType stateType)
    {
        return true;
    }

    public void PerformEnter()
    {
        OnEnter();
    }

    protected virtual void OnEnter()
    {

    }

    public void PerformUpdate()
    {
        OnUpdate();
    }

    protected virtual bool OnUpdate()
    {
        return true;
    }

    public void PerformLeave()
    {
        OnLeave();
    }

    protected virtual void OnLeave()
    {

    }
}