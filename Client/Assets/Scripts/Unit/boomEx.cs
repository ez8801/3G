using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class boomEx : MonoBehaviour {

    void Start()
    {
        Destroy(this.gameObject, 0.45f);
        gameEnd.killNumber += 1;
    }
 }
