/* 
 * UILoading.cs
 * 
 * Writer : bmw122
 * Date   : 2017-07-03
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

public class UILoading : MonoBehaviour
{
    public UISprite m_SprProgressBar;
    public UILabel m_LblProgress;
    public UILabel m_LblTip;
    public UITexture m_TexTip;

    private int m_originWidth;

    public void Start()
    {
        m_originWidth = m_SprProgressBar.width;
    }
    
    public void SetProgress(float ratio)
    {
        m_SprProgressBar.SetFillAmountSafely(ratio, m_originWidth);
        m_LblProgress.SetTextSafely(string.Format("{0}%", (ratio * 100f).ToString("0.0")));
    }

    public void SetTip(string tip)
    {
        m_LblTip.SetTextSafely(tip);
    }
}