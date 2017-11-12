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
        public int PrefabId;
        public string Texture;
        public bool Chargeable;
        public int Charging;
        public int Level;
        public string Summary;
    }
}

//스킬의 구분
public enum ActiveType
{
    None,
    Projectile = 1,
    Buff = 2,
    Summon = 3,
    Targeting = 4,
    Circle = 5,
    Move = 6
}

public struct SimpleActive
{
    public long Id;
    public int ActiveId;
    public int Cooltime;
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