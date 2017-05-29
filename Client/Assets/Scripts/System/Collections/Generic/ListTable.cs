using System.Collections.Generic;

public class ListTable<T> : Table<T> where T : IIndexer, IDeserializable, new()
{
    protected List<T> m_container;

    public T this[int index]
    {
        get
        {
            return m_container[index];
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

    public override void Clear()
    {
        if (m_container != null)
            m_container.Clear();
    }

    public override T Find(int index)
    {
        return m_container.Find((match) => {
            return match.GetIndex() == index;
        });
    }

    public override void Load(int totalItemCount, Deserializer deserializer)
    {
        m_container = new List<T>(totalItemCount);
        for (int i = 0; i < totalItemCount; i++)
        {
            T t = new T();
            t.Deserialize(deserializer);
            m_container.Add(t);
        }
    }
}