/* 
 * SkillManager.cs
 * 
 * Writer : user
 * Date   : 2017-11-15
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class SkillManager : MonoBehaviour
{
    public GameObject BlueShotPrefab;

    public void GetSkill(int skillId)
    {
        Debug.Log("This is Manager");
        switch (skillId)
        {
            case 13:
                StartCoroutine("SkillBlueWave");
                break;
            case 3000002:
                StartCoroutine("SkillBlueShot");
                break;
        }
    }
    IEnumerator SkillBlueWave()
    {
        Debug.Log("Use BlueWave from SkillManager");
        yield break;
    }

    IEnumerator SkillBlueShot()
    {
        Debug.Log("Use BlueShot from SkillManager");
        Instantiate(BlueShotPrefab, transform.position, Quaternion.identity);
        yield break;
    }

}