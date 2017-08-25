using Data;
using UnityEngine;

public class UIRecipeCell : UIBase
{
	[System.Serializable]
	public struct View
	{
		public GameObject Lock;
		public UITexture TexIcon;
		public UISprite SprNew;
		public UISprite SprSelect;
		public UILabel LblName;
	}
	public View m_view;

    private bool m_isSelected;
    private bool m_isLocked;

    private UIEventListener.VoidDelegate m_onClickListener;
    
    public void Initialize()
	{
        BindComponents();

        m_isSelected = false;
    }

    [ContextMenu("Bind")]
    public void BindComponents()
    {
        if (!IsAssigned(m_view))
            m_view = new View();
        this.Bind(ref m_view.Lock, "Lock");
        this.Bind(ref m_view.TexIcon, "TexIcon");
        this.Bind(ref m_view.SprNew, "SprNew");
        this.Bind(ref m_view.SprSelect, "SprSelect");
        this.Bind(ref m_view.LblName, "LblName");
    }

    public void SetData(Recipe data)
    {
        m_view.LblName.SetTextSafely(R.GetText(data.Name));
        m_view.SprSelect.SetActiveSafely(m_isSelected);
        m_view.SprNew.SetActiveSafely(false);
        m_view.Lock.SetActiveSafely(m_isLocked);
    }

    public void SetSelection(bool isSelect)
    {
        m_isSelected = isSelect;
    }

    public void SetLock(bool isLock)
    {
        m_isLocked = isLock;
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
