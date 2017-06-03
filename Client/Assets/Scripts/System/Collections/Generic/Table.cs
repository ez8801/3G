
public abstract class Table<T>
{
    public virtual T Find(int index)
    {
        return default(T);
    }

    public virtual void Clear()
    {
        //
    }

    public abstract void Load(int totalItemCount, Deserializer deserializer);
    public abstract void Load(JSONObject jsonList);
}