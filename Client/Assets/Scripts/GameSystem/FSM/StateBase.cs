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

public interface IStateMachine
{
    void Revert();
    void Transition(StateType stateType);
}

public abstract class StateBase
{
    public StateType StateType
    {
        get
        {
            return m_stateType;
        }
    }
    private StateType m_stateType;
    protected Actor m_owner;
    protected IActor m_actor;
    protected IStateMachine m_stateMachine;

    public void Initialize(Actor owner, IStateMachine stateMachine)
    {
        m_owner = owner;
        m_actor = owner;
        m_stateMachine = stateMachine;
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