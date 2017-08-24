/* 
 * UIBattleResult.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-13
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections.Generic;

/// <summary>
/// 전투 결과 UI
/// </summary>
public class UIBattleResult : UIBase
{
	[System.Serializable]
	public struct View
	{
		public UITexture TexIcon;
		public UILabel LblTitle;
		public UILabel LblLevel;
		public Transform Items;
		public UISprite SprGauge;
	}
	public View m_view;

	public override void Initialize()
	{		
        BindComponents();
    }

    public void SetResult(MatchResult matchResult, List<SimpleItem> gainedItems)
    {
        int childCount = m_view.Items.childCount;
        for (int i = 0; i < childCount; i++)
        {
            Transform child = m_view.Items.GetChild(i);
            UIItemCell itemCellUI = Util.FindInChildren<UIItemCell>(child);
            itemCellUI.Initialize();

            bool isAssigned = (i < gainedItems.Count);
            if (isAssigned)
            {
                itemCellUI.SetData(gainedItems[i]);
            }
            else
            {
                itemCellUI.Disable();
            }
        }

        TweenScale ts = Util.FindInChildren<TweenScale>(gameObject);
        ts.method = UITweener.Method.EaseOut;
    }

    [ContextMenu("Bind")]
    private void BindComponents()
    {
        if (!IsAssigned(m_view))
            m_view = new View();
        this.Bind(ref m_view.TexIcon, "Pop/TexIcon");
        this.Bind(ref m_view.LblTitle, "Pop/LblTitle");
        this.Bind(ref m_view.LblLevel, "Pop/LblLevel");
        this.Bind(ref m_view.Items, "Pop/Items");
        this.Bind(ref m_view.SprGauge, "Pop/XpBar/SprGauge");
    }

    public void OnClickOK()
    {
        NotificationCenter.Post(R.Id.ExitStage);
        Destroy(gameObject);
    }
}
