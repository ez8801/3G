using UnityEngine;
using System.Collections.Generic;

/// <summary>
/// 월드 UI
/// </summary>
/// <seealso cref="UIType.UIWorld"/>
public class UIWorld : UIBase
{
	[System.Serializable]
	public struct View
	{
		public UILabel LblWorld;
		public Transform Stages;
		public Transform TexBG;
        public GameObject BtnClose;
	}
	public View m_view;

    private int m_worldId;
    private List<Data.Stage> m_stages;

    private int m_selectedIndex;

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        if (!IsAssigned(m_view))
            m_view = new View();
        this.Bind(ref m_view.LblWorld, "LblWorld");
        this.Bind(ref m_view.Stages, "Stages");
        this.Bind(ref m_view.TexBG, "TexBG");
        this.Bind(ref m_view.BtnClose, "BtnClose");
    }

    internal override void OnCreate()
    {
        base.OnCreate();
        BindComponents();
    }
    
    internal override void OnStart()
    {
        base.OnStart();
        Debug.LogWarning(Macros.__PRETTY_FUNCTION__);

        m_selectedIndex = 1;

        ReloadData();
    }

    public void SetData(int worldId)
    {
        Debug.LogWarning(Macros.__PRETTY_FUNCTION__);

        m_worldId = worldId;
        m_stages = StageTable.Instance.GetStages(worldId);
    }

    public override void ReloadData()
    {
        base.ReloadData();

        Data.World worldData = WorldTable.Instance.Find(m_worldId);
        m_view.LblWorld.SetTextSafely(R.GetText(worldData.Name));

        for (int i = 0; i < m_view.Stages.childCount; i++)
        {
            Transform child = m_view.Stages.GetChild(i);
            UIEventListener.Get(child.gameObject).onClick = OnClickStage;

            Data.Stage stageData = m_stages[i];
            
            UILabel lblStage = Util.FindComponent<UILabel>(child, "LblStage");
            lblStage.SetTextSafely(R.GetText(stageData.Name));

            UISprite sprCurrent = Util.FindComponent<UISprite>(child, "SprCurrent");
            sprCurrent.SetActiveSafely(stageData.Id == m_selectedIndex);
        }
    }

    //-------------------------------------------------------------------------
    //  UIActions
    //-------------------------------------------------------------------------
    #region UIActions

    private void OnClickStage(GameObject go)
    {
        int index = -1;
        if (!int.TryParse(go.name, out index))
            return;

        UIStageInfo stageInfoUI 
            = UIManager.Instance.RequireUI<UIStageInfo>(UIType.UIStageInfo);
        stageInfoUI.SetData(m_worldId, index + 1);
        UIManager.Instance.Push(UIType.UIStageInfo);
    }

    public void OnClickClose()
    {
        Hide();
    }
    #endregion UIActions
}
