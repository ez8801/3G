/* 
 * ActiveSkillBlueWave.cs
 * 
 * Writer : user
 * Date   : 2017-11-12
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class ActiveSkillBlueShot : MonoBehaviour
{
    private const float moveSpeed = 10f;
    public GameObject ParticleBlueExplose;
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
        float moveX = moveSpeed * Time.deltaTime;

        transform.Translate(moveX, 0, 0);

        if((transform.position.x - startPosition) >= 30f) Destroy(this.gameObject);
    }

    public void GetInfo()
    {
        //서버에서 발사한 놈의 그룹 아이디를 가져옴.
        //지금은 임의 그룹아이디 제공.
        m_groupID = GameObject.Find("StatManager").GetComponent<StatManager>().GroupId;

        //서버에서 발사한 놈의(이하 공격자) 현 공격력을 가져옴.
        //지금은 스탯매니저에서 가져옴.
        StatManager statManager = GameObject.Find("StatManager").GetComponent<StatManager>();
        m_damage = statManager.CharacterStats.AttackDamage;

    }

    private void OnTriggerEnter2D(Collider2D other)
    {

        //그룹 아이디로 구별
        //서버에서 처리 안한다 했기 때문. 이러면 클라에서 서버로 피격판정만보내면 댐. 생성시 인포만 받음.

        Actor hitter = other.gameObject.GetComponent<Actor>();

        if (hitter != null)
            Debug.Log(hitter.name + "is hit");

        AttackObject attackObject = null;
        if(hitter == null)
        {
            attackObject = other.gameObject.GetComponent<AttackObject>();
            if (attackObject == null)
                return;

            hitter = attackObject.Actor;
            attackObject.OnHit(gameObject);
        }

        if(hitter != null && hitter.GroupId != m_groupID)
        {
            int realDamage = (int)((m_damage - hitter.Stats.Armor) * Random.Range(0.9f, 1.1f));
            if (realDamage <= 1) realDamage = 1;



            if (realDamage > 0)
            {

                Debug.Log(Macros.__PRETTY_FUNCTION__ + " : " + realDamage);
                hitter.ApplyDamage(realDamage);

                Destroy(this.gameObject);

                Vector3 point = transform.position;
                point.x = transform.position.x + 1;
                Instantiate(ParticleBlueExplose, point, Quaternion.identity);
            }


        }
    }
}