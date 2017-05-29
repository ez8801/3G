using UnityEngine;

public class Program : MonoBehaviour
{
    private void Awake()
    {
        Main();
        Destroy(gameObject);
    }

    static void Main()
    {   
        // @TODO: Initialize
        DataManager.Instance.Initialize();
        UIManager.Instance.Initialize();
    }
}
