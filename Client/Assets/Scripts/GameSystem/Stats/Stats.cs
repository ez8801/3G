/* 
 * Stats.cs
 * 
 * Writer : bmw122
 * Date   : 2017-06-23
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

public class Stats
{
    private AttackDamage m_attackDamage;
    private Armor m_armor;

    public int AttackDamage
    {
        get
        {
            return Mathf.FloorToInt(m_attackDamage.Final);
        }
    }

    public int Armor
    {
        get
        {
            return Mathf.FloorToInt(m_armor.Final);
        }
    }

    public void Initialize()
    {

    }
}