/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once

#include "ProcHeap.h"

namespace Proud
{
	/* Type�� ����Ű�� ��ü Ÿ�� ��ü�� ���� Ư¡�� ������ �Ѵ�.
	- ��ü ��ü�� ����Ʈ ������ Ÿ���� �ǰ� �Ѵ�. �� ���� ����� ������ �Ѵ�.
	- ��ü�� ������ ���� ��ü(substance)�� class level�� ���� object pool���� ����ǰ� �Ѵ�. �� ��ü ����/�Ҵ� ����� ������ �� �ְ� ���ش�.

	���ǻ���: ���� �ʱ�ȭ�� ���� ������ü�� ����ȴٴ� ���� ������, ��� �������� �������� �� �ִ�. �� �ʿ�� ��� �������� ���� û���� �־�� �Ѵ�.
	Type�� Clear(), SuspendShrink()�� ������ �Ѵ�. �ƹ��͵� ���ϴ���.
	���� ����ڴ� ���� ��� �Ұ����� Ŭ����. src/ �ȿ����� ����. */
	template<typename Type, bool ClearOnDrop>
	class BiasManagedPointer
	{
	public:
		// ���� ī��Ʈ�� ��ü ��ü�� �� �޸� ���� ��� ������.
		class Tombstone
		{
		public:
			// ���� ������ ��ü
			Type m_substance;

			// ���� ī��Ʈ
			volatile intptr_t m_refCount;

			inline Tombstone()
			{
				m_refCount = 0;
			}

			// �迭 ���̳� ���� �ִ� ���۰� ���Ƶ��� ���̴� ����� �����Ѵ�.
			void SuspendShrink()
			{
				m_substance.SuspendShrink();
			}
			void OnRecycle() {}
			void OnDrop()
			{
				m_substance.OnDrop();
			}


			DECLARE_NEW_AND_DELETE
		};

	private:
		// refcount�� Type ��ü�� ������ ��ü.
		Tombstone* m_tombstone;

		//////////////////////////////////////////////////////////////////////////
		// src/ �ȿ��� ������. ��� ���Ͽ� ���� ����. 

		static Tombstone* AllocTombstone();
		static void FreeTombstone(Tombstone* tombstone);

		//////////////////////////////////////////////////////////////////////////

	protected:
		// �Ļ� Ŭ���� �ȿ��� ��ü�� �׼����� �� ���δ�.
		inline Tombstone* GetTombstone() const
		{
			return m_tombstone;
		}

	public:
		inline BiasManagedPointer()
			: m_tombstone(NULL)  // ó������ Tombstone ��ü�� ����. ������� ����ڰ� InitTombstoneIfEmpty()�� �� �ؾ� �Ѵ�.
		{
		}

		// ���� ������
		inline BiasManagedPointer(const BiasManagedPointer& src)
		{
			// src�� tombstone�� �����Ѵ�.
			if (src.m_tombstone)
			{
				AtomicIncrementPtr(&src.m_tombstone->m_refCount);
				m_tombstone = src.m_tombstone;
			}
			else
				m_tombstone = NULL;
		}

#ifdef SUPPORTS_CPP11
		// �̵� ������
		inline BiasManagedPointer(BiasManagedPointer&& src)
		{
			if (src.m_tombstone)
			{
				// smart ptr�̹Ƿ� �̵� �����ڰ� �� �δ�.
				m_tombstone = src.m_tombstone;
				// �̵� �������̹Ƿ�, src�� ��� ������.
				src.m_tombstone = NULL;
			}
			else
				m_tombstone = NULL;
		}
#endif

		// ���� ������
		inline BiasManagedPointer& operator=(const BiasManagedPointer& src)
		{
			if (src.m_tombstone != m_tombstone)
			{
				UninitTombstone(); // ���� �� ����

				if (src.m_tombstone != NULL)
				{
					AtomicIncrementPtr(&src.m_tombstone->m_refCount);
					m_tombstone = src.m_tombstone;
				}
			}

			return *this;
		}

#ifdef SUPPORTS_CPP11
		// �̵� ������
		inline BiasManagedPointer& operator=(BiasManagedPointer&& src)
		{
			if (&src != this)
			{
				UninitTombstone(); // ���� �� ����

				// ������ �̾�
				m_tombstone = src.m_tombstone;
				// src�� ��� ������.
				src.m_tombstone = NULL;
			}

			return *this;
		}
#endif

		inline ~BiasManagedPointer()
		{
			UninitTombstone(); 
		}

	protected:
		// Tombstone�� ������ �ʱ� ���·� ����.
		inline void UninitTombstone()
		{
			if (m_tombstone)
			{
				// ���۷��� ī��Ʈ ���̰� 0�� �Ǹ�
				if (AtomicDecrementPtr(&m_tombstone->m_refCount) == 0)
				{
					// ��û�Ͽ� ���빰 û��
					if(ClearOnDrop)
						m_tombstone->m_substance.Clear();

					// obj-pool�� ��ȯ
					FreeTombstone(m_tombstone);
				}
				m_tombstone = NULL;
			}
		}

		// Tombstone�� �Ҵ��Ѵ�. �̹� ���� ������ skip.
		// Tombstone �Ҵ��̶� ����, Type subtance ��ü�� �� �������� �ǹ��Ѵ�.
		// ����, object-pool���� �����´�.
		inline void InitTombstoneIfEmpty()
		{
			if(!m_tombstone)
			{
				m_tombstone = AllocTombstone();
				m_tombstone->SuspendShrink();
				m_tombstone->m_refCount = 1;
			}
		}
	};
}

#include "BiasManagedPointer.inl"
