/* 
 * TableLoader.cs
 * 
 * Writer : BMW
 * Date   : 2017-06-03
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;

public class TableLoader : AssetLoader
{
    private string m_tableName;
    private TextAsset m_textAsset;

    public TableLoader(string tableName)
    {
        m_tableName = tableName;
        m_textAsset = null;
    }

    public override bool IsValid()
    {
        return true;
        // return !AssetBundleHandler.Instance.IsLoadedTable(m_tableName);
    }

    public override IEnumerator Load()
    {
#if UNITY_EDITOR
        m_textAsset = Resources.Load<TextAsset>(string.Concat("Data/TABLE_DATA_", m_tableName));
#else
		// yield return AssetBundleHandler.Instance.ResourceLoad<TextAsset>("data.assetbundle", m_tableName);
#endif

        yield return null;
    }

    public override void OnPostLoad()
    {
        base.OnPostLoad();

        // m_textAsset = AssetBundleHandler.Instance.GetAsset<TextAsset>(m_tableName);
        // DataManager.Instance.DataLoad(m_textAsset, m_tableName);
        // AssetBundleHandler.Instance.AddLoadedTable(m_tableName);
    }
}