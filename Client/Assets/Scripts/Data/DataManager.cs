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
        LoadTable(ResourceLoad("Items.json"), ItemTable.Instance);
        LoadTable(ResourceLoad("Config.json"), ConfigTable.Instance);
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
}
