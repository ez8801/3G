
/// <summary>
/// UIWidget의 확장함수를 정의하는 클래스
/// </summary>
public static class UIWidgetEx
{
    public static void SetTextSafely(this UILabel label, string text)
    {
        if (label != null)
            label.text = text;
    }

    public static void SetSpriteSafely(this UISprite spr, string spriteName, bool isPixelPerfect)
    {
        if (spr != null)
        {
            spr.spriteName = spriteName;
            if (isPixelPerfect)
                spr.MakePixelPerfect();
        }
    }

    public static void SetValueSafely(this UIProgressBar progress, float value)
    {
        if (progress != null)
            progress.value = value;
    }

    public static void SetValueSafely(this UISlider slider, float value)
    {
        if (slider != null)
            slider.value = value;
    }
}
