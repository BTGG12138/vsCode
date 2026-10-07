using JetBrains.Annotations;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class Lemon : MonoBehaviour
{
    Animator animator;
    Rigidbody rigidBody;
    AudioSource audioSource;
    Quaternion rotation = Quaternion.identity;
    float Horizontal;
    float Vertical;
    public float turnSpeed;
    public float moveSpeed;
    Vector3 Position;
    // Start is called before the first frame update
    void Start()
    {
        animator = GetComponent<Animator>();
        rigidBody = GetComponent<Rigidbody>();
        audioSource = GetComponent<AudioSource>();
    }
    void Update()
    {
        Horizontal = Input.GetAxis("Horizontal");
        Vertical = Input.GetAxis("Vertical");
    }
    void FixedUpdate()
    {
        Position.Set(Horizontal, 0.0f, Vertical);
        Position.Normalize();
        bool isHorizontal = !Mathf.Approximately(Horizontal, 0.0f);
        bool isVertical = !Mathf.Approximately(Vertical, 0.0f);
        bool IsMoving = isHorizontal || isVertical;
        animator.SetBool("isMoving", IsMoving);
        Vector3 forward = Vector3.RotateTowards(transform.forward, Position,turnSpeed*Time.deltaTime,0f);
        rotation = Quaternion.LookRotation(forward);
        if(IsMoving)
        {
            if(!audioSource.isPlaying)
            {
                audioSource.Play();
            }
        }
        else
        {
            audioSource.Stop();
        }
    }
    void OnAnimatorMove()
    {
        rigidBody.MovePosition(rigidBody.position + moveSpeed*Position * animator.deltaPosition.magnitude);
        rigidBody.MoveRotation(rotation);
    }
}