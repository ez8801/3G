using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class tabToStart : MonoBehaviour {

    public void SceneMaster(int tab){
        SceneManager.LoadScene(tab);
    } 
}
