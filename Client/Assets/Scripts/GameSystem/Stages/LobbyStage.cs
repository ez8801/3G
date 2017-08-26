using GameSystem;
using System.Collections;

/// <summary>
/// 로비 씬
/// </summary>
/// <see cref="StageType.LobbyStage"/>
public class LobbyStage : Stage
{
    public const string LevelName = "Lobby";
    
    public override IEnumerator OnCrate(Intent savedInstanceState)
    {
        AssetLoader.AddLevelLoadingRequest(LevelName, false);
        AssetLoader.AddUILoadingRequest(UIType.UILobby);
        AssetLoader.AddUILoadingRequest(UIType.UINavigationBar);
        yield return AssetLoader.StartLoading();
    }

    public override void OnStart()
    {
        base.OnStart();
        UIManager.Instance.Show(UIType.UINavigationBar);
        UIManager.Instance.Show(UIType.UILobby);
    }

    public override void OnStop()
    {
        base.OnStop();
        UIManager.Instance.DestroyUI(UIType.UINavigationBar);
        UIManager.Instance.DestroyUI(UIType.UILobby);
    }
}
