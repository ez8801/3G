/* 
 * MyInfo.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-22
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

public class AccountInfo
{
    public long Id;
    public int Level;
    public string NickName;

    private int m_gold;
    public int Gold
    {
        get
        {
            return m_gold;
        }
        set
        {
            m_gold = value;
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
}