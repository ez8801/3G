using UnityEngine;
using System.IO;
using System.Collections.Generic;

public class DataManager : MonoSingleton<DataManager>
{
    private Deserializer m_deserializer = null;

#if UNITY_EDITOR

    [SerializeField]
    private List<string> m_loadedTables = new List<string>();

#endif

    public void Initialize()
    {
        m_deserializer = new Deserializer();
    }

    public void LoadAllData()
    {
        LoadTable("Character.json", CharacterTable.Instance);
        LoadTable("Config.json", ConfigTable.Instance);
        LoadTable("DropItem.json", DropItemTable.Instance);    
        LoadTable("Item.json", ItemTable.Instance);
        LoadTable("Material.json", MaterialTable.Instance);
        LoadTable("Monster.json", MonsterTable.Instance);
        LoadTable("Prefab.json", PrefabTable.Instance);
        LoadTable("Recipe.json", RecipeTable.Instance);
        LoadTable("Stats.json", StatsTable.Instance);
        LoadTable("String.json", StringTable.Instance);
        LoadTable("Skill.json", SkillTable.Instance);
        LoadTable("Tip.json", TipTable.Instance);
        LoadTable("PassiveSkill.json", PassiveSkillTable.Instance);
        LoadTable("World.json", WorldTable.Instance);
        LoadTable("Stage.json", StageTable.Instance);
    }

    public void GenerateBytes()
    {
        string resourcesFolderPath = Path.Combine(Application.dataPath, "Resources/Data/");
        Serializer serializer = new Serializer(resourcesFolderPath);

        serializer.Serialize("Character", CharacterTable.Instance);
        serializer.Serialize("Config", ConfigTable.Instance);
        serializer.Serialize("DropItem", DropItemTable.Instance);
        serializer.Serialize("Item", ItemTable.Instance);
        serializer.Serialize("Material", MaterialTable.Instance);
        serializer.Serialize("Monster", MonsterTable.Instance);
        serializer.Serialize("Prefab", PrefabTable.Instance);
        serializer.Serialize("Recipe", RecipeTable.Instance);
        serializer.Serialize("Stats", StatsTable.Instance);
        serializer.Serialize("String", StringTable.Instance);
        serializer.Serialize("Tip", TipTable.Instance);
        serializer.Serialize("Skill", SkillTable.Instance);
        serializer.Serialize("PassiveSkill", PassiveSkillTable.Instance);
        serializer.Serialize("World", WorldTable.Instance);
        serializer.Serialize("Stage", StageTable.Instance);

        Validate("Character", new CharacterTable());
        Validate("Config", new ConfigTable());
        Validate("DropItem", new DropItemTable());
        Validate("Item", new ItemTable());
        Validate("Material", new MaterialTable());
        Validate("Monster", new MonsterTable());
        Validate("Prefab", new PrefabTable());
        Validate("Recipe", new RecipeTable());
        Validate("Stats", new StatsTable());
        Validate("String", new StringTable());
        Validate("Tip", new TipTable());
        Validate("Skill", new SkillTable());
        Validate("PassiveSkill", new PassiveSkillTable());
        Validate("World", new WorldTable());
        Validate("Stage", new StageTable());
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

    private void LoadTable<T>(string name, Table<T> table) where T : IIndexer, IDeserializable, new()
    {
        JSONObject data = ResourceLoad(name);
        m_deserializer.Load(data, table);

#if UNITY_EDITOR
        m_loadedTables.Add(name);
#endif
    }

    private void OnDestroy()
    {
        m_deserializer = null;
    }
}
