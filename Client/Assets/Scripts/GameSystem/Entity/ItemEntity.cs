/* 
 * DropItem.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-06
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;

public class ItemEntity : EntityBase
{
    private const float Radius = 0.6f;

    private bool m_wasGrounded;
    private bool m_wasTrigger;
    private bool m_isStartChasing;

    private int m_itemId;
    private int m_itemCount;
    
    private Transform m_target;
    private BoxCollider2D m_collider;
    private SpriteRenderer m_spriteRenderer;
    private Rigidbody2D m_rigidbody2D;

    private Vector3 m_forward = Vector3.zero;


    public override void Initialize()
    {
        base.Initialize();
        SetEntityId(EntityType.Item, CharacterFactory.uid);

        m_wasGrounded = false;
        m_wasTrigger = false;
        m_isStartChasing = false;

        m_spriteRenderer = GetComponent<SpriteRenderer>();
        m_collider = GetComponent<BoxCollider2D>();
        m_rigidbody2D = GetComponent<Rigidbody2D>();

        m_collider.SetEnableSafely(false);
    }

    public void InitWithData(int itemId, int itemCount)
    {
        Initialize();

        m_itemId = itemId;
        m_itemCount = itemCount;

        Data.Item itemData = ItemTable.Instance.Find(itemId);
        if (!string.IsNullOrEmpty(itemData.Texture) && m_spriteRenderer != null)
        {
            m_spriteRenderer.sprite = Resources.Load<Sprite>(itemData.Texture);
        }

        AddForce();
    }
    
    public void SetTarget(Transform target)
    {
        m_target = target;
    }

    public void AddForce()
    {
        Vector2 force = (Random.Range(0, 2) == 0) ? Vector2.left : Vector2.right;
        force.x *= Random.Range(1f, 4f);
        force.y = Random.Range(3f, 6f);

        m_rigidbody2D.AddForce(force, ForceMode2D.Impulse);
    }

    protected override void Update()
    {
        base.Update();
        if (HasTarget() == false)
            return;

        bool isGrounded = IsGrounded();
        if (isGrounded && !m_wasGrounded)
        {
            StartCoroutine(WaitForDelay());   
        }
        m_wasGrounded = isGrounded;
        
        if (m_isStartChasing)
        {
            FollowTarget();

            bool isTriggerEnter = IsTriggerEnter();
            if (isTriggerEnter && !m_wasTrigger)
            {
                MyInfo.Inventory.AddItem(m_itemId, m_itemCount);
                GameObjectPool.Instance.Release(gameObject);
            }
            m_wasTrigger = isTriggerEnter;
        }
    }

    private IEnumerator WaitForDelay()
    {
        yield return new WaitForSeconds(Random.Range(0.4f, 0.8f));
        m_isStartChasing = true;
    }

    public bool IsGrounded()
    {
        bool isGrounded = Physics2D.Raycast(new Vector2(transform.position.x, transform.position.y)
            , Vector2.down, 0.2f, LayerMask.GetMask("Ground"));
        if (isGrounded)
        {
            m_rigidbody2D.velocity = Vector2.zero;
        }

        return isGrounded;
    }

#if UNITY_EDITOR

    private void OnGUI()
    {
        Debug.DrawRay(transform.position, Vector3.down * 0.2f);
        Debug.DrawRay(transform.position, m_forward, Color.red);
    }
    
#endif

    private bool HasTarget()
    {
        return (m_target != null);
    }

    private void FollowTarget()
    {
        m_forward = transform.Direction(m_target.position);
        transform.position += m_forward * Time.deltaTime * 10f;
    }

    private bool IsTriggerEnter()
    {
        float distance = Vector3.Distance(m_target.position, transform.position);
        return (distance < Radius);
    }
}