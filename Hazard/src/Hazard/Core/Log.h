#pragma once

#include "Hazard/Core/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Hazard
{
	class HZ_API Log
	{
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	};
}


#define HZ_CORE_TRACE(...)		::Hazard::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define HZ_CORE_INFO(...)		::Hazard::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HZ_CORE_WARN(...)		::Hazard::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HZ_CORE_ERROR(...)		::Hazard::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HZ_CORE_FATAL(...)		::Hazard::Log::GetCoreLogger()->critical(__VA_ARGS__)

#define HZ_TRACE(...)			::Hazard::Log::GetClientLogger()->trace(__VA_ARGS__)
#define HZ_INFO(...)			::Hazard::Log::GetClientLogger()->info(__VA_ARGS__)
#define HZ_WARN(...)			::Hazard::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HZ_ERROR(...)			::Hazard::Log::GetClientLogger()->error(__VA_ARGS__)
#define HZ_FATAL(...)			::Hazard::Log::GetClientLogger()->critical(__VA_ARGS__)


