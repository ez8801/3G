/* 
 * ObserverBase.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-13
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */
 
using System;
using System.Collections.Generic;

public abstract class ObserverBase<T> : IObservable<T> where T : new()
{
    private List<IObserver<T>> m_observers = new List<IObserver<T>>();

    public IDisposable Subscribe(IObserver<T> observer)
    {
        if (!m_observers.Contains(observer))
            m_observers.Add(observer);
        return new Unsubscriber(m_observers, observer);
    }

    private class Unsubscriber : IDisposable
    {
        private List<IObserver<T>> _observers;
        private IObserver<T> _observer;

        public Unsubscriber(List<IObserver<T>> observers, IObserver<T> observer)
        {
            this._observers = observers;
            this._observer = observer;
        }

        public void Dispose()
        {
            if (_observer != null && _observers.Contains(_observer))
                _observers.Remove(_observer);
        }
    }

    public virtual void Post(T t)
    {
        for (int i = 0; i < m_observers.Count; i++)
        {
            m_observers[i].OnNext(t);
        }
    }

    public virtual void Clear()
    {
        foreach (var observer in m_observers.ToArray())
        {
            if (m_observers.Contains(observer))
                observer.OnCompleted();
        }

        m_observers.Clear();
    }
}