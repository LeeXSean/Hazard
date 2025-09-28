#pragma once
#include "core.h"

namespace Hazard {

	class HZ_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}