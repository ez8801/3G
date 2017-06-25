/* 
 * VFXManager.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */
using UnityEngine;
using System.Collections.Generic;

[System.Serializable]
public class VFXInfo
{
    public string key;
    public float duration;
    public float lifeTime;
    public GameObject go;

    public VFXInfo(string key)
    {
        this.key = key;
    }
}

public class VFXManager : MonoSingleton<VFXManager>
{
    private Dictionary<string, VFXInfo> m_cachedPool = null;
    private List<VFXInfo> m_activities = null;
    public List<VFXInfo> Activities
    {
        get
        {
            if (m_activities == null)
                m_activities = new List<VFXInfo>();
            return m_activities;
        }
    }

    public void Initialize()
    {

    }

    public void PlayVFX(string name, Vector3 v, Quaternion q)
    {
        VFXInfo vfxInfo = Get(name);
        GameObject goPrefab = Resources.Load(name) as GameObject;
        if (goPrefab == null)
            return;

        GameObject goVFX = GameObjectPool.Instance.Create(goPrefab);
        if (vfxInfo == null)
        {
            vfxInfo = new VFXInfo(name);

            ParticleSystem[] particleSystems = goVFX.GetComponentsInChildren<ParticleSystem>(true);
            if (Util.IsNullOrEmpty(particleSystems) == false)
            {
                float maxDuration = 0f;
                for (int i = 0; i < particleSystems.Length; i++)
                {
                    ParticleSystem ps = particleSystems[i];
                    maxDuration = Mathf.Max(ps.main.duration, maxDuration);
                }

                vfxInfo.duration = maxDuration + 0.2f;
                vfxInfo.lifeTime = vfxInfo.duration;
            }
        }
        else
            vfxInfo.lifeTime = vfxInfo.duration;
        
        vfxInfo.go = goVFX;
        Activities.Add(vfxInfo);
        
        Util.Attach(Instance.gameObject, goVFX);
        goVFX.transform.position = v;
        goVFX.transform.rotation = q;
        goVFX.SetActive(true);
    }

    public VFXInfo Get(string key)
    {
        if (Util.IsNullOrEmpty(m_cachedPool))
            return null;
        if (m_cachedPool.ContainsKey(key) == false)
            return null;
        return m_cachedPool[key];
    }
    
    public void Release(VFXInfo vfxInfo)
    {
        if (vfxInfo == null || m_activities == null)
            return;

        GameObjectPool.Instance.Release(vfxInfo.go);
        vfxInfo.go = null;

        m_activities.Remove(vfxInfo);
    }

    private void Update()
    {
        if (Util.IsNullOrEmpty(m_activities))
            return;

        for (int i = 0; i < m_activities.Count; i++)
        {
            VFXInfo vfxInfo = m_activities[i];
            vfxInfo.lifeTime -= Time.deltaTime;

            if (vfxInfo.lifeTime < 0f)
            {
                Release(vfxInfo);
            }
        }
    }
}
