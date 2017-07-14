/* 
 * GameController.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */
 
using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class GameController : SubscriberBase<SimpleItem>
{
    private MatchJudge m_matchJudge = null;
    private Actor m_player;
    public Actor Player
    {
        get
        {
            if (m_player == null)
                m_player = (Actor)EntityBase.Find(EntityType.Character, 1);
            return m_player;
        }
    }

    private RespawnPoint[] m_respawnPoints;

    private Team m_myTeam;
    private Team m_enemyTeam;

    private List<SimpleItem> m_gainedItems;
        
    public void Initialize()
    {
        m_matchJudge = new MatchJudge();
    }

    public IEnumerator BuildGame()
    {
        SetTeam();
        yield return SpawnCharacters();
        
        AddWinCondition(new TotalDestruction(m_enemyTeam));
        AddLoseCondition(new HpCondition(Player, CompareOperation.LessThanOrEqual, 0f));

        SetTarget(m_myTeam);
        SetTarget(m_enemyTeam);
    }

    private void SetTeam()
    {
        m_myTeam = Team.AddTeam(Team.kRedTeamId, "Player.Team");
        m_enemyTeam = Team.AddTeam(Team.kBlueTeamId, "Monster.Team");
    }

    private IEnumerator SpawnCharacters()
    {
        GameObject respawn = GameObject.FindGameObjectWithTag("Respawn");
        m_respawnPoints = respawn.GetComponentsInChildren<RespawnPoint>();

        GameObject prefab = Resources.Load("Prefabs/UI/HpBar") as GameObject;
        for (int i = 0; i < m_respawnPoints.Length; i++)
        {
            RespawnPoint each = m_respawnPoints[i];
            yield return each.AsyncSpwan();

            Actor spwanedEntity = (Actor)each.GetLastSpawnedEntity();
            spwanedEntity.Initialize();

            UIHpBar.Initialize(prefab, spwanedEntity);

            // @TODO: This code is temporary, It must be upgrade
            Team team = Team.GetTeam(each.Group);
            team.AddMember(spwanedEntity);
        }
    }

    private void SetTarget(Team team)
    {
        int count = team.GetMemberCount();
        for (int i = 0; i < count; i++)
        {
            Team.Member each = team.GetMemberAt(i);
            if (each == null || each.Actor == null)
                continue;

            if (each.Actor.FindNearestTarget())
            {
                each.Actor.LookAt(each.Actor.Target);
            }
        }
    }

    public void AddWinCondition(ICondition condition)
    {
        m_matchJudge.AddWinCondition(condition);
    }

    public void AddLoseCondition(ICondition condition)
    {
        m_matchJudge.AddLoseCondition(condition);
    }

    public void OnEntityDead(long entityId)
    {
        m_matchJudge.OnEntityDead(entityId);
    }

    public void StartGame()
    {

    }

    public void EndGame()
    {

    }

    public override void OnNext(SimpleItem value)
    {
        base.OnNext(value);

        if (m_gainedItems == null)
            m_gainedItems = new List<SimpleItem>();

        bool isContains = false;
        Data.Item itemData = ItemTable.Instance.Find(value.ItemId);
        if (itemData.Stackable)
        {
            for (int i = 0; i < m_gainedItems.Count; i++)
            {
                SimpleItem match = m_gainedItems[i];
                if (match.ItemId == value.ItemId)
                {
                    match.Count += value.Count;
                    m_gainedItems[i] = match;

                    isContains = true;
                    break;
                }
            }
        }

        if (!isContains)
            m_gainedItems.Add(value);
    }

    public List<SimpleItem> GetGainedItems()
    {
        if (m_gainedItems == null)
            m_gainedItems = new List<SimpleItem>();
        return m_gainedItems;
    }
}