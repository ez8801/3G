/* 
 * GoodsMonitor.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-17
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

public struct GoodsInfo
{
    public int Gold;
}

/// <summary>
/// 아이템 획득/소모 장부
/// </summary>
public class GoodsMonitor : ObserverBase<GoodsInfo>
{
    private GoodsInfo m_goodsInfo;

    public GoodsMonitor()
    {
        m_goodsInfo = new GoodsInfo();
    }
    
    public void OnGoldChanged(int gold)
    {
        m_goodsInfo.Gold = gold;
        Post(m_goodsInfo);
    }
}