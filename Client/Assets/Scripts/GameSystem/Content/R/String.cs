/* 
 * String.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-17
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

public static partial class R
{
    public static class String
    {
        public static string GetText(string resId)
        {
            if (!string.IsNullOrEmpty(resId))
                return GetText(resId.GetHashCode());
            return string.Empty;
        }

        public static string GetText(int resId)
        {
            if (!StringTable.Instance.ContainsKey(resId))
                return string.Empty;

            Data.String stringData = StringTable.Instance.Find(resId);
            return stringData.Value;
        }
    }
}