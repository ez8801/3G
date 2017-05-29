using System.Collections;
using UnityEngine;

namespace GameSystem
{
    public abstract class Scene
    {
        public virtual void OnCrate(Intent savedInstanceState)
        {

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
            return SceneManager.Instance;
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
            NotificationCenter.Instance.Post(Notification.System.OnBackPressed);
        }

        public virtual void OnStop()
        {

        }

        public virtual void OnDestroy()
        {

        }
    }
}
