/* 
 * IObserver.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-13
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System;

public interface IObserver<T>
{
    void OnCompleted();
    void OnError(Exception error);
    void OnNext(T value);
}