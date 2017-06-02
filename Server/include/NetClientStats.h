/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once

#include "NetCoreStats.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/**
	\~korean
	Ŭ���̾�Ʈ�� ��Ȳ ��� �����Դϴ�.
	���� ���� ��� ���˴ϴ�.
	
	\~english
	Client status information.
	Used for performance check.
	
	\~chinese
	��?Ӯ????���ӡ�
	��������??��
	
	\~japanese
	���髤����Ȫ�?�Ϫ���ͪ���êǪ���
	�ѫի�?�ޫ󫹪����������Ū��ƪ��ު���
	*/
	class CNetClientStats :public CNetCoreStats
	{
	public:

		/**
		\~korean
		���� ����Ǿ��ִ� remote peer�� ����

		\~english
		Number of remote peer that in currently connected

		\~chinese
		?��?����remote peer��??��

		\~japanese
		��Īʪ��êƪ���remote peer��?
		\~
		*/
		uint32_t m_remotePeerCount;

		/**
		\~korean
		true�̸� �������� UDP ����� �������� �ǹ��Ѵ�.
		false�̸� UDP�� ���� ���ϸ�, �������� unreliable �޽�¡�� TCP�� �ְ�޾����� ������ �ǹ��Ѵ�.

		\~english
		true means the UDP communication with server is ok
		Cannot use UDP when false and also means the unreliable messaging with server is done via TCP.

		\~chinese
		True��?��ګ�?��?����UDP�������ȡ�
		False��?��������UDP����ګ�?unreliable messaging�������TCP?�ȡ�

		\~japanese
		True�Ǫ���Ы�?��?�Ȫ�UDP���᪬���ȪǪ��몳�Ȫ���ګ���ު���
		False�Ǫ����UDP���Ū�������?��?�Ȫ�unreliable��ë�?���󫰪�TCP�Ǫ�����ꪹ�몳�Ȫ���ګ���ު���
		\~
		*/
		bool m_serverUdpEnabled;

		/**
		\~korean
		Direct P2P�� �Ǿ��ִ� remote peer�� ����

		\~english
		Number of remote peer that consisted Direct P2P

		\~chinese
		Direct P2P��remote peer??��

		\~japanese
		Direct P2P�˪ʪêƪ���remote peer��?
		\~
		*/
		uint32_t m_directP2PEnabledPeerCount;


		/**
		\~korean
		TCP, UDP Send Queue�� �����ִ� �� ũ��, Send Queue �� ũ��

		\~english
		Total size left in TCP and UDP Send Queue. Total size of the Send Queue


		\~chinese
		TCP, UDP Send Queue�������?�����, Send Queue��?���

		\~japanese
		TCP, UDP Send Queue��?�êƪ��뫵������ͪ��Send Queue�Ϋ�������ͪ
		\~
		*/
		uint32_t m_sendQueueTotalBytes;
		uint32_t m_sendQueueTcpTotalBytes;
		uint32_t m_sendQueueUdpTotalBytes;


		CNetClientStats();

		virtual String ToString() const;
	};
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif