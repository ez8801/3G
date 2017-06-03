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
        LoadItems(ResourceLoad("Items.json"));
    }

    private JSONObject ResourceLoad(string fileName)
    {
        string filePath = string.Concat(Application.streamingAssetsPath, "/", fileName);
        string text = File.ReadAllText(filePath);
        return new JSONObject(text);
    }

    private void LoadItems(JSONObject data)
    {
        m_deserializer.Load(data, ItemTable.Instance);
    }
}
