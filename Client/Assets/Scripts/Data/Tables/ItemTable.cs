using System;
using Data;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct Item
    {
        public int Id;

        /// <summary>
        /// 아이템 카테고리
        /// </summary>
        /// <see cref="ItemCategory"/>
        public int Category;

        /// <summary>
        /// 아이템 타입
        /// </summary>
        /// <see cref="ItemType"/>
        public int Type;

        /// <summary>
        /// 아이템 레어도
        /// </summary>
        /// <see cref="ItemRarity"/>
        public int Rarity;

        /// <summary>
        /// 아이템 이름
        /// </summary>
        [DeclaringType("string", "int")]
        public int Name;
        
        public int Value;

        /// <summary>
        /// 중첩 가능 여부
        /// </summary>
        public bool Stackable;

        /// <summary>
        /// 아이템 텍스쳐
        /// </summary>
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

public enum ItemRarity
{
    None,
    Normal,
    Magic,
    Rare,
    Unique,
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