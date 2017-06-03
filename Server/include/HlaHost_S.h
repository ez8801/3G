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

#ifdef USE_HLA
#include "HlaEntity_S.h"
#include "HlaDelagate_Common.h"

namespace Proud 
{
	class CHlaEntityManagerBase_S;
	class CriticalSection;
	class CHlaSpace_S;
	class IHlaDelegate_S;

	/**
	\~korean
	HLA ���� ���� �޼��� �������̽��Դϴ�.

	\~english TODO:translate needed.
	This is a HLA session server method interface. 

	\~chinese
	��HLA session��?��۰��ͣ����

	\~japanese
	HLA���ë����?��?�᫽�ëɫ���?�ի�?���Ǫ���
	\~
	*/
	class IHlaHost_S
	{
	public:
		virtual ~IHlaHost_S() {};

		/** 
		\~korean
		HLA entity class�� ����մϴ�. 
		HLA entity class�� HLA compiler output�̾�� �մϴ�. 

		\~english TODO:translate needed.
		An HLA entity class is registered. 
		An HLA entity class must be HLA complier output. 
	
		\~chinese
		��?HLA entity class��
		HLA entity class����HLA compiler output��

		\~japanese
		HLA entity class����?���ު���
		HLA entity class��HLA compiler output�ǪϪʪ���Ъʪ�ު���

		*/
		virtual void HlaAttachEntityTypes(CHlaEntityManagerBase_S* entityManager) = 0;

		/** 
		\~korean
		�� ��⿡ ���� �ݹ�Ǵ� �޼������ ������ ��ü�� �޾Ƶ��Դϴ�. 

		\~english TODO:translate needed.
		This receives the objects that implements the methods called back by this module. 
	
		\~chinese
		����??���ټ?����?۰����?�ڡ�

		\~japanese
		���Ϋ⫸��?��˪�êƫ�?��Ыë������᫽�ëɪ�?�ު������֫������Ȫ���������ު���

		*/
		virtual void HlaSetDelegate(IHlaDelegate_S* dg) = 0;

		/** 
		\~korean
		����ڴ� �� �Լ��� ���� �ð����� �� �ؾ� �մϴ�. 

		\~english TODO:translate needed.
		Users must call this function at a certain interval. 
	
		\~chinese
		��?����̰��ӫ???���?��

		\~japanese
		��?��?�Ϫ���??��������઴�Ȫ������󪵪ʪ���Ъʪ�ު���

		*/
		virtual void HlaFrameMove() = 0;
		
		virtual CHlaSpace_S* HlaCreateSpace() = 0;
		virtual void HlaDestroySpace(CHlaSpace_S* space) = 0;

		virtual CHlaEntity_S* HlaCreateEntity(HlaClassID classID) = 0;
		virtual void HlaDestroyEntity(CHlaEntity_S* Entity) = 0;

		virtual void HlaViewSpace(HostID viewerID, CHlaSpace_S* space, double levelOfDetail = 1) = 0;
		virtual void HlaUnviewSpace(HostID viewerID, CHlaSpace_S* space) = 0;
	};

	/** 
	\~korean
	HLA ���� ������ ���� �ݹ�Ǵ� �������̽��Դϴ�. 
	
	����
	- C++ �̿� ���������� �� �޼���� delegate callback ������ �� �ֽ��ϴ�. 

	\~english
	This is an interface called back by the HLA session server.

	Note
	- In versions other than C++, this method may be in the form of delegate callback. 
	
	\~chinese
	��HLA??��?����?����Ϣ�� 
	?��
	- �C++ ��������������۰��ʦ���delegate callback���ҡ� 

	\~japanese
	HLA���ë����?��?�˪�êƫ�?��Ыë�����뫤��?�ի�?���Ǫ���
	
	?��
	- C++ ���Ϋ�?�����Ǫϡ���᫽�ëɪ�delegate callback�����Ǫ������ꪬ����ު���

	*/
	class IHlaDelegate_S:public IHlaDelegate_Common
	{
	public:
		virtual ~IHlaDelegate_S() {}

	};
}
#endif
#ifdef _MSC_VER
#pragma pack(pop)
#endif