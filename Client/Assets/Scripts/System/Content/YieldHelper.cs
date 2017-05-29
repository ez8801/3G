using UnityEngine;

public static class YieldHelper
{
    public static WaitForSeconds ZeroSeconds = new WaitForSeconds(0.0f);
    public static WaitForSeconds PointOneSeconds = new WaitForSeconds(0.1f);
    public static WaitForSeconds PointTwoSeconds = new WaitForSeconds(0.2f);
    public static WaitForSeconds PointThreeSeconds = new WaitForSeconds(0.3f);
    public static WaitForSeconds OneSeconds = new WaitForSeconds(1.0f);

    public static WaitForSeconds CreateInstance(float delay)
    {
        return new WaitForSeconds(delay);
    }
}
