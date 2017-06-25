using Data;
using System;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct Config
    {
        public int Id;
        public string Key;
        public int Value;
    }
}

/// <summary>
/// Config테이블
/// 이 클래스는 상속할 수 없습니다.
/// </summary>
public class ConfigTable : ArrayTable<Config>
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
