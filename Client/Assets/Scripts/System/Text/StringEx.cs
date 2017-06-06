/* 
 * StringEx.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-06
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System.Text;

public static class StringEx
{
    private static StringBuilder m_builder = new StringBuilder();

    /// <summary>
    /// 서식 문자열을 처리한 문자열을 반환합니다.
    /// </summary>
    public static string Format(string format, params object[] args)
    {
        if (string.IsNullOrEmpty(format))
            return string.Empty;

        m_builder.Length = 0;
        m_builder.AppendFormat(format, args);
        return m_builder.ToString();
    }

    /// <summary>
    /// 지정된 String 배열의 요소를 연결합니다.
    /// </summary>
    public static string Concat(params string[] args)
    {
        if (args == null || args.Length == 0)
            return string.Empty;

        m_builder.Length = 0;
        for (int i = 0; i < args.Length; i++)
        {
            m_builder.Append(args[i]);
        }
        return m_builder.ToString();
    }

    /// <summary>
    /// 지정된 Object 배열에 있는 요소의 문자열 표현을 연결합니다.
    /// </summary>
    public static string Concat(params object[] args)
    {
        if (args == null || args.Length == 0)
            return string.Empty;

        m_builder.Length = 0;
        for (int i = 0; i < args.Length; i++)
        {
            m_builder.Append(args[i].ToString());
        }
        return m_builder.ToString();
    }
}