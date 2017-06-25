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
    public static Team AddTeam(int id, string name)
    {
        GameObject go = new GameObject(name);
        Team team = go.AddComponent<Team>();
        team.Initialize(EntityType.Team, id);
        return team;
    }

    /// <summary>
    /// 팀원을 정의하는 클래스
    /// </summary>
    public class Member
    {
        public long TeamId;
        public int Id;
        public string Name;
        public Actor Actor;
    }

    public long Id;
    public string Name;

    /// <summary>
    /// 해당 팀에 소속된 멤버 목록
    /// </summary>
    private List<Member> m_members = new List<Member>();
    
    public void SetTeamName(string teamName)
    {
        Name = teamName;
    }

    public Team(string teamName, long teamId)
    {
        SetTeamName(teamName);
        Id = teamId;
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
        Member newMember = new Member();
        newMember.TeamId = Id;
        newMember.Id = m_members.Count;
        newMember.Name = string.Empty;
        newMember.Actor = actor;
        
        m_members.Add(newMember);
    }
}