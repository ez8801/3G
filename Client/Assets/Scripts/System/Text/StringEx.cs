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

    public static string Format(string format, object arg)
    {
        m_builder.Length = 0;
        m_builder.AppendFormat(format, arg);
        return m_builder.ToString();
    }

    public static string Format(string format, object arg1, object arg2)
    {
        m_builder.Length = 0;
        m_builder.AppendFormat(format, arg1, arg2);
        return m_builder.ToString();
    }

    public static string Format(string format, object arg1, object arg2, object arg3)
    {
        m_builder.Length = 0;
        m_builder.AppendFormat(format, arg1, arg2, arg3);
        return m_builder.ToString();
    }

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

    public static string Concat(string arg0, string arg1)
    {
        m_builder.Length = 0;
        m_builder.Append(arg0);
        m_builder.Append(arg1);
        return m_builder.ToString();
    }

    public static string Concat(string arg0, string arg1, string arg2)
    {
        m_builder.Length = 0;
        m_builder.Append(arg0);
        m_builder.Append(arg1);
        m_builder.Append(arg2);
        return m_builder.ToString();
    }

    public static string Concat(string arg0, string arg1, string arg2, string arg3)
    {
        m_builder.Length = 0;
        m_builder.Append(arg0);
        m_builder.Append(arg1);
        m_builder.Append(arg2);
        m_builder.Append(arg3);
        return m_builder.ToString();
    }

    public static string Concat(object arg0, object arg1)
    {
        m_builder.Length = 0;
        m_builder.Append(arg0);
        m_builder.Append(arg1);
        return m_builder.ToString();
    }

    public static string Concat(object arg0, object arg1, object arg2)
    {
        m_builder.Length = 0;
        m_builder.Append(arg0);
        m_builder.Append(arg1);
        m_builder.Append(arg2);
        return m_builder.ToString();
    }

    public static string Concat(object arg0, object arg1, object arg2, object arg3)
    {
        m_builder.Length = 0;
        m_builder.Append(arg0);
        m_builder.Append(arg1);
        m_builder.Append(arg2);
        m_builder.Append(arg3);
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

    /// <summary>
    /// 각 요소 사이에 지정된 구분 기호를 사용하여 문자열 배열의 모든 요소를 연결합니다.
    /// </summary>
    public static string Join(string separator, string[] value)
    {
        if (value != null && value.Length > 0)
        {
            m_builder.Length = 0;
            for (int i = 0, j = 1; i < value.Length; i++, j++)
            {
                m_builder.Append(value[i]);
                if (j < value.Length)
                    m_builder.Append(separator);
            }
            return m_builder.ToString();
        }
        return string.Empty;
    }

    /// <summary>
    /// 각 요소 사이에 지정된 구분 기호를 사용하여 문자열 배열의 모든 요소를 연결합니다.
    /// </summary>
    public static string Join(string separator, params object[] args)
    {
        if (args != null && args.Length > 0)
        {
            m_builder.Length = 0;
            for (int i = 0, j = 1; i < args.Length; i++, j++)
            {
                m_builder.Append(args[i]);
                if (j < args.Length)
                    m_builder.Append(separator);
            }
            return m_builder.ToString();
        }
        return string.Empty;
    }
}