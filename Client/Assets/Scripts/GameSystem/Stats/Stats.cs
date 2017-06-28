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
    private Hp m_hp;

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

    public int Hp
    {
        get
        {
            return Mathf.FloorToInt(m_hp.Final);
        }
    }
    
    public void Initialize(Data.Stats statsData)
    {
        m_hp = new Hp();
        m_hp.Value = statsData.Hp;

        m_armor = new Armor();
        m_armor.Value = statsData.Armor;

        m_attackDamage = new AttackDamage();
        m_attackDamage.Value = statsData.AttackDamage;
    }
}