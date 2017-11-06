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

public class UIPvpRoomCell : MonoBehaviour 
{
    // 셀은 텍스트 두개로 이루어짐. 방 번호와 방 이름
    public UILabel LblRoomNum;
    public UILabel LblRoomName;

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
        this.Bind(ref LblRoomNum, "LblRoomNum");
        this.Bind(ref LblRoomName, "LblRoomName");
    }

    public void SetData(SimplePvpRoom room)
    {
        if (m_isFull == false)
            gameObject.SetActive(true);
        LblRoomNum.SetTextSafely(string.Format("{0}", room.RoomId));
        LblRoomName.SetTextSafely(room.RoomName);
    }

    public bool IsFull()
    {
        return m_isFull;
    }

    public void SetSelection(bool isSelect)
    {
        m_isSelected = isSelect;
    }

    public void Disable()
    {
        LblRoomName.SetActiveSafely(false);
        LblRoomNum.SetActiveSafely(false);
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