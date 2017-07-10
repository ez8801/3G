/* 
 * UIBattle.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-03
 * 
 * Copyright ⓒ SHAprojectVer001. DefaultCompany, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class UIBattle : UIBase
{
    public UISprite SprMyTeamHp;
    private int m_sprMyTeamHpWidth;

    public UISprite SprEnemyTeamHp;
    private int m_sprEnemyTeamHpWidth;

    private Team m_myTeam;
    public Team MyTeam
    {
        get
        {
            if (m_myTeam == null)
                m_myTeam = Team.GetTeam(Team.kRedTeamId);
            return m_myTeam;
        }
    }
    private float m_myTeamHpRatio;

    private Team m_enemyTeam;
    public Team EnemyTeam
    {
        get
        {
            if (m_enemyTeam == null)
                m_enemyTeam = Team.GetTeam(Team.kBlueTeamId);
            return m_enemyTeam;
        }
    }
    private float m_enemyTeamHpRatio;

    public override void ViewDidLoad()
    {
        base.ViewDidLoad();
        m_sprMyTeamHpWidth = SprMyTeamHp.width;
        m_sprEnemyTeamHpWidth = SprEnemyTeamHp.width;
    }

    public override void ViewDidAppear()
    {
        base.ViewDidAppear();
        NavigationBar.SetActiveSafely(false);
    }

    public void Update()
    {
        //
        if (MyTeam.HpRatio != m_myTeamHpRatio)
        {
            //TweenValue tween = TweenValue.Begin(MyTeam.gameObject, 0.4f, MyTeam.HpRatio);            
            //tween.method = UITweener.Method.EaseOut;
            //tween.SetOnUpdateListener((value, isFinished) =>
            //{
            //    SprMyTeamHp.SetFillAmountSafely(value, m_sprMyTeamHpWidth);
            //});
        }
        m_myTeamHpRatio = MyTeam.HpRatio;

        //
        if (EnemyTeam.HpRatio != m_enemyTeamHpRatio)
        {
            //TweenValue tween = TweenValue.Begin(EnemyTeam.gameObject, 0.4f, EnemyTeam.HpRatio);
            //tween.method = UITweener.Method.EaseOut;
            //tween.SetOnUpdateListener((value, isFinished) =>
            //{
            //    SprEnemyTeamHp.SetFillAmountSafely(value, m_sprEnemyTeamHpWidth);
            //});
        }
        m_enemyTeamHpRatio = EnemyTeam.HpRatio;
    }

    public override void ViewDidDisAppear()
    {
        base.ViewDidDisAppear();
        NavigationBar.SetActiveSafely(true);
    }
}