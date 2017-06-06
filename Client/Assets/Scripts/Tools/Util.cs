/* 
 * Util.cs
 * 
 * Writer : P_BaekMinWoo
 * Date   : 2015-12-16
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */
using UnityEngine;
using System.Collections;

#if UNITY_EDITOR
using UnityEditor;
#endif

public class Util
{
    /// <summary>
    /// 지정된 리스트가 Null 이거나 비어있는지 여부를 반환
    /// </summary>
    public static bool IsNullOrEmpty(ICollection iCollection)
    {
        return (iCollection == null || iCollection.Count == 0);
    }

    /// <summary>
    /// 지정된 배열이 Null 이거나 비어있는지 여부를 반환
    /// </summary>
    public static bool IsNullOrEmpty(System.Array i_array)
    {
        return (i_array == null || i_array.Length == 0);
    }

    /// <summary>
    /// GameObject로부터 지정된 컴포넌트를 얻어온다.
    /// </summary>
    public static T RequireComponent<T>(GameObject go) where T : Component
    {
        if (go == null)
            return null;
        
        T comp = go.GetComponent<T>();
        if (comp == null)
            comp = go.AddComponent<T>();

        return comp;
    }

    /// <summary>
    /// Transform으로부터 지정된 컴포넌트를 얻어온다. 
    /// </summary>
    public static T RequireComponent<T>(Transform t) where T : Component
    {
        if (t == null)
            return null;
        
        T comp = t.GetComponent<T>();
        if (comp == null)
            comp = t.gameObject.AddComponent<T>();
        
        return comp;
    }
    
    /// <summary>
    /// 지정된 GameObject와 자식 오브젝트로부터 특정 이름의 컴포넌트를 찾아 반환합니다.
    /// </summary>
    /// <typeparam name="T">컴포넌트 타입</typeparam>
    /// <param name="go">지정한 GameObject</param>
    /// <param name="name">검색할 오브젝트 이름</param>
    /// <param name="includeInActive">비활성화된 오브젝트 포함 여부</param>
    /// <returns></returns>
    public static T FindComponentByName<T>(GameObject go, string name, bool includeInActive = true) where T : Component
    {
        if (go == null || string.IsNullOrEmpty(name))
            return null;

        T[] children = go.GetComponentsInChildren<T>(includeInActive);
        if (IsNullOrEmpty(children))
            return null;

        for (int i = 0; i < children.Length; i++)
        {
            T each = children[i];
            if (each != null && each.name == name)
                return (T)each;
        }

        return null;
    }

    /// <summary>
    /// 지정된 Transform으로부터 특정 이름의 컴포넌트를 찾아 반환합니다.
    /// </summary>
    public static T FindComponentByName<T>(Transform t, string name, bool includeInActive = true) where T : Component
    {
        if (t == null || string.IsNullOrEmpty(name))
            return null;

        if (t.name == name)
        {
            T ret = t.GetComponent<T>();
            if (ret != null)
                return ret;
        }
        
        T[] children = t.GetComponentsInChildren<T>(includeInActive);
        if (IsNullOrEmpty(children))
            return null;

        for (int i = 0; i < children.Length; i++)
        {
            T each = children[i];
            if (each != null && each.name == name)
                return (T)each;
        }

        return null;
    }

    /// <summary>
    /// 지정된 Transform으로부터 특정 이름의 컴포넌트를 찾아 반환합니다.
    /// </summary>
    public static Component FindComponentByName(System.Type type, Transform t, string name, bool includeInActive = true)
    {
        if (t == null || string.IsNullOrEmpty(name))
            return null;

        if (t.name == name)
        {
            Component ret = t.GetComponent(type);
            if (ret != null)
                return ret;
        }

        Component[] children = t.GetComponentsInChildren(type, includeInActive);
        if (IsNullOrEmpty(children))
            return null;

        for (int i = 0; i < children.Length; i++)
        {
            Component each = children[i];
            if (each != null && each.name == name)
                return each;
        }

        return null;
    }
    
    /// <summary>
    /// 지정된 게임오브젝트에 하위에 해당 게임오브젝트를 첨부합니다.
    /// </summary>
    public static void Attach(GameObject parent, GameObject child)
    {
        if (parent == null || child == null)
            return;

        Transform t = child.transform;
        t.parent = parent.transform;
        t.localPosition = Vector3.zero;
        t.localRotation = Quaternion.identity;
        t.localScale = Vector3.one;
        child.layer = parent.layer;
    }

    /// <summary>
    /// 지정된 태그로 카메라를 찾아 반환합니다.
    /// </summary>
    public static Camera GetCameraByTag(string tag)
    {
        for (int i = 0; i < Camera.allCameras.Length; i++)
        {
            if (Camera.allCameras[i].CompareTag(tag) == true)
                return Camera.allCameras[i];            
        }

        return null;
    }

#if UNITY_EDITOR

    public static void SavePrefab(GameObject obj)
    {
        PrefabType prefabType = PrefabUtility.GetPrefabType(obj);
        if (prefabType != PrefabType.Prefab)
        {
            return;
        }

        GameObject go = Object.Instantiate(obj) as GameObject;

        NestedPrefab nestedPrefab = go.GetComponent<NestedPrefab>();
        if (nestedPrefab != null)
        {
            string prevName = string.Empty;
            if (nestedPrefab.m_instance != null)
            {
                prevName = nestedPrefab.m_instance.name;
            }
            nestedPrefab.InstantiateObject();
            if (string.IsNullOrEmpty(prevName) == false)
                nestedPrefab.m_instance.name = prevName;
        }

        PrefabUtility.ReplacePrefab(go
                , obj
                , ReplacePrefabOptions.ConnectToPrefab);

        Object.DestroyImmediate(go);
        go = null;
    }

#endif
}
