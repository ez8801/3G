
#define USING_STOP_WATCH
#define USING_REAL_TIME
#define USING_TIKC_COUNT

using System;
using System.Text;
using System.Collections.Generic;
using System.Diagnostics;

public class Clock : IDisposable
{
    static Dictionary<string, List<Clock>> mContext
        = new Dictionary<string, List<Clock>>(); 
    static Dictionary<string, Clock> mMap 
        = new Dictionary<string, Clock>();

    static Clock Acquire(string key, string context = null)
    {
        Clock clock = null;
        if (mMap.TryGetValue(key, out clock))
            return clock;
        clock = new Clock(key, context);
        mMap.Add(key, clock);
        if (string.IsNullOrEmpty(context) == false)
        {
            if (mContext.ContainsKey(context) == false)
            {
                mContext.Add(context, new List<Clock>());
                clock.m_isRoot = true;
            }
            else
                mContext[clock.m_context].Add(clock);
        }

        return clock;
    }

    static public Clock Create(string key, string context = null)
    {
        return Acquire(key, context);
    }

    Clock(string key)
    {
        m_key = key;
        m_context = null;
#if USING_STOP_WATCH
        watch = new Stopwatch();
        watch.Reset();
        watch.Start();
#endif

#if USING_REAL_TIME
        m_RealTimeBeforeStart = UnityEngine.Time.realtimeSinceStartup;
#endif

#if USING_TIKC_COUNT
        m_TickCountBeforeStart = Environment.TickCount;
#endif
    }

    Clock(string key, string context)
    {
        m_key = key;
        m_context = context;
#if USING_STOP_WATCH
        watch = new Stopwatch();
        watch.Reset();
        watch.Start();
#endif

#if USING_REAL_TIME
        m_RealTimeBeforeStart = UnityEngine.Time.realtimeSinceStartup;
#endif

#if USING_TIKC_COUNT
        m_TickCountBeforeStart = Environment.TickCount;
#endif
    }

    //
	private static StringBuilder builder = new StringBuilder();

    //
    private string m_key;
    private string m_context;
    private bool m_isRoot;

    // Diagnostics
	private Stopwatch watch;
    private double m_TotalMilliseconds;
    private long m_ElapsedTicks;

    // Time
    private float m_RealTimeBeforeStart;
    private float m_RealTimeAfterEnd;
    public float RealTime
    {
        get
        {
            return (m_RealTimeAfterEnd - m_RealTimeBeforeStart);
        }
    }

    // Environment
	private int m_TickCountBeforeStart;
    private int m_TickCountAfterEnd;
    public int TickCount
    {
        get
        {
            return (m_TickCountAfterEnd - m_TickCountBeforeStart);
        }
    }

    public static void time(string key, string context = null)
    {
        Acquire(key, context);
    }

    public static void timeEnd(string key)
    {
        Clock clock = Acquire(key);
        if (clock == null)
            return;

#if USING_TIKC_COUNT
        clock.m_TickCountAfterEnd = Environment.TickCount;
#endif

#if USING_REAL_TIME
        clock.m_RealTimeAfterEnd = UnityEngine.Time.realtimeSinceStartup;
#endif

#if USING_STOP_WATCH
        clock.watch.Stop();

        clock.m_TotalMilliseconds = clock.watch.Elapsed.TotalMilliseconds;
        clock.m_ElapsedTicks = clock.watch.Elapsed.Ticks;
#endif

        builder.Length = 0;

        if (string.IsNullOrEmpty(clock.m_context))
            builder.AppendFormat("# {0}\r\n", key);
        else
            builder.AppendFormat("# {0} ({1})\r\n", key, clock.m_context);

#if USING_STOP_WATCH
        builder.AppendFormat("- Elapsed Ticks\t: {0}\r\n"
            , clock.m_ElapsedTicks);
#endif

#if USING_TIKC_COUNT
        builder.AppendFormat("- Tick Count\t\t: {0}\r\n"
            , clock.TickCount);
#endif

#if USING_REAL_TIME
        builder.AppendFormat("- Real Time\t\t: {0}\r\n"
            , clock.RealTime.ToString("0.000 s"));
#endif

#if USING_STOP_WATCH
        builder.AppendFormat("- Milliseconds\t: {0}\r\n"
            , clock.m_TotalMilliseconds.ToString("0.000 ms"));
#endif

        //
        if (mMap.ContainsKey(clock.m_key))
            mMap.Remove(clock.m_key);

        if (clock.m_isRoot
            && mContext.ContainsKey(clock.m_context))
        {
            List<Clock> l = mContext[clock.m_context];

            if (l != null && l.Count > 0)
            {
                builder.AppendFormat("\r\n\r\n");
                for (int i = 0; i < l.Count; i++)
                {
                    Clock each = l[i];
                    builder.AppendFormat("[{0}] {1:0.0%}\r\n"
                        , each.m_key
                        , ((float)each.TickCount / clock.TickCount));
                }
                builder.AppendFormat("\r\n\r\n");
            }

            mContext.Remove(clock.m_context);
        }

        UnityEngine.Debug.Log(builder);
    }

    public void Dispose()
    {
        timeEnd(m_key);
    }
}