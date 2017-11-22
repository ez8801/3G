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

        //서버에서 이 유저의 캐릭터를 찾아서 카메라를 따라다니게 해줘야함.
        GameObject Player = GameObject.FindGameObjectWithTag("Player");

        Camera mainCamera = Camera.main;
        CharacterFollow follower
            = Util.RequireComponent<CharacterFollow>(mainCamera.gameObject);



        follower.target = Player.transform;

    }

    public override void Initialize()
    {
        base.Initialize();
        // PassiveManager it = GameObject.Find("PassiveManager").GetComponent<PassiveManager>();
        m_characterData = CharacterTable.Instance.Find(m_entityID.Id);
        //m_statsData = StatsTable.Instance.Find(m_characterData.StatsId);

        StatManager statManager = GameObject.Find("StatManager").GetComponent<StatManager>();

        m_statsData = statManager.CharacterStats;

        m_stats = new Stats();
        m_stats.Initialize(m_statsData);


        CurrentHp = m_stats.Hp;
        
    }

    public void ImEnemy(Data.Stats statData, int groupId)
    {
        //이 캐릭터가 상대 캐릭터일 경우 이 함수를 호출하며 스탯 데이터를 적용 시킴. StatManager의 FinalStatsToS함수를 통해 얻은 스탯 최종값을 교환하여 적용.
        m_stats.Initialize(statData);
        this.SetGroupId(groupId);
    }

    public void ReloadStat()
    {
        //서버 : 지금은 싱글톤의 스탯 매니저가 관리중이지만 서버에서 스킬쓸때, 패시브 쓸때마다 그 정보 가지게 되면 서버가 이 역할.
        // 서버에 버프 걸렸다는 정보를 준다면 그 값을 받아와서 캐릭터 스탯에 적용.
        //현 상황 : 버프가 걸리면 스탯 매니저의 스탯값을 조정해 준 후 현 함수인 ReloadStat()을 호출하여 캐릭터 스탯과 동기화 해줌.
        //기대 : 버프가 걸리면 더해질 스탯값(종료 후 빼질 스탯값)을 서버에 전송 후 합산된 스탯을 전송받아 캐릭터 스탯과 동기화.
        StatManager statManager = GameObject.Find("StatManager").GetComponent<StatManager>();
        m_statsData = statManager.CharacterStats;

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

    public void StartIncreaseAttackBuff(int buffValue)
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
            StartCoroutine(attackCorutine);
        }
    }

    IEnumerator IncreaseAttackDamage(int increaseValue)
    {
        //this.Stats.AttackDamageValue(increaseValue);
        StatManager statManager = GameObject.Find("StatManager").GetComponent<StatManager>();
        StatManager.Instance.WeaponAttackStat = StatManager.Instance.WeaponAttackStat + increaseValue;
        ReloadStat();

        yield return new WaitForSeconds(4.0f);
        StatManager.Instance.WeaponAttackStat = StatManager.Instance.WeaponAttackStat - increaseValue;
        ReloadStat();
        //this.Stats.AttackDamageValue(-increaseValue);
        AttackBuffOn = false;
    }

    public void StartIncreaseArmorBuff(int buffValue)
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

    IEnumerator IncreaseArmor(int increaseValue)
    {
        this.Stats.ArmorValue(increaseValue);
        StatManager statManager = GameObject.Find("StatManager").GetComponent<StatManager>();
        StatManager.Instance.WeaponAttackStat = StatManager.Instance.FinalArmorEquipStat + increaseValue;
        ReloadStat();
        yield return new WaitForSeconds(5.0f);
        StatManager.Instance.WeaponAttackStat = StatManager.Instance.FinalArmorEquipStat - increaseValue;
        ReloadStat();
        this.Stats.ArmorValue(-increaseValue);

        ArmorBuffOn = false;
    }
}
