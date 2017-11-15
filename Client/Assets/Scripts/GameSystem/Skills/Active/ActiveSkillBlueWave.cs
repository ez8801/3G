/* 
 * ActiveSkillBlueWave.cs
 * 
 * Writer : user
 * Date   : 2017-11-12
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class ActiveSkillBlueWave : MonoBehaviour 
{
    private const float moveSpeed = 15f;

    private void Update()
    {
        float moveX = moveSpeed * Time.deltaTime;

        transform.Translate(moveX, 0, 0);
    }
}