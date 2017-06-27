using UnityEngine;
using System.IO;

public class DataManager : MonoSingleton<DataManager>
{
    private Deserializer m_deserializer = null;
    
    public void Initialize()
    {
        m_deserializer = new Deserializer();
    }

    public void LoadAllData()
    {
        LoadTable(ResourceLoad("Config.json"), ConfigTable.Instance);
        LoadTable(ResourceLoad("Items.json"), ItemTable.Instance);
        LoadTable(ResourceLoad("Monster.json"), MonsterTable.Instance);
        LoadTable(ResourceLoad("Stats.json"), StatsTable.Instance);
        LoadTable(ResourceLoad("String.json"), StringTable.Instance);
    }

    public void GenerateBytes()
    {
        string resourcesFolderPath = Path.Combine(Application.dataPath, "Resources/Data/");
        Serializer serializer = new Serializer(resourcesFolderPath);

        serializer.Serialize("Config", ConfigTable.Instance);
        serializer.Serialize("Items", ItemTable.Instance);
        serializer.Serialize("Monster", MonsterTable.Instance);
        serializer.Serialize("Stats", StatsTable.Instance);
        serializer.Serialize("String", StringTable.Instance);

        Validate("Config", new ConfigTable());
        Validate("Items", new ItemTable());
        Validate("Monster", new MonsterTable());
        Validate("Stats", new StatsTable());
        Validate("String", new StringTable());
    }

    private bool Validate<T>(string tableName, Table<T> table) where T : IIndexer, IDeserializable, new()
    {
        TextAsset textAsset = Resources.Load<TextAsset>(string.Concat("Data/", tableName));
        if (textAsset == null)
        {
            Debug.LogWarning(string.Concat("Not found *.bytes file: ", tableName));
            return false;
        }

        try
        {
            m_deserializer.Load(textAsset, table);
        }
        catch (System.Exception e)
        {
            Debug.LogWarning(e.ToString());
            return false;
        }

        Debug.Log("Validate Success: " + tableName);
        return true;
    }

    private JSONObject ResourceLoad(string fileName)
    {
        string filePath = string.Concat(Application.streamingAssetsPath, "/", fileName);
        string text = File.ReadAllText(filePath);
        return new JSONObject(text);
    }

    private void LoadTable<T>(JSONObject data, Table<T> table) where T : IIndexer, IDeserializable, new()
    {
        m_deserializer.Load(data, table);
    }

    private void OnDestroy()
    {
        m_deserializer = null;
    }
}
