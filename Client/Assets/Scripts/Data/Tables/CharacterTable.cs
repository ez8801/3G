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

        /// <summary>
        /// 캐릭터 이름
        /// </summary>
        [DeclaringType("string", "int")]
        public int Name;

        /// <summary>
        /// 능력치 Id
        /// </summary>
        /// <seealso cref="Stats.Id"/>
        public int StatsId;
        
        /// <summary>
        /// 프리팹 Id
        /// </summary>
        /// <seealso cref="Prefab.Id"/>
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