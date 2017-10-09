/* 
 * StageTable.cs
 * 
 * Writer : EZ
 * Date   : 2017-08-28
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using Data;
using System;
using System.Collections.Generic;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct Stage
    {
        public int Id;

        [DeclaringType("string", "int")]
        public int Name;

        public int WorldId;

        public int GoldReward;
    }
}

/// <summary>
/// 스테이지 테이블
/// 이 클래스는 상속할 수 없습니다.
/// </summary>
public class StageTable : ArrayTable<Stage>
{
    private static StageTable m_instance;
    public static StageTable Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new StageTable();
            return m_instance;
        }
    }

    /// <summary>
    /// 지정된 World Id에 해당하는 Stage 목록을 반환합니다.
    /// </summary>
    public List<Stage> GetStages(int worldId)
    {
        List<Stage> stages = new List<Stage>();
        for (int i = 0; i < Length; i++)
        {
            Stage match = this[i];
            if (match.WorldId == worldId)
                stages.Add(match);
        }
        return stages;
    }
}