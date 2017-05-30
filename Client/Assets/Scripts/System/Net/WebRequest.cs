using UnityEngine;
using System.Collections;
using UnityEngine.Networking;

/// <summary>
/// Error Handling
/// Recognize Timeout
/// </summary>
public class WebRequest
{
	private const float kFrameMaxTime	= 1f / 30f;
	private const float kStopTimeOut	= 10f;
	private const float kTimeOut		= 300f;
	
	private string m_errorMessage;
	public string error
	{
		get
		{
			return m_errorMessage;
		}
	}

	public bool isError
	{
		get
		{
			return !string.IsNullOrEmpty(m_errorMessage);
		}
	}

	private bool isTimeOut
	{
		get
		{
			return m_errorMessage == "TimeoutException";
		}
	}
	private float accumulatedStopTime;
	private float accumulatedTotalTime;

	private float m_lastProgress;
	private long m_lastResponseCode;
    public long LastResponseCode
    {
        get
        {
            return m_lastResponseCode;
        }
    }
    
    private string m_url;
	private UnityWebRequest m_webRequest;

	private System.Action<WebRequest> m_onRequestEndListener;

	public WebRequest(string url)
	{
		SetUrl(url);
	}

	public void SetUrl(string url)
	{
		m_url = url;

		accumulatedStopTime = 0f;
		accumulatedTotalTime = 0f;
		m_lastProgress = 0f;
		m_lastResponseCode = 200;
	}
	
	public void SetOnRequestEndListener(System.Action<WebRequest> l)
	{
		m_onRequestEndListener = l;
	}

	private float Clamp(float value, float max)
	{
		if (value > max)
			return max;
		return value;
	}
    
	public IEnumerator AsyncSendRequest()
	{
		using (m_webRequest = new UnityWebRequest(m_url))
		{
			if (m_webRequest == null)
				yield break;

			m_webRequest.Send();

			while (m_webRequest.isDone == false && m_webRequest.isError == false)
			{
				float frameTime = Clamp(Time.unscaledDeltaTime, kFrameMaxTime);

				accumulatedStopTime += frameTime;
				accumulatedTotalTime += frameTime;

				if (m_lastProgress != m_webRequest.downloadProgress)
				{
					m_lastProgress = m_webRequest.downloadProgress;
					accumulatedStopTime = 0f;
				}

				if (accumulatedStopTime >= kStopTimeOut || accumulatedTotalTime >= kTimeOut)
				{
					m_errorMessage = "TimeoutException";
					break;
				}
			}

			m_lastResponseCode = m_webRequest.responseCode;
			m_errorMessage = m_webRequest.error;
		}
		
		if (m_onRequestEndListener != null)
			m_onRequestEndListener(this);

		yield return null;
	}

    public void SendRequest(string url)
    {
        SetUrl(url);
        m_webRequest = new UnityWebRequest(url);
        m_webRequest.Send();
    }

    public void Update()
	{
		if (m_webRequest == null)
			return;
		
		if (m_webRequest.isDone == true || m_webRequest.isError == true)
		{
			m_lastResponseCode = m_webRequest.responseCode;
			m_errorMessage = m_webRequest.error;

			if (m_onRequestEndListener != null)
				m_onRequestEndListener(this);
		}
		else
		{
			float frameTime = Clamp(Time.unscaledDeltaTime, kFrameMaxTime);

			accumulatedStopTime += frameTime;
			accumulatedTotalTime += frameTime;

			if (m_lastProgress != m_webRequest.downloadProgress)
			{
				m_lastProgress = m_webRequest.downloadProgress;
				accumulatedStopTime = 0f;
			}

			if (accumulatedStopTime >= kStopTimeOut || accumulatedTotalTime >= kTimeOut)
			{
				m_errorMessage = "TimeoutException";
			}
		}
	}
}
