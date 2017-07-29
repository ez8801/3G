using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class ActiveSkill : SkillBase
{

    private Data.Skill m_activeSkill;

    private float m_baseCoolTime; //기본 쿨타임
    public float BaseCoolTime
    {
        get
        {
            return m_baseCoolTime;
        }
        set
        {
            m_baseCoolTime = value;
            CoolTimeCheck();
        }
    }
    private float m_coolTimePercent; //쿨타임 퍼센트(100 이면 기본쿨타임)
    public float CoolTimePercent
    {
        get
        {
            return m_coolTimePercent;
        }
        set
        {
            m_baseCoolTime = value;
            CoolTimeCheck();
        }
    }

    private float m_decreaseCoolTime; //기본쿨타임에서 감소되는 쿨타임(단위 : 초)
    public float DecreaseCoolTime
    {
        get
        {
            return m_decreaseCoolTime;
        }
        set
        {
            m_decreaseCoolTime = value;
            CoolTimeCheck();
        }
    }

    private float m_finalCoolTime;
    /// <summary>
    ///최종쿨타임, (기본쿨타임-감소쿨타임) * (쿨타임비율 / 100.f)를 반환합니다.
    /// </summary>
    public float FinalCoolTime
    {
        get
        {
            return m_finalCoolTime;
        }
    }
    private void CoolTimeCheck() // final 쿨타임 계산(초단위 쿨타임 감소 후 퍼센트 적용)
    {
        m_finalCoolTime = (m_baseCoolTime - m_decreaseCoolTime) * (m_coolTimePercent / 100.0f);
    }


    private int m_skillLevel; // 스킬 단계
    public int SkillLevel
    {
        get
        {
            return m_skillLevel;
        }
        set
        {
            m_skillLevel = value;
        }
    }

    private string m_skillName;
    public string SkillName
    {
        get
        {
            return m_skillName;
        }
        set
        {
            m_skillName = value;
        }
    }

    private int m_skillType;
    public int ActiveSkillType
    {
        get
        {
            return m_skillType;
        }
        set
        {
            m_skillType = value;
        }
    }


    public override void Initialize()
    {
        base.Initialize();
        m_activeSkill = SkillTable.Instance.Find(m_skillId.Id);

        SkillName = m_activeSkill.Name;
        m_baseCoolTime = m_activeSkill.Cooltime;
        CoolTimePercent = 100.0f;
        DecreaseCoolTime = 0;
        SkillLevel = m_activeSkill.Level;

    }

    public long GetSkillId()
    {
        return SkillID;
    }
}