#pragma once
//마샬링을 위한 헤더
//기존에 ProudNet에 선언된 오퍼레이션 말고
//사용자 정의 데이터 타입에 대한
//오퍼레이션 오버로딩을 할 때 사용
//현재 items struct에 대한 정보만 마샬링중
//작성자 -- 이승준
#ifndef __MARSHALER_H_
#define __MARSHALER_H_
#include "Common.h"
struct equipinfo
{
	int equipslot1;
	int equipslot2;
	int equipslot3;
	int equipslot4;
	int equipslot5;
	int equipslot6;
	/*int ActiveSkill_1_idx;
	int ActiveSkill_2_idx;
	int ActiveSkill_3_idx;
	int ActiveSkill_4_idx;
	int PassiveSkill_1_idx;
	int PassiveSkill_2_idx;
	int PassiveSkill_3_idx;
	int PassiveSkill_4_idx;*/
};
struct passiveskillinfo
{
	int passiveSlot1;
	int passiveSlot2;
	int passiveSlot3;
	int passiveSlot4;
};
struct items
{
	int inId;
	int itemIdx;
	int count;
};

struct raidrooms
{
	int hostId;
	int groupId;
	int curCrew;
};
struct pvprooms
{
	int roomId;
	int hostId;
	String hostname;
	int groupId;
	String pvproomname;
};
struct battleinfo
{
	int curA;
	int totalA;
	int curB;
	int totalB;
};

namespace Proud
{

	

	inline CMessage& operator>>(CMessage &a, items &b)
	{
		a.ReadScalar(b.inId);
		a.ReadScalar(b.itemIdx); 
		a.ReadScalar(b.count);
		return a;
	}

	inline CMessage& operator<<(CMessage &a, const Proud::CFastArray<items> &b)
	{
		// 배열 크기를 기록한다.
		int64_t size = (int64_t)b.GetCount();
		a.WriteScalar(size);

		// 각 배열 인자를 기록한다.
		for (int i = 0; i < b.GetCount(); i++)
		{
			items t = b.ElementAt(i);
			a.WriteScalar(t.inId);
			a.WriteScalar(t.itemIdx);
			a.WriteScalar(t.count);
			
		}
		
		return a;
	}

	inline CMessage& operator>>(CMessage &a, passiveskillinfo &b)
	{
		a.ReadScalar(b.passiveSlot1);
		a.ReadScalar(b.passiveSlot2);
		a.ReadScalar(b.passiveSlot3);
		a.ReadScalar(b.passiveSlot4);
		return a;
	}

	inline CMessage& operator<<(CMessage &a, const Proud::CFastArray<passiveskillinfo> &b)
	{
		// 배열 크기를 기록한다.
		int64_t size = (int64_t)b.GetCount();
		a.WriteScalar(size);

		// 각 배열 인자를 기록한다.
		for (int i = 0; i < b.GetCount(); i++)
		{
			passiveskillinfo t = b.ElementAt(i);
			a.WriteScalar(t.passiveSlot1);
			a.WriteScalar(t.passiveSlot2);
			a.WriteScalar(t.passiveSlot3);
			a.WriteScalar(t.passiveSlot4);

		}

		return a;
	}

	inline CMessage& operator>>(CMessage &a, equipinfo &b)
	{
		a.ReadScalar(b.equipslot1);
		a.ReadScalar(b.equipslot2);
		a.ReadScalar(b.equipslot3);
		a.ReadScalar(b.equipslot4);
		a.ReadScalar(b.equipslot5);
		a.ReadScalar(b.equipslot6);
		/*a.ReadScalar(b.ActiveSkill_1_idx);
		a.ReadScalar(b.ActiveSkill_2_idx);
		a.ReadScalar(b.ActiveSkill_3_idx);
		a.ReadScalar(b.ActiveSkill_4_idx);
		a.ReadScalar(b.PassiveSkill_1_idx);
		a.ReadScalar(b.PassiveSkill_2_idx);
		a.ReadScalar(b.PassiveSkill_3_idx);
		a.ReadScalar(b.PassiveSkill_4_idx);*/
		return a;
	}

	inline CMessage& operator<<(CMessage &a, const Proud::CFastArray<equipinfo> &b)
	{
		// 배열 크기를 기록한다.
		int64_t size = (int64_t)b.GetCount();
		a.WriteScalar(size);

		// 각 배열 인자를 기록한다.
		for (int i = 0; i < b.GetCount(); i++)
		{
			equipinfo t = b.ElementAt(i);
			a.WriteScalar(t.equipslot1);
			a.WriteScalar(t.equipslot2);
			a.WriteScalar(t.equipslot3);
			a.WriteScalar(t.equipslot4);
			a.WriteScalar(t.equipslot5);
			a.WriteScalar(t.equipslot6);
			/*a.WriteScalar(t.ActiveSkill_1_idx);
			a.WriteScalar(t.ActiveSkill_2_idx);
			a.WriteScalar(t.ActiveSkill_3_idx);
			a.WriteScalar(t.ActiveSkill_4_idx);
			a.WriteScalar(t.PassiveSkill_1_idx);
			a.WriteScalar(t.PassiveSkill_2_idx);
			a.WriteScalar(t.PassiveSkill_3_idx);
			a.WriteScalar(t.PassiveSkill_4_idx);*/

		}

		return a;
	}


	
	inline CMessage& operator>>(CMessage &a, raidrooms &b)
	{
		a.ReadScalar(b.hostId); 
		a.ReadScalar(b.groupId); 
		a.ReadScalar(b.curCrew);
		return a;
	}

	inline CMessage& operator>>(CMessage &a, pvprooms &b)
	{
		a.ReadScalar(b.roomId);
		a.ReadScalar(b.hostId);
		a.ReadString(b.hostname);
		a.ReadScalar(b.groupId);
		a.ReadString(b.pvproomname);
		return a;
	}
	inline CMessage& operator<<(CMessage &a, const Proud::CFastArray<pvprooms> &b)
	{
		// 배열 크기를 기록한다.
		int64_t size = (int64_t)b.GetCount();
		a.WriteScalar(size);

		// 각 배열 인자를 기록한다.
		for (int i = 0; i < b.GetCount(); i++)
		{
			pvprooms t = b.ElementAt(i);
			a.WriteScalar(t.roomId);
			a.WriteScalar(t.hostId);
			a.WriteString(t.hostname);
			a.WriteScalar(t.groupId);
			a.WriteString(t.pvproomname);
		}

		return a;
	}

	inline CMessage& operator<<(CMessage &a, const Proud::CFastArray<raidrooms> &b)
	{
		// 배열 크기를 기록한다.
		int64_t size = (int64_t)b.GetCount();
		a.WriteScalar(size);

		// 각 배열 인자를 기록한다.
		for (int i = 0; i < b.GetCount(); i++)
		{
			raidrooms t = b.ElementAt(i);
			a.WriteScalar(t.hostId);
			a.WriteScalar(t.groupId);
			a.WriteScalar(t.curCrew);

		}

		return a;
	}

	inline CMessage& operator>>(CMessage &a, battleinfo &b)
	{
		a.ReadScalar(b.curA);
		a.ReadScalar(b.totalA);
		a.ReadScalar(b.curB);
		a.ReadScalar(b.totalB);
		return a;
	}

	inline CMessage& operator<<(CMessage &a, const Proud::CFastArray<battleinfo> &b)
	{
		// 배열 크기를 기록한다.
		int64_t size = (int64_t)b.GetCount();
		a.WriteScalar(size);

		// 각 배열 인자를 기록한다.
		for (int i = 0; i < b.GetCount(); i++)
		{
			battleinfo t = b.ElementAt(i);
			a.WriteScalar(t.curA);
			a.WriteScalar(t.totalA);
			a.WriteScalar(t.curB);
			a.WriteScalar(t.totalB);

		}

		return a;
	}

}

#endif // !__MARSHALER_H
