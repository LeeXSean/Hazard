#pragma once

#include "hzpch.h"
#include "Hazard/Core/Core.h"
#include "Hazard/Events/Event.h"

namespace Hazard
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Hazard Engine",
			unsigned int width = 1280,
			unsigned int height = 720)
			: Title(title)
			, Width(width)
			, Height(height)
		{ }

	};

	class HZ_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		static Window* Create(const WindowProps& props = WindowProps());

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;
	};
}