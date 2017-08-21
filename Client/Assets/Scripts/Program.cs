using UnityEngine;
using GameSystem;
using System.Collections;

public class Program : MonoBehaviour
{
    private void Awake()
    {
        StartCoroutine(Initialize());
    }

    private IEnumerator Initialize()
    {
        DataManager.Instance.Initialize();
        UIManager.Instance.Initialize();
        GameObjectPool.Instance.Initialize();

        DataManager.Instance.LoadAllData();

        StageManager.Instance.Initialize(StageType.TitleStage);

        PassiveManager.Instance.Initialize();

        StatManager.Instance.Initialize();

        yield return null;

        Destroy(gameObject);
    }
}
