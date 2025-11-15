#pragma once

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HZ_API __declspec(dllexport)
	#else
		#define HZ_API __declspec(dllimport)
	#endif
#else 
	#error Hazard only supports Windows!
#endif

#ifdef HZ_DEBUG
	#define HZ_ENABLE_ASSERTS

	#ifdef HZ_PLATFORM_WINDOWS
		#define HZ_DEBUGBREAK __debugbreak();
	#else
		#error Platform doesnt support debugbreak yet!
	#endif
#else
	#define HZ_DEBUGBREAK
#endif

#ifdef HZ_ENABLE_ASSERTS
	#define HZ_CORE_ASSERT(x, ...)\
		{if(!x){\
			HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__);\
			HZ_DEBUGBREAK}\
		}
	#define HZ_ASSERT(x, ...)\
		{if(!x){\
			HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__);\
			HZ_DEBUGBREAK}\
		}
#else
	#define HZ_CORE_ASSERT(x, ...)
	#define HZ_ASSERT(x, ...)	
#endif

#define BIT(x) (1 << x)