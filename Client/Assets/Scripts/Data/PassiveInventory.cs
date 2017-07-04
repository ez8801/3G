using System.Collections.Generic;

namespace UserData
{
    public class PassiveSkill
    {
        public long Id;
        public int PassiveId;
        public int Level;
    }
}

public class PassiveInventory
{
    private List<UserData.PassiveSkill> m_passive = new List<UserData.PassiveSkill>();

    private static int GUID = 0;

    public void AddPassive(int passiveId, int passiveLv)
    {
        UserData.PassiveSkill newpassive = new UserData.PassiveSkill();
        newpassive.Id = ++GUID;
        newpassive.PassiveId = passiveId;
        newpassive.Level = passiveLv;
        m_passive.Add(newpassive);
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

    #endregion ListAdapter
}