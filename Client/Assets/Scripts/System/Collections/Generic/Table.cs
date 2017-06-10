using System;
using System.IO;
using System.Collections.Generic;

public abstract class Table<T>
{
#if UNITY_EDITOR
    public static List<Table<T>> Instances = new List<Table<T>>();
#endif

    public virtual T Find(int index)
    {
        return default(T);
    }

    public virtual T Find(Predicate<T> predicate)
    {
        return default(T);
    }

    public virtual int Count
    {
        get
        {
            return 0;
        }
    }

    protected virtual int BinarySearch(int value)
    {
        return -1;
    }

    public bool BinarySearchable
    {
        get
        {
            return m_isAscendingOrder;
        }
    }
    
    protected bool IsAscendingOrder(ref int lastIndex, int compareIndex)
    {
        if (lastIndex < compareIndex)
        {
            lastIndex = compareIndex;
            return true;
        }

        return false;
    }

    public virtual void Clear()
    {
        //
    }

    protected bool m_isAscendingOrder = true;

    public abstract void Load(int totalItemCount, Deserializer deserializer);
    public abstract void Load(JSONObject jsonList);

    public abstract void Export(BinaryWriter binaryWriter);
}