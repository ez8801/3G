using UnityEngine;
using UnityEditor;
using System;

public enum PlayModeState
{
    Stopped,
    Playing,
    Paused,
}

[InitializeOnLoad]
public class PlayModeChangeListener
{
    private static PlayModeState currentState = PlayModeState.Stopped;

    static PlayModeChangeListener()
    {
        EditorApplication.playmodeStateChanged = OnUnityPlayModeChanged;
        if (EditorApplication.isPaused)
            currentState = PlayModeState.Paused;
    }

    private static event Action<PlayModeState, PlayModeState> m_listener;
    public static void SetPlayModeChangeListener(Action<PlayModeState, PlayModeState> l)
    {
        m_listener = l;
    }

    private static void OnPlayModeChanged(PlayModeState currentState, PlayModeState changedState)
    {
        if (m_listener != null)
            m_listener(currentState, changedState);

        Debug.Log("Current mode: " + currentState.ToString() + ", Changed Mode: " + changedState.ToString());
    }

    private static void OnUnityPlayModeChanged()
    {
        var changedState = PlayModeState.Stopped;

        switch (currentState)
        {
            case PlayModeState.Stopped:
                if (EditorApplication.isPlayingOrWillChangePlaymode)
                {
                    changedState = PlayModeState.Playing;
                }
                else if (EditorApplication.isPaused)
                {
                    changedState = PlayModeState.Paused;
                }
                break;

            case PlayModeState.Playing:
                if (EditorApplication.isPaused)
                {
                    changedState = PlayModeState.Paused;
                }
                else if (EditorApplication.isPlaying)
                {
                    changedState = PlayModeState.Playing;
                }
                else
                {
                    changedState = PlayModeState.Stopped;
                }
                break;

            case PlayModeState.Paused:
                if (EditorApplication.isPlayingOrWillChangePlaymode && !EditorApplication.isPaused)
                {
                    changedState = PlayModeState.Playing;
                }
                else if (EditorApplication.isPlayingOrWillChangePlaymode && EditorApplication.isPaused)
                {
                    changedState = PlayModeState.Paused;
                }
                break;

            default:
                throw new ArgumentOutOfRangeException();
        }

        // Fire PlayModeChanged event.
        if (currentState != changedState)
            OnPlayModeChanged(currentState, changedState);

        // Set current state.
        currentState = changedState;
    }

}
