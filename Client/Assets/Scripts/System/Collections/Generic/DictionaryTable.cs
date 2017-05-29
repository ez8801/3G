using System.Collections.Generic;

public class DictionaryTable<T> : Table<T> where T : IIndexer, IDeserializable, new()
{
    protected Dictionary<int, T> m_container;

    public T this[int index]
    {
        get
        {
            return Find(index);
        }
    }

    public int Count
    {
        get
        {
            if (m_container == null)
                return 0;
            return m_container.Count;
        }
    }

    public bool ContainsKey(int key)
    {
        return m_container.ContainsKey(key);
    }

    public override void Clear()
    {
        if (m_container != null)
            m_container.Clear();
    }

    public override T Find(int index)
    {
        T data;
        m_container.TryGetValue(index, out data);
        return data;
    }

    public override void Load(int totalItemCount, Deserializer deserializer)
    {
        m_container = new Dictionary<int, T>();
        for (int i = 0; i < totalItemCount; i++)
        {
            T t = new T();
            t.Deserialize(deserializer);
            m_container.Add(t.GetIndex(), t);
        }
    }
}