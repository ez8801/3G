using System;
using UnityEngine;

public static class TimeSynchronizer
{
    private static DateTime m_currentTime = new DateTime();
    private static float realtimeSinceStartup = 0f;
    
    public static DateTime Now
    {
        get
        {
            double gapValue = (double)Time.realtimeSinceStartup - realtimeSinceStartup;
            return m_currentTime.AddSeconds(gapValue);
        }
        set
        {
            m_currentTime = value;
            realtimeSinceStartup = Time.realtimeSinceStartup;
        }
    }
}
