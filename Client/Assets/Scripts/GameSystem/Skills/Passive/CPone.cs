/* 
 * CPone.cs
 * 
 * Writer : user
 * Date   : 2017-08-20
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class CPone : PassiveBase 
{
    public override void ApplyPassive()
    {
        base.ApplyPassive();
        StatManager.Instance.CommonPassiveAttackStat += 3;
    }

    public override void ReleasePassive()
    {
        base.ReleasePassive();
        StatManager.Instance.CommonPassiveAttackStat += -3;
    }

}