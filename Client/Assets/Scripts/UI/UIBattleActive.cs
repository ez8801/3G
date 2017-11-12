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
    
    public List<Data.Skill> m_actives;
    //public Data.Skill m_activeTestOne = SkillTable.Instance.Find(30000001);
    //public Data.Skill m_activeTestTwo = SkillTable.Instance.Find(30000002);

    public void ReloadActiveList(int numOfActive, List<Data.Skill> activeList)
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

        GetActiveList();
        //UserData.Active m_activeTest = SkillTable.Instance.Find();
        //m_actives[0] = m_activeTest;
        
        int activeCount = (m_actives != null) ? m_actives.Count : 0;
        for(int i = 0; i < m_view.PanelCell.childCount; i++)
        {
            Transform child = m_view.PanelCell.GetChild(i);
            child.SetActiveSafely(i < activeCount);

            UIActiveCell activeCellUI = Util.FindInChildren<UIActiveCell>(child);
            activeCellUI.Initialize();
            if (i < activeCount)
            {
                Data.Skill active = m_actives[i];
                activeCellUI.SetData(0, active.Id, active.Cooltime);
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


    private void GetActiveList()
    {

        //testCode : 지정된 리스트를 넣어줌.. 이후 ActiveEquip창에서 리스트 갱신된걸 불러와야함.
        Data.Skill skill = SkillTable.Instance.Find(13);
        m_actives.Add(skill);
        Debug.Log(m_actives[0].Cooltime);
    }

    private void OnClickActive(GameObject sender)
    {
        int index = -1;
        if(int.TryParse(sender.name, out index))
        {
            Data.Skill clickedActive = m_actives[index];
            //서버 : 여기서 서버로 signal 날림 (playerID, 1(Active스킬을 뜻함) ,ActiveID)

        }
    }
}