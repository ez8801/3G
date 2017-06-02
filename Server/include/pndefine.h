/* 106 228 203 199 203 251 69 164 171 249 223 147 102 233 72 137 119 94 82 90 79 10 155 183 241 217 150 77 172 108 93 173 68 19 40 212 204 206 54 180 157 223 26 99 125 119 19 97 77 110 19 247 97 96 131 5 72 145 14 214 105 62 226 154 70 6 217 121 223 90 234 52 213 76 97 23 184  */
#pragma once

#ifdef _MSC_VER
#pragma pack(push,8)
#endif

#ifdef _MSC_VER // pragma warning is VC++ specific.
#pragma warning(disable:4127) // We know that compiler optimizes JCX instruction if constant is used and we make use of them.
#endif

#define PNDEFINE_USED

// Windows SDK�� Playstation SDK�� iconv�� �⺻ �������� �ʴ´�.
// TODO: tiniconv�� ����Ż��?
#if defined _WIN32 || defined __ORBIS__ || defined __ANDROID__  // NOTE: ProudNet_android.vcxproj������ NDK �� iconv�� ã�� �� ����.
#	define PROUDNET_HAS_ICONV
#endif

// NOTE: ���� �𵨿� ���� �ü�� define ����
//
#if defined(__MACH__)
#define USE_KQUEUE_ONLY_ON_MACH
#endif

#if defined(__FreeBSD__)
#define USE_KQUEUE_ONLY_ON_FREEBSD
#endif

#if defined(__MACH__) || defined(__FreeBSD__)
#define USE_KQUEUE_ONLY
#endif

#if defined(__linux__)
#define USE_EPOLL_ONLY_ON_LINUX
#endif

#if defined(__linux__) || defined(__MACH__) || defined(__FreeBSD__)
#define USE_EPOLL_OR_KQUEUE
#endif

#if defined(_WIN32)
#define USE_IOCP_ONLY_ON_WINDOWS
#endif

#if defined(__MARMALADE__)
#define USE_POLL_ONLY
#endif

#if defined(_WIN32) || defined(__linux__) || defined(__MACH__) || defined(__FreeBSD__)
#define USE_IOCP_AND_EPOLL_AND_KQUEUE
#endif

// ������,�ڵ� �� Ŀ�� ���ҽ� ���� ���� ����Ǵ� �÷���
#if defined(__ANDROID__) || defined(TARGET_OS_IPHONE) || defined(__ORBIS__) || defined(__MARMALADE__)
#define KERNEL_RESOURCE_SHORTAGE
#endif

// critical section or mutex�� thread ID ���� ���ü� �ִ� ȯ�濡���� ���ǵ˴ϴ�.
#if defined (_WIN32) || defined (__linux__) || defined (__ANDROID__) /*|| defined (__MACH__)*/
#define PN_LOCK_OWNER_SHOWN
#endif

#ifdef _MSC_VER // VC++�迭�̸�
#define PN_ALIGN(val) __declspec(align(val))
#else //�̿� �����Ϸ� �迭�̸�
#define PN_ALIGN(val) __attribute__((aligned(val)))
#endif

// std::chrono�� �� �� �ִ���?
#if (_MSC_VER>=1800) || (__cplusplus > 199711L)
// �������� �̰ſ��� => defined(SUPPORTS_CPP11) && !((defined(__MACH__) && defined(__GLIBCXX__)) || defined(_PN_BOOST))
#define PN_USE_CHRONO 1
#else
#define PN_USE_CHRONO 0
#endif


#ifdef _MSC_VER
#pragma pack(pop)
#endif