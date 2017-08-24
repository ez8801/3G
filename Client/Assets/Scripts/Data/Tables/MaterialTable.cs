/* 
 * MaterialTable.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-16
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System;
using System.Collections.Generic;

namespace Data
{
    /// <summary>
    /// 재료 정보
    /// </summary>
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct Material
    {
        /// <summary>
        /// 인덱스
        /// </summary>
        public int Id;

        /// <summary>
        /// 재료 그룹번호
        /// </summary>
        public int Group;

        /// <summary>
        /// 재료명
        /// </summary>
        [DeclaringType("string", "int")]
        public int Name;
        
        /// <summary>
        /// 아이템 재료 그룹
        /// </summary>
        public int ItemMaterialGroup;

        /// <summary>
        /// 아이템 개수 (요구)
        /// </summary>
        public int RequestCount;
    }
}

/// <summary>
/// 재료 테이블
/// 이 클래스는 상속할 수 없습니다.
/// </summary>
public sealed class MaterialTable : ArrayTable<Data.Material>
{
    private static MaterialTable m_instance;
    public static MaterialTable Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new MaterialTable();
            return m_instance;
        }
    }

    /// <summary>
    /// 지정된 그룹에 해당하는 재료 목록을 반환합니다.
    /// </summary>
    public List<Data.Material> GetMaterials(int group)
    {
        List<Data.Material> materials = new List<Data.Material>();
        for (int i = 0; i < Length; i++)
        {
            Data.Material match = this[i];
            if (match.Group == group)
            {
                materials.Add(match);
            }
        }
        return materials;
    }
}