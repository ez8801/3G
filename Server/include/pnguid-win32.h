/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once 

#include "pnguid.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#if defined(_WIN32) 

// 주의: UE4 project에서는 include하지 말 것! 빌드 오류난다.
#pragma comment(lib,"rpcrt4.lib")
#pragma comment(lib,"winmm.lib")


namespace Proud
{
	/** helper functions for win32 GUID to Proud.Guid. */
	class Win32Guid
	{
	public:
		/** creates a new unique ID. */
		PROUD_API static Guid NewGuid();

		/** gets data from Win32 UUID data. */
		static Guid From(UUID src);

		/** outputs Win32 UUID data. */
		static UUID ToNative(Guid src);
	};
}

#endif // _WIN32
#ifdef _MSC_VER
#pragma pack(pop)
#endif