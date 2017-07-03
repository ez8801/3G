/* 
 * MonsterTable.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct Monster
    {
        public int Id;
        public int Grade;
        public string Name;
        public int StatsId;
        public int PrefabId;
        public int DropGroupId;
    }
}

public enum MonsterGrade
{
    None,
    Minion,
    Champion,
    Boss,
    Max,
}

/// <summary>
/// 몬스터 테이블
/// 이 클래스는 상속할 수 없습니다.
/// </summary>
public class MonsterTable : ArrayTable<Data.Monster>
{

    private static MonsterTable m_instance;
    public static MonsterTable Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new MonsterTable();
            return m_instance;
        }
    }
}