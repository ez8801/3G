/* 
 * Monster.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

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

    public override void Initialize(EntityType entityType, int entityId)
    {
        base.Initialize(entityType, entityId);
        m_monsterData = MonsterTable.Instance.Find(entityId);
        m_statsData = StatsTable.Instance.Find(m_monsterData.StatsId);

        m_stats = new Stats();
        m_stats.Initialize(m_statsData);

        CurrentHp = m_stats.Hp;
    }
}