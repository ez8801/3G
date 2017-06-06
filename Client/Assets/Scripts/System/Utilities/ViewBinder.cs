/* 
 * ViewById.cs
 * 
 * Writer : P_BaekMinWoo
 * Date   : 2016-01-06
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */
using System;
using System.Reflection;
using UnityEngine;

/// <summary>
/// 바인딩할 Field 혹은 Property의 Id를 저장할 Attribute, 이 클래스는 상속될 수 없습니다.
/// </summary>
[AttributeUsage(AttributeTargets.Field | AttributeTargets.Property)]
public sealed class ViewByIdAttribute : Attribute
{
    public string id;
    public ViewByIdAttribute(string strId)
    {
        id = strId;
    }
}

/// <summary>
/// 참조할 레이아웃 리소스를 저장할 Attribute, 이 클래스는 상속될 수 없습니다.
/// </summary>
[AttributeUsage(AttributeTargets.Class)]
public sealed class LayoutResAttribute : Attribute
{
    public string id;
    public LayoutResAttribute(string strId)
    {
        id = strId;
    }
}

public class ViewBinder
{
    /// <summary>
    /// 지정된 MonoBehaviour의 각 Field 혹은 Property에 Id를 기준으로 연결합니다.
    /// </summary>
    public static void Bind(MonoBehaviour obj)
    {
        Type type = obj.GetType();
        FieldInfo[] fieldInfos = type.GetFields(BindingFlags.Public 
            | BindingFlags.NonPublic 
            | BindingFlags.Instance 
            | BindingFlags.GetField 
            | BindingFlags.SetField);
        if (fieldInfos == null)
        {
            Debug.LogWarning("Field is empty");
            return;
        }

        for (int i = 0; i < fieldInfos.Length; i++)
        {
            FieldInfo fi = fieldInfos[i];

            object[] attributes = fi.GetCustomAttributes(typeof(ViewByIdAttribute), true);
            if (attributes == null || attributes.Length == 0)
                continue;

            ViewByIdAttribute attribute = (ViewByIdAttribute)attributes[0];
            
            Debug.Log("FieldType: " + fi.FieldType);

            Component component = Util.FindComponentByName(fi.FieldType, obj.transform, attribute.id, true);

            //Transform t = Util.FindComponentByName<Transform>(obj.transform, attribute.id, true);
            //if (t == null)
            if (component == null)
            {
                Debug.LogWarning(string.Format("Couldn't bind view: {0}", attribute.id));
                continue;
            }
            
            fi.SetValue(obj, component);
        }
    }

    /// <summary>
    /// 지정된 MonoBehaviour의 현재 상태를 프리팹에 반영, 저장합니다.
    /// </summary>
    public static void Save(MonoBehaviour obj)
    {

    }
}
