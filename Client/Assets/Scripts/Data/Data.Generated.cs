using System.IO;

namespace Data
{
	public partial struct Item : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Type = json["Type"].I4;
			Rarity = json["Rarity"].I4;
			Name = json["Name"].STR;
			Value = json["Value"].I4;
			Stackable = json["Stackable"].B;
			Texture = json["Texture"].STR;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Type);
			deserializer.Deserialize(ref Rarity);
			deserializer.Deserialize(ref Name);
			deserializer.Deserialize(ref Value);
			deserializer.Deserialize(ref Stackable);
			deserializer.Deserialize(ref Texture);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(Type);
			binaryWriter.Write(Rarity);
			binaryWriter.Write(Name);
			binaryWriter.Write(Value);
			binaryWriter.Write(Stackable);
			binaryWriter.Write(Texture);
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
			Key = json["Key"].STR;
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
			return Key.GetHashCode();
		}
	}

	public partial struct String : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Key = json["Key"].STR;
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
			return Key.GetHashCode();
		}
	}

	public partial struct Monster : IDeserializable, ISerializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Grade = json["Grade"].I4;
			Name = json["Name"].STR;
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
			Name = json["Name"].STR;
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
			Message = json["Message"].STR;
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

}
