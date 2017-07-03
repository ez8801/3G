/* 
 * Character.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

public class Character : Actor 
{
    private Data.Character m_characterData;
    private Data.Stats m_statsData;

    private Stats m_stats;
    public override Stats Stats
    {
        get
        {
            return m_stats;
        }
    }

    protected override void Awake()
    {
        base.Awake();

        Camera mainCamera = Camera.main;
        CharacterFollow follower 
            =  Util.RequireComponent<CharacterFollow>(mainCamera.gameObject);

        follower.target = transform;
    }
    
    public override void Initialize()
    {
        base.Initialize();
        m_characterData = CharacterTable.Instance.Find(m_entityID.Id);
        m_statsData = StatsTable.Instance.Find(m_characterData.StatsId);

        m_stats = new Stats();
        m_stats.Initialize(m_statsData);

        CurrentHp = m_stats.Hp;
    }


}