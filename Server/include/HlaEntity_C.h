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

#include "HlaDef.h"
#include "FastMap.h" 

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud 
{
	class CHlaSessionHostImpl_C;
	class CMessage;
	class CHlaEntityInternal_C;

	class CHlaEntity_C
	{
		friend class CHlaSessionHostImpl_C;

		CHlaEntityInternal_C* m_internal;
	public:
		CHlaEntity_C();
		virtual ~CHlaEntity_C();

		// ����ڴ� �մ��� �� ��
		void SetDirty_INTERNAL();
		void SetClassID_INTERNAL( HlaClassID val );

		HlaEntityID GetInstanceID();

		virtual void DeserializeAppear(CMessage& input)  = 0;
		virtual void DeserializeNotifyChange(CMessage& input)  = 0;
	};

	typedef CFastMap<HlaEntityID, CHlaEntity_C*> CHlaEntities_C;

	class CHlaEntityManagerBase_C
	{
	public:
		CHlaSessionHostImpl_C* m_ownerHost;

		CHlaEntityManagerBase_C() 
		{
			m_ownerHost = NULL;
		}
		virtual CHlaEntity_C* CreateEntityByClassID(HlaClassID classID) = 0;
		virtual HlaClassID GetFirstEntityClassID() = 0;
		virtual HlaClassID GetLastEntityClassID() = 0;
	};
}
#ifdef _MSC_VER
#pragma pack(pop)
#endif