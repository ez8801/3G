using GameSystem;

public class TitleScene : Scene
{
    public override string GetTitle()
    {
        return "TitleScene";
    }

    public override void OnBackPressed()
    {
        if (IsBackable())
            base.OnBackPressed();
    }
}
