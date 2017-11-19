/* 
 * ActiveSkillMeteorStrike.cs
 * 
 * Writer : user
 * Date   : 2017-11-19
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class ActiveSkillMeteorStrike : MonoBehaviour 
{
    private const float moveSpeed = 3f;
    public GameObject ParticleNuclear;
    private long m_groupID;
    private int m_damage;
    public int startPosition;

    private void Start()
    {
        GetInfo();
        startPosition = (int)transform.position.x;
    }

    private void Update()
    {
        float moveX = moveSpeed * Time.deltaTime * 2.2f;
        float moveY = moveSpeed * Time.deltaTime * -3;

        transform.Translate(moveX, moveY, 0);

        if(transform.position.y <= -1)
        {
            Destroy(this.gameObject);

            Vector3 point = transform.position;
            point.x = point.x - 1;
            Instantiate(ParticleNuclear, point, Quaternion.identity);
        }
    }


    public void GetInfo()
    {
        m_groupID = 1;

        StatManager statManager = GameObject.Find("StatManager").GetComponent<StatManager>();
        m_damage = statManager.CharacterStats.AttackDamage;
    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        Actor hitter = other.gameObject.GetComponent<Actor>();

        if (hitter != null) Debug.Log(hitter.name + "is hit meteor");

        AttackObject attackObject = null;
        if(hitter == null)
        {
            attackObject = other.gameObject.GetComponent<AttackObject>();
            if (attackObject == null) return;

            hitter = attackObject.Actor;
            attackObject.OnHit(gameObject);
        }

        if(hitter != null && hitter.GroupId != m_groupID)
        {
            int realDamage = (int)((m_damage - hitter.Stats.Armor) * Random.Range(0.9f, 1.1f));
            if (realDamage <= 1) realDamage = 1;

            if(realDamage > 0)
            {
                Debug.Log(Macros.__PRETTY_FUNCTION__ + " : " + realDamage);
                hitter.ApplyDamage(realDamage);
            }
        }

    }

}