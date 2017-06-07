/* 
 * StateMachine.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System.Collections.Generic;

public class StateMachine
{
    public Stack<StateBase> m_stack = new Stack<StateBase>();

    private StateBase m_currState = null;

    private StateBase GetCachedState(StateType stateType)
    {
        // @TODO: Cache State
        return null;
    }

    /// <summary>
    /// 지정된 타입의 상태를 생성하여 반환합니다.
    /// </summary>
    public StateBase CreateState(StateType stateType)
    {
        StateBase state = GetCachedState(stateType);
        if (state == null)
        {
            switch (stateType)
            {
                case StateType.Idle:
                    state = new Idle();
                    break;

                case StateType.Walk:
                    state = new Walk();
                    break;

                case StateType.Attack:
                    state = new Attack();
                    break;

                case StateType.Damaged:
                    state = new Damaged();
                    break;

                case StateType.Dead:
                    state = new Dead();
                    break;
            }
        }

        return state;
    }

    public void PerformUpdate()
    {
        OnUpdate();
    }

    private void OnUpdate()
    {
        if (m_currState != null)
        {
            m_currState.PerformUpdate();
        }
    }

    /// <summary>
    /// 이전 상태로 되돌립니다.
    /// </summary>
    public void Revert()
    {
        if (m_stack.Count > 1)
        {
            StateBase currState = m_stack.Pop();
            Assert.IsNotNull(currState, "StateMachine::Revert(void) NullReferenceException");
            currState.PerformLeave();
            
            StateBase prevState = m_stack.Peek();
            Assert.IsNotNull(prevState, "StateMachine::Revert(void) NullReferenceException");

            m_currState = prevState;

            prevState.PerformEnter();
        }
    }
    
    /// <summary>
    /// 지정된 상태로 전이 시킵니다.
    /// </summary>
    public void Transition(StateType stateType)
    {
        StateBase top = m_stack.Peek();
        if (top == null || top.AllowTransitionTo(stateType))
        {
            StateBase stateBase = CreateState(stateType);
            Assert.IsNotNull(stateBase, "StateMachine::Transition(StateType)");
            if (top != null)
                top.PerformLeave();

            m_stack.Push(stateBase);
            m_currState = stateBase;

            stateBase.PerformEnter();
        }
    }
}