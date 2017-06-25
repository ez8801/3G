﻿using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.SceneManagement;
using Nettention.Proud;

public class loginToServer : MonoBehaviour {
	// Client 객체 생성.
	private Client m_client;
	
	private string m_userPassword; // 유저의 Password값
	private string m_serverIP; // 서버아이피를 저장할 스트링 변수.
    private string m_userID; // 유저의 ID값
	private string m_logonButtonString;
	
	// Use this for initialization
	void Start () {
		m_client = Client.Instance; // Client 만들어진 객체가 있다면 그것을 아니라면 새로 만들어서 가져온다.
		m_logonButtonString = "Login";
		m_serverIP = "121.131.147.109"; // m_serverIP 초기화.

        m_userID = ""; // m_userName 초기화.
        m_userPassword = "";
	}
	
	
	// Update is called once per frame
	void Update () {
		// 서버 연결이 정상적으로 되었는지 확인 한다.
		if (m_client.IsConnect == true) // 서버 연결이 되었다면.
		{
            //SceneManager.LoadScene(4);
			//Application.LoadLevel("globalChat"); // 다음씬으로 전환 한다.
		}
	}
	
	void OnGUI()
	{
		// 라벨을 ServerIP 라는 문자로 그린다.
		GUI.Label( new Rect(m_client.ScreenWidth / 2 - m_client.ScreenOneW * 2, m_client.ScreenOneH, m_client.ScreenOneW * 4, m_client.ScreenOneH),"ID");
        // 텍스트 필드를 그린다. 여기에는 serverIP 가 입력 된다.
        m_userID = GUI.TextField(new Rect(m_client.ScreenWidth / 2 - m_client.ScreenOneW * 2, m_client.ScreenOneH * 2, m_client.ScreenOneW * 4, m_client.ScreenOneH), m_userID);
		// 라벨을 userName 이라는 문자로 그린다.
		GUI.Label( new Rect(m_client.ScreenWidth / 2 - m_client.ScreenOneW * 2, m_client.ScreenOneH * 4, m_client.ScreenOneW * 4, m_client.ScreenOneH),"Password");
        // 텍스트필드를 그린다. 여기에는 닉네임이 입력 된다.
        m_userPassword = GUI.TextField(new Rect(m_client.ScreenWidth / 2 - m_client.ScreenOneW * 2, m_client.ScreenOneH * 5, m_client.ScreenOneW * 4, m_client.ScreenOneH), m_userPassword);
		
		/* 버튼 클릭시 userName 과 serverIP 를 CCleint 객체에 저장하고 서버 연결을 시도한다.
		 * 정상적으로 연결 되었다면 다음 씬으로 전환된다.
		 * */
		// LogOn 버튼을 그린다. 
		if (GUI.Button(new Rect(m_client.ScreenWidth / 2, m_client.ScreenOneH * 7, m_client.ScreenOneW, m_client.ScreenOneH), m_logonButtonString))
		{
			if (!m_userID.Equals("") && !m_serverIP.Equals("")) // 닉네임과 서버 아이피가 모두 입력 되어 있다면.
			{
				m_client.ServerIP = m_serverIP; // m_client 에 서버아이피를 설정.
				m_client.userName = m_userID; // m_client 에 닉네임을 설정.
                m_client.userPassword = m_userPassword;
				m_client.Connect(); // 서버에 접속 요청.
				m_client.IsWait = true; // 서버 연결요청을 하였을음 체크하는 변수의 속성에 true 값을 넣어준다.
				m_logonButtonString = "connecting...";
			}
		}

		if(GUI.Button(new Rect(m_client.ScreenWidth / 2 + m_client.ScreenOneW, m_client.ScreenOneH * 7, m_client.ScreenOneW, m_client.ScreenOneH), "QUIT"))
		{
            SceneManager.LoadScene(1); // 어플리케이션 종료. -> 메인화면으로 씬 전환
		}
	}
}

public struct items
{
    public int itemInherentIdx;
    public int itemIdx;
    public int itemType;
};


    class Test : Nettention.Proud.Marshaler
    {
        public static void Write(Nettention.Proud.Message msg, Nettention.Proud.FastArray<items> strMsg)
        {
            int a;
            a = 0;
        }
        public static bool Read(Nettention.Proud.Message msg, out Nettention.Proud.FastArray<items> strMsg)
        {
            strMsg = new Nettention.Proud.FastArray<items>();
            int count = 0;
            msg.ReadScalar(ref count);

            items contain_items = new items();
            for (int i = 0; i < count; i++)
            {
                msg.ReadScalar(ref contain_items.itemInherentIdx);
                msg.ReadScalar(ref contain_items.itemIdx);
                msg.ReadScalar(ref contain_items.itemType);
                strMsg.Add(contain_items);
            }
            
            return true;
      } 
            
            
            
        
    }