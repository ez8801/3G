/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once

#include <iostream>
#include <errno.h> // for clang

typedef int errno_t;

namespace Proud
{
	template <typename T>
	inline void SafeDelete(T *&p)
	{
		delete p;
		p = static_cast<T *>(0); // for c++03
	}

	template <typename T>
	inline void SafeDeleteArray(T *&p)
	{
		delete[] p;
		p = static_cast<T *>(0); // for c++03
	}

	template <typename T, size_t N>
	inline size_t ArraySize(T (&)[N])
	{
		return N;
	}

	template <typename T, size_t N>
	inline size_t ArrayByteSize(T (&)[N])
	{
		return sizeof(T) * N;
	}
}

// #ikpil.choi 2016-12-28, memset_s 
inline errno_t memset_s(void *dest, size_t dest_size, int c, size_t n)
{
	errno_t err = 0;

	if (dest == 0)
		return EINVAL;

	// ���� ����� �ִ밪�� size_t / 2 ������
	const size_t max_value = (SIZE_MAX >> 1);

	// ����� ����� �ִ밪�� �Ѿ��� ���, ������ �����Ƿ�, ����
	if (dest_size > max_value)
		return E2BIG;

	// ä���� �� ����� �ִ밪�� �ʰ� ���� ���, ��� ������� ����, ���� ����
	if (n > max_value) 
	{
		err = E2BIG;
		n = dest_size;
	}

	// ä���� �� ����Ʈ�� ��� ������� Ŭ ���, ��� ������� ����, ���� ����
	if (n > dest_size) 
	{
		err = EOVERFLOW;
		n = dest_size;
	}

	memset(dest, c, n);

	return err;
}

#if !defined(WIN32)
#include "SafeMemoryCRT.h"
#endif

