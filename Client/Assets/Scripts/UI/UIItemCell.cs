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
	[System.Serializable]
	public struct View
	{
		public GameObject Lock;
		public UITexture TexIcon;
        public UILabel LblLevel;
        public UISprite SprSelect;
        public UISprite SprNew;
    }
	public View m_view;

	[ContextMenu("Bind")]
	public void Initialize()
	{
		m_view = new View();
		this.Bind(ref m_view.Lock, "Lock");
		this.Bind(ref m_view.TexIcon, "TexIcon");
		this.Bind(ref m_view.LblLevel, "LblLevel");
		this.Bind(ref m_view.SprSelect, "SprSelect");
		this.Bind(ref m_view.SprNew, "SprNew");
    }
}
