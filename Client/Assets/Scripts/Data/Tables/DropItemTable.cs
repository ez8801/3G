/* 
 * DropItemTable.cs
 * 
 * Writer : bmw122
 * Date   : 2017-07-03
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */
 
using Data;

namespace Data
{

    public struct DropItem
    {
        public int Id;
        public int Group;
        public int ItemId;
        public int MinCount;
        public int MaxCount;
        public int Prob;
    }
}

/// <summary>
/// 아이템 드랍 테이블
/// 이 클래스는 상속할 수 없습니다.
/// </summary>
public sealed class DropItemTable 
{
    
}