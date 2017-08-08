using UnityEngine;
using System.Collections;

namespace GameSystem
{
    public class StageManager : MonoSingleton<StageManager>, IObserver
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
        
        public string currentStageName
        {
            get
            {
                return currentStageType.ToString();
            }
        }
        
        public StageType currentStageType { private set; get; }
        private Stage m_currentStage;
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
            if (m_currentStage != null)
                m_currentStage.OnUpdate();

#if UNITY_EDITOR || UNITY_ANDROID
            HandleKeyInput();
#endif
        }

        public void Initialize(StageType initialStageType)
        {
            ChangeStage(initialStageType);
            loadedLevelName = GetLevelName(initialStageType);
        }

        public string GetLevelName(StageType stageType)
        {
            switch (stageType)
            {
                case StageType.GameStage:
                    return GameStage.LevelName;
                case StageType.LobbyStage:
                    return LobbyStage.LevelName;
                case StageType.TitleStage:
                    return TitleStage.LevelName;
            }
            return string.Empty;
        }

        public void ChangeStage(StageType stageType)
        {
            ChangeStage(stageType, null);
        }

        public void ChangeStage(StageType stageType, Intent intent)
        {
            StartCoroutine(PerformChangeStage(stageType, intent));
        }

        internal IEnumerator PerformChangeStage(StageType stageType, Intent intent)
        {
            yield return StartCoroutine(OnPreChange());

            Stage nextStage = null;
            bool isAssigned = Activator.CreateInstance(out nextStage, stageType);
            Assert.IsTrue(isAssigned, string.Format("Couldn't Create Instance at: {0}", stageType));

            yield return nextStage.OnCrate(intent);
            if (m_currentStage != null)
                m_currentStage.OnStop();

            currentStageType = stageType;
            m_currentStage = nextStage;
            
            nextStage.OnStart();
            yield return StartCoroutine(OnPostChange());
            NotificationCenter.Post(R.Id.OnStageChanged, (int)stageType);
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
            NotificationCenter.Post(R.Id.OnProgressDone);
            yield return null;
        }

        public Stage GetCurrentStage()
        {
            return m_currentStage;
        }

        public void HandleKeyInput()
        {
            if (Input.GetKeyUp(KeyCode.Escape))
            {
                if (m_currentStage != null)
                    m_currentStage.OnBackPressed();
            }
        }

        public void HandleNotification(Notification message)
        {
            switch (message.id)
            {
                case R.Id.OnBackPressed:
                    // @TODO: Change Prev Stage

                    break;
            }
        }

        public IEnumerator LoadLevelAsync(string levelName, bool isAdditive)
        {
            Assert.IsFalse(string.IsNullOrEmpty(levelName), "StageManager:LoadLevelAsync(string, bool, bool) ArgumentException: levelName is null or empty");

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