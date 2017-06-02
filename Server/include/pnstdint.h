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

#include "pndefine.h"
#if defined(_MSC_VER) && (_MSC_VER < 1600)

#include <yvals.h> // _C2¶ó´Â ¸ÅÅ©·Î ¶§¹®¿¡

typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

typedef signed char int_least8_t;
typedef short int_least16_t;
typedef int int_least32_t;

typedef unsigned char uint_least8_t;
typedef unsigned short uint_least16_t;
typedef unsigned int uint_least32_t;

typedef char int_fast8_t;
typedef int int_fast16_t;
typedef int int_fast32_t;

typedef unsigned char uint_fast8_t;
typedef unsigned int uint_fast16_t;
typedef unsigned int uint_fast32_t;

#ifndef _INTPTR_T_DEFINED
#define _INTPTR_T_DEFINED
#ifdef _WIN64
typedef __int64 intptr_t;
#else /* _WIN64 */
typedef _W64 int intptr_t;
#endif /* _WIN64 */
#endif /* _INTPTR_T_DEFINED */

#ifndef _UINTPTR_T_DEFINED
#define _UINTPTR_T_DEFINED
#ifdef _WIN64
typedef unsigned __int64 uintptr_t;
#else /* _WIN64 */
typedef _W64 unsigned int uintptr_t;
#endif /* _WIN64 */
#endif /* _UINTPTR_T_DEFINED */

typedef __int64 int64_t;
typedef unsigned __int64 uint64_t;

typedef __int64 int_least64_t;
typedef unsigned uint_least64_t;

typedef __int64 int_fast64_t;
typedef unsigned uint_fast64_t;

typedef __int64 intmax_t;
typedef unsigned uintmax_t;

/* LIMIT MACROS */
#define INT8_MIN	(-0x7f - _C2)
#define INT16_MIN	(-0x7fff - _C2)
#define INT32_MIN	(-0x7fffffff - _C2)

#define INT8_MAX	0x7f
#define INT16_MAX	0x7fff
#define INT32_MAX	0x7fffffff
#define UINT8_MAX	0xff
#define UINT16_MAX	0xffff
#define UINT32_MAX	0xffffffff

#define INT_LEAST8_MIN		(-0x7f - _C2)
#define INT_LEAST16_MIN		(-0x7fff - _C2)
#define INT_LEAST32_MIN		(-0x7fffffff - _C2)

#define INT_LEAST8_MAX		0x7f
#define INT_LEAST16_MAX		0x7fff
#define INT_LEAST32_MAX		0x7fffffff
#define UINT_LEAST8_MAX		0xff
#define UINT_LEAST16_MAX	0xffff
#define UINT_LEAST32_MAX	0xffffffff

#define INT_FAST8_MIN		(-0x7f - _C2)
#define INT_FAST16_MIN		(-0x7fff - _C2)
#define INT_FAST32_MIN		(-0x7fffffff - _C2)

#define INT_FAST8_MAX		0x7f
#define INT_FAST16_MAX		0x7fff
#define INT_FAST32_MAX		0x7fffffff
#define UINT_FAST8_MAX		0xff
#define UINT_FAST16_MAX		0xffff
#define UINT_FAST32_MAX		0xffffffff

#if _INTPTR == 0 || _INTPTR == 1
#define INTPTR_MAX			0x7fffffff
#define INTPTR_MIN			(-INTPTR_MAX - _C2)
#define UINTPTR_MAX			0xffffffff

#else /* _INTPTR == 2 */
#define INTPTR_MIN			(-_LLONG_MAX - _C2)
#define INTPTR_MAX			_LLONG_MAX
#define UINTPTR_MAX			_ULLONG_MAX
#endif /* _INTPTR */

#define INT8_C(x)	(x)
#define INT16_C(x)	(x)
#define INT32_C(x)	((x) + (INT32_MAX - INT32_MAX))

#define UINT8_C(x)	(x)
#define UINT16_C(x)	(x)
#define UINT32_C(x)	((x) + (UINT32_MAX - UINT32_MAX))

#ifdef _WIN64
#define PTRDIFF_MIN		INT64_MIN
#define PTRDIFF_MAX		INT64_MAX
#else /* _WIN64 */
#define PTRDIFF_MIN		INT32_MIN
#define PTRDIFF_MAX		INT32_MAX
#endif /* _WIN64 */

#define SIG_ATOMIC_MIN	INT32_MIN
#define SIG_ATOMIC_MAX	INT32_MAX

#ifndef SIZE_MAX
#ifdef _WIN64
#define SIZE_MAX		UINT64_MAX
#else /* _WIN64 */
#define SIZE_MAX		UINT32_MAX
#endif /* _WIN64 */
#endif /* SIZE_MAX */

#define WINT_MIN	0x0000
#define WINT_MAX	0xffff

#define INT64_MIN	(-0x7fffffffffffffff - _C2)
#define INT64_MAX	0x7fffffffffffffff
#define UINT64_MAX	0xffffffffffffffffU

#define INT_LEAST64_MIN	(-0x7fffffffffffffff - _C2)
#define INT_LEAST64_MAX	0x7fffffffffffffff
#define UINT_LEAST64_MAX	0xffffffffffffffffU

#define INT_FAST64_MIN		(-0x7fffffffffffffff - _C2)
#define INT_FAST64_MAX		0x7fffffffffffffff
#define UINT_FAST64_MAX	0xffffffffffffffffU

#define INTMAX_MIN		(-0x7fffffffffffffff - _C2)
#define INTMAX_MAX		0x7fffffffffffffff
#define UINTMAX_MAX	0xffffffffffffffffU

#define INT64_C(x)		((x) + (INT64_MAX - INT64_MAX))
#define UINT64_C(x)		((x) + (UINT64_MAX - UINT64_MAX))
#define INTMAX_C(x)		INT64_C(x)
#define UINTMAX_C(x)	UINT64_C(x)

#else
#include <stdint.h>
#endif