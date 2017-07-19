/* 
 * DropItemTable.cs
 * 
 * Writer : bmw122
 * Date   : 2017-07-03
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */
 
using Data;
using System;
using System.Collections.Generic;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct DropItem
    {
        public int Id;

        /// <summary>
        /// 드랍 아이템 그룹 Id
        /// </summary>
        /// <seealso cref="Monster.DropGroupId"/>
        public int Group;

        /// <summary>
        /// 아이템 Id
        /// </summary>
        /// <seealso cref="Item.Id"/>
        public int ItemId;
        public int MinCount;
        public int MaxCount;
        public int Prob;
    }
}

/// <summary>
/// 아이템 드랍 테이블
/// 이 클래스는 상속할 수 없습니다.
/// </summary>
public sealed class DropItemTable : ArrayTable<DropItem>
{
    private static DropItemTable m_instance;
    public static DropItemTable Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new DropItemTable();
            return m_instance;
        }
    }

    public Dictionary<int, List<DropItem>> Dictionary
    {
        get
        {
            if (m_dictionary == null)
            {
                m_dictionary = new Dictionary<int, List<DropItem>>();
                for (int i = 0; i < m_container.Length; i++)
                {
                    DropItem dropItem = m_container[i];
                    if (m_dictionary.ContainsKey(dropItem.Group) == false)
                        m_dictionary.Add(dropItem.Group, new List<DropItem>());

                    m_dictionary[dropItem.Group].Add(dropItem);
                }
            }
            return m_dictionary;
        }
    }
    private Dictionary<int, List<Data.DropItem>> m_dictionary;

    public List<DropItem> GetDropGroup(int groupId)
    {
        if (Dictionary.ContainsKey(groupId))
            return Dictionary[groupId];
        return null;
    }
}