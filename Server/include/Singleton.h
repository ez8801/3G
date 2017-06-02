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
#include "Exception.h"
#include "CriticalSect.h"
#include "atomic.h"
#include "Ptr.h"

#if defined __MARMALADE__ || defined __linux__
#include <unistd.h>
#endif

#include "PnThread.h"
#include "SysTime.h"


#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif


namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	/**
	\~korean
	JIT �ν��Ͻ̸� thread safe�ϰ� �ϴ� singleton template
	- JIT �ν��Ͻ� ������ CS lock�� �ؼ� thread safe�ϰ� �ϰ�, ������ ���ĺ��ʹ� thread unsafe�ϰ� �Ѵ�.
	- ������ thread ����ȭ�ϰ� ���ĺ��ʹ� ���ʿ��� ���, ������ CItemTemplate ��� �� ��ü�� ��� �幮 ���� ���� �ٿ���
	���� ����.

	�Ϲ��� �뵵
	- �� Ŭ������ �Ļ� Ŭ������ �����. T���� �Ļ� Ŭ������ �̸��� �ִ´�.
	- Instance()�� �̿��ؼ� �̱����� ���۷����� ��´�. Instance()�� ���ʷ� ȣ���ϸ� ��ü�� �ν��Ͻ�ȭ�ȴ�.
	- �̱��氣 �ı� ������ �����Ϸ��� �̱����� �����ڿ��� ���� ��� �̱����� �ѹ� �������ָ� �ȴ�.

	��뿹
	\code
	class A:public CSingleton<A>
	{
	public:
	void Foo();
	};

	void Aoo()
	{
	A::Instance().Foo();
	}
	\endcode

	DLL�� EXE�� ���� Singleton�� ������ �ϴ� ���
	- CSingleton�� DLL�� �����ϰ� EXE�� �װ��� ������ �ϴ� ��쿡�� �� Ŭ������ ������ ���� �����ؾ� �Ѵ�. �ȱ׷��� EXE�� ���� singleton��
	DLL�� ���� singleton�� ���� �ٸ� �ν��Ͻ��� �����ϰ� �ȴ�.
	\code
	class Goofie:protected CSingleton<Goofie> // protected�� �����ؼ� Instance�� ���� �������� ���ϰ� �Ѵ�.
	{
	public:
	__declspec(dllexport) Goofie& Instance() // CSingleton.Instance()�� �������̵��ϵ� DLL���� export�Ǵ� �Լ��� �����.
	{
	return __super::Instance(); // DLL ��� �޸� ���� ���� ������� instance�� �����Ѵ�.
	}
	};
	\endcode

	\~english
	Singleton template that makes only JIT instancing to be thread safe.
	- Only CS locks JIT instancing process making it thread safe and makes thread unsafe after created.
	- Only thread synchronized then not needed afterwards, e.g. Server down with little frequency can be prevented by using this object at CItemTemplate ans so on.

	General usage
	- Creates derivative class to this class. The name of the derivative class is to enter at T.
	- Gets reference of Singleton using Instance(). Object is instanced when Instance() is called for the first time.
	- To control the destruction order of Singletons, constructor of Signleton should approach to dependent target Singleton just for once.

	Usage example
	\code
	class A:public CSingleton<A>
	{
	public:
	void Foo();
	};

	void Aoo()
	{
	A::Instance().Foo();
	}
	\endcode

	If DLL and EXE to use same Singleton,
	- This class must be realized as followings for the case that DLL provides CSingleton and EXE uses it. Otherwise, the singleton used by EXE and the singleton used by DLL will exist as different instance.
	\code
	class Goofie:protected CSingleton<Goofie> // Declared as protected to prevent direct access of Instance
	{
	public:
	__declspec(dllexport) Goofie& Instance() // Override CSingleton.Instance() but make it as a function exported from DLL.
	{
	return __super::Instance(); // Returns the instance that is created in DLL module memory space
	}
	};
	\endcode

	\~chinese
	����JIT instancing?����thread safe��singleton template��
	- ����JIT instancing?��CS lock�������thread safe���������?�??thread unsafe��
	- ����������thread���������������?�������� CItemTemplate%�������?�����?��?�?������?��������

	������Բ
	- ?���?������?����T��?������?��٣��
	- ����Instance()?��singleton��reference�������УInstance()��??��?instance����
	- ������singleton��?����??����singleton��������������������?����singleton��

	������
	\code
	class A:public CSingleton<A>
	{
	public:
	void Foo();
	};

	void Aoo()
	{
	A::Instance().Foo();
	}
	\endcode

	DLL ��EXE�����������singleton��?��
	- DLL���� CSingleton%��EXE �����?��?������?����??����?EXE������singleton��DLL������singleton?�����������instance��
	\code
	class Goofie:protected CSingleton<Goofie> // ��protected�ͱ����?Instance�������Ρ�
	{
	public:
	__declspec(dllexport) Goofie& Instance() // ���� CSingleton.Instance()��ӣ��������DLL��export����?��
	{
	return __super::Instance(); // �����DLLټ??����??�����instance��
	}
	};
	\endcode

	\~japanese
	JIT���󫹫��󫷫󫰪Ϊ�thread safe����誦�˪���singleton template
	- JIT���󫹫��󫷫�Φ��Ϊ�CS lock�򪷪�thread safe����誦�˪��ơ������������thread unsafe����誦�˪��ު���
	- �����Ϊ�thread��Ѣ���򪷪ơ��˽�������驪����ꡢ�Ǫ���CItemTemplate�ʪɪǪ��Ϋ��֫������Ȫ����Ī���ȡ��Ϫ�?�檹�뫵?��?��������������몳�Ȫ��Ǫ��ު���

	�����ܪ���Բ
	- ���Ϋ��髹�����櫯�髹���ª�ު���T�˪����櫯�髹��٣�������ު���
	- Instance()�����Ī��ƫ��󫰫��?��Ϋ�ի���󫹪���ު���Instance()������������󪹪ȫ��֫������Ȫ����󫹫����������ު���
	- ���󫰫��?�������?�������٪��몿��˪ϡ����󫰫��?��������������?�ګ��󫰫��?������������������ƪ���������

	������
	\code
	class A:public CSingleton<A>
	{
	public:
	void Foo();
	};

	void Aoo()
	{
	A::Instance().Foo();
	}
	\endcode

	DLL��EXE���Ҫ�Singleton���Ū����Ȫ�������
	- CSingleton��DLL����ꪷ��EXE��������Ū����Ȫ�������˪ϡ����Ϋ��髹���Ϊ誦��?�ު��ʪ���Ъʪ�ު��󡣪���ǪϪʪ���С�EXE���Ū�singleton��DLL���Ū�singleton���������ު����󫹫��󫹪������誦�˪ʪ�ު���
	\code
	class Goofie:protected CSingleton<Goofie> // protected����몷��Instance�����ȫ��������Ǫ��ʪ��誦�˪��ު���
	{
	public:
	__declspec(dllexport) Goofie& Instance() // CSingleton.Instance()��?��?�髤�ɪ��ު�����DLL���export�����??���ª�ު���
	
	return __super::Instance(); // DLL�⫸��?�����?����?���ª�쪿instance��꫿?�󪷪ު���
	}
	};
	\endcode

	

	\~


	\~korean

	���� �̱��波�� �ı� ������ �����ؾ� �ϴ� ���, shared pointer ��ü�� �� ���������ν� �ı� ������ ������ �� �ֽ��ϴ�.

	\~english

	You can define destruction order of singletons by keeping shared pointer object from singleton.

	\~chinese

	������?��ټ����?�����??��ʦ�?��?����shared pointer?�����?��??��

	\~japanese
	�⪷�����󫰫��?����Ǫ���?������������驪��������ꡢshared pointer���֫������Ȫ������η�ժު���?������������몳�Ȫ��Ǫ��ު���

	\~



	\~korean

	���� �ڵ�

	\~english

	Example code

	\~chinese

	??�ǡ�

	\~japanese
	���ƫ�?��

	\~


	\~korean

	\code
	// �̱��� Ŭ�����Դϴ�.
	class MySingleton:public CSingleton<MySingleton>
	{
	...
	Something();
	};

	// �̱����� �����ϴ� ������Դϴ�.
	class MyGoo
	{
	// MyGoo �ν��Ͻ��� �����ϴ� ���� �̱����� ������ �����Ϸ��� �� ����� ���� �־�� �մϴ�.
	// ����, �̱��� ������ ���� �� ����� ����Ͻʽÿ�.
	MySingleton::PtrType m_mySingleton;

	// ������ �޼���
	User()
	{
	// �̱��� ���� ī��Ʈ�� ������Ű�鼭, �̱����� ������ �����ŵ�ϴ�.
	m_mySingleton = MySingleton::GetInstanceAccessor();
	}

	Foo()
	{
	...
	// �̱����� �����Ϸ��� �̹� ���� �ִ� �̱��� ����Ʈ������ ��ü�� ���� �����մϴ�.
	m_mySingleton->Something();
	}
	}

	\endcode

	\~english

	\code
	// Singleton Class
	class MySingleton:public CSingleton<MySingleton>
	{
	...
	Something();
	};

	// It is the user that has access to Singleton.
	class MyGoo
	{
	// While MyGoo instance exists, it must have this member in order to assure Singleton��s survival.
	// Use this member for Singleton access, of course.
	MySingleton::PtrType m_mySingleton;

	// constructor
	User()
	{
	// It guarantee survival of singleton with increasing singleton refer count.
	m_mySingleton = MySingleton::GetInstanceAccessor();
	}

	Foo()
	{
	...
	// To access singleton, use singleton smartpointer object that already has.
	// do not use MySingleton::Instance(), but use this member variable.
	m_mySingleton->Something();
	}
	}

	\endcode

	\~chinese

	\code
	// singleton?��
	class MySingleton:public CSingleton<MySingleton>
	{
	...
	Something();
	};

	// ����singleton��������
	class MyGoo
	{
	// MyGoo��instance���Ѣ?�������singleton������?���?�����?��
	// ?��singleton���Σ��������??��
	MySingleton::PtrType m_mySingleton;

	// �����۰��
	User()
	{
	// ����ʥsingleton?��count��?��ʦ����singleton������
	m_mySingleton = MySingleton::GetInstanceAccessor();
	}

	Foo()
	{
	...
	// ������singleton��?����?�??����singleton smartpointer?��?���Ρ�
	m_mySingleton->Something();
	}
	}
	\endcode

	\~japanese
	\code
	// ���󫰫��?�󫯫髹�Ǫ���
	class MySingleton:public CSingleton<MySingleton>
	{
	...
	Something();
	};
	// ���󫰫��?��򫢫����������?��?�Ǫ���
	class MyGoo
	{
	// MyGoo �ν��Ͻ��� �����ϴ� ���� �̱����� ������ �����Ϸ��� �� ����� ���� �־�� �մϴ�.
	// MyGoo���󫹫��󫹪��������˫��󫰫��?������������몿��˪Ϫ��Ϋ���?���êƪ�����驪�����ު���
	// ����, �̱��� ������ ���� �� ����� ����Ͻʽÿ�.
	// �����󡢫��󫰫��?��Ϋ��������Ϊ���˪��Ϋ���?���Ūêƪ���������
	MySingleton::PtrType m_mySingleton;

	// �����᫽�ë�
	User()
	{

	// ���󫰫��?��?�Ϋ�����Ȫ�?ʥ�����ʪ��顢���󫰫��?��������������ު���
	m_mySingleton = MySingleton::GetInstanceAccessor();
	}

	Foo()
	{
	...

	// ���󫰫��?��򫢫��������몿��˪ϡ�?���êƪ��뫷�󫰫��?�󫹫�?�ȫݫ���?���֫������Ȫ��ת������������ު���
	m_mySingleton->Something();
	}
	}

	\endcode

	

	
	\~


	*/

	template<typename T>
	class CSingleton 
	{
		// ���� ���� : �̱��� ��ü Ư���� ���� �ڵ�� �־ �ȵ˴ϴ�.
		NO_COPYABLE(CSingleton)

	public:
		typedef RefCount<T> PtrType;

	public:
		virtual ~CSingleton() { }

	protected:
		// ���� ���� : �̱����� ����� ��, �ݵ�� GetSharedPtr() or GetUnsafeRef() �� �����մϴ�.
		CSingleton() { }

	private:
		static PtrType &m_instancePtr;
		static CriticalSection m_cs;

	public:
		_Noinline static PtrType GetSharedPtr()
		{
			// #ikpil.choi 2017-01-07 double-checked locking
			// check 1
			if (0 != m_instancePtr)
				return m_instancePtr;

			// lock
			CriticalSectionLock lock(m_cs, true);

			// check 2
			if (0 != m_instancePtr)
				return m_instancePtr;

			// create
			m_instancePtr = PtrType(new T());

			return m_instancePtr;
		}

		// ������� : GetSharedPtr() ����� ���� ����Ͻð�, �ӵ��� �ΰ��ϴٸ�, GetUnsafeRef()�� ����ϼ���.
		static inline T& GetUnsafeRef()
		{
			static T* val = NULL;
			if (!val)
			{
				val = GetSharedPtr();
			}
			return *val;
		}
		

		// ����ڰ� �̰��� ������ ����� ������ ���� ������� ��ü�� �ı��Ǳ� ������ �� �̱����� �ı� �ȵ��� �����Ѵ�.
		class Holder
		{
			PtrType m_sharedPtr;
		public:
			Holder()
			{
				m_sharedPtr = CSingleton<T>::GetSharedPtr();
			}
			// �� �Լ��� �־��.
			// �����Ϸ��� �˾Ƽ� �Ļ� Ŭ������ ����Ʈ �ı��ڸ� ������ �ϰ�����, Ȯ�� ����� ����.
			virtual ~Holder() {}
		};

	private:
		static PtrType& CreateRefCount()
		{
			// #ikpil.choi 2017-01-07 : ����Ʈ �������� ��ü�� �Լ� ȣ�� �ڷ� ����, �ι� �̻� ȣ�� �Ǿ, �ѹ� instance�� �����Ѵ�.
			static PtrType ptr;
			return ptr;
		}

	};

	/**  @} */


	template<typename T>
	CriticalSection CSingleton<T>::m_cs;

	template<typename T>
	RefCount<T> &CSingleton<T>::m_instancePtr = CSingleton<T>::CreateRefCount();
}

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

#ifdef _MSC_VER
#pragma pack(pop)
#endif
