using UnityEngine;
using System.Collections.Generic;
//  SkillBase
//   -> 스킬 시전자의 사용 모션, 프리팹 : skillName으로 검색
//   -> skillID를 통해 구별
//   -> 쿨타임
//   -> 스킬등급
//   -> 장착 여부
public abstract class SkillBase : MonoBehaviour
{

    private static List<SkillBase> skills = new List<SkillBase>();

    protected SkillID m_skillId;

    public long SkillID
    {
        get
        {
            return m_skillId.SID;
        }
    }

    public SkillType SkillType
    {
        get
        {
            return m_skillId.Type;
        }
    }

    public virtual void Initialize(SkillType skillType, int skillId)
    {
        SetSkillId(skillType, skillId);
    }

    public void SetSkillId(SkillType skillType, int skillId)
    {
        m_skillId = new SkillID(skillType, skillId);
    }

    public virtual void Initialize()
    {

    }

    public static SkillBase Find(long id)
    {
        for(int i = 0; i < skills.Count; i++)
        {
            SkillBase match = skills[i];
            if (match.SkillID == id)
                return match;
        }
        return null;
    }

    public static SkillBase Find(SkillType skillType, int id)
    {
        SkillID skillId = new SkillID(skillType, id);
        return Find(skillId.SID);
    }
}