using UnityEngine;
using System.Collections;
using System.Collections.Generic;


public class BuffSkillBase : MonoBehaviour 
{
    private GameObject target;

    Character character;

    private string m_myTeamName;

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
        Team myteam = gameObject.GetComponent<Team>();
 //       m_myTeamName = myteam.GroupId;
        int i = 0;
        Collider2D[] coll = Physics2D.OverlapCircleAll(transform.position, Radius);
        while(coll[i] != null)
        {
            if(coll[i].transform.tag == m_myTeamName)
            {
                target = coll[i].gameObject;
                character = target.GetComponent<Character>();
             //character.CurrentHp += myCharacter.Stats.AttackDamage * 버프 비율 << 이런식으로
                //아군 식별 후 stat변화를 줌
                //스킬 아이디로 버프에 관한 설정을 받아와서 만들면 정형화 해야할 수치가 너무 많아질 것으로 예상
                //엑티브 스킬과 동일하게 버프 이펙트와 각 버프 마다의 스크립트를 생성하는것이 좋을듯..
            }
            i++;
        }
    }
    


}