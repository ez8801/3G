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

    [ContextMenu("Bind")]
	public void Initialize()
	{
		this.Bind(ref Lock, "Lock");
		this.Bind(ref TexIcon, "TexIcon");
		this.Bind(ref LblLevel, "LblLevel");
		this.Bind(ref SprSelect, "SprSelect");
		this.Bind(ref SprNew, "SprNew");
        this.Bind(ref LblCount, "LblCount");
    }
}
