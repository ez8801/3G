﻿
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GameScene : GameSystem.Scene, IObserver
{
    public const string LevelName = "Game";

    private MatchJudge m_matchJudge = new MatchJudge();

    private Actor m_player;
    private List<Actor> m_monsters;

    private Team m_playerTeam;
    private Team m_monsterTeam;

    private RespawnPoint[] m_respawnPoints;

    private UIBattle m_battleUI;
    
    public override IEnumerator OnCrate(Intent savedInstanceState)
    {
        // Load Scenes
        AssetLoader.AddLevelLoadingRequest(LevelName, false);
        AssetLoader.AddLevelLoadingRequest("Woods", true);
        yield return AssetLoader.StartLoading();
        
        m_battleUI = SetContentView<UIBattle>("Prefabs/UI/BattelUI");
        
        // Add First Responder
        NotificationCenter.Instance.AddObserver(this);

        // Team Setting
        m_playerTeam = Team.AddTeam(Team.kRedTeamId, "Player.Team");
        m_monsterTeam = Team.AddTeam(Team.kBlueTeamId, "Monster.Team");

        // Spawn Characters
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

        m_matchJudge.AddWinCondition(new TotalDestruction(m_monsterTeam));
        m_matchJudge.AddLoseCondition(new HpCondition(m_player, CompareOperation.LessThanOrEqual, 0f));
        yield return null;
    }

    public override void OnStart()
    {
        base.OnStart();
        
        SetTarget(m_playerTeam);
        SetTarget(m_monsterTeam);
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
    
    public void HandleNotification(Notification notification)
    {
        switch (notification.id)
        {
            case (int)Notification.Entity.OnDead:
                m_matchJudge.OnEntityDead(notification.longExtra);
                break;

            case (int)Notification.GameSystem.Win:
                GameSystem.SceneManager.Instance.ChangeScene(SceneType.LobbyScene);

                break;
        }
    }

    public override void OnStop()
    {
        base.OnStop();
        NotificationCenter.Instance.RemoveObserver(this);
    }
}
