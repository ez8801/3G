using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playerRig : MonoBehaviour {
    public GameObject explosionPrefab;
    private void OnTriggerEnter2D(Collider2D other)
    {
        if (other.gameObject.tag.Equals("TestEnemy"))
        {
            Instantiate(explosionPrefab, other.transform.position, Quaternion.identity);
            Destroy(other.gameObject);
            gameEnd.killNumber++;
        }
    }



}
