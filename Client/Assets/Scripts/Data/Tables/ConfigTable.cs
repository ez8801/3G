using Data;
using System;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct Config
    {
        public int Id;
        public string Value;
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
