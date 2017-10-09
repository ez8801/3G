/* 
 * UIBattleActive.cs
 * 
 * Writer : user
 * Date   : 2017-10-09
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class UIBattleActive : UIBase 
{
    [System.Serializable]
    public struct View
    {
        public Transform PanelCell;
    }
    public View m_view;

    private List<Data.Active> m_actives;

    public void ReloadActiveList(int numOfActive, List<Data.Active> activeList)
    {
        for (int i = 0; i < numOfActive; i++)
        {
            m_actives[i] = activeList[i];
        }

    }

    internal override void OnCreate()
    {
        base.OnCreate();
        BindComponents();

        int activeCount = (m_actives != null) ? m_actives.Count : 0;
        for(int i = 0; i < m_view.PanelCell.childCount; i++)
        {
            Transform child = m_view.PanelCell.GetChild(i);
            child.SetActiveSafely(i < activeCount);

            UIActiveCell activeCellUI = Util.FindInChildren<UIActiveCell>(child);
            activeCellUI.Initialize();
            if(i < activeCount)
            {
                Data.Active active = m_actives[i];
                activeCellUI.SetData(0, active.Id, active.Level);
            }
            else
            {
                activeCellUI.Disable();
            }

            //10_09 일 요기까지 하고있었ㅇ,ㅁ
        }
    }

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        if (!IsAssigned(m_view))
            m_view = new View();

        this.Bind(ref m_view.PanelCell, "PanelCell");
    }


}