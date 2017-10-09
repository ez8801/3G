/* 
 * ItemCategory.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-16
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

public enum ItemCategory
{
    None,
    Goods,
    Material,
    Misc,
    Weapon = 10,
    Armor = 11,
    Active = 12,
    Max
}

public enum ItemType
{
    None,
    Exp,
    Gold,
    Jewel = 10,
    Ingot = 11,
    Leather = 12,
    BluePrint = 100,
    Sword = 1000,
    Armor = 2000,
    ActiveStone = 3000,
    Max
}

public enum ItemRarity
{
    None,
    Normal,
    Magic,
    Rare,
    Unique,
    Max
}

public struct ItemSlot
{
    public const int None = 0;
    public const int MainEquipment = 1;
    public const int SubEquipment = 2;
    public const int Armor = 3;
    public const int Max = 4;
}