using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerController2 : MonoBehaviour
{
    private Rigidbody playerRd;  //Rigidbody 컴포넌트 저장
    public float speed = 10f;

    // Start is called before the first frame update
    void Start ()
    {
        playerRd = GetComponent<Rigidbody> (); //Rigidbody 컴포넌트를 찾아서 지정
    }

    // Update is called once per frame
    void Update()
    {
        if(Input.GetKey(KeyCode.LeftArrow) == true) 
        {
            playerRd.AddForce (-speed , 0f , 0f);
        }
        if (Input.GetKey (KeyCode.RightArrow) == true)
        {
            playerRd.AddForce (speed , 0f , 0f);
        }
        if (Input.GetKey (KeyCode.UpArrow) == true) 
        {
            playerRd.AddForce (0f, 0f , speed);
        }
        if (Input.GetKey (KeyCode.DownArrow) == true)
        {
            playerRd.AddForce (0f , 0f , -speed);
        }
        if (Input.GetKey (KeyCode.Space) == true) 
        {
            playerRd.AddForce (0f , speed , 0f);
        }
    }
}
