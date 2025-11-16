#pragma once
#include "Hazard/Core/Core.h"
#include "Hazard/Core/Window.h"

namespace Hazard 
{

	class HZ_API Application 
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}