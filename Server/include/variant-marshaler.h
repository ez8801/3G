/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once 

#include "Variant.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	class CMessage;
	class CVariant;

#if defined(_WIN32)    
	CMessage& operator<<(CMessage &a, const CVariant &b);
	CMessage& operator>>(CMessage &a, CVariant &b);

	void AppendTextOut(String &a, const CVariant &b);
#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif