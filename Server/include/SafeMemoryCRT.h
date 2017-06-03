/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once

#ifdef _WIN32
#error This header file is NOT for Win32 platform
#endif

#include <stdio.h>
#include <stdarg.h>
#include <time.h>



namespace Proud
{
#if !defined(__ORBIS__)
	// #ikpil.choi, 2016-12-28 : memcpy_s ������ ����
	// �ý�4 ����
	inline errno_t memcpy_s(void *dest, size_t dest_size, const void* src, size_t src_size)
	{
		errno_t err = 0;

		// ���� ���/�ҽ��� ���� ���
		if (0 == dest || 0 == src)
			return EINVAL;

		// ���� ����� �ִ밪�� size_t / 2 ������
		const size_t max_value = (SIZE_MAX >> 1);

		// ����� ����� �ִ밪�� �Ѿ��ٸ�, ����� ����� �߸� �Ȱ����� �Ǵ�, ������ ����
		if (dest_size > max_value)
			return E2BIG;

		// �ҽ��� ����� �ִ밪���� ũ�ٸ�, �ʹ� ū �������� ��� ������� ����
		if (src_size > max_value)
		{
			err = E2BIG;
			src_size = dest_size;
		}

		// �ҽ� ����� ��� ������� ũ�ٸ�, �����÷ο� ���� �� ��� ������� ����
		if (src_size > dest_size)
		{
			err = EOVERFLOW;
			src_size = dest_size;
		}

		memcpy(dest, src, src_size);
		return err;
	}
#endif

	template <size_t _Size>
	inline int sprintf_s(char(&_Dst)[_Size], const char *_TArg1, ...)
	{
		va_list _ArgList;
		va_start(_ArgList, _TArg1);

		int ret = vsnprintf(_Dst, _Size, _TArg1, _ArgList);

		va_end(_ArgList);
		return ret;
	}

	inline int sprintf_s(char *_Dst, size_t _Size, const char *_TArg1, ...)
	{
		va_list _ArgList;
		va_start(_ArgList, _TArg1);

		int ret = vsnprintf(_Dst, _Size, _TArg1, _ArgList);

		va_end(_ArgList);
		return ret;
	}

	template <size_t _Size>
	inline int _snscanf_s(char (&_Dst)[_Size], const char *_TArg1, ...)
	{
		va_list _ArgList;
		va_start(_ArgList, _TArg1);
		return vsscanf(_Dst, _TArg1, _ArgList);
	}

	inline int _snscanf_s(char *_Dst, size_t _Size, const char *_TArg1, ...)
	{
		va_list _ArgList;
		va_start(_ArgList, _TArg1);

		int ret = vsscanf(_Dst, _TArg1, _ArgList);

		va_end(_ArgList);
		return ret;
	}

	template <size_t _Size>
	inline errno_t strcpy_s(char(&_Dst)[_Size], const char *_Src)
	{
		strncpy(_Dst, _Src, _Size);
		// �Է¹��� ������ �� �� �����Ϳ� �Ϻη� ǥ���� ����, ���� ������ ���� �߰��Ѵ�.
		// �� ���� ���� sigabort���� ���� �������� �ϴ��� �̷��� ����.
		// �Ʒ� �Լ��鵵 ��������.
		_Dst[_Size - 1] = '\0';
		return 0;
	}

	inline errno_t strcpy_s(char *_Dst, size_t _Size, const char *_Src)
	{
		strncpy(_Dst, _Src, _Size);
		_Dst[_Size - 1] = '\0';
		return 0;
	}

	template <size_t _Size>
	inline errno_t strncpy_s(char(&_Dst)[_Size], const char *_Src, size_t _MaxCount)
	{
		strncpy(_Dst, _Src, PNMIN(_Size, _MaxCount));
		_Dst[_Size - 1] = '\0';
		return 0;
	}

	inline errno_t strncpy_s(char *_Dst, size_t _Size, const char *_Src, size_t _MaxCount)
	{
		strncpy(_Dst, _Src, PNMIN(_Size, _MaxCount));
		_Dst[_Size - 1] = '\0';
		return 0;
	}


	template <size_t _Size>
	inline errno_t wcscpy_s(wchar_t(&_Dst)[_Size], const wchar_t *_Src)
	{
		wcsncpy(_Dst, _Src, _Size);
		_Dst[_Size - 1] = '\0';
		return 0;
	}

	inline errno_t wcscpy_s(wchar_t *_Dst, size_t _Size, const wchar_t *_Src)
	{
		wcsncpy(_Dst, _Src, _Size);
		_Dst[_Size - 1] = '\0';
		return 0;
	}

	template <size_t _Size>
	inline errno_t wcsncpy_s(wchar_t(&_Dst)[_Size], const wchar_t *_Src, size_t _MaxCount)
	{
		wcsncpy(_Dst, _Src, PNMIN(_Size, _MaxCount));
		_Dst[_Size - 1] = '\0';
		return 0;
	}

	inline errno_t wcsncpy_s(wchar_t *_Dst, size_t _Size, const wchar_t *_Src, size_t _MaxCount)
	{
		wcsncpy(_Dst, _Src, PNMIN(_Size, _MaxCount));
		_Dst[_Size - 1] = '\0';
		return 0;
	}

	inline int vprintf_s(char const* const _Format, va_list _ArgList)
	{
		return vprintf(_Format, _ArgList);
	}

	inline int vwprintf_s(wchar_t const* const _Format, va_list _ArgList)
	{
		return vwprintf(_Format, _ArgList);
	}



	template <size_t _Size>
	inline errno_t _tcscpy_s(wchar_t(&_Dst)[_Size], const wchar_t *_Src)
	{
		return wcscpy_s(_Dst, _Src);
	}

	template <size_t _Size>
	inline errno_t _tcscpy_s(char(&_Dst)[_Size], const char*_Src)
	{
		return strcpy_s(_Dst, _Src);
	}

	// #ikpil.choi 2017-02-20 : ũ�ν� �÷����� ���� wcsftime ���� �Լ�
	inline size_t _tcsftime(wchar_t *_Buf, size_t _SizeInWords, const wchar_t * _Format, const struct tm * _Tm)
	{
		return wcsftime(_Buf, _SizeInWords, _Format, _Tm);
	}

	// #ikpil.choi 2017-02-20 : ũ�ν� �÷����� ���� strftime ���� �Լ�
	inline size_t _tcsftime(char*_Buf, size_t _SizeInWords, const char * _Format, const struct tm * _Tm)
	{
		return strftime(_Buf, _SizeInWords, _Format, _Tm);
	}

	inline int _tprintf_s(const char * _Format, ...)
	{
		va_list _ArgList;
		va_start(_ArgList, _Format);

		int ret = vprintf_s(_Format, _ArgList);

		va_end(_ArgList);

		return ret;
	}

	inline int _tprintf_s(const wchar_t * _Format, ...)
	{
		va_list _ArgList;
		va_start(_ArgList, _Format);

		int ret = vwprintf_s(_Format, _ArgList);

		va_end(_ArgList);

		return ret;
	}

	
}
