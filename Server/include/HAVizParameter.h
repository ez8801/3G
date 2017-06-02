/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 149 70 6 217 120 217 88 234 61 209 73 37 67 248  */
#pragma once

#include <stdint.h>

namespace Proud
{
	class HAVizStartParameter
	{
	public:
		// Visualizer 사용시에 해당 값을 true로 설정 해야만 정상 작동 합니다.
		bool m_useVisualizer = false;

		// Visualizer 게이트웨이의 포트 번호입니다.
		uint16_t m_visualizerGatewayPort = 0;
	};
}