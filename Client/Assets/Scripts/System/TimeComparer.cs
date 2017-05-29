using System;

public static class TimeComparer
{
    /// <summary>
	/// 현재 시간 값과 지정된 DateTime 값 비교하고, 이후인지 여부를 반환합니다.
	/// </summary>
    public static bool IsAfter(DateTime dateTime)
    {
        return (TimeSynchronizer.Now.CompareTo(dateTime) > 0);
    }

    /// <summary>
	/// 현재 시간 값과 지정된 DateTime 값 비교하고, 날이 지났는지 여부를 반환합니다.
	/// </summary>
	public static bool IsAfterDay(DateTime dateTime)
    {
        DateTime tomorrow = new DateTime(dateTime.Year
            , dateTime.Month
            , dateTime.Day);
        tomorrow = tomorrow.AddDays(1);
        return IsAfter(tomorrow);
    }

    /// <summary>
    /// 현재 시간 값과 지정된 DateTime 값 비교하고, 달이 지났는지 여부를 반환합니다.
    /// </summary>
    public static bool IsAfterMonth(DateTime dateTime)
    {
        DateTime nextMonth = new DateTime(dateTime.Year
            , dateTime.Month
            , 1);
        nextMonth = nextMonth.AddMonths(1);
        return IsAfter(nextMonth);
    }

    /// <summary>
    /// 지정된 DateTime 값이 Min, Max의 사이 일자에 있는지 여부를 반환합니다.
    /// </summary>
    public static bool IsBetweenDay(DateTime min, DateTime max)
    {
        // From 12:00 AM
        DateTime startDate = new DateTime(min.Year, min.Month, min.Day);

        // To 11:59:59 PM
        DateTime endDate = new DateTime(max.Year, max.Month, max.Day, 23, 59, 59);

        return IsBetween(startDate, endDate);
    }

    /// <summary>
	/// 지정된 DateTime 값이 Min, Max의 사이에 있는지 여부를 반환합니다.
	/// </summary>
	public static bool IsBetween(DateTime value, DateTime min, DateTime max)
    {
        return value > min && value < max;
    }

    /// <summary>
	/// 현재 시간 값이 Min, Max의 사이에 있는지 여부를 반환합니다.
	/// </summary>
	public static bool IsBetween(DateTime min, DateTime max)
    {
        return IsBetween(TimeSynchronizer.Now, min, max);
    }
}
