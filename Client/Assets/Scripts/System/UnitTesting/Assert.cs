using System;

/// <summary>
/// 어설션을 하는 데 필요한 메서드 및 속성 집합을 제공합니다. 
/// 이 클래스는 상속될 수 없습니다.
/// </summary>
public sealed class Assert
{
    public class AssertFailedException : Exception
    {
        private string AddtionalMessage;

        public AssertFailedException()
        {
            //
        }

        public AssertFailedException(string message)
        {
            AddtionalMessage = message;
        }

        public string GetClassName()
        {
            return GetType().Name;
        }

        public override string Message
        {
            get
            {
                return AddtionalMessage;
            }
        }

        public override string ToString()
        {
            string className;
            string message = AddtionalMessage;
            if (string.IsNullOrEmpty(message))
            {
                className = GetClassName();
            }
            else
            {
                className = string.Concat(GetClassName(), ": ", message);
            }
            string stackTrace = StackTrace;
            if (stackTrace != null)
            {
                className = string.Concat(className, Environment.NewLine, stackTrace);
            }
            return className;
        }
    }

    /// <summary>
    /// 지정된 조건이 true인지 확인합니다. 조건이 false이면 어설션이 실패합니다. 
    /// 어설션이 실패할 경우 메시지를 표시합니다.
    /// </summary>
    /// <param name="condition"></param>
    /// <param name="message"></param>
    public static void IsTrue(bool condition, string message)
    {
        if (condition == false)
        {
            Exception e = new AssertFailedException(message);
            throw e;
            // LogSystem.SendException(new KAssert.AssertFailedException(message));
        }
    }

    /// <summary>
    /// 지정된 조건이 false인지 확인합니다. 조건이 true이면 어설션이 실패합니다. 
    /// 어설션이 실패할 경우 메시지를 표시합니다.
    /// </summary>
    /// <param name="condition"></param>
    /// <param name="message"></param>
    public static void IsFalse(bool condition, string message)
    {
        if (condition)
        {
            Exception e = new AssertFailedException(message);
            throw e;
            // LogSystem.SendException(new AssertFailedException(message));
        }
    }

    /// <summary>
    /// 지정된 개체가 Null인지 확인합니다. 오브젝트가 null이 아니면 어셜션이 실패합니다. 
    /// 어설션이 실패할 경우 메시지를 표시합니다.
    /// </summary>
    public static void IsNull(object value, string message)
    {
        if (value != null)
        {
            Exception e = new AssertFailedException(message);
            throw e;
        }
    }

    /// <summary>
    /// 지정된 개체가 Null이 아닌지 확인합니다. 오브젝트가 null이면 어셜션이 실패합니다. 
    /// 어설션이 실패할 경우 메시지를 표시합니다.
    /// </summary>
    public static void IsNotNull(object value, string message)
    {
        if (value == null)
        {
            Exception e = new AssertFailedException(message);
            throw e;
        }
    }
}
