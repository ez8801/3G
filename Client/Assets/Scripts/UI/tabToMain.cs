using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class tabToMain : MonoBehaviour
{

    public int tab = 1;

    public void SceneMaster()
    {
        SceneManager.LoadScene(tab);
    }
}
