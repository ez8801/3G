/* 
 * Character.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

public class Character : Actor 
{
    private Stats m_stats;

    public override Stats Stats
    {
        get
        {
            return m_stats;
        }
    }
}