using System.IO;

namespace Data
{
	public partial struct Item : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Category = json["Category"].I4;
			Type = json["Type"].I4;
			Rarity = json["Rarity"].I4;
			Name = json["Name"].STR.GetHashCode();
			Desc = json["Desc"].STR.GetHashCode();
			Value = json["Value"].I4;
			ItemMaterialGroup = json["ItemMaterialGroup"].I4;
			Texture = json["Texture"].STR;
			Price = json["Price"].I4;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Category);
			deserializer.Deserialize(ref Type);
			deserializer.Deserialize(ref Rarity);
			deserializer.Deserialize(ref Name);
			deserializer.Deserialize(ref Desc);
			deserializer.Deserialize(ref Value);
			deserializer.Deserialize(ref ItemMaterialGroup);
			deserializer.Deserialize(ref Texture);
			deserializer.Deserialize(ref Price);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(Category);
			binaryWriter.Write(Type);
			binaryWriter.Write(Rarity);
			binaryWriter.Write(Name);
			binaryWriter.Write(Desc);
			binaryWriter.Write(Value);
			binaryWriter.Write(ItemMaterialGroup);
			binaryWriter.Write(Texture);
			binaryWriter.Write(Price);
		}

		public int GetIndex()
		{
			return Id;
		}
	}

	public partial struct Config : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Key = json["Key"].STR.GetHashCode();
			Value = json["Value"].I4;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Key);
			deserializer.Deserialize(ref Value);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(Key);
			binaryWriter.Write(Value);
		}

		public int GetIndex()
		{
			return Key;
		}
	}

	public partial struct String : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Key = json["Key"].STR.GetHashCode();
			Value = json["Value"].STR;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Key);
			deserializer.Deserialize(ref Value);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Key);
			binaryWriter.Write(Value);
		}

		public int GetIndex()
		{
			return Key;
		}
	}

	public partial struct Monster : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Grade = json["Grade"].I4;
			Name = json["Name"].STR.GetHashCode();
			StatsId = json["StatsId"].I4;
			PrefabId = json["PrefabId"].I4;
			DropGroupId = json["DropGroupId"].I4;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Grade);
			deserializer.Deserialize(ref Name);
			deserializer.Deserialize(ref StatsId);
			deserializer.Deserialize(ref PrefabId);
			deserializer.Deserialize(ref DropGroupId);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(Grade);
			binaryWriter.Write(Name);
			binaryWriter.Write(StatsId);
			binaryWriter.Write(PrefabId);
			binaryWriter.Write(DropGroupId);
		}

		public int GetIndex()
		{
			return Id;
		}
	}

	public partial struct Stats : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Hp = json["Hp"].I4;
			AttackDamage = json["AttackDamage"].I4;
			Armor = json["Armor"].I4;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Hp);
			deserializer.Deserialize(ref AttackDamage);
			deserializer.Deserialize(ref Armor);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(Hp);
			binaryWriter.Write(AttackDamage);
			binaryWriter.Write(Armor);
		}

		public int GetIndex()
		{
			return Id;
		}
	}

	public partial struct Character : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Name = json["Name"].STR.GetHashCode();
			StatsId = json["StatsId"].I4;
			PrefabId = json["PrefabId"].I4;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Name);
			deserializer.Deserialize(ref StatsId);
			deserializer.Deserialize(ref PrefabId);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(Name);
			binaryWriter.Write(StatsId);
			binaryWriter.Write(PrefabId);
		}

		public int GetIndex()
		{
			return Id;
		}
	}

	public partial struct Prefab : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			PrefabName = json["PrefabName"].STR;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref PrefabName);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(PrefabName);
		}

		public int GetIndex()
		{
			return Id;
		}
	}

	public partial struct Tip : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Message = json["Message"].STR.GetHashCode();
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Message);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(Message);
		}

		public int GetIndex()
		{
			return Id;
		}
	}

	public partial struct Skill : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Type = json["Type"].I4;
			Name = json["Name"].STR;
			Cooltime = json["Cooltime"].I4;
			Effect = json["Effect"].I4;
			Texture = json["Texture"].STR;
			Chargeable = json["Chargeable"].B;
			Charging = json["Charging"].I4;
			Level = json["Level"].I4;
			Summary = json["Summary"].STR;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Type);
			deserializer.Deserialize(ref Name);
			deserializer.Deserialize(ref Cooltime);
			deserializer.Deserialize(ref Effect);
			deserializer.Deserialize(ref Texture);
			deserializer.Deserialize(ref Chargeable);
			deserializer.Deserialize(ref Charging);
			deserializer.Deserialize(ref Level);
			deserializer.Deserialize(ref Summary);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(Type);
			binaryWriter.Write(Name);
			binaryWriter.Write(Cooltime);
			binaryWriter.Write(Effect);
			binaryWriter.Write(Texture);
			binaryWriter.Write(Chargeable);
			binaryWriter.Write(Charging);
			binaryWriter.Write(Level);
			binaryWriter.Write(Summary);
		}

		public int GetIndex()
		{
			return Id;
		}
	}

	public partial struct PassiveSkill : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Type = json["Type"].I4;
			Name = json["Name"].STR;
			Texture = json["Texture"].STR;
			Level = json["Level"].I4;
			Summary = json["Summary"].STR;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Type);
			deserializer.Deserialize(ref Name);
			deserializer.Deserialize(ref Texture);
			deserializer.Deserialize(ref Level);
			deserializer.Deserialize(ref Summary);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(Type);
			binaryWriter.Write(Name);
			binaryWriter.Write(Texture);
			binaryWriter.Write(Level);
			binaryWriter.Write(Summary);
		}

		public int GetIndex()
		{
			return Id;
		}
	}

	public partial struct DropItem : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Group = json["Group"].I4;
			ItemId = json["ItemId"].I4;
			MinCount = json["MinCount"].I4;
			MaxCount = json["MaxCount"].I4;
			Prob = json["Prob"].I4;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Group);
			deserializer.Deserialize(ref ItemId);
			deserializer.Deserialize(ref MinCount);
			deserializer.Deserialize(ref MaxCount);
			deserializer.Deserialize(ref Prob);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(Group);
			binaryWriter.Write(ItemId);
			binaryWriter.Write(MinCount);
			binaryWriter.Write(MaxCount);
			binaryWriter.Write(Prob);
		}

		public int GetIndex()
		{
			return Id;
		}
	}

	public partial struct Material : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Group = json["Group"].I4;
			Name = json["Name"].STR.GetHashCode();
			ItemMaterialGroup = json["ItemMaterialGroup"].I4;
			RequestCount = json["RequestCount"].I4;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Group);
			deserializer.Deserialize(ref Name);
			deserializer.Deserialize(ref ItemMaterialGroup);
			deserializer.Deserialize(ref RequestCount);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(Group);
			binaryWriter.Write(Name);
			binaryWriter.Write(ItemMaterialGroup);
			binaryWriter.Write(RequestCount);
		}

		public int GetIndex()
		{
			return Id;
		}
	}

	public partial struct Recipe : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Name = json["Name"].STR.GetHashCode();
			RecipeKind = json["RecipeKind"].I2;
			MaterialGroupId = json["MaterialGroupId"].I4;
			ResultItemId = json["ResultItemId"].I4;
			CostGold = json["CostGold"].I4;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Name);
			deserializer.Deserialize(ref RecipeKind);
			deserializer.Deserialize(ref MaterialGroupId);
			deserializer.Deserialize(ref ResultItemId);
			deserializer.Deserialize(ref CostGold);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(Name);
			binaryWriter.Write(RecipeKind);
			binaryWriter.Write(MaterialGroupId);
			binaryWriter.Write(ResultItemId);
			binaryWriter.Write(CostGold);
		}

		public int GetIndex()
		{
			return Id;
		}
	}

	public partial struct Stage : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Name = json["Name"].STR.GetHashCode();
			WorldId = json["WorldId"].I4;
			GoldReward = json["GoldReward"].I4;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Name);
			deserializer.Deserialize(ref WorldId);
			deserializer.Deserialize(ref GoldReward);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(Name);
			binaryWriter.Write(WorldId);
			binaryWriter.Write(GoldReward);
		}

		public int GetIndex()
		{
			return Id;
		}
	}

	public partial struct World : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Name = json["Name"].STR.GetHashCode();
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Name);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(Name);
		}

		public int GetIndex()
		{
			return Id;
		}
       
    }
    public partial struct Active : IDeserializable, ISerializable, IIndexer
    {
        public void Deserialize(JSONObject json)
        {
            Id = json["Id"].I4;
            Type = json["Type"].I4;
            Cooltime = json["Cooltime"].I4;
            Effect = json["Effect"].I4;
            Texture = json["Texture"].STR;
            Chargeable = json["Chargeable"].B;
            Charging = json["Charging"].I4;
            Level = json["Level"].I4;
        }

        public void Deserialize(Deserializer deserializer)
        {
            deserializer.Deserialize(ref Id);
            deserializer.Deserialize(ref Type);
            deserializer.Deserialize(ref Cooltime);
            deserializer.Deserialize(ref Effect);
            deserializer.Deserialize(ref Texture);
            deserializer.Deserialize(ref Chargeable);
            deserializer.Deserialize(ref Charging);
            deserializer.Deserialize(ref Level);
        }

        public void Serialize(BinaryWriter binaryWriter)
        {
            binaryWriter.Write(Id);
            binaryWriter.Write(Type);
            binaryWriter.Write(Cooltime);
            binaryWriter.Write(Effect);
            binaryWriter.Write(Texture);
            binaryWriter.Write(Chargeable);
            binaryWriter.Write(Charging);
            binaryWriter.Write(Level);
        }

        public int GetIndex()
        {
            return Id;
        }
    }
}
