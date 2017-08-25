using System.Collections;
using UnityEngine;

namespace GameSystem
{
    /// <summary>
    /// Flow를 제어하는 클래스
    /// </summary>
    /// <see cref="StageManager"/>
    public abstract class Stage
    {
        protected UIBase m_contentView;

        private string GetFileName(string pathOrName)
        {
            if (!string.IsNullOrEmpty(pathOrName))
            {
                int indexOfSlash = pathOrName.LastIndexOf("/");
                if (indexOfSlash != -1)
                    return pathOrName.Substring(indexOfSlash + 1);
                else
                    return pathOrName;
            }
            return string.Empty;
        }

        public UIBase SetContentView(string resourceName)
        {
            string uiName = GetFileName(resourceName);
            UIBase cachedUI = Util.FindComponent<UIBase>(UIManager.Instance.Root, uiName);
            if (cachedUI != null)
            {
                m_contentView = cachedUI;
                return cachedUI;
            }

            GameObject prefab = Resources.Load(resourceName) as GameObject;
            Assert.IsNotNull(prefab);

            GameObject newOne = Object.Instantiate(prefab) as GameObject;
            UIManager.Instance.AttachUI(newOne);

            m_contentView = Util.RequireComponent<UIBase>(newOne);
            return m_contentView;
        }

        public T SetContentView<T>(string resourceName) where T : UIBase
        {
            T cachedUI = Util.FindInChildren<T>(UIManager.Instance.Root);
            if (cachedUI != null)
            {
                m_contentView = cachedUI;
                return cachedUI;
            }

            GameObject prefab = Resources.Load(resourceName) as GameObject;
            Assert.IsNotNull(prefab);

            GameObject newOne = Object.Instantiate(prefab) as GameObject;
            newOne.name = newOne.name.Replace("(Clone)", string.Empty);
            UIManager.Instance.AttachUI(newOne);

            T contentView = Util.RequireComponent<T>(newOne);
            m_contentView = contentView;
            return contentView;
        }

        public virtual IEnumerator OnCrate(Intent savedInstanceState)
        {
            yield return null;
        }

        public virtual void OnStart()
        {
            if (m_contentView != null)
                m_contentView.Show();
        }

        public virtual void OnUpdate()
        {

        }
        
        public virtual string GetTitle()
        {
            return string.Empty;
        }
        
        public virtual MonoBehaviour GetInvoker()
        {
            return StageManager.Instance;
        }

        public Coroutine StartCoroutine(IEnumerator routine)
        {
            return GetInvoker().StartCoroutine(routine);
        }

        public virtual bool IsBackable()
        {
            return true;
        }

        public virtual void OnBackPressed()
        {
            NotificationCenter.Post(R.Id.OnBackPressed);
        }

        public virtual void OnStop()
        {
            if (m_contentView != null)
                m_contentView.Hide();            
        }

        public virtual void OnDestroy()
        {

        }
    }
}
