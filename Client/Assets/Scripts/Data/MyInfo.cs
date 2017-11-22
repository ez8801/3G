/* 
 * MyInfo.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-22
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;

public class AccountInfo
{
    public long Id;
    private int m_level;
    public int Level
    {
        get
        {
            return m_level;
        }
        set
        {
            m_level = Mathf.Clamp(value, 0, R.Integer.GetInteger("MaxPlayerLevel"));
        }
    }
    public string NickName;
    public Nettention.Proud.HostID LocalHost;
    public bool amIHost = true;
    private int m_gold;
    public int Gold
    {
        get
        {
            return m_gold;
        }
        set
        {
            m_gold = Mathf.Clamp(value, 0, R.Integer.GetInteger("MaxGold"));
            NotificationCenter.GoodsMonitor.OnGoldChanged(m_gold);
        }
    }
    public int Exp;
}

public class MyInfo
{
    private static MyInfo m_instance;
    private static MyInfo Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new MyInfo();
            return m_instance;
        }
    }

    private AccountInfo m_accountInfo = new AccountInfo();
    public static AccountInfo Account
    {
        get
        {
            return Instance.m_accountInfo;
        }
    }

    private Inventory m_inventory = new Inventory();
    public static Inventory Inventory
    {
        get
        {
            return Instance.m_inventory;
        }
    }

    private PassiveInventory m_passiveInventory = new PassiveInventory();
    public static PassiveInventory PassiveInventory
    {
        get
        {
            return Instance.m_passiveInventory;
        }
    }
}