/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once 

#ifndef _WIN32
//#include <alloca.h>
#endif

/* ����: _MALLOCA, _FREEA�� ����
�� �Լ����� ���ÿ� ����� ������ ������ ���ÿ� �Ҵ���, �׷��� ������ heap�� �Ҵ��� �Ѵ�.
�� �ſ� ���� ũ�Ⱑ �ƴ� �̻� heap�� �Ҵ��ϴ� ������ �Ѵ�. �� ���� ���к��ٴ� ������ ���ϵǴ��� heap�� �׼����ϴ� ���̴�.
���� ����� �Ҵ��ϰ��� �ϴ� ũ�Ⱑ ū ��찡 ���� ��� �� �Լ��� �׻� heap�� �׼����� ���̴�. �� ������ ������ ���� ���Ѵ�.
�̷��� ��쿡�� _MALLOCA ��� object pooling�� �϶�. ���� Proud.CPooledArrayObjectAsLocalVar�� ���� ���� �ξ� ����.

*/

/* _malloca�� ���� ũ������ heap access�� �ع�����. �׷��� win32���� ������ ũ�� �����Ѵ�. 
���� TLS ��� obj-pool�� ����. �ƹ�ư �����ϸ� �׳� _alloca�� ����, _malloc�� ������. 
���� �ſ� ���� ũ�⿡ ���ؼ� ��� �ϰڰ�.
*/
#if 0 

#if !defined(_WIN32)
#define _MALLOCA alloca
#define _FREEA(...) 
#else
#if (_MSC_VER>=1400)
#define _MALLOCA _malloca
#define _FREEA _freea
#else
#define _MALLOCA _alloca
#define _FREEA __noop
#endif
#endif

#else  // 0

#	ifndef _WIN32
#		define _MALLOCA alloca
#		define _FREEA(...) 
#	else 
#		define _MALLOCA _alloca
#		define _FREEA 
#	endif

#endif  // 1

/* ���ÿ� C++ ��ü�� �Ҵ�/�����ϴ� ��ũ��.

���ǻ���:
���ÿ� �ʹ� ū ũ�⸦ �Ҵ����� �� ��. �����̶�� �� ��ü�� �뷮 ���ڶ�� �� ���� ȯ���̱� �����̴�.
������ win32 _malloca������ 1KB �̻��� �׳� heap �Ҵ��� ������. 
1KB �̸��� ���� ũ�Ⱑ �ƴ϶�� NEW_ON_STACK�̳� _MALLOCA ��� POOLED_LOCAL_VAR�� �� ��.

��뿹:
int arrayLength;
NEW_ON_STACK(array, MyType, arrayLength);

...

FREE_ON_STACK(array);


*/

#define NEW_ON_STACK(VARNAME, TYPE, LENGTH) \
	TYPE* VARNAME = (TYPE*)_MALLOCA(sizeof(TYPE) * LENGTH); \
	CallConstructors(VARNAME, LENGTH); 

#define FREE_ON_STACK(VARNAME, LENGTH) \
	CallDestructors(VARNAME, LENGTH); \
	_FREEA(VARNAME);
