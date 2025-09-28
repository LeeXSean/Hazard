#pragma once

#ifdef HZ_PLATFORM_WINDOWS

extern Hazard::Application* Hazard::CreateApplication();

int main() {
	printf("Hazard Engine Start\n");
	auto app = Hazard::CreateApplication();
	app->Run();
	delete app;
}

#endif
