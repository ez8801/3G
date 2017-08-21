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
        MyInfo.PassiveInventory.AddPassive(2, 2);
        MyInfo.Inventory.AddStackAbleItem(10001, 12);
    }
	
    public void ApplyPassive(Data.PassiveSkill apply)
    {
        switch (apply.Id)
        {
            case 1: ApplyOne();
                break;
            case 2: ApplyTwo();
                break;
        }
    }

    public void ReleasePassive(Data.PassiveSkill release)
    {
        switch (release.Id)
        {
            case 1:
                ReleaseOne();
                break;
            case 2:
                ReleaseTwo();
                break;
        }
    }

    private void ApplyOne()
    {
        StatManager.Instance.CommonPassiveAttackStat += 5;
        StatManager.Instance.FinalArmorPassiveStat -= 5;
    }
    private void ReleaseOne()
    {
        StatManager.Instance.CommonPassiveAttackStat -= 5;
        StatManager.Instance.FinalArmorPassiveStat += 5;
    }

    private void ApplyTwo()
    {
        StatManager.Instance.CommonPassiveAttackStat -= 2;
        StatManager.Instance.FinalArmorPassiveStat += 3;
    }
    private void ReleaseTwo()
    {
        StatManager.Instance.CommonPassiveAttackStat += 2;
        StatManager.Instance.FinalArmorPassiveStat -= 3;
    }
}