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

    protected EntityID m_entityID;
    protected EntityID m_groupId;

    public long EntityID
    {
        get
        {
            return m_entityID.UID;
        }
    }

    public long GroupId
    {
        get
        {
            return m_groupId.UID;
        }
    }

    public virtual void Initialize(EntityType entityType, int entityId)
    {
        SetEntityId(entityType, entityId);
    }

    public void SetEntityId(EntityType entityType, int entityId)
    {
        m_entityID = new EntityID(entityType, entityId);
    }
    
    public void SetGroupId(int groupId)
    {
        m_groupId = new EntityID(EntityType.Team, groupId);
    }

    public virtual void Initialize()
    {

    }

    public static EntityBase Find(long id)
    {
        for (int i = 0; i < entities.Count; i++)
        {
            EntityBase match = entities[i];
            if (match.EntityID == id)
                return match;
        }
        return null;
    }

    /// <summary>
    /// 지정된 Entity와 가장 가까운 Entity를 반환합니다.
    /// </summary>
    public static EntityBase FindNearestTarget(EntityBase source)
    {
        float minDist = 9999;
        int indexOfNearest = -1;

        for (int i = 0; i < entities.Count; i++)
        {
            EntityBase match = entities[i];
            if (match.EntityID == source.EntityID)
                continue;

            if (match.GroupId == 0 || match.GroupId == source.GroupId)
                continue;
            
            float distance = Vector3.Distance(match.CachedTransform.position, source.CachedTransform.position);
            if (distance < minDist)
            {
                minDist = distance;
                indexOfNearest = i;
            }
        }

        if (indexOfNearest >= 0 && indexOfNearest < entities.Count)
        {
            return entities[indexOfNearest];
        }

        // Not found entity
        return null;
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
            if (entities[i].EntityID == EntityID)
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