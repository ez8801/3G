/* 
 * PrefabTable.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-27
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using Data;
using System;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct Prefab
    {
        public int Id;
        public string PrefabName;
    }
}

/// <summary>
/// 프리팹 테이블
/// 이 클래스는 상속할 수 없습니다.
/// </summary>
public sealed class PrefabTable : ArrayTable<Prefab>
{
    private static PrefabTable m_instance;
    public static PrefabTable Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new PrefabTable();
            return m_instance;
        }
    }
}