using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class UIPassiveCell : MonoBehaviour 
{
    // 장착된 패시브 락
    public GameObject EquipLock;
    public UITexture TexPassiveIcon;
    //패시브 스킬랩
    public UILabel LblPassiveLevel;

    private UIEventListener.VoidDelegate m_onClickListener;

    public void Initialize()
    {
        BindComponents();
    }

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        this.Bind(ref EquipLock, "EquipLock");
        this.Bind(ref TexPassiveIcon, "TexPassiveIcon");
        this.Bind(ref LblPassiveLevel, "LblPassiveLevel");
    }

    public void InitWithData(UserData.PassiveSkill passive)
    {
        InitWith(passive.Id, passive.PassiveId, passive.Level);
    }

    public void InitWithData(SimplePassive passive)
    {
        InitWith(passive.Id, passive.PassiveId, passive.Level);
    }
    public void InitWith(long id, int passiveId, int passiveLevel)
    {

        Data.PassiveSkill passiveData = PassiveSkillTable.Instance.Find(passiveId);
        if (!string.IsNullOrEmpty(passiveData.Texture))
        {
            TexPassiveIcon.SetActiveSafely(true);
            TexPassiveIcon.mainTexture = Resources.Load<Texture2D>(passiveData.Texture);
        }
        LblPassiveLevel.SetActiveSafely(true);
        LblPassiveLevel.SetTextSafely(string.Concat("Lv.", passiveLevel));
        
        EquipLock.SetActiveSafely(false);
    }

    public void Disable()
    {
        TexPassiveIcon.SetActiveSafely(false);
        LblPassiveLevel.SetActiveSafely(false);
        EquipLock.SetActiveSafely(false);
    }

    public void SetOnClickListener(UIEventListener.VoidDelegate l)
    {
        m_onClickListener = l;
    }

    public void OnClick()
    {
        if (m_onClickListener != null)
            m_onClickListener(gameObject);
    }



}