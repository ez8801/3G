/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once 

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

/** ������, �ı��ڸ� ��������� ȣ���ϴ� �Լ���.
Container class�� ������ �� �ַ� ���ȴ�. */

template< typename T >
void CallConstructor(T* pInstance)
{
#ifndef __MARMALADE__
#pragma push_macro("new")
#undef new
#endif

	::new(pInstance)T();

#ifndef __MARMALADE__
#pragma pop_macro("new")
#endif // __MARMALADE__
};

// ���� �����ڸ� ȣ���Ѵ�.
template< typename T, typename Src >
void CallConstructor(T* pInstance, const Src& src)
{
#ifndef __MARMALADE__
#pragma push_macro("new")
#undef new
#endif // __MARMALADE__

	::new(pInstance)T(src);

#ifndef __MARMALADE__
#pragma pop_macro("new")
#endif // __MARMALADE__
};

// ����: �ݵ��!! �Լ� ���� <T>�� ����ϰ� ���� ��. �Ϻ� �����Ϸ��� ������ ���� ���ø� �ν��Ͻ�ȭ�Ѵ�.
template< typename T, typename Src, typename Src1 >
void CallConstructor(T* pInstance, const Src& src, const Src1 src1)
{
#ifndef __MARMALADE__
#pragma push_macro("new")
#undef new
#endif // __MARMALADE__

	::new(pInstance)T(src, src1);

#ifndef __MARMALADE__
#pragma pop_macro("new")
#endif // __MARMALADE__
};

// ����: �ݵ��!! �Լ� ���� <T>�� ����ϰ� ���� ��. �Ϻ� �����Ϸ��� ������ ���� ���ø� �ν��Ͻ�ȭ�Ѵ�.
template< typename T >
void CallDestructor(T* pInstance)
{
	pInstance->T::~T();
};

#ifndef __MARMALADE__
#pragma push_macro("new")
#undef new
#endif // __MARMALADE__

// ����: �ݵ��!! �Լ� ���� <T>�� ����ϰ� ���� ��. �Ϻ� �����Ϸ��� ������ ���� ���ø� �ν��Ͻ�ȭ�Ѵ�.
template< typename T >
static inline void CallConstructors(T* pElements, intptr_t nElements)
{
	int iElement = 0;

	//	try
	//	{
	for (iElement = 0; iElement < nElements; iElement++)
	{
		::new(pElements + iElement) T;

	}
	//	}
	// 	catch(...)
	// 	{
	// 		while( iElement > 0 )
	// 		{
	// 			iElement--;
	// 			pElements[iElement].~T();
	// 		}
	// 
	// 		throw;
	// 	}
}

// ����: �ݵ��!! �Լ� ���� <T>�� ����ϰ� ���� ��. �Ϻ� �����Ϸ��� ������ ���� ���ø� �ν��Ͻ�ȭ�Ѵ�.
template< typename T >
static inline void CallCopyConstructors(T* pElements, const T* pOldElements, intptr_t nElements)
{
	int iElement = 0;

	for (iElement = 0; iElement < nElements; iElement++)
	{
		::new(pElements + iElement) T(pOldElements[iElement]);
	}
}


// ����: �ݵ��!! �Լ� ���� <T>�� ����ϰ� ���� ��. �Ϻ� �����Ϸ��� ������ ���� ���ø� �ν��Ͻ�ȭ�Ѵ�.
template< typename T >
static inline void CallDestructors(T* pElements, intptr_t nElements) throw()
{
	(void)pElements;

	for (int iElement = 0; iElement < nElements; iElement++)
	{
		pElements[iElement].~T();
	}
}
#ifndef __MARMALADE__
#pragma pop_macro("new")
#endif // __MARMALADE__

#ifdef _MSC_VER
#pragma pack(pop)
#endif