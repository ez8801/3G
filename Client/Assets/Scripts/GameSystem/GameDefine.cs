using System;

public class GameDefine
{
    // @TODO:
    public Version version = new Version(1, 0, 0);
    public string VersionString
    {
        get
        {
            return version.ToString();
        }
    }
}
