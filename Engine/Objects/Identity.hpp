#pragma once

#include "../../Visualization/ConsoleIdentity.hpp"

namespace Engine
{
    namespace ObjectComponent
    {
	//temporary
	//until the "Visualization" is created in all its glory, by default we will use the "Console".
	class Identity : public Visualization::Console::Identity
	{
	private:
	    using CIdentuty = Visualization::Console::Identity;
	public:
	    using ObjectID = unsigned int;
	private:
	    Identity::ObjectID	m_objectID = -1;
	public:
	    Identity(Visualization::Console::Symbol symbol, Visualization::Console::Color color) 
		: Visualization::Console::Identity(symbol, color) {}  
	    Identity(const Identity& id) : CIdentuty(id) {}
	    Identity(Identity&& id) noexcept : CIdentuty(id) {}

	    Identity::ObjectID getObjectID() { return m_objectID;}
	};
    }
}