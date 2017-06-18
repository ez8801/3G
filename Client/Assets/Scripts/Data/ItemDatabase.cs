using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using LitJson;
using System.IO;

//json이용 아이템 정보 가져와서 파싱

public class ItemDatabase : MonoBehaviour {


    private List<Item> database = new List<Item>();
    private JsonData itemData;

    private void Start()
    {
        itemData = JsonMapper.ToObject(File.ReadAllText(Application.dataPath + "/StreamingAssets/Items.json"));
        ConstructItemDatabase();

        Debug.Log(FetchItemByID(0).Title);
    }

    public Item FetchItemByID(int id)
    {
        for(int i = 0; i < database.Count; i++)
        {
            if(database[i].ID == id)           
            return database[i];
        }
        return null;
    }

    void ConstructItemDatabase()
    {
        for(int i = 0; i < itemData.Count; i++)
        {
            database.Add(new Item((int)itemData[i]["id"], itemData[i]["title"].ToString(), (int)itemData[i]["value"],(bool)itemData[i]["stackable"], (int)itemData[i]["rarity"], (int)itemData[i]["type"]));
        }

    }

    public class Item
    {
        public int ID { get; set; }
        public string Title { get; set; }
        public int Value { get; set; }
        public bool Stackable { get; set; }
        public int Rarity { get; set; }
        public int Type { get; set; }


        public Item(int id, string title, int value, bool stackable, int rarity, int type)
        {
            this.ID = id;
            this.Title = title;
            this.Value = value;
            this.Stackable = stackable;
            this.Rarity = rarity;
            this.Type = type;
        }

        public Item()
        {
            this.ID = -1;
        }
    }


}
