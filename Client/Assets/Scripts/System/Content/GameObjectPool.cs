/* 
 * GameObjectPool.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-06
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections.Generic;

public class GameObjectPool : MonoBehaviour 
{
    // 캐싱된 오브젝트
    private Dictionary<int, List<GameObject>> m_cachedPool = null;
    public Dictionary<int, List<GameObject>> CachedPool
    {
        get
        {
            if (m_cachedPool == null)
                m_cachedPool = new Dictionary<int, List<GameObject>>();
            return m_cachedPool;
        }

        private set
        {
            m_cachedPool = value;
        }
    }

    //
    private GameObject m_defaultFolder = null;
    private int m_layerOfIgnoreRendering = -1;
    
    /// <summary>
    /// 해당 인스턴스를 초기화 합니다.
    /// </summary>
    public void Initialize()
    {
        // 숨김용 레이어
        m_layerOfIgnoreRendering = LayerMask.NameToLayer("Ignore Rendering");

        // Default 폴더를 생성한다.
        m_defaultFolder = new GameObject("Default");
        m_defaultFolder.transform.parent = transform;
        m_defaultFolder.layer = m_layerOfIgnoreRendering;
    }

    /// <summary>
    /// 지정된 프리팹의 복사본을 반환합니다.
    /// </summary>
    public GameObject Create(GameObject goPrefab)
    {
        int key = goPrefab.name.GetHashCode();
        GameObject go = Get(key);

        // 검색에 실패하면 새로운 복사본을 생성한다.
        if (go == null)
        {
            go = Instantiate(goPrefab) as GameObject;
            if (go != null)
            {
                // 복사본을 생성할 때 자동으로 '(Clone)'으로 접미사가 붙기때문에 제거해준다.
                int indexOf = go.name.IndexOf("(Clone)");
                if (indexOf != -1)
                    go.name = go.name.Substring(0, indexOf);
            }
            // 검색, 생성 모두 실패한 경우
            else
            {
                Debug.LogWarning("Could not Instantiate Object");
                return null;
            }
        }

        go.layer = m_layerOfIgnoreRendering;
        go.SetActive(false);

        return go;
    }

    /// <summary>
    /// 지정된 키로 캐싱되어있는 오브젝트를 반환합니다.
    /// </summary>
    public GameObject Get(int key)
    {
        if (CachedPool.ContainsKey(key) == false)
            return null;

        List<GameObject> l = CachedPool[key];
        if (Util.IsNullOrEmpty(l))
            return null;

        GameObject go = l[0];

        go.transform.parent = null;
        l.RemoveAt(0);

        return go;
    }

    /// <summary>
    /// 지정된 키로 해당 오브젝틀 캐싱합니다.
    /// </summary>
    public void Set(int key, GameObject go)
    {
        if (go == null)
            return;

        if (CachedPool.ContainsKey(key) == false)
            CachedPool.Add(key, new List<GameObject>());

        go.SetActive(false);

        List<GameObject> l = CachedPool[key];
        l.Add(go);
    }

    /// <summary>
    /// 지정된 게임오브젝트를 캐싱합니다.
    /// </summary>
    public void Release(GameObject go)
    {
        Util.Attach(m_defaultFolder, go);
        // NGUITools.SetLayer(go, m_layerOfIgnoreRendering);
        Set(go.name.GetHashCode(), go);
    }

    /// <summary>
    /// 캐싱된 오브젝트를 모두 제거합니다.
    /// </summary>
    public void ClearAll()
    {
        if (Util.IsNullOrEmpty(m_cachedPool))
            return;

        var enumerator = CachedPool.GetEnumerator();
        while (enumerator.MoveNext())
        {
            List<GameObject> l = enumerator.Current.Value;
            if (Util.IsNullOrEmpty(l))
                continue;

            for (int i = 0; i < l.Count; i++)
            {
                if (l[i] != null)
                    DestroyImmediate(l[i]);
            }
            l.Clear();
        }

        m_cachedPool.Clear();
        m_cachedPool = null;
    }
}