/* 
 * NuClearEffect.cs
 * 
 * Writer : user
 * Date   : 2017-11-19
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class EnemyNuclear : MonoBehaviour
{
    // Use this for initialization
    float radius = 3.0f;
    public long ThisGroupID;
    public int Damage;
    void Start()
    {
        Destroy(this.gameObject, 0.8f);
        GetInfo();
        //private void OnCollisionEnter2D(Collision2D other)
        Collider2D[] colliders = Physics2D.OverlapCircleAll(transform.position, radius);
        foreach (Collider2D col in colliders)
        {
            Debug.Log(col.name);
            Actor hitter = col.gameObject.GetComponent<Actor>();
            if (hitter != null)
            {
                Debug.Log("널은 아님");
                if (hitter.GroupId == ThisGroupID)
                {
                    Debug.Log("그룹아이디 같아");
                    hitter.ApplyDamage(Damage);

                    if (hitter.CurrentHp <= 0)
                    {
                        hitter.OnDead();
                    }

                    Vector3 opposite = hitter.Forward;
                    opposite.x *= -4.0f * Random.Range(0.5f, 1.0f);
                    opposite.y += 1f;
                    opposite.y *= 4f * Random.Range(0.5f, 1.5f);
                    hitter.GetComponent<Rigidbody2D>().AddForce(opposite, ForceMode2D.Impulse);
                    hitter.GetDamageAction();
                }
            }
        }


    }

    public void SetGroupId(long id)
    {
        ThisGroupID = id;
    }

    public void GetInfo()
    {
        ThisGroupID = GameObject.Find("StatManager").GetComponent<StatManager>().GroupId;
        //서버에서 발사한 놈의(이하 공격자) 현 공격력을 가져옴.
        //지금은 스탯매니저에서 가져옴.
        StatManager statManager = GameObject.Find("StatManager").GetComponent<StatManager>();
        Damage = (int)(statManager.CharacterStats.AttackDamage * 3 * Random.Range(0.9f, 1.1f));
    }
}