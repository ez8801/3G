/* 
 * Drawable.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-16
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

namespace R
{
    public static class Drawable
    {
        public static string GetTabSprite(bool isSelected)
        {
            return (isSelected) ? "SkillNumBack" : "SkillSelect";
        }
    }
}