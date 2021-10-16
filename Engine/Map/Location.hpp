#pragma once

#include "Abscissa.hpp"
#include "Ordinate.hpp"

namespace Engine
{
    namespace MapComponent
    {
	class Location
	{
	private:
	    Engine::MapComponent::Abscissa   m_abscissa;
	    Engine::MapComponent::Ordinate   m_ordinate;

	public:
	    //Location(int abs, int ord) : Abscissa(abs), Ordinate(ord) {}
	    Location(const Engine::MapComponent::Abscissa& abs, const Engine::MapComponent::Ordinate& ord) : m_abscissa(abs), m_ordinate(ord) {}
	    Location(Engine::MapComponent::Abscissa&& abs, Engine::MapComponent::Ordinate&& ord) : m_abscissa(abs), m_ordinate(ord) {}

	    Location(const Engine::MapComponent::Ordinate& ord, const Engine::MapComponent::Abscissa& abs) : m_abscissa(abs), m_ordinate(ord) {}
	    Location(Engine::MapComponent::Ordinate&& ord, Engine::MapComponent::Abscissa&& abs) : m_abscissa(abs), m_ordinate(ord) {}

	    Location(const Location& loc) : m_abscissa(loc.m_abscissa), m_ordinate(loc.m_ordinate) {}
	    Location(Location&& loc) noexcept : m_abscissa(loc.m_abscissa), m_ordinate(loc.m_ordinate) {}

	    bool operator==(const Location& obj) const
	    {
		return (m_abscissa == obj.m_abscissa && m_ordinate == obj.m_ordinate);
	    }
	    bool operator!=(const Location& obj) const
	    {
		return (!(m_abscissa == obj.m_abscissa && m_ordinate == obj.m_ordinate));
	    }

	    Location& operator=(const Location& loc) { m_abscissa = loc.m_abscissa; m_ordinate = loc.m_ordinate; return *this; }
	    Location& operator=(Location&& loc) noexcept { m_abscissa = loc.m_abscissa; m_ordinate = loc.m_ordinate; return *this; }

	    Engine::MapComponent::Abscissa getAbscissa() const { return (m_abscissa); }
	    Engine::MapComponent::Ordinate getOrdinate() const { return (m_ordinate); }

	    void changeAbscissa(const Abscissa& abs) { m_abscissa = abs; }
	    void changeOrdinate(const Ordinate& ord) { m_ordinate = ord; }
	    void changeAbscissa(Abscissa&& abs) { m_abscissa = abs; }
	    void changeOrdinate(Ordinate&& ord) { m_ordinate = ord; }
	};
    }

    using   Coordinate = MapComponent::Location;
}