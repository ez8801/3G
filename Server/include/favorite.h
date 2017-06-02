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

/**
\~korean
Áñ°Ü ¾²´Â Çì´õ ÆÄÀÏµéÀ» ¸ğÀº ÆÄÀÏÀÌ´Ù.
ProudNetÀ» ¾²±â À§ÇØ¼­ ¹İµå½Ã #includeÇØ¾ß ÇÏ´Â ÆÄÀÏÀº ¾Æ´Ï´Ù.

\~english
A collection of favorite header files.
There is no must need to #include this file when using ProudNet.

\~chinese
ãÀßÈéÄ?ÙşËìîÜâ¥íúÙşËì¡£
?ÜôãÀŞÅéÄProudNetá¶ù±?é©#include îÜÙşËì¡£

\~japanese
ªª?ªËìıªêªÎ«Ø«Ã«À?«Õ«¡«¤«ëªòó¢ªáª¿«Õ«¡«¤«ëªÇª¹¡£
ProudNetªòŞÅª¦ª¿ªáªËªÏù±ªº#includeª¹ªÙª­«Õ«¡«¤«ëªÇªÏª¢ªêªŞª»ªó¡£
\~
*/

#pragma once


#if defined(_WIN32)
#include <assert.h>
#include <algorithm>
//#include <comdef.h> ¼­¹ö¿¡¼­¸¸ ¾²ÀÚ. UE4 ¶§¹®¿¡ Å¬¶ó´Â ¾²¸é ¾ÈµÊ.
#include <conio.h>
#include <conio.h>
#include <crtdbg.h>
#include <ctype.h>
#include <deque>
#include <dimm.h>
#include <direct.h>
#include <exception>
#include <float.h>
#include <fstream>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <mbstring.h>
#include <memory.h>
#include <mmreg.h>
#include <WinSock2.h>
#include <mmsystem.h>
//#include <new>
#include <oleauto.h>
#include <process.h>
#include <queue>
//#include <rpcdce.h> UE4 ºñÈ£È¯µÇ¹Ç·Î »èÁ¦
#include <set>
#include <shellapi.h>
#include <sstream>
#include <stack>
#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
//#include <string>
#include <tchar.h>
#include <time.h>
#include <unknwn.h>
#include <usp10.h>
#include <utility>
#include <vector>
#include <wincrypt.h>
#include <windows.h>
#include <windowsx.h>
#include <wininet.h>
#include <winsock2.h>
#include <xmemory>
#endif
