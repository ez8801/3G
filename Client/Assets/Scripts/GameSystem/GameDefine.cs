using System;

public static class GameDefine
{
    public static Version version = new Version(1, 0, 0);
    
    public static string VersionString
    {
        get
        {
            if (string.IsNullOrEmpty(m_versionString))
                m_versionString = version.ToString();
            return m_versionString;
        }
    }
    private static string m_versionString = string.Empty;

    public const string ProductName = "Sweet Home Alabama";
    public const string CompanyName = "Team 3G";
}
