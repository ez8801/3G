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

    public void InitWithData()
    {
        InitWith();
    }

    public void InitWithData(int a)//나중에 int a 를 심플 액티브로 교체해야함. 위는 유저데이터 액티브
    {
        InitWith();
    }

    public void InitWith()
    {

    }


}