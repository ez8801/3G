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

    public bool ContainsKey(int key)
    {
        if (m_container != null)
        {
            for (int i = 0; i < m_container.Count; i++)
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
            m_container.Clear();
    }

    protected override int BinarySearch(int value)
    {
        var start = 0;
        var end = Count - 1;
        while (start <= end)
        {
            var mid = (start + end) / 2;
            if (this[mid].GetIndex() > value)
                end = mid - 1;
            else if (this[mid].GetIndex() < value)
                start = mid + 1;
            else
            {
                // found k
                return mid;
            }
        }

        // not found k
        return -1;
    }

    private int LinearSearch(int key)
    {
        return m_container.FindIndex((match) => {
            return match.GetIndex() == key;
        });
    }

    public override T Find(int key)
    {
        int index = -1;
        if (m_isAscendingOrder)
        {
            index = BinarySearch(key);
            if (index != -1)
                return m_container[index];
        }

        index = LinearSearch(key);
        return (index >= 0) ? m_container[index] : default(T);
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
    
    public override void Load(JSONObject jsonList)
    {
        m_container = new List<T>();
        for (int i = 0; i < jsonList.list.Count; i++)
        {
            JSONObject json = jsonList.list[i];
            T t = new T();
            t.Deserialize(json);
            m_container.Add(t);
        }
    }
}