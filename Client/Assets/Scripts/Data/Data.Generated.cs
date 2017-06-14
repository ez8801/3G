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
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Type);
			deserializer.Deserialize(ref Rarity);
			deserializer.Deserialize(ref Name);
			deserializer.Deserialize(ref Value);
			deserializer.Deserialize(ref Stackable);
		}

		public void Serialize(BinaryWriter binaryWriter)
		{
			binaryWriter.Write(Id);
			binaryWriter.Write(Type);
			binaryWriter.Write(Rarity);
			binaryWriter.Write(Name);
			binaryWriter.Write(Value);
			binaryWriter.Write(Stackable);
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
			return Id;
		}
	}

}
