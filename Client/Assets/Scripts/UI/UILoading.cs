/* 
 * UILoading.cs
 * 
 * Writer : bmw122
 * Date   : 2017-07-03
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

public class UILoading : UIBase, IObserver
{
    public UISprite m_SprProgressBar;
    public UILabel m_LblProgress;
    public UILabel m_LblTip;
    public UITexture m_TexTip;

    private int m_originWidth;

    public void Awake()
    {
        NotificationCenter.Instance.AddObserver((int)Notification.UI.OnProgress, this);
        NotificationCenter.Instance.AddObserver((int)Notification.UI.OnProgressDone, this);

        m_originWidth = m_SprProgressBar.width;
    }
    
    private void OnEnable()
    {
        SetTip(TipTable.Instance.GetTipMessage());
    }

    public void ShowLoadingUI(bool value)
    {
        gameObject.SetActiveSafely(value);
    }

    public void SetProgress(float ratio)
    {
        m_SprProgressBar.SetFillAmountSafely(ratio, m_originWidth);
        m_LblProgress.SetTextSafely(StringEx.Format("{0}%", (ratio * 100f).ToString("0.0")));
    }

    public void SetTip(string tip)
    {
        m_LblTip.SetTextSafely(StringEx.Format("Tip. {0}", tip));
    }

    public void HandleNotification(Notification notification)
    {
        switch (notification.id)
        {
            case (int)Notification.UI.OnProgress:
                ShowLoadingUI(true);
                SetProgress(notification.floatExtra);
                break;

            case (int)Notification.UI.OnProgressDone:
                ShowLoadingUI(false);
                break;
        }
    }

    public void OnDestroy()
    {
        NotificationCenter.Instance.RemoveObserver((int)Notification.UI.OnProgress, this);
        NotificationCenter.Instance.RemoveObserver((int)Notification.UI.OnProgressDone, this);
    }
}