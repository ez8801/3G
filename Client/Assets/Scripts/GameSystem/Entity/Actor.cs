using UnityEngine;

public class Actor : EntityBase
{
    private StateMachine m_stateMachine;
    public StateMachine StateMachine
    {
        get
        {
            return m_stateMachine;
        }
    }

    public virtual Stats Stats { get { return null; } }

    protected int m_level;
    public int Level
    {
        get
        {
            return m_level;
        }
    }

    protected float m_currentHp;
    public float CurrentHp
    {
        set
        {
            int maxHp = (Stats != null) ? Stats.Hp : 0;
            m_currentHp = (value > maxHp) ? maxHp : value;
        }
        get
        {
            return m_currentHp;
        }
    }

    public float HpRatio
    {
        get
        {
            if (CurrentHp > 0f && Stats != null && Stats.Hp > 0)
            {
                return CurrentHp / Stats.Hp;
            }
            return 0f;
        }
    }

    /// <summary>
    /// 생존 여부
    /// </summary>
    public bool IsAlive
    {
        get
        {
            return (m_currentHp > 0f);
        }
    }

    public bool IsDead
    {
        get
        {
            return (m_currentHp <= 0f);
        }
    }

    /// <summary>
    /// 무적 여부
    /// </summary>
    public bool IsInvincible { get; set; }

    [SerializeField]
    public Actor Target; // { private set; get; }

    public Transform Head;
    public Transform Pelvis;
    public Rigidbody2D CachedRigidbody2D;
    public Vector3 Forward;

    public override void Initialize()
    {
        base.Initialize();

        m_stateMachine = new StateMachine(this);
        m_stateMachine.Transition(StateType.Idle);

        CachedRigidbody2D = GetComponent<Rigidbody2D>();
    }

    public bool HasTarget()
    {
        return Target != null;
    }

    public void SetTarget(Actor target)
    {
        Target = target;
    }

    public void LookAt(Actor target)
    {
        if (CachedTransform.position.x < target.CachedTransform.position.x)
        {
            Forward = new Vector3(1f, 0f, 0f);
        }
        else if (CachedTransform.position.x > target.CachedTransform.position.x)
        {
            Forward = new Vector3(-1f, 0f, 0f);
        }
        else
        {
            Forward = new Vector3(1f, 0f, 0f);
        }
    }

    public bool FindNearestTarget()
    {
        Actor target = FindNearestTarget(this) as Actor;
        if (target != null)
        {
            SetTarget(target);
            LookAt(target);
            return true;
        }

        SetTarget(null);
        return false;
    }

    public Team GetTeam()
    {
        return Team.GetTeam(m_groupId.Id);
    }

    public bool ApplyDamage(float damage)
    {
        Debug.Log(Macros.__PRETTY_FUNCTION__ + " : " + damage);
        bool wasDead = IsDead;
        m_currentHp -= damage;
        bool isDead = IsDead;
        if (wasDead == false && isDead == true)
        {
            m_stateMachine.Transition(StateType.Dead);
        }

        return (isDead);
    }

    protected override void Update()
    {
        base.Update();
        if (m_stateMachine != null)
            m_stateMachine.PerformUpdate();
    }

    /// <summary>
    /// 충돌 판정
    /// </summary>
    private void OnCollisionEnter2D(Collision2D other)
    {
        Actor attacker = other.gameObject.GetComponent<Actor>();
        if (attacker != null)
            Debug.Log(Macros.__PRETTY_FUNCTION__ + ": " + attacker.name);

        AttackObject attackObject = null;
        if (attacker == null)
        {
            attackObject = other.gameObject.GetComponent<AttackObject>();
            if (attackObject == null)
                return;

            attacker = attackObject.Actor;
            attackObject.OnHit(gameObject);
        }

        // 출동된 객체와 다른 팀일 경우
        if (attacker != null && GroupId != attacker.GroupId)
        {
            float prevRatio = HpRatio;

            float damage = (attacker.Stats.AttackDamage - Stats.Armor) * Random.Range(0.9f, 1.1f);
            int damageAmount = Mathf.FloorToInt(damage);
            if (damageAmount <= 0)
                damageAmount = 1;
            
            if (damageAmount > 0)
            {
                VFXManager.Instance.PlayVFX("Prefabs/VFX/Hit", Head.position, Quaternion.identity);
            }

            bool isDead = ApplyDamage(damageAmount);
            if (isDead)
            {
                // 최고 레벨이 아닐 경우에만 경험치 부여
                if (!ConfigTable.Instance.IsMaxLevel(attacker.Level))
                {
                    //int neededXp = GetNeededXp(this.level);
                    //if (neededXp > 0)
                    //{
                    //    int levelGap = this.level - attacker.level;
                    //    float factor = Mathf.Clamp(levelGap * 0.07f, -0.2f, float.MaxValue);
                    //    neededXp = Mathf.FloorToInt(neededXp * (1 + factor) * 0.5f);

                    //    DamageFontManager.Instance.AddXpData(attacker, neededXp);
                    //    attacker.GainXp(neededXp);
                    //}
                }
            }
            else
            {
                m_stateMachine.Transition(StateType.Damaged);
            }

            // DamageFontManager.Instance.AddDamageData(attacker, this, damageAmount);

            float gapRatio = Mathf.Clamp(HpRatio - prevRatio, 1f, 10f);
            Vector3 opposite = attacker.Forward;
            opposite.x *= -gapRatio;
            opposite.y = 10f * 0.5f;

            if (attackObject == null)
                attacker.GetComponent<Rigidbody2D>().AddForce(opposite, ForceMode2D.Impulse);

            SoundManager.Instance.PlaySound(1);
        }
    }
}
