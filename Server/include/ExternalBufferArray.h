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
#include "UnsafeMem.h"
#include "sysutil.h"
#include "FastArray.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/

	PROUD_API extern const char* ExternalBufferArrayIsUninitializedError;
	PROUD_API extern const char* ExternalBufferArrayIsInitializedError;

	/** 
	\~korean
	¿ÜºÎ ¹öÆÛ¸¦ »ç¿ëÇÏ´Â ¹è¿­ Å¬·¡½ºÀÔ´Ï´Ù.

	ÁÖÀÇ: ¿ÜºÎ ¹öÆÛ¾È¿¡ ÀÌ¹Ì ÇÒ´çµÈ °´Ã¼µéÀÌ Á¸ÀçÇÏÁö ¾Ê¾Æ¾ß ÇÕ´Ï´Ù. Áï ´Ü¼øÈ÷ ÃÊ±âÈ­µÈ ¸Ş¸ğ¸® ¿µ¿ªÀÌ¾î¾ß ÇÕ´Ï´Ù. ¿Ö³ÄÇÏ¸é
	CArrayWithExternalBuffer °¡ ÃÊ±âÈ­ÇÒ °ÍÀÌ±â ¶§¹®ÀÔ´Ï´Ù. 

	\param TYPE ¹è¿­ÀÇ ¿ø¼Ò Å¸ÀÔÀÔ´Ï´Ù.
	\param RAWTYPE ¹è¿­ ¿ø¼Ò°¡ raw memory copy¸¦ ÇØµµ ¾ÈÀüÇÑ Å¸ÀÔÀÎÁö¿¡ ´ëÇÑ ¿©ºÎÀÔ´Ï´Ù. int´Â ¾ÈÀüÇÏÁö¸¸ std.stringÀº ¾ÈÀüÇÏÁö ¾Ê½À´Ï´Ù.
	¹è¿­ÀÇ Ç×¸ñ Å¸ÀÔÀÌ »ı¼ºÀÚ, ÆÄ±«ÀÚ, º¹»ç ´ëÀÔ ¿¬»êÀÚ°¡ »ç¿ëµÇÁö ¾Ê¾Æµµ µÇ´Â Å¸ÀÔÀÎ °æ¿ì true·Î ÁöÁ¤ÇÒ ¼ö ÀÖ½À´Ï´Ù.
	ÀÌ¸¦ true·Î ÁöÁ¤ÇÏ¸é ¹è¿­¿¡ »ğÀÔ, »èÁ¦, Å©±â º¯°æ µîÀ» ÇÒ ¶§ ³»ºÎÀûÀ¸·Î ¹ß»ıÇÏ´Â ¹è¿­ Ç×¸ñÀÇ »ı¼º, ÆÄ±«, º¹»ç °úÁ¤À» À§ÇØ
	»ı¼ºÀÚ, ÆÄ±«ÀÚ, º¹»ç ´ëÀÔ ¿¬»êÀÚ¸¦ È£ÃâÇÏÁö ¾Ê½À´Ï´Ù. µû¶ó¼­ Ã³¸® ¼Óµµ°¡ Çâ»óµË´Ï´Ù. ±âº»°ªÀº falseÀÔ´Ï´Ù.
	\param INDEXTYPE ¹è¿­ ÃÖ´ë Å©±â ¹× indexÀÇ type. int32,int64,intPtr Áß ÇÏ³ª¸¦ ¾²´Â °ÍÀ» ±ÇÀåÇÕ´Ï´Ù. 32-64bit int°£ casting ºÎÇÏµµ ¹«½Ã ¸øÇÏ¹Ç·Î ÀûÀıÇÑ °ÍÀ» ¾µ °ÍÀ» ±ÇÇÕ´Ï´Ù.
	¿¹¸¦ µé¾î ÆĞÅ¶ Å©±âÀÇ °æ¿ì À¢¸¸ÇÏ¸é 2GB¸¦ ³Ñ´Â °ÍÀ» ¾È ´Ù·ç¹Ç·Î int32¸¦ ±ÇÀåÇÕ´Ï´Ù. ·ÎÄÃ ÇÁ·Î¼¼½º¿¡¼­¸¸ ´Ù·ç´Â °ÍÀÌ¸é intPtrÀ» ±ÇÇÕ´Ï´Ù. ³×Æ®¿öÅ© Åë°è µî 32bit·Î´Â ºÒÃæºĞÇÑ °ªÀ» ´Ù·ç¸é
	int64¸¦ ±ÇÇÕ´Ï´Ù.

	\~english
	Allocation class that uses external buffer

	Note: There must be NO previously allocated object within external buffer. In other words,it must be an initialized memory area since CArrayWithExternalBuffer will be initialized.

	\param TYPE Allocation type
	\param RAWTYPE To check if the type is safe even if array element is processed as ¡°raw memory copy¡±. int is safe but std.string is not safe.
	In case element type of array is not related to constructor, destructor and copy assignment operator, you can set it as ¡°true¡±. 
	If setting it as ¡°true¡±, constructor, destructor and copy assignment will not be called for progression of construction, destruction and copy of array element that internally occurs when inserting & deleting & changing size.
	Therefore, processing speed will be improved. 
	Default is ¡°false¡±.
	\param INDEXTYP It is strongly recommended to use the maximum size of array and one of index types like int32,int64 and intPtr.
	Casting load between int32 and int64 should be considered, so using the appropriate one is recommended. 
	For example, packet size should be int32 because it does not exceed 2GB and if it is only for local process, intPtr is recommended. 
	int64 is appropriate when int32 cannot deal with accurate value like network statistics.  

	\~chinese
	ŞÅéÄèâİ»?ğí?îÜÛÉÖª?¡£
	ñ¼ëò£ºèâİ»?ğí?Üô?ğíî¤ì«?İÂÛÕîÜ?ßÚ¡£???ãÀ??ôøã·ûùîÜ?ğí?æ´¡£ì×? CArrayWithExternalBuffer%??ú¼ôøã·?¡£

	\param TYPE ÛÉÖªîÜêªáÈ?úş¡£
	\param RAWTYPE ???ÙÍ?ú¼raw memory copyãÀÜúãÀäÌîïîÜ?úş¡£Int ?æÔäÌîï£¬Ó£ std.string%ÜôäÌîï¡£
	åıÍıÛÉÖªîÜ?ÙÍ?úşÊ¦ì¤ÜôŞÅéÄConstructor¡¢Destructor¡¢?ğ¤???ß©İ¬£¨Copy Assignment Operator£©Ñá?Ê¦ì¤ò¦ïÒ?true¡£
	åıÍı?Ğìò¦ïÒ?true£¬î¤?ÛÉÖª?ú¼?ìı¡¢?ğ¶¡¢?ÌÚÓŞá³ÔõğÃíÂ?£¬?Öõ?ú¼î¤?İ»?ßæîÜÛÉÖª?ÙÍîÜßæà÷¡¢÷ò?¡¢?ğ¤?ïï£¬Üôû¼Ğ£Constructor¡¢Destructor¡¢?ğ¤???ß©İ¬¡£
	??ğ«ÍÔ?×âáÜÓø¡£Ğìôøã·??false¡£
	\param INDEXTYP Ëï?î¤??õÌÓŞÓŞá³ĞàindexîÜtype. int32,int64,intPtr ñıñéŞÅéÄìé?¡£32-64bit int ñı?îÜcasting?ùÃå¥ÜôÒöûì?£¬á¶ì¤Ëï?ŞÅéÄıæ?îÜÛ°Ûö¡£
	ÖÇåı?ËßøĞÓŞá³ĞñÜâÔ´ÜôŞÅéÄõ±?2GBîÜ£¬á¶ì¤Ëï?ŞÅéÄint32¡£ŞÅéÄÜâò¢ïïßíîÜ?Ëï?intPtr¡£åıû»????Ôõ?ŞÅ××éÄ32bitå¥ÜôõöİÂîÜ?£¬Ëï?éÄint64¡£

	\~japanese
	èâİ»«Ğ«Ã«Õ«¡?ªòŞÅª¦ÛÕÖª«¯«é«¹ªÇª¹¡£

	ª´ñ¼ëò£ºèâİ»«Ğ«Ã«Õ«¡??ªË?ªËùÜªê?ªÆªéªìª¿«ª«Ö«¸«§«¯«Èª¬ğíî¤ª·ªÆªÏª¤ª±ªŞª»ªó¡£?ªÁ¡¢?âíªËôøÑ¢ûùªµªìª¿«á«â«ê?ÖÅæ´ªÇªÏªÊª±ªìªĞªÊªêªŞª»ªó¡£ªÊª¼ªÊªé¡¢CArrayWithExternalBufferª¬ôøÑ¢ûùªµªìªëª«ªéªÇª¹¡£
	\param TYPE ÛÕÖªªÎêªáÈ«¿«¤«×ªÇª¹¡£
	\param RAWTYPE ÛÕÖªêªáÈª¬raw memory copyªòª·ªÆªâäÌîïªÊ«¿«¤«×ªÊªÎª«ªË?ª¹ªëÊ¦ÜúªÇª¹¡£IntªÏäÌîïªÇª¹ª¬¡¢std.stringªÏäÌîïªÇªÏª¢ªêªŞª»ªó¡£
	ÛÕÖªªÎú£ÙÍ«¿«¤«×ª¬ßæà÷í­¡¢÷ò?í­¡¢«³«Ô?ÓÛìıæÑß©í­ª¬ŞÅªïªìªÊª¯ªÆªâÕŞª¤«¿«¤«×ªÇª¢ªëíŞùê¡¢trueªËò¦ïÒª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
	ª³ªìªòtureªËò¦ïÒª¹ªëªÈÛÕÖªªË?ìı¡¢Şûğ¶¡¢«µ«¤«º?ÌÚªÊªÉªòª¹ªëãÁ¡¢?İ»îÜªË?ßæª¹ªëÛÕÖªú£ÙÍªÎßæà÷¡¢÷ò?¡¢«³«Ô?Î¦ïïªÎª¿ªáªË¡¢ßæà÷í­¡¢÷ò?í­¡¢«³«Ô?ÓÛìıæÑß©í­ªòû¼ªÓõóª·ªŞª»ªó¡£ªèªÃªÆ¡¢?×âáÜÓøª¬ú¾ß¾ªµªìªŞª¹¡£ĞñÜâö·ªÏfalseªÇª¹¡£
	\param INDEXTYPEÛÕÖªõÌÓŞ«µ«¤«ºªªªèªÓindexªÎtype. int32¡¢int64¡¢intPtrªÎª¦ªÁìéªÄªòŞÅª¦ª³ªÈªòªª?ªáª·ªŞª¹¡£32-64bit intÊàªÎcastingİ¶ùÃªâÙíãÊªÇª­ªŞª»ªóªÎªÇîêï·ªÊªâªÎªòŞÅª¦ª³ªÈªòªª?ªáª·ªŞª¹¡£
	ÖÇª¨ªĞ¡¢«Ñ«±«Ã«ÈªÎ«µ«¤«ºªÎíŞùê¡¢ªÇª­ªìªĞ2GBªòõ±Î¦ª·ªÊª¤ªâªÎªÏĞâªïªÊª¤ªÎªÇint32ªòªª?ªáª·ªŞª¹¡£«í?«««ë«×«í«»«¹ªÇªÎªßĞâª¤ªâªÎªÊªéintPtrªòªª?ªáª·ªŞª¹¡£«Í«Ã«È«ï?«¯÷ÖÍªªÊªÉ32bitªÇªÏÜôä¨İÂªÊö·ªòĞâª¨ªĞint64ªòªª?ªáª·ªŞª¹¡£

	\~
	*/
	template < typename TYPE, bool TYPE_IN_REF = true, bool RAWTYPE = false, typename INDEXTYPE = intptr_t>
	class CArrayWithExternalBuffer :public CFastArray < TYPE, TYPE_IN_REF, RAWTYPE, INDEXTYPE >
	{
		/****************************
		ÁÖÀÇ!!! °íÁ¤ Å©±â ¹è¿­À» ¸â¹ö·Î °¡Áö´Â ·ÎÄÃ º¯¼ö°¡ ÀÌ°Í°ú´Â PS4¿¡¼­ ²¿ÀÎ´Ù!! 
		*/

	public:
		inline CArrayWithExternalBuffer(void *buffer, INDEXTYPE capacity)
		{
			// CFastArray¿¡¼­ ¼³Á¤µÇ¾ú´ø »óÅÂ¸¦ º¯Á¶ÇÑ´Ù.
			this->m_Capacity = capacity;
			this->m_Data = (TYPE*)buffer;
		}

		

		/**
		\~korean
		NULLÀÌ¸é ¿¹¿Ü¸¦ ³½´Ù

		\~english TODO:translate needed.
		Generate an exception if null. 

		\~chinese
		NULL îÜ??ÖÇèâ¡£

		\~japanese
		NULLªÇª¢ªìªĞÖÇèâªËªÊªêªŞª¹¡£
		\~
		*/
		inline void MustNotNull() const
		{
			if (this->m_Data == NULL)
				ThrowException(ExternalBufferArrayIsUninitializedError);
		}
		
		/**
		\~korean
		NULLÀÌ ¾Æ´Ï¸é ¿¹¿Ü¸¦ ³½´Ù

		\~english TODO:translate needed.
		Generate an exception if not null.

		\~chinese
		ÜôãÀNULLîÜ?ÖÇèâ¡£

		\~japanese
		NULLªÇªÏªÊª±ªìªĞÖÇèâªËªÊªêªŞª¹¡£
		\~
		*/
		inline void MustNull() const
		{
			if (this->m_Data != NULL)
				ThrowException(ExternalBufferArrayIsInitializedError);
		}

		/**
		\~korean
		ÇöÀç NULLÀÌ´Ù

		\~english TODO:translate needed.
		It¡¯s null now

		\~chinese
		?î¤ãÀNULL¡£

		\~japanese
		úŞî¤NULLªÇª¹¡£
		\~
		*/
		inline bool IsNull() const
		{
			return this->m_Data == NULL;
		}

		/** 
		\~korean 
		¼¼ÆÃÇÑ´Ù.
		\param buffer bufferÆ÷ÀÎÅÍ 
		\param capacity ¹öÆÛÀÇ Å©±â 

		\~english TODO:translate needed.
		Set it up. 
		\param buffer buffer pointer
		\param capacity buffer size

		\~chinese
		?öÇ¡£
		\param buffer bufferò¦?¡£
		\param capacity bufferîÜÓŞá³¡£		

		\~japanese
		àâïÒª·ªŞª¹¡£
		\param buffer buffer«İ«¤«ó«¿?
		\param capacity «Ğ«Ã«Õ«¡?ªÎ«µ«¤«º
		\~
		*/
		inline void Init(void* buffer, INDEXTYPE capacity)
		{
			MustNull();

			if(buffer == 0 || capacity == 0)
				return;   // ÀÏºÎ·¯ ÀÌ·¸°Ô ¼³Á¤ÇÏ´Â °æ¿ìµµ ÀÖÀ» ¼ö ÀÖ´Ù. ÀÌ·¯ÇÑ °æ¿ì ¾Æ¹« °Íµµ Ã³¸®ÇÏÁö ¸»°í ¸®ÅÏÇØ¾ß ÇÑ´Ù. ÀÌ°ÍÀ» ¿øÇÏ´Â ¾÷Ã¼°¡ ÀÖ¾ú´Ù.

			// »óÅÂ¸¦ º¯Á¶ÇÑ´Ù.
			this->m_Capacity = capacity;
			this->m_Length = 0;
			this->m_Data = (TYPE*)buffer;
		}

		/**
		\~korean
		¸ğµç ¸â¹ö º¯¼ö¸¦ ÃÊ±âÈ­ ÇÑ´Ù.

		\~english TODO:translate needed.
		Initialize all member parameters. 

		\~chinese
		ôøã·ûùá¶êóà÷???¡£

		\~japanese
		îïªÆªÎ«á«ó«Ğ?ªÎ??ªòôøÑ¢ûùª·ªŞª¹¡£
		\~
		*/
		inline void Uninit()
		{
			this->SetCount(0); // ÀÌ°É ÇØÁÖ¾î¼­ ¿ÏÀü ÃÊ±âÈ­ºÎÅÍ ÇØ ¹ö·Á¾ß!
			this->m_Capacity = 0;
			this->m_Length = 0;
			this->m_Data = NULL;
		}

		inline CArrayWithExternalBuffer()
		{
			this->m_Capacity = 0;
			this->m_Length = 0;
			this->m_Data = NULL;
		}

		inline ~CArrayWithExternalBuffer()
		{
			// ÀÌ°É ÇØÁà¾ß »óÀ§ Å¬·¡½ºÀÇ ÆÄ±«ÀÚ¿¡¼­ DataBlock_Free¸¦ È£Ãâ ¾ÈÇÑ´Ù.
			// ÀÌ ÇÔ¼ö°¡ ¸®ÅÏÇÒ ¶§¿¡´Â »ç½Ç»ó ¸ğµç°Ô Ã»¼ÒµÈ »óÅÂÀÌ¾î¾ß ÇÑ´Ù.
			if (IsNull() == false)
			{
				this->SetCount(0);
				this->m_Data = NULL; 
			}
		}

		/**
		\~korean 
		dest¿Í ¹öÆÛ¸¦ °øÀ¯ÇÑ´Ù. 

		\~english Shares data with dest.

		\~chinese
		dest ?destÍìú½?ğí?¡£

		\~japanese
		DestªÈ«Ğ«Ã«Õ«¡?ªòÍêĞåª·ªŞª¹¡£
		\~
		*/
		inline void ShareTo(CArrayWithExternalBuffer& dest) const
		{
			dest.m_Capacity = this->m_Capacity;
			dest.m_Data = this->m_Data;
			dest.m_Length = this->m_Length;
		}
	private:



		/* 
		\~korean
		º¹»ç ÀÚÃ¼´Â ±İÁöµÈ´Ù. CopyTo ¶Ç´Â ShareTo¸¦ ½á¾ß ÇÑ´Ù.
		ÀÌ·¸°Ô µÇ¾î ÀÖ´Â ÀÌÀ¯´Â, CArrayWithExternalBuffer ´Â = ¿¬»êÀÚ¸¦ ¾µ °æ¿ì ÀÌ°ÍÀÌ
		Æ÷ÀÎÅÍ °øÀ¯ÀÎÁö, ³»¿ë¹° º¹»çÀÎÁö°¡ ¸ğÈ£ÇÏ±â ¶§¹®ÀÌ´Ù.

		\~english
		Duplication itself is prohibited. Must use CopyTo or ShareTo.
		The reason why is that it is unclear whether CArrayWithExternalBuffer is a pointer share or copying contents 
		when CArrayWithExternalBuffer uses '=' opeartor.

		\~chinese
		?ğ¤ÜâãóãÀù¬Ğ×ò­îÜ¡£é©ŞÅéÄCopyToûäíºShareTo¡£
		ì×?£¬ŞÅéÄ CArrayWithExternalBuffer%?ß©íºîÜ?£¬???ïÒĞìãÀò¦?Íìú½?ãÀ?é»?ğ¤¡£

		\~japanese
		«³«Ô?í»?ªÏĞ×ò­ªÇª¹¡£CopyToªŞª¿ªÏShareToªòŞÅªÃªÆª¯ªÀªµª¤¡£
		ª³ªÎªèª¦ªËªÊªë×âë¦ªÏ¡¢CArrayWithExternalBufferªÏ=æÑß©í­ªòŞÅª¦íŞùê¡¢ª³ªìª¬«İ«¤«ó«¿?ÍìêóªÊªÎª«¡¢?é»Úª«³«Ô?ªÊªÎª«ª¬äòØÜªÀª«ªéªÇª¹¡£
		\~
		*/
		CArrayWithExternalBuffer& operator=(const CArrayWithExternalBuffer&);
		CArrayWithExternalBuffer(const CArrayWithExternalBuffer&);

		virtual INDEXTYPE GetRecommendedCapacity(INDEXTYPE actualCount)
		{
			// Ç×»ó ÀÌ¹Ì ÀâÇôÀÖ´Â ¿ÜÀå ¸Ş¸ğ¸®ÀÇ Å©±â¸¦ Áà¾ß.
			if (actualCount > this->m_Capacity)
				ThrowArrayOutOfBoundException();
			return this->m_Capacity;
		}

		virtual void DataBlock_Free(void* /*data*/)
		{
			// ÇÏ´Â ÀÏÀÌ ¾ø´Ù. 
			// ÁÖÀÇ: CFastArray°¡ m_Data=null ÇÏ´Â ÀÏÀÌ ¾øÀ½À» °¡Á¤ÇØ¾ß ÇÑ´Ù!
		}

		virtual void* DataBlock_Alloc(size_t length)
		{
			if (length > 0)
			{
				MustNotNull();
			}
			return this->m_Data;
		}

		virtual void* DataBlock_Realloc(void* /*oldPtr*/, size_t newLength)
		{
			if (newLength > 0)
			{
				MustNotNull();
			}
			return this->m_Data;
		}
	};

	/**  @} */
}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
