using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class IsOpen : MonoBehaviour {

    public GameObject Target;
    public void openUI()
    {
        Target.SetActive(true);
    }
    public void downUI()
    {
        Target.SetActive(false);
    }
}
