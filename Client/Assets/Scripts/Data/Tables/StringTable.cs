/* 
 * StringTable.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-21
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using Data;
using System;

namespace Data
{
    [Serializable]
    [PrimaryKey("Key")]
    public partial struct String
    {
        public string Key;
        public string Value;
    }
}

/// <summary>
/// 문자열 테이블
/// 이 클래스는 상속할 수 없습니다.
/// </summary>
public sealed class StringTable : DictionaryTable<Data.String>
{
    private static StringTable m_instance;
    public static StringTable Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new StringTable();
            return m_instance;
        }
    }
}