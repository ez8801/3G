/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


�� ���α׷��� ���۱��� ���ټǿ��� �ֽ��ϴ�.
�� ���α׷��� ����, ���, ������ ���õ� ������ �� ���α׷��� �������ڿ��� ����� ������,
����� �ؼ����� �ʴ� ��� ��Ģ������ ���� ����� �����մϴ�.
���� ��뿡 ���� å���� �� ���α׷��� �������ڿ��� ��༭�� ��õǾ� �ֽ��ϴ�.

** ���� : ���۹��� ���� ���� ��ø� �������� ���ʽÿ�.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


���������??Nettention�������
?����������ǡ����ġ�?����?����?���������������?���??��
������???��?�������������ġ�
���������?��٥���?��������?�������?�졣

** ��������?�����ڪ��߾��٥�ơ�


���Ϋ׫���������?��Nettention�˪���ު���
���Ϋ׫��������ᡢ���ġ����֪�?������������׫��������?�Ȫ���峪�?����
��峪��������ʪ����ꡢ����ܪ���?���Ī��ת��ު���
��?���Ī˪���������׫��������?�Ȫ��������٥�ƪ���ƪ��ު���

** �������ڪ��?����߾����٥�ƪ���۪��ʪ��Ǫ���������

*/

#pragma once 

#include "PNString.h"
#if !defined(_WIN32)
#include "BasicTypes.h"
#endif
#include <time.h>

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#ifdef _WIN32
// ���� �����̶� #include <oledb.h>�� include�� �� ���� ȯ�� ������ ���� ���� �Ѵ�.
struct tagDBTIMESTAMP;
typedef tagDBTIMESTAMP DBTIMESTAMP;
#endif // _WIN32



// #ikpil.choi 2017-02-17 : Visual Studio 2015 �̻���� timespec ����, �� ���ϴ� ���� ���ϹǷ�, ������ ����
#if defined(_WIN32) && !defined(_CRT_NO_TIME_T) && (1900 > _MSC_VER)
struct timespec
{
	time_t tv_sec;  // Seconds - >= 0
	long   tv_nsec; // Nanoseconds - [0, 999999999]
};
#endif

namespace Proud
{
	// #ikpil.choi 2017-02-17 : timespec_get �� �ʿ� define, ũ�ν� �÷��� �������� ����Ǿ� ���� ������, �����մϴ�.
#ifndef TIME_UTC
	enum
	{
		// #ikpil.choi 2017-03-03 : �ٸ������� TIME_UTC �� ������ �� �� �����Ƿ�, enum���� ����
		TIME_UTC = 1
	};
#endif
	/**
	\~korean
	\brief localtime_s �� ũ�ν� �÷������� �����ϱ� ���� �Լ�.
	\param[in]  time tm���� �ٲٱ� ���� utc ������ time_t ������ ����
	\param[out] t    tm ���ڷ� ���� time�� tm���� ����ϴ� ����

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/
	errno_t localtime_pn(const ::time_t* time, ::tm* t);

	/**
	\~korean
	\brief gmtime_s �� ũ�ν� �÷������� �����ϱ� ���� �Լ�.
	\param[in]  time tm���� �ٲٱ� ���� utc ������ time_t ������ ����
	\param[out] t    tm ���ڷ� ���� time�� tm���� ����ϴ� ����

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/
	errno_t gmtime_pn(const ::time_t* time, ::tm* t);

	/**
	\~korean
	\brief timespec_get �� ũ�ν� �÷������� �����ϱ� ���� �Լ�.
	\param[out] tp   ��µ� timespec ����ü
	\param[in]  base TIME_UTC �Ǵ� Ÿ�Ӻ��̽��� ��Ÿ���� �ٸ� 0�� �ƴ� ���� �� (����� TIME_UTC�� ������)

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/
	int timespec_get_pn(::timespec *tp, int const base);

	/**
	\~korean
	\brief struct timespec�� ���뼼����� �ٲٴ� �Լ�
	\param[in] ts ���뼼��Ʈ�� ��ȯ��ų struct timespec

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/
	long long timespec_to_nanosecond(const ::timespec& ts);

	/**
	\~korean
	\brief ���뼼���带 struct timespec���� �ٲٴ� �Լ�
	\param[in]  ns struct timespec ���� �ٲ� ���뼼����
	\param[out] tp ��µ� struct timespec

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/
	int nanosecond_to_timespec(const long long& ns, timespec *tp);

	/**
	\~korean
	\brief struct timespec�� �и�������� �ٲٴ� �Խ�
	\param[in] ts �и�������� �ٲ� struct timespec

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/
	long long timespec_to_millisecond(const ::timespec& ts);

	/**
	\~korean
	\brief �и������带 struct timespec���� �ٲٴ� �Լ�
	\param[in] ts �и�������� �ٲ� struct timespec

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/

	int millisecond_to_timespec(const long long& ms, timespec *tp);

	/**
	\~korean
	\brief UTC �������� ���� �ӽ��� ���뼼���带 ��ȯ�ϴ� �Լ�

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/
	long long GetCurrentTimeNanoSecond();

	/**
	\~korean
	\brief UTC �������� ���� �ӽ��� �и������带 ��ȯ�ϴ� �Լ�

	\~english
	\brief

	\~chinese
	\brief

	\~japanese
	\brief

	\~
	*/

	long long GetCurrentTimeMilliSecond();
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
