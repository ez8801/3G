using UnityEngine;
using System;
using System.Text;
using System.IO;
#if UNITY_EDITOR
using UnityEditor;

using System.Reflection;
#endif

public class Deserializer
{
    private static readonly UTF8Encoding encoding = new UTF8Encoding();
    
    private BinaryReader m_binaryReader;
    private int m_rowCount;
    // private short m_rowCount;

    public void Load<T>(JSONObject data, Table<T> table) where T: IIndexer, IDeserializable, new()
    {
        Assert.IsNotNull(data, new ArgumentNullException("data").ToString());
        Assert.IsNotNull(table, new ArgumentNullException("table").ToString());
        
        table.Load(data);
    }

    public void Load<T>(TextAsset textAsset, Table<T> table) where T : IIndexer, IDeserializable, new()
    {
        Assert.IsNotNull(textAsset, new ArgumentNullException("textAsset").ToString());
        Assert.IsNotNull(table, new ArgumentNullException("table").ToString());
        
        m_rowCount = 0;

        m_binaryReader = new BinaryReader(new MemoryStream(textAsset.bytes), encoding);
        Deserialize(ref m_rowCount);
        table.Load(m_rowCount, this);
        
        m_binaryReader.Close();
        m_binaryReader = null;
    }

    public void Load(TextAsset textAsset, Action<Deserializer> onLoop)
    {
        Assert.IsNotNull(textAsset, new ArgumentNullException("textAsset").ToString());
        Assert.IsNotNull(onLoop, new ArgumentNullException("onLoop").ToString());
        
        m_rowCount = 0;

        m_binaryReader = new BinaryReader(new MemoryStream(textAsset.bytes), encoding);
        Deserialize(ref m_rowCount);
        for (int i = 0; i < m_rowCount; i++)
        {
            onLoop(this);
        }
        
        m_binaryReader.Close();
        m_binaryReader = null;
    }

    public void Deserialize(ref bool boolean)
    {
        boolean = m_binaryReader.ReadBoolean();
    }
    
    public void Deserialize(ref byte i1)
    {
        i1 = m_binaryReader.ReadByte();
    }

    public void Deserialize(ref short i2)
    {
        i2 = m_binaryReader.ReadInt16();
    }

    public void Deserialize(ref int i4)
    {
        i4 = m_binaryReader.ReadInt32();
    }
    
    public void Deserialize(ref string str)
    {
        //short bytesCount = m_binaryReader.ReadInt16();
        //byte[] bytes = m_binaryReader.ReadBytes(bytesCount);
        //str = encoding.GetString(bytes);

        str = m_binaryReader.ReadString();
    }

    public string ReadString()
    {
        return m_binaryReader.ReadString();
    }

#if UNITY_EDITOR

    [UnityEditor.Callbacks.DidReloadScripts]
    private static void DidReloadScripts()
    {
        bool isAutoGenerate = EditorPrefs.GetBool(kAutoGeneration, false);
        if (isAutoGenerate)
            GenerateSourceCode();
    }

    private const string kTargetNameSpace = "Data";
    private const string kDestinationPath = "Scripts/Data/Data.Generated.cs";
    private const string kAutoGeneration = "Auto Generation";
    private const string kAutoGenerationMode = "Code/Auto Generation Mode";

    [MenuItem(kAutoGenerationMode, false, 100)]
    private static void ToggleSimulationMode()
    {
        bool isAutoGeneration = EditorPrefs.GetBool(kAutoGeneration, false);
        EditorPrefs.SetBool(kAutoGeneration, !isAutoGeneration);
    }

    [MenuItem(kAutoGenerationMode, true)]
    private static bool ToggleSimulationModeValidate()
    {
        Menu.SetChecked(kAutoGenerationMode, EditorPrefs.GetBool(kAutoGeneration, false));
        return true;
    }

    private static string GetTypeName(Type type)
    {
        if (type == typeof(string))
            return "string";
        else if (type == typeof(long))
            return "long";
        else if (type == typeof(int))
            return "int";
        else if (type == typeof(short))
            return "short";
        else if (type == typeof(float))
            return "float";
        else if (type == typeof(bool))
            return "bool";

        return type.ToString();
    }

    private static string GetPropertyName(string fieldType)
    {
        if (fieldType == "string")
            return "STR";
        else if (fieldType == "long")
            return "I8";
        else if (fieldType == "float")
            return "f";
        else if (fieldType == "int")
            return "I4";
        else if (fieldType == "short")
            return "I2";
        else if (fieldType == "bool")
            return "B";
        return string.Empty;
    }

    [MenuItem("Code/Generate Deserialize Code")]
    private static void GenerateSourceCode()
    {
        Assembly executingAssembly = Assembly.GetExecutingAssembly();
        Type[] types = executingAssembly.GetTypes();

        StringBuilder builder = new StringBuilder();
        builder.AppendLine("using System.IO;");
        builder.AppendLine();

        builder.AppendFormat("namespace {0}", kTargetNameSpace);
        builder.AppendLine();
        builder.AppendLine("{");

        for (int i = 0; i < types.Length; i++)
        {
            Type type = types[i];
            if (type.Namespace != kTargetNameSpace)
                continue;

            var attributes = type.GetCustomAttributes(typeof(SerializableAttribute), true);
            if (attributes == null || attributes.Length == 0)
                continue;

            FieldInfo[] fieldInfos = type.GetFields(BindingFlags.Public
                | BindingFlags.Instance
                | BindingFlags.GetField
                | BindingFlags.SetField);
            if (fieldInfos == null || fieldInfos.Length == 0)
                continue;

            var primaryKeyAttributes = type.GetCustomAttributes(typeof(PrimaryKeyAttribute), true);
            bool isAssignPrimaryKey = (primaryKeyAttributes.Length > 0);

            string primaryKeyName = string.Empty;
            bool isStringKey = false;
            if (isAssignPrimaryKey)
            {
                PrimaryKeyAttribute primaryKeyAttribute = (PrimaryKeyAttribute)primaryKeyAttributes[0];
                primaryKeyName = primaryKeyAttribute.m_primaryKey;
            }

            var compositeKeyAttrbutes = type.GetCustomAttributes(typeof(CompositeKeyAttribute), true);
            bool isAssignCompositeKey = (compositeKeyAttrbutes.Length > 0);

            string definitionType = (type.IsClass) ? "class" : "struct";              
            builder.AppendFormat("\tpublic partial {0} {1} : IDeserializable, ISerializable", definitionType, type.Name);
            if (isAssignPrimaryKey || isAssignCompositeKey)
                builder.AppendLine(", IIndexer");
            else
                builder.AppendLine();
            builder.AppendLine("\t{");
            
            // Method: void Deserialize(JSONObject)
            builder.AppendLine("\t\tpublic void Deserialize(JSONObject json)");
            builder.AppendLine("\t\t{");

            for (int j = 0; j < fieldInfos.Length; j++)
            {
                FieldInfo fi = fieldInfos[j];
                var nonSerializedAttributes = fi.GetCustomAttributes(typeof(NonSerializedAttribute), true);
                if (!(nonSerializedAttributes == null || nonSerializedAttributes.Length == 0))
                    continue;

                string declaringTypeName = string.Empty;
                string dataTypeName = string.Empty;
                var declaringTypeAttributes = fi.GetCustomAttributes(typeof(DeclaringTypeAttribute), true);
                if (!(declaringTypeAttributes == null || declaringTypeAttributes.Length == 0))
                {
                    DeclaringTypeAttribute declaringType = (DeclaringTypeAttribute) declaringTypeAttributes[0];
                    declaringTypeName = declaringType.DeclaringTypeName;
                    dataTypeName = declaringType.DataTypeName;
                }

                string bindingCommand = string.Empty;
                string fieldType = string.Empty;
                string propertyName = string.Empty;
                if (string.IsNullOrEmpty(declaringTypeName))
                {
                    fieldType = GetTypeName(fi.FieldType);
                    propertyName = GetPropertyName(fieldType);
                    bindingCommand = string.Format("\t\t\t{0} = json[\"{0}\"].{1};"
                        , fi.Name, propertyName);
                }
                else
                {
                    fieldType = dataTypeName;
                    propertyName = GetPropertyName(fieldType);
                    if (dataTypeName == "string" && declaringTypeName == "int")
                    {
                        bindingCommand = string.Format("\t\t\t{0} = json[\"{0}\"].{1}.GetHashCode();"
                            , fi.Name, propertyName);
                    }
                    else
                    {
                        // Simple Cast
                        bindingCommand = string.Format("\t\t\t{0} = ({1})json[\"{0}\"].{2};"
                            , fi.Name, declaringTypeName, propertyName);
                    }
                }
                builder.AppendLine(bindingCommand);
            }
            builder.AppendLine("\t\t}");
            builder.AppendLine();

            // Method: void Deserialize(Deserializer)
            builder.AppendLine("\t\tpublic void Deserialize(Deserializer deserializer)");
            builder.AppendLine("\t\t{");

            for (int j = 0; j < fieldInfos.Length; j++)
            {
                FieldInfo fi = fieldInfos[j];
                var nonSerializedAttributes = fi.GetCustomAttributes(typeof(NonSerializedAttribute), true);
                if (!(nonSerializedAttributes == null || nonSerializedAttributes.Length == 0))
                    continue;

                if (fi.Name == primaryKeyName)
                {
                    if (fi.FieldType == typeof(string))
                        isStringKey = true;
                    else
                        isStringKey = false;
                }

                builder.AppendLine(string.Format("\t\t\tdeserializer.Deserialize(ref {0});", fi.Name));
            }
            builder.AppendLine("\t\t}");
            builder.AppendLine();

            // Method: void Serialize(BinaryWriter)
            builder.AppendLine("\t\tpublic void Serialize(BinaryWriter binaryWriter)");
            builder.AppendLine("\t\t{");

            for (int j = 0; j < fieldInfos.Length; j++)
            {
                FieldInfo fi = fieldInfos[j];
                var nonSerializedAttributes = fi.GetCustomAttributes(typeof(NonSerializedAttribute), true);
                if (!(nonSerializedAttributes == null || nonSerializedAttributes.Length == 0))
                    continue;
                
                builder.AppendLine(string.Format("\t\t\tbinaryWriter.Write({0});", fi.Name));
            }
            builder.AppendLine("\t\t}");
            builder.AppendLine();

            // Method: int GetIndex(void).PrimaryKey
            if (isAssignPrimaryKey)
            {
                builder.AppendLine("\t\tpublic int GetIndex()");
                builder.AppendLine("\t\t{");
                
                if (isStringKey)
                    builder.AppendFormat("\t\t\treturn {0}.GetHashCode();", primaryKeyName);
                else
                    builder.AppendFormat("\t\t\treturn {0};", primaryKeyName);

                builder.AppendLine();
                builder.AppendLine("\t\t}");
            }

            // Method: int GetIndex(void).CompositeKey
            if (isAssignCompositeKey)
            {
                CompositeKeyAttribute compositeKeyAttrbute = (CompositeKeyAttribute)compositeKeyAttrbutes[0];

                builder.AppendLine("\t\tpublic int GetIndex()");
                builder.AppendLine("\t\t{");
                builder.Append("\t\t\treturn string.Concat(");
                if (!string.IsNullOrEmpty(compositeKeyAttrbute.m_key1))
                    builder.Append(compositeKeyAttrbute.m_key1);
                if (!string.IsNullOrEmpty(compositeKeyAttrbute.m_key2))
                    builder.AppendFormat(", {0}", compositeKeyAttrbute.m_key2);
                if (!string.IsNullOrEmpty(compositeKeyAttrbute.m_key3))
                    builder.AppendFormat(", {0}", compositeKeyAttrbute.m_key3);
                builder.AppendLine(").GetHashCode();");
                builder.AppendLine("\t\t}");
            }

            builder.AppendLine("\t}");
            builder.AppendLine();
        }
        builder.AppendLine("}");
        
        string scriptPath = Path.Combine(Application.dataPath, kDestinationPath);

        FileStream fs = null;
        if (File.Exists(scriptPath))
            File.Delete(scriptPath);

        fs = File.Create(scriptPath);

        //if (File.Exists(scriptPath) == false)
        //    fs = File.Create(scriptPath);
        //else
        //    fs = File.Open(scriptPath, FileMode.OpenOrCreate);

        using (StreamWriter sw = new StreamWriter(fs, Encoding.UTF8))
        {
            using (StringReader sr = new StringReader(builder.ToString()))
            {
                while (sr.Peek() != -1)
                {
                    sw.WriteLine(sr.ReadLine());
                }

                sw.Flush();
            }
        }

        AssetDatabase.Refresh();
    }

#endif
}
