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

#include <exception>
#include "BasicTypes.h"
#include "PNString.h"
#include "Enums.h"
#include "Ptr.h"

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4324)
#endif // __MARMALADE__

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{

	/** \addtogroup util_group
	*  @{
	*/
	class ErrorInfo;

	/**
	\~korean
	Exception Type °´Ã¼
	- typeÀ¸·Î ±¸ºĞÇÏ¿© ÇØ´ç exception °´Ã¼ÀÇ Æ÷ÀÎÅÍ ¹× Á¤º¸¸¦ ¾òÀ»¼ö ÀÖ½À´Ï´Ù.

	\~english
	Exception Type object
	- You can get pointer and information of exception object by classifying type.

	\~chinese
	Exception Type?ßÚ
	- ë¦type?İÂı¨Ê¦ì¤?ÔğßÓ?exception?ßÚîÜò¦?ĞàãáãÓ¡£

	\~japanese
	Exception Type «ª«Ö«¸«§«¯«È
	- typeªÇ?İÂª·ªÆú±?exception«ª«Ö«¸«§«¯«ÈªÎ«İ«¤«ó«¿?ĞàªÓï×ÜÃªòÔğªëª³ªÈª¬ªÇª­ªŞª¹¡£
	\~
	*/
	enum ExceptionType
	{
		/**
		\~korean
		¾øÀ½

		\~english
		None

		\~chinese
		Ùé

		\~japanese
		ªÊª·
		\~
		*/
		ExceptionType_None = 0,

		/**
		\~korean
		 Exception(LPCWSTR pFormat, ...); À¸·Î »ı¼ºµÈ Exception

		\~english
		Exception that created by Exception(LPCWSTR pFormat, ...);

		\~chinese
		ßæà÷?Exception(LPCWSTR pFormat, ...);îÜException¡£

		\~japanese
		Exception(LPCWSTR pFormat, ...); ª«ªéßæà÷ªµªìª¿ Exception
		\~
		*/
		ExceptionType_String,

		/**
		\~korean
		Exception(std::exception& src); À¸·Î »ı¼ºµÈ Exception

		\~english
		Exception that created by Exception(std::exception& src);

		\~chinese
		ßæà÷?Exception(std::exception& src);îÜException¡£

		\~japanese
		Exception(std::exception& src); ª«ªéßæà÷ªµªìª¿ Exception
		\~
		*/
		ExceptionType_Std,

		/**
		\~korean
		Exception(_com_error& src); À¸·Î »ı¼ºµÈ Exception

		\~english
		Exception that created by Exception(_com_error& src);

		\~chinese
		ßæà÷?Exception(_com_error& src);îÜException¡£

		\~japanese
		Exception(_com_error& src); ª«ªéßæà÷ªµªìª¿ Exception
		\~
		*/
		ExceptionType_ComError,

		/**
		\~korean
		Exception(void* src); À¸·Î »ı¼ºµÈ Exception

		\~english
		Exception that created by Exception(void* src);

		\~chinese
		ßæà÷?Exception(void* src);îÜException¡£

		\~japanese
		Exception(void* src); ª«ªéßæà÷ªµªìª¿ Exception
		\~
		*/
		ExceptionType_Void,

		/**
		\~korean
		Exception(ErrorInfo* src); À¸·Î »ı¼ºµÈ Exception

		\~english
		Exception that created by Exception(ErrorInfo* src);

		\~chinese
		ßæà÷?Exception(ErrorInfo* src);îÜException¡£

		\~japanese 
		Exception(ErrorInfo* src); ª«ªéßæà÷ªµªìª¿ Exception
		\~
		*/
		ExceptionType_ErrorInfo,

		/**
		\~korean
		Exception() À¸·Î »ı¼ºµÈ UnhandleException

		\~english
		UnhandleException that created by Exception()

		\~chinese
		ßæà÷?Exception()îÜUnhandleException¡£

		\~japanese
		Exception() ª«ªéßæà÷ªµªìª¿ UnhandleException
		\~
		*/
		ExceptionType_Unhandled,

		/**
		\~korean
		CLRÀ» »ç¿ëÇÏ´Â °æ¿ì Managed code¿¡¼­ ¹ß»ıÇÑ Exception

		\~english
		Exception occurred in the managed code in case of using a CLR. 

		\~chinese
		ŞÅéÄCLR?î¤Managed codeñé?ßæîÜException

		\~japanese
		CLRªòŞÅéÄª¹ªëíŞùê¡¢Managed codeªèªê?ßæª·ª¿Exception

		\~
		*/
		ExceptionType_Clr
	};

	/**
	\~korean
	printf()Ã³·³ ¿¡·¯ ¸Ş½ÃÁö¸¦ ¹Ş¾Æ º¸³¾ ¼ö ÀÖ´Â exception °´Ã¼.
	Åë»ó ´ÙÀ½°ú °°ÀÌ ¾´´Ù.

	\~english
	An exception object that can receive and send an error message as printf().
	It's commonly used as followed.

	\~chinese
	ßÀprintf()ìé?ÒöïÈâ¥??áê??ãáãÓîÜexception?ßÚ¡£
	ìéÚõ?ìıåıù»¡£

	\~japanese
	printf()ªÎªèª¦ªË«¨«é?«á«Ã«»?«¸ªòáôª±ªÆáêªëª³ªÈª¬ªÇª­ªëexception«ª«Ö«¸«§«¯«È
	÷×ßÈ¡¢ó­ªÎªèª¦ªËŞÅéÄª·ªŞª¹¡£

	\~

	\code
		throw Exception("error=%d",error);
	\endcode

	*/
	class Exception : public std::exception // std::exceptionÀº defacto C++ Ç¥ÁØÀÓ. Áö¿ìÁö ¸» °Í!
	{
	private:
		void operator= (const Exception& src);

	public:
		/**
		\~korean
		Exception À» À¯¹ß½ÃÅ² remote ÀÇ hostID

		\~english
		hostID of remote that occured Exception

		\~chinese
		??ExceptionîÜremoteîÜhost ID¡£

		\~japanese
		Exception ªòë¯?ªµªìª¿remoteªÎhostID
		\~
		*/
		HostID m_remote;

		/**
		\~korean
		void*Çü Exception °´Ã¼ÀÇ Æ÷ÀÎÅÍ¸¦ ÀúÀåÇÑ´Ù.

		\~english
		Save pointer of void*type Exception object

		\~chinese
		?ğívoid*úşException?ßÚîÜò¦?¡£

		\~japanese
		void*úşException«ª«Ö«¸«§«¯«ÈªÎ«İ«¤«ó«¿?ªòÜÁğíª·ªŞª¹¡£
		\~
		*/
		void* m_pVoidSource;

		/**
		\~korean
		std::exception °´Ã¼ÀÇ Æ÷ÀÎÅÍ¸¦ ÀúÀåÇÑ´Ù.

		\~english
		Save pointer of std::exception object

		\~chinese
		?ğí std::exception%?ßÚîÜò¦?¡£

		\~japanese
		std::exception «ª«Ö«¸«§«¯«ÈªÎ«İ«¤«ó«¿?ªòÜÁğíª·ªŞª¹¡£
		\~
		*/
		std::exception *m_pStdSource;

		/**
		\~korean
		Exception Type °´Ã¼

		\~english
		Exception Type object

		\~chinese
		Exception Type?ßÚ¡£

		\~japanese
		Exception Type «ª«Ö«¸«§«¯«È
		\~
		*/
		ExceptionType m_exceptionType;

		/**
		\~korean
		ErrorInfo °´Ã¼ÀÇ º¹Á¦º»À» ÀúÀåÇÑ´Ù.

		\~english 
		Save the copy of ErrorInfo object. 

		\~chinese 
		ÜÁğíErrorInfo?ßÚîÜÜùÜâ¡£

		\~japanese 
		ErrorInfo «ª«Ö«¸«§«¯«ÈªÎ«³«Ô?ªòÜÁğíª·ªŞª¹¡£
		\~
		*/
		RefCount<ErrorInfo> m_errorInfoSource;

		/**
		\~korean
		- »ç¿ëÀÚ Á¤ÀÇ Äİ¹é¿¡¼­ ExceptionÀÌ ¹ß»ıÇÑ °æ¿ì ÇØ´ç ÇÔ¼ö¸íÀÌ ±â·ÏµË´Ï´Ù.
		- »ç¿ëÀÚ Á¤ÀÇ RMI Stub¿¡¼­ ExceptionÀÌ ¹ß»ıÇÑ °æ¿ì ÇØ´ç RMI ID°¡ ±â·ÏµË´Ï´Ù.

		\~english
		- The relevant name of function will be recorded in case exception occurs at user definition callback.
		- The relevant RMI ID will be recorded in case exception occurs at user definition RMI Stub.

		\~chinese
		- î¤í»ïÒ?Callbackñé?ßæException?£¬?ùŞ?Ù£?ù¬??¡£
		- î¤í»ïÒ?RMI Stubñé?ßæException?£¬?RMI ID?ù¬??¡£

		\~japanese
		- «æ?«¶?ïÒëùCallbackª«ªéExceptionª¬?ßæª·ª¿íŞùê¡¢ú±???Ù£ª¬ÑÀ?ªµªìªŞª¹¡£
		- «æ?«¶?ïÒëùRMI Stubª«ªéExceptionª¬?ßæª·ª¿íŞùê¡¢ú±?RMI IDª¬ÑÀ?ªµªìªŞª¹¡£
		\~
		*/
		String m_userCallbackName;

		/**
		\~korean
		- »ç¿ëÀÚ Á¤ÀÇ Äİ¹é¿¡¼­ ExceptionÀÌ ¹ß»ıÇÑ °æ¿ì ÇØ´ç Äİ¹éÀÌ ±¸ÇöµÈ °´Ã¼(SetEventSink·Î µî·ÏÇÑ °´Ã¼)ÀÇ ÁÖ¼Ò°¡ ÀÔ·ÂµË´Ï´Ù.
		- »ç¿ëÀÚ Á¤ÀÇ RMI Stub¿¡¼­ ExceptionÀÌ ¹ß»ıÇÑ °æ¿ì ÇØ´ç StubÀÌ ±¸ÇöµÈ IRmiStub°´Ã¼(AttachStubÀ¸·Î µî·ÏÇÑ °´Ã¼)ÀÇ ÁÖ¼Ò°¡ ÀÔ·ÂµË´Ï´Ù.
		- m_userCallbackNameÀ¸·Î ¹®Á¦ÀÇ ÇÔ¼ö¸¦ ÆÇº°ÇÏ±â ¾î·Á¿î °æ¿ì ÀÌ º¯¼öÀÇ °ªÀÌ ÈùÆ®°¡ µÉ ¼ö ÀÖ½À´Ï´Ù.

		\~english
		- In case exception occurs at user definition callback, the address of object that has been registered by SetEventSink will be inputted.
		- In case exception occurs at user definition RMI Stub, the address of IRmiStub object that has been registered by AttachStub will be inputted.
		- This variable value could be the hint in case it is difficult to find out the problematic function by m_userCallbackName.

		\~chinese
		- î¤í»ïÒ?Callbackñé?ßæException?£¬ ?Callbacká¶??îÜ?ßÚ£¨ì¤SetEventSinkñ¼?îÜ?ßÚ£©îÜò¢ò£?ù¬?ìı¡£
		- î¤í»ïÒ?RMI Stubñé?ßæException?£¬ ?Stubá¶??îÜIRmiStub?ßÚ£¨ì¤AttachStubñ¼?îÜ?ßÚ£©îÜò¢ò£?ù¬?ìı¡£
		- ì¤m_userCallbackName??÷÷???ùŞ??£¬????å¥?ãÀğ«ãÆ¡£


		\~japanese
		- «æ?«¶?ïÒëùCallbackª«ªéExceptionª¬?ßæª·ª¿íŞùê¡¢ú±?Callbackª¬ÎıúŞªµªìª¿«ª«Ö«¸«§«¯«È(SetEventSinkªÈÔô?ªµªìª¿«ª«Ö«¸«§«¯«È)ªÎ«¢«É«ì«¹ª¬ìıÕôªµªìªŞª¹¡£
		- «æ?«¶?ïÒëùRMI Stubª«ªéExceptionª¬?ßæª·ª¿íŞùê¡¢ú±?Stubª¬ÎıúŞªµªìª¿IRmiStub«ª«Ö«¸«§«¯«È(AttachStubªÈÔô?ªµªìª¿«ª«Ö«¸«§«¯«È)ªÎ«¢«É«ì«¹ª¬ìıÕôªµªìªŞª¹¡£
		- m_userCallbackNameªÇÙığ¹ªÎ??ªò÷÷Ü¬ª·ªËª¯ª¤íŞùê¡¢ª³ªÎ??ªÎö·ª¬«Ò«ó«ÈªËªÊªêªŞª¹¡£

		\~
		*/
		void* m_delegateObject;

		StringA chMsg;// public because of Exception_UpdateFromComError

	public:
		PROUD_API Exception(void);
		PROUD_API Exception(const char* text);
		PROUD_API Exception(const wchar_t* text);
		PROUD_API Exception(std::exception& src);
		PROUD_API Exception(ErrorInfo* src);
		PROUD_API Exception(const Exception& src);

		PROUD_API ~Exception(void) throw();

		/**
		\~korean
		Exception ¿¡ ´ëÇÑ ¹®ÀÚ¿­ Æ÷ÀÎÅÍ¸¦ ¸®ÅÏÇÕ´Ï´Ù.

		\~english 
		Return the string pointer to the exception. 

		\~chinese
		Ú÷üŞ?ExceptionîÜí®İ¬Íúò¦?¡£

		\~japanese
		Exception ªË?ª¹ªëÙşí®Öª«İ«¤«ó«¿?ªò«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		PROUD_API const char *what( ) const throw();

	};

	PROUD_API void XXXHeapChkImpl(int index = 1); // PN DLLÀÌ¸é ÀÌ°Å ¼¼´Ù!

#if defined(CHECK_HEAP_CORRUPTION) && defined(_WIN32)
	#define XXXHeapChk XXXHeapChkImpl
#else
	#if (_MSC_VER>=1500) // 2005 ¹öÁ¯ ÀÌÇÏ¿¡¼­´Â °¡º¯ÀÎÀÚ Áö¿ø¾ÈµÊ.
		#define XXXHeapChk(...)
	#else
		#if defined(_WIN32)
			#define XXXHeapChk __noop
		#else
			#define XXXHeapChk(...)
		#endif
	#endif
#endif

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif

#ifdef _MSC_VER
#pragma warning(pop)
#endif // __MARMALADE__
