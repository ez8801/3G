/* 
 * ControlChars.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-06
 * 
 * Copyright ⓒ Util. DefaultCompany, All rights reserved
 */

using UnityEngine;

public static class ControlChars
{
    public enum LineEnding
    {
        NONE,
        WINDOWS,            // CRLF
        MACINTOSH,          // CR
        UNIX,               // LF
        MIXED               // MIXED
    }

    public const char Back = '\b';
    public const char Cr = '\r';
    public const string CrLf = "\r\n";
    public const char FormFeed = '\f';
    public const char Lf = '\n';
    public const string NewLine = "\r\n";
    public const char NullChar = '\0';
    public const char Quote = '"';
    public const char Tab = '\t';
    public const char VerticalTab = '\v';

    public static LineEnding CurrentSetting
    {
        get
        {
            if (System.Environment.NewLine.Equals(Cr))
                return LineEnding.MACINTOSH;
            else if (System.Environment.NewLine.Equals(CrLf))
                return LineEnding.WINDOWS;
            else if (System.Environment.NewLine.Equals(Lf))
                return LineEnding.UNIX;

            return LineEnding.NONE;
        }
    }
}