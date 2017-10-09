/* 
 * UIItemCell.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

public class UIItemCell : MonoBehaviour
{
    public GameObject Lock;
    public UITexture TexIcon;
    public UILabel LblLevel;
    public UISprite SprSelect;
    public UISprite SprNew;
    public UILabel LblCount;
    public UISprite SprEquip;

    private UIEventListener.VoidDelegate m_onClickListener;

    private bool m_isSelected;

    public void Initialize()
    {
        BindComponents();

        m_isSelected = false;
    }

    [ContextMenu("Bind")]
	public void BindComponents()
	{
		this.Bind(ref Lock, "Lock");
		this.Bind(ref TexIcon, "TexIcon");
		this.Bind(ref LblLevel, "LblLevel");
		this.Bind(ref SprSelect, "SprSelect");
		this.Bind(ref SprNew, "SprNew");
        this.Bind(ref LblCount, "LblCount");
        this.Bind(ref SprEquip, "SprEquip");
    }

    public void SetData(UserData.Item item)
    {
        SetData(item.Id, item.ItemId, item.Count);
    }

    public void SetData(SimpleItem item)
    {
        SetData(item.Id, item.ItemId, item.Count);
    }

    public void SetData(long id, int itemId, int itemCount, int requestCount = 0)
    {
        Data.Item itemData = ItemTable.Instance.Find(itemId);
        if (ItemTable.Instance.IsStackable(itemData))
        {
            LblCount.SetActiveSafely(true);

            if (requestCount == 0)
                LblCount.SetTextSafely(string.Concat("x", itemCount));
            else
                LblCount.SetTextSafely(string.Format("{0}/{1}", itemCount, requestCount));
        }
        else
        {
            LblCount.SetTextSafely(string.Empty);
        }

        // @TODO: Set Item Info
        if (!string.IsNullOrEmpty(itemData.Texture))
        {
            TexIcon.SetActiveSafely(true);
            TexIcon.mainTexture = Resources.Load<Texture2D>(itemData.Texture);
        }
        else
        {
            TexIcon.SetActiveSafely(false);
        }

        SprNew.SetActiveSafely(MyInfo.Inventory.GetDirty(id));
        SprEquip.SetActiveSafely(MyInfo.Inventory.IsEquip(id));

        LblLevel.SetActiveSafely(false);
        SprSelect.SetActiveSafely(m_isSelected);
        Lock.SetActiveSafely(false);
    }

    public void SetSelection(bool isSelect)
    {
        m_isSelected = isSelect;
    }
    
    public void Disable()
    {
        LblCount.SetActiveSafely(false);
        LblLevel.SetActiveSafely(false);
        SprNew.SetActiveSafely(false);
        SprSelect.SetActiveSafely(false);
        TexIcon.SetActiveSafely(false);
        Lock.SetActiveSafely(false);
        SprEquip.SetActiveSafely(false);
    }

    public void SetOnClickListener(UIEventListener.VoidDelegate l)
    {
        m_onClickListener = l;
    }

    //-------------------------------------------------------------------------
    //  UIActions
    //-------------------------------------------------------------------------
    #region UIActions

    private void OnClick()
    {
        if (m_onClickListener != null)
            m_onClickListener(gameObject);
    }

    #endregion UIActions
}
