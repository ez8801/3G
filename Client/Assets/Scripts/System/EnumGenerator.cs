using System;
using System.IO;
using System.Text;
using System.Collections.Generic;

public class EnumGenerator
{
    private static bool Contains(ref string[] array, string match)
    {
        for (int i = 0; i < array.Length; i++)
        {
            if (array[i] == match)
                return true;
        }
        return false;
    }

    private static bool IsNull(string enumName)
    {
        if (string.IsNullOrEmpty(enumName))
            return false;

        string lowerEnumName = enumName.ToLower();
        switch (lowerEnumName)
        {
            case "none":
            case "unknown":
                return true;
        }
        return false;
    }

    private static bool IsChange(ref List<string> typeNames, Type classType, Type enumType)
    {
        System.Reflection.Assembly assembly = System.Reflection.Assembly.GetExecutingAssembly();
        Type[] types = assembly.GetTypes();

        for (int i = 0; i < types.Length; i++)
        {
            Type type = types[i];
            if (type.BaseType == classType)
            {
                typeNames.Add(type.Name);
            }
        }

        bool isChanged = false;
        string[] enumNames = Enum.GetNames(enumType);
        int enumCount = 0;
        for (int i = 0; i < enumNames.Length; i++)
        {
            string enumName = enumNames[i];
            if (IsNull(enumName) == false)
                enumCount++;
        }

        if (typeNames.Count != enumCount)
            isChanged = true;

        if (isChanged == false)
        {
            for (int i = 0; i < typeNames.Count; i++)
            {
                string sceneName = typeNames[i];
                if (Contains(ref enumNames, sceneName) == false)
                {
                    isChanged = true;
                    break;
                }
            }
        }

        if (isChanged == false)
        {
            for (int i = 0; i < enumNames.Length; i++)
            {
                string enumName = enumNames[i];
                if (IsNull(enumName))
                    continue;

                if (typeNames.Contains(enumName) == false)
                {
                    isChanged = true;
                    break;
                }
            }
        }

        return isChanged;
    }
    
    public static bool GenerateEnum(string scriptPath, Type classType, Type enumType, bool includeNone = true)
    {
        List<string> typeNames = new List<string>();
        bool isChanged = IsChange(ref typeNames, classType, enumType);

        if (isChanged == false)
            return false;

        FileStream fs = null;
        if (File.Exists(scriptPath))
            fs = File.Create(scriptPath);
        else
            fs = new FileStream(scriptPath, FileMode.Create);

        using (StreamWriter sw = new StreamWriter(fs))
        {
            sw.WriteLine(string.Concat("public enum ", enumType.Name));
            sw.WriteLine("{");
            if (includeNone)
                sw.WriteLine("\tNone,");

            for (int i = 0; i < typeNames.Count; i++)
            {
                string typeName = typeNames[i];
                sw.WriteLine(string.Concat("\t", typeName, ","));
            }
            sw.WriteLine("}");
        }

        return true;
    }

    private static void AppendTabs(ref StringBuilder builder, int depth)
    {
        for (int i = 0; i < depth; i++)
            builder.Append("\t");
    }

    private static void OpenScope(ref StringBuilder builder, int depth)
    {
        AppendTabs(ref builder, depth);
        builder.AppendLine("{");
    }

    private static void CloseScope(ref StringBuilder builder, int depth)
    {
        AppendTabs(ref builder, depth);
        builder.AppendLine("}");
    }

    public static void GenerateActivator(string scriptPath, Type classType, Type enumType)
    {
        int depth = 0;

        StringBuilder builder = new StringBuilder();
        builder.AppendLine("namespace GameSystem {");
        builder.AppendLine("public partial class Activator");
        builder.AppendLine("{");
        {
            AppendTabs(ref builder, ++depth);

            string method = string.Concat("public static bool CreateInstance(out "
                , classType.FullName
                , " instance,"
                , enumType.FullName
                , " "
                , enumType.Name.ToLower()
                , ") {");
            builder.AppendLine(method);
            
            AppendTabs(ref builder, ++depth);
            builder.AppendLine(string.Format("instance = null;", classType.FullName));

            AppendTabs(ref builder, depth);
            builder.AppendLine(string.Concat("switch (", enumType.Name.ToLower(), ") {"));
            {
                depth++;

                string[] enumNames = Enum.GetNames(enumType);
                for (int i = 0; i < enumNames.Length; i++)
                {
                    string enumName = enumNames[i];
                    if (IsNull(enumName))
                        continue;

                    AppendTabs(ref builder, depth);
                    builder.AppendLine(string.Concat("case ", enumType.Name, ".", enumName, ":"));

                    AppendTabs(ref builder, ++depth);
                    builder.AppendLine(string.Concat("instance = new ", enumName, "();"));
                    
                    AppendTabs(ref builder, depth);
                    builder.AppendLine("break;");
                    --depth;
                }
                
                CloseScope(ref builder, --depth);

                AppendTabs(ref builder, depth);
                builder.AppendLine("return (instance != null);");
            }
            CloseScope(ref builder, --depth);
        }
        CloseScope(ref builder, --depth);
        builder.AppendLine("}");

        UnityEngine.Debug.Log(builder.ToString());

        FileStream fs = null;
        if (File.Exists(scriptPath))
            fs = File.Create(scriptPath);
        else
            fs = new FileStream(scriptPath, FileMode.Create);

        using (StreamWriter sw = new StreamWriter(fs))
        {
            sw.Write(builder.ToString());
        }
        
        //if (!string.IsNullOrEmpty(classType.Namespace))
        //{
        //    builder.AppendLine(classType.Namespace);
        //    builder.AppendLine("{");
        //    depth++;
        //}

        //if (!string.IsNullOrEmpty(classType.Namespace))
        //{
        //    builder.AppendLine("}");
        //}
    }
}
