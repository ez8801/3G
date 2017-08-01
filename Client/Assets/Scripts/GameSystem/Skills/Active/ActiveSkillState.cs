using UnityEngine;
using System;
using System.Collections;

//ActiveSkill과 연계하여 슬롯에서 쿨타임 연계하는것으로 수정 요함.

public enum ActiveSkillStateType
{
    Ready,
    Disabled,
    Cooltime,
    Casttime
}

public abstract class ActiveSkillState : MonoBehaviour
{
    private ActiveSkillStateType m_currentState;

    public ActiveSkillStateType StateType
    {
        get
        {
            return m_currentState;
        }
    }

    private float m_coolTime;
    public void SetCool(float baseCoolTime, float minusCoolTime ,float decreaseCoolTime)
    {
        m_coolTime = (baseCoolTime - minusCoolTime) * decreaseCoolTime;
    }
    private float m_currentCoolTime;

    public float m_disableTime;
    private float m_currentDisableTime;

    private float m_castTime;
    public void SetCast(float baseCastTime, float minusCastTime, float decreaseCastTime)
    {
        m_castTime = (baseCastTime - minusCastTime) * decreaseCastTime;
    }
    private float m_currentCastTime;

    public void Onclick()
    {
        switch (m_currentState)
        {
            case ActiveSkillStateType.Ready:
                SetState(ActiveSkillStateType.Casttime);
                break;
            case ActiveSkillStateType.Cooltime:
                break;
            case ActiveSkillStateType.Disabled:
                break;
            case ActiveSkillStateType.Casttime:
                break;
        }
    }

    IEnumerator CoolTime()
    {
        if (m_currentCoolTime <= 0)
            m_currentCoolTime = m_coolTime;

        while (m_currentCoolTime > 0)
        {
            m_currentCoolTime -= Time.deltaTime;
            yield return null;
        }
        SetState(ActiveSkillStateType.Ready);
    }

    IEnumerator CastTime()
    {
        m_currentCastTime = m_castTime;

        while (m_currentCastTime > 0)
        {
            m_currentCastTime -= Time.deltaTime;
            yield return null;
        }
        SetState(ActiveSkillStateType.Cooltime);
    }

    IEnumerator DisableTime()
    {
        if(m_disableTime >= m_currentDisableTime)
            m_currentDisableTime = m_disableTime;

        while (m_currentDisableTime > 0)
        {
            m_currentDisableTime -= Time.deltaTime;
            yield return null;
        }
        if (m_currentCoolTime > 0)
        {
            SetState(ActiveSkillStateType.Cooltime);
        }
        else
        {
            SetState(ActiveSkillStateType.Ready);
        }
    }

    private void SetState(ActiveSkillStateType state)
    {
        m_currentState = state;
        switch (m_currentState)
        {
            case ActiveSkillStateType.Ready:
                break;
            case ActiveSkillStateType.Cooltime:
                StartCoroutine(CoolTime());
                break;
            case ActiveSkillStateType.Disabled:
                StartCoroutine(DisableTime());
                break;
            case ActiveSkillStateType.Casttime:
                StartCoroutine(CastTime());
                break;
        }
    }
}

