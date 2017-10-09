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
        
        public virtual IEnumerator OnCrate(Intent savedInstanceState)
        {
            yield return null;
        }

        public virtual void OnStart()
        {

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

        }

        public virtual void OnDestroy()
        {

        }
    }
}
