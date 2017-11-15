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
        //지금은 테스트로 13아이디의 스킬을 하나 리스트에 넣어줬음.
        //서버에서 리스트 받아옴.
        Data.Skill skill = SkillTable.Instance.Find(13);
        Data.Skill skilltwo = SkillTable.Instance.Find(3000002);
        m_actives.Add(skill);
        m_actives.Add(skilltwo);
        Debug.Log(m_actives[0].Cooltime);
    }

    


    #region UIActions
    public void OnClickActive(GameObject sender)
    {
        Debug.Log("dfsdfsdfsdfsdfsdf");
        int index = -1;
        if(int.TryParse(sender.name, out index))
        {
            Data.Skill clickedActive = m_actives[index];
            Data.Prefab prefabActive = PrefabTable.Instance.Find(clickedActive.PrefabId);
            //서버 : 여기서 서버로 signal 날림 (playerID, 1(Active스킬을 뜻함) ,ActiveID)
            //지금 당장은 로컬에서 작업함. 로컬에서는 Effect라는 프리팹의 경로를 테이블에 저장해 뒀다가
            //불러와서 그 경로의 프리팹 투사체를 불러옴.

            Debug.Log(prefabActive.PrefabName);
            switch (clickedActive.Type)
            {
                case 1:
                    GameObject prefab = Resources.Load(prefabActive.PrefabName) as GameObject;
                    GameObject PJ = Instantiate(prefab) as GameObject;
                    break;
                case 2:


                    break;

            }

        }

    }



    #endregion UIActions
}