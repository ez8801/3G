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

public enum ItemType
{
    None,
    Jewel,
    Ingot,
    Leather,
    BluePrint = 10,
    Max
}

/// <summary>
/// 아이템 테이블
/// 이 클래스는 상속할 수 없습니다.
/// </summary>
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