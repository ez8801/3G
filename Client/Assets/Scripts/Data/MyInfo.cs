/* 
 * MyInfo.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-22
 * 
 * Copyright ⓒ SHAprojectVer001. DefaultCompany, All rights reserved
 */

 public class AccountInfo
{
    public long Id;
    public string NickName;
    public int Gold;
}

public class MyInfo
{
    private static MyInfo m_instance;
    public static MyInfo Instance
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
}