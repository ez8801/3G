using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//단순하게 버튼 끄고 킴, 차후 상태머신 만들어야함.

public class IsActive : MonoBehaviour {
    
    public GameObject button1;
    public GameObject button2;
    public GameObject button3;
    public GameObject button4;
    public void isclickOpen()
    {
        //button1.GetComponent<UIButton>().isEnabled = false;
        //button2.GetComponent<UIButton>().isEnabled = false;
        //button3.GetComponent<UIButton>().isEnabled = false;
        //button4.GetComponent<UIButton>().isEnabled = false;
    }

    public void isclickClose()
    {
        //button1.GetComponent<UIButton>().isEnabled = true;
        //button2.GetComponent<UIButton>().isEnabled = true;
        //button3.GetComponent<UIButton>().isEnabled = true;
        //button4.GetComponent<UIButton>().isEnabled = true;
    }
}
