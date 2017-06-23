using System.Collections;
using System.Collections.Generic;
using UnityEngine.SceneManagement;
using UnityEngine;

public class gameEnd : MonoBehaviour {


    public static int killNumber = 0;
    public int roundKill = 8;
    public int notice;

    // Update is called once per frame
    void Update () {
        notice = killNumber;
		if(killNumber >= roundKill)
        {
            killNumber = 0;
            Invoke("EndGame", 1.0f);
        }
	}
    void EndGame()
    {

        SceneManager.LoadScene(1);
    }
}
