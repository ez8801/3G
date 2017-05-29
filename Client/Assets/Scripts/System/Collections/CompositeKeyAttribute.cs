using System;

[AttributeUsage(AttributeTargets.Class | AttributeTargets.Struct, AllowMultiple = false, Inherited = false)]
public class CompositeKeyAttribute : Attribute
{
    public string m_key1;
    public string m_key2;
    public string m_key3;

    public CompositeKeyAttribute(string key1, string key2)
    {
        m_key1 = key1;
        m_key2 = key2;
        m_key3 = string.Empty;
    }

    public CompositeKeyAttribute(string key1, string key2, string key3)
    {
        m_key1 = key1;
        m_key2 = key2;
        m_key3 = key3;
    }
}
