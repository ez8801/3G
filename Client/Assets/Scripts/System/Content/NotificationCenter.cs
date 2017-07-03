using System;
using System.Collections;
using System.Collections.Generic;

public interface IObserver
{
    void HandleNotification(Notification notification);
}

public class NotificationCenter : MonoSingleton<NotificationCenter>
{
    private Dictionary<int, List<WeakReference>> m_observers
        = new Dictionary<int, List<WeakReference>>();

    private List<WeakReference> m_firstResponders
        = new List<WeakReference>();

    EqualityComparer<IObserver> m_comparer
        = EqualityComparer<IObserver>.Default;

    /// <summary>
    /// 리스트에서 지정된 개체가 포함되어있는지 여부를 반환합니다.
    /// </summary>
    private bool IsContains(List<WeakReference> observers, IObserver observer)
    {
        if (observers == null || observers.Count == 0)
            return false;

        for (int i = 0; i < observers.Count; i++)
        {
            WeakReference weakReference = observers[i];
            if (IsEquals(weakReference, observer))
                return true;
        }
        return false;
    }

    /// <summary>
    /// 지정된 참조와 개체가 같은지 여부를 반환합니다.
    /// </summary>
    private bool IsEquals(WeakReference weakReference, IObserver observer)
    {
        if (IsExpiredObserver(weakReference))
            return false;
        IObserver match = weakReference.Target as IObserver;
        return m_comparer.Equals(match, observer);
    }

    /// <summary>
    /// 모든 메시지를 받는 옵저버를 추가합니다.
    /// </summary>
    public void AddObserver(IObserver observer)
    {
        bool isContains = IsContains(m_firstResponders, observer);
        if (isContains == false)
            m_firstResponders.Add(new WeakReference(observer));
    }

    /// <summary>
	/// 지정된 메시지를 기다리는 옵저버를 추가합니다.
	/// </summary>
    public void AddObserver(int id, IObserver observer)
    {
        if (!m_observers.ContainsKey(id))
            m_observers[id] = new List<WeakReference>();

        List<WeakReference> observers = m_observers[id];
        bool isContains = IsContains(observers, observer);
        if (isContains == false)
            m_observers[id].Add(new WeakReference(observer));
    }

    /// <summary>
    /// 지정된 옵저버, 메시지에 해당하는 항목을 제거합니다.
    /// </summary>
    public void RemoveObserver(int id, IObserver observer)
    {
        if (observer == null || !m_observers.ContainsKey(id))
            return;

        List<WeakReference> observers = m_observers[id];
        if ((observers == null || observers.Count == 0) == false)
        {
            for (int i = 0; i < observers.Count; i++)
            {
                WeakReference weakReference = observers[i];
                if (IsEquals(weakReference, observer))
                {
                    observers.RemoveAt(i);
                    break;
                }
            }

            //if (observers.Contains(observer))
            //	observers.Remove(observer);

            if (observers.Count == 0)
                m_observers.Remove(id);
        }
    }

    /// <summary>
	/// 지정된 옵저버에 해당하는 항목을 모두 제거합니다.
	/// </summary>
    public void RemoveObserver(IObserver observer)
    {
        if (m_firstResponders.Count > 0)
        {
            for (int i = 0; i < m_firstResponders.Count; i++)
            {
                WeakReference weakReference = m_firstResponders[i];
                if (IsEquals(weakReference, observer))
                {
                    m_firstResponders.RemoveAt(i);
                    break;
                }
            }
        }

        if (observer == null || m_observers.Count == 0)
            return;

        var enumerator = m_observers.GetEnumerator();
        while (enumerator.MoveNext())
        {
            int message = enumerator.Current.Key;
            List<WeakReference> observers = m_observers[message];
            if ((observers == null || observers.Count == 0) == false)
            {
                for (int i = 0; i < observers.Count; i++)
                {
                    WeakReference weakReference = observers[i];
                    if (IsEquals(weakReference, observer))
                    {
                        observers.RemoveAt(i);
                        break;
                    }
                }

                //if (observers.Count == 0)
                //    m_observers.Remove(message);
            }
        }
    }

    public void RemoveAll()
    {
        if (m_observers.Count > 0)
        {
            m_observers.Clear();
        }

        if (m_firstResponders.Count > 0)
        {
            m_firstResponders.Clear();
        }
    }

    public bool IsExpiredObserver(WeakReference match)
    {
        return (match == null || match.IsAlive == false || match.Target == null);
    }
    
    public void Post(Notification.System systemMessage)
    {
        Post((int)systemMessage);
    }

    public void Post(Notification.UI uiMessage)
    {
        Post((int)uiMessage);
    }

    public void Post(int id)
    {
        Post(new Notification(id));
    }

    public void Post(int id, long data)
    {
        Post(new Notification(id, data));
    }

    public void Post(int id, int data)
    {
        Post(new Notification(id, data));
    }

    public void Post(int id, float data)
    {
        Post(new Notification(id, data));
    }

    public void Post(int id, string data)
    {
        Post(new Notification(id, data));
    }

    public void Post(int id, bool data)
    {
        Post(new Notification(id, data));
    }

    public void Post(int id, object data)
    {
        Post(new Notification(id, data));
    }

    //
    public void PostDelayed(int id, float delayTime)
    {
        StartCoroutine(PerformPostDelayed(new Notification(id), delayTime));
    }
    
    public void PostDelayed(int id, int data, float delayTime)
    {
        StartCoroutine(PerformPostDelayed(new Notification(id, data), delayTime));
    }

    public void PostDelayed(int id, float data, float delayTime)
    {
        StartCoroutine(PerformPostDelayed(new Notification(id, data), delayTime));
    }

    public void PostDelayed(int id, string data, float delayTime)
    {
        StartCoroutine(PerformPostDelayed(new Notification(id, data), delayTime));
    }

    public void PostDelayed(int id, bool data, float delayTime)
    {
        StartCoroutine(PerformPostDelayed(new Notification(id, data), delayTime));
    }

    public void PostDelayed(Notification notification, float delayTime)
    {
        StartCoroutine(PerformPostDelayed(notification, delayTime));
    }

    public IEnumerator PerformPostDelayed(Notification notification, float delayTime)
    {
        yield return YieldHelper.CreateInstance(delayTime);
        Post(notification);
    }

    public IEnumerator PerformPostDelayed(Notification notification, int skipFrameCount)
    {
        for (int i = 0; i < skipFrameCount; i++)
        {
            yield return null;
        }
        Post(notification);
    }

    public void Post(Notification notification)
    {
        if (m_firstResponders.Count > 0)
        {
            m_firstResponders.RemoveAll(IsExpiredObserver);
            for (int i = 0; i < m_firstResponders.Count; i++)
            {
                IObserver observer = m_firstResponders[i].Target as IObserver;
                observer.HandleNotification(notification);
            }
        }

        if (m_observers.ContainsKey(notification.id) == false)
        {
            return;
        }

        List<WeakReference> observers = m_observers[notification.id];
        if ((observers == null || observers.Count == 0) == false)
        {
            // 유효하지 않은 옵저버 삭제
            observers.RemoveAll(IsExpiredObserver);

            for (int i = 0; i < observers.Count; i++)
            {
                IObserver observer = observers[i].Target as IObserver;
                observer.HandleNotification(notification);

                //GameObject go = observers[i].Target as GameObject;
                //go.SendMessage("HandleNotification", notification, SendMessageOptions.DontRequireReceiver);
            }
        }
    }
}
