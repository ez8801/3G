using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class playerWalkEx : MonoBehaviour
{
    public float movespeed = 1.0f;
    public Animator animator;
    private float backspeed = -1.0f;
    private bool boolchk;
    bool isJumping;
    public GameObject backJumpButton;

    Rigidbody2D rigdbody;

    Vector2 movement;

    private void Awake()
    {
        rigdbody = GetComponent<Rigidbody2D>();
    }

    private void FixedUpdate()
    {
        playerBackStep();
    }

    void Update()
    {

        if (Input.GetButtonDown("Jump")) isJumping = true;
        boolchk = this.animator.GetBool("backStepCk");
        if (boolchk == false)
            playerMove();

    }
    void playerMove()
    {
        float distansX = movespeed * Time.deltaTime;
        if (this.animator.GetBool("attackChk")) return;
        this.gameObject.transform.Translate(distansX, 0, 0);
    }
    public void playerBackStep()
    {

        //       Vector3 vector;
        //        vector = transform.position;

        //       float distansX = backspeed * Time.deltaTime;
        //       float distansY = -backspeed * Time.deltaTime * 0.2f;
        //       this.gameObject.transform.Translate(vector.x + distansX, vector.y + distansY, 0);
        if (!isJumping) return;

        rigdbody.AddForce(Vector2.right * backspeed, ForceMode2D.Impulse);

        isJumping = false;
    }
    private void OnTriggerEnter2D(Collider2D other)
    {
        if (other.gameObject.tag.Equals("TestEnemy"))
        {
            this.animator.SetBool("attackChk", true);
        }
    }
    private void OnTriggerStay2D(Collider2D other)
    {
        if (other.gameObject.tag.Equals("TestEnemy"))
        {
            this.animator.SetBool("attackChk", true);
        }
        else this.animator.SetBool("attackChk", false);
    }
}
