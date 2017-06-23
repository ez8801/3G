using GameSystem;
using System.Collections;

/// <summary>
/// 로비 씬
/// </summary>
/// <see cref="SceneType.LobbyScene"/>
public class LobbyScene : Scene
{
    public const string LevelName = "Lobby";

    private UILobby m_lobbyUI;

    public override IEnumerator OnCrate(Intent savedInstanceState)
    {
        yield return AssetLoader.LoadAsset(AssetType.Scene, LevelName);
        m_lobbyUI = SetContentView<UILobby>("Prefabs/UI/LobbyUI");
        UIBase.NavigationBar.ReloadData();
        yield return null;
    }

    public override void OnStart()
    {
        base.OnStart();

    }
}
