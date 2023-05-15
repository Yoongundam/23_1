using UnityEngine;
using System.Collections;
using UnityEngine.SceneManagement;

public enum MarbleGameState {playing, won,lost };

public class MarbleGameManager : MonoBehaviour
{
    public static MarbleGameManager SP;

    private int totalGems;
    private int foundGems;
    private MarbleGameState gameState;


    void Awake()
    {
        SP = this; 
        foundGems = 0;
        gameState = MarbleGameState.playing;
        totalGems = GameObject.FindGameObjectsWithTag("Pickup").Length;
        Time.timeScale = 1.0f;
    }

	void OnGUI () {
	    GUILayout.Label(" Found gems: "+foundGems+"/"+totalGems );

        if (gameState == MarbleGameState.lost)
        {
            GUILayout.Label("You Lost!");
            if(GUILayout.Button("Try again") ){
                SceneManager.LoadScene(SceneManager.GetActiveScene().name);
            }
        }
        else if (gameState == MarbleGameState.won)
        {
            GUILayout.Label("You won!");
            if(GUILayout.Button("Play again") ){
                SceneManager.LoadScene(SceneManager.GetActiveScene().name);
            }
        }
	}

    public void FoundGem()
    {
        foundGems++;
        if (foundGems >= totalGems)
        {
            WonGame();
        }
    }

    public void WonGame()
    {
        Time.timeScale = 0.0f; //Pause game
        gameState = MarbleGameState.won;
    }

    public void SetGameOver()
    {
        Time.timeScale = 0.0f; //Pause game
        gameState = MarbleGameState.lost;
    }
}
