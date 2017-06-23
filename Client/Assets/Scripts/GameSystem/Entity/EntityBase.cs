/* 
 * EntityBase.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-06
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using UnityEngine;
using System.Collections.Generic;

public abstract class EntityBase : MonoBehaviour
{
    private static List<EntityBase> entities = new List<EntityBase>();
    
    public Transform CachedTransform
    {
        get
        {
            if (m_cachedTransform == null)
                m_cachedTransform = transform;
            return m_cachedTransform;
        }
    }
    Transform m_cachedTransform;

    protected EntityID m_guid;

    public long GUID
    {
        get
        {
            return m_guid.Id;
        }
    }

    public void Initialize(EntityType entityType, long guid)
    {
        m_guid = new EntityID(entityType, guid);
    }

    //-------------------------------------------------------------------------
    //  MonoBehaviour Life Cycle
    //-------------------------------------------------------------------------
    #region MonoBehaviour Life Cycle

    protected virtual void Awake()
    {
        bool isContains = false;
        for (int i = 0; i < entities.Count; i++)
        {
            if (entities[i].GUID == GUID)
            {
                isContains = true;
                break;
            }
        }

        if (!isContains)
            entities.Add(this);
    }

    protected virtual void Start()
    {

    }

    protected virtual void OnEnable()
    {

    }
    
    protected virtual void Update()
    {

    }

    protected virtual void OnDisable()
    {
        
    }

    protected virtual void LateUpdate()
    {

    }

    protected virtual void OnDestroy()
    {
        entities.Remove(this);
    }

    #endregion MonoBehaviour Life Cycle
}