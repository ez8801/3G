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

    // @TODO: Temporary
    private static int GUID = 0;

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

    public void AddItem(int itemId, int itemCount)
    {
        if (IsStackAble(itemId))
        {
            AddStackAbleItem(itemId, itemCount);
        }
        else
        {
            InternalAddItem(itemId, itemCount);
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
    }

    /// <summary>
    /// 지정된 아이템 인덱스에 해당하는 아이템이 중첩되는지 여부를 반환합니다.
    /// </summary>
    public bool IsStackAble(int itemId)
    {
        Data.Item itemData = ItemTable.Instance.Find(itemId);
        return itemData.Stackable;
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

    #endregion ListAdapter
}