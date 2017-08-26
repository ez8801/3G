/* 
 * AssetLoader.cs
 * 
 * Writer : BMW
 * Date   : 2017-06-03
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections;
using System.Collections.Generic;

public abstract class AssetLoader 
{
    private static List<AssetLoader> m_queue = new List<AssetLoader>();
    public static int TotalItemCount { get; private set; }
    public static int LoadedCount { get; private set; }

    public virtual bool IsValid()
    {
        return true;
    }

    public virtual void OnPostLoad()
    {
        LoadedCount = Mathf.Clamp(LoadedCount + 1, 0, TotalItemCount);

        if (TotalItemCount > 0)
        {
            float progress = (float)LoadedCount / TotalItemCount;
            NotificationCenter.Post(R.Id.OnProgress, progress);
        }
    }

    public abstract IEnumerator Load();

    public static void AddLoadingRequest(AssetType assetType
        , AssetCategory categoryType
        , string assetName)
    {
        AssetLoader loader = CreateAssetLoader(assetType, categoryType, assetName);
        AddLoadingRequest(loader);
    }

    public static void AddLevelLoadingRequest(string levelName, bool isAdditive)
    {
        AssetLoader loader = new SceneLoader(levelName, isAdditive);
        AddLoadingRequest(loader);
    }

    public static void AddUILoadingRequest(UIType typeOfUI)
    {
        AssetLoader loader = new UILoader(typeOfUI);
        AddLoadingRequest(loader);
    }

    public static void AddLoadingRequest(AssetLoader loader)
    {
        TotalItemCount++;
        m_queue.Add(loader);
    }
    
    public static AssetLoader CreateAssetLoader(AssetType assetType
        , AssetCategory categoryType
        , string assetName)
    {
        AssetLoader loader = null;
        switch (assetType)
        {
            case AssetType.Scene:
                loader = new SceneLoader(assetName, false);
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
        return loader;
    }

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
        AssetLoader loader = CreateAssetLoader(assetType, categoryType, assetName);
        yield return LoadAsset(loader);
    }
    
    private static void Clear()
    {
        TotalItemCount = 0;
        LoadedCount = 0;
        m_queue.Clear();
    }

    public static IEnumerator StartLoading()
    {
        UIManager.Instance.ShowLoadingUI(true);

        for (int i = 0; i < m_queue.Count; i++)
        {
            AssetLoader loader = m_queue[i];
            yield return LoadAsset(loader);

            yield return null;
        }

        Clear();
        yield return new WaitForEndOfFrame();
    }
}