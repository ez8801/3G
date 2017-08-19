/* 
 * Character.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;

public class Character : Actor
{
    private Data.Character m_characterData;
    private Data.Stats m_statsData;
    IEnumerator attackCorutine;
    IEnumerator armorCorutine;

    private bool AttackBuffOn = false;
    private bool ArmorBuffOn = false;

    private Stats m_stats;
    public override Stats Stats
    {
        get
        {
            return m_stats;
        }
    }

    protected override void Awake()
    {
        base.Awake();

        Camera mainCamera = Camera.main;
        CharacterFollow follower
            = Util.RequireComponent<CharacterFollow>(mainCamera.gameObject);

        follower.target = transform;


    }

    public override void Initialize()
    {
        base.Initialize();
        // PassiveManager it = GameObject.Find("PassiveManager").GetComponent<PassiveManager>();
        m_characterData = CharacterTable.Instance.Find(m_entityID.Id);
        //m_statsData = StatsTable.Instance.Find(m_characterData.StatsId);

        StatManager m = GameObject.Find("StatManager").GetComponent<StatManager>();

        m_statsData = m.m_characterStats;

        m_stats = new Stats();
        m_stats.Initialize(m_statsData);


        CurrentHp = m_stats.Hp;
    }

    protected override void Update()
    {
        base.Update();
        if (HasTarget())
        {
            if (Target.IsDead)
            {
                Actor newTarget = FindNearestTarget(this) as Actor;
                SetTarget(newTarget);
            }
        }
    }
    public long GetGroupId()
    {
        return GroupId;
    }

    public void StartIncreaseAttackBuff(float buffValue)
    {
        attackCorutine = IncreaseAttackDamage(buffValue);
        if (AttackBuffOn == false)
        {
            AttackBuffOn = true;
            StartCoroutine(attackCorutine);
        }
        else
        {
            StopCoroutine(attackCorutine);
            this.Stats.AttackDamageValue(-buffValue);
            StartCoroutine(attackCorutine);
        }
    }

    IEnumerator IncreaseAttackDamage(float increaseValue)
    {
        this.Stats.AttackDamageValue(increaseValue);
        yield return new WaitForSeconds(10.0f);
        this.Stats.AttackDamageValue(-increaseValue);
        AttackBuffOn = false;
    }

    public void StartIncreaseArmorBuff(float buffValue)
    {
        armorCorutine = IncreaseArmor(buffValue);
        if (ArmorBuffOn == false)
        {
            ArmorBuffOn = true;
            StartCoroutine(armorCorutine);
        }
        else
        {
            StopCoroutine(armorCorutine);
            this.Stats.ArmorValue(-buffValue);
            StartCoroutine(armorCorutine);
        }
    }

    IEnumerator IncreaseArmor(float increaseValue)
    {
        this.Stats.ArmorValue(increaseValue);
        yield return new WaitForSeconds(5.0f);
        this.Stats.ArmorValue(-increaseValue);
        ArmorBuffOn = false;
    }
}
