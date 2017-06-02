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

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud 
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	/* a,b�� ����Ű�� �ΰ��� int32 �迭�� ��� ���θ� �Ǻ��Ѵ�.
	memcmp(a,b,16)�� ���� ������ �Ѵ�. �ٸ� ũ�Ⱑ ���� ��� �̰��� �� ���� �ӵ��� ���� �̰��� �� ���� �ִ�.
	�迭 ũ�Ⱑ ���ø� ���ڶ� loop unroll ����ȭ�� �̷������.
	#TODO �ƴҼ��� �ִ�. compiler�� �˾Ƽ� 16����Ʈ ���� ũ���
	intrinsic level�� ����ȭ�� �ڵ尡 ���� �� �ִ�.
	�ϴ��� ���������� ������ ���� üũ�ؼ� �� �Լ��� �������� �����ϴ��� ����. */
	template <size_t LENGTH> 
	int CompareInt32Array(const void* a, const void* b)
	{
		const int32_t* a2 = (const int32_t*)a;
		const int32_t* b2 = (const int32_t*)b;
		for (int i = 0; i < LENGTH; i++)
		{
			int c = (*a2) - (*b2);
			if (c != 0)
				return c;
			a2++;
			b2++;
		}
		// ������ �� ���ص� �����ϴ�.
		return 0;
	}

//
//
//	// ���� ũ���� �����Ϳ� ���� memcpy. memcpy ��ü�� ���������� SIMD ����ȭ�� ������ CPU ��Ȳ�̶���� ���������� �˾ƺ��� �ڽ�Ʈ�� ũ��.
//	// ������ ���� ũ��� �̰� �� ����.
//	inline void SmallMemcpy(uint8_t*dst, const uint8_t*src, size_t size)  
//	{
//		static const size_t sizetSize = sizeof(size_t);
//
//		size_t i;
//
//#if defined(_WIN64) || defined(__LP64__)
//		assert(sizetSize == 8);
//		size_t pad = size & 7; // X mod 8�� ���� ����
//		size_t blsize = size >> 3; // X / 8 �� ���� ����
//#else
//		assert(sizetSize == 4);
//		size_t pad = size & 3; // X mod 8�� ���� ����
//		size_t blsize = size >> 2; // X / 8 �� ���� ����
//#endif
//		for (i = 0; i < blsize; i++)
//		{
//			*(size_t*)dst = *(size_t*)src;
//			dst += sizetSize;
//			src += sizetSize;
//		}
//		for (i = 0; i < pad; i++)
//		{
//			*(uint8_t *)dst = *(uint8_t *)src;
//			dst++;
//			src++;
//		}
//	}

	inline void UnsafeFastMemmove(void *dest,const void* src,size_t length)
	{
		// array.add���� length=0�� ��찡 ���.
		if(length==0)
			return;

		// memmove_s�� memcpy_s�� memmove, memcpy���� �ξ� ������. �������� �ٿ�� üũ�� �������� zeromem ó���� �ֱ� �����̴�.
		// ���� �̰� �׳� ����.
		// ���Ŀ��� AMD64,IA64,Itanium,Win32�� ���� ��� ��ƾ�� ���� ����� ���� �� ��������.
		memmove(dest,src,length);
	}

//// sysutil.cpp�� �̰� �� ������ ����Ǿ� ����
//// Steam OS���� �����3���� ũ���� �̽��� ���� Unsafememcopy ��� ��Ȱ��ȭ �ϵ��� USE_UnsafeFastMemcpy define �ּ� ó��
////#define USE_UnsafeFastMemcpy
//
//#ifdef USE_UnsafeFastMemcpy
//
//	inline void UnsafeFastMemcpy(void *dest, const void* src, size_t length)
//	{
//		// array.add���� length=0�� ��찡 ���.
//		if ( length == 0 )
//			return;
//
//#if defined(__MARMALADE__) || defined(__ANDROID__) || defined(__arm__) // RVCT�� ���� ��� __packed keyword�� ���� ������ gcc�� ���Ƿ� 
//		memcpy(dest,src,length);
//		// memmove_s�� memcpy_s�� memmove, memcpy���� �ξ� ������. �������� �ٿ�� üũ�� �������� zeromem ó���� �ֱ� �����̴�.
//		// ���� �̰� �׳� ����.
//		// ���Ŀ��� AMD64,IA64,Itanium,Win32�� ���� ��� ��ƾ�� ���� ����� ���� �� ��������.
//#else
//		if ( length <= 256 ) // 32���� ����. memcpy�� ȣ���ϴ� ������ �����ؼ� ������ �÷���.
//			SmallMemcpy((uint8_t*)dest, (uint8_t*)src, length);
//		else
//			memcpy(dest, src, length);
//#endif
//	}
//
//#else 
//
//#	define UnsafeFastMemcpy memcpy 
//
//#endif
//
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

}

#ifdef _MSC_VER
#pragma pack(pop)
#endif