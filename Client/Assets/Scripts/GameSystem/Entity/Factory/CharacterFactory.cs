/* 
 * CharacterFactory.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

public static class CharacterFactory 
{
    public static int uid = 0;

	public static EntityBase CreateEntity(string name)
    {
        GameObject prefab = Resources.Load(name) as GameObject;
        Assert.IsNotNull(prefab, "CharacterFactory::CreateEntity(string)");

        GameObject newOne = Object.Instantiate(prefab) as GameObject;
        Assert.IsNotNull(newOne, "CharacterFactory::CreateEntity(string)");

        EntityBase entity = Util.RequireComponent<EntityBase>(newOne);
        ++uid;
        return entity;
    }
}