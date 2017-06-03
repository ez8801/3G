
public abstract class Table<T>
{
    public virtual T Find(int index)
    {
        return default(T);
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
}