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

//#if defined(_WIN32)
    #include <deque>
    #include "FastArrayPtr.h"
//#endif

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
//#if defined(_WIN32)
	/** \addtogroup util_group
	*  @{
	*/
	template<typename T>
	class Deque: public std::deque<T>
	{
        typedef typename std::deque<T> DeqType;
        
	public:
		/**
		\~korean 
		\return Data�� ���� �����մϴ�.

		\~english 
		\return the number of data.

		\~chinese
		\return ����data��?��

		\~japanese
		\return Data��?��꫿?�󪷪ު���
		\~
		*/
		int GetCount()
		{
			return (int)DeqType::size();
		}
#if defined (_MSC_VER)
		__declspec(property(get = GetCount)) int Count;
#endif

        inline bool IsEmpty() const { return DeqType::empty(); }

		/**
		\~korean 
		ť�� Data�� �߰��մϴ�.
		\param data �߰��� Data�Դϴ�.

		\~english TODO:translate needed.		
		\param data Data to be added 

		\~chinese
		?֪����ʥData��
		\param data ���ʥ��Data��

		\~japanese
		����?�˫�?������ʥ���ު���
		\param data ��ʥ�����?���Ǫ���
		\~
		*/
		void PushBack(const T& data)
		{
			this->push_back(data);
		}

		/**
		\~korean 
		���� �տ� �ִ� Data�� ����޽��ϴ�.
		\param [out] ret ������� reference�Դϴ�.

		\~english TODO:translate needed.
		Get the very front data copied. 
		\param [out] ret This is a reference to be copied

		\~chinese
		?���������data��
		\param [out] ret ����?���reference��

		\~japanese
		������˪����?���򫳫�?���ƪ�骤�ު���
		\param [out] ret ����?���ƪ�骦reference�Ǫ���
		\~
		*/
		void PeekFront(T& ret)
		{
			ret = DeqType::front();
		}

		/**
		\~korean 
		\return ���� ���� ������

		\~english 
		\return The first data.

		\~chinese
		\return ��������?�ߡ�

		\~japanese
		\return ������Ϋ�?��
		\~
		*/
		T PeekFront()
		{
			return DeqType::front();
		}

		/**
		\~korean 
		���� ���� �����͸� ť���� �����ϰ� ���Ϲ޽��ϴ�.
		\return ���� �տ� �־��� ������

		\~english 
		Removes the very front data from the queue and get it returned. 
		\return The very front data.

		\~chinese
		??֪��?���������?�������ޡ�
		\return ���������?�ߡ�

		\~japanese
		������Ϋ�?���򫭫�?�����۪��ƫ꫿?�󪷪ƪ�骤�ު���
		\return ������˪��ê���?��
		\~
		*/
		T PopFront()
		{
			T ret = DeqType::front();
            DeqType::pop_front();
			return ret;
		}

		/**
		\~korean
		���� ���� �����͸� ť���� �����ϰ� reference�� �޽��ϴ�.
		\param [out] ret Data�� ���� reference

		\~english 
		Deletes the very first data from the queue and get it as reference. 
		\param [out] ret             Reference to receive data

		\~chinese
		??֪��?���������?���������reference��
		\param [out] ret           ���Data��reference��

		\~japanese
		������Ϋ�?���򫭫�?�����۪���reference�Ȫ��ƪ�骤�ު���
		\param [out] ret           Data��������reference
		\~
		*/
		void PopFront(T& ret)
		{
			ret = DeqType::front();
            DeqType::pop_front();
		}

		/**
		\~korean
		��� ������ ������ �����մϴ�.

		\~english 
		Deletes all data information.

		\~chinese
		?����?�����ӡ�

		\~japanese
		��ƪΫ�?�����ê���۪��ު���
		\~
		*/
		void Clear()
		{
            DeqType::clear();
		}

		// �� �޼���� deque.iterator ��ü�� ������ ������ ��ȿ�����̴�.
		// 		void CloneToArray(CFastArray<T> &dest)
		// 		{
		// 			dest.SetCount(size());
		// 			int c=0;
		// 			for(iterator i=begin();i!=end();i++)
		// 			{
		// 				dest[c++]=*i;
		// 			}
		// 		}
	};

	/**  @} */
//#endif
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
