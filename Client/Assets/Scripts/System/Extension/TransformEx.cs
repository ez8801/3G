using UnityEngine;

/// <summary>
/// Transform의 확장함수를 정의하는 클래스
/// </summary>
public static class TransformEx
{
    public static void SetLocalPositionX(this Transform t, float x)
    {
        if (t != null)
            t.localPosition = new Vector3(x, t.localPosition.y, t.localPosition.z);
    }

    public static void SetLocalPositionY(this Transform t, float y)
    {
        if (t != null)
            t.localPosition = new Vector3(t.localPosition.x, y, t.localPosition.z);
    }

    public static void SetLocalPositionZ(this Transform t, float z)
    {
        if (t != null)
            t.localPosition = new Vector3(t.localPosition.x, t.localPosition.y, z);
    }

    public static void SetLocalScaleX(this Transform t, float x)
    {
        if (t != null)
            t.localScale = new Vector3(x, t.localScale.y, t.localScale.z);
    }

    public static void SetLocalScaleY(this Transform t, float y)
    {
        if (t != null)
            t.localScale = new Vector3(t.localScale.x, y, t.localScale.z);
    }

    public static void SetLocalScaleZ(this Transform t, float z)
    {
        if (t != null)
            t.localScale = new Vector3(t.localScale.x, t.localScale.y, z);
    }

    public static void SetActiveSafely(this Transform t, bool value)
    {
        if (t != null)
            t.gameObject.SetActive(value);
    }

    public static void SetActiveSafely(this GameObject go, bool value)
    {
        if (go != null)
            go.SetActive(value);
    }
}