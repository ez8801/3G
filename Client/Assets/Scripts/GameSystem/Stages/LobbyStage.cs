using GameSystem;
using System.Collections;

/// <summary>
/// 로비 씬
/// </summary>
/// <see cref="StageType.LobbyStage"/>
public class LobbyStage : Stage
{
    public const string LevelName = "Lobby";

    private UILobby m_lobbyUI;

    public override IEnumerator OnCrate(Intent savedInstanceState)
    {
        UIBase.LoadingUI.ShowLoadingUI(true);
        UIBase.LoadingUI.SetProgress(0.1f);
        yield return YieldHelper.PointTwoSeconds;

        yield return AssetLoader.LoadAsset(AssetType.Scene, LevelName);
        UIBase.LoadingUI.SetProgress(0.5f);

        yield return YieldHelper.PointTwoSeconds;
        m_lobbyUI = SetContentView<UILobby>("Prefabs/UI/LobbyUI");
        UIBase.NavigationBar.ReloadData();

        UIBase.LoadingUI.SetProgress(1f);

        yield return null;
    }

    public override void OnStart()
    {
        base.OnStart();

    }
}
