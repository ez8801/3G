using System;

[AttributeUsage(AttributeTargets.Class | AttributeTargets.Struct)]
public class PrimaryKeyAttribute : Attribute
{
    public string m_primaryKey;

    public PrimaryKeyAttribute(string primaryKey)
    {
        m_primaryKey = primaryKey;
    }
}
