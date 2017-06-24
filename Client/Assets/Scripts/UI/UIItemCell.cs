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
	}
	public View m_view;

	[ContextMenu("Bind")]
	public void Initialize()
	{
		m_view = new View();
		this.Bind(ref m_view.Lock, "Lock");
		this.Bind(ref m_view.TexIcon, "TexIcon");
	}
}
