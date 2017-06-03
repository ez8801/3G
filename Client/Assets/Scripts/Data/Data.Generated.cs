namespace Data
{
	public partial struct Item : IDeserializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Type = json["Type"].I4;
			Rarity = json["Rarity"].I4;
			Name = json["Name"].STR;
			Stackable = json["Stackable"].B;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Type);
			deserializer.Deserialize(ref Rarity);
			deserializer.Deserialize(ref Name);
			deserializer.Deserialize(ref Stackable);
		}

		public int GetIndex()
		{
			return Id;
		}
	}

	public partial struct Config : IDeserializable, IIndexer
	{
		public void Deserialize(JSONObject json)
		{
			Id = json["Id"].I4;
			Value = json["Value"].STR;
		}

		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref Id);
			deserializer.Deserialize(ref Value);
		}

		public int GetIndex()
		{
			return Id;
		}
	}

}
