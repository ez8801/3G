using UnityEngine;

public class ExampleComponent : UIViewBase
{
    [ViewById("TEST")]
    public Transform t;

    [ViewById("component")]
    public ExampleComponent component;

    [ContextMenu("Execute")]
    public void FindViewById()
    {
        ViewBinder.Bind(this);
        Util.SavePrefab(gameObject);
    }
}