/* 
 * PassiveManager.cs
 * 
 * Writer : user
 * Date   : 2017-08-18
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class PassiveManager : MonoSingleton<PassiveManager> 
{
    public void Initialize()
    {
        MyInfo.PassiveInventory.AddPassive(1, 1);
        MyInfo.PassiveInventory.AddPassive(101, 2);
        MyInfo.PassiveInventory.AddPassive(2, 3);
        MyInfo.PassiveInventory.AddPassive(3, 2);
        MyInfo.Inventory.AddStackAbleItem(10001, 12);
    }
	
    public void ApplyPassive(Data.PassiveSkill apply)
    {
        switch (apply.Id)
        {
            case 1: ApplyO();
                break;
            case 101: ApplyOZO();
                break;
            case 2: ApplyT();
                break;
            case 3: ApplyTh();
                break;
        }
    }

    public void ReleasePassive(Data.PassiveSkill release)
    {
        switch (release.Id)
        {
            case 1:
                ReleaseO();
                break;
            case 101:
                ReleaseOZO();
                break;
            case 2:
                ReleaseT();
                break;
            case 3:
                ReleaseTh();
                break;

        }
    }

    private void ApplyO()
    {
        StatManager.Instance.CommonPassiveAttackStat += 15;
        StatManager.Instance.FinalArmorPassiveStat -= 10;
    }
    private void ReleaseO()
    {
        StatManager.Instance.CommonPassiveAttackStat -= 15;
        StatManager.Instance.FinalArmorPassiveStat += 10;
    }

    private void ApplyOZO()
    {
        StatManager.Instance.CommonPassiveAttackStat -= 10;
        StatManager.Instance.FinalArmorPassiveStat += 20;
    }
    private void ReleaseOZO()
    {
        StatManager.Instance.CommonPassiveAttackStat += 10;
        StatManager.Instance.FinalArmorPassiveStat -= 20;
    }
    private void ApplyT()
    {
        StatManager.Instance.FinalAttackPassivePercent += 30;
        StatManager.Instance.FinalArmorPassivePercent -= 50;
    }
    private void ReleaseT()
    {
        StatManager.Instance.FinalAttackPassivePercent -= 30;
        StatManager.Instance.FinalArmorPassivePercent += 50;
    }
    private void ApplyTh()
    {
        StatManager.Instance.FinalHpPassiveStat += 100;
    }
    private void ReleaseTh()
    {
        StatManager.Instance.FinalHpPassiveStat -= 100;
    }
}