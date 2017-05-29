using System.Collections;

/// <summary>
/// Collection의 확장함수를 정의하는 클래스
/// </summary>
public static class CollectionEx
{
    /// <summary>
    /// 지정된 Collection이 null이거나 비어있는지를 나타냅니다.
    /// </summary>
    public static bool IsNullOrEmpty(ICollection collection)
    {
        return (collection == null || collection.Count == 0);
    }

    /// <summary>
    /// 지정된 Array가 null이거나 비어있는지를 나타냅니다.
    /// </summary>
    public static bool IsNullOrEmpty(System.Array array)
    {
        return (array == null || array.Length == 0);
    }
}