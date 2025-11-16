#pragma once

#include "Hazard/Events/Event.h"

namespace Hazard
{
	class HZ_API MouseMovedEvent : public Event
	{
	private:
		struct MousePosition
		{
			float X, Y;
		};

		float m_MouseX, m_MouseY;
	public:
		MouseMovedEvent(float x, float y)
			: m_MouseX(x)
			, m_MouseY(y)
		{ }

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: " << m_MouseX << ", " << m_MouseY << "\n";
			return ss.str();
		}

		inline MousePosition GetPosition() const { return { m_MouseX, m_MouseY }; }
	};

	class HZ_API MouseScrolledEvent : public Event
	{
	private:
		struct MouseOffsetPosition
		{
			float XOffset, YOffset;
		};

		float m_XOffset, m_YOffset;

	public:
		MouseScrolledEvent(float xoffset, float yoffset)
			: m_XOffset(xoffset)
			, m_YOffset(yoffset)
		{ }

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << m_XOffset << ", " << m_YOffset << "\n";
			return ss.str();
		}

		inline MouseOffsetPosition GetOffsetPosition() const { return { m_XOffset, m_YOffset }; }
	};

	class HZ_API MouseButtonEvent : public Event
	{
	public:
		EVENT_CLASS_CATEGORY(EventCategoryMousebutton | EventCategoryInput)

		inline int GetButton() const { return m_Button; }
	protected:
		int m_Button;

		MouseButtonEvent(int button)
			: m_Button(button)
		{ }
	};

	class HZ_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button)
		{ }

		EVENT_CLASS_TYPE(MouseButtonPressed)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << m_Button << "\n";
			return ss.str();
		}
	};

	class HZ_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button)
		{ }

		EVENT_CLASS_TYPE(MouseButtonReleased)

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << m_Button << "\n";
			return ss.str();
		}
	};
}