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