/* 
 * BlueExplose.cs
 * 
 * Writer : user
 * Date   : 2017-11-15
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;

public class BlueExplose : MonoBehaviour 
{
    // Use this for initialization
    float radius = 2.0f;
    public long ThisGroupID;
    public int Damage;
    void Start()
	{
        Destroy(this.gameObject, 0.5f);
        GetInfo();
        Collider2D[] colliders = Physics2D.OverlapCircleAll(transform.position, radius);
        foreach (Collider2D col in colliders)
        {
            Debug.Log(col.name);
            Actor hitter = col.gameObject.GetComponent<Actor>();
            Debug.Log(col.name);
            if (hitter != null)
            {
                if (hitter.GroupId != ThisGroupID)
                {
                    hitter.ApplyDamage(Damage);

                    if(hitter.CurrentHp <= 0)
                    {
                        hitter.OnDead();
                    }
                    
                    Vector3 opposite = hitter.Forward;
                    opposite.x *= -2f * Random.Range(0.5f, 1.0f);
                    opposite.y += 1f;
                    opposite.y *= 3f * Random.Range(0.5f, 1.5f);
                    hitter.GetComponent<Rigidbody2D>().AddForce(opposite, ForceMode2D.Impulse);
                    hitter.GetDamageAction();
                }
            }
        }
        
        
	}

    public void GetInfo()
    {
        //서버에서 발사한 놈의 그룹 아이디를 가져옴.
        //지금은 임의 그룹아이디 제공.
        ThisGroupID = 1;

        //서버에서 발사한 놈의(이하 공격자) 현 공격력을 가져옴.
        //지금은 스탯매니저에서 가져옴.
        StatManager statManager = GameObject.Find("StatManager").GetComponent<StatManager>();
        Damage = (int)(statManager.CharacterStats.AttackDamage*Random.Range(0.9f, 1.1f));
    }
    
	
}