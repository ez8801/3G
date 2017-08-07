
public class Notification
{
    public R.Id id;
    public bool boolExtra;
    public short shortExtra
    {
        get
        {
            return (short)longExtra;
        }
    }

    public int intExtra
    {
        get
        {
            return (int)longExtra;
        }
    }

    public float floatExtra;    
    public long longExtra;
    public string stringExtra;
    public object objectExtra;

    public Notification(R.Id id)
    {
        this.id = id;
        boolExtra = false;
        floatExtra = 0f;
        longExtra = 0;
        stringExtra = string.Empty;
        objectExtra = null;
    }

    public Notification(R.Id id, long data)
    {
        this.id = id;
        boolExtra = false;
        floatExtra = 0f;
        longExtra = data;
        stringExtra = string.Empty;
        objectExtra = null;
    }

    public Notification(R.Id id, int data)
    {
        this.id = id;
        boolExtra = false;
        floatExtra = 0f;
        longExtra = data;
        stringExtra = string.Empty;
        objectExtra = null;
    }

    public Notification(R.Id id, float data)
    {
        this.id = id;
        boolExtra = false;
        floatExtra = data;
        longExtra = 0;
        stringExtra = string.Empty;
        objectExtra = null;
    }

    public Notification(R.Id id, string data)
    {
        this.id = id;
        boolExtra = false;
        floatExtra = 0f;
        longExtra = 0;
        stringExtra = data;
    }

    public Notification(R.Id id, bool data)
    {
        this.id = id;
        boolExtra = data;
        floatExtra = 0f;
        longExtra = 0;
        stringExtra = string.Empty;
        objectExtra = null;
    }

    public Notification(R.Id id, object data)
    {
        this.id = id;
        boolExtra = false;
        floatExtra = 0f;
        longExtra = 0;
        stringExtra = string.Empty;
        objectExtra = data;
    }
}
