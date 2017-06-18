using System.Collections;
using System.Collections.Generic;
using UnityEngine.SceneManagement;
using UnityEngine;

public class gameEnd : MonoBehaviour {


    public static int killNumber = 1;
    public int roundKill = 8;

    // Update is called once per frame
    void Update () {
		if(killNumber == roundKill)
        {
            killNumber = 1;
            Invoke("EndGame", 1.0f);
        }
	}
    void EndGame()
    {

        SceneManager.LoadScene(1);
    }
}
