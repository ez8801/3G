/* 
 * StatsTable.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ SHAprojectVer001. DefaultCompany, All rights reserved
 */

using System;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct Stats
    {
        public int Id;
        public int Hp;
        public int AttackDamage;
        public int Armor;
    }
}

/// <summary>
/// 스탯 테이블
/// 이 클래스는 상속할 수 없습니다.
/// </summary>
public class StatsTable : ArrayTable<Data.Stats>
{
    private static StatsTable m_instance;
    public static StatsTable Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new StatsTable();
            return m_instance;
        }
    }
}