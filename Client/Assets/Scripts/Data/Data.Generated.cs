namespace Data
{
	public partial struct Item : IDeserializable, IIndexer
	{
		public void Deserialize(Deserializer deserializer)
		{
			deserializer.Deserialize(ref index);
			deserializer.Deserialize(ref type);
			deserializer.Deserialize(ref name);
		}

		public int GetIndex()
		{
			return index;
		}
	}

}