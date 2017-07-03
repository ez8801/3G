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
        private int m_targetFrameRate;

        public void Start()
        {
            NotificationCenter.Instance.AddObserver(this);
#if UNITY_EDITOR
            m_targetFrameRate = Application.targetFrameRate;
#else
            m_targetFrameRate = Mathf.RoundToInt(Application.targetFrameRate * 0.5f);
#endif
        }

        public void Update()
        {
            if (m_currentScene != null)
                m_currentScene.OnUpdate();

#if UNITY_EDITOR || UNITY_ANDROID
            HandleKeyInput();
#endif
        }

        public void Initialize(SceneType initialSceneType)
        {
            ChangeScene(initialSceneType);
            loadedLevelName = GetLevelName(initialSceneType);
        }

        public string GetLevelName(SceneType sceneType)
        {
            switch (sceneType)
            {
                case SceneType.GameScene:
                    return GameScene.LevelName;
                case SceneType.LobbyScene:
                    return LobbyScene.LevelName;
                case SceneType.TitleScene:
                    return TitleScene.LevelName;
            }
            return string.Empty;
        }

        public void ChangeScene(SceneType sceneType)
        {
            ChangeScene(sceneType, null);
        }

        public void ChangeScene(SceneType sceneType, Intent intent)
        {
            StartCoroutine(PerformChangeScene(sceneType, intent));
        }

        internal IEnumerator PerformChangeScene(SceneType sceneType, Intent intent)
        {
            yield return StartCoroutine(OnPreChange());

            Scene nextScene = null;
            bool isAssigned = Activator.CreateInstance(out nextScene, sceneType);
            Assert.IsTrue(isAssigned, string.Format("Couldn't Create Instance at: {0}", sceneType));

            yield return nextScene.OnCrate(intent);
            if (m_currentScene != null)
                m_currentScene.OnStop();

            currentSceneType = sceneType;
            m_currentScene = nextScene;
            
            nextScene.OnStart();
            yield return StartCoroutine(OnPostChange());
            NotificationCenter.Instance.Post((int)Notification.System.OnSceneChanged, (int)sceneType);
        }

        IEnumerator OnPreChange()
        {
            yield return null;
        }

        IEnumerator OnPostChange()
        {
            for (int i = 0; i < m_targetFrameRate; i++)
            {
                yield return null;
            }
            NotificationCenter.Instance.Post((int)Notification.UI.OnProgressDone);
            yield return null;
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

        public IEnumerator LoadLevelAsync(string levelName, bool isAdditive)
        {
            Assert.IsFalse(string.IsNullOrEmpty(levelName), "SceneManager:LoadLevelAsync(string, bool, bool) ArgumentException: levelName is null or empty");

            if (isAdditive == false)
                yield return UnityEngine.SceneManagement.SceneManager.LoadSceneAsync("Empty");
            
            m_loadedLevelName = levelName;

            //if (AssetBundleHandler.IsUseAssetBundle())
            //    yield return AssetBundleManager.LoadLevelAsync("scenes.assetbundle", levelName, isAdditive);
            
            UnityEngine.SceneManagement.LoadSceneMode loadSceneMode = UnityEngine.SceneManagement.LoadSceneMode.Single;
            if (isAdditive)
                loadSceneMode = UnityEngine.SceneManagement.LoadSceneMode.Additive;
            yield return UnityEngine.SceneManagement.SceneManager.LoadSceneAsync(levelName, loadSceneMode);
            
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

        private void OnDestroy()
        {
            NotificationCenter.Instance.RemoveObserver(this);
        }
    }
}