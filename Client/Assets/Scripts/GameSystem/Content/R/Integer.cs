/* 
 * Integer.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-17
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

namespace R
{
    public static class Integer
    {
        public static int GetInteger(string resId)
        {
            if (!string.IsNullOrEmpty(resId))
            {
                return GetInteger(resId.GetHashCode());
            }
            return 0;
        }

        public static int GetInteger(int resId)
        {
            if (ConfigTable.Instance.ContainsKey(resId))
            {
                Data.Config config = ConfigTable.Instance.Find(resId);
                return config.Value;
            }
            return 0;
        }
    }
}