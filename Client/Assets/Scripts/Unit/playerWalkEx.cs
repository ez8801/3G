using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playerWalkEx : MonoBehaviour {
    public float movespeed = 1.0f;

	void Update () {
        playerMove();
	}
    void playerMove()
    {
        float distansX = movespeed * Time.deltaTime;

        this.gameObject.transform.Translate(distansX, 0, 0);
    }
}
