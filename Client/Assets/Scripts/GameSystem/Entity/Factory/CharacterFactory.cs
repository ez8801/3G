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
    public static long guid = 0;

	public static EntityBase CreateEntity(string name)
    {
        GameObject prefab = Resources.Load(name) as GameObject;
        Assert.IsNotNull(prefab, "CharacterFactory::CreateEntity(string)");

        GameObject newOne = Object.Instantiate(prefab) as GameObject;
        Assert.IsNotNull(newOne, "CharacterFactory::CreateEntity(string)");

        Actor actor = Util.RequireComponent<Actor>(newOne);
        actor.Initialize(EntityType.Character, ++guid);
        return actor;
    }
}