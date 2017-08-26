
using UnityEngine;
using System.Collections;

public class GameStage : GameSystem.Stage, IObserver
{
    public const string LevelName = "Game";
    
    private GameController m_gameController;
    
    public override IEnumerator OnCrate(Intent savedInstanceState)
    {
        // Load Scenes
        AssetLoader.AddLevelLoadingRequest(LevelName, false);
        AssetLoader.AddLevelLoadingRequest("Woods", true);
        AssetLoader.AddUILoadingRequest(UIType.UIBattle);
        AssetLoader.AddUILoadingRequest(UIType.UIBattleResult);
        yield return AssetLoader.StartLoading();
        
        m_gameController = new GameController();
        m_gameController.Initialize();
        yield return m_gameController.BuildGame();
        
        // Add First Responder
        NotificationCenter.Instance.AddObserver(this);
        
        yield return null;
    }

    public override void OnStart()
    {
        base.OnStart();
        UIManager.Instance.Show(UIType.UIBattle);
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
        UIManager.Instance.DestroyUI(UIType.UIBattleResult);
        NotificationCenter.Instance.RemoveObserver(this);
    }
}
