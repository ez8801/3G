using UnityEngine;

/// <summary>
/// 공격과 관련된 정보를 담는 오브젝트
/// </summary>
public class AttackObject : MonoBehaviour
{
    private Actor m_actor;
    public Actor Actor
    {
        get
        {
            return m_actor;
        }
    }

    private float m_attackDamage;
    public float AttackDamage
    {
        get
        {
            return m_attackDamage;
        }
    }

    public delegate void CollisionDelegate(GameObject target);
    private CollisionDelegate m_onHitEnter;
    
    protected void Initialize(Actor actor, float AttackDamage)
    {
        m_actor = actor;
        m_attackDamage = AttackDamage;
    }

    public void SetOnCollideListener(CollisionDelegate l)
    {
        m_onHitEnter = l;
    }

    public virtual void OnHit(GameObject target)
    {
        if (m_onHitEnter != null)
            m_onHitEnter(target);

        // @TODO : 사운드/이펙트 출력

    }
}
