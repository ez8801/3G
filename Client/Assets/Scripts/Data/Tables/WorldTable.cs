/* 
 * WorldTable.cs
 * 
 * Writer : EZ
 * Date   : 2017-08-28
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using Data;
using System;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct World
    {
        public int Id;

        [DeclaringType("string", "int")]
        public int Name;
    }
}

/// <summary>
/// 월드 테이블
/// 이 클래스는 상속할 수 없습니다.
/// </summary>
public sealed class WorldTable : ArrayTable<World>
{
    private static WorldTable m_instance;
    public static WorldTable Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new WorldTable();
            return m_instance;
        }
    }
}