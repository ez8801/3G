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
#include "UnsafeMem.h"
#include "Exception.h"

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

namespace Proud
{
	/** \addtogroup util_group
	*  @{
	*/


	extern const char* CannotUseFastHeapForFilledCollectionErrorText;


	/**
	\~korean
	ÀÌ °´Ã¼ÀÇ ¹è¿­ Å©±â°¡ Áõ°¡ÇÒ ¶§ °¡ÁßÄ¡ Å¸ÀÔ

	\~english
	The weight type when the size of the array of this object.

	\~chinese
	ó®?ßÚîÜ??ÓŞá³ñòÊ¥îÜ?ı¦Ê¥ñì??úş¡£

	\~japanese
	ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎÛÕÖª«µ«¤«ºª¬?Ê¥ª¹ªëãÁªÎÊ¥ñìö·«¿«¤«×
	\~
	 */
	enum GrowPolicy
	{
		/**
		\~korean
		±ÕÇü

		\~english
		Balance

		\~chinese
		Ğ³û¬

		\~japanese
		«Ğ«é«ó«¹
		\~
		*/
		GrowPolicy_Normal,
		/**
		\~korean
		°í¼º´É. ´ë½Å ¸Ş¸ğ¸® »ç¿ë·®ÀÌ ¸¹À½

		\~english
		High performance but use more memory

		\~chinese
		ÍÔàõÒö¡£Üô??ğíŞÅéÄÕáÒı¡£

		\~japanese
		ÍÔàõÒö¡£ÓÛªïªêªË«á«â«ê?ŞÅéÄÕáª¬Òıª¤ªÇª¹¡£
		\~
		*/
		GrowPolicy_HighSpeed,
		/**
		\~korean
		¸Ş¸ğ¸® Àı°¨. ´ë½Å ¹è¿­ Å©±â°¡ Áõ°¡½Ã º¹»ç ºÎÇÏ·Î ÀÎÇÑ Àú¼º´É.

		\~english
		Save memory but when array size is increased, it shows low performance because of overload of copying

		\~chinese
		?àı?ğí¡£Ó£ãÀ??ßæ??ÓŞá³ñòÊ¥??ğ¤?ùÃìÚÑÃîÜî¸àõÒö¡£

		\~japanese
		«á«â«ê?ï½Êõ¡£ÓÛªïªêªËÛÕÖª«µ«¤«ºª¬?Ê¥ãÁªË«³«Ô?İ¶ùÃªËªèªÃªÆàõÒöª¬ÕªªÁªŞª¹¡£
		\~
		*/
		GrowPolicy_LowMemory,
	};

	// byvalÀÎÁö byrefÀÎÁö¿¡ µû¶ó ¼±ÅÃµÇ¾î »ç¿ëµÇ´Â, Æ¯¼ºÈ­ ÅÛÇÃ¸´ Å¬·¡½º

	template<typename T, bool T_IN_REF>
	struct FastArray_Traits;

	template<typename T>
	struct FastArray_Traits< T, true >
	{
		typedef const T& type;
	};

	template<typename T>
	struct FastArray_Traits< T, false >
	{
		typedef T type;
	};

	/**
	\~korean
	¹è¿­ Å¬·¡½º

	Pritimitive typeÀ» À§ÇÑ ¼º´É Çâ»ó ±â´É
	- RAWTYPE=true·Î ¼¼ÆÃÇÏ¸é, ¹è¿­ ¿ä¼Ò´Â int µîÀÇ primitive Å¸ÀÔÀ¸·Î °£ÁÖµÇ¾î ¹è¿­ ´Ù·ç´Â ¼º´ÉÀÌ Çâ»óµË´Ï´Ù. (¼º´É ±Ø´ëÈ­¸¦ À§ÇØ ³»ºÎÀûÀ¸·Î memcpy µîÀÌ »ç¿ëµË´Ï´Ù.)
	- ´Ü, int, bool, byte µî primitive type¸¸ »ç¿ë °¡´ÉÇÕ´Ï´Ù. »ı¼ºÀÚ, ÆÄ±«ÀÚ, º¹»ç ´ëÀÔ ¿¬»êÀÚ¸¦ µû·Î °¡Áö°í ÀÖ´Â Å¸ÀÔÀÌ ¹è¿­ Ç×¸ñÀ¸·Î ¾²ÀÌ´Â °æ¿ì À§ÇèÇÕ´Ï´Ù.

	ÁÖ¿ä Æ¯Â¡
	- heap Á¢±ÙÀ» ÃÖ¼ÒÈ­ÇÏ±â À§ÇØ auto memory shrink¸¦ ÇÏÁö ¾Ê½À´Ï´Ù.
	Áï capacity´Â Àı´ë ÁÙÁö ¾Ê½À´Ï´Ù. µû¶ó¼­ ¸Ş¸ğ¸® °ú´Ù »ç¿ëÀÇ ¹®Á¦Á¡À» °í·ÁÇØ¾ß ÇÑ´Ù¸é ÀÌ °´Ã¼ÀÇ »ç¿ëÀ» ÇÇÇÏ´Â °ÍÀÌ ÁÁ½À´Ï´Ù.
	- ³»ºÎÀûÀ¸·Î <a target="_blank" href="http://guide.nettention.com/cpp_ko#fast_heap" >Fast heap</a> À» ½á¼­ heap Á¢±ÙÀ¸·Î ÀÎÇÑ ºÎÇÏ¸¦ Àı¾àÇÒ ¼ö ÀÖ½À´Ï´Ù.
	±âº»ÀûÀ¸·Î ÀÌ ±â´ÉÀº ²¨Á®ÀÖ½À´Ï´Ù. ±×·¯³ª, UseFastHeapÀ¸·Î º¯°æ °¡´ÉÇÕ´Ï´Ù.
	- .Net frameworkÀÇ List<>, STL.vector, CAtlArrayÀÇ ¸Ş¼­µå ÀÌ¸§À» ¸ğµÎ ¾µ ¼ö ÀÖ½À´Ï´Ù. ±×¸®°í STL.vector.iterator¿Í °°Àº ¿ªÇÒÀÇ
	iterator classµµ Á¦°øÇÏ°í ÀÖ½À´Ï´Ù.

	\param T ¹è¿­ÀÇ Ç×¸ñ Å¸ÀÔÀÔ´Ï´Ù.
	\param T_IN_REF trueÀÌ¸é, by reference·Î ÀÔ·Â°ªÀÌ Àü´ŞµË´Ï´Ù. falseÀÌ¸é by value·Î Àü´ŞµË´Ï´Ù. int Ã³·³ Å©±â°¡ 8 byte ÀÌÇÏÀÎ °ÍÀº false¸¦ ¾²´Â °ÍÀÌ ±ÇÀåµË´Ï´Ù.
	\param RAWTYPE ¹è¿­ Ç×¸ñÀÌ raw memory copy¸¦ ÇØµµ ¾ÈÀüÇÑ Å¸ÀÔÀÎÁö¿¡ ´ëÇÑ ¿©ºÎÀÔ´Ï´Ù. int´Â ¾ÈÀüÇÏÁö¸¸ std.stringÀº ¾ÈÀüÇÏÁö ¾Ê½À´Ï´Ù.
	¹è¿­ÀÇ Ç×¸ñ Å¸ÀÔÀÌ »ı¼ºÀÚ, ÆÄ±«ÀÚ, º¹»ç ´ëÀÔ ¿¬»êÀÚ°¡ »ç¿ëµÇÁö ¾Ê¾Æµµ µÇ´Â Å¸ÀÔÀÎ °æ¿ì true·Î ÁöÁ¤ÇÒ ¼ö ÀÖ½À´Ï´Ù.
	ÀÌ¸¦ true·Î ÁöÁ¤ÇÏ¸é ¹è¿­¿¡ »ğÀÔ, »èÁ¦, Å©±â º¯°æ µîÀ» ÇÒ ¶§ ³»ºÎÀûÀ¸·Î ¹ß»ıÇÏ´Â ¹è¿­ Ç×¸ñÀÇ »ı¼º, ÆÄ±«, º¹»ç °úÁ¤À» À§ÇØ
	»ı¼ºÀÚ, ÆÄ±«ÀÚ, º¹»ç ´ëÀÔ ¿¬»êÀÚ¸¦ È£ÃâÇÏÁö ¾Ê½À´Ï´Ù. µû¶ó¼­ Ã³¸® ¼Óµµ°¡ Çâ»óµË´Ï´Ù. ±âº»°ªÀº false ÀÔ´Ï´Ù.
	\param INDEXTYPE ¹è¿­ ÃÖ´ë Å©±â ¹× indexÀÇ type. int32,int64,intPtr Áß ÇÏ³ª¸¦ ¾²´Â °ÍÀ» ±ÇÀåÇÕ´Ï´Ù. 32-64bit int°£ casting ºÎÇÏµµ ¹«½Ã ¸øÇÏ¹Ç·Î ÀûÀıÇÑ °ÍÀ» ¾µ °ÍÀ» ±ÇÇÕ´Ï´Ù.
	¿¹¸¦ µé¾î ÆĞÅ¶ Å©±âÀÇ °æ¿ì À¢¸¸ÇÏ¸é 2GB¸¦ ³Ñ´Â °ÍÀ» ¾È ´Ù·ç¹Ç·Î int32¸¦ ±ÇÀåÇÕ´Ï´Ù. ·ÎÄÃ ÇÁ·Î¼¼½º¿¡¼­¸¸ ´Ù·ç´Â °ÍÀÌ¸é intPtrÀ» ±ÇÇÕ´Ï´Ù. ³×Æ®¿öÅ© Åë°è µî 32bit·Î´Â ºÒÃæºĞÇÑ °ªÀ» ´Ù·ç¸é
	int64¸¦ ±ÇÇÕ´Ï´Ù.

	\~english
	Array class

	Performance increase function for primitive type
	- The performance that manages array increases when RAWTYPE=true due to array factors are regarded as primitive type such as int. (In order to maximize the performance, sometimes memcpy can be used internally.)
	- However, only specific primitive types such as int, bool and byte can be used. It can be dangerous that the type with separate constructor, destructor and duplicator is used as array clause.

	Major characteristics
	- Does not perform auto memory shrink in order to minimize heap access
	  In other words, capacity never decreases. Therefore, if the circumstances must consider the side-effects of using too much memory then this object must not be used.
	- Internally, by using <a target="_blank" href="http://guide.nettention.com/cpp_en#fast_heap" >Fast heap</a>, it is possible to decrease the load cuased by heap access.
	  By default, this feature is off. But it can be changed by UseFastHeap.
	- Can use the metohd names of List<> of .Net framework, STL.vector and CAtlArray. And provides interator class that acts as STL.vector.iterator

	\param T Clause type of array
	\param T_IN_REF Set to true if you want the value to be passed by reference, or false for by value. Type of 8 or less of bytes such as int is passed faster if by value is selected.
	\param RAWTYPE To check if the type is safe even if array element is processed as ¡°raw memory copy¡±. int is safe but std.string is not safe.
	In case element type of array is not related to constructor, destructor and copy assignment operator, you can set it as ¡°true¡±.
	If setting it as ¡°true¡±, constructor, destructor and copy assignment will not be called for progression of construction, destruction and copy of array element that internally occurs when inserting & deleting & changing size.
	Therefore, processing speed will be improved.
	Default is ¡°false¡±.
	\param INDEXTYPE It is strongly recommended to use the maximum size of array and one of index types like int32,int64 and intPtr.
	Casting load between int32 and int64 should be considered, so using the appropriate one is recommended.
	For example, packet size should be int32 because it does not exceed 2GB and if it is only for local process, intPtr is recommended.
	int64 is appropriate when int32 cannot deal with accurate value like network statistics.

	\~chinese
	???

	?ÖõPritimitive typeîÜàõÒöğ«ÍÔÍíÒö¡£
	- ?öÇà÷RAWTYPE=true îÜ???ì×áÈ?Ê×íÂintÔõprimitive?úş£¬?öÈŞÅéÄ??îÜàõÒöğ«ÍÔ£¨?ÖõàõÒöîÜ?ÓŞûù£¬?İ»ŞÅéÄmemcpyÔõ¡££©
	- -Ó£ñşÒöŞÅéÄint, bool, byteÔõPrimitive type¡£åıÍı??êóConstructor¡¢Destructor¡¢?ğ¤???ß©İ¬îÜ?úşù¬éÄ?ÛÉÖª?ÙÍ?Ê¦Òö?ğíî¤êË?¡£

	ñ«é©÷åïÖ
	- ?ÖõõÌá³ûùheap??£¬Üôñ®auto memory shrink¡£
	?capacity??Üô??á´¡£ì×ó®é©ÍÅ??ğíŞÅéÄ?Òı??îÜ?£¬õÌû¿ù­Øóó®?ßÚîÜŞÅéÄ¡£
	- ?İ»Ê¦ì¤ŞÅéÄ<a target="_blank" href="http://guide.nettention.com/cpp_zh#fast_heap" >Fast heap</a>%ì»??heap??ğÎà÷îÜ?ùÃ¡£
	ó®ÍíÒöĞñÜâ?????¡£Ó£ãÀÊ¦ì¤éÄUseFastHeap?ú¼áóËÇ¡£
	- Ê¦ì¤ŞÅéÄ.Net framework îÜList<>, STL.vector, CAtlArray%á¶êóîÜÛ°ÛöÙ£?¡£?ğ«ÍêßÀSTL.vector.iterator%îÜiterator class¡£

	\param T ??îÜ?ÙÍ?úş¡£
	\param T_IN Type name for input parameter.
	Use T/const T& for passing values by value/reference.
	byval is preferred if data type is same or little than 8 bytes.
	\param RAWTYPE ???ÙÍ?ú¼raw memory copyãÀÜúãÀäÌîïîÜ?úş¡£Int ?æÔäÌîï£¬Ó£ std.string%ÜôäÌîï¡£
	åıÍıÛÉÖªîÜ?ÙÍ?úşÊ¦ì¤ÜôŞÅéÄConstructor¡¢Destructor¡¢?ğ¤???ß©İ¬£¨Copy Assignment Operator£©Ñá?Ê¦ì¤ò¦ïÒ?true¡£
	åıÍı?Ğìò¦ïÒ?true£¬î¤?ÛÉÖª?ú¼?ìı¡¢?ğ¶¡¢?ÌÚÓŞá³ÔõğÃíÂ?£¬?Öõ?ú¼î¤?İ»?ßæîÜÛÉÖª?ÙÍîÜßæà÷¡¢÷ò?¡¢?ğ¤?ïï£¬Üôû¼Ğ£Constructor¡¢Destructor¡¢?ğ¤???ß©İ¬¡£
	??ğ«ÍÔ?×âáÜÓø¡£Ğìôøã·??false¡£
	\param INDEXTYPE Ëï?î¤??õÌÓŞÓŞá³ĞàindexîÜtype. int32,int64,intPtr ñıñéŞÅéÄìé?¡£32-64bit int ñı?îÜcasting?ùÃå¥ÜôÒöûì?£¬á¶ì¤Ëï?ŞÅéÄıæ?îÜÛ°Ûö¡£
	ÖÇåı?ËßøĞÓŞá³ĞñÜâÔ´ÜôŞÅéÄõ±?2GBîÜ£¬á¶ì¤Ëï?ŞÅéÄint32¡£ŞÅéÄÜâò¢ïïßíîÜ?Ëï?intPtr¡£åıû»????Ôõ?ŞÅ××éÄ32bitå¥ÜôõöİÂîÜ?£¬Ëï?éÄint64¡£

	\~japanese
	ÛÕÖª«¯«é«¹
	Pritimitive typeªÎª¿ªáªÎàõÒöú¾ß¾Ñ¦Òö
	- RAWTYPE=trueªÇàâïÒª¹ªëªÈ¡¢ÛÕÖªé©áÈªÏintªÊªÉªÎprimitive«¿«¤«×ªÇÌ¸ªÊªµªìªÆÛÕÖªàõÒöª¬ú¾ß¾ªµªìªŞª¹¡£(àõÒöĞ¿ÓŞûùªÎª¿ªáªË?İ»îÜªËmemcpyªÊªÉª¬ŞÅªïªìªŞª¹)
	- Ó£ª·¡¢int, bool, byteªÊªÉprimitive typeªÎªßŞÅéÄÊ¦ÒöªÇª¹¡£ßæà÷í­¡¢÷ò?í­¡¢«³«Ô?ÓÛìıæÑß©í­ªòÜ¬ªËò¥ªÃªÆª¤ªë«¿«¤«×ª¬ÛÕÖªú£ÙÍªÇŞÅªïªìªëíŞùêêË?ªÇª¹¡£

	ñ«é©÷å?
	- heap «¢«¯«»«¹ªòõÌá³ûùª¹ªëª¿ªáªË auto memory shrinkªòª·ªŞª»ªó¡£
	?ªÁ¡¢capacityªÏï¾?Êõªéª·ªŞª»ªó¡£ªèªÃªÆ¡¢«á«â«ê?Î¦ÒıŞÅéÄªÎÙığ¹ïÃªòÍÅÕçª¹ªìªĞ¡¢ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎŞÅéÄªÏù­ª±ª¿Û°ª¬ÕŞª¤ªÇª¹¡£
	- ?İ»îÜªË\ref fast_heapªòŞÅªÃªÆheap«¢«¯«»«¹ªËªèªëİ¶ùÃªòï½å³ª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£ 
	ĞñÜâîÜªËª³ªÎÑ¦ÒöªÏ«ª«ÕªÇª¹¡£ª·ª«ª·¡¢UseFastHeapªË?ÌÚÊ¦ÒöªÇª¹¡£
	- .Net frameworkªÎList<>¡¢STL.vector¡¢CAtlArrayªÎ«á«½«Ã«ÉÙ£ªòîïªÆŞÅª¦ª³ªÈª¬ªÇª­ªŞª¹¡£ª½ª·ªÆ¡¢STL.vector.iteratorªÎªèª¦ªÊæµùÜªÎiterator classªâğ«Íêª·ªÆª¤ªŞª¹¡£
	\param T ÛÕÖªªÎú£ÙÍ«¿«¤«×ªÇª¹¡£
	\param T_IN_REF trueªÇª¢ªìªĞ¡¢by referenceªËìıÕôö·ª¬?Ó¹ªµªìªŞª¹¡£FalseªÇª¢ªìªĞby valueªË?Ó¹ªµªìªŞª¹¡£IntªÎªèª¦ªË«µ«¤«ºª¬8 byteì¤ù»ªÎªâªÎªÏfalseªòŞÅª¦ª³ªÈªòªª?ªáª·ªŞª¹¡£
	\param RAWTYPE ÛÕÖªú£ÙÍª¬ raw memory copyªòª·ªÆªâäÌîïªÊ«¿«¤«×ªÊªÎª«ªÉª¦ª«ªÇª¹¡£IntªÏäÌîïªÇª¹ª¬¡¢std.stringªÏäÌîïªÇªÏª¢ªêªŞª»ªó¡£
	ÛÕÖªªÎú£ÙÍ«¿«¤«×ª¬ßæà÷í­¡¢÷ò?í­¡¢«³«Ô?ÓÛìıæÑß©í­ª¬ŞÅªïªìªÊª¯ªÆªâÕŞª¤«¿«¤«×ªÇª¢ªëíŞùêªÏtrueªÇò¦ïÒª¹ªëª³ªÈª¬ªÇª­ªŞª¹¡£
	ª³ªìªòtureªÇò¦ïÒª¹ªëªÈÛÕÖªªË?ìı¡¢Şûğ¶¡¢«µ«¤«º?ÌÚªÊªÉªòª¹ªëãÁ¡¢?İ»îÜªË?ßæª¹ªëÛÕÖªú£ÙÍªÎßæà÷¡¢÷ò?¡¢«³«Ô?Î¦ïïªÎª¿ªáªË¡¢ßæà÷í­¡¢÷ò?í­¡¢«³«Ô?ÓÛìıæÑß©í­ªòû¼ªÓõóª·ªŞª»ªó¡£ªèªÃªÆ¡¢?×âáÜÓøª¬ú¾ß¾ªµªìªŞª¹¡£ĞñÜâö·ªÏfalseªÇª¹¡£
	\param INDEXTYPE ÛÕÖªõÌÓŞ«µ«¤«ºªªªèªÓindexªÎtype¡£int32,int64,intPtrªÎñéªÇìéªÄªòŞÅª¦ª³ªÈªòªª?ªáª·ªŞª¹¡£32-64bit intÊàªÎcastingİ¶ùÃªâÙíãÊªÇª­ªŞª»ªóªÎªÇ¡¢îêï·ªÊªâªÎªòŞÅª¦ª³ªÈªòªª?ªáª·ªŞª¹¡£
	ÖÇª¨ªĞ¡¢«Ñ«±«Ã«È«µ«¤«ºªÎíŞùê¡¢ªÇª­ªìªĞ2GBªòõ±ª¨ªëªâªÎªÏĞâªïªÊª¤ªÎªÇint32ªòªª?ªáª·ªŞª¹¡£«í?«««ë«×«í«»«¹ªÇªÎªßĞâª¦ªÊªéintPtrªòªª?ªáª·ªŞª¹¡£«Í«Ã«È«ï?«¯÷ÖÍªªÊªÉ32bitªÇªÏÜôä¨İÂªÊö·ªòĞâª¨ªĞint64ªòªª?ªáª·ªŞª¹¡£

	\~
	 */
	template<typename T, bool T_IN_REF = true, bool RAWTYPE = false, typename INDEXTYPE = intptr_t>
	class CFastArray
	{
		typedef typename FastArray_Traits<T, T_IN_REF>::type T_IN;

	public:
		// #ikpil.choi 2016-11-29 : TÀÇ Å¸ÀÔ »çÀÌÁî Ãß°¡, 		
		static const size_t TYPE_SIZE = sizeof(T);

	protected:
		/* ÀÌ °ªµéÀº »ó¼ÓµÈ Å¬·¡½º¿¡¼­ Á÷Á¢ Á¶ÀÛÇÒ ¼ö ÀÖ´Ù.
		Q: ÆĞÄ¡¿öÅ© ¾Æ´Ñ°¡¿ä?
		A: ÀÖÀ» °ÍÀº ÀÖ¾î¾ß ÇÏ°í ¾øÀ» °ÍÀº ¾ø¾î¾ß ÇÑ´Ù´Â ±¸Çö Á¤Ã¥¿¡ À§¹èµÇÁö¸¸,
		min capacity³ª capacity µîÀÌ ¿©±â¼­ ÀÚÁÖ ¾×¼¼½ºµÇ±â ¶§¹®¿¡ ÀÌµé »óÅÂ º¯¼ö°¡ µû·Î ÀÖ´Â °ÍÀÌ Â÷¶ó¸® Á÷°üÀûÀÔ´Ï´Ù.
		*/

		// ¹è¿­ µ¥ÀÌÅÍ
		T* m_Data;
		// ¹è¿­ÀÇ ÇöÀç Å©±â
		INDEXTYPE m_Length;
		// ¹è¿­ µ¥ÀÌÅÍ ºí·°ÀÇ ½ÇÁ¦ ÇÒ´çµÈ Å©±â
		INDEXTYPE m_Capacity;
		// ¹è¿­ µ¥ÀÌÅÍ ºí·°ÀÇ ÃÖ¼Ò Å©±â. ´Ü 1°³ÀÇ ¹è¿­ Ç×¸ñÀ» Àâ¾Æµµ ÀÌ°Í ÀÌ»óÀº ÀâÈ÷°Ô µÇ¾î ÀÖ´Ù.
		INDEXTYPE m_minCapacity;

		// if true, capacity never shrinks.
		// for example, this is flagged if this object is being object-pooled.
		bool m_suspendShrink;

		// ¸Ş¸ğ¸® ¿ì¼±? CPU ¿ì¼±?
		GrowPolicy m_growPolicy;

		inline void InitVars()
		{
			m_Data = NULL;
			m_Length = 0;
			m_Capacity = 0;
			m_minCapacity = 0;
		}

		// gets recommended capacity for required length actualCount.
		virtual INDEXTYPE GetRecommendedCapacity(INDEXTYPE actualCount)
		{
			INDEXTYPE nGrowBy = INDEXTYPE(); // prevent compile LV4 warning
			switch (m_growPolicy)
			{
			case GrowPolicy_LowMemory:
				// »ç¿ëÀÚ°¡ ´Ã¸®·ÁÇÑ Å©±â ±×´ë·Î¸¸ ´Ã¸°´Ù.
				return PNMAX(m_minCapacity, actualCount);
			default:
				nGrowBy = m_Length / 8;
				nGrowBy = PNMIN(nGrowBy, 1024); // ÃÖ´ë Áõ°¡ºĞ
				nGrowBy = PNMAX(nGrowBy, 4); // ÃÖ¼Ò Áõ°¡ºĞ
				break;
			case GrowPolicy_HighSpeed:
				// ¿ø·¡ ±æÀÌÀÇ ¾à 12% Á¤µµ¸¦ Ãß°¡·Î ´Ã¸°´Ù.
				nGrowBy = m_Length / 8;
				nGrowBy = PNMAX(nGrowBy, 16); // ÃÖ¼Ò Áõ°¡ºĞ
				nGrowBy = PNMAX(nGrowBy, (INDEXTYPE)(64 / sizeof(T))); // for ByteArray and CMessage.
				nGrowBy = PNMIN(nGrowBy, 1024); // ÃÖ´ë Áõ°¡ºĞ
				break;
			}

			// change capacity only if there is much gap between current capacity and new capacity.
			INDEXTYPE v1 = m_Capacity;
			INDEXTYPE v2 = actualCount + nGrowBy;
			INDEXTYPE diff;
			if (v1 > v2) // INDEXTYPE might be unsigned.
				diff = v1 - v2;
			else
				diff = v2 - v1;

			// never return 0 which clears all capacity.
			if(!m_suspendShrink)
			{
				// shrink¸¦ Çã¿ëÇÏ´Â »óÈ².
				if (diff > nGrowBy)
				{
					return PNMAX(m_minCapacity, v2);
				}
				else
					return PNMAX(m_minCapacity, v1);
			}
			else
			{
				// shrink¸¦ Àı´ë ÇÏÁö ¾Ê´Â »óÈ².
				if (diff > nGrowBy)
				{
					return PNMAX(m_Capacity, v2);
				}
				else
					return PNMAX(m_Capacity, v1);
			}
		}

		inline void BoundCheck(INDEXTYPE index) const
		{
			if (index < 0 || index >= m_Length)
				ThrowArrayOutOfBoundException();
		}
	public:

		/**
		\~korean
		±âº» »ı¼ºÀÚ

		\~english
		Default constructor

		\~chinese
		Ùù?ßæà÷íº

		\~japanese
		ĞñÜâßæà÷í­
		\~
		*/
		inline CFastArray()
		{
			m_growPolicy = GrowPolicy_Normal;
			m_suspendShrink = false;

			InitVars();
		}

		/**
		\~korean
		¿ÜºÎ µ¥ÀÌÅÍ¸¦ º¹»çÇØ¿À´Â »ı¼ºÀÚ
		\param data µ¥ÀÌÅÍ ¹è¿­ÀÇ Æ÷ÀÎÅÍ ÀÔ´Ï´Ù.
		\param count ¹è¿­ÀÇ Data¼ö ÀÔ´Ï´Ù.

		\~english 
		Constructor that copies external data
		\param src This is the pointer of the data array
		\param count This is the number of data in the array		



		\~chinese
		?ğ¤èâİ»?ËßîÜßæà÷íº¡£
		\param data ?Ëß??îÜò¦?¡£
		\param count ãÀ??îÜData?¡£

		\~japanese
		èâİ»«Ç?«¿ªò«³«Ô?ª·ªÆª¯ªëßæà÷í­
		\param data «Ç?«¿ÛÕÖªªÎ«İ«¤«ó«¿?ªÇª¹¡£
		\param count ÛÕÖªªÎ«Ç?«¿?ªÇª¹¡£

		\~
		*/
		inline CFastArray(const T* data, INDEXTYPE count)
		{
			m_growPolicy = GrowPolicy_Normal;
			m_suspendShrink = false;

			InitVars();
			InsertRange(0, data, count);
		}

		/**
		\~korean
		¿ÜºÎ µ¥ÀÌÅÍ¸¦ º¹»çÇØ¿À´Â »ı¼ºÀÚ
		\param src º¹»çÇÒ CFastArray

		\~english 
		Constructor that copies external data
		\param src CFastArray to be copied
		

		\~chinese
		?ğ¤èâİ»?ËßîÜßæà÷íº¡£
		\param src é©?ğ¤îÜ CFastArray%¡£

		\~japanese
		èâİ»«Ç?«¿ªò«³«Ô?ª·ªÆª¯ªëßæà÷í­
		\param src «³«Ô?ª¹ªë CFastArray 

		\~
		*/
		inline CFastArray(const CFastArray &src)
		{
			m_suspendShrink = src.m_suspendShrink;
			m_growPolicy = src.m_growPolicy;
			InitVars();
			src.CopyTo(*this);
		}

		virtual ~CFastArray()
		{
			// SetCount(0); // ÀÌ·¸°Ô ÇÏ¸é ¾ÈµÊ! SetCount->GetRecommendedCapacity->invalid enum valueÂüÁ¶->kaboom!
			if(!RAWTYPE)
			{
				if(m_Length > 0)
					CallDestructors(m_Data, m_Length);
			}

			if (m_Data != NULL)
			{
				DataBlock_Free(m_Data);
			}
		}

		/**
		\~korean
		ÀÌ °´Ã¼ÀÇ ¹è¿­ Å©±â°¡ Áõ°¡ÇÒ ¶§ °¡ÁßÄ¡ Å¸ÀÔÀ» ¼³Á¤. ÀÚ¼¼ÇÑ ³»¿ëÀº GrowPolicyÀ» ÂüÁ¶
		\param val ¹è¿­ÀÇ Áõ°¡ °¡ÁßÄ¡¿¡ ´ëÇÑ type

		\~english 
		Set the weighted value type when the array size of this object increases. For details, refer to GrowPolicy.
		\param val The type to the weighted value of the array


		\~chinese
		?ó®?ßÚîÜ??ÓŞá³ñòÊ¥îÜ?ı¦?öÇÊ¥ñì??úş¡£???é»??ÍÅGrowPolicy¡£
		\param val ???ñòÊ¥Ê¥ñì?îÜtype¡£

		\~japanese
		ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎÛÕÖª«µ«¤«ºª¬?Ê¥ª¹ªëãÁ¡¢Ê¥ñìö·«¿«¤«×ªòàâïÒ¡£ßÙª·ª¯ªÏ¡¢GrowPolicyªò?ğÎ
		\param val ÛÕÖªªÎ?Ê¥Ê¥ñìö·ªË?ª¹ªëtype

		\~
		 */
		inline void SetGrowPolicy(GrowPolicy val)
		{
			m_growPolicy = val;
		}

		/**
		\~korean
		±âÁ¸ grow policy(ÀÌ °´Ã¼ÀÇ ¹è¿­ Å©±â°¡ Áõ°¡ÇÒ ¶§ °¡ÁßÄ¡ Å¸ÀÔ) ¾ò±â

		\~english
		Getting existing grow policy

		\~chinese
		?ö¢ñıîñgrow policy£¨ó®?ßÚîÜ??ÓŞá³ñòÊ¥?îÜÊ¥ñì??úş£©¡£

		\~japanese
		?ğíªÎgrow policy(ª³ªÎ«ª«Ö«¸«§«¯«ÈªÎÛÕÖª«µ«¤«ºª¬?Ê¥ª¹ªëãÁªÎÊ¥ñìö·«¿«¤«×)ªòÔğªŞª¹¡£
		\~
		 */
		inline GrowPolicy GetGrowPolicy()
		{
			return m_growPolicy;
		}

		/**
		\~korean
		ÃÖ¼Ò ¹öÆÛ Å©±â¸¦ ¼³Á¤ÇÑ´Ù. ¹öÆÛ(capacity)Å©±â°¡ Áõ°¡ÇÒ ¶§ ÃÖ¼ÒÇÑ ÀÌ »çÀÌÁîº¸´Ù Å©°Ô ¼³Á¤ÇÑ´Ù.
		\param newCapacity ÃÖ¼Ò Capacity size

		\~english 
		Set the minimum buffer size. When the buffer (capacity) size increases, set it at least bigger than this size.
		\param newCapacity Minimum capacity size



		\~chinese
		?öÇõÌá³bufferÓŞá³¡£Buffer£¨capacity£©ÓŞá³ñòÊ¥?£¬?Õá?öÇà÷İï?ÓŞîÜ??¡£
		\param newCapacity õÌá³Capacity size¡£

		\~japanese
		õÌá³«Ğ«Ã«Õ«¡?«µ«¤«ºªòàâïÒª·ªŞª¹¡£«Ğ«Ã«Õ«¡?(capacity)«µ«¤«ºª¬?Ê¥ª¹ªëãÁ¡¢õÌá³ùÚª³ªÎ«µ«¤«ºªèªêÓŞª­ª¯àâïÒª·ªŞª¹¡£
		\param newCapacity õÌá³ Capacity size 

		\~
		*/
		inline void SetMinCapacity(INDEXTYPE newCapacity)
		{
			m_minCapacity = PNMAX(newCapacity, m_minCapacity);
			//SetCapacity(m_minCapacity); ÀÌ·¯¸é ¼¼ÆÃ¸¸ Çß´Âµ¥µµ ¾öÇÑ ÇÒ´çÀ»! Áñ!
		}

		/**
		\~korean
		¹è¿­ÀÌ °®°í ÀÖ´Â ¹öÆÛ(Ä³ÆÛ¼­Æ¼)¸¦ Á¶ÀıÇÑ´Ù.
		- Ä³ÆÛ¼­Æ¼´Â Áõ°¡¸¸ ÇÒ »Ó, ÁÙ¾îµéÁö´Â ¾Ê´Â´Ù.

		\~english
		Balances the buffer(capacity) possessed by array
		- Capacity is only increased, not decreased.

		\~chinese
		?ïÚ???êóîÜbuffer£¨capacity£©¡£
		- capacityñş?ñòÊ¥£¬Üô??á´¡£

		\~japanese
		ÛÕÖªª¬ò¥ªÃªÆª¤ªë«Ğ«Ã«Õ«¡?(«­«ã«Ñ«·«Æ«£?)ªòğàï½ª·ªŞª¹¡£
		- «­«ã«Ñ«·«Æ«£?ªÏ?Ê¥ª¹ªëªÀª±ªÇÊõªëª³ªÈªÏª¢ªêªŞª»ªó¡£

		\~
		 */
		inline void SetCapacity(INDEXTYPE newCapacity)
		{
			assert(m_Capacity >= m_Length);

			newCapacity = PNMAX(m_minCapacity, PNMAX(newCapacity, m_Capacity) );

			// ´Ã¸± ÇÊ¿ä°¡ ÀÖÀ»¶§¸¸ ´Ã¸°´Ù.
			if(newCapacity > m_Capacity)
			{
				if (m_Capacity == 0) // Ä³ÆÛ°¡ ¾Ö´çÃÊ ¾ø¾ú´Ù¸é
				{
					assert(!m_Data);

					// 0->N
					m_Data = (T*)DataBlock_Alloc(newCapacity * sizeof(T));

					// capacity¸¸ ¼¼ÆÃÇÑ °ÍÀÌ¹Ç·Î ctor,dtor È£Ãâ NO!
				}
				else
				{
					// ÀÖ´ø Ä³ÆÛÀÇ Áõ°¡
					if(RAWTYPE)
					{
						T* oldData = m_Data;
						T* newData;

						newData = (T*)DataBlock_Realloc(oldData, newCapacity * sizeof(T));

						m_Data = newData;

						// reallocÀº ±¸ ºí·°À¸·ÎÀÇ º¹»çµµ °âÇÏ´Ï±î ¿©±â¼­ ¶Ç º¹»ç ºÒÇÊ¿ä
					}
					else	// raw typeÀÌ ¾Æ´Ñ °æ¿ì
					{
						T* oldData = m_Data;
						T* newData;

						// copy operator°¡ ÀÖ´Â °´Ã¼ Å¸ÀÔÀÎ °æ¿ì reallocÀ» ÇÏ¸é ±¸ µ¥ÀÌÅÍ ºí·°À» ¼Ò½ÇÇÏ°Ô µÈ´Ù.
						// µû¶ó¼­ reallocÀÌ ¾Æ´Ñ alloc new => do assign oper => delete old¸¦ ÇØ¾ß ÇÑ´Ù.
						newData = (T*)DataBlock_Alloc(newCapacity * sizeof(T));

						// »õ·Î ÇÒ´çµÈ ¹öÆÛ¿¡ ±¸ ¹öÆÛ¿¡ ÀÖ´Â °´Ã¼µéÀÇ º¹»ç »ı¼ºÀÚ¸¦ ¼öÇàÇÑ´Ù.
						CallCopyConstructors<T>(newData, oldData, m_Length);

						// ±¸ µ¥ÀÌÅÍ ºí·°¿¡ ÀÖµç °´Ã¼µéÀº Á¦°ÅÇØ¾ß. À§¿¡¼­ º¹»ç°¡ µÇ¾úÀ¸¹Ç·Î. ÀÌ°Ô ºüÁö¸é ´©¼ö·Î ÀÌ¾îÁü!
						CallDestructors<T>(oldData,m_Length);
						DataBlock_Free(oldData);

						m_Data = newData;
					}
				}
				// »õ·Î¿î ¿ë·®À¸·Î ¼ÂÆÃÇÑ´Ù.
				m_Capacity = newCapacity;
			}
		}

		// Capacity never shrinks after this is called.
		// called by object pool classes.
		inline void SuspendShrink()
		{
			m_suspendShrink = true;
		}

		// called by object pool classes.
		inline void OnRecycle()
		{
		}

		// called by object pool classes.
		inline void OnDrop()
		{
			// ¹è¿­ °´Ã¼°¡ Àç»ç¿ë ÇØÁ¦µÇ´Â °æ¿ì, °®°í ÀÖ´Â ¸â¹öµéÀ» ¸ğµÎ Ã»¼ÒÇÏ´Â °ÍÀÌ ÁÁ´Ù.
			// Çà¿©³ª shared_ptrÀ» °¡Áö°í ÀÖ´Â item typeÀÌ¸é, ÀÌ°Í ¶§¹®¿¡ ´©¼ö·Î ÀÌ¾îÁú ¼ö ÀÖÀ¸´Ï±î.
			ClearAndKeepCapacity();
		}

		/**
		\~korean
		¹è¿­ Å©±â¸¦ Á¶ÀıÇÑ´Ù
		- ¹è¿­ Å©±â Á¶Àı½Ã capacity°¡ ÃæºĞÈ÷ Áõ°¡ÇÑ´Ù.
		\param newVal »õ·Î¿î ¹è¿­ÀÇ Å©±â

		\~english 
		Adjust the array size
		- When adjusting the array size, the capacity increases sufficiently. 
		\param newVal Size of the new array


		\~chinese
		?ïÚ??ÓŞá³¡£
		- ?ïÚ??ÓŞá³?capacity?õöİÂñòÊ¥¡£
		\param newVal ãæîÜ??ÓŞá³¡£

		\~japanese
		ÛÕÖª«µ«¤«ºªòğàï½ª·ªŞª¹¡£
		- ÛÕÖª«µ«¤«ºªòğàï½ãÁªËcapacityª¬ä¨İÂ?Ê¥ª·ªŞª¹¡£
		\param newVal ãæª·ª¤ÛÕÖªªÎ«µ«¤«º

		\~
		 */
		inline void SetCount(INDEXTYPE newVal) // ¼º´ÉÀÌ Áß¿äÇÏ¹Ç·Î ·çÆ¾ÀÌ Ä¿µµ inline
		{
			/*
			\~korean
			Å©±â Á¶Àı½Ã ¹ß»ıÇÏ´Â »çÇ×
			- 0->N: ¹öÆÛ »ı¼º
			- N->0: capacity´Â ±×´ë·Î º¸À¯
			- M->N (M>N): capacity´Â ±×´ë·Î º¸À¯
			- M->N(M<N): granularity ´ÜÀ§·Î Å©±â Áõ°¡. Å©±â Áõ°¡½Ã reallocµÊ.

			\~english
			Details occur when modifying size
			- 0->N: creates buffer
			- N->0: capacity is still kept
			- M->N (M>N): capacity is still kept
			- M->N(M<N): size increases in granularity unit. to be 'relloc'ed when size increased.

			\~chinese
			?ïÚÓŞá³??ßæîÜï×?¡£
			- 0->N: ßæà÷buffer
			- N->0: capacityÜÁ×ºê«?
			- M->N (M>N): capacityÜÁ×ºê«?
			- M->N(M<N): ì¤granularity?êÈñòÊ¥ÓŞá³¡£ÓŞá³ñòÊ¥??realloc¡£

			\~japanese
			«µ«¤«ºğàï½ãÁªË?ßæª¹ªëŞÀú£
			- 0->N: «Ğ«Õ«¡?ßæà÷
			- N->0: capacityªÏª½ªÎªŞªŞÜÁêó
			- M->N (M>N): capacityªÏª½ªÎªŞªŞÜÁêó
			- M->N(M<N): granularity ?êÈªÇ«µ«¤«º?Ê¥¡£«µ«¤«º?Ê¥ãÁªËreallocªµªìªŞª¹¡£

			\~
			 */

			if (newVal < 0)
			{
				ThrowInvalidArgumentException();
			}

			if (newVal > m_Length)
			{
				// ´Ã¸®±â
				AddCount(newVal - m_Length);
			}
			else if (newVal < m_Length) // ÁÙÀÌ±â
			{
				// ÇÊ¿ä½Ã Ä³ÆÛ¸¦ ÁÙÀÌÀÚ. ¸Ş¸ğ¸®¸¦ ¾Æ³¥°Ç ¾Æ²¸¾ßÁö.
				// »ç¿ëÀÚ´Â, ¼º´ÉÀÌ ÇÊ¿äÇÏ¸é SuspendShrink¸¦ ½áµµ µÇ°í.
				INDEXTYPE newCapacity = GetRecommendedCapacity(newVal);
				SetCapacity(newCapacity);

				if (!RAWTYPE)
				{
					// Å©±â°¡ ÁÙ°í ÀÖÀ¸´Ï ÆÄ±«ÀÚ È£Ãâ
					CallDestructors<T>(m_Data + newVal, m_Length - newVal);
				}
				else
				{
					// ¾Æ¹«°Íµµ ¾ÈÇÑ´Ù.
					// ºñ¾îÁö°Ô µÇ´Â °ø°£À» zero memoryÇÏ´Â °Íµµ ¼º´É¿¡ ¾Ç¿µÇâ. µû¶ó¼­ Áñ.
				}

				// ½Ç »çÀÌÁî Á¶Àı
				m_Length = newVal;
			}
		}

		// SetCountº¸´Ù Ã³¸® ¼Óµµ°¡ ´õ ºü¸£´Ù.
		// CMessage.Write¿¡¼­ ÀÚÁÖ È£ÃâÇÏ¹Ç·Î ¼º´É ÃÖÀûÈ­¸¦ À§ÇÔ.
		inline void AddCount(INDEXTYPE addLength)
		{
			if (addLength < 0)
			{
				ThrowInvalidArgumentException(); // Å©±â¸¦ ÁÙÀÌ·Á¸é ÀÌ ÇÔ¼ö ¸»°í ´Ù¸¥ ÇÔ¼ö¸¦ ¾µ °Í.
			}
			else if (addLength > 0)
			{
				// ¾Æ·¡ µÎ ±¸¹®Àº Á¦¹ı ½Ã°£À» ¸Ô´Â´Ù. µû¶ó¼­ Á¶°Ç¹®À¸·Î ¹Ì¸® °Ç³Ê¶Ú´Ù.
				if (m_Length + addLength > m_Capacity) // capacity¸¦ ´õ ´Ã·Á¾ß ÇÑ´Ù¸é
				{
					// ¹öÆÛ Å©±â ÀçÇÒ´ç, ÇÊ¿ä½Ã °´Ã¼ º¹»ç Ã³¸®
					INDEXTYPE newCapacity = GetRecommendedCapacity(m_Length + addLength);
					SetCapacity(newCapacity);
				}

				if(!RAWTYPE)
				{
					// ´Ã¾î³­ Å©±â¸¸Å­ »ı¼ºÀÚ È£Ãâ
					CallConstructors<T>(m_Data + m_Length, addLength);
				}

				// ½Ç Å©±â Á¶Àı
				m_Length += addLength;
			}
		}

		/// for STL compatibility
		inline void resize(INDEXTYPE sz)
		{
			SetCount(sz);
		}

		/**
		\~korean
		capacityÀÇ Å©±â¸¦ ¾ò´Â´Ù

		\~english 
		Get the size of the capacity

		\~chinese
		?ö¢capacityîÜÓŞá³¡£

		\~japanese
		capacityªÎ«µ«¤«ºªòÔğªŞª¹¡£
		\~
		*/
		inline INDEXTYPE GetCapacity() const { return m_Capacity; }

		/**
		\~korean
		¹è¿­ Å©±â

		\~english
		Array size

		\~chinese
		??ÓŞá³

		\~japanese
		ÛÕÖª«µ«¤«º
		\~
		*/
		inline INDEXTYPE GetCount() const
		{
			return m_Length;
		}

		/// for STL compatibility
		inline INDEXTYPE size() const
		{
			return GetCount();
		}

		inline bool IsEmpty() const
		{
			return m_Length == 0;
		}

		/**
		\~korean
		¹è¿­ Ã»¼Ò. ClearAndKeepCapacity¿Í °°À½

		\~english
		Clean up array. Same as ClearAndKeepCapacity

		\~chinese
		????¡£?ClearAndKeepCapacityìé?¡£

		\~japanese
		ÛÕÖªá·ğ¶¡£. ClearAndKeepCapacityªÈÔÒª¸ªÇª¹¡£
		\~
		*/
		inline void Clear()
		{
			SetCount(0);    // ¸Ş¸ğ¸® ºí·° ÆÄ±«´Â Àı´ë ¾ÈÇÔ
		}

		/**
		\~korean
		¹è¿­ Ã»¼Ò. Clear¿Í °°À½

		\~english
		Clean up array. Same as Clear

		\~chinese
		????¡£?clearìé?¡£

		\~japanese
		ÛÕÖªá·ğ¶¡£ClearªÈÔÒª¸ªÇª¹¡£
		\~
		*/
		inline void ClearAndKeepCapacity()
		{
#ifdef _DEBUG
			INDEXTYPE oldCount = m_Length;
#endif
			Clear();
#ifdef _DEBUG
			// ÀÖ´ø ¹è¿­À» ºñ¿î°Å¶ó¸é ¹öÆÛ°¡ ³²¾ÆÀÖ¾î¾ß ÇÑ´Ù.
			if (oldCount > 0)
			{
				assert(m_Data != NULL);
			}
#endif
		}

#if defined(_MSC_VER)
		/**
		\~korean
		¹è¿­ Å©±â

		\~english
		Array size

		\~chinese
		??ÓŞá³¡£

		\~japanese
		ÛÕÖª«µ«¤«º
		\~
		*/
		__declspec(property(get = GetCount)) INDEXTYPE Count;
#endif

		/**
		\~korean
		index°¡ °¡¸®Å°´Â ¹è¿­ Ç×¸ñ

		\~english
		Array item that pointed by index

		\~chinese
		Indexá¶ò¦îÜ???ÙÍ¡£

		\~japanese
		indexª¬ò¦ª¹ÛÕÖªú£ÙÍ
		\~
		*/
		inline T_IN ElementAt(INDEXTYPE index) const
		{
			BoundCheck(index);
			return m_Data[index];
		}

		/**
		\~korean
		index°¡ °¡¸®Å°´Â ¹è¿­ Ç×¸ñ

		\~english
		Array item that pointed by index

		\~chinese
		Indexá¶ò¦îÜ???ÙÍ¡£

		\~japanese
		indexª¬ò¦ª¹ÛÕÖªú£ÙÍ
		\~
		*/
		inline T& ElementAt(INDEXTYPE index)
		{
			BoundCheck(index);
			return m_Data[index];
		}

		/**
		\~korean
		index°¡ °¡¸®Å°´Â ¹è¿­ Ç×¸ñ

		\~english
		Array item that pointed by index

		\~chinese
		Indexá¶ò¦îÜ???ÙÍ¡£

		\~japanese
		indexª¬ò¦ª¹ÛÕÖªú£ÙÍ
		\~
		*/
		inline T_IN operator[] (INDEXTYPE index) const
		{
			return ElementAt(index);
		}

		/**
		\~korean
		index°¡ °¡¸®Å°´Â ¹è¿­ Ç×¸ñ

		\~english
		Array item that pointed by index

		\~chinese
		Indexá¶ò¦îÜ???ÙÍ¡£

		\~japanese
		indexª¬ò¦ª¹ÛÕÖªú£ÙÍ
		\~
		*/
		inline T& operator[](INDEXTYPE index)
		{
			return ElementAt(index);
		}

		/**
		\~korean
		¹è¿­ ¹öÆÛ Æ÷ÀÎÅÍ¸¦ ¾ò´Â´Ù.

		\~english
		Gets array buffer pointer

		\~chinese
		?Ôğ??bufferò¦?¡£

		\~japanese
		ÛÕÖª«Ğ«Ã«Õ«¡?«İ«¤«ó«¿?ªòÔğªŞª¹¡£
		\~
		*/
		inline T* GetData()
		{
			if (m_Length == 0)
				return NULL;
			return m_Data;
		}

		/**
		\~korean
		¹è¿­ ¹öÆÛ Æ÷ÀÎÅÍ¸¦ ¾ò´Â´Ù.

		\~english
		Gets array buffer pointer

		\~chinese
		?Ôğ??bufferò¦?¡£

		\~japanese
		ÛÕÖª«Ğ«Ã«Õ«¡?«İ«¤«ó«¿?ªòÔğªŞª¹¡£
		\~
		*/
		inline const T* GetData() const
		{
			if (m_Length == 0)
				return NULL;
			return m_Data;
		}

		/**
		\~korean
		¸ÇµÚ¿¡ Ãß°¡

		\~english
		Add at the end

		\~chinese
		ôÕÊ¥ÓğõÌı¨¡£

		\~japanese
		õÌı­ªËõÚÊ¥
		\~
		*/
		inline void Add(T_IN value)
		{
			INDEXTYPE length = m_Length;

			// code profile °á°ú ¸Å¿ì ÀÚÁÖ È£ÃâµÇ´Â ÇÔ¼öÀÌ´Ù. ÀÌ·¸°Ô ¼ôÄÆ ·ÎÁ÷À¸·Î Ã³¸®ÇÏ¸é ´ëºÎºĞÀÇ °æ¿ì ºü¸£´Ù.
			if (length < m_Capacity)
			{
				if (!RAWTYPE)
				{
					CallConstructor(&m_Data[length], value);
				}
				else
				{
					m_Data[length] = value;
				}
				length++;
				m_Length = length;
			}
			else
			{
				// ¸Ç ³¡¿¡ Ãß°¡ÇÑ´Ù.
				Insert(m_Length, value);
			}
		}

		/**
		\~korean
		indexAtÀÌ °¡¸®Å°´Â Ç×¸ñÀ» ¸ğµÎ ÇÑÄ­¾¿ µÚ·Î ¹Ğ°í value ¸¦ indexAt ÀÌ °¡¸®Å°´Â °÷¿¡ Ãß°¡ÇÑ´Ù.

		\~english
		Move back item that pointed by indexAt then add value to place that pointed by indexAt

		\~chinese
		÷êindexAtá¶ò¦îÜ?ÙÍèÙı¨õÏìéÌ«£¬î¢÷êvalueôÕÊ¥ÓğindexAtá¶ò¦îÜêÈöÇ¡£

		\~japanese
		indexAtª¬ò¦ª¹ú£ÙÍªòîïªÆ1ùùªºªÄı­ªíªËªºªéª·ªÆ¡¢valueªòindexAtª¬ò¦ª¹ªÈª³ªíªËõÚÊ¥ª·ªŞª¹¡£
		\~
		*/
		inline void Insert(INDEXTYPE indexAt, T_IN value)
		{
			InsertRange(indexAt, &value, 1);
		}

		/**
		\~korean
		¹è¿­ µÚ¿¡ »õ·Î¿î ¹è¿­ Ãß°¡
		\param data »õ·Î Ãß°¡ÇÒ ¹è¿­ÀÇ Æ÷ÀÎÅÍ
		\param count Ãß°¡ÇÒ ¹è¿­ÀÇ Å©±â

		\~english 
		Add a new array behind an array
		\param data Pointer of the array to be newly added. 
		\param count Size of the array to be added


		\~chinese
		??ı¨ôÕÊ¥ãæîÜ??¡£
		\param data é©ãæôÕÊ¥îÜò¦?¡£
		\param count é©ôÕÊ¥îÜ??ÓŞá³¡£

		\~japanese
		ÛÕÖªªÎı­ªíªËãæª·ª¤ÛÕÖªªòõÚÊ¥
		\param data ãæª¿ªËõÚÊ¥ª¹ªëÛÕÖªªÎ«İ«¤«ó«¿? 
		\param count õÚÊ¥ª¹ªëÛÕÖªªÎ«µ«¤«º

		\~
		*/
		inline void AddRange(const T* data, INDEXTYPE count)
		{
			//InsertRange(m_Length, data, count);ÀÌ°Ô ´õ ´À¸²

			if (count < 0)
				ThrowInvalidArgumentException();

			if (count == 0)
				return;

			INDEXTYPE oldCount = m_Length;

			// °ø°£ È®º¸
			AddCount(count);
			INDEXTYPE indexAt = oldCount;

			T* src = GetData();
			if (!RAWTYPE)
			{
				// °ª Ã¤¿ì±â

				for (INDEXTYPE i = 0; i < count; i++)
				{
					// °¡¼ÓÀ» À§ÇØ GetData() »ç¿ë
					src[i + indexAt] = data[i];
				}
			}
			else
			{
				// #ikpil.choi 2016-11-07 : memcpy_s ·Î º¯°æ, destSize(2¹øÂ° ÀÎÀÚ) °ªÀÌ Ç×»ó ¿Ã¹Ù¸¥ °ªÀÌ¿©¾ß ÇÕ´Ï´Ù.
				//UnsafeFastMemcpy(src + indexAt, data, sizeof(T)*count);
				memcpy_s(src + indexAt, sizeof(T) * (m_Length - indexAt), data, sizeof(T) * count);
			}
		}

		/**
		\~korean
		¹è¿­ Áß°£¿¡ ¹è¿­ Ãß°¡. indexAtÀÌ °¡¸®Å°´Â ºÎºĞÀ» µÚ·Î ¹Ğ¾î³õ°í Æ´»õ¿¡ Ãß°¡ÇÑ´Ù.
		\param indexAt ÀÌ index ¹øÈ£ÀÇ ´ÙÀ½ºÎÅÍ Ãß°¡ µË´Ï´Ù.
		\param data data »ğÀÔÇÒ ¹è¿­ÀÇ Æ÷ÀÎÅÍ ÀÔ´Ï´Ù.
		\param count »ğÀÔÇÒ ¹è¿­ÀÇ Å©±â

		\~english 
		Add an array in the middle of an array. Push the area pointed at by indexAt behind and add it in the gap. 
		\param indexAt It is added after this index number. 
		\param data data It is a pointer of the array to be inserted. 
		\param count Size of the array to be added. 




		\~chinese
		î¤??ñé?ôÕÊ¥??¡£?indexAtá¶ò¦îÜİ»İÂı¨õÏ£¬ñıı¨ôÕÊ¥Óğ?ĞÀ×ì¡£
		\param indexAt ?index??ñıı¨?ã·ôÕÊ¥¡£
		\param data dataé©?ìıîÜ??ò¦?¡£
		\param count ?ìıîÜ??ÓŞá³¡£

		\~japanese
		ÛÕÖªñéÊàªËÛÕÖªõÚÊ¥£ºindexAtª¬ò¦ª¹İ»İÂªòı­ªíªØªºªéª·ªÆöÇª¤ªÆĞÀÊàªËõÚÊ¥ª·ªŞª¹¡£
		\param indexAt ª³ªÎindexÛã?ªÎó­ª«ªéõÚÊ¥ªµªìªŞª¹¡£
		\param data data ?ìıª¹ªëÛÕÖªªÎ«İ«¤«ó«¿?ªÇª¹¡£
		\param count ?ìıª¹ªëÛÕÖªªÎ«µ«¤«º

		\~
		*/
		inline void InsertRange(INDEXTYPE indexAt, const T* data, INDEXTYPE count)
		{
			if (count < 0 || indexAt < 0 || indexAt > m_Length)
				ThrowInvalidArgumentException();

			INDEXTYPE oldCount =  m_Length;

			// °ø°£ È®º¸
			AddCount(count);

			// ¹Ì¸® ¹Ğ¾î³Ö°í
			INDEXTYPE moveAmount = oldCount - indexAt;
			T* src = GetData(); // getdata¾È¿¡ if¹®ÀÖÀ½.

			if (moveAmount > 0)
			{
				if(!RAWTYPE)
				{
					for (INDEXTYPE i = moveAmount - 1;i >= 0;i--)
					{
						// °¡¼ÓÀ» À§ÇØ GetData() »ç¿ë
						src[i+indexAt+count] = src[i+indexAt];
					}
				}
				else
				{
					UnsafeFastMemmove(src+indexAt+count,src+indexAt,sizeof(T)*moveAmount);
					assert(indexAt+count+moveAmount<=m_Length);
				}
			}

			if(!RAWTYPE)
			{
				// °ª Ã¤¿ì±â
				for (INDEXTYPE i = 0;i < count;i++)
				{
					// °¡¼ÓÀ» À§ÇØ GetData() »ç¿ë
					src[i+indexAt] = data[i];
				}
			}
			else
			{
				// #ikpil.choi 2016-11-07 : memcpy_s ·Î º¯°æ, destSize(2¹øÂ° ÀÎÀÚ) °ªÀÌ Ç×»ó ¿Ã¹Ù¸¥ °ªÀÌ¿©¾ß ÇÕ´Ï´Ù.
				//UnsafeFastMemcpy(src + indexAt, data, sizeof(T) * count);
				// m_Length = 7, indexAt = 0, count = 1 ÀÌ¸é, true
				// m_Length = 7, indexAt = 7, count = 1 ÀÌ¸é, false

				// m_Length = 7, indexAt = 0, count = 7 ÀÌ¸é, true
				// m_Length = 7, indexAt = 6, count = 1 ÀÌ¸é, true

				// m_Length = 7, indexAt = 7, count = 1 ÀÌ¸é, false
				// m_Length = 0, indexAt = 0, count = 1 ÀÌ¸é, false
				memcpy_s(src + indexAt, sizeof(T) * (m_Length - indexAt), data, sizeof(T) * count);
			}
		}

		/**
		\~korean
		destÀÇ Å©±â¸¦ count·Î Á¶Á¤ ÈÄ srcÀÇ ÀÏºÎ³ª ÀüÃ¼¸¦ dest·Î º¹»çÇÑ´Ù.
		\param dest ¹è¿­À» dest·Î º¹»çÇÕ´Ï´Ù.
		\param srcOffset ¹è¿­ ³» srcOffset ÀÌÈÄ DataºÎÅÍ dest·Î º¹»ç ÇÑ´Ù.
		\param count count°¹¼ö ¸¸Å­ÀÇ ¹è¿­À» º¹»ç ÇÑ´Ù.

		\~english 
		After adjusting the size of dest with count, part of all of src is copied to dest. 
		\param dest Array is copied to dest. 
		\param srcOffset Copy the data after srcOffset within the array to dest.  
		\param count count Copy arrays as the same number of count. 




		\~chinese
		÷êdestîÜÓŞá³?ïÚ?countı¨£¬?srcîÜİ»İÂûäîïİ»?ğ¤Óğdest¡£
		\param dest ÷ê???ğ¤?dest¡£
		\param srcOffset ????srcOffsetì¤ı¨Data?ã·?ğ¤Óğdest¡£
		\param count  ?ğ¤õóßÓ?éÍcount??îÜ??¡£

		\~japanese
		DestªÎ«µ«¤«ºªòcountªÇğàïÚı­¡¢srcªÎìéİ»ªŞª¿ªÏîï?ªòdestªØ«³«Ô?ª·ªŞª¹¡£ 
		\param dest ÛÕÖªªòdestªØ«³«Ô?ª·ªŞª¹¡£
		\param srcOffset ÛÕÖª?ªÎsrcOffsetì¤Ë½ªÎ«Ç?«¿ª«ªédestªØ«³«Ô?ª·ªŞª¹¡£
		\param count count?ªÀª±ªÎÛÕÖªªò«³«Ô?ª·ªŞª¹¡£

		\~
		*/
		inline void CopyRangeTo(CFastArray &dest, INDEXTYPE srcOffset, INDEXTYPE count) const
		{
			if (srcOffset + count > m_Length || srcOffset < 0 || count < 0)
				ThrowInvalidArgumentException();

			dest.SetCount(count);

			if(!RAWTYPE)
			{
				T* pDest = dest.GetData();
				const T* pSrc = GetData();
				for (INDEXTYPE i = 0;i < count;i++)
				{
					// °¡¼ÓÀ» À§ÇØ GetData() »ç¿ë
					pDest[i] = pSrc[i+srcOffset];
				}
			}
			else
			{
				// #ikpil.choi 2016-11-07 : memcpy_s ·Î º¯°æ, destSize(2¹øÂ° ÀÎÀÚ) °ªÀÌ Ç×»ó ¿Ã¹Ù¸¥ °ªÀÌ¿©¾ß ÇÕ´Ï´Ù.
				//UnsafeFastMemcpy(dest.GetData(),GetData()+srcOffset,sizeof(T)*count);
				memcpy_s(dest.GetData(), sizeof(T) * dest.m_Length, GetData() + srcOffset, sizeof(T) * count);
			}
		}

		/**
		\~korean
		\param dest ¹è¿­À» dest·Î º¹»çÇÑ´Ù.

		\~english
		\param dest copy array to dest.

		\~chinese
		\param dest ÷ê???ğ¤à÷dest¡£

		\~japanese
		\param dest ÛÕÖªªòdestªØ«³«Ô?ª·ªŞª¹¡£ 
		\~
		*/
		inline void CopyTo(CFastArray &dest) const
		{
			CopyRangeTo(dest, 0, m_Length);
		}

		inline void CopyFrom(const CFastArray &src)
		{
			src.CopyTo(*this);
		}

		inline void CopyFrom(const T* from, INDEXTYPE fromCount)
		{
			if (fromCount < 0)
				ThrowInvalidArgumentException();
			SetCount(fromCount);
			for (INDEXTYPE i = 0;i < fromCount;i++)
			{
				(*this)[i] = from[i];
			}
		}

		/**
		\~korean
		index¹øÂ° Ç×¸ñºÎÅÍ count¸¸Å­ Á¦°ÅÇÑ´Ù.
		\param index Á¦°ÅÇÒ ¹è¿­ÀÇ index
		\param count index·ÎºÎÅÍ count¼ö ¸¸Å­ Á¦°ÅÇÑ´Ù.

		\~english 
		Remove as many as the count from the (index)th item. 
		\param index Index of the array to be removed. 
		\param count Remove as many as the number of count from the index.


		\~chinese
		?ğ¯index??ÙÍ?ğ¶ßÓ?éÍcountîÜÕá¡£
		\param index é©?ğ¶îÜ??index¡£
		\param count ?index?ã·?ğ¶ßÓ?éÍcountîÜÕá¡£

		\~japanese
		indexÛãÙÍªÎú£ÙÍª«ªécountªÀª±ğ¶ËÛª·ªŞª¹¡£ 
		\param index ğ¶ËÛª¹ªëÛÕÖªªÎ index
		\param count indexª«ªécount?ªÀª±ğ¶ËÛª·ªŞª¹¡£

		\~
		*/
		inline void RemoveRange(INDEXTYPE index, INDEXTYPE count)
		{
			if (index < 0 || count < 0)
				ThrowInvalidArgumentException();
			count = PNMIN(count, m_Length - index);

			//¾ÕÀ¸·Î ¶¯±ä´Ù
			INDEXTYPE amount = m_Length - (index + count);

			T* src = GetData();
			if (amount > 0)
			{
				if(!RAWTYPE)
				{
					for (INDEXTYPE i = 0;i < amount;i++)
					{
						// °¡¼ÓÀ» À§ÇØ GetData() »ç¿ë
						src[i+index] = src[i+index+count];
					}
				}
				else
				{
					UnsafeFastMemmove(src+index,src+index+count,amount*sizeof(T));
					assert(index+count+amount<=m_Length);
				}
			}

			SetCount(m_Length - count);
		}

		/**
		\~korean
		\param index index¿¡ ÇØ´çÇÏ´Â data¸¦ Á¦°ÅÇÑ´Ù.

		\~english
		\param index Remove index th item

		\~chinese
		\param index ?ğ¶ÔõéÍindexîÜdata¡£

		\~japanese
		\param index indexªËú±?ª¹ªë«Ç?«¿ªòğ¶ËÛª·ªŞª¹¡£ 
		\~
		*/
		inline void RemoveAt(INDEXTYPE index)
		{
			RemoveRange(index, 1);
		}

		/**
		\~korean
		\param value value¿Í °°Àº °ªÀ» °¡Áö´Â ¹è¿­ ¾Õ¿¡¼­ºÎÅÍ Ã£¾Æ¼­ Ã£À¸¸é Á¦°ÅÇÑ´Ù.

		\~english
		\param value Seek same value as value from the first then remove it

		\~chinese
		\param value ?îñ?ã·???valueßÓÔÒ?îÜ??£¬?Óğøµ?ğ¶¡£

		\~japanese
		\param value valueªÎªèª¦ªÊö·ªòò¥ªÄÛÕÖªªÎîñª«ªé÷®ª·ªÆ¡¢Ì¸ªÄª«ªÃª¿ªéğ¶ËÛª·ªŞª¹¡£
		\~
		*/
		inline bool RemoveOneByValue(T_IN value)
		{
			T* src = GetData();
			for (INDEXTYPE i = 0;i < m_Length;i++)
			{
				// °¡¼ÓÀ» À§ÇØ GetData() »ç¿ë
				if (src[i] == value)
				{
					RemoveAt(i);
					return true;
				}
			}

			return false;
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
		inline CFastArray& operator=(const CFastArray &src)
		{
			src.CopyTo(*this);
			return *this;
		}

		/**
		\~korean
		\param value value¿Í °°Àº °ªÀ» °¡Áö´Â ¹è¿­ Ç×¸ñÀÌ ÀÖ´ÂÁö È®ÀÎÇÑ´Ù.
		\return value¿Í °°Àº °ªÀ» °¡Áö´Â ¹è¿­ Ç×¸ñÀÌ ÀÖÀ¸¸é ±× ÀÎµ¦½º¸¦ ¸®ÅÏÇÑ´Ù. Ã£Áö ¸øÇÏ¸é -1À» ¸®ÅÏÇÑ´Ù.

		\~english
		\param value check if there is an array that has the same value as ¡°value¡±.
		\return If there is the array that has the same value as ¡°value¡±, the index is returned. If not found, -1 will be returned.

		\~chinese
		\param value ??ãÀÜúêó?valueìé??îÜ???ÙÍ¡£
		\return åıÍıêó?valueìé??îÜ???ÙÍîÜ?Ú÷üŞÑá?index¡£?êó?ÓğÚ÷üŞ-1¡£

		\~japanese
		\param value valueªÎªèª¦ªÊö·ªòò¥ªÄÛÕÖªú£ÙÍª¬ª¢ªëª«ªòü¬ìãª·ªŞª¹¡£
		\return valueªÎªèª¦ªÊö·ªòò¥ªÄÛÕÖªú£ÙÍª¬ª¢ªìªĞ¡¢ª½ªÎ«¤«ó«Ç«Ã«¯«¹ªò«ê«¿?«óª·ªŞª¹¡£Ì¸ªÄª«ªéªÊª«ªÃª¿ªé?1ªò«ê«¿?«óª·ªŞª¹¡£

		\~
		 */
		inline INDEXTYPE FindByValue(T_IN value)
		{
			T* src = GetData();

			for (INDEXTYPE i = 0;i <  m_Length;i++)
			{
				if (value == src[i])
					return i;
			}
			return -1;
		}

		/** Returns true if value exists in the array. */
		inline bool Contains(T_IN value)
		{
			return FindByValue(value) >= 0;
		}

		/**
		\~korean
		- ÁÖÀÇ: ´Ü¼ø ¸Ş¸ğ¸® ºñ±³´Ù. ÀÌ Á¡À» ÁÖÀÇÇÒ °Í.
		\param rhs rhs¿Í ³»¿ëÀÌ µ¿ÀÏÇÑÁö Ã¼Å©ÇÑ´Ù.

		\~english
		- Note: This is a simple memory comparison. This is crucial.
		\param rhs Checks if this contains same as rhs

		\~chinese
		- ñ¼ëò£ºãÀ??îÜ?ğíİï?¡£ñ¼ëò?ìéïÃ¡£
		\param rhs ??ãÀÜú?rhs?é»ßÓÔÒ¡£

		\~japanese
		- ª´ñ¼ëò£º?âí«á«â«ê?İïÎòªÇª¹¡£ª³ªìªËª´ñ¼ëòª¹ªëª³ªÈ¡£
		\param rhs rhsªÈ?é»ª¬ÔÒª¸ª«ªÉª¦ª«ªò«Á«§«Ã«¯ª·ªŞª¹¡£

		\~
		 */
		inline bool Equals(const CFastArray &rhs) const
		{
			if(rhs.m_Length!=m_Length)
				return false;

			// ´Ü¼ø ¸Ş¸ğ¸® ºñ±³´Ù.
			const T* p_rhs = rhs.GetData();
			const T* p_lhs = GetData();

			if(RAWTYPE)
			{
				return memcmp(p_rhs,p_lhs,rhs.m_Length * sizeof(T)) == 0;
			}
			else
			{

				for (INDEXTYPE i=0;i<m_Length;i++)
				{
					if(p_rhs[i] != p_lhs[i])
						return false;
				}
				return true;
			}

		}

		/// for STL compatibility
		inline void clear()
		{
			Clear();
		}

		class iterator;

		friend class iterator;

#ifndef PROUDNET_NO_CONST_ITERATOR
		class const_iterator;
		friend class const_iterator;

		/**
		\~korean
		STLÀÇ const_iterator¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Acts like const_iterator of STL

		\~chinese
		ÑÃó·?STLîÜconst_iteratorìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎconst_iteratorªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		 */
		class const_iterator
		{
			friend class CFastArray;
		public:
			const CFastArray* m_owner;
			INDEXTYPE m_pos;

			inline const_iterator() {}
			inline const_iterator(const iterator& src) { m_owner=src.m_owner; m_pos=src.m_pos; }

			inline const_iterator& operator++()
			{
				// preincrement
				if(m_pos<m_owner->m_Length)
					m_pos++;
				else
					ThrowArrayOutOfBoundException();

				return (*this);
			}

			inline const_iterator operator++(int)
			{
				// postincrement
				const_iterator _Tmp = *this;
				++*this;
				return (_Tmp);
			}

			inline bool operator==(const const_iterator& a) const
			{
				return m_pos==a.m_pos && m_owner==a.m_owner;
			}

			inline bool operator!=(const const_iterator& a) const
			{
				return !(m_pos==a.m_pos && m_owner==a.m_owner);
			}

			inline T_IN operator*() const
			{
				return m_owner->ElementAt(m_pos);
			}

		};
#endif
		/**
		\~korean
		STLÀÇ iterator¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Acts similar as iterator of STL

		\~chinese
		ÑÃó·?STLîÜiteratorìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎiteratorªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		 */
		class iterator
		{
			friend class CFastArray;
		public:
			CFastArray* m_owner;
			INDEXTYPE m_pos;

			inline iterator() {}
			inline iterator(const const_iterator& src) { m_owner=src.m_owner; m_pos=src.m_pos; }

			inline iterator& operator++()
			{
				// preincrement
				if(m_pos<m_owner->m_Length)
					m_pos++;
				else
					ThrowArrayOutOfBoundException();

				return (*this);
			}

			inline iterator operator++(int)
			{
				// postincrement
				iterator _Tmp = *this;
				++*this;
				return (_Tmp);
			}

			inline T_IN operator*() const
			{
				return m_owner->ElementAt(m_pos);
			}

			inline T& operator*()  // ÀÌ ¸Ş¼­µå°¡ ¿©Áö²¯ ¿Ö ¾ø¾úÁö?
			{
				return m_owner->ElementAt(m_pos);
			}

			inline bool operator==(const iterator& a) const
			{
				return m_pos==a.m_pos && m_owner==a.m_owner;
			}

			inline bool operator!=(const iterator& a) const
			{
				return !(m_pos==a.m_pos && m_owner==a.m_owner);
			}
		};

		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Acts similar as same name method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		 */
		inline iterator begin()
		{
			iterator ret;
			ret.m_pos = 0;
			ret.m_owner=this;

			return ret;
		}

		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Acts similar as same name method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		 */
		inline iterator end()
		{
			iterator ret;
			ret.m_pos=m_Length;
			ret.m_owner=this;

			return ret;
		}

#ifndef PROUDNET_NO_CONST_ITERATOR
			/**
			\~korean
			STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

			\~english
			Acts similar as same name method of STL

			\~chinese
			ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

			\~japanese
			STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
			\~
			 */
		inline const_iterator begin() const
		{
			const_iterator ret;
			ret.m_pos = 0;
			ret.m_owner = this;

			return ret;
		}

		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.

		\~english
		Acts similar as same name method of STL

		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\~
		 */
		inline const_iterator end() const
		{
			const_iterator ret;
			ret.m_pos=m_Length;
			ret.m_owner=this;

			return ret;
		}
#endif
		/**
		\~korean
		STLÀÇ µ¿¸í ¸Ş¼­µå¿Í °°Àº ¿ªÇÒÀ» ÇÑ´Ù.
		\param iter iter°¡ °¡¸£Å°´Â µ¥ÀÌÅÍ¸¦ Á¦°ÅÇÑ´Ù.

		\~english 
		Acts similar as same name method of STL


		\~chinese
		ÑÃó·?STLîÜÔÒÙ£Û°Ûöìé?îÜíÂéÄ¡£
		\param iter ?ğ¶iterá¶ò¦îÜ?Ëß¡£

		\~japanese
		STLªÎÔÒÙ£«á«½«Ã«ÉªÎªèª¦ªÊæµùÜªòª·ªŞª¹¡£
		\param iter iterª¬ò¦ª¹«Ç?«¿ªòğ¶ËÛª·ªŞª¹¡£

		\~
		 */
		iterator erase(iterator iter)
		{
			if(iter.m_owner!=this)
			{
				ThrowInvalidArgumentException();
			}
			iterator ret = iter;
			//ret++; ÀÌ°Ç ¾ø¾î¾ß ÇÑ´Ù. ¹è¿­ Ç×¸ñÀ» Á¦°ÅÇÏ¸é¼­ µÚ¿¡ÀÖ´Â°Ô ¾ÕÀ¸·Î ÁÖ·ç·è ¹Ğ·Á¿À°í ±×·¯¸é¼­ iter´Â ÀÚµ¿À¸·Î ´ÙÀ½°É °¡¸®Å°´Ï±î.
			RemoveAt(iter.m_pos);

			return ret;
		}

		/**
		\~korean
		¹è¿­ÀÇ ¸¶Áö¸· Á¤º¸¸¦ ¹è¿­³»¿¡¼­ Á¦°ÅÇÏ°í ¸®ÅÏÇØÁØ´Ù.

		\~english 
		Remove the last information of the array within the array and return it. 

		\~chinese
		?????ğ¶??îÜõÌı¨ãáãÓ?Ú÷üŞ¡£

		\~japanese
		ÛÕÖªªÎõÌı­ªÎï×ÜÃªòÛÕÖª?ª«ªéğ¶ËÛª·ªÆ«ê«¿?«óª·ªŞª¹¡£
		\~
		*/
		inline T PopBack()
		{
			INDEXTYPE cnt = m_Length;

			if(cnt == 0)
				ThrowInvalidArgumentException();

			T ret = GetData()[cnt - 1];
			SetCount(cnt - 1);

			return ret;
		}

		/**
		\~korean
		¸Ç ¸¶Áö¸· Ç×¸ñÀ» index°¡ °¡¸®Å°´Â °÷À¸·Î ¿Å±ä ÈÄ ¸Ç ¸¶Áö¸· Ç×¸ñÀ» Á¦°ÅÇÑ´Ù.
		¼ø¼­°¡ »ó°ü¾ø´Â Äİ·º¼Ç¿¡¼­ Çã¸® Ç×¸ñÀ» Á¦°ÅÇÒ ¶§ Remove ´ë½Å ¾²¸é È¿°úÀûÀÌ´Ù.
		\param index Á¦°ÅÇÒ index

		\~english 
		After moving the last item to the place where index is pointing at and remove the last item. 
		It is effective to use instead of Remove when you move the waist item from a collection where sequence is irrelevant. 
		\param index Index to be removed. 

		\~chinese
		÷êõÌı¨?ÙÍ?Óğindexò¦ú¾îÜò¢Û°ì¤ı¨?ğ¶õÌı¨?¡£
		î¤??ßíÙé?îÜcollectionñé?ğ¶mid-part?ÙÍîÜ?ı¦ÓÛôğRemoveîÜ??êóüùÍı¡£
		\param index é©?ğ¶îÜindex¡£

		\~japanese
		õÌı­ªÎú£ÙÍªòindexª¬ò¦ª¹á¶ªËì¹ª·ª¿ı­¡¢õÌı­ªÎú£ÙÍªòğ¶ËÛª·ªŞª¹¡£
		â¢â÷ªË?ÌõªÊª¤«³«ì«¯«·«ç«óªÇé¦ú£ÙÍªòğ¶ËÛª¹ªëãÁ¡¢RemoveªÎôğªïªêªËŞÅª¨ªĞ?ÍıîÜªÇª¹¡£
		\param index ğ¶ËÛª¹ªë index

		\~
		 */
		inline void RemoveAndPullLast(intptr_t index)
		{
			intptr_t cnt = m_Length;
			if(index<0 || index>=cnt)
				ThrowInvalidArgumentException();

			// ¸Ç ³¡ Ç×¸ñÀ» index°¡ °¡¸®Å°´Â °÷À¸·Î ÀÌµ¿
			if(index < cnt - 1)
			{
				GetData()[index] = GetData()[cnt - 1];
			}

			// »çÀÌÁî 1 °¨¼Ò
			SetCount(cnt-1);
		}


		virtual void DataBlock_Free(void* data)
		{
			CProcHeap::Free(data);
		}

		virtual void* DataBlock_Alloc(size_t length)
		{
			void* ret = CProcHeap::Alloc(length);

			if (ret == NULL)
				ThrowBadAllocException();

			return ret;
		}

		virtual void* DataBlock_Realloc(void* oldPtr, size_t newLength)
		{
			void* newData = (T*)CProcHeap::Realloc(oldPtr, newLength);

			if (newData == NULL)
				ThrowBadAllocException();

			return newData;
		}
	};



	/**  @} */


}

#ifdef _MSC_VER
#pragma pack(pop)
#endif
