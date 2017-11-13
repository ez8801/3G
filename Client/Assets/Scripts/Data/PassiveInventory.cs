using UnityEngine;
using System.Collections;
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
    private Client m_client;
    private List<UserData.PassiveSkill> m_passive = new List<UserData.PassiveSkill>();

    private Dictionary<long, bool> m_dirtyFlags = new Dictionary<long, bool>();

    private Dictionary<int, long> m_equippedSkills = new Dictionary<int, long>();

    private int m_selectSlot = 0;

    private static int GUID = 0;


    public PassiveInventory()
    {
        m_client = Client.Instance;
        for (int i = SkillSlot.None + 1; i < SkillSlot.Max;i++)
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
        m_selectSlot = FindEmptySlot();
        if (m_selectSlot != 0)
        {
            if (m_equippedSkills.ContainsKey(m_selectSlot) == false)
            {
                return false;
            }
            m_equippedSkills[m_selectSlot] = nowPassive.Id;

            Data.PassiveSkill passive = PassiveSkillTable.Instance.Find(nowPassive.PassiveId);
            GameObject.Find("PassiveManager").SendMessage("ApplyPassive", passive);
            // 패시브 슬롯과 패시브 아이디를 서버로 보내서 DB에 저장
            // DB에서 패시브 값 받아와서 m_equippedSkills에 저장하고
            // 패시브에 따른 능력값 Apply해주는 루트 만들어주면 됨
            // 내일
            m_selectSlot = 0;
            return true;
        }
        return false;
    }

    public bool EquipPassive(long id)
    {
        UserData.PassiveSkill passive = Find(id);
        if (passive != null)
        {
            bool result;
            result = EquipPassive(passive);
            if(result == true)
            {
                m_client.SendPassiveEquipInfo(Nettention.Proud.HostID.HostID_Server, Nettention.Proud.RmiContext.UnreliableSend, MyInfo.Account.NickName,
                    (int)m_equippedSkills[1], (int)m_equippedSkills[2], (int)m_equippedSkills[3], (int)m_equippedSkills[4]);
            }
            return result;
        }
        return false;
    }

    public bool EquipPassiveFromDB(long id)
    {
        UserData.PassiveSkill passive = Find(id);
        if (passive != null)
            return EquipPassive(passive);
        return false;
    }

    //빈 슬롯을 반환합니다.
    public int FindEmptySlot()
    {
        int i;
        for(i = 1; i < 5; i++)
        {
            if(m_equippedSkills[i] == 0)
            {
                return i;
            }
        }
        //빈 슬롯이 없을경우 0 반환
        return 0;
    }

    //지정된 패시브가 장착된 슬롯을 반환합니다.
    public int FindEquipSlot(UserData.PassiveSkill passive)
    {
        int i;
        for (i = 1; i < 5; i++)
        {
            if (m_equippedSkills[i] == passive.Id)
            {
                return i;
            }
        }
        return 0;
    }

    public int FindEquipSlot(long id)
    {
        UserData.PassiveSkill passive = Find(id);

        int i;
        for (i = 1; i < 5; i++)
        {
            if (m_equippedSkills[i] == passive.Id)
            {
                return i;
            }
        }
        return 0;
    }
//지정된 스킬 해제
    public void UnEquipSkill(UserData.PassiveSkill passive)
    {
        int passiveSlot = FindEquipSlot(passive);
        if (passiveSlot != 0)
        {
            m_equippedSkills[passiveSlot] = 0;
        }
    }
    //지정된 스킬 아이디로 해제
    public void UnEquipSkill(long id)
    {
        var enumerator = m_equippedSkills.GetEnumerator();
        while (enumerator.MoveNext())
        {
            if (enumerator.Current.Value == id)
            {
                m_equippedSkills[enumerator.Current.Key] = 0;

                UserData.PassiveSkill passive = Find(id);
                Data.PassiveSkill passiveData = PassiveSkillTable.Instance.Find(passive.PassiveId);
                m_client.SendPassiveEquipInfo(Nettention.Proud.HostID.HostID_Server, Nettention.Proud.RmiContext.UnreliableSend, MyInfo.Account.NickName,
                    (int)m_equippedSkills[1], (int)m_equippedSkills[2], (int)m_equippedSkills[3], (int)m_equippedSkills[4]);
                GameObject.Find("PassiveManager").SendMessage("ReleasePassive", passiveData);

                break;
            }
        }
    }
    //지정된 스킬슬롯의 패시브 패제
    public void UnEquipSkill(int skillSlot)
    {
        if (m_equippedSkills.ContainsKey(skillSlot))
        {
            m_equippedSkills[skillSlot] = 0;
        }
    }

    //지정 스킬 장착 여부 반환
    public bool IsEquip(UserData.PassiveSkill passive)
    {
        return IsEquip(passive.Id);
    }

    //스킬 아이디로 장착 여부 반환
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

    //지정 슬롯의 스킬 착용 여부
    public bool IsEquipWith(int skillSlot)
    {
        if (m_equippedSkills.ContainsKey(skillSlot))
        {
            return (m_equippedSkills[skillSlot] != 0);
        }
        return false;
    }

    public void AddPassive(int passiveId, int passiveLv)
    {
        UserData.PassiveSkill newPassive = new UserData.PassiveSkill();
        newPassive.Id = ++GUID;
        newPassive.PassiveId = passiveId;
        newPassive.Level = passiveLv;
        m_passive.Add(newPassive);

        SetDirty(newPassive.Id, true);
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

    public void Remove(long id)
    {
        for(int i = 0; i < m_passive.Count; i++)
        {
            UserData.PassiveSkill match = m_passive[i];
            if(match.Id == id)
            {
                m_passive.RemoveAt(i);
                return;
            }
        }
    }

    public List<UserData.PassiveSkill> GetPassiveList()
    {
        return m_passive;
    }

    public List<UserData.PassiveSkill> FindAll(System.Predicate<UserData.PassiveSkill> predicate)
    {
        List<UserData.PassiveSkill> ret = new List<UserData.PassiveSkill>();
        for (int i = 0; i < Count; i++)
        {
            UserData.PassiveSkill match = m_passive[i];
            if (predicate(match))
            {
                ret.Add(match);
            }
        }
        return ret;
    }

    public List<UserData.PassiveSkill> FindAll(int passiveType)
    {
        List<UserData.PassiveSkill> ret = new List<UserData.PassiveSkill>();
        for(int i = 0; i < Count; i++)
        {
            UserData.PassiveSkill match = m_passive[i];
            Data.PassiveSkill passiveData = PassiveSkillTable.Instance.Find(match.PassiveId);
            if(passiveData.Type == passiveType)
            {
                ret.Add(match);
            }
        }
        return ret;
    }



    #endregion ListAdapter
}