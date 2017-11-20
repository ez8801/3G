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

    public class Active
    {
        public long Id;
        public int ActiveId;
        public int Cooltime;
    }
}



public class Inventory
{
    private Client m_client;
    private List<UserData.Item> m_items = new List<UserData.Item>();
    private Dictionary<long, bool> m_dirtyFlags = new Dictionary<long, bool>();

    private Dictionary<int, long> m_equippedItems = new Dictionary<int, long>();

    // @TODO: Temporary
    private static int GUID = 0;
    public void decGUID()
    {
        GUID--;
    }

    public Inventory()
    {
        m_client = Client.Instance;
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
    public void SetItem(int inId, int itemId, int itemCount)
    {
        if (IsGoods(itemId))
        {
            AddGoodsItem(itemId, itemCount);
            OnGainedItem(0, itemId, itemCount);
        }
        else if (IsStackAble(itemId))
        {
            InternalAddItemFromDB(inId, itemId, itemCount);
        }
        else
        {
            InternalAddItemFromDB(inId, itemId, itemCount);
        }
    }

    public void AddItem(int itemId)
    {
        AddItem(itemId, 1);
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
            int newitemId;
            newitemId = InternalAddItem(itemId, itemCount);
            //NoServer
            m_client.AddItemToInventory(Nettention.Proud.HostID.HostID_Server, Nettention.Proud.RmiContext.UnreliableSend, MyInfo.Account.NickName, newitemId, itemId, itemCount, 0);
        }
    }

    public void AddGoodsItem(int itemId, int itemCount)
    {
        Data.Item itemData = ItemTable.Instance.Find(itemId);
        switch ((ItemType) itemData.Type)
        {
            case ItemType.Gold:
                m_client.AddGold(Nettention.Proud.HostID.HostID_Server, Nettention.Proud.RmiContext.UnreliableSend, MyInfo.Account.NickName, itemCount);
                MyInfo.Account.Gold += itemCount;
                break;

            case ItemType.Exp:
                MyInfo.Account.Exp += itemCount;
                break;
        }
    }

    public bool AddStackAbleItem(int itemId, int itemCount)
    {
     
        for (int i = 0; i < m_items.Count; i++)
        {
            UserData.Item match = m_items[i];
            if (match.ItemId == itemId)
            {
                match.Count += itemCount;
                SetDirty(match.Id, true);
                OnGainedItem(match.Id, itemId, itemCount);
                m_client.AddItemToInventory(Nettention.Proud.HostID.HostID_Server, Nettention.Proud.RmiContext.UnreliableSend, MyInfo.Account.NickName, (int)match.Id, itemId, itemCount, 1);
                return true;
            }
        }
        int newitemId;
        newitemId = InternalAddItem(itemId, itemCount);
        m_client.AddItemToInventory(Nettention.Proud.HostID.HostID_Server, Nettention.Proud.RmiContext.UnreliableSend, MyInfo.Account.NickName, newitemId , itemId, itemCount , 0);
        return false;
    }

    private int InternalAddItem(int itemId, int itemCount)
    {
        UserData.Item newItem = new UserData.Item();
        newItem.Id = ++GUID;
        newItem.ItemId = itemId;
        newItem.Count = itemCount;
        m_items.Add(newItem);

        SetDirty(newItem.Id, true);
        OnGainedItem(newItem.Id, itemId, itemCount);
        return (int)newItem.Id;
    }

    public bool AddStackAbleItemFromDB(int itemId, int itemCount)
    {
        for (int i = 0; i < m_items.Count; i++)
        {
            UserData.Item match = m_items[i];
            if (match.ItemId == itemId)
            {
                match.Count += itemCount;
                SetDirty(match.Id, true);
                OnGainedItem(match.Id, itemId, itemCount);
                return true;
            }
        }
        
        InternalAddItem(itemId, itemCount);
        return false;
    }
    private void InternalAddItemFromDB(int inId, int itemId, int itemCount)
    {
        UserData.Item newItem = new UserData.Item();
        newItem.Id = inId;
        newItem.ItemId = itemId;
        newItem.Count = itemCount;
        m_items.Add(newItem);

        SetDirty(newItem.Id, true);
        OnGainedItem(newItem.Id, itemId, itemCount);
        GUID = inId;
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
            if(itemSlot == 4)
            {
                //블루 엑티브.
            }
            if (itemSlot == 5)
            {
                //그린 엑티브.
            }
            if (itemSlot == 6)
            {
                //레드 엑티브.
            }
            m_client.SendEquipInfo(Nettention.Proud.HostID.HostID_Server, Nettention.Proud.RmiContext.UnreliableSend, MyInfo.Account.NickName, (int)m_equippedItems[1], (int)m_equippedItems[2], (int)m_equippedItems[3]);
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
    public bool EquipItemFromDB(long id)
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
        m_client.SendEquipInfo(Nettention.Proud.HostID.HostID_Server, Nettention.Proud.RmiContext.UnreliableSend, MyInfo.Account.NickName, (int)m_equippedItems[1], (int)m_equippedItems[2], (int)m_equippedItems[3]);
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
                m_client.SendEquipInfo(Nettention.Proud.HostID.HostID_Server, Nettention.Proud.RmiContext.UnreliableSend, MyInfo.Account.NickName, (int)m_equippedItems[1], (int)m_equippedItems[2], (int)m_equippedItems[3]);
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

    /// <summary>
    /// 지정된 아이템 Id에 해당하는 아이템을 소모합니다.
    /// </summary>
    public void ConsumeItem(long id, int itemCount)
    {
        UserData.Item item = Find(id);

        // @TODO: Validation
        item.Count -= itemCount;
        m_client.UseItemFromInventory(Nettention.Proud.HostID.HostID_Server, Nettention.Proud.RmiContext.UnreliableSend, MyInfo.Account.NickName, (int)id, item.ItemId,itemCount, 1);
        if (item.Count < 0)
        {
            Remove(id);
        }        
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