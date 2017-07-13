/* 
 * MatchJudge.cs
 * 
 * Writer : bmw122
 * Date   : 2017-07-03
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

public enum MatchResult
{
    None,
    Win,
    Draw,
    Lose,
}

public class MatchJudge
{
    private ConditionCompositer m_loseCondition = new ConditionCompositer();
    private ConditionCompositer m_winCondition = new ConditionCompositer();

    public void AddWinCondition(ICondition condition)
    {
        m_winCondition.AddCondition(condition);
    }

    public void AddLoseCondition(ICondition condition)
    {
        m_loseCondition.AddCondition(condition);
    }

    public void OnEntityDead(long entityId)
    {
        if (m_winCondition.IsDone())
        {
            NotificationCenter.Instance.Post((int)Notification.GameSystem.Win);
        }
    }
}