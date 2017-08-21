using System;
using Data;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct PassiveSkill
    {
        public int Id;
        public int Type;
        public string Name;
        public string Texture;
        public int Level;
        public string Summary;
    }
}

//공통스킬(common), 무기특화 스킬로 구분
public enum PassiveType
{
    None,
    Common = 1,
    Staff = 10,
    Gem = 11,
    Shield = 12,
    Sword = 13,
    Spear = 14,
    Bow = 15,
}

public struct SimplePassive
{
    public long Id;
    public int PassiveId;
    public int Level;
}

public sealed class PassiveSkillTable : ArrayTable<PassiveSkill>
{
    private static PassiveSkillTable m_instance = null;
    public static PassiveSkillTable Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new PassiveSkillTable();
            return m_instance;
        }
    }

}