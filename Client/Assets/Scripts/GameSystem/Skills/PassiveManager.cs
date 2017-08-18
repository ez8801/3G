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
	
	void Update()
	{
		
	}
}