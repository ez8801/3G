using System.Collections;
using GameSystem;
using UnityEngine;

/// <summary>
/// 타이틀 씬
/// </summary>
/// <see cref="UITitle"/>
/// <see cref="SceneType.TitleScene"/>
public class TitleScene : Scene
{
    public const string LevelName = "Title";
    
    public override string GetTitle()
    {
        return "TitleScene";
    }

    public override IEnumerator OnCrate(Intent savedInstanceState)
    {
        yield return AssetLoader.LoadAsset(AssetType.Scene, LevelName);
        SetContentView<UITitle>("Prefabs/UI/TitleUI");
        yield return null;
    }

    public override void OnStart()
    {
        base.OnStart();
        m_contentView.ReloadData();
    }

    public override void OnUpdate()
    {
        base.OnUpdate();

        bool isPressKey = false;
#if UNITY_EDITOR
        isPressKey = Input.GetMouseButton(0);
#else
        isPressKey = (Input.touchCount > 0);    
#endif

        if (isPressKey)
            SceneManager.Instance.ChangeScene(SceneType.LobbyScene);
    }
}
