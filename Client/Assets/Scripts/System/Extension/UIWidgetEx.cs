
using UnityEngine;

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

    public static void SetSpriteSafely(this UISprite sprite
        , string spriteName, bool isPixelPerfect)
    {
        if (sprite != null)
        {
            sprite.spriteName = spriteName;
            if (isPixelPerfect)
                sprite.MakePixelPerfect();
        }
    }

    public static void SetFillAmountSafely(this UISprite sprite, float fillAmount, int width)
    {
        if (sprite != null)
        {
            if (sprite.type == UIBasicSprite.Type.Filled)
            {
                sprite.fillAmount = fillAmount;
            }
            else
            {
                sprite.SetDimensions(Mathf.RoundToInt(width * fillAmount), sprite.height);
            }
        }        
    }

    public static void SetFillAmountSafely(this UISprite sprite, float fillAmount)
    {
        if (sprite != null)
        {
            sprite.fillAmount = fillAmount;
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
