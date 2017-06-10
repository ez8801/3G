using System;
using System.IO;
using System.Collections;
using System.Collections.Generic;

/// <summary>
/// Dictionary 형태의 테이블
/// </summary>
/// <see cref="Table{T}"/>
/// <seealso cref="ArrayTable{T}"/>
/// <seealso cref="ListTable{T}"/>
public class DictionaryTable<T> : Table<T> where T : IIndexer
    , IDeserializable
    , ISerializable
    , new()
{
    protected Dictionary<int, T> m_container;

    public T this[int index]
    {
        get
        {
            return Find(index);
        }
    }

    public override int Count
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

    public override T Find(Predicate<T> predicate)
    {
        var enumerator = m_container.GetEnumerator();
        while (enumerator.MoveNext())
        {
            T match = enumerator.Current.Value;
            if (predicate(match))
                return match;       
        }
        return default(T);
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

    public override void Load(JSONObject jsonList)
    {
        m_container = new Dictionary<int, T>();
        for (int i = 0; i < jsonList.list.Count; i++)
        {
            JSONObject json = jsonList.list[i];
            T t = new T();
            t.Deserialize(json);
            m_container.Add(t.GetIndex(), t);
        }
    }

    public override void Export(BinaryWriter binaryWriter)
    {
        var enumerator = m_container.GetEnumerator();
        while (enumerator.MoveNext())
        {
            T each = enumerator.Current.Value;
            each.Serialize(binaryWriter);
        }
    }
}