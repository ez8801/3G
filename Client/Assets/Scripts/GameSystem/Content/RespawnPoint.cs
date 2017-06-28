/* 
 * RespawnPoint.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-27
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */

using System.Collections;
using UnityEngine;

public class RespawnPoint : MonoBehaviour
{
    public int Id;
    public int Group;
    public float DelayTime;
    public float RandomRangeMin = -0.1f;
    public float RandomRangeMax = 0.1f;
    public bool IsLoop;
    public int LoopCount;
    private int m_spwanCount;
    public Vector3 SpawnPosition;

    private EntityBase m_lastSpwanedEntity;

    public void PerformSpwan()
    {
        InternalPerformSpawn(DelayTime);
    }

    public IEnumerator AsyncSpwan()
    {
        yield return Spawn(DelayTime);
        OnSpwan();
    }

    private void InternalPerformSpawn(float delayTime)
    {
        StartCoroutine(Spawn(delayTime));
    }

    private IEnumerator Spawn(float delayTime)
    {
        for (int i = 0; i < LoopCount; i++)
        {
            yield return new WaitForSecondsRealtime(delayTime);
            OnSpwan();
        }
    }

    private void OnSpwan()
    {
        Debug.Log(Macros.__PRETTY_FUNCTION__);
        Debug.Log(Id);

        SpawnPosition = GetSpwanPosition(RandomRangeMin, RandomRangeMax);
        m_lastSpwanedEntity = LoadEntity(Id);
        m_lastSpwanedEntity.Initialize(EntityType.Character, Id);
        Assert.IsNotNull(m_lastSpwanedEntity);
        m_lastSpwanedEntity.transform.position = SpawnPosition;
        m_spwanCount++;
    }

    private EntityBase LoadEntity(int entityId)
    {
        Data.Prefab prefabData = PrefabTable.Instance.Find(entityId);
        return CharacterFactory.CreateEntity(prefabData.PrefabName);
    }

    public Vector3 GetSpwanPosition(float min, float max)
    {
        Vector3 spwanPosition = new Vector3(
            transform.position.x + Random.Range(min, max)
            , transform.position.y
            , transform.position.z);
        return spwanPosition;
    }

    public void OnEntityDead(int entityId)
    {
        if (IsLoop && Id == entityId)
        {
            if (LoopCount > m_spwanCount)
            {
                InternalPerformSpawn(DelayTime);
            }
        }
    }

    public EntityBase GetLastSpawnedEntity()
    {
        return m_lastSpwanedEntity;
    }

#if UNITY_EDITOR
    private void OnDrawGizmos()
    {
        Gizmos.color = Color.cyan;
        Gizmos.DrawWireSphere(transform.position, 0.25f);
    }
#endif
}