#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazard::Application* Hazard::CreateApplication();

int main() 
{
	Hazard::Log::Init();
	HZ_CORE_ERROR("HAZARD ENGINE INITIALIZING...");
	HZ_INFO("HAZARD ENGINE INITIALIZED.");
	HZ_INFO("WELCOME! USER");

	auto app = Hazard::CreateApplication();
	app->Run();
	delete app;
}

#endif
