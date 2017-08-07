using System.Collections.Generic;

namespace UserData
{
    public class PassiveSkill
    {
        public long Id;
        public int PassiveId;
        public int Level;
        public float PassiveExp;
    }
}
public struct SkillSlot
{
    public const int None = 0;
    public const int firstSlot = 1;
    public const int SecondSlot = 2;
    public const int ThirdSlot = 3;
    public const int ForthSlot = 4;
    public const int Max = 5;
}

public class PassiveInventory
{
    private List<UserData.PassiveSkill> m_passive = new List<UserData.PassiveSkill>();

    private Dictionary<long, bool> m_dirtyFlags = new Dictionary<long, bool>();

    private Dictionary<int, long> m_equippedSkills = new Dictionary<int, long>();

    private int m_selectSlot = 0;

    private static int GUID = 0;


    public PassiveInventory()
    {
        for(int i = SkillSlot.None + 1; i < SkillSlot.Max;i++)
        {
            m_equippedSkills.Add(i, 0);
        }
    }

    public void SetDirty(long skillID, bool flag)
    {
        if (m_dirtyFlags.ContainsKey(skillID))
        {
            m_dirtyFlags[skillID] = flag;
        }
        else
        {
            m_dirtyFlags.Add(skillID, flag);
        }
    }

    public void ClearDirtyFlag()
    {
        m_dirtyFlags.Clear();
    }

    public bool GetDirty(long skillID)
    {
        if (m_dirtyFlags.ContainsKey(skillID))
            return m_dirtyFlags[skillID];
        return false;
    }

    public UserData.PassiveSkill GetEquipPassive(int skillSlot)
    {
        if (m_equippedSkills.ContainsKey(skillSlot))
        {
            return Find(m_equippedSkills[skillSlot]);
        }
        return null;
    }

    //바꾸어넣을 최신의 패시브 스킬과, 선택된 스킬 슬롯의 번호를 입력받아 수정합니다.
    public bool EquipPassive(UserData.PassiveSkill nowPassive)
    {
        if(m_equippedSkills.ContainsKey(m_selectSlot) == false)
        {
            return false;
        }
        m_equippedSkills[m_selectSlot] = nowPassive.Id;
        m_selectSlot = 0;
        return true;
    }

    public bool EquipPassive(long id, int selectSlot)
    {
        UserData.PassiveSkill passive = Find(id);
        if (passive != null)
            return EquipPassive(passive);
        return false;
    }
    
    public bool SelectSlot(int select)
    {
        m_selectSlot = select;
        return true;
    }

    public bool IsSelect(int select)
    {
        if(m_selectSlot != 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    public void UnEquipSkill(int skillSlot)
    {
        if (m_equippedSkills.ContainsKey(skillSlot))
        {
            m_equippedSkills[skillSlot] = 0;
        }
    }

    public bool IsEquip(long id)
    {
        var enumerator = m_equippedSkills.GetEnumerator();
        while(enumerator.MoveNext())
        {
            if (enumerator.Current.Value == id)
                return true;
        }
        return false;
    }

    //지정 슬롯의 아이템 착용 여부
    public bool IsEquipWith(int skillSlot)
    {
        if (m_equippedSkills.ContainsKey(skillSlot))
        {
            return (m_equippedSkills[skillSlot] != 0);
        }
        return false;
    }

    #region ListAdapter

    public UserData.PassiveSkill this[int index]
    {
        get
        {
            if (index < 0 || index >= m_passive.Count)
                return null;
            return m_passive[index];
        }
    }

    public int Count
    {
        get
        {
            return m_passive.Count;
        }
    }

    public UserData.PassiveSkill Find(long id)
    {
        for(int i = 0; i < m_passive.Count; i++)
        {
            UserData.PassiveSkill match = m_passive[i];
            if(match.Id == id)
            {
                return match;
            }
        }
        return null;
    }

    #endregion ListAdapter
}