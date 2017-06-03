using System;
using Data;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct Item
    {
        public int Id;
        public int Type;
        public int Rarity;
        public string Name;
        public int Value;
        public bool Stackable;
    }
}

public sealed class ItemTable : ArrayTable<Item>
{
    private static ItemTable m_instance = null;
    public static ItemTable Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new ItemTable();
            return m_instance;
        }
    }
}