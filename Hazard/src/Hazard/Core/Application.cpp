#include "hzpch.h"
#include "Hazard/Core/Application.h"
#include "Hazard/Events/Event.h"
#include "Hazard/Events/ApplicationEvent.h"
#include "Hazard/Core/Log.h"

namespace Hazard 
{
	
	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() 
	{

	}

	void Application::Run() 
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}
