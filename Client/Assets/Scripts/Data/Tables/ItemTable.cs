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

        /// <summary>
        /// 아이템 설명
        /// </summary>
        [DeclaringType("string", "int")]
        public int Desc;
        
        public int Value;
        
        /// <summary>
        /// 아이템 재료 그룹
        /// </summary>
        /// <seealso cref="Material.ItemMaterialGroup"/>
        public int ItemMaterialGroup;

        /// <summary>
        /// 아이템 텍스쳐
        /// </summary>
        public string Texture;

        /// <summary>
        /// 아이템 가격
        /// </summary>
        public int Price;
    }
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

    /// <summary>
    /// 지정된 아이템이 중첩가능한지 여부를 반환합니다.
    /// </summary>
    public bool IsStackable(Item data)
    {
        string key = StringEx.Format("Stackable.{0}", data.Type);
        bool isStackable = ConfigTable.Instance.GetBooleanValue(key);
        return isStackable;
    }

    /// <summary>
    /// 지정된 아이템 인덱스에 해당하는 아이템이 중첩가능한지 여부를 반환합니다.
    /// </summary>
    public bool IsStackable(int itemId)
    {
        if (ContainsKey(itemId))
        {
            return IsStackable(Find(itemId));
        }
        return false;
    }

    /// <summary>
    /// 지정된 아이템이 장착가능한지 여부를 반환합니다.
    /// </summary>
    public bool IsEquipable(Item data)
    {
        return (GetItemSlot(data) != ItemSlot.None);
    }

    /// <summary>
    /// 지정된 아이템 인덱스에 해당하는 아이템이 장착가능한지 여부를 반환합니다.
    /// </summary>
    public bool IsEquipable(int itemId)
    {
        return (GetItemSlot(itemId) != ItemSlot.None);
    }

    /// <summary>
    /// 지정된 아이템의 아이템 슬롯을 반환합니다.
    /// </summary>
    public int GetItemSlot(Item data)
    {
        string key = StringEx.Format("Item.Slot.{0}", data.Type);
        int itemSlot = R.Integer.GetInteger(key);
        return itemSlot;
    }

    /// <summary>
    /// 지정된 아이템 인덱스의 해당하는 아이템의 슬롯을 반환합니다.
    /// </summary>
    public int GetItemSlot(int itemId)
    {
        if (ContainsKey(itemId))
        {
            Find(itemId);
        }
        return ItemSlot.None;
    }
}