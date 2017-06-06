﻿/* 
 * SceneLoader.cs
 * 
 * Writer : BMW
 * Date   : 2017-06-03
 * 
 * Copyright ⓒ Util. DefaultCompany, All rights reserved
 */
 
using GameSystem;
using System.Collections;

public class SceneLoader : AssetLoader
{
    private string m_sceneName;
    private bool m_isAdditive;
    private bool m_isShowLoadingUI;

    public SceneLoader(string sceneName, bool isAdditive, bool isShowLoadingUI)
    {
        m_sceneName = sceneName;
        m_isAdditive = isAdditive;
        m_isShowLoadingUI = isShowLoadingUI;
    }

    public override bool IsValid()
    {
        var activeScene = UnityEngine.SceneManagement.SceneManager.GetActiveScene();
        string loadedLevel = SceneManager.Instance.loadedLevelName;

#if UNITY_EDITOR
        UnityEngine.Debug.Log(string.Format("Active Scene: {0}\nLoaded Level: {1}\nNew Scene: {2}"
            , activeScene.name
            , loadedLevel
            , m_sceneName));
#endif

        return m_sceneName != activeScene.name && m_sceneName != loadedLevel;
    }

    public override IEnumerator Load()
    {
        yield return SceneManager.Instance.LoadLevelAsync(m_sceneName, m_isAdditive, m_isShowLoadingUI);
    }
}