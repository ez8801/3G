using System.Collections.Generic;

public class Intent
{
    private Dictionary<string, object> m_bundle;

    public byte GetByteExtra(string key, byte defaultValue)
    {
        if (m_bundle != null && m_bundle.ContainsKey(key))
            return (byte)m_bundle[key];
        return defaultValue;
    }

    public char GetCharExtra(string key, char defaultValue)
    {
        if (m_bundle != null && m_bundle.ContainsKey(key))
            return (char)m_bundle[key];
        return defaultValue;
    }

    public short GetShortExtra(string key, short defaultValue)
    {
        if (m_bundle != null && m_bundle.ContainsKey(key))
            return (short)m_bundle[key];
        return defaultValue;
    }

    public int GetIntExtra(string key, int defaultValue)
    {
        if (m_bundle != null && m_bundle.ContainsKey(key))
            return (int)m_bundle[key];
        return defaultValue;
    }

    public float GetFloatExtra(string key, float defaultValue)
    {
        if (m_bundle != null && m_bundle.ContainsKey(key))
            return (float)m_bundle[key];
        return defaultValue;
    }

    public long GetLongExtra(string key, long defaultValue)
    {
        if (m_bundle != null && m_bundle.ContainsKey(key))
            return (long)m_bundle[key];
        return defaultValue;
    }

    public double GetDoubleExtra(string key, double defaultValue)
    {
        if (m_bundle != null && m_bundle.ContainsKey(key))
            return (double)m_bundle[key];
        return defaultValue;
    }

    public string GetStringExtra(string key)
    {
        if (m_bundle != null && m_bundle.ContainsKey(key))
            return (string)m_bundle[key];
        return string.Empty;
    }

    public bool HasExtra(string key)
    {
        return (m_bundle != null && m_bundle.ContainsKey(key));
    }

    public Intent PutExtra(string key, byte value)
    {
        if (m_bundle == null)
            m_bundle = new Dictionary<string, object>();
        if (m_bundle.ContainsKey(key) == false)
            m_bundle.Add(key, value);
        return this;
    }

    public Intent PutExtra(string key, char value)
    {
        if (m_bundle == null)
            m_bundle = new Dictionary<string, object>();
        if (m_bundle.ContainsKey(key) == false)
            m_bundle.Add(key, value);
        return this;
    }

    public Intent PutExtra(string key, short value)
    {
        if (m_bundle == null)
            m_bundle = new Dictionary<string, object>();
        if (m_bundle.ContainsKey(key) == false)
            m_bundle.Add(key, value);
        return this;
    }

    public Intent PutExtra(string key, int value)
    {
        if (m_bundle == null)
            m_bundle = new Dictionary<string, object>();
        if (m_bundle.ContainsKey(key) == false)
            m_bundle.Add(key, value);
        return this;
    }

    public Intent PutExtra(string key, float value)
    {
        if (m_bundle == null)
            m_bundle = new Dictionary<string, object>();
        if (m_bundle.ContainsKey(key) == false)
            m_bundle.Add(key, value);
        return this;
    }

    public Intent PutExtra(string key, long value)
    {
        if (m_bundle == null)
            m_bundle = new Dictionary<string, object>();
        if (m_bundle.ContainsKey(key) == false)
            m_bundle.Add(key, value);
        return this;
    }

    public Intent PutExtra(string key, double value)
    {
        if (m_bundle == null)
            m_bundle = new Dictionary<string, object>();
        if (m_bundle.ContainsKey(key) == false)
            m_bundle.Add(key, value);
        return this;
    }

    public Intent PutExtra(string key, string value)
    {
        if (m_bundle == null)
            m_bundle = new Dictionary<string, object>();
        if (m_bundle.ContainsKey(key) == false)
            m_bundle.Add(key, value);
        return this;
    }

    public void RemoveExtra(string key)
    {
        if (m_bundle != null && m_bundle.ContainsKey(key))
            m_bundle.Remove(key);
    }
}
