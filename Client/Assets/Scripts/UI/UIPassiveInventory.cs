/* 
 * UIPassiveInventory.cs
 * 
 * Writer : user
 * Date   : 2017-08-07
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public class UIPassiveInventory : UIBase
{
    [System.Serializable]
    public struct View
    {
        public UILabel LblName;
        public Transform GridEquip;
        public UIEventListener BtnClose;
    }


}