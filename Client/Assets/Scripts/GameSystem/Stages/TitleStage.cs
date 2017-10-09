using System.Collections;
using GameSystem;
using UnityEngine;

/// <summary>
/// 타이틀 씬
/// </summary>
/// <see cref="UITitle"/>
/// <see cref="StageType.TitleStage"/>
public class TitleStage : Stage
{
    public const string LevelName = "Title";
    
    public override string GetTitle()
    {
        return "TitleStage";
    }

    public override IEnumerator OnCrate(Intent savedInstanceState)
    {
        AssetLoader.AddLevelLoadingRequest(LevelName, false);
        AssetLoader.AddUILoadingRequest(UIType.UITitle);
        yield return AssetLoader.LoadAsset(AssetType.Scene, LevelName);
    }

    public override void OnStart()
    {
        base.OnStart();
        UIManager.Instance.Show<UITitle>(UIType.UITitle);
    }

    public override void OnUpdate()
    {
        base.OnUpdate();

        bool isPressKey = false;
#if UNITY_EDITOR
        isPressKey = Input.GetMouseButtonUp(0);
#else
        isPressKey = (Input.touchCount > 0);    
#endif

        if (isPressKey)
            StageManager.Instance.ChangeStage(StageType.LobbyStage);
    }

    public override void OnStop()
    {
        base.OnStop();
        UIManager.Instance.DestroyUI(UIType.UITitle);
    }
}
