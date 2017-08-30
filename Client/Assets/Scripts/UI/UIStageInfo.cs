using UnityEngine;
using GameSystem;

/// <summary>
/// 스테이지 정보 UI
/// </summary>
/// <seealso cref="UIType.UIStageInfo"/>
public class UIStageInfo : UIBase
{
	[System.Serializable]
	public struct View
	{
		public UILabel LblWorld;
		public UILabel LblStage;
		public UIEventListener BtnClose;
		public UIEventListener BtnStart;
		public UILabel LblGoldReward;
	}
	public View m_view;

    private int m_worldId;
    private int m_stageId;

    internal override void OnCreate()
    {
        base.OnCreate();
        BindComponents();
    }

    [ContextMenu("Bind")]
	public void BindComponents()
	{
        if (!IsAssigned(m_view))
            m_view = new View();
		this.Bind(ref m_view.LblWorld, "LblWorld");
		this.Bind(ref m_view.LblStage, "LblStage");
		this.Bind(ref m_view.BtnClose, "BtnClose");
		this.Bind(ref m_view.BtnStart, "BtnStart");
		this.Bind(ref m_view.LblGoldReward, "LblGoldReward");

        m_view.BtnClose.onClick += OnClickClose;
        m_view.BtnStart.onClick += OnClickStart;
    }

    public void SetData(int worldId, int stageId)
    {
        m_worldId = worldId;
        m_stageId = stageId;
    }

    //-------------------------------------------------------------------------
    //  UIActions
    //-------------------------------------------------------------------------
    #region UIActions

    private void OnClickClose(GameObject go)
    {
        UIManager.Instance.Pop();
    }

    private void OnClickStart(GameObject go)
    {
        StageManager.Instance.ChangeStage(StageType.GameStage);
    }

    #endregion UIActions
}
