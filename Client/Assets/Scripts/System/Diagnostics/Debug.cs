#if UNITY_EDITOR
#   define ENABLE_LOG
#endif

#if !ENABLE_LOG
using System;
using System.Diagnostics;
using UnityEngine;

public class Debug
{
    public static bool developerConsoleVisible
    {
        get { return UnityEngine.Debug.developerConsoleVisible; }
        set { UnityEngine.Debug.developerConsoleVisible = value; }
    }

    public static bool isDebugBuild
    {
        get { return UnityEngine.Debug.isDebugBuild; }
    }

    public static ILogger logger
    {
        get { return UnityEngine.Debug.logger; }

    }


    [Conditional("UNITY_ASSERTIONS")]
    [Conditional("ENABLE_LOG")]
    public static void Assert(bool condition)
    {
    }

    [Conditional("UNITY_ASSERTIONS")]
    [Conditional("ENABLE_LOG")]
    public static void Assert(bool condition, UnityEngine.Object context)
    {
    }

    [Conditional("UNITY_ASSERTIONS")]
    [Conditional("ENABLE_LOG")]
    public static void Assert(bool condition, object message)
    {
    }

    [Conditional("UNITY_ASSERTIONS")]
    [Conditional("ENABLE_LOG")]
    public static void Assert(bool condition, string message)
    {
    }

    [Conditional("UNITY_ASSERTIONS")]
    [Conditional("ENABLE_LOG")]
    public static void Assert(bool condition, object message, UnityEngine.Object context)
    {
    }

    [Conditional("UNITY_ASSERTIONS")]
    [Conditional("ENABLE_LOG")]
    public static void Assert(bool condition, string message, UnityEngine.Object context)
    {
    }

    [Conditional("UNITY_ASSERTIONS")]
    [Conditional("ENABLE_LOG")]
    [Obsolete("Assert(bool, string, params object[]) is obsolete. Use AssertFormat(bool, string, params object[]) (UnityUpgradable) -> AssertFormat(*)", true)]
    public static void Assert(bool condition, string format, params object[] args)
    {
    }

    [Conditional("UNITY_ASSERTIONS")]
    [Conditional("ENABLE_LOG")]
    public static void AssertFormat(bool condition, string format, params object[] args)
    {
    }

    [Conditional("UNITY_ASSERTIONS")]
    [Conditional("ENABLE_LOG")]
    public static void AssertFormat(bool condition, UnityEngine.Object context, string format, params object[] args)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void Break()
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void ClearDeveloperConsole()
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void DebugBreak()
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void DrawLine(Vector3 start, Vector3 end)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void DrawLine(Vector3 start, Vector3 end, Color color)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void DrawLine(Vector3 start, Vector3 end, Color color, float duration)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void DrawLine(Vector3 start, Vector3 end, Color color, float duration, bool depthTest)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void DrawRay(Vector3 start, Vector3 dir)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void DrawRay(Vector3 start, Vector3 dir, Color color)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void DrawRay(Vector3 start, Vector3 dir, Color color, float duration)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void DrawRay(Vector3 start, Vector3 dir, Color color, float duration, bool depthTest)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void Log(object message)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void Log(object message, UnityEngine.Object context)
    {
    }

    [Conditional("UNITY_ASSERTIONS")]
    [Conditional("ENABLE_LOG")]
    public static void LogAssertion(object message)
    {
    }

    [Conditional("UNITY_ASSERTIONS")]
    [Conditional("ENABLE_LOG")]
    public static void LogAssertion(object message, UnityEngine.Object context)
    {
    }

    [Conditional("UNITY_ASSERTIONS")]
    [Conditional("ENABLE_LOG")]
    public static void LogAssertionFormat(string format, params object[] args)
    {
    }

    [Conditional("UNITY_ASSERTIONS")]
    [Conditional("ENABLE_LOG")]
    public static void LogAssertionFormat(UnityEngine.Object context, string format, params object[] args)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void LogError(object message)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void LogError(object message, UnityEngine.Object context)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void LogErrorFormat(string format, params object[] args)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void LogErrorFormat(UnityEngine.Object context, string format, params object[] args)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void LogException(Exception exception)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void LogException(Exception exception, UnityEngine.Object context)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void LogFormat(string format, params object[] args)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void LogFormat(UnityEngine.Object context, string format, params object[] args)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void LogWarning(object message)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void LogWarning(object message, UnityEngine.Object context)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void LogWarningFormat(string format, params object[] args)
    {
    }

    [Conditional("ENABLE_LOG")]
    public static void LogWarningFormat(UnityEngine.Object context, string format, params object[] args)
    {
    }
}
#endif