//-------------------------------------------------
//            NGUI: Next-Gen UI kit
// Copyright © 2011-2017 Tasharen Entertainment Inc
//-------------------------------------------------

using UnityEngine;

/// <summary>
/// Tween the value.
/// </summary>

[AddComponentMenu("NGUI/Tween/Tween Value")]
public class TweenValue : UITweener
{
	public float from = 1f;
	public float to = 1f;

    private float m_value = 0f;
    
	/// <summary>
	/// Audio source's current volume.
	/// </summary>

	public float value
	{
		get
		{
			return m_value;
		}
		set
		{
            m_value = value;
		}
	}

    public delegate void OnUpdateDelegate(float factor, bool isFinished);
    private OnUpdateDelegate m_onUpdateListener;

    public void SetOnUpdateListener(OnUpdateDelegate l)
    {
        m_onUpdateListener = l;
    }

	protected override void OnUpdate(float factor, bool isFinished)
	{
		value = from * (1f - factor) + to * factor;
        if (m_onUpdateListener != null)
            m_onUpdateListener(value, isFinished);
    }

	/// <summary>
	/// Start the tweening operation.
	/// </summary>

	static public TweenValue Begin(GameObject go, float duration, float from, float to)
	{
        TweenValue comp = Begin<TweenValue>(go, duration);
		comp.from = from;
		comp.to = to;
		return comp;
	}

	public override void SetStartToCurrentValue () { from = value; }
	public override void SetEndToCurrentValue () { to = value; }
}
