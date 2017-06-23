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
		// �迭 ũ�⸦ ��´�.
		int64_t length;
		a.ReadScalar(length);

		// length�� ��ŷ�Ǿ� ���� �ȵǴ� ���̸� ���� ó���ϱ�
		// ���� ��� ��츦 ������ �������� (sizeof elem ��������) �׷��� �ּ� 1����Ʈ�� ���״�.
		// ������ ������ ����Ʈ �������� ���� ���� ����.
		if (length< 0 || length > a.GetLength() - a.GetReadOffset())
			ThrowExceptionOnReadArray(length);

		// �迭 ũ�� ���� �� capacity set
		b.SetCount((items)length);

		// �� �迭 �׸��� �д´�.
		for (items i = 0; i < (items)length; i++)
		{
			a >> b[i];
		}
		return a;
	}


	template<typename items>
	inline CMessage& operator<<(CMessage &a, const Proud::CFastArray<items> &b)
	{
		// �迭 ũ�⸦ ����Ѵ�.
		int64_t size = (int64_t)b.GetCount();
		a.WriteScalar(size);

		// �� �迭 ���ڸ� ����Ѵ�.
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
