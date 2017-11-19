/* 
 * UIPvpRoomCell.cs
 * 
 * Writer : user
 * Date   : 2017-10-31
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class UIPvpRoomCell : UIBase 
{
    // 셀은 텍스트 두개로 이루어짐. 방 번호와 방 이름
    [System.Serializable]
    public struct View
    {
        public UILabel LblRoomNum;
        public UILabel LblRoomName;
    }
    public View m_view;


    private UIEventListener.VoidDelegate m_onClickListener;

    private bool m_isSelected;

    private SimplePvpRoom m_pvpRoom;
    private bool m_isFull;

    public void Initilize()
    {
        BindComponents();

        m_isSelected = false;
        m_isFull = false;
    }

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        if (!IsAssigned(m_view))
            m_view = new View();
        this.Bind(ref m_view.LblRoomNum, "LblRoomNum");
        this.Bind(ref m_view.LblRoomName, "LblRoomName");
    }

    public void SetData(SimplePvpRoom room)
    {
        
        m_view.LblRoomNum.SetTextSafely(string.Format("{0}", room.RoomId));
        m_view.LblRoomName.SetTextSafely(room.RoomName);
        Debug.Log("Room Cell");
    }

    public bool IsFull()
    {
        return m_isFull;
    }

    public void SetSelection(bool isSelect)
    {
        m_isSelected = isSelect;
    }

   

    public void SetOnClickListener(UIEventListener.VoidDelegate I)
    {
        m_onClickListener = I;
    }

    #region UIActions

    private void OnClick()
    {
        if (m_onClickListener != null)
            m_onClickListener(gameObject);
    }

    #endregion UIActions


}