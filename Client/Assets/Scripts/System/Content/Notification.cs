
public class Notification
{
    public enum System
    {
        None,
        OnBackPressed,
        OnSceneChanged,
        Max
    }

    public enum UI
    {
        None = System.Max + 1,
        OnProgress,
        OnProgressDone,
        OnGoldChanged,
        Max
    }

    public enum Entity
    {
        None = UI.Max + 1,
        OnDead,
        Max,
    }

    public enum GameSystem
    {
        None = Entity.Max + 1,
        Win,
        Lose,
        Draw,
        Max,
    }
    
    public int id;
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

    public Notification(int msg)
    {
        id = msg;
        boolExtra = false;
        floatExtra = 0f;
        longExtra = 0;
        stringExtra = string.Empty;
        objectExtra = null;
    }

    public Notification(int msg, long data)
    {
        id = msg;
        boolExtra = false;
        floatExtra = 0f;
        longExtra = data;
        stringExtra = string.Empty;
        objectExtra = null;
    }

    public Notification(int msg, int data)
    {
        id = msg;
        boolExtra = false;
        floatExtra = 0f;
        longExtra = data;
        stringExtra = string.Empty;
        objectExtra = null;
    }

    public Notification(int msg, float data)
    {
        id = msg;
        boolExtra = false;
        floatExtra = data;
        longExtra = 0;
        stringExtra = string.Empty;
        objectExtra = null;
    }

    public Notification(int msg, string data)
    {
        id = msg;
        boolExtra = false;
        floatExtra = 0f;
        longExtra = 0;
        stringExtra = data;
    }

    public Notification(int msg, bool data)
    {
        id = msg;
        boolExtra = data;
        floatExtra = 0f;
        longExtra = 0;
        stringExtra = string.Empty;
        objectExtra = null;
    }

    public Notification(int msg, object data)
    {
        id = msg;
        boolExtra = false;
        floatExtra = 0f;
        longExtra = 0;
        stringExtra = string.Empty;
        objectExtra = data;
    }
}
