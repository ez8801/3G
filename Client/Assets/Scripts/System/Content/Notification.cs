
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
    public short shortExtra;
    public float floatExtra;
    public int intExtra;
    public string stringExtra;

    public Notification(int msg)
    {
        id = msg;
        boolExtra = false;
        shortExtra = 0;
        floatExtra = 0f;
        intExtra = 0;
        stringExtra = string.Empty;
    }

    public Notification(int msg, int data)
    {
        id = msg;
        boolExtra = false;
        shortExtra = 0;
        floatExtra = 0f;
        intExtra = data;
        stringExtra = string.Empty;
    }

    public Notification(int msg, float data)
    {
        id = msg;
        boolExtra = false;
        shortExtra = 0;
        floatExtra = data;
        intExtra = 0;
        stringExtra = string.Empty;
    }

    public Notification(int msg, string data)
    {
        id = msg;
        boolExtra = false;
        shortExtra = 0;
        floatExtra = 0f;
        intExtra = 0;
        stringExtra = data;
    }

    public Notification(int msg, bool data)
    {
        id = msg;
        boolExtra = data;
        shortExtra = 0;
        floatExtra = 0f;
        intExtra = 0;
        stringExtra = string.Empty;
    }
}
