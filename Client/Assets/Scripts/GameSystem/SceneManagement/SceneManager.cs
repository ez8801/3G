using UnityEngine;
using System.Collections;

namespace GameSystem
{
    public class SceneManager : MonoSingleton<SceneManager>, IObserver
    {
        private string m_loadedLevelName = string.Empty;
        public string loadedLevelName
        {
            get
            {
                return m_loadedLevelName;
            }
            set
            {
                m_loadedLevelName = value;
            }
        }

        public string currentSceneName
        {
            get
            {
                return currentSceneType.ToString();
            }
        }

        public SceneType currentSceneType { private set; get; }
        private Scene m_currentScene;

        public void Update()
        {
            if (m_currentScene != null)
                m_currentScene.OnUpdate();

#if UNITY_EDITOR || UNITY_ANDROID
            HandleKeyInput();
#endif
        }

        public void ChangeScene(SceneType sceneType)
        {
            ChangeScene(sceneType, null);
        }

        public void ChangeScene(SceneType sceneType, Intent intent)
        {
            if (m_currentScene != null)
                m_currentScene.OnStop();

            bool isCreatable = Activator.CreateInstance(ref m_currentScene, sceneType);
            Assert.IsTrue(isCreatable, string.Format("Couldn't Create Instance at: {0}", sceneType));

            currentSceneType = sceneType;
            m_currentScene.OnCrate(intent);
            m_currentScene.OnStart();
        }

        public Scene GetCurrentScene()
        {
            return m_currentScene;
        }

        public void HandleKeyInput()
        {
            if (Input.GetKeyUp(KeyCode.Escape))
            {
                if (m_currentScene != null)
                    m_currentScene.OnBackPressed();
            }
        }

        public void HandleNotification(Notification message)
        {
            switch (message.id)
            {
                case (int)Notification.System.OnBackPressed:
                    // @TODO: Change Prev Scene

                    break;
            }
        }

        public IEnumerator LoadLevelAsync(string levelName, bool isAdditive, bool isShowLoadingUI)
        {
            Assert.IsFalse(string.IsNullOrEmpty(levelName), "SceneManager:LoadLevelAsync(string, bool, bool) ArgumentException: levelName is null or empty");

            //if (isShowLoadingUI)
            //    yield return UnityEngine.SceneManagement.SceneManager.LoadSceneAsync("Scene_Loading");

            m_loadedLevelName = levelName;

            //if (AssetBundleHandler.IsUseAssetBundle())
            //    yield return AssetBundleManager.LoadLevelAsync("scenes.assetbundle", levelName, isAdditive);
            //else
            //{
            //    UnityEngine.SceneManagement.LoadSceneMode loadSceneMode = UnityEngine.SceneManagement.LoadSceneMode.Single;
            //    if (isAdditive)
            //        loadSceneMode = UnityEngine.SceneManagement.LoadSceneMode.Additive;
            //    yield return UnityEngine.SceneManagement.SceneManager.LoadSceneAsync(levelName, loadSceneMode);
            //}

            yield return null;
        }

        private void GarbageCollect()
        {
            System.GC.Collect();
#if !UNITY_EDITOR
		    System.GC.WaitForPendingFinalizers();
#endif
        }

        private IEnumerator ClearUnusedMemory()
        {
            GarbageCollect();
            yield return new WaitForEndOfFrame();
            yield return Resources.UnloadUnusedAssets();
        }
    }
}