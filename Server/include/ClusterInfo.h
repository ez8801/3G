/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once

#include <memory>

#include "pnguid.h"

#include "ThreadPool.h"
#include "FastArray.h"
#include "PNString.h"

namespace Proud
{
	struct ClusterInfo
	{
		// 클러스터 서버는 여러대가 될 수 있다. 이 때 각 클러스터를 식별하기 위한 사용자가 지정한 논리적인 유니크 값이다.
		String		m_identifier;

		// 클러스터 서버의 IP 주소 혹은 FQDN이 될 수 있는 값이다.
		String		m_hostName;
		uint16_t	m_port;

		ClusterInfo()
			: m_port(0)
		{
		}
		ClusterInfo(const String identifier, const String hostName, const uint16_t port) :
			m_identifier(identifier),
			m_hostName(hostName),
			m_port(port)
		{}

		inline bool operator==(const ClusterInfo& rhs) const
		{
			if (m_identifier == rhs.m_identifier &&
				m_hostName == rhs.m_hostName &&
				m_port == rhs.m_port)
			{
				return true;
			}

			return false;
		}

		inline bool operator<(const ClusterInfo& rhs) const
		{
			// lexicographical order comparison

			if (m_identifier < rhs.m_identifier)
				return true;
			if (m_identifier > rhs.m_identifier)
				return false;

			if (m_hostName < rhs.m_hostName)
				return true;
			if (m_hostName > rhs.m_hostName)
				return false;

			return m_port < rhs.m_port;
		}
	};
}