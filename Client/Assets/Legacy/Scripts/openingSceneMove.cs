using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class openingSceneMove : MonoBehaviour {
    public float scrollSpeed = 0.1f;
    public Material thisMaterial;

    void Update()
    {
        Vector2 newOffset = thisMaterial.mainTextureOffset;
        newOffset.Set(newOffset.x + (scrollSpeed * Time.deltaTime), 0);
        thisMaterial.mainTextureOffset = newOffset;
    }
}
