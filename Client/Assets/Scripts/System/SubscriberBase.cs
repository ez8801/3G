/* 
 * SubscriberBase.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-13
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */
 
using System;

public class SubscriberBase<T> : IObserver<T> where T : new()
{
    private IDisposable m_cancellation;

    public virtual void Subscribe(ObserverBase<T> provider)
    {
        if (provider != null)
            m_cancellation = provider.Subscribe(this);
    }

    public virtual void Unsubscribe()
    {
        m_cancellation.Dispose();
    }

    public virtual void OnCompleted()
    {
        Unsubscribe();
    }

    public virtual void OnError(Exception error)
    {
        
    }

    public virtual void OnNext(T value)
    {

    }
}