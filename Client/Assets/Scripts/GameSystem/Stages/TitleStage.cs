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
    private Client m_client;
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
        m_client = Client.Instance;
        UIManager.Instance.Show<UITitle>(UIType.UITitle);
    }

    public override void OnUpdate()
    {
        base.OnUpdate();

        bool isPressKey = false;
        
#if UNITY_EDITOR
        isPressKey = Input.GetMouseButtonUp(0);
#else
        isPressKey = Input.GetMouseButtonUp(0);
        //isPressKey = (Input.touchCount > 0);
        
#endif
        //Debug.Log("ServerConnect Request");
        if (isPressKey)
        {
            
            // 서버에 연결하는 코드
            //서버 연결 안타고 다음 화면으로 넘어가려면 아래 코드 지우시오 - NoServer
            ///*
            m_client.ServerIP = "121.131.147.109"; // m_client 에 서버아이피를 설정.
            m_client.userName = ""; // m_client 에 닉네임을 설정.
            m_client.userPassword = "";
            Debug.Log("ServerConnect Request");
            m_client.Connect(); // 서버에 접속 요청.
            m_client.IsWait = true;

            
            
            //*/
            // 시작에 필요한 기본 데이터 여기서 요청
            
            // 데이터 로드가 끝나면 change scene
            //서버 연결 안타고 다음 화면으로 넘어가려면 아래 주석 지우면됨 - NoServer
            //StageManager.Instance.ChangeStage(StageType.LobbyStage);
        }
    }

    public override void OnStop()
    {
        base.OnStop();
        UIManager.Instance.DestroyUI(UIType.UITitle);
    }
}
