/* 
 * RecipeTable.cs
 * 
 * Writer : EZ
 * Date   : 2017-07-16
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System;

namespace Data
{
    [Serializable]
    [PrimaryKey("Id")]
    public partial struct Recipe
    {
        public enum Kind : short
        {
            NONE = 0,
            MAKING = 1,
            DECOMPOSE = 2,
            CONVERT = 3
        }

        /// <summary>
        /// 인덱스
        /// </summary>
        public int Id;

        /// <summary>
        /// 레시피 이름
        /// </summary>
        [DeclaringType("string", "int")]
        public int Name;
        
        /// <summary>
        /// 레시피 종류
        /// * 1: 제작, 2: 분해, 3: 변환
        /// </summary>
        public short RecipeKind;
        
        /// <summary>
        /// 재료 그룹 Id
        /// </summary>
        /// <seealso cref="Material.Group"/>
        public int MaterialGroupId;
        
        /// <summary>
        /// 완제품 인덱스
        /// </summary>
        /// <seealso cref="Item.Id"/>
        public int ResultItemId;

        /// <summary>
        /// 제작 비용 (골드)
        /// </summary>
        public int CostGold;
    }
}

/// <summary>
/// 레시피 테이블
/// 이 클래스는 상속할 수 없습니다.
/// </summary>
public sealed class RecipeTable : ArrayTable<Data.Recipe>
{
    private static RecipeTable m_instance;
    public static RecipeTable Instance
    {
        get
        {
            if (m_instance == null)
                m_instance = new RecipeTable();
            return m_instance;
        }
    }
}