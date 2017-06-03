/* 
 * AssetLoader.cs
 * 
 * Writer : BMW
 * Date   : 2017-06-03
 * 
 * Copyright ⓒ Util. DefaultCompany, All rights reserved
 */

using UnityEngine;
using System.Collections;

public abstract class AssetLoader 
{
    public virtual bool IsValid()
    {
        return true;
    }

    public virtual void OnPostLoad()
    {
        //
    }

    public abstract IEnumerator Load();

    public static IEnumerator LoadAsset(AssetLoader loader)
    {
        if (loader == null)
        {
            yield break;
        }
        else if (loader.IsValid())
        {
            yield return loader.Load();
            loader.OnPostLoad();
        }
        yield return null;
    }

    public static IEnumerator LoadAsset(AssetType assetType, string assetName)
    {
        yield return LoadAsset(assetType, AssetCategory.None, assetName);
    }

    public static IEnumerator LoadAsset(AssetType assetType
        , AssetCategory categoryType
        , string assetName)
    {
        AssetLoader loader = null;
        switch (assetType)
        {
            case AssetType.Scene:
                loader = new SceneLoader(assetName, false, true);
                break;

            case AssetType.None:
                switch (categoryType)
                {
                    case AssetCategory.Data:
                        loader = new TableLoader(assetName);
                        break;
                }
                break;

            case AssetType.Texture:
                loader = new GenericLoader<Texture>(assetName, string.Empty);
                break;

            case AssetType.AudioClip:
                loader = new GenericLoader<AudioClip>(assetName, string.Empty);
                break;

            case AssetType.AnimationClip:
                loader = new GenericLoader<AnimationClip>(assetName, string.Empty);
                break;

            case AssetType.Prefab:
                switch (categoryType)
                {
                    case AssetCategory.UI:
                        loader = new GenericLoader<GameObject>(assetName, string.Empty);
                        break;
                }
                break;
        }

        yield return LoadAsset(loader);
    }
}