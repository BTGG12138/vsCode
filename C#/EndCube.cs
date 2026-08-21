using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
public class EndCube : MonoBehaviour
{
bool isEnd, isCaught,isAudio;
public float uiTime;
float timeCount;
public GameObject Lemon;
public CanvasGroup isCaughtUI, isEndUI;
public AudioSource Win, Loss;
void OnTriggerEnter(Collider collider)
{
    if (collider.gameObject == Lemon)
    {
        isEnd = true;
    }
}

public void IsCaught()
{
    isCaught = true;
}

void Awake()
{
    QualitySettings.vSyncCount = 0;
    Application.targetFrameRate=60;
}
void Update()
{
    if (isEnd)
    {
    UIGenerate(isEndUI, true,Win);
    }
    if (isCaught)
    {
    UIGenerate(isCaughtUI, false,Loss);
    }
    if (Input.GetKeyDown(KeyCode.Escape))
    {
    Application.Quit();
    }
    }
void UIGenerate(CanvasGroup UIChange, bool isEnding,AudioSource audioPlaying)
{
    timeCount += Time.deltaTime;
    UIChange.alpha = timeCount / uiTime;
    if(!isAudio)
    {
        audioPlaying.Play();
        isAudio = true;
    }
    if (timeCount > uiTime)
    {
        if (isEnding)
        {
            //UnityEditor.EditorApplication.isPlaying = false;
            SceneManager.LoadScene(0);
        }
        else
        {
            SceneManager.LoadScene(0);
        }
    }
}
}