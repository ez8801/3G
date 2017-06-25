/* 
 * Inventory.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ SHAprojectVer001. DefaultCompany, All rights reserved
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

    // @TODO: Temporary
    private static int GUID = 0;

    public void AddItem(int itemId, int itemCount)
    {
        if (IsStackAble(itemId))
        {
            AddStackAbleItem(itemId, itemCount);
        }
        else
        {
            UserData.Item newItem = new UserData.Item();
            newItem.Id = ++GUID;
            newItem.ItemId = itemId;
            newItem.Count = itemCount;
            m_items.Add(newItem);
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
                return;
            }
        }

        UserData.Item newItem = new UserData.Item();
        newItem.Id = ++GUID;
        newItem.ItemId = itemId;
        newItem.Count = itemCount;
        m_items.Add(newItem);
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
    


    #endregion ListAdapter
}