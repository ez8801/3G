/* 
 * StatManager.cs
 * 
 * Writer : user
 * Date   : 2017-08-20
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class StatManager : MonoSingleton<StatManager>
{
    private Data.Character m_startCharacterData;
    private Data.Stats m_startStatsData;
    public Data.Stats CharacterStats;

    //EquipStats
    private int m_finalAttackEquipStat;
    public int FinalAttackEquipStat
    {
        set
        {
            m_finalAttackEquipStat = value;
            CalculateStats();
        }
        get
        {
            return m_finalAttackEquipStat;
        }
    }
    private int m_finalArmorEquipStat;
    public int FinalArmorEquipStat
    {
        set
        {
            m_finalArmorEquipStat = value;
            CalculateStats();
        }
        get
        {
            return m_finalArmorEquipStat;
        }
    }
    private int m_finalHpEquipStat;
    public int FinalHpEquipStat
    {
        set
        {
            m_finalHpEquipStat = value;
            CalculateStats();
        }
        get
        {
            return m_finalHpEquipStat;
        }
    }
    private float m_finalSpeedEquipStat;
    public float FinalSpeedEquipStat
    {
        set
        {
            m_finalSpeedEquipStat = value;
            CalculateStats();
        }
        get
        {
            return m_finalSpeedEquipStat;
        }
    }

    //PassiveStats
    private int m_finalAttackPassiveStat;
    public int FinalAttackPassiveStat
    {
        set
        {
            m_finalAttackPassiveStat = value;
            CalculateStats();
        }
        get
        {
            return m_finalAttackPassiveStat;
        }
    }
    private int m_finalArmorPassiveStat;
    public int FinalArmorPassiveStat
    {
        set
        {
            m_finalArmorPassiveStat = value;
            CalculateStats();
        }
        get
        {
            return m_finalArmorPassiveStat;
        }
    }
    private int m_finalHpPassiveStat;
    public int FinalHpPassiveStat
    {
        set
        {
            m_finalHpPassiveStat = value;
            CalculateStats();
        }
        get
        {
            return m_finalHpPassiveStat;
        }
    }
    private float m_finalSpeedPassiveStat;
    public float FinalSpeedPassiveStat
    {
        set
        {
            m_finalSpeedPassiveStat = value;
            CalculateStats();
        }
        get
        {
            return m_finalSpeedPassiveStat;
        }
    }

    private float m_finalAllCooltimeDecrease;
    public float FinalAllCooltimeDecrease
    {
        set
        {
            m_finalAllCooltimeDecrease = value;
            CalculateStats();
        }
        get
        {
            return m_finalAllCooltimeDecrease;
        }
    }

    //percent increase
    private float m_finalAttackEquipPercent;
    public float FinalAttackEquipPercent
    {
        set
        {
            m_finalAttackEquipPercent = value;
            CalculateStats();
        }
        get
        {
            return m_finalAttackEquipPercent;
        }
    }
    private float m_finalAttackPassivePercent;
    public float FinalAttackPassivePercent
    {
        set
        {
            m_finalAttackPassivePercent = value;
            CalculateStats();
        }
        get
        {
            return m_finalAttackPassivePercent;
        }
    }
    private float m_finalArmorEquipPercent;
    public float FinalArmorEquipPercent
    {
        get
        {
            return m_finalArmorEquipPercent;
        }
        set
        {
            m_finalArmorEquipPercent = value;
            CalculateStats();
        }
    }
    private float m_finalArmorPassivePercent;
    public float FinalArmorPassivePercent
    {
        set
        {
            m_finalArmorPassivePercent = value;
            CalculateStats();
        }
        get
        {
            return m_finalArmorPassivePercent;
        }
    }
    private float m_finalHpEquipPercent;
    public float FinalHpEquipPercent
    {
        get
        {
            return m_finalHpEquipPercent;
        }
        set
        {
            m_finalHpEquipPercent = value;
            CalculateStats();
        }
    }
    private float m_finalHpPassivePercent;
    public float FinalHpPassivePercent
    {
        set
        {
            m_finalHpPassivePercent = value;
            CalculateStats();
        }
        get
        {
            return m_finalHpPassivePercent;
        }
    }


    /// <summary>
    /// Equip 스텟 : weapon과 support장비
    /// </summary>
    private int m_weaponAttackStat;
    public int WeaponAttackStat
    {
        get
        {
            return m_weaponAttackStat;
        }
        set
        {
            m_weaponAttackStat = value;
            CalculateFinalAttackEquipStat();
        }
    }
    private int m_supportAttackStat;
    public int SupportAttackStat
    {
        get
        {
            return m_supportAttackStat;
        }
        set
        {
            m_supportAttackStat = value;
            CalculateFinalAttackEquipStat();
        }
    }

    private void CalculateFinalAttackEquipStat()
    {
        FinalAttackEquipStat = SupportAttackStat + WeaponAttackStat;
    }


    /// <summary>
    /// 일반 패시브 깡스텟 
    /// </summary>
    private int m_commonPassiveAttackStat;
    public int CommonPassiveAttackStat
    {
        get
        {
            return m_commonPassiveAttackStat;
        }
        set
        {
            m_commonPassiveAttackStat = value;
            CalculateFinalAttackPassiveStat();
        }
    }
    /// <summary>
    /// sword패시브 깡스텟
    /// </summary>
    private int m_swordPassiveAttackStat;
    public int SwordPassiveAttackStat
    {
        get
        {
            return m_swordPassiveAttackStat;
        }
        set
        {
            m_swordPassiveAttackStat = value;
            CalculateFinalAttackPassiveStat();
        }
    }
    // !!! 다른 종류 장비도 추가해야함 !!!
    //
    //

    /// <summary>
    /// 최종 패시브 깡스텟 계산
    /// </summary>
    private void CalculateFinalAttackPassiveStat()
    {
        FinalAttackPassiveStat = CommonPassiveAttackStat + SwordPassiveAttackStat;
    }

    private void CalculateStats()
    {
        CharacterStats.AttackDamage =
            (int)(
            (m_startStatsData.AttackDamage + m_finalAttackPassiveStat + m_finalAttackEquipStat) *
            (((m_finalAttackPassivePercent + m_finalAttackEquipPercent) / 100) + 1)
            );
        CharacterStats.Armor =
            (int)(
            (m_startStatsData.Armor + m_finalArmorPassiveStat + m_finalArmorEquipStat) *
            (((m_finalArmorPassivePercent + m_finalArmorEquipPercent) / 100) + 1)//수치 추가 요망
            );
        CharacterStats.Hp =
            (int)(
            (m_startStatsData.Hp + m_finalHpPassiveStat + m_finalHpEquipStat) *
            (((m_finalHpPassivePercent + m_finalHpEquipPercent) / 100) + 1)//수치 추가 요망
            );

    }


    public void Initialize()
    {
        m_startCharacterData = CharacterTable.Instance.Find(1);
        m_startStatsData = StatsTable.Instance.Find(m_startCharacterData.StatsId);
        CharacterStats = m_startStatsData;
        CalculateStats();
    }
}