using System;
using Data;

namespace Data
{
    [Serializable]
    [PrimaryKey("index")]
    public partial struct Item
    {
        public int index;
        public int type;
        public string name;
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