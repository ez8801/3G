/* 
 * Monster.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections.Generic;

public class Monster : Actor 
{
    private Data.Monster m_monsterData;
    private Data.Stats m_statsData;
    
    private Stats m_stats;
    public override Stats Stats
    {
        get
        {
            return m_stats;
        }
    }
    
    public override void Initialize()
    {
        base.Initialize();
        m_monsterData = MonsterTable.Instance.Find(m_entityID.Id);
        m_statsData = StatsTable.Instance.Find(m_monsterData.StatsId);
        
        m_stats = new Stats();
        m_stats.Initialize(m_statsData);

        CurrentHp = m_stats.Hp;
    }

    public void DropItem()
    {
        List<Data.DropItem> dropItems = DropItemTable.Instance.GetDropGroup(m_monsterData.DropGroupId);
        if (Util.IsNullOrEmpty(dropItems) == false)
        {
            for (int i = 0; i < dropItems.Count; i++)
            {
                Data.DropItem each = dropItems[i];
                int seed = Random.Range(0, ConfigTable.Instance.MaxProb());
                
                if (seed <= each.Prob)
                {
                    Data.Item itemData = ItemTable.Instance.Find(each.ItemId);
                    if (!string.IsNullOrEmpty(itemData.Texture))
                    {
                        ItemEntity itemEntity = (ItemEntity)CharacterFactory.CreateEntity("Prefabs/Entity/DropItem");
                        itemEntity.InitWithData(each.ItemId, Random.Range(each.MinCount, each.MaxCount));
                        itemEntity.SetTarget(Target.CachedTransform);
                    }
                    
                }
            }
        }
    }

    public override void OnDead()
    {
        DropItem();
        base.OnDead();
    }
}