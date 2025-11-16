#pragma once

#include "hzpch.h"
#include "Hazard/Core/core.h"

namespace Hazard
{
	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseScrolled, MouseMoved,
		AppTick, AppUpdate, AppRender
	};

	enum EventCategory
	{
		Node = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMousebutton = BIT(4)
	};


	class HZ_API Event
	{
		friend class EventDispatcher;

	public:
		virtual ~Event() = default;

		bool handled = false;

		virtual EventType GetEventType() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual const char* GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsinCategory(int category)
		{
			return GetCategoryFlags() & category;
		}

	};


	class EventDispatcher
	{
	private:
		Event& m_Event;

		template<typename T>
		using EventFn = std::function<bool(T&)>;

	public:
		template<typename T>
		bool Dispatch(const EventFn<T>& func)
		{
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.handled = func(static_cast<T&>(m_Event));
				return true;
			}
			return false;
		}
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& ev)
	{
		os << ev.ToString();
		return os;
	}

	#define EVENT_CLASS_TYPE(type)\
		static EventType GetStaticType() { return EventType::type; }\
		virtual EventType GetEventType() const override { return GetStaticType(); }\
		virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category)\
		virtual int GetCategoryFlags() const override { return category; }

}