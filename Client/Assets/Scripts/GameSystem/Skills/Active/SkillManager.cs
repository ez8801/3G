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
    public long GroupID;
    public GameObject BlueShotPrefab;
    public GameObject MeteorPrefab;
    public Vector3 side;

    public void SetGroupID(long id)
    {
        GroupID = id;
    }

    public long GetGroupID()
    {
        return GroupID;
    }

    public void GetSkill(int skillId)
    {
        side = gameObject.GetComponent<Character>().Forward;
        Debug.Log("This is Manager");
        switch (skillId)
        {
            case 3000001:
                StartCoroutine("SkillBlueShot");
                break;
            case 3000002:
                StartCoroutine("SkillBlueWave");
                break;
            case 3000003:
                StartCoroutine("SkillMeteor");
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
        Vector3 summonPoint = transform.position;
        summonPoint.x += side.x;
        Instantiate(BlueShotPrefab, summonPoint, Quaternion.identity);
        yield break;
    }
    IEnumerator SkillMeteor()
    {
        Debug.Log("Use Meteor from SkillManager");
        Vector3 summonPoint = transform.position;
        summonPoint.y = transform.position.y + 12;
        summonPoint.x = transform.position.x + -(6 * side.x);
        Instantiate(MeteorPrefab, summonPoint, Quaternion.identity);
        yield break;
    }

}