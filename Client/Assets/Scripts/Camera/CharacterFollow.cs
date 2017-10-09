﻿/* 
 * CharacterFollow.cs
 * 
 * Writer : P_BaekMinWoo
 * Date   : 2017-06-27
 * Desc   : 카메라가 타겟 오브젝트를 따라가도록 할 수 있습니다.
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */
using UnityEngine;

public class CharacterFollow : MonoBehaviour
{
    /// <summary>
    /// 타겟 오브젝트
    /// </summary>
    public Transform target;
    
    public Transform farLeft;    
    public Transform farRight;

    public Vector2 scale = Vector2.one;

    public float strength = 2.5f;

    Transform cachedTransform;
    float mThreshold = 0f;

    void Awake()
    {
        cachedTransform = transform;
    }

    public void Initialize(Transform t)
    {
        target = t;

        GameObject go = GameObject.FindWithTag("FarLeft");
        if (go != null)
            farLeft = go.transform;

        go = GameObject.FindWithTag("FarRight");
        if (go != null)
            farRight = go.transform;
    }
    //10-09카메라 위치 약간손봄(위로 1.0f올려서 추적, 게임 씬 내부 main camera 의 SIZE 2->3으로 변함)
    void Update()
    {
        if (target == null)
            return;

        float clampX = Mathf.Clamp(target.position.x
            , (farLeft != null) ? farLeft.position.x : float.MinValue
            , (farRight != null) ? farRight.position.x : float.MaxValue);

        Vector3 vTarget = new Vector3(clampX
            , (scale.y == 1) ? target.position.y+1.0f : cachedTransform.position.y+1.0f
            , cachedTransform.position.z);

        // cachedTransform.SetPosX(clampX);        
        float delta = Time.deltaTime;
        if (mThreshold == 0f)
            mThreshold = (vTarget - cachedTransform.position).magnitude * 0.001f;
        cachedTransform.position = NGUIMath.SpringLerp(cachedTransform.position, vTarget, strength, delta);

        if (mThreshold >= (vTarget - cachedTransform.position).magnitude)
            cachedTransform.position = vTarget;            
    }
}