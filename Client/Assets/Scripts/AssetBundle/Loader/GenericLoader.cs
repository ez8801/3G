/* 
 * GenericLoader.cs
 * 
 * Writer : BMW
 * Date   : 2017-06-03
 * 
 * Copyright ⓒ Util. DefaultCompany, All rights reserved
 */

using UnityEngine;
using System.Collections;

public class GenericLoader<T> : AssetLoader where T : Object
{
    private string m_assetName;
    private string m_assetBundleName;

    public GenericLoader(string assetName, string assetBundleName)
    {
        m_assetName = assetName;
        m_assetBundleName = assetBundleName;
    }

    public override bool IsValid()
    {
        return false;
        // return !AssetBundleHandler.Instance.IsLoadedObject(m_assetName);
    }

    public override IEnumerator Load()
    {
        yield return null;
        // yield return AssetBundleHandler.Instance.ResourceLoad<T>(m_assetBundleName, m_assetName);
    }

    public override void OnPostLoad()
    {
        base.OnPostLoad();
    }
}