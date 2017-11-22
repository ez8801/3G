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
    private Client m_client;
    public UITexture TexActiveIcon;
    public UILabel LblActiveLevel;
    public UITexture SkillFilter;
    private UIEventListener.VoidDelegate m_onClickListener;
    private int m_skillId;

    private float currentCoolTime;
    public float coolTime;

    private bool canUseSkill = true;

    public void Initialize()
    {
        m_client = Client.Instance;
        BindComponents();
        SkillFilter.fillAmount = 0;
        
    }

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        this.Bind(ref TexActiveIcon, "TexActiveIcon");
        this.Bind(ref LblActiveLevel, "LblActiveLevel");
        this.Bind(ref SkillFilter, "SkillFilter");
    }

    public void SetData(UserData.Active active)
    {
        SetData(active.Id, active.ActiveId, active.Cooltime);
    }

    public void SetData(SimpleActive active)
    {
        SetData(active.Id, active.ActiveId, active.Cooltime);
    }

    public void SetData(long id, int activeId, int ActiveCooltime)
    {
        Data.Skill activeData = SkillTable.Instance.Find(activeId);
        m_skillId = activeId;
        if (!string.IsNullOrEmpty(activeData.Texture))
        {
            TexActiveIcon.SetActiveSafely(true);
            TexActiveIcon.mainTexture = Resources.Load<Texture2D>(activeData.Texture);

            LblActiveLevel.SetActiveSafely(true);
            LblActiveLevel.SetTextSafely(string.Concat("Cool:", ActiveCooltime));

            coolTime = ActiveCooltime;
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

    
    public void SetOnClickListener(UIEventListener.VoidDelegate l)
    {
        m_onClickListener = l;
    }

    private void OnClick()
    {
        if (m_onClickListener != null && canUseSkill)
        {
            m_onClickListener(gameObject);
            UseSkill();
        }
            
        Debug.Log("Use Skill");
    }

    public void UseSkill()
    {
        SkillFilter.fillAmount = 1;
        StartCoroutine("CoolTime");
        GameObject Player = GameObject.FindGameObjectWithTag("Player");
        Player.gameObject.GetComponent<SkillManager>().GetSkill(m_skillId);
        m_client.SendUseSkill(Nettention.Proud.RmiContext.ReliableSend, m_skillId);
        //PVP일 경우를 체크해서
        //PVP일 경우 여기서 스킬 사용 패킷을 보내준다
        canUseSkill = false;
    }
    
    IEnumerator CoolTime()
    {
        while(SkillFilter.fillAmount > 0)
        {
            SkillFilter.fillAmount -= 1 * Time.smoothDeltaTime / coolTime;

            yield return null;
        }

        canUseSkill = true;

        yield break;
    }

}