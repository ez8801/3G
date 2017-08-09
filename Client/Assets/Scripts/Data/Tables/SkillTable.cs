using System;
using Data;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct Skill
    {
        public int Id;
        public int Type;
        public string Name;
        public int Cooltime;
        public int Effect;
        public string Texture;
        public bool Chargeable;
        public int Charging;
        public int Level;
        public string Summary;
    }
}

//공통스킬(common), 무기특화 스킬로 구분
public enum ActiveType
{
    None,
    Common = 1,
    Staff = 10,
    Gem = 11,
    Shield = 12,
    Sword = 13,
    Spear = 14,
    Bow = 15
}

public sealed class SkillTable : ArrayTable<Skill>
{
    private static SkillTable m_instance = null;
    public static SkillTable Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new SkillTable();
            return m_instance;
        }
    }
}