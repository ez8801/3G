/* 
 * Inventory.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System.Collections.Generic;

namespace UserData
{
    public class Item
    {
        public long Id;
        public int ItemId;
        public int Count;
    }
}

public class Inventory
{
    private List<UserData.Item> m_items = new List<UserData.Item>();
    private Dictionary<long, bool> m_dirtyFlags = new Dictionary<long, bool>();

    private Dictionary<int, long> m_equippedItems = new Dictionary<int, long>();

    // @TODO: Temporary
    private static int GUID = 0;

    public Inventory()
    {
        for (int i = ItemSlot.None + 1; i < ItemSlot.Max; i++)
        {
            m_equippedItems.Add(i, 0);
        }
    }
    
    public void SetDirty(long itemId, bool flag)
    {
        if (m_dirtyFlags.ContainsKey(itemId))
            m_dirtyFlags[itemId] = flag;
        else
            m_dirtyFlags.Add(itemId, flag);
    }

    public void ClearDirtyFlag()
    {
        m_dirtyFlags.Clear();
    }

    public bool GetDirty(long itemId)
    {
        if (m_dirtyFlags.ContainsKey(itemId))
            return m_dirtyFlags[itemId];
        return false; 
    }

    public UserData.Item GetEquipItem(int itemSlot)
    {
        if (m_equippedItems.ContainsKey(itemSlot))
        {
            return Find(m_equippedItems[itemSlot]);
        }
        return null;
    }
    
    public void AddItem(int itemId, int itemCount)
    {
        if (IsGoods(itemId))
        {
            AddGoodsItem(itemId, itemCount);
            OnGainedItem(0, itemId, itemCount);
        }
        else if (IsStackAble(itemId))
        {
            AddStackAbleItem(itemId, itemCount);
        }
        else
        {
            InternalAddItem(itemId, itemCount);
        }
    }

    public void AddGoodsItem(int itemId, int itemCount)
    {
        Data.Item itemData = ItemTable.Instance.Find(itemId);
        switch ((ItemType) itemData.Type)
        {
            case ItemType.Gold:
                MyInfo.Account.Gold += itemCount;
                break;

            case ItemType.Exp:
                MyInfo.Account.Exp += itemCount;
                break;
        }
    }

    public void AddStackAbleItem(int itemId, int itemCount)
    {
        for (int i = 0; i < m_items.Count; i++)
        {
            UserData.Item match = m_items[i];
            if (match.ItemId == itemId)
            {
                match.Count += itemCount;
                SetDirty(match.Id, true);
                OnGainedItem(match.Id, itemId, itemCount);
                return;
            }
        }

        InternalAddItem(itemId, itemCount);
    }

    private void InternalAddItem(int itemId, int itemCount)
    {
        UserData.Item newItem = new UserData.Item();
        newItem.Id = ++GUID;
        newItem.ItemId = itemId;
        newItem.Count = itemCount;
        m_items.Add(newItem);

        SetDirty(newItem.Id, true);
        OnGainedItem(newItem.Id, itemId, itemCount);
    }
    
    /// <summary>
    /// 지정된 아이템을 장착합니다.
    /// </summary>
    public bool EquipItem(UserData.Item item)
    {
        if (ItemTable.Instance.IsEquipable(item.ItemId))
        {
            int itemSlot = ItemTable.Instance.GetItemSlot(item.ItemId);
            if (m_equippedItems.ContainsKey(itemSlot) == false)
            {
                // 식별되지 않는 아이템 슬롯
                return false;
            }

            m_equippedItems[itemSlot] = item.Id;
            return true;
        }
        return false;
    }

    public bool EquipItem(long id)
    {
        UserData.Item item = Find(id);
        if (item != null)
            return EquipItem(item);
        return false;
    }

    /// <summary>
    /// 지정된 아이템을 해제합니다.
    /// </summary>
    public void UnEquipItem(UserData.Item item)
    {
        int itemSlot = ItemTable.Instance.GetItemSlot(item.ItemId);
        if (m_equippedItems.ContainsKey(itemSlot))
        {
            m_equippedItems[itemSlot] = 0;
        }
    }
    
    /// <summary>
    /// 지정된 아이템 Id에 해당하는 아이템을 해제합니다.
    /// </summary>
    public void UnEquipItem(long id)
    {
        var enumerator = m_equippedItems.GetEnumerator();
        while (enumerator.MoveNext())
        {
            if (enumerator.Current.Value == id)
            {
                m_equippedItems[enumerator.Current.Key] = 0;
                break;
            }
        }
    }

    /// <summary>
    /// 지정된 아이템의 장착여부를 반환합니다.
    /// </summary>
    public bool IsEquip(UserData.Item item)
    {
        return IsEquip(item.Id);
    }

    /// <summary>
    /// 지정된 아이템 Id에 해당하는 아이템의 장착여부를 반환합니다.
    /// </summary>
    public bool IsEquip(long id)
    {
        var enumerator = m_equippedItems.GetEnumerator();
        while (enumerator.MoveNext())
        {
            if (enumerator.Current.Value == id)
                return true;
        }

        return false;
    }
    
    /// <summary>
    /// 지정된 아이템 슬롯에 아이템이 장착되어있는지 여부를 반환합니다.
    /// </summary>
    public bool IsEquipWith(int itemSlot)
    {
        if (m_equippedItems.ContainsKey(itemSlot))
        {
            return (m_equippedItems[itemSlot] != 0);
        }
        return false;
    }

    private void OnGainedItem(long id, int itemId, int itemCount)
    {
        SimpleItem gainedItem = new SimpleItem();
        gainedItem.Id = id;
        gainedItem.ItemId = itemId;
        gainedItem.Count = itemCount;
        NotificationCenter.ItemLedger.Post(gainedItem);
    }

    /// <summary>
    /// 지정된 아이템 인덱스에 해당하는 아이템이 중첩되는지 여부를 반환합니다.
    /// </summary>
    public bool IsStackAble(int itemId)
    {
        return ItemTable.Instance.IsStackable(itemId);
    }
    
    /// <summary>
    /// 지정된 아이템 인덱스에 해당하는 아이템이 재화류인지 여부를 반환합니다.
    /// </summary>
    public bool IsGoods(int itemId)
    {
        Data.Item itemData = ItemTable.Instance.Find(itemId);
        return (ItemCategory)itemData.Category == ItemCategory.Goods;
    }

    //-------------------------------------------------------------------------
    //  ListAdapter
    //-------------------------------------------------------------------------
    #region ListAdapter

    public UserData.Item this[int index]
    {
        get
        {
            if (index < 0 || index >= m_items.Count)
                return null;
            return m_items[index];
        }
    }
    
    public int Count
    {
        get
        {
            return m_items.Count;
        }
    }

    public UserData.Item Find(long id)
    {
        for (int i = 0; i < m_items.Count; i++)
        {
            UserData.Item match = m_items[i];
            if (match.Id == id)
                return match;            
        }
        return null;
    }

    public void Remove(long id)
    {
        for (int i = 0; i < m_items.Count; i++)
        {
            UserData.Item match = m_items[i];
            if (match.Id == id)
            {
                m_items.RemoveAt(i);
                return;
            }
        }
    }

    public List<UserData.Item> GetItemList()
    {
        return m_items;
    }

    public List<UserData.Item> FindAll(int itemType)
    {
        List<UserData.Item> ret = new List<UserData.Item>();
        for (int i = 0; i < Count; i++)
        {
            UserData.Item match = m_items[i];
            Data.Item itemData = ItemTable.Instance.Find(match.ItemId);
            if (itemData.Type == itemType)
                ret.Add(match);
        }
        return ret;
    }

    public List<UserData.Item> FindAll(System.Predicate<UserData.Item> predicate)
    {
        List<UserData.Item> ret = new List<UserData.Item>();
        for (int i = 0; i < Count; i++)
        {
            UserData.Item match = m_items[i];
            if (predicate(match))
                ret.Add(match);            
        }
        return ret;
    }

    #endregion ListAdapter
}