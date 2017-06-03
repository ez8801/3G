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
	/** 
	\~korean
	����ڴ� �� �޼��嵵 �����ؾ� �մϴ�.
	
	����
	- C++ �̿� ���������� �� �޼���� delegate callback ������ �� �ֽ��ϴ�. 
	
	\~english TODO:translate needed.
	Users must implement this method. 
	
	Note
	- In versions other than C++, this method may be in the form of delegate callback. 

	\~chinese
	��?��????۰����

	?��
	- C++����������۰��ʦ����delegate callback���ҡ�

	\~japanese
	��?��?�Ϫ��Ϋ᫽�ëɪ�?�ު��ʪ���Ъʪ�ު���

	?��
	- C++ ���Ϋ�?�����Ǫϡ����Ϋ᫽�ëɪ�delegate callback�����˪ʪ몳�Ȫ�����ު��� 

	*/
	class IHlaDelegate_Common
	{
	public:
		virtual ~IHlaDelegate_Common() {}
		
		/** 
		\~korean
		HLA ���� ��⿡ ���� ��� ��ȣ�� ��û�Ǹ� �� �޼��尡 �ݹ�˴ϴ�. ����ڴ� �̸� �����ؾ� �մϴ�.
		���� ���, ����� �� ��ƾ���� �޸𸮸� ��ȣ�� critical section ����� �Ͻ� �� �ְڽ��ϴ�. 
		
		\~english TODO:translate needed.
		If lock protection is requested by an HLA internal module, this method is called back. Users must implement this. 
		For example, you may do critical section lock that would protect the memory from this routine. 
		
		\~chinese
		��HLA?ݻټ?�??����?��?�۰��?��?����?�????��
		������?ʦ���routine?����??����critical section?�ҡ�

		\~japanese
		HLA?ݻ�⫸��?��˪�êƫ�ë����ު���몵�쪿�骳�Ϋ᫽�ëɪ���?��Ыë�����ު�����?��?�Ϫ����?�ު��ʪ���Ъʪ�ު���
		�Ǫ��С����ʪ��Ϫ��Ϋ�?����ǫ���?�����ު���critical section��ë��򪹪몳�Ȫ��Ǫ��ު���

		*/
		virtual void HlaOnLockCriticalSection() = 0;

		/** 
		\~korean
		HlaOnLockCriticalSection()�� �ݴ� ������ �մϴ�. 
		
		\~english TODO:translate needed.
		It performs the opposite role of HlaOnLockCriticalSection()
		
		\~chinese
		���HlaOnLockCriticalSection()���������ġ�

		\~japanese
		HlaOnLockCriticalSection()����?��ܪ򪷪ު��� 

		*/
		virtual void HlaOnUnlockCriticalSection() = 0;
	};
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
