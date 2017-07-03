/* 
 * TipTable.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-03
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using Data;
using System;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct Tip
    {
        public int Id;
        public string Message;
    }
}

/// <summary>
/// 팁 테이블
/// 이 클래스는 상속할 수 없습니다.
/// </summary>
public sealed class TipTable : ArrayTable<Tip>
{
    private static TipTable m_instance;
    public static TipTable Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new TipTable();
            return m_instance;
        }
    }

    /// <summary>
    /// 임의의 팁 메시지를 반환합니다.
    /// </summary>
    public string GetTipMessage()
    {
        int randomIndex = UnityEngine.Random.Range(0, Count);
        return this[randomIndex].Message;
    }
}