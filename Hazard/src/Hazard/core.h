#pragma once

#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HZ_API __declspec(dllexport)
	#else
		#define HZ_API __declspec(dllimport)
	#endif
#else
	#error hazard only supports Windows!
#endif