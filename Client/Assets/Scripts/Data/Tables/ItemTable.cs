using System;
using Data;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct Item
    {
        public int Id;
        public int Category;
        public int Type;
        public int Rarity;
        public string Name;
        public int Value;
        public bool Stackable;
        public string Texture;
    }
}

public enum ItemCategory
{
    None,
    Goods,
    Material,
    Misc,
    Weapon = 10,
    Armor = 11,
    Max
}

public enum ItemType
{
    None,
    Exp,
    Gold,
    Jewel = 10,
    Ingot = 11,
    Leather = 12,
    BluePrint = 100,
    Max
}

public struct SimpleItem
{
    public long Id;
    public int ItemId;
    public int Count;
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