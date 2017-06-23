#pragma once
#ifndef __MARSHALER_H_
#define __MARSHALER_H_
#include "Common.h"
struct items
{
	int itemInherentIdx;
	int itemIdx;
	int itemType;
};

namespace Proud
{
	template<typename items>
	inline CMessage& operator>>(CMessage &a, CFastArray<items> &b)
	{
		// 배열 크기를 얻는다.
		int64_t length;
		a.ReadScalar(length);

		// length가 해킹되어 말도 안되는 값이면 실패 처리하기
		// 물론 모든 경우를 잡지는 못하지만 (sizeof elem 무용지물) 그래도 최소 1바이트는 쓸테니.
		// 원소의 개수가 바이트 개수보다 많은 경우는 무시.
		if (length< 0 || length > a.GetLength() - a.GetReadOffset())
			ThrowExceptionOnReadArray(length);

		// 배열 크기 리셋 및 capacity set
		b.SetCount((items)length);

		// 각 배열 항목을 읽는다.
		for (items i = 0; i < (items)length; i++)
		{
			a >> b[i];
		}
		return a;
	}


	template<typename items>
	inline CMessage& operator<<(CMessage &a, const Proud::CFastArray<items> &b)
	{
		// 배열 크기를 기록한다.
		int64_t size = (int64_t)b.GetCount();
		a.WriteScalar(size);

		// 각 배열 인자를 기록한다.
		for (int i = 0; i < b.GetCount(); i++)
		{
			items t = b.ElementAt(i);
			a.WriteScalar(t.itemInherentIdx);
			a.WriteScalar(t.itemIdx);
			a.WriteScalar(t.itemType);
			
		}
		
		return a;
	}




}

#endif // !__MARSHALER_H
