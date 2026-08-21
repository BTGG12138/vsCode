using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class GhostSeeWP : MonoBehaviour
{
    NavMeshAgent navmeshagent;
    public Transform[] WPs;
    int WPindex;
    void Start()
    {
        navmeshagent = GetComponent<NavMeshAgent>();
        navmeshagent.SetDestination(WPs[0].position);
    }
    void Update()
    {
        if(navmeshagent.remainingDistance<navmeshagent.stoppingDistance)
        {
            WPindex = (WPindex + 1) % WPs.Length;
            navmeshagent.SetDestination(WPs[WPindex].position);
        }
    }
}
