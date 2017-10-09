/* 
 * UIActiveCell.cs
 * 
 * Writer : user
 * Date   : 2017-09-30
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class UIActiveCell : MonoBehaviour 
{
    public UITexture TexActiveIcon;
    public UILabel LblActiveLevel;

    private UIEventListener.VoidDelegate m_onClickListener;

    public void Initialize()
    {
        BindComponents();
    }

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        this.Bind(ref TexActiveIcon, "TexActiveIcon");
        this.Bind(ref LblActiveLevel, "LblActiveLevel");
    }

    public void SetData(UserData.Active active)
    {
        SetData(active.Id, active.ActiveId, active.Level);
    }

    public void SetData(SimpleActive active)
    {
        SetData(active.Id, active.ActiveId, active.Level);
    }

    public void SetData(long id, int activeId, int ActiveLevel)
    {
        Data.Active activeData = ActiveTable.Instance.Find(activeId);
        // @TODO: Set Item Info
        if (!string.IsNullOrEmpty(activeData.Texture))
        {
            TexActiveIcon.SetActiveSafely(true);
            TexActiveIcon.mainTexture = Resources.Load<Texture2D>(activeData.Texture);

            LblActiveLevel.SetActiveSafely(true);
            LblActiveLevel.SetTextSafely(string.Concat("Lv.", ActiveLevel));
        }
        else
        {
            TexActiveIcon.SetActiveSafely(false);
        }
    }

    public void Disable()
    {
        TexActiveIcon.SetActiveSafely(false);
        LblActiveLevel.SetActiveSafely(false);
    }


    #region UIActions
    public void SetOnClickListener(UIEventListener.VoidDelegate l)
    {
        m_onClickListener = l;
    }

    private void OnClick()
    {
        if (m_onClickListener != null)
            m_onClickListener(gameObject);
    }

    #endregion UIActions

}