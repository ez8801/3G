/* 
 * ProjectileBase.cs
 * 
 * Writer : user
 * Date   : 2017-07-15
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class ProjectileBase : MonoBehaviour
{
    private float m_projectileSpeed;
    public float ProjectileSpeed
    {
        get
        {
            return m_projectileSpeed;
        }
        set
        {
            m_projectileSpeed = value;
        }
    }

    private GameObject m_effect;
    public GameObject ProjectileEffect
    {
        get
        {
            return m_effect;
        }
        set
        {
            m_effect = value;
        }
    }

    public void Initilize()
    {

    }

    private void OnTriggerEnter2D(Collider2D other)
    {
        Character me = gameObject.GetComponent<Character>();
        long myId = me.GetGroupId();

        Monster monster;
        long otherId;
        monster = other.GetComponentInParent<Monster>();
        otherId = monster.GetGroupId();
        if(otherId != myId)
        {
            //데미지를 줍니다. -> Actor에 충돌 체크 부분을 수정하거나 스킬, 공격마다 따로 데미지를 줄 필요가 있어보임
            //이펙트를 생성시킨 후 자신을 지웁니다.
            Destroy(this.gameObject);
            Instantiate(m_effect, this.transform.position, Quaternion.identity);
        }
    }

    private void Update()
    {
        float moveX = m_projectileSpeed * Time.deltaTime;

        transform.Translate(0, moveX, 0);

    }


}