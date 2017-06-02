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
	JIT ÀÎ½ºÅÏ½Ì¸¸ thread safeÇÏ°Ô ÇÏ´Â singleton template
	- JIT ÀÎ½ºÅÏ½Ì °úÁ¤¸¸ CS lockÀ» ÇØ¼­ thread safeÇÏ°Ô ÇÏ°í, »ı¼ºµÈ ÀÌÈÄºÎÅÍ´Â thread unsafeÇÏ°Ô ÇÑ´Ù.
	- »ı¼º¸¸ thread µ¿±âÈ­ÇÏ°í ÀÌÈÄºÎÅÍ´Â ºÒÇÊ¿äÇÑ °æ¿ì, ¿¹ÄÁ´ë CItemTemplate µî¿¡¼­ ÀÌ °´Ã¼¸¦ ½á¾ß µå¹® ºóµµÀÇ ¼­¹ö ´Ù¿îÀ»
	¿¹¹æ °¡´É.

	ÀÏ¹İÀû ¿ëµµ
	- ÀÌ Å¬·¡½ºÀÇ ÆÄ»ı Å¬·¡½º¸¦ ¸¸µç´Ù. T¿¡´Â ÆÄ»ı Å¬·¡½ºÀÇ ÀÌ¸§À» ³Ö´Â´Ù.
	- Instance()¸¦ ÀÌ¿ëÇØ¼­ ½Ì±ÛÅæÀÇ ·¹ÆÛ·±½º¸¦ ¾ò´Â´Ù. Instance()¸¦ ÃÖÃÊ·Î È£ÃâÇÏ¸é °´Ã¼°¡ ÀÎ½ºÅÏ½ºÈ­µÈ´Ù.
	- ½Ì±ÛÅæ°£ ÆÄ±« ¼ø¼­¸¦ Á¦¾îÇÏ·Á¸é ½Ì±ÛÅæÀÇ »ı¼ºÀÚ¿¡¼­ ÀÇÁ¸ ´ë»ó ½Ì±ÛÅæÀ» ÇÑ¹ø Á¢±ÙÇØÁÖ¸é µÈ´Ù.

	»ç¿ë¿¹
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

	DLL°ú EXE°¡ °°Àº SingletonÀ» ¾²°íÀÚ ÇÏ´Â °æ¿ì
	- CSingletonÀ» DLLÀÌ Á¦°øÇÏ°í EXE°¡ ±×°ÍÀ» ¾²°íÀÚ ÇÏ´Â °æ¿ì¿¡´Â º» Å¬·¡½º¸¦ ´ÙÀ½°ú °°ÀÌ ±¸ÇöÇØ¾ß ÇÑ´Ù. ¾È±×·¯¸é EXE°¡ ¾²´Â singleton°ú
	DLLÀÌ ¾²´Â singletonÀÌ ¼­·Î ´Ù¸¥ ÀÎ½ºÅÏ½º·Î Á¸ÀçÇÏ°Ô µÈ´Ù.
	\code
	class Goofie:protected CSingleton<Goofie> // protected·Î ¼±¾ğÇØ¼­ Instance¸¦ Á÷Á¢ Á¢±ÙÇÏÁö ¸øÇÏ°Ô ÇÑ´Ù.
	{
	public:
	__declspec(dllexport) Goofie& Instance() // CSingleton.Instance()¸¦ ¿À¹ö¶óÀÌµåÇÏµÇ DLL¿¡¼­ exportµÇ´Â ÇÔ¼ö·Î ¸¸µç´Ù.
	{
	return __super::Instance(); // DLL ¸ğµâ ¸Ş¸ğ¸® °ø°£ ³»¿¡ ¸¸µé¾îÁø instance¸¦ ¸®ÅÏÇÑ´Ù.
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
	ñş÷êJIT instancing?ú¼à÷thread safeîÜsingleton template¡£
	- ñş÷êJIT instancing?ïïCS lockì¤ı¨ŞÅĞìthread safe£¬ßæà÷ì¤ı¨?ã·??thread unsafe¡£
	- ñşÔÒÜÆßæà÷thread£¬ñıı¨Üôù±é©îÜï×?£¬ÖÇåıé©î¤ CItemTemplate%ÔõŞÅéÄó®?ßÚî¦Òö?ÛÁ?á´?áãîÜÜ×?ĞïŞİÏõ¡£

	ìéÚõéÄÔ²
	- ?Ëïó®?îÜ÷ïßæ?¡£èÙT×ì?ìı÷ïßæ?îÜÙ£í®¡£
	- ××éÄInstance()?ÔğsingletonîÜreference¡£ôøã·û¼Ğ£Instance()îÜ??ßÚ?instanceûù¡£
	- ßÌé©Íóğ¤singletonñı?îÜ÷ò??ßí£¬é©î¤singletonîÜßæà÷íº×ìïÈĞÎìéó­ëîğí?ßÚîÜsingleton¡£

	ŞÅéÄÖÇ
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

	DLL ûúEXEé©ŞÅéÄßÓÔÒîÜsingletonîÜ?ı¦
	- DLLé©ğ«Íê CSingleton%£¬EXE é©ŞÅéÄ?îÜ?ı¦é©÷êó®?åıù»??¡£Üú?EXEŞÅéÄîÜsingletonûúDLLŞÅéÄîÜsingleton?ğíî¤à÷ÜôÔÒîÜinstance¡£
	\code
	class Goofie:protected CSingleton<Goofie> // éÄprotectedà¾Í±£¬Üô?InstanceòÁïÈïÈĞÎ¡£
	{
	public:
	__declspec(dllexport) Goofie& Instance() // ÜİËÌ CSingleton.Instance()£¬Ó£ãÀğ¤ğãà÷î¤DLLÒöexportîÜùŞ?¡£
	{
	return __super::Instance(); // Ú÷üŞî¤DLLÙ¼??ğíÍö??ğ¤ğãîÜinstance¡£
	}
	};
	\endcode

	\~japanese
	JIT«¤«ó«¹«¿«ó«·«ó«°ªÎªßthread safeª¹ªëªèª¦ªËª¹ªësingleton template
	- JIT«¤«ó«¹«¿«ó«·«ó«°Î¦ïïªÎªßCS lockªòª·ªÆthread safeª¹ªëªèª¦ªËª·ªÆ¡¢ßæà÷ı­ª«ªéªÏthread unsafeª¹ªëªèª¦ªËª·ªŞª¹¡£
	- ßæà÷ªÎªßthreadÔÒÑ¢ûùªòª·ªÆ¡¢ì¤Ë½ª«ªéªÏÜôé©ªÊíŞùê¡¢ÖÇª¨ªĞCItemTemplateªÊªÉªÇª³ªÎ«ª«Ö«¸«§«¯«ÈªòŞÅéÄª¹ªëªÈ¡¢éÏªË?ßæª¹ªë«µ?«Ğ?«À«¦«óªòåøÛÁª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£

	ìéÚõîÜªÊéÄÔ²
	- ª³ªÎ«¯«é«¹ªÎ÷ïßæ«¯«é«¹ªòíÂªêªŞª¹¡£TªËªÏ÷ïßæ«¯«é«¹ªÎÙ£îñªòìıªìªŞª¹¡£
	- Instance()ªò××éÄª·ªÆ«·«ó«°«ë«È?«óªÎ«ì«Õ«¡«ì«ó«¹ªòÔğªŞª¹¡£Instance()ªòôøªáªÆû¼ªÓõóª¹ªÈ«ª«Ö«¸«§«¯«Èª¬«¤«ó«¹«¿«ó«ÈûùªµªìªŞª¹¡£
	- «·«ó«°«ë«È?«óÊàªÎ÷ò?â¢â÷ªòğ¤åÙª¹ªëª¿ªáªËªÏ¡¢«·«ó«°«ë«È?«óªÎßæà÷í­ªèªêëîğí?ßÚ«·«ó«°«ë«È?«óªòìéÓø«¢«¯«»«¹ª·ªÆª¯ªÀªµª¤¡£

	ŞÅéÄÖÇ
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

	DLLªÈEXEª¬ÔÒª¸SingletonªòŞÅªªª¦ªÈª¹ªëíŞùê
	- CSingletonªòDLLª¬ğ«Íêª·ªÆEXEª¬ª½ªìªòŞÅªªª¦ªÈª¹ªëíŞùêªËªÏ¡¢ª³ªÎ«¯«é«¹ªòó­ªÎªèª¦ªË?úŞª·ªÊª±ªìªĞªÊªêªŞª»ªó¡£ª½ªìªÇªÏªÊª±ªìªĞ¡¢EXEª¬ŞÅª¦singletonªÈDLLª¬ŞÅª¦singletonª¬ªªû»ª¤êŞª¦«¤«ó«¹«¿«ó«¹ªÇğíî¤ª¹ªëªèª¦ªËªÊªêªŞª¹¡£
	\code
	class Goofie:protected CSingleton<Goofie> // protectedªËà¾åëª·ªÆInstanceªòòÁïÈ«¢«¯«»«¹ªÇª­ªÊª¤ªèª¦ªËª·ªŞª¹¡£
	{
	public:
	__declspec(dllexport) Goofie& Instance() // CSingleton.Instance()ªò«ª?«Ğ?«é«¤«Éª·ªŞª¹ª¬¡¢DLLªèªêexportªµªìªë??ªËíÂªêªŞª¹¡£
	
	return __super::Instance(); // DLL«â«¸«å?«ë«á«â«ê?ÍöÊà?ªËíÂªéªìª¿instanceªò«ê«¿?«óª·ªŞª¹¡£
	}
	};
	\endcode

	

	\~


	\~korean

	¸¸¾à ½Ì±ÛÅæ³¢¸® ÆÄ±« ¼ø¼­¸¦ º¸ÀåÇØ¾ß ÇÏ´Â °æ¿ì, shared pointer °´Ã¼¸¦ ¾ò¾î¼­ º¸°üÇÔÀ¸·Î½á ÆÄ±« ¼ø¼­¸¦ Á¤ÀÇÇÒ ¼ö ÀÖ½À´Ï´Ù.

	\~english

	You can define destruction order of singletons by keeping shared pointer object from singleton.

	\~chinese

	åıÍıé©î¤?ÖÇÙ¼ãÒñı?ÜÁî¡÷ò??ßí£¬Ê¦ì¤?ö¢?ÜÁğíshared pointer?ßÚì¤ïÒ?÷ò??ßí¡£

	\~japanese
	ªâª·¡¢«·«ó«°«ë«È?«óÊàªÇªÎ÷ò?â¢â÷ªòÜÁî¡ª¹ªëù±é©ª¬ª¢ªëíŞùê¡¢shared pointer«ª«Ö«¸«§«¯«ÈªòÔğªÆÜÁÎ·ßÕªŞªÇ÷ò?â¢â÷ªòïÒëùª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£

	\~



	\~korean

	¿¹½Ã ÄÚµå

	\~english

	Example code

	\~chinese

	??ÖÇ¡£

	\~japanese
	ÖÇãÆ«³?«É

	\~


	\~korean

	\code
	// ½Ì±ÛÅæ Å¬·¡½ºÀÔ´Ï´Ù.
	class MySingleton:public CSingleton<MySingleton>
	{
	...
	Something();
	};

	// ½Ì±ÛÅæÀ» Á¢±ÙÇÏ´Â »ç¿ëÀÚÀÔ´Ï´Ù.
	class MyGoo
	{
	// MyGoo ÀÎ½ºÅÏ½º°¡ Á¸ÀçÇÏ´Â µ¿¾È ½Ì±ÛÅæÀÇ »ıÁ¸À» º¸ÀåÇÏ·Á¸é ÀÌ ¸â¹ö¸¦ °®°í ÀÖ¾î¾ß ÇÕ´Ï´Ù.
	// ¹°·Ğ, ½Ì±ÛÅæ Á¢±ÙÀ» À§ÇØ ÀÌ ¸â¹ö¸¦ »ç¿ëÇÏ½Ê½Ã¿À.
	MySingleton::PtrType m_mySingleton;

	// »ı¼ºÀÚ ¸Ş¼­µå
	User()
	{
	// ½Ì±ÛÅæ ÂüÁ¶ Ä«¿îÆ®¸¦ Áõ°¡½ÃÅ°¸é¼­, ½Ì±ÛÅæÀÇ »ıÁ¸À» º¸Àå½ÃÅµ´Ï´Ù.
	m_mySingleton = MySingleton::GetInstanceAccessor();
	}

	Foo()
	{
	...
	// ½Ì±ÛÅæÀ» Á¢±ÙÇÏ·Á¸é ÀÌ¹Ì °®°í ÀÖ´Â ½Ì±ÛÅæ ½º¸¶Æ®Æ÷ÀÎÅÍ °´Ã¼¸¦ ÅëÇØ Á¢±ÙÇÕ´Ï´Ù.
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
	// While MyGoo instance exists, it must have this member in order to assure Singleton¡¯s survival.
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
	// singleton?¡£
	class MySingleton:public CSingleton<MySingleton>
	{
	...
	Something();
	};

	// ïÈĞÎsingletonîÜŞÅéÄíº¡£
	class MyGoo
	{
	// MyGooîÜinstanceğíî¤Ñ¢?£¬ßÌÜÁî¡singletonßæğíîÜ?£¬é©?êóó®à÷?¡£
	// ?ÖõsingletonïÈĞÎ£¬ŞÅéÄó®à÷??¡£
	MySingleton::PtrType m_mySingleton;

	// ßæà÷íºÛ°Ûö
	User()
	{
	// ßÌñòÊ¥singleton?ğÎcountîÜ?£¬Ê¦ì¤ÜÁî¡singletonîÜßæğí¡£
	m_mySingleton = MySingleton::GetInstanceAccessor();
	}

	Foo()
	{
	...
	// ßÌïÈĞÎsingletonîÜ?£¬÷×?ì«??êóîÜsingleton smartpointer?ßÚ?ïÈĞÎ¡£
	m_mySingleton->Something();
	}
	}
	\endcode

	\~japanese
	\code
	// «·«ó«°«ë«È?«ó«¯«é«¹ªÇª¹¡£
	class MySingleton:public CSingleton<MySingleton>
	{
	...
	Something();
	};
	// «·«ó«°«ë«È?«óªò«¢«¯«»«¹ª¹ªë«æ?«¶?ªÇª¹¡£
	class MyGoo
	{
	// MyGoo ÀÎ½ºÅÏ½º°¡ Á¸ÀçÇÏ´Â µ¿¾È ½Ì±ÛÅæÀÇ »ıÁ¸À» º¸ÀåÇÏ·Á¸é ÀÌ ¸â¹ö¸¦ °®°í ÀÖ¾î¾ß ÇÕ´Ï´Ù.
	// MyGoo«¤«ó«¹«¿«ó«¹ª¬ğíî¤ª¹ªëÊàªË«·«ó«°«ë«È?«óªÎßæğíªòÜÁî¡ª¹ªëª¿ªáªËªÏª³ªÎ«á«ó«Ğ?ªòò¥ªÃªÆª¤ªëù±é©ª¬ª¢ªêªŞª¹¡£
	// ¹°·Ğ, ½Ì±ÛÅæ Á¢±ÙÀ» À§ÇØ ÀÌ ¸â¹ö¸¦ »ç¿ëÇÏ½Ê½Ã¿À.
	// ªâªÁªíªó¡¢«·«ó«°«ë«È?«óªÎ«¢«¯«»«¹ªÎª¿ªáªËª³ªÎ«á«ó«Ğ?ªòŞÅªÃªÆª¯ªÀªµª¤¡£
	MySingleton::PtrType m_mySingleton;

	// ßæà÷í­«á«½«Ã«É
	User()
	{

	// «·«ó«°«ë«È?«ó?ğÎ«««¦«ó«Èªò?Ê¥ªµª»ªÊª¬ªé¡¢«·«ó«°«ë«È?«óªÎßæğíªòÜÁî¡ªµª»ªŞª¹¡£
	m_mySingleton = MySingleton::GetInstanceAccessor();
	}

	Foo()
	{
	...

	// «·«ó«°«ë«È?«óªò«¢«¯«»«¹ª¹ªëª¿ªáªËªÏ¡¢?ªËò¥ªÃªÆª¤ªë«·«ó«°«ë«È?«ó«¹«Ş?«È«İ«¤«ó«¿?«ª«Ö«¸«§«¯«Èªò÷×ª¸«¢«¯«»«¹ª·ªŞª¹¡£
	m_mySingleton->Something();
	}
	}

	\endcode

	

	
	\~


	*/

	template<typename T>
	class CSingleton 
	{
		// º¹»ç ¹æÁö : ½Ì±ÛÅÏ °´Ã¼ Æ¯¼º»ó º¹»ç ÄÚµå´Â ÀÖ¾î¼± ¾ÈµË´Ï´Ù.
		NO_COPYABLE(CSingleton)

	public:
		typedef RefCount<T> PtrType;

	public:
		virtual ~CSingleton() { }

	protected:
		// »ı¼º ¹æÁö : ½Ì±ÛÅÏÀ» »ç¿ëÇÒ ¶©, ¹İµå½Ã GetSharedPtr() or GetUnsafeRef() ·Î Á¦ÇÑÇÕ´Ï´Ù.
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

		// ±ÇÀå»çÇ× : GetSharedPtr() »ç¿ëÀ» ¸ÕÀú °í·ÁÇÏ½Ã°í, ¼Óµµ¿¡ ¹Î°¨ÇÏ´Ù¸é, GetUnsafeRef()¸¦ »ç¿ëÇÏ¼¼¿ä.
		static inline T& GetUnsafeRef()
		{
			static T* val = NULL;
			if (!val)
			{
				val = GetSharedPtr();
			}
			return *val;
		}
		

		// »ç¿ëÀÚ°¡ ÀÌ°ÍÀÇ º¯¼ö¸¦ ¸â¹ö·Î °¡Áö´Â µ¿¾È »ç¿ëÀÚÀÇ °´Ã¼°¡ ÆÄ±«µÇ±â Àü¿¡´Â ÀÌ ½Ì±ÛÅæÀÌ ÆÄ±« ¾ÈµÊÀ» º¸ÀåÇÑ´Ù.
		class Holder
		{
			PtrType m_sharedPtr;
		public:
			Holder()
			{
				m_sharedPtr = CSingleton<T>::GetSharedPtr();
			}
			// ÀÌ ÇÔ¼ö°¡ ÀÖ¾î¾ß.
			// ÄÄÆÄÀÏ·¯°¡ ¾Ë¾Æ¼­ ÆÄ»ı Å¬·¡½ºÀÇ µğÆúÆ® ÆÄ±«ÀÚ¸¦ ¸¸µé±â´Â ÇÏ°ÚÁö¸¸, È®ÀÎ »ç»ìÀ» À§ÇØ.
			virtual ~Holder() {}
		};

	private:
		static PtrType& CreateRefCount()
		{
			// #ikpil.choi 2017-01-07 : ½º¸¶Æ® Æ÷ÀÎÅÍÀÇ °´Ã¼¸¦ ÇÔ¼ö È£Ãâ µÚ·Î ¼û°Ü, µÎ¹ø ÀÌ»ó È£Ãâ µÇ¾îµµ, ÇÑ¹ø instance·Î º¯°æÇÑ´Ù.
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
