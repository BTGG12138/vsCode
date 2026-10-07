using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class Demon : MonoBehaviour
{
    public GameObject Lemon;
    bool isBeIn, isCaught;
    public EndCube gameEnding;

    void OnTriggerEnter(Collider collider)
    {
        if (collider.gameObject == Lemon)
        {
            isBeIn = true;
        }
    }

    void OnTriggerExit(Collider collider)
    {
        if (collider.gameObject == Lemon)
        {
            isBeIn = false;
        }
    }

    void Update()
    {
        if (isBeIn == true)
        {
            Vector3 position = Lemon.transform.position - transform.position + Vector3.up;
            Ray ray = new Ray(transform.position, position);
            RaycastHit raycastHit;

            if (Physics.Raycast(ray, out raycastHit))
            {
                if (raycastHit.collider.gameObject == Lemon)
                {
                    isCaught = true;
                }
            }
        }

        if (isCaught == true)
        {
            gameEnding.IsCaught();
        }
    }
}