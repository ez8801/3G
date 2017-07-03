/* 
 * Team.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections.Generic;

/// <summary>
/// 적과 아군을 구분하기 위한 클래스
/// </summary>
public class Team : EntityBase
{
    public const int kRedTeamId = 1;
    public const int kBlueTeamId = 2;

    private static List<Team> teams = new List<Team>();
    
    public static Team AddTeam(int id, string name)
    {
        GameObject go = new GameObject(name);
        Team team = go.AddComponent<Team>();
        team.Initialize(EntityType.Team, id);
        team.Id = id;
        team.SetTeamName(name);

        teams.Add(team);
        return team;
    }

    public static Team GetTeam(int id)
    {
        for (int i = 0; i < teams.Count; i++)
        {
            Team match = teams[i];
            if (match.Id == id)
                return match;
        }

        return null;
    }
    
    /// <summary>
    /// 팀원을 정의하는 클래스
    /// </summary>
    public class Member
    {
        public int TeamId;
        public int Id;
        public string Name;
        public Actor Actor;
    }
    
    public int Id;
    public string Name;

    /// <summary>
    /// 해당 팀에 소속된 멤버 목록
    /// </summary>
    private List<Member> m_members = new List<Member>();
    
    public void SetTeamName(string teamName)
    {
        Name = teamName;
    }
    
    public int GetMemberCount()
    {
        return (m_members != null) ? m_members.Count : 0;
    }

    public Member GetMemberAt(int index)
    {
        if (index < 0 || index >= m_members.Count)
            return null;
        return m_members[index];
    }

    public void AddMember(Actor actor)
    {
        Assert.IsNotNull(actor);
        actor.SetGroupId(Id);

        Member newMember = new Member();
        newMember.TeamId = Id;
        newMember.Id = m_members.Count;
        newMember.Name = string.Empty;
        newMember.Actor = actor;
        
        m_members.Add(newMember);
    }

    protected override void OnDestroy()
    {
        if (teams.Count > 0)
            teams.Remove(this);

        base.OnDestroy();
    }

    public float HpRatio
    {
        get
        {
            float hpRatio = 0f;
            int memberCount = 0;
            for (int i = 0; i < m_members.Count; i++)
            {
                Member each = m_members[i];
                if (each.Actor == null)
                    continue;

                hpRatio += each.Actor.HpRatio;
                memberCount++;                
            }

            if (hpRatio <= 0f)
                return 0f;
            return hpRatio / memberCount;
        }
    }
}