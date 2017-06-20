using System;
using System.IO;

/// <summary>
/// Array 형태의 테이블
/// </summary>
/// <see cref="Table{T}"/>
/// <seealso cref="ListTable{T}"/>
/// <seealso cref="DictionaryTable{T}"/>
public class ArrayTable<T> : Table<T> where T : IIndexer
    , IDeserializable
    , ISerializable
    , new()
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
    
    public override int Count
    {
        get
        {
            return Length;
        }
    }

    public bool ContainsKey(int key)
    {
        int index = -1;
        if (m_isAscendingOrder)
        {
            index = BinarySearch(key);
            return (index != -1);
        }

        index = LinearSearch(key);
        return (index != -1);
    }

    public override void Clear()
    {
        if (m_container != null)
            Array.Clear(m_container, 0, m_container.Length);
    }
    
    protected override int BinarySearch(int value)
    {
        if (m_container != null)
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
        }
        
        // not found k
        return -1; 
    }

    private int LinearSearch(int key)
    {
        if (m_container != null)
        {
            for (int i = 0; i < m_container.Length; i++)
            {
                if (m_container[i].GetIndex() == key)
                    return i;
            }
        }
        return -1;
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

    public override T Find(Predicate<T> predicate)
    {
        for (int i = 0; i < Count; i++)
        {
            T match = m_container[i];
            if (predicate(match))
                return match;
        }
        return default(T);
    }

    public byte[] Deserialize()
    {
        for (int i = 0; i < Count; i++)
        {
            T match = m_container[i];

        }
        return null;
    }

    public override void Load(int totalItemCount, Deserializer deserializer)
    {
        m_container = new T[totalItemCount];

        int lastIndex = int.MinValue;
        for (int i = 0; i < totalItemCount; i++)
        {
            T t = new T();
            t.Deserialize(deserializer);

            if (m_isAscendingOrder)
            {
                m_isAscendingOrder = IsAscendingOrder(ref lastIndex, t.GetIndex());
            }

            m_container[i] = t;
        }
    }

    public override void Load(JSONObject jsonList)
    {
        m_container = new T[jsonList.list.Count];

        int lastIndex = int.MinValue;
        for (int i = 0; i < jsonList.list.Count; i++)
        {
            JSONObject json = jsonList.list[i];
            T t = new T();
            t.Deserialize(json);

            if (m_isAscendingOrder)
            {
                m_isAscendingOrder = IsAscendingOrder(ref lastIndex, t.GetIndex());
            }

            m_container[i] = t;
        }
    }

    public override void Export(BinaryWriter binaryWriter)
    {
        for (int i = 0; i < Count; i++)
        {
            T each = m_container[i];
            each.Serialize(binaryWriter);
        }
    }
}