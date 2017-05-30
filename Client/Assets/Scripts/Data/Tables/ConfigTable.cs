using Data;
using System;

namespace Data
{
    [Serializable]
    [PrimaryKey("index")]
    public partial struct Config
    {
        public int index;
        public string value;
    }
}

public class ConfigTable : ArrayTable<Item>
{
    private static ConfigTable m_instance = null;
    public static ConfigTable Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new ConfigTable();
            return m_instance;
        }
    }
}
