/* 
 * UIActiveSkill.cs
 * 
 * Writer : user
 * Date   : 2017-09-30
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class UIActiveSkill : UIBase 
{
    [System.Serializable]
    public struct View
    {
        public Transform ActiveEquip;
    }
    public View m_view;

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        if (IsAssigned(m_view) == false) m_view = new View();
        this.Bind(ref m_view.ActiveEquip, "ActiveEquip");
    }


    public void SetActiveEquipSlots()
    {
        for(int i = 0; i < m_view.ActiveEquip.childCount; i++)
        {
            Transform child = m_view.ActiveEquip.GetChild(i);
            UIActiveCell activeCell;
        }
    }




}