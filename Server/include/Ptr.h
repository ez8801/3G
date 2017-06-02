/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
/*
ProudNet 1.7.38050-master


ÀÌ ÇÁ·Î±×·¥ÀÇ ÀúÀÛ±ÇÀº ³İÅÙ¼Ç¿¡°Ô ÀÖ½À´Ï´Ù.
ÀÌ ÇÁ·Î±×·¥ÀÇ ¼öÁ¤, »ç¿ë, ¹èÆ÷¿¡ °ü·ÃµÈ »çÇ×Àº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾àÀ» µû¸£¸ç,
°è¾àÀ» ÁØ¼öÇÏÁö ¾Ê´Â °æ¿ì ¿øÄ¢ÀûÀ¸·Î ¹«´Ü »ç¿ëÀ» ±İÁöÇÕ´Ï´Ù.
¹«´Ü »ç¿ë¿¡ ÀÇÇÑ Ã¥ÀÓÀº º» ÇÁ·Î±×·¥ÀÇ ¼ÒÀ¯±ÇÀÚ¿ÍÀÇ °è¾à¼­¿¡ ¸í½ÃµÇ¾î ÀÖ½À´Ï´Ù.

** ÁÖÀÇ : ÀúÀÛ¹°¿¡ °üÇÑ À§ÀÇ ¸í½Ã¸¦ Á¦°ÅÇÏÁö ¸¶½Ê½Ã¿À.


This program is soley copyrighted by Nettention.
Any use, correction, and distribution of this program are subject to the terms and conditions of the License Agreement.
Any violated use of this program is prohibited and will be cause of immediate termination according to the License Agreement.

** WARNING : PLEASE DO NOT REMOVE THE LEGAL NOTICE ABOVE.


ó®ïïßíîÜ÷ú??NettentionÍëŞÉá¶êó¡£
?ó®ïïßíîÜáóËÇ¡¢ŞÅéÄ¡¢?øÖßÓ?îÜŞÀ?é©ñåáúó®ïïßíîÜá¶êó?íºîÜ??¡£
Üôñåáú???é©ê«?àõîÜĞ×ò­ôºí»ŞÅéÄ¡£
ôºí»ŞÅéÄîÜ?ìòÙ¥ãÆî¤?ó®ïïßíá¶êó?íºîÜùêÔÒ?×ì¡£

** ñ¼ëò£ºÜôé©ì¹ğ¶?éÍğ¤íÂÚªîÜß¾âûÙ¥ãÆ¡£


ª³ªÎ«×«í«°«é«àªÎîÊíÂ?ªÏNettentionªËª¢ªêªŞª¹¡£
ª³ªÎ«×«í«°«é«àªÎáóïá¡¢ŞÅéÄ¡¢ÛÕøÖªË?ª¹ªëŞÀú£ªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ªË?ª¤¡¢
Ìøå³ªòñåáúª·ªÊª¤íŞùê¡¢ê«öÎîÜªËÙí?ŞÅéÄªòĞ×ª¸ªŞª¹¡£
Ùí?ŞÅéÄªËªèªëô¡ìòªÏÜâ«×«í«°«é«àªÎá¶êó?íºªÈªÎÌøå³ßöªËÙ¥ãÆªµªìªÆª¤ªŞª¹¡£

** ñ¼ëò£ºîÊíÂÚªªË?ª¹ªëß¾ÑÀªÎÙ¥ãÆªòğ¶ËÛª·ªÊª¤ªÇª¯ªÀªµª¤¡£

*/

#pragma once

#include "pnstdint.h" 

#include "BasicTypes.h"
#include "atomic.h"
#include "Enums.h"
#include "ProcHeap.h"
#include "ClassBehavior.h"


#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4324)
#endif 

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

#if (_MSC_VER>=1400)
#pragma managed(push, off)
#endif

	class CLookasideAllocator;

	/** 
	\~korean
	reference count¸¦ ¼¼Áö ¾Ê´Â ´ú smartÇÑ pointerÀÌ´Ù.
	- ATL CAutoPtr°ú °°Àº ¿ªÇÒÀ» ÇÑ´Ù.
	- ÀÌ °´Ã¼°¡ ÆÄ±«µÉ ¶§ holdÇÏ°í ÀÖ´Â pointerÀÇ object¸¦ deleteÇÑ´Ù. 

	\~english
	A less smart pointer that does not count reference count
	- Acts as ATL CAutoPtr
	- When this object is destructed, the object of the pointer that is held by this object is deleted.

	\~chinese
	Üô?reference coutîÜÜô÷¼smartîÜpointer¡£
	- ÑÃó·?ATL CAutoPtr%ìé?îÜíÂéÄ¡£
	- ???ßÚù¬÷ò?îÜ?ı¦deleteïáî¤holdîÜpointerîÜobject¡£

	\~japanese
	reference countªò?ª¨ªÊª¤ª¢ªŞªê«¹«Ş?«ÈªÇªÏªÊª¤pointerªÇª¹¡£
	- ATL CautoPtrªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
	- ª³ªÎ«ª«Ö«¸«§«¯«Èª¬÷ò?ªµªìªëãÁªËHoldª·ªÆª¤ªëpointerªÎ«ª«Ö«¸«§«¯«ÈªòŞûğ¶ª·ªŞª¹¡£
	\~
	*/
	template<typename T>
	class CHeldPtr
	{
	public:
		T* m_p;

		inline CHeldPtr() : m_p(NULL) {}
		
		inline CHeldPtr(T* p_) : m_p(p_) {}
		
		inline CHeldPtr& operator=(T* p_)
		{
			m_p = p_;
			return *this;
		}

		inline ~CHeldPtr()
		{
			if (m_p)
				delete m_p;
		}

		/**
		\~korean 
		object¸¦ Á¦°ÅÇÑ´Ù. 

		\~english 
		Remove an object. 

		\~chinese
		?ğ¶object¡£

		\~japanese
		Objectªòğ¶ËÛª·ªŞª¹¡£
		\~
		*/
		inline void Free()
		{
			if(m_p)
				delete m_p;
			m_p=0;
		}

		/**
		\~korean
		object¸¦ attachÇÑ´Ù.
		- ÀÌ¹Ì ´Ù¸¥ °ÍÀ» attachÇÏ°í ÀÖ´Â °æ¿ì ±×°ÍÀ» deleteÇÏÁö´Â ¾Ê´Â´Ù.
		\param p_ attachÇÒ °´Ã¼ÀÇ Æ÷ÀÎÅÍ

		\~english 
		Attach an object
		- If something else is already attached, do not delete it. 
		\param p_ Pointer of the object to be attached. 

		\~chinese
		Attach object¡£
		- ïáî¤attachĞìöâ?îÜ?ı¦Üô?ğ¶?¡£
		\param p_ é©attachîÜ?ßÚîÜò¦?¡£

		\~japanese
		Objectªòattachª·ªŞª¹¡£
		- ?ªËöâªÎªâªÎªòAttachª·ªÆª¤ªëíŞùê¡¢ª½ªìªòŞûğ¶ª¹ªëª³ªÈªÏª¢ªêªŞª»ªó¡£
		\param p_ attachª¹ªë«ª«Ö«¸«§«¯«ÈªÎ«İ«¤«ó«¿?
		\~
		*/
		inline void Attach(T* p_)
		{
			m_p = p_;
		}

		/** 
		\~korean
		object¸¦ detachÇÑ´Ù. Áï, holdÇÏ°í ÀÖ´Â object¸¦ NULL·Î ¼¼ÆÃÇÑ´Ù.
		- ±âÁ¸ attachµÈ object¸¦ deleteÇÏÁö´Â ¾Ê´Â´Ù.
		- Áï, Attach(NULL)°ú °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english 
		Detach an object. In other words, the object being held is set to null. 
		- Do not delete the previously attached object. 
		- In other words, it performs the same role as Attach (NULL). 

		\~chinese
		Detach object¡£??holdñéîÜobject?öÇà÷NULL¡£
		- ÜôdeleteñıîñattachîÜobject¡£
		- ?ÑÃó·?Attach(NULL)ìé?îÜíÂéÄ¡£

		\~japanese
		Objectªòdetachª·ªŞª¹¡£?ªÁ¡¢holdª·ªÆª¤ªëobjectªòNULLªËàâïÒª·ªŞª¹¡£
		- ?ğíªËattachªµªìª¿objectªòŞûğ¶ª¹ªëª³ªÈªÏª¢ªêªŞª»ªó¡£
		- ?ªÁ¡¢Attach(NULL)ªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		*/
		inline void Detach()
		{
			m_p = NULL;
		}

		inline operator T*() const
		{
			return m_p;
		}

		inline T* operator->() const
		{
			return m_p;
		}

		NO_COPYABLE(CHeldPtr)
	};

	template<typename T>
	inline bool operator<(const CHeldPtr<T> a, const CHeldPtr<T> b)
	{
		return a.m_p < b.m_p;
	}

	template <typename T> class SmartPtr {
		T* p;
	public:
		SmartPtr(T* p_) : p(p_) {
			p->upcount();
		}
		~SmartPtr(void) {
			p->downcount();
		}
		operator T*(void) {
			return p;
		}
		T& operator*(void) {
			return *p;
		}
		T* operator->(void) {
			return p;
		}
		SmartPtr& operator=(SmartPtr<T> &p_)
		{
			return operator=((T *) p_);
		}
		SmartPtr& operator=(T* p_) {
			p->downcount();
			p = p_;
			p->upcount();
			return *this;
		}
	};

// 	PROUD_API void* RefCount_LookasideAllocator_Alloc(size_t length);
// 	PROUD_API void RefCount_LookasideAllocator_Free(void* ptr);

	/** 
	\~korean
	Smart pointer Å¬·¡½º. ÀÚ¼¼ÇÑ ³»¿ëÀº <a target="_blank" href="http://guide.nettention.com/cpp_ko#smart_ptr" >½º¸¶Æ® Æ÷ÀÎÅÍ</a>¿¡ ÀÖ´Ù.

	RefCount¸¦ »ç¿ë½Ã ´ÙÀ½À» ÁÖÀÇÇØ¾ß ÇÑ´Ù.
	- RefCount°¡ ÃÖÃÊ·Î °´Ã¼¸¦ ÂüÁ¶ÇÒ ¶§ TombstoneÀÌ¶ó´Â °ÍÀ» ¸¸µç´Ù. ±×¸®°í ÀÌÈÄÀÇ °øµ¿ ÂüÁ¶ °´Ã¼°¡ µîÀå½Ã ÀÌ tombstoneÀÌ °øÀ¯µÈ´Ù.
	Áï tombstoneÀ» ÃÖÃÊ¿¡ »ı¼ºÇÏ´Â ½Ã°£ ºñ¿ë(¸Ş¸ğ¸® ÇÒ´ç 1È¸)ÀÌ µç´Ù. 
	- ¼­·Î ´Ù¸¥ ¿¬°üµÈ Å¬·¡½º Å¸ÀÔÀ¸·Î Ä³½ºÆÃÀÌ ¾ÈµÈ´Ù. ¿¹ÄÁ´ë RefCount<CFile>À» RefCount<CObject>¿¡ º¹»çÇÒ ¼ö ¾ø´Ù.
	ÀÌ·± °æ¿ì´Â RefCountÀÇ class typeÀ¸·Î °¡±ŞÀû »óÀ§ base class¸¦ ³Ö°í ÄÚµù½Ã type cast¸¦ ¸Å¹ø ÇØ¾ß ÇÑ´Ù. 
	\code
	class Base {};
	class A:public Base {};

	void Foo()
	{
	   RefCount<A> a;
	   RefCount<Base> b;
	   a = b; // ¿¡·¯
	}

	void Foo2()
	{
	   RefCount<Base> a;
	   RefCount<Base> b(new A);
	   a = b; // OK
	   A* p = (A*)a.get(); // Å¸ÀÔ A¸¦ ÂüÁ¶ÇÏ·Á¸é ÀÌ·¸°Ô ÇØ¾ß ÇÑ´Ù.
	}
	\endcode
	
	\param T ½º¸¶Æ® Æ÷ÀÎÅÍ°¡ ´Ù·ê °´Ã¼ÀÇ Å¸ÀÔ
	\param AllocT AllocType °ª Áß ÇÏ³ª. 
	\param IsThreadSafe <¾È¾¸!> trueÀÌ¸é ÀÌ ½º¸¶Æ® Æ÷ÀÎÅÍ º¯¼ö¸¦ ¿©·¯ ½º·¹µå°¡ µ¿½Ã¿¡ ´Ù·ç¾îµµ ¾ÈÀüÇÏ´Ù. ±×·¯³ª ¼º´É ÀúÇÏ°¡ ÀÖ´Ù.

	\~english
	Smart pointer class. Please refer to <a target="_blank" href="http://guide.nettention.com/cpp_en#smart_ptr" >Smart Pointer</a>.

	When using RefCount, the following must be considered.
	- When RefCount refers object for the first time, it creates Tombstone. And when joint reference object appears, this tombstone will be shared.
	  In other words, there is a time cost(memory allocation, 1 time) to create tombstone initially. 
	- Cannot cast to related class types that are different to each other. Which means, RefCount<CFile> cannot be copied to RefCount<CObject>.  
	  Type cast must be performed each time when coding as class type of RefCount entered higher possible base class.
	\code
	class Base {};
	class A:public Base {};

	void Foo()
	{
	   RefCount<A> a;
	   RefCount<Base> b;
	   a = b; // Error
	}

	void Foo2()
	{
	   RefCount<Base> a;
	   RefCount<Base> b(new A);
	   a = b; // OK
	   A* p = (A*)a.get(); // This must be done to refer type A.
	}
	\endcode
	
	\param T Type of object that is to be handled by smart pointer
	\param AllocT one of the values of AllocType 
	\param IsThreadSafe <NEVER USED!> If true then it is safe that many threads handle the variable of this smart pointer. But it reduces overall performance.

	\~chinese
	Smart pointer?¡£???é»î¤<a target="_blank" href="http://guide.nettention.com/cpp_zh#smart_ptr" >Smartò¦?</a>%¡£

	ŞÅéÄRefCountîÜ?ı¦é©ñ¼ëòì¤ù»?ïÃ¡£
	- RefCountõÌôø?ÍÅ?ßÚîÜ?ı¦?ËïĞ£TombstoneîÜ?à¤¡£æÔı¨åıêóÍìÔÒ?ÍÅ?ßÚîÜÔô??ó®tombstoneù¬Íìú½¡£
	??ßæôøó­ßæà÷tombstoneîÜ???éÄ£¨?ğíİÂÛÕìéó­£©¡£
	- ÜôÒöéÄû»ÜôßÓÔÒîÜ????úş?ú¼cast¡£ÖÇåıÜôÒö÷êRefCount<CFile>?ğ¤?RefCount<CObject>¡£
	??ï×?éÄRefCountîÜclass type?Ê¦Òö?ìıß¾êÈbase class£¬?ïï?Øßó­Ô´é©?ú¼type cast¡£
	\code
		class Base {};
		class A:public Base {};

		void Foo()
		{
		   RefCount<A> a;
		   RefCount<Base> b;
		   a = b; // ??
		}

		void Foo2()
		{
		   RefCount<Base> a;
		   RefCount<Base> b(new A);
		   a = b; // OK
		   A* p = (A*)a.get(); // ßÌ?ÍÅAîÜ?é©??ñ®¡£
		}
	\endcode

	\param T smartò¦?é©?×âîÜ?ßÚ?úş¡£
	\param AllocT AllocType?ñéñıìé¡£
	\param IsThreadSafe <ÜôéÄ£¡> trueîÜ?î»?ïïÔÒ??×âó®smartò¦???å¥äÌîï¡£Ó£ãÀàõÒö?ù»Ë½¡£

	\~japanese
	Smart pointer «¯«é«¹¡£ßÙª·ª¯ªÏ¡¢\ref smart_ptrªËª¢ªêªŞª¹¡£

	RefCountªòŞÅéÄãÁªËó­ªòñ¼ëòª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
	- RefCountª¬ôøªáªÆ«ª«Ö«¸«§«¯«Èªò?ğÎãÁªËTombstoneªÈª¤ª¦ª³ªÈªòíÂªêªŞª¹¡£ª½ª·ªÆ¡¢ì¤Ë½ªÎÍìÔÒ?ğÎ«ª«Ö«¸«§«¯«Èª¬ÔôíŞãÁªËª³ªÎtombstoneª¬ÍìêóªµªìªŞª¹¡£
	?ªÁ¡¢tombstoneªòôøªáªÆßæà÷ª¹ªëãÁÊà«³«¹«È(«á«â«ê?ùÜ?1üŞ)ª¬ª«ª«ªêªŞª¹¡£ 
	- ªªû»ª¤êŞª¦?Ö§ª·ª¿«¯«é«¹«¿«¤«×ªÇ«­«ã«¹«Æ«£«ó«°ª¬ªµªìªŞª»ªó¡£ÖÇª¨ªĞ¡¢RefCount<CFile>ªòRefCount<CObject>ªË«³«Ô?ª¹ªëª³ªÈªÏªÇª­ªŞª»ªó¡£
	ª³ªÎªèª¦ªÊíŞùêªÏRefCountªÎclass typeªÇªÊªëªÙª¯ß¾êÈªÎbase classªòìıªìªÆ«³?«Ç«£«ó«°ãÁªËtype castªò?üŞª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£ 
\code
	class Base {};
	class A:public Base {};

	void Foo()
	{
	   RefCount<A> a;
	   RefCount<Base> b;
	   a = b; // «¨«é?¡¡
	}

	void Foo2()
	{
	   RefCount<Base> a;
	   RefCount<Base> b(new A);
	   a = b; // OK
	   A* p = (A*)a.get(); // «¿«¤«×Aªò?ğÎª¹ªëª¿ªáªËªÏª³ªÎªèª¦ªËª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£
	}
	\endcode

	\param T «¹«Ş?«È«İ«¤«ó«¿?ª¬Ğâª¦«ª«Ö«¸«§«¯«ÈªÎ«¿«¤«×
	\param AllocT AllocType ö·ªÎª¦ªÁìéªÄ¡£ 
	\param IsThreadSafe <ŞÅªïªÊª¤!> trueªÇª¢ªìªĞª³ªÎ«¹«Ş?«È«İ«¤«ó«¿???ªòÜÜ?ªÎ«¹«ì«Ã«Éª¬ÔÒãÁªËĞâªÃªÆªâäÌîïªÇª¹¡£ª·ª«ª·¡¢àõÒöî¸ù»ª¬ª¢ªêªŞª¹¡£

	\~
	*/
	template<typename T>
	class RefCount 
	{
	public:
		typedef RefCount<T> Type;
	private:
		struct Tombstone 
		{
			T* m_ptr;

			/* ³·Àº È®·üÀÏ °Í °°Áö? 64bit¿¡¼­´Â reference count°¡ 2^32¸¦ ³Ñ¾î°¡Áö ¸»¶õ ¹ı ¾ø´Ù.
			¿©·¯ ½º·¹µå¿¡¼­ µ¿½Ã¿¡ assignÀÌ³ª ¾Ï¹¬ÀûÀÎ scope outÀÌ ÀÖÀ» °æ¿ì ¾ó¸¶µçÁö thread unsafe´Â ÀÖÀ» ¼ö ÀÖ´Ù. 
			µû¶ó¼­ ÀÌ °ªÀº atomic opÀ¸·Î¸¸ ´Ù·ç¾îÁ®¾ß ÇÑ´Ù. */
			PROUDNET_VOLATILE_ALIGN intptr_t m_count; 
 
			inline Tombstone() {}
			inline ~Tombstone() {
				delete m_ptr;
			}
#ifdef _WIN32
 #pragma push_macro("new")
 #undef new
		private:
			// new,delete oper ±İÁö½ÃÅ´
			void* operator new(size_t size);
			void operator delete(void* ptr, size_t size);
		public:
 #pragma pop_macro("new")
#endif
		public:
			/**
			\~korean
			CFirstHeapÀº CSingleton ÂüÁ¶. 
			- CSingletonÀº RefCount¸¦ ÂüÁ¶. 
			- µû¶ó¼­ CSingletonÀº CFirstHeap »ç¿ë ±İÁö.
			- object¸¦ »ı¼º ÇØÁÜ
			- ÀÚÃ¼ÀûÀ¸·Î new¸¦ ÇÒ ¼ö ¾ø°Ô²û µÇ¾îÀÖÀ½

			\~english TODO:translate needed
			CFirstHeap refers to CSingleton
			- CSingleton refers to RefCount
			- Therefore, CSingleton is forbidden to use CFirstHeap.
			- It generates objects. 
			- It is made not to do new on its own. 

			\~chinese
			CFirstHeap ?ÍÅ CSingleton%¡£
			- CSingleton%?ÍÅRefCount¡£
			- ì×ó® CSingleton%Ğ×ò­ŞÅéÄ CFirstHeap%¡£
			- ßæà÷object¡£
			- Üô?í»ĞùÜâãóñ®new¡£

			\~japanese
			CFirstHeapªÏCSingletonªòª´?ğÎª¯ªÀªµª¤¡£ 
			- CSingletonªÏRefCountªòª´?ğÎª¯ªÀªµª¤¡£ 
			- ªèªÃªÆ¡¢CSingletonªÏCFirstHeapŞÅéÄĞ×ò­
			- objectªòßæà÷ª·ªŞª¹¡£
			- í»?îÜªËnewª¬ªÇª­ªÊª¯ªÊªÃªÆª¤ªŞª¹¡£
			\~
			*/
			inline static Tombstone* NewInstance()
			{
				Tombstone* ret = (Tombstone*)CProcHeap::Alloc(sizeof(Tombstone));  // ¹İµå½Ã CProcHeapÀ» ½á¾ß ÇÑ´Ù. CFirstHeapÀº ÇÁ·Î¼¼½º Á¾·áÁß »ç¿ë ºÒ°¡ÀÌ¹Ç·Î.				
				if(ret == NULL)
				 ThrowBadAllocException();
 
				CallConstructor<typename Type::Tombstone>(ret);// <Type::Tombstone>¸¦ ºÙ¿©¾ß ÄÄÆÄÀÏ·¯°¡ ¾û¶×ÇÑ Å¸ÀÔ ¸ÅÄªÀ» ÇÏ´Â ¹ö±×¸¦ ÇÇÇÔ
 
				return ret;
			}
 
			/**
			\~korean
			 object¸¦ Á¦°ÅÇÔ.
			- ÀÚÃ¼Àû delete¸¦ ÇÒ ¼ö ¾øÀ½
			\param object Á¦°ÅÇÒ °´Ã¼

			\~english 
			Removes objects. 
			- It cannot delete on its own. 
			\param object Object to be removed. 

			\~chinese
			?ğ¶object¡£
			- ÜôÒö?ú¼ÜâãóîÜdelete¡£
			\param object é©?ğ¶îÜ?ßÚ¡£

			\~japanese
			Objectªòğ¶ËÛª·ªŞª¹¡£
			- í»?îÜªËdeleteªòú¼ª¦ª³ªÈª¬ªÇª­ªŞª»ªó¡£
			\param object ğ¶ËÛª¹ªë«ª«Ö«¸«§«¯«È
			\~
			*/
			inline static void DeleteInstance(Tombstone* object)
			{
				CallDestructor<typename Type::Tombstone>(object);// <Type::Tombstone>¸¦ ºÙ¿©¾ß ÄÄÆÄÀÏ·¯°¡ ¾û¶×ÇÑ Å¸ÀÔ ¸ÅÄªÀ» ÇÏ´Â ¹ö±×¸¦ ÇÇÇÔ
 
				CProcHeap::Free(object);
			}

			NO_COPYABLE(Tombstone)
		};
 
		Tombstone* m_tombstone;
 
	public:
		/** 
		\~korean
		ÀÌ °´Ã¼¸¦ ÂüÁ¶ÇÏ°í ÀÖ´Â ´Ù¸¥ º¯¼ö °´Ã¼µéÀÇ °¹¼ö¸¦ ¸®ÅÏÇÑ´Ù. Áï ÂüÁ¶ È½¼ö´Ù. 

		\~english
		Returns the number of other variable objects that refer this object. In other words, the number of referring.

		\~chinese
		Ú÷üŞ?ÍÅó®?ßÚîÜĞìöâ???ßÚ??¡£??ÍÅó­?¡£

		\~japanese
		ª³ªÎ«ª«Ö«¸«§«¯«Èªò?ğÎª·ªÆª¤ªëöâªÎ??«ª«Ö«¸«§«¯«ÈªÎ?ªò«ê«¿?«óª·ªŞª¹¡£?ªÁ¡¢?ğÎüŞ?ªÇª¹¡£
		\~
		*/
		inline intptr_t GetRefCount() 
		{
			if (!m_tombstone)
				return 0;
 
			return m_tombstone->m_count;
		}
 
		/** 
		\~korean
		»ı¼ºÀÚ. Æ÷ÀÎÅÍ p°¡ °¡¸®Å°´Â °´Ã¼ÀÇ ¼ÒÀ¯±ÇÀ» °¡Á®¿Â´Ù. 

		\~english
		Constructor. Brings the ownership of the object that pointer p points.

		\~chinese
		ßæà÷íº¡£ö¢ò¦?pá¶ò¦îÜ?ßÚîÜá¶êó?¡£

		\~japanese
		ßæà÷í­¡£«İ«¤«ó«¿?pª¬ò¦ª¹«ª«Ö«¸«§«¯«ÈªÎá¶êó?ªòö¢ªê?ªßªŞª¹¡£
		\~
		*/
		inline explicit RefCount(T* p = 0)			
		{
			if(p)
			{
				m_tombstone = Tombstone::NewInstance();
				
				m_tombstone->m_count = 1;
				m_tombstone->m_ptr = p;
			}
			else
				m_tombstone = 0;
		}
		/** 
		\~korean
		º¹»ç ´ëÀÔ ¿¬»êÀÚ 

		\~english
		Copy assignment operator

		\~chinese
		?ğ¤???ß©İ¬¡£

		\~japanese
		«³«Ô?ÓÛìıæÑß©í­
		\~
		*/
		inline RefCount(const Type& other)
		{
			m_tombstone = 0;
			AssignFrom(other);
		}

		inline ~RefCount()
		{
			Reset();
		}

		inline void Reset()
		{
			if (m_tombstone)
			{
				intptr_t result = AtomicDecrementPtr(&m_tombstone->m_count);
				if (result == 0)
				{
					Tombstone::DeleteInstance(m_tombstone);
				}
			}
			m_tombstone = NULL;
		}

		// shared_ptr.reset°ú µ¿ÀÏ
		inline void reset()
		{
			Reset(); 
		}
 
	private:
		inline void AssignFrom(const Type& other)
		{
			// ÀÌ¹Ì °°Àº°Å¸é ½ºÅµ
			if(other.m_tombstone == m_tombstone)
				return;
 
			// »ó´ëÃø RefCount Áõ°¡
			if(other.m_tombstone)
			{
				AtomicIncrementPtr(&other.m_tombstone->m_count);
			}
 
			// ÀÌÂÊ RefCount °¨¼Ò
			Tombstone* deletePendee = 0;
			if(m_tombstone)
			{
				intptr_t result = AtomicDecrementPtr(&m_tombstone->m_count);
				if(result == 0)
				{
					deletePendee = m_tombstone;
				}
			}
 
			// º»°İ
			m_tombstone = other.m_tombstone;
 
			// ÆÄ±«ÇØ¾ß ÇÏ´Â °´Ã¼ÀÇ µÚ´ÊÀº ÆÄ±«
			if(deletePendee != NULL)
				Tombstone::DeleteInstance(deletePendee);
		}

	public:
		inline Type& operator=(const Type& other)
		{
			AssignFrom(other);
			return *this;
		}
 
		inline operator T* () const
		{
			return m_tombstone ? m_tombstone->m_ptr : 0;
		}
		inline T* operator->() const
		{
			return m_tombstone ? m_tombstone->m_ptr : 0;
		}
		inline T* get() const
		{
			return m_tombstone ? m_tombstone->m_ptr : 0;
		}
 
	};

	/**
	\~korean
	memory page¸¦ ÅëÂ°·Î alloc/freeÇÒ ¶§ À¯¿ëÇÏ´Ù.

	\~english 

	\~chinese
	÷êïÚ?memory page?ú¼alloc/freeîÜ?ı¦êóéÄ¡£

	\~japanese
	memory pageªòü¯ª´ªÈªÇalloc/freeª¹ªëãÁªËêóéÄªÇª¹¡£
	\~
	*/
#if defined(_WIN32)
	template<typename T>
	class CVirtualAllocPage
	{
	public:
		T* m_p;
		size_t m_dwSizeOnFree;
		uint32_t m_dwTypeOnFree;

		CVirtualAllocPage()
		{
			m_p=NULL;
			m_dwSizeOnFree=0;
			m_dwTypeOnFree=0;
		}

		~CVirtualAllocPage()
		{
			if(m_p!=NULL)
				::VirtualFree(m_p,m_dwSizeOnFree,m_dwTypeOnFree);
		}

		/** 
		\~korean 
		memory page¸¦ ÇÒ´çÇÏµÇ ÀÚµ¿ ÇØÁ¦½Ã »ç¿ëµÉ °ªµµ ¹Ì¸® ÀÔ·ÂÇØµĞ´Ù. 
		
		\~english 
		
		\~chinese
		İÂÛÕmemory page£¬ì»ó¦?à»?ìıí»?ú°ğ¶??ù¬ŞÅéÄîÜ?¡£

		\~japanese
		memory pageªòùÜªê?ªÆªëª¬í»ÔÑú°ğ¶ãÁªËŞÅéÄªµªìªëö·ªâîñªâªÃªÆìıÕôª·ªÆöÇª­ªŞª¹¡£ 
		\~
		*/
		void VirtualAlloc(void* lpAddress,size_t dwSize,uint32_t flAllocationType,uint32_t flProtect,size_t dwSizeOnFree,uint32_t dwFreeType)
		{
			void* ret = ::VirtualAlloc(lpAddress,dwSize,flAllocationType,flProtect);
			if(ret == NULL)
				ThrowBadAllocException();

			m_p=(T*)ret;
			m_dwSizeOnFree=dwSizeOnFree;
			m_dwTypeOnFree=dwFreeType;
		}

	public:
#pragma push_macro("new")
#undef new
		// ÀÌ Å¬·¡½º´Â ProudNet DLL °æ¿ì¸¦ À§ÇØ Ä¿½ºÅÒ ÇÒ´çÀÚ¸¦ ¾²µÇ fast heapÀ» ¾²Áö ¾Ê´Â´Ù.
		DECLARE_NEW_AND_DELETE
#pragma pop_macro("new")
	};
#endif

#if (_MSC_VER>=1400)
#pragma managed(pop)
#endif

	/**  @} */
}

/**
\~korean
RefCount °´Ã¼¸¦ CFastMapÀÌ³ª CFastSetÀÇ key·Î ¾²·Á¸é ÀÌ Å¸ÀÔÀ» Traits·Î½á »ç¿ëÇÏ¸é ÆíÇÏ´Ù.

\~english
It is convenient to use this type as Traits in order to use RefCount object as key of CFastMap or CFastSet.

\~chinese
ßÌ÷êRefCount?ßÚéÄéÍ CHashMap%ûäíº CFastSet%îÜkey£¬÷êó®?ŞÅéÄà÷Traits?ÌÚÛ°øµ¡£

\~japanese
RefCount «ª«Ö«¸«§«¯«ÈªòCFastMapªÈª«CFastSetªÎ«­?ªÇŞÅª¦ª¿ªáªËªÏ¡¢ª³ªÎ«¿«¤«×ªòTraitsªÈª·ªÆŞÅª¨ªĞ?ªÇª¹¡£
\~
*/
template<typename T>
class CPNElementTraits<Proud::RefCount<T> >
{
public:
	typedef Proud::RefCount<T> Type;
	typedef const Type& INARGTYPE;
	typedef Type& OUTARGTYPE;

	inline static uint32_t Hash(INARGTYPE a)
	{
		uintptr_t v = (uintptr_t)a.get();
		return CPNElementTraits<uintptr_t>::Hash(v);
	}

	/**
	\~korean
	µÎ Element¸¦ ºñ±³ÇÑ´Ù.
	\param element1 ºñ±³ÇÒ Ã¹¹øÂ° element
	\param element2 ºñ±³ÇÒ µÎ¹øÂ° element
	\return °°À¸¸é true °°Áö ¾ÊÀ¸¸é false

	\~english '
	Compare two elements
	\param element1 First element to be compared
	\param element2 Second element to be compared
	\return True if the same, otherwise false. 


	\~chinese
	İï???Element¡£
	\param element1 é©İï?îÜğ¯ìé?element¡£
	\param element2 é©İï?îÜğ¯ì£?element¡£
	\return ßÓÔÒîÜ?true£¬ÜôÔÒîÜ?false¡£

	\~japanese
	?ElementªòİïÎòª·ªŞª¹¡£
	\param element1 İïÎòª¹ªë1ÛãÙÍªÎelement
	\param element2 İïÎòª¹ªë2ÛãÙÍªÎelement
	\return ÔÒª¸ªÇª¢ªìªĞtrue¡¢ÔÒª¸ªÇªÏªÊª±ªìªĞfalse
	\~
	*/
	inline static bool CompareElements(INARGTYPE element1, INARGTYPE element2)
	{
		return element1.get() == element2.get();
	}

	/**
	\~korean
	µÎ Element¸¦ ºñ±³ÇÑ´Ù.
	\param element1 ºñ±³ÇÒ Ã¹¹øÂ° element
	\param element2 ºñ±³ÇÒ µÎ¹øÂ° element
	\return element1ÀÌ ´õ Å©¸é 1, ÀÛÀ¸¸é -1, °°À¸¸é 0

	\~english 
	Compare two elements
	\param element1 First element to be compared
	\param element2 Second element to be compared
	\return 1 if element 1 is bigger, -1 if smaller, 0 if equal. 


	\~chinese
	İï???Element¡£
	\param element1 é©İï?îÜğ¯ìé?element¡£
	\param element2 é©İï?îÜğ¯ì£?element¡£
	\return element1ÌÚÓŞîÜ?1£¬á³îÜ?-1£¬ßÓÔÒîÜ?0¡£

	\~japanese
	?ElementªòİïÎòª·ªŞª¹¡£
	\param element1 İïÎòª¹ªë1ÛãÙÍªÎelement
	\param element2 İïÎòª¹ªë1ÛãÙÍªÎelement
	\return element1ª¬ªâªÃªÈÓŞª­ª±ªìªĞ1¡¢á³ªµª±ªìªĞ-1¡¢ÔÒª¸ªÇª¢ªìªĞ0
	\~
	*/
	inline static int CompareElementsOrdered(INARGTYPE element1, INARGTYPE element2)
	{
		if (element1.get() < element2.get())
			return -1;
		if (element1.get() == element2.get())
			return 0;
		return 1;
	}

};


#ifdef _MSC_VER
#pragma pack(pop)
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif 
