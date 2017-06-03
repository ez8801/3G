/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once

#include <functional>
#include <vector>
#include <Psapi.h>
#include "CriticalSect.h"

namespace Proud
{
	class UserServerStatus
	{
	public:
		double UsageCPU;
		size_t UsageMemory;
		size_t ConnectionCount;
		std::string ExStatus;
	};

	class IUserServer
	{
	public:
		virtual void OnStart() = 0;
		virtual void OnStop() = 0;
		virtual void GetStatus(UserServerStatus* outStatus) = 0;

		virtual ~IUserServer() {}
	};

	class UserServer : public IUserServer
	{
	private:
		std::string m_status;
		double m_oldTime;
		__int64 m_iOldKernelTime = 0;
		__int64 m_iOldUserTime = 0;

	protected:
		std::vector<std::string> m_args;

	public:
		UserServer(const std::vector<std::string>* args) :
			m_args(*args),
			m_oldTime(GetBaseTime()),
			m_iOldKernelTime(0),
			m_iOldUserTime(0)
		{
			GetUsageCPU();
		}

		virtual ~UserServer()
		{
			m_status = "";
			m_args.clear();
		}

		size_t GetProcessUsageMemory()
		{
			PROCESS_MEMORY_COUNTERS pmc;
			if (!GetProcessMemoryInfo(GetCurrentProcess(), &pmc, sizeof(pmc))) {
				return 0;
			}
			return pmc.WorkingSetSize;
		}

		double GetUsageCPU()
		{
			double ret;

			if (GetUsageCPU(ret))
			{
				return ret;
			}
			return 0;
		}

		virtual void OnStart() = 0;
		virtual void OnStop() = 0;
		virtual void GetStatus(UserServerStatus* outStatus) = 0;

	private:
		double GetBaseTime(void)
		{
			LARGE_INTEGER liEndCounter, liFrequency;
			QueryPerformanceCounter(&liEndCounter);
			QueryPerformanceFrequency(&liFrequency);

			return (liEndCounter.QuadPart / (double)liFrequency.QuadPart) * 1000;
		}

		bool GetUsageCPU(double &dShare)
		{
			LARGE_INTEGER  iCreationTime, iExitTime, iKernelTime, iUserTime;

			bool ret = false;

			if (GetProcessTimes(GetCurrentProcess(), (LPFILETIME)&iCreationTime, (LPFILETIME)&iExitTime
				, (LPFILETIME)&iKernelTime, (LPFILETIME)&iUserTime) == TRUE)
			{
				if (m_iOldKernelTime > 0)
				{
					__int64 sum = iKernelTime.QuadPart - m_iOldKernelTime + iUserTime.QuadPart - m_iOldUserTime;
					sum /= 10000; // 100 nano sec 단위에서 msec 단위로 변환

					if (sum && GetBaseTime() - m_oldTime > 0)
					{
						dShare = sum / (GetBaseTime() - m_oldTime) * 100.0;

						SYSTEM_INFO Info;
						GetSystemInfo(&Info);

						dShare /= Info.dwNumberOfProcessors;

						ret = true;
					}
				}

				m_iOldKernelTime = iKernelTime.QuadPart;
				m_iOldUserTime = iUserTime.QuadPart;
				m_oldTime = GetBaseTime();
			}

			return ret;
		}
	};

	typedef UserServer* (CALLBACK* CreateUserServerFuncType)(const std::vector<std::string>* args);
	typedef void (CALLBACK* DestroyUserServerFuncType)(UserServer* userServer);
}
