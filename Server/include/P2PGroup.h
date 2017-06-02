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

#include "BasicTypes.h"
#include "HostIDArray.h"
#include "Ptr.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif
	/** \addtogroup net_group
	*  @{
	*/

	class CP2PGroup;
	typedef RefCount<CP2PGroup> CP2PGroupPtr;

	/** 
	\~korean
	P2P �׷� ���� ����ü 

	\~english
	Information construct of P2P group

	\~chinese
	P2P?����?��?

	\~japanese
	P2P����?�����ê�ϰ��?
	\~
	*/
	class CP2PGroup
	{
	public:
		/** 
		\~korean
		�׷� ID 

		\~english
		Group ID 

		\~chinese
		?ID

		\~japanese
		����?��ID
		\~
		*/
		HostID m_groupHostID;
		/** 
		\~korean
		�׷쿡 �Ҽӵ� client peer���� HostID 

		\~english
		HostID of client peer that is possessed by group

		\~chinese
		�?��?��client peer��Host ID��

		\~japanese
		����?�ת��?���쪿client peer�ʪɪ�HostID
		\~
		*/
		HostIDArray m_members;

		PROUD_API CP2PGroup();

#ifdef _WIN32
#pragma push_macro("new")
#undef new
		// �� Ŭ������ ProudNet DLL ��츦 ���� Ŀ���� �Ҵ��ڸ� ���� fast heap�� ���� �ʴ´�.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif
	};
	/** 
	\~korean
	P2P �׷� ����Ʈ
	- ���� �ڼ��� ������ ���̽� Ŭ������ ������ ��. 

	\~english
	 P2P group list
	- Please refer base class for more details.

	\~chinese
	P2P?list��
	- ��??������۰��??��base?��

	\~japanese
	P2P����?�׫꫹��
	- ����٪�������۰���ϫ�?�����髹��?�Ϊ��몳�ȡ�
	\~
	*/
	class CP2PGroups : public CFastMap<HostID, CP2PGroupPtr>
	{
	public:
#ifndef SWIG
#ifndef __MARMALADE__
#pragma push_macro("new")
#undef new
		// �� Ŭ������ ProudNet DLL ��츦 ���� Ŀ���� �Ҵ��ڸ� ���� fast heap�� ���� �ʴ´�.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
#endif //__MARMALADE__
#endif //SWIG 
	};

	/**
	\~korean
	\brief <a target="_blank" href="http://guide.nettention.com/cpp_ko#p2p_group" >P2P �׷�</a> �� ���� ����� ���� �����Դϴ�. 
	�ʿ��� ��찡 �ƴ� �̻� �� ��ü�� ����Ͻ� �ʿ�� �����ϴ�.

	\~english 
	Additional settings for a P2P group. 
	Unless necessary, you don��t have to use this object. 

	\~chinese
	\brief <a target="_blank" href="http://guide.nettention.com/cpp_zh#p2p_group" >P2P ?</a>%��?��?���?�ǡ�
        ���������������?������������?�ڡ�

	\~japanese
	\brief \ref p2p_group  1���Ϋ�?��?������ҪǪ��� 
	��驪�����ǪϪʪ��߾�����Ϋ��֫������Ȫ��Ū���驪Ϫ���ު���
	\~
	*/
	class CP2PGroupOption
	{
	public:
		/**
		\~korean
		true�̸� �׷� ����� Direct P2P ����� �����մϴ�. �⺻���� true�Դϴ�.
		�׷��� �ε� ����� P2P ����� �����ϰ��� �� �� �� ���� false�� �����ϸ� �˴ϴ�. 
		
		�׷� �� ����� �̹� Ÿ �׷� ���ӿ� ���� ���� Direct P2P�� �̹� �ϰ� �ִ� ������ ���, �� ���� false�� �����ϴ� ���� �׵��� Direct P2P�� ���������� �ʽ��ϴ�.

		\~english TODO:translate needed.
		If true, this provides direct P2P communication among group members. The default value is true. 
		You can set this value as false when you form a group but want to block P2P communication among members. 

		When direct P2P is already being done due to being subordinated by another group among the members in the group, selecting this value as false does not block the direct P2P among them. 

		\~chinese
		True��?���?��?��?Direct P2P���ᡣ��??��true��
		����?��ӣ�����?��?��?P2P������?�����??����false��

		??��?��?�?������ݾ??����?��Direct P2P?�������??����false��?�?��?��Direct P2P��

		\~japanese
		True�Ǫ���Ы���?�׫���?���Direct P2P�������ꪷ�ު�����������true�Ǫ���
		����?�ת�̿�֪�����?��Ǫ�P2P������?���������Ϫ�������false�����Ҫ��ƪ���������

		����?��?�ǪΫ���?��˪����ơ�?����Ϋ���?�ת�??�˪�êƪ�����Direct P2P��?�˪�êƪ���?�������ꡢ��������false�����Ҫ��몳�Ȫ�������Direct P2P���?���몳�ȪϪ���ު���
		\~
	*/
		bool m_enableDirectP2P;

		CP2PGroupOption();		

		static PROUD_API CP2PGroupOption Default;
	};

	/**  @} */
#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif
}


#ifdef _MSC_VER
#pragma pack(pop)
#endif
