using System;

public class ArrayTable<T> : Table<T> where T : IIndexer, IDeserializable, new()
{
    protected T[] m_container;

    public T this[int index]
    {
        get
        {
            return m_container[index];
        }
    }

    public int Length
    {
        get
        {
            if (m_container == null)
                return 0;
            return m_container.Length;
        }
    }

    public int Count
    {
        get
        {
            return Length;
        }
    }

    public bool ContainsKey(int key)
    {
        if (m_container != null)
        {
            for (int i = 0; i < m_container.Length; i++)
            {
                if (m_container[i].GetIndex() == key)
                    return true;
            }
        }

        return false;
    }

    public override void Clear()
    {
        if (m_container != null)
            Array.Clear(m_container, 0, m_container.Length);
    }

    public override T Find(int index)
    {
        return Array.Find<T>(m_container, (match) => {
            return match.GetIndex() == index;
        });
    }

    public override void Load(int totalItemCount, Deserializer deserializer)
    {
        m_container = new T[totalItemCount];
        for (int i = 0; i < totalItemCount; i++)
        {
            T t = new T();
            t.Deserialize(deserializer);
            m_container[i] = t;
        }
    }
}