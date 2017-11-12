using UnityEngine;
using System.Collections;
using System.Collections.Generic;


public class IncreaseAttackBuff : SkillBase 
{
    private GameObject target;

    private Character character;

    private string m_myTeamName;

    public float power = 1;

    private float m_radius;
    public float Radius
    {
        get
        {
            return m_radius;
        }
        set
        {
            m_radius = value;
        }
    }

    //범위 내 아군 식별
    public void BuffCheck()
    {
        Character myCharacter = gameObject.GetComponent<Character>();
        Character me = gameObject.GetComponent<Character>();
        long myId = me.GetGroupId();
        int i = 0;
        int myAtt = me.Stats.AttackDamage;
        long teamId;
        Collider2D[] coll = Physics2D.OverlapCircleAll(transform.position, Radius);

        while (coll[i] != null)
        {
            target = coll[i].gameObject;
            character = target.GetComponent<Character>();
            teamId = character.GetGroupId();

            if (teamId == myId)
            {
                character.StartIncreaseAttackBuff((int)(myAtt*3 - power));
            }
            i++;
        }
    }
}