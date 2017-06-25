/* 
 * SoundManager.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */
using UnityEngine;
using System.Collections.Generic;

public enum SoundType
{
    None,
    BGM,
    Effect
}

public class SoundManager : MonoSingleton<SoundManager>
{
    private AudioListener audioListener = null;

    /// <summary>
    /// 효과음 출력 여부
    /// </summary>
    public bool enabledBGMSound
    {
        get
        {
            return EnabledBGMSound;
        }
        set
        {
            bool prev = EnabledBGMSound;
            EnabledBGMSound = value;

            if (prev == true && value == false)
            {
                StopBGM();
            }
            else if (prev == false && value == true)
            {
                PlayBGM(indexOfLastBGM);
            }
        }
    }
    private bool EnabledBGMSound = false;

    /// <summary>
    /// 배경음 출력 여부
    /// </summary>
    public bool enabledEffectSound = false;

    private Transform m_cachedTransform = null;

    private List<SoundInfo> m_activities = null;
    private List<SoundInfo> Activities
    {
        get
        {
            if (m_activities == null)
                m_activities = new List<SoundInfo>();
            return m_activities;
        }
    }

    private int indexOfLastBGM = -1;
    

    //    
    public void Initialize()
    {
        if (audioListener == null)
            audioListener = Util.RequireComponent<AudioListener>(gameObject);
        
        m_cachedTransform = transform;
        
        // enabledBGMSound = Preference.Instance.enabledBGMSound;
        // enabledEffectSound = Preference.Instance.enabledEffectSound;
    }

    /// <summary>
    /// 지정된 인덱스에 해당하는 사운드를 출력합니다.
    /// </summary>
    public bool PlaySound(int index)
    {
        if (enabledEffectSound == false)
            return false;

        // Sound Prefab을 얻어옵니다.
        GameObject goPrefab = null;
            // Preference.Instance.GetSound(index);
        if (goPrefab == null)
            return false;

        GameObject goSound = GameObjectPool.Instance.Create(goPrefab);
        SoundInfo si = Util.RequireComponent<SoundInfo>(goSound);
        if (si.audioSource == null)
        {
            si.audioSource = goSound.GetComponent<AudioSource>();
            si.audioSource.playOnAwake = false;
        }
        
        //
        si.index = index;
        si.type = SoundType.Effect;

        // 등록
        Activities.Add(si);

        Util.Attach(Instance.gameObject, goSound);
        si.gameObject.SetActive(true);
        si.audioSource.Play();
        return true;
    }

    /// <summary>
    /// 지정된 인덱스에 해당하는 사운드를 출력합니다.
    /// </summary>
    public bool PlayBGM(int index)
    {
        if (enabledBGMSound == false)
            return false;
        
        StopBGM();

        // Sound Prefab을 얻어옵니다.
        GameObject goPrefab = null;
            // Preference.Instance.GetSound(index);
        if (goPrefab == null)
            return false;

        GameObject goSound = GameObjectPool.Instance.Create(goPrefab);
        SoundInfo si = Util.RequireComponent<SoundInfo>(goSound);
        if (si.audioSource == null)
        {
            si.audioSource = goSound.GetComponent<AudioSource>();
            si.audioSource.playOnAwake = false;
        }

        //
        si.index = index;
        si.type = SoundType.BGM;
        si.audioSource = Util.FindComponentByName<AudioSource>(goSound, goSound.name, true);
        
        // 등록
        Activities.Add(si);

        Util.Attach(m_cachedTransform.gameObject, goSound);
        si.gameObject.SetActive(true);
        si.audioSource.Play();

        indexOfLastBGM = index;
        return true;
    }

    /// <summary>
    /// 배경음악을 정지합니다.
    /// </summary>
    public void StopBGM()
    {
        for (int i = 0; i < Activities.Count; i++)
        {
            SoundInfo si = Activities[i];
            if (si.type != SoundType.BGM)
                continue;
            if (si == null || si.audioSource == null)
                continue;

            Activities.Remove(si);
            ReleseSound(si);
        }
    }

    public void Update()
    {
        for (int i = Activities.Count - 1; i >= 0; i--)
        {
            SoundInfo si = Activities[i];
            if (si == null || si.audioSource == null)
                continue;

            if (si.audioSource.isPlaying == false)
            {
                Activities.Remove(si);
                ReleseSound(si);
            }
        }
    }


    //------------------------------------------------------------------------------------
    //  internal
    //------------------------------------------------------------------------------------
    #region internal
    
    /// <summary>
    /// 지정된 Index의 객체를 해제합니다.
    /// </summary>
    private void ReleseSound(SoundInfo si)
    {
        if (si == null)
            return;
        
        si.audioSource.Stop();

        GameObjectPool.Instance.Release(si.gameObject);        
        Activities.Remove(si);
    }

    #endregion internal
}
