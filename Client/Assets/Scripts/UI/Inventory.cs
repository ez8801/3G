using System.Collections;
using System.Collections.Generic;
using UnityEngine;

//인벤토리 grid의 자식리스트 가져오는 방법 알아내야함.

public class Inventory : MonoBehaviour
{
    GameObject inventoryPanel;
    GameObject slotPanel;
    public GameObject inventorySlot;
    public GameObject inventoryItem;

    int slotAmount;
    public List<Data.Item> items = new List<Data.Item>();
    public List<GameObject> slots = new List<GameObject>();

    private void Start()
    {
        slotAmount = 80;
        // inventoryPanel = GameObject.Find(In)

    }
}
