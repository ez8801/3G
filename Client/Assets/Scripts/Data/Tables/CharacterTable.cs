/* 
 * CharacterTable.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-27
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct Character
    {
        public int Id;
        public string Name;
        public int StatsId;
        public int PrefabId;
    }
}

/// <summary>
/// 캐릭터 테이블
/// 이 클래스는 상속할 수 없습니다.
/// </summary>
public sealed class CharacterTable : ArrayTable<Data.Character>
{
    private static CharacterTable m_instance;
    public static CharacterTable Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new CharacterTable();
            return m_instance;
        }
    }
}