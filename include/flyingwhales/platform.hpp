#pragma once

#define FW_CPP14 201402L
#define FW_CPP11 201103L
#define FW_CPP98 199711L

// C pre-processor platform, architecture and compiler detection header.
#if defined(_MSC_VER)
#	define FW_COMPILER_MSVC true
#	define FW_COMPILER_VERSION _MSC_VER
#elif defined(__clang__)
#	define FW_COMPILER_CLANG true
#	define FW_COMPILER_VERSION (__clang_major__ * 100 + __clang_minor__ * 10 + __clang_patchlevel__)
#elif defined(__GNUC__)
#	define FW_COMPILER_GCC true
#	define FW_COMPILER_VERSION (__GNUC__ * 100 + __GNUC_MINOR__ * 10 + __GNUC_PATCHLEVEL__)
#else
#	pragma warning "Unknown compiler detected. Your compiler may be unsupported."
#	define FW_COMPILER_UNKNOWN true
#	define FW_COMPILER_VERSION 0
#endif

#if defined (__WIN32__) || defined(_WIN32)
#	include <sdkddkver.h>
#	if defined(WINAPI_FAMILY)
#		include <winapifamily.h>
#		if WINAPI_FAMILY == WINAPI_FAMILY_APP || WINAPI_FAMILY == WINAPI_FAMILY_PHONE_APP
#			define FW_PLATFORM_WINRT true
#			pragma warning "You are compiling for WinRT, which may not be supported."
#		else
#			define FW_PLATFORM_WIN32 true
#		endif
#	else
#		define FW_PLATFORM_WIN32 true
#	endif
#elif defined(__APPLE_CC__)
#	if __ENVIRONMENT_IPHONE_OS_VERSION_MIN_REQUIRED__ >= 60000 || __IPHONE_OS_VERSION_MIN_REQUIRED >= 60000
#		define FW_PLATFORM_IOS true
#	else
#		define FW_PLATFORM_MACOSX true
#	endif
#elif defined(__ANDROID__)
#	define FW_PLATFORM_ANDROID
#elif defined(__linux) || defined(__linux__)
#	define FW_PLATFORM_LINUX true
#elif defined(__unix) || defined(__unix__)
#	define FW_PLATFORM_UNIX true
#else
#	define FW_PLATFORM_UNKNOWN true
#endif

#if __cplusplus >= FW_CPP14
#	define FW_CPP_VERSION FW_CPP14
#elif __cplusplus >= FW_CPP11
#	define FW_CPP_VERSION FW_CPP11
#elif __cplusplus >= FW_CPP98
#	define FW_CPP_VERSION FW_CPP98
#else 
#	pragma warning "Could not detect C++ revision. Your compiler may be unsupported."
#endif

// And thus comes the long list of x86_64 macros.
#if defined(__x86_64__) || defined(_M_X64) || defined(__powerpc64__) || defined(__alpha__) || defined(__ia64__) || defined(__s390__) || defined(__s390x__) || defined(__arm64__) || defined(__aarch64__) || defined(__mips64) || defined(__mips64_)
#	define FW_ARCH_X86_64 true
#else
#	define FW_ARCH_X86 true
#endif

#if defined(_DEBUG) || defined(DEBUG)
#	define FW_DEBUG true
#else
#	define FW_RELEASE true
#endif
