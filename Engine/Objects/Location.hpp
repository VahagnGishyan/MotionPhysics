#pragma once

#include "../Map/Location.hpp"

namespace Engine
{
    namespace ObjectComponent
    {
	class Location : public Engine::MapComponent::Location 
	{
	public:
	    Location(const Engine::MapComponent::Abscissa& abs, const Engine::MapComponent::Ordinate& ord) 
		: Engine::MapComponent::Location(abs, ord) {}
	    Location(Engine::MapComponent::Abscissa&& abs, Engine::MapComponent::Ordinate&& ord)
		: Engine::MapComponent::Location(abs, ord) {}

	    Location(const Engine::MapComponent::Ordinate& ord, const Engine::MapComponent::Abscissa& abs)
		: Engine::MapComponent::Location(abs, ord) {}
	    Location(Engine::MapComponent::Ordinate&& ord, Engine::MapComponent::Abscissa&& abs)
		: Engine::MapComponent::Location(abs, ord) {}

	    Location(const Location& loc) : Engine::MapComponent::Location(loc) {}
	    Location(Location&& loc) noexcept : Engine::MapComponent::Location(loc) {}

	    bool operator==(const Location& obj) const
	    {
		return (Engine::MapComponent::Location::operator==(obj));
	    }
	    bool operator!=(const Location& obj) const
	    {
		return (Engine::MapComponent::Location::operator!=(obj));
	    }

	    Location& operator=(const Location& loc) { Engine::MapComponent::Location::operator=(loc); return *this; }
	    Location& operator=(Location&& loc) noexcept { Engine::MapComponent::Location::operator=(loc); return *this; }

	    Engine::MapComponent::Abscissa getAbscissa() const { return (Engine::MapComponent::Location::getAbscissa()); }
	    Engine::MapComponent::Ordinate getOrdinate() const { return (Engine::MapComponent::Location::getOrdinate()); }
	};
    }
}