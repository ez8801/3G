/* 
 * SoundInfo.cs
 * 
 * Writer : EZ
 * Date   : 2017-06-25
 * 
 * Copyright ⓒ Sweet Home Alabama. Team 3G, All rights reserved
 */
using UnityEngine;
using System.Collections;

public class SoundInfo : MonoBehaviour
{
    public SoundType type = SoundType.Effect;

    public int index;

    /// <summary>
    /// The volume of the audio source
    /// </summary>
    public float volume = 1f;

    /// <summary>
    /// Is the audio looping ?
    /// </summary>
    public bool loop = false;
    
    public AudioSource audioSource = null;    
}
