/* 
 * BattleStage.cs
 * 
 * Writer : user
 * Date   : 2017-11-21
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class BattleStage : GameSystem.Stage, IObserver
{

    public const string LevelName = "Battle";
    private Client m_client;
    private GameController m_gameController;

    public override IEnumerator OnCrate(Intent savedInstanceState)
    {
        m_client = Client.Instance;
        // Load Scenes
        AssetLoader.AddLevelLoadingRequest(LevelName, false);
        AssetLoader.AddLevelLoadingRequest("Stones", true);
        AssetLoader.AddUILoadingRequest(UIType.UIBattle);
        AssetLoader.AddUILoadingRequest(UIType.UIBattleActive);
        AssetLoader.AddUILoadingRequest(UIType.UIBattleResult);
        yield return AssetLoader.StartLoading();

        m_gameController = new GameController();
        m_gameController.Initialize();
        yield return m_gameController.BuildGame();

        // Add First Responder
        NotificationCenter.Instance.AddObserver(this);
        // 여기서 내 스탯을 상대방에게 보내준다.
        StatManager statManager = GameObject.Find("StatManager").GetComponent<StatManager>();
        Data.Stats stat = statManager.CharacterStats;
        m_client.SendMyInfoToEnermy(Nettention.Proud.RmiContext.ReliableSend, stat.Id, stat.Hp, stat.AttackDamage, stat.Armor);

        yield return null;
    }

    public override void OnStart()
    {
        base.OnStart();
        UIManager.Instance.Show(UIType.UIBattle);
        UIManager.Instance.Show(UIType.UIBattleActive);
    }

    public void HandleNotification(Notification notification)
    {
        switch (notification.id)
        {
            case R.Id.OnEntityDead:
                m_gameController.OnEntityDead(notification.longExtra);
                break;

            case R.Id.OnEntityAttacked:
                m_gameController.OnEntityAttacked(notification.longExtra);
                m_client.DamagedPacket(Nettention.Proud.RmiContext.ReliableSend, 10, 100);
                break;

            case R.Id.Win:
                StartCoroutine(OnGameEnd(MatchResult.Win));
                break;

            case R.Id.ExitStage:
                GameSystem.StageManager.Instance.ChangeStage(StageType.LobbyStage);
                break;
        }
    }

    private IEnumerator OnGameEnd(MatchResult result)
    {
        //결투 결과 창으로 변경해야함
        yield return YieldHelper.PointTwoSeconds;
        while (EntityBase.Count(EntityType.Item) != 0)
        {
            yield return null;
        }

        UIManager.Instance.HideUI(UIType.UIBattle);

        UIBattleResult battleResultUI
            = UIManager.Instance.Show<UIBattleResult>(UIType.UIBattleResult);
        battleResultUI.SetResult(result, m_gameController.GetGainedItems());
    }

    public override void OnStop()
    {
        base.OnStop();
        UIManager.Instance.DestroyUI(UIType.UIBattle);
        UIManager.Instance.DestroyUI(UIType.UIBattleActive);
        UIManager.Instance.DestroyUI(UIType.UIBattleResult);
        NotificationCenter.Instance.RemoveObserver(this);
    }
}