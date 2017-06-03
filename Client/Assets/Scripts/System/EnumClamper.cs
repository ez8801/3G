using System;

public class EnumClamper
{
    public static T Clamp<T>(object value, T defaultValue) where T : struct, IComparable, IFormattable, IConvertible
    {
        Type type = defaultValue.GetType();
        if (type.IsEnum == false)
        {
            throw new ArgumentException("Argument must be Enum type");
        }

        if (Enum.IsDefined(type, value))
            return (T)value;
        return defaultValue;
    }
}
