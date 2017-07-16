/* 
 * DeclaringTypeAttribute.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-16
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System;

[AttributeUsage(AttributeTargets.Field, Inherited = false)]
public sealed class DeclaringTypeAttribute : Attribute 
{
    public string DataTypeName;
    public string DeclaringTypeName;

    public DeclaringTypeAttribute(string dataTypeName, string declaringTypeName)
    {
        DataTypeName = dataTypeName;
        DeclaringTypeName = declaringTypeName;
    }
}