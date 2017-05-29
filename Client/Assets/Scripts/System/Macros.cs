#if UNITY_EDITOR
	#define REFLECTION_SUPPORT
#endif

#if REFLECTION_SUPPORT
using System.Reflection;
using System.Diagnostics;
using System.Text;
#endif

/// <summary>
/// 미리 정의된 매크로
/// </summary>
public class Macros
{
#if REFLECTION_SUPPORT
	private static StringBuilder builder;
#endif

	/// <summary>
	/// 현재 소스 파일의 이름을 반환합니다.
	/// </summary>
	public static string __FILE__
	{
		get
		{
#if REFLECTION_SUPPORT
			StackFrame stackFrame = GetCurrentStack();
			if (stackFrame != null)
				return stackFrame.GetFileName();
#endif
			return string.Empty;
		}
	}

	/// <summary>
	/// 현재 소스 파일의 줄 수를 반환합니다.
	/// </summary>
	public static int __LINE__
	{
		get
		{
#if REFLECTION_SUPPORT
			StackFrame stackFrame = GetCurrentStack();
			if (stackFrame != null)
				return stackFrame.GetFileLineNumber();
#endif
			return 0;
		}
	}

	/// <summary>
	/// 현재 스택의 함수명을 반환합니다.
	/// e.g. function
	/// </summary>
	public static string __func__
	{
		get
		{
#if REFLECTION_SUPPORT
			StackFrame stackFrame = GetCurrentStack();
			if (stackFrame == null)
				return string.Empty;

			MethodBase mb = stackFrame.GetMethod();
			if (mb != null)
				return mb.Name;
#endif
			return string.Empty;
		}
	}

	/// <summary>
	/// 현재 스택의 클래스, 반환, 인자를 포함한 함수명을 반환합니다.
	/// e.g. void className::function(params)
	/// </summary>
	public static string __PRETTY_FUNCTION__
	{
		get
		{
#if REFLECTION_SUPPORT
			StackFrame stackFrame = GetCurrentStack();
			if (stackFrame == null)
				return string.Empty;

			MethodBase mb = stackFrame.GetMethod();
			if (mb == null)
				return string.Empty;
			
			MethodInfo[] methodInfos = mb.ReflectedType.GetMethods(BindingFlags.Public
				| BindingFlags.NonPublic
				| BindingFlags.Static
				| BindingFlags.Instance
				| BindingFlags.GetField
				| BindingFlags.SetField);

			if (methodInfos == null || methodInfos.Length == 0)
				return mb.Name;
			
			MethodInfo methodInfo = null;
			for (int i = 0; i < methodInfos.Length; i++)
			{
				methodInfo = methodInfos[i];
				if (methodInfo.Name == mb.Name)
					break;
			}

			if (methodInfo == null)
				return mb.Name;

			if (builder == null)
				builder = new StringBuilder();
			builder.Length = 0;

			builder.AppendFormat("{0} {1}::{2}(", methodInfo.ReturnType.Name, mb.ReflectedType.Name, methodInfo.Name);			
			
			AppendParameter(methodInfo);
			
			builder.Append(")");
			return builder.ToString();
#else
            return string.Empty;
#endif
		}
	}

#if REFLECTION_SUPPORT

	private static void AppendParameter(MethodInfo methodInfo)
	{
		if (methodInfo == null)
			return;

		ParameterInfo[] paramInfos = methodInfo.GetParameters();
		if (paramInfos == null || paramInfos.Length == 0)
			return;

		for (int j = 0; j < paramInfos.Length; j++)
		{
			ParameterInfo paramInfo = paramInfos[j];
			builder.AppendFormat("{0} {1}, "
				, paramInfo.ParameterType.ToString()
				, paramInfo.Name);
		}
		builder.Remove(builder.Length - 2, 2);
	}

	/// <summary>
	/// 현재 호출 스택의 StackFrame를 반환합니다.
	/// </summary>
	private static StackFrame GetCurrentStack()
	{
		StackTrace stackTrace = new StackTrace(true);
		StackFrame[] stackFrames = stackTrace.GetFrames();
		if (stackFrames == null || stackFrames.Length == 0)
			return null;

		return stackFrames[2];
	}

#endif
}
