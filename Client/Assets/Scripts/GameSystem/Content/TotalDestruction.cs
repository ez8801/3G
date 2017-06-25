/* 
 * TotalDestruction.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ SHAprojectVer001. DefaultCompany, All rights reserved
 */

public class TotalDestruction : ICondition
{
    private Team m_team;

    public TotalDestruction(Team targetTeam)
    {
        SetTarget(targetTeam);
    }

    public void SetTarget(Team team)
    {
        m_team = team;
    }

    public bool IsDone()
    {
        for (int i = 0; i < m_team.GetMemberCount(); i++)
        {
            Team.Member member = m_team.GetMemberAt(i);
            if (member.Actor.IsAlive)
                return false;
        }
        return true;
    }
}